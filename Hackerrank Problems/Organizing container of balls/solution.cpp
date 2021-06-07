#include <iostream>
using namespace std;

// Complete the organizingContainers function below.


string organizingContainers(vector<vector<int>> container)
{

    bool flag = true;
    int s = container.size();
    int balls[s] = {0};
    int cons[s] = {0};

    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            balls[i] += container[i][j];
            cons[j] += container[i][j];
        }
    }

    sort(balls, balls + s);
    sort(cons, cons + s);

    for (int i = 0; i < s; i++)
    {
        if (balls[i] != cons[i])
            flag = false;
    }

    if (flag)
        return "Possible";
    return "Impossible";
}



// Driver code


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++)
    {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> container(n);
        for (int i = 0; i < n; i++)
        {
            container[i].resize(n);

            for (int j = 0; j < n; j++)
            {
                cin >> container[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string result = organizingContainers(container);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}