#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;


long arr;

void *PrintHello(void *threadid) {
   long tid;
   tid = (long)threadid;
   arr=tid;
   pthread_exit(NULL);
}

int main () {
    int NUM_THREADS;
    cout<<"Enter the upper limit of range(0 - X): ";
    cin>>NUM_THREADS;

   pthread_t threads[NUM_THREADS];
   int rc;
   int i;

   for( i = 0; i < NUM_THREADS; i++) {
     // cout << "main() : creating thread, " << i << endl;
      rc = pthread_create(&threads[i], NULL, PrintHello, (void *)i);

      if (rc) {
         cout << "Error:unable to create thread," << rc << endl;
         exit(-1);
      }
   }
   cout<<arr;
   pthread_exit(NULL);



}
