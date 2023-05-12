/*
 Display different number on four 7-seg using 74HC595

 The program's goal is to display different numbers using the 4 digit 7-segment and the 74HC595 shitOut

 The main theme is the use of shiftOut() function to sent the data we want in order to display a number in a digit.
*/

//4 7segment pins:
int clearPin = 5; //Arduino pin A1 connected to Pin 10, SRCLR(Clear/Reset) of 74HC595
int serialData = 6;  //Arduino pin 3 connected to Pin 14, SER(serial input) of 74HC595
int shiftClock = 7;  //Arduino pin 4 connected to Pin 11, SRCLK(shift clock) of 74HC595
int latchClock = 8;  //Arduino pin 2 connected to Pin 12, RCLK(storage/latch clock) of 74HC595
int D1=13; //Digit 1 to pin A4
int D2=12; //Digit 2 to pin 12
int D3=11; //Digit 3 to pin 11
int D4=10; //Digit 4 to pin 10

// Numbers to display in the 4 7 segment:
/*
Every LED pin in the 4 7 segment is a bit, so if we add the decimal value of the bits of every LED
we want turn on we obtain a number that written in the ShiftOut function will make the 4 7 segment 
display in one of its digits the number we want to see.

DP(H)   G    F    E    D    C    B    A  <-Pins of the 4 7 segment
 2^7   2^6  2^5  2^4  2^3  2^2  2^1  2^0
 ___   ___  ___  ___  ___  ___  ___  ___ 

 128   64   32   16    8    4    2    1  <-Decimal values of the pins of the 4 7 segment

Example:
if we want to display the number two in one digit of the 4 7 segment, we would have to add the decimal
value of the pins A B G E D, wich are the LEDs we want to turn on. So, if we add those values we get the 
number 91 because 1(A) + 2(B) + 64(G) + E(16) + D(8) = 91. Now, if the write that number in the 
ShiftOut function we will display the number 2 in one digit of the 4 7 segment.
*/
int zero=63;
int one=6;
int two=91;
int three=79;
int four=102;
int five=109;
int six=125;
int seven=7;
int eight=127;
int nine=111;
// If we add 128 to every number, we get the same number plus its decimal point:
int zerodp=zero+128;
int onedp=one+128;
int twodp=two+128;
int threedp=three+128;
int fourdp=four+128;
int fivedp=five+128;
int sixdp=six+128;
int sevendp=seven+128;
int eightdp=eight+128;
int ninedp=nine+128;

// If we don't want to display any number in a digit of the 4 7 segment, we write 0 in the shiftout function
int none=0;

void setup() {
// set all pins for the 4 7 segment as outputs:
pinMode(clearPin, OUTPUT);
pinMode(shiftClock, OUTPUT);
pinMode(latchClock, OUTPUT);
pinMode(serialData, OUTPUT);
pinMode(D1, OUTPUT);
pinMode(D2, OUTPUT);
pinMode(D3, OUTPUT);
pinMode(D4, OUTPUT);

digitalWrite(clearPin, 0); //Pin is active-low, this clears the shift register
digitalWrite(clearPin, 255); //Clear pin is inactive
}

void loop() {
Number_to_display(two, zero, two, three); // Call function to display the number we want in each digit from left to right.
}

void Number_to_display(int c, int b, int d, int a) {
// This function turns off and then on in sequence every digit so fast so we can se that the 4 7 segment ins displaying one number
 First_digit(c);
 delay(5);
 Second_digit(b);
 delay(5);
 Third_digit(d);
 delay(5);
 Fourth_digit(a);
 delay(5);
}
void First_digit(int x) {
// take the latchClock low so the LEDs don't change while you're sending in bits:  
  digitalWrite(latchClock, 0);    
// We will only display a value in the first digit, as this is active-low we will write 0 to turn a digit on:
     digitalWrite(D1, 0); 
     digitalWrite(D2, 1); 
     digitalWrite(D3, 1); 
     digitalWrite(D4, 1);       
   shiftOut(serialData, shiftClock, MSBFIRST, x); // shift out the bits
// take the latchClock high to send the data mentioned in the shiftOut 
   digitalWrite(latchClock, 1); 
}
void Second_digit(int x) {
// take the latchClock low so the LEDs don't change while you're sending in bits:  
  digitalWrite(latchClock, 0);
// We will only display a value in the second digit, as this is active-low we will write 0 to turn a digit on:    
     digitalWrite(D1, 255); 
     digitalWrite(D2, 0); 
     digitalWrite(D3, 1); 
     digitalWrite(D4, 1);        
   shiftOut(serialData, shiftClock, MSBFIRST, x); // shift out the bits
// take the latchClock high to send the data mentioned in the shiftOut 
   digitalWrite(latchClock, 1);    
}
void Third_digit(int x) {
// take the latchClock low so the LEDs don't change while you're sending in bits:  
  digitalWrite(latchClock, 0);    
// We will only display a value in the third digit, as this is active-low we will write 0 to turn a digit on:
     digitalWrite(D1, 255); 
     digitalWrite(D2, 1); 
     digitalWrite(D3, 0); 
     digitalWrite(D4, 1); 
   shiftOut(serialData, shiftClock, MSBFIRST, x); // shift out the bits
// take the latchClock high to send the data mentioned in the shiftOut 
   digitalWrite(latchClock, 255); 
}
void Fourth_digit(int x) {
  //take the latchClock low so the LEDs don't change while you're sending in bits:  
  digitalWrite(latchClock, 0);   
// We will only display a value in the fourth digit, as this is active-low we will write 0 to turn a digit on: 
     digitalWrite(D1, 255); 
     digitalWrite(D2, 1); 
     digitalWrite(D3, 1); 
     digitalWrite(D4, 0); 
   shiftOut(serialData, shiftClock, MSBFIRST, x); // shift out the bits
// take the latchClock high to send the data mentioned in the shiftOut 
   digitalWrite(latchClock, 1);    
}