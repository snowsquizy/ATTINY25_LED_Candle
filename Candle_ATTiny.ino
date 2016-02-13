/*
 *  ATTINY LED Candle simulation
 *  -------------------------------
 *  Connections
 *  2.7 - 5.0 Volts to   Pin 8
 *  Ground to            Pin 4
 *  Long LED Lead to     Pin 5
 *  1K Resistor          Short LED leg
 *  1K Resistor to       Pin 4
 *            -----
 *  RESET   1 |*  | 8   VCC
 *  A3/D3   2 |   | 7   A1/D2
 *  A2/D4   3 |   | 6   PWM/D1
 *  GND     4 |   | 5   PWM/D0
 *            -----
 *  -------------------------------
*/

#define LEDPIN 0 // LED Connection
#define PWMIN 1 // Minimum number of pulses
#define PWMAX 4 // Maximum number of pulses
const int BRIGHTMIN = 60; // Default LED brightness. =<96.
const int DELAYMIN = 500; // Minimum delay between pulses 
const int DELAYMAX = 4000; // Maximum delay between pulses

void setup() 
{                
  randomSeed (analogRead (A1)); // Randomise
  pinMode(LEDPIN, OUTPUT); // Sets LED Pin to be an output 
}
void loop() 
{
  // For loop sets the number of pulses and repeats these pulses
  for (int x = random(PWMIN, PWMAX); x > 0; x-- ) 
  { 
    int bright = 200 - random(80); // Sets a random maximum brightness level for this pulse
    // For loop raises the brightness of the LED from minimum to maximum value
    for (int j = BRIGHTMIN; j < bright ; j++) 
    {
      analogWrite(LEDPIN, j);
      delay(4);
    }
    // For loop lowers the brightness of the LED from maximum to minimum value
    for (int k = bright; k > BRIGHTMIN; k--) 
    {
      analogWrite(LEDPIN, k);
      delay(4);
    }
    delay(25); // Adds a delay between pulses to make them more visible
  }
  analogWrite(LEDPIN, BRIGHTMIN);
  delay(random(DELAYMIN,DELAYMAX)); // Adds a delay between pulse sets
}
