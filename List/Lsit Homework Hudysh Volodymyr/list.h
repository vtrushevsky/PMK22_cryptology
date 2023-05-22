#pragma once
template <typename T>
class DoubleLinkedList {
public:
    struct Node {
        T data;
        Node* prev;
        Node* next;

    };

private:
    Node* head;
    Node* tail;
    size_t size;


public:

    DoubleLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    DoubleLinkedList(const DoubleLinkedList& other) : head(nullptr), tail(nullptr), size(0) // copy constructor
    {
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
        return head->data;
    }

    Node* GetHead() const { return this->head; }

    void Clear()
    {
        while (head != nullptr)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        tail = nullptr;
        size = 0;
    }

    DoubleLinkedList& operator=(const DoubleLinkedList& other) // copy assignment operator
    {
        if (this != &other)
        {
            Clear();
            Copy(other);
        }
        return *this;
    }

    DoubleLinkedList& operator=(DoubleLinkedList&& other) noexcept // �������� ��������� �������
    {
        if (this != &other)
        {
            Clear();
            Move(move(other));
        }
        return *this;
    }


    void Copy(const DoubleLinkedList& other) // method copy
    {
        if (other.size == 0)
        {
            return;
        }
        head = new Node{ other.head->data, nullptr, nullptr };

        Node* current = head;
        Node* otherCurrent = other.head->next;

        while (otherCurrent != nullptr)
        {
            current->next = new Node{ otherCurrent->data, current, nullptr };
            current = current->next;
            otherCurrent = otherCurrent->next;
        }

        size = other.size;
    }

    DoubleLinkedList(DoubleLinkedList&& other) noexcept // constructor move
    {
        Move(move(other));
    }


    void Move(DoubleLinkedList&& other) noexcept
    {
        head = other.head;
        tail = other.tail;
        size = other.size;

        other.head = nullptr;
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
            head = new Node{ value, nullptr,nullptr };
            tail = head;

        }
        else
        {
            tail->next = new Node{ value, tail,nullptr };
            tail = tail->next;
        }

        size++;
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
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
        size--;
    }


    void PopFront()
    {
        if (size == 0)
        {
            return;
        }
        if (size == 1)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }

        size--;
    }


    void InsertBefore(Node* node, const T& value)
    {
        if (node == nullptr || node == head)
        {
            PushFront(value);
            return;
        }

        Node* prev = node->prev;
        Node* new_node = new Node(value);

        new_node->next = node;
        new_node->prev = prev;

        prev->next = new_node;
        node->prev = new_node;

        ++size;
    }

    void NodeDelete(Node* nodeToDelete)
    {
        if (nodeToDelete == nullptr)
        {
            return;
        }
        if (nodeToDelete == tail)
        {
            tail = nodeToDelete->prev;
        }
        if (nodeToDelete == head)
        {
            head = nodeToDelete->next;
        }
        if (nodeToDelete->prev != nullptr)
        {
            nodeToDelete->prev->next = nodeToDelete->next;
        }
        if (nodeToDelete->next != nullptr)
        {
            nodeToDelete->next->prev = nodeToDelete->prev;
        }
        delete nodeToDelete;

        size--;
    }

    void InsertAfter(Node* previousNode, const T& value)
    {
        if (previousNode == nullptr || previousNode == tail) {
            PushBack(value);
            return;
        }

        Node* newNode = new Node{ value, previousNode, previousNode->next };
        previousNode->next = newNode;
        newNode->next->prev = newNode;

        size++;
    }






    void PushFront(const T& value)
    {
        if (size == 0)
        {
            head = new Node{ value,nullptr, nullptr };
            tail = head;
        }
        else
        {
            head = new Node{ value, nullptr, head };
            head->next->prev = head;
        }
        size++;
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
        Iterator& operator--() { ptr = ptr->prev; return *this; } 
        Iterator operator--(int) { Iterator temp(*this); ptr = ptr->prev; return temp; }
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

    Iterator begin()const { return Iterator(head); }
    Iterator end()const { return Iterator(nullptr); }
};