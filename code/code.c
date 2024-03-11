#include <stdio.h>
#include <string.h>

void printTabelaASCII() {
    for (int i = 33; i < 127; i++) {
        printf("%3d %08b %c\n", i, i, i);
    }
}

void exportarTabelaASCII() {
    char *arq = "saida/ascii.txt";
    FILE *file = fopen(arq, "w+");
    
    fprintf(file, "%s;%s;%s\n", "Decimal","Binário", "Caractere");
    for (int i = 33; i < 127; i++) {
        fprintf(file, "%3d;%08b;%c\n", i, i, i);
    }
    fclose(file);
}

int main(int size, char *args[]) {
    if(size > 1) {
        char *arq0 = "saida/code.txt", *arq1 = "saida/decode.txt";
        FILE *file0 = fopen(arq0, "w+"), *file1 = fopen(arq1, "w+");
        for(int i = 1; i < size; i++) {
            for(int j = 0; j < strlen(args[i]); j++) {
                fprintf(file0, "%08b", args[i][j]);
                fprintf(file1, "%c = %08b\n", args[i][j], args[i][j]);
            }
        }
        fprintf(file0, "\n");
        fclose(file0);
        fclose(file1);
    } else {
        printTabelaASCII();
        exportarTabelaASCII();
    }
    return 0;
}
