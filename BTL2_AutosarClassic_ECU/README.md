## ( Autosar Classic: Project 2 )
# ECU: Quản lý phanh tái sinh (Regenerative Braking Control)

---

## I. Giới thiệu dự án
### 1. Hệ thống phanh tái sinh (Regenerative Braking Control)

> Hệ thống quản lý hệ thống phanh tái sinh trong xe điện hoặc xe hybrid nhằm tận dụng chuyển động năng thành điện năng để nạp vào pin. Hệ thống bao gồm nhiều cảm biến để đo đạc tình trạng xe và điều chỉnh phanh tái sinh.

 <img src="https://github.com/hthuan02/C_Cpp_Advance/blob/main/BTL2_AutosarClassic_ECU/img/regen_brake_control_in_car.jpeg" alt="Memory Layout" width="880"/>

### 2. Chức năng quản lý phanh tái sinh
#### 1. Thu hồi năng lượng

- Tận dụng chuyển động năng khi phanh hoặc nhả ga.  
- Biến chuyển động năng thành điện năng để nạp vào pin.  
- Cải thiện hiệu suất sử dụng năng lượng, tăng quãng đường di chuyển.  

#### 2. Giảm hao mòn

- Hạn chế sử dụng phanh truyền thống, giảm hao mòn phanh.  

---

## II. Nguyên lý hoạt động

- **Chuyển động năng thành điện năng**: Khi người lái nhả ga hoặc phanh, ECU kích hoạt chế độ phanh tái sinh. Động cơ điện chuyển động năng thành điện năng và nạp lại vào pin.

- **Kích hoạt phanh tái sinh**: Phanh tái sinh được kích hoạt khi nhả ga hoặc nhấn phanh để thu hồi năng lượng từ tốc độ di chuyển của xe.

- **Tái nạp vào pin**: Năng lượng tạo ra từ phanh tái sinh được nạp vào pin, kéo dài tuổi thọ và giảm nhu cầu sạc.

- **Lực phanh tái sinh**: ECU điều chỉnh lực phanh dựa trên tốc độ, độ nghiêng và mức độ nhấn phanh từ người lái để đảm bảo quá trình giảm tốc mượt mà và an toàn.

---

## III. Hệ thống cảm biến và điều chỉnh phanh tái sinh
### 1. Cảm biến tốc độ

- Đọc giá trị tốc độ hiện tại của xe.  
- Tính toán:  
  - Lực phanh tái sinh (Đơn vị: N).  
  - Công suất tái sinh (Đơn vị: W).  
  - Năng lượng tái sinh (Đơn vị: Wh).  
- Kiểm tra bàn đạp ga nhả hoặc phanh được nhấn, và tốc độ có đủ điều kiện.  

### 2. Cảm biến trạng thái pin

- Đo trạng thái sạc của pin (SOC).  
- Kiểm tra nhiệt độ pin.  
- Ngăn chặn tái nạp khi nhiệt độ pin quá cao.  
- Tính phần trăm pin được nạp từ năng lượng tái sinh.  

### 3. Cảm biến độ nghiêng

- Đo góc nghiêng xe (Đơn vị: °).  
- Xác định xe đang lên dốc, xuống dốc hoặc trên mặt phẳng.  
- Điều chỉnh lực phanh tái sinh dựa vào góc nghiêng.  

### 4. Cảm biến tải trọng

- Đo khối lượng xe hiện tại.  
- Điều chỉnh lực phanh tái sinh dựa vào tải trọng xe.  

---

## IV. Các tầng chính trong dự án (AUTOSAR)
Hệ thống quản lý phanh tái sinh (Regenerative Braking Control) được xây dựng dựa trên ba tầng chính của kiến trúc AUTOSAR:
- Software Component (SWC).
- Runtime Environment (RTE).
- Basic Software (BSW).

### 1. Software Component (SWC)
Software Component là tầng nằm ở trên cùng (Application Layer). Tầng SWC thiết kế để quản lý và điều khiển quá trình phanh tái sinh, bao gồm các chức năng như đọc dữ liệu từ cảm biến, tính toán lực phanh tái sinh, điều chỉnh các tham số liên quan, và tái nạp năng lượng vào pin.

- `RegenBrakeControl_Init(void)`: Hàm khởi tạo các cảm biến cần thiết như cảm biến tốc độ, cảm biến trạng thái pin, cảm biến góc nghiêng, và cảm biến tải trọng. 

- `RegenBrakeControl_Update(void)`: Hàm cập nhật và điều khiển phanh tái sinh, tính toán lực và công suất phanh tái sinh dựa trên dữ liệu cảm biến và các điều kiện như nhả ga, nhấn phanh, và tốc độ xe.

-  Trong hàm cập nhật, gồm các hàm nhỏ như:
   - Tái nạp năng lượng vào pin: Chuyển đổi năng lượng từ phanh tái sinh vào pin, đồng thời giám sát nhiệt độ pin để đảm bảo an toàn.

   - Điều chỉnh lực phanh tái sinh: Dựa trên góc nghiêng và tải trọng để đảm bảo hiệu quả và an toàn.

### 2. Runtime

## V. Kết luận

> Hệ thống quản lý phanh tái sinh không chỉ cải thiện hiệu suất năng lượng mà còn giảm hao mòn phanh, tăng tuổi thọ của xe. Đây là một giải pháp bền vững, hỗ trợ phát triển các phương tiện giao thông thân thiện với môi trường.
