#include <iostream>

using namespace std;

class Car{
    private:
        int speed;
        string color;
        int fuelCapacity;
    public:
        Car(int Speed, string Color, int Fuel) : speed(Speed), color(Color), fuelCapacity(Fuel){}
        void accelerate();
        void brake();
        void displayInfo();
};

void Car::accelerate(){
    speed += 5;
}

void Car::brake(){
    if (speed >= 5) speed -=5;
    else speed = 0;
}
void Car::displayInfo(){
    cout<<"toc do    : "<<speed<<endl;
    cout<<"mau sac   : "<<color<<endl;
    cout<<"Dung tich : "<<fuelCapacity<<endl;
}

int main (){
    Car toyota (250,"xanh",300);
    toyota.displayInfo();
    return 0 ;
}