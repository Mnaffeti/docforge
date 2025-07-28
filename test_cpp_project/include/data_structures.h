#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <functional>
#include <vector>
#include <memory>

/**
 * @brief ds namespace
 * 
 * Contains classes and functions related to ds functionality.
 * TODO: Add specific namespace purpose description
 * 
 * @since Version 1.0
 */
/**
 * @brief ds namespace
 * 
 * Contains classes and functions related to ds functionality.
 * TODO: Add specific namespace purpose description
 * 
 * @since Version 1.0
 */
namespace ds {

    template<typename T>
/**
 * @brief Node struct
 * 
 * Detailed description of the Node struct.
 * TODO: Add specific purpose and usage description
 * 
 * @since Version 1.0
 */
/**
 * @brief Node struct
 * 
 * Detailed description of the Node struct.
 * TODO: Add specific purpose and usage description
 * 
 * @since Version 1.0
 */
    struct Node {
        T data;
        std::shared_ptr<Node<T>> next;
        std::weak_ptr<Node<T>> prev;
        
        Node(const T& value) : data(value), next(nullptr) {}
        Node(T&& value) : data(std::move(value)), next(nullptr) {}
    };

    template<typename T>
/**
 * @brief LinkedList class
 * 
 * Detailed description of the LinkedList class.
 * TODO: Add specific functionality description
 * 
 * @since Version 1.0
 * 
 * @example
 * LinkedList obj;
 * // Usage example
 */
/**
 * @brief LinkedList class
 * 
 * Detailed description of the LinkedList class.
 * TODO: Add specific functionality description
 * 
 * @since Version 1.0
 * 
 * @example
 * LinkedList obj;
 * // Usage example
 */
    class LinkedList {
    public:
        LinkedList();
        ~LinkedList();

/**
 * @brief pushFront function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for pushFront
 */
/**
 * @brief pushFront function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for pushFront
 */
        void pushFront(const T& value);
/**
 * @brief pushBack function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for pushBack
 */
/**
 * @brief pushBack function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for pushBack
 */
        void pushBack(const T& value);
/**
 * @brief pushFront function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for pushFront
 */
/**
 * @brief pushFront function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for pushFront
 */
        void pushFront(T&& value);
/**
 * @brief pushBack function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for pushBack
 */
/**
 * @brief pushBack function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for pushBack
 */
        void pushBack(T&& value);

/**
 * @brief popFront function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for popFront
 */
/**
 * @brief popFront function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for popFront
 */
        void popFront();
/**
 * @brief popBack function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for popBack
 */
/**
 * @brief popBack function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for popBack
 */
        void popBack();

        T& front();
        const T& front() const;
        T& back();
        const T& back() const;

/**
 * @brief empty function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @return bool Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for empty
 */
/**
 * @brief empty function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @return bool Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for empty
 */
        bool empty() const;
/**
 * @brief size function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @return size_t Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for size
 */
/**
 * @brief size function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @return size_t Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for size
 */
        size_t size() const;
/**
 * @brief clear function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for clear
 */
/**
 * @brief clear function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for clear
 */
        void clear();

/**
 * @brief remove function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for remove
 */
/**
 * @brief remove function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for remove
 */
        void remove(const T& value);
        void removeIf(std::function<bool(const T&)> predicate);

/**
 * @brief iterator class
 * 
 * Detailed description of the iterator class.
 * TODO: Add specific functionality description
 * 
 * @since Version 1.0
 * 
 * @example
 * iterator obj;
 * // Usage example
 */
/**
 * @brief iterator class
 * 
 * Detailed description of the iterator class.
 * TODO: Add specific functionality description
 * 
 * @since Version 1.0
 * 
 * @example
 * iterator obj;
 * // Usage example
 */
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

/**
 * @brief begin function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @return iterator Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for begin
 */
/**
 * @brief begin function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @return iterator Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for begin
 */
        iterator begin();
/**
 * @brief end function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @return iterator Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for end
 */
/**
 * @brief end function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @return iterator Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for end
 */
        iterator end();

    private:
        std::shared_ptr<Node<T>> head;
        std::shared_ptr<Node<T>> tail;
        size_t count;
    };

    template<typename T, typename Compare = std::less<T>>
/**
 * @brief BinarySearchTree class
 * 
 * Detailed description of the BinarySearchTree class.
 * TODO: Add specific functionality description
 * 
 * @since Version 1.0
 * 
 * @example
 * BinarySearchTree obj;
 * // Usage example
 */
/**
 * @brief BinarySearchTree class
 * 
 * Detailed description of the BinarySearchTree class.
 * TODO: Add specific functionality description
 * 
 * @since Version 1.0
 * 
 * @example
 * BinarySearchTree obj;
 * // Usage example
 */
    class BinarySearchTree {
    public:
        BinarySearchTree();
/**
 * @brief BinarySearchTree function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return explicit Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for BinarySearchTree
 */
/**
 * @brief BinarySearchTree function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return explicit Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for BinarySearchTree
 */
        explicit BinarySearchTree(const Compare& comp);
        ~BinarySearchTree();

/**
 * @brief insert function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for insert
 */
/**
 * @brief insert function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for insert
 */
        void insert(const T& value);
/**
 * @brief insert function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for insert
 */
/**
 * @brief insert function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for insert
 */
        void insert(T&& value);
/**
 * @brief remove function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return bool Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for remove
 */
/**
 * @brief remove function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return bool Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for remove
 */
        bool remove(const T& value);
/**
 * @brief contains function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return bool Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for contains
 */
/**
 * @brief contains function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return bool Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for contains
 */
        bool contains(const T& value) const;

/**
 * @brief size function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @return size_t Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for size
 */
/**
 * @brief size function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @return size_t Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for size
 */
        size_t size() const;
/**
 * @brief empty function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @return bool Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for empty
 */
/**
 * @brief empty function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @return bool Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for empty
 */
        bool empty() const;
/**
 * @brief clear function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for clear
 */
/**
 * @brief clear function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for clear
 */
        void clear();

/**
 * @brief findMin function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @return T Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for findMin
 */
/**
 * @brief findMin function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @return T Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for findMin
 */
        T findMin() const;
/**
 * @brief findMax function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @return T Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for findMax
 */
/**
 * @brief findMax function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @return T Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for findMax
 */
        T findMax() const;

        void inorderTraversal(std::function<void(const T&)> visitor) const;
        void preorderTraversal(std::function<void(const T&)> visitor) const;
        void postorderTraversal(std::function<void(const T&)> visitor) const;

/**
 * @brief height function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @return int Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for height
 */
/**
 * @brief height function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @return int Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for height
 */
        int height() const;
/**
 * @brief isBalanced function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @return bool Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for isBalanced
 */
/**
 * @brief isBalanced function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @return bool Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for isBalanced
 */
        bool isBalanced() const;

    private:
/**
 * @brief TreeNode struct
 * 
 * Detailed description of the TreeNode struct.
 * TODO: Add specific purpose and usage description
 * 
 * @since Version 1.0
 */
/**
 * @brief TreeNode struct
 * 
 * Detailed description of the TreeNode struct.
 * TODO: Add specific purpose and usage description
 * 
 * @since Version 1.0
 */
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

/**
 * @brief insertHelper function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return TreeNode* Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for insertHelper
 */
/**
 * @brief insertHelper function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return TreeNode* Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for insertHelper
 */
        TreeNode* insertHelper(std::unique_ptr<TreeNode>& node, const T& value);
/**
 * @brief insertHelper function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return TreeNode* Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for insertHelper
 */
/**
 * @brief insertHelper function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return TreeNode* Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for insertHelper
 */
        TreeNode* insertHelper(std::unique_ptr<TreeNode>& node, T&& value);
        std::unique_ptr<TreeNode> removeHelper(std::unique_ptr<TreeNode> node, const T& value);
/**
 * @brief findMin function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return TreeNode* Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for findMin
 */
/**
 * @brief findMin function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return TreeNode* Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for findMin
 */
        TreeNode* findMin(TreeNode* node) const;
/**
 * @brief containsHelper function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return bool Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for containsHelper
 */
/**
 * @brief containsHelper function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return bool Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for containsHelper
 */
        bool containsHelper(const TreeNode* node, const T& value) const;
/**
 * @brief heightHelper function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return int Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for heightHelper
 */
/**
 * @brief heightHelper function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return int Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for heightHelper
 */
        int heightHelper(const TreeNode* node) const;
        void inorderHelper(const TreeNode* node, std::function<void(const T&)> visitor) const;
        void preorderHelper(const TreeNode* node, std::function<void(const T&)> visitor) const;
        void postorderHelper(const TreeNode* node, std::function<void(const T&)> visitor) const;
    };

    template<typename Key, typename Value, typename Hash = std::hash<Key>>
/**
 * @brief HashTable class
 * 
 * Detailed description of the HashTable class.
 * TODO: Add specific functionality description
 * 
 * @since Version 1.0
 * 
 * @example
 * HashTable obj;
 * // Usage example
 */
/**
 * @brief HashTable class
 * 
 * Detailed description of the HashTable class.
 * TODO: Add specific functionality description
 * 
 * @since Version 1.0
 * 
 * @example
 * HashTable obj;
 * // Usage example
 */
    class HashTable {
    public:
/**
 * @brief HashTable function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return explicit Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for HashTable
 */
/**
 * @brief HashTable function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return explicit Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for HashTable
 */
        explicit HashTable(size_t initialCapacity = 16);
        ~HashTable();

/**
 * @brief insert function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for insert
 */
/**
 * @brief insert function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for insert
 */
        void insert(const Key& key, const Value& value);
/**
 * @brief insert function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for insert
 */
/**
 * @brief insert function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for insert
 */
        void insert(const Key& key, Value&& value);
/**
 * @brief remove function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return bool Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for remove
 */
/**
 * @brief remove function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return bool Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for remove
 */
        bool remove(const Key& key);
        
/**
 * @brief find function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return Value* Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for find
 */
/**
 * @brief find function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return Value* Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for find
 */
        Value* find(const Key& key);
/**
 * @brief find function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return Value* Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for find
 */
/**
 * @brief find function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return Value* Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for find
 */
        const Value* find(const Key& key) const;
        
/**
 * @brief contains function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return bool Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for contains
 */
/**
 * @brief contains function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return bool Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for contains
 */
        bool contains(const Key& key) const;
/**
 * @brief size function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @return size_t Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for size
 */
/**
 * @brief size function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @return size_t Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for size
 */
        size_t size() const;
/**
 * @brief empty function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @return bool Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for empty
 */
/**
 * @brief empty function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @return bool Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for empty
 */
        bool empty() const;
/**
 * @brief clear function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for clear
 */
/**
 * @brief clear function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for clear
 */
        void clear();

/**
 * @brief loadFactor function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @return double Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for loadFactor
 */
/**
 * @brief loadFactor function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @return double Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for loadFactor
 */
        double loadFactor() const;
/**
 * @brief rehash function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for rehash
 */
/**
 * @brief rehash function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for rehash
 */
        void rehash(size_t newCapacity);

    private:
/**
 * @brief Entry struct
 * 
 * Detailed description of the Entry struct.
 * TODO: Add specific purpose and usage description
 * 
 * @since Version 1.0
 */
/**
 * @brief Entry struct
 * 
 * Detailed description of the Entry struct.
 * TODO: Add specific purpose and usage description
 * 
 * @since Version 1.0
 */
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

/**
 * @brief hash function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return size_t Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for hash
 */
/**
 * @brief hash function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return size_t Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for hash
 */
        size_t hash(const Key& key) const;
/**
 * @brief probe function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return size_t Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for probe
 */
/**
 * @brief probe function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return size_t Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for probe
 */
        size_t probe(size_t hash, size_t attempt) const;
/**
 * @brief resize function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for resize
 */
/**
 * @brief resize function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for resize
 */
        void resize();
/**
 * @brief needsResize function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @return bool Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for needsResize
 */
/**
 * @brief needsResize function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @return bool Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for needsResize
 */
        bool needsResize() const;
    };

/**
 * @brief algorithms namespace
 * 
 * Contains classes and functions related to algorithms functionality.
 * TODO: Add specific namespace purpose description
 * 
 * @since Version 1.0
 */
/**
 * @brief algorithms namespace
 * 
 * Contains classes and functions related to algorithms functionality.
 * TODO: Add specific namespace purpose description
 * 
 * @since Version 1.0
 */
    namespace algorithms {
        template<typename Iterator, typename Compare>
/**
 * @brief quickSort function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for quickSort
 */
/**
 * @brief quickSort function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for quickSort
 */
        void quickSort(Iterator first, Iterator last, Compare comp);
        
        template<typename Iterator, typename Compare>
/**
 * @brief mergeSort function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for mergeSort
 */
/**
 * @brief mergeSort function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for mergeSort
 */
        void mergeSort(Iterator first, Iterator last, Compare comp);
        
        template<typename Iterator, typename T>
/**
 * @brief binarySearch function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return Iterator Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for binarySearch
 */
/**
 * @brief binarySearch function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return Iterator Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for binarySearch
 */
        Iterator binarySearch(Iterator first, Iterator last, const T& value);
        
        template<typename Container, typename T>
/**
 * @brief contains function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return bool Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for contains
 */
/**
 * @brief contains function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return bool Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for contains
 */
        bool contains(const Container& container, const T& value);
    }
}

#endif // DATA_STRUCTURES_H
