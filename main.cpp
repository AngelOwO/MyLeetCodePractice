#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_map>

#include "header/Concurrent_basic.h"

void printFunc(Concurrent_basic &co,const char *t_Name);

void reverseString(std::string &s);

template <typename T,std::size_t size>
void bubbleSort(T (&n)[size]);          // (&n) means pass by referense.


int main(){

    // reverse string
    std::string s = "apple";
    reverseString(s);
    std::cout<<s<<std::endl;

    // bubble sort
    int n[10] = {2,9,8,10,436,3214,89,354,687,453};
    //int n[5] = {0};
    //for(int i=0;i<sizeof(n)/sizeof(n[0]);i++){
    //    std::cin>>n[i];
    //}

    bubbleSort<int,sizeof(n)/sizeof(n[0])> (n);
    for(auto x:n) std::cout<<x<<std::endl;

    // concurrent_basic
    Concurrent_basic c1(2);

    std::thread worker_1(printFunc,std::ref(c1),"worker_1");

    std::cout<<"main: "<<std::endl;
    c1.printWorld();
    worker_1.join();

    return 0;
}

void reverseString(std::string &s){
    for(int i =s.length()-1,j=0;i>s.length()/2;i--,j++){
        s[i] ^= s[j];
        s[j] ^= s[i];
        s[i] ^= s[j];
    }
}

template <typename T,std::size_t size>
void bubbleSort(T (&n)[size]){
    static_assert(std::is_same<T, int>::value || std::is_same<T, char>::value,"type not allow.");

    for(int i = 0;i<sizeof(n)/sizeof(n[0]);i++){
        for (int j = i;j<sizeof(n)/sizeof(n[0]);j++){
            if(n[i]>n[j]){
                n[i] ^= n[j];
                n[j] ^= n[i];
                n[i] ^= n[j];
            }
        }
    }
}

void printFunc(Concurrent_basic &co,const char *t_Name){
    std::cout<<t_Name<<" : "<<std::endl;
    co.printHello();
    //co.printWorld();
}

bool containsDuplicate(std::vector<int>& nums) {
    std::unordered_map<int,int>um;
    
    for(auto x:nums){
        if(um.find(x)==um.end()){   // nothing found.
            um.insert({x,x});
        }else return true;
    }
    return false;
}