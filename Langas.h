#ifndef LANGAS_H
#define LANGAS_H
#include <windows.h>
#include <iostream>
#include <iomanip>

//piesa visa langa ir sienos
//logikos nera
class Langas
{
private:
	short xkoord, ykoord, koordtop;
	COORD koord1;
	short x, y;              // nauduosiu darydamas zaidymo lauka vidu
	COORD ko;         // nauduosiu darydamas zaidymo lauka vidu

	short spalva;
	//tl- top left kampas, br- bottom right, hor- horizantali linija
	// diaR-diag linija su issakojimu i RIGHT, horD- hor linija ir DOWN, fb- full block, 
	unsigned char tl1, tr1, bl1, br1, hor1, diag1, diagR, diagL, horU, horD, cross, fb;            //vidines sienos ir kampai
	unsigned char tl2, tr2, bl2, br2, hor2, diag2;            //isorines sienos
protected:
	short bottomY, rightX; //paciame field kad nereiketu skaiciuot kiekviena karta :D
public:
	Langas();
	void index();
	short get_bottomY();
	short get_rightX();
	void piesti_langa(); //piesa langa 
	void piesti_remeli(); // pesa remeli, 0-be rem, 1-vieng, 2- dvygub
	void piesti_vert();  //piesa vertikalios linijos viduje
	void piesti_hor();  //piesa diag linijos viduje
	void piesti_blokus(); //piesa blokus viduje
	void piesti_prize();
};

#endif 