 FFT for LoL Shield
================
 by Andy Doro
 http://andydoro.com/vulol/


This is an audio spectrum VU meter using the LoL Shield for Arduino.

The LoL Shield is a 14 x 9 LED matrix which fits onto the Arduino as a shield and is controlled through an efficient method known as Charlieplexing. It was designed by Jimmie P. Rodgers.

This project uses a Fast Fourier Transform library for Arduino to analyze an audio signal, break it up into frequency bands, and display that information on the LoL Shield.

The Arduino microcontroller is fast enough to calculate a fast Fourier transformation. It lives up to its name and is surprisingly fast and accurate.
Since all the work is done by the microcontroller, this project is completely portable if you use batteries.

Instructions for how to build and code this project were released on Instructables. The project was a finalist in the Instructables Microcontroller Contest and featured in the Instructables eBook Awesome LED Projects. 

http://www.instructables.com/id/LoL-Shield-Audio-Spectrum-VU-Meter/
 

Hardware:
 
- Arduino or Arduino-compatible
- LoL Shield
- audio source

Requires FFT and Charlieplexing libraries. The ones included here may be out of date.

