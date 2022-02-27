#include <fstream> 
#include <iostream>
#include <cstring>
#include <cstdarg>

#define SAVEDIR "./.dirList"

using namespace std;

int writeDir();
int readDir();
int delDir();

int main(int argc, char *argv[], char *envp[])
{


        return 0;
}

int writeDir()
{
        int i;
        string buff;

        ofstream outFile;
        ifstream inFile;

        outFile.open(SAVEDIR, ios::out | ios::app);
        if (outFile.is_open()==false) 
        {
                cout << "Unable to open the file" << endl;
                return -1;
        }

        cout << "File dir : ";
        
        cin >> buff;
        outFile << buff << endl;

        cout << "File alias : ";

        cin >> buff;
        outFile << buff << endl;

        outFile.close();

        return 0;
}

int readDir()
{
        ifstream inFile;

        inFile.open(SAVEDIR);
        if(inFile.fail())
        {
                cout << "Unable to open the file" << endl;
                return -1;
        }
        while(!inFile.eof())
        {
                string s;
                inFile >> s;
                cout << s << endl;
        }

        inFile.close();

        return 0;
}

int delDir()
{
        ifstream tempFile;
        ofstream outFile;
        tempFile.open(SAVEDIR);
        if(tempFile.fail())
        {
                cout << "Unable to open file" << endl;
                return -1;
        }

        if(outFile.fail())
        {
                cout << "Unable to open file" << endl;
                return -1;
        }
        
        tempFile.close();
        outFile.close();

        return 0;
}
