## RING_BUFFER_UART_STM32, Đang sử dụng uart2 , 9600, có ngắt. [[Link tải project stm32cubeIDE]](https://drive.google.com/file/d/1wDVpuR6tLLuQGhBVZVAhAoebv3edCGyu/view?usp=sharing)
- Ring Buffer (RB) là cấu trúc buffer sử dụng rất phổ biến trong lập trình nhúng vi điều khiển, ví dụ: Serial trong arduino sử dụng Ring Buffer, các cấu trúc lọc nhiễu với dữ liệu đầu vào là N phần tử mới nhất,...  Nắm vững cấu trúc này giúp các cấu trúc code của các bạn sẽ rất linh hoạt.
- Ring buffer được ứng dụng rộng rãi trong các hệ thống nhúng, sử dụng trong quá trình truyền dữ liệu không đồng bộ, hệ thống điều khiển thời gian thực khi có nhiều quá trình tương tác vào đối tượng.
# Cấu trúc của Ring Buffer
- Ring Buffer (RB) còn được gọi là Circular buffer (dịch nôm na là bộ đệm vòng), hoạt động theo nguyên tắc FIFO (First In, First Out). Điểm khác biệt với FIFO là khi đầy dữ liệu RB sẽ ghi đè lên dữ liệu cũ nhất (Circular).
# Có 2 cách hiện thực RB:
-   RB hiện thực trên một mảng (Array).
-   RB hiện thực trên một danh sách liên kết (Linklist).
# Trong khuôn khổ bài viết này mình sẽ ví dụ RB trên một Array.
Các hàm / phương thức dùng để thao tác / sử dụng RB:
- Khởi tạo RB
- Thêm một phần tử vào RB.
- Lấy một phần tử từ RB.
- Cơ chế quay vòng khi buffer đầy, nó sẽ ghi đè lên vị trí dữ liệu cũ nhất.
Ring Buffer có các biến như sau để hiện thực hóa việc trên:
- head: Vị trí để lấy dữ liệu ra từ buffer.
- tail: Vị trí để thêm một phần tử vào buffer.
- Các thành phần khác: fill size (có bao nhiêu dữ liệu đã put vào buffer), element size (kích thước của từng phần tử trong buffer)

# Cơ chế hoạt động của Ring Buffer hiện thực trên mảng (Array)
- Ring Buffer được khởi tạo với là một mảng với kích thước cố định, head và tail đều bằng vị trí đầu tiên của mảng.
![image](https://github.com/user-attachments/assets/824704c1-28af-4be6-aafe-f0a51b8f23be)

- Ví dụ: Mình gọi lệnh put (thêm) một phần tử vào mảng, nó sẽ trông như sau:

![image](https://github.com/user-attachments/assets/38ff9478-08a2-45f4-ba0d-66a2cb2f46ce)

- Sau khi put một phần tử, tail sẽ dịch sang chỉ mục (index) kế tiếp để chuẩn bị cho lần put kế tiếp. Tiếp theo mình thử put thêm một vài phần tử nữa.

![image](https://github.com/user-attachments/assets/62cf99b9-3454-468a-94ca-c3abd6c13665)

- Ok, bây giờ mình thử gọi lệnh get (lấy) để lấy một phần tử ra từ mảng.

![image](https://github.com/user-attachments/assets/d4ada249-cdce-4f7e-b8e0-26db7c4c768c)

- Như bạn thấy, tương tự như lúc put, sau khi lấy một phần tử ra từ mảng, head sẽ dời sang vị trí tiếp theo để chuẩn bị cho lần lấy kế tiếp. Mình sẽ lấy tiếp số 7 ra khỏi mảng.

 ![image](https://github.com/user-attachments/assets/713b824f-9339-4c45-ab3e-e6aa6d52517a)

- Bây giờ mình thêm tiếp các phần tử khác đến khi đầy mảng.

 ![image](https://github.com/user-attachments/assets/78ffc97e-073a-4f50-96c5-557b5141d107)

### Như các bạn thấy, khi đầy mảng, dữ liệu mới sẽ được ghi đè lên dữ liệu cũ nhất. Mình cũng có thể chủ động code các exception khi việc ghi đè dữ liệu này diễn ra. Vì thế mà Ring Buffer được sử dụng trong nhiều trường hợp như:
- Làm bộ đệm chờ xử lý: Khi viết chương trình truyền nhận dữ liệu giữa vi điều khiển và PC: khi nhận được 1 byte dữ liệu từ PC, trong Interrupt UART mình sẽ put byte nhận vào Ring Buffer, trong main() while loop sẽ kiểm tra kích thước RB và lấy dữ liệu ra xử lý. RB luôn đảm bảo Buffer không bị tràn nếu PC gửi liên tục, trường hợp xấu nhất nếu bạn không get kịp dữ liệu thì luôn có N dữ liệu mới nhất đang nằm trong buffer để xử lý.
- Các tính năng lọc nhiễu: Bạn làm tính năng lọc nhiễu cho ADC, phương pháp sử dụng 10 phần tử mới nhất để tính trung bình, dữ liệu sẽ đẩy định kì vào RB, khi nào cần tính toán, bạn chỉ cần lấy toàn bộ dữ liệu của RB ra tính trung bình là xong.

### OK code nhé ! Ví dụ làm bộ đệm chờ xử lý - Ring Buffer Char (RBC).
- Struct của RBC
  
![image](https://github.com/user-attachments/assets/c94cc132-6f70-4f53-b41c-ffa45406ac86)

- Hàm khởi tạo RBC
  
![image](https://github.com/user-attachments/assets/ae7b86ee-2f3e-4784-b3ee-44b75061afd6)

- Để thêm một kí tự, sử dụng hàm put (thêm) với code như sau
  
![image](https://github.com/user-attachments/assets/0feb6ff4-66db-4d62-b0bc-dbea38a69899)

-  Để lấy một kí tự, sử dụng hàm get (lấy) với code như sau
- 
![image](https://github.com/user-attachments/assets/9dd94e64-db5a-4469-b7fe-4e9cb7cb9537)

- Các chức năng khác để kiểm tra buffer đang trống (empty) hoặc đầy (full).
  
![image](https://github.com/user-attachments/assets/0529cf8d-070f-4ab7-8d9c-ee866e9076b4)






