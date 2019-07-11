#pragma once

//�Z���
struct Move {
	char move_name[50];		//�Z�̖��O
	char move_exp[200];
	int att_point;			//����ɗ^����_���[�W
	int DP_cons;			//�Z�g�p���ɏ����DP
};


//�����X�^�[���
struct Monster {
	char monster_name[50];	//�����X�^�[�̖��O

	int HP; //HP
	int DP; //DP

	struct Move m1;		//1�̖ڂ̋Z
	struct Move m2;		//2�̖ڂ̋Z
	struct Move m3;		//3�̖ڂ̋Z
	struct Move m4;		//4�̖ڂ̋Z
	struct Move m5;		//5�̖ڂ̋Z
	struct Move m6;		//6�̖ڂ̋Z

	int gold;			//�G�����Ƃ��S�[���h
	int exp;			//�G���瓾����o���l
};

extern int num;

//�����X�^�[1�̋Z���X�g

extern Move move1[6] = {
	{ "�Ȃɂ����Ȃ�Lv.1", "�Ȃɂ������ADP���T���߂�", 0, -5 },
	{ "�Ȃɂ����Ȃ�Lv.1", "�Ȃɂ������ADP���T���߂�", 0, -5 },
	{ "�Ȃɂ����Ȃ�Lv.1", "�Ȃɂ������ADP���T���߂�", 0, -5 },
	{ "�̓�����Lv.1", "����ɏo����+1�̃_���[�W��^���A�����ɂ�2�_���[�W", num + 1, -2 },
	{ "�Ō�Lv.1", "����ɏo���ڂ̃_���[�W", num, -1 },
	{ "�Ō�Lv.1", "����ɏo���ڂ̃_���[�W", num, -1 }
};


//�����X�^�[����
extern struct Monster monster1 { "�X���C��", 10, 10, move1[0], move1[1], move1[2], move1[3], move1[4], move1[5], 10, 10 };		//�X���C��



