#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>

using namespace std;

class ElectricityBill {
private:
    double costPerKWh; // Cost per kWh
    string date;       // Date of the bill
    double totalKWh;   // Total consumed kWh
    double amountPaid; // Amount paid

public:
    // Constructor
    ElectricityBill(double cost, const string& billDate, double kWh)
        : costPerKWh(cost), date(billDate), totalKWh(kWh), amountPaid(cost* kWh) {
        if (cost < 0 || kWh < 0) {
            throw invalid_argument("Cost and kWh must be non-negative.");
        }
    }

    // Overload operator ++
    void operator++() {
        costPerKWh++;
        amountPaid = costPerKWh * totalKWh; // Update amount paid
    }

    // Overload operator -=
    void operator-=(double value) {
        if (value < 0) {
            throw invalid_argument("Value to decrease must be non-negative.");
        }
        costPerKWh -= value;
        amountPaid = costPerKWh * totalKWh; // Update amount paid
    }

    // Method to search the bill by date
    bool searchByDate(const string& searchDate) const {
        return date == searchDate;
    }

    // Method to display bill information
    void displayInfo() const {
        cout << "Date: " << date << endl;
        cout << "Cost per kWh: " << fixed << setprecision(2) << costPerKWh << " UAH" << endl;
        cout << "Total kWh consumed: " << fixed << setprecision(2) << totalKWh << " kWh" << endl;
        cout << "Amount paid: " << fixed << setprecision(2) << amountPaid << " UAH" << endl;
    }
};

int main() {
    try {
        // Create an instance of ElectricityBill
        ElectricityBill bill(4.32, "2024-10-06", 320.0);

        // Display initial bill information
        bill.displayInfo();

        // Increment the cost by 1
        ++bill;
        cout << "\nAfter incrementing the cost:" << endl;
        bill.displayInfo();

        // Decrease the cost by 2
        bill -= 2.0;
        cout << "\nAfter decreasing the cost:" << endl;
        bill.displayInfo();

        // Search for the bill by date
        string searchDate = "2024-10-06";
        if (bill.searchByDate(searchDate)) {
            cout << "\nBill found for date: " << searchDate << endl;
        }
        else {
            cout << "\nBill not found for date: " << searchDate << endl;
        }
    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}


