/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int main()
{
	int total = 0;
	int i, j = 0;
	double distancia_pt = 0.0, distancia_en = 0.0;
	double frqTexto[26];
	char str[100], semEspacos[100];
	int contagem[26] = {0};
	double freq_pt[26] = {
        14.63, 1.04, 0.38, 4.99, 12.57, 1.02, 1.30, 1.28, 6.18, 0.40, 
        0.02, 2.78, 4.74, 5.05, 10.73, 2.52, 1.20, 6.53, 7.81, 4.34, 
        4.63, 1.67, 0.01, 0.21, 0.01, 0.47 // a–z
    };

    double freq_en[26] = {
        8.12, 1.49, 2.71, 4.32, 12.02, 2.30, 2.03, 5.92, 7.31, 0.10, 
        0.69, 3.98, 2.61, 6.95, 7.68, 1.82, 0.11, 6.02, 6.28, 9.10, 
        2.88, 1.11, 2.09, 0.17, 2.11, 0.07 // a–z
    };
    

	printf("Digite uma string: ");
	fgets(str, sizeof(str), stdin);

	// Remove a quebra de linha do fgets, se houver
	str[strcspn(str, "\n")] = '\0';

	// Copia apenas os caracteres que nC#o sC#o espaC'os
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] != ' ') {
			semEspacos[j++] = str[i];
		}
	}
	semEspacos[j] = '\0';

	for (int i = 0; semEspacos[i] != '\0'; i++) {
		semEspacos[i] = tolower((unsigned char)semEspacos[i]);
	}

	printf("String em minúsculas: %s\n", semEspacos);

    for (int i = 0; semEspacos[i] != '\0'; i++){
        char c = semEspacos[i];
        
        if (isalpha(c)) {
        contagem[c - 'a']++;
        }
    }
    
    
    for (int i = 0; i < 26; i++){
        total = total + contagem[i];
    }
    
    
    for (int i = 0; i < 26; i++){
        frqTexto[i] = (contagem[i] * 100)/total;
    }
    
    
    for (int i = 0; i < 26; i++) {
        distancia_pt += (frqTexto[i] - freq_pt[i]) * (frqTexto[i] - freq_pt[i]);
        distancia_en += (frqTexto[i] - freq_en[i]) * (frqTexto[i] - freq_en[i]);
    }
    
    printf("String em minúsculas: %s\n", semEspacos);
    
    if (distancia_pt < distancia_en){
        printf("É Portugues\n");
    }
    
    else{
        printf("É Ingles\n");
    }
    
    
	return 0;
}