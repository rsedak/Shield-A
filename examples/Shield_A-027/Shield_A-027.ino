/* D0-D7, SW1, SW2
 * Turning On / Off D0
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
  
  // turn the MOSFET switch on
  digitalWrite(12, HIGH);
  
  // Set SW1
  pinMode(A1, INPUT_PULLUP);
  
  // Set SW2
  pinMode(A2, INPUT_PULLUP);
} // end of setup function

void loop() {

  // read the state of the SW1 push button
  // and check if the push button is pressed.
  if (digitalRead(A1) == 0) {
    // turn LED D0 ON
    digitalWrite(0, HIGH);
  }
  
  // read the state of the SW2 push button
  // and check if the push button is pressed.
  if (digitalRead(A2) == 0){
    // turn LED D0 OFF
    digitalWrite(0, LOW);
  }
} // end of loop function
