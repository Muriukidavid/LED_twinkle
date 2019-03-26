/*
 * random.c
 *
 *  Created on: Feb 19, 2014
 *      Author: karibe
 */
extern uint32_t tym;
uint32_t rand_me(int min, int max){
	uint32_t taim;
	taim = tym;
	taim = taim & 0x000000ff;
	return taim = taim %max+min;
}


