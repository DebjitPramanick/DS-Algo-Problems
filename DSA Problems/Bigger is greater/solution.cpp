#include <bits/stdc++.h>

using namespace std;

// Complete the biggerIsGreater function below.
string biggerIsGreater(string w)
{
    int l = w.length();
    char ar[l + 1];
    int f, n;

    strcpy(ar, w.c_str());
    int i = 0;

    for (i = l - 1; i >= 0; i--)
        if (ar[i] > ar[i - 1]) break;

    if (i == 0) return "no answer";
    else{
        f = ar[i - 1];
        n = i;
        for (int j = i + 1; j < l; j++){
            if (ar[j] > f && ar[j] < ar[n]){
                n = j;
            }
        }
        swap(ar[i - 1], ar[n]);
        sort(ar + i, ar + l);
    }
    for (int m = 0; m < l; m++) w.at(m) = ar[m];
    return w;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++)
    {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
