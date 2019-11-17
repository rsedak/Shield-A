/* D0 and D1 blinks
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
  // initialize digital pins 0, 1 and 12 as an ouput
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(12, OUTPUT);
    
  digitalWrite(12, HIGH); // turn the MOSFET switch Q1 on
  digitalWrite(1, LOW);   // turn the LED D1 off
} // end of setup function

void loop() {
  digitalWrite(0, HIGH);  // turn the LED D0 on
  digitalWrite(1, LOW);   // turn the LED D1 off
  delay(1000);            // wait for a second
  digitalWrite(0, LOW);   // turn the LED D0 off
  digitalWrite(1, HIGH);  // turn the LED D1 on
  delay(1000);            // wait for a second
} // end of loop function
