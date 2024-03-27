#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "movieList.h"
using namespace std;

int main()
{
    int selection;
    movieList *movies = new movieList();


    do{
            cout << "1.Add movie" << endl;
            cout << "2.Remove movie"<< endl;
            cout << "3.Update movie" << endl;
            cout << "4.Print movies by year" << endl;
            cout << "5.Print movies by name" << endl;
            cout << "6.Print movies by rate" << endl;
            cout << "7.Load file" << endl;
            cout << "8.Save to file by year" << endl;
            cout << "9.Save to file by name" << endl;
            cout << "10.Save to file by rate" << endl;
            cout << "Enter command number" << endl;
            cin >> selection;
            cin.ignore();

            if(selection == 1)
            {
                int year;
                double rate;
                string name;
                cout << "Enter movie name:  ";
                getline(cin,name);
                cout << "Enter rate: ";
                cin >> rate;
                cin.ignore();
                cout << "Enter year: ";
                cin >> year;
                cin.ignore();

                movies->add(name,rate,year);
            }
            else if(selection == 2)
            {
                string name;
                cout << "Enter movie name: ";
                getline(cin,name);
                if(movies->remove(name))
                    cout << "Movie removed" << endl;
                else
                    cout << "Movie not found" << endl;
            }
            else if(selection == 3)
            {
                string name;
                double rate;
                cout << "Enter movie name: ";
                getline(cin,name);
                cout << "Enter updated rate: ";
                cin >> rate;
                cin.ignore();
                movies->update(name,rate);
            }
            else if(selection == 4)
            {
                movies->printByYear();
            }
            else if(selection == 5)
            {
                movies->printByName();
            }
            else if(selection == 6)
            {
                movies->printByRate();
            }
            else if(selection == 7)
            {
                string filename;
                cout << "Enter filename: ";
                getline(cin,filename);
                movies->loadFile(filename);
            }
            else if(selection == 8)
            {
                string filename;
                cout << "Enter filename to save to: ";
                getline(cin,filename);
                movies->saveToFileByYear(filename);

            }
            else if(selection == 9)
            {
                string filename;
                cout << "Enter filename to save to: ";
                getline(cin,filename);
                movies->saveToFileByName(filename);

            }
            else if(selection == 10)
            {
                string filename;
                cout << "Enter filename to save to: ";
                getline(cin,filename);
                movies->saveToFileByRate(filename);

            }
    }while(selection != 0);



}
