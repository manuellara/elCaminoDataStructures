#include <iostream>

using namespace std;

#include "globals.h"
#include "arena.h"
#include "robot.h"



Arena::Arena(int nRows, int nCols)
{
	if (nRows <= 0 || nCols <= 0 || nRows > MAXROWS || nCols > MAXCOLS)
	{
		cout << "***** Arena created with invalid size " << nRows << " by "
			<< nCols << "!" << endl;
		exit(1);
	}
	m_rows = nRows;
	m_cols = nCols;
	m_player = nullptr;
	m_nRobots = 0;
}

Arena::~Arena()
{
	// TODO:  Delete the player and all remaining dynamically allocated robots.
	delete player();

	for (int i = 0; i < m_nRobots; i++)
	{
		delete m_robots[i];		//DONE
	}
}

int Arena::rows() const
{
	// TODO:  TRIVIAL:  Return the number of rows in the arena.
	// Delete the following line and replace it with the correct code.
	// This implementation compiles, but is incorrect.
	return m_rows;  //DONE
}

int Arena::cols() const
{
	// TODO:  TRIVIAL:  Return the number of columns in the arena.
	// Delete the following line and replace it with the correct code.
	// This implementation compiles, but is incorrect.
	return m_cols;  //DONE
}

Player* Arena::player() const
{
	return m_player;
}

int Arena::robotCount() const
{
	return m_nRobots;
}

int Arena::nRobotsAt(int r, int c) const
{
	// TODO:  Return the number of robots at row r, column c.
	// This implementation compiles, but is incorrect.
	for (int i = 0 ; i< m_nRobots ; i++)
	{
		if (m_robots[i]->row() == r && m_robots[i]->col() == c)
		{
			return 1;
		}

	}

	return 0;
	
}

void Arena::display(string msg) const
{
	// Position (row,col) in the arena coordinate system is represented in
	// the array element grid[row-1][col-1]
	char grid[MAXROWS][MAXCOLS];
	int r, c;

	// Fill the grid with dots
	for (r = 0; r < rows(); r++)
		for (c = 0; c < cols(); c++)
			grid[r][c] = '.';

	// Indicate each robot's position
	// TODO:  If one robot is at some grid point, set the char to 'R'.
	//        If it's 2 though 8, set it to '2' through '8'.
	//        For 9 or more, set it to '9'.
	
	for (r = 0; r < rows(); r++)
		for (c = 0; c < cols(); c++)
			if ( grid[r][c] == grid[ m_robots[r]->row() - 1 ][ m_robots[c]->col() - 1 ]  )
			{
				grid[r][c] = 'R';       //if grid points are the same as the robots, put 'R' instead 
			}		//DONE



	// Indicate player's position
	if (m_player != nullptr)
	{
		// Set the char to '@', unless there's also a robot there,
		// in which case set it to '*'.
		char& gridChar = grid[m_player->row() - 1][m_player->col() - 1];
		if (gridChar == '.')
			gridChar = '@';
		else
			gridChar = '*';
	}

	// Draw the grid
	clearScreen();
	for (r = 0; r < rows(); r++)
	{
		for (c = 0; c < cols(); c++)
			cout << grid[r][c];
		cout << endl;
	}
	cout << endl;

	// Write message, robot, and player info
	cout << endl;
	if (msg != "")
		cout << msg << endl;
	cout << "There are " << robotCount() << " robots remaining." << endl;
	if (m_player == nullptr)
		cout << "There is no player." << endl;
	else
	{
		if (m_player->age() > 0)
			cout << "The player has lasted " << m_player->age() << " steps." << endl;
		if (m_player->isDead())
			cout << "The player is dead." << endl;
	}
}

bool Arena::addRobot(int r, int c)
{
	// If MAXROBOTS have already been added, return false.  Otherwise,
	// dynamically allocate a new robot at coordinates (r,c).  Save the
	// pointer to the newly allocated robot and return true.

	// TODO:  Implement this.
	// This implementation compiles, but is incorrect.
	if (m_nRobots == MAXROBOTS)
	{
		return false;
	}
	else
	{
		Robot* robot;
		robot = new Robot(this, r, c);

		*(m_robots + m_nRobots) = robot;

							 ///initializes robot(m_robots) at robot count(m_nRobots)
		m_nRobots++;        //increment count every iteration
		return true;		//DONE
	}

}

bool Arena::addPlayer(int r, int c)
{
	// Don't add a player if one already exists
	if (m_player != nullptr)
		return false;

	// Dynamically allocate a new Player and add it to the arena
	m_player = new Player(this, r, c);
	return true;
}

void Arena::damageRobotAt(int r, int c)
{
	// TODO:  Damage one robot at row r, column c if at least one is there.
	// If the robot does not survive the damage, destroy it.
	for (int x = 0 ; x < m_nRobots ; x++)
	{
		if (r == m_robots[x]->row() && c == m_robots[x]->col())
		{
			bool z = m_robots[x]->takeDamageAndLive();     //damage robot

			if (z == true)
				delete m_robots[m_nRobots];         //delete robot[index]

		}	//DONE
		
	}
	
}

bool Arena::moveRobots()
{
	// TODO:  Have the k-th robot in the arena make one move.
	//        If that move results in that robot being in the same
	//        position as the player, the player dies.

	for( int i = 0; i< m_nRobots ; i++ )
		m_robots[i]->move(); ///move robots


	for (int k = 0; k < m_nRobots; k++)
	{
		if (m_robots[k]->row() == player()->row() && m_robots[k]->col() == player()->col())
		{
			m_player->setDead();

			return player()->isDead();
		}	//DONE
	}
	// return true if the player is still alive, false otherwise
	return false;
}