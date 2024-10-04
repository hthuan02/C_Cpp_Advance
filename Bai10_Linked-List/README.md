# BÀI 10: LIKED LIST

- Liked list (danh sách liên kết): Là cấu trúc dữ liệu gồm chuổi các node(nút) liên kết với nhau, mỗi node gồm 2 thành phần: Data và con trỏ (*Next).

_VD0:_ Cho mảng `int array[] = {2,7,4,5,3};`

- Dùng Malloc:
  
        // Lưu trữ 5 phần tử * sizeof(int)= (20byte)

        // Thêm - Thu hồi phần tử bằng cách thủ công, nhưng đối với array[10000] thì không thể làm thủ công được.

        // Free()

➡️➡️➡️➡️➡️
- Liked list: Tạo 5 node

    <img src="https://github.com/hthuan02/C_Cpp_Advance/blob/main/Bai10_Linked-List/liked_list.png" alt="Memory Layout" width="800"/>

    - Trong danh sách liên kết này có thể thêm hoặc thu hồi tùy ý các phần tử.
 
    - Liked LIST còn có thể sử dụng ở quy mô lớn hơn như array[10000].
 
    - Các hàm sử dụng của danh sách dữ liệu LIST:

    ```
        node *createNode(int value); //Tạo 1 node mới, có giá trị value và trả về con trỏ node
        void push_back(node** array, int value); //Thêm 1 node mới có giá trị value vào cuối danh sách 
        void push_front(node **array, int value); //Thêm 1 node có giá trị value đầu danh sách
        void pop_back(node **array); //Xóa node cuối danh sách 
        void pop_front(node **array); //Xóa node đầu danh sách 
        int front(node *array); //Lấy giá trị của node đầu tiên
        int back(node *array); //Lấy giá trị của node cuối cùng
        void insert(node **array, int value, int pos); //Thêm 1 node vào một vị trí bất kỳ(int pos là vị trí)
        void delete_list(node **array, int pos); //Xóa 1 node ở vị trí bất kỳ
        int size(node *array); //Lấy kích thước node của danh sách
        int get(node *array, int pos); //Lấy giá trị của node(tại pos) của danh sách

        bool empty(node *array); // kiem tra list co rong hay khong
        //Không có hàm kiểm tra đầy, vì nó k quan tâm đến số lượng
    ```

**Ứng dụng: Liked List giúp quản lý danh sách tốt hơn mảng.**















    
