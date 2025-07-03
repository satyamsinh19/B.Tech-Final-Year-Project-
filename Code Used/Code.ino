
#include <Servo.h> 
 
// Pin definitions 
const int trigPin1 = 2; // Ultrasonic Sensor 1 Trigger 
const int echoPin1 = 3; // Ultrasonic Sensor 1 Echo 
const int trigPin2 = 4; // Ultrasonic Sensor 2 Trigger 
const int echoPin2 = 5; // Ultrasonic Sensor 2 Echo 
 
const int servoPin1 = 6; // Servo Motor 1 
const int servoPin2 = 7; // Servo Motor 2 
 
const int redLED = 8; // Red LED 
const int yellowLED = 9; // Yellow LED 
66  
const int greenLED = 10; // Green LED 
const int buzzerPin = 11; // Buzzer 
 
// Servo objects 
Servo gateServo1; 
Servo gateServo2; 
 
// Gate positions (degrees) - Adjust as per your servo setup 
const int gateOpenPos = 0; 
const int gateClosePos = 90; 
// Detection distance threshold in cm 
const float detectionDistance = 15.0; 
 
// Timing constants 
const unsigned long delayBeforeGateClose = 500; // 0.5 seconds 
const unsigned long yellowLightDuration = 500; // 0.5 seconds 
 
// State enums for better readability 
enum SystemState { 
IDLE,  // Gate open, green LED on, waiting for train 
TRAIN_APPROACHING, // Train detected on Sensor1, red LED + buzzer, 
gates closing 
GATE_CLOSED_HOLD, // Gates closed, keep red LED + buzzer until 
sensor2 detects train 
TRAIN_PASSING, // Train detected on Sensor2, buzzer off, LED 
sequence, gates opening 
}; 
SystemState currentState = IDLE; 
unsigned long stateStartTime = 0; 
void setup() { 
Serial.begin(9600); 
 
// Attach servos 
gateServo1.attach(servoPin1); 
gateServo2.attach(servoPin2); 
 
// Set pins modes 
pinMode(trigPin1, OUTPUT); 
pinMode(echoPin1, INPUT); 
pinMode(trigPin2, OUTPUT); 
67  
pinMode(echoPin2, INPUT); 
 
pinMode(redLED, OUTPUT); 
pinMode(yellowLED, OUTPUT); 
pinMode(greenLED, OUTPUT); 
pinMode(buzzerPin, OUTPUT); 
 
// INITIAL STATE: 
// Gates are opened, green LED ON, other LEDs OFF, buzzer OFF 
enterIdleState(); 
} 
 
void loop() { 
float distance1 = measureDistance(trigPin1, echoPin1); 
float distance2 = measureDistance(trigPin2, echoPin2); 
 
switch(currentState) { 
case IDLE: 
// If trained detected within 15cm on sensor1 => start approach sequence 
if(distance1 > 0 && distance1 < detectionDistance) { 
enterTrainApproachingState(); 
} 
break; 
 
case TRAIN_APPROACHING: 
// Wait for 0.5 seconds then close gates and move to hold state 
if(millis() - stateStartTime >= delayBeforeGateClose) { 
closeGates(); 
enterGateClosedHoldState(); 
} 
break; 
 
case GATE_CLOSED_HOLD: 
// Keep gates closed and red LED + buzzer on 
// Wait for sensor2 to detect train 
if(distance2 > 0 && distance2 < detectionDistance) { 
enterTrainPassingState(); 
} 
break; 
 
case TRAIN_PASSING: 
// After yellow light duration, switch to green light and open gates 
if(millis() - stateStartTime >= yellowLightDuration) { 
68  
digitalWrite(yellowLED, LOW); 
digitalWrite(greenLED, HIGH); 
openGates(); 
// After gate opens, return to idle state 
enterIdleState(); 
} 
break; 
} 
 
 
delay(50); // Small delay to avoid excessive sensor querying 
} 
 
// State handling functions 
 
void enterIdleState() { 
currentState = IDLE; 
stateStartTime = millis(); 
 
openGates(); 
 
digitalWrite(redLED, LOW); 
digitalWrite(yellowLED, LOW); 
digitalWrite(greenLED, HIGH); 
 
noTone(buzzerPin); 
 
Serial.println("State: IDLE - Gate open, green LED on"); 
} 
 
void enterTrainApproachingState() { 
currentState = TRAIN_APPROACHING; 
stateStartTime = millis(); 
 
digitalWrite(greenLED, LOW); 
digitalWrite(redLED, HIGH); 
digitalWrite(yellowLED, LOW); 
 
tone(buzzerPin, 1000); // 1kHz buzzer tone 
 
Serial.println("State: TRAIN_APPROACHING - Red LED + Buzzer ON, preparing to 
close gates"); 
} 
69  
void enterGateClosedHoldState() { 
currentState = GATE_CLOSED_HOLD; 
stateStartTime = millis(); 
 
// Keep red LED and buzzer on for hold 
digitalWrite(redLED, HIGH); 
digitalWrite(yellowLED, LOW); 
digitalWrite(greenLED, LOW); 
 
tone(buzzerPin, 1000); 
 
Serial.println("State: GATE_CLOSED_HOLD - Gates closed, red LED + buzzer ON, 
waiting for sensor2"); 
} 
 
void enterTrainPassingState() { 
currentState = TRAIN_PASSING; 
stateStartTime = millis(); 
 
noTone(buzzerPin); 
digitalWrite(redLED, LOW); 
digitalWrite(yellowLED, HIGH); 
digitalWrite(greenLED, LOW); 
 
Serial.println("State: TRAIN_PASSING - Buzzer OFF, yellow LED ON"); 
} 
 
// Helper functions 
 
float measureDistance(int trigPin, int echoPin) { 
// Send ultrasonic pulse 
digitalWrite(trigPin, LOW); 
delayMicroseconds(2); 
digitalWrite(trigPin, HIGH); 
delayMicroseconds(10); 
digitalWrite(trigPin, LOW); 
 
// Measure pulse duration on echo pin 
long duration = pulseIn(echoPin, HIGH, 30000); // timeout 30ms to avoid blocking 
indefinitely 
if(duration == 0) { 
// No echo received (timeout) 
70  
return -1.0; 
} 
 
// Calculate distance in cm 
float distanceCm = (duration * 0.0343) / 2; 
//Serial.print("Distance (cm): "); Serial.println(distanceCm); 
return distanceCm; 
} 
 
void closeGates() { 
gateServo1.write(gateClosePos); 
gateServo2.write(gateClosePos); 
Serial.println("Gates closing"); 
} 
 
void openGates() { 
gateServo1.write(gateOpenPos); 
gateServo2.write(gateOpenPos); 
Serial.println("Gates opening"); 
} 
 