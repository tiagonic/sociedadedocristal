#include <stdio.h>
#include <string.h>

void printTabelaASCII() {
    for (int i = 0; i < 256; i++) {
        printf("%08b=%c\n", i, i);
    }
}

void exportarTabelaASCII() {
    char *arq = "ascii.txt";
    FILE *file = fopen(arq, "w+");
    
    fprintf(file, "%s;%s\n", "Código", "Caractere");
    for (int i = 0; i < 256; i++) {
        fprintf(file, "%08b;%c\n", i, i);
    }
    fclose(file);
}

int main(int size, char *args[]) {
    if(size > 1) {
        char *arq0 = "code.txt", *arq1 = "decode.txt";
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
