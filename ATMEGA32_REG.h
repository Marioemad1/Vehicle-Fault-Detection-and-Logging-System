/****************************************************************************************************************************************
*****************************************************************************************************************************************
**************************************************    Date     :   8/23/2025			*************************************************
**************************************************    Name     :   Mario Emad Boles 	*************************************************
**************************************************    Version     :   1.0            	*************************************************
**************************************************    SWC     :   ATMEGA32_REG          *************************************************
*****************************************************************************************************************************************
*****************************************************************************************************************************************
*/


#ifndef ATMEGA32_REG_H_
#define ATMEGA32_REG_H_
					
					/*DIO_REGS*/
/* DIRECT MEM*/
#define DDRA (*(volatile u8*)0x3A)
#define DDRB (*(volatile u8*)0x37)
#define DDRC (*(volatile u8*)0x34)
#define DDRD (*(volatile u8*)0x31)

/*OUTPUT MEM*/
#define PORTA (*(volatile u8*)0x3B)
#define PORTB (*(volatile u8*)0x38)
#define PORTC (*(volatile u8*)0x35)
#define PORTD (*(volatile u8*)0x32)

/*INPUT MEM*/
#define PINA (*(volatile u8*)0x39)
#define PINB (*(volatile u8*)0x36)
#define PINC (*(volatile u8*)0x33)
#define PIND (*(volatile u8*)0x30)


		/*EXTIRANL INTERRPTURES*/

/*STATUS REG*/
#define SREG   (*(volatile u8*)0x5F)

/*GENERAL INTERRPTURE CONTROL REG*/
#define GICR   (*(volatile u8*)0x5B)

/*GENERAL INTERRPTURE FLAG REG*/
#define GIFR   (*(volatile u8*)0x5A)

/*MCU CONTROL REGESTER*/
#define MCUCR  (*(volatile u8*)0x55)

/*MCU CONTROL AND STATUS REG*/
#define MCUCSR (*(volatile u8*)0x54)


			/*ADC_REGS*/
			
//ADC Multiplexer Selection Register

#define ADMUX   (*(volatile u8*)0x27)

// ADC Control and Status Register A 
#define ADCSRA  (*(volatile u8*)0x26)

// The ADC Data Register – ADCL and ADCH 
#define ADCH    (*(volatile u8*)0x25)
#define ADCL    (*(volatile u8*)0x24)

//this is a to access the full 10 bits in the two registers 
#define ADC_u16 (*(volatile u16*)0x24)

// Special FunctionIO Register – SFIOR
#define SFIOR   (*(volatile u16*)0x50)


			/*TIMER_REGS*/


/*TIMER_0 REGS */

//Timer/Counter Control Register – TCCR0
#define TCCR0 (*(volatile u8*)0x53)

//Timer/Counter Register – TCNT0
#define TCNT0 (*(volatile u8*)0x52)

//Output Compare Register – OCR0
#define OCR0  (*(volatile u8*)0x5C)

//Timer/Counter Interrupt Mask Register – TIMSK
#define TIMSK (*(volatile u8*)0x59)

// Timer/Counter Interrupt Flag Register – TIFR
#define TIFR  (*(volatile u8*)0x58)


/*TIMER_1_REGS*/

// Timer/Counter1 Control Register A 

#define TCCR1A  (*(volatile u8*)0x4F)

//Timer/Counter1 Control Register B  
#define TCCR1B  (*(volatile u8*)0x4E)

// Timer/Counter1 – TCNT1H and TCNT1L
#define TCNT1H    (*(volatile u8*)0x4D)
#define TCNT1L    (*(volatile u8*)0x4C)
#define TCNT1_u16 (*(volatile u16*)0x4C)

// Output Compare Register 1 A – OCR1AH and OCR1AL
#define OCR1AH    (*(volatile u8*)0x4B)
#define OCR1AL    (*(volatile u8*)0x4A)
#define OCR1A_u16 (*(volatile u16*)0x4A)

// Output Compare Register 1 B – OCR1BH and OCR1BL
#define OCR1BH    (*(volatile u8*)0x49)
#define OCR1BL    (*(volatile u8*)0x48)
#define OCR1B_u16 (*(volatile u16*)0x48)

//Input Capture Register 1 – ICR1H and ICR1L
#define ICR1H    (*(volatile u8*)0x47)
#define ICR1L    (*(volatile u8*)0x46)
#define ICR1_u16 (*(volatile u16*)0x46)


/*WDT REGS*/
// Watchdog Timer Control Register
#define WDTCR    (*(volatile u8*)0x41)


			/*UART_REGS*/

// USART I/O Data 
#define  UDR   (*(volatile u8*)0x2C)

// USART Control and Status Register A – 
#define  UCSRA   (*(volatile u8*)0x2B)

// USART Control and Status Register B – 
#define UCSRB     (*(volatile u8*)0x2A)

//USART Control and Status Register C – 
#define UCSRC    (*(volatile u8*)0x40)

// USART Baud Rate Registers – UBRRL and UBRRH
#define UBRRL    (*(volatile u8*)0x29)
#define UBRRH    (*(volatile u8*)0x40)


			/*SPI_REGS*/
//SPI Control Register 
#define SPCR  (*(volatile u8*)0x2D)

// SPI Status Register  
#define SPSR  (*(volatile u8*)0x2E)

// SPI Data Register 
#define SPDR  (*(volatile u8*)0x2F)




			/*TWI_REGS*/
//TWI Bit Rate Register – 
#define TWBR  (*(volatile u8*)0x20)

// TWI Control Register – 
#define TWCR  (*(volatile u8*)0x56)

//TWI Status Register – 
#define TWSR  (*(volatile u8*)0x21)

//TWI Data Register – 
#define TWDR  (*(volatile u8*)0x23)

//TWI (Slave) Address Register – 
#define TWAR  (*(volatile u8*)0x22)

#endif /* ATMEGA32_REG_H_ */