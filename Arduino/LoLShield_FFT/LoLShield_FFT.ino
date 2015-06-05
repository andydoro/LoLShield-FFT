/*
FFT for LoL Shield
 by Andy Doro
 http://andydoro.com/vulol/
 
 based on FFT library and code from the Arduino forums and
 the Charlieplexing library for the LoL Shield.
 */


// include libraries
#include <Charliplexing.h>
#include <fix_fft.h>

// where we read the audio voltage
#define AUDIOPIN 5


char im[128], data[128];

char data_avgs[14];

int i=0,val;


void setup() {
  LedSign::Init();            // initilizes the LoL Shield
}


void loop() {

  for (i=0; i < 128; i++){                                     
    val = analogRead(AUDIOPIN); // read voltage                                    
    data[i] = val;                                       
    im[i] = 0;                                                     
  };

  fix_fft(data,im,7,0);

  for (i=0; i< 64;i++){                                      
    data[i] = sqrt(data[i] * data[i] + im[i] * im[i]);  // this gets the absolute value of the values in the array, so we're only dealing with positive numbers
  };     


  // average bars together
  for (i=0; i<14; i++) {
    data_avgs[i] = data[i*4] + data[i*4 + 1] + data[i*4 + 2] + data[i*4 + 3];   // average together 
    data_avgs[i] = map(data_avgs[i], 0, 30, 0, 9);                              // remap values for LoL
  }



  // set LoLShield
  for (int x=0; x < 14; x++) {
    for (int y=0; y < 9; y++) {
      if (y < data_avgs[13-x]) { // 13-x reverses the bars so low to high frequences are represented from left to right.
        LedSign::Set(x,y,1);        // set the LED on
      } 
      else {
        LedSign::Set(x,y,0);       // set the LED off
      }
    } 
  }

}


