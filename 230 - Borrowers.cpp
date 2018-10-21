#include <bits/stdc++.h>
using namespace std;

map <string, string> Authorof;

class classcomp
{
public:
    bool operator () (const string &a, const string &b) const
    {
        if(Authorof[a] != Authorof[b])
            return Authorof[a] < Authorof[b];

        return a < b;
    }
};

int main()
{
    string s;
    map <string, string, classcomp> BookShelve;

    while(getline(cin, s), s != "END")
    {
        stringstream ss(s);
        string author, title, temp;

        ///Extracting book name with double quote (doesn't matter while processing)
        ss >> title;

        while(ss >> temp, temp != "by")
            title += (" " + temp);

        ///Extracting author name
        ss >> author;

        while(ss >> temp)
            author += (" " + temp);

        Authorof[title] = author;
        BookShelve[title] = author;
    }

    set <string, classcomp> ReturnBooks;

    while(getline(cin, s), s != "END")
    {
        stringstream ss(s);
        string decision, title, temp;

        ///Extracting decision and name with double quote
        ss >> decision >> title;

        while(ss >> temp)
            title += (" " + temp);

        if(decision == "BORROW")
            BookShelve.erase(title); ///Deleting borrowed book from shelve

        else if(decision == "RETURN")
            ReturnBooks.insert(title); ///Storing returned books

        else if(decision == "SHELVE")
        {
            ///Returning returned books to the shelve
            set <string, classcomp> :: iterator sit;

            for(sit = ReturnBooks.begin(); sit != ReturnBooks.end(); sit++)
            {
                string title = *sit;
                BookShelve[title] = Authorof[title];

                map <string, string, classcomp> :: iterator mit;
                mit = BookShelve.lower_bound(title); ///Getting reference of stored book

                ///if it is first book
                if(mit == BookShelve.begin())
                    cout << "Put " << title << " first\n";

                ///if it is not first book
                else
                {
                    --mit; ///getting previous book's reference
                    cout << "Put " << title << " after " << mit->first << endl;
                }
            }

            ReturnBooks.clear();
            cout << "END\n";
        }
    }

    return 0;
}
