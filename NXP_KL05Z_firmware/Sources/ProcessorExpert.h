/*
 * ProcessorExpert.h
 *
 *  Created on: Feb 20, 2014
 *      Author: simlab
 */

#ifndef PROCESSOREXPERT_H_
#define PROCESSOREXPERT_H_
volatile uint16_t randnum=0;
int RANDMAX = 64, limit;
volatile uint8_t state[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
volatile uint8_t duty[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //keeps the duty cycle of every LED: 0 - never on, 64 - all on
volatile int myrun;
volatile uint8_t thestate = 0;
volatile char increment=0;
volatile uint8_t la_row;
LDD_TDeviceData *bitsIO;
//pin masks
static const uint32_t Bits_MASK_MAP[11U] = {
   0x01U, 0x02U, 0x04U, 0x08U, 0x10U, 0x20U, 0x40U, 0x80U, 0x0100U, 0x0200U, 0x0400U
};
//convert LED index to pin mask index, LED pairs share drive lines
static const char position[20] = {
	1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10
};

void myrandom(){
	randnum = (uint16_t)((SYST_CVR&0x000000ff)%64+1);
}

uint16_t myabs(uint16_t x){
	return (x ^ (x >> 31)) - (x >> 31);
}

void all_led_off(){
	Bits1_PutVal(bitsIO,0x00);
}

void all_led_on(){
	Bits1_PutVal(bitsIO,0x7fe);
	Bits1_PutVal(bitsIO,0x01);
}
char decode_pin(int index){
	return position[index];
}
void led_on(int index){
	int pin = decode_pin(index);
	if(index%2==0){//index is even
		Bits1_ClrBit(bitsIO,0);
		Bits1_PutVal(bitsIO,Bits_MASK_MAP[pin]);
	}else{
		Bits1_SetBit(bitsIO,0);
		Bits1_PutVal(bitsIO,~Bits_MASK_MAP[pin]);
	}
}

void set_all_duty(uint8_t theduty){
	int x=0;
	for(x=0;x<20;x++){
		duty[x] = theduty;
	}
}

void delay(int mils){
	WAIT1_Waitms(mils);
}

void go_round_once(){
	int i;
   for(i=0;i<20;i++){
	   led_on(i);
	   delay(400);
   }
}

#endif /* PROCESSOREXPERT_H_ */
