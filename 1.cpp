#include <iostream>
#include <thread>
using namespace std;

int estado = 1; // 0=ocupado, 1=libre

void P1() {
    while (true) {
        while (estado == 0);
        estado = 0;
        cout << "Proceso 1 esta en su sección critica" << endl;
        estado = 1;
    }
}

void P2() {
    while (true) {
        while (estado == 0);
        estado = 0;
        cout << "Proceso 2 esta en su seccion critica" << endl;
        estado = 1;
    }
}

int main() {
    estado = 1;
    thread t1(P1);
    thread t2(P2);
    
    t1.join();
    t2.join();
    
    return 0;
}