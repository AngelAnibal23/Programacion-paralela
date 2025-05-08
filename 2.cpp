#include <iostream>
#include <thread>
using namespace std;

int turno = 1;

void P1() {
    while (true) {
        while (turno == 2);
        cout << "Process 1 en su Seccion Critica" << endl;
        turno = 2;
    }
}

void P2() {
    while (true) {
        while (turno == 1);
        cout << "Process 2 en su Seccion Critica" << endl;
        turno = 1;
    }
}

int main() {
    thread t1(P1);
    thread t2(P2);
    
    t1.join();
    t2.join();
    
    return 0;
}