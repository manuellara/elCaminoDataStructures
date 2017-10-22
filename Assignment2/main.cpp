// zion.cpp

// Portions you are to complete are marked with a TODO: comment.
// We've provided some incorrect return statements (so indicated) just
// to allow this skeleton program to compile and run, albeit incorrectly.
// The first thing you probably want to do is implement the trivial
// functions (marked TRIVIAL).  Then get Arena::display going.  That gives
// you more flexibility in the order you tackle the rest of the functionality.
// As you finish implementing each TODO: item, remove its TODO: comment.

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

///////////////////////////////////////////////////////////////////////////
// Manifest constants
///////////////////////////////////////////////////////////////////////////

const int MAXROWS = 20;             // max number of rows in the arena
const int MAXCOLS = 40;             // max number of columns in the arena
const int MAXROBOTS = 130;          // max number of robots allowed
const int MAXSHOTLEN = 5;           // max number of steps you can shoot

const int UP    = 0;
const int DOWN  = 1;
const int LEFT  = 2;
const int RIGHT = 3;

///////////////////////////////////////////////////////////////////////////
//  Auxiliary function declarations
///////////////////////////////////////////////////////////////////////////

int decodeDirection(char dir);
void clearScreen();

///////////////////////////////////////////////////////////////////////////
// Type definitions
///////////////////////////////////////////////////////////////////////////

class Arena;  
// This is needed to let the compiler know that Arena is a
// type name, since it's mentioned in the Robot declaration.

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
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    int    damageCount; //DONE
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      // TODO: You'll probably find that a robot object needs an additional
      // data member to support your implementation of the behavior affected
      // by being hit and taking damage.
};

class Player
{
  public:
        // Constructor
    Player(Arena *ap, int r, int c);

        // Accessors
        int  row() const;
        int  col() const;
        int  age() const;
        bool isDead() const;

        // Mutators
        string takeComputerChosenTurn();
        void   stand();
        void   move(int dir);
        bool   shoot(int dir);
        void   setDead();

  private:
        Arena* m_arena;
        int    m_row;
        int    m_col;
        int    m_age;
        bool   m_dead;
};

class Arena
{
  public:
    // Constructor/destructor
    Arena(int nRows, int nCols);
    ~Arena();

        // Accessors
        int     rows() const;
        int     cols() const;
        Player* player() const;
        int     robotCount() const;
        int     nRobotsAt(int r, int c) const;
        void    display(string msg) const;

        // Mutators
        bool   addRobot(int r, int c);
        bool   addPlayer(int r, int c);
        void   damageRobotAt(int r, int c);
        bool   moveRobots();

  private:
        int     m_rows;
        int     m_cols;
        Player* m_player;
        Robot*  m_robots[MAXROBOTS];
        int     m_nRobots;
};

class Game
{
  public:
    // Constructor/destructor
    Game(int rows, int cols, int nRobots);
    ~Game();

        // Mutators
        void play();

  private:
    Arena* m_arena;
};

///////////////////////////////////////////////////////////////////////////
//  Robot implementation
///////////////////////////////////////////////////////////////////////////

Robot::Robot(Arena* ap, int r, int c)
{
    if (ap == nullptr)
    {
        cout << "***** A robot must be in some Arena!" << endl;
        exit(1);
    }
    if (r < 1  ||  r > ap->rows()  ||  c < 1  ||  c > ap->cols())
    {
        cout << "***** Robot created with invalid coordinates (" << r << ","
             << c << ")!" << endl;
        exit(1);
    }
    m_arena = ap;
    m_row = r;
    m_col = c;
    damageCount = 0;
}

int Robot::row() const
{
    return m_row;
}

int Robot::col() const
{
      // TODO: TRIVIAL:  Return what column the robot is at.
      // Delete the following line and replace it with the correct code.
    return m_col;  // DONE
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Robot::move()
{
      // Attempt to move in a random direction; if we can't move, don't move
    switch (rand() % 4)
    {
      case UP:
        m_row--;
        break;
      case DOWN:
        m_row++;
      case LEFT:
        m_col--;
      case RIGHT:
        // TODO:  Implement the other movements.
        m_col++;
        break;
    }
}//DONE
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Robot::takeDamageAndLive()
{
      // TODO:  If the robot has been hit once before, return false (since a
      // second hit kills a robot).  Otherwise, return true (since the robot
      // survived the damage).
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    damageCount++;

    if (damageCount == 2)
    {
        return false;       //DONE
    }

    return true;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

///////////////////////////////////////////////////////////////////////////
//  Player implementations
///////////////////////////////////////////////////////////////////////////

Player::Player(Arena* ap, int r, int c)
{
    if (ap == nullptr)
    {
        cout << "***** The player must be in some Arena!" << endl;
        exit(1);
    }
    if (r < 1  ||  r > ap->rows()  ||  c < 1  ||  c > ap->cols())
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
    return m_row;  // DONE
}

int Player::col() const
{
      // TODO: TRIVIAL:  Return what column the player is at.
      // Delete the following line and replace it with the correct code.
    return m_col;  // DONE
}

int Player::age() const
{
      // TODO:  TRIVIAL:  Return the player's age.
      // Delete the following line and replace it with the correct code.
    return m_age;  // DONE
}

string Player::takeComputerChosenTurn()
{
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // TODO:  Replace this implementation:
    int random = rand() % 3 + 1 ;
    int movement = rand() % 4;
    bool result;
    

    switch ( random )
    {
        case 1:
            stand();
            return "Stood";
        case 2:
            move( movement );
            return "moved";
        case 3:
            result = shoot( movement );
            if (result == true)
            {
                return "robot shot and damaged.";
            }
            else 
            {
                return "shot but missed.";
            }
        case 4:
            result = shoot( movement );
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
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Player::move(int dir)
{
    m_age++;
    switch (dir)
    {
      case UP:
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
        break;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Player::shoot(int dir)
{
    m_age++;

    if (rand() % 3 == 0)
    {  // miss with 1/3 probability
        return false;
    }

      // TODO:  Damage the nearest robot in direction dir, returning
      // true if a robot is hit and damaged, false if not hit.
    // This implementation compiles, but is incorrect.
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    int z = rand() % 3;
    switch( z )
    {
        case 0:
        {
            int x = 0;

            do{
                int x = m_arena->nRobotsAt( m_row , m_col );     //if robot exists at coordinates
                
                    if( x == 1 )
                        {
                            m_arena->damageRobotAt( m_row , m_col );    //damage robot
                            return true;
                        }
                    else
                    {
                        m_col--;
                    }

            }while( x == 0 );
            break;
        }
        case 1:
        {
            int x = 0;

            do{
                int x = m_arena->nRobotsAt( m_row , m_col );     //if robot exists at coordinates
                
                    if( x == 1 )
                        {
                            m_arena->damageRobotAt( m_row , m_col );    //damage robot
                            return true;
                        }
                    else
                    {
                        m_col++;
                    }

            }while( x == 0 );
            break;
        }
        case 2:
        {
            int x = 0;

            do{
                int x = m_arena->nRobotsAt( m_row , m_col );     //if robot exists at coordinates
                
                    if( x == 1 )
                        {
                            m_arena->damageRobotAt( m_row , m_col );    //damage robot
                            return true;
                        }
                    else
                    {
                        m_row--;
                    }

            }while( x == 0 );
            break;
        }
        case 3:
        {
            int x = 0;

            do{
                int x = m_arena->nRobotsAt( m_row , m_col );     //if robot exists at coordinates
                
                    if( x == 1 )
                        {
                            m_arena->damageRobotAt( m_row , m_col );    //damage robot
                            return true;
                        }
                    else
                    {
                        m_row++;
                    }

            }while( x == 0 );
            break;
        }

    }

    return true;
}

bool Player::isDead() const
{
      // TODO:  TRIVIAL:  Return whether the player is dead.
      if (m_dead == true)
      {
        return true;
      }
      else
      {
        return false;   // DONE
      }
      
}

void Player::setDead()
{
    m_dead = true;
}

///////////////////////////////////////////////////////////////////////////
//  Arena implementations
///////////////////////////////////////////////////////////////////////////

Arena::Arena(int nRows, int nCols)
{
    if (nRows <= 0  ||  nCols <= 0  ||  nRows > MAXROWS  ||  nCols > MAXCOLS)
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Arena::~Arena()
{
      // TODO:  Delete the player and all remaining dynamically allocated robots.
      delete player();

      for (int i = 0 ; i < m_nRobots ; i++)
      {
          delete m_robots[i];
      }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Arena::rows() const
{
      // TODO:  TRIVIAL:  Return the number of rows in the arena.
      // Delete the following line and replace it with the correct code.
    return m_rows;  // DONE
}

int Arena::cols() const
{
      // TODO:  TRIVIAL:  Return the number of columns in the arena.
      // Delete the following line and replace it with the correct code.
    return m_cols;  // DONE
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
    if(m_robots[m_nRobots]->row() == r && m_robots[m_nRobots]->col() == c)
    {
        return 1;
    }
    else
    {
        return 0;
    }

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
      //        If it's 2 through 8, set it to '2' through '8'.
      //        For 9 or more, set it to '9'.
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    for (r = 0; r < rows(); r++)
        for (c = 0; c < cols(); c++)
            if (grid[r][c] == grid[m_robots[m_nRobots]->row()-1][m_robots[m_nRobots]->col()-1])
            {
                grid[r][c] = 'R';       //if grid points are the same as the robots, put 'R' instead 
            }
    
    ////else statement for 2 through 8 -- almost DONE
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



        // Indicate player's position
    if (m_player != nullptr)
    {
          // Set the char to '@', unless there's also a robot there,
          // in which case set it to '*'.
        char& gridChar = grid[m_player->row()-1][m_player->col()-1];
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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Dynamically allocate a new Robot and add it to the arena
    if (m_nRobots == MAXROBOTS)
    {
        return false;
    }

    m_robots[m_nRobots] = new Robot( this , r , c ); ///initializes robot(m_robots) at robot count(m_nRobots)
    m_nRobots++;        //increment count every iteration
    return true;

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (r == m_robots[m_nRobots]->row() && c == m_robots[m_nRobots]->col() )
    {
        bool x = m_robots[m_nRobots]->takeDamageAndLive() ;     //damage robot

        if ( x == true )
        {
            delete m_robots[m_nRobots];         //delete robot[index]
        }
    }
    //DONE
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

bool Arena::moveRobots()
{
    for (int k = 0; k < m_nRobots; k++)
    {
      // TODO:  Have the k-th robot in the arena make one move.
      //        If that move results in that robot being in the same
      //        position as the player, the player dies.
      ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        m_robots[k]->move();
        if( m_robots[k]->row() == player()->row() && m_robots[k]->col() == player()->col() )
        {
            return m_player->isDead();
        } //DONE

      ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    }

      // return true if the player is still alive, false otherwise
    return ! m_player->isDead();
}

///////////////////////////////////////////////////////////////////////////
//  Game implementations
///////////////////////////////////////////////////////////////////////////

Game::Game(int rows, int cols, int nRobots)
{
    if (nRobots > MAXROBOTS)
    {
        cout << "***** Trying to create Game with " << nRobots
             << " robots; only " << MAXROBOTS << " are allowed!" << endl;
        exit(1);
    }

        // Create arena
    m_arena = new Arena(rows, cols);

        // Add player
    int rPlayer = 1 + rand() % rows;
    int cPlayer = 1 + rand() % cols;
    m_arena->addPlayer(rPlayer, cPlayer);

      // Populate with robots
    while (nRobots > 0)
    {
        int r = 1 + rand() % rows;
        int c = 1 + rand() % cols;
          // Don't put a robot where the player is
        if (r == rPlayer  &&  c == cPlayer)
            continue;
        m_arena->addRobot(r, c);
        nRobots--;
    }
}

Game::~Game()
{
    delete m_arena;
}

void Game::play()
{
    Player* p = m_arena->player();
    if (p == nullptr)
    {
        m_arena->display("");
        return;
    }
    string msg = "";
    do
    {
        m_arena->display(msg);
        msg = "";
        cout << endl;
        cout << "Move (u/d/l/r/su/sd/sl/sr/c//q): ";
        string action;
        getline(cin,action);
        if (action.size() == 0)
            p->stand();
        else
        {
            switch (action[0])
            {
              default:   // if bad move, nobody moves
                cout << '\a' << endl;  // beep
                continue;
              case 'q':
                return;
              case 'c':  // computer moves player
                msg = p->takeComputerChosenTurn();
                break;
              case 'u':
              //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                p->move(0);
                break;
              case 'd':
                p->move(1);
                break;
              case 'l':
                p->move(2);
                break;
                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
              case 'r':
                p->move(decodeDirection(action[0]));
                break;
              case 's':
                if (action.size() < 2)  // if no direction, nobody moves
                {
                    cout << '\a' << endl;  // beep
                    continue;
                }
                switch (action[1])
                {
                  default:   // if bad direction, nobody moves
                    cout << '\a' << endl;  // beep
                    continue;
                  case 'u':
                  case 'd':
                  case 'l':
                  case 'r':
                    if (p->shoot(decodeDirection(action[1])))
                        msg = "Hit!";
                    else
                        msg = "Missed!";
                    break;
                }
                break;
            }
        }
        m_arena->moveRobots();
    } while ( ! m_arena->player()->isDead()  &&  m_arena->robotCount() > 0);
    m_arena->display(msg);
}

///////////////////////////////////////////////////////////////////////////
//  Auxiliary function implementations
///////////////////////////////////////////////////////////////////////////

int decodeDirection(char dir)
{
    switch (dir)
    {
      case 'u':  return UP;
      case 'd':  return DOWN;
      case 'l':  return LEFT;
      case 'r':  return RIGHT;
    }
    return -1;  // bad argument passed in!
}

///////////////////////////////////////////////////////////////////////////
//  main()
///////////////////////////////////////////////////////////////////////////

int main()
{
      // Initialize the random number generator.  (You don't need to
      // understand how this works.)
    srand(static_cast<unsigned int>(time(0)));

      // Create a game
      // Use this instead to create a mini-game:   Game g(3, 3, 2);
    Game g(15, 18, 80);

      // Play the game
    g.play();
}

///////////////////////////////////////////////////////////////////////////
//  clearScreen implementations
///////////////////////////////////////////////////////////////////////////

// DO NOT MODIFY OR REMOVE ANY CODE BETWEEN HERE AND THE END OF THE FILE!!!
// THE CODE IS SUITABLE FOR VISUAL C++, XCODE, AND g++ UNDER LINUX.

// Note to Xcode users:  clearScreen() will just write a newline instead
// of clearing the window if you launch your program from within Xcode.
// That's acceptable.


#ifdef _MSC_VER  //  Microsoft Visual C++

#include <windows.h>

void clearScreen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    COORD upperLeft = { 0, 0 };
    DWORD dwCharsWritten;
    FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft,
                                                        &dwCharsWritten);
    SetConsoleCursorPosition(hConsole, upperLeft);
}

#else  // not Microsoft Visual C++, so assume UNIX interface

#include <cstring>

void clearScreen()  // will just write a newline in an Xcode output window
{
    static const char* term = getenv("TERM");
    if (term == nullptr  ||  strcmp(term, "dumb") == 0)
        cout << endl;
    else
    {
        static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
        cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
    }
}

#endif
