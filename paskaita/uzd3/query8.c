#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
	char name[30];
	char surname[30];
	int course;					// year of study
	double average; 			// average grade
	
	int load; 					// number of courses
	char courses[10][30]; 		// course names
	int grades[10]; 			// course grades	
	
	char languages[100];		// spoken languages
	
} Student;


int main(int argc, char *argv[]) {
	FILE *db = NULL;
	// open database file for reading, provide a parameter or use default "db.bin"
	if (argc > 1)
		db = fopen(argv[1], "rb");
	else
		db = fopen("db.bin", "rb");
		
	if (db){							
		Student students[1000];			// all the data goes here
		int size = 0;					// how many students in database
		
		// reading data from file
		fread(&size, sizeof(int), 1, db);
		
		for (int i = 0; i < size; i++){			
			fread(&students[i], sizeof(Student), 1, db);			
		}	
		printf("%d records loaded succesfully\n", size);
		
		
		// MODIFY CODE BELOW
		
		int counterDemo = 0; // for counting students

		for (int i = 0; i < size; ++i) { 
   			Student s = students[i];
    
  			int hasCalculus = 0; 
   			int hasAlgebra = 0;
    
   			for (int j = 0; j < s.load; ++j) {
        		if (strcmp(s.courses[j], "Calculus") == 0) {
        		hasCalculus = 1;
    			}
    			if (strcmp(s.courses[j], "Algebra") == 0) {
        		hasAlgebra = 1;
    			}
			}
    
    		
   			if (hasAlgebra && hasCalculus) {
        		printf("Vardas Pavarde: %s %s\n Kursas: %d\n Vidurkis: %f\n Kursu kiekis: %d\n", 
            	s.name, s.surname, s.course, s.average, s.load);
        
        	// Print all their courses & grades
        	for (int j = 0; j < s.load; ++j) {
            	printf(" %s kurso pazymys: %d\n", s.courses[j], s.grades[j]);
        	}

        	printf(" Kalbos: %s\n\n", s.languages);

        	++counterDemo; // Count the student
    }
}		
		printf("Filter applied, %d students found\n", counterDemo); // how many passed the filters
		fclose(db);	
		
		
	} else {
		printf("File db.bin not found, check current folder\n");
	}
		
	
	
	return 0;
}