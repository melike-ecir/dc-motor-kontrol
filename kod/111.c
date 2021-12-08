#include <111.h>
#define LCD_ENABLE_PIN PIN_D0
#define LCD_RS_PIN PIN_D1
#define LCD_RW_PIN PIN_D2
#define LCD_DATA4 PIN_D4
#define LCD_DATA5 PIN_D5
#define LCD_DATA6 PIN_D6
#define LCD_DATA7 PIN_D7

#include <lcd.c>

#use delay(clock = 20000000)
#use fast_io(B)
#use fast_io(C)

unsigned int digital ;

void main(){
  
  output_b(0);                           
  set_tris_b(7);                         
  output_c(0);                         
  set_tris_c(0);                         
  output_d(0);                           
  set_tris_d(0);                         
  setup_adc(ADC_CLOCK_DIV_16);           
  setup_adc_ports(AN0);                  
  set_adc_channel(0);                    
  setup_timer_2(T2_DIV_BY_16, 255, 1);   
  delay_ms(100);      
 lcd_init();
     output_high(pin_b7);
  
  while(TRUE){
  
  
    printf(lcd_putc,"\fDC MOTOR KONROLU");
    
    digital = read_adc();                      
    if(input(PIN_B3) == 1)               
      set_pwm1_duty(digital);                 
     
    if(input(PIN_B4) == 1)               
      set_pwm2_duty(digital);                  
         
   
    delay_ms(10);                        
    if(input(PIN_B0) == 0){              
      if(input(PIN_B3) == 0){            
        output_b(0);                     
        setup_ccp1(CCP_OFF);            
        setup_ccp2(CCP_OFF);             
        output_c(0);                     
        delay_ms(100);                   
        setup_ccp1(CCP_PWM);             
        output_high(PIN_B3);             
        
      
        }}
    if(input(PIN_B1) == 0){              
      if(input(PIN_B4) == 0){            
        output_b(0);                    
        setup_ccp1(CCP_OFF);            
        setup_ccp2(CCP_OFF);             
        output_c(0);                     
        delay_ms(100);                  
        setup_ccp2(CCP_PWM);            
        output_high(PIN_B4);             
        }}
    if(input(PIN_B2) == 0){              
      setup_ccp1(CCP_OFF);               
      setup_ccp2(CCP_OFF);               
      output_c(0);                       
      output_b(0);}                      
      printf(lcd_putc,"\ndigital=%u"digital);
      delay_ms(50);
   }
}
