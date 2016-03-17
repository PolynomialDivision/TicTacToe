#ifndef FIELD_H
#define FIELD_H


class Field{
public:
	Field();
	int set_field(int x, int y, int player);
	void print(void);
	int player_win(int player);
	int world[3][3];
    void reset_field(void);
private:
	int win_zeile(int player);
	int win_spalte(int player);
	int win_diagonal(int player);
};


#endif
