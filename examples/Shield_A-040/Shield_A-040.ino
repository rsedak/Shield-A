/* RV1, LCD (I2C) 
 *  Show analogue input value
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

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
int potentiometerValue = 0;

void setup() {
  // initialize the lcd
  lcd.init(); 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  // Print a message to the LCD.
  lcd.print("A0 input value:");  
} // end of setup function


void loop() {
  potentiometerValue = analogRead(A0);
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
