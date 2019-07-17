
//#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<curses.h>
#include<Windows.h>
#include "monster_data.h"
#include "battle.h"
#include "dangion.h"

#define BUFFSIZE 1024

void menu() 
{
	int x, y, w, h;
	char str1[11] = "ダンジョン";
	char str2[10] = "ショップ";
	char str3[10] = "そうび";
	getmaxyx(stdscr, h, w);
	y = h/2 - 2;
	x = (w/2 - strlen(str1)/2);
	mvaddstr(y, x, str1);
	x = (w/2 - strlen(str2)/2);
	mvaddstr(y+2, x, str2);
	x = (w/2 - strlen(str3)/2);
	mvaddstr(y+4, x, str3);
	refresh();
}

void shop() {
	int x, y, w, h;
	char str[20] = "いらっしゃいませ";
	getmaxyx(stdscr, h, w);
	y = h / 2 - 10;
	x = (w / 2 - strlen(str) / 2);
	mvaddstr(y, x, str);

}

void equip() {
	int i ,x ,y ,h ,w;
	getmaxyx(stdscr, h, w);
	y = h / 2 - 5;
	x = w / 5;
	mvaddstr(y, x+3, "そうび技");
	y = y + 2;
	for (i = 1; i <= 6; i++) {
		mvprintw(y + i, x, "%d:%s", i, p.m[i - 1].move_name);
	}
}

int main()
{
	int x = 0, y = 0;
	int w, h;
	int c = 0;

	initscr();
	noecho();
	cbreak();
	start_color();
	keypad(stdscr, TRUE);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_CYAN, COLOR_BLACK);

	getmaxyx(stdscr, h, w);

	while(1){
		menu();
		x = (w / 2 - strlen("ダンジョン") / 2);
		y = h/2 - 2 ;
		attrset(COLOR_PAIR(1));
		mvaddstr(y, x, "ダンジョン");
		attrset(COLOR_PAIR(0));

		while (TRUE) {

			key = getch();
			switch (key) {
			case KEY_UP:
				erase();
				y = y - 2;
				c = c - 1;
				if (y <= h / 2 - 2) {
					y = h / 2 - 2;
					c = 0;
				}
				menu();
				attrset(COLOR_PAIR(1));
				if (c == 0) {
					x = (w / 2 - strlen("ダンジョン") / 2);
					mvaddstr(y, x, "ダンジョン");
				}
				else if (c == 1) {
					x = (w / 2 - strlen("ショップ") / 2);
					mvaddstr(y, x, "ショップ");
				}
				else if (c == 2) {
					x = (w / 2 - strlen("そうび") / 2);
					mvaddstr(y, x, "そうび");
				}
				attrset(COLOR_PAIR(0));

				break;
			case KEY_DOWN:
				erase();
				y = y + 2;
				c = c + 1;
				if (y >= h / 2 + 2) {
					y = h / 2 + 2;
					c = 2;
				}
				menu();
				attrset(COLOR_PAIR(1));
				if (c == 0) {
					x = (w / 2 - strlen("ダンジョン") / 2);
					mvaddstr(y, x, "ダンジョン");
				}
				else if (c == 1) {
					x = (w / 2 - strlen("ショップ") / 2);
					mvaddstr(y, x, "ショップ");
				}
				else if (c == 2) {
					x = (w / 2 - strlen("そうび") / 2);
					mvaddstr(y, x, "そうび");
				}
				attrset(COLOR_PAIR(0));
				break;

			case 'a':
				erase();
				if (y == h / 2 - 2) {
					dangion();
				}
				else if (y == h / 2) {
					shop();
				}
				else {
					equip();
				}
				break;
			default:
				break;
			}
		}

		

	}
}

