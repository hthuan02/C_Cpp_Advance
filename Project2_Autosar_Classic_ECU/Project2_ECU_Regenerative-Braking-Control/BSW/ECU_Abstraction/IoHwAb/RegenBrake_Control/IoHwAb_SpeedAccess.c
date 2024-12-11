#include "IoHwAb_SpeedAccess.h"
#include "Adc.h"   // Gọi API từ MCAL để đọc giá trị từ ADC
#include "Dio.h"
#include <stdio.h>
#include <stdlib.h>

// Giả lập cấu hình của cảm biến tốc độ
static SpeedAccess_ConfigType SpeedAccess_CurrentConfig;

// Hàm khởi tạo cảm biến tốc độ với cấu hình
Std_ReturnType IoHwAb_SpeedAccess_Init(const SpeedAccess_ConfigType* ConfigPtr) {
    if (ConfigPtr == NULL) {
        printf("Error: Null configuration pointer passed to IoHwAb_SpeedAccess_Init.\n");
        return E_NOT_OK;
    }

    // Lưu cấu hình cảm biến tốc độ vào biến toàn cục
    SpeedAccess_CurrentConfig.SpeedAccess_Channel = ConfigPtr->SpeedAccess_Channel;
    SpeedAccess_CurrentConfig.SpeedAccess_MaxValue = ConfigPtr->SpeedAccess_MaxValue;

    // In ra thông tin cấu hình cảm biến tốc độ
    printf("Speed Sensor Initialized with Configuration:\n");
    printf(" - ADC Channel: %d\n", SpeedAccess_CurrentConfig.SpeedAccess_Channel);
    printf(" - Max Speed Value: %d km/h\n", SpeedAccess_CurrentConfig.SpeedAccess_MaxValue);

    return E_OK;
}

// Hàm đọc giá trị từ cảm biến tốc độ
Std_ReturnType IoHwAb_SpeedAccess_Read(float *SpeedAccessValue) {
    if (SpeedAccessValue == NULL) {
        return E_NOT_OK; // Kiểm tra con trỏ NULL
    }

    // Đọc giá trị từ kênh ADC
    uint16_t speed_adc_value =0;
    if (Adc_ReadChannel(SpeedAccess_CurrentConfig.SpeedAccess_Channel, &speed_adc_value) != E_OK) {
        printf("Error: Failed to read ADC value.\n");
        return E_NOT_OK;
    }
    
    // Chuyển đổi giá trị ADC sang tốc độ (giả lập)
    *SpeedAccessValue = ((float)speed_adc_value / 1023.0f) * SpeedAccess_CurrentConfig.SpeedAccess_MaxValue;

    // In ra tốc độ hiện tại
    printf("Reading Speed Access(ADC Channel: %d) Speed = %.2f km/h\n",
            SpeedAccess_CurrentConfig.SpeedAccess_Channel, *SpeedAccessValue);

    return E_OK;

}