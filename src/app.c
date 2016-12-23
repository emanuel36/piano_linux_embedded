#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include "functions.h"
#include "piano.h"

int main(){
	init_gpio(PLAY, INPUT);
	init_gpio(DO, INPUT);
	init_gpio(RE, INPUT);
	init_gpio(LED_DO, OUTPUT);
	init_gpio(LED_RE, OUTPUT);
	init_gpio(BUZZER, OUTPUT);
	init_gpio(LED_RECORD, OUTPUT);

	Lista* notas = NULL;
	pthread_t led;
	long int time;
	RECORD:
	pthread_create(&led, NULL, *led_record, NULL);
	while(get_value(PLAY) != 1){
		if(get_value(DO)){
			time = 0;
			set_gpio_high(LED_DO);
			while(get_value(DO)){
				play_nota(FREQUENCIA_DO);
				time++;
			}
			set_gpio_low(LED_DO);
			notas = insert(notas, FREQUENCIA_DO, LED_DO, time);
		}
		if(get_value(RE)){
			time = 0;
			set_gpio_high(LED_RE);
			while(get_value(RE)){
				play_nota(FREQUENCIA_RE);
				time++;
			}
			set_gpio_low(LED_RE);
			notas = insert(notas, FREQUENCIA_RE, LED_RE, time);
		}	
	}
	pthread_cancel(led);
	set_gpio_low(LED_RECORD);
	
	notas = invert(notas);
	Lista* aux;
	while(notas != NULL){
		aux = notas;
		set_gpio_high(notas->led);
		while(notas->time){
			play_nota(notas->nota);
			notas->time--;
		}
		set_gpio_low(notas->led);
		notas = notas->next;
		free(aux);
		usleep(300000);
	}
	goto RECORD;
}