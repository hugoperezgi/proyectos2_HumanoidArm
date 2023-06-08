#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>


#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates


Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(); 

/**
 * 
 *  USMAX//SERVOMAX- maximum extension possible for the servo AKA open hand
 *  USMIN//SERVOMIN- minimum extension possible for the servo AKA closed hand
 *  
 *  _A- outer servo of the given finger
 *  _B- inner servo of the given finger 
 * 
**/

/**               ¬TODO
 *  Ajustar dedos para q se abran hasta la misma posicion aprox.
*/

//Thumb servos
// #define USMIN_thumb_A  1650 // thumb outer servo min        RED1      id5
// #define USMAX_thumb_A  2400 // thumb outer servo max        RED1      id5
// #define USMIN_thumb_B  600 // thumb inner servo min         RED2      id0
// #define USMAX_thumb_B  1850 // thumb inner servo max        RED2      id0

#define SERVOMIN_thumb_A  337 // thumb outer servo min         RED1      id5
#define SERVOMAX_thumb_A  490 // thumb outer servo max         RED1      id5
#define SERVOMIN_thumb_B  122 // thumb inner servo min         RED2      id0  122
#define SERVOMAX_thumb_B  378 // thumb inner servo max         RED2      id0

//Index finger servos
// #define USMIN_index_A  600 // index outer servo min         YELLOW1   id6
// #define USMAX_index_A  2000 // index outer servo max        YELLOW1   id6
// #define USMIN_index_B  1350 // index inner servo min        YELLOW2   id1
// #define USMAX_index_B  2460 // index inner servo max        YELLOW2   id1

#define SERVOMIN_index_A  122 // index outer servo min         YELLOW1   id6  122
#define SERVOMAX_index_A  409 // index outer servo max         YELLOW1   id6
#define SERVOMIN_index_B  276 // index inner servo min         YELLOW2   id1
#define SERVOMAX_index_B  503 // index inner servo max         YELLOW2   id1

//Middle finger servos
// #define USMIN_middle_A  600 // middle outer servo min       BLUE1     id7
// #define USMAX_middle_A  2400 // middle outer servo max      BLUE1     id7
// #define USMIN_middle_B  800 // middle inner servo min       BLUE2     id2
// #define USMAX_middle_B  1700 // middle inner servo max      BLUE2     id2

#define SERVOMIN_middle_A  122 // middle outer servo min       BLUE1     id7  122
#define SERVOMAX_middle_A  490 // middle outer servo max       BLUE1     id7
#define SERVOMIN_middle_B  163 // middle inner servo min       BLUE2     id2
#define SERVOMAX_middle_B  347 // middle inner servo max       BLUE2     id2

//Ring finger servos
// #define USMIN_ring_A  600 // ring outer servo min           GREEN1    id8
// #define USMAX_ring_A  2050 // ring outer servo max          GREEN1    id8
// #define USMIN_ring_B  1200 // ring inner servo min          GREEN2    id3
// #define USMAX_ring_B  2050  // ring inner servo max         GREEN2    id3

#define SERVOMIN_ring_A  122 // ring outer servo min           GREEN1    id8  122
#define SERVOMAX_ring_A  419 // ring outer servo max           GREEN1    id8
#define SERVOMIN_ring_B  245 // ring inner servo min           GREEN2    id3
#define SERVOMAX_ring_B  419  // ring inner servo max          GREEN2    id3

//Pinky finger servos
// #define USMIN_pinky_A  600 // pinky outer servo min         GRAY1     id9
// #define USMAX_pinky_A  1950 // pinky outer servo max        GRAY1     id9
// #define USMIN_pinky_B  600 // pinky inner servo min         GRAY2     id4
// #define USMAX_pinky_B  1500 // pinky inner servo max        GRAY2     id4

#define SERVOMIN_pinky_A  122 // pinky outer servo min         GRAY1     id9  122
#define SERVOMAX_pinky_A  398 // pinky outer servo max         GRAY1     id9
#define SERVOMIN_pinky_B  122 // pinky inner servo min         GRAY2     id4  122
#define SERVOMAX_pinky_B  306 // pinky inner servo max         GRAY2     id4


#define THUMB_USMAX 800 //thumb hacia fuera
#define THUMB_USMIN 300  //thumb hacia dentro

#define USMAX_WRIST 2200 //Muñeca min extension/hacia antebrazo (MANO HACIA ABAJO, PLEGADA, WHATEVER)
#define USMIN_WRIST 1000 //Muñeca max extension/hacia fuera (MANO HACIA EL EXTERIOR)

#define USMAX_ANTEBRAZO 2350 //antebrazo SENTIDO HORARIO MAX
#define USMIN_ANTEBRAZO 1400 // SENTIDO ANTI-HORARIO MAX

#define BICEPS_USMAX 1650 //BRAZO CONTRAIDO - Puede subir un poco más, pero al igual q min, no puede bajar :)
#define BICEPS_USMIN 1100  //bRAZO EXTENDIDO - No puede subir si baja mas q esto, por rango si q podría

#define SHOULDER_USMAX 2000 //HOMBRO HACIA "DENTRO"
#define sHOULDER_USMIN 1200  //hOMBRO HACIA "FUERA"

uint8_t servoid = 0;
uint8_t i = 0;

/**
 * SERVOMIN_ values corresponding to the servoid given:
 * 
 * SERVOMINS_Fingers[servoid] = SERVOMIN_finger_X
 * 
 * Inner servos:
 * thumb_B == servoid=0; index_B == servoid=1; middle_B == servoid=2; ring_B == servoid=3; pinky_B == servoid=4
 * 
 * Outer servos:
 * thumb_A == servoid=5; index_A == servoid=6; middle_A == servoid=7; ring_A == servoid=8; pinky_A == servoid=9
 * 
*/
uint16_t SERVOMINS_Fingers[10] = {SERVOMIN_thumb_B, SERVOMIN_index_B, SERVOMIN_middle_B, SERVOMIN_ring_B, SERVOMIN_pinky_B, SERVOMIN_thumb_A, SERVOMIN_index_A, SERVOMIN_middle_A, SERVOMIN_ring_A, SERVOMIN_pinky_A};

/**
 * SERVOMAX_ values corresponding to the servoid given:
 * 
 * SERVOMAXS_Fingers[servoid] = SERVOMAX_finger_X
 * 
 * Inner servos:
 * thumb_B == servoid=0; index_B == servoid=1; middle_B == servoid=2; ring_B == servoid=3; pinky_B == servoid=4
 * 
 * Outer servos:
 * thumb_A == servoid=5; index_A == servoid=6; middle_A == servoid=7; ring_A == servoid=8; pinky_A == servoid=9
 * 
*/
uint16_t SERVOMAXS_Fingers[10] = {SERVOMAX_thumb_B, SERVOMAX_index_B, SERVOMAX_middle_B, SERVOMAX_ring_B, SERVOMAX_pinky_B, SERVOMAX_thumb_A, SERVOMAX_index_A, SERVOMAX_middle_A, SERVOMAX_ring_A, SERVOMAX_pinky_A};

/**
 * Returns the pulselen needed to turn a servo into X degree position
 * 
 *  pulselen_from_degrees[servoid][degrees]
 * 
*/
uint16_t pulselen_from_degrees[10][181];

void setup() {
  Serial.begin(9600);
  Serial.println("Hand servos range");

  pwm.begin();

  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ); 

  for (i = 0; i < 181; i++){
    for(servoid=0; servoid<10; servoid++){
      pulselen_from_degrees[servoid][i] = map(i,0,180,SERVOMINS_Fingers[servoid],SERVOMAXS_Fingers[servoid]);
    }
  }

  delay(10);

}

void loop() {

  for (i = 0; i < 181; i++){
    for(servoid=0; servoid<10; servoid++){
      pwm.setPWM(servoid, 0, pulselen_from_degrees[servoid][i]); 
    }
  }
  
  delay(250);

  for (i = 180; i < 181; i--){  //tl;dr: Overflow causes it to jump from 0 to 255 so no bueno if using i<=0
    for(servoid=0; servoid<10; servoid++){
      pwm.setPWM(servoid, 0, pulselen_from_degrees[servoid][i]);
      
    }
  }
    

}


