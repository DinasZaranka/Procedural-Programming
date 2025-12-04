#include <stdio.h>
#include <string.h>

int main(){
    printf("Si programa patikrina jusu ivesta el. pasto adresa, ir tuo atveju kai jis teisingas ji issaugo faile emails.txt\n");
    char user[50];
    char domain[50];
    char tld[10];
    while(1){

        if(scanf("%49[^@]%49[^.]%9s",user,domain,tld) != 3){
            printf("Jus ivedete netinkamo formato el.pasto adresa. Bandykite dar karta\n");
            while(getchar() != '\n');
            continue;
        }
        
        //check at symbols
        int atCount = 0;
        for(int i=0; i<strlen(domain); i++){
            if(domain[i] == '@'){
                atCount++;
            }
        }
        //check dot count
        int dotCount = 0;
        for(int i=0; i<strlen(tld); i++){
            if(tld[i] == '.'){
                dotCount++;
            }
        }
        int validEmail = 0;
        if(strlen(user) >= 1){
            if(strlen(domain) > 1 && atCount == 1){
                if(strlen(tld) > 1 && dotCount == 1){
                    validEmail=1;
                    printf("Jusu el pasta tinka reikalavimus!\n");
                }
            }
        }

        if(validEmail == 1){
            printf("Jusu pasto domenas: %s%s\n",domain,tld);
            printf("Jusu el. pastas issaugotas emails.txt faile\n");
            break;
        } else {
            printf("Jus ivedete neteisinga el.pasto adresa,bandykite dar karta\n");
            continue;
        }
    }

    //writing emails into file
    FILE *myFile;
    myFile = fopen("emails.txt", "a");
    if(myFile != NULL){
        fprintf(myFile, "%s%s%s\n",user,domain,tld);
    } else {
        printf("Programa nesugebejo atidaryti failo!\n");
    }


    return 0;
}