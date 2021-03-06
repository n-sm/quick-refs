#include "stdio.h"
#include <stdlib.h>     /* srand, rand */
#include <iostream>
#define NFILAS 7
#define NCOLUMNAS 8

using namespace std; //System

class cosos {
	int color;
public :
	void set_color(int num);
	int get_color();
	cosos();
	~cosos();
};
void cosos::set_color(int num) {color = num + 1;};
int cosos::get_color() { return color; };

cosos::cosos() {
	set_color(rand() % 4);
};
cosos::~cosos() {};


class Puntos {
public :
  int coordenadas[2];
  void print_coordenadas();
  void set_coordenadas(int fil, int col);
  //  int* get_coordenadas(Puntos punto);
  Puntos();
  ~Puntos();
};

void Puntos::set_coordenadas(int fil, int col){
  coordenadas[0] = fil;
  coordenadas[1] = col;
};
Puntos::Puntos(){};
Puntos::~Puntos(){};
void Puntos::print_coordenadas(){
  cout << "[0]: " << coordenadas[0] ;
}

class tablero {
  cosos coso[NFILAS][NCOLUMNAS];
  Puntos partida, llegada;
  int contar;

public :
  void mostrar_cosos();

  void mostrar_coso(int fila, int columna);
  int eliminar(int fila, int columna);


  void drop(int col, int fil_desde, int fil_hasta);
  void rellenar();
  void ocupar_lugar(int fil, int col);
  int hay_trio(int fil, int col);

  void hacer_jugada();
  void HacerJugada(Puntos partida, Puntos llegada);
  int revisar_tablero();

  tablero();
} tab;

void tablero::mostrar_cosos()
{
  int i, j;
  cout << "   0 1 2 3 4 5 6 7" << endl;
  for(i = 0; i < NFILAS; ++i){
    cout << endl << i << "  ";
    for(j = 0; j < NCOLUMNAS; ++j){
      cout << coso[i][j].get_color() << " ";
    }
  }
  cout << endl << endl << "   0 1 2 3 4 5 6 7" << endl;
};
void tablero::mostrar_coso(int fila, int columna){
	cout << endl << coso[fila][columna].get_color() << endl;
};

int tablero::eliminar(int fil, int col){
  int color;
  color = coso[fil][col].get_color();
  coso[fil][col].set_color(-1);
  contar++;
  if(fil>0){
    if(color == coso[fil-1][col].get_color()) eliminar(fil-1, col);
  };
  if(fil<NFILAS-1){
    if(color == coso[fil+1][col].get_color()) eliminar(fil+1, col);
  };
  if(col>0){
    if(color == coso[fil][col-1].get_color())  eliminar(fil, col-1);
  };
  if(col<NCOLUMNAS-1){
    if(color == coso[fil][col+1].get_color())  eliminar(fil, col+1);
  };
  return contar;
};

void tablero:: drop(int col, int fil_desde, int fil_hasta){
  coso[fil_hasta][col] = coso[fil_desde][col];
  coso[fil_desde][col].set_color(-1);
}
void tablero::rellenar(){
  int i, j, k;

  for(i = NFILAS-1; i >= 0; --i){
    for(j = NCOLUMNAS-1; j >= 0; --j){

      if(coso[i][j].get_color() < 1){

	ocupar_lugar(i,j);
      }
    }
  }
};
void tablero::ocupar_lugar(int fil, int col){
  int i, j, k;
  if(coso[fil][col].get_color() < 1){
	if(fil == 0) coso[fil][col].set_color((rand() % 4)+1);
	else{
	  k = fil-1;
	  if(coso[k][col].get_color() > 0){
	   
	    drop(col, k, fil);
	  
	  }
	  else {
	    ocupar_lugar(k, col);
	    ocupar_lugar(fil,col);
	  }
	  
	  
	}
  }
}	    
int tablero::hay_trio(int fil, int col){
	if(fil + 2 < NFILAS) {
		if(coso[fil][col].get_color()==coso[fil+1][col].get_color() &&
			coso[fil][col].get_color()==coso[fil+2][col].get_color())
			return 1;
	}
	if(fil + 1 < NFILAS && fil > 0) {
		if(coso[fil][col].get_color()==coso[fil+1][col].get_color() &&
			coso[fil][col].get_color()==coso[fil-1][col].get_color())
			return 1;
	}

	if(fil > 1) {
		if(coso[fil][col].get_color()==coso[fil-1][col].get_color() &&
			coso[fil][col].get_color()==coso[fil-2][col].get_color())
			return 1;
	}
	if(col + 2 < NCOLUMNAS) {
		if(coso[fil][col].get_color()==coso[fil][col+1].get_color() &&
			coso[fil][col].get_color()==coso[fil][col+2].get_color())
		return 1;
	}
	if(col + 1 < NCOLUMNAS && col > 0) {
		if(coso[fil][col].get_color()==coso[fil][col+1].get_color() &&
			coso[fil][col].get_color()==coso[fil][col-1].get_color())
		return 1;
	}

	if(col > 1) {
		if(coso[fil][col].get_color()==coso[fil][col-1].get_color() &&
			coso[fil][col].get_color()==coso[fil][col-2].get_color())
		return 1;
	}
	return 0;
}

void tablero::hacer_jugada(){
  int fila, columna, mensage, color;
  contar = 0;
  cout << "Ingrese FILA y COLUMNA" << endl ;
  cin >> fila >> columna;
  color = coso[fila][columna].get_color();
  if(fila == 9 || columna == 9) exit(1);
  if(!hay_trio(fila, columna)){
    cout << endl << "                                                      No!!!! " << endl;
  }
  else {
    mensage = eliminar(fila, columna);
    cout << "                                                   Si....     se eliminaron " << mensage;
    cout << " de color " << color << endl;
  }
  rellenar();
  mostrar_cosos();
	
}

int tablero::revisar_tablero(){
	int i, j, retu = 0;
	for(i = NCOLUMNAS - 1; i > -1; --i){
		for(j = NFILAS - 1; j > -1; --j){
			if(hay_trio(j, i)) retu = 1;
		}
	}
	if(!retu) cout << "No hay mas ternas" ;
	return retu;
}
tablero::tablero() {
};
void tablero::HacerJugada(Puntos partida, Puntos llegada){

};


int main()
{
 
  Puntos prueba;
  prueba.set_coordenadas(66653, 24);
  cout << prueba.coordenadas[1] << endl;
  //  printf("%d at\n", prueba.coordenadas[0]);
  prueba.print_coordenadas();
  cout << " aca" << endl;
  tab.mostrar_cosos();
    while(tab.revisar_tablero()){
	  tab.hacer_jugada();
  }
  cout << endl;
  
  
  

  
	return 0;
};
