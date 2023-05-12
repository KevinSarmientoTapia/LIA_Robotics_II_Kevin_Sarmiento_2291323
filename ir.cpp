//CPP file for IR
#include "ir.h" // Includes the created IR header file

ir::ir(int IR){ // define IR pin
  this->IR=IR;
}
void ir::read(){ // read IR pulse
  //STEP 1: DETECTION OF THE SEQUENCE START PULSE (4.5mS)
  start_pulse=pulseIn(IR, HIGH);
  if(start_pulse>4000 && start_pulse<5000) // check if it is the start pulse of 4.5mS (start of sequence)
  {
    //STEP 2: TIMING OF TIMES OF EACH PULSE (uS)
    for(x=1; x<=32; x++) 
    {
      duration[x]=pulseIn(IR, HIGH); // Duration of each pulse (uS)
    }
    //STEP 3: ACCORDING TO THE TIME OF EACH PULSE, WE DETERMINE IF IT IS A LOGIC 0 OR 1 
    for(x=1; x<=32; x++) 
    {
      if(duration[x]>500 && duration[x]<700) //If the pulse lasts between 500 and 700uS:
      {  
        bits[x]=0; // is a logical 0
      }
      if(duration[x]>1500 && duration[x]<1750) //If the pulse lasts between 1500 and 1750uS:
      {
        bits[x]=1; //is a logical 1
      }
    }      
    //STEP 4: CONVERSION OF THE BINARY ARRAY TO A DECIMAL VARIABLE.
     //Since many of the bits are repeated on all keys, we omit those bits and
     //we are left with bits 17 through 21 and 23 (6 bits). Enough to distinguish all the keys.
     //These 6 bits are converted to decimal with the Powers of 2 method. And we store the result
     //in the variable code_key.
    key_code=0; // Reset the last key pressed
    if(bits[17]==1)
    {
      key_code=key_code+32; //2^6
    }
    if(bits[18]==1)
    {
      key_code=key_code+16; //2^5
    }
    if(bits[19]==1)
    {
      key_code=key_code+8; //2^4
    }
    if(bits[20]==1)
    {
      key_code=key_code+4; //2^3
    }
    if(bits[21]==1)
    {
      key_code=key_code+2; //2^2
    }
    if(bits[23]==1)
    {
      key_code=key_code+1; //2^1
    }
  }
  delay(180); //delay so it doesn't "bounce" and doesn't read two presses of the same key
}

int ir::keycode(){ // read key_code pressed and returns the value
  key_code;

  return key_code;
}
