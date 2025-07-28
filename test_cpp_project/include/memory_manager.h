#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include <memory>
#include <vector>
#include <unordered_map>
#include <string>
#include <mutex>

namespace memory {

    template<typename T>
    class Pool {
    public:
        Pool(size_t blockSize = 1024);
        ~Pool();

        T* allocate();
        void deallocate(T* ptr);

        size_t getBlockSize() const;
        size_t getAllocatedCount() const;
        size_t getAvailableCount() const;

    private:
        struct Block {
            std::unique_ptr<T[]> data;
            std::vector<bool> used;
            size_t nextAvailable;
        };

        std::vector<std::unique_ptr<Block>> blocks;
        size_t blockSize;
        size_t allocatedCount;
        mutable std::mutex mutex;

        void createNewBlock();
        T* findAvailableSlot();
    };

    class MemoryTracker {
    public:
        static MemoryTracker& getInstance();
        
        void recordAllocation(void* ptr, size_t size, const std::string& file, int line);
        void recordDeallocation(void* ptr);
        
        size_t getTotalAllocatedBytes() const;
        size_t getCurrentAllocations() const;
        size_t getPeakAllocations() const;
        
        void printStatistics() const;
        void resetStatistics();
        
        bool hasLeaks() const;
        std::vector<std::string> getLeakReport() const;

    private:
        struct AllocationInfo {
            size_t size;
            std::string file;
            int line;
            std::chrono::steady_clock::time_point timestamp;
        };

        MemoryTracker() = default;
        ~MemoryTracker() = default;
        MemoryTracker(const MemoryTracker&) = delete;
        MemoryTracker& operator=(const MemoryTracker&) = delete;

        std::unordered_map<void*, AllocationInfo> allocations;
        size_t totalAllocatedBytes;
        size_t currentAllocations;
        size_t peakAllocations;
        mutable std::mutex mutex;
    };

    template<typename T>
    class SmartArray {
    public:
        explicit SmartArray(size_t size);
        SmartArray(const SmartArray& other);
        SmartArray(SmartArray&& other) noexcept;
        ~SmartArray();

        SmartArray& operator=(const SmartArray& other);
        SmartArray& operator=(SmartArray&& other) noexcept;

        T& operator[](size_t index);
        const T& operator[](size_t index) const;

        T* data();
        const T* data() const;

        size_t size() const;
        bool empty() const;

        void resize(size_t newSize);
        void clear();

        class iterator {
        public:
            iterator(T* ptr);
            iterator& operator++();
            iterator operator++(int);
            T& operator*();
            bool operator!=(const iterator& other) const;
            bool operator==(const iterator& other) const;

        private:
            T* ptr;
        };

        iterator begin();
        iterator end();

    private:
        T* data_;
        size_t size_;
        size_t capacity_;

        void copyFrom(const SmartArray& other);
        void moveFrom(SmartArray&& other);
        void reallocate(size_t newCapacity);
    };

    namespace detail {
        void* alignedAlloc(size_t size, size_t alignment);
        void alignedFree(void* ptr);
        
        template<typename T>
        constexpr size_t getAlignment() {
            return alignof(T);
        }
    }
}

#define TRACK_ALLOCATION(ptr, size) \
    memory::MemoryTracker::getInstance().recordAllocation(ptr, size, __FILE__, __LINE__)

#define TRACK_DEALLOCATION(ptr) \
    memory::MemoryTracker::getInstance().recordDeallocation(ptr)

#endif // MEMORY_MANAGER_H
