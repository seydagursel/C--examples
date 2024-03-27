#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float calculateAttackPower(char type1,char type2,int strength1) {
    
    float attackpower1=strength1;
    
    
    if(type1=='F' && type2=='W') {
        attackpower1=(strength1*0.8);
 
    }
    else if(type1=='F' && type2=='G') {
        attackpower1=(strength1*2);
        
    }
    else if(type1=='W' && type2=='F') {
        attackpower1=(strength1*3);
        
    } 
    else if(type1=='W' && type2=='G') {
        attackpower1=(strength1*0.5);
        
    }
    else if(type1=='G' && type2=='F') {
        attackpower1=(strength1*0.9);
        
    }
    else if(type1=='G' && type2=='W') {
        attackpower1=(strength1*1.5);
        
    }
    else{
        attackpower1=(strength1);
       
        
    }
return attackpower1;
}

float calculateDefense(int health1,float attackpower1){
    float defense1=health1+(2*attackpower1);
  
    
    return defense1 ; 
}
int findWinner(char type1,char type2,int health1,int health2,int strength1,int strength2){
   
float attackpower1=calculateAttackPower(type1,type2,strength1);
    float attackpower2=calculateAttackPower(type2,type1,strength2);
    float defense1=calculateDefense(health1,attackpower1);
    float defense2=calculateDefense(health2,attackpower2);

    if ((defense1/attackpower2) > (defense2/attackpower1)){
        return 1;
    }
    else {
        return 2;
    }
}

int main(int argc,char const*argv[])
{
    int strength1,strength2,health1,health2;
    char type1,type2;


    
    printf("Player1 please registor your pokemon:");
    printf("\nWhat is his/her type?\n");
    scanf("%c",&type1);

    printf("What is strength?\n");
    scanf("%d",&strength1);
    printf("What is health?\n");
    scanf("%d",&health1);
    
    printf("Player1 please registor your pokemon:");
    printf("\nWhat is his/her type?\n");
    scanf(" %c",&type2);

    printf("What is strength?\n");
    scanf("%d",&strength2);
    printf("What is health?\n");
    scanf(" %d",&health2);
 

    printf("Winner is pokemon: %d",findWinner(type1,type2,health1,health2,strength1,strength2));
    return 0;
    
}