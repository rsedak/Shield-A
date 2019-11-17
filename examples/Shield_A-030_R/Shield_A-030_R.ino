/* D0-D7, SW1, SW2
 *  for SW1 pressed, light moves in direction from D0 to D7 for one LED
 *  for SW2 pressed, light moves in direction from D7 to D0 for one LED
 *  using debounce algorithm
 *  with register manipulation  
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
 *                  A0 | PC0
 *                  A1 | PC1
 *                  A2 | PC2
 *                  A3 | PC3
 *                  A4 | PC4
 *                  A5 | PC5
 *                  A6 | PC6
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

unsigned long lastDebounceTimeSW1 = 0;  
unsigned long lastDebounceTimeSW2 = 0;  
unsigned long debounceDelay = 50;    

int activeLED = 0;

void setup() {
  // initialize digital pins 
  // 0, 1, 2, 3, 4, 5, 6 and 7 as an ouput
  DDRD  = B11111111;
  // initialize digital pin 12 as an output.
  DDRB |= (1 << PB4);  

  // turn the MOSFET switch Q1 on
  PORTB |= (1 << PB4);  

  // turn the D0 LED on
  PORTD |= (1 << PD0);
  
  // Set SW1 as input pin
  DDRC &= ~(1 << PC1);
  // Set pullup resistor for SW1
  PORTC |= (1 << PC1);

  // Set SW2 as input pin
  DDRC &= ~(1 << PC2);
  // Set pullup resistor for SW2
  PORTC |= (1 << PC2);

  // let it stabilize
  delay(20);
} // end of setup function

void loop() {

  int readingSW1 = ((PINC & (1 << PC1)) >> PC1);
  if (readingSW1 != lastStateSW1) {
    lastDebounceTimeSW1 = millis();
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


  int readingSW2 = ((PINC & (1 << PC2)) >> PC2);
  if (readingSW2 != lastStateSW2) {
    lastDebounceTimeSW2 = millis();
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
  // Rotate D register to left for one step 
  PORTD  = ( PORTD << 1 ) | ( PORTD >> 7);
} // end of moveLightToLeft function

void moveLightToRight(){
  // Rotate D register to right for one step  
  PORTD  = ( PORTD >> 1 ) | ( PORTD << 7);
} // end of moveLightToRight function

