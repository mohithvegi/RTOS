#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <pthread.h>
#include <time.h>
#include <sys/time.h>

pthread_cond_t cond1  = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond2  = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond3  = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond4  = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond5  = PTHREAD_COND_INITIALIZER;

pthread_mutex_t lock1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock2 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock3 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock4 = PTHREAD_MUTEX_INITIALIZER;

int TRUE = 0;
struct timeval start, stop;

void *player1(void *arg){
	// printf("Player1 turn.\n");
	while(1){
		static int move1 = 0;
		int dice;
		pthread_mutex_lock(&lock1);
		pthread_cond_wait(&cond1, &lock1);
		dice = rand() % 6 + 1;
		if(move1 < 100){
			move1 = move1 + dice;
		}
		if(move1 == 100){
			printf("Winner : Player1\n");
			gettimeofday(&stop, NULL);
			printf("%lu\n", (stop.tv_sec - start.tv_sec)*1000000 + (stop.tv_usec - start.tv_usec));
			// TRUE = 1;
			// pthread_exit(NULL);
			exit(0);
		}
		if(move1 > 100){
			move1 = move1 - dice;
		}
		pthread_cond_signal(&cond5);
		pthread_mutex_unlock(&lock1);
	}
}

void *player2(void *arg){
	// printf("Player2 turn.\n");
	while(1){
		static int move2 = 0;
		int dice;
		pthread_mutex_lock(&lock2);
		pthread_cond_wait(&cond2, &lock2);
		dice = rand() % 6 + 1;
		if(move2 < 100){
			move2 = move2 + dice;
		}
		if(move2 == 100){
			printf("Winner : Player2\n");
			gettimeofday(&stop, NULL);
			printf("%lu\n", (stop.tv_sec - start.tv_sec)*1000000 + (stop.tv_usec - start.tv_usec));
			// TRUE = 1;
			// pthread_exit(NULL);
			exit(0);
		}
		if(move2 > 100){
			move2 = move2 - dice;
		}
		pthread_cond_signal(&cond5);
		pthread_mutex_unlock(&lock2);
	}
}

void *player3(void *arg){
	// printf("Player3 turn.\n");
	while(1){
		static int move3 = 0;
		int dice;
		pthread_mutex_lock(&lock3);
		pthread_cond_wait(&cond3, &lock3);
		dice = rand() % 6 + 1;
		if(move3 < 100){
			move3 = move3 + dice;
		}
		if(move3 == 100){
			printf("Winner : Player3\n");
			gettimeofday(&stop, NULL);
			printf("%lu\n", (stop.tv_sec - start.tv_sec)*1000000 + (stop.tv_usec - start.tv_usec));
			// pthread_exit(NULL);
			// TRUE = 1;
			exit(0);
		}
		if(move3 > 100){
			move3 = move3 - dice;
		}
		pthread_cond_signal(&cond5);
		pthread_mutex_unlock(&lock3);
	}
}

void *player4(void *arg){
	// printf("Player4 turn.\n");
	while(1){
		static int move4 = 0;
		int dice;
		pthread_mutex_lock(&lock4);
		pthread_cond_wait(&cond4, &lock4);
		dice = rand() % 6 + 1;
		if(move4 < 100){
			move4 = move4 + dice;
		}
		if(move4 == 100){
			printf("Winner : Player4\n");
			gettimeofday(&stop, NULL);
			printf("%lu\n", (stop.tv_sec - start.tv_sec)*1000000 + (stop.tv_usec - start.tv_usec));
			// TRUE = 1;
			// pthread_exit(NULL);
			exit(0);
		}
		if(move4 > 100){
			move4 = move4 - dice;
		}
		pthread_cond_signal(&cond5);
		pthread_mutex_unlock(&lock4);
	}
}

int main(void){
	pthread_t tid1, tid2, tid3, tid4;
	srand(time(0));
	if( pthread_create(&tid1, NULL, player1, NULL) != 0 )
        printf("Failed to create thread1\n");

	if( pthread_create(&tid2, NULL, player2, NULL) != 0 )
        printf("Failed to create thread2\n");

	if( pthread_create(&tid3, NULL, player3, NULL) != 0 )
        printf("Failed to create thread3\n");

	if( pthread_create(&tid4, NULL, player4, NULL) != 0 )
        printf("Failed to create thread4\n");

    gettimeofday(&start, NULL);

    while(1){
    	pthread_cond_signal(&cond1);
    	pthread_mutex_unlock(&lock1);
    	pthread_mutex_lock(&lock1);
    	pthread_cond_wait(&cond5, &lock1);

    	pthread_cond_signal(&cond2);
    	pthread_mutex_unlock(&lock2);
    	pthread_mutex_lock(&lock2);
    	pthread_cond_wait(&cond5, &lock2);

    	pthread_cond_signal(&cond3);
    	pthread_mutex_unlock(&lock3);
    	pthread_mutex_lock(&lock3);
    	pthread_cond_wait(&cond5, &lock3);

    	pthread_cond_signal(&cond4);
    	pthread_mutex_unlock(&lock4);
    	pthread_mutex_lock(&lock4);
    	pthread_cond_wait(&cond5, &lock4);
    }

    return 0;
}
