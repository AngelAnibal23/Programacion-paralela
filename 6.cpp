#include <iostream>
#include <thread>
using namespace std;

int turno = 2;
int suma = 0;
bool s1 = false;
bool s2 = false;

void P1() {
    while (true) {
        s1 = true;
        while (s2) {
            if (turno == 2) {
                s1 = false;
                while (turno == 2);
                s1 = true;
            }
        }
        cout << "El proceso 1 se encuentra en su SC" << endl;
        suma += 2;
        cout << "La suma total es: " << suma << endl;
        turno = 2;
        s1 = false;
    }
}

void P2() {
    while (true) {
        s2 = true;
        while (s1) {
            if (turno == 1) {
                s2 = false;
                while (turno == 1);
                s2 = true;
            }
        }
        cout << "El proceso 2 se encuentra en su SC" << endl;
        suma -= 1;
        cout << "La suma total es: " << suma << endl;
        turno = 1;
        s2 = false;
    }
}

int main() {
    suma = 0;
    turno = 2;
    s1 = false;
    s2 = false;
    
    thread t1(P1);
    thread t2(P2);
    
    t1.join();
    t2.join();
    
    return 0;
}