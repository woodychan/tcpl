#include <stdio.h>

#define MAXLINE 1000
#define UPPER 80

int readline(char line[], int limit);

int main() 
{
	char line[MAXLINE];
	int length;

	while((length=readline(line,MAXLINE)) > 0)
	{
		if(length > UPPER)
			printf("%s",line);
	}

	return 0;
}


int readline(char line[],int limit)
{
	int i;
	char c;
	for(i=0;i <= limit-1 && (c=getchar()) != '\n' && c != EOF; ++i)
		line[i] = c;
	if(c == '\n')
	{
		line[i] = '\n';
		++i;
	}
	line[i] = '\0';

	return i;
}
