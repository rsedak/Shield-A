/* D0-D7, RV1
 *  running light 
 *  - from D7 to D0 depending on potentiometer shaft position
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

// define which the LED is currently turned on
int activeLED = 7;

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
  // read the potentiomenter value into a local variable
  int potentiometerValue = analogRead(A0);

  // turn the active LED off
  digitalWrite(activeLED, LOW);

  // define active LED depending on potentiometer readings
  activeLED = 7 - map(potentiometerValue, 0, 1023, 0 , 7);

  // turn the active LED on
  digitalWrite(activeLED, HIGH);
} // end of loop function
