/* RGB matrix 
 * red, blue, green
 * four RGB LED
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
  // Set D5-D11 as output pins 
  for ( int i = 5; i <= 11; i++){
    pinMode(i, OUTPUT);
  }

  // Set colors
  digitalWrite(5, LOW);  // Red
  digitalWrite(6, LOW);  // Blue
  digitalWrite(7, LOW);  // Green

  // Set which RGB LED is turned ON/OFF
  digitalWrite(8, HIGH);  // Turn OFF first RGB LED
  digitalWrite(9, HIGH);  // Turn OFF second RGB LED
  digitalWrite(10, HIGH); // Turn OFF third RGB LED
  digitalWrite(11, HIGH); // Turn OFF fourth RGB LED
} // end of setup function

void loop() {
  // rotate LEDs D8 - D11
  for (int i=8; i<=11; i++){
    digitalWrite(i, LOW);
    // rotate LED colors
    for (int j=5; j<=7; j++){
      digitalWrite(j, HIGH);
      delay(500);
      digitalWrite(j, LOW);
    }
    digitalWrite(i, HIGH);
  }
} // end of loop function
