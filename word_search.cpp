#include <iostream>
#include <fstream>
#include <cctype>
#include <string.h>
using namespace std;

string recur(string p, string w, string word);

int main (int argc, char **argv) {
    ifstream fp;
    fp.open (argv[1]);

    if (!fp.is_open()) {
        cout << "Could not open file " << argv[1] << endl;
        return 1;
    }

    string strng[25001], sng[25001];
    int z=0, x=0, count[25001] = {0};

    while (!fp.eof()) {
        string temp = "\0", str;
        fp >> str;
        int len = str.size();
        for (int i=0; i<len+1; ++i) {
            if (isupper(str[i])) str[i]+=32;
            if (str[i]=='\0') {
                if (temp!=""){
                    strng[z] = temp;
                    ++z;
                }
            }
            else if (!isalpha(str[i])) {
                if (temp!="\0") {
                    strng[z] = temp;
                    temp = "\0";
                    if (str.size()==1) i=len+1;
                    ++z;
                }
            }
            else {
                temp+=str[i];
            }
        }
    }

    // for (int i=0; i<z; ++i) {
    //     cout << strng[i] << " ";
    //     cout << (int)strng[i][0] << endl;
    // }
    
    sng[0] = strng[0];
    count[0]++;
    ++x;
    for (int i=1; i<z; ++i) {
        int test=0;
        for (int j=0; j<x; ++j) {
            if (strng[i]==sng[j]) {
                test=1;
                count[j]++;
            }
        }
        if (test==0) {
            sng[x] = strng[i];
            count[x]=1;
            ++x;
        }
    }

    cout << "The number of words found in the file was " << z << endl;
    cout << "The number of distinct words found in the file was " << x << endl << endl;

    while (1) {
        string word;
        cout << "Please enter a word: ";
        cin >> word;
        int len = word.size();
        if (cin.eof()) break;

        int blarg=0;
        for (int j=0; j<len; ++j) {
            if (word[j]=='?') {
                blarg=1;
            }
            if (isupper(word[j])) word[j]+=32;
        }
        if (blarg==0) {
            int test=0;
            for (int i=0; i<x; ++i) {
                if (word==sng[i]) {
                    test=1;
                    cout << "The word " << word << " appears " << count[i] << " times in the document" << endl << endl;
                }
            }
            if (test==0) {
                cout << "The word " << word << " appears 0 times in the document" << endl << endl;
            }
        }
        else if (blarg==1) {
            int ind[len+1] = {0};
            ind[len+1]=0;
            for (int i=0; i<len; ++i) {
                if (word[i]=='?') {
                    ind[i]=2;
                }
                else {
                    ind[i]=1;
                }
            }
            
            int i=0;
            string newt;
            //ignore qmark case
            while (ind[i]!=0) {
                if (ind[i]==1) {
                    newt+=word[i];
                }
                ++i;
            }
            // int test=0;
            /*for (int i=0; i<x; ++i) {
                if (newt==sng[i]) {
                    // test=1;
                    cout << "The word " << newt << " appears " << count[i] << " times in the document" << endl;
                }
            }*/

            //use qmark case
            bool exist = false;
            for (int i=0; i<x; ++i) {
                string argo = "";
                if (newt==sng[i]) {
                    cout << "The word " << newt << " appears " << count[i] << " times in the document" << endl;
                }
                else {
                    argo = recur(word, sng[i], sng[i]);
                }
                if (argo != "") {
                    cout << "The word " << argo << " appears " << count[i] << " times in the document" << endl;
                    exist=true;
                }
            }
            if (exist==false) cout << "The word " << word << " appears 0 times in the document" << endl;
            cout << endl;
        }
    }
    return 0;
}

string recur(string p, string w, string word) {
    if (p.size()==0 && w.size()==0) {
        // cout << "equivalent" << endl;
        return word;
    }
    else if (w.size()==0) {
        // cout << "w-out" << endl;
        int po=p.size();
        for (int i=0; i<po; ++i) {
            if (p[i]!='?') return "";
        }
        return word;
    }
    else if (p.size()==0) {
        // cout << "p-out" << endl;
        return "";
    }
    if (p[0]==w[0]) {
        // cout << "equal" << endl;
        return recur(p.substr(1), w.substr(1), word);
    }
    else {
        // if (p[0]=='?') {
        //     string lorax = recur(p.substr(1), w.substr(1), word);
        //     if (lorax!="") {
        //         cout << "first ?" << endl;
        //         return word;
        //     }
        //     lorax = recur(p.substr(1), w, word);
        //     if (lorax!="") {
        //         cout << "second ?" << endl;
        //         return word;
        //     }
        //     return "";
        // }

        // if (p[0]=='?' && w.size()==1) {
        //     return word;
        // }
        if (p[0]=='?') {
            // cout << "question" << endl;
            string oboe = recur(p.substr(1), w.substr(1), word);
            if (oboe==word) return oboe; 
            oboe = recur(p.substr(1), w, word);
            if (oboe==word) return oboe;
        }
        // cout << "not-equal" << endl;
        return "";
    }
    //return "";
}