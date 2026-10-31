#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Time {
    int seconds;

public:
    Time(int s = 0) : seconds(s) {}

    // Prefix increment
    Time& operator++() {
        ++seconds;
        return *this;
    }

    // Postfix increment
    Time operator++(int) {
        Time temp = *this;
        seconds++;
        return temp;
    }

    // Equality operator
    bool operator==(const Time& other) const {
        return seconds == other.seconds;
    }

    // Less than operator
    bool operator<(const Time& other) const {
        return seconds < other.seconds;
    }

    // Display time
    friend ostream& operator<<(ostream& out, const Time& t) {
        out << t.seconds << " seconds";
        return out;
    }
};

class Playlist {
    vector<string> songs;

public:
    Playlist(const vector<string>& s) : songs(s) {}

    // Non-const subscript operator
    string& operator[](int index) {
        return songs.at(index);
    }

    // Const subscript operator
    const string& operator[](int index) const {
        return songs.at(index);
    }

    int size() const {
        return static_cast<int>(songs.size());
    }
};

int main() {
    cout << "TIME OPERATORS\n";

    Time t1(10);

    cout << "Original time: " << t1 << '\n';

    cout << "Prefix increment: " << ++t1 << '\n';

    cout << "Postfix increment: " << t1++ << '\n';

    cout << "After postfix increment: " << t1 << '\n';

    Time t2(12);

    cout << "Time comparison:\n";

    if (t1 == t2)
        cout << "Both times are equal.\n";
    else
        cout << "Both times are not equal.\n";

    if (t1 < t2)
        cout << "t1 is less than t2.\n";
    else
        cout << "t1 is not less than t2.\n";

    cout << "\nPLAYLIST OPERATORS\n";

    Playlist playlist({"Song A", "Song B", "Song C"});

    cout << "First song: " << playlist[0] << '\n';

    playlist[1] = "Updated Song B";

    cout << "Updated second song: " << playlist[1] << '\n';

    cout << "All songs:\n";

    for (int i = 0; i < playlist.size(); i++) {
        cout << playlist[i] << '\n';
    }

    return 0;
}