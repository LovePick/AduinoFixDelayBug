//-------- Add --
#include <DateTime.h>

//--------

#define LED_BUILTIN 13
#define LED_BUTTONTOUT 12
#define BUTTON 5

int buttonState = 0;

bool ledState = HIGH;

//-------- Add --

struct Async{
  bool wait = false;
  unsigned long nextActive;
  unsigned long timeDelay; //second
} myAsync;

//--------

void setup() {
  Serial.begin(19200);
  
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_BUTTONTOUT, OUTPUT);

  pinMode(BUTTON, INPUT);

  setUpAsyn(&myAsync, 1);
}

// the loop function runs over and over again forever
void loop() {

  //--------
//  digitalWrite(LED_BUILTIN, HIGH);   
//  delay(1000);                      
//  digitalWrite(LED_BUILTIN, LOW);    
//  delay(1000);    


  
  if(loopAsynchronous(&myAsync) == false){
    
    //Change state
    ledState = !ledState; // Change state LED


    setUpAsyn(&myAsync, 1); // reset timmer
  }

  digitalWrite(LED_BUILTIN, ledState);
  
  //------

  buttonState = digitalRead(BUTTON);

  if(buttonState == HIGH){
    digitalWrite(LED_BUTTONTOUT, HIGH);
  }else{
    digitalWrite(LED_BUTTONTOUT, LOW);
  }
  

}



//--------


void setUpAsyn(Async* _asyn, unsigned long _delay){

  if(_asyn->wait == false){
    _asyn->wait = true;
    _asyn->timeDelay = _delay;
    _asyn->nextActive = DateTime.now() + _asyn->timeDelay;
  }
}



bool loopAsynchronous(Async* _asyn){

  unsigned long _now = DateTime.now();

  if(_now >= _asyn->nextActive){
    _asyn->wait = false;
    _asyn->nextActive = _now + _asyn->timeDelay;
  }

  return _asyn->wait;
  
}
