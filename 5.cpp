#include <iostream>
#include <thread>
using namespace std;

int s1 = 0;
int s2 = 0;

void P1() {
    while (true) {
        s1 = 1;
        while (s2 == 1) {
            s1 = 0;
            s1 = 1;
        }
        cout << "***Seccion critica P1***" << endl;
        s1 = 0;
    }
}

void P2() {
    while (true) {
        s2 = 1;
        while (s1 == 1) {
            s2 = 0;
            s2 = 1;
        }
        cout << "....Seccion critica P2...." << endl;
        s2 = 0;
    }
}

int main() {
    thread t1(P1);
    thread t2(P2);
    
    t1.join();
    t2.join();
    
    return 0;
}