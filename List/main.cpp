#include <iostream>
#include <Windows.h>
#include <algorithm>

using namespace std;

class Shapes
{
private:
	string name;
	double S_Shapes;
public:
	Shapes(string n, double s): name(name), S_Shapes(s) {}


};

template <typename T>
class List
{
private:
	struct Node
	{
		Node(const T& _data, Node* _next) : data(_data), next(_next) {};
		Node* next;
		T data;
	};
	Node* head;
	size_t size;
public:

	List(): head(nullptr), size(0) {}
	~List()
	{
		while (head)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}

	void push(const T& value)
	{
		Node* nev = new Node(value, nullptr);
		Node *temp = head;
		this->size++;
		head = nev;
		nev->next = temp;
	}
	void pop()
	{
		if (this->size == 0)
		{
			throw std::out_of_range("List ÏÓÑÒÈÉ");
		}
		Node* toDelete = head;
		this->head = toDelete->next;
		delete toDelete;
		this->size--;
	}
	size_t size() { return this->size; }
	bool isEmpty() const
	{
		return size == 0;
	}

	const T top()
	{
		if (size == 0)
		{
			throw std::out_of_range("List ÏÓÑÒÈÉ")
		}
		return head->data;
	}
	const T find(size_t index)
	{
		T resoult;
		if (size < index)
		{
			throw std::out_of_range("ÂÈ ÂÈÉØËÈ ÇÀ ÐÎÇÌ²ÐÍ²ÑÒÜ ÏÀÌ'ßÒ²")
		}
		Node *temp1 = head;
		for (size_t i = 1; i < index; i++)
		{
			Node* temp =temp1->next;
			resoult = temp->data;
		}
		return resoult;
	}

	List sort()
	{
		T arr = new T[this->size];
		for (size_t i = 0; i < this->size; i++)
		{
			arr[i] = this->top;
			this->pop;
		}
		int n = sizeof(arr) / sizeof(arr[0]);
		QuickSort(arr, 0, n - 1);
		for (size_t i = n-1; 0<= i;i--)
		{
			this->push(arr[i]);
		}

	}

	void readTxt(string filename)
	{
		string line;
		T content;

		ifstream infile;
		infile.open(filename);

		if (!infile) {
			throw(ExceptionOpenFile)
		}

		while (getline(infile, line)) {
			content += line + "\n";
		}
		infile.close();

		for (char element : content)
		{
			this->push(element);
		}
	}
	void zapTxt(string filename)
	{
		ofstream outfile;
		outfile.open(filename);
		while (!this->isEmpty())
		{
			outfile << this->top() << endl;
		    this->pop();
		}
		outfile.close();
	}
};

template<typename T>
void QuickSort(T arr[], int left, int right)
{
	int i = left, j = right;
	T pivot = arr[(left + right) / 2];

	while (i <= j) {
		while (arr[i] < pivot) {
			i++;
		}
		while (arr[j] > pivot) {
			j--;
		}
		if (i <= j) {
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	if (left < j) {
		QuickSort(arr, left, j);
	}
	if (i < right) {
		QuickSort(arr, i, right);
	}
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	List<Shapes> list;
	try 
	{
		for (size_t i = 1; i <= 5; i++)
		{
			list.push(Shapes(" Òðèêóòíèê",i));
		}
		list.sort();
		list.zapTxt("resolt.txt");
	}
	catch (invalid_argument & a)
	{
		cout << a.what() << endl;
	}
	
	list.~List();
	return 0;
}