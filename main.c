/******************************************************************************

Jiye Huang - 10438990
Gustavo Kiyoshi Ikeda - 10430179
Gabriel Mires Camargo - 10436741 

*******************************************************************************/
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int main()
{
	int total = 0;
	int i, j = 0;
	double distancia_pt = 0.0, distancia_in = 0.0;
	double frqTexto[26];
	char str[100], semEspacos[100];
	int contagem[26] = {0};
	double freq_pt[26] = {
        14.63, 1.04, 0.38, 4.99, 12.57, 1.02, 1.30, 1.28, 6.18, 0.40, 
        0.02, 2.78, 4.74, 5.05, 10.73, 2.52, 1.20, 6.53, 7.81, 4.34, 
        4.63, 1.67, 0.01, 0.21, 0.01, 0.47 
    };

    double freq_en[26] = {
        8.12, 1.49, 2.71, 4.32, 12.02, 2.30, 2.03, 5.92, 7.31, 0.10, 
        0.69, 3.98, 2.61, 6.95, 7.68, 1.82, 0.11, 6.02, 6.28, 9.10, 
        2.88, 1.11, 2.09, 0.17, 2.11, 0.07 
    };
    
    // Pega o String
	printf("Digite uma string: ");
	fgets(str, sizeof(str), stdin);

    // colocar no lugar do pular linha o marcador do fim de linha(\0)
	str[strcspn(str, "\n")] = '\0';

    // enquanto não for fim do string e espaço coloca no lista
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] != ' ') {
			semEspacos[j++] = str[i];
		}
	}
    // coloca o demarcador do fim de string no fim lista
	semEspacos[j] = '\0';
    
    // transforma os elementos em minúsculo
	for (int i = 0; semEspacos[i] != '\0'; i++) {
		semEspacos[i] = tolower((unsigned char)semEspacos[i]);
	}

    // enquanto nao for fim do string e c for alphabeto adciona um no posição do char c no ascii menos o posição do char a, primeiro alphabeto,
    // que tá o posição do char c começando do a-1,b-2 e etc, então o vetor contagem conterá no posição 0 quantidade de a, no posição 1 quantidade de b e etc   
    for (int i = 0; semEspacos[i] != '\0'; i++){
        char c = semEspacos[i];
        if (isalpha(c)) {
        contagem[c - 'a']++;
        }
    }
    
    // calcular quantidade total de alphabetos no frase
    for (int i = 0; i < 26; i++){
        total = total + contagem[i];
    }
    
    //calculo do frequência de cada alphabeto no frase
    for (int i = 0; i < 26; i++){
        frqTexto[i] = (contagem[i] * 100)/total;
    }
    
    // eles fazem o calculo quão próximo o texto é do portugues ou ingles quanto o resultado do subtração entre as frquências tão zero
    // significa um alto afinidade com a língua e quanto mais longe do zero, negativo ou positivo, menor é o chance dele ser a língua
    // elevado ao quadrado é para evitar número negativo e almentar o impacto do diferença dentre frequências.
    for (int i = 0; i < 26; i++) {
        distancia_pt += (frqTexto[i] - freq_pt[i]) * (frqTexto[i] - freq_pt[i]);
        distancia_in += (frqTexto[i] - freq_en[i]) * (frqTexto[i] - freq_en[i]);
    }
    
    // quanto ele é mais "distante do ingles" comparado ao portugues , ele é mais próximo do portugues
    if (distancia_pt < distancia_in){
        printf("É Portugues\n");
    }
    
    // aqui é o inverso
    else{
        printf("É Ingles\n");
    }
    
    
	return 0;
}