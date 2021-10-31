#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include "pthread.h"

class ThreadClass
{
public:
    ThreadClass();
    ~ThreadClass();
    int Create(std::string name, void (*func)(std::mutex* mu), int num);
    void Join();

    enum NMAX {
        THREAD_NUM = 32
    };

private:
    std::vector<std::thread> threads;
    std::mutex mu;
    int num;
};
