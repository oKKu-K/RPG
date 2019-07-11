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
extern Move mon1_move_1{ "�Ȃɂ����Ȃ�Lv.1", "�Ȃɂ������ADP���T���߂�", 0, -5 };
extern Move mon1_move_2{ "�Ȃɂ����Ȃ�Lv.1", "�Ȃɂ������ADP���T���߂�", 0, -5 };
extern Move mon1_move_3{ "�Ȃɂ����Ȃ�Lv.1", "�Ȃɂ������ADP���T���߂�", 0, -5 };
extern Move mon1_move_4{ "�̓�����Lv.1", "����ɏo����+1�̃_���[�W��^���A�����ɂ�2�_���[�W", num + 1, -2 };
extern Move mon1_move_5{ "�Ō�Lv.1", "����ɏo���ڂ̃_���[�W", num, -1 };
extern Move mon1_move_6{ "�Ō�Lv.1", "����ɏo���ڂ̃_���[�W", num, -1 };


//�����X�^�[����
extern struct Monster monster1 { "�X���C��", 10, 10, mon1_move_1, mon1_move_2, mon1_move_3, mon1_move_4, mon1_move_5, mon1_move_6, 10, 10 };		//�X���C��



