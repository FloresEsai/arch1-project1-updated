#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "tokenizer.h"
#include "history.h"

/*
    The following is a simple testing script with a single example of input
    your code is expected to handle. The testing of your code should be more
    thorough and explore other input cases.
*/

#define TEST_TOKENIZER 1
#define TEST_HISTORY 1

/* MinUnit: http://www.jera.com/techinfo/jtns/jtn002.html */
#define mu_assert(message, test) do { if (!(test)) return message; } while (0)
#define mu_run_test(test) do { char *message = test(); tests_run++; if (message) return message; } while (0)

int tests_run;

/* Tokenizer test cases */
static char* test_string_length(const char* str) {
    assert(string_length(str) == (int)strlen(str));
    return 0;
}
static char* test_is_valid_character(int c) {
    assert(is_valid_character(c) == (c == ' ' ? 0 : 1));
    return 0;
}

static char* test_find_word_start(const char* str) {
    assert(find_word_start(str) == (str + (strspn(str, " ") + 1)));
    return 0;
}

static char* test_find_word_terminator(const char* str) {
    char* empty = "";
    assert(find_word_terminator(str) == (str + (strcspn(str, " ") + 1)));
    assert(find_word_terminator(empty) == empty);
    return 0;
}

static char* test_count_words(const char* str) {
    assert(count_words(str) == count_words_in_string(str));
    return 0;
}

static char** test_tokenize(const char* str) {
    char** tokens = tokenize(str);
    assert(strcmp(tokens[0], "happy") == 0);
    assert(strcmp(tokens[1], "happy") == 0);
    assert(strcmp(tokens[2], "joy") == 0);
    assert(strcmp(tokens[3], "joy") == 0);
    free_tokens(tokens);
    return 0;
}

/* History test cases */
static char* test_add_history(List* list, const char* str) {
    assert(list == init_history());
    add_history(list, str);
    assert(strcmp(list->root->str, str) == 0);
    add_history(list, "joy");
    assert(strcmp(list->root->next->str, "joy") == 0);
    return 0;
}

static char* test_get_history(List* list, int index) {
    assert(get_history(list, 1) != NULL);
    assert(strcmp(get_history(list, 1), "happy") == 0);
    return 0;
}

static char* all_tests() {
    if (TEST_TOKENIZER) {
        mu_run_test(test_string_length);
        mu_run_test(test_is_valid_character);
        mu_run_test(test_find_word_start);
        mu_run_test(test_find_word_terminator);
        mu_run_test(test_count_words);
        mu_run_test(test_tokenize);
    }

    if (TEST_HISTORY) {
        List* list = init_history();
        mu_run_test(test_add_history, list, "happy");
        mu_run_test(test_get_history, list, 1);
        free_list(list);
    }

    return 0;
}

int main(int argc, char** argv) {
    char* result = all_tests();

    if (result != 0)
        printf("Failed test: %s\n", result);
    else
        printf("ALL TESTS PASSED\n");

    printf("Tests run: %d\n", tests_run);

    return result != 0;
}