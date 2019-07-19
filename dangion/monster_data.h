#pragma once

//技情報
struct Move {
	char move_name[50];		//技の名前
	char move_exp[200];
	int att_point;			//相手に与えるダメージ
	int myself_att;
	int DP_cons;			//技使用時に消費するDP
};

//プレイヤー情報
struct Player {

	int HP;		//現在のHP
	int HP_MAX;	//HPの最大値
	int DP;		//現在のDP
	int DP_MAX;	//DPの最大値

	struct Move m[6];		//1～6の目の技

	int gold;			//所持ゴールド
	int exp;			//現在の経験値
	int max_exp;		//次のレベルまでの必要経験値
};

//モンスター情報
struct Monster {
	char monster_name[50];	//モンスターの名前

	int HP;		//現在のHP
	int HP_MAX;	//HPの最大値
	int DP;		//現在のDP
	int DP_MAX;	//DPの最大値

	struct Move m[6];		//1～6の目の技

	int gold;			//敵が落とすゴールド
	int exp;			//敵から得られる経験値
};

extern int num;

void player_data();

void player_data_set();

void player_data_ini();

extern Move shop_move[6];

extern int s[6];

extern Move moveList[50];

extern int count;

extern Move move0[6];
extern Move move1[6];
extern Move move2[6];
extern Move move3[6];
extern Move move4[6];
extern Player p;
extern Monster monster[22];