#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    enum vocab { Term, Hint, NumVocab };
    const int totVocab = 10;
    const string WORDS[totVocab][NumVocab] =
    {
        {"Wall", "Do you feel you're banging your head against something?"},
        {"Glasses", "These might help you see the answer."}
    };
}