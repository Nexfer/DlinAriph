#include <stdio.h>
#include <stdlib.h>
#include "test.h"

int main(int argc, char *argv[])
{
    char *inputFirst,*inputSecond,*inputThird;
    FILE *output;
    int lenghtFirst,lenghtSecond,i,binary,module,lenghtModule;
    unsigned char *numberOne,*numberTwo,*ostatok,*numModule;
	unsigned char znak1,znak2,znak3;
	char znak;
	if (argc < 5 )
	{
		printf("\nEnter correct parameters\n");
		return 0;
	}
	if (argc == 7)
	{
		binary=1;
		module=1;
		inputThird=argv[6];
		lenghtModule = readb(&numModule,inputThird);
	}
	if (argc == 6)
	{
		if (strcmp(argv[5],"-b") == 0)
		{
			binary=1;
			module=0;
		}
		else
		{
			binary=0;
			module=1;
			inputThird=argv[5];
			lenghtModule = readd(&numModule,inputThird,&znak3);
		}
	}
	if (argc < 6)
	{
		binary=0;
		module=0;
	}
		

	inputFirst =argv[1];
        inputSecond=argv[3];

    if(!binary)
    {

        output = fopen(argv[4],"w");
    }
    else
    {
        output = fopen(argv[4],"wb");
    }

	znak=argv[2][0];
	switch(znak)
	{
		case '+' :
			if (!binary)
			{
				lenghtFirst = readd(&numberOne,inputFirst,&znak1);
				lenghtSecond = readd(&numberTwo,inputSecond,&znak2);
				turn(&numberOne);
				turn(&numberTwo);
				if ((znak1=='+')&&(znak2=='+'))
				{
					numberOne = summ(&numberOne,&numberTwo);
					turn(&numberOne);
					fprintf(output,"%s",numberOne);
					break;
				}
				if ((znak1=='-')&&(znak2=='-'))
				{
					numberOne = summ(&numberOne,&numberTwo);
					turn(&numberOne);
					fprintf(output,"-%s",numberOne);
					break;
				}
				if ((znak1=='+')&&(znak2=='-'))
				{
					if (cmp(&numberOne,&numberTwo) == 1)
					{
						numberOne = sub(&numberOne,&numberTwo);
						turn(&numberOne);
						fprintf(output,"%s",numberOne);
					}
					else
					{
						numberOne = sub(&numberTwo,&numberOne);
						turn(&numberOne);
						fprintf(output,"-%s",numberOne);
					}
					break;
				}
				if ((znak1=='-')&&(znak2=='+'))
				{
					if (cmp(&numberOne,&numberTwo) == 1)
					{
						numberOne = sub(&numberOne,&numberTwo);
						turn(&numberOne);
						fprintf(output,"-%s",numberOne);
					}
					else
					{
						numberOne = sub(&numberTwo,&numberOne);
						turn(&numberOne);
						fprintf(output,"%s",numberOne);
					}
					break;
				}
			}
			else
			{
				lenghtFirst = readb(&numberOne,inputFirst);
				lenghtSecond = readb(&numberTwo,inputSecond);
				numberOne=summb(&numberOne,&numberTwo,lenghtFirst,lenghtSecond,&lenghtFirst);
				fwrite(numberOne,lenghtFirst,1,output);
			}
			break;

		case '-' :
			if (!binary)
			{
				lenghtFirst = readd(&numberOne,inputFirst,&znak1);
				lenghtSecond = readd(&numberTwo,inputSecond,&znak2);
				turn(&numberOne);
				turn(&numberTwo);
				if ((znak1=='+')&&(znak2=='+'))
				{
					if (cmp(&numberOne,&numberTwo) == 1)
					{
						numberOne = sub(&numberOne,&numberTwo);
						turn(&numberOne);
						fprintf(output,"%s",numberOne);
					}
					else
					{
						numberOne = sub(&numberTwo,&numberOne);
						turn(&numberOne);
						fprintf(output,"-%s",numberOne);
					}
					break;
				}
				if ((znak1=='-')&&(znak2=='-'))
				{
					if (cmp(&numberOne,&numberTwo) == 1)
					{
						numberOne = sub(&numberOne,&numberTwo);
						turn(&numberOne);
						fprintf(output,"-%s",numberOne);
					}
					else
					{
						numberOne = sub(&numberTwo,&numberOne);
						turn(&numberOne);
						fprintf(output,"%s",numberOne);
					}
					break;
				}
				if ((znak1=='+')&&(znak2=='-'))
				{
					numberOne = summ(&numberOne,&numberTwo);
					turn(&numberOne);
					fprintf(output,"%s",numberOne);
					break;
				}
				if ((znak1=='-')&&(znak2=='+'))
				{
					numberOne = summ(&numberOne,&numberTwo);
					turn(&numberOne);
					fprintf(output,"-%s",numberOne);
					break;
				}
			}
			else
			{
				lenghtFirst = readb(&numberOne,inputFirst);
				lenghtSecond = readb(&numberTwo,inputSecond);
				numberOne=subb(&numberOne,&numberTwo,lenghtFirst,lenghtSecond,&lenghtFirst);
				fwrite(numberOne,lenghtFirst,1,output);
			}
			break;

		case '*' :
			if (!binary)
			{
				lenghtFirst = readd(&numberOne,inputFirst,&znak1);
				lenghtSecond = readd(&numberTwo,inputSecond,&znak2);
				turn(&numberOne);
				turn(&numberTwo);
				if (((znak1=='+')&&(znak2=='+'))||((znak1=='-')&&(znak2=='-')))
				{
					numberOne=mul(&numberOne,&numberTwo);
					turn(&numberOne);
					fprintf(output,"%s",numberOne);
				}
				else
				{
					numberOne=mul(&numberOne,&numberTwo);
					turn(&numberOne);
					fprintf(output,"-%s",numberOne);
				}
			}
			else
			{
				lenghtFirst = readb(&numberOne,inputFirst);
				lenghtSecond = readb(&numberTwo,inputSecond);
				numberOne=mulb(&numberOne,&numberTwo,lenghtFirst,lenghtSecond,&lenghtFirst);
				fwrite(numberOne,lenghtFirst,1,output);
			}
			break;

		case '/' :
			if (!binary)
			{
				lenghtFirst = readd(&numberOne,inputFirst,&znak1);
				lenghtSecond = readd(&numberTwo,inputSecond,&znak2);
				if (((znak1=='+')&&(znak2=='+'))||((znak1=='-')&&(znak2=='-')))
				{
					fprintf(output,"%s",divv(&numberOne,&numberTwo,&ostatok));
				}
				else
				{
					fprintf(output,"-%s",divv(&numberOne,&numberTwo,&ostatok));
				}
			}
			else
			{
				lenghtFirst = readb(&numberOne,inputFirst);
				lenghtSecond = readb(&numberTwo,inputSecond);
				turnb(&numberOne,lenghtFirst);
				turnb(&numberTwo,lenghtSecond);
				numberOne=divvb(&numberOne,&numberTwo,lenghtFirst,lenghtSecond,&lenghtFirst,&ostatok,&lenghtSecond);
				turnb(&numberOne,lenghtFirst);
				fwrite(numberOne,lenghtFirst,1,output);
			}
			break;

		case '%' :
			if (!binary)
			{
				lenghtFirst = readd(&numberOne,inputFirst,&znak1);
				lenghtSecond = readd(&numberTwo,inputSecond,&znak2);
				divv(&numberOne,&numberTwo,&ostatok);
				fprintf(output,"%s",ostatok);
			}
			else
			{
				lenghtFirst = readb(&numberOne,inputFirst);
				lenghtSecond = readb(&numberTwo,inputSecond);
				turnb(&numberOne,lenghtFirst);
				turnb(&numberTwo,lenghtSecond);
				divvb(&numberOne,&numberTwo,lenghtFirst,lenghtSecond,&lenghtFirst,&ostatok,&lenghtSecond);
				turnb(&ostatok,lenghtSecond);
				fwrite(ostatok,lenghtSecond,1,output);
				free(ostatok);
			}
			break;

		case '^' :
			if (!binary)
			{
				lenghtFirst = readd(&numberOne,inputFirst,&znak1);
				lenghtSecond = readd(&numberTwo,inputSecond,&znak2);
				turn(&numberOne);
				turn(&numberTwo);
				numberOne=stepen(&numberOne,&numberTwo,&znak1);
				turn(&numberOne);
				if (znak1=='+')
					fprintf(output,"%s",numberOne);
				else
					fprintf(output,"-%s",numberOne);
			}
			else
			{
				lenghtFirst = readb(&numberOne,inputFirst);
				lenghtSecond = readb(&numberTwo,inputSecond);
				numberOne=stepenb(&numberOne,&numberTwo,lenghtFirst,lenghtSecond,&lenghtFirst);
				fwrite(numberOne,lenghtFirst,1,output);
			}
			break;
		default:
			break;
	}

    fclose(output);

	if (module)
	{
		if(!binary)
		{
			output = fopen(argv[4],"w");
			divv(&numberOne,&numModule,&ostatok);
			fprintf(output,"%s",ostatok);
		}
		else
		{
			output = fopen(argv[4],"wb");
			turnb(&numberOne,lenghtFirst);
			turnb(&numModule,lenghtModule);
			divvb(&numberOne,&numModule,lenghtFirst,lenghtModule,&lenghtFirst,&ostatok,&lenghtModule);
			turnb(&ostatok,lenghtModule);
			fwrite(ostatok,lenghtModule,1,output);
		}
		fclose(output);
	    
	}
    return 0;
}
