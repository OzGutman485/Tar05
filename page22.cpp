#include <iostream>
#include <thread>
#include <unistd.h>
#include <mutex>
using namespace std;
mutex mtx;
int counter;
void foo(int a)
{
    sleep(1);
    mtx.lock();
    counter += 1;
    cout << counter << endl;
    mtx.unlock();
}
int main()
{
    counter = 0;
    thread threads[20];
    for (int i = 0; i < 20; i++)
    {
        threads[i] = thread(foo, i);
    }
    for (int i = 0; i < 20; i++)
    {
        threads[i].join();
    }
}