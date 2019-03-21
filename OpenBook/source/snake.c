#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/time.h>

// Declaration of thread condition variables.
pthread_cond_t cond1  = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond2  = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond3  = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond4  = PTHREAD_COND_INITIALIZER;

// mutex which we are going to use avoid race condition.
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

// done is a global variable which decide which waiting thread should be scheduled.
int done = 1;

struct timeval start, stop;

// Thread function - 1
void * player1(void *n){
	while(1){
		static int move = 0;
		static int state = 0;

		// acquire a lock.
		pthread_mutex_lock(&lock);

        if (done != (int)*(int*)n) {
                // value of done and n is not equal, hold wait lock on condition varible
            if ((int)*(int*)n == 1) {
                pthread_cond_wait(&cond1, &lock);
            }
            else if ((int)*(int*)n == 2) {
                pthread_cond_wait(&cond2, &lock);
            }
            else if ((int)*(int*)n == 3) {
                pthread_cond_wait(&cond3, &lock);
            }
            else {
                pthread_cond_wait(&cond4, &lock);
            }
        }

		int dice;
		dice = rand() % 6 + 1;
		if(move<100){
			move = move + dice;
		}

		if(move==100){
			printf("player1 wins\n");
			gettimeofday(&stop, NULL);
			printf("%lu\n", (stop.tv_sec - start.tv_sec)*1000000 + (stop.tv_usec - start.tv_usec));
			exit(0);
		}

		if(move>100){
            move = move - dice;
		}

		// Now time to schedule next thread accordingly using pthread_cond_signal().
		if (done == 4) {
            done = 1;
            pthread_cond_signal(&cond1);
        }
        else if(done == 1) {
            done = 2;
            pthread_cond_signal(&cond2);
        }
        else if (done == 2) {
            done = 3;
            pthread_cond_signal(&cond3);
        }
        else if (done == 3) {
            done = 4;
            pthread_cond_signal(&cond4);
        }

        // Finally release mutex
        pthread_mutex_unlock(&lock);

	}

	return NULL;
}


// Thread function - 2
void * player2(void *n){
	while(1){
		static int move = 0;
		static int state = 0;

		pthread_mutex_lock(&lock);

        if (done != (int)*(int*)n) {
                // value of done and n is not equal, hold wait lock on condition varible
            if ((int)*(int*)n == 1) {
                pthread_cond_wait(&cond1, &lock);
            }
            else if ((int)*(int*)n == 2) {
                pthread_cond_wait(&cond2, &lock);
            }
            else if ((int)*(int*)n == 3) {
                pthread_cond_wait(&cond3, &lock);
            }
            else {
                pthread_cond_wait(&cond4, &lock);
            }
        }

		int dice;
		dice = rand() % 6 + 1;
		if(move<100){
			move = move + dice;
		}

		if(move==100){
			printf("player2 wins\n");
			gettimeofday(&stop, NULL);
			printf("%lu\n", (stop.tv_sec - start.tv_sec)*1000000 + (stop.tv_usec - start.tv_usec));
			exit(0);
		}

		if(move>100){
            move = move - dice;
		}

		if (done == 4) {
            done = 1;
            pthread_cond_signal(&cond1);
        }
        else if(done == 1) {
            done = 2;
            pthread_cond_signal(&cond2);
        }
        else if (done == 2) {
            done = 3;
            pthread_cond_signal(&cond3);
        }
        else if (done == 3) {
            done = 4;
            pthread_cond_signal(&cond4);
        }

        // Finally release mutex
        pthread_mutex_unlock(&lock);

	}

	return NULL;
}


// Thread function - 3
void * player3(void *n){
	while(1){
		static int move = 0;
		static int state = 0;

		pthread_mutex_lock(&lock);

        if (done != (int)*(int*)n) {
                // value of done and n is not equal, hold wait lock on condition varible
            if ((int)*(int*)n == 1) {
                pthread_cond_wait(&cond1, &lock);
            }
            else if ((int)*(int*)n == 2) {
                pthread_cond_wait(&cond2, &lock);
            }
            else if ((int)*(int*)n == 3) {
                pthread_cond_wait(&cond3, &lock);
            }
            else {
                pthread_cond_wait(&cond4, &lock);
            }
        }

		int dice;
		dice = rand() % 6 + 1;
		if(move<100){
			move = move + dice;
		}

		if(move==100){
			printf("player3 wins\n");
			gettimeofday(&stop, NULL);
			printf("%lu\n", (stop.tv_sec - start.tv_sec)*1000000 + (stop.tv_usec - start.tv_usec));
			exit(0);
		}

		if(move>100){
            move = move - dice;
		}

		if (done == 4) {
            done = 1;
            pthread_cond_signal(&cond1);
        }
        else if(done == 1) {
            done = 2;
            pthread_cond_signal(&cond2);
        }
        else if (done == 2) {
            done = 3;
            pthread_cond_signal(&cond3);
        }
        else if (done == 3) {
            done = 4;
            pthread_cond_signal(&cond4);
        }

        // Finally release mutex
        pthread_mutex_unlock(&lock);

	}

	return NULL;
}


// Thread function - 4
void * player4(void *n){
	while(1){
		static int move = 0;
		static int state = 0;

		pthread_mutex_lock(&lock);

        if (done != (int)*(int*)n) {
                // value of done and n is not equal, hold wait lock on condition varible
            if ((int)*(int*)n == 1) {
                pthread_cond_wait(&cond1, &lock);
            }
            else if ((int)*(int*)n == 2) {
                pthread_cond_wait(&cond2, &lock);
            }
            else if ((int)*(int*)n == 3) {
                pthread_cond_wait(&cond3, &lock);
            }
            else {
                pthread_cond_wait(&cond4, &lock);
            }
        }

		int dice;
		dice = rand() % 6 + 1;
		if(move<100){
			move = move + dice;
		}

		if(move==100){
			printf("player4 wins\n");
			gettimeofday(&stop, NULL);
			printf("%lu\n", (stop.tv_sec - start.tv_sec)*1000000 + (stop.tv_usec - start.tv_usec));
			exit(0);
		}

		if(move>100){
            move = move - dice;
		}

		if(done == 4) {
            done = 1;
            pthread_cond_signal(&cond1);
        }
        else if(done == 1) {
            done = 2;
            pthread_cond_signal(&cond2);
        }
        else if (done == 2) {
            done = 3;
            pthread_cond_signal(&cond3);
        }
        else if (done == 3) {
            done = 4;
            pthread_cond_signal(&cond4);
        }

        // Finally release mutex
        pthread_mutex_unlock(&lock);

	}

	return NULL;
}

int main(){
    //struct timeval start, stop;
	pthread_t  tid1, tid2, tid3, tid4;
    int n1 = 1, n2 = 2, n3 = 3, n4 = 4;
    srand(time(0));
    pthread_create(&tid1, NULL, player1, (void *)&n1);
    pthread_create(&tid2, NULL, player2, (void *)&n2);
    pthread_create(&tid3, NULL, player3, (void *)&n3);
    pthread_create(&tid4, NULL, player4, (void *)&n4);
    gettimeofday(&start, NULL);

    // infinite loop to avoid exit of a program/process
    while(1);

    return 0;
}
