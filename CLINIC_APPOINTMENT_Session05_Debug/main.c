#include <stdio.h>

int main() {
    // Khoi tao danh sach 4 ma so thu tu kham
    int queue_numbers[4] = {1001, 1002, 1003, 1004};

    // Benh nhan o vi tri thu 4
    int patient_position = 4;
    int new_queue_number = 1099;

    queue_numbers[patient_position - 1] = new_queue_number;

    // In ra danh sach 4 benh nhan
    printf("--- DANH SACH SO THU TU KHAM BENH ---\n");
    printf("Benh nhan 1 (Index 0): %d\n", queue_numbers[0]);
    printf("Benh nhan 2 (Index 1): %d\n", queue_numbers[1]);
    printf("Benh nhan 3 (Index 2): %d\n", queue_numbers[2]);
    printf("Benh nhan 4 (Index 3): %d\n", queue_numbers[3]);

    return 0;
}