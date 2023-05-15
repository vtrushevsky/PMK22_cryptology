
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
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

// Функція для пошуку магазину за назвою
Bookstore* findBookstoreByName(const vector<Bookstore>& bookstores, const string& name) {
auto it = find_if(bookstores.begin(), bookstores.end(), [&name](const Bookstore& bookstore) {
return bookstore.name == name;
});

if (it != bookstores.end()) {
    return const_cast<Bookstore*>(&(*it));
}
throw runtime_error("Bookstore not found.");
}


Bookstore* findBookstoreByBookCount(const vector<Bookstore>& bookstores, int requiredBookCount) {
    for ( const Bookstore& bookstore : bookstores) {
        if (bookstore.books.size() == requiredBookCount) {
            return const_cast<Bookstore*>(&bookstore);
        }
    }
    return nullptr;
}

double calculateTotalPrice(const Bookstore& bookstore) {
    double totalPrice = 0.0;
    for (const auto& book : bookstore.books) {
        totalPrice += book.price;
    }
    return totalPrice;
}

void findBooksByAuthor(const vector<Bookstore>& bookstores, const string& author, const string& outputFile) {
    ofstream output(outputFile);
    if (output.is_open()) {
        for (const auto& bookstore : bookstores) {
            for (const auto& book : bookstore.books) {
                if (book.author == author) {
                    output << "Title: " << book.title << ", Author: " << book.author << ", Price: " << book.price << endl;
                }
            }
        }
        output.close();
    } else {
        cout << "Failed to open the output file." << endl;
    }
}

// Функція для обчислення кількості книжок заданого автора в заданому діапазоні цін
int countBooksByAuthorInRange(const vector<Bookstore>& bookstores, const string& author, double minPrice, double maxPrice) {
    int count = 0;
    for (const auto& bookstore : bookstores) {
        for (const auto& book : bookstore.books) {
            if (book.author == author && book.price >= minPrice && book.price <= maxPrice) {
                count++;
            }
        }
    }
    return count;
}

// Функція для виведення інформації про книги з мінімальною та максимальною вартістю
void printMinMaxPriceBooks(const vector<Bookstore>& bookstores) {
auto minmaxPrice = minmax_element(bookstores.begin(), bookstores.end(), [](const Bookstore& b1, const Bookstore& b2) {
return min_element(b1.books.begin(), b1.books.end(), [](const Book& book1, const Book& book2) {
return book1.price < book2.price;
})->price < min_element(b2.books.begin(), b2.books.end(), [](const Book& book1, const Book& book2) {
return book1.price < book2.price;
})->price;
});
    if (minmaxPrice.first != bookstores.end() && minmaxPrice.second != bookstores.end()) {
        const Book& minPriceBook = *min_element(minmaxPrice.first->books.begin(), minmaxPrice.first->books.end(), [](const Book& book1, const Book& book2) {
            return book1.price < book2.price;
        });
        const Book& maxPriceBook = *max_element(minmaxPrice.second->books.begin(), minmaxPrice.second->books.end(), [](const Book& book1, const Book& book2) {
            return book1.price < book2.price;
        });

        cout << "Book with minimum price: Title: " << minPriceBook.title << ", Author: " << minPriceBook.author << ", Price: " << minPriceBook.price << endl;
        cout << "Book with maximum price: Title: " << maxPriceBook.title << ", Author: " << maxPriceBook.author << ", Price: " << maxPriceBook.price << endl;
    } else {
        cout << "No bookstores available." << endl;
    }
}


// Функція для перевірки, чи існує пара сусідніх книжок для заданого магазину, таких що ціна другої книги у двічі більша за першу
bool hasAdjacentBooksDoublePrice(const Bookstore& bookstore) {
if (bookstore.books.size() < 2) {
return false;
}
for (size_t i = 0; i < bookstore.books.size() - 1; i++) {
    const Book& book1 = bookstore.books[i];
    const Book& book2 = bookstore.books[i + 1];

    if (book2.price >= book1.price * 2.0) {
        return true;
    }
}

return false;
}

// Функція для перевірки, чи існує у першому магазині така сама книга як у другому, але з меншою ціною
bool hasSameBookWithLowerPrice(const Bookstore& bookstore1,const Bookstore& bookstore2) {
for (const auto& book1 : bookstore1.books) {
for (const auto& book2 : bookstore2.books) {
if (book1.title == book2.title && book1.price < book2.price) {
return true;
}
}
}

return false;
}

// Функція для знаходження першої пари книжок для двох заданих магазинів, таких що ціна другої у двічі більша за першу
pair<Book, Book> findFirstPairWithDoublePrice(const Bookstore& bookstore1, const Bookstore& bookstore2) {
for (const auto& book1 : bookstore1.books) {
for (const auto& book2 : bookstore2.books) {
if (book2.price >= book1.price * 2.0) {
return make_pair(book1, book2);
}
}
}

return make_pair(Book{}, Book{}); // Return empty pair if no such pair is found
}

// Функція для перевірки, чи перші три книги зі списку книжок заданого магазину утворюють підпослідовність у списку книжок другого магазину
bool isSubsequence(const Bookstore& bookstore1, const Bookstore& bookstore2) {
if (bookstore1.books.size() < 3 || bookstore2.books.size() < 3) {
return false;
}

for (size_t i = 0; i < 3; i++) {
    if (bookstore1.books[i].title != bookstore2.books[i].title) {
        return false;
    }
}

return true;
}

int main() {
// Зчитування даних з файлу
ifstream input("/Users/solomia/Desktop/algorithm/algorithm/bookstores.txt");
if (!input.is_open()) {
cout << "Failed to open the input file." << endl;
return 1;
}

vector<Bookstore> bookstores;

string line;
while (getline(input, line)) {
    if (line.empty()) {
        continue; // Пропускаємо порожні рядки
    }

    // Отримуємо назву магазину
    string bookstoreName = line;

    // Отримуємо кількість книжок у магазині
    getline(input, line);
    int bookCount = stoi(line);

    // Отримуємо дані про книжки
    vector<Book> books;
    for (int i = 0; i < bookCount; i++) {
        Book book;
        getline(input, book.title);
        getline(input, book.author);
        getline(input, line);
        book.price = stod(line);
        books.push_back(book);
    }

    // Створюємо об'єкт магазину та додаємо його до вектора
    Bookstore bookstore;
    bookstore.name = bookstoreName;
    bookstore.books = books;
    bookstores.push_back(bookstore);
}

input.close();

    string author = "Zoe";
    string outputFile = "/Users/solomia/Desktop/algorithm/algorithm/books_by_author.txt";
    findBooksByAuthor(bookstores, author, outputFile);
    double minPrice = 10.0;
    double maxPrice = 20.0;
    


// Виклик функції для обчислення кількості книжок заданого автора в заданому діапазоні цін
int bookCount = countBooksByAuthorInRange(bookstores, author, minPrice, maxPrice);
cout << "Number of books by author " << author << " in price range $" << minPrice << " - $" << maxPrice << ": " << bookCount << endl;

// Виклик функції для виведення інформації про книги з мінімальною та максимальною вартістю
printMinMaxPriceBooks(bookstores);

int requiredBookCount = 5;
// Виклик функції для знаходження магазину, кількість книжок якого більша за задане число
Bookstore* bookstoreWithRequiredCount = findBookstoreByBookCount(bookstores, requiredBookCount);
if (bookstoreWithRequiredCount != nullptr) {
    cout << "Bookstore with more than " << requiredBookCount << " books: " << bookstoreWithRequiredCount->name << endl;
} else {
    cout << "No bookstore found with more than " << requiredBookCount << " books." << endl;
}

// Виклик функції для перевірки, чи існує пара сусідніх книжок для заданого магазину, таких що ціна другої книги у двічі більша за першу
bool hasAdjacentBooksDouble = hasAdjacentBooksDoublePrice(bookstores[0]);
if (hasAdjacentBooksDouble) {
    cout << "Bookstore " << bookstores[0].name << " has adjacent books with the second book price double the first book price." << endl;
} else {
    cout << "No adjacent books found in bookstore " << bookstores[0].name << " with the second book price double the first book price." << endl;
}

// Виклик функції для перевірки, чи існує у першому магазині така сама книга як у другому, але з меншою ціною
bool hasSameBookLowerPrice = hasSameBookWithLowerPrice(bookstores[0], bookstores[1]);
if (hasSameBookLowerPrice) {
    cout << "Bookstore " << bookstores[0].name << " has a book with the same title as bookstore " << bookstores[1].name << " but with a lower price." << endl;
} else {
    cout << "No book found in bookstore " << bookstores[0].name << " with the same title as bookstore " << bookstores[1].name << " but with a lower price." << endl;
}

// Виклик функції для знаходження першої пари книжок для двох заданих магазинів, таких що ціна другої у двічі більша за першу
pair<Book, Book> firstPairWithDoublePrice = findFirstPairWithDoublePrice(bookstores[0], bookstores[1]);
if (!firstPairWithDoublePrice.first.title.empty() && !firstPairWithDoublePrice.second.title.empty()) {
cout << "First pair of books with the second book price double the first book price:" << endl;
cout << "Book 1: " << firstPairWithDoublePrice.first.title << ", Price: $" << firstPairWithDoublePrice.first.price << endl;
cout << "Book 2: " << firstPairWithDoublePrice.second.title << ", Price: $" << firstPairWithDoublePrice.second.price << endl;
} else {
cout << "No pair of books found with the second book price double the first book price." << endl;
}

// Виклик функції для перевірки, чи перші три книги зі списку книжок заданого магазину утворюють підпослідовність у списку книжок другого магазину
bool isSubsequenceExists = isSubsequence(bookstores[0], bookstores[1]);
if (isSubsequenceExists) {
    cout << "The first three books in bookstore " << bookstores[0].name << " form a subsequence in bookstore " << bookstores[1].name << "." << endl;
} else {
    cout << "The first three books in bookstore " << bookstores[0].name << " do not form a subsequence in bookstore " << bookstores[1].name << "." << endl;
}

return 0;
}






