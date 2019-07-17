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
		block1(15, 30, 60, 140); //1
		block1(110, 140, 100, 150); //2
		block1(160,200,50,100);//4
		block1(170,220,145,180);//5
		block1(130,150,160,200);//6
		block1(15,100,170,220);//7
		block1(140,180,250,270);//8
		block1(230,260,220,270);//9
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
		tate(200, 230, 245);
		
	//ab[15][60] = '@';
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
			if (ab[py - 1][px] != '#') {
				a++;
				py--;
				random = rand() % 8;
				if (random == 7) {
					mnumber = rand() % 3;
					erase();
					Battle(mnumber);
				}
			}
			break;
		case KEY_DOWN:
			if (ab[py + 1][px] != '#') {
				a--;
				py++;
				random = rand() % 8;
				if (random == 7) {
					mnumber = rand() % 3;
					erase();
					Battle(mnumber);
				}
			}
			break;
		
		case KEY_RIGHT:
			if (ab[py][px + 1] != '#') {
				b--;
				px++;
				random = rand() % 8;
				if (random == 7) {
					mnumber = rand() % 3;
					erase();
					Battle(mnumber);
				}
			}
			break;
		case KEY_LEFT:
			if (ab[py][px - 1] != '#') {
				b++;
				px--;
				random = rand() % 8;
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
