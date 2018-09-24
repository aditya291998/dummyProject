#include<stdio.h>
#include<string.h>
#include<ctype.h>
int i,top=-1;
char stack[100];
void push(char);
void infixToPostfix();
char target[50],source[50];
char pop();
int priority(char);
int flag=1;
int main()
{

    printf("give infix exp.\n");
    scanf("%s",source);
    infixToPostfix();

    return 0;
}
int priority(char op)
{
    if(op=='%'||op=='*'||op=='/')
        return 2;
    else if(op=='+' || op=='-')
        return 1;
       else
            return -1;
}
void infixToPostfix()
{
    int i=0,j=0;
    char temp;
    //stack[++top]='(';
    while(source[i]!='\0')
    {
        if(isalpha(source[i])||isdigit(source[i]))
           {
               target[j]=source[i];
               i++;
               j++;
           }
           else if(source[i]=='(')
                    {
                        push(source[i]);
                        i++;
                    }
                else if(source[i]=='+'||source[i]=='%'||source[i]=='/'||source[i]=='*'||source[i]=='-')
                    {

                        while((top!=-1)&&(priority(source[i])<priority(stack[top])))
                        {
                            target[j]=pop();
                            j++;
                        }
                        push(source[i]);
                        i++;
                    }
                    else  if(source[i]==')')
                    {
                        while(stack[top]!='(')
                        {
                            target[j]=pop();
                            j++;
                        }
                       temp=pop();//ft parenthesis
			i++;
                    }
    }
    while(top!=-1)
    {

        target[j]=pop();

        j++;
    }
    target[j]='\0';
        printf("infix expression is\n");
    printf("%s",target);
}
char pop()
{
    char value;
    if(top==-1)
    {
        printf("stack underflow");
    }
    else
    {
        value=stack[top];
        top--;
        return value;
    }
}
void push(char value)
{
    if(top==100)
    {
        printf("stack overflow");
    }
    else
    {

        top++;
        stack[top]=value;

    }
}

