#include "ft_printf.h"
#include	<stdio.h>

int main(void)
{
    char chara = 'o';
    char chare = 'a';
    char charu = '\0';
    int number = -3478214;
    int nub    = 21345;
    unsigned int a = 4294967295;
    char *null_str = NULL;
    char *p;
    
    
    ft_printf("%c qualquer, %s teste %c novo %c%c\n\n", chara, "bem marromenos dessa vez", chare, charu, charu);
    ft_printf("Int negativo = %d\n", number);
    ft_printf("Int positivo = %d\n", nub);
    ft_printf("Unsigned int = %u\n", a);
    ft_printf("Imprimindo porcentagem%%%%% asdasda\n%");
    ft_printf("Imprimindo x = %x\n", 26);
    ft_printf("Imprimindo X = %X\n", 26);
    ft_printf("%s\n", null_str);
    ft_printf("%p endereço bugado\n", &p);
	ft_printf("%s", "");
   
    return (0);
}
