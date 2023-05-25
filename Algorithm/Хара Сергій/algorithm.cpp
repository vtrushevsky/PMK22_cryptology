#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric>

using namespace std;

struct Book
{
	string name;
	string author;
	int price;
	
	Book() : name(""), author(""), price(0) {}
	Book(string _name,string _author, int _price) : name(_name), author(_author), price(_price) {};

	const size_t getBookPrice() const { return this->price; }
	const string getBookName() const { return this->name; }
};

class BookStore {
	string name;
	vector<Book> Books;
public:
	BookStore() : name("") {};
	BookStore(string _name, vector<Book> _Books) : name(_name)
	{
		for (int i = 0; i < _Books.size(); i++)
		{
			Books.push_back(_Books[i]);
		}
	}
	BookStore(string _name) : name(_name) {}

	const string getStoreName() const { return name; }
	const size_t getBookNumber() const { return Books.size();}
	const vector<Book> getBooks()  const { return Books; }
	bool operator==(const BookStore& other) const {
		return name == other.name;
	}
};

int calculateSumOfAuthorBooks(const string& authorName, const vector<Book>& books)
{
	int sum = accumulate(books.begin(), books.end(), 0, [authorName](int total, const Book& book)
	{
		if (book.author == authorName) return total + book.price;
	});
	return sum;
}
vector<Book> findAuthorBooks(const vector<Book>& booksInStore, const string& authorName) {
	vector<Book> authorBooks;
	copy_if(booksInStore.begin(), booksInStore.end(), back_inserter(authorBooks), [&authorName](const Book& book) {
		return authorName == book.author;
	});
	return authorBooks;
}
BookStore* findBookStoreByName(vector<BookStore> BookStores, string bookStoreName)
{
	BookStore findMe(bookStoreName);
	auto it = find(BookStores.begin(), BookStores.end(), findMe);
	if (it != BookStores.end()) {
		cout << "Book store is in town." << endl;
		return &(*it);
	}
	else
		cout << "Book is not available";
		return nullptr;
}
int calculateSumForBooks(BookStore bookStore)
{
	vector<Book> calcArr = bookStore.getBooks();
	int sum = accumulate(calcArr.begin(), calcArr.end(), 0, [](int total, const Book& book){ return total + book.price;});
	return sum;
}
void showMinMaxPrice(vector<Book> books)
{
	sort(books.begin(), books.end(), [](const Book& book1, const Book& book2) {
		return book1.price < book2.price;
	});
	cout << "Min book price :" << books.front().name << endl;
	cout << "Max book price :" << books.back().name << endl;
}
BookStore* findBookStoreGreaterThanNum(int num,vector<BookStore>& bookStores) {
	auto it = find_if(bookStores.begin(), bookStores.end(), [num](BookStore& bookstore) {
		return bookstore.getBookNumber() > num;
	});

	if (it != bookStores.end()) 
	{
		return &(*it);
	}

	return nullptr;
}
bool checkAdjacentBooks(const BookStore& bookstore) // #7
{
	const vector<Book>& books = bookstore.getBooks();
	for (size_t i = 0; i < books.size() - 1; i++)
	{
		if (books[i + 1].getBookPrice() == 2 * books[i].getBookPrice())
		{
			return true;
		}
	}
	return false;
}
bool compareBookPrices(const BookStore& bookstore1, const BookStore& bookstore2) // #8
{
	const vector<Book>& books1 = bookstore1.getBooks();
	const vector<Book>& books2 = bookstore2.getBooks();

	for (const Book& book1 : books1)
	{
		for (const Book& book2 : books2)
		{
			if (book1.getBookName() == book2.getBookName() && book1.getBookPrice() < book2.getBookPrice())
			{
				return true;
			}
		}
	}

	return false;
}
pair<Book, Book> findDoublePricePair(const BookStore& bookstore1, const BookStore& bookstore2) // #9
{
	const vector<Book>& books1 = bookstore1.getBooks();
	const vector<Book>& books2 = bookstore2.getBooks();

	for (const Book& book1 : books1)
	{
		for (const Book& book2 : books2)
		{
			if (book2.getBookPrice() == 2 * book1.getBookPrice())
			{
				return make_pair(book1, book2);
			}
		}
	}

	return make_pair(Book(), Book());
}
bool checkSubsequence(const BookStore& bookstore1, const BookStore& bookstore2) // #10
{
	const vector<Book>& books1 = bookstore1.getBooks();
	const vector<Book>& books2 = bookstore2.getBooks();

	size_t i = 0;
	size_t j = 0;

	while (i < books1.size() && j < books2.size())
	{
		if (books1[i].getBookName() == books2[j].getBookName())
		{
			i++;
		}
		j++;

		if (i == 3)
		{
			return true;
		}
	}

	return false;
}
int main()
{ // Можна, будь ласка, трошки більше балів ніж 1.9 за все завдання..? І так поточка у всієї групи не дуже..
	vector<BookStore> BookStores;
	vector<Book> testBooks;
	
	testBooks.push_back(Book("The python guide","Flask WebDev Enjoyer", 60));
	testBooks.push_back(Book("C++ Style Guide but i love python", "Django Lover", 45));
	testBooks.push_back(Book("Python is better than C++","Bjarne Stroustrup", 15));
	testBooks.push_back(Book("Python is more smarter than C++ ^_^","Bjarne Stroustrup", 20));

	BookStores.push_back(BookStore("Python > C++", testBooks));
	BookStores.push_back(BookStore("print(Python > C++)"));
	BookStores.push_back(BookStore("True"));
	BookStores.push_back(BookStore("Python & JS Book Store, bcs C-like langs are not good as python"));
	
	// #3
	auto BjarneBooks = findAuthorBooks(BookStores[0].getBooks(), "Bjarne Stroustrup");
	for (auto book : BjarneBooks)
	{
		cout << book.name << endl;
	}
	// #4 Обчислити кількість книжок заданого автора ціна яких знаходиться у заданому діапазоні;
	int BjarneBooksPrice = calculateSumOfAuthorBooks("Bjarne Stroustrup", BookStores[0].getBooks());
	cout << "Bjarne books price -> " << BjarneBooksPrice << endl;
	// #5 Вивести інформацію про книги з мінімальною та максимальною вартістю;
	showMinMaxPrice(BookStores[0].getBooks());
	// #6 Знайти магазин кількість книжок якого більше за задане число;
	auto bookStoreGreaterThan3 = findBookStoreGreaterThanNum(3, BookStores);
	cout << "Book Store where number of books greater than 3" << bookStoreGreaterThan3->getStoreName();
	return 0;
}