#include <iostream>

class SinhVien{
    private:
    std::string name;
    int age;
    int diem;   
    public:
    SinhVien(std::string sName, int iAge, int iDiem) : name(sName), age(iAge), diem(iDiem) {}
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
