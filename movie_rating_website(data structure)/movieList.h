#ifndef MOVIELIST_H
#define MOVIELIST_H
#include <string>
using namespace std;
class movieNode
{
public:
    movieNode()
    {
        name_next = NULL;
        rate_next = NULL;
        year_next = NULL;
    }

    movieNode(string n, double r, int y)
    {
        name = n;
        rate = r;
        year = y;
        name_next = NULL;
        rate_next = NULL;
        year_next = NULL;
    }

    string name;
    double rate;
    int year;

    movieNode *name_next, *rate_next, *year_next;
};
class movieList
{
    public:
        movieList()
        {
            name_head = NULL;
            rate_head = NULL;
            year_head = NULL;
        }

        void add(string n, double r, int y);
        void printByName();
        void printByRate();
        void printByYear();
        void update(string n, double r);
        bool remove(string n);
        void loadFile(string filename);
        void saveToFileByYear(string filename);
        void saveToFileByName(string filename);
        void saveToFileByRate(string filename);

        movieNode *name_head, *rate_head, *year_head;




};

#endif // MOVIELIST_H
