#include "thread.hpp"

ThreadClass::ThreadClass()
{
    this->threads.reserve(this->THREAD_NUM);
    this->num = 0;
}

ThreadClass::~ThreadClass()
{
}

int ThreadClass::Create(std::string name, void (*func)(std::mutex* mu), int num)
{
    const unsigned int numOfCpus = std::thread::hardware_concurrency();
    cpu_set_t   mask;
    int i;

    for ( i = this->num; i < (this->num + num) && (i < this->THREAD_NUM); i++) {
        this->threads[i] = std::thread(func, &this->mu);
        pthread_setname_np(this->threads[i].native_handle(), name.c_str());
        CPU_ZERO(&mask);
        CPU_SET(i % numOfCpus, &mask);
        const int rc0 = pthread_setaffinity_np(this->threads[i].native_handle(), sizeof(cpu_set_t), &mask);
        if (rc0 != 0) {
            std::cerr << "Set cpu affinity" << std::endl;
        }
    }
    if (this->num + num > this->THREAD_NUM) {
        std::cerr << (this->num + num + 1 - this->THREAD_NUM) << " threads are not created" << std::endl;
    }
    this->num = i;

    return i;
}

void ThreadClass::Join()
{
    if (this->num > 0) {
        for (int i = 0; i < num; i++) {
            this->threads[i].join();
        }
    }
    else {
        std::cerr << "Threads is nothing!!!" << std::endl;
    }
}

