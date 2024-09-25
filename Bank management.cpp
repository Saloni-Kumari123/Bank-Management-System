#include <iostream>
#include <string>
#include <ctime>
#include <vector>

using namespace std;
class BankAccount {
private:
string name;
string address;
string accountType;
int accountNo;
double balance;
public:
BankAccount(string _name, string _address, string _accountType, double _balance)
: name(_name), address(_address), accountType(_accountType), balance(_balance)
{
static int nextAccountNo = 1000; // Static variable to generate unique account numbers
accountNo = nextAccountNo++;
}
void deposit(double amount)
{
if (amount > 0)
{
balance += amount;
cout << "Amount deposited. Current balance: " << balance << endl;
}
else
{
cout << "Invalid amount." << endl;
}
}
bool withdrawal(double amount) {


if (amount > 0 && balance >= amount) {
balance -= amount;
cout << "Amount withdrawn. Current balance: " << balance << endl;
return true; // Withdrawal successful
} else {
cout << "Invalid amount or insufficient balance." << endl;
return false; // Withdrawal unsuccessful
}
}
void displayAccountDetails() const {
cout << "Account holder's name: " << name << endl;
cout << "Account number: " << accountNo << endl;
cout << "Account balance: " << balance << endl;
}
int getAccountNo() const {
return accountNo;
}
double getBalance() const {
return balance;
}
string getName() const {
return name;
}
string getAddress() const {
return address;
}
string getAccountType() const {
return accountType;
}
};
class Bank {
private:
vector<BankAccount> accounts;
public:
void addAccount(const BankAccount& account)
{
accounts.push_back(account);

}
BankAccount* getLastAccount() {
if (!accounts.empty()) {
return &accounts.back();
}
return nullptr;
}
void displayAllAccounts() const {
cout << "----------All Accounts----------" << endl;
for (const auto& account : accounts) {
account.displayAccountDetails();
cout << "-------------------------------" << endl;
}
}
void addCustomer(const BankAccount& account) {
accounts.push_back(account);
cout << "Customer added successfully." << endl;
}
void openAccount() {
string name, address, accountType;
double balance;
cout << "Enter customer's name: ";
cin.ignore();
getline(cin, name);
cout << "Enter customer's address: ";
getline(cin, address);
cout << "Enter account type (Savings/Current): ";
getline(cin, accountType);
cout << "Enter initial balance: ";
cin >> balance;
BankAccount newAccount(name, address, accountType, balance);
addCustomer(newAccount);
}
void deposit(double amount) {
BankAccount* account = getLastAccount();
if (account != nullptr) {
account->deposit(amount);

} 
else {
cout << "No account found." << endl;
}
}
void withdrawal(double amount) {
BankAccount* account = getLastAccount();
if (account != nullptr) {
account->withdrawal(amount);
} else {
cout << "No account found." << endl;
}
}
};
void displayDateTime() {
// Display current date and time
time_t now = time(0);
char* date_time = ctime(&now);
cout << "Date and Time: " << date_time << endl;
}
int main() {
Bank bank;
displayDateTime();
int choice;
do {
cout << "-------------------WELCOME-------------------" << endl;
cout << "HOW CAN I HELP YOU?" << endl;
cout << "1) Add Customer " << endl;
cout << "2) Deposit " << endl;
cout << "3) Withdrawal" << endl;
cout << "4) Display all Account" << endl;
cout << "5) Exit" << endl;
cout << "Enter your choice: ";
cin >> choice;
switch (choice) {
case 2: {
double amount;
cout << "Enter amount to deposit: ";
cin >> amount;



bank.deposit(amount);
break;
}
case 3: {
double amount;
cout << "Enter amount to withdraw: ";
cin >> amount;
bank.withdrawal(amount);
break;
}
case 1: {
bank.openAccount();
break;
}
case 4: {
bank.displayAllAccounts();
break;
}
case 5: {
cout << "Exiting..." << endl;
break;
}
default: {
cout << "Invalid choice." << endl;
break;
}
}
} while (choice != 5);
return 0;
}