# STM32F_HX711
STM32F4 HX711 library tested on STM32F411CEUb BlackPill, I have not confirmed but it should work on any STM32F4 that uses ARM Cortex-M4. 

# Important details
Need to configure a 32-bit timer in the MCU system in order for the library to work. Need to initialize timer in main.c file.
Need to set dout_pin as INPUT and clock_pin as OUTPUT aswell as the GPIO Periferal port in use, GPIO periferal must be the same for both pins as of now.

# How to use 
Currently it's needed to download both .h and .c files and put them under the same folder inside /Drivers folder. Need to configure this folder as a workspace or else STM32CubeIDE won't use it/work at all.

Use initialize function before while and set a private HX711 variable;

HC711 ExampleName;

# Future work
Repository is new, need implementation of the device characteristics such as gain and power down. May aswell implement complex formulas to use the measurements in real time.
