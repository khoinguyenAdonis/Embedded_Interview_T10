#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool sortName(string arr1, string arr2){
    string::iterator it1 = arr1.begin();
    string::iterator it2 = arr2.begin();
    while(it1 != arr1.end()){
        if(*it1 == *it2){
            it1++;
            it2++;
            continue;
        }else if (*it1 > *it2) return true;
        else return false;
    }
    return false;
}


class Student{
    private:
    string name;
    int age;
    int id;
    float math;
    float physics;
    float chemistry;
    float mediumScore ;
    string classify;
    public : 
    Student(string sName = "", int iAge = 0, float fMath = 0, float fPhysics = 0, float fChemistry = 0 ): name(sName),age(iAge),math(fMath),physics(fPhysics),chemistry(fChemistry){
        static int Id = 0;
        Id ++;
        id = Id;
    }
    void caculateScore();
    void classification();
    void displayIfo();
    void edit(string sName, int iAge,  float fMath, float fPhysics, float fChemistry);
    int Id();
    string Name(){
        return name;
    }
    float getMediumScore();
};

void Student::caculateScore(){
    mediumScore = (math+physics+chemistry)/3;
}

void Student::classification(){
    if (mediumScore >= 8.5) classify = "GIOI";
    else if(mediumScore<8.5 &&mediumScore>= 6.5) classify = "KHA";
    else if(mediumScore<6.5 &&mediumScore>= 5) classify = "TRUNGBINH";
    else classify = "YEU";
}

void Student::displayIfo(){    
    cout<<" | ID : "<<id;
    cout<<" | Ho & Ten : "<< name;
    cout<<" | Tuoi : "<< age;
    cout<<" | Diem TB : "<< mediumScore;
    cout<<" | Hoc Luc : "<< classify<<endl;

}
int Student:: Id(){
        return id;
    }
void Student::edit(string sName, int iAge, float fMath, float fPhysics, float fChemistry){
    name = sName;
    age = iAge;
    math = fMath;
    physics = fPhysics;
    chemistry = fChemistry;
}
float Student::getMediumScore(){
    return mediumScore;
}
class StudentManagement {
    private:
        vector<Student> array;
    public:
        void addStudent();
        void removeStudent();
        void editStudent();
        void arrangeName();
        void arrangeScore();
        void display();
};

void StudentManagement::addStudent(){
    string name;
    int age;
    float math;
    float physics;
    float chemistry;
    cout<<"Nhap thong tin sinh vien:"<<endl;
    cout<<"Ho & ten  : "; getline(cin,name);
    fflush(stdin);
    cout<<"Tuoi : "; cin>>age;
    fflush(stdin);
    do
    {
        cout << "Toan : ";
        cin >> math;
        
    } while (math > 10 || math < 0);
    do
    {
        fflush(stdin);
        cout << "Ly   : ";
        cin >> physics;
        
    } while (physics > 10 || physics < 0);
    do
    {
        fflush(stdin);
        cout << "Hoa  : ";
        cin >> chemistry;
        
    } while (chemistry > 10 || chemistry < 0);
    cin.ignore();
    Student student(name,age,math,physics,chemistry);
    student.caculateScore();
    student.classification();
    array.push_back(student);
    cout<<"Them thanh cong"<<endl;
}

void StudentManagement::display(){
    for(auto item : array){
        item.displayIfo();
    }
}
void StudentManagement::removeStudent(){
    int id;
    int count = 0;
    cout<<"Nhap ID sinh vien can xoa: ";
    cin>>id;
    if(array[0].Id() == id) {
        array.erase(array.begin());
        cout<<"Da xoa sinh vien co ID : "<<id<<endl;
        return;
    }
    else{
        for(auto item : array){  
            if(item.Id() == id) break;
            else count ++;
        }
        if (count>0){
            array.erase(array.begin() + count);
            cout<<"Da xoa sinh vien co ID : "<<id<<endl;
            return;
        }
        else cout<<"khong tim thay sinh vien co ID: "<< id<<endl;
    }
}

void StudentManagement::editStudent(){
    int id;
    int count = 0;
    string name;
    int age;
    float math;
    float physics;
    float chemistry;
    cout<<"Nhap ID sinh vien can thay doi: ";
    cin>>id;
    for(auto i = 0; i< array.size(); i++){  
        if(array[i].Id() == id) {
            cout<<"Da tim thay sinh vien co ID : "<<id<<endl;
            array[i].displayIfo();
            cout<<"Nhap thong tin sinh vien thay doi:"<<endl;
            cout<<"Ho & ten  : "; getline(cin,name);
            fflush(stdin);
            cout<<"Tuoi : "; cin>>age;
            fflush(stdin);
            do
            {
                cout << "Toan : ";
                cin >> math;
                fflush(stdin);
            } while (math > 10 || math < 0);
            do
            {
                cout << "Ly   : ";
                cin >> physics;
                fflush(stdin);
            } while (physics > 10 || physics < 0);
            do
            {
                cout << "Hoa  : ";
                cin >> chemistry;
                cin.ignore();
            } while (chemistry > 10 || chemistry < 0);

            array[i].edit(name,age,math,physics,chemistry);
            array[i].caculateScore();
            array[i].classification();
            cout<<"Da thay doi thong tin sinh vien"<<endl;
        
        }
        else cout<<"khong tim thay sinh vien co ID: "<< id<<endl;
    }
}

void StudentManagement::arrangeName(){
    vector<Student> temp;
    for (int i = 0; i < array.size(); i++){
        int j = i+1;
        for (j; j< array.size(); j++){
            if(sortName(array[i].Name(), array[j].Name())){
                temp.push_back(array[i]);
                array[i] = array[j];
                array[j] = temp[0];
            }
            temp.clear();
        }
    }
}

void StudentManagement::arrangeScore(){   
    vector<Student> temp;
    for (int i = 0; i < array.size(); i++){
        int j = i+1;
        for (j; j< array.size(); j++){
            if(array[i].getMediumScore() > array[j].getMediumScore()){
                temp.push_back(array[i]);
                array[i] = array[j];
                array[j] = temp[0];
            }
            temp.clear();
        }
    }
}

void graphic(){
     int option; 
    StudentManagement a;
    while (1)
    {
        system("clear");
        cout<<"----------------Student__Management----------------"<<endl;
        cout<<"| *CHON CHUC NANG CHUONG TRINH:                   |"<<endl;
        cout<<"|>1. THEM SINH VIEN                               |"<<endl;
        cout<<"|>2. XOA SINH VIEN                                |"<<endl;
        cout<<"|>3. SUA THONG TIN SINH VIEN                      |"<<endl;
        cout<<"|>4. SAP XEP SINH VIEN                            |"<<endl;
        cout<<"|>5. HIEN THI DANH SACH SINH VIEN                 |"<<endl;
        cout<<"|>6. THOAT CHUONG TRINH                           |"<<endl;
        cout<<"---------------------------------------------------"<<endl;
        cout<<"   NHAP CHUC NANG CHUONG TRINH: ";
        cin>>option;
        cout<<"---------------------------------------------------"<<endl;  
        fflush(stdin);
        switch (option)
        {
        case 1:
            do
            {
                system("clear");
                option = 0;
                cout<<"----------------Student__Management----------------"<<endl;
                cout<<"| *CHON CHUC NANG CHUONG TRINH:                   |"<<endl;
                cout<<"|>1. THEM MOT SINH VIEN                           |"<<endl;
                cout<<"|>2. THEM NHIEU SINH VIEN                         |"<<endl;
                cout<<"|>3. EXIT                                         |"<<endl;
                cout<<"|                                                 |"<<endl;
                cout<<"|                                                 |"<<endl;
                cout<<"|                                                 |"<<endl;
                cout<<"---------------------------------------------------"<<endl;
                cout<<"   NHAP CHUC NANG CHUONG TRINH: ";
                cin>>option;
                cin.ignore();
                cout<<"---------------------------------------------------"<<endl; 
                if(option == 1){
                    system("clear");
                    cout<<"----------------THEM_MOT_SINH_VIEN----------------"<<endl;
                    a.addStudent();
                }
                else if (option == 2 ){
                    system("clear");
                    int count = 0;
                    cout<<"Nhap so luong sinh vien: ";
                    cin>>count;
                    cin.ignore();
                    for (int  i = 0; i < count; i++)
                    {
                        system("clear");
                        cout<<"----------------THEM_NHIEU_SINH_VIEN----------------"<<endl;
                        cout<<"sinh vien thu "<<i+1<<endl;
                        a.addStudent();
                    }   
                }
                else if (option == 3){
                    system("clear");
                    break;
                }
            /* code */
        } while (option >0 && option <4);
                        
            break;
        case 2:
            system("clear");
            cout<<"----------------XOA_MOT_SINH_VIEN----------------"<<endl;
            a.removeStudent();
            system("clear");
            break;
        case 3:
            system("clear");
            cout<<"----------------SUA_THONG_TIN_SINH_VIEN----------------"<<endl;
            a.editStudent();
            system("clear");
            break;
        case 4:
            system("clear");
            cout<<"----------------SAP_XEP_SINH_VIEN----------------"<<endl;
            do
            {
                system("clear");
                option = 0;
                cout<<"----------------SAP_XEP_SINH_VIEN------------------"<<endl;
                cout<<"| *CHON CHUC NANG CHUONG TRINH:                   |"<<endl;
                cout<<"|>1. SAP XEP THEO TEN                             |"<<endl;
                cout<<"|>2. SAP XEP THEO DIEM TRUNG BINH                 |"<<endl;
                cout<<"|>3. EXIT                                         |"<<endl;
                cout<<"|                                                 |"<<endl;
                cout<<"|                                                 |"<<endl;
                cout<<"|                                                 |"<<endl;
                cout<<"---------------------------------------------------"<<endl;
                cout<<"   NHAP CHUC NANG CHUONG TRINH: ";
                cin>>option;
                cin.ignore();
                cout<<"---------------------------------------------------"<<endl; 
                if(option == 1){
                    system("clear");
                    cout<<"----------------SAP XEP THEO TEN----------------"<<endl;
                    a.arrangeName();
                    cout<<"          --------------------------"<<endl; 
                    cout<<"          | DA SAP XEP THANH CONG! |"<<endl;
                    cout<<"          --------------------------"<<endl;
                    cout<<"            NHAP PHIM *3* DE THOAT :";
                    cin>>option;
                    cin.ignore();
                }
                else if (option == 2 ){
                    system("clear");
                    cout<<"----------------SAP XEP THEO ID----------------"<<endl;
                    a.arrangeScore();
                    cout<<"          --------------------------"<<endl; 
                    cout<<"          | DA SAP XEP THANH CONG! |"<<endl;
                    cout<<"          --------------------------"<<endl;
                    cout<<"            NHAP PHIM *3* DE THOAT :";
                    cin>>option;
                    cin.ignore();
                }
                else if (option == 3){
                    system("clear");
                    break;
                }
            /* code */
        } while (option >0 && option <4);
                        
            break;
        case 5:
            system("clear");
            cout<<"----------------DANH_SACH_SINH_VIEN---------------------------------------------"<<endl;
            a.display();
            cout<<"--------------------------------------------------------------------------------"<<endl; 
            cout<<"NHAP PHIM *3* DE THOAT :";
            cin>>option;
            break;
        case 6:
            exit(1);
        default:
            break;
        }
        /* code */
    }
}

int main(){

    graphic();
    
    return 0;
}