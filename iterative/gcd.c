#include <stdio.h>
int times=0;
int gcd(int a,int b){
    int r;
    if(a==0){
        printf("%d is GCD",b);

    }
    else if(b==0){
        printf("%d is GCD",a);
    }
    else{
        while(b!=0){
            r=a%b;
            a=b;
            b=r;
            times++;
        }  
    }
    return a;
}
int main(){
    int a,b,g;
    printf("Enter the two numbers:");
    scanf("%d%d",&a,&b);
    g=gcd(a,b);
    printf("The gcd of %d and %d is: %d\n", a, b, g);
    printf("No of times while loop executed is: %d",times);
    printf("Name: Krisha Dhakal\tRoll No: 8");
}

