/* D0-D7
 * two even LEDs shift from D0 to D7
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
  // initialize digital pins 
  // 0, 1, 2, 3, 4, 5, 6 and 7 as an ouput
  DDRD  = B11111111;
  // initialize digital pin 12 as an output.
  DDRB |= (1 << PB4);  

  // turn the LEDs D3 - D7 and D1 off, D0 and D2 on
  PORTD = B00000101;    
  PORTB |= (1 << PB4);  // turn the MOSFET switch Q1 on
} // end of setup function

void loop() {
 
  delay(200);  // wait for a 200ms

  // Rotate D register to left for one step  
  PORTD  = ( PORTD << 1) | ( PORTD >> 7 );
} // end of loop function
