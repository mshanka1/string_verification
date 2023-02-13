#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*
Conditions to lookout for:
CONDITION1: check if string has minimum 7 chars and maximum 15 chars.
CONDITION2: check string has 3 '.' not more not less
CONDITION3: '.' are not consiqutive
CONDITION4: value between '.' are only numeric
CONDITION5:Numeric range is between 0 to 255
*/

void validate_ip(char *);
int validate_length(char *);
int validate_string(char *);

int main()
{
    char ip1[] ="192.168.1.1";
    char ip2[] ="192.168.1.1.";
    char ip3[] ="...19216811";
    char ip4[] ="300.168.1.1";
    char ip5[] ="192.168.abc.1";
    char ip6[] ="1.1.1.1";
    char ip7[] ="1. .1.1";
    char ip8[] ="1.1.1.";
    validate_ip(ip1);
    validate_ip(ip2);
    validate_ip(ip3);
    validate_ip(ip4);
    validate_ip(ip5);
    validate_ip(ip6);
    validate_ip(ip7);
    validate_ip(ip8);

    return 0;
}

void validate_ip(char *ip)
{
    if(validate_length(ip)==1)
    {
        printf("%s is Valid IP\n",ip);
    }
    else
    {
        printf("%s is Invalid IP\n",ip);
    }
}

int validate_length(char *ip)
{
    if((strlen(ip)>6)&&(strlen(ip)<16))
    {
		//CONDITION1
        if(validate_string(ip))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

int validate_string(char *ip)
{
    int num=0;
    int param_length=0;
    int dot_count=0;
    int count =0;
    int old_count=-1;
    char param_c[2];
    param_length = strlen(ip);
    for(count=0;count<param_length;count++)
    {
        param_c[0]=ip[count];
        param_c[1]='\0';
        //printf("data got = %s\n",param_c);
        //printf("data count = %d, old = %d\n",count,old_count);
        if(param_c[0]=='.')
        {
            dot_count++;
            if(dot_count>3)
            {
                //CONDITION2
                return 0;
            }
            if((dot_count==3)&&(count<5))
            {
                //CONDITION3
                return 0;
            }
            if((count-old_count==1)&&(dot_count>1))
            {
                //CONDITION3
                return 0;
            }
            if(num>255)
            {
                //CONDITION5
                return 0;
            }
            num=0;
        }
        else
        {
            old_count++;
            if(isdigit(param_c[0])==0)
            {
                //CONDITION4
                return 0;
            }
            else
            {
                num = (num *10) + atoi(param_c);
            }
        }
    }
    //printf("Dot count = %d\n",dot_count);
    return 1;
}