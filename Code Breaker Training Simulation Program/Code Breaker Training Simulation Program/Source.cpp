/*
	James Pope
	10/22/20
	Keywords II Code Breaker Simulation Training Program
	This program isa  simple word guessing game, spy style.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

int main() 
{	
	enum fields {WORD, HINT, NUM_FIELDS};
	const int NUM_KEYS = 10;
	const string keywords[NUM_KEYS][NUM_FIELDS] = // create a collection of 10 keywords
	{
		{"ESPIONAGE","Cold war era spies partook in this when stealing information"},
		{"CIA","The USA's agency for gathering secret intel"},
		{"KBG","The Soviet Union's agency for gathering secret intel"},
		{"SYNDICATE","A self-organizing group of individuals, companies, corporations or entities"},
		{"GOLDENEYE","A nuclear electromagnetic pulse space-based weapon"},
		{"SPY","Someone who sneakily recovers secret intel"},
		{"INTEL","A spy-like version of the word information"},
		{"BOND","The most legendary spy of all time"},
		{"FILES","digital objects containing information that spies can easily steal"},
		{"SATELLITE","Space-bound constructs used to transmit communications and data"},
	};

	const int MAX_FAILS = 5;													// max number of incorrect attempts
	int fails = 0;																// number of incorrect decryption attempts
	string guess;																//variable for player guess
	char playAgain = 'n';																//var for playing again

	// Display Title of program to user
	cout << "------------------------------------------------------" << endl;
	cout << "Keywords Code Breaker Simulation Training Program" << endl;
	cout << "------------------------------------------------------" << endl << endl;

	// Ask the recruit to login using thier name
	cout << "Recruit, please enter your name to begin." << endl;
	
	// Hold the recruit's name in a var, and address them by it throughout the simulation.
	string userName;
	cin >> userName;

	// Display an overview of what Keywords II is to the recruit 
	cout << "------------------------------------------------------------------------------------------------\n";
	cout << userName + ", this training program is designed to ready you for deciphering enemy transmissionsn.\n";
	cout << "Recently, our enemies have turned the clock back on their transmission encryption methods.\n";
	cout << "This is where you come in, " + userName + ". You will decrypt the keywords that unlock the enemy's encryption.\n";
	cout << "Use this training program until you are completely comfortable with the concept.\n";
	cout << "When your performance is satisfactory your superiors will be automatically notified.\n";
	cout << "------------------------------------------------------------------------------------------------\n";

	system("pause"); // to prevent instantaneous text wall

	// Display an directions to the recruit on how to use Keywords
	cout << "------------------------------------------------------------------------------------------------\n";
	cout << "Keywords will come through the program scrambled.\n";
	cout << "Decrypt the scrambled encryption keyword.\n";
	cout << "The program will tell you what you decrypt correctly ";
	cout << "or when you fail a decryption attempt.\n";
	cout << "If you require a hint for the keyword type 'hint'\n";
	cout << "All of your answers are to be in lowercase.\n";
	cout << "Training will start momentarily.";
	cout << " Good luck, " + userName << endl; 
	cout << "------------------------------------------------------------------------------------------------\n\n";

	system("pause"); // to give user a moment before the training starts
	
	 // int to count the number of simulations being run starting at 1
	
	do
	{
		fails = 0; // reset amount of fails. This is to reset the fails when the player says they want to play again

		for (int round = 1; round < 4; round++)
		{
			srand(static_cast<unsigned int>(time(0)));			// seed rng for random keywords
			int choice = (rand() % NUM_KEYS);					// shuffle the elements in the keywords vector
			const string SECRET_WORD = keywords[choice][WORD];	// pick the keyword randomly from the array
			const string SECRET_HINT = keywords[choice][HINT];	//pick the matching hint from the array

			string scramble = SECRET_WORD;  // scrambled version of keyword
			int length = scramble.size(); //get size of string and store it as length
			for (int i = 0; i < length; ++i)
			{
				int index1 = (rand() % length);
				int index2 = (rand() % length);
				char temp = scramble[index1];
				scramble[index1] = scramble[index2];
				scramble[index2] = temp;
			}

			cout << "\nSimulation Round: " << round; // Display the current simulation round to the recruit. 
			cout << "\nIncoming encryption,";
			cout << "the keyword scrambled is: " << scramble << endl;

			// While recruit hasn’t made too many fails and hasn’t guessed the keywork
			while ((fails < MAX_FAILS) && (guess != SECRET_WORD))
			{
				// Tell recruit how many attempts they have left
				cout << "\n\nYou have " << (MAX_FAILS - fails);
				cout << " attempts left to crack this encryption.\n";
				// Get recruit's next guess
				cout << "Enter possible keyword for decryption attempt: ";
				cin >> guess;
				//convert it to all uppercase for comparison
				transform(guess.begin(), guess.end(), guess.begin(), ::toupper);


				// If recruit enters "hint"
				if (guess == "HINT")
				{
					//display hint
					cout << SECRET_HINT;
				}
				//else if recruit's guess is the secret word
				else if (guess == SECRET_WORD)
				{
					//display success message
					cout << "----------------------";
					cout << "\nEncryption cracked! ";
					cout << "Great job, " + userName << endl;
					cout << "----------------------\n\n";
				}
				//otherwise
				else
				{
					//display failure message
					cout << "\nDecryption attempt failed: Incorrect input.";
					//increment number of fails
					fails++;
				}
			}
			//if the number of fails is equal to the maximum amount of fails
			if (fails == MAX_FAILS)
			{
				//regrettably inform recruit
				cout << endl << userName + ", you have failed the simulation.";
				//sound round to 4 to end loop
				round = 4;
			}
		}

		//ask recruit if they would like to run the simulation again
		cout << "\nWould you like to try again? y/n: ";
		//get their answer and store it
		cin >> playAgain;

	} while (playAgain == 'y'); //exit condition, playAgain has to equal 'y'

	//display goodbye message
	cout << "\nGood work, " + userName;
	cout << "\nSimulation terminating....";
}
