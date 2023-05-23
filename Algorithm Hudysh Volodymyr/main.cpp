#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include <string>
using namespace std;

struct Book
{
	string nameOfBook;
	string author;
	double price;
};

struct BookStore
{
	string bookStoreName;
	vector<Book> books;
};


string searchBookStoreByName(const vector<BookStore>& bookStores, const string& storeName) 
{
	auto it = find_if(bookStores.begin(), bookStores.end(), [&storeName](const BookStore& store) {
		return store.bookStoreName == storeName;
		});

	if (it != bookStores.end()) {
		return it->bookStoreName;
	}
	else {
		return "Магазин не знайдено.";
	}
}
double calculatetotalCost(const BookStore& bookStore) 
{
	double totalCost = 0.0;

	for (const Book& book : bookStore.books) {
		totalCost += book.price;
	}

	return totalCost;
}



void findBooksByAuthor(const vector<BookStore>& bookStores, const string& author, const string& outputFile) 
{
	ofstream outFile(outputFile);

	if (!outFile) {
		cout << "Помилка відкриття файлу " << outputFile << endl;
		return;
	}

	for (const BookStore& bookStore : bookStores) {
		auto it = find_if(bookStore.books.begin(), bookStore.books.end(), [&author](const Book& book) {
			return book.author == author;
			});

		if (it != bookStore.books.end()) {
			outFile << "Магазин: " << bookStore.bookStoreName << endl;
			outFile << "Книги автора " << author << ":" << endl;

			auto printBook = [&outFile](const Book& book) {
				outFile << "- Назва: " << book.nameOfBook << ", Ціна: " << book.price << endl;
			};

			for_each(bookStore.books.begin(), bookStore.books.end(), [&author, &printBook](const Book& book) {
				if (book.author == author) {
					printBook(book);
				}
				});

			outFile << endl;
		}
	}

	outFile.close();
}

int countBooksByAuthorInPriceRange(const vector<BookStore>& bookStores, const string& author, double minPrice, double maxPrice)
{
	int count = 0;

	for (const BookStore& bookStore : bookStores) {
		count += count_if(bookStore.books.begin(), bookStore.books.end(), [&author, minPrice, maxPrice](const Book& book) {
			return book.author == author && book.price >= minPrice && book.price <= maxPrice;
			});
	}

	return count;
}

void printBooksMinMaxPrice(const vector<BookStore>& bookStores) 
{
	if (bookStores.empty())
		return;

	const auto minMaxPrice = minmax_element(bookStores.front().books.begin(), bookStores.front().books.end(), [](const Book& book1, const Book& book2) {
		return book1.price < book2.price;
		});

	cout << "Книга з мінімальною вартістю: " << minMaxPrice.first->nameOfBook << ", Ціна: " << minMaxPrice.first->price << endl;
	cout << "Книга з максимальною вартістю: " << minMaxPrice.second->nameOfBook << ", Ціна: " << minMaxPrice.second->price << endl;
}

vector<BookStore> findStoresWithBookCountGreaterThan(const vector<BookStore>& bookStores, int count) 
{
	vector<BookStore> result;

	copy_if(bookStores.begin(), bookStores.end(), back_inserter(result), [count](const BookStore& bookStore) {
		return bookStore.books.size() > count;
		});

	return result;
}

bool hasBooksPairWithDoublePrice(const BookStore& bookStore) 
{
	if (bookStore.books.size() < 2)
		return false;

	const auto it = adjacent_find(bookStore.books.begin(), bookStore.books.end(), [](const Book& book1, const Book& book2) {
		return book2.price == book1.price * 2.0;
		});

	return it != bookStore.books.end();
}

bool hasBookWithLowerPrice(const BookStore& firstStore, const BookStore& secondStore) 
{
	const auto& firstBooks = firstStore.books;
	const auto& secondBooks = secondStore.books;

	const auto it = find_if(firstBooks.begin(), firstBooks.end(), [&secondBooks](const Book& book) {
		return any_of(secondBooks.begin(), secondBooks.end(), [&book](const Book& otherBook) {
			return otherBook.nameOfBook == book.nameOfBook && otherBook.price < book.price;
			});
		});

	return it != firstBooks.end();
}
pair<Book, Book> FindFirstBookPairWithPriceRatio(const BookStore& firstBookstore, const BookStore& secondBookstore)
{
	for (const Book& firstBook : firstBookstore.books)
	{
		for (const Book& secondBook : secondBookstore.books)
		{
			if (secondBook.price == 2 * firstBook.price)
				return make_pair(firstBook, secondBook);

		}
	}

	return make_pair(Book{}, Book{});
}

void WriteToFile(const vector<Book>& books, const string& filename)
{
	ofstream outputFile(filename);

	for (const Book& book : books)
		outputFile << "Назва книги:  " << book.nameOfBook << ", автор " << book.author << ", ціна:  " << book.price << endl;


	outputFile.close();
}

bool AreFirstThreeBooksSubsequence(const BookStore& firstBookstore, const BookStore& secondBookstore)
{
	if (secondBookstore.books.size() < 3)
		return false;


	for (size_t i = 0; i < 3; i++)
	{
		const Book& firstBook = firstBookstore.books[i];
		const Book& secondBook = secondBookstore.books[i];

		if (firstBook.nameOfBook != secondBook.nameOfBook)
			return false;

	}

	return true;
}

vector<BookStore> ReadBookStoreFromFile(const string& filebookStoreName) {
	vector<BookStore> BookStores;
	ifstream inputFile(filebookStoreName);

	if (!inputFile)
	{
		cout << "Cannot Open File. Please rewrite file" << endl;
		return BookStores;
	}

	string line;
	while (getline(inputFile, line)) {
		BookStore BookStore;
		BookStore.bookStoreName = line;

		string bookName;
		string bookAuthor;
		double bookPrice;

		while (getline(inputFile, bookName) && !bookName.empty())
		{
			getline(inputFile, bookAuthor);
			inputFile >> bookPrice;
			inputFile.ignore();

			Book book;
			book.nameOfBook = bookName;
			book.author = bookAuthor;
			book.price = bookPrice;

			BookStore.books.push_back(book);
		}

		BookStores.push_back(BookStore);
	}

	inputFile.close();

	return BookStores;
}

int main()
{
	vector<BookStore> bookstore = ReadBookStoreFromFile("Bookstore.txt");
}
