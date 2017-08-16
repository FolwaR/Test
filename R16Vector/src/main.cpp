#include <iostream>
#include <vector>

using namespace std;

struct Review
{
    string title;
    int rating;
};

bool FillReview(Review & rr);
void ShowReview(const Review & rr);

int main()
{
    vector<Review> books;
    Review temp;

    while (FillReview(temp))
        books.push_back(temp);

    int num = books.size();

    if (num > 0)
    {
        cout << "Dziękuję. Wpisałeś następujące dane:\n"
        << "Ocena\tKsiążka\n";

        for (int i = 0; i < num; i++)
            ShowReview(books[i]);
        
        cout << " Przypomnienie ocen:\n"
            << "Ocena\tKsiążka\n";
        
        vector<Review>::iterator pr(books.begin());

        while (pr != books.end())
        {
            ShowReview(*pr);
            pr++;
        }

        vector<Review> oldlist(books);

        if (num > 3)
        {
            books.erase(books.begin() + 1, books.begin() + 3);
            cout << "Po usunięciu:\n";
            for (pr = books.begin(); pr != books.end(); pr++)
                ShowReview(*pr);
            books.insert(books.begin(), oldlist.begin() + 1, oldlist.begin() + 2);  
            cout << "Po wstawieniu:\n";
            for (pr = books.begin(); pr != books.end(); pr++)
                ShowReview(*pr);
        }
        books.swap(oldlist);
        cout << "Zamiana zawartości wektorów oldlist i books:\n";
        for (pr = books.begin(); pr != books.end(); pr++)
            ShowReview(*pr);
    }
    else
        cout << "Bez wpisywania nie ma wyświetlania.\n";
    
    return 0;
}


bool FillReview(Review & rr)
{
    cout << "Wpisz tytuł książki ('koniec', aby zakończyć): ";
    getline(cin, rr.title);
    
    if ( rr.title == "koniec" )
        return false;
    
    cout << "Podaj ocenę owej książki: ";
    
    if (!(cin >> rr.rating))
    {
        cin.clear();
        
        while (cin.get() != '\n')
            continue;
        
        return false;    
    }
    
    cin.get();

    return true;    
}


void ShowReview(const Review & rr)
{
    cout << rr.rating << '\t' << rr.title << endl;
    
}



