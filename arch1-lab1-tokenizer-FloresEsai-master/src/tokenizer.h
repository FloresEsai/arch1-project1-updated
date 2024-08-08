#ifndef _TOKENIZER_
#define _TOKENIZER_

#include <stdbool.h>

/**
 * Returns true (non-zero) if c is a whitespace character ('\t' or ' ').
 * Zero terminators are not printable (therefore false).
 *
 * @param c The character to check.
 * @return True if c is a whitespace character, false otherwise.
 */
bool space_char(char c);

/**
 * Returns true (non-zero) if c is a non-whitespace character (not tab or space).
 * Zero terminators are not printable (therefore false).
 *
 * @param c The character to check.
 * @return True if c is a non-whitespace character, false otherwise.
 */
bool non_space_char(char c);

/**
 * Returns a pointer to the first character of the next space-separated word in zero-terminated str.
 * Return a zero pointer if str does not contain any words.
 *
 * @param str The string to search for words.
 * @return A pointer to the first character of the next word, or NULL if there are no more words.
 */
char* word_start(const char* str);

/**
 * Returns a pointer terminator char following *word.
 *
 * @param word The word to find the terminator for.
 * @return A pointer to the terminator character.
 */
char* word_terminator(const char* word);

/**
 * Counts the number of words in the string argument.
 *
 * @param str The string to count words in.
 * @return The number of words in the string.
 */
int count_words(const char* str);

/**
 * Returns a freshly allocated new zero-terminated string containing <len> chars from <inStr>.
 *
 * @param inStr The string to copy.
 * @param len The number of characters to copy.
 * @return A freshly allocated new zero-terminated string containing <len> chars from <inStr>.
 */
char* copy_str(const char* inStr, short len);

/**
 * Returns a freshly allocated zero-terminated vector of freshly allocated space-separated tokens from zero-terminated str.
 *
 * For example, tokenize("hello world string") would result in:
 *   tokens[0] = "hello"
 *   tokens[1] = "world"
 *   tokens[2] = "string"
 *   tokens[3] = NULL
 *
 * @param str The string to tokenize.
 * @return A freshly allocated zero-terminated vector of freshly allocated space-separated tokens.
 */
char** tokenize(const char* str);

/**
 * Prints all tokens.
 *
 * @param tokens The tokens to print.
 */
void print_tokens(char** tokens);

/**
 * Frees all tokens and the vector containing them.
 *
 * @param tokens The tokens to free.
 */
void free_tokens(char** tokens);

#endif