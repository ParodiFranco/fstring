/* License ********************************************************************/
/*******************************************************************************
MIT License

Copyright (c) 2025 Parodi, Franco

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*******************************************************************************/

/* Configuration Fuses ********************************************************/
/******************************************************************************/
// CONFIG1
#pragma config FEXTOSC = HS		// External Oscillator mode selection bits (EC above 8MHz; PFM set to high power)
#pragma config RSTOSC = EXT4X	// Power-up default value for COSC bits (HFINTOSC with OSCFRQ= 32 MHz and CDIV = 1:1)
#pragma config CLKOUTEN = OFF	// Clock Out Enable bit (CLKOUT function is disabled; i/o or oscillator function on OSC2)
#pragma config CSWEN = ON		// Clock Switch Enable bit (The NOSC and NDIV bits cannot be changed by user software)
#pragma config FCMEN = OFF		// Fail-Safe Clock Monitor Enable bit (FSCM timer enabled)

// CONFIG2
#pragma config MCLRE = ON		// Master Clear Enable bit (MCLR pin function is port defined function)
#pragma config PWRTE = OFF		// Power-up Timer Enable bit (PWRT disabled)
#pragma config LPBOREN = OFF	// Low-Power BOR enable bit (ULPBOR disabled)
#pragma config BOREN = ON       // Brown-out reset enable bits (Brown-out Reset Enabled, SBOREN bit is ignored)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (VBOR) set to 1.9V on LF, and 2.45V on F Devices)
#pragma config ZCD = OFF        // Zero-cross detect disable (Zero-cross detect circuit is disabled at POR.)
#pragma config PPS1WAY = ON     // Peripheral Pin Select one-way control (The PPSLOCK bit can be cleared and set only once in software)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable bit (Stack Overflow or Underflow will cause a reset)

// CONFIG3
#pragma config WDTCPS = WDTCPS_31	// WDT Period Select bits (Divider ratio 1:65536; software control of WDTPS)
#pragma config WDTE = OFF			// WDT operating mode (WDT enabled regardless of sleep; SWDTEN ignored)
#pragma config WDTCWS = WDTCWS_7	// WDT Window Select bits (window always open (100%); software control; keyed access not required)
#pragma config WDTCCS = SC			// WDT input clock selector (Software Control)

// CONFIG4
#pragma config WRT = OFF			// UserNVM self-write protection bits (Write protection off)
#pragma config SCANE = available	// Scanner Enable bit (Scanner module is available for use)
#pragma config LVP = ON				// Low Voltage Programming Enable bit (High Voltage on MCLR/Vpp must be used for programming)

// CONFIG5
#pragma config CP = OFF		// UserNVM Program memory code protection bit (Program Memory code protection disabled)
#pragma config CPD = OFF	// DataNVM code protection bit (Data EEPROM code protection disabled)

/* Includes *******************************************************************/
#include <xc.h>

/* Private Function Declaration ***********************************************/
static void UART_Init(void);

/* ET CallBack Function Definitions *******************************************/
void ET_onInit(int argc, char *argv[]) {
	(void)argc;
    (void)argv;
	/* Configure pins for USART Peripheral */
	char const PPS_INPUT_RB0 = 0x08; /* RB0 value for xxxPPS Register (0x08)*/
	char const PPS_OUTPUT_TX = 0x10; /* TX RxyPPS Register Value (0x10) */
	RXPPS = PPS_INPUT_RB0; /* RB0 Input -> RX */
	RB1PPS = PPS_OUTPUT_TX; /* RB1 Output -> TX */
	ANSB0 = 0;
	RB0 = 1;
	RB1 = 0;
	
    UART_Init();
}

void ET_onPrintChar(char const ch) {
    /* busy-wait as long as UART busy */
    while(0 == PIR3bits.TXIF);
    TXREG = ch;
}

void ET_onExit(int err) {
    (void)err;
    while(1);
}

/* Private Function Definitions ***********************************************/
static void UART_Init(void){
	/* Baud Rate = Fosc/(64([SPBRGH:SPBRGL] + 1)) = 32Mhz/64(51+1) = 9615 bps */
	/* [SPBRGH:SPBRGL] = Fosc/Baud Rate/64 - 1 */
	SPBRG = 51; /* Set Baud Rate */

	TX1STAbits.SYNC = 0; /* Configure for Async transmission */
	RC1STAbits.CREN = 1; /* Enable recieving */
	TX1STAbits.TXEN = 1; /* Enable transmission */
	RC1STAbits.SPEN = 1; /* Enable Serial Port */
}