#include <stdio.h>
#include <ctype.h>
#include <string.h>

void cleanString(char *text) {
    text[strlen(text) - 1] = '\0';
}

int onlyLettersOrDigits(char *line) {
    printf("line--> %s\n", line);
    int i;
    int digits = 0;
    int letters = 0;
    for (i = 0; i < strlen(line); i++) {
        if (isdigit(line[i])) {
            ++digits;
        }
        if (isalpha(line[i])) {
            ++letters;
        }
    }
    return digits == strlen(line) || letters == (strlen(line));
//    int i;
//    char first = line[0];
//    if (isalpha(first)) {
//        for (i = 1; i < strlen(line); i++) {
//            if (!isalpha(line[i])) return 0;
//        }
//    } else if (isdigit(first)) {
//        for (i = 1; i < strlen(line); i++) {
//            if (!isdigit(line[i])) return 0;
//        }
//    } else {
//        return 0;
//    }
//
//    return 1;
}

int main() {
    FILE *f = fopen("/Users/bojanangjeleski/CLionProjects/untitled136/text.txt", "r");
    char line[100];
    char maxLine[100];
    int first = 1;

    while (fgets(line, 100, f) != NULL) {
        cleanString(line);
        if (onlyLettersOrDigits(line)) {
            if (first) {
                strcpy(maxLine, line);
                first = 0;
            } else {
                if (strlen(line) > strlen(maxLine)) {
                    strcpy(maxLine, line);
                }
            }
        }
    }
    if (first) {
        printf("Nema");
    } else {
        printf("%s", maxLine);
    }

    fclose(f);
    return 0;
}
/*
 Во eдна датотека text.txt се запишани низи од знаци (содржат букви, цифри и специјални знаци), секоја во посебен ред. Низите знаци, секоја за себе, не е поголема од 80 знаци.

Да се напише програма со која на стандарден излез ќе го отпечати редот со најголем број знаци, што содржи само букви или само цифри. Ако нема такви редови, се печати "Nema!". Ако има два или повеќе реда што го задоволуваат овој услов, се печати првиот ред што го задоволува условот.

Пример:

Влез:
Kfd?vsvv985%vdvfb
Ccsvsdvdfv
342425vbbcb
352!235325
gdg??dfg!!
5336346644747
8338736767867

Излез:
5336346644747
 */