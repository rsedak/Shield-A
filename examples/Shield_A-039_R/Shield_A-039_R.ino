/* RV1, LCD 
 *  Show analogue input value
 * with register manipulation  
 *  
 * Arduino Digital Pin | Register Pin Mark
 * ----------------------------------------
 *                   0 | PD0 
 *                   1 | PD1 
 *                   2 | PD2 
 *                   3 | PD3
 *                   4 | PD4
 *                   5 | PD5
 *                   6 | PD6
 *                   7 | PD7
 *                   8 | PB0
 *                   9 | PB1
 *                  10 | PB2
 *                  11 | PB3
 *                  12 | PB4
 *                  13 | PB5 
 *                  A0 | PC0
 *                  A1 | PC1
 *                  A2 | PC2
 *                  A3 | PC3
 *                  A4 | PC4
 *                  A5 | PC5
 *                  A6 | PC6
 *  
 *  Created 2019 by Robert Sedak
 *  
 *  This example code is in the public domain.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES 
 *  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHOR(S) OR 
 *  CONTRIBUTOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, 
 *  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR 
 *  THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
int potentiometerValue = 0;

void setup() {
  // turn on LCD's backlight
  DDRC |= (1 << PC3); 
  PORTC |= (1 << PC3);

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("A0 input value:");  

  // Prepare ADC Multiplexer Selection Register and ADC converter
  // to read potentiometer value

  // turn ADC on
  ADCSRA = (1 << ADEN);   
  
  // Prescaler of 128
  ADCSRA |= (1 << ADPS0) |  (1 << ADPS1) | (1 << ADPS2);  
  
  // enable AVcc with external capacitor at AREF pin
  // and connect analog input pin A0 to the ADC
  ADMUX = (1 << REFS0) | ( 0 & 0x07);  
  
  // let it stabilize
  delay (20);    
} // end of setup function


void loop() {
  // read the potentiomenter value into a local variable

  // start a conversion 
  ADCSRA |= (1 << ADSC);
  
  // conversion is over when ADSC bit turns to 0,
  // so wait while ADSC bit is 1
  while (((ADCSRA & (1 << ADSC)) >> ADSC));

  // store converted vaule to variable
  potentiometerValue = ADC;  
  
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(potentiometerValue);
  
  if (potentiometerValue < 1000 ) { lcd.print(" "); };
  if (potentiometerValue < 100 ) { lcd.print("  "); };
  if (potentiometerValue < 10 ) { lcd.print("   "); };

  delay(100);
} // end of loop function
