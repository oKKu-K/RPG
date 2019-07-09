// myGame1.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <curses.h>
#include "Setting.h"

#define BUFFSIZE 1024


int main() {
	int i = 1;
	int key = 0;
	
	if (initscr() == NULL) {
		return 1;
	}

	keypad(stdscr, TRUE);
	cbreak();
	noecho();
	while (1) {
		while (1) {
			key = getch();
			i++;
			if (i > 6) {
				i = 1;
			}
			mvprintw(5, 5, "%d", 1);
			refresh();
			if (key == 'a') {
				break;
			}
		}
		while (1) {
		}
	}
}