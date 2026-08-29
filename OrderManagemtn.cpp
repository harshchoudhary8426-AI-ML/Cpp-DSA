// //Design a console-based E-Commerce Order Management System that manages products, customers, orders, and payments.

// Requirements:

// Product Class
// Create a Product class with:
// Product ID, Name, Price, Stock
// Category using enum Category
// Functions: displayProduct(), updateStock(), checkAvailability()
// Customer Class
// Create a Customer class with:
// Customer ID, Name, Email, Phone, Address
// Functions to display and update customer details
// Order Struct
// Create an Order struct with:
// Order ID, Customer ID, Total Amount
// Order Status and Payment Status using enums
// Support creating, updating, confirming, cancelling, and displaying orders
// Payment & Union
// Use:
// enum PaymentMethod {
// CREDIT_CARD,
// UPI,
// CASH
// };
#include <bits/stdc++.h>
using namespace std;

// Category enum
enum Category {
    ELECTRONICS,
    CLOTHING,
    FOOD,
    BOOKS
};

// Payment method enum
enum PaymentMethod {
    CREDIT_CARD,
    UPI,
    CASH
};

// Order status enum
enum OrderStatus {
    CREATED,
    CONFIRMED,
    CANCELLED
};

// Payment union
union Payment {
    long long card;
    char upi[20];
    float cash;
};

// Product Class
class Product {
public:
    int id;
    string name;
    float price;
    int stock;
    Category category;

    void displayProduct() {
        cout << "\nProduct ID: " << id;
        cout << "\nName: " << name;
        cout << "\nPrice: " << price;
        cout << "\nStock: " << stock;
    }

    void updateStock(int x) {
        stock = stock + x;
    }

    bool checkAvailability(int quantity) {
        return stock >= quantity;
    }
};

// Customer Class
class Customer {
public:
    int id;
    string name;
    string email;
    string phone;
    string address;

    void displayCustomer() {
        cout << "\nCustomer ID: " << id;
        cout << "\nName: " << name;
        cout << "\nEmail: " << email;
        cout << "\nPhone: " << phone;
        cout << "\nAddress: " << address;
    }

    void updateCustomer() {
        cout << "\nEnter new name: ";
        cin >> name;

        cout << "Enter new phone: ";
        cin >> phone;

        cout << "Customer updated!";
    }
};

// Order Structure
struct Order {
    int orderID;
    int customerID;
    float totalAmount;

    OrderStatus status;
    PaymentMethod method;

    void displayOrder() {
        cout << "\nOrder ID: " << orderID;
        cout << "\nCustomer ID: " << customerID;
        cout << "\nTotal Amount: " << totalAmount;

        cout << "\nStatus: ";

        if (status == CREATED)
            cout << "Created";
        else if (status == CONFIRMED)
            cout << "Confirmed";
        else
            cout << "Cancelled";

        cout << "\nPayment Method: ";

        if (method == CREDIT_CARD)
            cout << "Credit Card";
        else if (method == UPI)
            cout << "UPI";
        else
            cout << "Cash";
    }
};

int main() {

    Product p;
    Customer c;
    Order o;
    Payment pay;

    int choice;

    do {
        cout << "\n\n===== E-COMMERCE SYSTEM =====";
        cout << "\n1. Add Product";
        cout << "\n2. Display Product";
        cout << "\n3. Add Customer";
        cout << "\n4. Display Customer";
        cout << "\n5. Update Customer";
        cout << "\n6. Create Order";
        cout << "\n7. Confirm Order";
        cout << "\n8. Cancel Order";
        cout << "\n9. Display Order";
        cout << "\n0. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "\nEnter Product ID: ";
            cin >> p.id;

            cout << "Enter Product Name: ";
            cin >> p.name;

            cout << "Enter Price: ";
            cin >> p.price;

            cout << "Enter Stock: ";
            cin >> p.stock;

            cout << "Enter Category (0-Electronics, 1-Clothing, 2-Food, 3-Books): ";
            int cat;
            cin >> cat;
            p.category = (Category)cat;

            cout << "Product added!";
            break;

        case 2:
            p.displayProduct();
            break;

        case 3:
            cout << "\nEnter Customer ID: ";
            cin >> c.id;

            cout << "Enter Name: ";
            cin >> c.name;

            cout << "Enter Email: ";
            cin >> c.email;

            cout << "Enter Phone: ";
            cin >> c.phone;

            cout << "Enter Address: ";
            cin >> c.address;

            cout << "Customer added!";
            break;

        case 4:
            c.displayCustomer();
            break;

        case 5:
            c.updateCustomer();
            break;

        case 6:
            cout << "\nEnter Order ID: ";
            cin >> o.orderID;

            o.customerID = c.id;

            int quantity;
            cout << "Enter Product Quantity: ";
            cin >> quantity;

            if (p.checkAvailability(quantity)) {

                o.totalAmount = p.price * quantity;

                p.updateStock(-quantity);

                cout << "\nChoose Payment Method";
                cout << "\n0. Credit Card";
                cout << "\n1. UPI";
                cout << "\n2. Cash";
                cout << "\nEnter choice: ";
                int x;
                cin >> x;

                o.method = (PaymentMethod)x;

                if (o.method == CREDIT_CARD) {
                    cout << "Enter card number: ";
                    cin >> pay.card;
                }
                else if (o.method == UPI) {
                    cout << "Enter UPI ID: ";
                    cin >> pay.upi;
                }
                else {
                    pay.cash = o.totalAmount;
                }

                o.status = CREATED;

                cout << "\nOrder created!";
            }
            else {
                cout << "\nProduct not available!";
            }

            break;

        case 7:
            o.status = CONFIRMED;
            cout << "\nOrder confirmed!";
            break;

        case 8:
            o.status = CANCELLED;
            cout << "\nOrder cancelled!";
            break;

        case 9:
            o.displayOrder();
            break;

        case 0:
            cout << "\nExiting...";
            break;

        default:
            cout << "\nInvalid choice!";
        }

    } while (choice != 0);

    return 0;
} 
    



// Create a union to store payment-specific information:

// Credit Card → Last 4 digits
// UPI → UPI ID
// Cash → No additional information
// Validation
// Handle at least 5 invalid scenarios, such as:
// Product out of stock
// Invalid product/customer ID
// Cancelling a delivered order
// Payment for a cancelled order
// Confirming an order with failed payment

// Mandatory Concepts:
// Class, Struct, Union, Enum, Constructor, Member Functions, Access Specifiers

using namespace std;
#include <bits/stdc++.h>

enum Category{ELECTRONICS,CLOTHING,FOOD,BOOKS};
enum PaymentMethod{CREDIT_CARD,UPI,CASH};
enum OrderStatus{CREATED,CONFIRMED,DELIVERED,CANCELLED};
enum PaymentStatus{PENDING,SUCCESS,FAILED};

union PaymentInfo{
    char card[5];
    char upi[30];
    PaymentInfo(){card[0]='\0';}
};

class Product{
private:
    int id,stock;
    string name;
    float price;
    Category category;
public:
    Product(int i=0,string n="",float p=0,int s=0,Category c=FOOD){
        id=i;name=n;price=p;stock=s;category=c;
    }
    void displayProduct(){
        cout<<"\nID: "<<id<<"\nName: "<<name<<"\nPrice: "<<price<<"\nStock: "<<stock;
    }
    void updateStock(int x){stock+=x;}
    bool checkAvailability(int q){return stock>=q;}
    int getID(){return id;}
    float getPrice(){return price;}
};

class Customer{
private:
    int id;
    string name,email,phone,address;
public:
    Customer(int i=0,string n="",string e="",string p="",string a=""){
        id=i;name=n;email=e;phone=p;address=a;
    }
    void displayCustomer(){
        cout<<"\nID: "<<id<<"\nName: "<<name<<"\nEmail: "<<email<<"\nPhone: "<<phone<<"\nAddress: "<<address;
    }
    void updateCustomer(){
        cout<<"\nEnter new phone: ";
        cin>>phone;
        cout<<"Updated!";
    }
    int getID(){return id;}
};

struct Order{
    int orderID,customerID,productID,quantity;
    float totalAmount;
    OrderStatus status;
    PaymentStatus paymentStatus;
    PaymentMethod method;
    PaymentInfo payment;
    void displayOrder(){
        cout<<"\nOrder ID: "<<orderID<<"\nCustomer ID: "<<customerID;
        cout<<"\nProduct ID: "<<productID<<"\nQuantity: "<<quantity;
        cout<<"\nAmount: "<<totalAmount<<"\nStatus: ";
        if(status==CREATED)cout<<"Created";
        else if(status==CONFIRMED)cout<<"Confirmed";
        else if(status==DELIVERED)cout<<"Delivered";
        else cout<<"Cancelled";
        cout<<"\nPayment: ";
        if(paymentStatus==PENDING)cout<<"Pending";
        else if(paymentStatus==SUCCESS)cout<<"Success";
        else cout<<"Failed";
    }
};

int main(){
    Product p[3]={
        Product(101,"Laptop",50000,5,ELECTRONICS),
        Product(102,"TShirt",800,10,CLOTHING),
        Product(103,"Book",500,3,BOOKS)
    };
    Customer c[2]={
        Customer(1,"Rahul","rahul@gmail.com","9876543210","Delhi"),
        Customer(2,"Aman","aman@gmail.com","9876500000","Noida")
    };
    Order o;
    int choice;

    do{
        cout<<"\n\n1.Products\n2.Customers\n3.Create Order\n4.Confirm Order";
        cout<<"\n5.Cancel Order\n6.Deliver Order\n7.Payment\n8.Display Order\n0.Exit";
        cout<<"\nChoice: ";
        cin>>choice;

        if(choice==1){
            for(int i=0;i<3;i++)p[i].displayProduct();
        }
        else if(choice==2){
            for(int i=0;i<2;i++)c[i].displayCustomer();
        }
        else if(choice==3){
            cout<<"\nOrder ID: ";cin>>o.orderID;
            cout<<"Customer ID: ";cin>>o.customerID;
            bool cf=false;
            for(int i=0;i<2;i++)
                if(c[i].getID()==o.customerID)cf=true;
            if(!cf){
                cout<<"Invalid Customer ID!";
                continue;
            }
            cout<<"Product ID: ";cin>>o.productID;
            int pi=-1;
            for(int i=0;i<3;i++)
                if(p[i].getID()==o.productID)pi=i;
            if(pi==-1){
                cout<<"Invalid Product ID!";
                continue;
            }
            cout<<"Quantity: ";cin>>o.quantity;
            if(!p[pi].checkAvailability(o.quantity)){
                cout<<"Product out of stock!";
                continue;
            }
            o.totalAmount=p[pi].getPrice()*o.quantity;
            p[pi].updateStock(-o.quantity);
            o.status=CREATED;
            o.paymentStatus=PENDING;
            cout<<"Payment 0.Card 1.UPI 2.Cash: ";
            int x;cin>>x;
            o.method=(PaymentMethod)x;
            if(x==CREDIT_CARD){
                cout<<"Last 4 digits: ";cin>>o.payment.card;
            }
            else if(x==UPI){
                cout<<"UPI ID: ";cin>>o.payment.upi;
            }
            cout<<"Order Created!";
        }
        else if(choice==4){
            if(o.status==CANCELLED)cout<<"Cancelled order!";
            else if(o.paymentStatus!=SUCCESS)cout<<"Payment not successful!";
            else{
                o.status=CONFIRMED;
                cout<<"Order Confirmed!";
            }
        }
        else if(choice==5){
            if(o.status==DELIVERED)cout<<"Cannot cancel delivered order!";
            else if(o.status==CANCELLED)cout<<"Already cancelled!";
            else{
                o.status=CANCELLED;
                cout<<"Order Cancelled!";
            }
        }
        else if(choice==6){
            if(o.status==CONFIRMED){
                o.status=DELIVERED;
                cout<<"Order Delivered!";
            }
            else cout<<"Order must be confirmed!";
        }
        else if(choice==7){
            if(o.status==CANCELLED)cout<<"Cannot pay for cancelled order!";
            else{
                o.paymentStatus=SUCCESS;
                cout<<"Payment Successful!";
            }
        }
        else if(choice==8)o.displayOrder();
        else if(choice!=0)cout<<"Invalid choice!";
    }while(choice!=0);

    return 0;
}

