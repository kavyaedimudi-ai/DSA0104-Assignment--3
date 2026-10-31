#include <iostream>
#include <string>
using namespace std;
class Book {
    string title, author; int copies;
public:
    Book() : Book("", "Unknown", 0) {}
    explicit Book(const string& t) : Book(t, "Unknown", 0) {}
    Book(const string& t,const string& a) : Book(t,a,0) {}
    Book(const string& t,const string& a,int c) : title(t),author(a),copies(c<0?0:c) {}
    void print() const { cout<<"Title: "<<(title.empty()?"(empty)":title)<<", Author: "<<author<<", Copies: "<<copies<<'\\n'; }
};
int main(){ Book a,b("C++ Basics"),c("Effective C++","Scott Meyers"),d("C++ Language","Bjarne Stroustrup",5),e("Invalid","Unknown",-3); a.print();b.print();c.print();d.print();e.print(); }
