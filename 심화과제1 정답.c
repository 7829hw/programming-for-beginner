#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 500

int main(void) 
{
    int data[MAXSIZE];
    int hist[10];
    int size;

    while (1) {
        printf("데이터의 개수를 입력하시오(0: 종료, 30 <= x <= 500): ");
        scanf("%d", &size);
        if (size == 0) break;
        if (size < 30 || size > 500) continue;       

        // 랜덤 데이터 생성
        srand(time(NULL));
        for (int i = 0; i < size; i++)
            data[i] = rand() % 10;

        puts("\t[원 랜덤 데이터]");
        for (int i = 0; i < size; i++) {
            printf("%5d ", data[i]);
            if (i % 10 == 9) puts("");
        }
        puts("");

        // 히스토그램 계산
        for (int i = 0; i < 10; i++)
            hist[i] = 0;
        for (int i = 0; i < size; i++)
            hist[data[i]]++;

        // 히스토그램 출력 v0.1
        puts("\t[히스토그램]");
        for (int i = 0; i < 10; i++)
		    printf("%5d | %d\n", i, hist[i]);
	    puts("");

        // 히스토그램 출력 v1.0
        puts("\t[히스토그램 v1.0]");
        for (int i = 0; i < 10; i++) {
		    printf("%5d | ", i);
		    for (int j = 0; j < hist[i]; j++)
			    printf("*");
		    puts("");
	    }
	    puts("");

        // 히스토그램 출력 v2.0
        puts("\t[히스토그램 v2.0]");
	    int max;

    	max = hist[0];
	    for (int i = 1; i < 10; i++)
		    if (max < hist[i]) max = hist[i];

	    for (int v = max + 2; v > 0; v--) {
		    printf("%5d", v);
            printf(" | ");
    		for (int j = 0; j < 10; j++) {
	    		if (v == hist[j] + 1)
		    		printf("%2d ", hist[j]);
			    else
				    printf(" %c ", (v <= hist[j]) ? '*' : ' ');
		    }
		    puts("");
    	}
	    printf("%5s", " ");
	    printf(" +-");
	    for (int j = 0; j < 10; j++)
		    printf("---");
	    puts("");

	    printf("%5s", " ");
	    printf("   ");
	    for (int j = 0; j < 10; j++)
		    printf(" %d ", j);
	    puts("");   
	    puts("");

        // 히스토그램 출력 v3.0
        puts("\t[히스토그램 v3.0]");

	    for (int v = max + 1; v > 0; v--) {
		    (v % 5 == 0) ? printf("%5d", v) : printf("%5s", " ");
    		printf(" | ");
	    	for (int j = 0; j < 10; j++) {
    			if (v <= hist[j])
    				printf("%2d ", v);
    			else
    				printf("   ");
    		}
	    	puts("");
	    }
    	printf("%5s", " ");
    	printf(" +-");
    	for (int j = 0; j < 10; j++)
    		printf("---");
    	puts("");
    
    	printf("%5s", " ");
    	printf("   ");
    	for (int j = 0; j < 10; j++)
    		printf(" %d ", j);
    	puts("");
	    puts("");

        // 히스토그램 출력 v4.0
        puts("\t[히스토그램 v4.0]");
        int sum = 0;

        for (int i = 0; i < 10; i++)
            sum += hist[i];

        for (int v = (int) (max * 50.0 / sum + 1); v > 0; v--) {
            printf("%5.2f", v / 50.0);
            printf(" | ");
            for (int j = 0; j < 10; j++) {
                if (v == (int)(hist[j] * 50.0 / sum)) printf("+-+");
                else if (v < (int)(hist[j] * 50.0 / sum)) printf("| |");
                else printf("   ");
            }
            puts("");
        }
        printf("%5s", " ");
        printf(" +-");
        for (int j = 0; j < 10; j++)
            printf("---");
        puts("");

        printf("%5s", " ");
    	printf("   ");
    	for (int j = 0; j < 10; j++)
    		printf(" %d ", j);
    	puts("");
	    puts("");

    }
    
	return 0;
}
