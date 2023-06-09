#include <stdint.h>
#include "calibrationServos.h"
#include <stdio.h>
#include <unistd.h>


uint8_t servoid = 0;
uint8_t i = 0;
uint8_t j = 0;



int main(){
  FILE* fd=fopen("output.txt","w");
      //Cerrar mano quitando indice
  i=0;
  while (i<180){
    fprintf(fd,"0:%f\n", -i*STEP_SERVOID_0 + SERVOMAX_thumb_B);
    fprintf(fd,"1:%i\n",  SERVOMAX_index_B);
    fprintf(fd,"2:%f\n", -i*STEP_SERVOID_2 + SERVOMAX_middle_B);
    fprintf(fd,"3:%f\n", -i*STEP_SERVOID_3 + SERVOMAX_ring_B);
    fprintf(fd,"4:%f\n", -i*STEP_SERVOID_4 + SERVOMAX_pinky_B);
    fprintf(fd,"5:%f\n", -i*STEP_SERVOID_5 + SERVOMAX_thumb_A);
    fprintf(fd,"6:%i\n",  SERVOMAX_index_A);
    fprintf(fd,"7:%f\n", -i*STEP_SERVOID_7 + SERVOMAX_middle_A);
    fprintf(fd,"8:%f\n", -i*STEP_SERVOID_8 + SERVOMAX_ring_A);
    fprintf(fd,"9:%f\n", -i*STEP_SERVOID_9 + SERVOMAX_pinky_A);      
    fprintf(fd,"10:%f\n", i*STEP_SERVOID_11+ SERVOMIN_palm);
    usleep(1);
    i++;
  }

  //Bajar la mano (rotar la muñeca)
  j=0;
  while (j<180){
    fprintf(fd,"%f\n", j*STEP_SERVOID_15+SERVOMIN_wrist);
    j++;
    usleep(5);
  }

  sleep(1);
  //Subir la mano (rotar la muñeca)
  j=0;
  while (j<180){
    fprintf(fd,"%f\n", -j*STEP_SERVOID_15+SERVOMAX_wrist);
    j++;
    usleep(5);

  }
  fclose(fd);
}