#include <stdio.h>

int getPositiveNumber(char *msg){
    int num;
    while(1){
        printf("%s",msg);
        if(scanf("%d",&num) == 1){
            return num;
        } else {
            scanf("%*[^\n]"); //pravalyti bufferi
            continue;
        }
    }
    return 0;
}

int main(){
    printf("Programa atspausdina jusu ivesta teksta, ir sustoja veikti tada, kai po jos ivedate skaiciu\n");
    printf("Prasau iveskite savo pranesima:\n");
    char msg[100];
    
    fgets(msg,100,stdin);
    int result;
    result = getPositiveNumber(msg);
    printf("Jusu ivestas skaicius: %d",result);


    return 0;
}