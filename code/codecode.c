/*
 ==================================================================================================
 Nome        : codecode.c
 Data        : 11 de março de 2024
 Autor       : Tiago Barreto dos Santos
 Email       : tiagonic@gmail.com
 Instagram   : @tiagonic
 GitHub      : https://github.com/tiagonic/sociedadedocristal.git
 Descrição   : Este programa codifica e decodifica textos utilizando a tabela ASCII.
 Compilação  : gcc codecode.c -o codecode -lm
 Uso         : ./codecode [-c] [-f arquivo] [código]
 Exemplo     : ./codecode -f arquivo-com-o-codigo.txt .
 ==================================================================================================
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

void printTabelaASCII() {
    for (int i = 32; i < 127; i++) {
        printf("%3d %c %08b\n", i, i, i);
    }
}

void exportarTabelaASCII() {
    char *arq = "saida/ascii.txt";
    FILE *file = fopen(arq, "w+");
    
    fprintf(file, "%s;%s;%s\n", "Decimal", "Caractere", "Binário");
    for (int i = 32; i < 127; i++) {
        fprintf(file, "%d;%c;%08b\n", i, i, i);
    }
    fclose(file);
}

int main(int size, char *args[]) {
    int opt = -1;
    char *code = NULL;
    
    if(size > 1) {
        
        while ((opt = getopt(size, args, "hcf:")) != -1) {
            switch (opt) {
                case 'h':
                    printf("Opções:\n");
                    printf("\t-h: Ajuda\n");
                    printf("\t-c: Codifica para binários\n");
                    printf("\t-f: Informe o arquivo com os códigos binários\n");
                    exit(0);
                    break;
                case 'c':
                    
                    if (optind < size) {
                        
                        char *arq0 = "saida/code0.txt", *arq1 = "saida/code1.txt";
                        FILE *file0 = fopen(arq0, "w+"), *file1 = fopen(arq1, "w+");
                            
                        while(optind < size) {
                            code = args[optind];
                            for(int  i= 0; i < strlen(code); i++) {
                                fprintf(file0, "%08b", code[i]);
                                fprintf(file1, "%c = %08b\n", code[i], code[i]);
                            }
                            optind++;
                        }
                        
                        fprintf(file0, "\n");
                        fclose(file0);
                        fclose(file1);
                    
                    } else {
                        printf("Entre com um texto.\n");
                    }
                    
                    break;
                    
                case 'f':
                    
                    char *arqIn = optarg;
                    FILE *entrada = fopen(arqIn, "r");
                    if(entrada == NULL) {
                        printf("Erro ao tentar abrir arquivo.\n");
                        exit(1);
                    }
                    char *arqOut = "saida/decode.txt";
                    FILE *saida = fopen(arqOut, "w+");
                    
                    char c = -1;
                    int i = 0, exp = 7, n = 0;
                    
                    while((c = fgetc(entrada)) != EOF) {
                    
                        if(c=='0' || c=='1') {
                            i++;
                            n += pow(2, exp)*(c=='1'?1:0);
                            exp--;
                            
                            if( i>7 ) {
                                printf("%c", n);
                                fprintf(saida, "%c", n);
                                n=0;
                                i=0;
                                exp=7;
                            }
                        }
                    }
                    
                    printf("\n");
                    fprintf(saida, "\n");
                    fclose(saida);
                    fclose(entrada);
                
                    break;
                default:
                    fprintf(stderr, "Opções válidas: %s [-hc] [-f] [arquivo] [caracteres]\n", args[0]);
                    exit(1);
            }
        }
        
    } else {
        printTabelaASCII();
        exportarTabelaASCII();
    }
    return 0;
}
