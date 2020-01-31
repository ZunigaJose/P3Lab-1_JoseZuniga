#include<iostream>
#include<cstdlib>
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

int menor(int size, int arr[]) {
	int menor;
	for(int i = 1; i < size; i++) {
		
	}

}

void ej2() {
	int size;
	cout << "Ingrese el tamaño del arreglo: ";
	cin >> size;
	int arr[size];

}

void ej1() {
	int a, b;
	cout << "Ingrese el valor de a: ";
	cin >> a;
	cout << "Ingrese el valor de b: ";//Validar?
	cin >> b;
	cout << "mcd(" << a << "," << b << ") = " << mcd(a,b) << endl;
}

int menu() {
	int op;
	cout << "0. Salir" << endl;
	cout << "1. Ejercicio 1 (Mcd)" << endl;
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
	}
	} while (op != 0);
	return 0;
}
