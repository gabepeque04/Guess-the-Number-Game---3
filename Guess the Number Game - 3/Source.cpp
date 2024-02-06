#include <iostream> //Necessary for input/output
#include <cstdlib> //Random number generator. For rand() and srand()
#include <ctime> //For time functions. time()

using namespace std; //allows the use standard C++ fuctions without prefixing them with std::

// Function to generate a random number between min and max (inclusive)
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min; //0-99 + 1 -> 1-100. Generates a random number with numbers from generateRandomNumber.
}

// Function to provide hints based on the difference between the guess and the secret number
void provideHint(int previousGuess, int secretNumber) {
    int difference = abs(secretNumber - previousGuess); //Absolute difference between the previous guess and secret number is calculated to ensure positive values.
    //If user guess is 20 or more away from secret number this is prompted.
    if (difference >= 20) {
        cout << "Hint: You are far from the secret number." << endl;
    }
    //If user guess is 10 or more away from secret number this is prompted.
    else if (difference >= 10) {
        cout << "Hint: You are getting closer to the secret number." << endl;
    }
    //If user guess is less than 10 away from secret number this is prompted.
    else {
        cout << "Hint: You are very close to the secret number." << endl;
    }
    
}
//Define the main function, the starting point of execution for the C++ program.
int main() {
    srand(time(0)); //Seed the random number generator with the current time to produce different random numbers each time the program runs.

    int secretNumber = generateRandomNumber(1, 100); //Generate a random number between 1 and 100. 
    int guess; //Stores the user's guess.
    int previousGuess = 0; //Stores the user's previous guess. This will make sure the previous guess is not removed when asking for a hint.
    int attempts = 0; //Stores the user's attempts.

    cout << "Welcome to Guess the Number!" << endl; //Outputs a welcome message to the user.
    cout << "Try to guess the secret number between 1 and 100." << endl; //Provides instructions to the user.
    cout << "You can enter '0' to get a hint." << endl; //Gives the user instructions on how to get a hint. 

    do {
        cout << "Enter your guess: "; //Prompts the user to enter a guess.
        cin >> guess; //Reads the user's input and assigns it to the variable guess.
        attempts++; //Increments the attempts counter for each guess.
        //Checks if the user's guess is equal to the secret number. Outputs Congratulations and how many attempts it took.
        if (guess == secretNumber) {
            cout << "Congratulations! You guessed the correct number in " << attempts << " attempts." << endl;
        }
        //User selects 0 to get a hint. 
        else if (guess == 0) {
            provideHint(previousGuess, secretNumber); //Call the provideHint function to give a hint based on the previous guess.
           
        }
        //Checks if guess is out of the limit. 
        else if (guess < 1 || guess > 100) {
            cout << "Invalid guess. Please enter a number between 1 and 100." << endl;
        }
        //Checks if guess is lower than secret number.
        else if (guess < secretNumber) {
            cout << "Too low. Try again!" << endl;
            
        }
        //Catches if guess is higher than secret number.
        else {
            cout << "Too high. Try again!" << endl;
            
        }
        previousGuess = guess; //Updates previousGuess for the next iteration.

    } while (guess != secretNumber); //Continues the loop until the user guesses the correct number.

    return 0; //Indicates succesful program execution.
}