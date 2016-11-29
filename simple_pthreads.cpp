#include <iostream>
#include <cstdlib>
#include <pthread.h>
using namespace std;


const int NUM_THREADS = 5;

void *PrintHello(void *threadid) {
	long tid;
	tid = (long)threadid;
	cout << "Hello thread id: " << tid << endl;
	pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
	pthread_t threads[NUM_THREADS];
	int rc, i;
	for(i=0; i< NUM_THREADS; i++) {
		cout << "main(): creating thread" << i << endl;
		rc = pthread_create(&threads[i], NULL, PrintHello, (void*)i);
		if (rc) {
			cout << "Unable to create thread" << endl;
			exit(-1);
		}
	}

	// TODO: FIX THIS... IT DOES NOT WORK


	pthread_exit(NULL);
	return 0;
}
