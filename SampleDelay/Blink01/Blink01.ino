

#define LED_BUILTIN 13
#define LED_BUTTONTOUT 12
#define BUTTON 5

int buttonState = 0;
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_BUTTONTOUT, OUTPUT);

  pinMode(BUTTON, INPUT);
  
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(1000);                      
  digitalWrite(LED_BUILTIN, LOW);    
  delay(1000);                       


  buttonState = digitalRead(BUTTON);

  if(buttonState == HIGH){
    digitalWrite(LED_BUTTONTOUT, HIGH);
  }else{
    digitalWrite(LED_BUTTONTOUT, LOW);
  }
  

}
