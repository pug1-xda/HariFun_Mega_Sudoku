int thresholds[15] = {0, 55, 107, 248, 281, 313, 340, 400, 423, 445, 461, 503, 519, 533, 546};   // analog inputs from pressing the keypad
char keypad[15] = {1, 2, 3, 4, 5, 6, 10, 7, 8, 9, 11, 13, 0, 14}; // A=10,B=11,C=12,*=13,#=14

#define KEY_A   10
#define KEY_B   11
#define KEY_C   12
#define KEY_D   13
#define KEY_STAR  14
#define KEY_HASH  15


void setup() {
  Serial.begin(9600);
}


void loop() {
  WaitForKeypress();
}


void HandleKeypress(char keyPress)  {

  switch (keyPress) {
    case KEY_A: // Select Box

      break;
      
    case KEY_B: // ???
    
      break;
      
    case KEY_C: // ???
    
      break;
      
    case KEY_D: // Clear
 
      break;
      
    case KEY_STAR: // New Game

      break;
      
    case KEY_HASH: // Start Over

      break;
      
  }
}

void WaitForKeypress()
{
  int value = analogRead(A0);
  //Serial.println(value);
  for (int i = 0; i < 16; i++)
  {
    // Is A0 close enough to one of the keypad values?
    if ( abs(value - thresholds[i]) < 4)
    {
      // Yes, translate the index of that value to the actual name of the key
      //Serial.print("   ");
      //Serial.println(keypad[i],DEC);
      //FillAll(keypad[i]);
      HandleKeypress(keypad[i]);
      // Wait until they release the button
      while (analogRead(A0) < 1000) {
        delay(100);
      }
    }
  }
  //delayMicroseconds(10);
}

