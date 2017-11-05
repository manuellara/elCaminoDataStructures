#include "robot.h"


Robot::Robot(Arena* ap, int r, int c)
{
	if (ap == nullptr)
	{
		cout << "***** A robot must be in some Arena!" << endl;
		exit(1);
	}
	if (r < 1 || r > ap->rows() || c < 1 || c > ap->cols())
	{
		cout << "***** Robot created with invalid coordinates (" << r << ","
			<< c << ")!" << endl;
		exit(1);
	}
	m_arena = ap;
	m_row = r;
	m_col = c;
}

int Robot::row() const
{
	return m_row;
}

int Robot::col() const
{
	// TODO: TRIVIAL:  Return what column the robot is at.
	// Delete the following line and replace it with the correct code.
	// This implementation compiles, but is incorrect.
	return m_col;  //DONE
}

void Robot::move()
{
	// Attempt to move in a random direction; if we can't move, don't move
	switch ( rand() % 4)
	{
	case UP:
		// TODO:  Move the robot up one row if possible.
		m_row--;//DONE
		break;
	case DOWN:
		m_row++;//DONE
		break;
	case LEFT:
		m_col--;//DONE
		break;
	case RIGHT:
		m_col++;//DONE
		// TODO:  Implement the other movements.
		break;
	}
}

bool Robot::takeDamageAndLive()
{
	// TODO:  If the robot has been hit once before, return false (since a
	// second hit kills a robot).  Otherwise, return true (since the robot
	// survived the damage).
	damageCount++;

	if (damageCount == 2)
	{
		return false;       //DONE
	}

	return true;
}