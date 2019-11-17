/* D0-D7, SW1, SW2
 *  when SW1 is short pressed, 
 *   - light moves in direction from D0 to D7 for one LED 
 *  when SW1 is pressed for 3 seconds, 
 *   - light moves in direction from D0 to D7 for one LED continuously
 *  when SW2 is short pressed, 
 *   - light moves in direction from D7 to D0 for one LED
 *  when SW2 is pressed for 3 seconds, 
 *   - light moves in direction from D7 to D0 for one LED continuously
 *  - using debounce algorithm
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

int currentStateSW1;
int lastStateSW1 = HIGH;   
int currentStateSW2;             
int lastStateSW2 = HIGH;   
int longSWPress = 3000;

unsigned long lastDebounceTimeSW1 = 0;  
unsigned long lastDebounceTimeSW2 = 0;  
unsigned long debounceDelay = 50;    

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
  
  digitalWrite(activeLED, HIGH); // turn the LED on
  
  // turn the MOSFET switch Q1 on
  digitalWrite(12, HIGH);

  // Set SW1
  pinMode(A1, INPUT_PULLUP);
  
  // Set SW2
  pinMode(A2, INPUT_PULLUP);
} // end of setup function

void loop() {

  int readingSW1 = digitalRead(A1);
  if (readingSW1 != lastStateSW1) {
    lastDebounceTimeSW1 = millis();
  } else {
    if ((millis() - lastDebounceTimeSW1) > longSWPress && (readingSW1 == LOW)){
      moveLightToLeft();
      delay(200);
    }
  }
  if ((millis() - lastDebounceTimeSW1) > debounceDelay) {
    if (readingSW1 != currentStateSW1) {
      currentStateSW1 = readingSW1;
      if (currentStateSW1 == LOW) {
        moveLightToLeft();
      }
    }
  }
  lastStateSW1 = readingSW1;


  int readingSW2 = digitalRead(A2);
  if (readingSW2 != lastStateSW2) {
    lastDebounceTimeSW2 = millis();
  } else {
    if ((millis() - lastDebounceTimeSW2) > longSWPress && (readingSW2 == LOW)) {
      moveLightToRight();
      delay(200);
    }
  }
  if ((millis() - lastDebounceTimeSW2) > debounceDelay) {
    if (readingSW2 != currentStateSW2) {
      currentStateSW2 = readingSW2;
      if (currentStateSW2 == LOW) {
        moveLightToRight();
      }
    }
  }
  lastStateSW2 = readingSW2;
  
} // end of loop function

void moveLightToLeft(){
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
} // end of moveLightToLeft function

void moveLightToRight(){
  // Turn the active LED off
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
} // end of moveLightToRight function

