
#include <iostream>
using namespace std;

int matrix_print(int ptr[5][5], int);
int main()
{
    int k = 0, i = 0, j = 0, m = 0, s = 0, x = 0, y = 1, z = 5;
    int count = z;
    int a[5][5] = {{0,0,1,0,1},{0,0,0,1,0},{1,0,0,1,0},{0,1,0,0,0},{0,0,0,0,1}};
    int b[5][5] = {0};
    int n = count;

    matrix_print(a, z);
    cout<<("*************BBBBBBB*************\n")<<endl;
    matrix_print(b, z);

    int c[z];
    for (int t=0; t<z; t++)
        c[t]= 1;
    c[0] = 0;

    for ( k = 0; k < n; k++)
        a[k][0] = 0;
    b[0][0] = 1;
    while (count + 1)
    {
        s = 0;
            for (j = 0; j < n ; j++)
            {
                if (a[i][j] == 1)
                {
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
                if ((j == n-1) && (s == 0))
                {
                    if (y == 0)
                    {
                        x++;
                        b[x][0] = j+1;
                        count--;
                        c[i] = 0;
                    }
                    else
                    {
                        x++;
                        count--;
                        y = 0;
                    }
                    for (int d = 0;d < z;d++)
                    {
                        if (c[d] != 0)
                        {
                            i = d ;
                            break;
                        }
                    }
                }
            }
    }
    cout<<("\n")<<endl;
    matrix_print(a, z);
    cout<<("*************BBBBBBB*************\n")<<endl;
    matrix_print(b, z);
    return 0;
}


int matrix_print (int ptr[5][5], int size){

    int i = 0, j = 0;

    for ( i = 0; i < size; i++){
        for (j = 0; j < size; j++)
            cout<<(ptr[i][j])<< " ";
        cout << endl;

    }
    cout<<("\n\n")<<endl;

    return 0;
}
