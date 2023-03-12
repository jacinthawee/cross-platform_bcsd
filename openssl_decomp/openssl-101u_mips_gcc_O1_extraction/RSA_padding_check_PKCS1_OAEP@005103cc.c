
int RSA_padding_check_PKCS1_OAEP(uchar *to,int tlen,uchar *f,int fl,int rsa_len,uchar *p,int pl)

{
  byte bVar1;
  byte bVar2;
  undefined *puVar3;
  int iVar4;
  uint seedlen;
  EVP_MD *pEVar5;
  uint uVar6;
  uint *puVar7;
  BIGNUM *r;
  BIGNUM *b;
  BIGNUM *m;
  BIGNUM *r_00;
  BIGNUM *a;
  BN_CTX *ctx;
  int iVar9;
  int iVar10;
  BIGNUM *pBVar11;
  uint uVar12;
  uint uVar13;
  uint *puVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint *mask;
  uint *puVar20;
  byte *pbVar21;
  undefined4 uVar22;
  uint local_ac;
  uint local_a8;
  uint local_a4;
  uint local_a0;
  uint local_9c;
  uint auStack_98 [11];
  undefined auStack_6c [64];
  int local_2c;
  uint *puVar8;
  
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar4 = -1;
  if ((0 < tlen) && (0 < fl)) {
    if ((rsa_len < fl) || (seedlen = rsa_len - 0x15, rsa_len < 0x2a)) {
      pbVar21 = (byte *)0x0;
      mask = (uint *)0x0;
      goto LAB_00510448;
    }
    mask = (uint *)(*(code *)PTR_CRYPTO_malloc_006a7008)(seedlen,"rsa_oaep.c",0x78);
    pbVar21 = (byte *)(*(code *)PTR_CRYPTO_malloc_006a7008)(rsa_len,"rsa_oaep.c",0x79);
    if ((mask == (uint *)0x0) || (pbVar21 == (byte *)0x0)) {
      ERR_put_error(4,0x7a,0x41,"rsa_oaep.c",0x7b);
LAB_0051046c:
      iVar4 = -1;
      if (mask != (uint *)0x0) goto LAB_00510474;
    }
    else {
      (*(code *)PTR_memset_006a99f4)(pbVar21,0,rsa_len);
      puVar20 = (uint *)(pbVar21 + 0x15);
      (*(code *)PTR_memcpy_006a9aec)(pbVar21 + (rsa_len - fl),f,fl);
      bVar1 = *pbVar21;
      pEVar5 = (EVP_MD *)(*(code *)PTR_EVP_sha1_006a75d0)();
      iVar4 = PKCS1_MGF1((uchar *)&local_ac,0x14,(uchar *)puVar20,seedlen,pEVar5);
      if (iVar4 == 0) {
        puVar14 = (uint *)(pbVar21 + 1);
        if ((&local_ac < pbVar21 + 5 && puVar14 < &local_a8) || (((uint)puVar14 & 3) != 0)) {
          puVar8 = &local_ac;
          do {
            puVar7 = (uint *)((int)puVar8 + 1);
            bVar2 = *(byte *)puVar14;
            puVar14 = (uint *)((int)puVar14 + 1);
            *(byte *)puVar8 = bVar2 ^ *(byte *)puVar8;
            puVar8 = puVar7;
          } while (puVar7 != auStack_98);
        }
        else {
          local_ac = *(uint *)(pbVar21 + 1) ^ local_ac;
          local_a4 = local_a4 ^ *(uint *)(pbVar21 + 9);
          local_a8 = *(uint *)(pbVar21 + 5) ^ local_a8;
          local_a0 = local_a0 ^ *(uint *)(pbVar21 + 0xd);
          local_9c = local_9c ^ *(uint *)(pbVar21 + 0x11);
        }
        pEVar5 = (EVP_MD *)(*(code *)PTR_EVP_sha1_006a75d0)();
        iVar4 = PKCS1_MGF1((uchar *)mask,seedlen,(uchar *)&local_ac,0x14,pEVar5);
        if (iVar4 == 0) {
          if (((((uint)puVar20 | (uint)mask) & 3) == 0) &&
             (pbVar21 + 0x19 <= mask || mask + 1 <= puVar20)) {
            uVar18 = 0;
            uVar12 = (rsa_len - 0x19U >> 2) + 1;
            uVar6 = uVar12 * 4;
            puVar14 = mask;
            puVar8 = puVar20;
            do {
              uVar18 = uVar18 + 1;
              uVar19 = *puVar8;
              puVar8 = puVar8 + 1;
              *puVar14 = *puVar14 ^ uVar19;
              puVar14 = puVar14 + 1;
            } while (uVar18 < uVar12);
            if (uVar6 != seedlen) {
              iVar4 = uVar6 + 1;
              *(byte *)(mask + uVar12) = *(byte *)(puVar20 + uVar12) ^ *(byte *)(mask + uVar12);
              if (iVar4 < (int)seedlen) {
                iVar10 = uVar6 + 2;
                *(byte *)((int)mask + iVar4) =
                     *(byte *)((int)puVar20 + iVar4) ^ *(byte *)((int)mask + iVar4);
                if (iVar10 < (int)seedlen) {
                  *(byte *)((int)mask + iVar10) =
                       *(byte *)((int)puVar20 + iVar10) ^ *(byte *)((int)mask + iVar10);
                }
              }
            }
          }
          else {
            puVar14 = mask;
            do {
              bVar2 = *(byte *)puVar20;
              puVar20 = (uint *)((int)puVar20 + 1);
              *(byte *)puVar14 = bVar2 ^ *(byte *)puVar14;
              puVar14 = (uint *)((int)puVar14 + 1);
            } while ((uint *)(pbVar21 + rsa_len) != puVar20);
          }
          uVar22 = (*(code *)PTR_EVP_sha1_006a75d0)();
          iVar4 = (*(code *)PTR_EVP_Digest_006a7a14)(p,pl,auStack_6c,0,uVar22,0);
          if (iVar4 != 0) {
            uVar6 = (*(code *)PTR_CRYPTO_memcmp_006a8128)(mask,auStack_6c,0x14);
            puVar20 = mask + 5;
            uVar19 = (int)(~uVar6 & uVar6 - 1 & ~(uint)bVar1 & bVar1 - 1) >> 0x1f;
            uVar12 = 0;
            uVar18 = 0;
            uVar6 = 0x14;
            do {
              uVar13 = (uint)*(byte *)puVar20;
              uVar17 = uVar6 ^ uVar18;
              uVar15 = ~uVar12;
              uVar16 = (int)(~(uVar13 ^ 1) & (uVar13 ^ 1) - 1) >> 0x1f;
              uVar12 = uVar12 | uVar16;
              uVar6 = uVar6 + 1;
              uVar18 = uVar15 & uVar17 & uVar16 ^ uVar18;
              uVar19 = uVar19 & ((int)(~uVar13 & uVar13 - 1) >> 0x1f | uVar12);
              puVar20 = (uint *)((int)puVar20 + 1);
            } while (uVar6 != seedlen);
            if ((uVar12 & uVar19) == 0) {
LAB_00510448:
              ERR_put_error(4,0x7a,0x79,"rsa_oaep.c",0xcb);
              goto LAB_0051046c;
            }
            iVar4 = uVar6 - (uVar18 + 1);
            if (tlen < iVar4) {
              ERR_put_error(4,0x7a,0x6d,"rsa_oaep.c",0xbf);
              goto LAB_00510448;
            }
            (*(code *)PTR_memcpy_006a9aec)(to,(byte *)((int)mask + uVar18 + 1),iVar4);
            goto LAB_00510474;
          }
        }
      }
      iVar4 = -1;
LAB_00510474:
      (*(code *)PTR_CRYPTO_free_006a6e88)(mask);
    }
    if (pbVar21 != (byte *)0x0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)(pbVar21);
    }
  }
  if (local_2c == *(int *)puVar3) {
    return iVar4;
  }
  iVar4 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if ((((*(int *)(iVar4 + 0x1c) == 0) || (*(int *)(iVar4 + 0x20) == 0)) ||
      (*(int *)(iVar4 + 0x10) == 0)) ||
     ((*(int *)(iVar4 + 0x14) == 0 || (*(int *)(iVar4 + 0x18) == 0)))) {
    ERR_put_error(4,0x7b,0x93,"rsa_chk.c",0x3f);
    return 0;
  }
  r = BN_new();
  b = BN_new();
  m = BN_new();
  r_00 = BN_new();
  a = BN_new();
  ctx = BN_CTX_new();
  if (r == (BIGNUM *)0x0) {
    iVar10 = -1;
    ERR_put_error(4,0x7b,0x41,"rsa_chk.c",0x4c);
    goto LAB_00510ac0;
  }
  if (((b == (BIGNUM *)0x0) || (m == (BIGNUM *)0x0)) ||
     ((r_00 == (BIGNUM *)0x0 || ((a == (BIGNUM *)0x0 || (ctx == (BN_CTX *)0x0)))))) {
    ERR_put_error(4,0x7b,0x41,"rsa_chk.c",0x4c);
    goto LAB_00510aac;
  }
  iVar9 = BN_is_prime_ex(*(BIGNUM **)(iVar4 + 0x1c),0,(BN_CTX *)0x0,(BN_GENCB *)0x0);
  if (iVar9 != 1) {
    iVar10 = iVar9;
    if (iVar9 == 0) {
      ERR_put_error(4,0x7b,0x80,"rsa_chk.c",0x56);
      goto LAB_00510a50;
    }
    goto LAB_00510ab4;
  }
LAB_00510a50:
  iVar10 = BN_is_prime_ex(*(BIGNUM **)(iVar4 + 0x20),0,(BN_CTX *)0x0,(BN_GENCB *)0x0);
  if (iVar10 != 1) {
    if (iVar10 != 0) goto LAB_00510ab4;
    ERR_put_error(4,0x7b,0x81,"rsa_chk.c",0x5f);
    iVar9 = 0;
  }
  iVar10 = iVar9;
  iVar9 = BN_mul(r,*(BIGNUM **)(iVar4 + 0x1c),*(BIGNUM **)(iVar4 + 0x20),ctx);
  if (iVar9 == 0) {
LAB_00510aac:
    iVar10 = -1;
  }
  else {
    iVar9 = BN_cmp(r,*(BIGNUM **)(iVar4 + 0x10));
    if (iVar9 != 0) {
      iVar10 = 0;
      ERR_put_error(4,0x7b,0x7f,"rsa_chk.c",0x6b);
    }
    uVar22 = *(undefined4 *)(iVar4 + 0x1c);
    pBVar11 = BN_value_one();
    iVar9 = (*(code *)PTR_BN_sub_006a85a8)(r,uVar22,pBVar11);
    if (iVar9 == 0) goto LAB_00510aac;
    uVar22 = *(undefined4 *)(iVar4 + 0x20);
    pBVar11 = BN_value_one();
    iVar9 = (*(code *)PTR_BN_sub_006a85a8)(b,uVar22,pBVar11);
    if ((((iVar9 == 0) || (iVar9 = BN_mul(r_00,r,b,ctx), iVar9 == 0)) ||
        (iVar9 = (*(code *)PTR_BN_gcd_006a871c)(a,r,b,ctx), iVar9 == 0)) ||
       ((iVar9 = (*(code *)PTR_BN_div_006a855c)(m,0,r_00,a,ctx), iVar9 == 0 ||
        (iVar9 = BN_mod_mul(r,*(BIGNUM **)(iVar4 + 0x18),*(BIGNUM **)(iVar4 + 0x14),m,ctx),
        iVar9 == 0)))) goto LAB_00510aac;
    if ((r->top != 1) || ((*r->d != 1 || (r->neg != 0)))) {
      iVar10 = 0;
      ERR_put_error(4,0x7b,0x7b,"rsa_chk.c",0x94);
    }
    if (((*(int *)(iVar4 + 0x24) != 0) && (*(int *)(iVar4 + 0x28) != 0)) &&
       (*(int *)(iVar4 + 0x2c) != 0)) {
      uVar22 = *(undefined4 *)(iVar4 + 0x1c);
      pBVar11 = BN_value_one();
      iVar9 = (*(code *)PTR_BN_sub_006a85a8)(r,uVar22,pBVar11);
      if ((iVar9 != 0) &&
         (iVar9 = (*(code *)PTR_BN_div_006a855c)(0,b,*(undefined4 *)(iVar4 + 0x18),r,ctx),
         iVar9 != 0)) {
        iVar9 = BN_cmp(b,*(BIGNUM **)(iVar4 + 0x24));
        if (iVar9 != 0) {
          iVar10 = 0;
          ERR_put_error(4,0x7b,0x7c,"rsa_chk.c",0xa7);
        }
        uVar22 = *(undefined4 *)(iVar4 + 0x20);
        pBVar11 = BN_value_one();
        iVar9 = (*(code *)PTR_BN_sub_006a85a8)(r,uVar22,pBVar11);
        if ((iVar9 != 0) &&
           (iVar9 = (*(code *)PTR_BN_div_006a855c)(0,b,*(undefined4 *)(iVar4 + 0x18),r,ctx),
           iVar9 != 0)) {
          iVar9 = BN_cmp(b,*(BIGNUM **)(iVar4 + 0x28));
          if (iVar9 != 0) {
            iVar10 = 0;
            ERR_put_error(4,0x7b,0x7d,"rsa_chk.c",0xb9);
          }
          iVar9 = (*(code *)PTR_BN_mod_inverse_006a85f0)
                            (r,*(undefined4 *)(iVar4 + 0x20),*(undefined4 *)(iVar4 + 0x1c),ctx);
          if (iVar9 != 0) {
            iVar4 = BN_cmp(r,*(BIGNUM **)(iVar4 + 0x2c));
            if (iVar4 != 0) {
              iVar10 = 0;
              ERR_put_error(4,0x7b,0x7e,"rsa_chk.c",0xc4);
            }
            goto LAB_00510ab4;
          }
        }
      }
      goto LAB_00510aac;
    }
  }
LAB_00510ab4:
  BN_free(r);
LAB_00510ac0:
  if (b != (BIGNUM *)0x0) {
    BN_free(b);
  }
  if (m != (BIGNUM *)0x0) {
    BN_free(m);
  }
  if (r_00 != (BIGNUM *)0x0) {
    BN_free(r_00);
  }
  if (a != (BIGNUM *)0x0) {
    BN_free(a);
  }
  if (ctx == (BN_CTX *)0x0) {
    return iVar10;
  }
  BN_CTX_free(ctx);
  return iVar10;
}

