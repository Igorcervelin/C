#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <pthread.h>
#include <semaphore.h>
double sum = 0;
int i, n;
sem_t mutex;
void *funcao(void *param );
void *funcao2(void *param );

	
int main(){

	pthread_t threads[2];
	sem_init(&mutex, 0,1);
	
	for (i = 1; i <= 1000; i++){
		sum = 0;
		pthread_create(&threads[0], NULL, funcao, (void *)0);
		pthread_create(&threads[1], NULL, funcao2, (void *)0);		
		
		pthread_join(threads[1], NULL); 
		pthread_join(threads[0], NULL); 
		
		printf("%lf\n",sum * 4);
	}
	return(0);
}
void *funcao(void *param ){
	 
	sem_wait (&mutex);
	for (n = 0; n <= i; n++)
	{
		sum = sum + pow(-1, (double)n) / (2 * n + 1);
		n++;
	}
	Sleep(30);
	sem_post (&mutex);
	pthread_exit(NULL);
}
void *funcao2(void *param ){
	 
	sem_wait (&mutex);
	for (n = 1; n <= i; n++)
	{
		sum = sum + pow(-1, (double)n) / (2 * n + 1);
		n++;
	}
	Sleep(30);
	sem_post (&mutex);
	pthread_exit(NULL);
}
