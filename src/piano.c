#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include "piano.h"
#include "functions.h"

Lista* insert(Lista* l, unsigned int nota, unsigned int led, long int time){
	Lista* new_nota = malloc(sizeof(Lista));
	new_nota->nota = nota;
	new_nota->led = led;
	new_nota->next = l;
	new_nota->time = time;
	return new_nota;
}

Lista* invert(Lista *l){
	Lista* new_list = NULL;
	while(l != NULL){
		new_list = insert(new_list, l->nota, l->led, l->time);
		l = l->next;
	}
	return new_list;
}

void* led_record(){
	while(1){
		blink(LED_RECORD);
	}
}

int play_nota(unsigned int nota){
	set_gpio_high(BUZZER);
	usleep(nota);
	set_gpio_low(BUZZER);
	usleep(nota);
}