# Bài 14: OPP - Inheritance (Part 2)

#### Phạm vi truy cập:

- **public**: method, property bên trong và object bên ngoài có thể truy cập.

- **protected**:  
    - Object bên ngoài không thể truy cập method, property (giống private).
    - Class con kế thừa có thể truy cập.

- **private**: 
    - Class con kế thừa không thể truy cập (chỉ có phạm vi trong nội bộ class: method, property tron
    g nội bộ class mới truy cập được)

# III. Tính kế thừa

> Kế thừa là khả năng sử dụng lại các property, method class khác.
>
> Có 3 kiểu kế thừa: public, private, protected. 
>
> Có 2 cách dùng: ghi đè (Override) hoặc sử dụng lại. 

## 1. Kế thừa public
(Giữ nguyên)

- Các thành viên của Class cha phạm vi public, protected sẽ giữ nguyên phạm vi kế thừa khi sang class con. 

- Thành viên phạm vi private thì class con không thể kế thừa.

_VD1: (Code minh họa Complier chạy)_

```cpp
class DoiTuong{
    private:
        string a;
    
    protected:
        int b;

    public:
        string ten;
        int id;
};

class SinhVien  : public DoiTuong{
    protected:
        int b;
    public:
        string ten;
        int id;

    public:
        string chuyenNganh;
};
```

### Đặc điểm của kế thừa:

- Có thể ghi đè lên method của class mà nó kế thừa gọi là **Override**.

_VD2:_

```cpp
class DoiTuong{
    protected:
        string ten;
        int id;

    public:
        DoiTuong(){  
            static int ID = 1;
            id = ID;
            ID++;
        }

        void setName(string _ten){
            // check chuỗi nhập vào
            ten = _ten;
        }

        void display(){
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
        }
};

class SinhVien : public DoiTuong{ 
    protected:
        string chuyenNganh;

    public:
        void setChuyenNganh(string _nganh){
            chuyenNganh = _nganh;
        }

        // method display được ghi đè
        void display(){ // override: ghi đè
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
            cout << "chuyen nganh: " << chuyenNganh << endl;
        }
};

class HocSinh : public DoiTuong{
    protected:
        string lop;
   
    public:
        void setLop(string _lop){
            lop = _lop;
        }

        void display(){ // override
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
            cout << "lop: " << lop << endl;
        }
};

class GiaoVien : public DoiTuong{
    protected:
        string chuyenMon;

    public:
        void setChuyenMon(string _mon){
            chuyenMon = _mon;
        }

        void display(){ // override
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
            cout << "chuyen mon: " << chuyenMon << endl;
        }
};
```
- Để phân biệt được 3 method `display()` cùng tên với nhau, thì dựa vào object mà nó tạo ra  

```cpp
int main(int argc, char const *argv[])
{
    SinhVien sv1;
    sv1.setName("Trung");
    sv1.setChuyenNganh("TDH");
    sv1.display();

    cout << endl;

    HocSinh hs1;
    hs1.setName("Tuan");
    hs1.setLop("12A1");
    hs1.display();

    cout << endl;

    GiaoVien gv1;
    gv1.setName("Hoang");
    gv1.setChuyenMon("Toan");
    gv1.display();
    return 0;
}
```
## 2. Kế thừa protected
(Thay đổi)

- Tất cả các thành viên của Class cha phạm vi public, protected sẽ chuyển protected ở Class con khi kế thừa.

#### Đặc điểm:

- Thành viên của Class cha phạm vi `private` thì class con không thể kế thừa.

- (Giống kế thừa Private): Object bên ngoài không thể truy cập property, method bên trong nó. 

->> Chỉ có thể truy cập thông qua class con kế thừa nó. 

- (Khác kế thừa Private): Class con khi kế thừa có thể sử dụng thành viên trong phạm vi protected.

_VD3: (Code minh họa Complier chạy)_

- Vì ở phạm vi protected, khi tạo object thuộc `class SinhVien` không thể truy cập method, property được.

_VD3:_

```cpp
class DoiTuong{
    protected:
        string ten;
        int id;

    public:
        DoiTuong(){  
            static int ID = 1;
            id = ID;
            ID++;
        }

        void setName(string _ten){
            // check chuỗi nhập vào
            ten = _ten;
        }

        void display(){
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
        }
};

class SinhVien : protected DoiTuong{
    protected:
        string ten;
        int id;
    protected:
        DoiTuong(){  
            static int ID = 1;
            id = ID;
            ID++;
        }

        void setName(string _ten){
            // check chuỗi nhập vào
            ten = _ten;
        }

        void display(){
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
        }
   
    // phạm vi của class chuyên ngành 
    protected:
        string chuyenNganh;

    public:
        void setChuyenNganh(string _nganh){
            chuyenNganh = _nganh;
        }

        void display(){ // override
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
            cout << "chuyen nganh: " << chuyenNganh << endl;
        }
};
```
## 3. Kế thừa private

- Giống với protected, các thành viên kế thừa thì chuyển về private hết.

_VD4:(Code minh họa Complier chạy)_

- Object của `class SinhVien` không thể truy cập được các thành viên.

- Nếu có class con kế thừa `class SinhVien` thì không thể sử dụng các thành viên kế thừa lại được nữa. 

_VD4:_

```cpp
class DoiTuong{
    protected:
        string ten;
        int id;

    public:
        DoiTuong(){  
            static int ID = 1;
            id = ID;
            ID++;
        }

        void setName(string _ten){
            // check chuỗi nhập vào
            ten = _ten;
        }

        void display(){
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
        }
};

class SinhVien : private DoiTuong{

    private:
        string ten;
        int id;

    private:
        DoiTuong(){  
            static int ID = 1;
            id = ID;
            ID++;
        }

        void setName(string _ten){
            // check chuỗi nhập vào
            ten = _ten;
        }

        void display(){
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
        }

    protected:
        string chuyenNganh;

    public:
        void setChuyenNganh(string _nganh){
            chuyenNganh = _nganh;
        }

        void display(){ // override
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
            cout << "chuyen nganh: " << chuyenNganh << endl;
        }
};
```

## 4. Đa kế thừa
 
- Class con có thể kế thừa từ nhiều class cha, phạm vi thì tương tự.

_VD5:_

```cpp
class SinhVien : public DoiTuong, protected HocSinh, private SinhVien{
}
```
 