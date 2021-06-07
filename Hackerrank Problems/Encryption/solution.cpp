#include <bits/stdc++.h>

using namespace std;

// Complete the encryption function below.
string encryption(string s) {
    int l = s.length();
    int r, c, index = 0;
    r = floor(sqrt(l));
    c = ceil(sqrt(l));
    
    if(r*c < l) r++;
    
    vector<vector<char>> ans(r, vector<char> (c));
    string res = "";
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            ans[i][j] = s[index];
            index++;
        }
    }
    
    for(int i=0;i<c;i++){
        for(int j=0;j<r;j++){
            char c = ans[j][i];
            if(c) res += c; 
        }
        res += ' ';
    }
    
    return res;
    

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
