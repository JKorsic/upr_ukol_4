#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void histogram_h (int m, int histogram[9], int invalid){
            int *p_histogram = histogram;
            int max_m = m+8;
            char retezec[100];
            sprintf(retezec, "%d", max_m);
            int max_d = (int)strlen(retezec);
            int akt_m = 0;
            for (int i = 0; i <= 8; i++)
            {
                akt_m = m + i;
                sprintf(retezec, "%d", akt_m);
                int d = (int)strlen(retezec);
                if (d < max_d)
                {
                    printf(" ");
                }
                if ( *(p_histogram + i) > 0){
                    printf("%d ", akt_m);
                }
                else{
                printf("%d", akt_m);
                }
                for (int j = 1; j <= *(p_histogram + i); j++)
                {
                    printf("#");
                }
                
                printf("\n");
            }
            if (invalid > 0){
                printf("invalid: ");
                for (int i = 1; i <= invalid; i++)
                {
                    printf("#");
                }
                printf("\n");
            }
}

void histogram_v (int histogram[9], int invalid){
            int *p_histogram = histogram;
            int max_vyskyt = 0;
            for (int i = 0; i <= 8; i++)
            {
                if (*(p_histogram + i) > max_vyskyt){
                    max_vyskyt = *(p_histogram + i);
                }
                if (invalid > max_vyskyt){
                    max_vyskyt = invalid;
                }
            }
            for (int j = max_vyskyt; j >= 1; j--)
            {
                if (invalid >= j){
                    printf("#");
                }
                else
                {
                    printf(" ");
                }
                for (int k = 0; k <= 8; k++)
                {
                if (*(p_histogram + k) >= j){
                    printf("#");
                }
                else
                {
                    printf(" ");
                }
                }
                printf("\n");
            }
            printf("i123456789\n");
            
        }


int main (){
    char typ_h;
    scanf("%c", &typ_h);
    if (typ_h != 'h' && typ_h != 'v'){
        printf("Neplatny mod vykresleni\n");
        return 1;
    }
    else{
        int n = 0;
        int m = 0;
        scanf("%d %d", &n, &m);

        int histogram[9] = {0};
        int *p_histogram = histogram;
        int invalid = 0;
        int cislo = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &cislo);
            if (cislo >= m && cislo <= m + 8){
                *(p_histogram + (cislo - m)) = *(p_histogram + (cislo - m)) + 1;
            }
            else{
                invalid++;
            }
        }
        if(typ_h == 'h'){
            histogram_h(m, histogram, invalid);
        }

        else if (typ_h == 'v')
        {
            histogram_v(histogram, invalid);
        }
    }
    

    return 0;
}