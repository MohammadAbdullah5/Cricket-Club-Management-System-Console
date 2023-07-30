#include <iostream>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <windows.h>
using namespace std;

const int num = 20;
const int clubPlayers = 25;
const int clubCoaches = 3;
const int achievements = 5;
const int scheduleNumber = 10;

int usersCount = 0;
string userArrName[num];
string userArrPassword[num];
string userArrRole[num];
string clubPlayersName[clubPlayers];
int clubPlayersAge[clubPlayers];
string clubPlayersRole[clubPlayers];
string clubPlayersBattingStyle[clubPlayers];
string clubPlayersBowlingStyle[clubPlayers];
int clubPlayersSalary[clubPlayers];
string clubCoachesName[clubCoaches];
int clubCoachesAge[clubCoaches];
string clubCoachesRole[clubCoaches];
int clubCoachesSalary[clubCoaches];
string showAchievements[achievements];
string oppositions[scheduleNumber];
string dates[scheduleNumber];
string times[scheduleNumber];
string grounds[scheduleNumber];
int clubPlayerInnings[clubPlayers];
int clubPlayerRuns[clubPlayers];
int clubPlayerWickets[clubPlayers];
int clubPlayerHighScore[clubPlayers];
float clubPlayerAverage[clubPlayers];
string trainingDate[scheduleNumber];
string trainingTime[scheduleNumber];

string clubName = "Diamond Cricket Club";
int newTicketPrices = 200;
int currentPlayers = 0;
int currentCoaches = 0;

void header();
void welcome();
string login();
void subMenu(string subMenu);
string adminMenu();
string playerMenu();
string coachMenu();
string fanMenu();
string signIn(string name, string password);
bool signUp(string name, string password, string role);
void adminInterface();
void playerInterface();
void coachInterface();
void fanInterface();
void addPlayer();
void removePlayer();
void searchPlayer();
void checkFinances();
void addCoach();
void removeCoach();
void addAchievements();
void setTicketPrices();
void checkTeam();
void checkMgmtStaff();
void changePlayerName();
void scheduleMatch();
void checkSchedule();
void changePlayingX1();
void addPlayerPerformance();
void checkStats();
void scheduleTraining();
void checkAchievements();
void checkPlayingXI();
void checkTrainingSchedule();
void loadData();
void storeStatistics(string name, string role, int innings, int runs, int highScore, int average, int wickets);
void loadStatistics();
string parseWord(string line, int field);
void storeCricketersData(string name, string role, string battingStyle, string bowlingStyle, int age, int salary);
void loadCricketersData();
void storeCoachesData(string name, string role, int age, int salary);
void loadCoachesData();
void storeAchievements(string achievement1, string achievement2, string achievement3, string achievement4, string achievement5);
void loadAchievements();
void storeSchedule(string opposition, string date, string time, string ground);
void loadSchedule();
void storeTrainingSchedule(string date, string time);
void loadTrainingSchedule();
string validateInteger(string line);
string validateString(string line);
string validateSignUpRole(string line);
string validatePlayerRole(string line);
string validateBattingStyleRole(string line);
string validateBowlingStyleRole(string line);
string validateCoachesRole(string line);
string validateDate(string line);
string validateTime(string line);
void storeData(string username, string password, string role);
void addUser(string username, string password, string role);
bool isValid(string username, string role);
bool isValidPlayer(string name, string role);
bool isDateValid(string line);
bool isTimeValid(string time);
void storeAllDataInFiles();

main()
{
    loadData();
    loadCoachesData();
    loadCricketersData();
    loadStatistics();
    loadAchievements();
    loadSchedule();
    loadTrainingSchedule();
    system("cls");
    welcome();
    cout << endl
         << "Press any key to continue";
    getch();
    string option = "0";
    while (option != "3")
    {
        header();
        subMenu("Login");
        option = login();

        if (option == "1")
        {
            system("cls");
            header();
            subMenu("Signin");
            string name;
            string password;
            string role;

            cout << "\t"
                 << "Name: ";
            getline(cin, name);
            cout << "\t"
                 << "Password: ";
            getline(cin, password);

            role = signIn(name, password);

            if (role == "Admin")
            {
                system("cls");
                adminInterface();
            }

            else if (role == "Player")
            {
                system("cls");
                playerInterface();
            }

            else if (role == "Coach")
            {
                system("cls");
                coachInterface();
            }

            else if (role == "Fans")
            {
                system("cls");
                fanInterface();
            }
            else if (role == "nothing")
            {
                cout << "\t"
                     << "You have entered invalid credentials..." << endl;
                string anykey;
                cout << "\t"
                     << "Enter any key to continue...";
                getline(cin, anykey);
            }
        }

        else if (option == "2")
        {
            bool decision;
            system("cls");
            string name, password, role, validRole;
            header();
            subMenu("Sign up");
            cout << "\t"
                 << "Username: ";
            getline(cin, name);
            cout << "\t"
                 << "Password: ";
            getline(cin, password);
            cout << "\t"
                 << "Role (Admin / Coach / Player / Fans): ";
            getline(cin, validRole);
            role = validateSignUpRole(validRole);
            decision = isValid(name, role);
            if (decision == true)
            {
                bool ok = signUp(name, password, role);
                if (ok == true)
                {
                    storeData(name, password, role);
                    addUser(name, password, role);
                    cout << "\t"
                         << "Signed up successfully." << endl;
                }

                else if (ok == false)
                {
                    cout << "\t"
                         << "User capacity have been filled." << endl;
                }
            }
            else if (decision == false)
            {
                cout << "\t"
                     << "User already exists" << endl;
            }

            cout << "\t"
                 << "Enter any key to continue...";
            string userEnter;
            getline(cin, userEnter);
        }
        else if (option == "3")
        {
            continue;
        }
        else
        {
            cout << "\t"
                 << "Invalid Input.Try Again" << endl;
            getch();
        }
    }
    storeAllDataInFiles();
}

void header()
{
    system("cls");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 112);

    cout << "             _________        .__        __           __    _________ .__       ___.                               " << endl;
    cout << "             \\_   ___ \\_______|__| ____ |  | __ _____/  |_  \\_   ___ \\|  |  __ _\\_ |__                              " << endl;
    cout << "             /    \\  \\/\\_  __ \\  |/ ___\\|  |/ // __ \\   __\\ /    \\  \\/|  | |  |  \\ __ \\                                " << endl;
    cout << "             \\     \\____|  | \\/  \\  \\___|    <\\  ___/|  |   \\     \\___|  |_|  |  / \\_\\ \\                                 " << endl;
    cout << "              \\______  /|__|  |__|\\___  >__|_ \\\\___  >__|    \\______  /____/____/|___  /                                 " << endl;
    cout << "                     \\/               \\/     \\/    \\/               \\/               \\/                                  " << endl;
    cout << "     _____                                                             __      _________               __                  " << endl;
    cout << "   /     \\ _____    ____ _____     ____   ____   _____   ____   _____/  |_   /   _____/__.__. _______/  |_  ____   _____  " << endl;
    cout << "  /  \\ /  \\\\__  \\  /    \\\\__  \\   / ___\\_/ __ \\ /     \\_/ __ \\ /    \\   __\\  \\_______<   |  |/  ___/\\   __\\/ __ \\ /     \\ " << endl;
    cout << " /    Y    \\/ __ \\|   |  \\/ __ \\_/ /_/  >  ___/|  Y Y  \\  ___/|   |  \\  |    /        \\___  |\\___ \\  |  | \\  ___/|  Y Y  \\" << endl;
    cout << " \\____|__  (____  /___|  (____  /\\___  / \\___  >__|_|  /\\___  >___|  /__|   /_______  / ____/____  > |__|  \\___  >__|_|  /" << endl;
    cout << "         \\/     \\/     \\/     \\//_____/      \\/      \\/     \\/     \\/               \\/\\/         \\/            \\/      \\/ " << endl;

    cout << endl
         << endl;
    SetConsoleTextAttribute(hConsole, 113);
}

void welcome()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 112);
    cout << "\t"
         << "                        d8b             888                   888    " << endl;
    cout << "\t"
         << "                                        888                   888    " << endl;
    cout << "\t"
         << "                                        888                   888    " << endl;
    cout << "\t"
         << "     .d8888b8  88d888   888    .d8888   b888 .d88    .d88b.   888888     " << endl;
    cout << "\t"
         << "    d88P       888P     888   d88P      888.d88P     d8  8    Y8b     " << endl;
    cout << "\t"
         << "    Y88b.      888      888   Y88b.     888  .d88    Y8b/     Y88 " << endl;
    cout << "\t"
         << "      Y8888P   888      888     Y8888   P888    88    Y8888    Y8880" << endl;
}

string login()
{
    cout << "\t"
         << "1. Sign in" << endl;
    cout << "\t"
         << "2. Sign Up" << endl;
    cout << "\t"
         << "3. Exit" << endl;
    string option;
    cout << "\t"
         << "Enter an option...";
    getline(cin, option);

    return option;
}

void subMenu(string subMenu)
{
    string message = subMenu + " Menu";
    cout << "\t" << message << endl;
    cout << "\t"
         << "-------------------" << endl;
}

string adminMenu()
{
    cout << "\t"
         << " 1. Add a player." << endl;
    cout << "\t"
         << " 2. Remove a player." << endl;
    cout << "\t"
         << " 3. Check Finances." << endl;
    cout << "\t"
         << " 4. Search a player." << endl;
    cout << "\t"
         << " 5. Add a coach." << endl;
    cout << "\t"
         << " 6. Remove a coach." << endl;
    cout << "\t"
         << " 7. Add Achievements." << endl;
    cout << "\t"
         << " 8. Set Ticket Prices." << endl;
    cout << "\t"
         << " 9. Check Team." << endl;
    cout << "\t"
         << "10. Check Management Staff." << endl;
    cout << "\t"
         << "11. Change a player's name." << endl;
    cout << "\t"
         << "12. Schedule a match." << endl;
    cout << "\t"
         << "13. Exit." << endl;
    cout << "\t"
         << "Enter an option...";
    string option;
    getline(cin, option);
    return option;
}

string playerMenu()
{
    cout << "\t"
         << "1. Check Schedule." << endl;
    cout << "\t"
         << "2. Check Playing XI." << endl;
    cout << "\t"
         << "3. Check Statistics." << endl;
    cout << "\t"
         << "4. Check Achievements." << endl;
    cout << "\t"
         << "5. Check Training Schedule." << endl;
    cout << "\t"
         << "6. Exit." << endl;
    string option;
    cout << "Enter an option...";
    getline(cin, option);
    return option;
}

string coachMenu()
{
    cout << "\t"
         << " 1. Add a player." << endl;
    cout << "\t"
         << " 2. Remove a player." << endl;
    cout << "\t"
         << " 3. Search a player." << endl;
    cout << "\t"
         << " 4. Check Schedule." << endl;
    cout << "\t"
         << " 5. Check Team." << endl;
    cout << "\t"
         << " 6. Change playing XI." << endl;
    cout << "\t"
         << " 7. Check statistics of players." << endl;
    cout << "\t"
         << " 8. Schedule Training Session." << endl;
    cout << "\t"
         << " 9. Check Achievements." << endl;
    cout << "\t"
         << "10. Add Player Statistics." << endl;
    cout << "\t"
         << "11. Exit." << endl;
    string option;
    cout << "Enter your option...";
    getline(cin, option);
    return option;
}

string fanMenu()
{
    cout << "\t"
         << "1. Check Schedule." << endl;
    cout << "\t"
         << "2. Check Statistics of players" << endl;
    cout << "\t"
         << "3. Check Achievements" << endl;
    cout << "\t"
         << "4. Exit" << endl;
    string option;
    cout << "Enter your option...";
    getline(cin, option);
    return option;
}

string signIn(string name, string password)
{
    for (int idx = 0; idx < num; idx++)
    {
        if ((name == userArrName[idx]) && (password == userArrPassword[idx]))
        {
            return userArrRole[idx];
        }
    }
    return "nothing";
}

bool signUp(string name, string password, string role)
{
    if (usersCount < num)
    {
        userArrName[usersCount] = name;
        userArrPassword[usersCount] = password;
        userArrRole[usersCount] = role;
        usersCount++;
        return true;
    }

    else
    {
        return false;
    }
}

void adminInterface()
{
    string adminOption = "0";
    while (adminOption != "13")
    {
        system("cls");
        header();
        adminOption = adminMenu();
        system("cls");
        if (adminOption == "1")
        {
            header();
            addPlayer();
        }
        else if (adminOption == "2")
        {
            header();
            removePlayer();
        }
        else if (adminOption == "3")
        {
            header();
            checkFinances();
        }
        else if (adminOption == "4")
        {
            header();
            searchPlayer();
        }
        else if (adminOption == "5")
        {
            header();
            addCoach();
        }
        
        else if (adminOption == "6")
        {
            header();
            removeCoach();
        }

        else if (adminOption == "7")
        {
            header();
            addAchievements();
        }
        else if (adminOption == "8")
        {
            header();
            setTicketPrices();
        }
        else if (adminOption == "9")
        {
            header();
            checkTeam();
        }
        else if (adminOption == "10")
        {
            header();
            checkMgmtStaff();
        }
        else if (adminOption == "11")
        {
            header();
            changePlayerName();
        }
        else if (adminOption == "12")
        {
            header();
            scheduleMatch();
        }
        else if (adminOption == "13")
        {
            continue;
        }

        else
        {
            cout << "\t"
                 << "Invalid Input.Try Again." << endl;
            getch();
        }
    }
}

void playerInterface()
{
    string playerOption = "0";
    while (playerOption != "6")
    {
        system("cls");
        header();
        playerOption = playerMenu();
        system("cls");

        if (playerOption == "1")
        {
            header();
            checkSchedule();
        }

        else if (playerOption == "2")
        {
            header();
            checkPlayingXI();
        }

        else if (playerOption == "3")
        {
            header();
            checkStats();
        }

        else if (playerOption == "4")
        {
            header();
            checkAchievements();
        }

        else if (playerOption == "5")
        {
            header();
            checkTrainingSchedule();
        }

        else if (playerOption == "6")
        {
            continue;
        }
        else
        {
            cout << "\t"
                 << "Invalid Input.Try Again." << endl;
            getch();
        }
    }
}

void coachInterface()
{
    string coachOption = "0";
    while (coachOption != "11")
    {
        system("cls");
        header();
        coachOption = coachMenu();
        system("cls");

        if (coachOption == "1")
        {
            header();
            addPlayer();
        }

        else if (coachOption == "2")
        {
            header();
            removePlayer();
        }

        else if (coachOption == "3")
        {
            header();
            searchPlayer();
        }

        else if (coachOption == "4")
        {
            header();
            checkSchedule();
        }

        else if (coachOption == "5")
        {
            header();
            checkTeam();
        }

        else if (coachOption == "6")
        {
            header();
            changePlayingX1();
        }

        else if (coachOption == "7")
        {
            header();
            checkStats();
        }

        else if (coachOption == "8")
        {
            header();
            scheduleTraining();
        }

        else if (coachOption == "9")
        {
            header();
            checkAchievements();
        }

        else if (coachOption == "10")
        {
            header();
            addPlayerPerformance();
        }

        else if (coachOption == "11")
        {
            continue;
        }
        else
        {
            cout << "\t"
                 << "Invalid Input.Try Again." << endl;
            getch();
        }
    }
}

void fanInterface()
{
    string fanOption = "0";
    while (fanOption != "4")
    {
        system("cls");
        header();
        fanOption = fanMenu();
        system("cls");

        if (fanOption == "1")
        {
            header();
            checkSchedule();
        }

        else if (fanOption == "2")
        {
            header();
            checkStats();
        }

        else if (fanOption == "3")
        {
            header();
            checkAchievements();
        }

        else if (fanOption == "4")
        {
            continue;
        }
        else
        {
            cout << "\t"
                 << "Invalid Input.Try Again." << endl;
            getch();
        }
    }
}

void addPlayer()
{
    string userEnter = "1", age, salary, name, role, battingStyle, bowlingStyle, validatedAge, validatedSalary, validatedName, validatedRole, validateBatting, validateBowling;
    while (userEnter != "0")
    {
        system("cls");
        header();
        cout << "\t"
             << "Enter the player's name: ";
        getline(cin, name);
        validatedName = validateString(name);
        clubPlayersName[currentPlayers] = validatedName;
        cout << "\t"
             << "Role(Batter / Bowler / WK / AllRounder): ";
        getline(cin, role);
        validatedRole = validatePlayerRole(role);
        clubPlayersRole[currentPlayers] = validatedRole;
        cout << "\t"
             << "Batting style(Left / Right): ";
        getline(cin, battingStyle);
        validateBatting = validateBattingStyleRole(battingStyle);
        clubPlayersBattingStyle[currentPlayers] = validateBatting;
        cout << "\t"
             << "Bowling style(Left / Right / No): ";
        getline(cin, bowlingStyle);
        validateBowling = validateBowlingStyleRole(bowlingStyle);
        clubPlayersBattingStyle[currentPlayers] = validateBowling;
        cout << "\t"
             << "Enter the age of player: ";
        getline(cin, age);
        validatedAge = validateInteger(age);
        clubPlayersAge[currentPlayers] = stoi(validatedAge);
        cout << "\t"
             << "Enter his salary: ";
        getline(cin, salary);
        validatedSalary = validateInteger(salary);
        clubPlayersSalary[currentPlayers] = stoi(validatedSalary);
        storeCricketersData(clubPlayersName[currentPlayers], clubPlayersRole[currentPlayers], clubPlayersBattingStyle[currentPlayers], clubPlayersBowlingStyle[currentPlayers], clubPlayersAge[currentPlayers], clubPlayersSalary[currentPlayers]);
        currentPlayers++;
        cout << "\t"
             << "Do you want to continue?" << endl
             << "\t"
             << "Enter 0 to exit. " << endl
             << "\t"
             << "Enter any other key to continue...";
        getline(cin, userEnter);
    }
}

void removePlayer()
{
    string nameToRemove, name;
    string userEnter = "1";
    while (userEnter != "0")
    {
        cout << "\t"
             << "Enter the name of player you want to remove: ";
        getline(cin, nameToRemove);
        name = validateString(nameToRemove);
        nameToRemove = name;
        for (int idx = 0; idx < currentPlayers; idx++)
        {
            if (nameToRemove == clubPlayersName[idx])
            {
                clubPlayersName[idx] = "";
                clubPlayersAge[idx] = 0;
                clubPlayersBattingStyle[idx] = "";
                clubPlayersBowlingStyle[idx] = "";
                clubPlayersRole[idx] = "";
                clubPlayersSalary[idx] = 0;
                currentPlayers--;
            }
        }
        cout << "\t"
             << "Do you want to continue?" << endl
             << "\t"
             << "Enter 0 to exit." << endl
             << "\t"
             << "Enter any other number to continue...";
        getline(cin, userEnter);
    }
}

void checkFinances()
{
    int sumPlayer = 0;
    int sumCoach = 0;
    string userEnter = "1";
    while (userEnter != "0")
    {
        for (int idx = 0; idx < currentPlayers; idx++)
        {
            sumPlayer = sumPlayer + clubPlayersSalary[idx];
        }
        for (int idx = 0; idx < currentCoaches; idx++)
        {
            sumCoach = sumCoach + clubCoachesSalary[idx];
        }
        cout << "\t"
             << "1. Player's Salary: " << sumPlayer << endl;
        cout << "\t"
             << "2. Coach's Salary: " << sumCoach << endl;

        cout << "\t"
             << "Enter 0 to exit." << endl
             << "\t"
             << "Enter any other number to continue...";
        getline(cin, userEnter);
    }
}

void addCoach()
{
    string userEnter = "1";
    string age, salary, name, role;
    string validatedAge, validatedSalary, validatedName, validatedRole;
    while (userEnter != "0")
    {
        cout << "\t"
             << "Enter the coach's name: ";
        getline(cin, name);
        validatedName = validateString(name);
        clubCoachesName[currentCoaches] = validatedName;
        cout << "\t"
             << "Role(Head / Batting / Bowling / WK / Fielding): ";
        getline(cin, role);
        validatedRole = validateCoachesRole(role);
        clubCoachesRole[currentCoaches] = validatedRole;
        cout << "\t"
             << "Enter the age of coach: ";
        getline(cin, age);
        validatedAge = validateInteger(age);
        clubCoachesAge[currentCoaches] = stoi(validatedAge);
        cout << "\t"
             << "Enter his salary: ";
        getline(cin, salary);
        validatedSalary = validateInteger(salary);
        clubCoachesSalary[currentCoaches] = stoi(validatedSalary);
        storeCoachesData(clubCoachesName[currentCoaches], clubCoachesRole[currentCoaches], clubCoachesAge[currentCoaches], clubCoachesSalary[currentCoaches]);
        currentCoaches++;
        cout << "\t"
             << "Do you want to continue?" << endl
             << "\t"
             << "Enter 0 to exit." << endl
             << "\t"
             << "Enter any other number to continue...";
        getline(cin, userEnter);
    }
}

void removeCoach()
{
    string nameToRemove;
    string userEnter = "1";
    while (userEnter != "0")
    {
        cout << "\t"
             << "Enter the name of coach you want to remove: ";
        getline(cin, nameToRemove);

        for (int idx = 0; idx < clubCoaches; idx++)
        {
            if ((nameToRemove == clubCoachesName[idx]))
            {
                clubCoachesName[idx] = "";
                clubCoachesAge[idx] = 0;
                clubCoachesRole[idx] = "";
                clubCoachesSalary[idx] = 0;
                currentCoaches--;
            }
        }
        cout << "\t"
             << "Do you want to continue?" << endl
             << "\t"
             << "Press 0 to exit." << endl
             << "\t"
             << "Enter any other number to continue...";
        getline(cin, userEnter);
    }
}

void addAchievements()
{
    string userEnter = "1";
    while (userEnter != "0")
    {
        cout << "\t"
             << "Enter Achievements:-" << endl;
        for (int idx = 0; idx < achievements; idx++)
        {
            getline(cin, showAchievements[idx]);
        }
        storeAchievements(showAchievements[0], showAchievements[1], showAchievements[2], showAchievements[3], showAchievements[4]);
        cout << "\t"
             << "Do you want to continue?" << endl
             << "\t"
             << "Press 0 to exit." << endl
             << "\t"
             << "Enter any other number to continue...";
        getline(cin, userEnter);
    }
}

void setTicketPrices()
{
    string userEnter = "1";
    string ticketPrice;
    string validatedPrice;
    while (userEnter != "0")
    {
        cout << "\t"
             << "Set New Ticket Prices: ";
        getline(cin, ticketPrice);
        validatedPrice = validateInteger(ticketPrice);
        newTicketPrices = stoi(validatedPrice);
        cout << "\t"
             << "Do you want to continue?" << endl
             << "\t"
             << "Enter 0 to exit." << endl
             << "\t"
             << "Enter any other number to continue...";
        getline(cin, userEnter);
        getline(cin, userEnter);
    }
}

void checkTeam()
{
    string userEnter = "1";
    while (userEnter != "0")
    {
        cout << "\t"
             << "     "
             << "Name"
             << "    "
             << "    Age"
             << "    "
             << "    Role"
             << "    "
             << "    Batting Style"
             << "    "
             << "    Bowling Style"
             << "    "
             << "    Salary" << endl;
        for (int idx = 0; idx < currentPlayers; idx++)
        {
            cout << "\t" << idx + 1 << ".    " << clubPlayersName[idx] << "    " << clubPlayersAge[idx] << "    " << clubPlayersRole[idx] << "    " << clubPlayersBattingStyle[idx] << "    " << clubPlayersBowlingStyle[idx] << "    " << clubPlayersSalary[idx] << endl;
        }
        cout << "Enter 0 to exit." << endl
             << "Enter any other number to continue...";
        getline(cin, userEnter);
    }
}

void checkMgmtStaff()
{
    string userEnter = "1";
    while (userEnter != "0")
    {
        cout << "\t"
             << "     "
             << "Name"
             << "    "
             << "Age"
             << "    "
             << "Role"
             << "    "
             << "Salary" << endl;
        for (int idx = 0; idx < clubCoaches; idx++)
        {
            cout << "\t" << idx + 1 << ".   " << clubCoachesName[idx] << "   " << clubCoachesAge[idx] << "    " << clubCoachesRole[idx] << "   " << clubCoachesSalary[idx] << endl;
        }
        cout << "Enter 0 to exit." << endl
             << "Enter any other number to continue...";
        getline(cin, userEnter);
    }
}

void searchPlayer()
{
    string search;
    bool flag = false;
    string userEnter = "1";
    while (userEnter != "0")
    {
        cout << "\t"
             << "Enter the player's name: ";
        getline(cin, search);

        for (int idx = 0; idx < clubPlayers; idx++)
        {
            if (search == clubPlayersName[idx])
            {
                flag = true;
                cout << "\t"
                     << "The player is at index " << idx << endl;
                cout << "\t"
                     << "Player's Role: " << clubPlayersRole[idx] << endl;
                cout << "\t"
                     << "Player's Batting Style: " << clubPlayersBattingStyle[idx] << endl;
                cout << "\t"
                     << "Player's Bowling Style: " << clubPlayersBowlingStyle[idx] << endl;
                cout << "\t"
                     << "Player's Salary: " << clubPlayersSalary[idx] << endl;
            }
        }
        if (flag == false)
        {
            cout << "\t"
                 << "There is no such player in the team." << endl;
        }
        cout << "\t"
             << "Do you want to continue?" << endl;
        cout << "\t"
             << "Enter 0 to exit." << endl
             << "\t"
             << "Enter any other number to continue...";
        getline(cin, userEnter);
    }
}

void scheduleMatch()
{
    string ground;
    string validatedTime;
    string validatedOpposition;
    string validatedDate;
    string userEnter = "1";
    while (userEnter != "0")
    {
        for (int idx = 0; idx < scheduleNumber; idx++)
        {
            cout << "\t"
                 << "Match " << idx + 1 << endl;
            cout << "\t"
                 << "Enter the opposite club name: ";
            getline(cin, validatedOpposition);
            oppositions[idx] = validateString(validatedOpposition);
            cout << "\t"
                 << "Date: ";
            getline(cin, validatedDate);
            dates[idx] = validateDate(validatedDate);
            cout << "\t"
                 << "Time: ";
            getline(cin, validatedTime);
            times[idx] = validateTime(validatedTime);
            cout << "\t"
                 << "Ground: ";
            getline(cin, ground);
            grounds[idx] = validateString(ground);
            storeSchedule(oppositions[idx], dates[idx], times[idx], grounds[idx]);
            cout << "\t"
                 << "Do you want to continue?" << endl
                 << "\t"
                 << "Press 0 to exit." << endl;
            string anykey = "2";
            getline(cin, anykey);
            if (anykey == "0")
            {
                break;
            }
        }
        cout << "\t"
             << "Enter 0 to exit the menu." << endl
             << "\t"
             << "Enter any other number to continue...";
        getline(cin, userEnter);
        getline(cin, userEnter);
    }
}

void checkSchedule()
{
    string userEnter = "1";

    for (int idx = 0; idx < scheduleNumber; idx++)
    {
        cout << "\t" << clubName << " vs " << oppositions[idx] << "       " << dates[idx] << "       " << times[idx] << "       " << grounds[idx] << endl;
    }

    cout << "\t"
         << "Enter any key to exit.";
    getline(cin, userEnter);
}

void changePlayingX1()
{
    string userEnter = "1";
    int idx1, idx2, temp;
    string index1, index2, temp2;
    string temp1;
    string validatedIndex1, validatedIndex2;
    while (userEnter != "0")
    {
        cout << "\t"
             << "Enter Player in playing XI(index): ";
        getline(cin, index1);
        validatedIndex1 = validateInteger(index1);
        idx1 = stoi(validatedIndex1);
        idx1 = idx1 - 1;
        cout << "\t"
             << "Enter substitution player(index): ";
        getline(cin, index2);
        validatedIndex1 = validateInteger(index1);
        idx2 = stoi(validatedIndex2);
        idx2 = idx2 - 1;
        temp1 = clubPlayersName[idx1];
        clubPlayersName[idx1] = clubPlayersName[idx2];
        clubPlayersName[idx2] = temp1;

        temp = clubPlayersAge[idx1];
        clubPlayersAge[idx1] = clubPlayersAge[idx2];
        clubPlayersAge[idx2] = temp;

        temp1 = clubPlayersRole[idx1];
        clubPlayersRole[idx1] = clubPlayersRole[idx2];
        clubPlayersRole[idx2] = temp1;

        temp1 = clubPlayersBattingStyle[idx1];
        clubPlayersBattingStyle[idx1] = clubPlayersBattingStyle[idx2];
        clubPlayersBattingStyle[idx2] = temp1;

        temp1 = clubPlayersBowlingStyle[idx1];
        clubPlayersBowlingStyle[idx1] = clubPlayersBowlingStyle[idx2];
        clubPlayersBowlingStyle[idx2] = temp1;

        temp = clubPlayersSalary[idx1];
        clubPlayersSalary[idx1] = clubPlayersSalary[idx2];
        clubPlayersSalary[idx2] = temp;

        cout << "\t"
             << "Do you want to continue?" << endl;
        cout << "\t"
             << "Enter 0 to exit." << endl
             << "\t"
             << "Enter any other number to continue...";
        getline(cin, userEnter);
        getline(cin, userEnter);
    }
}

void changePlayerName()
{
    string userEnter = "1";
    string name, role, validatedName;
    string correctName;
    bool decision;
    while (userEnter != "0")
    {

        cout << "\t"
             << "Name of player which was recorded previously: ";
        getline(cin, validatedName);
        name = validateString(validatedName);

        cout << "\t"
             << "His Role: ";
        getline(cin, role);
        decision = isValidPlayer(name, role);
        if (decision == true)
        {
            for (int idx = 0; idx < currentPlayers; idx++)
            {
                if ((name == clubPlayersName[idx]) && (role == clubPlayersRole[idx]))
                {
                    cout << "\t"
                         << "Write the corrected name: ";
                    getline(cin, correctName);
                    clubPlayersName[idx] = correctName;
                }
            }
        }
        else
        {
            cout << "\t"
                 << "There is no such player..." << endl;
        }

        cout << "\t"
             << "Do you want to continue?" << endl;
        cout << "\t"
             << "Enter 0 to exit." << endl
             << "\t"
             << "Enter any other number to continue...";
        getline(cin, userEnter);
    }
}

void addPlayerPerformance()
{
    string userEnter = "1";
    string name, role, avg;
    string validatedRuns, validatedInnings, validatedWickets, validatedHighScore, validatedName;
    string runs, innings, wickets, highScore;
    string validatedRole;
    float average;
    bool decision;

    while (userEnter != "0")
    {
        cout << "\t"
             << "Player's name: ";
        getline(cin, validatedName);
        name = validateString(validatedName);
        cout << "\t"
             << "Player's Role: ";
        getline(cin, validatedRole);
        role = validatePlayerRole(validatedRole);
        decision = isValidPlayer(name, role);
        if (decision == true)
        {
            for (int idx = 0; idx < currentPlayers; idx++)
            {
                if ((clubPlayersName[idx] == name))
                {
                    cout << "\t"
                         << "Enter his runs: ";
                    getline(cin, runs);
                    validatedRuns = validateInteger(runs);
                    clubPlayerRuns[idx] = stoi(validatedRuns);
                    cout << "\t"
                         << "Nummber of innings: ";
                    getline(cin, innings);
                    validatedInnings = validateInteger(innings);
                    clubPlayerInnings[idx] = stoi(validatedInnings);
                    cout << "\t"
                         << "Number of wickets: ";
                    getline(cin, wickets);
                    validatedWickets = validateInteger(wickets);
                    clubPlayerWickets[idx] = stoi(validatedWickets);
                    cout << "\t"
                         << "Highest Score: ";
                    getline(cin, highScore);
                    validatedHighScore = validateInteger(highScore);
                    clubPlayerHighScore[idx] = stoi(validatedHighScore);
                    average = clubPlayerRuns[idx] / clubPlayerInnings[idx];
                    cout << "\t"
                         << "Average: " << average << endl;
                    clubPlayerAverage[idx] = average;
                    storeStatistics(clubPlayersName[idx], clubPlayersRole[idx], clubPlayerInnings[idx], clubPlayerRuns[idx], clubPlayerHighScore[idx], clubPlayerAverage[idx], clubPlayerWickets[idx]);
                }
            }

            cout << "\t"
                 << "Do you want to continue?" << endl;
            cout << "\t"
                 << "Enter 0 to exit." << endl
                 << "\t"
                 << "Enter any other number to continue...";
            getline(cin, userEnter);
        }

        if (decision == false)
        {
            cout << "\t"
                 << "There is no such player in database.Try Again..";
            getch();
            userEnter = "0";
        }
    }
}

void checkStats()
{
    string userEnter = "1";
    string name, role;
    string validatedName, validatedRole;
    bool decision;
    while (userEnter != "0")
    {
        cout << "\t"
             << "Player's Name: ";
        getline(cin, validatedName);
        name = validateString(validatedName);
        cout << "\t"
             << "Player's Role: ";
        getline(cin, validatedRole);
        role = validatePlayerRole(validatedRole);
        decision = isValidPlayer(name, role);
        if (decision == true)
        {
            for (int idx = 0; idx < currentPlayers; idx++)
            {
                if ((name == clubPlayersName[idx]) && (role == clubPlayersRole[idx]))
                {
                    cout << "\t"
                         << "Player Name: " << name << endl;
                    cout << "\t"
                         << "Player's Role: " << role << endl;
                    cout << "\t"
                         << "Innings: " << clubPlayerInnings[idx] << endl;
                    cout << "\t"
                         << "Runs: " << clubPlayerRuns[idx] << endl;
                    cout << "\t"
                         << "Wickets: " << clubPlayerWickets[idx] << endl;
                    cout << "\t"
                         << "Highest Score: " << clubPlayerHighScore[idx] << endl;
                    cout << "\t"
                         << "Average: " << clubPlayerAverage[idx] << endl;
                }
            }
        }
        else
        {
            cout << "\t"
                 << "There is no such player..." << endl;
        }

        cout << "\t"
             << "Do you want to continue?" << endl;
        cout << "\t"
             << "Enter 0 to exit." << endl
             << "\t"
             << "Enter any other number to continue...";
        getline(cin, userEnter);
    }
}

void scheduleTraining()
{
    string userEnter = "1";
    string validatedTime, validatedDate;
    while (userEnter != "0")
    {
        for (int idx = 0; idx < scheduleNumber - 5; idx++)
        {
            cout << "\t"
                 << "Enter Date: ";
            getline(cin, validatedDate);
            trainingDate[idx] = validateDate(validatedDate);
            cout << "\t"
                 << "Enter Time: ";
            getline(cin, validatedTime);
            trainingTime[idx] = validateTime(validatedTime);
            storeTrainingSchedule(trainingDate[idx], trainingTime[idx]);
        }

        cout << "\t"
             << "Enter 0 to exit." << endl
             << "\t"
             << "Enter any other number to continue...";
        getline(cin, userEnter);
    }
}

void checkAchievements()
{
    string userEnter = "1";
    while (userEnter != "0")
    {
        for (int idx = 0; idx < achievements; idx++)
        {
            cout << idx + 1 << ". " << showAchievements[idx] << endl;
        }
        cout << "\t"
             << "Enter 0 to exit." << endl
             << "\t"
             << "Enter any other number to continue...";
        getline(cin, userEnter);
    }
}

void checkPlayingXI()
{
    string userEnter = "1";
    while (userEnter != "0")
    {
        for (int idx = 0; idx < 11; idx++)
        {
            cout << idx + 1 << ". " << clubPlayersName[idx] << endl;
        }
        cout << "\t"
             << "Enter 0 to exit.";
        getline(cin, userEnter);
        getline(cin, userEnter);
    }
}

void checkTrainingSchedule()
{
    string userEnter = "1";
    while (userEnter != "0")
    {
        cout << "\t"
             << "                       Date"
             << "        Time" << endl;
        for (int idx = 0; idx < scheduleNumber - 5; idx++)
        {
            cout << "\t"
                 << "Training Session " << idx + 1 << ". " << trainingDate[idx] << "    " << trainingTime[idx] << endl;
        }
        cout << "\t"
             << "Enter 0 to exit.";
        getline(cin, userEnter);
        getline(cin, userEnter);
    }
}

void storeData(string username, string password, string role)
{
    fstream file;
    file.open("Data.txt", ios::app);
    file << username << ",";
    file << password << ",";
    file << role << endl;
    file.close();
}

void addUser(string username, string password, string role)
{
    userArrName[usersCount] = username;
    userArrPassword[usersCount] = password;
    userArrRole[usersCount] = role;
    usersCount++;
}

void loadData()
{
    usersCount = 0;
    fstream file;
    string line;
    file.open("Data.txt", ios::in);
    while (getline(file, line))
    {
        userArrName[usersCount] = parseWord(line, 1);
        userArrPassword[usersCount] = parseWord(line, 2);
        userArrRole[usersCount] = parseWord(line, 3);
        usersCount++;
    }
    file.close();
}

void storeStatistics(string name, string role, int innings, int runs, int highScore, int average, int wickets)
{
    fstream file;
    file.open("CricketersStats.txt", ios::app);
    file << name << "," << role << "," << innings << "," << runs << "," << average << "," << highScore << "," << wickets << endl;
    file.close();
}

void loadStatistics()
{
    fstream file;
    string line;
    string tempName;
    string tempRole;
    file.open("CricketersStats.txt", ios::in);
    while (getline(file, line))
    {
        tempName = parseWord(line, 1);
        tempRole = parseWord(line, 2);
        for (int idx = 0; idx < 25; idx++)
        {
            if ((clubPlayersName[idx] == tempName) && (clubPlayersRole[idx] == tempRole))
            {
                clubPlayerInnings[idx] = stoi(parseWord(line, 3));
                clubPlayerRuns[idx] = stoi(parseWord(line, 4));
                clubPlayerAverage[idx] = stof(parseWord(line, 5));
                clubPlayerHighScore[idx] = stoi(parseWord(line, 6));
                clubPlayerWickets[idx] = stoi(parseWord(line, 7));
            }
        }
    }
    file.close();
}

string parseWord(string line, int field)
{
    int commaCount = 1;
    string reqdWord;
    for (int idx = 0; idx < line.length(); idx++)
    {
        if (line[idx] == ',')
        {
            commaCount++;
        }
        else if (commaCount == field)
        {
            reqdWord = reqdWord + line[idx];
        }
    }
    return reqdWord;
}

void storeCricketersData(string name, string role, string battingStyle, string bowlingStyle, int age, int salary)
{
    fstream file;
    file.open("CricketersData.txt", ios::app);
    file << name << "," << role << "," << battingStyle << "," << bowlingStyle << "," << age << "," << salary << endl;
    file.close();
}

void storeCoachesData(string name, string role, int age, int salary)
{
    fstream file;
    file.open("CoachesData.txt", ios::app);
    file << name << "," << role << "," << age << "," << salary << endl;
    file.close();
}

void loadCoachesData()
{
    fstream file;
    string line;
    int idx = 0;
    file.open("CoachesData.txt", ios::in);
    while (getline(file, line))
    {

        clubCoachesName[idx] = parseWord(line, 1);
        clubCoachesRole[idx] = parseWord(line, 2);
        clubCoachesAge[idx] = stoi(parseWord(line, 3));
        clubCoachesSalary[idx] = stoi(parseWord(line, 4));
        currentCoaches++;
        idx++;
    }

    file.close();
}

void storeAchievements(string achievement1, string achievement2, string achievement3, string achievement4, string achievement5)
{
    fstream file;
    file.open("Achievements.txt", ios::out);
    {
        file << achievement1 << ",";
        file << achievement2 << ",";
        file << achievement3 << ",";
        file << achievement4 << ",";
        file << achievement5;
    }
    file.close();
}

void loadAchievements()
{
    fstream file;
    string line;
    file.open("Achievements.txt", ios::in);
    getline(file, line);
    showAchievements[0] = parseWord(line, 1);
    showAchievements[1] = parseWord(line, 2);
    showAchievements[2] = parseWord(line, 3);
    showAchievements[3] = parseWord(line, 4);
    showAchievements[4] = parseWord(line, 5);
    file.close();
}

void loadCricketersData()
{
    fstream file;
    string line;
    string age;
    string salary;
    int idx = 0;
    file.open("CricketersData.txt", ios::in);
    while (getline(file, line))
    {
        clubPlayersName[idx] = parseWord(line, 1);
        clubPlayersRole[idx] = parseWord(line, 2);
        clubPlayersBattingStyle[idx] = parseWord(line, 3);
        clubPlayersBowlingStyle[idx] = parseWord(line, 4);
        age = parseWord(line, 5);
        clubPlayersAge[idx] = stoi(age);
        salary = parseWord(line, 6);
        clubPlayersSalary[idx] = stoi(salary);
        currentPlayers++;
        idx++;
    }
    file.close();
}

bool isValid(string username, string role)
{
    bool flag = true;
    for (int idx = 0; idx < usersCount; idx++)
    {
        if (userArrName[idx] == username && userArrRole[idx] == role)
        {
            flag = false;
            break;
        }
    }
    return flag;
}

bool isValidPlayer(string name, string role)
{
    for (int idx = 0; idx < currentPlayers; idx++)
    {
        if ((name == clubPlayersName[idx]) && (role == clubPlayersRole[idx]))
        {
            return true;
        }
    }
    return false;
}

void storeSchedule(string opposition, string date, string time, string ground)
{
    fstream file;
    file.open("Schedule.txt", ios::app);
    file << opposition << "," << date << "," << time << "," << ground << endl;
    file.close();
}

void loadSchedule()
{
    fstream file;
    string line;
    int idx = 0;
    file.open("Schedule.txt", ios::in);
    while (getline(file, line))
    {
        oppositions[idx] = parseWord(line, 1);
        dates[idx] = parseWord(line, 2);
        times[idx] = parseWord(line, 3);
        grounds[idx] = parseWord(line, 4);
    }
    file.close();
}

void storeTrainingSchedule(string date, string time)
{
    fstream file;
    file.open("Training.txt", ios::app);
    file << date << "," << time << endl;
    file.close();
}

void loadTrainingSchedule()
{
    fstream file;
    int idx = 0;
    string line;
    file.open("Training.txt", ios::in);
    while (getline(file, line))
    {
        trainingDate[idx] = parseWord(line, 1);
        trainingTime[idx] = parseWord(line, 2);
        idx++;
    }
    file.close();
}

string validateInteger(string line)
{
    char ch;
    int ascii;
    int idx = 0;
    string num;
    bool flag = true;
    bool outerLoop = true;
    while (outerLoop == true)
    {
        while (line[idx] != '\0')
        {
            flag = true;
            ch = line[idx];
            ascii = int(ch);
            if ((ascii > 47) && (ascii < 58))
            {
                num = num + line[idx];
            }
            else if ((ascii <= 47) || (ascii >= 58))
            {
                flag = false;
            }
            idx++;
        }
        if (flag == false)
        {
            cout << "Invalid Input.Try Again" << endl;
            num = "";
            getline(cin, line);
            idx = 0;
        }
        if (flag == true)
        {
            return num;
        }
    }
}

string validateString(string line)
{
    char ch;
    int ascii;
    int idx = 0;
    string words;
    bool flag = true;
    bool outerLoop = true;
    while (outerLoop == true)
    {
        while (line[idx] != '\0')
        {
            flag = true;
            ch = line[idx];
            ascii = int(ch);
            if (((ascii > 64) && (ascii <= 91)) || ((ascii > 96) && (ascii <= 122)) || (ascii == 32))
            {
                words = words + line[idx];
            }
            else if (((ascii < 64) || (ascii > 92)) && ((ascii < 96) || (ascii > 122)))
            {
                flag = false;
            }
            idx++;
        }
        if (flag == false)
        {
            cout << "\t"
                 << "Invalid Input.Enter only Alphabets or Space.Try Again" << endl
                 << "\t";
            words = "";
            getline(cin, line);
            idx = 0;
        }
        if (flag == true)
        {
            return words;
        }
    }
    return "invalid";
}

string validateSignUpRole(string line)
{
    char ch;
    int ascii;
    int idx = 0;
    string words;
    bool flag = true;
    bool outerLoop = true;
    while (outerLoop == true)
    {
        while (line[idx] != '\0')
        {
            flag = true;
            ch = line[idx];
            ascii = int(ch);
            if (((ascii > 64) && (ascii <= 91)) || ((ascii > 96) && (ascii <= 122)))
            {
                words = words + line[idx];
            }
            else if (((ascii < 64) || (ascii > 92)) && ((ascii < 96) || (ascii > 122)))
            {
                flag = false;
                break;
            }
            idx++;
        }
        if ((flag == true) && ((words == "Fans") || (words == "Admin") || (words == "Coach") || (words == "Player")))
        {
            return words;
        }
        flag = false;
        if (flag == false)
        {
            cout << "\t"
                 << "Invalid Input.Enter only one of these.(Admin, Coach, Player, Fans).Try Again" << endl
                 << "\t";
            words = "";
            getline(cin, line);
            idx = 0;
        }
    }
    return "invalid";
}

string validatePlayerRole(string line)
{
    char ch;
    int ascii;
    int idx = 0;
    string words;
    bool flag = true;
    bool outerLoop = true;
    while (outerLoop == true)
    {
        while (line[idx] != '\0')
        {
            flag = true;
            ch = line[idx];
            ascii = int(ch);
            if (((ascii > 64) && (ascii <= 91)) || ((ascii > 96) && (ascii <= 122)))
            {
                words = words + line[idx];
            }
            else if (((ascii < 64) || (ascii > 92)) && ((ascii < 96) || (ascii > 122)))
            {
                flag = false;
                break;
            }
            idx++;
        }
        if ((flag == true) && ((words == "Batter") || (words == "Bowler") || (words == "WK") || (words == "AllRounder")))
        {
            return words;
        }
        flag = false;
        if (flag == false)
        {
            cout << "\t"
                 << "Invalid Input.Enter only one of these.(Batter, Bowler, WK, AllRounder).Try Again" << endl
                 << "\t";
            words = "";
            getline(cin, line);
            idx = 0;
        }
    }
    return "invalid";
}

string validateBattingStyleRole(string line)
{
    char ch;
    int ascii;
    int idx = 0;
    string words;
    bool flag = true;
    bool outerLoop = true;
    while (outerLoop == true)
    {
        while (line[idx] != '\0')
        {
            flag = true;
            ch = line[idx];
            ascii = int(ch);
            if (((ascii > 64) && (ascii <= 91)) || ((ascii > 96) && (ascii <= 122)))
            {
                words = words + line[idx];
            }
            else if (((ascii < 64) || (ascii > 92)) && ((ascii < 96) || (ascii > 122)))
            {
                flag = false;
                break;
            }
            idx++;
        }
        if ((flag == true) && ((words == "Left") || (words == "Right")))
        {
            return words;
        }
        flag = false;
        if (flag == false)
        {
            cout << "\t"
                 << "Invalid Input.Enter only one of these.(Left/Right).Try Again" << endl
                 << "\t";
            words = "";
            getline(cin, line);
            idx = 0;
        }
    }
    return "invalid";
}

string validateBowlingStyleRole(string line)
{
    char ch;
    int ascii;
    int idx = 0;
    string words;
    bool flag = true;
    bool outerLoop = true;
    while (outerLoop == true)
    {
        while (line[idx] != '\0')
        {
            flag = true;
            ch = line[idx];
            ascii = int(ch);
            if (((ascii > 64) && (ascii <= 91)) || ((ascii > 96) && (ascii <= 122)))
            {
                words = words + line[idx];
            }
            else if (((ascii < 64) || (ascii > 92)) && ((ascii < 96) || (ascii > 122)))
            {
                flag = false;
                break;
            }
            idx++;
        }
        if ((flag == true) && ((words == "Left") || (words == "Right") || (words == "No")))
        {
            return words;
        }
        flag = false;
        if (flag == false)
        {
            cout << "\t"
                 << "Invalid Input.Enter only one of these.(Left/Right/No).Try Again" << endl
                 << "\t";
            words = "";
            getline(cin, line);
            idx = 0;
        }
    }
    return "invalid";
}

string validateTime(string line)
{
    bool flag = false;
    while (flag == false)
    {
        flag = isTimeValid(line);

        if (flag == false)
        {
            cout << "\t"
                 << "Invalid Input.Enter time in (hh:mm) format...Try Again." << endl;
            cout << "\t"
                 << "Note: Hours(0---23) and Minutes(0---59)" << endl
                 << "\t";
            getline(cin, line);
        }

        if (flag == true)
        {
            return line;
        }
    }
    return "invalid";
}

bool isTimeValid(string time)
{
    if (time.length() != 5)
    {
        return false;
    }

    if (time[2] != ':')
    {
        return false;
    }

    string hours, minutes;
    for (int idx = 0; idx < 2; idx++)
    {
        hours = hours + time[idx];
    }
    for (int idx = 3; idx < 5; idx++)
    {
        minutes = minutes + time[idx];
    }

    if (((stoi(hours) >= 24) || (stoi(hours) < 0)) || ((stoi(minutes) >= 60) || (stoi(minutes) < 0)))
    {
        return false;
    }

    return true;
}

bool isDateValid(string line)
{
    string date, month, year;
    if (line.length() != 10)
    {
        return false;
    }

    if ((line[2] != '-') || (line[5] != '-'))
    {
        return false;
    }

    for (int idx = 0; idx < 2; idx++)
    {
        date = date + line[idx];
    }

    for (int idx = 3; idx < 5; idx++)
    {
        month = month + line[idx];
    }

    for (int idx = 6; idx < 10; idx++)
    {
        year = year + line[idx];
    }

    if (((stoi(date) > 31) || (stoi(date) < 0)) || ((stoi(month) > 12) || (stoi(month) < 0)) || ((stoi(year) > 2030) || (stoi(year) < 0)))
    {
        return false;
    }
    return true;
}

string validateDate(string line)
{
    bool flag = false;
    while (flag == false)
    {
        flag = isDateValid(line);
        if (flag == false)
        {
            cout << "\t"
                 << "Invalid Input. Enter Date in (dd-mm-yyyy) format.Try Again..." << endl;
            cout << "\t"
                 << "Note: Date(0---31) and Month(0---12) and Year(0000---2030)" << endl
                 << "\t";
            getline(cin, line);
        }
        if (flag == true)
        {
            return line;
        }
    }
    return "invalid";
}

void storeAllDataInFiles()
{
    fstream file;

    file.open("Achievements.txt", ios::out);
    for (int idx = 0; idx < achievements; idx++)
    {
        if ((idx == (achievements - 1)) && (idx != 0))
        {
            file << showAchievements[idx];
        }
        else
        {
            file << showAchievements[idx] << ",";
        }
    }
    file.close();

    file.open("CoachesData.txt", ios::out);
    for (int idx = 0; idx < currentCoaches; idx++)
    {
        if ((idx == (currentCoaches - 1)) && (idx != 0))
        {
            file << clubCoachesName[idx] << "," << clubCoachesRole[idx] << "," << clubCoachesAge[idx] << "," << clubCoachesSalary[idx];
        }
        else
        {
            file << clubCoachesName[idx] << "," << clubCoachesRole[idx] << "," << clubCoachesAge[idx] << "," << clubCoachesSalary[idx] << endl;
        }
    }
    file.close();

    file.open("CricketersData.txt", ios::out);
    {
        for (int idx = 0; idx < currentPlayers; idx++)
        {
            if ((idx == (currentPlayers - 1)) && (idx != 0))
            {
                file << clubPlayersName[idx] << "," << clubPlayersRole[idx] << "," << clubPlayersBattingStyle[idx] << "," << clubPlayersBowlingStyle[idx] << "," << clubPlayersAge[idx] << "," << clubPlayersSalary[idx];
            }
            else
            {
                file << clubPlayersName[idx] << "," << clubPlayersRole[idx] << "," << clubPlayersBattingStyle[idx] << "," << clubPlayersBowlingStyle[idx] << "," << clubPlayersAge[idx] << "," << clubPlayersSalary[idx] << endl;
            }
        }
    }
    file.close();

    file.open("CricketersStats.txt", ios::out);

    for (int idx = 0; idx < currentPlayers; idx++)
    {
        if ((idx == (currentPlayers - 1)) && (idx != 0))
        {
            file << clubPlayersName[idx] << "," << clubPlayersRole[idx] << "," << clubPlayerRuns[idx] << "," << clubPlayerInnings[idx] << "," << clubPlayerAverage[idx] << "," << clubPlayerHighScore[idx] << "," << clubPlayerWickets[idx];
        }
        else
        {
            file << clubPlayersName[idx] << "," << clubPlayersRole[idx] << "," << clubPlayerRuns[idx] << "," << clubPlayerInnings[idx] << "," << clubPlayerAverage[idx] << "," << clubPlayerHighScore[idx] << "," << clubPlayerWickets[idx] << endl;
        }
    }
    file.close();
}

string validateCoachesRole(string line)
{
    char ch;
    int ascii;
    int idx = 0;
    string words;
    bool flag = true;
    bool outerLoop = true;
    while (outerLoop == true)
    {
        while (line[idx] != '\0')
        {
            flag = true;
            ch = line[idx];
            ascii = int(ch);
            if (((ascii > 64) && (ascii <= 91)) || ((ascii > 96) && (ascii <= 122)))
            {
                words = words + line[idx];
            }
            else if (((ascii < 64) || (ascii > 92)) && ((ascii < 96) || (ascii > 122)))
            {
                flag = false;
                break;
            }
            idx++;
        }
        if ((flag == true) && ((words == "Head") || (words == "Batting") || (words == "Bowling") || (words == "WK") || (words == "Fielding")))
        {
            return words;
        }
        flag = false;
        if (flag == false)
        {
            cout << "\t"
                 << "Invalid Input.Enter only one of these.(Batter, Bowler, WK, AllRounder).Try Again" << endl
                 << "\t";
            words = "";
            getline(cin, line);
            idx = 0;
        }
    }
    return "invalid";
}