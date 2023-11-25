<details> 
    <summary><h1>⭐ C programming language <h2></summary>

<details> 
    <summary><h2>struct and union </h3></summary>

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
    <summary><h2>Phân vùng bộ nhớ ram </h3></summary>

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
<details>
    <summary><h2>Kiểu dữ liệu </h3></summary>


- Biến số nguyên (**Integer Variables**): Lưu trữ giá trị số nguyên không có phần thập phân.
	`int age = 25;`
- Biến số thực (**Floating-point Variables**): Lưu trữ giá trị số thực có phần thập phân.
	`float pi = 3.14;`
- Biến dấu chấm động (**Floating-point Variables**): Lưu trữ giá trị số thực có độ chính xác cao hơn float.
    `double pi = 3.14159;`
- Biến dài (**Long Variables**): Lưu trữ giá trị số nguyên có phạm vi mở rộng so với int.
    `long population = 1000000;`
- Biến ngắn (**Short Variables**): Lưu trữ giá trị số nguyên có phạm vi nhỏ hơn so với int.
    `short temperature = -10;`
- Biến ký tự (**Character Variables**): Lưu trữ một ký tự.
	`char grade = 'A';`
- Biến chuỗi ký tự (**String Variables**): Lưu trữ một chuỗi các ký tự.
	`char name[] = "John";`
- Biến boolean (**Boolean Variables**): Lưu trữ giá trị đúng (1) hoặc sai (0).
	`int isTrue = 1;`
- Con trỏ (**Pointer Variables**): Lưu trữ địa chỉ của một biến hoặc vùng nhớ.
	`int* ptr = NULL;`
- Biến mảng (**Array Variables**): Lưu trữ nhiều giá trị trong một biến duy nhất.
	`int numbers[] = {1, 2, 3, 4, 5};`
- Biến kích thước (**Size Variables**): Lưu trữ giá trị kích thước của các đối tượng trong bộ nhớ.
    ```size_t length = 10;```
- Biến không đổi (**Constant Variables**): Lưu trữ giá trị không thay đổi trong suốt thời gian chương trình chạy.
    ```const int MAX_VALUE = 100;```
- Biến từ khóa (**Keyword Variables**): Lưu trữ giá trị trùng với các từ khóa được định nghĩa trong ngôn ngữ C.
    ```int int = 5;```
- Biến từ xa (**Extern Variables**):Khai báo một biến đã được định nghĩa trong một tệp tin khác.
    ```extern int globalVar;```
- Biến có phạm vi tĩnh (**Static Scope Variables**): Lưu trữ giá trị trong suốt vòng đời của biến và chỉ có thể truy cập trong phạm vi của một hàm hoặc tệp tin.
    ```static int count = 0;```
- Biến hệ thống (**System Variables**): Lưu trữ thông tin đối với chương trình chạy, như số lượng tham số dòng lệnh và danh sách tham số.
    ```int argc; char** argv;```
- Biến môi trường (**Environment Variables**): Lưu trữ thông tin môi trường hệ thống như đường dẫn, biến cấu hình, v.v.
    `char* path = getenv("PATH");`
- Biến vô kiểu (**Void Variables**): Lưu trữ một địa chỉ bất kỳ và có thể chuyển đổi thành bất kỳ kiểu con trỏ nào.
	`void* ptr;`
- Biến hằng số từ xa (**Extern Constant Variables**): Khai báo một hằng số đã được định nghĩa trong một tệp tin khác. 
    `extern const int MAX_VALUE;` 
- Biến gần (**Auto Variables**): Được sử dụng để chỉ ra rằng một biến cục bộ tự động sẽ được tạo ra.
 	`auto int x = 5;`
- Biến trình tự (**Sequence Variables**): Chỉ định rằng một biến thường được truy cập nhanh chóng và thường xuyên.
    `register int counter = 0;`
- Biến quyền (**Qualifier Variables**): Đánh dấu biến có thể thay đổi mà không cần thông báo và không nên tối ưu hóa.
   	`volatile int status;`
- Biến tĩnh (**Static Variables**): Lưu trữ giá trị trong suốt vòng đời của chương trình và giá trị được duy trì ngay cả khi hàm hoặc khối lệnh kết thúc.
	```static int count = 0;```
- Biến tĩnh cục bộ (**Local Static Variables**): Lưu trữ giá trị trong suốt vòng đời của biến, nhưng chỉ có thể truy cập trong phạm vi của một hàm.
    ```C
    void function() {
        static int count = 0;
        // ...
    }
    ```
- Biến toàn cục (**Global Variables**): Khai báo ngoài hàm. Lưu trữ giá trị có thể truy cập từ bất kỳ đâu trong chương trình.
	```int globalVar = 10;```
- Biến cục bộ (**Local Variables**): Khai báo trong hàm. Lưu trữ giá trị chỉ có thể truy cập trong phạm vi của một hàm hoặc khối lệnh.
	```C
	void function() {
    	int localVar = 5;
   		// ...
	} 
	```
- Biến tên (**Label Variables**): Đánh dấu một vị trí trong mã chương trình để nhảy đến khi sử dụng lệnh goto.
    ```C
    goto label;
    // ...
    label:
        // ...
    ```
- Biến tham chiếu (**Reference Variables**): Lưu trữ một tham chiếu đến một biến đã tồn tại, cho phép thay đổi giá trị của biến qua tham chiếu.
    ```C
    int x = 10;
    int& ref = x;
    ```
- Biến hàm (**Function Variables**): Lưu trữ địa chỉ của một hàm và cho phép gọi hàm thông qua con trỏ.
    ```C
    int (*func_ptr)(int, int);
    int sum(int a, int b) {
        return a + b;
    }
    func_ptr = sum;
    ```
- Biến cấu trúc (**Structure Variables**): Lưu trữ các thành phần có liên quan vào một biến.
    ```
    struct Person {
        char name[20];
        int age;
    };
    struct Person p1;
	```
- Biến cấu trúc mở rộng (**Extended Structure Variables**): Lưu trữ các thành phần có liên quan vào một biến và mở rộng chức năng của cấu trúc.
    ```C
    struct Person {
        char name[20];
        int age;
    } p1;
    ```
- Biến liên kết (**Union Variables**): Lưu trữ giá trị của một thành phần trong một thời điểm.
    ```
    union Data {
        int x;
        float y;
    };
    union Data data;
    ```
- Biến liệt kê (**Enumeration Variables**): Lưu trữ một trong các giá trị được xác định trước từ một tập hợp các giá trị có tên.
    ```
    enum Color {
        RED,
        GREEN,
        BLUE
    };
	enum Color c = BLUE;
- Biến kiểu định danh (**Typedef Variables**): Tạo ra một tên mới cho một kiểu dữ liệu đã tồn tại để sử dụng dễ dàng hơn.
    ```C
    typedef int Integer;
    Integer number = 42;
	```
- Biến kiểu dữ liệu do người dùng định nghĩa (**User-defined Data Type Variables**): Định nghĩa và sử dụng kiểu dữ liệu tùy chỉnh trong ngôn ngữ C.
	```C
	typedef struct {
    	char name[20];
    	int age;
	} Person;
	Person p1; 
	```
### Khác nhau của static cục bộ và static toàn cục:
- Biến static cục bộ: Khi 1 biến cục bộ được khai báo với từ khóa static. Biến sẽ chỉ được khởi tạo 1 lần duy nhất và tồn tại suốt thời gian chạy chương trình. Giá trị của nó không bị mất đi ngay cả khi kết thúc hàm. Tuy nhiên khác với biến toàn cục có thể gọi trong tất cả mọi nơi trong chương trình, thì biến cục bộ static chỉ có thể được gọi trong nội bộ hàm khởi tạo ra nó. Mỗi lần hàm được gọi, giá trị của biến chính bằng giá trị tại lần gần nhất hàm được gọi.
- Biến static toàn cục: Biến toàn cục static sẽ chỉ có thể được truy cập và sử dụng trong File khai báo nó, các File khác không có cách nào truy cập được. 
</details>
<details>
  <summary><h3>Pointer</h3></summary>
	
- Bộ nhớ RAM chứa rất nhiều ô nhớ, `mỗi ô nhớ có kích thước 1 byte`. Mỗi ô nhớ có địa chỉ duy nhất và địa chỉ này được đánh số từ 0 trở đi. Nếu `CPU 32bit` thì có `2^32 địa chỉ` có thể đánh cho các ô nhớ trong RAM.
	| Ô nhớ | 0 | 1 | ... | 2^32-2 | 2^32-1 |
  	|:-------:|:--------:|:--------:|---|:----------:|:--------:|
  	| Địa chỉ |0x00000000|0x00000001|...|0x0=fffffffe|0xffffffff|
	| Giá trị |          |     5    |...|     's'    |          |
	|   Biến  |          |     x    |...|    char    |          |
- Khi khai báo biến, trình biên dịch dành riêng một vùng nhớ với địa chỉ duy nhất để lưu biến. Trình biên dịch có nhiệm vụ liên kết địa chỉ ô nhớ đó với tên biến. Khi gọi tên biến, nó sẽ truy xuất tự động đến ô nhớ đã liên kết với tên biến để lấy dữ liệu. Các bạn phải luôn phân biệt giữa `địa chỉ bộ nhớ` và `dữ liệu được lưu trong đó`.
- Địa chỉ của biến bản chất cũng là một con số thường được biểu diễn ở `hệ cơ số 16`. Ta có thể sử dụng con trỏ (pointer) để lưu địa chỉ của các biến.
- ***Con trỏ(pointer):***
	- Trong ngôn ngữ C/C++, con trỏ (pointer) là những biến lưu trữ địa chỉ bộ nhớ của những biến khác.
	- Kích thước của các biến con trỏ có khác nhau không? Con trỏ chỉ lưu địa chỉ nên kích thước của mọi con trỏ là như nhau. Kích thước này phụ thuộc vào môi trường hệ thống máy tính:
		- `Môi trường Windows 32 bit: 4 bytes`
        - `Môi trường Windows 64 bit: 8 bytes`
### Các loại con trỏ:
- ***Con trỏ NULL:*** Con trỏ NULL là con trỏ lưu địa chỉ 0x00000000. Tức địa chỉ bộ nhớ 0, có ý nghĩa đặc biệt, cho biết con trỏ không trỏ vào đâu cả.
	```c
	int *p2; //con trỏ chưa khởi tạo, vẫn trỏ đến một vùng nhớ nào đó không xác định
	int *p3 = NULL; //con trỏ null không trỏ đến vùng nhớ nào
	int *p4 = null; // Lỗi "null" phải viết in hoa
	```
- ***Con trỏ đến con trỏ(pointer to pointer):*** Con trỏ này dùng để lưu địa chỉ của con trỏ khác.
	```c
	int x = 10;
    int *p1 = &x;     // Con trỏ p1 trỏ đến biến x và giá trị của p1 chỉnh là địa chỉ của biến x
    int **p2 = &p1;	 // Con trỏ p2 trỏ đến con trỏ p1 và lưu địa chỉ của con trỏ p1 vào p2  

    printf("Giá trị của x: %d\n", *p1); //Giá trị của x: 10
    printf("Địa chỉ của x: %p\n", p1); //Địa chỉ của x: 0x7ffee2a697a8 
    printf("Giá trị của x: %d\n", **p2); //Giá trị của x: 10
    printf("Địa chỉ của p1: %p\n", p2); //Địa chỉ của p1: 0x7ffee2a697a0
	```
- ***Con trỏ hằng (Constant Pointers):*** Không thể thay đổi giá trị mà nó trỏ tới, nhưng có thể thay đổi địa chỉ mà nó trỏ tới.
	```c
	int num = 10; 
	const int *ptr = &num; //thay đổi được địa chỉ của num nhưng không thay đổi được giá trị '10' của num
	```
- ***Con trỏ void (Void Pointers):*** Con trỏ void có thể trỏ tới bất kỳ kiểu dữ liệu nào, nhưng khi xuất ra giá trị thì phải ép kiểu.
	```c
	int num = 10;
	float f = 3.14;
	void *ptr;
	ptr = &num;
	printf("num = %d\n",(int*)ptr);
	ptr = &f;
	printf("f = %f\n",(float*)ptr);
	```
- ***Con trỏ hàm (Function Pointers):*** Dùng để lưu trữ và gọi các hàm thông qua con trỏ.
	```c
	int add(int a, int b) {
		return a + b;
	}
	int subtract(int a, int b) {
		return a - b;
	}

	int main() {
	
		int (*operation)(int, int) = add;
		int result = operation(5, 3);
		printf("Result: %d\n", result);

		operation = subtract;
		result = operation(5, 3);
		printf("Result: %d\n", result);

		return 0;
	}

	```
- ***Con trỏ vào hàm (Pointers to Functions):*** Lưu trữ địa chỉ của một hàm cụ thể để gọi hàm thông qua con trỏ.
	```c
	int add(int a, int b) {
		return a + b;
	}
	int subtract(int a, int b) {
		return a - b;
	}

	void performOperation(int a, int b, int (*operation)(int, int)) {
		int result = operation(a, b);
		printf("Result: %d\n", result);
	}

	int main() {
		int a = 5, b = 3;

		performOperation(a, b, add);
		performOperation(a, b, subtract);

		return 0;
	}

	```
- ***Con trỏ hàm parameter (Function Pointer Parameters):*** Truyền một hàm như một tham số cho một hàm khác.
	```c
	void greet() {
		printf("Hello, World!\n");
	}

	void performAction(void (*action)()) {
		action();
	}

	int main() {
		performAction(greet);

		return 0;
	}

	```
### Lưu ý khi sử dụng con trỏ
- Khi khởi tạo con trỏ NULL: Chữ NULL phải viết hoa, viết thường null sẽ bị lỗi.
- Không nên sử dụng con trỏ khi chưa được khởi tạo: Kết quả tính toán có thể sẽ phát sinh những lỗi không lường trước được nếu chưa khởi tạo con trỏ.
- Sử dụng biến con trỏ sai cách.

</details>
</details>


<details> 
    <summary><h1>⭐ C++ programming language <h2></summary>
<details> 
	<summary><h3>Class</h3></summary>

### Class là gì?
Class hay lớp là một mô tả trừu tượng (abstract) của nhóm các đối tượng (object) có
cùng bản chất, ngược lại mỗi một đối tượng là một thể hiện cụ thể (instance) cho
những mô tả trừu tượng đó. Một class trong C++ sẽ có các đặc điểm sau:
- Một class bao gồm các thành phần dữ liệu (thuộc tính hay property) và các
phương thức (hàm thành phần hay method).
- Class thực chất là một kiểu dữ liệu do người lập trình định nghĩa.
- Trong C++, từ khóa class sẽ chỉ điểm bắt đầu của một class sẽ được cài đặt.
Khai báo 1 class:

```c++
	class Car {
		public:
		string name;	// property
		int model;		// property
		void disPlay(){ // method
			std::cout<<"name"<<name<<std::endl;
			std::cout<<"model"<<model<<std::endl;
		}
	}
```

Cú pháp tạo một object của class và sử dụng:

```c++
	Car car;
	car.name = "vinfast";
	car.mode = "14213";
	car.display(); // in ra màn hình name và model
```
### Pham vi truy cập cẩu các thuộc tính và phương thức
Có 3 phạm vi truy cập trong C++ là public, private và protected.
- Các thuộc tính và phương thức khai báo public thì có thể được truy cập trực
tiếp thông qua instance của class đó. Các thuộc tính nên khai báo là public
nếu bạn không có ràng buộc điều kiện trước khi gán (người dùng có thể
thoải mái gán giá trị) hoặc bạn không cần xử lý trước khi trả về giá trị thuộc
tính;
- Các thuộc tính private thường được sử dụng khi bạn không mong muốn
người khác có thể tùy ý gán giá trị hoặc là bạn muốn xử lý trước khi trả về
giá trị.
- Đối với protected, các phương thức và thuộc tính chỉ có thể truy cập qua
các class kế thừa nó hoặc chính nó.
vd:

```c++
	class Car {
		public:
		string name;
		private:
		void disPlay(){ // method
			std::cout<<"name"<<name<<std::endl;
		}
	}
```
### Method declaration
Phương thức cũng giống như một hàm bình thường.
Đối với phương thức thì có hai cách định nghĩa thi hành: định nghĩa thi hành trong
lúc định nghĩa class và định nghĩa thi hành bên ngoài class.
Định nghĩa thi hành bên trong class:

```c++
	class Car {
		public:
		string name;	// property
		int model;		// property
		void disPlay(){ // method
			std::cout<<"name"<<name<<std::endl;
			std::cout<<"model"<<model<<std::endl;
		}
	}
```

Định nghĩa thi hành ngoài trong class:

```c++
	class Car {
		public:
		string name;	// property
		int model;		// property
		void disPlay();
	}
	void Car::disPlay(){ // method
			std::cout<<"name"<<name<<std::endl;
			std::cout<<"model"<<model<<std::endl;
		}
```
