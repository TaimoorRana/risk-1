#include<attack_move.h>
#include<random>
#include<time.h>

void bubble_sort(int arr[],int len) {
        int i, j, temp;
        for (i=0;i<len-1;i++)
                for (j=0;j <len-1-i;j++)
                        if (arr[j] < arr[j+1]){
                                temp=arr[j];
                                arr[j]=arr[j+1];
                                arr[j+1]=temp;
                        }
}

int min(int a, int b){
    if(a>b){
        return b;
    }
    else{
        return a;
    }
}


int* Attack_Move::attack(){
   int loss[2];
   for(int l=0;l<2;l++){
       loss[l]=0;
   }

   int attacker[3];
   int defender[2];
   for(int i=0;i<3;i++){
       srand(time(NULL));
       attacker[i]=rand()%6+1;
   }
   for(int j=0;j<2;j++){
       srand(time(NULL));
       defender[j]=rand()%6+1;
   }
   bubble_sort(attacker,origin.getArmy().getNumberOfArmys());
   bubble_sort(defender,destination.getArmy().getNumberOfArmys());

   for(k=0;k<min(origin.getArmy().getNumberOfArmys(),destination.getArmy().getNumberOfArmys());k++){
       if(attacker[k]>defender[k]){
           loss[1]++;
       }
       else{
           loss[0]++;
       }
   }
   return loss;
}

