#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<fstream>
using namespace std;

#define pausa \
 cout<<"\nTeclea enter para continuar...";\
 cin.ignore();


void menu();
int leerArchivo();
void escribirArchivo(int);
void depositar(int);
void retirar(int);


int saldoTotal=leerArchivo();
ofstream file;

int main(){

    menu();

    return 0;
}

void menu(){
    int opc, saldoDepos, saldoRet;
    char rpt;

    do{
        cout<<"\t ----------------------\n";
        cout<<"\t|      Bienvenido      |\n";
        cout<<"\t ----------------------\n";
        cout<<"\t|1. Ver saldo          |\n";
        cout<<"\t|2. Depositar          |\n";
        cout<<"\t|3. Retirar            |\n";
        cout<<"\t|4. Salir              |\n";
        cout<<"\t ----------------------\n";
        cout<<"\tOpción: ";
        cin>>opc;
        cin.ignore();
        
        system("clear");

        switch (opc){
            case 1:
                cout<<"\t--------Cuenta--------\n\n";
                cout<<"     Su saldo total es de: $"<<saldoTotal<<endl;
                pausa
            break;
            case 2:
                cout<<"\t-------Deposito--------\n\n";
                cout<<"      Cantidad a depositar: $";
                cin>>saldoDepos;
                depositar(saldoDepos);
            break;
            case 3:
                cout<<"\t-------Retiro--------\n\n";
                cout<<"      Cantidad a retirar: $";
                cin>>saldoRet;
                cin.ignore();
                 if(saldoRet>saldoTotal){
                    cout<<"\nTu crédito no es suficiente\n";
                    pausa
                }else{
                    retirar(saldoRet);
                    }
            break;
            default:
                if(opc!=4){
                    cout<<"Esta opción no existe, vuelve a intentarlo\n";
                    pausa
                }
            break;
        }

        system("clear");
    }while(opc != 4);
}
int leerArchivo(){
    ifstream file;
    string texto;
    file.open("Saldo total.txt", ios::in);
    if(file.fail()){
        cout<<"No se pudo abrir el archivo\n";
        exit(1);
    }
    getline(file, texto);

    saldoTotal = stoi(texto);

    file.close();

    return saldoTotal;
}

void escribirArchivo(int saldo){
    file.open("Saldo total.txt", ios::out);
    if(file.fail()){
        cout<<"No se pudo abrir el archivo\n";
        exit(1);
    }
    file<<saldo;
    file.close();
}

void depositar(int saldoD){
    saldoTotal += saldoD;
    escribirArchivo(saldoTotal);
}

void retirar(int saldoR){
    saldoTotal -= saldoR;
    escribirArchivo(saldoTotal);
}