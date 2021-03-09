#include <bits/stdc++.h>
using namespace std;

string isValid(string s)
{
    int l = s.length();
    int a[26] = {0};

    for (int i = 0; i < l; i++)
        a[s[i] - 'a']++;

    int max = 0;
    int min = 1000000;

    for (int i = 0; i < 26; i++)
    {
        if (max < a[i])
            max = a[i];
        if (min > a[i] && a[i] != 0)
            min = a[i];
    }

    for (int i = 0; i < 26; i++)
    {
        if (a[i] != 0)
        {
            if (a[i] == max || a[i] == min)
                continue;
            else
                return "NO";
        }
    }

    if (max == min)
        return "YES";
    else
    {
        int fmin = 0, fmax = 0;

        for (int i = 0; i < 26; i++)
        {
            if (a[i] == max)
                fmax++;
            if (a[i] == min)
                fmin++;
        }

        if (max - min != 1)
        {
            if (min == 1 && fmin == 1)
                return "YES";
            else
                return "NO";
        }
        else
        {
            if (fmin == 1 || fmax == 1)
                return "YES";
            else
                return "NO";
        }
    }
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
