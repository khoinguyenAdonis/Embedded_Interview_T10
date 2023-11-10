<details> 
    <summary><h1>▶ C programming language <h2></summary>

<details> 
    <summary><h2>▶struct and union </h3></summary>

### struct
Struct định nghĩa một kiểu dữ liệu mới, với hơn một thành phần trong chương trình, biến dạng struct bao gồm nhiều thành phần có thể thuộc nhiều kiểu dữ liệu khác nhau. Typedef Struct  khai báo/ định nghĩa một kiểu struct
vd 
th1: 
```c 
struct a {
    int b;
};
int main(void) {
     a c; // báo lỗi ở dòng này
	return 0;
}
```
th2:
```c
typedef struct a {
	int b;
} a; //định nghĩa struct a thành a

int main(void) {
a c; // không lỗi nữa
	        return 0;
}
```
Kích thước kiểu struct tối thiểu bằng kích thước các thành viên cộng lại tại vì còn phụ thuộc vào bộ nhớ đệm (struct padding). Dữ liệu của các thành viên của struct được lưu trữ ở những vùng nhớ khác nhau.
### union
Union trong C là một kiểu dữ liệu đặc biệt có sẵn trong C cho phép lưu trữ các kiểu dữ liệu khác nhau trong cùng một vị trí bộ nhớ. Cấu trúc của Union là tất cả các thành phần của nó dùng chung một vùng nhớ có kích thước tương ứng với thành phần lớn nhất.
Do đó kích thước của union là kích thước lớn nhất của kiểu dữ liệu trong nó. Thay đổi nội dung 1 thành viên trong union sẽ dẫn đến thay đổi nội dung của thành viên khác.

</details>
<details>
    <summary><h2>▶Phân vùng bộ nhớ ram </h3></summary>

|Stack|
|:-|
|↓|
|↑|
|Heap|
|Bss|
|Data|
|Text|
    
***Stack*** Quyền truy cập read and write.
- Được sử dụng cấp phát cho biến local, input parameter của hàm,...
- Sẽ được giải phóng khi ra khỏi block code/hàm .
- Các biến tạo trong vùng nhớ này có thể tự động được thu hồi, nên ta không cần các kỹ thuật thu hồi bộ nhớ như khi ta cấp phát động trong heap.

***Head*** Quyền truy cập Read and write.
- Được sr dụng để cấp phát bộ nhớ động.
- Các biến trong bộ nhớ này phải được thu hồi thủ công bằng cách sử dụng các hàm free()  

***Bss*** Quyền truy cập read and write.
- Chứa các biến global hoặc static khởi tạo bằng không hoặc không khởi tạo.
- Được giải phóng khi kết thúc chương trinhf.

***Data*** Quyền truy cập read and write.
- Chứa các biến global hoặc static được khởi tạo khác không.
- Được giải phóng khi kết thúc chương trình.

***Text*** Quyền truy cập read only.
- Chứa các biến khai báo hằng số.
- Chứa mã máy của chương trình đã được biên dịch.

</details>
<details>
    <summary><h2>Macro and Function </h3></summary>

### Macro
Chuyển thay thế macro bằng các văn bản code trong quá trình tiền xử lý. 
Khai báo:
```c
    #define MACRO text
    
    int main(){
        printf("MACRO");
    }
```
Tiền xử lý 
```c
    #define MACRO text
    
    int main(){
        printf("text"); // thay thế macro
    }
```
Nối chuổi:
```c
#define CREATE_VARIABLE(name)       \
int name##__kieuint;                \
double name##__kieudouble;
FUNC(hienthi,hello world\n);

int main(){
    CREATE_VARIABLE(test);
    return 0;
}
```
Tiền xử lý:
```c
    int main (){
        int test__kieuint;
        double test__kieudouble;
        return 0;
    }
```
### Function
Khi khởi tạo một Function chương trình sẽ cấp cho Function đó 1 địa chỉ cố định để khi dùng sẽ gọi đến địa chỉ đó. khi thực hiện xong các biến local, parameter function sẽ được thu hồi. Do đó sẽ tiết kiệm bộ nhớ. Macro sẽ chiếm nhiều bộ nhớ hơn do macro chỉ thay thế lại.
VD:
```c
    int addition(int value1, int value2)
{
	int sumary = value1 + value2;
	return sumary;
}

void introduce()
{
	cout << "Hello!" << endl;
	cout << "I'm a program" << endl;
}
```
</details>
<details>
    <summary><h2>Compiler </h3></summary>

### Compiler 
Là quá trình chuyển đổi ngôn ngữ viết thành ngôn ngữ bật thấp mà máy tinhs có thể hiểu và thực hiện được.
**Quá trình compiler bao gồm:**
- *Giai đoàn tiền xử lý (Pre-processor):* Nhận mã nguồn, Xóa bor các chú thích, chỉ thị tiền xử lý (bắt đầu bằng #) vd như #include cho phép ghép thêm tệp của mã nguồn cần biên dịch các #define cũng đuoc thay thế vào tạo ra file .i
    Cách xem file .i bằng  gcc: gcc -S -o filename.s filename.c
- *Giai đoạn dịch NNBC sang Asembly (Compiler):* Chuyển chúng sang dạng mã Assembly là một ngôn ngữ bậc thấp (hợp ngữ) gần với tập lệnh của bộ vi xử lý. Tạo file .s
    Cách xem file .s bằng gcc: gcc -S -o filename.s filename.c
- *Giai đoạn dịch asembly sang ngôn ngữ máy (Asember):* Dich chương trình => Sang mã máy 0 và 1.Một tệp mã máy (.obj) sinh ra trong hệ thống sau đó.
    Cách xem file .obj bằng gcc: gcc -c filename.c -o filename.o
- *Giai đoạn linker:*Trong giai đoạn này mã máy của một chương trình .o dịch từ nhiều nguồn (file .c hoặc file thư viện .lib) được liên kết lại với nhau để tạo thành chương trình đích nhất. Mã máy của các hàm thư viện gọi trong chương trình cũng được đưa vào chương trình cuối trong giai đoạn này. Chính vì vậy mà các lỗi liên quan đến việc gọi hàm hay sử dụng biến tổng thể mà không tồn tại sẽ bị phát hiện. Kể cả lỗi viết chương trình chính không có hàm main() cũng được phát hiện trong liên kết.
Kết thúc quá trình tất cả các đối tượng được liên kết lại với nhau thành một chương trình có thể thực thi được (executable hay .exe) thống nhất.

</details>