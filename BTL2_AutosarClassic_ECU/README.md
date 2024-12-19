## ( Autosar Classic: Project 2 )
# ECU: Quản lý phanh tái sinh (Regenerative Braking Control)

---

## I. Giới thiệu 
Hệ thống quản lý hệ thống phanh tái sinh (Regenerative Braking Control) trong xe điện hoặc xe hybrid nhằm tận dụng chuyển động năng thành điện năng để nạp vào pin. Hệ thống bao gồm nhiều cảm biến để đo đạc tình trạng xe và điều chỉnh phanh tái sinh.

 <img src="https://github.com/hthuan02/C_Cpp_Advance/blob/main/BTL2_AutosarClassic_ECU/img/regen_brake_control_in_car.jpeg" alt="Memory Layout" width="850"/>
 
---
## II. Chức năng quản lý phanh tái sinh

### 1. Thu hồi năng lượng

- Tận dụng chuyển động năng khi phanh hoặc nhả ga.  
- Biến chuyển động năng thành điện năng để nạp vào pin.  
- Cải thiện hiệu suất sử dụng năng lượng, tăng quãng đường di chuyển.  

### 2. Giảm hao mòn

- Hạn chế sử dụng phanh truyền thống, giảm hao mòn phanh.  

---

## III. Nguyên lý hoạt động

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

## IV. Các tầng chính trong dự án 
Hệ thống quản lý phanh tái sinh (Regenerative Braking Control) được xây dựng dựa trên ba tầng chính của kiến trúc AUTOSAR: Software Component (SWC), Runtime Environment (RTE) và Basic Software (BSW). Dưới đây là mô tả chi tiết về từng tầng trong dự án :

### 1. Software Component (SWC)



### 1. `RegenBrakeControl_Init`

- Khởi tạo các cảm biến: tốc độ, trạng thái pin, độ nghiêng, tải trọng.  
- Kiểm tra trạng thái khởi tạo và báo lỗi nếu thất bại.  

### 2. `RegenBrakeControl_Update`

- Đọc dữ liệu từ các cảm biến.  
- Tính toán:  
  - Lực phanh tái sinh.  
  - Công suất tái sinh.  
  - Năng lượng tái sinh.  
  - Phần trăm pin được nạp.  
- Kiểm tra điều kiện hoạt động phanh tái sinh.  
- Điều chỉnh lực phanh theo:  
  - Góc nghiêng.  
  - Tải trọng.  

---

## V. Kết luận

Hệ thống quản lý phanh tái sinh không chỉ cải thiện hiệu suất năng lượng mà còn giảm hao mòn phanh, tăng tuổi thọ của xe. Đây là một giải pháp bền vững, hỗ trợ phát triển các phương tiện giao thông thân thiện với môi trường.
