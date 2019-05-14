#include <iostream>
#include <string>

using namespace std; 

size_t hash_str(const string& s)
{
    size_t h = 0; 
    for(const char& c : s)
        h = h * 11 ^ c;
    return h;
}

int main()
{
    cout << hash_str("abcdef") << endl;
}