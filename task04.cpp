#include <iostream>
using namespace std;

class Money {
    long long paise;

public:
    // Constructor
    Money(long long rupees = 0, long long p = 0) {
        paise = rupees * 100 + p;
    }

    // Addition operator overloading
    Money operator+(const Money& other) const {
        Money result;
        result.paise = paise + other.paise;
        return result;
    }

    // Equality operator overloading
    bool operator==(const Money& other) const {
        return paise == other.paise;
    }

    // Stream insertion operator overloading
    friend ostream& operator<<(ostream& out, const Money& m) {
        out << "Rs. " << m.paise / 100
            << ".";

        if (m.paise % 100 < 10)
            out << "0";

        out << m.paise % 100;
        return out;
    }
};

int main() {
    Money m1(100, 75);
    Money m2(50, 50);

    Money m3 = m1 + m2;

    cout << "Money 1: " << m1 << '\n';
    cout << "Money 2: " << m2 << '\n';
    cout << "Total: " << m3 << '\n';

    if (m1 == m2) {
        cout << "Both amounts are equal.\n";
    } else {
        cout << "Both amounts are not equal.\n";
    }

    Money m4(10, 90);
    Money m5(5, 25);

    cout << "Carry Test: " << m4 + m5 << '\n';

    return 0;
}