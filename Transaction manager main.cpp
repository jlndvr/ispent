#include <vector>
#include "file.h"
#include <fstream>
using namespace std;

void displayMenu() {
    cout<<"Choose:"<<endl;
    cout << "1. Add Transaction" << endl;
    cout << "2. Edit Transaction" << endl;
    cout << "3. Delete Transaction" << endl;
    cout << "4. Generate Report" << endl;
    cout << "5. Exit" << endl;
}

int main() {
    vector<Trans> transactions = LoadTrans();
    int choice;
    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                AddTrans(transactions);
                break;
            case 2:
                EditTrans(transactions);
                break;
            case 3:
                DeleteTrans(transactions);
                break;
            case 4:
                GenerateReport(transactions);
                break;
            case 5:
                SaveTrans(transactions);
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 5);
    return 0;
}