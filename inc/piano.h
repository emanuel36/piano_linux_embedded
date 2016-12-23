//FREQUENCIAS
#define FREQUENCIA_DO 30000
#define FREQUENCIA_RE 10000
//INPUT
#define PLAY 26
#define DO 68	
#define RE 44
//OUTPUT
#define LED_DO 69
#define LED_RE 45
#define BUZZER 23
#define LED_RECORD 46

typedef struct lista Lista;

struct lista{
	unsigned int nota;
	unsigned int led;
	long int time;
	Lista* next;
};

Lista* insert(Lista* l, unsigned int nota, unsigned int led, long int time);
Lista* invert(Lista *l);
void* led_record();
int play_nota(unsigned int nota);