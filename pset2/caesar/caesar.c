#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        // Check that every char is a digit
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isalpha(argv[1][i]))
            {
                printf("Usage: ./caesar key \n");
                return 1;
            }
        }
            
        // Converts string to int
        int key = atoi(argv[1]);
        
        string pt = get_string("plaintext: ");
        int cipher[strlen(pt)];
        for (int i = 0; i < strlen(pt); i++)
        {
            if (isalpha(pt[i]))
            {
                int sum = pt[i] + key;
                
                // Check if current index char is upper
                if (isupper(pt[i]))
                {
                    // Check if loopback is necessary
                    if (sum > 90)
                    {
                        char n = ((sum - 65) % 26) + 65;
                        cipher[i] = n;
                    }
                    else
                    {
                        cipher[i] = sum;
                    }
                }
                else
                {
                    // Check if loopback is necessary
                    if (sum > 122)
                    {
                        char n = ((sum - 97) % 26) + 97;
                        cipher[i] = n;
                    }
                    else
                    {
                        cipher[i] = sum;
                    }
                }
                
            }
            // Current index char is not apart of alphabet - ignore
            else
            {
                cipher[i] = pt[i];
            }
        }
        printf("ciphertext: ");
        for (int i = 0, n = strlen(pt); i < n; i++)
        {
            printf("%c", cipher[i]);
        }
        printf("\n");
        return 0;
    }
    else 
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }
}
