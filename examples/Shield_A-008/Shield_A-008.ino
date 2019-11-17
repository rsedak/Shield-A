/* D0-D7 
 * turning on LEDs - from D7 to D0
 * turning off LEDs - from D0 to D7
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
  // turn the LEDs D7 - D0 on, one by one with 200ms delay
  for ( int i = 7; i >= 0; i--) {
    digitalWrite(i, HIGH);
    delay(200);
  }

  // turn the LEDs D0 - D7 off, one by one with 200ms delay
  for ( int i = 0; i <= 7; i++) {
    digitalWrite(i, LOW);
    delay(200);
  }
  delay(500);
} // end of loop function
