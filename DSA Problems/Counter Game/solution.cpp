#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'counterGame' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts LONG_INTEGER n as parameter.
 */
 
 bool isPowerOfTwo(long n){
   if(n==0)
   return false;
 
   return (ceil(log2(n)) == floor(log2(n)));
}

string counterGame(long n) {
    int c = 0;
    long low;
    
    while(n>2){
        if(!isPowerOfTwo(n)){
            low = pow(2, ceil(log2(n))-1 );
            n = n-low;
            if(n!=1 && c==0) c++;
            else if(n!=1 && c==1) c--;
        } 
        else{
            n = n/2;
            if(n!=1 && c==0) c++;
            else if(n!=1 && c==1) c--;
        }
    }
    if(c==0) return "Louise";
    return "Richard";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        long n = stol(ltrim(rtrim(n_temp)));

        string result = counterGame(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
