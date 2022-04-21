#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 500

int main(void)
{
    int data[MAXSIZE];
    int size;
    int max = 0; // 배열의 최댓값  
    double max_ratio = 0; // 히스토그램 비율의 최댓값

    while (1) {
        printf("\n데이터의 개수를 입력하시오 (0: 종료, 30 <= x <= 500): ");
        scanf("%d", &size);
        if (size == 0) break;
        if (size < 30) continue;
        if (size > 500) continue;

        srand(time(NULL));
        for (int i = 0; i < size; i++)
            data[i] = rand() % 10;

        puts("\t[원 랜덤 데이터]");
        for (int i = 0; i < size; i++) {
            printf("%5d", data[i]);
            if (i % 10 == 9) puts("");
        }
        puts("");

        // 히스토그램 계산
        int histo[10] = { 0 };
        for (int i = 0; i < size; i++)
            histo[data[i]]++;

        // 히스토그램 최댓값 계산
        max = histo[0];
        for (int i = 0; i < 10; i++) {
            if (histo[i] > max)
                max = histo[i];
        }

        // 히스토그램 출력
        puts("\t[히스토그램]");
        for (int j = 0; j < 10; j++)
            printf("%5d | %d\n", j, histo[j]);

        puts("");
        // 히스토그램 v1.0 출력
        puts("\t[히스토그램 v1.0]");
        for (int j = 0; j < 10; j++)
        {
            printf("%5d | ", j);
            for (int i = 0; i < histo[j]; i++)
                printf("*");
            printf("\n");
        }

        puts("");
        // 히스토그램 v2.0 출력
        puts("\t[히스토그램 v2.0]");
        for (int j = max + 2; j > 0; j--)
        {
            printf("%5d | ", j);
            for (int i = 0; i < 10; i++) {
                if (histo[i] >= j)
                    printf(" * ");
                else if (histo[i] == j - 1)
                    printf("%2d ", j - 1);
                else
                    printf("   ");
            }

            printf("\n");
        }
        printf("      +-------------------------------\n");
        printf("         0  1  2  3  4  5  6  7  8  9  \n");

        puts("");
        // 히스토그램 v3.0 출력
        puts("\t[히스토그램 v3.0]");
        for (int j = max + 1; j > 0; j--)
        {
            if (j % 5 == 0)
                printf("%5d | ", j);
            else
                printf("      | ");
            for (int i = 0; i < 10; i++) {
                if (histo[i] >= j)
                    printf("%2d ", j);
                else
                    printf("   ");
            }

            printf("\n");
        }
        printf("      +-------------------------------\n");
        printf("         0  1  2  3  4  5  6  7  8  9  \n");

        // 히스토그램 비율 계산
        double histo_ratio[10] = { 0 };
        for (int i = 0; i < 10; i++)
        {
            histo_ratio[i] = histo[i] / (double)size;
        }

        // 히스토그램 비율 최댓값 계산
        max_ratio = histo_ratio[0];
        for (int i = 0; i < 10; i++)
        {
            if (histo_ratio[i] > max_ratio)
                max_ratio = histo_ratio[i];
        }

        puts("");
        // 히스토그램 v4.0 출력
        puts("\t[히스토그램 v4.0]");
        for (double j = 1; j > 0; j -= 0.02)
        {
            if (max_ratio < j - 0.02)
                continue;
            else printf("%5.2f | ", j);

            for (int i = 0; i < 10; i++)
            {
                if (histo_ratio[i] >= j && histo_ratio[i] <= j + 0.02)
                    printf("+-+");
                else if (histo_ratio[i] > j)
                    printf("| |");
                else
                    printf("   ");
            }
            printf("\n");
        }
        printf("      +-------------------------------\n");
        printf("         0  1  2  3  4  5  6  7  8  9  \n");

    }

    return 0;
}
