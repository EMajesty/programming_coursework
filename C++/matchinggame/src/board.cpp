#include "board.h"
#include "card.h"
#include <iostream>
#include <time.h>	 // Used for seeding the randomness of the cards
#include <Windows.h> // For Sleep()

using namespace std;

Board::Board()
{
	populate();
	shuffle();
}

Board::~Board() {}

void Board::game()
{
	int card1;
	int card2;
	bool win = false;
	bool loop;

	while (!win)
	{

		card1 = 0;
		card2 = 0;
		loop = true;

		draw(1);

		while (loop) // Pick first card
		{
			while (true) // Return here if card is not valid
			{
				card1 = pickCard();

				if (m_cardArray[card1].getFound()) // If card doesn't exist
				{
					cout << "No card here\n";
					break; // Try again
				}
				else
				{
					m_cardArray[card1].setActive(true);
					loop = false;
					break;
				}
			}
		}

		loop = true;

		draw(1);

		while (loop) // Pick second card
		{
			while (true) // Return here if card is not valid
			{
				card2 = pickCard();

				if (m_cardArray[card2].getFound()) // If card doesn't exist
				{
					cout << "No card here\n";
					break; // Try again
				}
				else if (m_cardArray[card2].getActive()) // If card is already picked
				{
					cout << "Card already picked\n";
					break; // Try again
				}
				else
				{
					m_cardArray[card2].setActive(true);
					loop = false;
					break;
				}
			}
		}

		draw(1);

		// Wait a bit for player to see both cards
		Sleep(2000);

		if (m_cardArray[card1].getValue() == m_cardArray[card2].getValue()) // Set cards found if same value
		{
			m_cardArray[card1].setFound(true);
			m_cardArray[card2].setFound(true);
		}
		else // Or deactivate them
		{
			m_cardArray[card1].setActive(false);
			m_cardArray[card2].setActive(false);
		}

		win = checkWin();
	}

	draw(2); // Draw win screen

	Sleep(5000); // Wait a bit in the win screen
}

void Board::populate() // Manually assign card values, could be prettier
{
	m_cardArray[0].setValue(1);
	m_cardArray[1].setValue(1);
	m_cardArray[2].setValue(2);
	m_cardArray[3].setValue(2);
	m_cardArray[4].setValue(3);
	m_cardArray[5].setValue(3);
	m_cardArray[6].setValue(4);
	m_cardArray[7].setValue(4);
	m_cardArray[8].setValue(5);
	m_cardArray[9].setValue(5);
	m_cardArray[10].setValue(6);
	m_cardArray[11].setValue(6);
	m_cardArray[12].setValue(7);
	m_cardArray[13].setValue(7);
	m_cardArray[14].setValue(8);
	m_cardArray[15].setValue(8);
}

void Board::shuffle() // Shuffle the cards around
{
	int temp = 0;
	int randomIndex = 0;
	srand(time(NULL)); // Seed the randomness?

	for (int i = 0; i < 16; i++) // Somehow this works
	{
		randomIndex = rand() % 16;
		temp = m_cardArray[i].getValue();
		m_cardArray[i].setValue(m_cardArray[randomIndex].getValue());
		m_cardArray[randomIndex].setValue(temp);
	}
}

void Board::draw(int sel) // Draw board
{
	for (int i = 0; i < 30; i++) // Clear the screen? NO system("CLS")
	{
		cout << "\n";
	}

	if (sel == 1) // Normal drawing of board
	{
		cout << "oooo     oooo            o8            oooo                                     o88                           " << endl;
		cout << " 8888o   888   ooooooo o888oo ooooooo   888ooooo        ooooooooo     ooooooo   oooo  oo oooooo    oooooooo8  " << endl;
		cout << " 88 888o8 88   ooooo888 888 888     888 888   888        888    888   ooooo888   888   888    888 888ooooooo  " << endl;
		cout << " 88  888  88 888    888 888 888         888   888        888    888 888    888   888   888                888 " << endl;
		cout << "o88o  8  o88o 88ooo88 8o 888o 88ooo888 o888o o888o       888ooo88    88ooo88 8o o888o o888o       88oooooo88  " << endl;
		cout << "                                                        o888                                                  " << endl;

		for (int i = 0; i < 5; i++)
		{
			cout << "\n";
		}

		cout << "     (A)  (B)  (C)  (D)"
			 << "\n\n";
		cout << "(1)  ";
		m_cardArray[0].draw();
		m_cardArray[1].draw();
		m_cardArray[2].draw();
		m_cardArray[3].draw();
		cout << "\n\n";
		cout << "(2)  ";
		m_cardArray[4].draw();
		m_cardArray[5].draw();
		m_cardArray[6].draw();
		m_cardArray[7].draw();
		cout << "\n\n";
		cout << "(3)  ";
		m_cardArray[8].draw();
		m_cardArray[9].draw();
		m_cardArray[10].draw();
		m_cardArray[11].draw();
		cout << "\n\n";
		cout << "(4)  ";
		m_cardArray[12].draw();
		m_cardArray[13].draw();
		m_cardArray[14].draw();
		m_cardArray[15].draw();
		cout << "\n\n";
	}

	if (sel == 2) // Win
	{
		cout << "ooooo  oooo                                       o88               " << endl;
		cout << "  888  88 ooooooo  oooo  oooo       oooo  o  oooo oooo  oo oooooo   " << endl;
		cout << "    888 888     888 888   888        888 888 888   888   888   888  " << endl;
		cout << "    888 888     888 888   888         888888888    888   888   888  " << endl;
		cout << "   o888o  88ooo88    888o88 8o         88   88    o888o o888o o888o " << endl;

		for (int i = 0; i < 5; i++)
		{
			cout << "\n";
		}
	}
}

int Board::pickCard() // Returns the index of the selected card
{
	string input;
	int index = 123;

	while (index == 123)
	{
		cout << "Pick a card (A1 - D4): ";
		cin >> input;

		// EI TOIMI
		/*input == ("A1") ? index = 0
			: ("B1") ? index = 1
			: ("C1") ? index = 2
			: ("D1") ? index = 3
			: ("A2") ? index = 4
			: ("B2") ? index = 5
			: ("C2") ? index = 6
			: ("D2") ? index = 7
			: ("A3") ? index = 8
			: ("B3") ? index = 9
			: ("C3") ? index = 10
			: ("D3") ? index = 11
			: ("A4") ? index = 12
			: ("B4") ? index = 13
			: ("C4") ? index = 14
			: ("D4") ? index = 15
			:		   index = 123;*/

		// TOIMII
		if (input == "A1")
		{
			index = 0;
		}
		else if (input == "B1")
		{
			index = 1;
		}
		else if (input == "C1")
		{
			index = 2;
		}
		else if (input == "D1")
		{
			index = 3;
		}
		else if (input == "A2")
		{
			index = 4;
		}
		else if (input == "B2")
		{
			index = 5;
		}
		else if (input == "C2")
		{
			index = 6;
		}
		else if (input == "D2")
		{
			index = 7;
		}
		else if (input == "A3")
		{
			index = 8;
		}
		else if (input == "B3")
		{
			index = 9;
		}
		else if (input == "C3")
		{
			index = 10;
		}
		else if (input == "D3")
		{
			index = 11;
		}
		else if (input == "A4")
		{
			index = 12;
		}
		else if (input == "B4")
		{
			index = 13;
		}
		else if (input == "C4")
		{
			index = 14;
		}
		else if (input == "D4")
		{
			index = 15;
		}
		else
		{
			index = 123;
		}
	}
	return index;
}

bool Board::checkWin() // Check if all cards are found
{
	bool win = true;
	for (int i = 0; i < 16; i++)
	{
		if (!m_cardArray[i].getFound()) // If any card is not yet found
		{
			win = false;
		}
	}
	return win;
}