/* D0-D7, SW1, SW2
 * Turning On / Off D0
 * with register manipulation 
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
  // 0, 1, 2, 3, 4, 5, 6 and 7 as an ouput
  DDRD  = B11111111;
  // initialize digital pin 12 as an output.
  DDRB |= (1 << PB4);  
  
  PORTB |= (1 << PB4);  // turn the MOSFET switch on
  // Set SW1 as input pin
  DDRC &= ~(1 << PC1);
  // Set pullup resistor for SW1
  PORTC |= (1 << PC1);

  // Set SW2 as input pin
  DDRC &= ~(1 << PC2);
  // Set pullup resistor for SW2
  PORTC |= (1 << PC2);
} // end of setup function

void loop() {

  // read the state of the SW1 push button
  // and check if the push button is pressed.
  if (((PINC & (1 << PC1)) >> PC1) == 0) {
    // turn LED D0 ON
    PORTD |= (1 << PD0);
  }
  
  // read the state of the SW2 push button
  // and check if the push button is pressed.
  if (((PINC & (1 << PC2)) >> PC2) == 0){
    // turn LED D0 OFF
    PORTD &= ~(1 << PD0);
  }
} // end of loop function
