#include <stdio.h>

#define PAGE_SIZE 4        // ขนาดของเพจ (KB)
#define MEMORY_SIZE 16     // ขนาดหน่วยความจำจริง (KB)
#define NUM_PAGES (MEMORY_SIZE / PAGE_SIZE)  // จำนวนเพจ

int page_table[NUM_PAGES];  // ตารางเพจ

// ฟังก์ชันสำหรับการจำลองการแมปเพจไปยังเฟรม
void map_pages() {
    // ทำการแมปเพจไปยังเฟรมในหน่วยความจำจริง (เฟรมเป็นเพียงการจำลอง)
    for (int i = 0; i < NUM_PAGES; i++) {
        page_table[i] = i;  // ตัวอย่าง: เพจ i ถูกแมปไปยังเฟรม i
    }
}

// ฟังก์ชันแปลงที่อยู่เชิงตรรกะไปเป็นที่อยู่เชิงกายภาพ
void translate_address(int logical_address) {
    int page_number = logical_address / PAGE_SIZE;  // คำนวณเลขเพจจากที่อยู่เชิงตรรกะ
    int offset = logical_address % PAGE_SIZE;       // คำนวณออฟเซ็ตในเพจ

    // ตรวจสอบว่าเลขเพจถูกต้องหรือไม่
    if (page_number >= NUM_PAGES) {
        printf("Invalid logical address!\n");
        return;
    }

    // ดึงหมายเลขเฟรมจากตารางเพจ
    int frame_number = page_table[page_number];

    // คำนวณที่อยู่เชิงกายภาพ
    int physical_address = (frame_number * PAGE_SIZE) + offset;

    printf("Logical Address: %d -> Physical Address: %d\n", logical_address, physical_address);
}

int main() {
    // กำหนดการแมปเพจไปยังเฟรมในหน่วยความจำ
    map_pages();

    // ตัวอย่างการแปลงที่อยู่เชิงตรรกะไปเป็นที่อยู่เชิงกายภาพ
    translate_address(5);   // ที่อยู่เชิงตรรกะ 5
    translate_address(9);   // ที่อยู่เชิงตรรกะ 9
    translate_address(15);  // ที่อยู่เชิงตรรกะ 15
    translate_address(16);  // ที่อยู่เชิงตรรกะที่เกินขอบเขต (ไม่ถูกต้อง)

    return 0;
}
