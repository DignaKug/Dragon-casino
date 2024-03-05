#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <vector>
#include <limits>
//#pragma comment(lib, "winmm.lib")
using namespace std;

int dice;
void rules ()
{
    cout << "\n\nRULES:\n\n";
    cout << "You place a bet" << endl;
    cout << "Choose a number from 1 to 10" << endl;
    cout << "We roll the dice" << endl;
    cout << "You either win 10 times your bet or..." << endl;
    cout << "you LOSE!" << endl;
}
void DICEDRAW(int dice){
if (dice==1){
cout << R"(
  ___________
 |           |
 |           |
 |     0     |
 |           |
 |___________|)";}

 else if (dice==2){
cout << R"(
  ___________
 |           |
 |           |
 |   0   0   |
 |           |
 |___________|)";}

 else if (dice==3){
cout << R"(
  ___________
 |           |
 |     0     |
 |   0   0   |
 |           |
 |___________|)";}

 else if (dice==4){
cout << R"(
  ___________
 |           |
 |   0   0   |
 |           |
 |   0   0   |
 |___________|)";}

 else if (dice==5){
cout << R"(
  ___________
 |           |
 |   0   0   |
 |     0     |
 |   0   0   |
 |___________|)";}

 else if (dice==6){
cout << R"(
  ___________
 |           |
 |   0   0   |
 |   0   0   |
 |   0   0   |
 |___________|)";}

 else if (dice==7){
cout << R"(
  ___________
 |           |
 |   0   0   |
 |   0 0 0   |
 |   0   0   |
 |___________|)";}

 else if (dice==8){
cout << R"(
  ___________
 |           |
 |   0 0 0   |
 |   0   0   |
 |   0 0 0   |
 |___________|)";}

 else if (dice==9){
cout << R"(
  ___________
 |           |
 |   0 0 0   |
 |   0 0 0   |
 |   0 0 0   |
 |___________|)";}

else if (dice==10){
cout << R"(
  ___________
 |           |
 |  0 0 0 0  |
 |   0   0   |
 |  0 0 0 0  |
 |___________|)";
}
 cout << endl;
 cout << endl;}



int main ()
{
    //theme music
    //PlaySound("C:\\Users\\delfi\\Desktop\\muzikele.wav", NULL, SND_SYNC);
    char choice;
    string name;
    long amount;
    vector <string> names;
    vector <long > amounts;
    long bet;
    vector <long > bets;
    string loading = "Loading...";
    int players;
    int dice;
    int guess;
    vector <int> guesses;

    cout << endl;

    cout << R"(

        ,     \    /      ,               .-------.    ______
       / \    )\__/(     / \             /   o   /|   /\     \
      /   \  (_\  /_)   /   \           /_______/o|  /o \  o  \
 ____/_____\__\@  @/___/_____\____      | o     | | /   o\_____\
|             |\../|              |     |   o   |o/ \o   /o    /
|              \VV/               |     |     o |/   \ o/  o  /
|       DRAGON CASINO 2024        |     '-------'     \/____o/
|_________________________________|
 |    /\ /      \\       \ /\    |
 |  /   V        ))       V   \  |
 |/     `       //        '     \|
 `              V                '
 )";

    rules();

        cout << "\n\n_______________________________________________________________________________________\n\n";
        for (int i = 0; i < loading[i]; i++)
        {
            cout << loading[i];
            Sleep(500);
        }
        cout << "\n\nEnter amount of players: ";
        cin >> players;
        for (int i=0; i<players; i++)
        {
            cout << "\n\nEnter your name player " << i+1<< ": ";
            cin >> name;
            names.push_back(name);
        }


        for ( int i=0; i<players; i++)
        {
            cout << "\n\nFill in your bank account, player " << i+1<<" : $";
            while (!(cin >> amount)){
            cout << "Please enter a numerical value: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

            amounts.push_back(amount);
        }

        cout << "\n\n_______________________________________________________________________________________\n\n";
        for (int i=0; i<players; i++)
        {
            cout << "\nCONGRATULATIONS, " << names[i] <<" you have " << amounts[i] << "$ in your wallet" << endl;
        }
        cout << "\n\n_______________________________________________________________________________________\n\n";

        for (int i = 0; i < loading[i]; i++)
        {
            cout << loading[i];
            Sleep(500);
        }

do
    {
        cout << "\n\nNOW LET'S BET!\n\n";
        bets.clear();
        for (int i=0; i<names.size(); i++)
        {
            while(true)
            {
                cout << names[i] << "'s bet: $";
                while (!(cin >> bet)) {
                cout << "Please enter a numerical value: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); }
                if( bet > amounts[i])
                {
                    cout << "You can't afford to bet so much, bet less!\n";
                }
                else break;
            }
            bets.push_back(bet);
        }

        cout << "\n\nGUESS THE NUMBER!\n\n";
        guesses.clear();
        for (int i=0; i<names.size(); i++)
        {
            while(true)
            {
                cout << names[i] << "'s guess: ";
                 while (!(cin >> guess)) {
                cout << "Please enter a numerical value: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); }
                if( guess > 10)
                {
                    cout << "The number you guess has to be between 1 and 10!\n";
                }
                else break;
            }
            guesses.push_back(guess);
        }

        cout << "\nPlease wait we are rolling our 10 sided dice...\n";
        for (int i = 0; i < loading[i]; i++)
        {
            cout << loading[i];
            Sleep(500);
        }

        srand(time(0));
        dice = rand()%10 + 1;
        cout << endl;
        cout << endl;
        DICEDRAW(dice);
        for (int i=0; i<players; i++)
        {
            if(dice == guesses[i])
            {
                cout << "\nCongratulations, " << names[i] <<". You won " << bets[i]* 10 << "$\n";
                amounts[i] = amounts[i] + bets[i] * 10;
            }
            else
            {
                cout << "\nBad luck this time, " << names[i] << ". You lost " << bets[i] <<"$\n";
                amounts[i] = amounts[i] - bets[i];
            }

        }
        cout << "\nThe answer was " << dice ;
        cout << "\n\n_______________________________________________________________________________________\n\n";
        for (int i = 0; i < loading[i]; i++)
        {
            cout << loading[i];
            Sleep(300);
        }
        cout << endl;
        cout << endl;
        for (int i=0; i<players; i++)
        {
            cout << "Your current wallet looks like this, "<< names[i] << ": " << amounts[i] << "$\n";
        }
        string atsakas;
        for (int i=0; i<players; i++)
        {
            if (amounts[i] > 20000000)
            {
                cout << endl;
                cout << names[i]<< "... mes pagavome jus ponas Stepukoni...Paskutiniai zodziai stadiono labui?\n";
                cin >> atsakas;

                cout << "GRAZINAT BAPKES!";
                cout << R"(
 \
 /                                 />
 \__+_____________________/\/\___/ /|
 ()______________________      / /|/\
             /0 0  ---- |----    /---\
            |0 o 0 ----|| - \ --|      \
             \0_0/____/ |    |  |\      \
                         \__/__/  |      \
PYST PYST!                        |       \
                                  |         \
                                  |__________|)";
            }
        }

        for (int i=0; i< players; i++) {
                if(amounts[i] == 0)
        {
            cout << "\n\nSadly you have no money to play... See you next time! ";
             cout << R"(
                     __/>^^^;:,
        __  __      /-.       :,/|/|
       /  \/  \  __/ ^         :,/ \__
      |        |(~             ;/ /  /
      \       {  `-'--._       / / ,<  ___
       \      /,__.   /=\     /  _/  >|_'.
        \    /  `_ `--------'    __ / ',\ \
         \  / ,_// ,---_____,   ,_  \_  ,| |
          \/   `--' |=|           \._/ ,/  |
                     \=\            `,,/   |
                      \=\            ||    /
                       \=\____       |\    \
                      / \/    `     <__)    \
                      | |                    |
                    ,__\,\                   /
                   ,--____>    /\.         ./
                   '-__________>  \.______/)";
            exit(EXIT_SUCCESS);
        }
        }

        string playagain = "\nDo you wish to continue playing? Y/N\n";
        for (int i = 0; i < playagain[i]; i++)
        {
            cout << playagain[i];
            Sleep(200);
        }
        cout << endl;
        cin >> choice;
    }
    while(choice =='Y'|| choice=='y');
    cout << "\n\nTHANK YOU FOR PLAYING! SEE YOU NEXT YEAR...\n\n";
    cout << R"(
                     __/>^^^;:,
        __  __      /-.       :,/|/|
       /  \/  \  __/ ^         :,/ \__
      |        |(~             ;/ /  /
      \       {  `-'--._       / / ,<  ___
       \      /,__.   /=\     /  _/  >|_'.
        \    /  `_ `--------'    __ / ',\ \
         \  / ,_// ,---_____,   ,_  \_  ,| |
          \/   `--' |=|           \._/ ,/  |
                     \=\            `,,/   |
                      \=\            ||    /
                       \=\____       |\    \
                      / \/    `     <__)    \
                      | |                    |
                    ,__\,\                   /
                   ,--____>    /\.         ./
                   '-__________>  \.______/)";
    return 0;
}
