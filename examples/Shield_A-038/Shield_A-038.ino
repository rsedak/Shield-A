/* RV1 and buzzer 
 *  Making a noise
 *  
 *  Buzzer frequency changes depending on potentiometer value.
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


int potentiometerValue = 0;

void setup() {
  // Set buzzer pin
  pinMode(13, OUTPUT); 
} // end of setup function


void loop() {
  // read the potentiomenter value, calculate delay value
  // and store into the variable
  potentiometerValue = analogRead(A0) * 10 + 100;

  // turn the buzzer on
  digitalWrite(13, HIGH);

  // wait for calculated value
  delayMicroseconds(potentiometerValue);

  // turn the buzzer off
  digitalWrite(13, LOW);

  // wait for calculated value
  delayMicroseconds(potentiometerValue);
} // end of loop function
