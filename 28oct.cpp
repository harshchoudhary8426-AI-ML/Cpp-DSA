/*


Simulate a User Bank Account being flagged,
It consists of two classes-> BaseAccountClass, ConsumerAccountClass
Create these two classes with functions-> SendMoney() and ReceiveMoney()[virtual function]
Give and Take Permissions using Runtime Polymorphism.

*/

// OOPS concepts: Inheritance, polymorphism

#include <iostream>
using namespace std;


class BaseAccountClass{
    private:
        string accountNumber;
        string accountHolderName;
        double accountbalance;
    public:
        
        BaseAccountClass(string accNum, string accHolderName, double accBalance){
            this->accountNumber = accNum;
            this->accountHolderName = accHolderName;
            this->accountbalance = accBalance;
        }

        virtual void SendMoney(double amount){
            if(amount > accountbalance){
                cout << "Insufficient balance to send money!" << endl;
            } else {
                accountbalance -= amount;
                cout << "Sent $" << amount << " from account " << accountNumber << endl;
            }
        }

        virtual void ReceiveMoney(double amount){
            this->accountbalance += amount;
            cout << "Received $" << amount << " in account " << accountNumber << endl;
        }

        void DisplayBalance(){
            cout << "Account Balance for " << accountHolderName << ": $" << accountbalance << endl;
        }
};

class ConsumerAccountClass : public BaseAccountClass{
    public:
        ConsumerAccountClass(string accNum, string accHolderName, double accBalance)
            : BaseAccountClass(accNum, accHolderName, accBalance) {}

        void SendMoney(double amount) override {
            cout << "Consumer Account: ";
            BaseAccountClass::SendMoney(amount);
        }

        void ReceiveMoney(double amount) override {
            cout << "Consumer Account: ";
            BaseAccountClass::ReceiveMoney(amount);
        }
};

int main(){
    ConsumerAccountClass consumerAcc("123456789", "John Doe", 1000.0);
    
    consumerAcc.DisplayBalance();
    consumerAcc.SendMoney(200.0);
    consumerAcc.DisplayBalance();
    consumerAcc.ReceiveMoney(150.0);
    consumerAcc.DisplayBalance();

    return 0;
}