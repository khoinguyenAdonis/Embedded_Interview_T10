#include <iostream>

class BankAccount {
    private :
    int accountNumber ;
    long balance ;
    std::string ownerName;
    public:
    BankAccount(int account, long baLance, std::string name) : accountNumber(account), balance(baLance), ownerName(name) { } 
    void deposit(long a);
    void withdraw(long b);
    void displayInfo();
};

void BankAccount::deposit(long a){
    balance += a;
    std::cout<<"So tien da them:"<<a<<std::endl;
    std::cout<<"So tien hien co:"<<balance<<std::endl;
}

void BankAccount::withdraw(long b){
    if (balance > 0 && balance >= b){
        balance -= b;
        std::cout<<"So tien da rut:"<<b<<std::endl;
        std::cout<<"So con lai:"<<balance<<std::endl;
    }
    else if (balance < b)
    {
        std::cout<<"So tien rut khong hop le"<<std::endl;
        /* code */
    }
    
    else std::cout<<"Tai khoan khong con tien"<<std::endl;
}

void BankAccount::displayInfo(){
    std::cout<<"So tai khoan:"<<accountNumber<<std::endl;
    std::cout<<"So tien hien co:"<<balance<<std::endl;
    std::cout<<"Chu so huu:"<<ownerName<<std::endl;
}
int main (){
    BankAccount khoi(123241,2000000,"nguyen khoi");
    khoi.deposit(1000000);
    std::cout<<"-----------------------------------"<<std::endl;
    khoi.displayInfo();
    std::cout<<"-----------------------------------"<<std::endl;
    khoi.withdraw(2000000);
    std::cout<<"-----------------------------------"<<std::endl;
    khoi.displayInfo();
    return 0;
}