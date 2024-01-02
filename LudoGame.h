#ifndef LUDOGAME_H
#define LUDOGAME_H

#include "LudoBoard.h"
#include "LudoPlayer.h"


class LudoGame {
		const string colors[4] = {"red", "green", "purple", "blue"};
		Board* curr_board;
		string WinOrder[4];
		int i=0;
		Player* players[4];
		int curr_piece;
	public:
		LudoGame():curr_board(new Board) {
			for(int i=0; i<4; i++) {
				players[i]=new Player;
				for(int j=0; j<4; j++) {
					players[i]->pieces[j]=new Piece(colors[i],curr_board->colorjails[i],curr_board->win);
				}
			}
		}

		void checkcaptures(int cp,int t) {
			for(int i=0; i<3; i++) {
				for(int j=0; j<4; j++) {
					if(players[t]->pieces[cp]->position == players[(t+1+i)%4]->pieces[j]->position) {
						players[(t+i+1)%4]->pieces[j]->getcaptured();
						curr_board->updatejail((t+i+1)%4,3);
					}
				}
			}
		}

		void play() {
			int turns=0;
			int p=-1;
			bool activegame=true;
			while(activegame) {
				curr_board->display();
				p=players[turns]->turn(curr_piece);
				if(p==2) {
					curr_board->updatejail(turns,2);
				}
				if(!(players[turns]->playstate())) {
					WinOrder[i++]=players[turns]->getname();
				}
				if(players[0]->playstate()||players[1]->playstate()||players[2]->playstate()||players[3]->playstate()) {
					activegame=true;
				} else {
					activegame=false;
				}
				checkcaptures(curr_piece,turns);
				turns = (turns+1)%4;
			}
		}
};

#endif