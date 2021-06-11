#include <math.h>
#include "libs/analog.h"
#include "libs/LCD.h"

int main(void) {
    //LCD lcd(1, 0, 2, 3, 4,5);
    LCD lcd(2, 3, 4, 5, 6, 7);
    const uint16_t B = 3.9E3;   // El beta de la formula, en grados Kelvin
    const uint16_t T0 = 298;    // T0 que es 25 Â°C pero lo ponemos en Kelvin
    const uint16_t R = 10E3;    // R(T0)
    const uint8_t vcc= 5;
    const uint16_t r= 10000;

    while(1) {

        uint16_t val = analogRead(0);			   
        float vntc = (float)val * vcc / 1023;
        float  rntc = r*vntc/(vcc-vntc); 
        float temp  = (uint32_t)T0*B/(T0*log(rntc/R)+B);
        temp = temp-273;
        lcd.clear();
        lcd.print("t ");
        lcd.print(temp);
        lcd.setXY(2, 1);  
        lcd.print("r ");
        lcd.print(rntc);
       
       
        
    }

    return 0;
}
