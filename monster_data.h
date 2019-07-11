#pragma once

//技情報
struct Move {
	char move_name[50];		//技の名前
	char move_exp[200];
	int att_point;			//相手に与えるダメージ
	int DP_cons;			//技使用時に消費するDP
};


//モンスター情報
struct Monster {
	char monster_name[50];	//モンスターの名前

	int HP; //HP
	int DP; //DP

	struct Move m1;		//1の目の技
	struct Move m2;		//2の目の技
	struct Move m3;		//3の目の技
	struct Move m4;		//4の目の技
	struct Move m5;		//5の目の技
	struct Move m6;		//6の目の技

	int gold;			//敵が落とすゴールド
	int exp;			//敵から得られる経験値
};

extern int num;

//モンスター1の技リスト

extern Move move1[6] = {
	{ "なにもしないLv.1", "なにもせず、DPを５ためる", 0, -5 },
	{ "なにもしないLv.1", "なにもせず、DPを５ためる", 0, -5 },
	{ "なにもしないLv.1", "なにもせず、DPを５ためる", 0, -5 },
	{ "体当たりLv.1", "相手に出た目+1のダメージを与え、自分にも2ダメージ", num + 1, -2 },
	{ "打撃Lv.1", "相手に出た目のダメージ", num, -1 },
	{ "打撃Lv.1", "相手に出た目のダメージ", num, -1 }
};


//モンスター生成
extern struct Monster monster1 { "スライム", 10, 10, move1[0], move1[1], move1[2], move1[3], move1[4], move1[5], 10, 10 };		//スライム



