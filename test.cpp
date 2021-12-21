#include <bits/stdc++.h>

using namespace std;

class hash_table
{
    public:
    vector<string> username[10000];
    vector<string> password[10000];
};

int main()
{
    hash_table user;

    ifstream fin;
    string line;

    fin.open("userInfo.csv");

    while (getline(fin, line)) 
    {
        //int ascii_val = 0;
        cout<<line<<" F ";
        cin.ignore(10);
        // for (int i=0; i<line.length(); i++) 
        //     ascii_val += line[i];

        // user.username[ascii_val].push_back(line);

        //getline(fin, line,',');
        //cout<<line<<" password\n";

        //user.password[ascii_val].push_back(line);
    }

    fin.close();
    return 0;
}