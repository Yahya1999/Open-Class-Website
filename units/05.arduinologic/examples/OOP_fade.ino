//===========================================================================
//======================OOP Programing fading LEDS===========================
//===========================================================================
class FadingLED{
  // Class Member Variables
  // These are initialized at startup
  int led;
  int brightness;
  int fadeAmount;
  int pause;

  public:
  // Constructor - creates a Flasher 
  // and initializes the member variables and state
  FadingLED(int p){  // starts the constructor and catches a small scope variable 'p'
    led = p;         // uses the small scope variable 'p' to determine the LED pin
    fadeAmount = 5;  // sets a reasonable fadeAmount
    brightness = 0;  // sets a reasonable starting brightness
    pause = 30;
    
    pinMode(led, OUTPUT); //set up the pin you are going to use as an output
  }

  void fadeCycle(){
    int counter = 0;      // the counter is just here to check and see if we've made it 'down and back' through the fade
    while (counter < 2){  // while we haven't yet made it 'down and back' cycle through the fading process
      analogWrite(led, brightness);
    
      // change the brightness for next time through the loop:
      brightness = brightness + fadeAmount;
    
      // reverse the direction of the fading at the ends of the fade:
      if (brightness <= 0 || brightness >= 255) { 
        fadeAmount = -fadeAmount;
        counter++;    //add to the counter when you reach the end of a fade
      }
      // wait for the pause time to see the dimming effect
      delay(pause);
    }
  }

  void setDelay(int t){
    pause = t;  // change the pause time to user defined value
  }

  void setFadeAmount(int fA){
    if(fA > 255){       // if user input too high of value
      fadeAmount = 255; // make fadeAmount 255
    }else{              // otherwise....
      fadeAmount = fA;  // change the fade amount to user defined value
    }
  }

  void setFadeDirection(bool dir){ //can only input boolean values: 1>> positive fadeAmount ::: 0>> negative fadeAmount
    if (dir){           //if boolean is true
      abs(fadeAmount);  //set fade amount positive
    }else{              //if boolean is false
      abs(fadeAmount);  //absolute value to known positive
      fadeAmount = -fadeAmount; //then make fadeAmount negative
    }
  }

  void setBrightness(int b){ // change the starting brightness
    if (b<0){                // if the value is too low, bring it to zero
      b=0;
    }else if (b>255){        // if the value is too high, bring it to 255
      b=255;
      fadeAmount = -fadeAmount; // also have to start with a negative fade amount if you start at this limit
    }
    brightness = b;
  }
};

//===========================================================================
//===========================================================================
//========================The Arduino Sketch (after OOP)=====================
//===========================================================================

// initalize all of the LEDs you need
// each instance needs a:
        //name(pin#);
FadingLED LED1(3);
FadingLED LED2(5);
FadingLED LED3(6);
FadingLED LED4(9);
FadingLED LED5(10);
FadingLED LED6(11);

// the setup routine runs once when you press reset:
void setup() {
  // don't need anything here, since it is all done in the OOP constructor!!!
}

// the loop routine runs over and over again forever:
void loop() {
  LED1.fadeCycle(); //These are the methods set up in the OOP stuff above. There are more to explore also...
  LED2.fadeCycle();
  LED3.fadeCycle();
  LED4.fadeCycle();
  LED5.fadeCycle();
  LED6.fadeCycle();
}
