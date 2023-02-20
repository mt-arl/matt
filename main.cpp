#include <iostream>
#include "menu.cpp"

using namespace std;

int main(){
    
    // Mostrar el menú de operaciones de conjuntos
    mostrarMenu();

    // Esperar a que el usuario presione una tecla para cerrar la ventana
    getch();
    closegraph();

    return 0;
}