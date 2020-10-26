#include <iostream>
#include <fstream>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>  
#include <stdio.h>
#include <clocale> 
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <iterator>
using namespace std;

int menu() {
	system("color 1f");
	int a; 
	cout<<">>-----------------BIENVENIDO AL MENU PRINCIPAL--------------<<"<<endl;
	cout<<" |                   1. AGREGAR PALABRA                      |"<<endl;
	cout<<" |                   2. LEER PALABRAS                        |"<<endl;
	cout<<" |                   3. BUSCAR PALABRA                       |"<<endl;
	cout<<" |                   4. ACTUALIZAR PALABRA                   |"<<endl; 
	cout<<" |                   5. BORRAR PALABRA                       |"<<endl;
	cout<<" |                   6. EXIT                                 |"<<endl;
	cout<<" |                                                           |"<<endl;
	cout<<" |___________________________________________________________|	 "<<endl;
		cout<<"OPCION: "<<endl;
	cin>>a;
	return a;
}

//metodo agregar
void agregar (ofstream &pa) {
	
		system("color f0");
	string pala;
	string tradu;
	string funcio;
	
	pa.open("Palabr.txt", ios::out|ios::app);
	if(pa.fail()) {

	}
	
	cin.ignore();
	fflush(stdin);
	cout<<"Ingrese Palabra: "<<endl;
	getline(cin,pala);
		fflush(stdin);
	cout<<"Ingrese Traduccion: "<<endl;
	getline(cin,tradu);
		fflush(stdin);
	cout<<"Ingrese Funcionalidad: "<<endl;
	getline(cin,funcio);
	pa<<pala<<" "<<tradu<<" "<<funcio<<endl;

	}
	



//metodo lectura
void verPalabras(ifstream &lec) {
	
	system("color f0");
	system("cls");
	string pala;
	string tradu;
	string funcio,funcio2;
	string texto;
	lec.open("Palabr.txt", ios::in);
	 
	
		cout<<">>------PALABRAS REGISTRADAS------<<"<<endl;
		lec>>pala;
		while (!lec.eof()) {
			lec>>tradu;
			lec>>funcio;
			cout<<" "<<endl;
			cout<<"Palabra--------: "<<pala<<endl;
			cout<<"Traduccion-----: "<<tradu<<endl;
			cout<<"Funcionalidad--: "<<funcio;
			getline(lec,funcio2);
			cout<<funcio2<<endl;
			cout<<" "<<endl;
			cout<<"_________________________________________________________________________________________________________"<<endl;
		
			lec>>pala;
			 
		}//wh
		lec.close(); 
		
	system("pause");
}//meto



//METODO BUSCAR
void buscarPalabras(ifstream &lec) {
	system("color f0");
	system("cls");
	lec.open("Palabr.txt", ios::in);
	cout<<">>-------BUSCAR PALABRAS------<<"<<endl;
	string pala, palabusca;
	string tradu;
	string funcio, funcio2;
	bool encontrada = false;
		fflush(stdin);
	cout<<"Escriba la palabra que desee buscar: "<<endl;
	cin>>palabusca;
	lec>>pala;
	while(!lec.eof() &&  !encontrada) {
		lec>>tradu;
		lec>>funcio;
		
		if(pala == palabusca) {
		cout<<"Palabra--------: "<<pala<<endl;
		cout<<"Traduccion-----: "<<tradu<<endl;
		cout<<"Funcionalidad--: "<<funcio;
		getline(lec,funcio2);
			cout<<funcio2<<endl;;
		cout<<">>----------------------------------<<"<<endl;
		encontrada = true; 
		}
		lec>>pala;
	}
	lec.close();
	
	if(!encontrada)
		cout<<"Palabra no encontrada"<<endl;
	system("pause");
}



//metodo modificarfuncio
void modificafuncio(ifstream & Lec){
		system("color f0");
	system("cls");
		
		cout<<"--------MODIFICAR REGISTROS---------"<<endl;
		cout<<endl;
	string pala;
	string tradu;
	string funcio,funcio2;
	string palabusca;
	string pala2,tradu2,funci2;
	Lec.open("Palabr.txt",ios::in );//
	ofstream modi("modificar.txt",ios::out);//
	
	if(Lec.is_open()){
		cout<<"ingrese la palabra que desee modificar"<<endl;
		cin>>palabusca;
		Lec>>pala;
				while(pala != palabusca && !Lec.eof()){
				Lec>>tradu;
			Lec>>funcio;
				if(pala != palabusca){
					getline(Lec,funcio2);
					modi<<pala<<" "<<tradu<<" "<<funcio<<" "<<funcio2<<endl;
						}
					Lec>>pala;
					if(Lec.eof()){
							cout<<"No se encontro la palabra buscada"<<endl;
							modi.close();
								remove("modificar.txt");
							system("pause");
							int main();
								main();
					}	
				}
		while(!Lec.eof()){	
			if(pala == palabusca){
			Lec>>tradu;
			Lec>>funcio;
				cout<<endl;
				
				cout<<"POR FAVOR  COLOQUE LOS SIGUIENTES DATOS QUE SE LE PIDEN"<<endl;
				
				cout<<"Digite la nueva palabra "<<endl;
				cin>>pala2;
				
				cout<<"Digite la nueva traduccion "<<endl;
				cin>>tradu2;
				fflush(stdin);
				cout<<"Digite la nueva funcionalidad "<<endl;
				getline(cin,funci2);
	
					modi<<pala2<<" "<<tradu2<<" "<<funci2<<" "<<endl;	
			 cout<<endl;
			 	system("cls");
			
			
			 
			//
			} 
		Lec>>pala;
			Lec>>tradu;
			Lec>>funcio;
			 	getline(Lec,funcio2);
			 	if(!Lec.eof()){
				 
					modi<<pala<<" "<<tradu<<" "<<funcio<<" "<<funcio2<<endl;	
						}
				
		}
		Lec.close();
		modi.close();
		
	}else{
	cout<<"Error no se pudo encontrar el archivo."<<endl;
}
	
	remove("Palabr.txt");
	rename("modificar.txt","Palabr.txt");	
cout<<"---------El registro se ha modificado exitosamente--------"<<endl;	

			system("pause");	
	
}
void eliminar(ifstream & Lec){ // void
	system("cls");
			system("color f0");
		ofstream modi;
	string pala;
	string tradu;
	string funcio,funcio2;
	string palabusca;
	string pala2,tradu2,funci2;
	int ni;
	Lec.open("Palabr.txt",ios::in);
	modi.open("modificar.txt",ios::out);	
	cout<<"--------ELIMINAR LOS REGISTROS DE LA PALABRA--------"<<endl;
		cout<<endl;
	
		if(Lec.is_open()){ //if
		cout<<"ingrese la palabra que desee eliminar"<<endl;
		cin>>palabusca;
		Lec>>pala;
			while(pala != palabusca && !Lec.eof()){ //while 1
				Lec>>tradu;
				Lec>>funcio;
				if(pala != palabusca){//if2
					getline(Lec,funcio2);
					modi<<pala<<" "<<tradu<<" "<<funcio<<" "<<funcio2<<endl;
						} //if2
						Lec>>pala;
					if(Lec.eof()){//if3
							cout<<"No se encontro la palabra buscada"<<endl;
							modi.close();
								remove("modificar.txt");
							system("pause");
							int main();
								main();
					}//if3	
			}//while1
			
	
		while(!Lec.eof()){	
			if(pala == palabusca){
			Lec>>tradu;
			Lec>>funcio;
				cout<<endl;
				cout<<"Se eliminara la siguiente palabra,"<<palabusca<<", con todos y sus registros"<<endl;
			 
				cout<<"1. Esta usted acuerdo en eliminar la siguiente palabra:"<<palabusca<<endl;
				cout<<"2. No desea eliminar la palabra:"<<palabusca<<endl;	
				cin>>ni;
				cout<<endl;
	
				if (ni!=1){
					cout<<"No se eliminara la siguiente palabra: "<<palabusca<<endl;
						modi.close();
								remove("modificar.txt");
								
						system("pause");
						int main();
						main();
				}
			}
			
			Lec>>pala;
			Lec>>tradu;
			Lec>>funcio;
			 	getline(Lec,funcio2);
			 	if(!Lec.eof()){
				 
					modi<<pala<<" "<<tradu<<" "<<funcio<<" "<<funcio2<<endl;	
						}
				
		}
		Lec.close();
		modi.close();
		
		}else{
	cout<<"Error no se pudo encontrar el archivo."<<endl;
		}
	
	remove("Palabr.txt");
	rename("modificar.txt","Palabr.txt");	
cout<<"---------LOS REGISTRTOS DE LA PALABRA "<<palabusca<<" SE HAN ELIMINADO CORRECTAMENTE--------"<<endl;	

			system("pause");	
	
}//metodo eliminar





int main() {
	ofstream Palabra;
	ifstream lec;
	int sh;
	
	do {
		sh = menu();
		switch(sh){
			case 1:
				system("cls");
				agregar(Palabra);
				system("cls");
			break;
			
			case 2:
				system("cls");
				verPalabras(lec);
				system("cls");
			break;	
			
			case 3:
				system("cls");
				buscarPalabras(lec);
				system("cls");
				
			break;
			
			
			case 4:
				system("cls");
				modificafuncio(lec);
				system("cls");
			break;	
			
			case 5:
				system("cls");
				eliminar(lec);
				system("cls");
				
			break;	
			
			case 6:
			system("cls");
			exit (-1);
			system("cls");	
				
				
			break;			
			
		}
		
		
		
	} while(sh != 7);
	return 0;
	system("pause");
	
}
