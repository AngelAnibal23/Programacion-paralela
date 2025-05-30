#include <iostream>
#include <thread>
using namespace std;

int s1 = 0;
int s2 = 0;

void P1() {
    while (true) {
        s1 = 1;
        while (s2 == 1);
        cout << "Proceso 1 esta en su seccion critica" << endl;
        s1 = 0;
    }
}

void P2() {
    while (true) {
        s2 = 1;
        while (s1 == 1);
        cout << "Proceso 2 esta en su seccion critica" << endl;
        s2 = 0;
    }
}

int main() {
    s1 = 0;
    s2 = 0;
    
    thread t1(P1);
    thread t2(P2);
    
    t1.join();
    t2.join();
    
    return 0;
}