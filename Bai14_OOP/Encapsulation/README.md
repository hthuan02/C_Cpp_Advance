# Bài 14: OOP - Encapsulation & Abstraction (Part 1)

# I. Tính đóng gói

- Đóng gói Là ẩn đi các property "mật" khỏi người dùng.

- Là khai báo property, method trong phạm vi private. Các object bên ngoài không thể gọi ra được.

- Khi muốn đọc hoặc ghi có property này, thì truy cập gián tiếp thông qua method phạm vi public.

## Phạm vi private:

- Chỉ có giá trị trong nội bộ class (chỉ những method bên trong mới truy cập được property của private).

- Object không thể truy cập tới.

- Khắc phục việc truyền 1 chuỗi vào object, sẽ không kiểm tra được cái chuỗi này có hợp lệ hay không 

VD:

```cpp
#include <iostream>

using namespace std;

class SinhVien
{
public:
    string ten;
    string id;
    int age;

    SinhVien(string ten, string id, int age) : ten(ten), id(id), age(age)
    {
    }
    void display()
    {
        cout << "Tên: " << ten << endl;
        cout << "ID: " << id << endl;
        cout << "Age: " << age << endl;
    }
};

int main(int argc, char const *argv[])
{
    SinhVien sv1("Huỳnh Minh Thuận123@", "hthuan02", 22);
    sv1.display();
    return 0;
}
```

->> Chuỗi `Ten` truyền vào ở object `sv1` không hợp lệ.

->> Những method trong phạm vi public có thể thêm điều kiện kiểm tra chuỗi.

### Lưu ý:

- Khi viết thêm method để kiểm tra chu thì không khởi tạo thông qua Constructor mà tạo method khác như: `setter method`, `getter mehod`.

_Khắc phục VD1:_

```cpp
#include <iostream>

using namespace std;

class SinhVien
{
private:
    string name;
    int id;
    int age;

public:
    SinhVien()
    {
        static int ID = 0;
        ID++;
        id = ID;

        /* - ID truy cập vào id phạm vi private bên trong Constructor SinhVien
         * - propety static: khi gọi object ra thì tự động khởi tạo ID cho SinhVien,
         * ID tự động tăng lên, tránh việc trùng lặp ID.
         */
    }

    // setter method: dùng khởi tạo giá trị cho property
    void setName(string newName)
    {
        // kiểm tra chuỗi truyền vào
        // có ký tự đặc biệt, số -> yêu cầu người dùng nhập lại
        name = newName;
    }

    // setter method
    void setAge(int age)
    {
        // kiểm tra số nhập vào
        age = age;
    }

    // getter method: đặt/trả dữ liệu về
    string getName()
    {
        return name;
    }

    // getter method
    int getAge()
    {
        return age;
    }

    // getter method
    int getID()
    {
        return id;
    }

    void display()
    {
        cout << "Tên: " << getName() << endl;
        cout << "ID: " << getID() << endl;
        cout << "Age: " << getAge() << endl;
    }
};

int main(int argc, char const *argv[])
{
    SinhVien sv1, sv2;
    sv1.setName("Thuan");
    sv1.display();

    sv2.setName("Tuan");
    sv2.display();
    return 0;
}
```
# II. Tính trừu tượng

Static đi với 1 hàm, thì giới hạn trong nội bộ 1 file. Những file bên ngoài không thể gọi ra được kể cả dùng `Extern`. Gọi là quá trình tạo ra kết quả (VD: Tính delta pt bậc 2)

- Tính trừu tượng là ẩn đi quá trình xử lý logic, quá trình tính toán, thuật toán (**method** thuật toán xử lý để tạo ra kết quả) -> private 

_VD: Giải phương trình bậc 2_

```cpp
class GiaiPhuongTrinh{
    private:	// a,b,c,x1,x2,delta: Tính đóng gói
        double a;
        double b;
        double c;
        double x1;
        double x2;
        double delta;

        // Tính trừu tượng: quả trình tính delta sẽ bị ẩn đi
        void tinhNghiem(){	
            delta = b*b - 4*a*c;
            if (delta < 0){
                delta = -1;
            }
            else if (delta == 0){
                x1 = x2 = -b/ (2*a);
            }
            else if (delta > 0){
                x1 = (-b + sqrt(delta))/(2*a);
                x2 = (-b - sqrt(delta))/(2*a);
            }
        }
       
    public:
        void enterNumber(double num_a, double num_b, double num_c);
        void printResult();
};
```
- Quá trình tạo ra kết quả (tính delta) người dùng không thể truy cập. Chỉ được phép: Truyền vào tham số cho method cần tính và in ra kết quả.

```cpp
int main()
{
  GiaiPhuongTrinh phuongtrinh1;
  phuongtrinh1.enterNumber(1,5,4);
  phuongtrinh1.printResult();
  return 0;
}
```
