################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:/Program\ Files\ (x86)/eclipse/arduinoPlugin/libraries/TFT/1.0.5/src/TFT.cpp 

LINK_OBJ += \
./libraries/TFT/src/TFT.cpp.o 

CPP_DEPS += \
.\libraries\TFT\src\TFT.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
libraries/TFT/src/TFT.cpp.o: C:/Program\ Files\ (x86)/eclipse/arduinoPlugin/libraries/TFT/1.0.5/src/TFT.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\KoenD_000\eclipse\java-neon\eclipse\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_YUN -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8041 "-DUSB_MANUFACTURER=\"Unknown\"" "-DUSB_PRODUCT=\"Arduino Yun\""  -I"C:\Program Files (x86)\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\cores\arduino" -I"C:\Program Files (x86)\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\variants\yun" -I"C:\Program Files (x86)\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\EEPROM" -I"C:\Program Files (x86)\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\EEPROM\src" -I"C:\Program Files (x86)\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\HID" -I"C:\Program Files (x86)\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\HID\src" -I"C:\Program Files (x86)\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SoftwareSerial" -I"C:\Program Files (x86)\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SoftwareSerial\src" -I"C:\Program Files (x86)\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\Wire" -I"C:\Program Files (x86)\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\Wire\src" -I"C:\Program Files (x86)\eclipse\arduinoPlugin\libraries\Servo\1.1.2" -I"C:\Program Files (x86)\eclipse\arduinoPlugin\libraries\Servo\1.1.2\src" -I"C:\Program Files (x86)\eclipse\arduinoPlugin\libraries\CapacitiveSensor\0.5.1" -I"C:\Program Files (x86)\eclipse\arduinoPlugin\libraries\Ethernet\1.1.2" -I"C:\Program Files (x86)\eclipse\arduinoPlugin\libraries\Ethernet\1.1.2\src" -I"C:\Program Files (x86)\eclipse\arduinoPlugin\libraries\Firmata\2.5.7" -I"C:\Program Files (x86)\eclipse\arduinoPlugin\libraries\Firmata\2.5.7\utility" -I"C:\Program Files (x86)\eclipse\arduinoPlugin\libraries\GSM\1.0.5" -I"C:\Program Files (x86)\eclipse\arduinoPlugin\libraries\GSM\1.0.5\src" -I"C:\Program Files (x86)\eclipse\arduinoPlugin\libraries\Keyboard\1.0.1" -I"C:\Program Files (x86)\eclipse\arduinoPlugin\libraries\Keyboard\1.0.1\src" -I"C:\Program Files (x86)\eclipse\arduinoPlugin\libraries\LiquidCrystal\1.0.7" -I"C:\Program Files (x86)\eclipse\arduinoPlugin\libraries\LiquidCrystal\1.0.7\src" -I"C:\Program Files (x86)\eclipse\arduinoPlugin\libraries\Mouse\1.0.1" -I"C:\Program Files (x86)\eclipse\arduinoPlugin\libraries\Mouse\1.0.1\src" -I"C:\Program Files (x86)\eclipse\arduinoPlugin\libraries\SD\1.1.1" -I"C:\Program Files (x86)\eclipse\arduinoPlugin\libraries\SD\1.1.1\src" -I"C:\Program Files (x86)\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SPI" -I"C:\Program Files (x86)\eclipse\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SPI\src" -I"C:\Program Files (x86)\eclipse\arduinoPlugin\libraries\Stepper\1.1.2" -I"C:\Program Files (x86)\eclipse\arduinoPlugin\libraries\Stepper\1.1.2\src" -I"C:\Program Files (x86)\eclipse\arduinoPlugin\libraries\TFT\1.0.5" -I"C:\Program Files (x86)\eclipse\arduinoPlugin\libraries\TFT\1.0.5\src" -I"C:\Program Files (x86)\eclipse\arduinoPlugin\libraries\WiFi\1.2.6" -I"C:\Program Files (x86)\eclipse\arduinoPlugin\libraries\WiFi\1.2.6\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


