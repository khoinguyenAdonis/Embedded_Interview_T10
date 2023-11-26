#include <iostream>

class SinhVien{
    public:
    std::string name;
    int age;
    int diem;
    SinhVien(std::string Name, int Age, int Diem){
        name = Name;
        age = Age;
        diem = Diem;
    }
    void displayInfo();
};

void SinhVien::displayInfo() {
    std::cout<<"Ten: "<<name<<std::endl;
    std::cout<<"Tuoi: "<<age<<std::endl;
    std::cout<<"Diem: "<<diem<<std::endl;
}
int main(){

    SinhVien Hao("Hao",20,10);
    Hao.displayInfo();

    return 0;

}
