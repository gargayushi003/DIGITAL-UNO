/* This cpp file will be the main function for the game
   -asking players to play cards into a middle temp deck
   -distributing cards 
   -comparing playable cards and non playable cards 
   -use of wild cards and special action cards
   -show the amount of cards left for each player 
   -a player wins if the number of cards remaining is zero

 will start the game by 
	- asking amount of players
	-creating main deck and temporary deck
*/
#include "card.h"
#include "deck.h"
#include "player.h"
#include <bits/stdc++.h>
using namespace std;

#define clearscreen system("CLS");
#define TEXTFILE "readme.txt"


void stringcat(string st,int k){
    for (int i=0;i<k;i++){
        cout<<st;
    }
}

void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}


void welcome(){
    stringcat("\n",10);
    stringcat(" ",20);
    cout<<(" **       ** ******** **         ******    *******   ****     **** ********\n");
    stringcat(" ",20);
    cout<<("/**      /**/**///// /**        **////**  **/////** /**/**   **/**/**///// \n");
    stringcat(" ",20);
    cout<<("/**   *  /**/**      /**       **    //  **     //**/**//** ** /**/**      \n");
    stringcat(" ",20);
    cout<<("/**  *** /**/******* /**      /**       /**      /**/** //***  /**/******* \n");
    stringcat(" ",20);
    cout<<("/** **/**/**/**////  /**      /**       /**      /**/**  //*   /**/**////  \n");
    stringcat(" ",20);
    cout<<("/**** //****/**      /**      //**    **//**     ** /**   /    /**/**      \n");
    stringcat(" ",20);
    cout<<("/**/   ///**/********/******** //******  //*******  /**        /**/********\n");
    stringcat(" ",20);
    cout<<("//       // //////// ////////   //////    ///////   //         // //////// \n");

	delay(2);
    system("cls");
    stringcat("\n",10);
    stringcat(" ",45);
    cout<<(" **********   *******     \n");
    stringcat(" ",45);
    cout<<("/////**///   **/////**    \n");
    stringcat(" ",45);
    cout<<("    /**     **     //**   \n");
    stringcat(" ",45);
    cout<<("    /**    /**      /**   \n");
    stringcat(" ",45);
    cout<<("    /**    /**      /**   \n");
    stringcat(" ",45);
    cout<<("    /**    //**     **    \n");
    stringcat(" ",45);
    cout<<("    /**     //*******     \n");
    stringcat(" ",45);
    cout<<("    //       ///////      \n");
	delay(2);
    system("cls");
    stringcat("\n",10);
    cout<<"      _____                                                   \n";
    cout<<"     |A .  | _____                                            \n";
    cout<<"     | /.\\ ||A ^  | _____                                    \n";
    cout<<"     |(_._)|| / \\ ||A _  | _____                             \n";
    cout<<"     |  |  || \\ / || ( ) ||A_ _ |                            \n";
    cout<<"     |____V||  .  ||(_'_)||( v )|                             \n";
    cout<<"            |____V||  |  || \\ / |                            \n";
    cout<<"                   |____V||  .  |                             \n";
    cout<<"                          |____V|                             \n";
	delay(2);
    system("cls");
	stringcat("\n",10);
    cout<<"\t\t\t\t\t          _____                                                   \n";
    cout<<"\t\t\t\t\t         |A .  | _____                                            \n";
    cout<<"\t\t\t\t\t         | /.\\ ||A ^  | _____                                    \n";
    cout<<"\t\t\t\t\t         |(_._)|| / \\ ||A _  | _____                             \n";
    cout<<"\t\t\t\t\t         |  |  || \\ / || ( ) ||A_ _ |                            \n";
    cout<<"\t\t\t\t\t         |____V||  .  ||(_'_)||( v )|                             \n";
    cout<<"\t\t\t\t\t                |____V||  |  || \\ / |                            \n";
    cout<<"\t\t\t\t\t                       |____V||  .  |                             \n";
    cout<<"\t\t\t\t\t                              |____V|                             \n";
	delay(2);
	system("cls");
	stringcat("\n",10);
    cout<<"\t\t\t\t\t\t\t\t\t\t               _____                                                   \n";
    cout<<"\t\t\t\t\t\t\t\t\t\t              |A .  | _____                                            \n";
    cout<<"\t\t\t\t\t\t\t\t\t\t              | /.\\ ||A ^  | _____                                    \n";
    cout<<"\t\t\t\t\t\t\t\t\t\t              |(_._)|| / \\ ||A _  | _____                             \n";
    cout<<"\t\t\t\t\t\t\t\t\t\t              |  |  || \\ / || ( ) ||A_ _ |                            \n";
    cout<<"\t\t\t\t\t\t\t\t\t\t              |____V||  .  ||(_'_)||( v )|                             \n";
    cout<<"\t\t\t\t\t\t\t\t\t\t                     |____V||  |  || \\ / |                            \n";
    cout<<"\t\t\t\t\t\t\t\t\t\t                            |____V||  .  |                             \n";
    cout<<"\t\t\t\t\t\t\t\t\t\t                                   |____V|                             \n";
	delay(3);
    system("cls");
	
	cout<<"           _____                    _____                   _______             \n";
	cout<<"          /\\    \\                  /\\    \\                 /::\\    \\              \n";
	cout<<"         /::\\____\\                /::\\____\\               /::::\\    \\              \n";
	cout<<"        /:::/    /               /::::|   |              /::::::\\    \\              \n";
	cout<<"       /:::/    /               /:::::|   |             /::::::::\\    \\             \n";
	cout<<"      /:::/    /               /::::::|   |            /:::/~~\\:::\\    \\            \n";
	cout<<"     /:::/    /               /:::/|::|   |           /:::/    \\:::\\    \\           \n";
	cout<<"    /:::/    /               /:::/ |::|   |          /:::/    / \\:::\\    \\          \n";
	cout<<"   /:::/    /      _____    /:::/  |::|   | _____   /:::/____/   \\:::\\____\\         \n";
	cout<<"  /:::/____/      /\\    \\  /:::/   |::|   |/\\    \\ |:::|    |     |:::|    |        \n";
	cout<<" |:::|    /      /::\\____\\/:: /    |::|   /::\\____\\|:::|____|     |:::|    |        \n";
	cout<<" |:::|____\\     /:::/    /\\::/    /|::|  /:::/    / \\:::\\    \\   /:::/    /         \n";
	cout<<"  \\:::\\    \\   /:::/    /  \\/____/ |::| /:::/    /   \\:::\\    \\ /:::/    /          \n";
	cout<<"   \\:::\\    \\ /:::/    /           |::|/:::/    /     \\:::\\    /:::/    /           \n";
	cout<<"    \\:::\\    /:::/    /            |::::::/    /       \\:::\\__/:::/    /            \n";
	cout<<"     \\:::\\__/:::/    /             |:::::/    /         \\::::::::/    /             \n";
	cout<<"      \\::::::::/    /              |::::/    /           \\::::::/    /              \n";
	cout<<"       \\::::::/    /               /:::/    /             \\::::/    /               \n";
	cout<<"        \\::::/    /               /:::/    /               \\::/____/                \n";
	cout<<"         \\::/____/                \\::/    /                 ~~                    \n";
	cout<<"          ~~                       \\/____/                                    \n"; 
	stringcat("\n",3);                                                         

}

void display_intro(string filename)
{
	string line;
	fstream myfile;
	myfile.open(filename.c_str());
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			cout << line << endl;
		}
		myfile.close();
	}
	else
	{
		cout << "error unable to open file " << endl;
	}
}
#define PRINT_ALL_PLAYERS 0
#define TEMP_DECK 1
#define TURN 2
void whose_turn(int x)
{
	cout << "Confirm Player" << x << " by typing "
		 << "'" << x << "'"
		 << " and pressing enter"
		 << ": ";
	int temp=999;
	while (temp != x)
	{	if (temp!=999){
		cout<<"It seems you dont want to play the game :(";}
		cin >> temp;
	}
}
COLOR FromString(const string &str)
{
	if (str == "red")
		return red;
	else if (str == "green")
		return green;
	else if (str == "blue")
		return blue;
	else if (str == "yellow")
		return yellow;
	else
		return wild;
}

int main()
{
	//clear screen
	clearscreen
	welcome();
	//display an introduction to the game in the beginning
	display_intro(TEXTFILE);
	//ask user for amount of players
	int amount_players;
	int flag = 0;
	while (flag == 0)
	{
		cout << "Please enter amount of players: ";
		cin >> amount_players;
		if (amount_players >= 2 && amount_players <= 5)
		{	cout<<"*";
			stringcat("--",20);
			cout<<"*\n";
			cout << amount_players << " players entering game .... " << endl;
			flag = 1;
			break;
		}
		else
		{
			cout << "invalid amount of players" << endl;
		}
	}
	//creating deck
	deck main_deck;
	main_deck.create();
	main_deck.quick_shuffle();
	//creating player array
	player *play_array;
	play_array = new player[amount_players];
	//distributing 7 starting cards to each player
	for (int i = 0; i < amount_players; i++)
	{
		for (int k = 0; k < 7; k++)
		{
			card temp_card;
			temp_card = main_deck.draw();
			play_array[i].hand_add(temp_card);
		}
	}
	//all cards that are played will go to temp_deck
	deck temp_deck;
	//create the first starting card, by drawing from deck
	card played_card;
	card temp_card;
	int card_flag = 0;
	while (card_flag == 0) //Only non wild cards are drawn first
	{
		temp_card = main_deck.draw();
		if (temp_card.color != wild)
		{
			card_flag = 1;
			played_card = temp_card;
		}
		else
		{
			temp_deck.add_card(temp_card);
		}
	}
	//randomize who starts first
	srand(time(NULL));
	int turn = rand() % amount_players;
	cout << "PLAYER " << turn << " is randomly selected to play first" << endl;
	whose_turn(turn);

	bool force_draw_bool = false;
	int turn_flag = 1;
	int win = 0;
	//keep playing until a player wins
	while (win == 0)
	{
		clearscreen // clear screen
		player *curr_player = &play_array[turn % amount_players];
		// checked for forced draw cards
		cout << "PLAYER " << turn % amount_players << endl;
		if (force_draw_bool)
		{
			if (played_card.number == 10) // checked for Draw-2
			{
				cout << "Forced Draw-2" << endl;
				card draw_2;
				for (int i = 0; i < 2; i++)
				{
					draw_2 = main_deck.draw();
					curr_player->hand_add(draw_2);
				}
			}
			if (played_card.number == 14) // checked for Draw-4
			{
				cout << "Forced Draw-4" << endl;
				card draw_4;
				for (int i = 0; i < 4; i++)
				{
					draw_4 = main_deck.draw();
					curr_player->hand_add(draw_4);
				}
			}
			force_draw_bool = false;
		}
		// print out the cards remaining for each player
		cout<<"*";
		stringcat("--",20);
		cout<<"*\n";
		cout << "Cards remaining for each player: " << endl;
		for (int i = 0; i < amount_players; i++)
		{
			cout << "PLAYER " << i << ": " << play_array[i].get_size() << "   ";
		}
		cout << endl;
		cout << "Played Card: " << played_card << endl;
		// print out cards in player's hand
		cout << "PLAYER " << turn % amount_players << endl;
		cout<<"*";
		stringcat("--",20);
		cout<<"*\n";
		curr_player->print();
		int check_flag = 0;
		int index;
		int size = curr_player->get_size();
		// ask for which card to play into middle
		while (check_flag == 0)
		{	
			cout<<"*";
			stringcat("--",20);
			cout<<"*\n";
			cout << "which card do you want to play? " << endl;
			cout << "If you want to draw a card please enter '-1' " << endl;
			cout << "Type the index of the card and press enter: ";
			cin >> index;
			if (index == -1) //check if index is to draw a card
			{
				card draw_temp;
				draw_temp = main_deck.draw();
				cout << "DRAWN CARD: " << draw_temp << endl;
				if (draw_temp == played_card && draw_temp.color != wild)
				{
					int play_draw_flag = 0;
					while (play_draw_flag == 0) //check for playing the drawn card
					{
						string temp_play;
						cout << "Do you want to play the drawn card [y/n] : ";
						cin >> temp_play;
						if (temp_play == "y")
						{
							played_card = draw_temp;
							temp_deck.add_card(draw_temp);
							if (played_card.number >= 10 && played_card.number <= 14)
							{
								force_draw_bool = true;
							}
							play_draw_flag = 1;
						}
						if (temp_play == "n")
						{
							curr_player->hand_add(draw_temp);
							play_draw_flag = 1;
						}
					}
				}
				else
				{
					curr_player->hand_add(draw_temp);
				}
				check_flag = 1;
			}
			//if the player wants to play a card from his hand
			if (index >= 0 && index < size)
			{
				// check if card is compatilbe with played card
				card temp = curr_player->peek(index);
				if (temp == played_card)
				{
					curr_player->hand_remove(index);
					temp_deck.add_card(temp);
					played_card = temp;
					if (played_card.color == wild) //if played card is wild
					{
						int check_color = 0;
						COLOR temp_color;
						string str_color;
						while (check_color == 0)
						{ // ask for new color
							cout << "Please choose a color (red , green, blue, yellow) :";
							cin >> str_color;
							temp_color = FromString(str_color);
							if (temp_color != wild)
							{
								played_card.color = temp_color;
								check_color = 1;
							}
							else
							{
								cout << "invalid color" << endl;
							}
						}
					}
					if (played_card.number >= 10 && played_card.number <= 14)
					{
						force_draw_bool = true;
					}
					check_flag = 1;
				}
				else
				{
					cout << "card cannot be played " << endl;
				}
			}
			else
			{
				cout << "invalid index " << endl;
			}
		}
		// check if there is a winner, and break while loop
		if (curr_player->get_size() == 0)
		{
			win = 1;
			cout << "PLAYER " << turn % amount_players << " has won the game." << endl;
			
			break;
		}
		// check for action cards that influence the turn here
		if (played_card.number == 11 && force_draw_bool == true) // skip case
		{
			if (turn_flag == 1)
				turn = turn + 2;
			else
				turn = turn - 2;
		}
		else if (played_card.number == 12 && force_draw_bool == true) // reverse case
		{															  // if only two players, behaves like a skip card
			if (amount_players == 2)
			{
				turn = turn + 2;
			}
			else
			{ // changes the rotation of game (from CW to CCW or vice versa)
				if (turn_flag == 1)
				{
					turn_flag = -1;
					turn--;
				}
				else
				{
					turn_flag = 1;
					turn++;
				}
			}
		}
		// for other cards
		else
		{
			if (turn_flag == 1)
				turn++;
			else
				turn--;
		}
		clearscreen
		// print out the cards remaining for each player
		cout<<"*";
		stringcat("--",20);
		cout<<"*\n";
		cout << "Cards remaining for each player: " << endl;
		for (int i = 0; i < amount_players; i++)
		{
			cout << "PLAYER " << i << ": " << play_array[i].get_size() << "   ";
		}
		cout << endl;
		// print out the temporary card
		cout << "Played Card: " << played_card << endl;
		whose_turn(turn % amount_players);
	}
	return 0;
}
