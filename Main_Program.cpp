#include<iostream>
#include<string>
#include<ctime>
#include"LudoGame.h"
using namespace std;

int main(){
	srand(time(0));
	LudoGame game;
	game.play();
}