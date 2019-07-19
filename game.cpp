

// ConsoleApplication1.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//


//#include "stdafx.h"
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

	getmaxyx(stdscr, h, w);
	y = h / 2 - 2;
	x = (w / 2 - strlen(str1) / 2 - 1);
	mvaddstr(y, x, str1);
	x = (w / 2 - strlen(str2) / 2 - 1);
	mvaddstr(y + 2, x, str2);
	refresh();
}

void dangion_list() {
	int x, y, w, h;
	char dan0[30] = "ダンジョンを選択してください";
	char dan1[15] = "ゴーレムの館";
	char dan2[15] = "トンボの巣";
	char dan3[15] = "さいころリーグ";

	getmaxyx(stdscr, h, w);
	y = h / 2 - 6;
	x = (w / 2 - strlen(dan0) / 2 - 1);
	erase();
	mvaddstr(y, x, dan0);
	mvaddstr(y, x - 30, "戻る：B ");
	y = h / 2 - 2;
	x = (w / 2 - strlen(dan1) / 2 - 1);
	mvaddstr(y, x, dan1);
	mvaddstr(y + 2, x, dan2);
	mvaddstr(y + 4, x, dan3);
	refresh();

}

void dangion_select(){
	int x, y, w, h;
	int key;
	int q = 0;
	int c = 0;
	char dan0[30] = "ダンジョンを選択してください";
	char dan1[15] = "ゴーレムの館";
	char dan2[15] = "トンボの巣";
	char dan3[15] = "さいころリーグ";

	getmaxyx(stdscr, h, w);
	y = h / 2 - 2;
	x = (w / 2 - strlen(dan1) / 2 - 1);

	while (q == 0) {
		attrset(COLOR_PAIR(1));
		mvaddstr(y, x, dan1);
		attrset(COLOR_PAIR(0));

		while (q == 0) {
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
				dangion_list();
				attrset(COLOR_PAIR(1));
				if (c == 0) {
					mvaddstr(y, x, dan1);
				}
				else if (c == 1) {
					mvaddstr(y, x, dan2);
				}
				else if (c == 2) {
					mvaddstr(y, x, dan3);
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
				dangion_list();
				attrset(COLOR_PAIR(1));
				if (c == 0) {
					mvaddstr(y, x, dan1);
				}
				else if (c == 1) {
					mvaddstr(y, x, dan2);
				}
				else if (c == 2) {
					mvaddstr(y, x, dan3);
				}
				attrset(COLOR_PAIR(0));
				break;

			case 'a':
				erase();
				if (y == h / 2 - 2) {
					dangion();
				}
				else if (y == h / 2) {
					dangion();
				}
				else if (y == h / 2 + 2) {
					dangion();
				}
				break;
			case 'b':
				q = 1;
				break;
			}
		}
	}
}


void shop() {
	int x, y, x1, y1, w, h, i;
	int c = 0;
	int key;
	int q = 0;
	char str0[35] = "                                  ";
	char str1[20] = "いらっしゃいませ";
	char str2[20] = "なににしますか？";
	getmaxyx(stdscr, h, w);
	y1 = h / 2 - 10;
	x1 = (w / 2 - strlen(str1) / 2);
	mvaddstr(y1, x1, str1);
	mvprintw(y1 + 1, x1 + 30, "所持ゴールド：%dG", p.gold);
	mvaddstr(y1 + 1, x1 - 30, "メニューに戻る：B ");
	y1 = y1 + 1;
	x1 = (w / 2 - strlen(str2) / 2);
	mvaddstr(y1, x1, str2);

	x = w / 5;
	y = h / 2 - 7;

	for (i = 1; i <= 5; i++) {
		mvprintw(y + 2 * i, x, "%s：%s", shop_move[i - 1].move_name, shop_move[i - 1].move_exp);
	}
	for (i = 1; i <= 5; i++) {
		if (s[i - 1] == 0) {
			mvaddstr(y + 2 * i, x + 55, "SOLD OUT");
		}
		else {
			mvprintw(y + 2 * i, x + 55, "%dG", s[i - 1]);
		}
	}

	while (q == 0) {
		x = w / 5;
		y = y + 2;
		attrset(COLOR_PAIR(1));
		mvprintw(y, x, "%s", shop_move[0].move_name);
		attrset(COLOR_PAIR(0));

		while (q == 0) {
			key = getch();
			switch (key) {
			case KEY_UP:
				mvprintw(y, x, "%s", shop_move[c].move_name);
				y = y - 2;
				c = c - 1;
				if (y <= h / 2 - 5) {
					y = h / 2 - 5;
					c = 0;
				}
				attrset(COLOR_PAIR(1));
				mvprintw(y, x, "%s", shop_move[c].move_name);
				attrset(COLOR_PAIR(0));
				break;
			case KEY_DOWN:
				mvprintw(y, x, "%s", shop_move[c].move_name);
				y = y + 2;
				c = c + 1;
				if (y >= h / 2 + 3) {
					y = h / 2 + 3;
					c = 4;
				}
				attrset(COLOR_PAIR(1));
				mvprintw(y, x, "%s", shop_move[c].move_name);
				attrset(COLOR_PAIR(0));
				break;

			case 'a':
				x1 = (w / 2 - strlen(str2) / 2);
				y1 = h / 2 - 9;
				mvaddstr(y1, x1 - 5, str0);
				x1 = (w / 2 - strlen(str1) / 2);
				y1 = h / 2 - 10;
				mvaddstr(y1, x1 - 5, str0);
				if (p.gold < s[c]) {
					mvaddstr(y1, x1, "所持金が足りません");
				}
				else if (s[c] == 0) {
					mvaddstr(y1, x1 - 1, "すでに購入しています");
				}
				else {
					p.gold = p.gold - s[c];
					moveList[count] = shop_move[c];
					count++;
					mvaddstr(y1 + 1, (w / 2 - strlen(str1) / 2) + 30, str0);
					s[c] = 0;
					mvprintw(y1 + 1, (w / 2 - strlen(str1) / 2) + 30, "所持ゴールド：%dG", p.gold);
					s[c] = 0;
					mvaddstr(y1, x1 - 5, str0);
					mvaddstr(y1, x1 - 3, "お買い上げありがとうございます");
					mvaddstr(y, x + 55, "SOLD OUT");
				}
				break;

			case 'b':
				q = 1;
				break;;
			}
		}
	}
	erase();
	menu();
	attrset(COLOR_PAIR(1));
	x = (w / 2 - strlen("ショップ") / 2 - 1);
	y = h / 2;
	mvaddstr(y, x, "ショップ");
	attrset(COLOR_PAIR(0));
	refresh();
}


int main()
{
	int x = 0, y = 0;
	int w, h;
	int key;
	int c = 0;

	initscr();
	noecho();
	cbreak();
	start_color();
	keypad(stdscr, TRUE);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_CYAN, COLOR_BLACK);

	getmaxyx(stdscr, h, w);

	while (1) {
		menu();
		x = (w / 2 - strlen("ダンジョン") / 2 - 1);
		y = h / 2 - 2;
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
					x = (w / 2 - strlen("ダンジョン") / 2 - 1);
					mvaddstr(y, x, "ダンジョン");
				}
				else if (c == 1) {
					x = (w / 2 - strlen("ショップ") / 2 - 1);
					mvaddstr(y, x, "ショップ");
				}
				attrset(COLOR_PAIR(0));

				break;
			case KEY_DOWN:
				erase();
				y = y + 2;
				c = c + 1;
				if (y >= h / 2) {
					y = h / 2;
					c = 1;
				}
				menu();
				attrset(COLOR_PAIR(1));
				if (c == 0) {
					x = (w / 2 - strlen("ダンジョン") / 2 - 1);
					mvaddstr(y, x, "ダンジョン");
				}
				else if (c == 1) {
					x = (w / 2 - strlen("ショップ") / 2 - 1);
					mvaddstr(y, x, "ショップ");
				}
				attrset(COLOR_PAIR(0));
				break;

			case 'a':
				erase();
				if (y == h / 2 - 2) {
					dangion_list();
					dangion_select();
				}
				else if (y == h / 2) {
					shop();
				}
				break;
			default:
				break;
			}
		}
	}
}
