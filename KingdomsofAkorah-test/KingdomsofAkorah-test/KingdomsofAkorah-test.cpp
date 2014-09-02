//Project: "Kingdoms of Akorah!"
//Game Type: Text
//Game Genre: Role Playing Game
//By: Jared Ramey
//
//Any and all comments made by: Jared Ramey
//Contributors:
//		(Will list as people help/ code is inserted)
//		
//Default Libraries & Headers
#include "stdafx.h"
#include <iostream>
#include <string>
#include <time.h>
//My Header's
#include "MapMovment.h"

using namespace std;

//Global Variables
//Integers
//Ints needed for fight loop
int tmob, num1, num2, mobhlth, smlat, input, plyratt, mobatt, chance, mobchance;
int HIGH = 10;
int LOW = 1;
int plyrhlth = 20;
int medat = 10;
int lrgat = 5;
//Need to play around with these two..
int Hlth, Spd, Strgth;
//Ect ints
int x = 1;
int z = 1;
int inven = 1;
int choice;
int newlocation;
int tmpplyrlocation;
int playerlocation=1;
int forest1[5][5];
int y = 1;
int wlk;
//Strings
string surounding;
string mob;
string user;
string user2;
string plynm;
string ccy;
string food[9];
string tempfood;
string plycls;
//booleans

//Functions
//PlyrInv in beta stage
	void PlyrInv()
{
	while (inven == 1)
	{
		cout << "You look into your Satchel....\n";
		getchar();
		cout << "What do you wish to do?\n";
		cout << "1: Look through the Food pouch\n";
		cout << "2: Look through the Potions case\n";
		cout << "3: Look through the Armour flap\n";
		cout << "4: Look through the Weapons holster\n";
		cout << "5: Exit Satchel\n";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "You look into your food pocket.....\n";
			getchar();
			food[0] = "Berries";
			tempfood = food[0];
			cout << "1: ";
			printf("%s\n", tempfood);
			getchar();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			inven++;
			break;
		}
	}
}
//Fight function
	void FghtLp()
	{
		cout << "   " << endl;
        cout << "   " << endl;
        cout << "Let us start the fight then..." << endl;
        cout << "You have 20hp, be carefull out there." << endl;
		cin.get();
        time_t seconds;
        time(&seconds);
        srand((unsigned int) seconds);
        num2 = rand() % (HIGH - LOW + 1) + LOW;
        cout << "   " << endl;

                if(num2 == 1)
                {
					tmob = 2;
                    mobhlth = 10;
                    mob = "troll";
                    cout << "A wild Troll with " << mobhlth << "hp has attacked!" << endl;
                    cout << "" << endl;
                }

                    else if( num2 == 2 || num2 == 3 || num2 == 4 )
                    {
                        mobhlth = 20;
                        cout << "A wild Orc with " << mobhlth << "hp has attacked!" << endl;
                        cout << "" << endl;
                        mob = "Orc";
						tmob = 1;
                    }

                        else{
                                mobhlth = 15;
                                cout << "A Bandit with " << mobhlth << "hp has attacked!" << endl;
                                cout << "" << endl;
                                mob = "Bandit";
								tmob = 0;
                            }

                while( mobhlth >= 1 && plyrhlth >= 1 )
                {
                    cout << "" << endl;
                    cout << "What will you do?" << endl;
                    cout << "1: Small attack (1 dmg)" << endl;
                    cout << "2: Medium attack (2 dmg) [" << medat << "]" << endl;
                    cout << "3: Large attack (3 dmg) [" << lrgat << "]" << endl;
                    cin >> plyratt;
                    cin.ignore();

                        if(plyratt == 1)
                        {
                            cout << "you swung for 1 damage!" << endl;
                                    mobhlth--;
                                    cout << "You hit for 1 damage!" << endl;
									cin.get();
                                    cout << "The " << mob << "'s health is " << mobhlth << "hp." << endl;
                        }
                            else if(plyratt == 2)
                            {
                            if( medat >= 1)
                            {
                                cout << "You swung for 2 damage!" << endl;
                                time_t seconds;
                                time(&seconds);
                                srand((unsigned int) seconds);
                                chance = rand() % (HIGH - LOW + 1) + LOW;
                                    if( chance == 1 || chance == 2 || chance == 3 || chance == 4 || chance == 5){
                                        mobhlth--;
                                        mobhlth--;
                                        cout << "" << endl;
                                        cout << "You hit for 2 damage!" << endl;
                                        cin.get();
                                    cout << "The " << mob << "'s health is " << mobhlth << "hp." << endl;
                                   }

                                   else if(chance == 6 || chance == 7 || chance == 8)
                                   {
                                       cout << "You missed! The " << mob << " is still at " << mobhlth << "hp!" << endl;
                                   }
                                medat--;
                            }

                                        else if( medat < 1)
                                        {
                                            cout << "" <<  endl;
                                            cout << "You have run out of power for that attack!" << endl;
                                        }


                            }
                                else{
                                    if(lrgat >= 1)
                                    {
                                        cout << "You swung for 3 damage!" << endl;
                                        time_t seconds;
                                        time(&seconds);
                                        srand((unsigned int) seconds);
                                        chance = rand() % (HIGH - LOW + 1) + LOW;
                                                if( chance == 1 || chance == 2 || chance == 3 || chance == 4 || chance == 5){
                                                    mobhlth--;
                                                    mobhlth--;
                                                    mobhlth--;
                                                    cout << "" << endl;
                                                    cout << "You hit for 3 damage!" << endl;
                                                    cout << "The " << mob << "'s health is " << mobhlth << "hp." << endl;
                                   }
                                   else if(chance == 6 || chance == 7 || chance == 8)
                                   {
                                       cout << "You missed! The " << mob << " is still at " << mobhlth << "hp!" << endl;
                                   }
                                   lrgat--;
                                    }

                                        else if( lrgat < 1)
                                        {
                                            cout << "" << endl;
                                            cout << "You have run out of power for that attack!" << endl;
                                        }

                                    }

                cout << "" << endl;
                cout << "It is the " << mob << "'s turn..." << endl;
                time_t seconds;
                time(&seconds);
                srand((unsigned int) seconds);
                num1 = rand() % (HIGH - LOW + 1) + LOW;

                    if( num1 == 1 )
                    {
                        cout << "The " << mob << " swung for 3 damage!" << endl;
                        time_t seconds;
                        time(&seconds);
                        srand((unsigned int) seconds);
                        mobchance = rand() % (HIGH - LOW + 1) + LOW;
                            if(mobchance == 1 || mobchance == 2 || mobchance == 3 || mobchance == 4 || mobchance == 5)
                            {
                                cout << "The " << mob << " hit for 3 damage!" << endl;
								plyrhlth--;
                                plyrhlth--;
                                plyrhlth--;
                            }

                                else if(mobchance == 6 || mobchance == 7|| mobchance == 8)
                                {
                                    cout << "The " << mob << " missed it's attack!" << endl;
                                }
                        cout << "You have " << plyrhlth << "hp left!" << endl;
                        cout << "" << endl;
                    }

                        else if( num1 == 2 || num1 == 3 || num1 == 4 )
                        {
                            cout << "The " << mob << " swung for 2 damage!" << endl;
                            time_t seconds;
                            time(&seconds);
                            srand((unsigned int) seconds);
                            mobchance = rand() & (HIGH - LOW + 1) + LOW;

                                if(mobchance == 1 || mobchance == 2 || mobchance == 3 || mobchance == 4 || mobchance == 5)
                                {

                                    cout << "The " << mob << " hit for 2 damage!" << endl;
                                    plyrhlth--;
                                    plyrhlth--;
                                }

                                else if(mobchance == 6 || mobchance == 7 || mobchance == 8)
                                {
                                    cout << "The " << mob << " missed it's attack!" << endl;
                                }

                            cout << "You have " << plyrhlth << "hp left!" << endl;
                            cout << "" << endl;
							
                        }

                            else{
                                    cout << "The " << mob << " swung for 1 damage!" << endl;
                                    time_t seconds;
                                    time(&seconds);
                                    srand((unsigned int) seconds);
                                    mobchance = rand() & (HIGH - LOW + 1) + LOW;
                                        if(mobchance == 1 || mobchance == 2 || mobchance == 3 || mobchance == 4 || mobchance == 5)
                                        {
                                            cout << "" << endl;
                                            cout << "The " << mob << " hit for 1 damage!" << endl;
                                            plyrhlth--;
                                        }
                                            else(mobchance == 6 || mobchance == 7 || mobchance == 8);
                                            {
                                                cout << "The " << mob << " missed his attack!" << endl;
                                            }
                                    cout << "You have " << plyrhlth << "hp left!" << endl;
                                    cout << "" << endl;

										
										
                                }
						
							
									if(tmob == 2){
										if(mobhlth<10)
											{
											mobhlth++;
											mobhlth++;
											cout << "The " << mob << " regenerated! It's now at " << mobhlth << "!";
											}
									}
									else{
										cout << "" << endl;
									}
                }

                while(x == 1)
                {
                    x--;
                    if(mobhlth < 1 && plyrhlth > 0)
                    {
                        cout << "--------------------------------------------" << endl;
                        cout << "--------------------------------------------" << endl;
                        cout << "The " << mob << " has been defeated! Horrah!" << endl;
                    }

                        else if(mobhlth > 0 && plyrhlth <= 0)
                        {
                            cout << "" << endl;
                            cout << "" << endl;
                            cout << "The " << mob << " has defeated you! No!" << endl;
                        }
                  }


            if( input == 2 )
            {
                cout << "Why are you here then?" << endl;
                cout << "" << endl;
                cout << "" << endl;
            }

            lrgat = 5;
            medat = 10;

            cout << "So ends this game, if you have any suggestions for the creator then tell him!" << endl;
            cin.ignore();
            cout << "If you wish to play again then replay!" << endl;
            cout << "" << endl;
            cout << "Do you wish to play again?" << endl;
            cout << "Yes (To play again)" << endl;
            cout << "No (To stop the program)" << endl;
            cin >> user2;
            cin.ignore();

                if( user2 == "No" || user2 == "no")
                {
                    z--;
                }
		}
//Figure out how to loop this on screen while other things occur...
	void screenloop()
{
	cout << "\t\t||==================================================||\n";
	cout << "\t\t||              The Kingdom of Akorah!              ||\n";
	cout << "\t\t||                   By: Jared R.                   ||\n";
	cout << "\t\t||                 Started: 10/14/13                ||\n";
	cout << "\t\t||==================================================||\n\n";
	cout << "================================================================================\n\n";

}
//Need to learn how to move in 2D array...
	void wlkcycle()
	{
		void Location();

		bool wlkfwd;
		bool wlkbck;
		bool wlklft;
		bool wlkrght;
		int wlk;
		string walkchc;

	while(y==1)
	{
		//scan to see if player can move foward
		if((tmpplyrlocation-5) == 1 || (tmpplyrlocation-5) == 2 || (tmpplyrlocation-5) == 3)
			{
				wlkfwd = true;
				wlk++;
			}
				else
				{
					wlkfwd = false;
				}

//scan to see if player can move back
if((tmpplyrlocation+5)==1 || (tmpplyrlocation+5)==2 || (tmpplyrlocation+5)==3)
{
wlkbck = true;
wlk++;
}
else
{
wlkbck = false;
}

//scan to see if player can move to the right
if((tmpplyrlocation+1) == 1 || (tmpplyrlocation+1) == 2|| (tmpplyrlocation+1) == 3)
{
wlkrght = true;
wlk++;
}
else
{
wlkrght = false;
}

//scan to see if player can move left
if((tmpplyrlocation-1) == 1 || (tmpplyrlocation-1) == 2 || (tmpplyrlocation-1) == 3)
{
wlklft = true;
wlk++;
}
else
{
wlklft = false;
}

//start player on walking through map

if(tmpplyrlocation ==2)
{
cout << "You find yourself in a " << surounding << "..../n";
getchar();
}

cout << "You can walk in " << wlk <<" different ways./";
getchar();

	if(wlkfwd == true)
	{
		cout << "You can walk Foward./n";
	}
		if(wlkbck == true)
		{
			cout << "You can walk Backwards./n";
		}
			if(wlklft == true)
				{
					cout << "You can walk Left./n";
				}
					if(wlkrght==true)
						{
							cout << "You can walk Right./n";
						}
	cout << "Which way do you want to walk?/n";
	cout << "*hint* /n Foward = 1/n Backwards = 2/n Left = 3/n Right = 4/n";
	getchar();
	cin >> wlk;

	switch (wlk)
		{
		case 1:
			newlocation = tmpplyrlocation-5;
			break;

		case 2:
			newlocation = tmpplyrlocation+5;
			break;

		case 3:
			newlocation = tmpplyrlocation-1;
			break;

		case 4:
			newlocation = tmpplyrlocation+1;
			break;
		}


	}
}
	void Location(int playerlocation)
{
	//Function for all of the maps
	if (playerlocation == 1)
	{
		int forest1[5][5] =
		{ 0, 0, 0, 0, 0,
		0, 3, 0, 1, 0,
		0, 1, 1, 1, 0,
		0, 0, 0, 1, 0,
		0, 0, 0, 2, 0, };

		surounding = "Forest";
		tmpplyrlocation = forest1[3][5];
	}


}

//Main Loop
int _tmain(int argc, _TCHAR* argv[])
{

//Move these up top with rest of ints?
	int classchoice;
	int frstlp = 1;

	//Begining of Game
	cout << "\t\t||==================================================||\n";
	cout << "\t\t||              The Kingdom of Akorah!              ||\n";
	cout << "\t\t||                   By: Jared R.                   ||\n";
	cout << "\t\t||                 Started: 10/14/13                ||\n";
	cout << "\t\t||==================================================||\n\n\n\n";
	//Get user name
	cout << "Welcome To 'The Kingdom of Akorah!'\n";
	cout << "What is your name my fellow knight?\n";
	cin >> plynm;
	cout << "Hm.... " << plynm << " is it?\n";
	cout << "Tis a fine name indeed! Welcome to the Kingdom of Akorah!\n";
	system("PAUSE");

	while (frstlp == 1)
	{
		//choose a class
		system("CLS");
		screenloop();
		cout << "What race are you?\n";
		cout << "1: Human\n";
		cout << "2: Elf\n";
		cout << "3: Dwarf\n";
		cin >> classchoice;

		switch (classchoice)
		{
		case 1:
			cout << "Ah.. The good ol' human race. Not the Strongest, Not the Fastest, but their Willpower is higher than any other race in Akorah!\n";
			plycls = "Human";
			//Put some code here to change stats
			break;

		case 2:
			cout << "Ah.. The Majestic Elf, what they lack in willpower or strength they make up for in speed. They are faster then any race and can react faster then anyone else.\n";
			plycls = "Elf";
			//Put some code here to change stats
			break;

		case 3:
			cout << "Ah.. The hardy Dwarf, stuborn as a mule and stronger than any other race on Akorah. What they lack in speed they make up for in mighty shows of strength!\n";
			plycls = "Dwarf";
			//Put some code here to change stats
			break;
		}

		//confirm class choice, let the player look through descriptions
		cout << "Are you sure you want to be " << plycls << "?\n";
		cin >> ccy;

		if (ccy == 'Yes' || ccy == 'yes')
		{
			cout << "Excellent! You are now a " << plycls << "! \n";
			frstlp--;
			system("PAUSE");
			system("CLS");
		}

		else if (ccy == 'No' || ccy == 'no')
		{
			cout << "Then pick a race already!\n";
			system("PAUSE");
			system("CLS");
		}
	}

	cout << "\t\t||==================================================||\n";
	cout << "\t\t||              The Kingdom of Akorah!              ||\n";
	cout << "\t\t||                   By: Jared R.                   ||\n";
	cout << "\t\t||                 Started: 10/14/13                ||\n";
	cout << "\t\t||==================================================||\n\n\n\n";
	//Need to clean this up... Looks messy when compiled
	cout << "Let us begin your journey then....\n";
	cout << "It all started the day a little baby " << plycls << " was born.";
	getchar();
	cout << "Little did anyone know, " << plynm << " was destined for greatness.\n";
	cout << "Fast foward 10 years... Little " << plynm << " has grown into a sprouting young adventurer.\n";
	cout << plynm << " would always go where they weren't supposed to just to get a glimps of something that caught their eye.\n";
	cout << "Which made little " << plynm << " well know throughout the small village of Winter's Hail.";
	cout << "One day though, one of " << plynm << "'s little adventures saved their life.....\n\n\n";
	system("PAUSE");
	system("CLS");

	screenloop();

	//First "cutscene"/ instance. Need to move into functions
	cout << plynm << ": C'mon already guys! You're way to slow!\n";
	getchar();
	cout << "Phil: Unfortunantly.. We're not as fast as you!\n";
	getchar();
	cout << "Matt: Ya!.. And i'm getting tired!\n";
	getchar();
	cout << plynm << ": Well then go home! I think I saw a sprite flying around and i'm not going home until I find it!\n";
	getchar();
	cout << "Phil: That actual sounds like a good idea. Plus, we don't want to get into trouble like last time we wen't along on one of your adventures.\n";
	getchar();
	cout << "Matt: Ya! My but is still sore after breaking into Mrs. Collins place because you thought you saw a Pixie.\n And it even turned out that there was no Pixie there at all!\n";
	getchar();
	cout << plynm << ": Well if you two are going to keep complaining about it then just go home! You're slowing me down anyway.\n";
	getchar();
	cout << "Phil: You know what? I think we will! Go off and get yourself killed already so we don't have to put up with it! Let's go Matt.\n";
	getchar();
	cout << "Matt: Ya! I can't wait to get home and have some cakes! ...... Try not to die though " << plynm << ".";
	getchar();
	cout << "Fine! Get out of here! I don't need you anyway! I'll have the best adventure ever without you guys!\n But I wish I could share it with someone....\n";
	getchar();
	cout << "Oh well, off to find a mystical creature of some kind!\n";
	getchar();

//Still need to work on wlkcycle. Learn 2D arrays and how to move character..
	//Commenting out walk cycle until it fully works
	//void wlkcycle();
//Temp place for fight function in order to get mechanic ready to go.
	FghtLp();

	system("PAUSE");
	return 0;
}