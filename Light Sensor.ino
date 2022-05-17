// constants won't change
const int LIGHT_SENSOR_PIN = A0; // Arduino pin connected to light sensor's  pin
const int LED_PIN          = 13;  // Arduino pin connected to LED's pin
const int LED_ACTIVATION_VALUE = 400;
const int SERIAL_OUTPUT_FREQUENCY = 5000;
// variables will change:
int analogValue;
int time1;
int time2;
int flag;

void setup() {
  pinMode(LED_PIN, OUTPUT); // set arduino pin to output mode
  Serial.begin(9600);
  time1 = millis();
}

void loop() {
  analogValue = analogRead(LIGHT_SENSOR_PIN); // read the input on analog pin
  
  if(analogValue < LED_ACTIVATION_VALUE){
    digitalWrite(LED_PIN, HIGH); // turn on LED
    flag=0;
  }
  else{
    digitalWrite(LED_PIN, LOW);  // turn off LED
    flag=1;
  }
  time2 = millis();
  if(time2-time1 >=SERIAL_OUTPUT_FREQUENCY){
    if(flag==0){
        Serial.print("Light Sensor: ");
        Serial.println(analogValue);
        Serial.print("LED STATUS : " );
        Serial.println("ON");  
    }
    else{
        Serial.print("Light Sensor: ");
        Serial.println(analogValue);
        Serial.print("LED STATUS : " );
        Serial.println("OFF");
    }
    time1=time2;
    
   }
}
