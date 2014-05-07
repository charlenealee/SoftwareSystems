/*
  
Charlene Lee
HW 04
 Author: Allen Downey 
 
 Based on http://arduino.cc/en/Tutorial/AnalogInput
 Created by David Cuartielles
 modified 30 Aug 2011
 By Tom Igoe

 License: Public Domain
 
 */
 
//#include <TimerOne.h>
//#include "TimerOne.h"
 
int ledPin = 5;       // select the pin for the LED
int buttonPin1 = 2;
int buttonPin2 = 3;
boolean toggle0 = 0;

void setup() {
  Serial.begin(9600);
//  
  
  
  
  pinMode(buttonPin1, INPUT_PULLUP);  
  pinMode(buttonPin2, INPUT_PULLUP);  
  
  
  // setting digital pins num 7,6,5,4,3,2,1,0
  DDRD = DDRD | B11100000;  
  
  // setting digital pins num 15,14,13,12,11,10,_,_ <-- leaving last two empty 
  DDRB = B1111100;  
  
  
  
  
//  Here, initializing timers for length of 100000 microseconds
// Wanted to intially have led blink 5 times (10Hz), so in other words, 5 cycles of on & off/ sec, 0.1 sec 

  noInterrupts();           // disable all interrupts here
  
//Here, set timer0 interrupt at 2kHz
    
  TCCR0A = 0;// setting register of TCCR0A to 0
  TCCR0B = 0;// repeat ^ for TCCR0B
  TCNT0  = 0;// want to initialize the counter value to 0
  
  
  // set compare match register for 2khz increments
  //calculating match register by calculating 16*10^6= 16000000
  //16000000/127999=  ~125.   
  OCR0A = 124;
  
  
  //Then, need to turn onto mode for CTC by shifting over bytes
  TCCR0A |= (1 << WGM01);
  
  // Set CS01 and CS00 bits for the 64 prescaler, prepares for coming enabler for timer 
  TCCR0B |= (1 << CS01) | (1 << CS00);   
  
  // Enables timer interrupt
  TIMSK0 |= (1 << OCIE0A);

 
  interrupts();             // here enables all interrupts

}




void writeByte(int x) {

  int pinsA = B11111100;
  int pinsB = B00000011;

  int setA = x&Apins; //combine bytes here
  int setB= x&Bpins;

  setA <<=6; //shift over 6 bytes 
  setB >>=2;
  
  PORTA = setA;
  PORTB = setB | B00000100;
}


byte swapTheBits (byte test)
{
  byte results;
 
    asm("mov __tmp_reg__, %[in] \n\t"
		
		
	// shift over the high bits to carry over	
		
      "lsl __tmp_reg__  \n\t"  
      "ror %[out] \n\t" 
      : [out] "=r" (results) : [in] "r" (test));
      return(results);
}



ISR(timer1_compare){         

  int buttonA = digitalRead(buttonPin1);
  if (buttonA) return;  
  counter += stride;
  if (counter > high) {
    counter = low;
  }
  
  counter = swapTheBits(counter);
  writeByte(counter);
}

  
  counter = swapTheBits(counter);
  writeByte(counter);


int low = 36;
int high = 255;
int stride = 5;
int counter = low;

void loop() {
    
  }