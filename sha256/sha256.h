/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 17:57:32 by agusev            #+#    #+#             */
/*   Updated: 2019/04/21 01:53:20 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA256_H
# define SHA256_H

# include <sys/types.h>

# define SHA256_TPL		"SHA256(%s)= %s\n"
# define SHA256_R		"%s %s\n"

# define ROR(a,b) (((a) >> (b)) | ((a) << (32 - (b))))

# define CH(x,y,z) (((x) & (y)) ^ (~(x) & (z)))
# define MA(x,y,z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
# define E0(x) (ROR(x, 2) ^ ROR(x, 13) ^ ROR(x, 22))
# define E1(x) (ROR(x, 6) ^ ROR(x, 11) ^ ROR(x, 25))
# define SI0(x) (ROR(x, 7) ^ ROR(x, 18) ^ ((x) >> 3))
# define SI1(x) (ROR(x, 17) ^ ROR(x, 19) ^ ((x) >> 10))

static const u_int g_k[64] = {
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1,
	0x923f82a4, 0xab1c5ed5, 0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
	0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174, 0xe49b69c1, 0xefbe4786,
	0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147,
	0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
	0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85, 0xa2bfe8a1, 0xa81a664b,
	0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a,
	0x5b9cca4f, 0x682e6ff3, 0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

typedef struct			s_ctx
{
	u_int				state[8];
	unsigned char		buf[64];
	u_int				buf_len;
	unsigned long long	bit_len;
}						t_ctx;

void					sha256_init(t_ctx *ctx);
void					sha256_update(t_ctx *ctx, u_char *buf, u_int len);
void					sha256_final(t_ctx *ctx, u_char digest[32]);
void					sha256_transform(t_ctx *ctx, u_char b[64]);

#endif
