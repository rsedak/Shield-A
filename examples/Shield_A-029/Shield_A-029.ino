/* D0-D7, SW1, SW2
 *  for SW1 pressed, light moves in direction from D0 to D7 for one LED
 *  for SW2 pressed, light moves in direction from D7 to D0 for one LED
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

int activeLED = 0;

void setup() {
  // initialize digital pins 
  // 0, 1, 2, 3, 4, 5, 6, 7 and 12 as an ouput
  // and turn the LEDs D0 - D7 off 
  for ( int i = 0; i <= 7; i++){
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }  
  pinMode(12, OUTPUT);

  // turn the LED on
  digitalWrite(activeLED, HIGH); 
  
  // turn the MOSFET switch Q1 on
  digitalWrite(12, HIGH);
  
  // Set SW1
  pinMode(A1, INPUT_PULLUP);

  // Set SW2
  pinMode(A2, INPUT_PULLUP);
} // end of setup function

void loop() {

  // read the state of the SW1 push button value
  // and check if the push button is pressed.
  if (digitalRead(A1) == 0) {
    
    // Turn the active LED off
    digitalWrite(activeLED, LOW);
    
    // Check if active LED is D7
    // if it is, define D0 as active LED
    // if not, define next with higher number as active
    if ( activeLED == 7 ){
      activeLED = 0;
    } else {
      activeLED++;
    }
    // Turn the active LED on
    digitalWrite(activeLED, HIGH);
    
    // read the state of the SW1 push button value
    // and check if the push button is pressed.
    // while SW1 push button is pressed, do nothing
    while (digitalRead(A1) == 0){
    }
  }

  // read the state of the SW2 push button value
  // and check if the push button is pressed.
  if (digitalRead(A2) == 0){
    
    // Turn the actibe LED off
    digitalWrite(activeLED, LOW);

    // Check if active LED is D0
    // if it is, define D7 as active LED
    // if not, define next with lower as active
    if ( activeLED == 0 ){
      activeLED = 7;
    } else {
      activeLED--;
    }
    // Turn the active LED on
    digitalWrite(activeLED, HIGH);

    // read the state of the SW2 push button value
    // and check if the push button is pressed.
    // while SW2 push button is pressed, do notihing
    while (digitalRead(A2) == 0){
    }
  }
  
} // end of loop function
