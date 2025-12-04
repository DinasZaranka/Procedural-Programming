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
    printf("Programa sustoja veikti tada, kai po jos ivedate skaiciu\n");
    char msg[] = "Iveskite viena standartinio srauto skaiciu: \n";
    
    int result;
    result = getPositiveNumber(msg);
    printf("Jusu ivestas skaicius: %d\n",result);


    return 0;
}