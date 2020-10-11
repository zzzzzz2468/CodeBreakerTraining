#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void game()
{
    enum vocab { Term, Hint, NumVocab };
    const int totVocab = 10;
    const string Vocab[totVocab][NumVocab] =
    {
        {"Asm","Gives the ability to embed assembly language source code within a C++ program."},
        {"Auto", "Either that the return type will be deduced from return statements, or that it will be deduced from the argument."},
        {"Bool", "True or false, stored as 0 or 1, 0 = false, 1 = true, data type."},
        {"Break", "Breaks out of code or a loop.Used to break out of for loops or switch statements."},
        {"Case", "In switch statements, checks if the expression is equal to the following constant value."},
        {"Catch", "Used in try statements, it is on the recieving end of codeand finds if there was an exception."},
        {"Char", "Is a data type.It is a single character surrounded by single quotes."},
        {"Class", "It is the building block that leads to object oriented programming, it is similar to a blueprint."},
        {"Const", "Says the variable will be constant,and to prevent the program from changing it."},
        {"Const_cast", "Can change non - const class members inside a const member function."},
    };

    cout << "\t\tWelcome to Vocabulary Jumble!\n\n";
    cout << "Unscramble the letter to make a word.\n";
    cout << "Enter 'hint' for a hint.\n";
    cout << "Enter 'quit' to quit the game.\n\n";

    string answers[3];
    string hints[3];
    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < 3; i++)
    {
        int term = (rand() % totVocab);

        string theTerm = Vocab[term][Term];
        string theHint = Vocab[term][Hint];

        string jumble = theTerm;
        int length = jumble.size();

        for (int a = 0; a < length; a++)
        {
            int index1 = (rand() % length);
            int index2 = (rand() % length);
            char temp = jumble[index1];
            jumble[index1] = jumble[index2];
            jumble[index2] = temp;
        };

        cout << "\nA jumble is: " << jumble;
        answers[i] = theTerm;
        hints[i] = theHint;
    }

    string guess;
    int correctAnswers = 0;
    int wrongAnswers = 0;

    while (correctAnswers < 3 && guess != "quit")
    {
        cout << "\n\nYour guess: ";
        cin >> guess;

        if (guess == "hint")
        {
            cout << "\nWhich promt? (1/2/3) ";
            int promt;
            cin >> promt;
            cout << hints[promt];
        }
        else if (guess == answers[0] || guess == answers[1] || guess == answers[2])
        {
            cout << "\nWell done, you got one!";
            correctAnswers++;
        }
        else
        {
            cout << "\nWrong answer, try again...";
            wrongAnswers++;
        }
    }

    if (correctAnswers >= 3)
    {
        cout << "\nYou got them all, well done!";
        cout << "\nYou had " << wrongAnswers << " incorrect guesses.";
        cout << "\nYou had a total of " << (wrongAnswers + correctAnswers) << " guesses.";
    }
}

int main()
{
    bool isPlaying = true;
    while (isPlaying)
    {
        game();
        cout << "\nThanks for playing.\n";
        cout << "Do you want to contine? (y/n) ";
        string response;
        cin >> response;
        if (response == "y")
            isPlaying = true;
        else isPlaying = false;
    }

    return 0;
}