/*
 * Final Project1.c
 *
 * Created: 4/8/2022 6:35:43 PM
 * Author : mmassucci
 */


#include "F_cpu_lib.h"  // always put this first!!!!!!!!
#include <avr/io.h>
#include <util/delay.h>
#include "LCD_lib.h"
#include "Serial_lib2.h"

void ClearScreen();

int main(void)
{		
		int x = 1;
		HBridgeInit();
		uint8_t CharData; // character received from PC via serial port
		char mystring[20];
		uint8_t NewString = 0;  // starting a new input string
		int StringValue = 0;  // accumulated numeric value for string received from PC
		uint8_t StrCount = 0;
		int tmpnum= 0;
		uint8_t LCDRow;
		uint8_t LCDCol;
		uint8_t num_char;
		DDRC |= 1 << PORTC2; // set DDRC for Pin2 to 1 – output – do not modify other pins (ERE controller board)
		char number_out[8];
		LCD_init();
		USART_vInit();
		sei(); // enable interrupts
		LCDCol = 1;
		LCDRow = 1;
		LCDGoToPosition(LCDCol,LCDRow);
		LCDSendString("Starting Code");
		_delay_ms(2000);
		//ClearScreen();
		// Replace with your application code
		
		
		while(x == 1)
		{
			
			CharData =USART_vReceiveByte();
		
				
				
				if(CharData == 'a')//stop
				{
					HBridgeCommand(0, 0, 1);
					HBridgeCommand(1, 0, 1);
					LCDGoToPosition(1,3);
					LCDSendCharacter(CharData);	
					x = 0;
				}
				else if(CharData == 'b')//straight
				{
					HBridgeCommand(0, 50, 1);
					HBridgeCommand(1, 59, 1);
					LCDGoToPosition(1,3);
					LCDSendCharacter(CharData);
				}
				else if(CharData == 'c')//hard right
				{
					HBridgeCommand(0, 50, 1);
					HBridgeCommand(1, 0, 1);
					LCDGoToPosition(1,3);
					LCDSendCharacter(CharData);
				}
				else if(CharData == 'd')//hard left
				{
					HBridgeCommand(0, 0, 1);
					HBridgeCommand(1, 50, 1);
					LCDGoToPosition(1,3);
					LCDSendCharacter(CharData);
				}
				else if(CharData == 'e')//slight right
				{
					HBridgeCommand(0, 50, 1);
					HBridgeCommand(1, 25, 1);
					LCDGoToPosition(1,3);
					LCDSendCharacter(CharData);
				}
				else if(CharData == 'f')//slight left
				{
					HBridgeCommand(0, 25, 1);
					HBridgeCommand(1, 50, 1);
					LCDGoToPosition(1,3);
					LCDSendCharacter(CharData);
				}
					
					
					

			}
			

			// _delay_ms(2000);

			//HBridgeCommand(0, 50, 0);
			//HBridgeCommand(1, 50, 0);
		
		
		
		

}


 
/*
#include "F_cpu_lib.h"
#include <avr/io.h>
#include <util/delay.h>
#include "LCD_lib.h"
#include "Serial_lib2.h"
#include "Motor_PWM_lib.h"
	
int main(void)
{
	HBridgeInit();
	uint8_t CharData;
	char mystring[20];
	uint8_t NewString = 0;
	int StringValue = 0;
	uint8_t StrCount = 0;
	int tmpnum = 0;
	uint8_t LCDRow;
	uint8_t LCDCol;
	uint8_t num_char;
	DDRC |= 1 << PORTC2;
	char number_out[8];
	LCD_init();
	USART_vInit();
	sei();
	LCDCol = 1;
	LCDRow = 1;
	LCDGoToPosition(LCDCol, LCDRow);
	//LCDClearScreen();
	LCDSendString("trial 10");
	
     Replace with your application code 
    while (1) 
    {
		//HBridgeCommand(0, 10, 0);
		//HBridgeCommand(1, 75, 1);	
		//HBridgeCommand(0, 50, 0);
		//HBridgeCommand(1, 50, 0);
		
    }
}
*/


void ClearScreen()
{
	LCDGoToPosition(1,1);
	LCDSendString("                    ");
	LCDGoToPosition(1,2);
	LCDSendString("                    ");
	LCDGoToPosition(1,3);
	LCDSendString("                    ");
	LCDGoToPosition(1,4);
	LCDSendString("                    ");
	
}