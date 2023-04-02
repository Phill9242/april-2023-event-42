#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int	ft_return_size_longest_word (char** words)
{	
	int	 actual, longest_word = 0;

	for (int i = 0; words[i]; i++)
	{
		actual = strlen(words[i]);
		if (actual > longest_word)
			longest_word = actual;
	}
	return (longest_word);
}

char **ft_divide_args_in_words (int argc, char **argv)
{	
	char	**words = NULL;
	int		word_count = 0;

	for (int i = 1; i < argc; ++i) 
	{
		char *token = strtok(argv[i], " ");
		while (token) 
		{
			words = realloc(words, sizeof(char *) * (word_count + 2));
			words[word_count++] = token;
			token = strtok(NULL, " ");
		}
	}
	words[word_count++] = NULL;
	return (words);
}

void	ft_print_wildcards (int longest_word)
{
	for (int i = 0; i < longest_word + 4; i++)
	{
		printf("*");
	}
	printf("\n");
}

void	ft_print_frame(char **words, int longest_word)
{
	ft_print_wildcards (longest_word);

	for (int i = 0; words[i]; i++)
	{
		int word_len = strlen(words[i]);
		printf("* %s", words[i]);
		for (int j = 0; j < longest_word - word_len; j++)
		{
			printf(" ");
		}
		printf(" *\n");
	}

	ft_print_wildcards (longest_word);
}

int main (int argc, char **argv)
{	
	char	**words;
	int		longest_word;

	if (argc == 1)
		return 1;
	 
	words = ft_divide_args_in_words (argc, argv);
	longest_word = ft_return_size_longest_word (words);
	ft_print_frame (words, longest_word);
	return 0;
}