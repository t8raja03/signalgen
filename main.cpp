#include "mbed.h"
using namespace std;

#define PI 3.141592653589793238462
Serial pc(USBTX, USBRX, 115200);
AnalogOut dac(PA_4); //PA_4 alias A2
AnalogIn adc(A0);
Timer timer;
long unsigned int timestamp;
double f = 50;
double omega;
double u;
double T;

int main() {
	
    
    timer.start();
    timer.reset();

    while(true) {
        timestamp = timer.read_us();

		if ( 2000001 > timestamp && timestamp > 1000000 )
			f = 60;
		else if ( 3000001 > timestamp && timestamp > 2000000 )
			f = 70;
		else if ( 4000001 > timestamp && timestamp > 3000000 )
			f = 80;
		else if ( 5000001 > timestamp && timestamp > 4000000 )
			f = 90;
		else if ( 6000001 > timestamp && timestamp > 5000000 )
			f = 100;
		else if ( 7000001 > timestamp && timestamp > 6000000 )
			f = 110;
		else if ( 8000001 > timestamp && timestamp > 7000000 )
			f = 120;
		else if ( 9000001 > timestamp && timestamp > 8000000 )
			f = 130;
		else if ( 10000001 > timestamp && timestamp > 9000000 )
			f = 140;
		else if ( timestamp > 10000000 )
			f = 150;

		T = 1 / f;
		omega =  2 * PI / T;
        u = 32768*sin(timestamp*0.0000001*omega)+32767;
        dac.write_u16(u);
		// printf("%i ", timestamp);
        printf("%f\r\n", (float)3.3*adc.read());
    }
}

/*
#define SAMPLES_CNT 1000
#define PERIOD_CNT 33
#define PI 3.141592653589793238462
AnalogOut dac(PA_4); //PA_4 alias A2
AnalogIn adc(A0);
void calculate_sinewave(void); //sine generation function
uint16_t dac_buffer[SAMPLES_CNT];
float adc_buffer[SAMPLES_CNT];
int main()
{
 printf("Sine generation");
 calculate_sinewave();
 for (int i = 0; i < SAMPLES_CNT; i++)
 {
 dac.write_u16(dac_buffer[i]);
 adc_buffer[i]=(float)3.3*adc.read();
 wait_us(1000);
 }
 printf("ADC sampling done\n\r");
 for (int i = 0; i < SAMPLES_CNT; i++) printf("%f\n\r", adc_buffer[i]);

}
void calculate_sinewave(void) //sine generation
{
 for (int i = 0; i < SAMPLES_CNT; i++)
 {
 dac_buffer[i]=32768*cos(2*PI*i/PERIOD_CNT)+32767; //
 }
}
*/
