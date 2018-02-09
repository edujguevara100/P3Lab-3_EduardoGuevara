#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
//Primer ejercicio
//int* medianaDmedianas(int*);
//Segundo ejercicio
void permutaciones(string, string*&);
//Tercer ejercicio
//string* fechas(string);
//Menu
int menu();
//Ordenamiento de Permutaciones
void ordenar(string*&);
//Imprmir
void print(string*);
//Liberar arrays
void cleararray(string*&);

int main(){
	int salir = 0;
	string numero;
	while (salir != 4){
		switch(salir = menu()){
			//case 1:
			//	break;
			case 2:
				cout<<"Ingrese un numero con maximo 4 digitos:"<<endl;
				cin>>numero;
				if (numero.size() != 4){
					cout<<"Numero invalido"<<endl;
				}else{
					string* array;
					array = new string[12];
					permutaciones(numero, array);
					print(array);
					//cleararray(array);
				}
				break;
				
			case 3:
				break;
		}	
	}
	return 0;
}

int menu(){
	cout<<"1: Mediana de medianas"<<endl
		<<"2: Permutaciones"<<endl
		<<"3: Fechas"<<endl
		<<"4: Salir"<<endl;
	int op;
	cin>>op;
	return op;
}

void permutaciones(string num, string*& array){
	string num1,num2,num3,num4;
	num1 = num.at(0);
	num2 = num.at(1);
	num3 = num.at(2);
	num4 = num.at(3);
	//string* temp;
	//temp = new string[12];
	array[0] = num1+num2+num3+num4;
	array[1] = num2+num1+num3+num4;
	array[2] = num2+num3+num1+num4;
	array[3] = num2+num3+num4+num1;
	array[4] = num4+num3+num2+num1;
	array[5] = num3+num4+num2+num1;
	array[6] = num3+num2+num4+num1;
	array[7] = num3+num4+num1+num2;
	array[8] = num4+num1+num2+num3;
	array[9] = num1+num3+num4+num2;
	array[10] = num1+num4+num3+num2;
	array[11] = num4+num2+num3+num1;
	//array = temp;
	//cleararray(temp);
	ordenar(array);
	//return array;
}

void ordenar(string*& array){
	string temp = "";
	for (int i = 1; i<12;i++){
		for (int j =0; j<11;j++){
			if(atoi(array[j].c_str()) > atoi(array[j+1].c_str())){
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
}

void print(string* array){
	for (int i = 0; i < 12; i++){
		cout<<array[i]<<endl;
	}
}

void cleararray(string*& array){
	delete[] array;
	array=NULL;

}

