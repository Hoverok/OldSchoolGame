#ifndef LOGUS_H
#define LOGUS_H
#include <windows.h>
#include <iostream>
#include <iomanip>
#include "Langas.h"


class Logus : public Langas
{
private:
	COORD currK;  //laiko kur dabar randasi zaidejas
	char move;    // w a s d
	bool b, prize, win;       // tikrina kur galima judeti
	unsigned char u, d, r, l;  // avataras bus zymimas strelytem


protected:
	unsigned char F[24][60];

public:
	Logus();
	void set_move(char);  //gauna chara kur judet
	void testing_wall();       //tikrina ar siena
	void testing_prize();  //ar paimtas $
	void testing_win(); // ar pasiektas galas
	bool end_it();      //jeigu win = 0;
	void movement();

};

#endif