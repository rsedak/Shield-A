/* D0-D7
 * animation
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

// define animation in array
byte ANIMATION[] = {B10000001,
                    B01000010,
                    B00100100,
                    B00011000,
                    B00101000,
                    B01001000,
                    B10001000,
                    B01001000,
                    B00101000,
                    B00011000,
                    B00010100,
                    B00010010,
                    B00010001,
                    B00010010,
                    B00010100,
                    B00011000,
                    B00100100,
                    B01000010,
                    B10000001};

void setup() {
  // initialize digital pins 
  // 0, 1, 2, 3, 4, 5, 6, 7 and 12 as an ouput
  // and turn the LEDs D0 - D7 off  
  for ( int i = 0; i <= 7; i++){
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }  
  pinMode(12, OUTPUT);
  
  // turn the MOSFET switch Q1 on
  digitalWrite(12, HIGH);
} // end of setup function

void loop() {
  int sizeOfAnimation = sizeof(ANIMATION);

  // read every element of array, and set LEDs state
  for (int i=0; i<sizeOfAnimation; i++){
    digitalWrite(0, bitRead(ANIMATION[i], 0));  // set D0
    digitalWrite(1, bitRead(ANIMATION[i], 1));  // set D1
    digitalWrite(2, bitRead(ANIMATION[i], 2));  // set D2
    digitalWrite(3, bitRead(ANIMATION[i], 3));  // set D3
    digitalWrite(4, bitRead(ANIMATION[i], 4));  // set D4
    digitalWrite(5, bitRead(ANIMATION[i], 5));  // set D5
    digitalWrite(6, bitRead(ANIMATION[i], 6));  // set D6
    digitalWrite(7, bitRead(ANIMATION[i], 7));  // set D7
    delay(100);  // wait for a 100ms
  }
} // end of loop function
