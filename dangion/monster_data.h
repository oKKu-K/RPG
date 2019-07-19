#pragma once

//�Z���
struct Move {
	char move_name[50];		//�Z�̖��O
	char move_exp[200];
	int att_point;			//����ɗ^����_���[�W
	int myself_att;
	int DP_cons;			//�Z�g�p���ɏ����DP
};

//�v���C���[���
struct Player {

	int HP;		//���݂�HP
	int HP_MAX;	//HP�̍ő�l
	int DP;		//���݂�DP
	int DP_MAX;	//DP�̍ő�l

	struct Move m[6];		//1�`6�̖ڂ̋Z

	int gold;			//�����S�[���h
	int exp;			//���݂̌o���l
	int max_exp;		//���̃��x���܂ł̕K�v�o���l
};

//�����X�^�[���
struct Monster {
	char monster_name[50];	//�����X�^�[�̖��O

	int HP;		//���݂�HP
	int HP_MAX;	//HP�̍ő�l
	int DP;		//���݂�DP
	int DP_MAX;	//DP�̍ő�l

	struct Move m[6];		//1�`6�̖ڂ̋Z

	int gold;			//�G�����Ƃ��S�[���h
	int exp;			//�G���瓾����o���l
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