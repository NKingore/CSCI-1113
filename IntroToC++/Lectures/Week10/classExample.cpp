#include <iostream>
using namespace std;

class BankAccount{
    double balance;
    double rate;
    int account_num;
    int routing_num;
    string name;
    string password;
    string type;
    string owner;
 public:
    BankAccount();
    BankAccount(double bal, string new_owner, string typ);
    BankAccount(double, double, string, string);
    
    void deposit(double);
    bool withdraw(double amount);
    double get_balance();
    void report();
};

BankAccount::BankAccount() 
{
    /*balance = 0;
    rate = 0;
    routing_num = 91000019;
    owner = "N/A";
    type = "Checking";
    */
}

BankAccount::BankAccount(double bal, string new_owner, string typ) 
    : BankAccount(bal, 0, new_owner, typ)
{ }

BankAccount::BankAccount(double bal, double interest_rate, string new_owner, string typ)
{
    if (bal < 0) {
        bal = 0;
    }

    balance = bal;
    rate = interest_rate;
    routing_num = 91000019;
    owner = new_owner;
    type = typ;
}


//this is a method. A function can be called anywhere in the code.
//this method "void deposit" can only be called in the class BankAccount.
void BankAccount::deposit(double amt) {
    balance += amt;
}

bool BankAccount::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
        return true;
    }
    return false;
}

double BankAccount::get_balance() {
    return balance;
}

void BankAccount::report() {
    cout << "Balance: $" << balance << endl;
    cout << "Rate: " << rate << "%" << endl;
    cout << "Owner: " << owner << endl;

}

int main(){
    BankAccount my_account;
    BankAccount not_my_account;

    my_account.deposit(100);
    not_my_account.withdraw(10000);

    my_account.report();
    not_my_account.report();

    //my_account.balance = 0;
    //my_account.rate = 0.0005;
    
    //cout << my_account.balance << endl;
    //cout << my_account.rate << endl;

    BankAccount acct1(2500, "Noah Kingore", "Checking");
    BankAccount acct2(1000000, .455, "Barrack Obama", "Savings");

    return 0;
}