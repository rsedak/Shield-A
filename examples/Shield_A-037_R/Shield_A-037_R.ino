/* D0-D7, RV1
 *  turning on LEDs from the edge to the centre
 *  depending on potentiometer shaft position 
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

// define which the LED is currently turned on
int activeLED = 0;

// define which the LED was turned on during last loop cycle
int lastActiveLED = 0;

// define default potentiometer value
int potentiometerValue = 0;

void setup() {
  // initialize digital pins 
  // 0, 1, 2, 3, 4, 5, 6 and 7 as an ouput
  DDRD  = B11111111;
  // initialize digital pin 12 as an output.
  DDRB |= (1 << PB4);  

  // turn the MOSFET switch Q1 on
  PORTB |= (1 << PB4);  

  
  // Prepare ADC Multiplexer Selection Register and ADC converter
  // to read potentiometer value

  // turn ADC on
  ADCSRA = (1 << ADEN);   
  
  // Prescaler of 128
  ADCSRA |= (1 << ADPS0) |  (1 << ADPS1) | (1 << ADPS2);  
  
  // enable AVcc with external capacitor at AREF pin
  // and connect analog input pin A0 to the ADC
  ADMUX = (1 << REFS0) | ( 0 & 0x07);  
  
  // let it stabilize
  delay (20);
  

  // read the potentiomenter value into a variable

  // start a AD conversion 
  ADCSRA |= (1 << ADSC);
  
  // conversion is over when ADSC bit turns to 0,
  // so wait while ADSC bit is 1
  while (((ADCSRA & (1 << ADSC)) >> ADSC));

  // store converted vaule to variable
  potentiometerValue = ADC;

  // define active LED depending on potentiometer readings
  activeLED = map(potentiometerValue, 0, 1023, 0 , 3);
  
  // turn on LEDs from active LED to the right
  for ( int i = activeLED; i >= 0; i--) {
    digitalWrite(i, HIGH);
    digitalWrite(7 - i, HIGH);
  }
  
} // end of setup function


void loop() {
  // read the potentiomenter value into a local variable

  // start a conversion 
  ADCSRA |= (1 << ADSC);
  
  // conversion is over when ADSC bit turns to 0,
  // so wait while ADSC bit is 1
  while (((ADCSRA & (1 << ADSC)) >> ADSC));

  // store converted vaule to variable
  potentiometerValue = ADC;

  // define active LED depending on potentiometer readings
  activeLED = map(potentiometerValue, 0, 1023, 0 , 3);
  
  // check if current active led is right of last active led
  // if so, turn off the last active LEDs 
  if ( lastActiveLED > activeLED ) {
    PORTD &= ~(1 << lastActiveLED);
    PORTD &= ~(1 << 7 - lastActiveLED);
  } else {
    // turn the active LEDs on
    PORTD |= (1 << activeLED);
    PORTD |= (1 << 7 - activeLED);
  }

  // set last active led for the next loop round
  lastActiveLED = activeLED;
  
} // end of loop function
