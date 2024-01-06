#include<iostream>
using namespace std;

#ifndef LUDOPIECE_H
#define LUDOPIECE_H

#include"LudoNode.h"

class Piece {
	public:
		const Node* win;  //place where piece is scored
		Node* start;	//Jail Location
		Node* position; //piece position
		string team;	//color/team of piece
		int relpos=-1;	//distance from starting point
		bool inplay=true;	//Shows that this piece is ready to play (not win)
		bool inJail=true;	//Shows that this piece is INSIDE jail
		bool canmove=true;	//Shows that this piece's turn is valid or not
		
		Piece(string t="",Node* pos=NULL, Node* w=NULL):team(t),position(pos),win(w),start(pos) {}
		
		int getcaptured(){
			(*(position->piececount))--;
			position = start;
			relpos=-1; 
			inJail=true;
			return 3;
		}
		int getpl(){
			return inplay;
		}
		int getpos(){
			return relpos;
		}
		
		int move(int roll) {
			canmove=true;
			if(inplay) {
				if(!inJail) {
					Node* startpos=position;
					int startrel = relpos;
					(*(position->piececount))--;
					int steps=0;
					while(steps<roll) {
						if (ExtendedColoredNode* extraNode = dynamic_cast<ExtendedColoredNode*>(position)) {
							if (extraNode->color == team) {
								position=extraNode->home;
								relpos++;
							}
							else{
								position=position->next;
								relpos++;
							}
						}
						 else {
							if(position->next != win) {
								position=position->next;
								relpos++;
							} else {
								if(roll-steps>1) {
									position=startpos;
									relpos=startrel;
									(*(position->piececount))++;
									canmove=false;
									return 0;
								} else {
									position=position->next;
									relpos++;
									(*(position->piececount))++;
									inplay=false;
									canmove=false;
									return 1;
								}
							}
						}
						steps++;
					}
					(*(position->piececount))++;
					return 1;
				} else {
					if(roll==6) {
						position=position->next;
						relpos++;
						inJail=false;
						(*(position->piececount))++;
						return 2;
					} else {
						cout<<"\n\nInvalid Move (Roll not high enough to Free a Piece).\nPlease Choose Another Piece."<<endl;
						return 0;
					}
				}
			} else {
				cout<<"This Piece is not In Play, Choose Another Piece."<<endl;
				return 0;
			}
		}

};

#endif