#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Book {
	string title;
	string author;
	double price;
};

struct Bookstore {
	string name;
	vector<Book> books;
};

// Функція для пошуку книжкового магазину за назвою
Bookstore FindBookstoreByName(const vector<Bookstore>& bookstores, const string& name)
{
	auto it = find_if(bookstores.begin(), bookstores.end(), [&](const Bookstore& bs) {
		return bs.name == name;
		});

	if (it != bookstores.end())
		return *it;


	// Повертаємо порожній об'єкт Bookstore, якщо магазин не знайдено
	return Bookstore{};
}

// Функція для обчислення загальної вартості книжок у магазині
double CalculateTotalPrice(const Bookstore& bookstore)
{
	double totalPrice = 0.0;

	for (const Book& book : bookstore.books)
		totalPrice += book.price;


	return totalPrice;
}

vector<Book> FindBooksByAuthor(const vector<Bookstore>& bookstores, const string& author)
{
	vector<Book> foundBooks;

	for (const Bookstore& bookstore : bookstores)
	{
		for (const Book& book : bookstore.books)
		{
			if (book.author == author)
				foundBooks.push_back(book);
		}
	}

	return foundBooks;
}

// Функція для запису книжок у файл
void WriteToFile(const vector<Book>& books, const string& filename)
{
	ofstream outputFile(filename);

	for (const Book& book : books)
		outputFile << "Назва: " << book.title << ", Автор: " << book.author << ", Ціна: " << book.price << endl;


	outputFile.close();
}

int CountBooksByAuthorWithPriceRange(const vector<Bookstore>& bookstores, const string& author, double minPrice, double maxPrice)
{
	int count = 0;

	for (const Bookstore& bookstore : bookstores)
	{
		for (const Book& book : bookstore.books)
		{
			if (book.author == author && book.price >= minPrice && book.price <= maxPrice)
				count++;
		}
	}

	return count;
}

void FindBooksByPriceRange(const vector<Bookstore>& bookstores, double& minPrice, double& maxPrice, vector<Book>& minPriceBooks, vector<Book>& maxPriceBooks)
{
	for (const Bookstore& bookstore : bookstores)
	{
		for (const Book& book : bookstore.books)
		{
			if (book.price < minPrice)
			{
				minPrice = book.price;
				minPriceBooks.clear();
				minPriceBooks.push_back(book);
			}

			else if (book.price == minPrice)
				minPriceBooks.push_back(book);

			if (book.price > maxPrice)
			{
				maxPrice = book.price;
				maxPriceBooks.clear();
				maxPriceBooks.push_back(book);
			}

			else if (book.price == maxPrice)
				maxPriceBooks.push_back(book);

		}
	}
}

Bookstore FindBookstoreWithBookCountGreaterThan(const vector<Bookstore>& bookstores, int count)
{
	auto it = find_if(bookstores.begin(), bookstores.end(), [&](const Bookstore& bs) {
		return bs.books.size() > count;
		});

	if (it != bookstores.end())
		return *it;


	return Bookstore{};
}

bool HasNeighboringBooks(const Bookstore& bookstore)
{
	for (size_t i = 0; i < bookstore.books.size() - 1; i++)
	{
		const Book& currentBook = bookstore.books[i];
		const Book& nextBook = bookstore.books[i + 1];

		if (nextBook.price == 2 * currentBook.price)
			return true;
	}

	return false;
}

bool HasBookWithLowerPrice(const Bookstore& firstBookstore, const Bookstore& secondBookstore)
{
	for (const Book& book : firstBookstore.books)
	{
		auto it = find_if(secondBookstore.books.begin(), secondBookstore.books.end(), [&](const Book& otherBook) {
			return book.title == otherBook.title && book.price < otherBook.price;
			});

		if (it != secondBookstore.books.end())
			return true;

	}

	return false;
}

pair<Book, Book> FindFirstBookPairWithPriceRatio(const Bookstore& firstBookstore, const Bookstore& secondBookstore)
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

bool AreFirstThreeBooksSubsequence(const Bookstore& firstBookstore, const Bookstore& secondBookstore)
{
	if (secondBookstore.books.size() < 3)
		return false;


	for (size_t i = 0; i < 3; i++)
	{
		const Book& firstBook = firstBookstore.books[i];
		const Book& secondBook = secondBookstore.books[i];

		if (firstBook.title != secondBook.title)
			return false;

	}

	return true;
}

vector<Bookstore> ReadBookstoresFromFile(const string& filename) {
	vector<Bookstore> bookstores;
	ifstream inputFile(filename);

	if (!inputFile)
	{
		cout << "Помилка при відкритті файлу." << endl;
		return bookstores;
	}

	string line;
	while (getline(inputFile, line)) {
		Bookstore bookstore;
		bookstore.name = line;

		string bookTitle;
		string bookAuthor;
		double bookPrice;

		while (getline(inputFile, bookTitle) && !bookTitle.empty()) 
		{
			getline(inputFile, bookAuthor);
			inputFile >> bookPrice;
			inputFile.ignore(); // Ігноруємо символ нового рядка

			Book book;
			book.title = bookTitle;
			book.author = bookAuthor;
			book.price = bookPrice;

			bookstore.books.push_back(book);
		}

		bookstores.push_back(bookstore);
	}

	inputFile.close();

	return bookstores;
}


int main()
{
	vector<Bookstore> bookstore = ReadBookstoresFromFile("bookstores.txt");

	FindBooksByAuthor(bookstore, "George Orwell");


	return 0;
}