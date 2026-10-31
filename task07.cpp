#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

class Complex {
    double real, imag;

public:
    Complex(double r = 0, double i = 0)
        : real(r), imag(i) {}

    // Addition
    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    // Subtraction
    Complex operator-(const Complex& c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    // Multiplication
    Complex operator*(const Complex& c) const {
        return Complex(
            real * c.real - imag * c.imag,
            real * c.imag + imag * c.real
        );
    }

    // Division
    Complex operator/(const Complex& c) const {
        double denominator = c.real * c.real + c.imag * c.imag;

        if (denominator == 0)
            throw runtime_error("Division by zero is not allowed.");

        return Complex(
            (real * c.real + imag * c.imag) / denominator,
            (imag * c.real - real * c.imag) / denominator
        );
    }

    // Display complex number
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real;

        if (c.imag >= 0)
            out << " + " << c.imag << "i";
        else
            out << " - " << -c.imag << "i";

        return out;
    }
};

int main() {
    const double PI = 3.141592653589793;
    const double frequency = 50.0;
    const double omega = 2 * PI * frequency;

    cout << "COMPLEX NUMBER OPERATIONS\n";

    Complex c1(4, 3);
    Complex c2(2, 1);

    cout << "Complex Number 1: " << c1 << '\n';
    cout << "Complex Number 2: " << c2 << '\n';

    cout << "Addition: " << c1 + c2 << '\n';
    cout << "Subtraction: " << c1 - c2 << '\n';
    cout << "Multiplication: " << c1 * c2 << '\n';
    cout << "Division: " << c1 / c2 << '\n';

    cout << "\nAC IMPEDANCE CALCULATION\n";

    double resistance = 100.0;
    double inductance = 0.1;
    double capacitance = 100e-6;

    Complex ZR(resistance, 0);
    Complex ZL(0, omega * inductance);
    Complex ZC(0, -1.0 / (omega * capacitance));

    cout << "Resistor Impedance: " << ZR << '\n';
    cout << "Inductor Impedance: " << ZL << '\n';
    cout << "Capacitor Impedance: " << ZC << '\n';

    // Series RLC circuit
    Complex Zseries = ZR + ZL + ZC;

    cout << "Series RLC Impedance: " << Zseries << '\n';

    // Parallel RLC circuit
    Complex one(1, 0);

    Complex YR = one / ZR;
    Complex YL = one / ZL;
    Complex YC = one / ZC;

    Complex totalAdmittance = YR + YL + YC;
    Complex Zparallel = one / totalAdmittance;

    cout << "Parallel RLC Impedance: " << Zparallel << '\n';

    // Division by zero test
    try {
        Complex zero(0, 0);
        Complex result = c1 / zero;
        cout << result << '\n';
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << '\n';
    }

    return 0;
}