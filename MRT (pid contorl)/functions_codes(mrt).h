/*
 * functions_codes.h
 *
 *  Created on: Jan 4, 2013
 *      Author: Hesham
 */

#ifndef FUNCTIONS_CODES_H_
#define FUNCTIONS_CODES_H_

#define RELEASED 1
#define PRESSED 2

#define RISING_EDGE 1
#define FALLING_EDGE 2

#define SENSE 1
#define NONE 2

#define LIGHT 1
#define DARK 2

#define TRUE 1
#define FALSE 0
#define HIGH 1
#define LOW 0


#define LEFT_MOTOR_1   1
#define RIGHT_MOTOR_1  2
#define LEFT_MOTOR_2   3
#define RIGHT_MOTOR_2  4

#define FORWARD_DIRECTION 4
#define BACKWARD_DIRECTION 5
#define STOP_DIRECTION 6

#define F1_KEY 0x32
#define F2_KEY 0x23
#define F3_KEY 0x34
#define F4_KEY 0x25
#define F5_KEY 0x26
#define F6_KEY 0x37
#define UP_KEY 0x2C
#define OFF_KEY 0

#define DOWN_KEY 0x3E
#define LEFT_KEY 0x3F
#define RIGHT_KEY 0x3D
#define UP_AND_LEFT_KEY 0x36
#define UP_AND_RIGHT_KEY 0x3C
#define DOWN_AND_LEFT_KEY 0x33
#define DOWN_AND_RIGHT_KEY 0x39

#define LIGHT  1
#define DARK  2

void mcu_initialization(void);

unsigned int analogRead(unsigned char PinNumber);

// Input Functions
unsigned char button(unsigned char PinNumber, unsigned char State);
unsigned char mic(unsigned char PinNumber);
unsigned char cds(unsigned char PinNumber, unsigned int SignalThreshold, unsigned char State);
unsigned char ir(unsigned char InputPinNumber, unsigned int SignalThreshold, unsigned char State);
unsigned char rc(unsigned char KeyName); 
unsigned char counter(unsigned char ReptitionNumber,unsigned int delay, unsigned char(*ptrFunctionHandler)(unsigned char, unsigned char));
unsigned char CheckCustomDigitalInput(unsigned char PinNumber, unsigned char SignalThreshold, unsigned char State);
unsigned char edge(unsigned char PinNumber, unsigned char EdgeType);


// Output Functions
void digitalWrite(unsigned char PinNumber, unsigned char LogicState);
void run_servo(unsigned char OutputPinNumber,  int Angle);
void tone(unsigned char OutputPinNumber, float Frequency, int Duration);
void noTone(unsigned char OutputPinNumber);
void dc_motor(unsigned char MotorTag, unsigned char MovingDirection, char Speed);
void lcd(unsigned char* strText); // Constraint: max 32 characters including spaces
void lcd_input(unsigned char PinNumber);
void debug(unsigned char* ptrMsg);
void debug_input(unsigned char PinNumber);
void CustomDigitalOutput(unsigned char PinNumber, unsigned char LogicState);

// Flow Functions
void delay(unsigned char Hour, unsigned char Minute,unsigned char Seconds,unsigned int miliSeconds);
void end(void);

#endif /* FUNCTIONS_CODES_H_ */
