#include "player.h"


Player::Player(Arena* ap, int r, int c)
{
	if (ap == nullptr)
	{
		cout << "***** The player must be in some Arena!" << endl;
		exit(1);
	}
	if (r < 1 || r > ap->rows() || c < 1 || c > ap->cols())
	{
		cout << "**** Player created with invalid coordinates (" << r
			<< "," << c << ")!" << endl;
		exit(1);
	}
	m_arena = ap;
	m_row = r;
	m_col = c;
	m_age = 0;
	m_dead = false;
}

int Player::row() const
{
	// TODO: TRIVIAL:  Return what row the player is at.
	// Delete the following line and replace it with the correct code.
	// This implementation compiles, but is incorrect.
	return m_row;  //DONE
}

int Player::col() const
{
	// TODO: TRIVIAL:  Return what column the player is at.
	// Delete the following line and replace it with the correct code.
	// This implementation compiles, but is incorrect.
	return m_col;  //DONE
}

int Player::age() const
{
	// TODO:  TRIVIAL:  Return the player's age.
	// Delete the following line and replace it with the correct code.
	// This implementation compiles, but is incorrect.
	return m_age;  //DONE
}

string Player::takeComputerChosenTurn()
{
	// TODO:  Replace this implementation: //DONE
	int random = rand() % 3 + 1;
	int movement = rand() % 4;
	bool result;


	switch (random)
	{
	case 1:
		stand();
		return "Stood";
	case 2:
		move(movement);
		return "moved";
	case 3:
		result = shoot(movement);
		if (result == true)
		{
			return "robot shot and damaged.";
		}
		else
		{
			return "shot but missed.";
		}
	case 4:
		result = shoot(movement);
		if (result == true)
		{
			return "robot shot and damaged.";
		}
		else
		{
			return "shot but missed.";
		}  //DONE

	}
	return "";
	// Your replacement implementation should do something intelligent
	// and return a string that describes what happened.  When you've
	// decided what action to take, take it by calling move, shoot, or stand.
	// This function must return one of the following four strings:
	//     "Moved."
	//     "Shot and hit!"
	//     "Shot and missed!"
	//     "Stood."

	// Here's one possible strategy:
	//   If moving in some direction would put me in less immediate danger
	//     than standing, then move in that direction.
	//   else shoot in the direction of the nearest robot I can hit.

	// A more aggressive strategy is possible, where you hunt down robots.
}

void Player::stand()
{
	m_age++;
}

void Player::move(int dir)
{
	m_age++;
	switch (dir)			//DONE
	{
	case UP:
		// TODO:  Move the player up one row if possible.
		m_row--;
		break;
	case DOWN:
		m_row++;
		break;
	case LEFT:
		m_col--;
		break;
	case RIGHT:
		m_col++;
		// TODO:  Implement the other movements.
		break;
	}
}

bool Player::shoot(int dir)
{
	m_age++;

	if ( rand() % 3 ==  0)  // miss with 1/3 probability
		return false;

	// TODO:  Damage the nearest robot in direction dir, returning
	// true if a robot is hit and damaged, false if not hit.
	// This implementation compiles, but is incorrect.
	switch ( dir )
	{
		case 0:
		{
			int x = 0;

			do {
				int x = m_arena->nRobotsAt(m_row, m_col);     //if robot exists at coordinates

				if (x == 1)
				{
					m_arena->damageRobotAt(m_row, m_col);    //damage robot
					return true;
				}
				else
				{
					m_col--;
				}

			} while (x == 0);
			break;
		}
		case 1:
		{
			int x = 0;

			do {
				int x = m_arena->nRobotsAt(m_row, m_col);     //if robot exists at coordinates

				if (x == 1)
				{
					m_arena->damageRobotAt(m_row, m_col);    //damage robot
					return true;
				}
				else
				{
					m_col++;
				}

			} while (x == 0);
			break;
		}
		case 2:
		{
			int x = 0;

			do {
				int x = m_arena->nRobotsAt(m_row, m_col);     //if robot exists at coordinates

				if (x == 1)
				{
					m_arena->damageRobotAt(m_row, m_col);    //damage robot
					return true;
				}
				else
				{
					m_row--;
				}

			} while (x == 0);
			break;
		}
		case 3:
		{
			int x = 0;

			do {
				int x = m_arena->nRobotsAt(m_row, m_col);     //if robot exists at coordinates

				if (x == 1)
				{
					m_arena->damageRobotAt(m_row, m_col);    //damage robot
					return true;
				}
				else
				{
					m_row++;
				}

			} while (x == 0);
			break;
		}

	}

	return true;
}

bool Player::isDead() const
{
	// TODO:  TRIVIAL:  Return whether the player is dead.
	// This implementation compiles, but is incorrect.

	if (m_dead == true)
	{
		return true;
	}

	return false;
}

void Player::setDead()
{
	m_dead = true;
}