
#include <iostream>
using namespace std;


void removeS(char* cstring){
    char* temp = cstring;
    while(*cstring!='\0'){
        if(*cstring=='S' || *cstring=='s'){
            temp = cstring;
            while(*temp!='\0'){
                *temp = *(temp+1);
                temp++;
            }
            cstring--;
        }
        cstring++;
    }
}

int main()
{
    char msg[50] = "She'll be a massless princess.";
    removeS(msg);
    cout << msg;  // prints   he'll be a male prince.
}

