/*
**Piezo speaker code is from http://hades.mech.northwestern.edu/index.php/Driving_a_piezo_speaker_with_a_PIC
**credit belongs to Lynch
**Implentation by Aaron Srivatava
**With help from Sam Ray
*/
/* Usage */
//setVolume(5);
//playSong(&sToHeaven[0], &sToHeavenLength[0], lz);
/* &[SongName],&[SongNameLength],length of array */

#define C 254
#define G 169
#define A 151
#define B 136
#define C1 127 
#define D1 113
#define E1 102
#define F1 95
#define G1 86
#define A1 76
#define B1 68
#define C2 63
#define D2 56
#define E2 50
#define F2 47
#define G2 41
#define A2 37
#define B2 33
#define C3 30


//the song1 is Twinkle Twinkle Little Star
//#define star 14
//int tTLS[star]={C2, C2, G2, G2, A2, A2, G2, F2, F2, E2, E2, D2, D2, C2};         //insert notes of song in array
//int tTLSLength[star]={1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2};                 //relative length of each note

//Stairway to Heaven 1/2 song
#define lz 16
int sToHeaven[lz]={A,C1,E1,A1,(B1),E1,C1,B1,(C2),E1,C1,C2,((F1-5)),D1,A,(F1-5)};
int sToHeavenLength[lz]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};



void setVolume(int vol) {
   setup_ccp1(CCP_PWM);                                              // PWM output on pin 17, RC2/CCP1 
   set_pwm1_duty(vol);                                            // the number changes the volume of the piezo speaker
}

void playSong (int *song, int *length, int x) {
   int i;
   for (i=0; i<x; i++) {                                        //play x notes inside song array
      setup_timer_2(T2_DIV_BY_16, song[i], 16);                 //set PWM frequency according to entries in song array
      delay_ms(400*length[i]);                                  //each note is played for 400ms*relative length
      setup_timer_2(T2_DIV_BY_16, 1, 16);                       //the PWM frequency set beyond audible range
                                                                //in order to create a short silence between notes
      delay_ms(5);                                              //the silence is played for 50 ms                  
   }
   delay_ms(500);
   set_pwm1_duty(0);
}
