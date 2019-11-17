/* D0 and D1 blinks
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
  // initialize digital pins 0 and 1 as an output.
  DDRD |= ((1 << PD0) | (1 << PD1));
  // initialize digital pin 12 as an output.
  DDRB |= (1 << PB4);
  
  PORTB |= (1 << PB4);    // turn the MOSFET switch Q1 on
  PORTD |= (1 << PD0);    // turn the LED D0 on
  PORTD &= ~(1 << PD1);   // turn the LED D1 off
} // end of setup function

void loop() {
  delay(1000);            // wait for a second 
  //change the LED D0 and D1 state
  PORTD ^= ((1 << PD0) | (1 << PD1));   
} // end of loop function
