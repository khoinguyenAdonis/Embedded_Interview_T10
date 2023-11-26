#include <iostream>

class Shape {
    public:
    float area;
    float perimeter;
    virtual void calculateArea();
    virtual void calculatePerimeter();
    void display();
};

void Shape::calculateArea(){
    area = 0;
}
void Shape::calculatePerimeter(){
    perimeter = 0;
}
void Shape::display(){
    std::cout<<"Chu vi la: "<<area<<std::endl;
    std::cout<<"Dien tich la: "<<perimeter<<std::endl;
}

class Circle : public Shape{
    public:
    float radius;
    void calculateArea();
    void calculatePerimeter();
};

void Circle :: calculateArea (){
    area = 2*3.14*radius;
}
void Circle :: calculatePerimeter(){
    perimeter = 3.14*radius*radius;
}
class Rectangle :public Shape{
    public:
    float length;
    float width;
    void calculateArea();
    void calculatePerimeter();
};

void Rectangle :: calculateArea(){
    area = (length+width)*2;
}

void Rectangle :: calculatePerimeter(){
    perimeter = length*width;
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