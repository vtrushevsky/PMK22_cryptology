#include <iostream>
#include <fstream>

using namespace std;

struct Node
{
	double area;
	double perimeter;
	Node* next;

	Node(): area(0), perimeter(0), next(nullptr) {}
	Node(double a, double p) : area(a), perimeter(p), next(nullptr) {}

	double GetArea() const { return area; }
	double GetPerimeter() const { return perimeter; }

	friend istream& operator >> (istream& is, Node& n)
	{
		is >> n.area;
		is >> n.perimeter;

		return is;
	}
};

class List
{
	Node n;
	Node *head;
	Node* tail;
	size_t size;

public:
	List() : head(nullptr), tail(nullptr), size(0) {}

	List(const List& other)
	{
		Node* curr = other.head;
		while (curr != nullptr)
		{
			AddEnd(curr->area, curr->perimeter);
			curr = curr->next;
		}
	}

	~List()
	{
		Node* current = head;
		while (current != nullptr)
		{
			Node* temp = current;
			current = current->next;
			delete temp;
		}
	}

	bool Empty() const { return head == nullptr; }
	size_t GetSize() const { return size; }

	double GetArea() const { return n.area; }
	double GetPerimeter() const { return n.perimeter; }

	void AddEnd(double area, double perimetr)
	{
		Node* new_node = new Node(area, perimetr);

		if (head == nullptr)
		{
			head = new_node;
			tail = new_node;
		}
		else
		{
			tail->next = new_node;
			tail = new_node;
		}
		size++;
	}

	void AddBegin(double area, double perimeter)
	{
		Node* new_node = new Node(area, perimeter);

		if (head == nullptr)
		{
			head = new_node;
			tail = new_node;
		}
		else
		{
			new_node->next = head;
			head = new_node;
		}
		size++;
	}

	bool Remove(Node* node_to_remove)
	{
		if (node_to_remove == nullptr || head == nullptr)
			return false;


		if (node_to_remove == head)
			head = head->next;
	
		else
		{
			Node* current = head;
			while (current->next != node_to_remove)
			{
				current = current->next;
				if (current == nullptr)
					return false;
				
			}

			current->next = node_to_remove->next;

			if (node_to_remove == tail)
				tail = current;

		}

		delete node_to_remove;
		size--;
		return true;
	}

	bool RemoveEnd()
	{
		if (head == nullptr)
		{
			return false;
		}
		size--;

		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
			tail = nullptr;
			return true;
		}

		Node* current = head;
		while (current->next->next != nullptr)
		{
			current = current->next;
		}

		delete current->next;
		current->next = nullptr;
		tail = current;
		return true;
	}

	Node* Find(double area, double perimeter)
	{
		Node* current = head;
		while (current != nullptr) 
		{
			if (current->area == area && current->perimeter == perimeter) 
			{
				return current;
			}

			current = current->next;
		}
		return nullptr;
	}

	void Print(ostream& out) const
	{
		Node* current = head;

		while (current != nullptr) 
		{
			out << "Area: " << current->area << "  " << "Perimeter: " << current->perimeter << endl;
			current = current->next;
		}
		out << endl;
	}

	friend ostream& operator << (ostream& out, const List l)
	{
		l.Print(out);
		return out;
	}
	friend istream& operator >>(istream& is, List& l) 
	{  
		double area, perimeter;
		is >> area >> perimeter;
		l.AddEnd(area, perimeter);
		return is;
	}

};

void BubbleSort(List* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j].GetArea() > arr[j + 1].GetArea())
			{
				auto temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main()
{
	int n;
	double limit1, limit2;

	ifstream f("Triangle.txt");
	f >> n;

	List* list = new List[n];

	int i = 0;
	while (!f.eof() && i < n)
	{
		f >> list[i];
		i++;
	}
	f.close();

	cout << "Input limit1 and limit2 ";
	cin >> limit1;
	cin >> limit2;

	ofstream out("File1.txt");

	BubbleSort(list, n);
	out << "Sorted list" << endl;
	for (int i = 0; i < n; i++)
		out << list[i];

	out << "Good perimeter " << endl;
	for (int i = 0; i < n; i++)
	{
		if (list[i].GetPerimeter() > limit1 && list[i].GetPerimeter() < limit2)
			out << list[i];
	}
	out.close();

	delete[]list;

	return 0;
}