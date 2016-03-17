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
    if(this->world[x][y] != 0){
        return -1;
    }
    this->world[x][y] = player;
    return 1;
}

int Field::win_zeile(int player){

	int count;
	for(int i = 0; i < 3; i++){
		count = 0;
		for(int j = 0; j < 3; j++){	
			if(this->world[i][j] == player){
				count++;
				if(count == 3){
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
					return 1;
				}
		}		
	}

	count = 0;
	for(int i = 0; i < 3; i++){
		if(this->world[i][3-i] == player){
				count++;
				if(count == 3){
					return 1;
				}
		}			
	}

	return 0;
}

int Field::player_win(int player){
	if(win_diagonal(player)){
		return 1;
	}
	if(win_spalte(player)){
		return 1;
	}
	if(win_zeile(player)){
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
