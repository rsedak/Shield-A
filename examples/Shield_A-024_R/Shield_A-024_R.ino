/* RGB matrix 
 * multiplexing four RGB LED
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
 * 
 * Created 2019 by Robert Sedak
 * 
 * This example code is in the public domain.
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

byte D8;
byte D9;
byte D10;
byte D11;
int RGBDelay = 2;  // delay 2ms
unsigned long lastTime = 0;
int randomNumber = 0;

void setup() {

  // Set D5-D7 as output pins 
  DDRD |= ((1 << PD5) | (1 << PD6) | (1 << PD7));

  // Set D8-D11 as output pins 
  DDRB |= ((1 << PB0) | (1 << PB1) | (1 << PB2) | (1 << PB3));
  
  // Turn OFF RED, Blue and Green LED
  PORTD &= ~((1 << PD5) | (1 << PD6) | (1 << PD7));

  // Turn OFF D8, D9, D10 and D11 RGB LED - pins are in HIGH state
  PORTB |= ((1 << PB0) | (1 << PB1) | (1 << PB2) | (1 << PB3));

  // Seed ranodom generator
  randomSeed(analogRead(A6));
} // end of setup function

void loop() {

  // define new random colors for RGB LEDs every second
  // no LED can not have same color
  if ((millis() - lastTime) > 1000) {
    D8 = random(1,8);
    randomNumber = random(1,8);
    while ( D8 == randomNumber ) {
      randomNumber = random(1,8);
    }
    D9 = randomNumber;

    while (    D8 == randomNumber 
            || D9 == randomNumber ) {
      randomNumber = random(1,8);
    }    
    D10 = randomNumber;
    while (    D8 == randomNumber 
            || D9 == randomNumber 
            || D10 == randomNumber) {
      randomNumber = random(1,8);
    }
    D11 = randomNumber;
    lastTime = millis();
  }
  
  PORTB &= ~(1 << PB0);   // Turn ON RGB LED D8
  PORTB |= (1 << PB3);    // Turn OFF RGB LED D11
  PORTD = (D8 << 5);      // Set color defined in variable D8
  
  delay(RGBDelay);

  PORTB |= (1 << PB0);    // Turn OFF RGB LED D8
  PORTB &= ~(1 << PB1);   // Turn ON RGB LED D9
  PORTD = (D9 << 5);      // Set color defined in variable D9
  
  delay(RGBDelay);

  PORTB |= (1 << PB1);   // Turn OFF RGB LED D9
  PORTB &= ~(1 << PB2);  // Turn ON RGB LED D10
  PORTD = (D10 << 5);    // Set color defined in variable D10
  
  delay(RGBDelay);

  PORTB |= (1 << PB2);   // Turn OFF RGB LED D10
  PORTB &= ~(1 << PB3);  // Turn ON RGB LED D11 
  PORTD = (D11 << 5);    // Set color defined in variable D11
  
  delay(RGBDelay);
} // end of loop function
