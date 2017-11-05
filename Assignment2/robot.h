#ifndef _robot
#define _robot


class Robot
{
public:
	// Constructor
	Robot(Arena* ap, int r, int c);

	// Accessors
	int  row() const;
	int  col() const;

	// Mutators
	void move();
	bool takeDamageAndLive();

private:
	Arena* m_arena;
	int    m_row;
	int    m_col;
	int    damageCount; ////DONE
	// TODO: You'll probably find that a robot object needs an additional
	// data member to support your implementation of the behavior affected
	// by being hit and taking damage.
};


#endif