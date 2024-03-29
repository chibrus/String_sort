#define _CRT_SECURE_NO_WARNINGS

#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//--------------------------------------------------------------------
//! @param [in] pointarr Array of pointers of strings in text
//! @param [in] length Number of strings in Array of pointers
//! @param [in] outputfile The File, where result will be sent
//!
//! @note Sorting the strings of text by chars left to right nad putting them in output file
//--------------------------------------------------------------------
void firstSort(char** pointarr, unsigned int length, FILE* outputfile);



//-------------------------------------------------—
//! @param [out] n - number of symbols in file
//! @param [out] nstr - number of strings in file
//-------------------------------------------------—
int howmuchsymbolsandstrings(FILE *ONEGIN, int *nstr);



//--------------------------------------------------------------------
//! @param [in] s1 1 string
//! @param [in] s2 2 string
//!
//! @return 1 if s1 > s2, 0 if s1 = s2, -1 if s1 < s2
//!
//! @note comporator for strings starting at the first char
//--------------------------------------------------------------------
int strcmp(const char* s1, const char* s2);



//--------------------------------------------------------------------
//! @param [in] v array of pointers of strings in text
//! @param [in] left pointer of first string
//! @param [in] right pointer of last string
//!
//! @note Sorting the strings of text by chars right to left
//--------------------------------------------------------------------
void qSortFirst(char* v[], int left, int right);



//--------------------------------------------------------------------
//! @param [in] v array of pointers of strings in text
//! @param [in] a index of 1 string
//! @param [in] b index of 2 string
//!
//! @note Swapping two strings in array of pointers of strings
//--------------------------------------------------------------------
void swap(char** v, int a, int b);



int main()
{
	FILE *ONEGIN;
	FILE *outputFile;

	ONEGIN = fopen("gamlet.txt", "r+");
	outputFile = fopen("output.txt", "w+");

	assert(ONEGIN != NULL);

	int n = 0;
	int nstr = 1;
	int j = 1;

	fseek(ONEGIN, sizeof(char), SEEK_END);
	n = ftell(ONEGIN);

	assert(n != 0);

	char *buffer;
	char **strukaz;

	buffer = (char *)calloc(n,sizeof(char));
	rewind(ONEGIN);
	fread(buffer, sizeof(char), n, ONEGIN);

	strukaz = (char **)calloc(nstr, sizeof(char*));
	
	for (int i = 0; i < n; i++) 
	{
		if (buffer[i] == '\n')
		{
			buffer[i] = '\0';
			nstr++;
		}
	}

	assert(nstr != 0);

	strukaz = (char**)calloc(nstr, sizeof(char*));
	strukaz[0] = buffer;

	for (int i = 0; buffer[i] != EOF && i < n && j < nstr; i++) 
	{
		if (buffer[i] == '\0')
		{
			strukaz[j] = &buffer[i] + 1;
			j++;
		}
	}

	firstSort(strukaz, nstr, outputFile);

	fputc((int)'\n', outputFile);

	for (int i = 0; i < n; i++) 
	{
		if (buffer[i] == '\0')
		{
			fputc((int)'\n', outputFile);
		}
	}


	printf("%d\t%d\n", n, nstr);
	system("pause");
	free(strukaz);
	free(buffer);
	fclose(ONEGIN);
	fclose(outputFile);
	return 0;
}



int strcmp(const char* s1, const char* s2) 
{
	char* s1_image = (char *)s1;
	char* s2_image = (char *)s2;

	while (*s1_image != '\0' && *s2_image != '\0') 
	{
		if (*s1_image > *s2_image)
			return 1;
		else if (*s1_image < *s2_image)
			return -1;
		else 
		{
			s1_image++;
			s2_image++;
		}
	}
	return 0;
}
void firstSort(char** pointarr, unsigned int length, FILE* outputfile) 
{

	qSortFirst(pointarr, 0, (int)length - 1);

	for (unsigned int i = 0; i < length; i++)
	{
		fputs(pointarr[i], outputfile);
		fputc((int)'\n', outputfile);
	}
}

void swap(char** v, int a, int b) 
{
	char* temp;

	temp = v[a];
	v[a] = v[b];
	v[b] = temp;
}

void qSortFirst(char* v[], int left, int right) 
{
	int last = 0;
	int counter = 0;

	if (left >= right)
		return;

	swap(v, left, (left + right) / 2);

	last = left;

	for (counter = left + 1; counter <= right; counter++) 
	{
		if (strcmp(v[counter], v[left]) < 0) 
		{
			swap(v, counter, ++last);
		}
	}

	swap(v, left, last);

	qSortFirst(v, left, last - 1);
	qSortFirst(v, last + 1, right);
}
