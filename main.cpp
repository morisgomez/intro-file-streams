#include <string>
#include <iostream>
#include <fstream> //library that helps us work with streams. allows us to read from files and write to files.
//fstream has data types: fstream for both reading and writing, ifstream for reading input and osfstream for writing output.
using namespace std;

int main() {
    fstream myFile; // create a fstream type with var name myFile. through this var we can access file data.

    //WRITING data to file
    myFile.open("moris1.txt", ios::out); //here we open file moris1.txt and if not exist, created. ios::out tells that we will be outputting (writing) data into the txt file.
    //let us actually put data on the txt file:
    if (myFile.is_open()) //checks if the file has been opened per line 8. if not, we cannot write data on it.
    {
        myFile << "this is line 1" << endl; //myFile stream is associated with moris1txt when opened.
        myFile << "this is line 2" << endl;
        myFile.close(); //closes file
    }

    //APPENDING data to file
    myFile.open("moris1.txt", ios::app); //to append data to exisits data, we use app instead of out. if we use out, previous data erases.
    if (myFile.is_open())
    {
        myFile << "this is line 3" << endl; //myFile stream is associated with moris1txt when opened.
        myFile << "this is line 4" << endl;
        myFile.close(); //closes file
    }

    //READING data from file
    myFile.open("moris1.txt", ios::in); //ios::in means read mode. bc we will be getting data from file to our program.
    if (myFile.is_open())
    {
        string line; //stores the line of text from file to variable
        while (getline(myFile, line)) //getline function is from string library
            //the condition goes to the file via myFile, then it stores the first line in variable line
            //the loop stops once there is no line of text to read.
        {
            cout << line << endl; //stores prints, stores, prints, value of line gets changed each iteration?
        }
        myFile.close();
    }

    //READING data file w/o while loop
    myFile.open("moris1.txt", ios::in); //ios::in means read mode. bc we will be getting data from file to our program.
    if (myFile.is_open())
    {
        string line2; //stores the line of text from file to variable
        getline(myFile, line2);//getline function is from string library
        cout << "----------" << endl << line2; //without the while loop, we just print the first line
        myFile.close();
    }
    return 0;
}
