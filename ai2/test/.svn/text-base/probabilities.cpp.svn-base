#include <iostream>

using namespace std;

int main()
{
    int n = 40;
    double *proba = new double[n*n];

    for(int k = 0;k<n;k++){
        proba[k]=0.; //defender wins
        proba[k*n]=1.; //attacker wins
    }

    for(int i=1;i<n;i++){
    for(int j=1;j<n;j++){
        if(i>=3&&j>=2){proba[i*n+j /* 605 to 803, 806 to 1004, ...... 40202 to  40400 */ ] = (2890./7776.*proba[i*n+j-2]
                                                   +2275./7776.*proba[(i-2)*n+j]
                                                   +2611./7776.*proba[(i-1)*n+j-1]);}
        if(i>=3&&j==1){proba[i*n+j /* 604, 805, 1006, .... , 40201 */ ] = (855./1296.
                                                   +441./1296.*proba[(i-1)*n+j]);}
        if(i==2&&j>=2){proba[i*n+j /* 404 to 602 */] = (295./1296.*proba[i*n+j-2]
                                                   +581./1296.*proba[(i-2)*n+j]
                                                   +420./1296.*proba[(i-1)*n+j-1]);}
        if(i==2&&j==1){proba[i*n+j /* 403 */ ] = (125./216.
                                                   +91./216.*proba[(i-1)*n+j]);}
        if(i==1&&j>=2){proba[i*n+j /* 203 to 401*/ ] = (55./216.*proba[i*n+j-1]);}
        if(i==1&&j==1){proba[i*n+j /* 202 */] = (15./36.);}
       // cout<< i <<" "<< j << ": " <<proba[i*n+j]<<"\t";
    }
    cout<<endl;
    }

    int l = 3, m = 1; //our three armies and enemy 1 army
    cout<< l <<" "<< m << ": " <<proba[l*n+m]<<"\n";


  /*  n = 200;
    proba[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){

        }*/
        return 1;
}
