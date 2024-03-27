#include "movieList.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void movieList::add(string n, double r, int y)
{
    movieNode *newmovie = new movieNode(n,r,y);

    if(name_head == NULL)
    {
        name_head = newmovie;
    }
    else if(newmovie->name.compare(name_head->name) < 0)
    {
        newmovie->name_next = name_head;
        name_head = newmovie;
    }
    else
    {
        movieNode *name_curr = name_head, *name_prev;
        while( (name_curr->name_next != NULL) && (newmovie->name.compare(name_curr->name) >= 0))
        {
            name_prev = name_curr;
            name_curr = name_curr->name_next;
        }

        if(newmovie->name.compare(name_curr->name) < 0)
        {
            name_prev->name_next = newmovie;
            newmovie->name_next = name_curr;
        }
        else
        {
            name_curr->name_next = newmovie;
        }

    }

    if(rate_head == NULL)
    {
        rate_head = newmovie;
    }
    else if((newmovie->rate) < (rate_head->rate) )
    {
        newmovie->rate_next = rate_head;
        rate_head = newmovie;
    }
    else
    {
        movieNode *rate_curr = rate_head, *rate_prev;
        while( (rate_curr->rate_next != NULL) && (newmovie->rate >= rate_curr->rate))
        {
            rate_prev = rate_curr;
            rate_curr = rate_curr->rate_next;
        }

        if(newmovie->rate < rate_curr->rate)
        {
            rate_prev->rate_next = newmovie;
            newmovie->rate_next = rate_curr;
        }
        else
        {
            rate_curr->rate_next = newmovie;
        }

    }

    if(year_head == NULL)
    {
        year_head = newmovie;
    }
    else if((newmovie->year) < (year_head->year) )
    {
        newmovie->year_next = year_head;
        year_head = newmovie;
    }
    else
    {
        movieNode *year_curr = year_head, *year_prev;
        while( (year_curr->year_next != NULL) && (newmovie->year >= year_curr->year))
        {
            year_prev = year_curr;
            year_curr = year_curr->year_next;
        }

        if(newmovie->year < year_curr->year)
        {
            year_prev->year_next = newmovie;
            newmovie->year_next = year_curr;
        }
        else
        {
            year_curr->year_next = newmovie;
        }

    }


}

void movieList::printByName()
{
    movieNode *temp = name_head;

    while(temp != NULL)
    {
        cout << temp->name << " " << temp->rate << " " << temp->year << endl;
        temp = temp->name_next;
    }
}

void movieList::printByRate()
{
    movieNode *temp = rate_head;

    while(temp != NULL)
    {
        cout << temp->name << " " << temp->rate << " " << temp->year << endl;
        temp = temp->rate_next;
    }
}

void movieList::printByYear()
{
    movieNode *temp = year_head;

    while(temp != NULL)
    {
        cout << temp->name << " " << temp->rate << " " << temp->year << endl;
        temp = temp->year_next;
    }
}

bool movieList::remove(string n)
{
    movieNode *temp = name_head;

    while((temp != NULL) && (temp->name.compare(n) != 0) )
    {
        temp = temp->name_next;
    }

    if(temp == NULL)
        return false;

    if(temp->name.compare(n) == 0)
    {

        if(temp == year_head)
        {
            year_head = temp->year_next;
            temp->year_next = NULL;
        }
        else
        {
            movieNode *year_curr = year_head, *year_prev;
            while(year_curr->name.compare(n) != 0)
            {
                year_prev = year_curr;
                year_curr = year_curr->year_next;
            }

            year_prev->year_next = temp->year_next;
            temp->year_next = NULL;
        }

        if(temp == rate_head)
        {
            rate_head = temp->rate_next;
            temp->rate_next = NULL;
        }
        else
        {
            movieNode *rate_curr = rate_head, *rate_prev;
            while(rate_curr->name.compare(n) != 0)
            {
                rate_prev = rate_curr;
                rate_curr = rate_curr->rate_next;
            }

            rate_prev->rate_next = temp->rate_next;
            temp->rate_next = NULL;
        }

        if(temp == name_head)
        {
            name_head = temp->name_next;
            temp->name_next = NULL;
        }
        else
        {
            movieNode *name_curr = name_head, *name_prev;
            while(name_curr->name.compare(n) != 0)
            {
                name_prev = name_curr;
                name_curr = name_curr->name_next;
            }

            name_prev->name_next = temp->name_next;
            temp->name_next = NULL;
        }
        return true;
    }

}

void movieList::update(string n, double r)
{
    movieNode *temp = name_head;

    while((temp != NULL) && (temp->name.compare(n) != 0) )
    {
        temp = temp->name_next;
    }

    if(temp != NULL)
    {
        movieNode *updated_movie = new movieNode(temp->name, r, temp->year);
        remove(n);
        add(updated_movie->name, updated_movie->rate, updated_movie->year);
    }
}

void movieList::loadFile(string filename)
{
    string line;
    fstream file(filename.c_str());

    while(getline(file,line))
    {
        int name_start = line.find_first_of('"');
        int name_end = line.find_last_of('"');
        string moviename = line.substr(name_start+1,name_end-1);

        int rating_start = line.find_first_of(' ',name_end);
        int rating_end = line.find_first_of(' ',rating_start);
        string rt = line.substr(rating_start+1,rating_end-1);
        stringstream rs(rt);
        double rating;
        rs >> rating;

        int year_start = line.find_first_of(' ',rating_end+1);
        int year_end = line.find_last_of(' ',year_start);
        string yr = line.substr(year_start+1,year_end-1);
        stringstream ys(yr);
        int year;
        ys >> year;

        add(moviename,rating,year);
    }
    file.close();
}

void movieList::saveToFileByName(string filename)
{
    fstream file(filename.c_str());

    movieNode *current = name_head;

    while(current != NULL)
    {
        file << '"' << current->name << '"' << " " << current->rate << " " << current->year << "\n";
        current = current->name_next;
    }

    file.close();
}

void movieList::saveToFileByRate(string filename)
{
    fstream file(filename.c_str());

    movieNode *current = rate_head;

    while(current != NULL)
    {
        file << '"' << current->name << '"' << " " << current->rate << " " << current->year << "\n";
        current = current->rate_next;
    }

    file.close();
}

void movieList::saveToFileByYear(string filename)
{
    fstream file(filename.c_str());

    movieNode *current = year_head;

    while(current != NULL)
    {
        file << '"' << current->name << '"' << " " << current->rate << " " << current->year << "\n";
        current = current->year_next;
    }

    file.close();
}
