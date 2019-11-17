/* D0-D7 
 * four LEDs shift from D7 to D0
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
  int led; 
  // Define the first LED which will be tuned on
  for ( int i = 7; i >= 0; i--) {
    // turn four LEDs in raw on
    for ( int j = 0; j <= 3; j++) {
      led = i - j;
      // if LED is "over" the right edge, 
      // turn on first LED on left edge
      if ( led < 0 ) {
        led = led + 8;
      }
      digitalWrite(led, HIGH);
    }
    delay(200);  // wait for a 200ms

    // turn four LEDs in raw off
    for ( int j = 0; j <= 3; j++) {
      // if LED is "over" the right edge, 
      // turn on first LED on left edge      
      led = i - j;
      if ( led < 0 ) {
        led = led + 8;
      }
      digitalWrite(led, LOW);
    }
  }
} // end of loop function
