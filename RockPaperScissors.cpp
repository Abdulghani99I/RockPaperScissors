#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
enum enChoice { Stone = 1, Paper = 2, Scissors = 3 };

void listChoice()
{
    cout << "Your Choice: [1]:Stone, [2]:Paper, [3]:Scissors ? ";
}

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

int ReadNumberRange(int From, int To)
{
    int Number = 0;
    do
    {
        cin >> Number;
    } while (Number < 0 || Number > 10);
    return Number;
}

string ChoicePlayer(enChoice Player)
{
    if (Player == enChoice::Stone)
        return "[Stone]";
    if (Player == enChoice::Paper)
        return "[Paper]";
    else
        return "[Scissors]";
}

string CheckWin(enChoice Player1, enChoice player2, int& PointsPy1, int& PointsPy2, int& NoWinner)
{
    if (Player1 == enChoice::Stone)
    {
        if (player2 == enChoice::Paper)
        {
            PointsPy2++;
            system("Color 40");
            cout << "\a";
            return "[Computer]";
        }
        if (player2 == enChoice::Scissors)
        {
            PointsPy1++;
            system("Color 20");
            return "[Player1]";
        }
        else
        {
            system("Color 60");
            NoWinner++;
            return "[No Winner]";
        }
    }
    if (Player1 == enChoice::Paper)
    {
        if (player2 == enChoice::Scissors)
        {
            PointsPy2++;
            system("Color 40");
            cout << "\a";
            return "[Computer]";
        }
        if (player2 == enChoice::Stone)
        {
            PointsPy1++;
            system("Color 20");
            return "[Player1]";
        }
        else
        {
            system("Color 60");
            NoWinner++;
            return "[No Winner]";
        }
    }
    else
    {
        if (player2 == enChoice::Stone)
        {
            PointsPy2++;
            system("Color 40");
            cout << "\a";
            return "[Computer]";
        }
        if (player2 == enChoice::Paper)
        {
            PointsPy1++;
            system("Color 20");
            return "[Player1]";
        }
        else
        {
            system("Color 60");
            NoWinner++;
            return "[No Winner]";
        }
    }
}

void PrintGameResult(enChoice Player1, enChoice Player2, int& PointsPy1, int& PointsPy2, int& NoWinner)
{
    string PlayerOne = ChoicePlayer(Player1);
    cout << "Player Choice  :  " << PlayerOne << endl;
    string Playertwo = ChoicePlayer(Player2);
    cout << "Computer Choice:  " << Playertwo << endl;
    cout << "Round Winner   :  " << CheckWin(Player1, Player2, PointsPy1, PointsPy2, NoWinner);
}

void PrintLine()
{
    cout << "\n___________________________________\n";
}

void ResultEndplay(int PointsPy1, int PointsPy2, int NoWinner, int CounterRound)
{
    cout << "\n\t\t_______________________________________________\n";
    cout << "\n\t\t              +++ Game Over +++                \n";
    cout << "\t\t_______________________________________________\n\n";
    cout << "\t\t_________________[Game Results ]_______________\n";
    cout << "\t\tGame Rounds        : " << CounterRound << endl;
    cout << "\t\tPlayer1 Won times  : " << PointsPy1 << endl;
    cout << "\t\tComputer Won times : " << PointsPy2 << endl;
    cout << "\t\tDraw times         : " << NoWinner << endl;
    cout << "\t\tFinal Winner       : " << CounterRound << endl;
    cout << "\t\t______________________________________________\n";
}

void Start()
{


    cout << "How Many Rounds 1 to 10 ?\n";
    int RoundPlay = ReadNumberRange(1, 10);
    int PointsPy1 = 0;
    int PointsPy2 = 0;
    int NoWinner = 0;
    int CounterRound = 0;
    int player1 = 0, player2 = 0;
    do
    {
        CounterRound++;
        cout << "\n\nRound " << CounterRound << " Begins:\n\n";
        listChoice();
        player1 = ReadNumberRange(1, 3);
        player2 = RandomNumber(1, 3);
        cout << "\n\n_____________Round [" << CounterRound << "]_____________\n\n";
        PrintGameResult((enChoice)player1, (enChoice)player2,
            PointsPy1, PointsPy2, NoWinner);
        PrintLine();
    } while (CounterRound < RoundPlay);
    ResultEndplay(PointsPy1, PointsPy2, NoWinner, CounterRound);
}

bool CheckPlayAgine()
{
    char Answer = ' ';
    cout << "\t\tDo You Want Play agine (Y/N)? ";
    cin >> Answer;
    if (Answer == 'Y' || Answer == 'y')
        return 1;
    else
        return 0;
}

void StartGame()
{
    char answer = ' ';
    do
    {
        system("color 0F");
        system("cls");
        Start();

    } while (CheckPlayAgine());
}

int main()
{
    srand((unsigned)time(NULL));
    StartGame();
}