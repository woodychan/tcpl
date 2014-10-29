#include <stdio.h>
/* Only 0-9 && a-z counts
 * A-Z will be translate to a-z
 * Numbers of all other chars which are not blanks store to char_num[36]
 */

int main()
{
	int char_num[37]={0};
	int i,maxnums;
	char c;

	while((c=getchar()) != EOF)
	{
		if( c != ' ' && c != '\t' && c != '\n' )
		{
			if(c >= '0' && c <= '9')
				char_num[c-'0']++;
			else if (c >= 'a' && c <= 'z')
				char_num[c-'a'+10]++;
			else if (c >= 'A' && c <= 'Z')
				char_num[c-'A'+10]++;
			else
				char_num[36]++;
		}
	}

    /* The substance of the vertical histogram is printing a rectangle
	 * So need to get it's 'hight'
	 */
	for(i = 0;i < 37; ++i)
	{
		if(char_num[i] > maxnums)
			maxnums = char_num[i];
	}

	/* Print the histogram vertically */
	while(maxnums)
	{
		for(i=0; i < 37; ++i)
		{
			if(char_num[i] == maxnums)
			{
				printf("* ");
				char_num[i]--;
			}
			else
				printf("  ");
		}
		--maxnums;
		printf("\n");
	}

	for(i=0; i <37 ;++i)
	{
		if(i <= 9)
			printf("%c ", i +'0');
		else if (i <36)
			printf("%c ", i-10 + 'a');
		else
			printf("others\n");
	}
    return 0;
}
