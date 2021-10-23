#include <stdio.h>

int main()
{
int i,j,k,n;

for(i=1;i<=4;i++){
    for(k=1;k<=4;k++){
        n=60;
        if(k<=4-i){
            printf(" ");
        }
        else{
        printf("%c",n+(k+i));
        
        }
        
    }
    
    for(j=1;j<=4;j++){
        if(j>i){
        printf(" ");}
        else{
        printf("%d",j);} 
    }
    printf("\n"); 
}

    return 0;
}
