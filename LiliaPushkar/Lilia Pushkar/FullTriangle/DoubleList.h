#pragma once
#include <iostream>

using namespace std;

template <typename T>
class DoubleList 
{
private:
	struct Node {
		T data;
		Node* prev;
		Node* next;

		Node(const T& value, Node* p = nullptr, Node* n = nullptr)
			: data(value), prev(p), next(n) {}

		
	};

	Node* head;
	Node* tail;
	int size;

public:

	DoubleList() : head(nullptr), tail(nullptr), size(0) {}
	DoubleList(const DoubleList& other) : head(nullptr), tail(nullptr), size(0) { *this = other; }
	DoubleList(DoubleList&& other) noexcept : head(nullptr), tail(nullptr);
	~DoubleList() { Clear(); }


	DoubleList& operator=(const DoubleList& other) noexcept;

	void PushFront(const T& value);
	void PushBack(const T& value);
	void Insert(Node* node, const T& value);
	void Sort();
	Node* FindNode(const T& value) const;
	void MoveList(DoubleList&& other) noexcept;
	void CopyList(const DoubleList& other);


	void PopFront();
	void PopBack();
	void Clear();
	void remove(const Iterator& iterator);

	T& front() { return head->data; }
	T& back() { return tail->data; }
	const T& front() const { return head->data; }
	const T& back() const { return tail->data; }


	bool Empty() const { return size == 0; }
	int GetSize() const { return size; }

	class Iterator {
	private:
		Node* node;

	public:
		Iterator(Node* n = nullptr) : node(n) {}

		Iterator& operator++() { node = node->next; return *this; }
		Iterator& operator--() { node = node->prev; return *this; }

		bool operator==(const Iterator& other) const { return node == other.node; }
		bool operator!=(const Iterator& other) const { return node != other.node; }

		T& operator*() { return node->data; }
		const T& operator*() const { return node->data; }

		Node* GetNode const(){ return node; }

	};

	Iterator begin() const { return Iterator(head); }
	Iterator end() const { return Iterator(nullptr); }
};
