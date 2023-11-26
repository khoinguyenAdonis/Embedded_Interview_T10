#include <iostream>

class Shape {
    public:
    virtual float calculateArea();
    virtual float calculatePerimeter();
    void display();
};

float Shape::calculateArea(){
    return 0;
}
float Shape::calculatePerimeter(){
    return 0;
}
void Shape::display(){
    std::cout<<"Chu vi la: "<<calculateArea()<<std::endl;
    std::cout<<"Dien tich la: "<<calculatePerimeter()<<std::endl;
}

class Circle : public Shape{
    public:
    float radius;
    float calculateArea();
    float calculatePerimeter();
};

float Circle :: calculateArea (){
    return 2*3.14*radius;
}
float Circle :: calculatePerimeter(){
    return 3.14*radius*radius;
}
class Rectangle :public Shape{
    public:
    float length;
    float width;
    float calculateArea();
    float calculatePerimeter();
};

float Rectangle :: calculateArea(){
    return (length+width)*2;
}

float Rectangle :: calculatePerimeter(){
    return length*width;
}

int main (){
    Circle c;
    c.radius = 5;
    c.calculateArea();
    c.calculatePerimeter();
    c.display();
    Rectangle r;
    r.length = 2;
    r.width = 3;
    r.calculateArea();
    r.calculatePerimeter();
    r.display();
    return 0;
}