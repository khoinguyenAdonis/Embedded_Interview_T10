#include <iostream>

using namespace std;

class Car{
    private:
        int speed;
        string color;
        int fuelCapacity;
    public:
        Car(int Speed, string Color, int Fuel) : speed(Speed), color(Color), fuelCapacity(Fuel){}
        void accelerate(int iSpeed);
        void brake(int iSpeed);
        void displayInfo();
};

void Car::accelerate(int iSpeed){
    speed += iSpeed;
}

void Car::brake(int iSpeed){
    if (speed >= iSpeed) speed -= iSpeed;
    else speed = 0;
}
void Car::displayInfo(){
    cout<<"toc do    : "<<speed<<endl;
    cout<<"mau sac   : "<<color<<endl;
    cout<<"Dung tich : "<<fuelCapacity<<endl;
}

int main (){
    Car toyota (250,"xanh",300);
    toyota.brake(50);
    toyota.displayInfo();
    return 0 ;
}