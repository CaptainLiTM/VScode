#include <iostream>
using namespace std;
int main()
{
    int ascore = 0;
    int bscore = 0;
    int a[200], b[200];
    int n, na, nb;
    int al = 0, bl = 0;
    cin >> n >> na >> nb;
    for (int i = 1; i <= na; i++)
        cin >> a[i];
    for (int i = 1; i <= nb; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
    {
        al++;
        bl++;
        if (al == na + 1)
            al = 1;
        if (bl == nb + 1)
            bl = 1;
        if (a[al] == 0)
        {
            if (b[bl] == 1)
                bscore++;
            if (b[bl] == 2)
                ascore++;
            if (b[bl] == 3)
                ascore++;
            if (b[bl] == 4)
                bscore++;
        }

        if (a[al] == 1)
        {
            if (b[bl] == 0)
                ascore++;
            if (b[bl] == 2)
                bscore++;
            if (b[bl] == 3)
                ascore++;
            if (b[bl] == 4)
                bscore++;
        }
        if (a[al] == 2)
        {
            if (b[bl] == 0)
                bscore++;
            if (b[bl] == 1)
                ascore++;
            if (b[bl] == 3)
                bscore++;
            if (b[bl] == 4)
                ascore++;
        }
        if (a[al] == 3)
        {
            if (b[bl] == 0)
                bscore++;
            if (b[bl] == 1)
                bscore++;
            if (b[bl] == 2)
                ascore++;
            if (b[bl] == 4)
                ascore++;
        }
        if (a[al] == 4)
        {
            if (b[bl] == 0)
                ascore++;
            if (b[bl] == 1)
                ascore++;
            if (b[bl] == 2)
                bscore++;
            if (b[bl] == 3)
                bscore++;
        }
    }
    cout << ascore << " " << bscore << endl;
    system("pause");
    return 0;
}