#include <field.h>
#include <iostream>
#include <cstdlib>

using namespace std;

Field::Field(void){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			this->world[i][j] = 0;
		}
	}
}

int Field::set_field(int x, int y, int player){
	this->world[x][y] = player;
}

int Field::win_zeile(int player){

	int count;
	for(int i = 0; i < 3; i++){
		count = 0;
		for(int j = 0; j < 3; j++){	
			if(this->world[i][j] == player){
				count++;
				if(count == 3){
					cout << "Win zeile" << endl;
					return 1;
				}
			}
		}
	}
	return 0;
}

int Field::win_spalte(int player){

	int count;
	for(int i = 0; i < 3; i++){
		count = 0;
		for(int j = 0; j < 3; j++){	
			if(this->world[j][i] == player){
				count++;
				if(count == 3){
					cout << "Win spalte" << endl;
					return 1;
				}
			}
		}
	}
	return 0;
}

int Field::win_diagonal(int player){

	int count = 0;
	for(int i = 0; i < 3; i++){
		if(this->world[i][i] == player){
				count++;
				if(count == 3){
					cout << "Win win_diagonal" << endl;
					return 1;
				}
		}		
	}
	//cout << "Win win_diagonal" << endl;

	count = 0;
	for(int i = 0; i < 3; i++){
		if(this->world[i][3-i] == player){
				count++;
				if(count == 3){
					cout << "Win win_diagonal" << endl;
					return 1;
				}
		}			
	}

	return 0;
	//cout << "Win win_diagonal" << endl;
}

int Field::player_win(int player){
	if(win_diagonal(player)){
		cout << "Win win_diagonal" << endl;
		return 1;
	}
	if(win_spalte(player)){
		cout << "Win spalte" << endl;
		return 1;
	}
	if(win_zeile(player)){
		cout << "Win zeile" << endl;
		return 1;
	}
	return 0;
}

void Field::print(void){
	//write(1,"\E[H\E[2J",7);
	std::system("clear");
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(this->world[i][j] == 0){
				cout << " ";
			} else if(this->world[i][j] == 1){
				cout << "X";
			} else if(this->world[i][j] == 2){
				cout << "O";
			}
			if(j == 2){
				cout << endl;
			} else {
				cout << "|";
			}
		}
	}	
}