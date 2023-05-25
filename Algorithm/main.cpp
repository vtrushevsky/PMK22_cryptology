#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iterator>
#include <numeric>

using namespace std;



class Bookstore {
private:
    vector<Book> bookss;
    string namee;
public:
    Bookstore(const string& name) : namee(name) {}

    Bookstore(const Bookstore& other) : namee(other.namee), bookss(other.bookss) {}

    Bookstore(Bookstore&& other) noexcept : namee(move(other.namee)), bookss(move(other.bookss)) {}

    const string& name() const { return namee; }

    const vector<Book>& books() const { return bookss; }

    void add_book(const Book& book) {
        bookss.push_back(book);
    }

    int countBooks() const {
        return bookss.size();
    }

    Book find_minPriceEbook() const {
        return *min_element(bookss.begin(), bookss.end(), [](const Book& book1, const Book& book2) {
            return book1.price() < book2.price();
            });
    }

    int countBookssby_bookAuthor(const string& bookAuthor) const {
        return count_if(bookss.begin(), bookss.end(), [&bookAuthor](const Book& book) {
            return book.bookAuthor() == bookAuthor;
            });
    }

    vector<Book> find_bookssby_bookAuthor(const string& bookAuthor) const {
        vector<Book> result;
        copy_if(bookss.begin(), bookss.end(), back_inserter(result), [&bookAuthor](const Book& book) {
            return book.bookAuthor() == bookAuthor;
            });
        return result;
    }

    double total_cost() const {
        return accumulate(bookss.begin(), bookss.end(), 0.0, [](double total, const Book& book) {
            return total + book.price();
            });
    }

    Book find_maxPriceEbook() const {
        return *max_element(bookss.begin(), bookss.end(), [](const Book& book1, const Book& book2) {
            return book1.price() < book2.price();
            });
    }

    void write_bookssby_bookAuthorrto_file(const string& bookAuthor) const {
        vector<Book> books = find_bookssby_bookAuthor(bookAuthor);

        ofstream outfile("bookss" + bookAuthor + ".txt");
        ostream_iterator<Book> out_iter(outfile, "\n");

        copy(books.begin(), books.end(), out_iter);
    }


    bool doublePriceNeighborsExist() const {
        if (countBooks() < 2) {
            return false;
        }
        for (auto it = bookss.begin(); it != bookss.end() - 1; ++it) {
            if ((it + 1)->price() == it->price() * 2) {
                return true;
            }
        }
        return false;
    }

    pair<Book, Book> searchfirstPairDoublePrice(const Bookstore& other_store) const {
        for (const auto& book : bookss) {
            for (const auto& other_book : other_store.books()) {
                if (book.price() == other_book.price() * 2) {
                    return make_pair(book, other_book);
                }
            }
        }
        throw runtime_error("No pair found");
    }

    bool has_cheaper_book(const Bookstore& other_store) const {
        for (const auto& book : bookss) {
            for (const auto& other_book : other_store.books()) {
                if (book.bookTitle() == other_book.bookTitle() && book.price() < other_book.price()) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isSubsequence(const vector<Book>& seq, const vector<Book>& target) const {
        if (seq.size() > target.size()) {
            return false;
        }
        auto it_seq = seq.begin();
        for (const auto& book : target) {
            if (*it_seq == book) {
                ++it_seq;
                if (it_seq == seq.end()) {
                    return true;
                }
            }
        }
        return false;
    }

    bool hasBookSubsequence(const Bookstore& other_store) const {
        if (countBooks() < 3 || other_store.countBooks() < 3) {
            return false;
        }
        return isSubsequence(vector<Book>(bookss.begin(), bookss.begin() + 3), other_store.books()) ||
            isSubsequence(vector<Book>(other_store.books().begin(), other_store.books().begin() + 3), bookss);
    }

};

class Book {
private:
    string bookTitlee;
    string bookAuthorr;
    double pricee;
    string currencyy;

public:
    Book(const string& bookTitle, const string& bookAuthor, double price, const string& currency) : bookTitlee(bookTitle), bookAuthorr(bookAuthor), pricee(price), currencyy(currency) {}

    const string& bookTitle() const { return bookTitlee; }

    const string& bookAuthor() const { return bookAuthorr; }

    double price() const { return pricee; }

    const string& currency() const { return currencyy; }

    bool operator == (const Book& other) const {
        return bookTitlee == other.bookTitlee && bookAuthorr == other.bookAuthorr && pricee == other.pricee && currencyy == other.currencyy;
    }

    friend ostream& operator<<(ostream& os, const Book& book) {
        os << book.bookTitle() << " by " << book.bookAuthor() << " price: " << book.price() << " " << book.currency();
        return os;
    }
};


const Bookstore* find_bookstore_by_name(const vector<Bookstore>& bookstores, const string& name) {

    auto it = find_if(bookstores.begin(), bookstores.end(), [&name](const Bookstore& bookstore) {
        return bookstore.name() == name;
        });
    return it != bookstores.end() ? &(*it) : nullptr;

}

vector<Bookstore> read_bookstores_from_file(const string& filename);

vector<Bookstore> read_bookstores_from_file(const string& filename) {
    vector<Bookstore> bookstores;

    ifstream infile(filename);
    string storeCity, name, bookTitle, bookAuthor, currency;

    double price;

    while (infile >> storeCity >> name >> bookTitle >> bookAuthor >> price >> currency) {
        bool found = false;
        for (auto& store : bookstores) {
            if (store.name() == name) {
                store.add_book(Book(bookTitle, bookAuthor, price, currency));
                found = true;
                break;
            }
        }
        if (!found) {
            bookstores.emplace_back(name);
            bookstores.back().add_book(Book(bookTitle, bookAuthor, price, currency));
        }
    }
    return bookstores;
}

int main() {
    vector<Bookstore> bookstores = read_bookstores_from_file("input.txt");
    const string bookstore_name = "bookstore2";
    const string otherBookstore_name = "bookstore";

    const Bookstore* storePtr = find_bookstore_by_name(bookstores, bookstore_name);

    if (storePtr == nullptr) {
        cout << "Bookstore " << bookstore_name << " not found." << endl;
        return 0;
    }

    const Bookstore& bookstore = *storePtr;

    cout << "Name of book: " << bookstore.name() << endl;

    cout << "Number of books: " << bookstore.countBooks() << endl;

    cout << "Total cost of books: " << bookstore.total_cost() << " " << bookstore.books().front().currency() << endl;

    const string bookSearchAuthor = "Leo_Tolstoy";

    int countBookssby_bookAuthor = bookstore.countBookssby_bookAuthor(bookSearchAuthor);

    cout << "Number of books by " << bookSearchAuthor << ": " << countBookssby_bookAuthor << endl;

    vector<Book> bookssby_bookAuthor = bookstore.find_bookssby_bookAuthor(bookSearchAuthor);
    for (const Book& book : bookssby_bookAuthor) {
        cout << book.bookTitle() << " by " << book.bookAuthor() << " (" << book.price() << " " << book.currency() << ")" << endl;
    }

    Book minPriceEbook = bookstore.find_minPriceEbook();
    cout << "Book minimum price: " << minPriceEbook.bookTitle() << " by " << minPriceEbook.bookAuthor() << " " << minPriceEbook.price() << " " << minPriceEbook.currency() << endl;

    Book maxPriceEbook = bookstore.find_maxPriceEbook();
    cout << "Book maximum price: " << maxPriceEbook.bookTitle() << " by " << maxPriceEbook.bookAuthor() << " " << maxPriceEbook.price() << " " << maxPriceEbook.currency() << endl;

    bookstore.write_bookssby_bookAuthorrto_file(bookSearchAuthor);
    cout << endl;


    const Bookstore& otherBookstore = *find_bookstore_by_name(bookstores, otherBookstore_name);
    const Bookstore* other_storePtr = find_bookstore_by_name(bookstores, otherBookstore_name);
    if (other_storePtr == nullptr) {
        cout << "Bookstore " << otherBookstore_name << " not found." << endl;
        return 0;
    }

    bool cheaperBookExists = bookstore.has_cheaper_book(otherBookstore);
    if (cheaperBookExists) {
        cout << "There is a book in " << bookstore.name() << " cheaper than in " << otherBookstore.name() << " " << minPriceEbook.bookTitle() << " " << minPriceEbook.price() << " " << minPriceEbook.currency() << endl;
    }
    else {
        cout << "There are no books in " << bookstore.name() << " cheaper than in " << otherBookstore.name() << endl;
    }

    bool doublePriceNeighborsExist = bookstore.doublePriceNeighborsExist();
    if (doublePriceNeighborsExist) {
        cout << "There are neighboring books with double price in " << bookstore.name() << endl;
    }
    else {
        cout << "There are no neighboring books with double price in " << bookstore.name() << endl;
    }

    try {
        pair<Book, Book> pair_with_double_price = bookstore.searchfirstPairDoublePrice(otherBookstore);
        cout << "The first pair of books with double price is: " << pair_with_double_price.first.bookTitle() << " by " << pair_with_double_price.first.bookAuthor() << " also " << pair_with_double_price.second.bookTitle() << " by " << pair_with_double_price.second.bookAuthor() << endl;
    }
    catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    bool hasBookSubsequence = bookstore.hasBookSubsequence(otherBookstore);
    if (hasBookSubsequence) {
        cout << "There is a subsequence of three books in " << bookstore.name() << " that is also in " << otherBookstore.name() << endl;
    }
    else {
        cout << "There are no subsequences of three books in " << bookstore.name() << " that are also in " << otherBookstore.name() << endl;
    }

    return 0;
}

