#include<bits/stdc++.h>
using namespace std;
int main()
{
    if(system("diff ./liu.out ./std.out"))
    {
        puts("ok!");
    }
    else puts("shit!");
    return 0; 
}