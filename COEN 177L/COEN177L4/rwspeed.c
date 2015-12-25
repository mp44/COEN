#include <sys/time.h>
#include <stdio.h>

struct timeval t1, t2, t3, t4;

int main()
{
	gettimeofday(&t1, NULL);

	FILE *fp, *fp1;
	char buffer[256];
	fp = fopen("lab4target.txt", "r+");
	fp1 = fopen("lab4source.txt", "w+");	
	fread(buffer, sizeof(buffer), 1, fp);
	gettimeofday(&t2, NULL);
	printf("Read Elapsed: %f\n", ((double)(t2.tv_usec-t1.tv_usec)/1000000)+(double)(t2.tv_sec-t1.tv_sec));
	
	gettimeofday(&t3, NULL);
	
	fwrite(buffer, sizeof(buffer),1, fp1);
	printf("file copied\n");
	fclose(fp);
	fclose(fp1);	
	gettimeofday(&t4, NULL);
		
	printf("Write Elapsed: %f\n", ((double)(t4.tv_usec-t3.tv_usec)/1000000)+(double)(t4.tv_sec-t3.tv_sec));
	printf("Total Elapsed: %f\n", ((double)(t4.tv_usec-t1.tv_usec)/1000000)+(double)(t4.tv_sec-t1.tv_sec));		       
	
return 0;
};
