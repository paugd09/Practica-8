#include "lib/include.h"
extern void Configurar_GPIO(void)
{
    SYSCTL->RCGCGPIO |=(1<<3); 
    SYSCTL->PRGPIO |=(1<<3); 
    GPIOD->ADCCTL = (1<<6);
    GPIOD->LOCK= 0x4C4F434B;   // 2) unlock GPIO Port F
    GPIOD->CR = (1<<6);           // allow changes to PF4-0
    GPIOD->AMSEL = 0x00;        // 3) disable analog on PF
    GPIOD->PCTL = 0x00000000;   // 4) PCTL GPIO on PF4-0
    GPIOD->DIR = (0<<6);          // 5) PF4,PF0 in, PF3-1 out
    GPIOD->AFSEL = 0x00;        // 6) disable alt funct on PF7-0
    GPIOD->PUR = (1<<6);          // enable pull-up on PF0 and PF4
    GPIOD->DEN = (1<<6);          // 7) enable digital I/O on PF4-0

    NVIC->IP[0] = (NVIC->IP[0]&0x00FFFFFF) | 0x80000000;;
    NVIC->ISER[0] = (1<<3);

        //configurar evento de interrupcion PORTJ
    GPIOD->IM |= (0<<6); //Limpiar los bits
    GPIOD->IS |= (0<<6);
    GPIOD->IBE |= (0<<6);
    GPIOD->IEV |= (1<<6);
    GPIOD->RIS |= (0<<6);
    GPIOD->IM |= (1<<6);


}

extern void Delay(void)
{
  unsigned long volatile time;
  time = 1600000;
  while(time)
  {
		time--;
  }
}