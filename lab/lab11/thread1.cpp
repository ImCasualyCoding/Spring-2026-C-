#include <iostream>
#include <thread>
void task() {
std::cout << "Thread is running\n";
}
int main() {
std::thread t(task); // Launch a new thread
t.join(); // Wait for the thread to finish
return 0;
}