#include <stdio.h>

int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg){
    while(1){
        printf("%s\n", menuTitle);
        for(int i=0; i<menuSize; i++){
            printf("%s",menuOptions[i]);
        }
        printf("%s",inputMsg);
        int userChoice = 0;
        if(scanf("%d", &userChoice) == 1){
            if(userChoice < menuSize && userChoice >= 0){
                return userChoice;
            }
        } else {
            printf("Jusu parinktis yra neteisinga, programa nori skaiciaus [0;2], bandykite dar karta!");
            scanf("%*[^\n]"); //pravalyti bufferi
            continue;
        }
    }

}

int main(){
    char menuTitle[] = "Programos meniu:\n";
    int menuSize = 3;
    char *menuOptions[] = {"0)Pradeti skaiciavimus\n", "1)Programos nustatymai\n", "2)Terminuoti programa\n"};
    char inputMsg[] = "Prasome iveskite meniu punkto numeri, kuri norite atidaryti\n";
    int result = 0;
    result = showMenu(menuTitle,menuOptions,menuSize,inputMsg);
    printf("Jusu pasirinktas meniu punktas: %s\n", menuOptions[result]);
    return 0;
}