#include <stdio.h>
#include <string.h>
//#pragma warning(suppress : 4996)
#pragma warning(disable : 4996)

#define DIRNAME "shubh"

char slocal_path[256] = "";
char ClientPath[500] = { '\0' };
//printf("curPath[%s]\n", curPath);
//printf("newPath[%s]\n", newPath);
//printf("curDir[%s]\n", curDir);
//printf("Tok[%s]\n", Tok);
//printf("slocal_path[%s]\n", slocal_path);
int ProcessPath(char* Line)
{
	char curPath[100] = { '\0' }, newPath[100] = { '\0' }, curDir[100] = { '\0' };

	char* Tok = NULL;
	if (Line)
	{
		Tok = strtok(Line, "=");
		printf("Tok[%s]\n", Tok);
		if (Tok)
		{
			Tok = strtok(NULL, "=");
			printf("Tok[%s]\n", Tok);
			strcpy(curPath, Tok);
			printf("curPath[%s]\n", curPath);
		}
	}
	char* ptr = strrchr(Tok, '/');

	//Error Coming here because *ptr = NULL snd this causing issue with copying

	strcpy(Tok, strrchr(Tok, '/'));
	strncpy(newPath, curPath, strlen(curPath) - strlen(Tok));
	newPath[strlen(curPath) - strlen(Tok)] = '\0';
	
	printf("ptr[%s]\n", ptr);
	printf("Tok[%s]\n", Tok);
	printf("curPath[%s]\n", curPath);
	printf("NewPath 1[%s]\n", newPath);

	strcpy(curDir, strrchr(newPath, '/'));
	int diff = strlen(newPath) - strlen(curDir);
	strncpy(newPath, newPath, strlen(newPath) - strlen(curDir));
	newPath[diff] = '\0';

	printf("curDir[%s]\n", curDir);
	printf("NewPath 2[%s]\n", newPath);

	strcat(newPath, "/");
	printf("NewPath 2[%s]\n", newPath);

	if (*slocal_path == NULL)
	{
		strcat(newPath, DIRNAME);
		printf("FROM IF newPath[%s]\n", newPath);
	}
	else
	{
		printf("slocal_path[%s]\n", slocal_path);
		strcat(newPath, slocal_path);
		printf("FROM ELSE newPath[%s]\n", newPath);
	}

	strcat(newPath, Tok);
	printf("NewPath 2[%s]\n", newPath);
	strcpy(ClientPath, newPath);
	printf("ClientPath[%s]\n", ClientPath);
	strcpy(Line, newPath);
	printf("Line[%s]\n", Line);


	return 1;
}

int main()
{
	//char Line[100] = "FILE=/a/b/c/d/e/file.txt";
	char Line[100] = "FILE=a";
	ProcessPath(Line);

	return 0;
}