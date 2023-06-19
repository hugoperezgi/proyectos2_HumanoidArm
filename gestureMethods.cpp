#include "calibrationServos.h" 



/**
 * 
 * Inner servos:
 * thumb_B == servoid=0; index_B == servoid=1; middle_B == servoid=2; ring_B == servoid=3; pinky_B == servoid=4
 * 
 * Outer servos:
 * thumb_A == servoid=5; index_A == servoid=6; middle_A == servoid=7; ring_A == servoid=8; pinky_A == servoid=9
 * 
 * STEP_SERVOID_X -> step of each servo for the mapped range of motion (0-180)
 * 
*/



void openCloseHand_array(){
  for (i = 0; i < 181; i++){
    for(servoid=0; servoid<11; servoid++){
      pwm.setPWM(servoid, 0, pulselen_from_degrees[servoid][i]); 
    }
  }
  
  delay(250);

  for (i = 180; i < 181; i--){  //tl;dr: Overflow causes it to jump from 0 to 255 so no bueno if using i<=0
    for(servoid=0; servoid<11; servoid++){
      pwm.setPWM(servoid, 0, pulselen_from_degrees[servoid][i]);
      
    }
  }

}


void openCloseHand(){
    uint8_t i=0;
    while (i<180){
        pwm.setPWM(0, 0, i*STEP_SERVOID_0 + SERVOMIN_thumb_B);
        pwm.setPWM(1, 0, i*STEP_SERVOID_1 + SERVOMIN_index_B);
        pwm.setPWM(2, 0, i*STEP_SERVOID_2 + SERVOMIN_middle_B);
        pwm.setPWM(3, 0, i*STEP_SERVOID_3 + SERVOMIN_ring_B);
        pwm.setPWM(4, 0, i*STEP_SERVOID_4 + SERVOMIN_pinky_B);
        pwm.setPWM(5, 0, i*STEP_SERVOID_5 + SERVOMIN_thumb_A);
        pwm.setPWM(6, 0, i*STEP_SERVOID_6 + SERVOMIN_index_A);
        pwm.setPWM(7, 0, i*STEP_SERVOID_7 + SERVOMIN_middle_A);
        pwm.setPWM(8, 0, i*STEP_SERVOID_8 + SERVOMIN_ring_A);
        pwm.setPWM(9, 0, i*STEP_SERVOID_9 + SERVOMIN_pinky_A);
        pwm.setPWM(11, 0, -i*STEP_SERVOID_11+SERVOMAX_palm);
        i++;
    }
    i=0;
    while (i<180){
        pwm.setPWM(0, 0, -i*STEP_SERVOID_0 + SERVOMAX_thumb_B);
        pwm.setPWM(1, 0, -i*STEP_SERVOID_1 + SERVOMAX_index_B);
        pwm.setPWM(2, 0, -i*STEP_SERVOID_2 + SERVOMAX_middle_B);
        pwm.setPWM(3, 0, -i*STEP_SERVOID_3 + SERVOMAX_ring_B);
        pwm.setPWM(4, 0, -i*STEP_SERVOID_4 + SERVOMAX_pinky_B);
        pwm.setPWM(5, 0, -i*STEP_SERVOID_5 + SERVOMAX_thumb_A);
        pwm.setPWM(6, 0, -i*STEP_SERVOID_6 + SERVOMAX_index_A);
        pwm.setPWM(7, 0, -i*STEP_SERVOID_7 + SERVOMAX_middle_A);
        pwm.setPWM(8, 0, -i*STEP_SERVOID_8 + SERVOMAX_ring_A);
        pwm.setPWM(9, 0, -i*STEP_SERVOID_9 + SERVOMAX_pinky_A);      
        pwm.setPWM(11, 0, i*STEP_SERVOID_11+ SERVOMIN_palm);
        i++;
    }
}
/**
 * Everything closed but thumb, palm servo extended
*/
void signLangA_array(){


    for (i = 0; i < 181; i++){
        for(servoid=0; servoid<11; servoid++){
            if(servoid == 5 || servoid == 0 || servoid ==11){pwm.setPWM(servoid, 0,pulselen_from_degrees[servoid][0]);}
            pwm.setPWM(servoid, 0, pulselen_from_degrees[servoid][i]); 
        }
    }
  
}

void signLangA(){
    uint8_t i=0;
    while (i<180){
        pwm.setPWM(0, 0, SERVOMIN_thumb_B);
        pwm.setPWM(1, 0, i*STEP_SERVOID_1 + SERVOMIN_index_B);
        pwm.setPWM(2, 0, i*STEP_SERVOID_2 + SERVOMIN_middle_B);
        pwm.setPWM(3, 0, i*STEP_SERVOID_3 + SERVOMIN_ring_B);
        pwm.setPWM(4, 0, i*STEP_SERVOID_4 + SERVOMIN_pinky_B);
        pwm.setPWM(5, 0, SERVOMIN_thumb_A);
        pwm.setPWM(6, 0, i*STEP_SERVOID_6 + SERVOMIN_index_A);
        pwm.setPWM(7, 0, i*STEP_SERVOID_7 + SERVOMIN_middle_A);
        pwm.setPWM(8, 0, i*STEP_SERVOID_8 + SERVOMIN_ring_A);
        pwm.setPWM(9, 0, i*STEP_SERVOID_9 + SERVOMIN_pinky_A);
        pwm.setPWM(11, 0, SERVOMAX_palm);
        i++;
    }
    // i=0;
    // while (i<180){
    //     pwm.setPWM(0, 0, SERVOMAX_thumb_B);
    //     pwm.setPWM(1, 0, -i*STEP_SERVOID_1 + SERVOMAX_index_B);
    //     pwm.setPWM(2, 0, -i*STEP_SERVOID_2 + SERVOMAX_middle_B);
    //     pwm.setPWM(3, 0, -i*STEP_SERVOID_3 + SERVOMAX_ring_B);
    //     pwm.setPWM(4, 0, -i*STEP_SERVOID_4 + SERVOMAX_pinky_B);
    //     pwm.setPWM(5, 0, SERVOMAX_thumb_A);
    //     pwm.setPWM(6, 0, -i*STEP_SERVOID_6 + SERVOMAX_index_A);
    //     pwm.setPWM(7, 0, -i*STEP_SERVOID_7 + SERVOMAX_middle_A);
    //     pwm.setPWM(8, 0, -i*STEP_SERVOID_8 + SERVOMAX_ring_A);
    //     pwm.setPWM(9, 0, -i*STEP_SERVOID_9 + SERVOMAX_pinky_A);        
    //     pwm.setPWM(11, 0, SERVOMAX_palm);
    //     i++;
    // }
}


/**
 * Everything extended, palm servo closed
*/
void signLangB_array(){

    for(servoid=0; servoid<11; servoid++){
        pwm.setPWM(servoid, 0, pulselen_from_degrees[servoid][0]); 
    }

    servoid=11;
    for (i = 0; i < 181; i++){
        pwm.setPWM(servoid, 0, pulselen_from_degrees[servoid][i]); 
    }
}

void signLangB(){
    uint8_t i=0;
    pwm.setPWM(0, 0, SERVOMIN_thumb_B);
    pwm.setPWM(1, 0, SERVOMIN_index_B);
    pwm.setPWM(2, 0, SERVOMIN_middle_B);
    pwm.setPWM(3, 0, SERVOMIN_ring_B);
    pwm.setPWM(4, 0, SERVOMIN_pinky_B);
    pwm.setPWM(5, 0, SERVOMIN_thumb_A);
    pwm.setPWM(6, 0, SERVOMIN_index_A);
    pwm.setPWM(7, 0, SERVOMIN_middle_A);
    pwm.setPWM(8, 0, SERVOMIN_ring_A);
    pwm.setPWM(9, 0, SERVOMIN_pinky_A);
    while (i<180){
        // pwm.setPWM(0, 0, SERVOMIN_thumb_B);
        // pwm.setPWM(1, 0, SERVOMIN_index_B);
        // pwm.setPWM(2, 0, SERVOMIN_middle_B);
        // pwm.setPWM(3, 0, SERVOMIN_ring_B);
        // pwm.setPWM(4, 0, SERVOMIN_pinky_B);
        // pwm.setPWM(5, 0, SERVOMIN_thumb_A);
        // pwm.setPWM(6, 0, SERVOMIN_index_A);
        // pwm.setPWM(7, 0, SERVOMIN_middle_A);
        // pwm.setPWM(8, 0, SERVOMIN_ring_A);
        // pwm.setPWM(9, 0, SERVOMIN_pinky_A);        
        delay(3);
        pwm.setPWM(11, 0, -i*STEP_SERVOID_11+SERVOMAX_palm);
        i++;
    }
    // i=0;
    // while (i<180){
    //     // pwm.setPWM(0, 0, SERVOMAX_thumb_B);
    //     // pwm.setPWM(1, 0, SERVOMAX_index_B);
    //     // pwm.setPWM(2, 0, SERVOMAX_middle_B);
    //     // pwm.setPWM(3, 0, SERVOMAX_ring_B);
    //     // pwm.setPWM(4, 0, SERVOMAX_pinky_B);
    //     // pwm.setPWM(5, 0, SERVOMAX_thumb_A);
    //     // pwm.setPWM(6, 0, SERVOMAX_index_A);
    //     // pwm.setPWM(7, 0, SERVOMAX_middle_A);
    //     // pwm.setPWM(8, 0, SERVOMAX_ring_A);
    //     // pwm.setPWM(9, 0, SERVOMAX_pinky_A);        
    //     delay(3);
    //     pwm.setPWM(11, 0, i*STEP_SERVOID_11+SERVOMIN_palm);
    //     i++;
    // }
}

/**
 * Everything extended, palm servo included
*/
void signLangC_array(){
    for(servoid=0; servoid<11; servoid++){
        pwm.setPWM(servoid, 0, pulselen_from_degrees[servoid][0]); 
    }
}

void signLangC(){
    pwm.setPWM(0, 0, SERVOMIN_thumb_B);
    pwm.setPWM(1, 0, SERVOMIN_index_B);
    pwm.setPWM(2, 0, SERVOMIN_middle_B);
    pwm.setPWM(3, 0, SERVOMIN_ring_B);
    pwm.setPWM(4, 0, SERVOMIN_pinky_B);
    pwm.setPWM(5, 0, SERVOMIN_thumb_A);
    pwm.setPWM(6, 0, SERVOMIN_index_A);
    pwm.setPWM(7, 0, SERVOMIN_middle_A);
    pwm.setPWM(8, 0, SERVOMIN_ring_A);
    pwm.setPWM(9, 0, SERVOMIN_pinky_A);
    pwm.setPWM(11, 0, SERVOMAX_palm);
}


/**
 * index extended, everything else clsoed
*/
void signLangD_array(){
    for (i = 0; i < 181; i++){
        for(servoid=0; servoid<11; servoid++){
            if(servoid == 1 || servoid == 6){pwm.setPWM(servoid, 0,pulselen_from_degrees[servoid][0]);}
            pwm.setPWM(servoid, 0, pulselen_from_degrees[servoid][i]); 
        }
    }
}

void signLangD(){
    uint8_t i=0;
    while (i<180){
        pwm.setPWM(0, 0, i*STEP_SERVOID_0 + SERVOMIN_thumb_B);
        pwm.setPWM(1, 0, SERVOMIN_index_B);
        pwm.setPWM(2, 0, i*STEP_SERVOID_2 + SERVOMIN_middle_B);
        pwm.setPWM(3, 0, i*STEP_SERVOID_3 + SERVOMIN_ring_B);
        pwm.setPWM(4, 0, i*STEP_SERVOID_4 + SERVOMIN_pinky_B);
        pwm.setPWM(5, 0, i*STEP_SERVOID_5 + SERVOMIN_thumb_A);
        pwm.setPWM(6, 0, i*STEP_SERVOID_6 + SERVOMIN_index_A);
        pwm.setPWM(7, 0, i*STEP_SERVOID_7 + SERVOMIN_middle_A);
        pwm.setPWM(8, 0, i*STEP_SERVOID_8 + SERVOMIN_ring_A);
        pwm.setPWM(9, 0, i*STEP_SERVOID_9 + SERVOMIN_pinky_A);
        pwm.setPWM(11, 0, -i*STEP_SERVOID_11+SERVOMAX_palm);
        i++;
    }
    // i=0;
    // while (i<180){
    //     pwm.setPWM(0, 0, -i*STEP_SERVOID_0 + SERVOMAX_thumb_B);
    //     pwm.setPWM(1, 0, SERVOMAX_index_B);
    //     pwm.setPWM(2, 0, -i*STEP_SERVOID_2 + SERVOMAX_middle_B);
    //     pwm.setPWM(3, 0, -i*STEP_SERVOID_3 + SERVOMAX_ring_B);
    //     pwm.setPWM(4, 0, -i*STEP_SERVOID_4 + SERVOMAX_pinky_B);
    //     pwm.setPWM(5, 0, -i*STEP_SERVOID_5 + SERVOMAX_thumb_A);
    //     pwm.setPWM(6, 0, -i*STEP_SERVOID_6 + SERVOMAX_index_A);
    //     pwm.setPWM(7, 0, -i*STEP_SERVOID_7 + SERVOMAX_middle_A);
    //     pwm.setPWM(8, 0, -i*STEP_SERVOID_8 + SERVOMAX_ring_A);
    //     pwm.setPWM(9, 0, -i*STEP_SERVOID_9 + SERVOMAX_pinky_A);        
    //     pwm.setPWM(11, 0, i*STEP_SERVOID_11+SERVOMIN_palm);
    //     i++;
    // }

}

/**
 * Everythin closed
*/
void signLangE_array(){
    for (i = 0; i < 181; i++){
        for(servoid=0; servoid<11; servoid++){
            pwm.setPWM(servoid, 0, pulselen_from_degrees[servoid][i]); 
        }
    }
}

void signLangE(){
    uint8_t i=0;
    while (i<180){
        pwm.setPWM(0, 0, i*STEP_SERVOID_0 + SERVOMIN_thumb_B);
        pwm.setPWM(1, 0, i*STEP_SERVOID_1 + SERVOMIN_index_B);
        pwm.setPWM(2, 0, i*STEP_SERVOID_2 + SERVOMIN_middle_B);
        pwm.setPWM(3, 0, i*STEP_SERVOID_3 + SERVOMIN_ring_B);
        pwm.setPWM(4, 0, i*STEP_SERVOID_4 + SERVOMIN_pinky_B);
        pwm.setPWM(5, 0, i*STEP_SERVOID_5 + SERVOMIN_thumb_A);
        pwm.setPWM(6, 0, i*STEP_SERVOID_6 + SERVOMIN_index_A);
        pwm.setPWM(7, 0, i*STEP_SERVOID_7 + SERVOMIN_middle_A);
        pwm.setPWM(8, 0, i*STEP_SERVOID_8 + SERVOMIN_ring_A);
        pwm.setPWM(9, 0, i*STEP_SERVOID_9 + SERVOMIN_pinky_A);
        pwm.setPWM(11, 0, -i*STEP_SERVOID_11+SERVOMAX_palm);
        i++;
    }
    // i=0;
    // while (i<180){
    //     pwm.setPWM(0, 0, -i*STEP_SERVOID_0 + SERVOMAX_thumb_B);
    //     pwm.setPWM(1, 0, -i*STEP_SERVOID_1 + SERVOMAX_index_B);
    //     pwm.setPWM(2, 0, -i*STEP_SERVOID_2 + SERVOMAX_middle_B);
    //     pwm.setPWM(3, 0, -i*STEP_SERVOID_3 + SERVOMAX_ring_B);
    //     pwm.setPWM(4, 0, -i*STEP_SERVOID_4 + SERVOMAX_pinky_B);
    //     pwm.setPWM(5, 0, -i*STEP_SERVOID_5 + SERVOMAX_thumb_A);
    //     pwm.setPWM(6, 0, -i*STEP_SERVOID_6 + SERVOMAX_index_A);
    //     pwm.setPWM(7, 0, -i*STEP_SERVOID_7 + SERVOMAX_middle_A);
    //     pwm.setPWM(8, 0, -i*STEP_SERVOID_8 + SERVOMAX_ring_A);
    //     pwm.setPWM(9, 0, -i*STEP_SERVOID_9 + SERVOMAX_pinky_A);        
    //     pwm.setPWM(11, 0, i*STEP_SERVOID_11+SERVOMIN_palm);
    //     i++;
    // }
}

/**
 * Index and thumb closed, palm closed, everything else extended
*/
void signLangF_array(){
    for (i = 0; i < 181; i++){
        for(servoid=0; servoid<11; servoid++){
            if(!(servoid == 0 || servoid == 1 || servoid == 5 || servoid == 6 || servoid == 11)){pwm.setPWM(servoid, 0,pulselen_from_degrees[servoid][0]);}
            pwm.setPWM(servoid, 0, pulselen_from_degrees[servoid][i]); 
        }
    }
}

void signLangF(){
    uint8_t i=0;
    while (i<180){
        pwm.setPWM(0, 0, i*STEP_SERVOID_0 + SERVOMIN_thumb_B);
        pwm.setPWM(1, 0, i*STEP_SERVOID_1 + SERVOMIN_index_B);
        pwm.setPWM(2, 0, SERVOMIN_middle_B);
        pwm.setPWM(3, 0, SERVOMIN_ring_B);
        pwm.setPWM(4, 0, SERVOMIN_pinky_B);
        pwm.setPWM(5, 0, i*STEP_SERVOID_5 + SERVOMIN_thumb_A);
        pwm.setPWM(6, 0, i*STEP_SERVOID_6 + SERVOMIN_index_A);
        pwm.setPWM(7, 0, SERVOMIN_middle_A);
        pwm.setPWM(8, 0, SERVOMIN_ring_A);
        pwm.setPWM(9, 0, SERVOMIN_pinky_A);
        pwm.setPWM(11, 0, -i*STEP_SERVOID_11+SERVOMAX_palm);
        i++;
    }
    // i=0;
    // while (i<180){
    //     pwm.setPWM(0, 0, -i*STEP_SERVOID_0 + SERVOMAX_thumb_B);
    //     pwm.setPWM(1, 0, -i*STEP_SERVOID_1 + SERVOMAX_index_B);
    //     pwm.setPWM(2, 0, SERVOMAX_middle_B);
    //     pwm.setPWM(3, 0, SERVOMAX_ring_B);
    //     pwm.setPWM(4, 0, SERVOMAX_pinky_B);
    //     pwm.setPWM(5, 0, -i*STEP_SERVOID_5 + SERVOMAX_thumb_A);
    //     pwm.setPWM(6, 0, -i*STEP_SERVOID_6 + SERVOMAX_index_A);
    //     pwm.setPWM(7, 0, SERVOMAX_middle_A);
    //     pwm.setPWM(8, 0, SERVOMAX_ring_A);
    //     pwm.setPWM(9, 0, SERVOMAX_pinky_A);        
    //     pwm.setPWM(11, 0, i*STEP_SERVOID_11+SERVOMIN_palm);
    //     i++;
    // }
}

/**
 * Everything closed, pynky fully extended, palm closed
*/
void signLangI_array(){
    for (i = 0; i < 181; i++){
        for(servoid=0; servoid<11; servoid++){
            if(servoid == 4 || servoid == 9){pwm.setPWM(servoid, 0,pulselen_from_degrees[servoid][0]);}
            pwm.setPWM(servoid, 0, pulselen_from_degrees[servoid][i]); 
        }
    }
}

void signLangI(){
    uint8_t i=0;
    while (i<180){
        pwm.setPWM(0, 0, i*STEP_SERVOID_0 + SERVOMIN_thumb_B);
        pwm.setPWM(1, 0, i*STEP_SERVOID_1 + SERVOMIN_index_B);
        pwm.setPWM(2, 0, i*STEP_SERVOID_2 + SERVOMIN_middle_B);
        pwm.setPWM(3, 0, i*STEP_SERVOID_3 + SERVOMIN_ring_B);
        pwm.setPWM(4, 0, i*STEP_SERVOID_4 + SERVOMIN_pinky_B);
        pwm.setPWM(5, 0, i*STEP_SERVOID_5 + SERVOMIN_thumb_A);
        pwm.setPWM(6, 0, i*STEP_SERVOID_6 + SERVOMIN_index_A);
        pwm.setPWM(7, 0, i*STEP_SERVOID_7 + SERVOMIN_middle_A);
        pwm.setPWM(8, 0, i*STEP_SERVOID_8 + SERVOMIN_ring_A);
        pwm.setPWM(9, 0, SERVOMIN_pinky_A);
        pwm.setPWM(11, 0, -i*STEP_SERVOID_11+SERVOMAX_palm);
        i++;
    }
    // i=0;
    // while (i<180){
    //     pwm.setPWM(0, 0, -i*STEP_SERVOID_0 + SERVOMAX_thumb_B);
    //     pwm.setPWM(1, 0, -i*STEP_SERVOID_1 + SERVOMAX_index_B);
    //     pwm.setPWM(2, 0, -i*STEP_SERVOID_2 + SERVOMAX_middle_B);
    //     pwm.setPWM(3, 0, -i*STEP_SERVOID_3 + SERVOMAX_ring_B);
    //     pwm.setPWM(4, 0, -i*STEP_SERVOID_4 + SERVOMAX_pinky_B);
    //     pwm.setPWM(5, 0, -i*STEP_SERVOID_5 + SERVOMAX_thumb_A);
    //     pwm.setPWM(6, 0, -i*STEP_SERVOID_6 + SERVOMAX_index_A);
    //     pwm.setPWM(7, 0, -i*STEP_SERVOID_7 + SERVOMAX_middle_A);
    //     pwm.setPWM(8, 0, -i*STEP_SERVOID_8 + SERVOMAX_ring_A);
    //     pwm.setPWM(9, 0, SERVOMAX_pinky_A);        
    //     pwm.setPWM(11, 0, i*STEP_SERVOID_11+SERVOMIN_palm);
    //     i++;
    // }
}

/**
 * Index, Middle and Thumb extended; ring, pynky and palm closed
*/
void signLangK_array(){
    for (i = 0; i < 181; i++){
        for(servoid=0; servoid<11; servoid++){
            if(servoid == 0 || servoid == 1 || servoid == 2 || servoid == 5 || servoid == 6 || servoid == 7){pwm.setPWM(servoid, 0,pulselen_from_degrees[servoid][0]);}
            pwm.setPWM(servoid, 0, pulselen_from_degrees[servoid][i]); 
        }
    }
}

void signLangK(){
    uint8_t i=0;
    while (i<180){
        pwm.setPWM(0, 0, SERVOMIN_thumb_B);
        pwm.setPWM(1, 0, SERVOMIN_index_B);
        pwm.setPWM(2, 0, SERVOMIN_middle_B);
        pwm.setPWM(3, 0, i*STEP_SERVOID_3 + SERVOMIN_ring_B);
        pwm.setPWM(4, 0, i*STEP_SERVOID_4 + SERVOMIN_pinky_B);
        pwm.setPWM(5, 0, i*STEP_SERVOID_5 + SERVOMIN_thumb_A);
        pwm.setPWM(6, 0, i*STEP_SERVOID_6 + SERVOMIN_index_A);
        pwm.setPWM(7, 0, i*STEP_SERVOID_7 + SERVOMIN_middle_A);
        pwm.setPWM(8, 0, i*STEP_SERVOID_8 + SERVOMIN_ring_A);
        pwm.setPWM(9, 0, i*STEP_SERVOID_9 + SERVOMIN_pinky_A);
        pwm.setPWM(11, 0, -i*STEP_SERVOID_11+SERVOMAX_palm);
        i++;
    }
    // i=0;
    // while (i<180){
    //     pwm.setPWM(0, 0, SERVOMAX_thumb_B);
    //     pwm.setPWM(1, 0, SERVOMAX_index_B);
    //     pwm.setPWM(2, 0, SERVOMAX_middle_B);
    //     pwm.setPWM(3, 0, -i*STEP_SERVOID_3 + SERVOMAX_ring_B);
    //     pwm.setPWM(4, 0, -i*STEP_SERVOID_4 + SERVOMAX_pinky_B);
    //     pwm.setPWM(5, 0, -i*STEP_SERVOID_5 + SERVOMAX_thumb_A);
    //     pwm.setPWM(6, 0, -i*STEP_SERVOID_6 + SERVOMAX_index_A);
    //     pwm.setPWM(7, 0, -i*STEP_SERVOID_7 + SERVOMAX_middle_A);
    //     pwm.setPWM(8, 0, -i*STEP_SERVOID_8 + SERVOMAX_ring_A);
    //     pwm.setPWM(9, 0, -i*STEP_SERVOID_9 + SERVOMAX_pinky_A);        
    //     pwm.setPWM(11, 0, i*STEP_SERVOID_11+SERVOMIN_palm);
    //     i++;
    // }
}

/**
 * Index, thumb and palm fully extended, other 3 fingers closed
*/
void signLangL_array(){
    for (i = 0; i < 181; i++){
        for(servoid=0; servoid<11; servoid++){
            if(servoid == 0 || servoid == 1 || servoid == 5 || servoid == 6 || servoid == 11){pwm.setPWM(servoid, 0,pulselen_from_degrees[servoid][0]);}
            pwm.setPWM(servoid, 0, pulselen_from_degrees[servoid][i]); 
        }
    }

}

void signLangL(){
    uint8_t i=0;
    while (i<180){
        pwm.setPWM(0, 0, SERVOMIN_thumb_B);
        pwm.setPWM(1, 0, SERVOMIN_index_B);
        pwm.setPWM(2, 0, i*STEP_SERVOID_2 + SERVOMIN_middle_B);
        pwm.setPWM(3, 0, i*STEP_SERVOID_3 + SERVOMIN_ring_B);
        pwm.setPWM(4, 0, i*STEP_SERVOID_4 + SERVOMIN_pinky_B);
        pwm.setPWM(5, 0, i*STEP_SERVOID_5 + SERVOMIN_thumb_A);
        pwm.setPWM(6, 0, i*STEP_SERVOID_6 + SERVOMIN_index_A);
        pwm.setPWM(7, 0, i*STEP_SERVOID_7 + SERVOMIN_middle_A);
        pwm.setPWM(8, 0, i*STEP_SERVOID_8 + SERVOMIN_ring_A);
        pwm.setPWM(9, 0, i*STEP_SERVOID_9 + SERVOMIN_pinky_A);
        pwm.setPWM(11, 0, SERVOMAX_palm);
        i++;
    }
    // i=0;
    // while (i<180){
    //     pwm.setPWM(0, 0, SERVOMAX_thumb_B);
    //     pwm.setPWM(1, 0, SERVOMAX_index_B);
    //     pwm.setPWM(2, 0, -i*STEP_SERVOID_2 + SERVOMAX_middle_B);
    //     pwm.setPWM(3, 0, -i*STEP_SERVOID_3 + SERVOMAX_ring_B);
    //     pwm.setPWM(4, 0, -i*STEP_SERVOID_4 + SERVOMAX_pinky_B);
    //     pwm.setPWM(5, 0, -i*STEP_SERVOID_5 + SERVOMAX_thumb_A);
    //     pwm.setPWM(6, 0, -i*STEP_SERVOID_6 + SERVOMAX_index_A);
    //     pwm.setPWM(7, 0, -i*STEP_SERVOID_7 + SERVOMAX_middle_A);
    //     pwm.setPWM(8, 0, -i*STEP_SERVOID_8 + SERVOMAX_ring_A);
    //     pwm.setPWM(9, 0, -i*STEP_SERVOID_9 + SERVOMAX_pinky_A);        
    //     pwm.setPWM(11, 0, SERVOMIN_palm);
    //     i++;
    // }
}

/**
 * Outer servos fully closed; palm and thumb servos fully closed
*/
void signLangO_array(){
    for (i = 0; i < 181; i++){
        for(servoid=0; servoid<11; servoid++){
            if(servoid == 1 || servoid == 2 || servoid == 3 || servoid == 4){pwm.setPWM(servoid, 0,pulselen_from_degrees[servoid][0]);}
            pwm.setPWM(servoid, 0, pulselen_from_degrees[servoid][i]); 
        }
    }
}

void signLangO(){
uint8_t i=0;
    while (i<180){
        pwm.setPWM(0, 0, i*STEP_SERVOID_0 + SERVOMIN_thumb_B);
        pwm.setPWM(1, 0, SERVOMIN_index_B);
        pwm.setPWM(2, 0, SERVOMIN_middle_B);
        pwm.setPWM(3, 0, SERVOMIN_ring_B);
        pwm.setPWM(4, 0, SERVOMIN_pinky_B);
        pwm.setPWM(5, 0, i*STEP_SERVOID_5 + SERVOMIN_thumb_A);
        pwm.setPWM(6, 0, i*STEP_SERVOID_6 + SERVOMIN_index_A);
        pwm.setPWM(7, 0, i*STEP_SERVOID_7 + SERVOMIN_middle_A);
        pwm.setPWM(8, 0, i*STEP_SERVOID_8 + SERVOMIN_ring_A);
        pwm.setPWM(9, 0, i*STEP_SERVOID_9 + SERVOMIN_pinky_A);
        pwm.setPWM(11, 0, -i*STEP_SERVOID_11+SERVOMAX_palm);
        i++;
    }
    // i=0;
    // while (i<180){
    //     pwm.setPWM(0, 0, -i*STEP_SERVOID_0 + SERVOMAX_thumb_B);
    //     pwm.setPWM(1, 0, SERVOMAX_index_B);
    //     pwm.setPWM(2, 0, SERVOMAX_middle_B);
    //     pwm.setPWM(3, 0, SERVOMAX_ring_B);
    //     pwm.setPWM(4, 0, SERVOMAX_pinky_B);
    //     pwm.setPWM(5, 0, -i*STEP_SERVOID_5 + SERVOMAX_thumb_A);
    //     pwm.setPWM(6, 0, -i*STEP_SERVOID_6 + SERVOMAX_index_A);
    //     pwm.setPWM(7, 0, -i*STEP_SERVOID_7 + SERVOMAX_middle_A);
    //     pwm.setPWM(8, 0, -i*STEP_SERVOID_8 + SERVOMAX_ring_A);
    //     pwm.setPWM(9, 0, -i*STEP_SERVOID_9 + SERVOMAX_pinky_A);        
    //     pwm.setPWM(11, 0, i*STEP_SERVOID_11+SERVOMIN_palm);
    //     i++;
    // }
}

/**
 * Inner index servo closed, palm servo closed; every other servo closed
*/
void signLangQ_array(){
    for(servoid=0; servoid<11; servoid++){
        if(servoid == 6 || servoid == 0 || servoid == 5){pwm.setPWM(servoid, 0,pulselen_from_degrees[servoid][0]);}
        pwm.setPWM(servoid, 0, pulselen_from_degrees[servoid][i]); 
    }
}

void signLangQ(){
    uint8_t i=0;
    while (i<180){
        pwm.setPWM(0, 0, SERVOMIN_thumb_B);
        pwm.setPWM(1, 0, SERVOMIN_index_B);
        pwm.setPWM(2, 0, i*STEP_SERVOID_2 + SERVOMIN_middle_B);
        pwm.setPWM(3, 0, i*STEP_SERVOID_3 + SERVOMIN_ring_B);
        pwm.setPWM(4, 0, i*STEP_SERVOID_4 + SERVOMIN_pinky_B);
        pwm.setPWM(5, 0, SERVOMIN_thumb_A);
        pwm.setPWM(6, 0, i*STEP_SERVOID_6 + SERVOMIN_index_A);
        pwm.setPWM(7, 0, i*STEP_SERVOID_7 + SERVOMIN_middle_A);
        pwm.setPWM(8, 0, i*STEP_SERVOID_8 + SERVOMIN_ring_A);
        pwm.setPWM(9, 0, i*STEP_SERVOID_9 + SERVOMIN_pinky_A);
        pwm.setPWM(11, 0, -i*STEP_SERVOID_11+SERVOMAX_palm);
        i++;
    }
    // i=0;
    // while (i<180){
    //     pwm.setPWM(0, 0, SERVOMAX_thumb_B);
    //     pwm.setPWM(1, 0, SERVOMAX_index_B);
    //     pwm.setPWM(2, 0, -i*STEP_SERVOID_2 + SERVOMAX_middle_B);
    //     pwm.setPWM(3, 0, -i*STEP_SERVOID_3 + SERVOMAX_ring_B);
    //     pwm.setPWM(4, 0, -i*STEP_SERVOID_4 + SERVOMAX_pinky_B);
    //     pwm.setPWM(5, 0, SERVOMAX_thumb_A);
    //     pwm.setPWM(6, 0, -i*STEP_SERVOID_6 + SERVOMAX_index_A);
    //     pwm.setPWM(7, 0, -i*STEP_SERVOID_7 + SERVOMAX_middle_A);
    //     pwm.setPWM(8, 0, -i*STEP_SERVOID_8 + SERVOMAX_ring_A);
    //     pwm.setPWM(9, 0, -i*STEP_SERVOID_9 + SERVOMAX_pinky_A);        
    //     pwm.setPWM(11, 0, i*STEP_SERVOID_11+SERVOMIN_palm);
    //     i++;
    // }
}

/** Index and thumb fully extended; every other servo closed*/
void signLangU_array(){
    for (i = 0; i < 181; i++){
        for(servoid=0; servoid<11; servoid++){
            if(servoid == 0 || servoid == 1 || servoid == 5 || servoid == 6){pwm.setPWM(servoid, 0,pulselen_from_degrees[servoid][0]);}
            pwm.setPWM(servoid, 0, pulselen_from_degrees[servoid][i]); 
        }
    }
}

void signLangU(){
    uint8_t i=0;
    while (i<180){
        pwm.setPWM(0, 0, SERVOMIN_thumb_B);
        pwm.setPWM(1, 0, SERVOMIN_index_B);
        pwm.setPWM(2, 0, i*STEP_SERVOID_2 + SERVOMIN_middle_B);
        pwm.setPWM(3, 0, i*STEP_SERVOID_3 + SERVOMIN_ring_B);
        pwm.setPWM(4, 0, i*STEP_SERVOID_4 + SERVOMIN_pinky_B);
        pwm.setPWM(5, 0, SERVOMIN_thumb_A);
        pwm.setPWM(6, 0, SERVOMIN_index_A);
        pwm.setPWM(7, 0, i*STEP_SERVOID_7 + SERVOMIN_middle_A);
        pwm.setPWM(8, 0, i*STEP_SERVOID_8 + SERVOMIN_ring_A);
        pwm.setPWM(9, 0, i*STEP_SERVOID_9 + SERVOMIN_pinky_A);
        pwm.setPWM(11, 0, -i*STEP_SERVOID_11+SERVOMAX_palm);
        i++;
    }
    // i=0;
    // while (i<180){
    //     pwm.setPWM(0, 0, SERVOMAX_thumb_B);
    //     pwm.setPWM(1, 0, SERVOMAX_index_B);
    //     pwm.setPWM(2, 0, -i*STEP_SERVOID_2 + SERVOMAX_middle_B);
    //     pwm.setPWM(3, 0, -i*STEP_SERVOID_3 + SERVOMAX_ring_B);
    //     pwm.setPWM(4, 0, -i*STEP_SERVOID_4 + SERVOMAX_pinky_B);
    //     pwm.setPWM(5, 0, SERVOMAX_thumb_A);
    //     pwm.setPWM(6, 0, SERVOMAX_index_A);
    //     pwm.setPWM(7, 0, -i*STEP_SERVOID_7 + SERVOMAX_middle_A);
    //     pwm.setPWM(8, 0, -i*STEP_SERVOID_8 + SERVOMAX_ring_A);
    //     pwm.setPWM(9, 0, -i*STEP_SERVOID_9 + SERVOMAX_pinky_A);        
    //     pwm.setPWM(11, 0, i*STEP_SERVOID_11+SERVOMIN_palm);
    //     i++;
    // }

}

/**
 * Simbolo de la paz
*/
void signLangV_array(){
    for (i = 0; i < 181; i++){
        for(servoid=0; servoid<11; servoid++){
            if(servoid == 2 || servoid == 1 || servoid == 7 || servoid == 6){pwm.setPWM(servoid, 0,pulselen_from_degrees[servoid][0]);}
            pwm.setPWM(servoid, 0, pulselen_from_degrees[servoid][i]); 
        }
    }
}

void signLangV(){
    uint8_t i=0;
    while (i<180){
        pwm.setPWM(0, 0, i*STEP_SERVOID_0 + SERVOMIN_thumb_B);
        pwm.setPWM(1, 0, SERVOMIN_index_B);
        pwm.setPWM(2, 0, SERVOMIN_middle_B);
        pwm.setPWM(3, 0, i*STEP_SERVOID_3 + SERVOMIN_ring_B);
        pwm.setPWM(4, 0, i*STEP_SERVOID_4 + SERVOMIN_pinky_B);
        pwm.setPWM(5, 0, i*STEP_SERVOID_5 + SERVOMIN_thumb_A);
        pwm.setPWM(6, 0, SERVOMIN_index_A);
        pwm.setPWM(7, 0, SERVOMIN_middle_A);
        pwm.setPWM(8, 0, i*STEP_SERVOID_8 + SERVOMIN_ring_A);
        pwm.setPWM(9, 0, i*STEP_SERVOID_9 + SERVOMIN_pinky_A);
        pwm.setPWM(11, 0, -i*STEP_SERVOID_11+SERVOMAX_palm);
        i++;
    }
    // i=0;
    // while (i<180){
    //     pwm.setPWM(0, 0, -i*STEP_SERVOID_0 + SERVOMAX_thumb_B);
    //     pwm.SERVOMAX_index_B);
    //     pwm.SERVOMAX_middle_B);
    //     pwm.setPWM(3, 0, -i*STEP_SERVOID_3 + SERVOMAX_ring_B);
    //     pwm.setPWM(4, 0, -i*STEP_SERVOID_4 + SERVOMAX_pinky_B);
    //     pwm.setPWM(5, 0, -i*STEP_SERVOID_5 + SERVOMAX_thumb_A);
    //     pwm.SERVOMAX_index_A);
    //     pwm.SERVOMAX_middle_A);
    //     pwm.setPWM(8, 0, -i*STEP_SERVOID_8 + SERVOMAX_ring_A);
    //     pwm.setPWM(9, 0, -i*STEP_SERVOID_9 + SERVOMAX_pinky_A);        
    //     pwm.setPWM(11, 0, i*STEP_SERVOID_11+SERVOMIN_palm);
    //     i++;
    // }
}

/**
 * tres cervezas
*/
void signLangW_array(){
    for (i = 0; i < 181; i++){
        for(servoid=0; servoid<11; servoid++){
            if(servoid == 3 || servoid == 2 || servoid == 1 || servoid == 7 || servoid == 6 || servoid == 8){pwm.setPWM(servoid, 0,pulselen_from_degrees[servoid][0]);}
            pwm.setPWM(servoid, 0, pulselen_from_degrees[servoid][i]); 
        }
    }
}

void signLangW(){
    uint8_t i=0;
    while (i<180){
        pwm.setPWM(0, 0, i*STEP_SERVOID_0 + SERVOMIN_thumb_B);
        pwm.setPWM(1, 0, SERVOMIN_index_B);
        pwm.setPWM(2, 0, SERVOMIN_middle_B);
        pwm.setPWM(3, 0, SERVOMIN_ring_B);
        pwm.setPWM(4, 0, i*STEP_SERVOID_4 + SERVOMIN_pinky_B);
        pwm.setPWM(5, 0, i*STEP_SERVOID_5 + SERVOMIN_thumb_A);
        pwm.setPWM(6, 0, SERVOMIN_index_A);
        pwm.setPWM(7, 0, SERVOMIN_middle_A);
        pwm.setPWM(8, 0, SERVOMIN_ring_A);
        pwm.setPWM(9, 0, i*STEP_SERVOID_9 + SERVOMIN_pinky_A);
        pwm.setPWM(11, 0, -i*STEP_SERVOID_11+SERVOMAX_palm);
        i++;
    }
    // i=0;
    // while (i<180){
    //     pwm.setPWM(0, 0, -i*STEP_SERVOID_0 + SERVOMAX_thumb_B);
    //     pwm.setPWM(1, 0, SERVOMAX_index_B);
    //     pwm.setPWM(2, 0, SERVOMAX_middle_B);
    //     pwm.setPWM(3, 0, SERVOMAX_ring_B);
    //     pwm.setPWM(4, 0, -i*STEP_SERVOID_4 + SERVOMAX_pinky_B);
    //     pwm.setPWM(5, 0, -i*STEP_SERVOID_5 + SERVOMAX_thumb_A);
    //     pwm.setPWM(6, 0, SERVOMAX_index_A);
    //     pwm.setPWM(7, 0, SERVOMAX_middle_A);
    //     pwm.setPWM(8, 0, SERVOMAX_ring_A);
    //     pwm.setPWM(9, 0, -i*STEP_SERVOID_9 + SERVOMAX_pinky_A);        
    //     pwm.setPWM(11, 0, i*STEP_SERVOID_11+SERVOMIN_palm);
    //     i++;
    // }
}

/**
 * Surf emote
*/
void signLangY_array(){
    for (i = 0; i < 181; i++){
        for(servoid=0; servoid<11; servoid++){
            if(servoid == 0 || servoid == 5 || servoid == 4 || servoid == 9 || servoid == 11){pwm.setPWM(servoid, 0,pulselen_from_degrees[servoid][0]);}
            pwm.setPWM(servoid, 0, pulselen_from_degrees[servoid][i]); 
        }
    }
}

void signLangY(){
        uint8_t i=0;
    while (i<180){
        pwm.setPWM(0, 0, SERVOMIN_thumb_B);
        pwm.setPWM(1, 0, i*STEP_SERVOID_1 + SERVOMIN_index_B);
        pwm.setPWM(2, 0, i*STEP_SERVOID_2 + SERVOMIN_middle_B);
        pwm.setPWM(3, 0, i*STEP_SERVOID_3 + SERVOMIN_ring_B);
        pwm.setPWM(4, 0, SERVOMIN_pinky_B);
        pwm.setPWM(5, 0, SERVOMIN_thumb_A);
        pwm.setPWM(6, 0, i*STEP_SERVOID_6 + SERVOMIN_index_A);
        pwm.setPWM(7, 0, i*STEP_SERVOID_7 + SERVOMIN_middle_A);
        pwm.setPWM(8, 0, i*STEP_SERVOID_8 + SERVOMIN_ring_A);
        pwm.setPWM(9, 0, SERVOMIN_pinky_A);
        pwm.setPWM(11, 0, SERVOMAX_palm);
        i++;
    }
    // i=0;
    // while (i<180){
    //     pwm.setPWM(0, 0, SERVOMAX_thumb_B);
    //     pwm.setPWM(1, 0, -i*STEP_SERVOID_1 + SERVOMAX_index_B);
    //     pwm.setPWM(2, 0, -i*STEP_SERVOID_2 + SERVOMAX_middle_B);
    //     pwm.setPWM(3, 0, -i*STEP_SERVOID_3 + SERVOMAX_ring_B);
    //     pwm.setPWM(4, 0, SERVOMAX_pinky_B);
    //     pwm.setPWM(5, 0, SERVOMAX_thumb_A);
    //     pwm.setPWM(6, 0, -i*STEP_SERVOID_6 + SERVOMAX_index_A);
    //     pwm.setPWM(7, 0, -i*STEP_SERVOID_7 + SERVOMAX_middle_A);
    //     pwm.setPWM(8, 0, -i*STEP_SERVOID_8 + SERVOMAX_ring_A);
    //     pwm.setPWM(9, 0, SERVOMAX_pinky_A);        
    //     pwm.setPWM(11, 0, SERVOMIN_palm);
    //     i++;
    // }
}
