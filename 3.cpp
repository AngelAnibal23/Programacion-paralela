#include <iostream>
#include <thread>
using namespace std;

bool S1 = false;
bool S2 = false;

void P1() {
    while (true) {
        while (S2);
        S1 = true;
        cout << "Proceso 1 en su seccion critica" << endl;
        S1 = false;
    }
}

void P2() {
    while (true) {
        while (S1);
        S2 = true;
        cout << "Proceso 2 en su seccion critica" << endl;
        S2 = false;
    }
}

int main() {
    thread t1(P1);
    thread t2(P2);
    
    t1.join();
    t2.join();
    
    return 0;
}