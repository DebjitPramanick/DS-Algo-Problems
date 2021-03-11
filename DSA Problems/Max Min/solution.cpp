#include <bits/stdc++.h>

using namespace std;

// Complete the maxMin function below.


int maxMin(int k, vector<int> arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int size = n-k+1;
    int a[size] = {0};
    
    for(int i=0;i<=n-k;i++){
        int dif = arr[i+k-1] - arr[i];
        a[i] = dif;
    }
    sort(a,a+size);
    return a[0];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    int result = maxMin(k, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
