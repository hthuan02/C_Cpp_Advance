#include "IoHwAb_InclinationSensor.h"
#include "Adc.h"   // Gọi API từ MCAL để đọc giá trị từ ADC
#include <stdio.h>
#include <stdlib.h>

// Giả lập cấu hình của cảm biến tốc độ
static InclinationSensor_ConfigType InclinationSensor_CurrentConfig;

// Hàm khởi tạo cảm biến tốc độ với cấu hình
Std_ReturnType IoHwAb_InclinationSensor_Init(const InclinationSensor_ConfigType* ConfigPtr) {
    if (ConfigPtr == NULL) {
        printf("Error: Null configuration pointer passed to IoHwAb_InclinationSensor_Init.\n");
        return E_NOT_OK;
    }

    // Lưu cấu hình cảm biến tốc độ vào biến toàn cục
    InclinationSensor_CurrentConfig.InclinationSensor_Channel = ConfigPtr->InclinationSensor_Channel;
    InclinationSensor_CurrentConfig.InclinationSensor_MaxValue = ConfigPtr->InclinationSensor_MaxValue;

    // In ra thông tin cấu hình cảm biến tốc độ
    printf("Inclination Sensor Initialized with Configuration:\n");
    printf(" - ADC Channel: %d\n", InclinationSensor_CurrentConfig.InclinationSensor_Channel);
    printf(" - Max Inclination Value: %d\n", InclinationSensor_CurrentConfig.InclinationSensor_MaxValue);

    return E_OK;
}