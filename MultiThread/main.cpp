#include "thread.hpp"
#include "worker.hpp"

int main()
{
    ThreadClass Thread;
    ThreadWorker do_work;

    Thread.Create("thread0", do_work.func0, 1);
    Thread.Create("thread1", do_work.func1, 1);
    Thread.Create("thread2", do_work.func2, 1);
    Thread.Create("thread3", do_work.func3, 1);

    Thread.Join();

    return 0;
}
