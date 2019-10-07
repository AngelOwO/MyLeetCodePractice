#pragma once
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>

class Concurrent_basic{
private:
    int howManyTimes;
    std::mutex m;
    int counter;
    std::condition_variable cv;
public:
    Concurrent_basic(int n);
    void printHello();
    void printWorld();
};