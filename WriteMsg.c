#include <stdio.h>

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        printf("More argument required");
    }

    if(argc == 3)
    {
        FILE *fp = NULL;
        fp = fopen(argv[2], "r");
        char str[255];
        int i = 0;
        int lineCount = 0;
        if (fp == NULL) 
        {
            perror("Error opening file");
            return 1; 
        }
        while(fgets(str, 255, fp) != NULL)
        {
            lineCount += 1;

            if (lineCount == 1)
            { 
                if(str[0] ==  'P' && str[1] == '6')
                {
                    printf("It is a PPM FILE\n");
                }
                else
                {
                    perror("IT IS NOT A PPM FILE.\n");
                }
            }

            if(lineCount == 2)
            {
                if(str[0] == '#')
                {
                    printf("hello\n");
                    
                }
                else
                {
                    printf("%c", str[0]);
                    printf("hi\n");
                }
            }

            
        }
        fclose(fp);
    }

    
    return 0;
}