/* RGB matrix
 * red, blue, green
 * one RGB LED
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

  // Set D5-D7 as output pins 
  DDRD |= ((1 << PD5) | (1 << PD6) | (1 << PD7));

  // Set D8-D11 as output pins 
  DDRB |= ((1 << PB0) | (1 << PB1) | (1 << PB2) | (1 << PB3));
  
  // Turn OFF RED, Blue and Green LED
  PORTD &= ~((1 << PD5) | (1 << PD6) | (1 << PD7));

  // Turn ON D8 RGB LED - pin is in LOW state
  PORTB &= ~(1 << PB0);

  // Turn OFF D9, D10 and D11 RGB LED - pins are in HIGH state
  PORTB |= ((1 << PB1) | (1 << PB2) | (1 << PB3));
} // end of setup function

void loop() {
  // rotate LED colors
  for (int i=5; i<=7; i++){
    PORTD |= (1 << i);
    delay(500);
    PORTD &= ~(1 << i);
  }
} // end of loop function
