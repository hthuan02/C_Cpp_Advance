#include <iostream>

using namespace std;

class HinhChuNhat
{
public:
    double chieuDai;  // property: thuộc tính (biến/mảng)
    double chieuRong; // property: thuộc tính
    // void DienTich()
    // { // method: phương thức (hàm)
    //     cout << "Dien tich = " << chieuDai * chieuRong;
    // }
    void DienTich();
};

void HinhChuNhat::DienTich() // :: là toán tử truy cập 
{
    cout << "Dien tich = " << chieuDai * chieuRong << endl;
}

int main(int argc, char const *argv[])
{
    HinhChuNhat hcn; // object: đối tượng(hcn là đối tượng thuộc class HinhChuNhat)
    hcn.chieuDai = 10;
    hcn.chieuRong = 20;
    hcn.DienTich();
    return 0;
}
