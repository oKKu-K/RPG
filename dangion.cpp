#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<curses.h>
#include<Windows.h>

int x = 10;
int y = 10;
char ab[300][300];
char cd[30][120];
void block(int a, int b, int c, int d);
void block1(int a, int b, int c, int d);
int main(int argc, char *argv[])
{
	// ‰Šú‰»
	int a = 0;  
	int b = 0;
	int j;
	int i;
	int key;
	
	initscr();
	noecho();

	cbreak();
	
	keypad(stdscr, TRUE);
	for (int i = 0; i < 300; i++) {
		for (int j = 0; j < 500; j++) {
			ab[i][j] = '#';
		}
	}
		
	int count = 0;
	while (true) {


		erase();
		int w = 10;
		int e = 27;
		int r = 60;
		int t = 140;
		block1(w, e, r, t);
		
		
		for (int i = 0; i < 300; i++) {
			for (int j = 0; j < 500; j++) {
						mvaddch(i, j, ab[i][j]);
						
			}
		}
		for (int i = a; i < 30; i++) {
			for (int j = b; j < 120; j++) {
				cd[i][j] = ab[i - a][j - b];
				
			}
		}
		for (int i = a; i < 30; i++) {
			for (int j = b; j < 120; j++) {
				if (cd[15][60] == '#') {
					mvaddch(i, j, ab[i][j]);
				}
			}
		}
		
		mvprintw(15, 60, "@");
		key = getch();
		switch (key) {
		case KEY_UP:
			if (ab[a+1][b]!= '#') {
				a++;
			}
			break;
		case KEY_DOWN:
			if (ab[a-1][b]!='#') {
				a--;
			}
			break;
		
		case KEY_RIGHT:
			if (ab[a][b-1]!='#') {
				b--;
			}
			break;
		case KEY_LEFT:
			if (ab[a][b+1]!='#') {
				b++;
			}
				break;
			
		}




		refresh();


		// 1•b‘Ò‹@

	}

	return 0;
}
void block(int a, int b, int c, int d) {
	 int i, j;
	for (j = a; j < b; j++) {
		mvprintw(d, j, "#");
	}
	for (j = a; j < b; j++) {
		mvprintw(c, j, "#");
	}
	for (i = c; i < d; i++) {
		mvprintw(i, a, "#");
	}

	for (i = c; i < d; i++) {
		mvprintw(i, b, "#");
	}
}
void block1(int a, int b, int c, int d) {
	int i, j;
	for (j = a; j < b; j++) {
		for (i = c; i < d; i++) {
			ab[j][i] = ' ';
		}
	}
}