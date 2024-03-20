/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/
//this is and array function cpontaing all the letters in the aplhabet in their respective morse code
//Constants
const int buttonPin = 2; // the pin for the push button
const int ledPin = LED_BUILTIN; //the pin for the led

const char* alphabetmorse[] = {
".-",     // A
"-...",   // B
"-.-.",   // C
"-..",    // D
".",      // E
"..-.",   // F
"--.",    // G
"....",   // H
"..",     // I
".---",   // J
"-.-",    // K
".-..",   // L
"--",     // M
"-.",     // N
"---",    // O
".--.",   // P
"--.-",   // Q
".-.",    // R
"...",    // S
"-",      // T
"..-",    // U
"...-",   // V
".--",    // W
"-..-",   // X
"-.--",   // Y
"--.."    // Z

};

String lastEnteredName; 

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(ledPin, OUTPUT);
  // initialize button pin as input
  pinMode(buttonPin, INPUT);
  Serial.begin(9600); // intialize the serial monitor to 9600
}

//the setup function to perform the blink of a dot
void dot() {
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(500);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second

}

//the setup function to perform the blink of a dash
void dash() {
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1500);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second

}

//the setup function will read the name input by the user and will check the morse code alphabet array 
//to find the relavent morese code and blink dots and dashes respectively
void nameBlink(String name){

  // converting each character of the name to uppercase
  name.toUpperCase();
  lastEnteredName = name;

  for(int i = 0;i < name.length(); i++)
  {
    char letter = name[i]; 
    
    //obtaining each letters morse code representation
    if( letter >= 'A' && letter <= 'Z')
    {
      String morseLetter = alphabetmorse[letter - 'A'];
      
      for ( int j = 0; j < morseLetter.length(); j++)
      {
        if (morseLetter[j] == '.') //check is the morse code a dot
        {
          dot(); //Blink dot
        }
        else if (morseLetter[j] == '-') //check is the morse code a dash
        {
          dash(); //Blink dash
        }
      }
      delay(1500);
    }
  }
}


// the loop function runs over and over again forever
void loop() {
  if (Serial.available())
  {
    String name = Serial.readStringUntil('\n');
    nameBlink(name);
  }

  if (digitalRead(buttonPin) == HIGH) {
   
  nameBlink(lastEnteredName);  // Blink the last entered name in Morse code
  delay(500);  // Delay before accepting another button press
  
}
}
