/* RV1, LCD 
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

#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
int potentiometerValue = 0;

void setup() {
  // turn on LCD's backlight
  pinMode(17, OUTPUT);
  digitalWrite(17, HIGH);
  
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("A0 input value:");  
} // end of setup function


void loop() {
  // read the potentiomenter value into a variable
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
