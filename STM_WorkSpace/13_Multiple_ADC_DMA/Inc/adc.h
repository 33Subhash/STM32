
#ifdef ADC_H_
#define ADC_H_


uint32_t pc0_adc_read(void);
void adc_init_start(void);
void adc_pc0_interrupt_init(void);
void adc_pa0_DMA_init(void);
void adc_multiple_DMA_init(void);

#endif
