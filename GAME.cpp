/*Write a C++ program for a rock-paper-scissors game that allows a human player to play against the computer. Use
virtual functions and polymorphism to implement the game. The program should have two classes: Player and
HumanPlayer.
The Player class should be an abstract base class and have a virtual function int makeChoice() that returns the player&#39;s
choice (1 for rock, 2 for paper, 3 for scissors).
The HumanPlayer class should be derived from the Player class and should implement the makeChoice() function by
prompting the user to enter their choice.
The computer&#39;s choice should be generated randomly, and the game should be repeated until the user decides to quit.
At the end of each game, the program should print the choices made by both the user and the computer, and the result
of the game (win, lose, or draw).
Note: You may assume that the user will always enter valid input*/
#include<iostream>
#include<string>
#include<ctime>
using namespace std;
class Player{
	public:
		Player(){
		}
		virtual int makeChoice()=0;
};
class HumanPlayer:public Player{
	public:
		HumanPlayer(){
		}
		int makeChoice(){
			int a;
			cout<<"Enter choice:\n(1-rock)\n(2-Paper)\n(3-scissor)";
			cin>>a;
			return a;
		}
};
class Computerplayer:public Player{
	public:
		Computerplayer(){
		}
		int makeChoice(){
			int a;
			srand(time(0));
			a=1+rand()%3;
			return a;
		}
		
	
};
main(){
	HumanPlayer h;
	int hc;
	int ch;
	Computerplayer c;
	int cc;
	do{
	cout<<"Human turn:\n";
	hc=h.makeChoice();
	
	cout<<"\nComputer turn:";
	cc=c.makeChoice();
	cout<<cc;
	if(hc==1 && cc==1 || hc==2 && cc==2|| hc==3 && cc==3  ){
		if(hc==1){
		cout<<"\nHuman and computer both chose rock";}
		else if(hc==2){
			cout<<"\nHuman and computer both chose paper";
		}
		else{
			cout<<"\nHuman and computer both chose scissor";
		}
	}
	else if(hc==1 && cc==2)
	{
		cout<<"\nCompuer wins";
		cout<<"\nComputer chose paper and human chose rock";
	}
	else if(hc==1 && cc==3){
		cout<<"\nHuman wins";
		cout<<"\nHuman chose rock and computer chose scissor";
	}
	else if(hc==2 && cc==3){
			cout<<"\nComputer wins";
		cout<<"\nHuman chose  paper and computer chose scissor";
	}
	else if(hc==3 && cc==1){
	    cout<<"\nComputer wins";
		cout<<"\nHuman chose scissor and computer chose rock";
	}
		else if(hc==2 && cc==1){
	    cout<<"\nComputer wins";
		cout<<"\nHuman chose paper and computer chose rock";
	}
		else if(hc==3 && cc==2){
	    cout<<"\nComputer wins";
		cout<<"\nHuman chose scissor and computer chose paper";
	}
	cout<<"\nEnter 0 to exit";
	cin>>ch;
	}while(ch!=0);
}
