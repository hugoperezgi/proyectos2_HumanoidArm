#include <stdint.h>
#include "calibrationServos.h"
#include <stdio.h>

uint8_t servoid = 0;
uint8_t i = 0;
uint16_t pulselen_from_degrees[10][181];
uint16_t SERVOMAXS_Fingers[] = {SERVOMAX_thumb_B, SERVOMAX_index_B, SERVOMAX_middle_B, SERVOMAX_ring_B, SERVOMAX_pinky_B, SERVOMAX_thumb_A, SERVOMAX_index_A, SERVOMAX_middle_A, SERVOMAX_ring_A, SERVOMAX_pinky_A};
uint16_t SERVOMINS_Fingers[] = {SERVOMIN_thumb_B, SERVOMIN_index_B, SERVOMIN_middle_B, SERVOMIN_ring_B, SERVOMIN_pinky_B, SERVOMIN_thumb_A, SERVOMIN_index_A, SERVOMIN_middle_A, SERVOMIN_ring_A, SERVOMIN_pinky_A};
uint16_t SERVOMAXS_Arm[] = {SERVOMAX_palm, SERVOMAX_wrist, SERVOMAX_forearm, SERVOMAX_biceps, SERVOMAX_shoulder};
uint16_t SERVOMINS_Arm[] = {SERVOMIN_palm, SERVOMIN_wrist, SERVOMIN_forearm, SERVOMIN_biceps, SERVOMIN_shoulder};
float pulse_step_hand[10];
uint16_t pulselen_from_degrees_arm[5][181];
float pulse_step_arm[5];

/**
 * Arduino map fn
*/
long map(long x, long in_min, long in_max, long out_min, long out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int main(){

    for (i = 0; i < 181; i++){
        for(servoid=0; servoid<10; servoid++){
        pulselen_from_degrees[servoid][i] = map(i,0,180,SERVOMINS_Fingers[servoid],SERVOMAXS_Fingers[servoid]);
        }
    }
    float fuck;
    for(servoid=0;servoid<10;servoid++){
        fuck=0;
        for(i=0;i<180;i++){
            fuck+=pulselen_from_degrees[servoid][i+1]-pulselen_from_degrees[servoid][i];
        }
        fuck/=180;
        pulse_step_hand[servoid]=fuck;
    }

    for(servoid=0; servoid<10; servoid++){
        printf("Servoid %i, Step: %f\n",servoid,pulse_step_hand[servoid]);
    }
    
    for (i = 0; i < 181; i++){
        for(servoid=0; servoid<5; servoid++){
            pulselen_from_degrees_arm[servoid][i] = map(i,0,180,SERVOMINS_Arm[servoid],SERVOMAXS_Arm[servoid]);
        }
    }
    
    for(servoid=0;servoid<5;servoid++){
        fuck=0;
        for(i=0;i<180;i++){
            fuck+=pulselen_from_degrees_arm[servoid][i+1]-pulselen_from_degrees_arm[servoid][i];
        }
        fuck/=180;
        pulse_step_arm[servoid]=fuck;
    }
    
    for(servoid=0; servoid<5; servoid++){
        switch(servoid){
            case 0: printf("Palm Servo, Step: %f\n",pulse_step_arm[0]);break;
            case 1: printf("Wrist Servo, Step: %f\n",pulse_step_arm[1]);break;
            case 2: printf("Forearm Servo, Step: %f\n",pulse_step_arm[2]);break;
            case 3: printf("Biceps Servo, Step: %f\n",pulse_step_arm[3]);break;
            case 4: printf("Shoulder Servo, Step: %f\n",pulse_step_arm[4]);break;
        }
    }

    float oSize = sizeof(pulselen_from_degrees) + sizeof(pulselen_from_degrees_arm) + 30*sizeof(uint16_t); //15*181 of the mapped values + 15(x2) Min/Max Values
    float nSize = 15*sizeof(float)+30*sizeof(uint16_t); //15 Step values + 15(x2) Min/Max Values

    printf("Original size: %i B, new size: %i B. Saved %i bytes (%f%).\n",int(oSize),int(nSize),int(oSize-nSize),((oSize-nSize)/oSize)*100);

    // for (i = 0; i < 181; i++){
    //     for(servoid=0; servoid<10; servoid++){    
    //         printf(" %i",pulselen_from_degrees[servoid][i]);
    //     }
    //     printf("\n\n");
    // }
    // for(i=0;i<10;i++){
    //     printf(" %f",pulse_step_hand[i]);
    // }
    //     printf("\n\n");
}

