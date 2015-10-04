//This function allows you input number of origin army (attack army) and destination army and output the number of army left of each side, it's easy to use, enjoy it!
//In this function we use randam number and I satisfy all kinds of situations we have met 

#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <iostream>

int* Attack(int troupnumber_origin,int troupnumber_destination) {
	int i=0, j=0, t=0, dice_number=0, origin_dice[3], destination_dice[2];
	int *temp=new int[2];
	srand(time(0));
	
   if(troupnumber_origin>=3&&troupnumber_destination>=2){
		for(i=0;i<3;i++){

		origin_dice[i]=rand()%6+1;}

		if(origin_dice[0]<origin_dice[1]){
			t=origin_dice[0];origin_dice[0]=origin_dice[1];origin_dice[1]=t;
		}

		if(origin_dice[1]<origin_dice[2]){
			t=origin_dice[1];origin_dice[1]=origin_dice[2];origin_dice[2]=t;
		}

		if(origin_dice[0]<origin_dice[1]){
			t=origin_dice[0];origin_dice[0]=origin_dice[1];origin_dice[1]=origin_dice[2];
		}


		for(i=0;i<2;i++){

		destination_dice[i]=rand()%6+1;}

		if(destination_dice[0]<destination_dice[1]){
			t=destination_dice[0];destination_dice[0]=destination_dice[1];destination_dice[1]=t;
		}

        //Compare
        if(origin_dice[0]>destination_dice[0]) troupnumber_destination--;
        else troupnumber_origin--;

        if(origin_dice[1]>destination_dice[1]) troupnumber_destination--;
        else troupnumber_origin--;
    }
    
    if(troupnumber_origin==3&&troupnumber_destination==1){
		
		for(i=0;i<3;i++){
			
		origin_dice[i]=rand()%6+1;}
		
		if(origin_dice[0]<origin_dice[1]){
			t=origin_dice[0];origin_dice[0]=origin_dice[1];origin_dice[1]=t;
		}
		
		if(origin_dice[1]<origin_dice[2]){
			t=origin_dice[1];origin_dice[1]=origin_dice[2];origin_dice[2]=t;
		} 
		
		if(origin_dice[0]<origin_dice[1]){
			t=origin_dice[0];origin_dice[0]=origin_dice[1];origin_dice[1]=origin_dice[2];
		}
		
		destination_dice[0]=rand()%6+1;
		
		if(origin_dice[0]>destination_dice[0]) troupnumber_destination--;
        else troupnumber_origin--;}
        
     if(troupnumber_origin==2&&troupnumber_destination==2){
		
		for(i=0;i<2;i++){
			
		origin_dice[i]=rand()%6+1;}
		
		if(origin_dice[0]<origin_dice[1]){
			t=origin_dice[0];origin_dice[0]=origin_dice[1];origin_dice[1]=t;
		}
		
		for(i=0;i<2;i++){
			
		destination_dice[i]=rand()%6+1;}
		
		if(destination_dice[0]<destination_dice[1]){
			t=destination_dice[0];destination_dice[0]=destination_dice[1];destination_dice[1]=t;
		}
		
		if(origin_dice[0]>destination_dice[0]) troupnumber_destination--;
        else troupnumber_origin--;
        
        if(origin_dice[1]>destination_dice[1]) troupnumber_destination--;
        else troupnumber_origin--;}
        
    if(troupnumber_origin==2&&troupnumber_destination==1){
		
		for(i=0;i<2;i++){
			
		origin_dice[i]=rand()%6+1;}
		
		if(origin_dice[0]<origin_dice[1]){
			t=origin_dice[0];origin_dice[0]=origin_dice[1];origin_dice[1]=t;
		}
		
		destination_dice[0]=rand()%6+1;
		
		if(origin_dice[0]>destination_dice[0]) troupnumber_destination--;
        else troupnumber_origin--;}
    
    if(troupnumber_origin==1&&troupnumber_destination==2){
		
		origin_dice[0]=rand()%6+1;
		
		for(i=0;i<2;i++){
			
		destination_dice[i]=rand()%6+1;}
		
		if(destination_dice[0]<destination_dice[1]){
			t=destination_dice[0];destination_dice[0]=destination_dice[1];destination_dice[1]=t;
		}
		
		
		if(origin_dice[0]>destination_dice[0]) troupnumber_destination--;
        else troupnumber_origin--;}
    
    if(troupnumber_origin==1&&troupnumber_destination==1){
		
		origin_dice[0]=rand()%6+1;
		
		destination_dice[0]=rand()%6+1;
		
		if(origin_dice[0]>destination_dice[0]) troupnumber_destination--;
        else troupnumber_origin--;} 
    
        
        
		temp[0]=troupnumber_origin;
        temp[1]=troupnumber_destination;
        return temp;
}

// An example of the main function that can call this function and return the value we need 
//int main()
//{
//    int origin=7,destination=4;   
//    int* a=Attack(origin,destination);
//    std::cout<<a[0]<<" "<<a[1]<<std::endl;
//    return 0;
//}
