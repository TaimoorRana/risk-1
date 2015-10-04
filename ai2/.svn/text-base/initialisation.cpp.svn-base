#include "initialisation.h"
#include "../shared_structures/country.h"
#include <vector>
#include <list>

using namespace std;

int CountryNB = 42;
vector<int> ourforce;

initialisation::initialisation()
{
    int i = 0, j = 0, m = 0, n = 0, s = 0, x = 0, y = 1, z = ourforce.size();
    int count = n = z;
    int c[z];

    for (int t=0; t < z; t++) {
        a[t][0] = 0;
        c[t]= 1;
    }

    c[0] = 0;
    b[0][0] = 1;

    while (count > 0) {
        s = 0;
        for (j = 0; j < n ; j++) {
            if (a[i][j] == 1) {
                s = a[i][j];

                for ( m = 0; m < n; m++)
                    a[m][j] = 0;

                count--;
                i = j;
                b[x][y] = j+1;
                y++;
                c[i] = 0;
                break;
            }

            if ((j == n-1) && (s == 0)) {
                x++;
                if (y == 0) {
                    b[x][0] = j+1;
                    c[i] = 0;
                }
                else {
                    y = 0;
                }
                count--;

                for (int d = 0; d < z; d++) {
                    if (c[d] != 0) {
                        i = d ;
                        break;
                    }
                }
            }
        }
    }
}

initialisation::~initialisation()
{

}

void initialisation::deploy(int troopNb)
{
    while(troopNb != 0)
    {

    }
}
