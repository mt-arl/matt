#include "conjunto.h"

#include <iostream>
#include <cstdlib>
//#ifndef CONJUNTO_H
//#define CONJUNTO_H

using namespace std;
const int MAX_SIZE = 100;

Conjunto::Conjunto(){
    size = 0;
    conjunto = new int[MAX_SIZE]; // reserva memoria para el conjunto
}

Conjunto::~Conjunto(){
    delete[] conjunto; // libera la memoria del conjunto
}

void Conjunto::leerConjunto() {
    int n;
    cout << "Ingrese el tamano del conjunto (max " << MAX_SIZE << "): ";
    cin >> n;
    size = n;
    conjunto = new int[n]; // reserva memoria para el conjunto
    cout << "Ingrese los elementos del conjunto separados por espacios: ";
    for(int i = 0; i < n; i++){
    	cout<<"\n>Elemento["<<i+1<<"]:";
        cin >> *(conjunto + i);
    }
}

void Conjunto::imprimirConjunto() {
    cout << "{";
    for (int i = 0; i < size; i++) {
        cout << *(conjunto + i);
        if (i != size - 1) {
            cout << ", ";
        }
    }
    cout << "}" << endl;
}
/*
Conjunto Conjunto::unionConjunto( Conjunto& B)  {
    Conjunto C;
    C.conjunto = new int[size + B.size]; // Reserva memoria dinÃ¡mica
    C.size = 0;
    int* ptrC = C.conjunto;
    int* ptrA = conjunto;
    int* ptrB = B.conjunto;
    // Copia los elementos de A que no estÃ¡n en B
    if(*ptrA==*ptrB){
    	C.size--;
	}
	for(int i = 0; i < size; i++, ptrA++, ptrC++){
        if(!B.pertenece(ptrA)){
            *ptrC = *ptrA;
            C.size++;
        }
    }
    // Copia los elementos de B
    for(int i = 0; i < B.size; i++, ptrB++, ptrC++){
        if(!pertenece(ptrB)){
            *ptrC = *ptrB;
            C.size++;
        }
    }
    return C;
}*/

Conjunto Conjunto::unionConjunto( Conjunto& B)  {
    Conjunto C;
    C.conjunto = new int[size + B.size]; // Reserva memoria dinámica
    C.size = 0;
    int* ptrC = C.conjunto;
    int* ptrA = conjunto;
    int* ptrB = B.conjunto;

    // Copia los elementos de A que no están en B
    for(int i = 0; i < size; i++, ptrA++){
        if(!B.pertenece(ptrA) || !C.pertenece(ptrA)){
            *ptrC = *ptrA;
            C.size++;
            ptrC++;
        }
    }
    // Copia los elementos de B
    for(int i = 0; i < B.size; i++, ptrB++){
        if(!pertenece(ptrB) || !C.pertenece(ptrB)){
            *ptrC = *ptrB;
            C.size++;
            ptrC++;
        }
    }
    return C;
}



/*
Conjunto Conjunto::interseccionConjunto( Conjunto& B)  {
    Conjunto C;
    int* ptrA = conjunto;
    int* ptrB = B.conjunto;
    for (int i = 0; i < size; i++, ptrA++) {
        if (B.pertenece(ptrA)) {
            C.conjunto[C.size] = *ptrA;
            C.size++;
        }
    }
    return C;
}*/

Conjunto Conjunto::interseccionConjunto(Conjunto& B) {
	Conjunto C;
	C.conjunto = new int[size + B.size]; // Reserva memoria dinámica
	C.size = 0;
	int* ptrC = C.conjunto;
	int* ptrA = conjunto;
	int* ptrB = B.conjunto;
	for (int i = 0; i < size; i++, ptrA++) {
		if (B.pertenece(ptrA) && !C.pertenece(ptrA)) {
			*ptrC = *ptrA;
			C.size++;
			C.mutable_size++;
		}
	}
	for (int i = 0; i < B.size; i++, ptrB++) {
		if (pertenece(ptrB) && !C.pertenece(ptrB)) {
			*ptrC = *ptrB;
			C.size++;
			C.mutable_size++;
		}
	}
	return C;
}

/*
Conjunto Conjunto::diferenciaConjunto( Conjunto& B) {
    Conjunto C;
    int* ptrA = conjunto;
    int* ptrB = B.conjunto;
    for(int i = 0; i < size; i++, ptrA++){
        if(!B.pertenece(ptrA)){
            C.conjunto[C.mutable_size] = *ptrA;
            C.mutable_size++;
        }
    }
    return C;
}*/

Conjunto Conjunto::diferenciaConjunto(Conjunto& B) {
	Conjunto C;
	C.size = 0;
	C.mutable_size = 0;
	C.conjunto = new int[size]; // Reserva memoria dinámica
	int* ptrA = conjunto;
	int* ptrB = B.conjunto;
	for(int i = 0; i < size; i++, ptrA++){
		if(!B.pertenece(ptrA) && !C.pertenece(ptrA)){
			*(C.conjunto + C.mutable_size) = *ptrA;
			C.mutable_size++;
			C.size++;
		}
	}
	return C;
}


bool Conjunto::pertenece(int *num) {
    int* ptr = conjunto;
    for (int i = 0; i < size; i++) {
        if (*ptr == *num) {
            return true;
        }
        ptr++;
    }
}
/*
int Conjunto::tamanio(int dimension){
    size=dimension;
	return size;
}*/