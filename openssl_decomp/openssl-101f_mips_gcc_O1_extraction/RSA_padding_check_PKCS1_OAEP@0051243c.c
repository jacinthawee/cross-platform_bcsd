
/* WARNING: Removing unreachable block (ram,0x005127e8) */

int RSA_padding_check_PKCS1_OAEP(uchar *to,int tlen,uchar *f,int fl,int rsa_len,uchar *p,int pl)

{
  bool bVar1;
  undefined *puVar2;
  uint *mask;
  EVP_MD *pEVar3;
  uint uVar4;
  undefined4 uVar5;
  uint *puVar6;
  BIGNUM *r;
  BIGNUM *b;
  BIGNUM *m;
  BIGNUM *r_00;
  BIGNUM *a;
  BN_CTX *ctx;
  int iVar7;
  BIGNUM *pBVar8;
  byte *pbVar9;
  uint uVar10;
  byte bVar11;
  uint *puVar12;
  uint uVar13;
  uint uVar14;
  uint seedlen;
  int iVar15;
  uint *puVar16;
  uint *puVar17;
  int iVar18;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint auStack_40 [5];
  int local_2c;
  uint *seed;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  iVar18 = rsa_len + -1;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar15 = iVar18 - fl;
  if (iVar18 < 0x29) {
    (*(code *)PTR_ERR_put_error_006a9030)(4,0x7a,0x79,"rsa_oaep.c",0xb5);
    iVar15 = -1;
  }
  else {
    bVar1 = iVar15 < 0;
    if (bVar1) {
      iVar15 = 0;
      fl = iVar18;
    }
    seedlen = rsa_len - 0x15;
    mask = (uint *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar18 + seedlen,"rsa_oaep.c",0x7c);
    if (mask == (uint *)0x0) {
      (*(code *)PTR_ERR_put_error_006a9030)(4,0x7a,0x41,"rsa_oaep.c",0x7f);
      iVar15 = -1;
    }
    else {
      puVar17 = (uint *)((int)mask + seedlen);
      (*(code *)PTR_memset_006aab00)(puVar17,0,iVar15);
      seed = puVar17 + 5;
      (*(code *)PTR_memcpy_006aabf4)((byte *)((int)puVar17 + iVar15),f,fl);
      pEVar3 = (EVP_MD *)(*(code *)PTR_EVP_sha1_006a86c4)();
      iVar15 = PKCS1_MGF1((uchar *)&local_54,0x14,(uchar *)seed,seedlen,pEVar3);
      if (iVar15 == 0) {
        if ((&local_54 < (uint *)((int)mask + rsa_len + -0x11) && puVar17 < &local_50) ||
           (((uint)puVar17 & 3) != 0)) {
          puVar12 = &local_54;
          puVar16 = puVar17;
          do {
            puVar6 = (uint *)((int)puVar12 + 1);
            bVar11 = *(byte *)puVar16;
            puVar16 = (uint *)((int)puVar16 + 1);
            *(byte *)puVar12 = *(byte *)puVar12 ^ bVar11;
            puVar12 = puVar6;
          } while (puVar6 != auStack_40);
        }
        else {
          local_54 = local_54 ^ *puVar17;
          local_4c = local_4c ^ puVar17[2];
          local_50 = puVar17[1] ^ local_50;
          local_48 = local_48 ^ puVar17[3];
          local_44 = local_44 ^ puVar17[4];
        }
        pEVar3 = (EVP_MD *)(*(code *)PTR_EVP_sha1_006a86c4)();
        iVar15 = PKCS1_MGF1((uchar *)mask,seedlen,(uchar *)&local_54,0x14,pEVar3);
        if (iVar15 == 0) {
          puVar12 = (uint *)((int)mask + iVar18);
          if (0 < (int)seedlen) {
            if ((seedlen < 7 || puVar12 < mask + 1 && 0 < rsa_len + 3) ||
               ((((uint)puVar12 | (uint)mask) & 3) != 0)) {
              puVar12 = mask;
              do {
                puVar16 = (uint *)((int)seed + 1);
                *(byte *)puVar12 = *(byte *)puVar12 ^ *(byte *)seed;
                puVar12 = (uint *)((int)puVar12 + 1);
                seed = puVar16;
              } while ((uint *)((int)puVar17 + iVar18) != puVar16);
            }
            else {
              uVar13 = 0;
              uVar4 = (rsa_len - 0x19U >> 2) + 1;
              uVar10 = uVar4 * 4;
              puVar17 = mask;
              do {
                uVar13 = uVar13 + 1;
                uVar14 = *puVar12;
                puVar12 = puVar12 + 1;
                *puVar17 = *puVar17 ^ uVar14;
                puVar17 = puVar17 + 1;
              } while (uVar13 < uVar4);
              if (uVar10 != seedlen) {
                iVar15 = uVar10 + 1;
                *(byte *)(mask + uVar4) = *(byte *)(seed + uVar4) ^ *(byte *)(mask + uVar4);
                if (iVar15 < (int)seedlen) {
                  iVar18 = uVar10 + 2;
                  *(byte *)((int)mask + iVar15) =
                       *(byte *)((int)seed + iVar15) ^ *(byte *)((int)mask + iVar15);
                  if (iVar18 < (int)seedlen) {
                    *(byte *)((int)mask + iVar18) =
                         *(byte *)((int)seed + iVar18) ^ *(byte *)((int)mask + iVar18);
                  }
                }
              }
            }
          }
          uVar5 = (*(code *)PTR_EVP_sha1_006a86c4)();
          iVar15 = (*(code *)PTR_EVP_Digest_006a8b04)(p,pl,auStack_40,0,uVar5,0);
          if (iVar15 != 0) {
            iVar15 = (*(code *)PTR_CRYPTO_memcmp_006a9088)(mask,auStack_40,0x14);
            if ((iVar15 == 0) && (!bVar1)) {
              if ((int)seedlen < 0x15) {
                if (seedlen == 0x14) goto LAB_00512724;
                uVar4 = 0x14;
                bVar11 = *(byte *)(mask + 5);
              }
              else {
                bVar11 = *(byte *)(mask + 5);
                uVar4 = 0x14;
                if (bVar11 == 0) {
                  uVar4 = 0x14;
                  pbVar9 = (byte *)((int)mask + 0x15);
                  do {
                    uVar4 = uVar4 + 1;
                    if (uVar4 == seedlen) goto LAB_00512724;
                    bVar11 = *pbVar9;
                    pbVar9 = pbVar9 + 1;
                  } while (bVar11 == 0);
                }
              }
              if (bVar11 == 1) {
                iVar15 = seedlen - (uVar4 + 1);
                if (tlen < iVar15) {
                  iVar15 = -1;
                  (*(code *)PTR_ERR_put_error_006a9030)(4,0x7a,0x6d,"rsa_oaep.c",0xa8);
                }
                else {
                  (*(code *)PTR_memcpy_006aabf4)(to,(byte *)((int)mask + uVar4 + 1),iVar15);
                }
                (*(code *)PTR_CRYPTO_free_006a7f88)(mask);
                goto LAB_00512758;
              }
            }
LAB_00512724:
            (*(code *)PTR_ERR_put_error_006a9030)(4,0x7a,0x79,"rsa_oaep.c",0xb5);
            (*(code *)PTR_CRYPTO_free_006a7f88)(mask);
          }
        }
      }
      iVar15 = -1;
    }
  }
LAB_00512758:
  if (local_2c == *(int *)puVar2) {
    return iVar15;
  }
  iVar15 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if ((((*(int *)(iVar15 + 0x1c) == 0) || (*(int *)(iVar15 + 0x20) == 0)) ||
      (*(int *)(iVar15 + 0x10) == 0)) ||
     ((*(int *)(iVar15 + 0x14) == 0 || (*(int *)(iVar15 + 0x18) == 0)))) {
    (*(code *)PTR_ERR_put_error_006a9030)(4,0x7b,0x93,"rsa_chk.c",0x41);
    return 0;
  }
  r = BN_new();
  b = BN_new();
  m = BN_new();
  r_00 = BN_new();
  a = BN_new();
  ctx = BN_CTX_new();
  if (r == (BIGNUM *)0x0) {
    iVar18 = -1;
    (*(code *)PTR_ERR_put_error_006a9030)(4,0x7b,0x41,"rsa_chk.c",0x4f);
    goto LAB_00512b20;
  }
  if (((b == (BIGNUM *)0x0) || (m == (BIGNUM *)0x0)) ||
     ((r_00 == (BIGNUM *)0x0 || ((a == (BIGNUM *)0x0 || (ctx == (BN_CTX *)0x0)))))) {
    (*(code *)PTR_ERR_put_error_006a9030)(4,0x7b,0x41,"rsa_chk.c",0x4f);
    goto LAB_00512b0c;
  }
  iVar7 = BN_is_prime_ex(*(BIGNUM **)(iVar15 + 0x1c),0,(BN_CTX *)0x0,(BN_GENCB *)0x0);
  if (iVar7 != 1) {
    iVar18 = iVar7;
    if (iVar7 == 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(4,0x7b,0x80,"rsa_chk.c",0x5a);
      goto LAB_00512ab0;
    }
    goto LAB_00512b14;
  }
LAB_00512ab0:
  iVar18 = BN_is_prime_ex(*(BIGNUM **)(iVar15 + 0x20),0,(BN_CTX *)0x0,(BN_GENCB *)0x0);
  if (iVar18 != 1) {
    if (iVar18 != 0) goto LAB_00512b14;
    (*(code *)PTR_ERR_put_error_006a9030)(4,0x7b,0x81,"rsa_chk.c",100);
    iVar7 = 0;
  }
  iVar18 = iVar7;
  iVar7 = BN_mul(r,*(BIGNUM **)(iVar15 + 0x1c),*(BIGNUM **)(iVar15 + 0x20),ctx);
  if (iVar7 == 0) {
LAB_00512b0c:
    iVar18 = -1;
  }
  else {
    iVar7 = BN_cmp(r,*(BIGNUM **)(iVar15 + 0x10));
    if (iVar7 != 0) {
      iVar18 = 0;
      (*(code *)PTR_ERR_put_error_006a9030)(4,0x7b,0x7f,"rsa_chk.c",0x6e);
    }
    uVar5 = *(undefined4 *)(iVar15 + 0x1c);
    pBVar8 = BN_value_one();
    iVar7 = (*(code *)PTR_BN_sub_006a96cc)(r,uVar5,pBVar8);
    if (iVar7 == 0) goto LAB_00512b0c;
    uVar5 = *(undefined4 *)(iVar15 + 0x20);
    pBVar8 = BN_value_one();
    iVar7 = (*(code *)PTR_BN_sub_006a96cc)(b,uVar5,pBVar8);
    if ((((iVar7 == 0) || (iVar7 = BN_mul(r_00,r,b,ctx), iVar7 == 0)) ||
        (iVar7 = (*(code *)PTR_BN_gcd_006a9840)(a,r,b,ctx), iVar7 == 0)) ||
       ((iVar7 = (*(code *)PTR_BN_div_006a967c)(m,0,r_00,a,ctx), iVar7 == 0 ||
        (iVar7 = BN_mod_mul(r,*(BIGNUM **)(iVar15 + 0x18),*(BIGNUM **)(iVar15 + 0x14),m,ctx),
        iVar7 == 0)))) goto LAB_00512b0c;
    if ((r->top != 1) || ((*r->d != 1 || (r->neg != 0)))) {
      iVar18 = 0;
      (*(code *)PTR_ERR_put_error_006a9030)(4,0x7b,0x7b,"rsa_chk.c",0x86);
    }
    if (((*(int *)(iVar15 + 0x24) != 0) && (*(int *)(iVar15 + 0x28) != 0)) &&
       (*(int *)(iVar15 + 0x2c) != 0)) {
      uVar5 = *(undefined4 *)(iVar15 + 0x1c);
      pBVar8 = BN_value_one();
      iVar7 = (*(code *)PTR_BN_sub_006a96cc)(r,uVar5,pBVar8);
      if ((iVar7 != 0) &&
         (iVar7 = (*(code *)PTR_BN_div_006a967c)(0,b,*(undefined4 *)(iVar15 + 0x18),r,ctx),
         iVar7 != 0)) {
        iVar7 = BN_cmp(b,*(BIGNUM **)(iVar15 + 0x24));
        if (iVar7 != 0) {
          iVar18 = 0;
          (*(code *)PTR_ERR_put_error_006a9030)(4,0x7b,0x7c,"rsa_chk.c",0x96);
        }
        uVar5 = *(undefined4 *)(iVar15 + 0x20);
        pBVar8 = BN_value_one();
        iVar7 = (*(code *)PTR_BN_sub_006a96cc)(r,uVar5,pBVar8);
        if ((iVar7 != 0) &&
           (iVar7 = (*(code *)PTR_BN_div_006a967c)(0,b,*(undefined4 *)(iVar15 + 0x18),r,ctx),
           iVar7 != 0)) {
          iVar7 = BN_cmp(b,*(BIGNUM **)(iVar15 + 0x28));
          if (iVar7 != 0) {
            iVar18 = 0;
            (*(code *)PTR_ERR_put_error_006a9030)(4,0x7b,0x7d,"rsa_chk.c",0xa4);
          }
          iVar7 = (*(code *)PTR_BN_mod_inverse_006a9714)
                            (r,*(undefined4 *)(iVar15 + 0x20),*(undefined4 *)(iVar15 + 0x1c),ctx);
          if (iVar7 != 0) {
            iVar15 = BN_cmp(r,*(BIGNUM **)(iVar15 + 0x2c));
            if (iVar15 != 0) {
              iVar18 = 0;
              (*(code *)PTR_ERR_put_error_006a9030)(4,0x7b,0x7e,"rsa_chk.c",0xb2);
            }
            goto LAB_00512b14;
          }
        }
      }
      goto LAB_00512b0c;
    }
  }
LAB_00512b14:
  BN_free(r);
LAB_00512b20:
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
  if (ctx != (BN_CTX *)0x0) {
    BN_CTX_free(ctx);
    return iVar18;
  }
  return iVar18;
}

