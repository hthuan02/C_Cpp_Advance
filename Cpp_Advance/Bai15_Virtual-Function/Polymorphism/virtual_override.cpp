#include <iostream>
#include <string>

using namespace std;

class DoiTuong{
    // private:
    //    string ten;
    //    int id;

    // protected: class con khi kế thừa lại có thể sử dụng lại thành viên trong  class
    protected:
        string ten;
        int id;

    public:
        // Constructor tự động khởi chạy property ID, để mỗi lần chạy ID chắc chắn khác nhau 
        DoiTuong(){  
            static int ID = 1;
            id = ID;
            ID++;
        }

        void setName(string _ten){
            // check chuỗi nhập vào
            ten = _ten;
        }

        // Có thể ghi đè, bổ sung tính năng method (Override)
        virtual void display(){
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

        void display() override{ // ghi đè từ hàm ảo, phải ghi thêm override
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
            cout << "chuyen nganh: " << chuyenNganh << endl; // Ghi đè (Override)
        }
};

class HocSinh : public DoiTuong{
    protected:
        string lop;
   
    public:
        void setLop(string _lop){
            lop = _lop;
        }

        void display() override{ // override
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
            cout << "lop: " << lop << endl; // Override
        }
};

class GiaoVien : public DoiTuong{
    protected:
        string chuyenMon;

    public:
        void setChuyenMon(string _mon){
            chuyenMon = _mon;
        }

        void display() override{ 
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
            cout << "chuyen mon: " << chuyenMon << endl; // Override
        }
};

int main(int argc, char const *argv[])
{
    SinhVien sv1;
    sv1.setName("Trung");
    sv1.setChuyenNganh("TDH");
    // sv1.display();

    cout << endl;

    HocSinh hs1;
    hs1.setName("Tuan");
    hs1.setLop("12A1");
    // hs1.display();

    cout << endl;

    GiaoVien gv1;
    gv1.setName("Hoang");
    gv1.setChuyenMon("Toan");
    // gv1.display();

    cout << endl;

    // Tạo 1 object(1 ptr *dt1) thuộc class DoiTuong
    DoiTuong *dt1 = &sv1; 
    dt1->display();

    dt1 = &hs1;
    dt1->display();

    dt1 = &gv1;
    dt1->display();
    
    return 0;

    /***  
     * - Mặc dù object *dt1 trỏ đến địa chỉ sv1 của class SinhVien
     * - Nhưng vẫn in ra method display của của class DoiTuong
     * - Để khắc phục được thì thêm từ khóa Virtual.
     ***/
}


