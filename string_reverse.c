#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char** argv)
{
	//Program to reverse a string
	const int BUFFER_SIZE = 100;
	char* user_input = (char*) malloc (BUFFER_SIZE*sizeof(char));
	if(user_input == NULL)
	{
		fprintf(stderr, "Memory allocation error.\n");
		exit(EXIT_FAILURE);
	}

	char* rev_string = (char*) malloc (BUFFER_SIZE*sizeof(char));
	if(rev_string == NULL)
	{
		fprintf(stderr, "Memory allocation error.\n");
		exit(EXIT_FAILURE);
	}

	//Taking the input
	fprintf(stderr, "Please enter a string to reverse.\n");
	char* check_var = fgets(user_input,BUFFER_SIZE,stdin);
	if(check_var == NULL)
	{
		fprintf(stderr,"Error reading the input");
		exit(EXIT_FAILURE);
	}

	int input_length = (int) strlen(user_input); //strlen returns a size_t
	if(input_length<0|| input_length > BUFFER_SIZE)
	{
		fprintf(stderr, "strlen returned a garbage data.\n");
		exit(EXIT_FAILURE);
	}
	input_length--; //we need to take the null terminator in account
	if(user_input[input_length] == '\n') {
		input_length--;
	}
	for(int j=0; input_length>=0; input_length--,j++)
	{
		rev_string[j]= user_input[input_length];
	}
	printf("Reversed string:  %s\n",rev_string);
}
