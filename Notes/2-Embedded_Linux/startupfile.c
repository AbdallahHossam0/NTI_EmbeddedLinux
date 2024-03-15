typedef unsigned long uint32_t;
typedef void (*PF_Handler)(void);

extern uint32_t _e_stack;
extern uint32_t _s_data_FLASH;
extern uint32_t _s_data;
extern uint32_t _e_data;
extern uint32_t _s_bss;
extern uint32_t _e_bss;

extern int main(void);

void __attribute__((weak)) defaultHandler(void);
void __attribute__((weak)) ResetHandler(void);

void __attribute__((weak, alias("defaultHandler"))) NMI_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) HardFault_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) MemManage_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) BusFault_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) UsageFault_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) SVCall_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) Debug_Monitor_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) PendSV_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) SysTick_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) WWDG_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) PVD_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) TAMPER_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) RTC_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) FLASH_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) RCC_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) EXTI0_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) EXTI1_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) EXTI2_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) EXTI3_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) EXTI4_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) DMA1_Channel1_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) DMA1_Channel2_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) DMA1_Channel3_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) DMA1_Channel4_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) DMA1_Channel5_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) DMA1_Channel6_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) DMA1_Channel7_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) ADC1_2_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) USB_HP_CAN1_TX_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) USB_LP_CAN1_RX0_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) CAN1_RX1_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) CAN1_SCE_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) EXTI9_5_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) TIM1_BRK_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) TIM1_UP_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) TIM1_TRG_COM_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) TIM1_CC_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) TIM2_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) TIM3_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) TIM4_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) I2C1_EV_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) I2C1_ER_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) I2C2_EV_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) I2C2_ER_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) SPI1_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) SPI2_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) USART1_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) USART2_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) USART3_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) EXTI15_10_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) RTCAlarm_Handler(void);
void __attribute__((weak, alias("defaultHandler"))) USBWakeUp_Handler(void);



__attribute__((section(".isr_vector"), used))
PF_Handler const vector_table[] = {
    (PF_Handler) &_e_stack,     /* stack pointer init value */
    ResetHandler,               /* Reset Handler */
    NMI_Handler,                /* NMI Handler */    
    HardFault_Handler,          /* Hard Fault Handler */
    MemManage_Handler,          /* MPU Fault Handler */
    BusFault_Handler,           /* Bus Fault Handler */
    UsageFault_Handler,         /* Usage Fault Handler */
    0, 0, 0, 0,                 /* Reserved */
    SVCall_Handler,             /* SVCall Handler */
    Debug_Monitor_Handler,      /* Debug Monitor Handler */
    0,                          /* Reserved */
    PendSV_Handler,             /* PendSV Handler */
    SysTick_Handler,            /* SysTick Handler */
    WWDG_Handler,               /* 0: Window Watchdog */
    PVD_Handler,                /* 1: PVD through EXTI Line detect */
    TAMPER_Handler,             /* 2: Tamper */
    RTC_Handler,                /* 3: RTC */
    FLASH_Handler,              /* 4: Flash */
    RCC_Handler,                /* 5: RCC */
    EXTI0_Handler,              /* 6: EXTI Line 0 */
    EXTI1_Handler,              /* 7: EXTI Line 1 */
    EXTI2_Handler,              /* 8: EXTI Line 2 */
    EXTI3_Handler,              /* 9: EXTI Line 3 */
    EXTI4_Handler,              /* 10: EXTI Line 4 */
    DMA1_Channel1_Handler,      /* 11: DMA1 Channel 1 */
    DMA1_Channel2_Handler,      /* 12: DMA1 Channel 2 */
    DMA1_Channel3_Handler,      /* 13: DMA1 Channel 3 */
    DMA1_Channel4_Handler,      /* 14: DMA1 Channel 4 */
    DMA1_Channel5_Handler,      /* 15: DMA1 Channel 5 */
    DMA1_Channel6_Handler,      /* 16: DMA1 Channel 6 */
    DMA1_Channel7_Handler,      /* 17: DMA1 Channel 7 */
    ADC1_2_Handler,             /* 18: ADC1 & ADC2 */
    USB_HP_CAN1_TX_Handler,      /* 19: USB High Priority or CAN1 TX */
    USB_LP_CAN1_RX0_Handler,     /* 20: USB Low  Priority or CAN1 RX0 */
    CAN1_RX1_Handler,           /* 21: CAN1 RX1 */
    CAN1_SCE_Handler,           /* 22: CAN1 SCE */
    EXTI9_5_Handler,            /* 23: EXTI Line 9..5 */
    TIM1_BRK_Handler,           /* 24: TIM1 Break */
    TIM1_UP_Handler,            /* 25: TIM1 Update */
    TIM1_TRG_COM_Handler,       /* 26: TIM1 Trigger and Commutation */
    TIM1_CC_Handler,            /* 27: TIM1 Capture Compare */
    TIM2_Handler,               /* 28: TIM2 */
    TIM3_Handler,               /* 29: TIM3 */
    TIM4_Handler,               /* 30: TIM4 */
    I2C1_EV_Handler,            /* 31: I2C1 Event */
    I2C1_ER_Handler,            /* 32: I2C1 Error */
    I2C2_EV_Handler,            /* 33: I2C2 Event */
    I2C2_ER_Handler,            /* 34: I2C2 Error */
    SPI1_Handler,               /* 35: SPI1 */
    SPI2_Handler,               /* 36: SPI2 */
    USART1_Handler,             /* 37: USART1 */
    USART2_Handler,             /* 38: USART2 */
    USART3_Handler,             /* 39: USART3 */
    EXTI15_10_Handler,          /* 40: EXTI Line 15..10 */
    RTCAlarm_Handler,           /* 41: RTC Alarm through EXTI Line */
    USBWakeUp_Handler,          /* 42: USB Wakeup from suspend */
};


void __attribute__((section(".text"))) ResetHandler(void){
    uint32_t *memSrcAddr = (uint32_t*) &_s_data_FLASH;
    uint32_t *memDstAddr = (uint32_t*) &_s_data;

    uint32_t sectionSize = &_e_data - &_s_data;

    for (int i = 0; i < sectionSize; ++i) {
        *memDstAddr++ = *memSrcAddr++;
    }

    memDstAddr = (uint32_t*) &_s_bss;
    sectionSize = &_e_bss -  &_s_bss;

    for (int i = 0; i < sectionSize; ++i) {
        *memDstAddr++ = 0;
    }

    main();  
    for(;;);
}

void __attribute__((section(".text"))) defaultHandler(void) {
    for (;;) {
    }
}