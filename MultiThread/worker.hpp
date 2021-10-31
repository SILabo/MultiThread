#include <cstdint>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include "pthread.h"

class ThreadWorker
{
public:
    ThreadWorker();
    ~ThreadWorker();

    static void func0(std::mutex* mu);
    static void func1(std::mutex* mu);
    static void func2(std::mutex* mu);
    static void func3(std::mutex* mu);

};

