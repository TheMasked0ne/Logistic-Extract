/* --- ARCHITECTURE DEFINITIONS ---

 * These profiles represent the "Knowledge Base" for the analyzer.
 
 * Addresses are sourced from official Silicon Vendor Datasheets.
 
 */

const ArchProfile ARM_M = {
    "ARM_CORTEX_M",
    {
        // 0x40012400 is the standard base for ADC1 on many STM32 variants
        {0x40012400, {"ADC1", "Sensor Reading", "uint32_t val = HAL_ADC_GetValue(&hadc1);"}},

        {0x40010800, {"GPIOA", "Digital I/O", "HAL_GPIO_WritePin(GPIOA, PIN_5, SET);"}}
    }
};

const ArchProfile ESP32 = {
    "ESP32_XTENSA",
    {
        // ESP32 uses a specific MMIO range starting at 0x3FF00000
        {0x3FF44000, {"GPIO", "Matrix Control", "gpio_set_level(GPIO_NUM_4, 1);"}},

        {0x3FF01000, {"AES_ACCEL", "Cryptography", "// ALERT: AES Hardware detected."}}
    }
};
