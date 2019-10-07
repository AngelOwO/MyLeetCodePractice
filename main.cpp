#include <iostream>
#include <cstring>

void reverseString(std::string &s);
void bubbleSort();



int main(){

    std::string s = "apple";

    for(int i =s.length()-1,j=0;i>s.length()/2;i--,j++){
        s[i] ^= s[j];
        s[j] ^= s[i];
        s[i] ^= s[j];
    }

    std::cout<<s<<std::endl;

    return 0;
}

void reverseString(std::string &s){
    for(int i =s.length()-1,j=0;i>s.length()/2;i--,j++){
        s[i] ^= s[j];
        s[j] ^= s[i];
        s[i] ^= s[j];
    }
}