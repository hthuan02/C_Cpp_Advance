#include <iostream>
#include <string>

using namespace std;

// class trừu tượng
class DoiTuong {
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

        // Pure virtual
        virtual void display() = 0;

        // virtual void display(){
        //     cout << "ten: " << ten << endl;
        //     cout << "id: " << id << endl;
        // }
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
    

    // DoiTuong dt3;
    // dt3.display();
    return 0;

}


