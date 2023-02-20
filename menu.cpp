#include <iostream>
#include "menu.h"
#include "graphics.h"
#include "conjunto.cpp"

using namespace std;

void mostrarConjuntoA(Conjunto conjunto, int color){
    setcolor(color);
    //int x = 100;
    //int y = 300;
    settextstyle(1,HORIZ_DIR,2);
  //  outtextxy(100, 80, "Conjunto A");
    settextstyle(0,HORIZ_DIR,2);
    int contadorX=0;
    for(int i = 0; i < conjunto.size; i++){
        contadorX=i;
		int x = 100 + i*50;
        int y = 300;
        int radio = 20;
        circle(x, y, radio); // Renombrar la función circle como my_circle
        char num[10];
        sprintf(num, "%d", conjunto.conjunto[i]);
        outtextxy(x-5, y-8, num);       
        if(contadorX==conjunto.size-1){
        	setcolor(6);
        	ellipse((x/2)+50, y+16, 0, 360, (x+contadorX)-100, (x+contadorX*5)-80); 
        	setcolor(7);
		}else{
			std::cout<<endl;
		}
    }
}

void mostrarConjuntoB(Conjunto conjunto, int color){
    setcolor(color);
    //int x = 300;
    int contadorX=0;
    settextstyle(1,HORIZ_DIR,2);
  //  outtextxy(460, 80, "Conjunto B");
    settextstyle(0,HORIZ_DIR,2);
    for(int i = 0; i < conjunto.size; i++){
        contadorX=i;
        setcolor(6);
		int x = 450 + i*50;
        int y = 300;
        int radio = 20;
        circle(x, y, radio); // Renombrar la función circle como my_circle
        char num[10];
        sprintf(num, "%d", conjunto.conjunto[i]);
        outtextxy(x-5, y-8, num);       
        if(contadorX==conjunto.size-1){
        	setcolor(6);
        	ellipse((x/2)+220, y+16, 0, 360, (x-(x/2)-150), (x/4)+28); 
        	setcolor(8);
		}else{
			std::cout<<endl;
		}
    }
}

void mostrarConjuntoC(Conjunto conjunto, int color){
    setcolor(color);
    //int x = 300;
    int contadorX=0;
    settextstyle(1,HORIZ_DIR,2);
  //  outtextxy(320, 80, "Conjunto C");
    settextstyle(0,HORIZ_DIR,2);
    for(int i = 0; i < conjunto.size; i++){
        contadorX=i;
        setcolor(6);
		int x = 340 + i*50;
        int y = 300;
        int radio = 20;
        circle(x, y, radio); // Renombrar la función circle como my_circle
        char num[10];
        sprintf(num, "%d", conjunto.conjunto[i]);
        outtextxy(x-5, y-8, num);       
        if(contadorX==conjunto.size-1){
        	setcolor(6);
        	ellipse((x/2)+165, y+16, 0, 360, (x-(x/2)-140), (x/4)+28); 
        	setcolor(8);
		}else{
			std::cout<<endl;
		}
    }
}
//Fin del código.



void mostrarMenu(){
	// Inicializar la ventana de graphics.h
	int gd = DETECT,gm;
    initwindow(800, 600, "Conjuntos");
    int op = -1;
    Conjunto* A = new Conjunto();
    Conjunto* B = new Conjunto();
    Conjunto C;
    while(op != 0){
        cleardevice();
        cout << "----- MENU -----" << endl;
        cout << "1. Leer conjunto A" << endl;
        cout << "2. Leer conjunto B" << endl;
        cout << "3. Mostrar conjuntos" << endl;
        cout << "4. Calcular union" << endl;
        cout << "5. Calcular interseccion" << endl;
        cout << "6. Calcular diferencia (A - B)" << endl;
        cout << "7. Calcular diferencia (B - A)" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> op;

        switch(op){
            case 1:
                //delete A;
                A = new Conjunto();
                A->leerConjunto();
                system("PAUSE");
        		cleardevice();
        		system("cls");
                break;
            case 2:
                //delete B;
                B = new Conjunto();
                B->leerConjunto();
                system("PAUSE");
        		cleardevice();
				system("cls");
				break;
            case 3:
                cout << "Conjunto A: ";
                A->imprimirConjunto();
                cout << "Conjunto B: ";
                B->imprimirConjunto();
                mostrarConjuntoA(*A, WHITE);
                mostrarConjuntoB(*B, YELLOW);
                system("PAUSE");
        		cleardevice();
				system("cls");
				break;
            case 4:
            	cout << "Conjunto A: ";
                A->imprimirConjunto();
                cout << "Conjunto B: ";
                B->imprimirConjunto();
                C = A->unionConjunto(*B);
                cout << "Union de A y B: ";
                C.imprimirConjunto();
                mostrarConjuntoC(C, RED);
                system("PAUSE");
        		cleardevice();
				system("cls");
				break;
            case 5:
                cout << "Conjunto A: ";
                A->imprimirConjunto();
                cout << "Conjunto B: ";
                B->imprimirConjunto();
				C = A->interseccionConjunto(*B);
                cout << "Interseccion de A y B: ";
                C.imprimirConjunto();
                mostrarConjuntoC(C, RED);
                system("PAUSE");
        		cleardevice();
				system("cls");
				break;
            case 6:
            	cout << "Conjunto A: ";
                A->imprimirConjunto();
                cout << "Conjunto B: ";
                B->imprimirConjunto();
                C = A->diferenciaConjunto(*B);
                cout << "Diferencia (A - B): ";
                C.imprimirConjunto();
                mostrarConjuntoC(C, RED);
                system("PAUSE");
        		cleardevice();
				system("cls");
				break;
			case 7:
            	cout << "Conjunto A: ";
                A->imprimirConjunto();
                cout << "Conjunto B: ";
                B->imprimirConjunto();
                /*C = B->diferenciaConjunto(*A);
                cout << "Diferencia (B - A): ";
                C.imprimirConjunto();
                mostrarConjuntoC(C, RED);*/
                system("PAUSE");
        		cleardevice();
				system("cls");
				break;
            case 0:
            	system("cls");
                cout << "Hasta luego!" << endl;
                break;
            default:
                cout << "\n>Opcion invalida" << endl;
                system("pause");
                system("cls");
        }
        //cout << "Presione una tecla para continuar..." << endl;
        //getch();
    }
    delete A;
    delete B;
}
