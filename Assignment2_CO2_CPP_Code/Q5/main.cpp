#include <iostream>
#include <string>

class BusTicket {
    static int issued;
    static const int CAPACITY = 3;

    int seat;
    std::string name;

public:
    explicit BusTicket(const std::string& n) : seat(0), name(n) {
        if (issued < CAPACITY) {
            ++issued;
            seat = issued;
        }
    }

    static int count() {
        return issued;
    }

    void print() const {
        if (seat != 0) {
            std::cout << name << ": Seat " << seat << '\n';
        } else {
            std::cout << name << ": Waiting\n";
        }
    }
};

int BusTicket::issued = 0;

int main() {
    BusTicket trip[4] = {
        BusTicket("Asha"),
        BusTicket("Bala"),
        BusTicket("Chitra"),
        BusTicket("Dev")
    };

    for (const BusTicket& ticket : trip) {
        ticket.print();
    }
    std::cout << "Issued: " << BusTicket::count() << '\n';
    return 0;
}
