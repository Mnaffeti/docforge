#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <functional>
#include <vector>
#include <memory>

namespace ds {

    template<typename T>
    struct Node {
        T data;
        std::shared_ptr<Node<T>> next;
        std::weak_ptr<Node<T>> prev;
        
        Node(const T& value) : data(value), next(nullptr) {}
        Node(T&& value) : data(std::move(value)), next(nullptr) {}
    };

    template<typename T>
    class LinkedList {
    public:
        LinkedList();
        ~LinkedList();

        void pushFront(const T& value);
        void pushBack(const T& value);
        void pushFront(T&& value);
        void pushBack(T&& value);

        void popFront();
        void popBack();

        T& front();
        const T& front() const;
        T& back();
        const T& back() const;

        bool empty() const;
        size_t size() const;
        void clear();

        void remove(const T& value);
        void removeIf(std::function<bool(const T&)> predicate);

        class iterator {
        public:
            iterator(std::shared_ptr<Node<T>> node);
            iterator& operator++();
            iterator operator++(int);
            T& operator*();
            T* operator->();
            bool operator==(const iterator& other) const;
            bool operator!=(const iterator& other) const;

        private:
            std::shared_ptr<Node<T>> current;
        };

        iterator begin();
        iterator end();

    private:
        std::shared_ptr<Node<T>> head;
        std::shared_ptr<Node<T>> tail;
        size_t count;
    };

    template<typename T, typename Compare = std::less<T>>
    class BinarySearchTree {
    public:
        BinarySearchTree();
        explicit BinarySearchTree(const Compare& comp);
        ~BinarySearchTree();

        void insert(const T& value);
        void insert(T&& value);
        bool remove(const T& value);
        bool contains(const T& value) const;

        size_t size() const;
        bool empty() const;
        void clear();

        T findMin() const;
        T findMax() const;

        void inorderTraversal(std::function<void(const T&)> visitor) const;
        void preorderTraversal(std::function<void(const T&)> visitor) const;
        void postorderTraversal(std::function<void(const T&)> visitor) const;

        int height() const;
        bool isBalanced() const;

    private:
        struct TreeNode {
            T data;
            std::unique_ptr<TreeNode> left;
            std::unique_ptr<TreeNode> right;
            
            TreeNode(const T& value) : data(value) {}
            TreeNode(T&& value) : data(std::move(value)) {}
        };

        std::unique_ptr<TreeNode> root;
        Compare comparator;
        size_t nodeCount;

        TreeNode* insertHelper(std::unique_ptr<TreeNode>& node, const T& value);
        TreeNode* insertHelper(std::unique_ptr<TreeNode>& node, T&& value);
        std::unique_ptr<TreeNode> removeHelper(std::unique_ptr<TreeNode> node, const T& value);
        TreeNode* findMin(TreeNode* node) const;
        bool containsHelper(const TreeNode* node, const T& value) const;
        int heightHelper(const TreeNode* node) const;
        void inorderHelper(const TreeNode* node, std::function<void(const T&)> visitor) const;
        void preorderHelper(const TreeNode* node, std::function<void(const T&)> visitor) const;
        void postorderHelper(const TreeNode* node, std::function<void(const T&)> visitor) const;
    };

    template<typename Key, typename Value, typename Hash = std::hash<Key>>
    class HashTable {
    public:
        explicit HashTable(size_t initialCapacity = 16);
        ~HashTable();

        void insert(const Key& key, const Value& value);
        void insert(const Key& key, Value&& value);
        bool remove(const Key& key);
        
        Value* find(const Key& key);
        const Value* find(const Key& key) const;
        
        bool contains(const Key& key) const;
        size_t size() const;
        bool empty() const;
        void clear();

        double loadFactor() const;
        void rehash(size_t newCapacity);

    private:
        struct Entry {
            Key key;
            Value value;
            bool isOccupied;
            bool isDeleted;
            
            Entry() : isOccupied(false), isDeleted(false) {}
            Entry(const Key& k, const Value& v) : key(k), value(v), isOccupied(true), isDeleted(false) {}
            Entry(const Key& k, Value&& v) : key(k), value(std::move(v)), isOccupied(true), isDeleted(false) {}
        };

        std::vector<Entry> table;
        size_t capacity;
        size_t elementCount;
        Hash hasher;

        size_t hash(const Key& key) const;
        size_t probe(size_t hash, size_t attempt) const;
        void resize();
        bool needsResize() const;
    };

    namespace algorithms {
        template<typename Iterator, typename Compare>
        void quickSort(Iterator first, Iterator last, Compare comp);
        
        template<typename Iterator, typename Compare>
        void mergeSort(Iterator first, Iterator last, Compare comp);
        
        template<typename Iterator, typename T>
        Iterator binarySearch(Iterator first, Iterator last, const T& value);
        
        template<typename Container, typename T>
        bool contains(const Container& container, const T& value);
    }
}

#endif // DATA_STRUCTURES_H
