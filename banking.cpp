#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Transaction Class
class Transaction {
public:
    string type;
    double amount;
    Transaction(string t, double a) : type(t), amount(a) {}
};

// Customer Class
class Customer {
public:
    string name;
    string customerID;
    Customer(string n = "", string id = "") : name(n), customerID(id) {}
};

// Account Class
class Account {
private:
    Customer customer;
    double balance;
    vector<Transaction> history;

public:
    Account(Customer c, double initial_balance) : customer(c), balance(initial_balance) {
        history.push_back(Transaction("Initial Deposit", initial_balance));
    }

    void deposit(double amount) {
        balance += amount;
        history.push_back(Transaction("Deposit", amount));
        cout << "Deposited successfully. Current Balance: $" << balance << "\n";
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds!\n";
        } else {
            balance -= amount;
            history.push_back(Transaction("Withdrawal", amount));
            cout << "Withdrawn successfully. Current Balance: $" << balance << "\n";
        }
    }

    void displayAccountInfo() {
        cout << "\n--- Account Information ---\n";
        cout << "Customer Name: " << customer.name << "\n";
        cout << "Customer ID: " << customer.customerID << "\n";
        cout << "Current Balance: $" << balance << "\n";
    }

    void displayTransactionHistory() {
        cout << "\n--- Transaction History ---\n";
        for (const auto& t : history) {
            cout << t.type << ": $" << t.amount << "\n";
        }
    }
};

int main() {
    string name, id;
    double initialDeposit;
    
    cout << "Enter Customer Name: ";
    getline(cin, name);
    cout << "Enter Customer ID: ";
    cin >> id;
    cout << "Enter Initial Deposit: ";
    cin >> initialDeposit;

    Customer cust(name, id);
    Account myAccount(cust, initialDeposit);

    int choice;
    double amount;

    while (true) {
        cout << "\n1. Deposit\n2. Withdraw\n3. View Account Info\n4. View Transactions\n5. Exit\nChoose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                myAccount.deposit(amount);
                break;
            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                myAccount.withdraw(amount);
                break;
            case 3:
                myAccount.displayAccountInfo();
                break;
            case 4:
                myAccount.displayTransactionHistory();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid option. Please try again.\n";
        }
    }
    return 0;
}