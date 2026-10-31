#include <iostream>
#include <cstring>
using namespace std;

class Text {
    char* data;

public:
    // Constructor
    Text(const char* str = "") {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    // Copy constructor
    Text(const Text& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }

    // Copy assignment operator
    Text& operator=(const Text& other) {
        if (this != &other) {
            char* temp = new char[strlen(other.data) + 1];
            strcpy(temp, other.data);

            delete[] data;
            data = temp;
        }
        return *this;
    }

    // Destructor
    ~Text() {
        delete[] data;
    }

    // Concatenation operator
    Text operator+(const Text& other) const {
        char* temp = new char[strlen(data) + strlen(other.data) + 1];

        strcpy(temp, data);
        strcat(temp, other.data);

        Text result(temp);
        delete[] temp;

        return result;
    }

    // Equality operator
    bool operator==(const Text& other) const {
        return strcmp(data, other.data) == 0;
    }

    // Inequality operator
    bool operator!=(const Text& other) const {
        return !(*this == other);
    }

    // Stream insertion operator
    friend ostream& operator<<(ostream& out, const Text& t) {
        out << t.data;
        return out;
    }
};

int main() {
    Text t1("Hello ");
    Text t2("World");

    cout << "Text 1: " << t1 << '\n';
    cout << "Text 2: " << t2 << '\n';

    Text t3 = t1 + t2;

    cout << "Concatenated Text: " << t3 << '\n';

    Text t4("Hello ");

    if (t1 == t4)
        cout << "Text 1 and Text 4 are equal.\n";
    else
        cout << "Text 1 and Text 4 are not equal.\n";

    if (t1 != t2)
        cout << "Text 1 and Text 2 are different.\n";

    // Self-assignment test
    t1 = t1;

    cout << "After self-assignment: " << t1 << '\n';

    return 0;
}