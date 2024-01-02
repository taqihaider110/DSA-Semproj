#include<iostream>
#include<conio.h>
using namespace std;

#ifndef LUDOPLAYER_H
#define LUDOPLAYER_H

#include"LudoPiece.h"
#include"validate.h"

class Player {
		string Name;
		bool playing=true;
		bool trapped=true;
		bool isComp=false;
	public:
		Piece* pieces[4];
		Player() {
			cout<<"Enter Name of Player: ";
			getline(cin,Name);
			char input;
			while(input!='Y'&&input!='y'&&input!='N'&&input!='n') {
				cout<<"Is "<<Name<<" Computer Controlled? [Y/N]"<<endl;
				cin>>input;
				switch(input) {
					case 'Y':
					case 'y':
						isComp=true;
						break;
					case 'N':
					case 'n':
						isComp=false;
						break;
					default:
						cout<<"Invalid Input, Give Y(yes) or N(no) as answer.\n";
				}
				fflush(stdin);
				cin.clear();
			}
		}
		string getname() {
			return Name;
		}
		bool playstate() {
			return playing;
		}

		bool checkplay() {
			if(pieces[0]->inplay == false && pieces[1]->inplay == false && pieces[2]->inplay == false && pieces[3]->inplay == false ) {
				playing=false;
				return 1;
			}
		}
		int turn(int &z) {
			if(playing) {
				int x;
				int roll;
				int pieceno;
				cout<<"\n---"<<Name<<"'s Turn---\n";
				if(!isComp) {
					cout<<"Press any key to roll..."<<endl;
					getch();
				}
				roll = rand()%6+1;
				do {
					cout<<"You rolled a "<<roll<<"!"<<endl;
					if(trapped && roll!=6) {
						cout<<"No Valid Moves, Turn Skipped!"<<endl;
						return -1;
					}
					if(!isComp) {
						cout<<"Choose which piece to attempt to move:"<<endl;
						for(int i=0; i<4; i++) {
							if(pieces[i]->getpl()) {
								cout<<"Piece #"<<i<<" currently ";
								if(pieces[i]->relpos==-1) {
									cout<<"in jail"<<endl;  //output
								} else {
									cout<<pieces[i]->relpos<<" steps from Start Position."<<endl;
								}
							}
						}
						pieceno = InputValid<int>();
						while(pieceno<0||pieceno>3) {
							cout<<"Incorrect Piece Number, Try Another Integer."<<endl;
							pieceno = InputValid<int>();
						}
					} else {
						do {
							pieceno=rand()%4;
						} while(!(pieces[pieceno]->canmove));
						}
					z = pieceno;  //changes current piece in LudoGame by reference
					x = pieces[pieceno]->move(roll);
					if(x==2) {
						trapped=false;
					}
					if((pieces[0]->inJail||!(pieces[0]->canmove))&&(pieces[1]->inJail|!(pieces[1]->canmove))&&(pieces[2]->inJail||!(pieces[2]->canmove))&&(pieces[3]->inJail||!(pieces[3]->canmove))) {
						trapped=true;
					}
				} while(x == 0 || trapped);
				checkplay();
				return x;
			} else {
				return -1;
			}
		}
};

#endif