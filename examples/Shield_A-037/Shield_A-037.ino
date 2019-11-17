/* D0-D7, RV1
 *  turning on LEDs from the edge to the centre
 *  depending on potentiometer shaft position 
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
int activeLED = 0;

// define which the LED was turned on during last loop cycle
int lastActiveLED = 0;

// define default potentiometer value
int potentiometerValue = 0;

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
  
  // read the potentiomenter value into a local variable
  potentiometerValue = analogRead(A0);

  // define active LED depending on potentiometer readings
  activeLED = map(potentiometerValue, 0, 1023, 0 , 3);
  
  // turn on LEDs from active LED to the right
  for ( int i = activeLED; i >= 0; i--) {
    digitalWrite(i, HIGH);
    digitalWrite(7 - i, HIGH);
  }
  
} // end of setup function


void loop() {
  // read the potentiomenter value into a variable
  potentiometerValue = analogRead(A0);

  // define active LED depending on potentiometer readings
  activeLED = map(potentiometerValue, 0, 1023, 0 , 3);
  
  // check if current active led is right of last active led
  // if so, turn off the last active LEDs 
  if ( lastActiveLED > activeLED ) {
    digitalWrite(lastActiveLED, LOW);
    digitalWrite(7 - lastActiveLED, LOW);
  } else {
    // turn the active LEDs on
    digitalWrite(activeLED, HIGH);
    digitalWrite(7 - activeLED, HIGH);
  }

  // set last active led for the next loop round
  lastActiveLED = activeLED;
  
} // end of loop function
