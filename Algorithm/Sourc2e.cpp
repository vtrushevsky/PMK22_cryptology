#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iterator>
#include <numeric>

using namespace std;

class Book {
public:
    Book(const string& title, const string& author, double price, const string& currency)
        : title_(title), author_(author), price_(price), currency_(currency)
    {}

    const string& title() const { return title_; }
    const string& author() const { return author_; }
    double price() const { return price_; }
    const string& currency() const { return currency_; }

    bool operator == (const Book& other) const {
        return title_ == other.title_ && author_ == other.author_ && price_ == other.price_ && currency_ == other.currency_;
    }

    friend ostream& operator<<(ostream& os, const Book& book) {
        os << book.title() << " by " << book.author() << ", price: " << book.price() << " " << book.currency();
        return os;
    }

private:
    string title_;
    string author_;
    double price_;
    string currency_;
};

class Bookstore {
public:
    Bookstore(const string& name)
        : name_(name)
    {}

    Bookstore(const Bookstore& other) : name_(other.name_), books_(other.books_) {}

    Bookstore(Bookstore&& other) noexcept : name_(move(other.name_)), books_(move(other.books_)) {}

    void add_book(const Book& book) {
        books_.push_back(book);
    }

    const string& name() const { return name_; }

    const vector<Book>& books() const { return books_; }

    double total_cost() const {
        return accumulate(books_.begin(), books_.end(), 0.0, [](double total, const Book& book) {
            return total + book.price();
            });
    }

    int num_books() const {
        return books_.size();
    }

    int num_books_by_author(const string& author) const {
        return count_if(books_.begin(), books_.end(), [&author](const Book& book) {
            return book.author() == author;
            });
    }

    vector<Book> find_books_by_author(const string& author) const {
        vector<Book> result;
        copy_if(books_.begin(), books_.end(), back_inserter(result), [&author](const Book& book) {
            return book.author() == author;
            });
        return result;
    }

    void write_books_by_author_to_file(const string& author) const {
        vector<Book> books = find_books_by_author(author);
        ofstream outfile("books_" + author + ".txt");
        ostream_iterator<Book> out_iter(outfile, "\n");
        copy(books.begin(), books.end(), out_iter);
    }

    Book find_min_price_book() const {
        return *min_element(books_.begin(), books_.end(), [](const Book& book1, const Book& book2) {
            return book1.price() < book2.price();
            });
    }

    Book find_max_price_book() const {
        return *max_element(books_.begin(), books_.end(), [](const Book& book1, const Book& book2) {
            return book1.price() < book2.price();
            });
    }

    bool has_cheaper_book(const Bookstore& other_store) const {
        for (const auto& book : books_) {
            for (const auto& other_book : other_store.books()) {
                if (book.title() == other_book.title() && book.price() < other_book.price()) {
                    return true;
                }
            }
        }
        return false;
    }

    bool has_neighbor_books_with_double_price() const {
        if (num_books() < 2) {
            return false;
        }
        for (auto it = books_.begin(); it != books_.end() - 1; ++it) {
            if ((it + 1)->price() == it->price() * 2) {
                return true;
            }
        }
        return false;
    }

    pair<Book, Book> find_first_pair_with_double_price(const Bookstore& other_store) const {
        for (const auto& book : books_) {
            for (const auto& other_book : other_store.books()) {
                if (book.price() == other_book.price() * 2) {
                    return make_pair(book, other_book);
                }
            }
        }
        throw runtime_error("No pair found");
    }

    bool is_subsequence(const vector<Book>& seq, const vector<Book>& target) const {
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

    bool has_subsequence(const Bookstore& other_store) const {
        if (num_books() < 3 || other_store.num_books() < 3) {
            return false;
        }
        return is_subsequence(vector<Book>(books_.begin(), books_.begin() + 3), other_store.books()) ||
            is_subsequence(vector<Book>(other_store.books().begin(), other_store.books().begin() + 3), books_);
    }

private:
    string name_;
    vector<Book> books_;
};

const Bookstore* find_bookstore_by_name(const vector<Bookstore>& bookstores, const string& name) {
    auto it = find_if(bookstores.begin(), bookstores.end(), [&name](const Bookstore& bookstore) {
        return bookstore.name() == name;
        });
    return it != bookstores.end() ? &(*it) : nullptr;
}

vector<Bookstore> read_bookstores_from_file(const string& filename);

int main() {
    vector<Bookstore> bookstores = read_bookstores_from_file("BOOKSTORES.txt");
    const string bookstore_name = "Knigarnya2";
    const string other_bookstore_name = "Knigarnya";

    const Bookstore* bookstore_ptr = find_bookstore_by_name(bookstores, bookstore_name);
    if (bookstore_ptr == nullptr) {
        cout << "Bookstore " << bookstore_name << " not found." << endl;
        return 0;
    }

    const Bookstore& bookstore = *bookstore_ptr;
    cout << "Name: " << bookstore.name() << endl;
    cout << "Number of books: " << bookstore.num_books() << endl;
    cout << "Total cost of books: " << bookstore.total_cost() << " " << bookstore.books().front().currency() << endl;

    const string author_name = "G.I.Lafcraft";
    int num_books_by_author = bookstore.num_books_by_author(author_name);
    cout << "Number of books by " << author_name << ": " << num_books_by_author << endl;
    vector<Book> books_by_author = bookstore.find_books_by_author(author_name);
    for (const Book& book : books_by_author) {
        cout << book.title() << " by " << book.author() << " (" << book.price() << " " << book.currency() << ")" << endl;
    }

    Book min_price_book = bookstore.find_min_price_book();
    cout << "Book with minimum price: " << min_price_book.title() << " by " << min_price_book.author() << " (" << min_price_book.price() << " " << min_price_book.currency() << ")" << endl;
    Book max_price_book = bookstore.find_max_price_book();
    cout << "Book with maximum price: " << max_price_book.title() << " by " << max_price_book.author() << " (" << max_price_book.price() << " " << max_price_book.currency() << ")" << endl;

    bookstore.write_books_by_author_to_file(author_name);
    cout << endl;


    const Bookstore& other_bookstore = *find_bookstore_by_name(bookstores, other_bookstore_name);
    const Bookstore* other_bookstore_ptr = find_bookstore_by_name(bookstores, other_bookstore_name);
    if (other_bookstore_ptr == nullptr) {
        cout << "Bookstore " << other_bookstore_name << " not found." << endl;
        return 0;
    }

    bool has_cheaper_book = bookstore.has_cheaper_book(other_bookstore);
    if (has_cheaper_book) {
        cout << "There is a book in " << bookstore.name() << " cheaper than in " << other_bookstore.name() << ": " << min_price_book.title() << " (" << min_price_book.price() << " " << min_price_book.currency() << ")" << endl;
    }
    else {
        cout << "There are no books in " << bookstore.name() << " cheaper than in " << other_bookstore.name() << "." << endl;
    }

    bool has_neighbor_books_with_double_price = bookstore.has_neighbor_books_with_double_price();
    if (has_neighbor_books_with_double_price) {
        cout << "There are neighboring books with double price in " << bookstore.name() << endl;
    }
    else {
        cout << "There are no neighboring books with double price in " << bookstore.name() << endl;
    }

    try {
        pair<Book, Book> pair_with_double_price = bookstore.find_first_pair_with_double_price(other_bookstore);
        cout << "The first pair of books with double price is: " << pair_with_double_price.first.title() << " by " << pair_with_double_price.first.author() << " and " << pair_with_double_price.second.title() << " by " << pair_with_double_price.second.author() << endl;
    }
    catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    bool has_subsequence = bookstore.has_subsequence(other_bookstore);
    if (has_subsequence) {
        cout << "There is a subsequence of three books in " << bookstore.name() << " that is also in " << other_bookstore.name() << endl;
    }
    else {
        cout << "There are no subsequences of three books in " << bookstore.name() << " that are also in " << other_bookstore.name() << endl;
    }

  return 0;
}

vector<Bookstore> read_bookstores_from_file(const string& filename) {
    vector<Bookstore> bookstores;
    ifstream infile(filename);
    string city, name, title, author, currency;
    double price;
    while (infile >> city >> name >> title >> author >> price >> currency) {
        bool found = false;
        for (auto& store : bookstores) {
            if (store.name() == name) {
                store.add_book(Book(title, author, price, currency));
                found = true;
                break;
            }
        }
        if (!found) {
            bookstores.emplace_back(name);
            bookstores.back().add_book(Book(title, author, price, currency));
        }
    }
    return bookstores;
}