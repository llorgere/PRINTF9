#include "libftprintf.h"
#include <stdio.h>
int		main(void)
{
	char	c;
	int		ft_p;
	int		p;

	ft_p = 0;
	p = 0;
/*	printf("%.0p, %.p", 0, 0);
	printf("%.5p", 0);
	printf("%2.9p", 1234);
	printf("%2.9p", 1234567);
	printf("%D", LONG_MIN);
	printf("{%05p}", 0);
//	printf("{%05p}", &pointer_valueLargerThanMinWidth_zeroFlag);
	printf("%S", L"米");
	printf("%S", L"我是一只猫。");
	printf("%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S",
	L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ",
	L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"");	
	printf("a%Sb%sc%S", L"我", "42", L"猫");
	printf("{%S}", NULL);
	printf("{%-15Z}", 123);
	printf("%hhC, %hhC", 0, L'米');
	printf("%hhS, %hhS", 0, L"米米");
	printf("%.3%");
	printf("\ntest de 4.1S J : [%4.1S]\n", L"Jambon");
	printf("\ntest de S : [%S]\n", L"我是一只猫。");
	printf("\ntest de 4.S : [%4.S]\n", L"我是一只猫。");
	printf("\ntest de 4.S J : [%4.S]\n", L"Jambon我是一只猫。");
	printf("\ntest de 4S : [%4S]\n", L"我是一只猫。");
	printf("\ntest de 4S J : [%4S]\n", L"Jambon我是一只猫。");
	printf("\ntest de 4.1S :[%4.1S]\n", L"我是一只猫。");
	printf("\ntest de 4.1S J :[%4.1S]\n", L"Jambon我是一只猫。");
	printf("\ntest de 4.15S :[%4.15S]\n", L"我是一只猫。");
	printf("\ntest de 4.15S J :[%4.15S]\n", L"Jambon我是一只猫。"); 
	printf("\ntest de 4.6S :[%4.6S]\n", L"我是一只猫。"); 
	printf("\ntest de 4.6S J :[%4.6S]\n", L"Jambon我是一只猫。"); 
	printf("\ntest de 4.7S :[%4.7S]\n", L"我是一只猫。"); 
	printf("\ntest de 4.7S J :[%4.7S]\n", L"Jambon我是一只猫。"); 
	printf("%15.4S", L"我是一只猫。");
	printf("[%4.15S]", L"我是一只猫。");
	printf("%.4S", L"我是一只猫。");
	printf("%15.4s", "42 is the answer");
	printf("\n%ld\n", LONG_MIN);
	printf("\n%li\n", LONG_MIN);
	printf("\n%ld\n", 9563846231258954);
	printf("%lc, %lc", L'暖', L'ح');
	printf("%ls, %ls", L"暖炉", L"لحم خنزير");
	printf("[%C]\n", L'猫');
	printf("[%C]\n", L'δ');
	printf("[%C]\n", L'요');
	printf("[%C]\n", L'莨');
	printf("[%C]\n", L'ي');
	printf("[%d]\n", L'猫');
	printf("%zi", LLONG_MIN);
	printf("%zd", LLONG_MIN);
	printf("% p|%+p", 42, 42);
	printf("{%5p}", 0);
	printf("{%-15p}", 0);
	printf("{%10R}");
	printf("{%30S}", L"我是一只猫。");
	printf("{%-30S}", L"我是一只猫。");
	printf("[%d]", printf("{%30S}", L"我是一只猫。"));
	printf("[%d]", printf("{%-30S}", L"我是一只猫。"));
	printf("%s %C %d %p %x %% %S", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير");
	printf("%s%d%p%%%S%D%i%o%O%u%U%x%X%c%C","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플');
	printf("%p", 0);
	printf("%.p, %.0p", 0, 0);
	printf("{%05.s}", 0);
	printf("{%05.%}", 0);
	printf("{%05.Z}", 0);
	printf("{%05.Z}");
	printf("{%05.S}", L"42 c est cool");
	printf("{% S}", NULL);

	printf("\nmon printf\n");
	ft_printf("%.0p, %.p", 0, 0);
	ft_printf("%.5p", 0);
	ft_printf("%2.9p", 1234);
	ft_printf("%2.9p", 1234567);
	ft_printf("%D", LONG_MIN);
	ft_printf("{%05p}", 0);
//	ft_printf("{%05p}", &pointer_valueLargerThanMinWidth_zeroFlag);
	ft_printf("%S", L"米");
	ft_printf("%S", L"我是一只猫。");
	ft_printf("%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S",
	L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ",
	L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"");	
	ft_printf("a%Sb%sc%S", L"我", "42", L"猫");
	ft_printf("{%S}", NULL);
	ft_printf("{%-15Z}", 123);
	ft_printf("%hhC, %hhC", 0, L'米');
	ft_printf("%hhS, %hhS", 0, L"米米");
	ft_printf("%.3%");
	ft_printf("\ntest de 4.1S J : [%4.1S]\n", L"Jambon");
	ft_printf("\ntest de S : [%S]\n", L"我是一只猫。");
	ft_printf("\ntest de 4.S : [%4.S]\n", L"我是一只猫。");
	ft_printf("\ntest de 4.S J : [%4.S]\n", L"Jambon我是一只猫。");
	ft_printf("\ntest de 4S : [%4S]\n", L"我是一只猫。");
	ft_printf("\ntest de 4S J : [%4S]\n", L"Jambon我是一只猫。");
	ft_printf("\ntest de 4.1S :[%4.1S]\n", L"我是一只猫。");
	ft_printf("\ntest de 4.1S J :[%4.1S]\n", L"Jambon我是一只猫。");
	ft_printf("\ntest de 4.15S :[%4.15S]\n", L"我是一只猫。");
	ft_printf("\ntest de 4.15S J :[%4.15S]\n", L"Jambon我是一只猫。"); 
	ft_printf("\ntest de 4.6S :[%4.6S]\n", L"我是一只猫。"); 
	ft_printf("\ntest de 4.6S J :[%4.6S]\n", L"Jambon我是一只猫。"); 
	ft_printf("\ntest de 4.7S :[%4.7S]\n", L"我是一只猫。"); 
	ft_printf("\ntest de 4.7S J :[%4.7S]\n", L"Jambon我是一只猫。"); 
	ft_printf("%15.4S", L"我是一只猫。");
	ft_printf("%.4S", L"我是一只猫。");
	ft_printf("%15.4s", "42 is the answer");
	ft_printf("\n%ld\n", LONG_MIN);
	ft_printf("\n%li\n", LONG_MIN);
	ft_printf("\n%ld\n", 9563846231258954);
	ft_printf("%lc, %lc", L'暖', L'ح');
	ft_printf("%ls, %ls", L"暖炉", L"لحم خنزير");
	ft_printf("[%C]\n", L'猫');
	ft_printf("[%C]\n", L'δ');
	ft_printf("[%C]\n", L'요');
	ft_printf("[%C]\n", L'莨');
	ft_printf("[%C]\n", L'ي');
	ft_printf("[%d]\n", L'猫');
	ft_printf("%zi", LLONG_MIN);
	ft_printf("%zd", LLONG_MIN);
	ft_printf("% p|%+p", 42, 42);
	ft_printf("{%5p}", 0);
	ft_printf("{%-15p}", 0);
	ft_printf("{%10R}");
	ft_printf("{%30S}", L"我是一只猫。");
	ft_printf("{%-30S}", L"我是一只猫。");
	printf("[%d]", ft_printf("{%30S}", L"我是一只猫。"));
	printf("[%d]", ft_printf("{%-30S}", L"我是一只猫。"));
	ft_printf("%s %C %d %p %x %% %S", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير");
	ft_printf("%s%d%p%%%S%D%i%o%O%u%U%x%X%c%C","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플');
	ft_printf("%p", 0);
	ft_printf("%.p, %.0p", 0, 0);
	ft_printf("{%05.s}", 0);
	ft_printf("{%05.%}", 0);
	ft_printf("{%05.Z}", 0);
	ft_printf("{%05.Z}");
	ft_printf("{%05.S}", L"42 c est cool");
	ft_printf("{% S}", NULL);
//	ft_printf("{% s}", NULL);
*/	//printf("[%d]", printf("{%30S}", L"我是一只猫。"));
//	printf("[%d]", printf("{%-30S}", L"我是一只猫。"));
//	printf("[%d]", printf("{%030S}", L"我是一只猫。"));
/*	printf("[%d]", ft_printf("{%30S}", L"我是一只猫。"));
	printf("[%d]", ft_printf("{%-30S}", L"我是一只猫。"));
	printf("[%d]", ft_printf("{%030S}", L"我是一只猫。"));
//	printf("{%030S}", L"我是一只猫。");
	ft_printf("{%030S}", L"我是一只猫。");
	printf("[%d]", printf("%S", L"米"));
	printf("[%d]", printf("%S", L"我是一只猫。"));
	printf("[%d]", printf("%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S",
	L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ",
	L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L""));
	printf("[%d]", printf("a%Sb%sc%S", L"我", "42", L"猫"));
	printf("[%d]", ft_printf("%S", L"米"));
	printf("[%d]", ft_printf("%S", L"我是一只猫。"));
	printf("[%d]", ft_printf("%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S",
	L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ",
	L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L""));
	printf("[%d]", ft_printf("a%Sb%sc%S", L"我", "42", L"猫"));
*/	//printf("[%d]", printf("%hhS, %hhS", 0, L"米米"));
//	printf("[%d]", printf("%d, %hhS", 198, L"米米"));
//	printf("[%d]", printf("%hhC, %hhC", 0, L'米'));
//	printf("[%d]", ft_printf("%hhS, %hhS", 0, L"米米"));
//	printf("[%d]", ft_printf("%hhC, %hhC", 0, L'米'));
//	printf("[%d]", printf("%S", L"我是一只猫。"));
//	printf("[%d]", ft_printf("{%S}", L"我是一只猫。"));
//	printf("[%d]", printf("%030S", L"我是一只猫。"));
//	printf("[%d]", ft_printf("{%030S}", L"我是一只猫。"));
	printf("ft_p est [%d] et p est [%d]\n", ft_p, p);
	ft_p = ft_printf("%05p", 0);
	printf("ft_p est [%d] et p est [%d]\n", ft_p, p);
	p = printf("%05p", 0);
	printf("ft_p est [%d] et p est [%d]\n", ft_p, p);
	return (0);
}
