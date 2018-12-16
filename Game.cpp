#include "Game.h"

Game::Game():gameState(GameStates::PLAY)
{
    //ctor
}

Game::~Game()
{
    //dtor
}

void Game::run()
{
    string p1Name,p2Name;
    input<string>(p1Name,"Enter the Name of First Player");
    cout<<endl;
    input<string>(p2Name,"Enter the Name of Second Player");
    p1.setName(p1Name);   p2.setName(p2Name);
    while(gameState!=GameStates::EXIT)
    {
        gameState=mainMenu();
        if(gameState==GameStates::PLAY)
        {
            startGame();
        }
        else if(gameState==GameStates::CREDITS)
        {
            creditsScreen();
        }
        else if(gameState==GameStates::HTP)
        {
            rulesScreen();
        }

    }
    CLEAR;
    cout.setf(ios::left);
    cout<<setw(10)<<"NAME   "<<setw(15)<<p1.getName()<<setw(5)<<"  :  "<<setw(15)<<p2.getName()<<endl;
    cout<<"--------------------------------"<<endl;
    cout<<setw(10)<<"POINTS   "<<setw(15)<<p1.getWins()<<setw(5)<<"  :  "<<setw(15)<<p2.getWins()<<endl;
    cout<<endl;
    if(p1.getWins()>p2.getWins())
        cout<<endl<<p1.getName()<<" won the Play with lead of "<<p1.getWins()-p2.getWins()<<"."<<endl;
    else if(p2.getWins()>p1.getWins())
        cout<<endl<<p2.getName()<<" won the Play with lead of "<<p2.getWins()-p1.getWins()<<"."<<endl;
    else
        cout<<"The Play is tied up between "<<p1.getName()<<" and "<<p2.getName()<<"."<<endl;
    PAUSE;
}

GameStates Game::mainMenu()
{
    CLEAR;
    cout<<"*** MAIN MENU ***"<<endl<<endl<<endl;
    cout<<" A. START A NEW GAME\n"<<endl;
    cout<<" B. HOW TO PLAY\n"<<endl;
    cout<<" C. CREDITS\n"<<endl;
    cout<<" D. EXIT\n"<<endl<<endl;

    cout<<"Enter Your Choice : ";
    char choice;   cin>>choice;
    choice=(char)toupper(choice);

    GameStates toReturn;
    switch (choice)
    {
        case 'A': toReturn=GameStates::PLAY;  break;
        case 'B': toReturn=GameStates::HTP;  break;
        case 'C': toReturn=GameStates::CREDITS;  break;
        case 'D': toReturn=GameStates::EXIT;  break;
        default : return mainMenu();
    }

    return toReturn;
}

void Game::startGame()
{
    CLEAR;
    inputCoords(p1.getSecreteCoord(),p1.getName()+" enter your secret coordinates");
    CLEAR;
    inputCoords(p2.getSecreteCoord(),p2.getName()+" enter your secret coordinates");

    CLEAR;
    cout<<"Lets Game Begin"<<endl;  PAUSE;

    bool isGameOver=false;
    while(!isGameOver)
    {
        CLEAR;
        inputCoords(p1.getMoveCoord(),p1.getName()+" enter your move coordinates");

        if(p1.getMoveCoord()==p2.getSecreteCoord())
        {
            isGameOver=true;  p1++;  break;
        }
        else
        {
            cout<<"Your Missed the target. Your are still "<<p1.getMoveCoord()-p2.getSecreteCoord()<<" distance away."<<endl<<endl;
            cout<<"Hints : "<<endl;
            if(p1.getMoveCoord().getX()==p2.getSecreteCoord().getX())
            {
                cout<<"You have reached the X, now reach Y"<<endl;
            }
            if(p1.getMoveCoord().getY()==p2.getSecreteCoord().getY())
            {
                cout<<"You have reached the Y, now reach X"<<endl;
            }
            if(p1.getMoveCoord().getX()<p2.getSecreteCoord().getX())
            {
                cout<<"You X position is less."<<endl;
            }
            if(p1.getMoveCoord().getX()>p2.getSecreteCoord().getX())
            {
                cout<<"You X position is more."<<endl;
            }
            if(p1.getMoveCoord().getY()<p2.getSecreteCoord().getY())
            {
                cout<<"You Y position is less."<<endl;
            }
            if(p1.getMoveCoord().getY()>p2.getSecreteCoord().getY())
            {
                cout<<"You Y position is more."<<endl;
            }

        }
        PAUSE;
        CLEAR;
        inputCoords(p2.getMoveCoord(),p2.getName()+" enter your move coordinates");
        if(p2.getMoveCoord()==p1.getSecreteCoord())
        {
            isGameOver=true;  p2++; break;
        }
        else
        {
            cout<<"Your Missed the target. Your are still "<<p2.getMoveCoord()-p1.getSecreteCoord()<<" distance away."<<endl<<endl;
            cout<<"Hints : "<<endl;
            if(p2.getMoveCoord().getX()==p1.getSecreteCoord().getX())
            {
                cout<<"You have reached the X, now reach Y"<<endl;
            }
            if(p2.getMoveCoord().getY()==p1.getSecreteCoord().getY())
            {
                cout<<"You have reached the Y, now reach X"<<endl;
            }
            if(p2.getMoveCoord().getX()<p1.getSecreteCoord().getX())
            {
                cout<<"You X position is less."<<endl;
            }
            if(p2.getMoveCoord().getX()>p1.getSecreteCoord().getX())
            {
                cout<<"You X position is more."<<endl;
            }
            if(p2.getMoveCoord().getY()<p1.getSecreteCoord().getY())
            {
                cout<<"You Y position is less."<<endl;
            }
            if(p2.getMoveCoord().getY()>p1.getSecreteCoord().getY())
            {
                cout<<"You Y position is more."<<endl;
            }
        }
        PAUSE;
    }
    CLEAR;
    cout.setf(ios::left);
    cout<<setw(10)<<"NAME   "<<setw(15)<<p1.getName()<<setw(5)<<"  :  "<<setw(15)<<p2.getName()<<endl;
    cout<<"-----------------------------------"<<endl;
    cout<<setw(10)<<"POINTS   "<<setw(15)<<p1.getWins()<<setw(5)<<"  :  "<<setw(15)<<p2.getWins()<<endl;
    PAUSE;
}

template <typename T>
void Game::input(T& var,string message)
{
    cout<<message<<" : ";   cin>>var;
}
template <typename P,typename Q>
void Game::input(P& var1,Q& var2,string message)
{
    cout<<message<<" : ";   cin>>var1>>var2;
}
void Game::inputCoords(Coordinate& c,string nm)
{
    int x,y;
    input<int,int>(x,y,nm);
    if(x<0 || x>30 || y<0 || y>30)
    {
        cout<<"Wrong Coordinates ( 0<=X<=30 , 0<=Y<=30 )"<<endl;
        cout<<endl;
        inputCoords(c,nm);
    }
    else
    {
        c.setCoordinates(x,y);
    }
}
void Game::rulesScreen()
{
    CLEAR;
    cout<<"Rules for Game Play"<<endl<<endl<<endl;
    cout<<"-Each player will choose his secret coordinates."<<endl<<endl;
    cout<<"-Players have to guess the secret coordinates of other player by moving their position."<<endl<<endl;
    cout<<"-Useful Hints will be provided for each move."<<endl<<endl;
    cout<<"-If player reach secret coordinate of other player, he will be awarded 1 point."<<endl<<endl;
    cout<<"-NOTE: Coordinates can be only between 0 to 30."<<endl<<endl;
    PAUSE;
}
void Game::creditsScreen()
{
    CLEAR;
    cout<<"Credits for the Game"<<endl<<endl;
    cout<<"Rahul Badgujar"<<endl;
    PAUSE;
}
