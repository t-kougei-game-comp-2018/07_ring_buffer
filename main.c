#include <stdio.h>
int main(int argc, char *argv[]) 
{
    char str[100];
    int a[10],i=0,j,x;
    for(j=0;j<10;j++)
        a[j]='\0';
    while(fgets(str, sizeof(str), stdin)){
        x=atoi(str);
        if(x==0){
            for(j=0;j<i;j++){
                printf("%d",a[j]);
                if(j<i-1)
                    printf(",");
            }
            printf("\n");
        }
        else if(x==-1){
            printf("%d\n",a[0]);
            for(j=0;j<i;j++)
                a[j]=a[j+1];
            a[i-1]='\0';
            i--;
        }
        else if(i<10){
            a[i]=x;
            i++;
        }
    }
    return 0;
}
