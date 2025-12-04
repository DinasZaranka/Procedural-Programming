#include <stdio.h>

int main(){
    int skaicius;
    
    printf("Si programa nustatys ar jusu ivestas skaicius yra lyginis ar nelyginis\n Prasau iveskite sveika skaiciu:\n");
    scanf("%d", &skaicius);


    char *atsakymas=(skaicius%2==0) ? "lyginis" : "nelyginis";
    printf("Jusu skaicius yra %s", atsakymas);

    return 0;
}