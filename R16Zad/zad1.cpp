#include <iostream>
#include <algorithm>

using namespace std;

void deleteSpC(string & sentence, char cah)
{
    sentence.erase(remove_if(sentence.begin(), sentence.end(), [cah](char c)->bool { return c == cah; }), sentence.end());
    transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower);
}


bool isPad(string & word)
{
    deleteSpC(word, ' ');
    cout << word << endl;
    for (int i = 0; i < word.size()/2; i++)
        if (word[i] != word[((word.size()-1)-i)])    
            return false;
    return true;
}


int main()
{
    cout << "Podaj cos, co moze byc padem: <albo 'koniec'>: ";    
    string pad;
    
    while (getline(cin, pad) && pad != "koniec")
    {
        if (isPad(pad))
            cout << "Podane słowo jest padem!";
        else
            cout << "Podane słowo nie jest padem!";

        cout << endl;
        cout << "Podaj cos, co moze byc padem: <albo 'koniec'>: ";
    }


    return 0;
}

