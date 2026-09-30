1. Mục tiêu

Phân tích và khắc phục lỗi vượt biên chỉ số mảng trong chương trình quản lý số thứ tự khám bệnh.

Chương trình sử dụng mảng queue_numbers[4] để lưu 4 mã số thứ tự khám.

Trong C, chỉ số mảng bắt đầu từ 0, vì vậy 4 phần tử có index từ 0 đến 3.

2. Phân tích lỗi

Mã nguồn ban đầu có dòng:

queue_numbers[patient_position] = new_queue_number;

Trong đó:

patient_position = 4;

Nhưng mảng:

int queue_numbers[4] = {1001, 1002, 1003, 1004};

chỉ có các index hợp lệ:

Vị trí bệnh nhân	Index mảng	Mã số
Bệnh nhân 1	0	1001
Bệnh nhân 2	1	1002
Bệnh nhân 3	2	1003
Bệnh nhân 4	3	1004

Do đó, queue_numbers[4] nằm ngoài phạm vi của mảng.

Đây là lỗi Out-of-bounds access / Buffer Overflow.

Nguyên nhân là chương trình sử dụng patient_position theo cách đánh số từ 1, trong khi C sử dụng index bắt đầu từ 0.

3. Cách khắc phục

Cần chuyển vị trí thực tế của bệnh nhân sang index của mảng:

queue_numbers[patient_position - 1] = new_queue_number;

Với:

patient_position = 4

ta có:

4 - 1 = 3

Do đó chương trình cập nhật:

queue_numbers[3] = 1099;

Đây là đúng vị trí của bệnh nhân thứ 4.

4. Test Cases
Trường hợp kiểm thử	Dữ liệu đầu vào	Kết quả sai thực tế	Kết quả đúng mong đợi
TC01 - Cập nhật bệnh nhân thứ 4	patient_position = 4, new_queue_number = 1099	queue_numbers[4] vượt biên, bệnh nhân 4 vẫn hiển thị 1004	Bệnh nhân 4 hiển thị 1099
TC02 - Kiểm tra các bệnh nhân còn lại	{1001, 1002, 1003, 1004}, cập nhật vị trí 4 thành 1099	Có nguy cơ ghi dữ liệu ra ngoài phạm vi mảng	Bệnh nhân 1 = 1001, bệnh nhân 2 = 1002, bệnh nhân 3 = 1003, bệnh nhân 4 = 1099