#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

struct Book {
    std::string title;
    std::string author;
    double price;
};

struct Bookstore {
    std::string name;
    std::vector<Book> books;
};

Bookstore* findBookstoreByName(std::vector<Bookstore>& bookstores, const std::string& name) {
    auto it = std::find_if(bookstores.begin(), bookstores.end(),
        [&](const Bookstore& bookstore) { return bookstore.name == name; });

    if (it != bookstores.end()) {
        return &(*it);
    }

    return nullptr;
}

double calculateTotalPrice(const Bookstore& bookstore) {
    double total = 0.0;
    for (const auto& book : bookstore.books) {
        total += book.price;
    }
    return total;
}

std::vector<Book> findBooksByAuthor(const std::vector<Bookstore>& bookstores, const std::string& author) {
    std::vector<Book> foundBooks;
    for (const auto& bookstore : bookstores) {
        for (const auto& book : bookstore.books) {
            if (book.author == author) {
                foundBooks.push_back(book);
            }
        }
    }
    return foundBooks;
}

int countBooksByAuthorInPriceRange(const std::vector<Bookstore>& bookstores, const std::string& author, double minPrice, double maxPrice) {
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

void writeBooksToFile(const std::vector<Book>& books, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& book : books) {
            file << "Title: " << book.title << "\n";
            file << "Author: " << book.author << "\n";
            file << "Price: " << book.price << "\n\n";
        }
        file.close();
        std::cout << "Books written to file: " << filename << std::endl;
    }
    else {
        std::cout << "Error opening file: " << filename << std::endl;
    }
}

void printBookInfo(const Book& book) {
    std::cout << "Title: " << book.title << "\n";
    std::cout << "Author: " << book.author << "\n";
    std::cout << "Price: " << book.price << "\n\n";
}

void printMinMaxPriceBooks(const std::vector<Bookstore>& bookstores) {
    double minPrice = std::numeric_limits<double>::max();
    double maxPrice = std::numeric_limits<double>::lowest();
    Book minPriceBook, maxPriceBook;

    for (const auto& bookstore : bookstores) {
        for (const auto& book : bookstore.books) {
            if (book.price < minPrice) {
                minPrice = book.price;
                minPriceBook = book;
            }
            if (book.price > maxPrice) {
                maxPrice = book.price;
                maxPriceBook = book;
            }
        }
    }

    std::cout << "Book with minimum price:\n";
    printBookInfo(minPriceBook);

    std::cout << "Book with maximum price:\n";
    printBookInfo(maxPriceBook);
}

Bookstore* findBookstoreWithBookCountGreaterThan(std::vector<Bookstore>& bookstores, int count) {
    auto it = std::find_if(bookstores.begin(), bookstores.end(),
        [&](const Bookstore& bookstore) { return bookstore.books.size() > count; });

    if (it != bookstores.end()) {
        return &(*it);
    }

    return nullptr;
}

bool hasAdjacentBooks(const Bookstore& bookstore) {
    for (size_t i = 0; i < bookstore.books.size() - 1; ++i) {
        const Book& currentBook = bookstore.books[i];
        const Book& nextBook = bookstore.books[i + 1];
        if (nextBook.price == 2 * currentBook.price) {
            return true;
        }
    }
    return false;
}

bool hasBookWithLowerPriceInOtherBookstore(const Bookstore& bookstore1, const Bookstore& bookstore2) {
    for (const auto& book1 : bookstore1.books) {
        for (const auto& book2 : bookstore2.books) {
            if (book1.title == book2.title && book1.price < book2.price) {
                return true;
            }
        }
    }
    return false;
}

std::pair<Book, Book> findFirstBooksPairWithDoublePrice(const Bookstore& bookstore1, const Bookstore& bookstore2) {
    for (const auto& book1 : bookstore1.books) {
        for (const auto& book2 : bookstore2.books) {
            if (book2.price == 2 * book1.price) {
                return std::make_pair(book1, book2);
            }
        }
    }
    return std::make_pair(Book{}, Book{});
}

bool areFirstThreeBooksSubsequence(const Bookstore& bookstore1, const Bookstore& bookstore2) {
    if (bookstore1.books.size() < 3 || bookstore2.books.size() < 3) {
        return false;
    }

    for (size_t i = 0; i < 3; ++i) {
        if (bookstore1.books[i].title != bookstore2.books[i].title ||
            bookstore1.books[i].author != bookstore2.books[i].author ||
            bookstore1.books[i].price != bookstore2.books[i].price) {
            return false;
        }
    }

    return true;
}

int main() {
    std::vector<Bookstore> bookstores = {
        {
            "Bookstore 1",
            {
                {"Book 1", "Author 1", 10.99},
                {"Book 2", "Author 2", 15.99},
                {"Book 3", "Author 1", 12.49}
            }
        },
        {
            "Bookstore 2",
            {
                {"Book 4", "Author 3", 8.99},
                {"Book 5", "Author 1", 11.99},
                {"Book 6", "Author 4", 9.99}
            }
        }
    };

    // Пошук магазину за назвою
    std::string searchName = "Bookstore 2";
    Bookstore* foundBookstore = findBookstoreByName(bookstores, searchName);
    if (foundBookstore) {
        std::cout << "Bookstore found: " << foundBookstore->name << std::endl;
    }
    else {
        std::cout << "Bookstore not found: " << searchName << std::endl;
    }

    // Обчислення загальної вартості книжок для знайденого магазину
    if (foundBookstore) {
        double totalPrice = calculateTotalPrice(*foundBookstore);
        std::cout << "Total price of books in " << foundBookstore->name << ": " << totalPrice << std::endl;
    }

    // Знайти книжки заданого автора та записати результат у файл
    std::string searchAuthor = "Author 1";
    std::vector<Book> foundBooks = findBooksByAuthor(bookstores, searchAuthor);
    writeBooksToFile(foundBooks, "books_by_author.txt");

    // Обчислити кількість книжок заданого автора ціна яких знаходиться у заданому діапазоні
    int count = countBooksByAuthorInPriceRange(bookstores, searchAuthor, 10.0, 15.0);
    std::cout << "Number of books by " << searchAuthor << " in price range [10.0, 15.0]: " << count << std::endl;

    // Вивести інформацію про книги з мінімальною та максимальною вартістю
    printMinMaxPriceBooks(bookstores);

    // Знайти магазин, кількість книжок якого більше за задане число
    int bookCountThreshold = 4;
    Bookstore* foundBookstoreWithCount = findBookstoreWithBookCountGreaterThan(bookstores, bookCountThreshold);
    if (foundBookstoreWithCount) {
        std::cout << "Bookstore with book count greater than " << bookCountThreshold << ": "
            << foundBookstoreWithCount->name << std::endl;
    }
    else {
        std::cout << "No bookstore with book count greater than " << bookCountThreshold << std::endl;
    }

    // Перевірити чи існує пара сусідніх книжок для заданого магазину таких, що ціна другої книги у двічі більша за першу
    if (foundBookstore) {
        bool hasAdjacent = hasAdjacentBooks(*foundBookstore);
        std::cout << "Adjacent books with price ratio 1:2 "
            << (hasAdjacent ? "exist" : "do not exist") << " in " << foundBookstore->name << std::endl;
    }

    // Перевірити чи існує у першому магазині така сама книга як у другому, але з меншою ціною
    if (bookstores.size() >= 2) {
        bool hasLowerPriceBook = hasBookWithLowerPriceInOtherBookstore(bookstores[0], bookstores[1]);
        std::cout << "Book with lower price in the first bookstore "
            << (hasLowerPriceBook ? "exists" : "does not exist") << " in the second bookstore" << std::endl;
    }

    // Знайти першу пару книжок таких, що ціна другої у двічі більша за першу
    if (bookstores.size() >= 2) {
        std::pair<Book, Book> booksPair = findFirstBooksPairWithDoublePrice(bookstores[0], bookstores[1]);
        if (booksPair.first.title != "" && booksPair.second.title != "") {
            std::cout << "First pair of books with price ratio 1:2:\n";
            std::cout << "Book 1:\n";
            printBookInfo(booksPair.first);
            std::cout << "Book 2:\n";
            printBookInfo(booksPair.second);
        }
        else {
            std::cout << "No pair of books with price ratio 1:2 found" << std::endl;
        }
    }

    // Перевірити, чи перші три книги зі списку книжок першого магазину утворюють підпослідовність у списку книжок другого магазину
    if (bookstores.size() >= 2) {
        bool areSubsequence = areFirstThreeBooksSubsequence(bookstores[0], bookstores[1]);
        std::cout << "First three books of the first bookstore "
            << (areSubsequence ? "form" : "do not form") << " a subsequence in the second bookstore" << std::endl;
    }

    return 0;
}