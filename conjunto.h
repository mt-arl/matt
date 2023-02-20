#ifndef CONJUNTO_H
#define CONJUNTO_H

class Conjunto{
private:
	
public:
	mutable int mutable_size;
	    int *conjunto;
	    int size;
	
	Conjunto();
    ~Conjunto(); // destructor para liberar la memoria reservada
    void leerConjunto();
    void imprimirConjunto();
    Conjunto unionConjunto( Conjunto& B) ;
    Conjunto interseccionConjunto( Conjunto& B) ;
    Conjunto diferenciaConjunto( Conjunto& B) ;
    bool pertenece(int*);
    //int tamanio(int);
};
#endif