#include "IoHwAb_LoadAccess.h"
#include "Adc.h"   // Gọi API từ MCAL để đọc giá trị từ ADC
#include <stdio.h>
#include <stdlib.h>

// Giả lập cấu hình của cảm biến tải trọng
static LoadAccess_ConfigType LoadAccess_CurrentConfig;

// Hàm khởi tạo cảm biến tải trọng 
Std_ReturnType IoHwAb_LoadAccess_Init(const LoadAccess_ConfigType* ConfigPtr) {
    if (ConfigPtr == NULL) {
        printf("Error: Null configuration pointer passed to IoHwAb_LoadAccess_Init.\n");
        return E_NOT_OK;
    }

    // Lưu cấu hình cảm biến tải trọng vào biến toàn cục
    LoadAccess_CurrentConfig.LoadAccess_Channel = ConfigPtr->LoadAccess_Channel;
    LoadAccess_CurrentConfig.LoadAccess_MaxValue = ConfigPtr->LoadAccess_MaxValue;

    // In ra thông tin cấu hình cảm biến tải trọng
    printf("Speed Sensor Initialized with Configuration:\n");
    printf(" - ADC Channel: %d\n", LoadAccess_CurrentConfig.LoadAccess_Channel);
    printf(" - Max Speed Value: %d km/h\n", LoadAccess_CurrentConfig.LoadAccess_MaxValue);

    return E_OK;
}

// Hàm đọc giá trị cảm biến tải trọng
Std_ReturnType IoHwAb_LoadAccess_Read(float* LoadAccessValue) {
    if (LoadAccessValue == NULL) {
        return E_NOT_OK;
    }

    // Đọc giá trị từ kênh ADC
    uint16_t adcLoadValue = 0;
    if (Adc_ReadChannel(LoadAccess_CurrentConfig.LoadAccess_Channel, &adcLoadValue) != E_OK) {
        printf("Error: Failed to read ADC value.\n");
        return E_NOT_OK;
    }

    // Chuyển đổi giá trị ADC sang tải trọng (giả lập)
    *LoadAccessValue = ((float)adcLoadValue / 1023.0f) * LoadAccess_CurrentConfig.LoadAccess_MaxValue;

    // In ra tải trọng hiện tại
    printf("Reading Load Access(ADC Channel: %d) Load = %.2f kg\n",
            LoadAccess_CurrentConfig.LoadAccess_Channel, *LoadAccessValue);
   
    return E_OK;
}