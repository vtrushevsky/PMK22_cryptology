#pragma once
template <typename T>
class DoubleLinkedList {
public:
    struct Node {
        T data;
        Node* previous;
        Node* next;

    };

private:
    Node* top;
    Node* tail;
    size_t size;


public:

    DoubleLinkedList() : top(nullptr), tail(nullptr), size(0) {}

    DoubleLinkedList(const DoubleLinkedList& other) : top(nullptr), tail(nullptr), size(0) {

        if (other.size != 0)
        {
            Copy(other);
        }

    }

    T& Back()
    {
        return tail->data;
    }

    T& Front()
    {
        return top->data;
    }

    Node* Gettop() const { return this->top; }

    void Clear()
    {
        while (top != nullptr)
        {
            Node* temp = top;
            top = top->next;
            delete temp;
        }

        tail = nullptr;
        size = 0;
    }

    DoubleLinkedList& operator=(const DoubleLinkedList& other)
    {
        if (this != &other)
        {
            Clear();
            Copy(other);
        }
        return *this;
    }

    DoubleLinkedList& operator=(DoubleLinkedList&& other) noexcept
    {
        if (this != &other)
        {
            Clear();
            Move(move(other));
        }
        return *this;
    }

    void Copy(const DoubleLinkedList& other)
    {
        if (other.size == 0)
        {
            return;
        }
        top = new Node{ other.top->data, nullptr, nullptr };

        Node* current = top;
        Node* otherCurrent = other.top->next;

        while (otherCurrent != nullptr)
        {
            current->next = new Node{ otherCurrent->data, current, nullptr };
            current = current->next;
            otherCurrent = otherCurrent->next;
        }

        size = other.size;
    }

    DoubleLinkedList(DoubleLinkedList&& other) noexcept
    {
        Move(move(other));
    }

    void Move(DoubleLinkedList&& other) noexcept
    {
        top = other.top;
        tail = other.tail;
        size = other.size;

        other.top = nullptr;
        other.tail = nullptr;
        other.size = 0;
    }

    ~DoubleLinkedList()
    {
        Clear();
    }

    size_t getSize() const {
        return size;
    }

    bool isEmpty() const {
        return size == 0;
    }

    void PushBack(const T& value)
    {
        if (size == 0)
        {
            top = new Node{ value, nullptr,nullptr };
            tail = top;

        }
        else
        {
            tail->next = new Node{ value, tail,nullptr };
            tail = tail->next;
        }

        size++;
    }

    void PopFront()
    {
        if (size == 0)
        {
            return;
        }
        if (size == 1)
        {
            delete top;
            top = nullptr;
            tail = nullptr;
        }
        else
        {
            Node* temp = top;
            top = top->next;
            top->previous = nullptr;
            delete temp;
        }

        size--;
    }

    void PopBack()
    {
        if (size == 0)
        {
            return;
        }
        if (size == 1)
        {
            delete tail;
            top = nullptr;
            tail = nullptr;
        }
        else
        {
            Node* temp = tail;
            tail = tail->previous;
            tail->next = nullptr;
            delete temp;
        }
        size--;
    }

    void InsertBefore(Node* node, const T& value)
    {
        if (node == nullptr || node == top)
        {
            PushFront(value);
            return;
        }

        Node* previous = node->previous;
        Node* new_node = new Node(value);

        new_node->next = node;
        new_node->previous = previous;

        previous->next = new_node;
        node->previous = new_node;

        ++size;
    }

    void InsertAfter(Node* previousiousNode, const T& value)
    {
        if (previousiousNode == nullptr || previousiousNode == tail) {
            PushBack(value);
            return;
        }

        Node* newNode = new Node{ value, previousiousNode, previousiousNode->next };
        previousiousNode->next = newNode;
        newNode->next->previous = newNode;

        size++;
    }

    void PushFront(const T& value)
    {
        if (size == 0)
        {
            top = new Node{ value,nullptr, nullptr };
            tail = top;
        }
        else
        {
            top = new Node{ value, nullptr, top };
            top->next->previous = top;
        }
        size++;
    }

    void NodeDelete(Node* nodeToDelete)
    {
        if (nodeToDelete == nullptr)
        {
            return;
        }
        if (nodeToDelete == tail)
        {
            tail = nodeToDelete->previous;
        }
        if (nodeToDelete == top)
        {
            top = nodeToDelete->next;
        }
        if (nodeToDelete->previous != nullptr)
        {
            nodeToDelete->previous->next = nodeToDelete->next;
        }
        if (nodeToDelete->next != nullptr)
        {
            nodeToDelete->next->previous = nodeToDelete->previous;
        }
        delete nodeToDelete;

        size--;
    }

    class Iterator
    {

    private:

        Node* ptr;

    public:
        Iterator(Node* ptr) : ptr(ptr) {}


        T& operator*() const { return ptr->data; }

        Iterator& operator++() { ptr = ptr->next; return *this; }

        Iterator operator++(int) { Iterator temp(*this); ptr = ptr->next; return temp; }

        Iterator& operator--() { ptr = ptr->previous; return *this; }

        Iterator operator--(int) { Iterator temp(*this); ptr = ptr->previous; return temp; }

        bool operator!=(const Iterator& other) const { return ptr != other.ptr; }

        bool operator==(const Iterator& other) const { return ptr == other.ptr; }

        friend class DoubleLinkedList;
    };

    Iterator Find(const T& value) const {
        for (Iterator it = *this; it != end(); ++it) {
            if (*it == value) {
                return it;
            }
        }
        return end();
    }

    Iterator begin()const { return Iterator(top); }
    Iterator end()const { return Iterator(nullptr); }
};