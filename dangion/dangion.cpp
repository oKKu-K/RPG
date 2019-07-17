#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<curses.h>
#include<Windows.h>
#include "battle.h"
#include<time.h>

int x = 120;
int y = 30;
char ab[300][300];
void block1(int a, int b, int c, int d);
void tate(int a, int b, int ichi);
void yoko(int a, int b, int ichi);
void create(int dangion_number);
int main(int argc, char *argv[])
{
	// ‰Šú‰»
	int a = 0;  
	int b = 0;
	int px = 60;
	int py = 15;
	int j;
	int i;
	int key;
	
	initscr();
	noecho();

	cbreak();
	
	keypad(stdscr, TRUE);
	for (int i = 0; i < 300; i++) {
		for (int j = 0; j < 300; j++) {
			ab[i][j] = '#';
		}
	}
	create(2);
	int count = 0;
	while (true) {


		erase();
			
			for (int i = 0; i < 30; i++) {
				for (int j = 0; j < 120; j++) {
						mvaddch(i, j, ab[i-a][j-b]);
				}
			}
		
		
		
		
		mvprintw(15, 60, "@");
		key = getch();

		srand((unsigned)time(NULL));

		int random = 0;
		int mnumber = 0;
		
		switch (key) {
		case KEY_UP:
			
		/*	if (py == 226 && (150<px&&170>px) {
				erase();
				Battle(3);
			}*/
			//else {
				if (ab[py - 1][px] != '#') {
					a++;
					py--;
					random = 0;
					if (random == 7) {
						mnumber = rand() % 2;
						erase();
						Battle(mnumber);
					}
				}
	//		}
			break;
		case KEY_DOWN:
			if (ab[py + 1][px] != '#') {
				a--;
				py++;
				random = 0;
				if (random == 7) {
					mnumber = rand() % 2;
					erase();
					Battle(mnumber);
				}
			}
			break;
		
		case KEY_RIGHT:
			if (px == 250 && (py > 80 && py < 170)) {
				erase();
				Battle(1);
			}
			else {
				if (ab[py][px + 1] != '#') {
					b--;
					px++;
					random = 1;
					if (random == 7) {
						mnumber = rand() % 3;
						erase();
						Battle(mnumber);
					}
				}
			}
			break;
		case KEY_LEFT:
			if (ab[py][px - 1] != '#') {
				b++;
				px--;
				random = 1;
				if (random == 7) {
					mnumber = rand() % 3;
					erase();
					Battle(mnumber);
				}
			}
				break;
		}
		

		refresh();


		// 1•b‘Ò‹@

	}

	return 0;
}

void block1(int a, int b, int c, int d) {
	int i, j;
	for (j = a; j < b; j++) {
		for (i = c; i < d; i++) {
			ab[j][i] = ' ';
		}
	}
}
void tate(int a, int b,int ichi) {
	int i;
	for (i = a; i < b; i++) {
		ab[i][ichi] = ' ';
	}
}
void yoko(int a, int b, int ichi) {
	int i;
	for (i = a; i < b; i++) {
		ab[ichi][i] = ' ';
	}
}
void create(int dangion_number) {
	if (dangion_number == 1) {
		block1(15, 30, 60, 140); //1
		block1(110, 140, 100, 150); //2
		block1(160, 200, 50, 100);//4
		block1(170, 220, 145, 180);//5
		block1(130, 150, 160, 200);//6
		block1(15, 100, 170, 220);//7
		block1(140, 180, 250, 270);//8
		block1(230, 260, 220, 270);//9
		tate(30, 110, 120);
		yoko(150, 160, 135);
		tate(150, 160, 170);
		yoko(150, 171, 160);
		tate(160, 170, 150);
		yoko(70, 110, 120);
		tate(120, 160, 70);
		yoko(140, 170, 25);
		yoko(220, 260, 55);
		tate(55, 140, 260);
		tate(180, 200, 260);
		yoko(245, 261, 200);
		tate(200, 231, 245);
		tate(260, 286, 250);
		yoko(160, 251, 285);
		tate(270, 285, 160);
		block1(222, 270, 150, 170);//10
		for (int i = 158; i < 163; i++) {
			ab[224][i] = 'X';
		}
		ab[225][158] = 'X'; ab[225][159] = 'o'; ab[225][160] = 'X'; ab[225][161] = 'o'; ab[225][162] = 'X';
		ab[226][158] = 'X'; ab[226][162] = 'X';
		for (int i = 159; i < 162; i++) {
			ab[226][i] = '_';
		}
		for (int i = 158; i < 163; i++) {
			ab[227][i] = 'X';
		}
		/*XXXXX
		XoXoX
		X___X
		XXXXX*/
	}
	else if (dangion_number == 2) {
		block1(15, 40, 60, 70);//1
		yoko(60, 75, 30);
		block1(20, 80, 75, 90);//2
		tate(80, 100, 75);
		block1(100, 130, 70, 90);//3
		yoko(90, 100, 110);
		block1(100, 180, 35, 45);//4
		tate(130, 150, 80);
		block1(150, 175, 60, 130);//5
		tate(175, 220, 110);
		yoko(110, 130, 220);
		block1(190, 230, 130, 200);//6
		yoko(90, 140, 110);
		block1(100, 130, 140, 210);//7
		tate(50, 150, 175);
		yoko(175, 241, 50);
		yoko(175, 241, 150);
		tate(50, 150, 240);
		yoko(240, 250, 110);
		block1(80, 170, 250, 270);//8
		for (int i = 108; i < 113; i++) {
			if (i != 110) {
				ab[i][261] = '{';
				ab[i][262] = '}';
			}
		}
		for (int i = 261; i < 268; i++) {
			ab[110][i] = '=';
		}
		ab[110][260] = 'O';
		/* {} 
 {}  
O=======
 {}
 {}*/
	}
}
