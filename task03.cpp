#include <iostream>
#include <string>
using namespace std;

class Auditorium {
    int rows, seats;
    bool** booked;

public:
    // Dynamic constructor
    Auditorium(int r, int s) : rows(r), seats(s) {
        if (rows < 0) rows = 0;
        if (seats < 0) seats = 0;

        booked = new bool*[rows];

        for (int i = 0; i < rows; i++) {
            booked[i] = new bool[seats]();
        }

        cout << "Auditorium created with "
             << rows << " rows and "
             << seats << " seats per row.\n";
    }

    // Book a seat
    void bookSeat(int r, int s) {
        if (r < 0 || r >= rows || s < 0 || s >= seats) {
            cout << "Invalid seat position.\n";
            return;
        }

        if (booked[r][s]) {
            cout << "Seat already booked.\n";
        } else {
            booked[r][s] = true;
            cout << "Seat booked successfully.\n";
        }
    }

    // Cancel a seat
    void cancelSeat(int r, int s) {
        if (r < 0 || r >= rows || s < 0 || s >= seats) {
            cout << "Invalid seat position.\n";
            return;
        }

        if (!booked[r][s]) {
            cout << "Seat is not booked.\n";
        } else {
            booked[r][s] = false;
            cout << "Booking cancelled successfully.\n";
        }
    }

    // Display seat status
    void display() const {
        cout << "\nSeat Status (0 = Available, 1 = Booked):\n";

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < seats; j++) {
                cout << booked[i][j] << " ";
            }
            cout << '\n';
        }
    }

    // Destructor
    ~Auditorium() {
        for (int i = 0; i < rows; i++) {
            delete[] booked[i];
        }

        delete[] booked;

        cout << "Auditorium memory released.\n";
    }
};

int main() {
    // Stack object
    Auditorium a(3, 4);

    a.bookSeat(0, 1);
    a.bookSeat(1, 2);
    a.bookSeat(0, 1);

    a.display();

    a.cancelSeat(0, 1);
    a.display();

    // Heap object
    Auditorium* b = new Auditorium(2, 3);

    b->bookSeat(1, 1);
    b->display();

    delete b;

    return 0;
}