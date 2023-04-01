print "Enter a string: ";
my $string = <STDIN>;
chomp $string;  

my $reverse = reverse $string;

if ($string eq $reverse) {
    print "The string is a palindrome \n";
} else {
    print "The string is not a palindrome\n";
}