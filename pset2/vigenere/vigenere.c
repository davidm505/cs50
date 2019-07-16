#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        int kv[strlen(argv[1])];
        
        // Iterate through command line arg
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isalpha(argv[1][i]) == false)
            {
                printf("Usage: ./vignere keyword\n");
                return 1;
            }
            // Add char to array if alpha char
            else
            {
                if (isupper(argv[1][i]))
                {
                    kv[i] = argv[1][i] - 65;
                }
                else
                {
                    kv[i] = argv[1][i] - 97;
                }
            }
        }
        
        string p = get_string("plaintext: ");
        int cipher[strlen(p)];
        
        for (int i = 0, n = strlen(p), j = 0; i < n; i++, j = (j + 1) % strlen(argv[1]))
        {
            if (isalpha(p[i]))
            {
                if (isupper(p[i]))
                {
                    char c = (((p[i] + kv[j]) - 65) % 26) + 65;
                    cipher[i] = c;
                }
                else
                {
                    char c = (((p[i] + kv[j]) - 97) % 26) + 97;
                    cipher[i] = c;
                }
            }
            else
            {
                j -= 1;
                cipher[i] = p[i];
            }
        }
        printf("ciphertext: ");
        for (int i = 0, n = strlen(p); i < n; i++)
        {
            printf("%c", cipher[i]);
        }
        printf("\n");
        return 0;
    }
    else
    {
        printf("Usage: ./vignere keyword\n");
        return 1;
    }
}
