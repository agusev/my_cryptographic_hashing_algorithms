/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 23:35:01 by agusev            #+#    #+#             */
/*   Updated: 2019/04/20 13:17:18 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ssl.h"

t_uint		*sha256_hash_cpy(t_uint *hash)
{
	int		i;
	t_uint	*tmp;

	i = 0;
	tmp = (unsigned int*)malloc(sizeof(unsigned int) * 8);
	while (i < 8)
	{
		tmp[i] = hash[i];
		i++;
	}
	return (tmp);
}

t_uint		*sha256_transform(t_uint *w, t_uint *arr)
{
	int		i;
	t_uint	a;
	t_uint	b;

	i = 0;
	w = (t_uint*)malloc(sizeof(t_uint) * 64);
	while (i < 16)
	{
		w[i] = arr[i];
		i++;
	}
	while (i < 64)
	{
		a = (ROR_32(w[i - 15], 7) ^ ROR_32(w[i - 15], 18) ^ (w[i - 15] >> 3));
		b = (ROR_32(w[i - 2], 17) ^ ROR_32(w[i - 2], 19) ^ (w[i - 2] >> 10));
		w[i] = w[i - 16] + a + w[i - 7] + b;
		i++;
	}
	return (w);
}

t_uint		*sha256_hash_sum(t_uint *hash, t_uint *tmp)
{
	hash[A] = hash[A] + tmp[A];
	hash[B] = hash[B] + tmp[B];
	hash[C] = hash[C] + tmp[C];
	hash[D] = hash[D] + tmp[D];
	hash[E] = hash[E] + tmp[E];
	hash[F] = hash[F] + tmp[F];
	hash[G] = hash[G] + tmp[G];
	hash[H] = hash[H] + tmp[H];
	return (hash);
}

t_uint		*sha256_algo(t_uint *fo, t_uint *tmp, int i, t_uint *words)
{
	unsigned const int k[] = {
			0x428A2F98, 0x71374491, 0xB5C0FBCF, 0xE9B5DBA5, 0x3956C25B,
			0x59F111F1, 0x923F82A4, 0xAB1C5ED5, 0xD807AA98, 0x12835B01,
			0x243185BE, 0x550C7DC3, 0x72BE5D74, 0x80DEB1FE, 0x9BDC06A7,
			0xC19BF174, 0xE49B69C1, 0xEFBE4786, 0x0FC19DC6, 0x240CA1CC,
			0x2DE92C6F, 0x4A7484AA, 0x5CB0A9DC, 0x76F988DA, 0x983E5152,
			0xA831C66D, 0xB00327C8, 0xBF597FC7, 0xC6E00BF3, 0xD5A79147,
			0x06CA6351, 0x14292967, 0x27B70A85, 0x2E1B2138, 0x4D2C6DFC,
			0x53380D13, 0x650A7354, 0x766A0ABB, 0x81C2C92E, 0x92722C85,
			0xA2BFE8A1, 0xA81A664B, 0xC24B8B70, 0xC76C51A3, 0xD192E819,
			0xD6990624, 0xF40E3585, 0x106AA070, 0x19A4C116, 0x1E376C08,
			0x2748774C, 0x34B0BCB5, 0x391C0CB3, 0x4ED8AA4A, 0x5B9CCA4F,
			0x682E6FF3, 0x748F82EE, 0x78A5636F, 0x84C87814, 0x8CC70208,
			0x90BEFFFA, 0xA4506CEB, 0xBEF9A3F7, 0xC67178F2
	};

	fo[E0] = (ROR_32(tmp[A], 2) ^ ROR_32(tmp[A], 13) ^ ROR_32(tmp[A], 22));
	fo[MA] = (tmp[A] & tmp[B]) ^ (tmp[A] & tmp[C]) ^ (tmp[B] & tmp[C]);
	fo[T2] = fo[E0] + fo[MA];
	fo[E1] = (ROR_32(tmp[E], 6) ^ ROR_32(tmp[E], 11) ^ ROR_32(tmp[E], 25));
	fo[CH] = (tmp[E] & tmp[F]) ^ ((~tmp[E]) & tmp[G]);
	fo[T1] = tmp[H] + fo[E1] + fo[CH] + k[i] + words[i];
	return (fo);
}

t_uint		*sha256_algorithm(t_uint *tmp, t_uint *words)
{
	int		i;
	t_uint	*fo;

	fo = (t_uint*)malloc(sizeof(t_uint) * 6);
	i = 0;
	while (i < 64)
	{
		fo = sha256_algo(fo, tmp, i, words);
		tmp[H] = tmp[G];
		tmp[G] = tmp[F];
		tmp[F] = tmp[E];
		tmp[E] = tmp[D] + fo[T1];
		tmp[D] = tmp[C];
		tmp[C] = tmp[B];
		tmp[B] = tmp[A];
		tmp[A] = fo[T1] + fo[T2];
		i++;
	}
	free(fo);
	return (tmp);
}