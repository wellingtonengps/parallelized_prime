
#include <iostream>
#include <iterator>
#include <list>
#include <thread>
#include <mutex>
#include "Parallelized.h"
#include "PrimeGenerator.h"


using namespace std;

std::mutex mtx;

class Task
{
    private:
        int index;
        int a;
        int b;
    public:
        Task(int index, int a, int b)
        {
            this->index = index;
            this->a = a;
            this->b = b;
        }

        void run()
        {
            mtx.lock();
            PrimeGenerator* prime = new PrimeGenerator();
            //cout << "Thread "<< index++ << ":\n";
            prime->Generator(a, b);
            delete prime;
            mtx.unlock();
        }

};

int Parallelized::Thread() {
    int threadCount = 10;
    list<thread*> threads;

    list<Task*> tasks;

    int a = 1, b = 1000000;
    int bit = b/threadCount;

    auto start = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);

    for(int i = 0; i < threadCount; i++)
    {
        Task* task = new Task(i, a, a+bit);
        thread* taskThread = new thread(&Task::run, task);

        tasks.push_back(task);
        threads.push_back(taskThread);
        a = bit;
    }

    for (list<thread*>::iterator it = threads.begin(); it != threads.end(); ++it)
    {
        (*it)->join();
        delete (*it);
    }

    for (list<Task*>::iterator it = tasks.begin(); it != tasks.end(); ++it)
    {
        delete (*it);
    }

    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Time: " << time_taken << "\nQuantidade de threads: " << threadCount;

    return 0;
}
