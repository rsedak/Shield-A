/* RGB matrix 
 * multiplexing four RGB LED
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
  // Set D5-D11 as output pins 
  for ( int i = 5; i <= 11; i++){
    pinMode(i, OUTPUT);
  }

  // Set colors
  digitalWrite(5, LOW);  // Red
  digitalWrite(6, LOW);  // Blue
  digitalWrite(7, LOW);  // Green

  // Set which RGB LED is turned ON/OFF
  digitalWrite(8, HIGH);  // Turn OFF RGB LED D8
  digitalWrite(9, HIGH);  // Turn OFF RGB LED D9
  digitalWrite(10, HIGH); // Turn OFF RGB LED D10
  digitalWrite(11, HIGH); // Turn OFF RGB LED D11

  // Seed ranodom generator
  randomSeed(analogRead(A6));
} // end of setup function

void loop() {

  // define new random colors for RGB LEDs
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
  
  digitalWrite(8, LOW);  // Turn ON RGB LED D8
  digitalWrite(11, HIGH); // Turn OFF RGB LED D11
  digitalWrite(5, bitRead(D8, 0));  // Red
  digitalWrite(6, bitRead(D8, 1));  // Blue
  digitalWrite(7, bitRead(D8, 2));  // Green
  
  delay(RGBDelay);

  digitalWrite(8, HIGH);  // Turn OFF RGB LED D8
  digitalWrite(9, LOW);  // Turn ON RGB LED D9
  digitalWrite(5, bitRead(D9, 0));  // Red
  digitalWrite(6, bitRead(D9, 1));  // Blue
  digitalWrite(7, bitRead(D9, 2));  // Green
  
  delay(RGBDelay);

  digitalWrite(9, HIGH);  // Turn OFF RGB LED D9
  digitalWrite(10, LOW); // Turn ON RGB LED D10
  digitalWrite(5, bitRead(D10, 0));  // Red
  digitalWrite(6, bitRead(D10, 1));  // Blue
  digitalWrite(7, bitRead(D10, 2));  // Green
  
  delay(RGBDelay);

  digitalWrite(10, HIGH); // Turn OFF RGB LED D10
  digitalWrite(11, LOW); // Turn ON RGB LED D11
  digitalWrite(5, bitRead(D11, 0));  // Red
  digitalWrite(6, bitRead(D11, 1));  // Blue
  digitalWrite(7, bitRead(D11, 2));  // Green
  
  delay(RGBDelay);
} // end of loop function
