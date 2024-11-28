# Bài 13: Class

## 1. Định nghĩa
Kiểu dữ liệu người dùng tự định nghĩa (tương tự struct & union).

```cpp
    class SinhVien{

    };
```

- không khai báo typedef cho class
 
## 2. Phạm vi truy cập

- Phục vụ tính chất hướng đối tượng(biến, hàm, mảng)
- Private  ->> Tính đóng gói
- Protected ->> Tính kế thừa
- Public ->> tính trừu tượng 

### 2.1 Class public

Phạm vi Public: Khi khai báo 1 object từ bên ngoài thì có thể tự do truy cập, thay đổi và đọc những thành phần bên trong phạm vi public (property, method).

Có 2 cách khai báo method(hàm)

- Cách 1: Khai báo method và nội dung của method trong Class

```cpp
#include <iostream>

using namespace std;

// Bên trong class không gọi là biến, hàm, mảng
class HinhChuNhat
{
public:
    double chieuDai;  // property: thuộc tính (biến/mảng)
    double chieuRong; // property: thuộc tính
    void DienTich()
    { // method: phương thức (hàm)
        cout << "Dien tich = " << chieuDai * chieuRong;
    }
};

int main(int argc, char const *argv[])
{
    HinhChuNhat hcn; // object: đối tượng(hcn là đối tượng thuộc class HinhChuNhat)
    hcn.chieuDai = 10;
    hcn.chieuRong = 20;
    hcn.DienTich();
    return 0;
}
```

- Cách 2: Khai báo method trong Class, nội dung để ở ngoài.

```cpp
#include <iostream>

using namespace std;

// Bên trong class không gọi là biến, hàm, mảng
class HinhChuNhat
{
public:
    double chieuDai;  // property
    double chieuRong; // property
    void DienTich(); // method
};

void HinhChuNhat::DienTich() // :: là toán tử truy cập 
{
    cout << "Dien tich = " << chieuDai * chieuRong << endl;
}

int main(int argc, char const *argv[])
{
    HinhChuNhat.hcn; // object
    hcn.chieuDai = 10;
    hcn.chieuRong = 20;
    hcn.DienTich();
    return 0;
}
```

#### Lưu ý: 
- Tương tự với struct & union, biến thì có địa chỉ. Khi khai báo 1 object thì Complier sẽ cấp địa chỉ để lưu những thành phần bên trong nó 

```cpp
int main(int argc, char const *argv[])
{
    HinhChuNhat.hcn; // object // 0xc0
    hcn.chieuDai = 10;
    hcn.chieuRong = 20;
    hcn.DienTich();
    return 0;
}
```

- Sau đó, object vào bên trong Class cấp địa chỉ cho các property, từ property đầu tiên. 

```c
class HinhChuNhat
{
public:
    double chieuDai;  // property // 0xc0 - 0xc7: 8byte
    double chieuRong; // property // 0xc8 - 0xcf
    void DienTich(); // method
};
```

### 2.2 Constructor
(Trong class có 1 method đặc biệt là Constructor, giúp khởi tạo giá trị cho property từ trong Class)

> Là method trùng tên với tên class.
>
> Được khai báo trong 3 phạm vi (public, private, protected).
>
> Tự động khởi chạy khi khai báo 1 object: Có 4 cách.

- Cách 1: Truy cập vào property từ bên ngoài.

```cpp
int main(int argc, char const *argv[])
{
    HinhChuNhat.hcn; // object  
    hcn.chieuDai = 10;
    hcn.chieuRong = 20;
    hcn.DienTich();
    return 0;
}
```
- Cách 2,3,4 Contructor

```cpp
    class HinhChuNhat{
        public:
            double chieuDai; 
            double chieuRong; 
            void DienTich();

            //Cách 2: Constructor không có tham số truyền vào
            // HinhChuNhat(){
            //     chieuDai = 20;
            //     chieuRong = 30;
            // }

            //Cách 3: Constructor có tham số truyền vào, không có tham số mặc định
            // HinhChuNhat(int dai, int rong){
            //     chieuDai = dai;
            //     chieuRong = rong;
            // }

           // Cách 4: Viết kiểu khác của cách 3, có tham số mặc định 
           HinhChuNhat(int dai = 5, int rong = 10): chieuDai(dai), chieuRong(rong){
                DienTich();
           }
    }; 

    void HinhChuNhat::Dientich(){
        cout << "Dien tich = " << chieuDai * chieuRong <<endl;
    }

    int main()
    {
        HinhChuNhat hcn(15,10); // object //150
        HinhCHuNhat hcn1; // Ghi đè lên 150, là 50
        // hcn.chieuDai = 10;
        // hcn.chieuRong = 20;  
        // hcn.DienTich();
        return 0;
    }
```
### 2.3 Destructor

> Cùng là method có tên trùng với tên Class, nhưng có thêm dấu `~` ở trước.
>
> Có thể nằm ở bất kỳ phạm vi nào (public, private, protected).
>
> Tự động khởi chạy khi tạo ra 1 object.

- Chạy Constructor trước, Destructor thực hiện cuối sau khi thực hiện các thao tác khác xong hết.

- Thu hồi lại object.

**Ứng dụng**:

- Cấp phát động cho 1 con trỏ.

- Khi sử dụng xong con trỏ, thay vì gán NULL. Mình có thể tự động thu hồi vùng nhớ bằng hàm Destructor.

_VD: Cách thức hoạt động của Constructor vs Destructor_

->> Hoạt động theo kiểu Stack(Last In-First Out)

### 2.4 Static trong Class

#### Static property

```cpp


#include <iostream>

using namespace std;

class HinhChuNhat
{
public:
    double chieuDai;  // property // 0xc0 - 0c7  object1 // 0x00 - 0x07   object2
    double chieuRong; // property // 0xc8 - 0xcf         // 0x08 - 0x0f
    // int var;       // property // 0xd0 - 0xd3         // 0x10 - 0x13

    /* Static
     * - Địa chỉ của biến static sẽ tồn tại xuyên suốt chương trình.
     * - Để sử dụng thì phải cấp phát địa chỉ thông qua truy cập từ class.
     * - Tất cả object khác vùng địa chỉ sẽ được sử dụng chung biến var.
     */
    static int var; // property // 0xa0 - 0xa3 (chung cho cả 2object)
};

int HinhChuNhat::var; // Truy cập từ trong class, không cần object. Để cấp phát địa chỉ dùng chung biến var

int main(int argc, char const *argv[])
{
    HinhChuNhat hcn1;
    HinhChuNhat hcn2;

    cout << "Address of var: " << &hcn1.var << endl; // &: C++ là tham chiếu
    cout << "Address of var: " << &hcn2.var << endl;
    return 0;
}
```

#### Static method

- Giống với static property, đều thuộc chung class -> Không cần khai báo object để gọi nó ra. Gọi trực tiếp bằng tên của Class.

- Static method chỉ gọi ra được property đi kèm với Static, không thể gọi property khác.


```cpp

#include <iostream>

using namespace std;

class HinhChuNhat
{
public:
    double chieuDai;  // property // 0xc0 - 0c7     // 0x00 - 0x07   object2
    double chieuRong; // property // 0xc8 - 0xcf    // 0x08 - 0x0f
    static int var;   // property // 0xa0 - 0xa3

    static void display()
    {
        cout << "This is static method" << endl;
        var = 20;
    }
};

int HinhChuNhat::var;

int main(int argc, char const *argv[])
{
    HinhChuNhat hcn1;
    HinhChuNhat hcn2;

    HinhChuNhat::display();
    return 0;
}
```

#### Lưu ý:

- Cả 2 đều truy cập từ trong Class, không cần truy cập object.

- **static property**: Truy cập vào bên trong  Class, để cấp phát địa chỉ tồn tại xuyên suốt chương trình. Tất cả object khai báo ra sẽ dùng chung địa chỉ này.

- **static method**: Chỉ làm việc được với property static.
