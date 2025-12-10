### Programa parašyta vadovaujantis šiomis taisyklėmis:

1. Kodo formatavimas
    1.1 Riestiniai skliaustai {}
    Atidaromi skliaustai rasomi toje pacioje eiluteje kaip funkcija, ar struktura
    # Geras pavyzdys
    if (*head == NULL){
        return;
    }
    # Blogas pavyzdys
    if (*head == NULL)
    {      
    return;}
    

    1.2 Tarpai
    tarpas po if,while,for,
    tarpai aplink operatorius =,<,>,==
    # Geras pavyzdys
    ```c
    if (current->next == start){
        return;
    }
    ```
    # Blogas pavyzdys
    ```c
    if(current->next==start){
    return;}
    ```
    
    1.3 Tusčios eilutės
    Tarp funkcijų turi būti viena tuščia eilutė
    # Geras pavyzdys
    ```c
    void printRecursive(Node *start, Node *current){
        printf("%d \n", current->value);
        
        if(current->next == start){
            return;
        }

        printRecursive(start, current->next);
    }
    ```
    # Blogas pavyzdys
    ```c
    void printRecursive(Node *start, Node *current){
    printf("%d \n", current->value);
    if(current->next == start){
        return;
    }
    printRecursive(start, current->next);
    }
    ```

2. Vardo taisykles
    2.1 kintamųjų pavadinimai
    – Rašomi mažosiomis raidėmis
    - Žodžiai prasideda iš didžiosios raidės
    # Geras pavyzdys
    char outputName;
    Node * newNode;
    # Blogas pavyzdys
    char Output;
    Node *tmp;
    
    
    2.2 funkcijų pavadinimai
    - Prasideda mažąja raide
    - Žodžiai prasideda iš didžiosios raidės
    - Funkcijos pavadinimas turi nusakyti, ka funkcija daro
    # Geras pavyzdys
    ```c 
    void insertEnd(Node **head, int value);
    void deleteMax(Node **head);
    void printRecursive(Node *start, Node *current);
    ```
    # Blogas pavyzdys
    ```c
    void Insert();
    void doThing();
    void prt(Node *x);
    ```
    
    2.3 Konstantų pavadinimai
    - Rašomi didžiosiomis raidėmis
    - žodžiai skiriami pabraukimu
    # Geras pavyzdys
    #define MAX_FILENAME_LEN 256
    # Blogas pavyzdys
    #define maxFile 256

    
    2.4 Sudurtiniai žodžiai privalo naudoti:
    - camelCase
    # Geras pavyzdys
    void printToFile
    # Blogas pavyzdys
    void PrintToFile
    void print_to_file

3. Failai turi buti pilnai apdorojami
    failu atidarymas privalo buti tikrinamas
    failai turi buti uzdaromi
    # Geras pavyzdys
    ```c
    FILE *input = fopen(file_name, "r");
    if (!input) {
    printf("Nepavyko atidaryti failo.\n");
    fclose(input);
    return;
    }
    ```
    # Blogas pavyzdys
    ```c
    FILE *f = fopen(file_name, "r"); //nepatikrinama
    ```