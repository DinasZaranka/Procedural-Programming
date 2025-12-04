//LSP:2513680, dinas.zaranka@mif.stud.vu.lt 1 uzd 8 variantas

#include <stdio.h>

int main(){
    printf("Si programa atspausdins jusu ivestu skaiciu sekos nelyginiu nariu neigiamu skaiciu kieki\n");
    printf("Iveskite sveikuosius skaicius (programa priims skaicius tol kol neirasysite 0): \n");
    
    int num;
    int totalCount = 0;
    int taskCount = 0;
    char extra;

    while(1){
        if(scanf("%d%c", &num, &extra) != 2 || extra != '\n'){
            printf("Jusu ivestis nera sveikas skaicius, bandykite dar karta\n");
            
            //Clear the buffer after wrong input
            int discard;
            while((discard = getchar()) != '\n' && discard != EOF);
                
            continue;
        } 
        

        if(totalCount == 0 && num == 0){
            printf("0 zymi sekos pabaiga, bandykite dar karta ivesdami sveika skaiciu\n");
            continue;
        } 


        if(num == 0){
            printf("Seka pasibaige, spausdinami rezultatai: \n");
            printf("Jus ivedete %d skaiciu(-s) kurie tenkina sios uzduoties salyga\n",taskCount);
            break;
        }
        
        totalCount++;
        
        if(totalCount % 2 != 0 && num < 0){
            taskCount++;
        }

        /*
        int i=0;
        for(i; i<3; ){
            printf("%d",i);
            i++;
        }
        */
    }

    return 0;
}