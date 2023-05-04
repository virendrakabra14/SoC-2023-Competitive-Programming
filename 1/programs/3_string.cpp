#include <bits/stdc++.h>
using namespace std;

int main() {

    string s="abcd";
    s.push_back('e');       // '' for characters, "" for strings

    // print string as `cout << s`

    cout << "string s:\t";
    for (int i=0; i<(int)s.length(); i++) {      // length()
        cout << s[i];       // indexing
    }
    cout << "\n";

    s.pop_back();

    
    char * cptr = new char[s.length()+1];       // +1 for '\0'
    strcpy(cptr, s.c_str());
    cout << "char array:\t" << cptr << "\n";

    string s1(cptr);    // initialize by char array
    // also, string assignments work `s1 = s;` (creates a copy)

    // same iterators
    cout << "string s1:\t";
    for (string::iterator it=s1.begin(); it!=s1.end(); it++) {
        cout << *it;
    }
    cout << "\n";

    string s2 = "qwerty";
    sort(s2.begin(), s2.end());      // sorts characters
    reverse(s2.begin(), s2.end());
    cout << "s2:\t" << s2 << "\n";

    // find
    string s3 = "abcdaef";
    cout << s3.find('a') << '\n';
    cout << s3.find('a', 2) << '\n';
    cout << (s3.find('z') == string::npos) << '\n';

    // substring
    cout << s3.substr(2) << '\n';
    cout << s3.substr(2, 3) << '\n';    // start at 2, len 3

}