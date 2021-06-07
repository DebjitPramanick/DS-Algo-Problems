#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the lilysHomework function below.
int lilysHomework(vector<int> v) {
    map<int,int>in,in1;
    for(int i=0;i<v.size();i++)
    {
        in[v[i]]=i;
        in1[v[i]]=i;
    }
    vector<int>v1,v2,v3,v4;
    v1=v;
    v2=v;
    v3=v;
    v4=v;
    int c1=0,c2=0;
    sort(v1.begin(),v1.end());
    sort(v3.begin(),v3.end(),greater<int>());
    for(int i=0;i<v.size();i++)
    {
        if(v1[i]!=v2[i])
        {
            int index=in1[v1[i]];
            in1[v1[i]]=i;
            in1[v2[i]]=index;
            swap(v2[i],v2[index]);
            c1++;
        }
        if(v3[i]!=v4[i])
        {
            int ind=in[v3[i]];
            in[v3[i]]=i;
            in[v4[i]]=ind;
            swap(v4[i],v4[ind]);
            c2++;
        }
    }
    if(c1<c2)
    {
        return c1;
    }
    else
    {
        return c2;
    }

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = lilysHomework(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
