
#include "functions_codes.h"
    

int main ()
{
    int PID;
    int turn_value = 0;
    float error, previous_error;
    float center_point = 3.5;
    int line_position;
    
    #define sensorNumber 6 
    
    int sensor[sensorNumber];


    int threshold[sensorNumber] = { 300, 300, 300, 300, 300, 300 };
    
    #define turn_delay 10    
    #define u_turn_delay 50  
    #define stop_timer 30  
   
    int kd = 1000;  //need to be adjusted 
    int kp = 70;  //need to be adjusted.
    
    int max_speed = 250;          
    int left_motor_speed = 200;   
    int right_motor_speed = 200;  
    int turn_speed = 150;         
    int sensor_sum;
    float calculated_pos;

    while(1)
    {
        for(;;)
        {
            if(ir(2,950,SENSE)==TRUE&&ir(3,950,SENSE)==TRUE)
            {
                dc_motor(LEFT_MOTOR_1,FORWARD_DIRECTION,5);
                dc_motor(RIGHT_MOTOR_1,FORWARD_DIRECTION,5);
            }
            if(ir(2,0,NONE)==TRUE&&ir(3,950,SENSE)==TRUE)
            {
                dc_motor(LEFT_MOTOR_1,FORWARD_DIRECTION,5);
                dc_motor(RIGHT_MOTOR_1,STOP_DIRECTION,0);
            }
            if(ir(2,950,SENSE)==TRUE&&ir(3,0,NONE)==TRUE)
            {
                dc_motor(LEFT_MOTOR_1,STOP_DIRECTION,0);
                dc_motor(RIGHT_MOTOR_1,FORWARD_DIRECTION,5);
            }
            if(ir(1,0,NONE)==TRUE||ir(4,0,NONE)==TRUE)
            {
                dc_motor(LEFT_MOTOR_1,STOP_DIRECTION,0);
                dc_motor(RIGHT_MOTOR_1,STOP_DIRECTION,0);
                delay(0,0,1,0);
                dc_motor(LEFT_MOTOR_1,FORWARD_DIRECTION,5);
                delay(0,0,0,435);
                goto Label_0;
            }
        }
    }
    return 0;
}
