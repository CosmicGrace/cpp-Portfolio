/*
⚠️ Copyright Notice
This project is not open source. All rights reserved.
No unauthorized use, modification, distribution, or commercial use permitted.
Copyrighted to CosmicGrace (https://github.com/CosmicGrace)
*/


#include <iostream> // Standard Inputs
#include <cstdlib> // yoinking the random
#include <ctime> // Time Library
#include <string> // the wordddsss
#include <cctype> //Checks for stuff and converts user's annoying uppercases
using namespace std; // Helpful, less clutter, yay


int main() {
    // Variables
    int attemptCounter = 0; // To count attempts in loops or if statements (maybe)
    string randomUserInput = "Empty"; //used for confirming the user knows the end command
    int theRandom_Num = 0;
    

    //Starting User inputs to set up the game
        string userInput_TargetType = "Empty"; //THIS WILL BE THE VALUE THE USER WANTS TO PRACTICE, its the inputed type for the given types
        
        string userInput_QuestionType = "Empty"; //Users input to what type they want to
        

        string userInput_QuestionQuantity = "Empty"; //User tells us how much they want to study and we will generate the desired number

        int given_Quandrant = 0; //If user's input for the above value is for Quadrents its put here

        string userInput_QuantityString = "Empty";
        int userInput_QuantityNumber = 0;


    // Game variables
        int amount_of_Questions; //used even if user picked infinite, we will just put a very very big number they won't know the difference
        int amount_of_Possible_Values; // will be used for the randomizers
        int amount_of_Possible_Answers; //might be used...

        string type_Practice; //THE TYPE THE USER CHOSE
        string userResponse;
        string userResponse_Redo;
        string user_FailedQuestion; //when max redos are found or user says no to a redo
        string correctAnswer; //stores the resulting correct value for user response

        string endingCommand = "end"; // This can be used by the user to stop question generation at any time. Also if the question limit has been reached

    // This below will determine what we give the user to help them practice their chosen value
        string type_Giving; // Will only be opposing types (not the user chosen type)
        // ^ Options- opposingType1 , opposingType2, or both
        //Used in game as well
        string multiType_Giving1; // Calls the first value type that isnt the target type
        string multiType_Giving2; // Calls the second vlaue type that isnt the target type

        string user_ChoiceQuadrantQuestionMark = "Inactive";
        string user_ChoiceSetQuestionMark = "Inactive";

        //these generated variables are for the user's type to figure out what their solving for
        int user_GeneratedNumber;

        /* may be cancelled
        //These below are generated stuff FOR THE ANSWERS (programmers side of giving the values to help the user)
        int question_GeneratedNumber1; //default
        int question_GeneratedNumber2;
        */

        // these are the correct values for if type_practice == "both"
        string question_GeneratedValue1; // Default variable we shall use, but also for the first generated value if user choose "both" in type_Giving
        string question_GeneratedValue2; // For the second generated value if user choose "both" in type_Giving


    //End game stat collection
    int end_AmountUserWrong = 0; //storage of mistakes, relies on total amount of target value type
    int end_TotalQuestionsCompleted = 0; // how many questions did the user answer? Can be used for precent calc
    int end_AmountUserCorrect = 0;


    // Variables for the radians
    string radian_Value;
    string radian_ValueGenerated;
    string radian_QuestionAnswer;// value looked for depending on users answer
    int const RADIANS_TotalAmount = 17; // Total number of radian values on the unit circle
    int const RADIANS_PerQuadrent_Amount = 5; // Includes the edge values


    // Variables for the coords
    string coord_Value;
    string coord_ValueGenerated;
    string coords_QuestionAnswer;// value looked for depending on users answer
    int const COORDS_TotalAmount = 16; // Total number of coord values on the unit circle
    int const COORDS_PerQuadrent_Amount = 5; // Includes edge values


    // Variables for the degrees
    string degree_Value;
    string degree_ValueGenerated;
    string degrees_QuestionAnswer;// value looked for depending on users answer
    int const DEGREES_TotalAmount = 17; // Total number of degree values on the unit circle
    int const DEGREES_PerQuadrent_Amount = 5; // Includes edge values

    srand(time(0));

    // Defining the unit circle stuff, help
        //Radians
            string radian1 = "0"; // 0 degrees
            string radian2 = "pi/6";
            string radian3 = "pi/4";
            string radian4 = "pi/3";
            string radian5 = "pi/2"; // 90 degrees
            string radian6 = "2pi/3";
            string radian7 = "3pi/4";
            string radian8 = "5pi/6";
            string radian9 = "pi"; // 180 degrees
            string radian10 = "7pi/6";
            string radian11 = "5pi/4";
            string radian12 = "4pi/3";
            string radian13 = "3pi/2"; //270 degrees
            string radian14 = "5pi/3";
            string radian15 = "7pi/4";
            string radian16 = "11pi/6";
            string radian17 = "2pi"; //360 degrees
        //Degrees
            string degrees1 = "0"; // Im so tired ;-;
            string degrees2 = "30";
            string degrees3 = "45";
            string degrees4 = "60";
            string degrees5 = "90";
            string degrees6 = "120";
            string degrees7 = "135";
            string degrees8 = "150";
            string degrees9 = "180";
            string degrees10 = "210";
            string degrees11 = "225";
            string degrees12 = "240";
            string degrees13 = "270";
            string degrees14 = "300";
            string degrees15 = "315";
            string degrees16 = "330";
            string degrees17 = "360";
        //Coords
            string coords1 = "(1,0)"; // 0 degree
            string coords2 = "(V3/2,1/2)";
            string coords3 = "(V2/2,V2/2)";
            string coords4 = "(1/2,V3/2)";
            string coords5 = "(0,1)"; //90 degree
            string coords6 = "(-1/2,V3/2)";
            string coords7 = "(-V2/2,V2/2)";
            string coords8 = "(-V3/2,1/2)";
            string coords9 = "(-1,0)"; //180 degree
            string coords10 = "(-V3/2,-1/2)";
            string coords11 = "(-V2/2,-V2/2)";
            string coords12 = "(-1/2,-V3/2)";
            string coords13 = "(0,-1)"; //270 degree
            string coords14 = "(1/2,-V3/2)";
            string coords15 = "(V2/2,-V2/2)";
            string coords16 = "(V3/2,-1/2)";
    





    //The ASCII Art...
    cout << endl << endl; // to seperate


    cout << "                                                                               " << endl;
    cout << "            _   _       _ _      ____ _          _                             " << endl; 
    cout << "           | | | |_ __ (_) |_   / ___(_)_ __ ___| | ___                        " << endl;
    cout << "           | | | | '_ \\| | __| | |   | | '__/ __| |/ _ \\                     " << endl;
    cout << "           | |_| | | | | | |_  | |___| | | | (__| |  __/                       " << endl;
    cout << "            \\___/|_|_|_|_|\\__|  \\____|_|_|_ \\___|_|\\___|                  " << endl;
    cout << "                ____                 _   _                                     " << endl;
    cout << "               |  _ \\ _ __ __ _  ___| |_(_) ___ ___                           " << endl;
    cout << "               | |_) | '__/ _` |/ __| __| |/ __/ _ \\                          " << endl;
    cout << "               |  __/| | | (_| | (__| |_| | (_|  __/                           " << endl;
    cout << "               |_|   |_|  \\__,_|\\___|\\__|_|\\___\\___|                      " << endl;
    cout << "                                                                               " << endl; 
    cout << "                                                                " << endl;
    cout << "                                                                " << endl;
    cout << "                          ++++++++++++++++                      " << endl;
    cout << "                        ++++++    |   ++++++                    " << endl;
    cout << "                      ++++        |       ++++                  " << endl;
    cout << "                    ++++          |         ++++                " << endl;
    cout << "                   =++            |           ++=               " << endl;
    cout << "                   ++             |            ++               " << endl;
    cout << "                  ++=             |            =++              " << endl;
    cout << "                  ++              |             ++              " << endl;
    cout << "                  ++--------------*-------------++              " << endl;
    cout << "                  ++              |             ++              " << endl;
    cout << "                  ++              |             ++              " << endl;
    cout << "                   ++             |            ++               " << endl;
    cout << "                   +++            |           +++               " << endl;
    cout << "                    ++++          |         =+++                " << endl;
    cout << "                      ++++        |       ++++                  " << endl;
    cout << "                        ++++++    |   ++++++                    " << endl;
    cout << "                          =++++++++++++++=                      " << endl;
    cout << "                                                                " << endl;  
    cout << "                                                                               " << endl << endl;


    // Intro
    cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl << endl; //marking start of program
    cout << endl << "Hello user! This program shall help you remember" << endl;
    cout << "the unit circle by forced practice! Yay, fun math." << endl;

    // Context
    cout << endl << "You, the user, will first need to choose what type you'd like to practice";
    cout << endl << "This means it will be either the radians, coordinates, or degrees.";
    cout << endl << "From the selection above which ONE do you want to study?" << endl;

    //finding what type the user needs to practice with, this will be the type the user answers with
   do { 
        if (attemptCounter != 0) {
            cout << endl << endl << "Here is the selection again! Please only pick one and copy the word as seen. ";
            cout << endl << " ~ radians   ,   coordinates   ,   degrees ~ " << endl;
        }
        cout << endl << " - "; // Visual indicator for the user to type
        getline(cin, userInput_TargetType);
        userInput_TargetType.at(0) = tolower(userInput_TargetType.at(0));

        if (userInput_TargetType == "radian" || userInput_TargetType == "rad" || userInput_TargetType == "1" || userInput_TargetType == "radians") { //user annoying so covering possible valid mistakes
            //cout << "------- TEST - wrong radian word converted --------"; //To help me figure out stuff, make comment or delete after
            userInput_TargetType = "radians";
            amount_of_Possible_Values = RADIANS_TotalAmount;

        } else if  (userInput_TargetType == "coordinate" || userInput_TargetType == "coord" || userInput_TargetType == "coords" || userInput_TargetType == "coordinates" ) { //user annoying so covering possible valid mistakes
            //cout << "------- TEST - wrong coord word converted --------"; //To help me figure out stuff, make comment or delete after
            userInput_TargetType = "coordinates";
            amount_of_Possible_Values = COORDS_TotalAmount;

        } else if (userInput_TargetType == "degree" || userInput_TargetType == "deg" || userInput_TargetType == "degrees") { //user annoying so covering possible valid mistakes
            //cout << "------- TEST - wrong degree word converted --------"; //To help me figure out stuff, make comment or delete after
            userInput_TargetType = "degrees";
            amount_of_Possible_Values = DEGREES_TotalAmount;

        } else { 
            cout << endl << " !!! - Invalid input! Copy only ONE word from the 3 types " << endl << endl;
        }
        //cout << endl << endl << "Of " << attemptCounter << " attempt the choosenUserType is stored as " << userInput_TargetType;
        attemptCounter += 1; //To count attempts!
    }  while (userInput_TargetType != "radians" && userInput_TargetType != "degrees"  && userInput_TargetType != "coordinates");

    type_Practice = userInput_TargetType; //Storing the user input to the main variable

    

    attemptCounter = 0; //reset
    
    //cout << endl << endl << " - "; //for me to test without the loop
    //cin >> choosenUserType; //for me to test without the loop  


    // Assigning opposing Type and users chosen type
    if (userInput_TargetType == "radians") {
        multiType_Giving1 = "degrees";
        multiType_Giving2 = "coordinates";
    } else if (userInput_TargetType == "degrees") {
        multiType_Giving1 = "radians";
        multiType_Giving2 = "coordinates";
    } else if (userInput_TargetType == "coordinates") {
        multiType_Giving1 = "radians";
        multiType_Giving2 = "degrees";
    } else { //This should only go if the programmer did something wrong, so it should never appear to the user!!!!!!!!
        cout << endl << (" !!! What the, why, YOUR VARIABLE IS WRONG !!! ") << endl;
    }

    //cout << endl << "from " << userInput_TargetType << ", opposing types are " << multiType_Giving1 << " & " << multiType_Giving2 << endl; // To help me visualize, remove or comment after

    // End of the first user input choice
    //seperation :)
    cout << endl << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl << endl;

        // Below question will figure out what the user wants the program to output to help practice, this is the GIVEN
    cout << "To practice " << type_Practice << " do you want both " << endl;
    cout << multiType_Giving1 << " (1) and " << multiType_Giving2 << " (2), ";
    cout << "or only one of them?" << endl;
    cout << "Note- please only either say that type, 1 or 2, or the word both" << endl;
    while (type_Giving != multiType_Giving1 && type_Giving != multiType_Giving2 && type_Giving != "both") { //|| (multiType_Giving1 == "Empty" && multiType_Giving2 == "Empty")
        cout << " - ";
        getline(cin,userInput_QuestionType);
        userInput_QuestionType.at(0) = tolower(userInput_QuestionType.at(0));

        if (userInput_QuestionType == "1" || userInput_QuestionType == multiType_Giving1) {
            type_Giving = multiType_Giving1;

            multiType_Giving1 = multiType_Giving1;
            multiType_Giving2 = multiType_Giving1;
            cout << endl << endl << " ~~ You picked " << type_Giving << "! ~~" << endl; //Just informing the user the question is over

        } else if (userInput_QuestionType == "2" || userInput_QuestionType == multiType_Giving2) {
            type_Giving = multiType_Giving2;

            multiType_Giving1 = multiType_Giving2;
            multiType_Giving2 = multiType_Giving2;
            cout << endl << endl << " ~~ You picked " << type_Giving << "! ~~" << endl; //Just informing the user the question is over

        } else if (userInput_QuestionType == "both") {
            multiType_Giving1 = multiType_Giving1;
            multiType_Giving2 = multiType_Giving2;
            type_Giving = "both";
            cout << endl << endl << " ~~ You picked " << type_Giving << "! ~~" << endl; //Just informing the user the question is over

        } else {
            cout << endl << "!!! - Invalid input! Please try again and follow directions!"  << endl << endl;
        }
    }

    
    // End of user choosing 2 to determine what to output for the user to practice

    //seperation :)
    cout << endl << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl << endl;

    //Here we are asking the user HOW they'd like to study. Basically the amount.
    cout << "How much would you like to study? " << endl;
    cout << "Is there a set number, all of it, or constant?" << endl << endl;
    cout << "Answer with... \"set\" for a set number, \"all\" to go through" << endl;
    cout << "all values, or \"infinite\" for constant questions." << endl << endl;

    while (userInput_QuestionQuantity != "set" && userInput_QuestionQuantity != "quadrant" && userInput_QuestionQuantity != "all" && userInput_QuestionQuantity != "infinite") {
        cout << " - ";
        getline(cin,userInput_QuestionQuantity);
        userInput_QuestionQuantity.at(0) = tolower(userInput_QuestionQuantity.at(0));
        
        if (userInput_QuestionQuantity == "set") {
            cout << endl << " ~~ You picked " << userInput_QuestionQuantity << "! ~~" << endl; //Just informing the user the question is over
            cout << endl << endl << ". . . . . . . . . . . . . . . " << endl;
            user_ChoiceSetQuestionMark = "active";

        } else if (userInput_QuestionQuantity == "quadrantWIP") { // Quadrant is being cancelled right now
            cout << endl << " ~~ You picked " << userInput_QuestionQuantity << "! ~~" << endl; //Just informing the user the question is over
            cout << endl << endl << ". . . . . . . . . . . . . . . " << endl;
            user_ChoiceQuadrantQuestionMark = "active";

        } else if (userInput_QuestionQuantity == "all") {
            cout << endl << " ~~ You picked " << userInput_QuestionQuantity << "! ~~" << endl; //Just informing the user the question is over
            cout << endl << endl << ". . . . . . . . . . . . . . . " << endl;

        } else if (userInput_QuestionQuantity == "infinite") {
            cout << endl << " ~~ You picked " << userInput_QuestionQuantity << "! ~~" << endl; //Just informing the user the question is over
            cout << endl << endl << ". . . . . . . . . . . . . . . " << endl;

        } else {
            cout << endl << "!!! - Invalid input! Please try again and follow directions!" << endl << endl;
        }
    }


    cout << endl << endl; //Speration 

    //This registers the user with their chosen quantity
    while (userInput_QuestionQuantity != "registered" && attemptCounter < 10) {

        if (userInput_QuestionQuantity == "set") { // Questioning User based off their input for the question quantity
            
            cout << "Now, what how much are you wanting to study?" << endl;
            cout << "Note- (numbers only)" << endl;

            while (userInput_QuantityNumber < 1){
                cout << " - ";
                cin >> userInput_QuantityNumber;
                cin.ignore();
                
                if (userInput_QuantityNumber > 0) {
                    userInput_QuestionQuantity = "registered";
                    amount_of_Questions = userInput_QuantityNumber;
                    cout << endl << " ~~ You picked " << userInput_QuantityNumber << " questions! ~~" << endl; //Just informing the user the question is over
                
                } else {
                    cout << endl << "!!! - Invalid input! Please try again and follow directions!" << endl;
                }
                
            }


        
        } else if (userInput_QuestionQuantity == "quadrant") { // Questioning User based off their input for the question quantity

            cout << "Now, what exact quadrent would you like to focus on?" << endl;
            cout << " Note- ONLY type the number" << endl;
            
            while (given_Quandrant != 1 && given_Quandrant != 2 && given_Quandrant != 3 && given_Quandrant != 4){
                cout << " - ";
                //getline(cin, given_Quandrant);
                cin >> given_Quandrant;
                cin.ignore();

                if (given_Quandrant == 1 || given_Quandrant == 2|| given_Quandrant == 3 || given_Quandrant == 4) {
                    given_Quandrant = given_Quandrant;
                    userInput_QuestionQuantity = "registered";
                    cout << endl << " ~~ You picked Quadrant " << given_Quandrant << "! ~~" << endl; //Just informing the user the question is over

                    if (type_Practice == "radians") {
                        amount_of_Questions = RADIANS_PerQuadrent_Amount;

                    } else if (type_Practice == "degrees") {
                        amount_of_Questions = DEGREES_PerQuadrent_Amount;

                    } else if (type_Practice == "coordinates") {
                        amount_of_Questions = COORDS_PerQuadrent_Amount;

                    }

                    cout << "You'll get " << amount_of_Questions << " questions!" << endl;
                    amount_of_Possible_Values = amount_of_Questions;
                    

                
                } else {
                    cout << endl << "!!! - Invalid input! Please try again and follow directions!" << endl;
                }
            }
            


        } else if (userInput_QuestionQuantity == "all") { // Questioning User based off their input for the question quantity
            
            if (type_Practice == "radians") {
                amount_of_Questions = RADIANS_TotalAmount;

            } else if (type_Practice == "degrees") {
                amount_of_Questions = DEGREES_TotalAmount;

            } else if (type_Practice == "coordinates") {
                amount_of_Questions = COORDS_TotalAmount;

            }

            cout << "Since you picked \"all\", the number of  " << endl;
            cout << "questions you'll get are " << amount_of_Questions << "!" << endl;
            userInput_QuestionQuantity = "registered";



        } else if (userInput_QuestionQuantity == "infinite") { // Questioning User based off their input for the question quantity
            
            cout << "Since you picked \"infinite\"..." << endl;
            cout << "... good luck." << endl;
            userInput_QuestionQuantity = "registered";
            amount_of_Questions = 2147483648;



        } else {
            cout << endl << "how are you here??????????????" << endl; //if i did something wrong :(
        }


        attemptCounter += 1;
    }


    //To slow down the couts
    while (randomUserInput != "yes") {
        cout << endl << endl << "Ready to continue?" << endl;
        cout << " - ";
        getline (cin, randomUserInput);
        randomUserInput.at(0) = tolower(randomUserInput.at(0));

        if (randomUserInput == "yes") {
            cout << endl << "Good, lets continue." << endl;
        } else {
            cout << "Your gonna continue anyways. " << endl;
            randomUserInput = "yes";
        }
    }
    randomUserInput = "Empty"; //resetting it back

    cout << endl << endl << ". . . . . . . . . . . . . . . " << endl << endl;



    // Informing the user before the game starts

    cout << endl << "Okay, before this starts I do want to note somethings to you." << endl << endl;

    cout << "The dash, aka \" - \" < that line, will help instruct you when to answer. " << endl << endl;

    cout << "For the values themselves that little pi shape thing, yeah we are going" << endl;
    cout << "to just put \"pi\". The square root of (...) will also be subbed." << endl;
    cout << "This will be in the form of \" V \" (uppercase V)." << endl;
    cout << "You got that?" << endl;

    while (randomUserInput != "yes") {
        cout << " - ";
        getline (cin, randomUserInput);
        randomUserInput.at(0) = tolower(randomUserInput.at(0));

        if (randomUserInput == "yes" || randomUserInput == "yeah") {
            cout << endl << "Good, lets continue." << endl;

        } else {
            cout << "Just say yes, its not that hard." << endl;
        }
    }
    randomUserInput = "Empty"; //resetting it back


    cout << endl << endl << ". . . . . . . . . . . . . . . " << endl << endl;


    cout << endl << endl << "At ANY point of the game, at the answering dash (-), you can stop" << endl;
    cout << "the game early. This command will just be \"end\" " << endl << endl;
    cout << "Do you have the stop command memorized or written down?" << endl;

    while (randomUserInput != "yes") {
        cout << " - ";
        getline (cin, randomUserInput);
        randomUserInput.at(0) = tolower(randomUserInput.at(0));

        if (randomUserInput == "yes" || randomUserInput == "yeah") {
            cout << endl << "Good, lets continue." << endl;
        } else {
            cout << "Just say yes, its not that hard." << endl;
        }
    }
    randomUserInput = "Empty"; //resetting it back

    cout << "You will want to end the game like that, trust me." << endl;
    cout << "At the end of each game will be your stats." << endl;
    cout << "So you can see how much your cooked or not." << endl << endl;

    cout << endl << endl << "Anyways good luck." << endl << endl << endl;


    //Making sure user understands above since cout's output quickly, so I rather it not be lost
    cout << "Ready to start?" << endl;

    while (randomUserInput != "yes") {
        cout << " - ";
        getline (cin, randomUserInput);
        randomUserInput.at(0) = tolower(randomUserInput.at(0));

        if (randomUserInput == "yes" || randomUserInput == "yeah") {
            cout << endl << "Good, lets continue." << endl;
            randomUserInput = "yes";
        } else {
            cout << "Your gonna continue anyways. " << endl;
            randomUserInput = "yes";
        }
    }
    randomUserInput = "Empty"; //resetting it back
 


    // The setup is finally finished. Now, onto the game.

    //seperation :)
    cout << endl << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

    while (userResponse != endingCommand && end_TotalQuestionsCompleted != amount_of_Questions){
        // Resetting Variables
        user_FailedQuestion = "Inactive";
        userResponse = "Empty";
        correctAnswer = "Empty";
        //theRandom_Num = (rand() % (amount_of_Possible_Values-1+1) + 1);
        
        //Randomizing the stufffffff
        if (type_Practice == "radians" || type_Practice == "degrees" || type_Practice == "both")
            user_GeneratedNumber = (rand() % (17-1+1) + 1);

        else if (type_Practice == "coords")
            user_GeneratedNumber = (rand() % (16-1+1) + 1);

        else
            user_GeneratedNumber = (rand() % (17-1+1) + 1);


        // Finding what the heck was generated
        if (type_Practice == "radians" || type_Practice == "both") { //If user wants radians it here
        
            if (user_GeneratedNumber == 1) {
                correctAnswer = radian1;

                // Other Correct Value finder :D
                if (type_Giving == "degrees" || multiType_Giving1 == "degrees" || multiType_Giving2 == "degrees") { //if type giv is degree it go here

                    if (type_Giving == "degrees")
                        question_GeneratedValue1 = degrees1;
                    else if (multiType_Giving1 == "degrees")
                        question_GeneratedValue1 = degrees1;
                    else if (multiType_Giving2 == "degrees")
                        question_GeneratedValue2 = degrees1;


                } else if (type_Giving == "coordinates" || multiType_Giving1 == "coordinates" || multiType_Giving2 == "coordinates"){
                    if (type_Giving == "coordinates")
                        question_GeneratedValue1 = coords1;
                    else if (multiType_Giving1 == "coordinates")
                        question_GeneratedValue1 = coords1;
                    else if (multiType_Giving2 == "coordinates")
                        question_GeneratedValue2 = coords1;
                }

            } else if (user_GeneratedNumber == 2) {
                correctAnswer = radian2;

                // Other Correct Value finder :D
                if (type_Giving == "degrees" || multiType_Giving1 == "degrees" || multiType_Giving2 == "degrees") { //if type giv is degree it go here
                    if (type_Giving == "degrees")
                        question_GeneratedValue1 = degrees2;
                    else if (multiType_Giving1 == "degrees")
                        question_GeneratedValue1 = degrees2;
                    else if (multiType_Giving2 == "degrees")
                        question_GeneratedValue2 = degrees2;


                } else if (type_Giving == "coordinates" || multiType_Giving1 == "coordinates" || multiType_Giving2 == "coordinates"){
                    if (type_Giving == "coordinates")
                        question_GeneratedValue1 = coords2;
                    else if (multiType_Giving1 == "coordinates")
                        question_GeneratedValue1 = coords2;
                    else if (multiType_Giving2 == "coordinates")
                        question_GeneratedValue2 = coords2;
                }

            } else if (user_GeneratedNumber == 3) {
                correctAnswer = radian3;

                // Other Correct Value finder :D
                if (type_Giving == "degrees" || multiType_Giving1 == "degrees" || multiType_Giving2 == "degrees") { //if type giv is degree it go here
                    if (type_Giving == "degrees")
                        question_GeneratedValue1 = degrees3;
                    else if (multiType_Giving1 == "degrees")
                        question_GeneratedValue1 = degrees3;
                    else if (multiType_Giving2 == "degrees")
                        question_GeneratedValue2 = degrees3;


                } else if (type_Giving == "coordinates" || multiType_Giving1 == "coordinates" || multiType_Giving2 == "coordinates"){
                    if (type_Giving == "coordinates")
                        question_GeneratedValue1 = coords3;
                    else if (multiType_Giving1 == "coordinates")
                        question_GeneratedValue1 = coords3;
                    else if (multiType_Giving2 == "coordinates")
                        question_GeneratedValue2 = coords3;
                }

            } else if (user_GeneratedNumber == 4) {
                correctAnswer = radian4;

                // Other Correct Value finder :D
                if (type_Giving == "degrees" || multiType_Giving1 == "degrees" || multiType_Giving2 == "degrees") { //if type giv is degree it go here
                    if (type_Giving == "degrees")
                        question_GeneratedValue1 = degrees4;
                    else if (multiType_Giving1 == "degrees")
                        question_GeneratedValue1 = degrees4;
                    else if (multiType_Giving2 == "degrees")
                        question_GeneratedValue2 = degrees4;


                } else if (type_Giving == "coordinates" || multiType_Giving1 == "coordinates" || multiType_Giving2 == "coordinates"){
                    if (type_Giving == "coordinates")
                        question_GeneratedValue1 = coords4;
                    else if (multiType_Giving1 == "coordinates")
                        question_GeneratedValue1 = coords4;
                    else if (multiType_Giving2 == "coordinates")
                        question_GeneratedValue2 = coords4;
                }

            } else if (user_GeneratedNumber == 5) {
                correctAnswer = radian5;

                // Other Correct Value finder :D
                if (type_Giving == "degrees" || multiType_Giving1 == "degrees" || multiType_Giving2 == "degrees") { //if type giv is degree it go here
                    if (type_Giving == "degrees")
                        question_GeneratedValue1 = degrees5;
                    else if (multiType_Giving1 == "degrees")
                        question_GeneratedValue1 = degrees5;
                    else if (multiType_Giving2 == "degrees")
                        question_GeneratedValue2 = degrees5;


                } else if (type_Giving == "coordinates" || multiType_Giving1 == "coordinates" || multiType_Giving2 == "coordinates"){
                    if (type_Giving == "coordinates")
                        question_GeneratedValue1 = coords5;
                    else if (multiType_Giving1 == "coordinates")
                        question_GeneratedValue1 = coords5;
                    else if (multiType_Giving2 == "coordinates")
                        question_GeneratedValue2 = coords5;
                }

            } else if (user_GeneratedNumber == 6) {
                correctAnswer = radian6;

                // Other Correct Value finder :D
                if (type_Giving == "degrees" || multiType_Giving1 == "degrees" || multiType_Giving2 == "degrees") { //if type giv is degree it go here
                    if (type_Giving == "degrees")
                        question_GeneratedValue1 = degrees6;
                    else if (multiType_Giving1 == "degrees")
                        question_GeneratedValue1 = degrees6;
                    else if (multiType_Giving2 == "degrees")
                        question_GeneratedValue2 = degrees6;


                } else if (type_Giving == "coordinates" || multiType_Giving1 == "coordinates" || multiType_Giving2 == "coordinates"){
                    if (type_Giving == "coordinates")
                        question_GeneratedValue1 = coords6;
                    else if (multiType_Giving1 == "coordinates")
                        question_GeneratedValue1 = coords6;
                    else if (multiType_Giving2 == "coordinates")
                        question_GeneratedValue2 = coords6;
                }

            } else if (user_GeneratedNumber == 7) {
                correctAnswer = radian7;

                // Other Correct Value finder :D
                if (type_Giving == "degrees" || multiType_Giving1 == "degrees" || multiType_Giving2 == "degrees") { //if type giv is degree it go here
                    if (type_Giving == "degrees")
                        question_GeneratedValue1 = degrees7;
                    else if (multiType_Giving1 == "degrees")
                        question_GeneratedValue1 = degrees7;
                    else if (multiType_Giving2 == "degrees")
                        question_GeneratedValue2 = degrees7;


                } else if (type_Giving == "coordinates" || multiType_Giving1 == "coordinates" || multiType_Giving2 == "coordinates"){
                    if (type_Giving == "coordinates")
                        question_GeneratedValue1 = coords7;
                    else if (multiType_Giving1 == "coordinates")
                        question_GeneratedValue1 = coords7;
                    else if (multiType_Giving2 == "coordinates")
                        question_GeneratedValue2 = coords7;
                }

            } else if (user_GeneratedNumber == 8) {
                correctAnswer = radian8;

                // Other Correct Value finder :D
                if (type_Giving == "degrees" || multiType_Giving1 == "degrees" || multiType_Giving2 == "degrees") { //if type giv is degree it go here
                    if (type_Giving == "degrees")
                        question_GeneratedValue1 = degrees8;
                    else if (multiType_Giving1 == "degrees")
                        question_GeneratedValue1 = degrees8;
                    else if (multiType_Giving2 == "degrees")
                        question_GeneratedValue2 = degrees8;


                } else if (type_Giving == "coordinates" || multiType_Giving1 == "coordinates" || multiType_Giving2 == "coordinates"){
                    if (type_Giving == "coordinates")
                        question_GeneratedValue1 = coords8;
                    else if (multiType_Giving1 == "coordinates")
                        question_GeneratedValue1 = coords8;
                    else if (multiType_Giving2 == "coordinates")
                        question_GeneratedValue2 = coords8;
                }

            } else if (user_GeneratedNumber == 9) {
                correctAnswer = radian9;

                // Other Correct Value finder :D
                if (type_Giving == "degrees" || multiType_Giving1 == "degrees" || multiType_Giving2 == "degrees") { //if type giv is degree it go here
                    if (type_Giving == "degrees")
                        question_GeneratedValue1 = degrees9;
                    else if (multiType_Giving1 == "degrees")
                        question_GeneratedValue1 = degrees9;
                    else if (multiType_Giving2 == "degrees")
                        question_GeneratedValue2 = degrees9;


                } else if (type_Giving == "coordinates" || multiType_Giving1 == "coordinates" || multiType_Giving2 == "coordinates"){
                    if (type_Giving == "coordinates")
                        question_GeneratedValue1 = coords9;
                    else if (multiType_Giving1 == "coordinates")
                        question_GeneratedValue1 = coords9;
                    else if (multiType_Giving2 == "coordinates")
                        question_GeneratedValue2 = coords9;
                }

            } else if (user_GeneratedNumber == 10) {
                correctAnswer = radian10;

                // Other Correct Value finder :D
                if (type_Giving == "degrees" || multiType_Giving1 == "degrees" || multiType_Giving2 == "degrees") { //if type giv is degree it go here
                    if (type_Giving == "degrees")
                        question_GeneratedValue1 = degrees10;
                    else if (multiType_Giving1 == "degrees")
                        question_GeneratedValue1 = degrees10;
                    else if (multiType_Giving2 == "degrees")
                        question_GeneratedValue2 = degrees10;


                } else if (type_Giving == "coordinates" || multiType_Giving1 == "coordinates" || multiType_Giving2 == "coordinates"){
                    if (type_Giving == "coordinates")
                        question_GeneratedValue1 = coords10;
                    else if (multiType_Giving1 == "coordinates")
                        question_GeneratedValue1 = coords10;
                    else if (multiType_Giving2 == "coordinates")
                        question_GeneratedValue2 = coords10;
                }

            } else if (user_GeneratedNumber == 11) {
                correctAnswer = radian11;

                // Other Correct Value finder :D
                if (type_Giving == "degrees" || multiType_Giving1 == "degrees" || multiType_Giving2 == "degrees") { //if type giv is degree it go here
                    if (type_Giving == "degrees")
                        question_GeneratedValue1 = degrees11;
                    else if (multiType_Giving1 == "degrees")
                        question_GeneratedValue1 = degrees11;
                    else if (multiType_Giving2 == "degrees")
                        question_GeneratedValue2 = degrees11;


                } else if (type_Giving == "coordinates" || multiType_Giving1 == "coordinates" || multiType_Giving2 == "coordinates"){
                    if (type_Giving == "coordinates")
                        question_GeneratedValue1 = coords11;
                    else if (multiType_Giving1 == "coordinates")
                        question_GeneratedValue1 = coords11;
                    else if (multiType_Giving2 == "coordinates")
                        question_GeneratedValue2 = coords11;
                }

            } else if (user_GeneratedNumber == 12) {
                correctAnswer = radian12;

                // Other Correct Value finder :D
                if (type_Giving == "degrees" || multiType_Giving1 == "degrees" || multiType_Giving2 == "degrees") { //if type giv is degree it go here
                    if (type_Giving == "degrees")
                        question_GeneratedValue1 = degrees12;
                    else if (multiType_Giving1 == "degrees")
                        question_GeneratedValue1 = degrees12;
                    else if (multiType_Giving2 == "degrees")
                        question_GeneratedValue2 = degrees12;


                } else if (type_Giving == "coordinates" || multiType_Giving1 == "coordinates" || multiType_Giving2 == "coordinates"){
                    if (type_Giving == "coordinates")
                        question_GeneratedValue1 = coords12;
                    else if (multiType_Giving1 == "coordinates")
                        question_GeneratedValue1 = coords12;
                    else if (multiType_Giving2 == "coordinates")
                        question_GeneratedValue2 = coords12;
                }

            } else if (user_GeneratedNumber == 13) {
                correctAnswer = radian13;

                // Other Correct Value finder :D
                if (type_Giving == "degrees" || multiType_Giving1 == "degrees" || multiType_Giving2 == "degrees") { //if type giv is degree it go here
                    if (type_Giving == "degrees")
                        question_GeneratedValue1 = degrees13;
                    else if (multiType_Giving1 == "degrees")
                        question_GeneratedValue1 = degrees13;
                    else if (multiType_Giving2 == "degrees")
                        question_GeneratedValue2 = degrees13;


                } else if (type_Giving == "coordinates" || multiType_Giving1 == "coordinates" || multiType_Giving2 == "coordinates"){
                    if (type_Giving == "coordinates")
                        question_GeneratedValue1 = coords13;
                    else if (multiType_Giving1 == "coordinates")
                        question_GeneratedValue1 = coords13;
                    else if (multiType_Giving2 == "coordinates")
                        question_GeneratedValue2 = coords13;
                }

            } else if (user_GeneratedNumber == 14) {
                correctAnswer = radian14;

                // Other Correct Value finder :D
                if (type_Giving == "degrees" || multiType_Giving1 == "degrees" || multiType_Giving2 == "degrees") { //if type giv is degree it go here
                    if (type_Giving == "degrees")
                        question_GeneratedValue1 = degrees14;
                    else if (multiType_Giving1 == "degrees")
                        question_GeneratedValue1 = degrees14;
                    else if (multiType_Giving2 == "degrees")
                        question_GeneratedValue2 = degrees14;


                } else if (type_Giving == "coordinates" || multiType_Giving1 == "coordinates" || multiType_Giving2 == "coordinates"){
                    if (type_Giving == "coordinates")
                        question_GeneratedValue1 = coords14;
                    else if (multiType_Giving1 == "coordinates")
                        question_GeneratedValue1 = coords14;
                    else if (multiType_Giving2 == "coordinates")
                        question_GeneratedValue2 = coords14;
                }

            } else if (user_GeneratedNumber == 15) {
                correctAnswer = radian15;

                // Other Correct Value finder :D
                if (type_Giving == "degrees" || multiType_Giving1 == "degrees" || multiType_Giving2 == "degrees") { //if type giv is degree it go here
                    if (type_Giving == "degrees")
                        question_GeneratedValue1 = degrees15;
                    else if (multiType_Giving1 == "degrees")
                        question_GeneratedValue1 = degrees15;
                    else if (multiType_Giving2 == "degrees")
                        question_GeneratedValue2 = degrees15;


                } else if (type_Giving == "coordinates" || multiType_Giving1 == "coordinates" || multiType_Giving2 == "coordinates"){
                    if (type_Giving == "coordinates")
                        question_GeneratedValue1 = coords15;
                    else if (multiType_Giving1 == "coordinates")
                        question_GeneratedValue1 = coords15;
                    else if (multiType_Giving2 == "coordinates")
                        question_GeneratedValue2 = coords15;
                }

            } else if (user_GeneratedNumber == 16) {
                correctAnswer = radian16;

                // Other Correct Value finder :D
                if (type_Giving == "degrees" || multiType_Giving1 == "degrees" || multiType_Giving2 == "degrees") { //if type giv is degree it go here
                    if (type_Giving == "degrees")
                        question_GeneratedValue1 = degrees16;
                    else if (multiType_Giving1 == "degrees")
                        question_GeneratedValue1 = degrees16;
                    else if (multiType_Giving2 == "degrees")
                        question_GeneratedValue2 = degrees16;


                } else if (type_Giving == "coordinates" || multiType_Giving1 == "coordinates" || multiType_Giving2 == "coordinates"){
                    if (type_Giving == "coordinates")
                        question_GeneratedValue1 = coords16;
                    else if (multiType_Giving1 == "coordinates")
                        question_GeneratedValue1 = coords16;
                    else if (multiType_Giving2 == "coordinates")
                        question_GeneratedValue2 = coords16;
                }

            } else if (user_GeneratedNumber == 17) {
                correctAnswer = radian17;

                // Other Correct Value finder :D
                if (type_Giving == "degrees" || multiType_Giving1 == "degrees" || multiType_Giving2 == "degrees") { //if type giv is degree it go here
                    if (type_Giving == "degrees")
                        question_GeneratedValue1 = degrees17;
                    else if (multiType_Giving1 == "degrees")
                        question_GeneratedValue1 = degrees17;
                    else if (multiType_Giving2 == "degrees")
                        question_GeneratedValue2 = degrees17;


                } else if (type_Giving == "coordinates" || multiType_Giving1 == "coordinates" || multiType_Giving2 == "coordinates"){
                    if (type_Giving == "coordinates")
                        question_GeneratedValue1 = coords1;
                    else if (multiType_Giving1 == "coordinates")
                        question_GeneratedValue1 = coords1;
                    else if (multiType_Giving2 == "coordinates")
                        question_GeneratedValue2 = coords1;
                }

            } else {
                cout << endl << "error with user_GeneratedNumber at radians answr finder!!!!!!!!!!" << endl;
            }


        } else if ( type_Practice == "degrees" || type_Practice == "both") {
            if (user_GeneratedNumber == 1) {
                correctAnswer = degrees1;

                // Other Correct Value finder :D
                if (type_Giving == "radians" || multiType_Giving1 == "radians" || multiType_Giving2 == "radians") { //if type giv is degree it go here
                    if (type_Giving == "radians")
                        question_GeneratedValue1 = radian1;
                    else if (multiType_Giving1 == "radians")
                        question_GeneratedValue1 = radian1;
                    else if (multiType_Giving2 == "radians")
                        question_GeneratedValue2 = radian1;


                } else if (type_Giving == "coordinates" || multiType_Giving1 == "coordinates" || multiType_Giving2 == "coordinates"){
                    if (type_Giving == "coordinates")
                        question_GeneratedValue1 = coords1;
                    else if (multiType_Giving1 == "coordinates")
                        question_GeneratedValue1 = coords1;
                    else if (multiType_Giving2 == "coordinates")
                        question_GeneratedValue2 = coords1;
                }

            } else if (user_GeneratedNumber == 2) {
                correctAnswer = degrees2;

                // Other Correct Value finder :D
                if (type_Giving == "radians" || multiType_Giving1 == "radians" || multiType_Giving2 == "radians") { //if type giv is degree it go here
                    if (type_Giving == "radians")
                        question_GeneratedValue1 = radian2;
                    else if (multiType_Giving1 == "radians")
                        question_GeneratedValue1 = radian2;
                    else if (multiType_Giving2 == "radians")
                        question_GeneratedValue2 = radian2;


                } else if (type_Giving == "coordinates" || multiType_Giving1 == "coordinates" || multiType_Giving2 == "coordinates"){
                    if (type_Giving == "coordinates")
                        question_GeneratedValue1 = coords2;
                    else if (multiType_Giving1 == "coordinates")
                        question_GeneratedValue1 = coords2;
                    else if (multiType_Giving2 == "coordinates")
                        question_GeneratedValue2 = coords2;
                }

            } else if (user_GeneratedNumber == 3) {
                correctAnswer = degrees3;

                // Other Correct Value finder :D
                if (type_Giving == "radians" || multiType_Giving1 == "radians" || multiType_Giving2 == "radians") { //if type giv is degree it go here
                    if (type_Giving == "radians")
                        question_GeneratedValue1 = radian3;
                    else if (multiType_Giving1 == "radians")
                        question_GeneratedValue1 = radian3;
                    else if (multiType_Giving2 == "radians")
                        question_GeneratedValue2 = radian3;


                } else if (type_Giving == "coordinates" || multiType_Giving1 == "coordinates" || multiType_Giving2 == "coordinates"){
                    if (type_Giving == "coordinates")
                        question_GeneratedValue1 = coords3;
                    else if (multiType_Giving1 == "coordinates")
                        question_GeneratedValue1 = coords3;
                    else if (multiType_Giving2 == "coordinates")
                        question_GeneratedValue2 = coords3;
                }

            } else if (user_GeneratedNumber == 4) {
                correctAnswer = degrees4;

                // Other Correct Value finder :D
                if (type_Giving == "radians" || multiType_Giving1 == "radians" || multiType_Giving2 == "radians") { //if type giv is degree it go here
                    if (type_Giving == "radians")
                        question_GeneratedValue1 = radian4;
                    else if (multiType_Giving1 == "radians")
                        question_GeneratedValue1 = radian4;
                    else if (multiType_Giving2 == "radians")
                        question_GeneratedValue2 = radian4;


                } else if (type_Giving == "coordinates" || multiType_Giving1 == "coordinates" || multiType_Giving2 == "coordinates"){
                    if (type_Giving == "coordinates")
                        question_GeneratedValue1 = coords4;
                    else if (multiType_Giving1 == "coordinates")
                        question_GeneratedValue1 = coords4;
                    else if (multiType_Giving2 == "coordinates")
                        question_GeneratedValue2 = coords4;
                }

            } else if (user_GeneratedNumber == 5) {
                correctAnswer = degrees5;

                // Other Correct Value finder :D
                if (type_Giving == "radians" || multiType_Giving1 == "radians" || multiType_Giving2 == "radians") { //if type giv is degree it go here
                    if (type_Giving == "radians")
                        question_GeneratedValue1 = radian5;
                    else if (multiType_Giving1 == "radians")
                        question_GeneratedValue1 = radian5;
                    else if (multiType_Giving2 == "radians")
                        question_GeneratedValue2 = radian5;


                } else if (type_Giving == "coordinates" || multiType_Giving1 == "coordinates" || multiType_Giving2 == "coordinates"){
                    if (type_Giving == "coordinates")
                        question_GeneratedValue1 = coords5;
                    else if (multiType_Giving1 == "coordinates")
                        question_GeneratedValue1 = coords5;
                    else if (multiType_Giving2 == "coordinates")
                        question_GeneratedValue2 = coords5;
                }

            } else if (user_GeneratedNumber == 6) {
                correctAnswer = degrees6;

                // Other Correct Value finder :D
                if (type_Giving == "radians" || multiType_Giving1 == "radians" || multiType_Giving2 == "radians") { //if type giv is degree it go here
                    if (type_Giving == "radians")
                        question_GeneratedValue1 = radian6;
                    else if (multiType_Giving1 == "radians")
                        question_GeneratedValue1 = radian6;
                    else if (multiType_Giving2 == "radians")
                        question_GeneratedValue2 = radian6;


                } else if (type_Giving == "coordinates" || multiType_Giving1 == "coordinates" || multiType_Giving2 == "coordinates"){
                    if (type_Giving == "coordinates")
                        question_GeneratedValue1 = coords6;
                    else if (multiType_Giving1 == "coordinates")
                        question_GeneratedValue1 = coords6;
                    else if (multiType_Giving2 == "coordinates")
                        question_GeneratedValue2 = coords6;
                }

            } else if (user_GeneratedNumber == 7) {
                correctAnswer = degrees7;

                // Other Correct Value finder :D
                if (type_Giving == "radians" || multiType_Giving1 == "radians" || multiType_Giving2 == "radians") { //if type giv is degree it go here
                    if (type_Giving == "radians")
                        question_GeneratedValue1 = radian7;
                    else if (multiType_Giving1 == "radians")
                        question_GeneratedValue1 = radian7;
                    else if (multiType_Giving2 == "radians")
                        question_GeneratedValue2 = radian7;


                } else if (type_Giving == "coordinates" || multiType_Giving1 == "coordinates" || multiType_Giving2 == "coordinates"){
                    if (type_Giving == "coordinates")
                        question_GeneratedValue1 = coords7;
                    else if (multiType_Giving1 == "coordinates")
                        question_GeneratedValue1 = coords7;
                    else if (multiType_Giving2 == "coordinates")
                        question_GeneratedValue2 = coords7;
                }

            } else if (user_GeneratedNumber == 8) {
                correctAnswer = degrees8;

                // Other Correct Value finder :D
                if (type_Giving == "radians" || multiType_Giving1 == "radians" || multiType_Giving2 == "radians") { //if type giv is degree it go here
                    if (type_Giving == "radians")
                        question_GeneratedValue1 = radian8;
                    else if (multiType_Giving1 == "radians")
                        question_GeneratedValue1 = radian8;
                    else if (multiType_Giving2 == "radians")
                        question_GeneratedValue2 = radian8;


                } else if (type_Giving == "coordinates" || multiType_Giving1 == "coordinates" || multiType_Giving2 == "coordinates"){
                    if (type_Giving == "coordinates")
                        question_GeneratedValue1 = coords8;
                    else if (multiType_Giving1 == "coordinates")
                        question_GeneratedValue1 = coords8;
                    else if (multiType_Giving2 == "coordinates")
                        question_GeneratedValue2 = coords8;
                }

            } else if (user_GeneratedNumber == 9) {
                correctAnswer = degrees9;

                // Other Correct Value finder :D
                if (type_Giving == "radians" || multiType_Giving1 == "radians" || multiType_Giving2 == "radians") { //if type giv is degree it go here
                    if (type_Giving == "radians")
                        question_GeneratedValue1 = radian9;
                    else if (multiType_Giving1 == "radians")
                        question_GeneratedValue1 = radian9;
                    else if (multiType_Giving2 == "radians")
                        question_GeneratedValue2 = radian9;


                } else if (type_Giving == "coordinates" || multiType_Giving1 == "coordinates" || multiType_Giving2 == "coordinates"){
                    if (type_Giving == "coordinates")
                        question_GeneratedValue1 = coords9;
                    else if (multiType_Giving1 == "coordinates")
                        question_GeneratedValue1 = coords9;
                    else if (multiType_Giving2 == "coordinates")
                        question_GeneratedValue2 = coords9;
                }

            } else if (user_GeneratedNumber == 10) {
                correctAnswer = degrees10;

                // Other Correct Value finder :D
                if (type_Giving == "radians" || multiType_Giving1 == "radians" || multiType_Giving2 == "radians") { //if type giv is degree it go here
                    if (type_Giving == "radians")
                        question_GeneratedValue1 = radian10;
                    else if (multiType_Giving1 == "radians")
                        question_GeneratedValue1 = radian10;
                    else if (multiType_Giving2 == "radians")
                        question_GeneratedValue2 = radian10;


                } else if (type_Giving == "coordinates" || multiType_Giving1 == "coordinates" || multiType_Giving2 == "coordinates"){
                    if (type_Giving == "coordinates")
                        question_GeneratedValue1 = coords10;
                    else if (multiType_Giving1 == "coordinates")
                        question_GeneratedValue1 = coords10;
                    else if (multiType_Giving2 == "coordinates")
                        question_GeneratedValue2 = coords10;
                }

            } else if (user_GeneratedNumber == 11) {
                correctAnswer = degrees11;

                // Other Correct Value finder :D
                if (type_Giving == "radians" || multiType_Giving1 == "radians" || multiType_Giving2 == "radians") { //if type giv is degree it go here
                    if (type_Giving == "radians")
                        question_GeneratedValue1 = radian11;
                    else if (multiType_Giving1 == "radians")
                        question_GeneratedValue1 = radian11;
                    else if (multiType_Giving2 == "radians")
                        question_GeneratedValue2 = radian11;


                } else if (type_Giving == "coordinates" || multiType_Giving1 == "coordinates" || multiType_Giving2 == "coordinates"){
                    if (type_Giving == "coordinates")
                        question_GeneratedValue1 = coords11;
                    else if (multiType_Giving1 == "coordinates")
                        question_GeneratedValue1 = coords11;
                    else if (multiType_Giving2 == "coordinates")
                        question_GeneratedValue2 = coords11;
                }

            } else if (user_GeneratedNumber == 12) {
                correctAnswer = degrees12;

                // Other Correct Value finder :D
                if (type_Giving == "radians" || multiType_Giving1 == "radians" || multiType_Giving2 == "radians") { //if type giv is degree it go here
                    if (type_Giving == "radians")
                        question_GeneratedValue1 = radian12;
                    else if (multiType_Giving1 == "radians")
                        question_GeneratedValue1 = radian12;
                    else if (multiType_Giving2 == "radians")
                        question_GeneratedValue2 = radian12;


                } else if (type_Giving == "coordinates" || multiType_Giving1 == "coordinates" || multiType_Giving2 == "coordinates"){
                    if (type_Giving == "coordinates")
                        question_GeneratedValue1 = coords12;
                    else if (multiType_Giving1 == "coordinates")
                        question_GeneratedValue1 = coords12;
                    else if (multiType_Giving2 == "coordinates")
                        question_GeneratedValue2 = coords12;
                }

            } else if (user_GeneratedNumber == 13) {
                correctAnswer = degrees13;

                // Other Correct Value finder :D
                if (type_Giving == "radians" || multiType_Giving1 == "radians" || multiType_Giving2 == "radians") { //if type giv is degree it go here
                    if (type_Giving == "radians")
                        question_GeneratedValue1 = radian13;
                    else if (multiType_Giving1 == "radians")
                        question_GeneratedValue1 = radian13;
                    else if (multiType_Giving2 == "radians")
                        question_GeneratedValue2 = radian13;


                } else if (type_Giving == "coordinates" || multiType_Giving1 == "coordinates" || multiType_Giving2 == "coordinates"){
                    if (type_Giving == "coordinates")
                        question_GeneratedValue1 = coords13;
                    else if (multiType_Giving1 == "coordinates")
                        question_GeneratedValue1 = coords13;
                    else if (multiType_Giving2 == "coordinates")
                        question_GeneratedValue2 = coords13;
                }

            } else if (user_GeneratedNumber == 14) {
                correctAnswer = degrees14;

                // Other Correct Value finder :D
                if (type_Giving == "radians" || multiType_Giving1 == "radians" || multiType_Giving2 == "radians") { //if type giv is degree it go here
                    if (type_Giving == "radians")
                        question_GeneratedValue1 = radian14;
                    else if (multiType_Giving1 == "radians")
                        question_GeneratedValue1 = radian14;
                    else if (multiType_Giving2 == "radians")
                        question_GeneratedValue2 = radian14;


                } else if (type_Giving == "coordinates" || multiType_Giving1 == "coordinates" || multiType_Giving2 == "coordinates"){
                    if (type_Giving == "coordinates")
                        question_GeneratedValue1 = coords14;
                    else if (multiType_Giving1 == "coordinates")
                        question_GeneratedValue1 = coords14;
                    else if (multiType_Giving2 == "coordinates")
                        question_GeneratedValue2 = coords14;
                }

            } else if (user_GeneratedNumber == 15) {
                correctAnswer = degrees15;
                // Other Correct Value finder :D
                if (type_Giving == "radians" || multiType_Giving1 == "radians" || multiType_Giving2 == "radians") { //if type giv is degree it go here
                    if (type_Giving == "radians")
                        question_GeneratedValue1 = radian15;
                    else if (multiType_Giving1 == "radians")
                        question_GeneratedValue1 = radian15;
                    else if (multiType_Giving2 == "radians")
                        question_GeneratedValue2 = radian15;


                } else if (type_Giving == "coordinates" || multiType_Giving1 == "coordinates" || multiType_Giving2 == "coordinates"){
                    if (type_Giving == "coordinates")
                        question_GeneratedValue1 = coords15;
                    else if (multiType_Giving1 == "coordinates")
                        question_GeneratedValue1 = coords15;
                    else if (multiType_Giving2 == "coordinates")
                        question_GeneratedValue2 = coords15;
                }

            } else if (user_GeneratedNumber == 16) {
                correctAnswer = degrees16;

                // Other Correct Value finder :D
                if (type_Giving == "radians" || multiType_Giving1 == "radians" || multiType_Giving2 == "radians") { //if type giv is degree it go here
                    if (type_Giving == "radians")
                        question_GeneratedValue1 = radian16;
                    else if (multiType_Giving1 == "radians")
                        question_GeneratedValue1 = radian16;
                    else if (multiType_Giving2 == "radians")
                        question_GeneratedValue2 = radian16;


                } else if (type_Giving == "coordinates" || multiType_Giving1 == "coordinates" || multiType_Giving2 == "coordinates"){
                    if (type_Giving == "coordinates")
                        question_GeneratedValue1 = coords16;
                    else if (multiType_Giving1 == "coordinates")
                        question_GeneratedValue1 = coords16;
                    else if (multiType_Giving2 == "coordinates")
                        question_GeneratedValue2 = coords16;
                }

            } else if (user_GeneratedNumber == 17) {
                correctAnswer = degrees17;

                // Other Correct Value finder :D
                if (type_Giving == "radians" || multiType_Giving1 == "radians" || multiType_Giving2 == "radians") { //if type giv is degree it go here
                    if (type_Giving == "radians")
                        question_GeneratedValue1 = radian17;
                    else if (multiType_Giving1 == "radians")
                        question_GeneratedValue1 = radian17;
                    else if (multiType_Giving2 == "radians")
                        question_GeneratedValue2 = radian17;


                } else if (type_Giving == "coordinates" || multiType_Giving1 == "coordinates" || multiType_Giving2 == "coordinates"){
                    if (type_Giving == "coordinates")
                        question_GeneratedValue1 = coords1;
                    else if (multiType_Giving1 == "coordinates")
                        question_GeneratedValue1 = coords1;
                    else if (multiType_Giving2 == "coordinates")
                        question_GeneratedValue2 = coords1;
                }

            } else {
                cout << endl << "error with user_GeneratedNumber at degrees answer finder!!!!!!!!!!" << endl;
            }




        } else if ( type_Practice == "coordinates" || type_Practice == "both") {
            if (user_GeneratedNumber == 1) {
                correctAnswer = coords1;

                // Other Correct Value finder :D
                if (type_Giving == "radians" || multiType_Giving1 == "radians" || multiType_Giving2 == "radians") { //if type giv is degree it go here
                    if (type_Giving == "radians")
                        question_GeneratedValue1 = radian1;
                    else if (multiType_Giving1 == "radians")
                        question_GeneratedValue1 = radian1;
                    else if (multiType_Giving2 == "radians")
                        question_GeneratedValue2 = radian1;


                } else if (type_Giving == "degrees" || multiType_Giving1 == "degrees" || multiType_Giving2 == "degrees"){
                    if (type_Giving == "degrees")
                        question_GeneratedValue1 = degrees1;
                    else if (multiType_Giving1 == "degrees")
                        question_GeneratedValue1 = degrees1;
                    else if (multiType_Giving2 == "degrees")
                        question_GeneratedValue2 = degrees1;
                }

            } else if (user_GeneratedNumber == 2) {
                correctAnswer = coords2;

                // Other Correct Value finder :D
                if (type_Giving == "radians" || multiType_Giving1 == "radians" || multiType_Giving2 == "radians") { //if type giv is degree it go here
                    if (type_Giving == "radians")
                        question_GeneratedValue1 = radian2;
                    else if (multiType_Giving1 == "radians")
                        question_GeneratedValue1 = radian2;
                    else if (multiType_Giving2 == "radians")
                        question_GeneratedValue2 = radian2;


                } else if (type_Giving == "degrees" || multiType_Giving1 == "degrees" || multiType_Giving2 == "degrees"){
                    if (type_Giving == "degrees")
                        question_GeneratedValue1 = degrees2;
                    else if (multiType_Giving1 == "degrees")
                        question_GeneratedValue1 = degrees2;
                    else if (multiType_Giving2 == "degrees")
                        question_GeneratedValue2 = degrees2;
                }

            } else if (user_GeneratedNumber == 3) {
                correctAnswer = coords3;

                // Other Correct Value finder :D
                if (type_Giving == "radians" || multiType_Giving1 == "radians" || multiType_Giving2 == "radians") { //if type giv is degree it go here
                    if (type_Giving == "radians")
                        question_GeneratedValue1 = radian3;
                    else if (multiType_Giving1 == "radians")
                        question_GeneratedValue1 = radian3;
                    else if (multiType_Giving2 == "radians")
                        question_GeneratedValue2 = radian3;


                } else if (type_Giving == "degrees" || multiType_Giving1 == "degrees" || multiType_Giving2 == "degrees"){
                    if (type_Giving == "degrees")
                        question_GeneratedValue1 = degrees3;
                    else if (multiType_Giving1 == "degrees")
                        question_GeneratedValue1 = degrees3;
                    else if (multiType_Giving2 == "degrees")
                        question_GeneratedValue2 = degrees3;
                }

            } else if (user_GeneratedNumber == 4) {
                correctAnswer = coords4;

                // Other Correct Value finder :D
                if (type_Giving == "radians" || multiType_Giving1 == "radians" || multiType_Giving2 == "radians") { //if type giv is degree it go here
                    if (type_Giving == "radians")
                        question_GeneratedValue1 = radian4;
                    else if (multiType_Giving1 == "radians")
                        question_GeneratedValue1 = radian4;
                    else if (multiType_Giving2 == "radians")
                        question_GeneratedValue2 = radian4;


                } else if (type_Giving == "degrees" || multiType_Giving1 == "degrees" || multiType_Giving2 == "degrees"){
                    if (type_Giving == "degrees")
                        question_GeneratedValue1 = degrees4;
                    else if (multiType_Giving1 == "degrees")
                        question_GeneratedValue1 = degrees4;
                    else if (multiType_Giving2 == "degrees")
                        question_GeneratedValue2 = degrees4;
                }

            } else if (user_GeneratedNumber == 5) {
                correctAnswer = coords5;

                // Other Correct Value finder :D
                if (type_Giving == "radians" || multiType_Giving1 == "radians" || multiType_Giving2 == "radians") { //if type giv is degree it go here
                    if (type_Giving == "radians")
                        question_GeneratedValue1 = radian5;
                    else if (multiType_Giving1 == "radians")
                        question_GeneratedValue1 = radian5;
                    else if (multiType_Giving2 == "radians")
                        question_GeneratedValue2 = radian5;


                } else if (type_Giving == "degrees" || multiType_Giving1 == "degrees" || multiType_Giving2 == "degrees"){
                    if (type_Giving == "degrees")
                        question_GeneratedValue1 = degrees5;
                    else if (multiType_Giving1 == "degrees")
                        question_GeneratedValue1 = degrees5;
                    else if (multiType_Giving2 == "degrees")
                        question_GeneratedValue2 = degrees5;
                }

            } else if (user_GeneratedNumber == 6) {
                correctAnswer = coords6;

                // Other Correct Value finder :D
                if (type_Giving == "radians" || multiType_Giving1 == "radians" || multiType_Giving2 == "radians") { //if type giv is degree it go here
                    if (type_Giving == "radians")
                        question_GeneratedValue1 = radian6;
                    else if (multiType_Giving1 == "radians")
                        question_GeneratedValue1 = radian6;
                    else if (multiType_Giving2 == "radians")
                        question_GeneratedValue2 = radian6;


                } else if (type_Giving == "degrees" || multiType_Giving1 == "degrees" || multiType_Giving2 == "degrees"){
                    if (type_Giving == "degrees")
                        question_GeneratedValue1 = degrees6;
                    else if (multiType_Giving1 == "degrees")
                        question_GeneratedValue1 = degrees6;
                    else if (multiType_Giving2 == "degrees")
                        question_GeneratedValue2 = degrees6;
                }

            } else if (user_GeneratedNumber == 7) {
                correctAnswer = coords7;

                // Other Correct Value finder :D
                if (type_Giving == "radians" || multiType_Giving1 == "radians" || multiType_Giving2 == "radians") { //if type giv is degree it go here
                    if (type_Giving == "radians")
                        question_GeneratedValue1 = radian7;
                    else if (multiType_Giving1 == "radians")
                        question_GeneratedValue1 = radian7;
                    else if (multiType_Giving2 == "radians")
                        question_GeneratedValue2 = radian7;


                } else if (type_Giving == "degrees" || multiType_Giving1 == "degrees" || multiType_Giving2 == "degrees"){
                    if (type_Giving == "degrees")
                        question_GeneratedValue1 = degrees7;
                    else if (multiType_Giving1 == "degrees")
                        question_GeneratedValue1 = degrees7;
                    else if (multiType_Giving2 == "degrees")
                        question_GeneratedValue2 = degrees7;
                }

            } else if (user_GeneratedNumber == 8) {
                correctAnswer = coords8;

                // Other Correct Value finder :D
                if (type_Giving == "radians" || multiType_Giving1 == "radians" || multiType_Giving2 == "radians") { //if type giv is degree it go here
                    if (type_Giving == "radians")
                        question_GeneratedValue1 = radian8;
                    else if (multiType_Giving1 == "radians")
                        question_GeneratedValue1 = radian8;
                    else if (multiType_Giving2 == "radians")
                        question_GeneratedValue2 = radian8;


                } else if (type_Giving == "degrees" || multiType_Giving1 == "degrees" || multiType_Giving2 == "degrees"){
                    if (type_Giving == "degrees")
                        question_GeneratedValue1 = degrees8;
                    else if (multiType_Giving1 == "degrees")
                        question_GeneratedValue1 = degrees8;
                    else if (multiType_Giving2 == "degrees")
                        question_GeneratedValue2 = degrees8;
                }

            } else if (user_GeneratedNumber == 9) {
                correctAnswer = coords9;

                // Other Correct Value finder :D
                if (type_Giving == "radians" || multiType_Giving1 == "radians" || multiType_Giving2 == "radians") { //if type giv is degree it go here
                    if (type_Giving == "radians")
                        question_GeneratedValue1 = radian9;
                    else if (multiType_Giving1 == "radians")
                        question_GeneratedValue1 = radian9;
                    else if (multiType_Giving2 == "radians")
                        question_GeneratedValue2 = radian9;


                } else if (type_Giving == "degrees" || multiType_Giving1 == "degrees" || multiType_Giving2 == "degrees"){
                    if (type_Giving == "degrees")
                        question_GeneratedValue1 = degrees9;
                    else if (multiType_Giving1 == "degrees")
                        question_GeneratedValue1 = degrees9;
                    else if (multiType_Giving2 == "degrees")
                        question_GeneratedValue2 = degrees9;
                }

            } else if (user_GeneratedNumber == 10) {
                correctAnswer = coords10;

                // Other Correct Value finder :D
                if (type_Giving == "radians" || multiType_Giving1 == "radians" || multiType_Giving2 == "radians") { //if type giv is degree it go here
                    if (type_Giving == "radians")
                        question_GeneratedValue1 = radian10;
                    else if (multiType_Giving1 == "radians")
                        question_GeneratedValue1 = radian10;
                    else if (multiType_Giving2 == "radians")
                        question_GeneratedValue2 = radian10;


                } else if (type_Giving == "degrees" || multiType_Giving1 == "degrees" || multiType_Giving2 == "degrees"){
                    if (type_Giving == "degrees")
                        question_GeneratedValue1 = degrees10;
                    else if (multiType_Giving1 == "degrees")
                        question_GeneratedValue1 = degrees10;
                    else if (multiType_Giving2 == "degrees")
                        question_GeneratedValue2 = degrees10;
                }

            } else if (user_GeneratedNumber == 11) {
                correctAnswer = coords11;

                // Other Correct Value finder :D
                if (type_Giving == "radians" || multiType_Giving1 == "radians" || multiType_Giving2 == "radians") { //if type giv is degree it go here
                    if (type_Giving == "radians")
                        question_GeneratedValue1 = radian11;
                    else if (multiType_Giving1 == "radians")
                        question_GeneratedValue1 = radian11;
                    else if (multiType_Giving2 == "radians")
                        question_GeneratedValue2 = radian11;


                } else if (type_Giving == "degrees" || multiType_Giving1 == "degrees" || multiType_Giving2 == "degrees"){
                    if (type_Giving == "degrees")
                        question_GeneratedValue1 = degrees11;
                    else if (multiType_Giving1 == "degrees")
                        question_GeneratedValue1 = degrees11;
                    else if (multiType_Giving2 == "degrees")
                        question_GeneratedValue2 = degrees11;
                }

            } else if (user_GeneratedNumber == 12) {
                correctAnswer = coords12;

                // Other Correct Value finder :D
                if (type_Giving == "radians" || multiType_Giving1 == "radians" || multiType_Giving2 == "radians") { //if type giv is degree it go here
                    if (type_Giving == "radians")
                        question_GeneratedValue1 = radian12;
                    else if (multiType_Giving1 == "radians")
                        question_GeneratedValue1 = radian12;
                    else if (multiType_Giving2 == "radians")
                        question_GeneratedValue2 = radian12;


                } else if (type_Giving == "degrees" || multiType_Giving1 == "degrees" || multiType_Giving2 == "degrees"){
                    if (type_Giving == "degrees")
                        question_GeneratedValue1 = degrees12;
                    else if (multiType_Giving1 == "degrees")
                        question_GeneratedValue1 = degrees12;
                    else if (multiType_Giving2 == "degrees")
                        question_GeneratedValue2 = degrees12;
                }

            } else if (user_GeneratedNumber == 13) {
                correctAnswer = coords13;

                // Other Correct Value finder :D
                if (type_Giving == "radians" || multiType_Giving1 == "radians" || multiType_Giving2 == "radians") { //if type giv is degree it go here
                    if (type_Giving == "radians")
                        question_GeneratedValue1 = radian13;
                    else if (multiType_Giving1 == "radians")
                        question_GeneratedValue1 = radian13;
                    else if (multiType_Giving2 == "radians")
                        question_GeneratedValue2 = radian13;


                } else if (type_Giving == "degrees" || multiType_Giving1 == "degrees" || multiType_Giving2 == "degrees"){
                    if (type_Giving == "degrees")
                        question_GeneratedValue1 = degrees13;
                    else if (multiType_Giving1 == "degrees")
                        question_GeneratedValue1 = degrees13;
                    else if (multiType_Giving2 == "degrees")
                        question_GeneratedValue2 = degrees13;
                }

            } else if (user_GeneratedNumber == 14) {
                correctAnswer = coords14;

                // Other Correct Value finder :D
                if (type_Giving == "radians" || multiType_Giving1 == "radians" || multiType_Giving2 == "radians") { //if type giv is degree it go here
                    if (type_Giving == "radians")
                        question_GeneratedValue1 = radian14;
                    else if (multiType_Giving1 == "radians")
                        question_GeneratedValue1 = radian14;
                    else if (multiType_Giving2 == "radians")
                        question_GeneratedValue2 = radian14;


                } else if (type_Giving == "degrees" || multiType_Giving1 == "degrees" || multiType_Giving2 == "degrees"){
                    if (type_Giving == "degrees")
                        question_GeneratedValue1 = degrees14;
                    else if (multiType_Giving1 == "degrees")
                        question_GeneratedValue1 = degrees14;
                    else if (multiType_Giving2 == "degrees")
                        question_GeneratedValue2 = degrees14;
                }

            } else if (user_GeneratedNumber == 15) {
                correctAnswer = coords15;

                // Other Correct Value finder :D
                if (type_Giving == "radians" || multiType_Giving1 == "radians" || multiType_Giving2 == "radians") { //if type giv is degree it go here
                    if (type_Giving == "radians")
                        question_GeneratedValue1 = radian15;
                    else if (multiType_Giving1 == "radians")
                        question_GeneratedValue1 = radian15;
                    else if (multiType_Giving2 == "radians")
                        question_GeneratedValue2 = radian15;


                } else if (type_Giving == "degrees" || multiType_Giving1 == "degrees" || multiType_Giving2 == "degrees"){
                    if (type_Giving == "degrees")
                        question_GeneratedValue1 = degrees15;
                    else if (multiType_Giving1 == "degrees")
                        question_GeneratedValue1 = degrees15;
                    else if (multiType_Giving2 == "degrees")
                        question_GeneratedValue2 = degrees15;
                }

            } else if (user_GeneratedNumber == 16) {
                correctAnswer = coords16;

                // Other Correct Value finder :D
                if (type_Giving == "radians" || multiType_Giving1 == "radians" || multiType_Giving2 == "radians") { //if type giv is degree it go here
                    if (type_Giving == "radians")
                        question_GeneratedValue1 = radian16;
                    else if (multiType_Giving1 == "radians")
                        question_GeneratedValue1 = radian16;
                    else if (multiType_Giving2 == "radians")
                        question_GeneratedValue2 = radian16;


                } else if (type_Giving == "degrees" || multiType_Giving1 == "degrees" || multiType_Giving2 == "degrees"){
                    if (type_Giving == "degrees")
                        question_GeneratedValue1 = degrees16;
                    else if (multiType_Giving1 == "degrees")
                        question_GeneratedValue1 = degrees16;
                    else if (multiType_Giving2 == "degrees")
                        question_GeneratedValue2 = degrees16;
                }

            } else if (user_GeneratedNumber == 17) {
                correctAnswer = coords1;

                // Other Correct Value finder :D
                if (type_Giving == "radians" || multiType_Giving1 == "radians" || multiType_Giving2 == "radians") { //if type giv is degree it go here
                    if (type_Giving == "radians")
                        question_GeneratedValue1 = radian17;
                    else if (multiType_Giving1 == "radians")
                        question_GeneratedValue1 = radian17;
                    else if (multiType_Giving2 == "radians")
                        question_GeneratedValue2 = radian17;


                } else if (type_Giving == "degrees" || multiType_Giving1 == "degrees" || multiType_Giving2 == "degrees"){
                    if (type_Giving == "degrees")
                        question_GeneratedValue1 = degrees17;
                    else if (multiType_Giving1 == "degrees")
                        question_GeneratedValue1 = degrees17;
                    else if (multiType_Giving2 == "degrees")
                        question_GeneratedValue2 = degrees17;
                }

            } else {
                cout << endl << "error with user_GeneratedNumber at coords answer finder!!!!!!!!!! " << user_GeneratedNumber << endl;
            }
        }
        
        
        /*
        if (end_TotalQuestionsCompleted == amount_of_Questions || userResponse == endingCommand){
            cout << endl << endl << endl;

            //seperation :)
            cout << endl << endl << ". . . . . . . . . . . . . . . " << endl;

            if (end_TotalQuestionsCompleted == amount_of_Questions) {
                cout << " ~!~ Congratulations! You've managed to finish. ~!~" << endl;
                end_TotalQuestionsCompleted = amount_of_Questions;

            } else if (userResponse == endingCommand) {
                cout << " ~!~ You've successfully ended the program. ~!~" << endl;
                userResponse = endingCommand;
            }
        } else {*/

            //Starting Barrier for each Question
            cout << endl << endl << "   . . . . . . . . . . . . . . . " << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "   . . . . . . . . . . . . . . . " << endl << endl << endl << endl << endl;

            cout << "QUESTION ~ " << end_TotalQuestionsCompleted << endl << endl;
            

            if (type_Giving == "both") {
                cout << multiType_Giving1 << " value is " << question_GeneratedValue1 << endl;
                cout << multiType_Giving2 << " value is " << question_GeneratedValue2 << endl;
            } else {
                cout << type_Giving << " value is " << question_GeneratedValue1 << endl;
            }



            //User response
            cout << endl << endl << " . . . . . . " << endl << endl;
            cout << "Whats your answer in " << type_Practice << "?" << endl;
            cout << "(remeber \"pi\" for pi and \"V\" for square root of... also no spaces!!!!!)" << endl;
            cout << " - ";
            getline (cin, userResponse);

            //Checking user answer

            if (userResponse != correctAnswer && attemptCounter < 3) {
                cout << endl << " ~!~ You have not entered the correct value ~!~" << endl;
                cout << endl << " ~!~ The correct value was " << correctAnswer << "! ~!~" << endl;
                end_AmountUserWrong += 1; 
                end_TotalQuestionsCompleted += 1;

            } else if (userResponse == correctAnswer) {
                cout << endl << " ~!~ You guessed the correct answer! ~!~ " << endl;
                end_TotalQuestionsCompleted += 1;
                end_AmountUserCorrect += 1;

            } else if (userResponse == endingCommand) {
                userResponse = endingCommand;

            } else {
                cout << endl << " ~!~ You have not entered the correct value ~!~" << endl;
                cout << endl << " ~!~ The correct value was " << correctAnswer << "! ~!~" << endl;  
                end_AmountUserWrong += 1; 
                end_TotalQuestionsCompleted += 1;
            }
            attemptCounter += 1;

        //}

    }



    //seperation :)
    cout << endl << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

    //Ending Stats
    cout << endl << " ~~****~~ Your stats for this session ~~****~~ " << endl << endl;

    cout << "Value you Picked to Practice ------------ " << type_Practice << endl << endl;

    if (type_Giving != "both") {
        cout << "Value(s) you Picked to Use to Practice -- " << type_Giving << endl << endl;
    
    } else if (type_Giving == "both") {
        cout << "Value(s) you Picked to Use to Practice -- " << multiType_Giving1 << " and " << multiType_Giving2 << endl << endl;
    }

    cout << "Total Questions Answered! --------------- " << end_TotalQuestionsCompleted << endl << endl;

    cout << "Total Wrong Answers! -------------------- " << end_AmountUserWrong << endl << endl;

    cout << "Total Correct Answers! ------------------ " << end_AmountUserCorrect << endl << endl << endl << endl << endl;

    //cout << "Based on this data you " << (end_TotalQuestionsCompleted / end_AmountUserCorrect ) << " proficient with your questions" << endl << endl;

    return 0;
}
