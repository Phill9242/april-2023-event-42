#include <regex.h>
#include <stdio.h>

#define BLACKJACK 21
#define TRUE 1
#define FALSE 0

int   ft_check_arguments (char *cards)
{
	regex_t regex;
	int ret;
	const char *valid_cards_expression = "^[23456789TJDKA]+$";

	if (regcomp(&regex, valid_cards_expression, REG_EXTENDED))
	{	
		printf("Error at regcomp function\n");
		return FALSE;
	}
	ret = regexec(&regex, cards, 0, NULL, 0);
	if (!ret)
	{   
		regfree(&regex);
		return TRUE;
	}

	if (ret == REG_NOMATCH)
	{
		printf ("Invalid parameter.\nHere the valid characters: 2 3 4 5 6 7 8 9 T J D K A \n");
		return FALSE;
	}

	printf("Error at regexec function\n");
	return FALSE;

}

int		ft_count_card_points(char *cards)
{
	int total = 0;
	
	for (int i = 0; cards[i]; i++)
	{	
		if (cards[i] >= '2' && cards[i] <= '9')
			total += cards[i] - '0';
		else if (cards[i] == 'A')
		{	
			if (total <= 10)
				total += 11;
			else
				total += 1;
		}
		else
			total += 10;

	}
	return total;
}

int     main(int argc, char **argv)
{   
	int total_card_sum;
	if (argc != 2)
	{
		printf ("Invalid use\nUsage: ./program_name \"VALID SEQUENCE\"\n");
		return 1;
	}

	if (ft_check_arguments(argv[1]) == FALSE)
		return 1;
	total_card_sum = ft_count_card_points (argv[1]);
	switch (total_card_sum)
	{
		case (BLACKJACK):
			printf ("Blackjack!\n");
			break;
		
		default:
			printf ("%d\n", total_card_sum);
			break;
	}

	return 0;
}