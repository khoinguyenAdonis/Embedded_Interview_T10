<details> 
    <summary><h2>▶ C programming language <h2></summary>

<details> 
    <summary><h3>▶struct and union <h3></summary>

# struct
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
# union
Union trong C là một kiểu dữ liệu đặc biệt có sẵn trong C cho phép lưu trữ các kiểu dữ liệu khác nhau trong cùng một vị trí bộ nhớ. Cấu trúc của Union là tất cả các thành phần của nó dùng chung một vùng nhớ có kích thước tương ứng với thành phần lớn nhất.
Do đó kích thước của union là kích thước lớn nhất của kiểu dữ liệu trong nó. Thay đổi nội dung 1 thành viên trong union sẽ dẫn đến thay đổi nội dung của thành viên khác.
</details>

<details>
    <summary><h3>▶Phân vùng bộ nhớ ram <h3></summary>

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
    <summary><h3>Macro and Function </h3></summary>


    