#include <pthread.h>
#include <iostream>
void* task(void*) {
std::cout << "Pthread is running\n";
return nullptr;
}
int main() {
pthread_t t;
pthread_create(&t, NULL, task, NULL);
pthread_join(t, NULL);
return 0;
}