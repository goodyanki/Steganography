#include <stdio.h>
#include <string.h>


void stego(char *s, FILE *fp)
{
    
}


int main(int argc, char *argv[])
{
    if(argc != 4)
    {
        printf("More argument required\n");
    }

    char *secret = argv[1];
    FILE *fp = NULL;
    fp = fopen(argv[2], "r");
    char str[255];
    int lineCount = 1;

    char col[] = {0};
    int colInt  = 0;
    char row[] = {0};
    int rowInt = 0;
    printf("%s\n", secret);


    if (fp == NULL) 
    {
        perror("Error opening file");
        return 1; 
    }


    while(fgets(str, 255, fp) != NULL)
    {

        if (lineCount == 1)
        { 

            if(str[0] ==  'P' && str[1] == '6')
            {
                printf("It is a PPM FILE\n");
                sleep(1);
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
                printf("Skip comment........\n");
                sleep(1);
                    
            }
            else 
            {
                colInt = 100 * (str[0] - '0') + 10 * (str[1] - '0' ) + (str[2] - '0');
                printf("cow is %d\n", colInt);
                sleep(1);
                rowInt = 100 * (str[4] - '0') + 10 * (str[5] - '0' ) + (str[6] - '0');
                printf("Row is %d\n", rowInt);
                sleep(1);
                lineCount++;
                continue;
            }

        }

        if(lineCount == 3)
        {
            
            colInt = 100 * (str[0] - '0') + 10 * (str[1] - '0' ) + (str[2] - '0');
            printf("cow is %d\n", colInt);
            sleep(1);
            rowInt = 100 * (str[4] - '0') + 10 * (str[5] - '0' ) + (str[6] - '0');
            printf("Row is %d\n", rowInt);
            sleep(1);

        }

        
        if(lineCount == 4)
        {
            if(str[0] == '2' && str[1] == '5' && str[2] =='5')
            {
                printf("The maximum is color value is 255! \n");
                sleep(1);
            }
            else
            {
                printf("The maximum value is not 255!\n");
            }


        }


        lineCount ++;

            
    }


    int image_size = colInt * rowInt * 3;
    int need_bits = strlen(secret) * 8;

    if(image_size > need_bits)
    {
        printf("Enough space to hide!\n");
        sleep(1);
    }
    else
    {
        printf("Not enogh space to hide!\n");
    }

    while(image_size > need_bits)
    {

    }



    

    fclose(fp);
    

    
    return 0;
}


