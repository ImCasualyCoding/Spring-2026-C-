#include <iostream>
#include <thread>
#include <mutex>
std::mutex mtx;
void print_task() {
std::lock_guard<std::mutex> lock(mtx);
std::cout << "Safe printing from a thread\n";
}
int main() {
std::thread t1(print_task);
std::thread t2(print_task);
t1.join();
t2.join();
}