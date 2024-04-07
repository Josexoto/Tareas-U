#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

struct Pieza {
    char simbolo[20];
    int x,y;
};
struct Tablero{
    int cantidad_piezas;
    Pieza *piezas_tablero;
};


void lectura() {
    ifstream archivo("pruebas.txt");

    if (!archivo) {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    int cantidad_de_piezas;
    archivo >> cantidad_de_piezas;
    Tablero piezas[1];
    piezas[1].cantidad_piezas = cantidad_de_piezas;

    const int max_torres = 2,max_peones = 8,max_alfiles = 2, max_caballos = 2, rey_sebastian = 1, rey_ton = 1, reina_sebastian = 1; 
    
    Pieza torres[max_torres]; 
    Pieza peones[max_peones];
    Pieza alfiles[max_alfiles];
    Pieza caballos[max_caballos];
    Pieza REY_sebastian[rey_sebastian];
    Pieza REY_ton[rey_ton];
    Pieza reina[reina_sebastian];
    

    int torres_totales = 0,alfiles_totales = 0,peones_totales = 0, reinas_totales = 0, caballos_totales = 0, reyS_totales = 0, reyT_totales = 0; 


    for (int i = 0; i < 8; i++) {
        string fila;
        archivo >> fila;
        for (int j = 0; j < 8; j++) {
            
            if (fila[j] == 'T') { 
                if (torres_totales < max_torres) { 
                    strcpy(torres[torres_totales].simbolo, "Torres de sebastian");
                    torres[torres_totales].x = i; 
                    torres[torres_totales].y = j; 
                    torres_totales++; 
                }
            }
            
            else if(fila[j] == 'P'){
                if(peones_totales < max_peones){
                    strcpy(peones[peones_totales].simbolo, "Peones de sebastian");
                    peones[peones_totales].x = i; 
                    peones[peones_totales].y = j; 
                    peones_totales++;
                }
            }
            
            else if(fila[j] == 'C'){
                if(caballos_totales < max_caballos){
                    strcpy(caballos[caballos_totales].simbolo, "Caballos de sebastian");
                    caballos[caballos_totales].x = i; 
                    caballos[caballos_totales].y = j;  
                    caballos_totales++;
                }
            }
            
            else if(fila[j] == 'A'){
                if(alfiles_totales < max_alfiles){
                    strcpy(alfiles[alfiles_totales].simbolo, "Peones de sebastian");
                    alfiles[alfiles_totales].x = i; 
                    alfiles[alfiles_totales].y = j; 
                    alfiles_totales++;
                }
            }
            
            else if(fila[j] == 'R'){
                if(reina_sebastian < max_peones){
                    strcpy(reina[reinas_totales].simbolo, "Reina de Sebastian");
                    reina[reinas_totales].x = i; 
                    reina[reinas_totales].y = j; 
                    reinas_totales++;
                }
            }
            
            else if(fila[j] == 'K'){
                if(reyS_totales < rey_sebastian){
                    strcpy(REY_sebastian[reyS_totales].simbolo, "Rey de sebastian");
                    REY_sebastian[reyS_totales].x = i; 
                    REY_sebastian[reyS_totales].y = j; 
                    reyS_totales++;
                }
            }
            
            else if(fila[j] == 'X'){
                if(reyT_totales < rey_ton){
                    strcpy(REY_ton[reyT_totales].simbolo, "Rey de Ton");
                    REY_ton[reyT_totales].x = i; 
                    REY_ton[reyT_totales].y = j; 
                    reyT_totales++;
                }
            }
        }
    }

    archivo.close();
}