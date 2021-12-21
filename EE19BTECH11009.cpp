#include<bits/stdc++.h>

using namespace std;

struct Credentials{
    string username;
    string password;
};

int hashFunction(string s){
    int ascii_sum=0;
    for(auto el:s){
        int k=el;
        k*=k;
        ascii_sum+=k;
        ascii_sum%=10000;
        ascii_sum=(ascii_sum*911)%10000;
        ascii_sum=(ascii_sum*911)%10000;
    }
    return (ascii_sum*911)%10000;
}

Credentials formatData(string data){
    int pos= data.find(",");
    Credentials fin;
    fin.username=data.substr(0,pos);
    fin.password=data.substr(pos+1);
    return fin;
}

struct HashItems{
    vector<Credentials> chain;
};

class HashTable{
    int size;
    vector<HashItems> HashEntry;
    public:
    HashTable(){
        size=10000;
        vector<HashItems> hEntry(size);
        HashEntry=hEntry;
    }
    HashTable(int s){
        size=s;
        vector<HashItems> hEntry(size);
        HashEntry=hEntry;
    }
    void insert(Credentials c){
        int HashValue=hashFunction(c.username);
        HashEntry[HashValue].chain.push_back(c);
    }

    void display(){
        for(int i=0;i<10000;++i){
            cout<<i<<":\n";
            for(auto el:HashEntry[i].chain){
                cout<<"\n\tUsername:"<<el.username;
                cout<<"\n\tPassword:"<<el.password<<"\n";
            }
        }
    }

    Credentials getCredentials(string u){
        int val=hashFunction(u);
        vector<Credentials>d=HashEntry[val].chain;
        Credentials ret;
        ret.username="";
        ret.password="";
        for(auto el:d){
            if(el.username==u){
                ret=el;
                break;
            }
        }
        return ret;
    }
};

bool checkPassword(string s, Credentials c)
{
    return (s == c.password);
}

int main(){

    cout<<"Running...\n";

    HashTable hTable;

    ifstream fin;
    fin.open("userInfo.csv");
    string data;
    while(fin>>data){
        Credentials Data=formatData(data);
        hTable.insert(Data);
    }
    fin.close();

    string u,p;
    cout<<"Enter username: ";
    cin>>u;

    Credentials Data=hTable.getCredentials(u);
    if(Data.username==""){
        cout<<"Name Not Found\n";
    }
    else{
        
        cout<<"Enter Password: ";
        cin>>p;
        if(!checkPassword(p,Data)){
            cout<<"Incorrect password\n";
        }
        else cout<<"Login successful\n";
    }

    return 0;
}