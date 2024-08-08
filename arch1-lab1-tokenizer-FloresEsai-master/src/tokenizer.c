#include <stdio.h>
#include <stdlib.h>
#include <tokenizer.h>
#include <history.h>

int space_char(char c)
{
    /* we check if the current char in the string is a white space */
    return c == ' ' || c == '\t' ? 1:0;
}


int non_space_char(char c)
{
    /* Check if the current char in the string is not a white space */
    return c != ' ' && c != '\t' && c != '\0';
}


char* word_start(char* str)
{
    while (isspace(*str)) {
        str++;
    }
    return str;
}


char* word_terminator(char* word)
{
    return strchr(word, ' ');
}


int count_words(char* str)
{
    int count = 0;
    int inWord = 0;

    while (*str) {
        if (non_space_char(*str)) {
            if (!inWord) {
                count++;
                inWord = 1;
            }
        }
        else {
            inWord = 0;
        }
        str++;
    }

    return count;
}


char* copy_str(const char* inStr, short len) {
    char* copy_of_string = malloc((len + 1) * sizeof(char));
    memcpy(copy_of_string, inStr, len);
    copy_of_string[len] = '\0';
    return copy_of_string;
}


char** tokenize(char* str)
{
    int word_count = count_words(str);
    char** tokens = malloc((word_count + 1) * sizeof(char*));

    char* start = str;
    char* end = str;
    int i = 0;

    while (*str && i < word_count) {
        while (*str && isspace(*str)) {
            str++;
        }
        start = str;
        while (*str && !isspace(*str)) {
            str++;
        }
        end = str;

        int len = end - start;
        tokens[i] = malloc((len + 1) * sizeof(char));
        strncpy(tokens[i], start, len);
        tokens[i][len] = '\0';

        i++;
    }

    tokens[i] = NULL;
    return tokens;
}


void print_tokens(char** tokens)
{
    while (*tokens) {
        printf("%s\n", *tokens);
        tokens++;
    }
}


void free_tokens(char** tokens)
{
	if (tokens != NULL)
	{
		int index = 0;
		while (tokens[index] != NULL)
		{
			free(tokens[index]);
			index++;
		}
		free(tokens);
	}
}