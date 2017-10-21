#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <math.h>
#include <float.h>
#include <limits.h>
#include <string.h>
#include <string>
#include <iomanip>

#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

struct Account{
    string username;
    string password;
    bool isModified;
    Account(string username, string password, bool isModified)
        : username(username), password(password), isModified(isModified){}
};

string convert(string password)
{
    for (int i = 0; i < password.length(); i++)
    {
        if (password[i] == '1')
            password[i] = '@';
        else if (password[i] == '0')
            password[i] = '%';
        else if (password[i] == 'l')
            password[i] = 'L';
        else if (password[i] == 'O')
            password[i] = 'o';
    }
    return password;
}

int main()
{
    int N;
    cin >> N;
    char username[15];
    char password[15];

    Account* new_account = NULL;

    vector<Account*> vec;
    string new_password;
    for (int i = 0; i < N; i++)
    {
        scanf("%s %s", username, password);
        new_password = convert(password);
        if (new_password != password)
        {
            new_account = new Account(username, new_password, true);
            vec.push_back(new_account);
        }
       
    }

    if (vec.empty())
    {
        if (N == 1)
            printf("There is 1 account and no account is modified\n");
        else 
            printf("There are %d accounts and no account is modified\n", N);
    }
    else
    {
        printf("%d\n", vec.size());
        for (int i = 0; i < vec.size(); i++)
            printf("%s %s\n", vec[i]->username.c_str(), vec[i]->password.c_str());
    }


    return 0;
}
