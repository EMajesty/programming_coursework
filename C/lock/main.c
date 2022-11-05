/******************************************************************************************
* Lassi Laitinen 1801311																  *
******************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define DATALEN 10

char buffer[DATALEN] = "DEFAULT";
int rd_count;
int wr_count;
int rd_loops;
int wr_loops;
int stop = 0;
pthread_t* rds;
pthread_t* wrs;

// conditional compilation flag MUTEX_IMPLEMENTATION
// if commented out --> reader_writer_version
#define MUTEX_IMPLEMENTATION

// declare global data buffer and other global variables if needed

#ifdef MUTEX_IMPLEMENTATION

// declare global mutexes
pthread_mutex_t rd_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t wr_mutex = PTHREAD_MUTEX_INITIALIZER;
int current_rd_count = 0;

// thread functions
void* reader(void* arg) {
	int id = arg;
	size_t i;
	for (i = 0; i < rd_loops; i++) {
		// reading finished
		usleep(rand() % 1000000);
		// prepare reading
		pthread_mutex_lock(&rd_mutex);		// lock reader lock
		current_rd_count++;					// incr reader count
		if (current_rd_count == 1)			// if the first reader:
			pthread_mutex_lock(&wr_mutex);	// lock writer lock
		pthread_mutex_unlock(&rd_mutex);	// release reader lock
		// start reading
		printf("reader #%d, data: %s\n", id, buffer);
		// prepare to finish reading
		pthread_mutex_lock(&rd_mutex);		// lock reader lock
		current_rd_count--;					// decr reader count
		if (current_rd_count == 0)
			pthread_mutex_unlock(&wr_mutex);// release writer lock
		pthread_mutex_unlock(&rd_mutex);	// release reader lock
	}
	pthread_exit(NULL);
}

void* writer(void* arg) {
	int id = arg;
	size_t i;
	for (i = 0; i < wr_loops; i++) {
		// writing finished
		usleep(rand() % 1000000);
		// prepare for write
		pthread_mutex_lock(&wr_mutex);		// lock writer lock
		buffer[i] = rand() % 100;
		printf("writer #%d, data: %s\n", id, buffer);
		// prepare to finish write
		pthread_mutex_unlock(&wr_mutex);	// unlock writer lock
	}
}

#else

// declare global reader_writer_locks

// thread functions

void* reader(void* arg) {
	int id = arg;
	for (;;) {
		pthread_rwlock_rdlock(&rwlock);		// lets acquire the lock for reading
		printf("\n#%dR:'%s' ", id, buffer);
		pthread_rwlock_unlock(&rwlock);		// finished reading so unlock
		if (stop) break;
		usleep(rand() % 1000000);
	}
	pthread_exit(NULL);
}

void* writer(void* arg) {
	int id = arg;
	for (;;) {
		pthread_rwlock_wrlock(&rwlock);		// lets acquire the lock for writing
		//data = rand()%100;
		int i;
		for (i = 0; i < DATALEN - 1; i++)
			data[i] = rand() % 26 + 97;		// 'a' .. 'z'
		//		data[i]=rand()%256;				// '\0'..255
		data[DATALEN - 1] = '\0';			// null char is number 0 or char '\0'
		printf("\n\t#%dW:'%s' ", id, buffer);
		pthread_rwlock_unlock(% rwlock);	// finished writing so unlock
		if (stop) break;
		usleep(rand() % 1000000 + 1000000);
	}
	pthread_exit(NULL);
}

#endif

int main(int argc, char* argv[]) {
	// create threads
	rds = malloc(sizeof(pthread_t) * rd_count);
	wrs = malloc(sizeof(pthread_t) * wr_count);
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	size_t i;
	for (i = 0; i < rd_count; i++)
		pthread_create(&rds[i], &attr, rds, (void*)(i + 1));
	for (i = 0; i < wr_count; i++)
		pthread_create(&wrs[i], &attr, wrs, (void*)(i + 1));
	// stop the threads
	char buf[256];
	printf("Press enter to stop\n");
	fgets(buf, 256, stdin);
	stop = 1;
	// join
	for (i = 0; i < rd_count; i++)
		pthread_join(rds[i], NULL);
	for (i = 0; i < wr_count; i++)
		pthread_join(wrs[i], NULL);

	// free the dynamic allocated contents
	free(rds);
	free(wrs);
	return(EXIT_SUCCESS);
}

// ----------------------------------------------------------------------------------------