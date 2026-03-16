#include <iostream>
using namespace std;


class PaymentMethod {
protected:
    double amount;
    string customerName;
 
public:
    PaymentMethod(string name, double amt)
        : customerName(name), amount(amt) { }
 
    virtual bool processPayment() = 0;   // Pure virtual (explained soon)
 
    virtual void printReceipt() {
        cout << "Payment of $" << amount
             << " received from " << customerName << endl;
    }
 
    virtual ~PaymentMethod() { }   // Virtual destructor (explained soon)
};
 
class CreditCard : public PaymentMethod {
private:
    string cardNumber;
    string expDate;
 
public:
    CreditCard(string name, double amt, string card, string exp)
        : PaymentMethod(name, amt), cardNumber(card), expDate(exp) { }
 
    virtual bool processPayment() {
        cout << "Charging credit card ending in "
             << cardNumber.substr(cardNumber.length() - 4) << endl;
        // In real code: contact payment gateway, validate card, etc.
        return true;
    }
 
    virtual void printReceipt() {
        PaymentMethod::printReceipt();   // Reuse base class receipt
        cout << "  (Card ending in "
             << cardNumber.substr(cardNumber.length() - 4) << ")" << endl;
    }
};
 
class PayPalPayment : public PaymentMethod {
private:
    string email;
 
public:
    PayPalPayment(string name, double amt, string email)
        : PaymentMethod(name, amt), email(email) { }
 
    virtual bool processPayment() {
        cout << "Processing PayPal payment for " << email << endl;
        return true;
    }
 
    virtual void printReceipt() {
        PaymentMethod::printReceipt();
        cout << "  (PayPal: " << email << ")" << endl;
    }
};
 
class BankTransfer : public PaymentMethod {
private:
    string routingNumber;
 
public:
    BankTransfer(string name, double amt, string routing)
        : PaymentMethod(name, amt), routingNumber(routing) { }
 
    virtual bool processPayment() {
        cout << "Initiating bank transfer via routing " << routingNumber << endl;
        return true;
    }
};

// This function doesn't know or care what kind of payment it's processing!
void checkout(PaymentMethod& payment) {
    cout << "Processing your order..." << endl;
    if (payment.processPayment()) {
        payment.printReceipt();
        cout << "Order confirmed!" << endl;
    } else {
        cout << "Payment failed. Please try again." << endl;
    }
}
 
int main() {
    CreditCard visa("Alice", 49.99, "4111111111111234", "12/26");
    PayPalPayment pp("Bob", 29.99, "bob@email.com");
    BankTransfer bt("Carol", 199.99, "021000021");
 
    checkout(visa);   // Automatically uses CreditCard methods
    checkout(pp);     // Automatically uses PayPal methods
    checkout(bt);     // Automatically uses BankTransfer methods
}
