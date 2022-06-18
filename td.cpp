#include <fstream> 
#include <iostream>
#include <cstring>
#include <cstdarg>
#include <direct.h>
#include <windows.h>

#define SAVEDIR "./.dirList"
#define dirwidth 80
#define aliaswidth 20
#define DIRSIZE MAX_PATH

using namespace std;

int write_dir();
int read_dir();
int delete_dir();
int select_dir(int);
int select_dir(string);

int main(int argc, char *argv[], char *envp[])
{
        read_dir();
        select_dir(3);

        return 0;
}

int write_dir()
{
        int i;
        string dirbuff;
        string aliasbuff;

        ofstream outFile;
        ifstream inFile;

        outFile.open(SAVEDIR, ios::app);
        if (outFile.is_open()==false) 
        {
                cout << "File open failed" << endl;
                return -1;
        }

        cout << "File dir : ";
        cin >> dirbuff;
        cout << "File alias : ";

        cin >> aliasbuff;
        outFile << aliasbuff << " ";
        outFile << dirbuff << endl;

        outFile.close();

        return 0;
}

int read_dir()
{
        ifstream inFile;
        string s;
        bool line = true;

        inFile.open(SAVEDIR);
        if(inFile.fail())
        {
                cout << "File open failed" << endl;
                return -1;
        }
        cout.width(aliaswidth/2 + 3);
        cout << "ALIAS";
        cout.width(8);
        cout << "|";
        cout.width(dirwidth/2 + 2);
        cout << "DIR" << endl;
        cout.width(dirwidth+aliaswidth+4);
        cout.fill('-');
        cout << "" << endl;
        cout.fill(' ');

        while(!inFile.eof())
        {
                inFile >> s;
                if(line)
                {
                        cout.width(aliaswidth);
                        cout << left << s;
                        line = false;
                }
                else
                {
                        cout.width(4);
                        cout << "|";
                        cout.width(dirwidth);
                        cout << s << endl;
                        line = true;
                }
        }

        inFile.close();

        return 0;
}

int delete_dir()
{
        ifstream tempFile;
        ofstream outFile;
        tempFile.open(SAVEDIR);
        if(tempFile.fail())
        {
                cout << "File open failed" << endl;
                return -1;
        }

        if(outFile.fail())
        {
                cout << "File open failed" << endl;
                return -1;
        }
        
        tempFile.close();
        outFile.close();

        return 0;
}

int select_dir(int select)
{
        ifstream inFile;
        string dir;
        char cp[DIRSIZE] = "cd ";
        int i = 0;
        inFile.open(SAVEDIR);
        if(inFile.fail())
        {
                cout << "File open failed" << endl;
                return -1;
        }

        while(i < select*2)
        {
                i++;
                inFile >> dir;
        }

        cout << dir << endl;
        system("dir");
        chdir("c:\\");
        system("dir");
        if(GetCurrentDirectory(DIRSIZE, (LPSTR)(LPCWSTR)dir.c_str()) == -1)
        {
                cout << "Dir move failed" << endl;
                return -1;
        }
        

        return 0;
}
