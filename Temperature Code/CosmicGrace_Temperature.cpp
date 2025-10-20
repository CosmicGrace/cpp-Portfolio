/*
⚠️ Copyright Notice
This project is not open source. All rights reserved.
No unauthorized use, modification, distribution, or commercial use permitted.
Copyrighted to CosmicGrace (https://github.com/CosmicGrace)
*/

#include <iostream> // Standard Inputs
#include <iomanip> // Output Manipulation
#include <string> // the wordddsss
#include <cctype> //Checks for stuff and converts user's annoying uppercases
#include <fstream> //files
using namespace std; // Helpful, less clutter, yay


int main() 
{
    // General Variables
        fstream logFile; // calling file
        int i; // for loops

        
        bool validNumberReached = 0; // did the user fail?

        const int AMOUNTOF_TEMPVARIABLES = 2;

    // User Input Variables
        string userInput;
        int given_WeekNumbers; // amount of temperatures we will ask for
        int daysTemp_High = 0; //The current target day's highest temperature
        int daysTemp_Low = 0; //The current target day's lowest temperature
        int daysTemp_Total = 0;
        int daysTemp_Average = 0;
        

    // Tracking Variables
        int daysCalculatingFor; // How many days we need inputs for

        int num_Of_InputsToFile = 0;
        int dayCount = 0;
        int loopCount = 1;
        int temp_CurrentHigh = 0;
        int temp_CurrentLow = 0;
        int temp_CurrentAvg = 0;

        int temp_Highest = 0;
        int temp_Highest_Day = 0;

        int temp_Lowest = 0;
        int temp_Lowest_Day = 0;

        int day_MostDramatic = 0;
        int day_MostDramatic_Day = 0;

        int totalTemp;

    // Ending Variables
        double stormyWeather_Chance = 0; // Via the fronts


    // File Stuff
        string dummyStringVariable; // To ignore labels put in the text file

        logFile.open("tempLog.txt");
        
        if (!logFile.is_open()) { // for when it doesn't open
            cout << "logFile did not open" << endl;
            return 1; //error indicator
        }


    //seperation to make it look better
    cout << endl << endl << endl << "~~ ~~ ~~ ~~~~ ~~~~~~~~~~ ~~~~~~~~~~ ~~~~ ~~ ~~ ~~" << endl << endl;
    //Introduction

    cout << "Hello, hello! Its getting into fall so you know" << endl;
    cout << "what that means..." << endl;
    getline (cin,userInput); // To slow down output text so its readable

    cout << "Different weathers due to temperature changes!" << endl << endl;

    cout << "Anyways this program is to analyize fall temperatures (in " << endl;
    cout << "Fahrenheit) and give you data for it." << endl;
    //cout << "" << endl;
    getline (cin,userInput); // To slow down output text so its readable

    cout << "This data will be... day with the highest temp," << endl;
    cout << "day with the lowest temp, and the most " << endl;
    cout << "volatile day (dramatic temp change)" << endl;
    getline (cin,userInput); // To slow down output text so its readable
    
    //seperation to make it look better
    cout << endl << endl << "~~ ~~ ~~ ~~~~ ~~~~~~~~~~ ~~~~~~~~~~ ~~~~ ~~ ~~ ~~" << endl << endl << endl;
    
    
    //Data Collection
    do {
        cout << "How many weeks do you want to do? (Only 1-6 weeks)" << endl;
        cout << " - "; //user input line
        cin >> given_WeekNumbers;
        if (cin.fail()) { //Checking if the input failed (user put in letter(s))
            cin.clear(); // This will clear the cin to allow for another answer
            cin.ignore(); // Remove the value causing failure
            cout << endl << " ~!~ Invalid input, try again ~!~" << endl << endl; // Informing the user of their failure

        } else if (given_WeekNumbers >= 1 && given_WeekNumbers <= 6) { // Enforing the number in be in range
            cout << endl << left << setw(5) << setfill(' ') << " . . . . . " << endl << endl; // Seperation to make it look nice
            cout << "You have entered " << given_WeekNumbers << " weeks." << endl;
            
            daysCalculatingFor = given_WeekNumbers * 7; //Calculating the number of days
            cout << "That will be " << daysCalculatingFor << " days" << endl << endl;
            
            cout << endl << left << setw(5) << setfill(' ') << " . . . . . " << endl << endl; // Seperation to make it look nice

            cin.ignore();

            cout << "Do you want to add extra to be 31 for the month of october?" << endl;
            cout << " - "; //user input line
            getline(cin,userInput);
            
            userInput.at(0) = tolower(userInput.at(0));
            if (userInput == "yes" || userInput == "ye") {
                cout << endl << "Great! Your day count is now 31!" << endl << endl; 
                daysCalculatingFor = 31;
            }

            validNumberReached = 1;
        } else {
            cin.clear(); // This will clear the cin to allow for another answer
            cin.ignore(); // Remove the bad value
            cout << endl << " ~!~ Invalid input, try again ~!~" << endl << endl; // Informing the user of their failure
        }
    } while (validNumberReached != 1);

    validNumberReached = 0; //resetting this variable


    //seperation to make it look better
    cout << endl << endl << endl << "~~ ~~ ~~ ~~~~ ~~~~~~~~~~ ~~~~~~~~~~ ~~~~ ~~ ~~ ~~" << endl << endl << endl;
    
    //Getting the temps
    do {
        daysCalculatingFor += 1; //Adds one on top of this Variable so all days can be found
        for (dayCount = 1; dayCount < daysCalculatingFor; ++dayCount) {
            if ((dayCount != 1 && dayCount != 15 && dayCount != 22 && dayCount != 24 && dayCount != 29) && (dayCount % 8) != 0) //This is the divider for between highs and lows inputs
                cout << endl << endl << endl << " - -~ -~ -~ -~ -~ -~ ~ ~- ~- ~- ~- ~- ~- -" << endl << endl << endl; //Seperation
            else if (dayCount == 16 || dayCount == 24)
                cout << endl << endl << endl << " - -~ -~ -~ -~ -~ -~ ~ ~- ~- ~- ~- ~- ~- -" << endl << endl << endl; //Seperation

            while (validNumberReached != 1) {
                cout << endl << "What is day " << dayCount << " highest temperature?" << endl;
                cout << " - "; //user input line
                cin >> daysTemp_High;

                if (cin.fail()) { //Checking if the input failed (user put in letter(s))
                    cin.clear(); // This will clear the cin to allow for another answer
                    cin.ignore(); // Remove the value causing failure
                    daysTemp_High = 0; //reset
                    cout << endl << " ~!~ Invalid input, try again ~!~" << endl << endl; // Informing the user of their failure
                } else {
                    validNumberReached = 1;
                }
            }
            validNumberReached = 0; //reseting this variable 

            cout << endl << " - - - - - - - - - - " << endl; //Seperation

            while (validNumberReached != 1) {
                cout << endl << "What is day " << dayCount << " lowest temperature?" << endl;
                cout << " - "; //user input line
                cin >> daysTemp_Low;

                if (cin.fail()) { //Checking if the input failed (user put in letter(s))
                    cin.clear(); // This will clear the cin to allow for another answer
                    cin.ignore(); // Remove the value causing failure
                    daysTemp_Low = 0; // reset
                    cout << endl << " ~!~ Invalid input, try again ~!~" << endl << endl; // Informing the user of their failure
                } else {
                    validNumberReached = 1;
                }
            }
            validNumberReached = 0; //reseting this variable

            if ((dayCount % 7) == 0 && daysCalculatingFor > 6) {
                if (dayCount == 7) 
                    cout << endl; // making it neat
                cout << endl << endl << endl << "~~ ~~ ~~ ~~~~ ~~~~~~~~~~ ~~~~~~~~~~ ~~~~ ~~ ~~ ~~" << endl << endl << endl << endl; //Seperation
            }


            //Calculating
            daysTemp_Total = daysTemp_High + daysTemp_Low;
            daysTemp_Average = daysTemp_Total / AMOUNTOF_TEMPVARIABLES;
            num_Of_InputsToFile += 1;

            if (logFile.is_open()) {
            // Giving File its Values
            logFile << "Day: ";
            logFile << dayCount;

            logFile << " High: ";
            logFile << daysTemp_High;

            logFile << " Low: ";
            logFile << daysTemp_Low;

            logFile << " Avg: ";
            logFile << daysTemp_Average;

            logFile << endl;
            } else {
                cout << endl << " ~!~ Unable to open file to write~!~" << endl;
            }
        }

    } while (dayCount != daysCalculatingFor);

    //Resetting variables
    dayCount = 0; 
    temp_CurrentHigh = 0;
    temp_CurrentLow = 0;
    temp_CurrentAvg = 0;
    logFile.close();
    logFile.open("tempLog.txt");

    //Reading the txt file
    
    if (logFile.is_open()) {
        //cout << "Opened" << endl;
        for (i = 0; i < num_Of_InputsToFile; ++i){
            logFile >> dummyStringVariable >> dayCount; // Grabing and ignoring label, then grabbing that day count
            logFile >> dummyStringVariable >> temp_CurrentHigh; // Grabing and ignoring label, then grabbing that high temp
            logFile >> dummyStringVariable >> temp_CurrentLow; // Grabing and ignoring label, then grabbing that low temp
            logFile >> dummyStringVariable >> temp_CurrentAvg; // Grabing and ignoring label, then grabbing that average
            
            if (i == 0){
                temp_Lowest = 100;
            }
            
            //totalAverageTemp += temp_CurrentAvg;

            if (temp_CurrentHigh > temp_Highest) { //Checks for highest temp. If so it puts it into highest variable
                temp_Highest = temp_CurrentHigh; // Replacing with new high
                temp_Highest_Day = dayCount; // Gives the day the temp is the highest
            }
            
            if (temp_CurrentLow < temp_Lowest) { //Checks for lowest temp. If so it puts it into lowest variable
                temp_Lowest = temp_CurrentLow; // Replacing with the new low
                temp_Lowest_Day = dayCount; // Gives the day the temp is lowest
            }
            
            if ((temp_Highest - temp_Lowest) > day_MostDramatic) { //Checks for most dramatic temp. If so it puts it into the most dramatic temp variable
                day_MostDramatic = (temp_Highest - temp_Lowest); // Replacing with the new drama queen
                day_MostDramatic_Day = dayCount; // Gives the day it is dramatic
            }

            cout << endl << endl << endl; //seperation

            // The chart
            if (loopCount == 1) {
                cout << endl << "_________________________________________________________________________________" << endl << endl; //Seperation

                cout << "                           ~!~ Temperature Chart ~!~ " << endl << endl;

                cout << "_________________________________________________________________________________" << endl << endl << endl; //Seperation

                cout << left << setw(14) << setfill(' ') << "Day Count";
                cout << left << setw(24) << setfill(' ') << "High Temperature";
                cout << left << setw(24) << setfill(' ') << "Low Temperature";
                cout << left << setw(20) << setfill(' ') << "Temperature Average";
                cout << endl; 

                cout << left << setw(5) << setfill(' ') << " ";
                cout << right << setw(18) << setfill(' ') << " ";
                cout << right << setw(25) << setfill(' ') << " ";
                cout << right << setw(26) << setfill(' ') << " ";
                cout << endl; 
            }

            cout << left << setw(5) << setfill(' ') << dayCount;
            cout << right << setw(18) << setfill(' ') << temp_CurrentHigh;
            cout << right << setw(25) << setfill(' ') << temp_CurrentLow;
            cout << right << setw(26) << setfill(' ') << temp_CurrentAvg;
            cout << endl;
            loopCount += 1;
        }
    } else {
        cout << endl << " ~!~ Unable to open file to read~!~" << endl;
    }

    //seperation to make it look better
    cout << endl << endl << "_________________________________________________________________________________" << endl << endl << endl << endl; //Seperation
    getline (cin,userInput); // To slow down output text so its readable

    // Giving Extra
    cout << " ~ ~ ~ Highest Temperature ~ ~ ~ " << endl;
    cout << "             Day- " << temp_Highest_Day << endl;
    cout << "             Temp- " << temp_Highest << endl;
    getline (cin,userInput); // To slow down output text so its readable
    cout << " . . . . . . " << endl << endl;

    cout << " ~ ~ ~ Lowest Temperature ~ ~ ~ " << endl;
    cout << "             Day- " << temp_Lowest_Day << endl;
    cout << "             Temp- " << temp_Lowest << endl;
    getline (cin,userInput); // To slow down output text so its readable
    cout << " . . . . . . " << endl << endl;

    cout << " ~ ~ ~ Volatile Temperature ~ ~ ~ " << endl;
    cout << "             Day- " << day_MostDramatic_Day << endl;
    cout << "            Change- " << day_MostDramatic << endl;


    //seperation to make it look better
    cout << endl << endl << "_________________________________________________________________________________" << endl << endl << endl << endl; //Seperation


    logFile.close();
    return 0;
}
