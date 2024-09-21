/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merrahal <merrahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:41:56 by merrahal          #+#    #+#             */
/*   Updated: 2024/03/02 16:01:31 by merrahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void printBinary(int num) {
//     for (int i = sizeof(num) * 8 - 1; i >= 0; --i) {
//         printf("%d", (num >> i) & 1);
//     }
// }

// void printBinaryChar(char c) {
//     for (int i = 7; i >= 0; --i) {
//         printf("%d", (c >> i) & 1);
//     }
// }

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	const char	*s;
	char		*d;

	s = src;
	d = dest;
	i = 0;
	if (!d && !s)
		return (NULL);
	if (dest == src)
		return (dest);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

// should i remove the unsigned or not ? bcs nothing gonna
// happen specialy in this laptop
// int main()
// {
// 	// char tab[] = "mossab";
// 	// char tab1[] = "mossab";
// 	printf("%s\n", ft_memcpy("",NULL, 0));
// 	// printf("%s", memcpy("",NULL, 0));

// int a = 150;//01111111 11111111 11111111 11111111
// ft_memset((char )&a, 255,3);
// ft_memset((char)&a + 3, 127,1);
// }

// int main()
// {
// 	/*this laptop handels the sign extension so its
// 	never gonna happens specially in this cases
// 	that i'm trying to test*/
// 	char srctab[4] = {1,2,-1,-128};
// 	char Char_desttab[4];
// 	int Int_desttab[4];
// 	ft_memcpy(Char_desttab, srctab, sizeof(srctab));
// 	for(int i = 0; i<4 ; i++)
// 	{
// 		printf("Char_desttab  [%d] decimal --> = %d\t", i, Char_desttab[i]);
// 		printBinaryChar(Char_desttab[i]);
// 		printf("\n");
// 	}

// 	/*-----------------*/
// 	printf("-----------------\n");
// 	ft_memcpy(Int_desttab, srctab, 1);
// 	ft_memcpy(Int_desttab+1, srctab+1, 1);
// 	ft_memcpy(Int_desttab+2, srctab+2, 1);
// 	ft_memcpy(Int_desttab+3, srctab+3, 1);
// 	for(int i = 0; i<4 ; i++)
// 	{
// 		printf("Int_desttab[%d] decimal --> = %d\t", i, Int_desttab[i]);
// 		printBinary(Int_desttab[i]);
// 		printf("\n");
// 	}
// }

// int main()
// {
// 	char ptr[1] = {16};
// 	char tab[1];//00010000

// 	ft_memcpy(tab, ptr, 1);
// 	printf("%d\n", tab[0]);

// printf("ihi    --> %s\n", (char *)ft_memcpy(tab, ptr, 2));
// printf("%s\n", (char *)ft_memcpy(tab+1, ptr+1, 1));

// char ptr1[] = "hello";
// printf("%s\n", (char *)memcpy(ptr1+2, ptr1,4));
// }
// int main()
// {
// 	int s[] = {1,2,3,4};
// 	char d[50];
// 	ft_memcpy(d, s, 16);

// 	printf("%d\n", d[0]);

// 	printf("%d\n", d[4]);

// 	printf("%d\n", d[8]);

// 	printf("%d\n", d[12]);

// }

// #include <stdio.h>

// void copyBytes(unsigned char *dest, const unsigned char *src, size_t n) {
//     for (size_t i = 0; i < n; ++i) {
//         dest[i] = src[i];
//     }
// }

// int main() {
//     char srcBlock[4] = {127, -128, 255, 0};
//     char charDest[4];
//     unsigned char unsig_nedCharDest[4];

//     // Copying with char destination
//     copyBytes(charDest, srcBlock, 4);

//     // Copying with unsigned char destination
//     copyBytes(unsig_nedCharDest, srcBlock, 4);

//     // Print results
//     printf("Source Block: %d %d %d %d\n", srcBlock[0], srcBlock[1],
//srcBlock[2], srcBlock[3]);

//     printf("\nCopying to Char Dest:\n");
//     printf("Char Dest: %d %d %d %d\n", charDest[0], charDest[1], charDest[2],
//charDest[3]);

//     printf("\nCopying to Unsigned Char Dest:\n");
//     printf("Unsigned Char Dest: %u %u %u %u\n",unsig_nedCharDest[0],
//unsig_nedCharDest[1], unsig_nedCharDest[2], unsig_nedCharDest[3]);

//     return (0);
// }