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
