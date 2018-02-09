#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;
//Primer ejercicio
//string medianaDmedianas(int*,int);
//Menu para tercer ejercicio
int menu2();
//Segundo ejercicio
void permutaciones(string, string*&);
//Tercer ejercicio
//string* fechas(string);
//Menu
int menu();
//Menu para el tipo de listado
int menu3();
//Ordenamiento de Permutaciones
void ordenar(string*&);
//Imprmir
void print(string*);
//Liberar arrays
void cleararray(string*&);
//LLenar arreglo 
void fill(int, int*&);
//Arreglar mediana
void orden(int*&, int);
//Imprimir enteros
void printInt(int, int*);

int main(){
	int salir = 0;
	string numero;
	string universo;
	int tam = 0;
	int* numeros;
	int par;
	int* temp;
	int size;
	int vueltas;
	while (salir != 4){
		switch(salir = menu()){
			case 1:
				cout<<"Ingrese el size del conjunto S:"<<endl;
				cin>>tam;
				numeros = new int[tam];
				fill(tam,numeros);
				cout<<endl;
				//printInt(tam,numeros);
				//cout<<endl;
				//cout<<endl;
				orden(numeros, tam);
				printInt(tam,numeros);
				if (tam <= 5 && tam > 0){
					if (tam%2 == 0){
						par = tam/2;
						cout<<"La mediana es: "<<numeros[par]<<endl;
					}else{
						par = ((tam+1)/2)-1;
						cout<<"La mediana es: "<<numeros[par]<<endl;
					}
				}else{
					if((tam+1)%5 == 0){
						temp = new int[tam+1];
						temp[0] = 0;
						size = tam+1;
						for(int i = 1; i < tam+1; i++){
							temp[i] = numeros[i-1];
						}
					}else if((tam+2)%5 == 0){
						size = tam+2;
						temp = new int[tam+2];
						temp[0] = 0;
						temp[1] = 0;
						for (int i = 2; i < tam+2; i++){
							temp[i] = numeros[i-2];
						}
					}else if((tam+3)%5 == 0){
						size = tam+3;
						temp =new int[tam+3];
						temp[0] = 0;
						temp[1] = 0;
						temp[2] = 0;
						for (int i = 3; i < tam+3; i++){
							temp[i] = numeros[i-3];
						}
					}else if((tam+4)%5 == 0){
						size = tam+4;
						temp = new int[tam+4];
						temp[0] = 0;
						temp[1] = 0;
						temp[2] = 0;
						temp[3] = 0;
						for (int i = 4; i < tam+4; i++){
							temp[i] = numeros[i-4];
						}
					}else{
						size = tam;
						temp = new int[tam];
						for(int i = 0; i < tam; i++){
							temp[i] = numeros[i];
						}
					}
					printInt(size,temp);
					vueltas = size/5;
					int cont = 0;
					int pos = 0;
					int* medianas = new int[vueltas];
					for (int j = 0; j < vueltas; j++){
						for (int h = 0; h < 5; h++){
							medianas[pos] = temp[cont+2];
							cont+=5;
							pos++;
						}
					}
					for(int c = 0; c<vueltas;c++){
						cout<<medianas[c]<<endl;
					}
					if(vueltas%2 == 0){
						par = vueltas/2;
						cout<<"La mediana es: "<<medianas[par]<<endl;
					}else{
						cout<<vueltas;
						par = ((vueltas+1)/2)+1;
						cout<<par;
						cout<<"La mediana es: "<<medianas[par]<<endl;
					}
					
				}
				break;
			case 2:
				cout<<"Ingrese un numero con maximo 4 digitos:"<<endl;
				cin>>numero;
				if (numero.size() != 4){
					cout<<"Numero invalido"<<endl;
				}else{
					string* array;
					array = new string[12];
					permutaciones(numero, array);
					cout<<endl;
					print(array);
					cleararray(array);
				}
				break;
				
			case 3:
				string fecha;
				cout<<"Ingrese una fecha"<<endl;
				cin>>fecha;
				switch(menu2()){
					case 1:
						break;
					case 2:
						break;
					case 3:
						switch(menu3()){
							case 1:
								break;
							case 2:
								break;
							case 3:
								break;
						}
						break;
				}
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

void printInt(int size, int* array){
	for (int i = 0; i < size; i++){
		cout<<array[i]<<endl;
	}
	cout<<endl;
}

void cleararray(string*& array){
	delete[] array;
	array=NULL;

}

void fill(int size, int*& array){
	srand(time(NULL));
	for (int i = 0; i < size; i++){
		array[i] = rand() % 100 + 1;
	}
}

void orden(int*& numeros, int size){
	int temp = 0;
	for (int i = 1; i < size; i++){
		for (int j = 0; j < size-1; j++){
			if(numeros[j] > numeros[j+1]){
				temp = numeros[j];
				numeros[j] = numeros[j+1];
				numeros[j+1] = temp;
			}
		}	
	}
}

int menu2(){
	int op;
	cout<<"1: Listar Todo"<<endl
		<<"2: Listar Ordenado"<<endl
		<<"3: Listar por consulta"<<endl
		<<"4: Volver"<<endl;
	cin>>op;
	return op;
}

int menu3(){
	int op;
	cout<<"1: Listar fechas por Mes especifico"<<endl
		<<"2: Listar fechas por Ano especifico"<<endl
		<<"3: Listar fechas de acuerdo a Dia"<<endl
		<<"4: Salir"<<endl;
	cin>>op;
	return op;
}
