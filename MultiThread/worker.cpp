#include "worker.hpp"

ThreadWorker::ThreadWorker()
{
}
ThreadWorker::~ThreadWorker()
{
}

void ThreadWorker::func0(std::mutex* mu)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
    while (1)
    {
        std::lock_guard<std::mutex> iolock(*mu);
        std::cout << "Thread #0" << ": on CPU " << sched_getcpu() << "\n";
    }
}

void ThreadWorker::func1(std::mutex* mu)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
    while (1)
    {
        std::lock_guard<std::mutex> iolock(*mu);
        std::cout << "Thread #1" << ": on CPU " << sched_getcpu() << "\n";
    }
}

void ThreadWorker::func2(std::mutex* mu)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
    while (1)
    {
        std::lock_guard<std::mutex> iolock(*mu);
        std::cout << "Thread #2" << ": on CPU " << sched_getcpu() << "\n";
    }
}

void ThreadWorker::func3(std::mutex* mu)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
    while (1)
    {
        std::lock_guard<std::mutex> iolock(*mu);
        std::cout << "Thread #3" << ": on CPU " << sched_getcpu() << "\n";
    }
}

