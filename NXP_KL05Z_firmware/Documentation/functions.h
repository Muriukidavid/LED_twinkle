/*
 * functions.h
 *
 *  Created on: Feb 19, 2014
 *      Author: karibe
 */
#define interval 11000
#define dead_time 1000
extern uint32_t taim;
extern LDD_TDeviceData *BitsIO;
unsigned long PWM_counter = 0;

int offset = 0;
int step_size = 200;
unsigned long on_time = 0;
unsigned long cycle_start = 0;
char dir = 1;

int offset2 = 0;
int step_size2 = 200;
unsigned long on_time2 = 0;
unsigned long cycle_start2 = 0;
char dir2 = 1;

byte LED_tracker1 = 1;
byte LED_tracker2 = 1;



unsigned short lfsr = 0xACE1u;
unsigned bit;
unsigned random()
  {
    bit  = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5) ) & 1;
    return lfsr =  ((lfsr >> 1) | (bit << 15));
  }

unsigned random2(int a, int b){
      return random()%b+a;
  }

void setup() {
offset = random2(2500,7500);
offset2 = random2(2500,7500);
}


void LED_on(byte LED)
{
	Bits1_SetBit(BitsIO,LED);
}

void LED_off(byte LED)
{
	Bits1_ClrBit(BitsIO,LED);
}


void loop()
{
  PWM_counter = taim;

  if( (PWM_counter + offset - cycle_start) >= interval) {  // completed cycle, start over
    on_time += step_size*dir;
    cycle_start = PWM_counter;
    if (on_time >= (interval - dead_time) ) {
      dir *= -1;
      on_time = interval - dead_time;
    }
    else if (on_time <= 0) {
      on_time = 0;
      dir *= -1;
      LED_tracker1 = LED_tracker2;
      while (LED_tracker1 == LED_tracker2) LED_tracker1 = random2(1,10);
      offset2 = random2(0,4000);
    }
  }
  else if( (PWM_counter + offset - cycle_start) >= (dead_time + on_time) ) {  // time to switch LED off
    //digitalWrite(LED1, LOW);
    LED_off(LED_tracker1);
  }
  else if( (PWM_counter + offset - cycle_start) >= dead_time) {  // time to switch LED on
    //digitalWrite(LED1, HIGH);
    LED_on(LED_tracker1);
    LED_off(0);
  }

  if( (PWM_counter + offset2 - cycle_start2) >= interval) {  // completed cycle, start over
    on_time2 += step_size2*dir2;
    cycle_start2 = PWM_counter;
    if (on_time2 >= (interval - dead_time) ) {
      dir2 *= -1;
      on_time2 = interval - dead_time;
    }
    else if (on_time2 <= 0) {
      on_time2 = 0;
      dir2 *= -1;
      LED_tracker2 = LED_tracker1;
      while (LED_tracker2 == LED_tracker1) LED_tracker2 = random2(1,10);
      offset2 = random2(0,4000);
    }
  }
  else if( (PWM_counter + offset2 - cycle_start2) >= (dead_time + on_time2) ) {  // time to switch LED off
    //digitalWrite(LED1, LOW);
    LED_off(LED_tracker2);
  }
  else if( (PWM_counter + offset2 - cycle_start2) >= dead_time) {  // time to switch LED on
    //digitalWrite(LED1, HIGH);
    LED_on(LED_tracker2);
  }
}





