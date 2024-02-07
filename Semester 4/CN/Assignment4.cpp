#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> fill_code(vector<int> code_word, int r, vector<int> data_word)
{
    for (int i = 0; i < r; i++)
    {
        code_word[pow(2, i) - 1] = 20;
    }
    int x = 0;
    reverse(data_word.begin(), data_word.end());
    for (int i = 0; i < code_word.size(); i++)
    {
        if (code_word[i] == -1)
        {
            code_word[i] = data_word[x];
            x++;
        }
    }
    return code_word;
}

vector<int> remove_code(vector<int> code_word, vector<int> data_word, int r)
{
    int x = 0;
    for (int i = 0; i < code_word.size(); i++)
    {
        if (i == pow(2, x) - 1)
        {
            x++;
        }
        else
        {
            data_word.push_back(code_word[i]);
        }
    }
    reverse(data_word.begin(), data_word.end());
    return data_word;
}

vector<vector<int>> getPos(int r, int d)
{
    vector<vector<int>> pos;
    for (int i = 0; i < r; i++)
    {
        vector<int> temp;
        int x = pow(2, i) - 1;
        int flag = 0;
        while (x < r + d)
        {
            if (flag == 0)
            {
                for (int j = 0; j < pow(2, i); j++)
                {
                    if (x >= r + d)
                    {
                        break;
                    }
                    temp.push_back(x);
                    x++;
                }
                flag = 1;
            }
            else
            {
                for (int j = 0; j < pow(2, i); j++)
                {
                    x++;
                }
                flag = 0;
            }
        }
        pos.push_back(temp);
    }

    return pos;
}

vector<int> create_code(vector<int> data_word)
{
    int r = 0;
    while (pow(2, r) - r < data_word.size() + 1)
    {
        r++;
    }
    vector<int> code_word(data_word.size() + r);
    for (int i = 0; i < data_word.size() + r; i++)
    {
        code_word[i] = -1;
    }
    code_word = fill_code(code_word, r, data_word);
    vector<vector<int>> pos = getPos(r, data_word.size());
    for (int i = 0; i < r; i++)
    {
        int count = 0;
        for (int j = 0; j < pos[i].size(); j++)
        {
            if (code_word[pos[i][j]] == 1)
            {
                count++;
            }
        }
        if (count % 2 == 0)
        {
            code_word[pow(2, i) - 1] = 0;
        }
        else
        {
            code_word[pow(2, i) - 1] = 1;
        }
    }
    reverse(code_word.begin(), code_word.end());
    return code_word;
}

vector<int> solve_word(vector<int> code_word)
{
    int r = 0;
    while (pow(2, r) < code_word.size())
    {
        r++;
    }
    int d = code_word.size() - r;
    reverse(code_word.begin(), code_word.end());
    vector<int> data_word;
    vector<vector<int>> pos = getPos(r, d);
    int err = 0;
    for (int i = 0; i < r; i++)
    {
        int count = 0;
        for (int j = 0; j < pos[i].size(); j++)
        {
            if (code_word[pos[i][j]] == 1)
            {
                count++;
            }
        }
        if (count % 2 != 0)
        {
            err += pow(2, i);
        }
    }
    if (err == 0)
    {
        cout << "\nNo error found.\n";
    }
    else
    {
        cout << "\nError found at pos " << d + r - err + 1 << ".\n";
    }
    data_word = remove_code(code_word, data_word, r);
    return data_word;
}

int main()
{
    int n;
    cout << "Enter data word or code word?(0/1): ";
    cin >> n;
    if (n == 0)
    {
        vector<int> data_word;
        int x;
        cout << "Enter length of data word: ";
        cin >> x;
        cout << "Enter word: ";
        while (x--)
        {
            int a;
            cin >> a;
            data_word.push_back(a);
        }
        vector<int> code_word = create_code(data_word);
        cout << "\nCode word: \n";
        for (auto n : code_word)
        {
            cout << n << " ";
        }
    }
    else
    {
        vector<int> code_word;
        int x;
        cout << "Enter length of code word: ";
        cin >> x;
        cout << "Enter word: ";
        while (x--)
        {
            int a;
            cin >> a;
            code_word.push_back(a);
        }
        vector<int> data_word = solve_word(code_word);
        cout << "\nData word: \n";
        for (auto n : data_word)
        {
            cout << n << " ";
        }
    }
    return 0;
}