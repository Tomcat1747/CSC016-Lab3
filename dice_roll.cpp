//######################################################################
// Program Header: dice_roll.cpp
// The function of this program is to simulate the rolling of two six 
// sided dice, where their sum will be calculated. If the player rolls 
// a 7 or 11 on their first roll they win, if they roll 2, 3, or 12 on
// their first roll they lose. If their sum is 4, 5, 6, 8, 9, or 10 that
// number becomes their point and they must re-roll that number to win
// but if they roll a 7 before then they lose. Once done ask the player 
// if they would like to play again.
// Author: Thomas Bischoff
// Date Created: 2/13/18
//######################################################################

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Function Declarations
int first_dice_roll();
int followup_dice_roll(int points);
bool users_choice();

int main()
{
	// Set Current Time
	srand(time(0));
	// Initialize the Number of Wins
	int wins = 0;
	// Initialize the Number of Losses
	int losses = 0;
	// Initialize a Statement as True to Run a While Loop
	bool run_statement = true;
	// Generate a While Loop
	while (run_statement == true)
	{
		// Initialize a Value for the First Roll of Dice
		int first_roll;
		// Roll the First Pair of Dice
		first_roll = first_dice_roll();
		// Check if the Player Won
		if (first_roll == 0)
		{
			// Display a Message Indicating that the Player Won
			cout << "Congratulations, You Win!" << endl;
			// Add to the Win Count
			wins += 1;
		}
		// Check if the Player Lost
		else if (first_roll == 1)
		{
			// Display a Message Indicating that the Player Lost
			cout << "Sorry, You Lost." << endl;
			// Add to the Loss Count
			losses += 1;
		}
		// Check if the Player Neither Won or Loss
		else
		{
			// Initialize a Value for the Follow Up Rolls
			int followup_rolls;
			// Perform the Follow Up Rolls
			followup_rolls = followup_dice_roll(first_roll);
			// Check if the Player Won
			if (followup_rolls == 0)
			{
				// Display a Message Indicating that the Player Won
				cout << "Congratulations, You Win!" << endl;
				// Add to the Win Count
				wins += 1;
			}
			// Check if the Player Lost
			if (followup_rolls == 1)
			{
				// Display a Message Indicating that the Player Lost
				cout << "Sorry, You Lost." << endl;
				// Add to the Loss Count
				losses += 1;
			}
		}
		// Display the Win and Loss Results
		cout << "Game Statistics:" << endl;
		cout << "  Wins = " << wins << endl;
		cout << "  Losses = " << losses << endl;
		// Check if the User Want to Play Again
		run_statement = users_choice();
	}
}

//######################################################################
// Function 1: int first_dice_roll()
// Purpose: The purpose of this function is to "roll" the dice and
//          determine if the player has won or lost the game.
//######################################################################

int first_dice_roll()
{
	// Initialize the Pair of Dice
	int die_one, die_two;
	// Roll the First Die
	die_one = rand()% 6 + 1;
	// Roll the Second Die
	die_two = rand()% 6 + 1;
	// Initialize the Sum of the Dice Rolled
	int dice_sum = die_one + die_two;
	// Display the Numbers on the Dice and their Sum
	cout << "You Rolled a " << die_one << " and a " << die_two << " = " << dice_sum << endl;
	// Initialize a Value to Hold the Points for the Player
	int points;
	// Check if the Player Won
	if ((dice_sum == 7) or (dice_sum == 11))
	{
		// Set Points to 0 to Indicate a Win
		points = 0;
		// Return the Points Indicating the Player Won
		return points;
	}
	// Check if the Player Lost
	if ((dice_sum == 2) or (dice_sum == 3) or (dice_sum == 12))
	{
		// Set Points to 1 to Indicate a Loss
		points = 1;
		// Return the Points Indicating the Player Lost
		return points;
	}
	// Check if the Player Neither Won or Loss the First Roll
	else
	{
		// Set the Points to be Equal to the Sum of the Dice Rolled
		points = dice_sum;
		// Return the Sum of the Dice as Points
		return points;
	}
}

//######################################################################
// Function 2: int followup_dice_roll(int points)
// Purpose: The purpose of this function is "roll" a set of dice until
//			they land on the players point or reach a 7.
//######################################################################

int followup_dice_roll(int points)
{
	// Initialize Win Result
	int win_result;
	// Initialize a Statement to be True
	bool repeat = true;
	// Generate a While Loop
	while (repeat == true)
	{
		// Initialize the Pair of Dice
		int die_one, die_two;
		// Find the Value "Rolled" by Die One
		die_one = rand()% 6 + 1;
		// Find the Value "Rolled" by Die Two
		die_two = rand()% 6 + 1;
		// Initialize a Variable for the Sum of the Two Dice
		int dice_sum;
		// Calculate the Sum of the Dice Rolled
		dice_sum = die_one + die_two;
		// Display the Numbers Rolled by the Player and their Sum
		cout << "You Rolled a " << die_one << " and a " << die_two << " = " << dice_sum << endl;
		// Check if the Player Won
		if (dice_sum == points)
		{
			// Set the Win Results to 0 to Indicate a Win
			win_result = 0;
			// Set Repeat to be False
			repeat = false;
		}
		// Check if the Player Lost
		if (dice_sum == 7)
		{
			// Set the Win Results to 1 to Indicate a Loss
			win_result = 1;
			// Set Repeat to be False
			repeat = false;
		}
	}
	// Return the Win Results
	return win_result;
}

//######################################################################
// Function 3: bool users_choice()
// Purpose: The purpose of this function is return the players decision 
// 			if they want to continue playing or not
//######################################################################

bool users_choice()
{
	// Initialize the Users Statement
	bool users_statement;
	// Initialize a Statement as True
	bool repeat = true;
	// Generate a while Loop
	while (repeat == true)
	{
		// Initialize the User's Response
		char users_answer;
		// Ask the Player if they Want to Play Again
		cout << "Would You Like to Play Again (Y / N): ";
		// Take the User's Answer
		cin >> users_answer;
		// Convert User's Anser
		users_answer = toupper(users_answer);
		// Check if the Player Wants to Conitnue
		if (users_answer == 'Y')
		{	
			// Set User's Statement to True
			users_statement = true;
			// Set Repeat to False
			repeat = false;
		}
		// Check if the Play Does Not Want to Continue
		else if (users_answer == 'N')
		{
			// Display Goodbye Message
			cout << "Goodbye." << endl;
			// Set User's Statement to False
			users_statement = false;
			// Set Repeat to False
			repeat = false;
		}
		// Check if the Player Made a Mistake with their Input
		else
		  // Display that the Response they Entered Cannot be Read
		   cout << "Sorry, but the Response you Entered is Not Recognized. Please Try Again." << endl;
	}
	// Return the User's Statement
	return users_statement;
}		
