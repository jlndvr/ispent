#include <fstream>
#include <vector>
#include <iostream>
#include "struct.h"
using namespace std;

void SaveTrans(const vector<Trans>& transactions) {
   ofstream file("trans.txt");
    if (!file) {
        cerr << "Error opening file for writing." << endl;
        return;
    }
    for (const auto& t : transactions) {
        file << t.date << " " << t.cat << " " << t.amount << endl;
    }
}

vector<Trans> LoadTrans() {
  vector<Trans> transactions;
    ifstream file("trans.txt");
    if (!file) {
        cerr << "Error opening file for reading." << endl;
        return transactions;
    }
    Trans t;
    while (file >> t.date >> t.cat >> t.amount) {
        transactions.push_back(t);
    }
    return transactions;
}

void AddTrans(vector<Trans>& transactions) {
    Trans t;
    cout << "Enter date (YYYY/MM/DD): ";
    cin >> t.date;
    cout << "Enter category: ";
    cin >> t.cat;
    cout << "Enter amount: ";
    cin >> t.amount;
    transactions.push_back(t);
    SaveTrans(transactions);
}

void EditTrans(vector<Trans>& transactions) {
    int index;
    cout << "Enter transaction index to edit: ";
    cin >> index;
    if (index >= 0 && index < transactions.size()) {
        cout << "Enter new date (YYYY-MM-DD): ";
        cin >> transactions[index].date;
        cout << "Enter new category: ";
        cin >> transactions[index].cat;
        cout << "Enter new amount: ";
        cin >> transactions[index].amount;
        SaveTrans(transactions);
    } else {
        cout << "Invalid index." << endl;
    }
}

void DeleteTrans(vector<Trans>& transactions) {
    int index;
    cout << "Enter transaction index to delete: ";
    cin >> index;
    if (index >= 0 && index < transactions.size()) {
        transactions.erase(transactions.begin() + index);
        SaveTrans(transactions);
    } else {
        cout << "Invalid index." << endl;
    }
}

void GenerateReport(const vector<Trans>& transactions) {
    for (const auto& t : transactions) {
        cout << "Date: " << t.date << ", Category: " << t.cat << ", Amount: " << t.amount << endl;
    }
}
