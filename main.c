/* p2_1.c Toggling green LED in C using header file register definitions.
 * This program toggles green LED for 0.5 second ON and 0.5 second OFF.
 * The green LED is connected to P2.1.
 * The LEDs are high active (a '1' turns ON the LED).
 *
 */

#include "msp.h"

#define DELAY 20           // busy loop delay of 20ms
#define DELAY2 DELAY*3000u // DELAY * 1 mS assuming 3 MHz clock

void delayMs(int n);

int main(void) {

    uint32_t counter = 0;
    P2->SEL1 &= ~BIT1;         /* configure P2.1 as simple I/O */
    P2->SEL0 &= ~BIT1;
    P2->DIR |= BIT1;           /* P2.1 set as output pin */

    while (1) {
        P2->OUT |= BIT1;       /* turn on P2.1 green LED */
        __delay_cycles(DELAY2);
        P2->OUT &= BIT1;      /* turn off P2.1 green LED */
        __delay_cycles(DELAY2);
        counter++;
    }
}
