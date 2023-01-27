#ifndef LIB_OLED_H_
#define LIB_OLED_H_
// Function declarations 
extern void OLED_Command(uint8_t temp);
extern void OLED_Data(uint8_t  temp);
extern void OLED_Init();
extern void OLED_YX(unsigned char Row, unsigned char Column); // *warning!* max 4 rows
extern void OLED_PutChar( char ch );
extern void OLED_Clear(); 
extern void OLED_Write_String( char *s );
extern void OLED_Write_Integer(uint8_t  i);
extern void Delay_ms(int time_ms);
#endif 