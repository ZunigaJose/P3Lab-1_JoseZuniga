#include<iostream>
#include<cstdlib>
#include<math.h>
using namespace std;

int mcd(int a, int b){
	double r;
	if (b > a){
		return b;
	}
	if (b == 0) {
		return a;	
	}	
	r = a % b;
	return (mcd(b,r));
}

void menor(int size, int* x, int pos) {
	bool entro = false;
	int menor = x[pos - 1], menorPos, valorPos = x[pos - 1];
	for(int i = pos; i < size; i++) {
		if(x[i] < menor) {
			entro = true;
			menor = x[i];
			menorPos = i;
		}	
	}
	if(entro) {
		x[pos - 1] = x[menorPos];
		x[menorPos] = valorPos;
	}
}

void imprimirArr(int size, int* x) {
	for (int i = 0; i < size; i++) {
		cout << "[" << x[i] << "]";
	}
	cout << endl;
}

void ej2() {
	int size;
	cout << "Ingrese el tamaño del arreglo: ";
	cin >> size;
	int* x = new int [size];
	for(int i = 0; i < size; i++){
		x[i] = rand() % 100;
	}

	cout << "Arreglo original: " << endl;
	imprimirArr(size, x);

	for(int i = 1; i < size; i++) {
		menor(size, x, i);
		imprimirArr(size, x);
	}
}

void ej1() {
	int a, b;
	cout << "Ingrese el valor de a: ";
	cin >> a;
	cout << "Ingrese el valor de b: ";//Validar?
	cin >> b;
	cout << "mcd(" << a << "," << b << ") = " << mcd(a,b) << endl;
}

int obtenerMayor(int* x){
	int num;
	for(int i = 3; i > 0; i--){
		num += x[i] * pow(10,i);
	}
	return num;
}

int obtenerMenor(int* x){
	int num;
	for(int i = 0; i < 4; i++){
		num += x[i] * pow(10,i);
	}
	return num;
}

 int operacion(int num) {
	int n1, n2, n3 , n4;
	n1 = num / 1000;
	n2 = num / 100 - (n1 * 10);
	n3 = num / 10 - ((n1 * 100) + (n2 * 10));
	n4 = num - (n1 * 1000 + n2 * 100 + n3 * 10);
	int* x = new int[4];
	for(int i = 1; i < 4; i++) {
		menor(4,x,i);
	}
	int mayor, menor;
	mayor = obtenerMayor(x);
	menor = obtenerMenor(x);
	return mayor - menor;
}

int menu() {
	int op;
	cout << "0. Salir" << endl;
	cout << "1. Ejercicio 1 (Mcd)" << endl;
	cout << "2. Ejercicio 2 (Arreglos)" << endl;
	cout << "3. Ejercicio 3 (Kaprekar)" << endl;
	cin >> op;
	if(op < 0 || op >3) {
		return menu();
	}
	return op;
}

int main() {
	int op;
	do {
		op = menu();
		switch (op) {
			case 0:
				
			break;
			case 1:
				ej1();
			break;
			case 2: 
				ej2();
			break;
	
			default: cout << "Opcion Incorrecta!!\nVuelva a Intentar:\n";
		}
	} while (op != 0);
	return 0;
}
