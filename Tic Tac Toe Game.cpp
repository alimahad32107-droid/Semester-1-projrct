#include<iostream>
using namespace std;
char space[9] = {'1','2','3','4','5','6','7','8','9'};
string p1, p2;
int move,player = 1;
char mark,ans;
void board() {
    cout<<"\n"<<space[0]<<"  | "<<space[1]<<" | "<<space[2]<<endl;
    cout<<"___|___|___"<<endl;
    cout<<space[3]<<"  | "<<space[4]<<" |  "<<space[5]<<endl;
    cout<<"___|___|___"<<endl;
    cout<<space[6]<<"  | "<<space[7]<<" | "<<space[8]<<endl;
}

void person1() {
    if (player==1) {
        cout<<"\n"<<p1<<" (X) Enter your move (1-9): ";
        cin>>move;
        mark='X';
         if ((move>=1&&move<=9)&&(space[move-1]!='X'&&space[move-1]!='O')) {
            space[move-1]=mark;
            player=2;
         }else{
            cout<<"Invalid move or space already taken. Try again."<<endl;
            person1();
         }
    }
}
void person2() {
    if (player==2) {
        cout<<"\n"<<p2<<" (O) Enter your move (1-9): ";
        cin>>move;
       mark='O';
        if ((move>=1&&move<=9)&&(space[move-1]!='X'&&space[move-1]!='O')) {
            space[move-1]=mark;
            player=1;
        }else{
            cout<<"Invalid move or space already taken. Try again."<<endl;
            person2();
        }
    }
}
bool checkwin(char n)  {
	
	if(((space[0]==n&&space[0]==space[1]&&space[1]==space[2])||
        (space[3]==n&&space[3]==space[4]&&space[4]==space[5])||
        (space[6]==n&&space[6]==space[7]&&space[7]==space[8])||
     	(space[0]==n&&space[0]==space[3]&&space[3]==space[6])|| 
       	(space[1]==n&&space[1]==space[4]&&space[4]==space[7])||
        (space[2]==n&&space[2]==space[5]&&space[5]==space[8])||
     	(space[0]==n&&space[0]==space[4]&&space[4]==space[8])||
       	(space[2]==n&&space[2]==space[4]&&space[4]==space[6])))
{
	   	if(n=='X'){
	cout<<"\n"<<p1<<" wins! (X)"<< endl;
	return true;
	}
	else {
	cout<<"\n"<<p2<<" wins! (O)"<< endl;
	return true;
	}	
}
return false;
}
bool full() {
    for (int i=0;i<9;i++) {
        if (space[i]!='X' &&space[i]!='O') {
            return false;
        }
    }
    return true;
}
void reset(){
	for(int i=0;i<9;i++)
	space[i]='1'+i;
	player=1;
}
void game() {
    reset();
    system("cls");
    cout<<"\n=== TIC TAC TOE ==="<<endl;
    board();
    int i=0;
    while(i<9)
    {
        if (player==1) {
            person1();
        } else {
            person2();
        }
        system("cls");
        cout << "\n=== TIC TAC TOE ===" << endl;
        board();
		if (checkwin(mark)) 
		{cout<<"\nDo You Want to Play Again(y/n):";
     	cin>>ans;
     	return;
		}
        if (full()) {
            cout<<"\n"<<"It's a draw!"<<endl;
          cout<<"\nDo You Want to Play Again(y/n):";
     	cin>>ans; 
		 return; 
        }
    i++;
	}	  
}
int main()
{
	cout << "\n=== TIC TAC TOE ===" << endl;
    cout << "\nEnter name of 1st Player (X): ";
    cin>>p1;
    cout << "Enter name of 2nd Player (O): ";
    cin>>p2; 
 do{
 	game();
 }while(ans=='y'|| ans=='Y');
 cout<<"\nThanks for Playing."<<endl;
 return 0;
}
