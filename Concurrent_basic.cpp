#include <iostream>

#include "header/Concurrent_basic.h"


Concurrent_basic::Concurrent_basic(int n){
    counter = 0;
    this->howManyTimes = n;
}

void Concurrent_basic::printHello(){
    std::unique_lock<std::mutex> u(m);
    for(int i=0;i<howManyTimes;i++){
        if(counter%2 != 0) {
            std::cout<<"-- Hello Waiting..."<<std::endl;
            cv.wait(u);
        }
        if(counter >= 100) counter = 0;

        std::cout<<"Hello "<<std::endl;
        counter++;
        cv.notify_all();
    }
}

void Concurrent_basic::printWorld(){
    std::unique_lock<std::mutex> u(m);
    for(int i=0;i<howManyTimes;i++){
        if(counter%2 != 1) {
            std::cout<<"-- World Waiting..."<<std::endl;
            cv.wait(u);
        }

        std::cout<<"World! "<<std::endl;
        counter++;
        cv.notify_all();
    }
}