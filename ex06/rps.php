<?php

echo "Choose rock, paper, or scissors: ";
$user_choice = trim(fgets(STDIN));

$availabre_choices = ['rock', 'paper', 'scissors'];

$random_choice = $availabre_choices[rand(0, 2)];
if (!(in_array($user_choice, $availabre_choices)))
{
	echo	"Invalid choice. You must choose 'rock, paper, or scissors'\n
			Your choice: $user_choice \n";
	return;
}

if ($user_choice == 'rock' && $random_choice == 'scissors' ||
	$user_choice == 'paper' && $random_choice == 'rock' ||
	$user_choice == 'scissors' && $random_choice == 'paper')
	{	
		echo "Congratulations! You won! The computer chose $random_choice\n";
		return;
	}
	   

if ($user_choice == $random_choice)
{
	echo "It's a draw !\n";
	return;
}
	
echo "Sorry, you lost. The computer chose $random_choice. \n";
return;

