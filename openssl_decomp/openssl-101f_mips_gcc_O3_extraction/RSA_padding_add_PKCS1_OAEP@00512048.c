
/* WARNING: Removing unreachable block (ram,0x005127e8) */

int RSA_padding_add_PKCS1_OAEP(uchar *to,int tlen,uchar *f,int fl,uchar *p,int pl)

{
  bool bVar1;
  undefined *puVar2;
  EVP_MD *dgst;
  int iVar3;
  uint *puVar4;
  EVP_MD *pEVar5;
  uint uVar6;
  undefined *puVar7;
  undefined4 uVar8;
  uint *puVar9;
  BIGNUM *r;
  BIGNUM *b;
  BIGNUM *m;
  BIGNUM *r_00;
  BIGNUM *a;
  BN_CTX *ctx;
  int iVar10;
  BIGNUM *pBVar11;
  char *pcVar12;
  byte *pbVar13;
  uint *puVar14;
  uint **ppuVar15;
  undefined *puVar16;
  byte bVar17;
  uint *puVar18;
  char *pcVar19;
  uint uVar20;
  uint uVar21;
  uint **unaff_s0;
  undefined *seedlen;
  int iVar22;
  uint *puVar23;
  uchar *unaff_s2;
  uint *unaff_s4;
  uint *unaff_s6;
  uint *puVar24;
  int unaff_s7;
  byte *unaff_s8;
  uint uStack_b4;
  uint uStack_b0;
  uint uStack_ac;
  uint uStack_a8;
  uint uStack_a4;
  uint auStack_a0 [5];
  int iStack_8c;
  uint **ppuStack_88;
  undefined *puStack_84;
  uchar *puStack_80;
  char *pcStack_7c;
  uint *puStack_78;
  uint *puStack_74;
  uint *puStack_70;
  int iStack_6c;
  byte *pbStack_68;
  code *pcStack_64;
  char *pcStack_5c;
  undefined4 local_4c;
  uint *local_40;
  uint local_3c;
  char *local_38;
  uint *local_34;
  char *local_30;
  int local_2c;
  
  puStack_84 = PTR___stack_chk_guard_006aabf0;
  puVar2 = PTR_EVP_sha1_006a86c4;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  pcStack_7c = (char *)(tlen + -1);
  if (fl < tlen + -0x29) {
    if ((int)pcStack_7c < 0x29) {
      local_34 = (uint *)&DAT_00000078;
      dgst = (EVP_MD *)0x33;
      goto LAB_00512110;
    }
    unaff_s4 = (uint *)(to + 0x15);
    *to = '\0';
    dgst = (EVP_MD *)(*(code *)puVar2)();
    pcVar19 = (char *)0x0;
    local_4c = 0;
    puVar4 = unaff_s4;
    iVar3 = (*(code *)PTR_EVP_Digest_006a8b04)(p);
    unaff_s6 = (uint *)f;
    unaff_s7 = fl;
    unaff_s2 = to;
    if (iVar3 == 0) {
LAB_005120f4:
      local_34 = puVar4;
      iVar3 = 0;
      unaff_s0 = (uint **)tlen;
    }
    else {
      iVar3 = (int)pcStack_7c - fl;
      p = to + 1;
      (*(code *)PTR_memset_006aab00)(to + 0x29,0,iVar3 + -0x29);
      unaff_s8 = (byte *)((int)unaff_s4 + iVar3);
      unaff_s8[-0x15] = 1;
      puVar4 = (uint *)fl;
      (*(code *)PTR_memcpy_006aabf4)((byte *)((int)unaff_s4 + iVar3 + -0x14),f);
      pl = (int)&DAT_00000014;
      iVar3 = RAND_bytes(p,0x14);
      if (iVar3 < 1) goto LAB_005120f4;
      unaff_s7 = 0x660000;
      pcStack_7c = (char *)(tlen + -0x15);
      unaff_s6 = (uint *)(*(code *)PTR_CRYPTO_malloc_006a8108)(pcStack_7c,"rsa_oaep.c",0x49);
      if (unaff_s6 != (uint *)0x0) {
        dgst = (EVP_MD *)(*(code *)PTR_EVP_sha1_006a86c4)();
        pcVar19 = &DAT_00000014;
        pl = (int)pcStack_7c;
        puVar4 = (uint *)p;
        iVar3 = PKCS1_MGF1((uchar *)unaff_s6,(long)pcStack_7c,p,0x14,dgst);
        if (-1 < iVar3) {
          if (0 < (int)pcStack_7c) {
            if ((&DAT_00000006 < pcStack_7c && (unaff_s6 + 1 <= unaff_s4 || to + 0x19 <= unaff_s6))
               && ((((uint)unaff_s4 | (uint)unaff_s6) & 3) == 0)) {
              uVar20 = 0;
              uVar6 = (tlen - 0x19U >> 2) + 1;
              pcVar19 = (char *)(uVar6 * 4);
              puVar4 = unaff_s4;
              puVar14 = unaff_s6;
              do {
                uVar21 = *puVar14;
                uVar20 = uVar20 + 1;
                puVar14 = puVar14 + 1;
                *puVar4 = uVar21 ^ *puVar4;
                puVar4 = puVar4 + 1;
              } while (uVar20 < uVar6);
              if (pcStack_7c != pcVar19) {
                pcVar12 = pcVar19 + 1;
                *(byte *)(unaff_s4 + uVar6) =
                     *(byte *)(unaff_s6 + uVar6) ^ *(byte *)(unaff_s4 + uVar6);
                if ((int)pcVar12 < (int)pcStack_7c) {
                  pcVar19 = pcVar19 + 2;
                  *(byte *)((int)unaff_s4 + (int)pcVar12) =
                       *(byte *)((int)unaff_s6 + (int)pcVar12) ^
                       *(byte *)((int)unaff_s4 + (int)pcVar12);
                  if ((int)pcVar19 < (int)pcStack_7c) {
                    *(byte *)((int)unaff_s4 + (int)pcVar19) =
                         *(byte *)((int)unaff_s6 + (int)pcVar19) ^
                         *(byte *)((int)unaff_s4 + (int)pcVar19);
                  }
                }
              }
            }
            else {
              puVar4 = unaff_s4;
              puVar14 = unaff_s6;
              do {
                puVar24 = (uint *)((int)puVar4 + 1);
                bVar17 = *(byte *)puVar14;
                puVar14 = (uint *)((int)puVar14 + 1);
                *(byte *)puVar4 = *(byte *)puVar4 ^ bVar17;
                puVar4 = puVar24;
              } while (puVar24 != (uint *)(to + tlen));
            }
          }
          tlen = (int)&local_40;
          dgst = (EVP_MD *)(*(code *)PTR_EVP_sha1_006a86c4)();
          pl = (int)&DAT_00000014;
          puVar4 = unaff_s4;
          pcVar19 = pcStack_7c;
          iVar3 = PKCS1_MGF1((uchar *)tlen,0x14,(uchar *)unaff_s4,(long)pcStack_7c,dgst);
          if (-1 < iVar3) {
            ppuVar15 = (uint **)tlen;
            if (((uint)p & 3) == 0) {
              *(uint *)(to + 1) = (uint)local_40 ^ *(uint *)(to + 1);
              *(uint *)(to + 5) = *(uint *)(to + 5) ^ local_3c;
              *(uint *)(to + 9) = *(uint *)(to + 9) ^ (uint)local_38;
              *(uint *)(to + 0xd) = *(uint *)(to + 0xd) ^ (uint)local_34;
              *(uint *)(to + 0x11) = *(uint *)(to + 0x11) ^ (uint)local_30;
              pl = (int)local_30;
              pcVar19 = local_38;
              puVar4 = (uint *)p;
            }
            else {
              do {
                puVar4 = (uint *)((int)p + 1);
                *p = *p ^ *(byte *)ppuVar15;
                ppuVar15 = (uint **)((int)ppuVar15 + 1);
                local_34 = local_40;
                p = (uchar *)puVar4;
              } while (unaff_s4 != puVar4);
            }
            (*(code *)PTR_CRYPTO_free_006a7f88)(unaff_s6);
            iVar3 = 1;
            unaff_s0 = (uint **)tlen;
            p = (uchar *)puVar4;
            goto LAB_00512128;
          }
        }
        goto LAB_005120f4;
      }
      pcVar19 = "rsa_oaep.c";
      local_34 = (uint *)&DAT_00000041;
      pl = 0x79;
      dgst = (EVP_MD *)0x4c;
      (*(code *)PTR_ERR_put_error_006a9030)(4);
      iVar3 = 0;
      unaff_s0 = (uint **)tlen;
    }
  }
  else {
    local_34 = (uint *)&DAT_0000006e;
    dgst = (EVP_MD *)&DAT_0000002d;
LAB_00512110:
    pcVar19 = "rsa_oaep.c";
    pl = 0x79;
    (*(code *)PTR_ERR_put_error_006a9030)(4);
    iVar3 = 0;
  }
LAB_00512128:
  if (local_2c == *(int *)puStack_84) {
    return iVar3;
  }
  pcStack_64 = RSA_padding_check_PKCS1_OAEP;
  iVar3 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar2 = PTR___stack_chk_guard_006aabf0;
  pcVar12 = (char *)((int)&dgst[-1].md_ctrl + 3);
  iStack_8c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar22 = (int)pcVar12 - (int)pcVar19;
  ppuStack_88 = unaff_s0;
  puStack_80 = unaff_s2;
  puStack_78 = unaff_s4;
  puStack_74 = (uint *)p;
  puStack_70 = unaff_s6;
  iStack_6c = unaff_s7;
  pbStack_68 = unaff_s8;
  pcStack_5c = (char *)pl;
  if ((int)pcVar12 < 0x29) {
    (*(code *)PTR_ERR_put_error_006a9030)(4,0x7a,0x79,"rsa_oaep.c",0xb5);
    iVar22 = -1;
  }
  else {
    bVar1 = iVar22 < 0;
    if (bVar1) {
      iVar22 = 0;
      pcVar19 = pcVar12;
    }
    seedlen = (undefined *)((int)dgst[-1].required_pkey_type + 0xb);
    puVar4 = (uint *)(*(code *)PTR_CRYPTO_malloc_006a8108)(pcVar12 + (int)seedlen,"rsa_oaep.c",0x7c)
    ;
    if (puVar4 == (uint *)0x0) {
      (*(code *)PTR_ERR_put_error_006a9030)(4,0x7a,0x41,"rsa_oaep.c",0x7f);
      iVar22 = -1;
    }
    else {
      puVar24 = (uint *)((int)puVar4 + (int)seedlen);
      (*(code *)PTR_memset_006aab00)(puVar24,0,iVar22);
      puVar14 = puVar24 + 5;
      (*(code *)PTR_memcpy_006aabf4)((byte *)((int)puVar24 + iVar22),local_34,pcVar19);
      pEVar5 = (EVP_MD *)(*(code *)PTR_EVP_sha1_006a86c4)();
      iVar22 = PKCS1_MGF1((uchar *)&uStack_b4,0x14,(uchar *)puVar14,(long)seedlen,pEVar5);
      if (iVar22 == 0) {
        if ((&uStack_b4 < (uint *)((int)puVar4 + (int)((int)dgst[-1].required_pkey_type + 0xf)) &&
             puVar24 < &uStack_b0) || (((uint)puVar24 & 3) != 0)) {
          puVar18 = &uStack_b4;
          puVar23 = puVar24;
          do {
            puVar9 = (uint *)((int)puVar18 + 1);
            bVar17 = *(byte *)puVar23;
            puVar23 = (uint *)((int)puVar23 + 1);
            *(byte *)puVar18 = *(byte *)puVar18 ^ bVar17;
            puVar18 = puVar9;
          } while (puVar9 != auStack_a0);
        }
        else {
          uStack_b4 = uStack_b4 ^ *puVar24;
          uStack_ac = uStack_ac ^ puVar24[2];
          uStack_b0 = puVar24[1] ^ uStack_b0;
          uStack_a8 = uStack_a8 ^ puVar24[3];
          uStack_a4 = uStack_a4 ^ puVar24[4];
        }
        pEVar5 = (EVP_MD *)(*(code *)PTR_EVP_sha1_006a86c4)();
        iVar22 = PKCS1_MGF1((uchar *)puVar4,(long)seedlen,(uchar *)&uStack_b4,0x14,pEVar5);
        if (iVar22 == 0) {
          puVar18 = (uint *)((int)puVar4 + (int)pcVar12);
          if (0 < (int)seedlen) {
            if ((&DAT_00000006 < seedlen &&
                 (puVar4 + 1 <= puVar18 || (int)((int)&dgst->type + 3) < 1)) &&
               ((((uint)puVar18 | (uint)puVar4) & 3) == 0)) {
              uVar20 = 0;
              uVar6 = ((uint)((int)dgst[-1].required_pkey_type + 7) >> 2) + 1;
              puVar16 = (undefined *)(uVar6 * 4);
              puVar24 = puVar4;
              do {
                uVar20 = uVar20 + 1;
                uVar21 = *puVar18;
                puVar18 = puVar18 + 1;
                *puVar24 = *puVar24 ^ uVar21;
                puVar24 = puVar24 + 1;
              } while (uVar20 < uVar6);
              if (puVar16 != seedlen) {
                puVar7 = puVar16 + 1;
                *(byte *)(puVar4 + uVar6) = *(byte *)(puVar14 + uVar6) ^ *(byte *)(puVar4 + uVar6);
                if ((int)puVar7 < (int)seedlen) {
                  puVar16 = puVar16 + 2;
                  *(byte *)((int)puVar4 + (int)puVar7) =
                       *(byte *)((int)puVar14 + (int)puVar7) ^ *(byte *)((int)puVar4 + (int)puVar7);
                  if ((int)puVar16 < (int)seedlen) {
                    *(byte *)((int)puVar4 + (int)puVar16) =
                         *(byte *)((int)puVar14 + (int)puVar16) ^
                         *(byte *)((int)puVar4 + (int)puVar16);
                  }
                }
              }
            }
            else {
              puVar18 = puVar4;
              do {
                puVar23 = (uint *)((int)puVar14 + 1);
                *(byte *)puVar18 = *(byte *)puVar18 ^ *(byte *)puVar14;
                puVar18 = (uint *)((int)puVar18 + 1);
                puVar14 = puVar23;
              } while ((uint *)((int)puVar24 + (int)pcVar12) != puVar23);
            }
          }
          uVar8 = (*(code *)PTR_EVP_sha1_006a86c4)();
          iVar22 = (*(code *)PTR_EVP_Digest_006a8b04)(local_4c,&_gp,auStack_a0,0,uVar8,0);
          if (iVar22 != 0) {
            iVar22 = (*(code *)PTR_CRYPTO_memcmp_006a9088)(puVar4,auStack_a0,0x14);
            if ((iVar22 == 0) && (!bVar1)) {
              if ((int)seedlen < 0x15) {
                if (seedlen == &DAT_00000014) goto LAB_00512724;
                puVar16 = &DAT_00000014;
                bVar17 = *(byte *)(puVar4 + 5);
              }
              else {
                bVar17 = *(byte *)(puVar4 + 5);
                puVar16 = &DAT_00000014;
                if (bVar17 == 0) {
                  puVar16 = &DAT_00000014;
                  pbVar13 = (byte *)((int)puVar4 + 0x15);
                  do {
                    puVar16 = puVar16 + 1;
                    if (puVar16 == seedlen) goto LAB_00512724;
                    bVar17 = *pbVar13;
                    pbVar13 = pbVar13 + 1;
                  } while (bVar17 == 0);
                }
              }
              if (bVar17 == 1) {
                iVar22 = (int)seedlen - (int)(puVar16 + 1);
                if ((int)pcStack_5c < iVar22) {
                  iVar22 = -1;
                  (*(code *)PTR_ERR_put_error_006a9030)(4,0x7a,0x6d,"rsa_oaep.c",0xa8);
                }
                else {
                  (*(code *)PTR_memcpy_006aabf4)
                            (iVar3,(byte *)((int)puVar4 + (int)(puVar16 + 1)),iVar22);
                }
                (*(code *)PTR_CRYPTO_free_006a7f88)(puVar4);
                goto LAB_00512758;
              }
            }
LAB_00512724:
            (*(code *)PTR_ERR_put_error_006a9030)(4,0x7a,0x79,"rsa_oaep.c",0xb5);
            (*(code *)PTR_CRYPTO_free_006a7f88)(puVar4);
          }
        }
      }
      iVar22 = -1;
    }
  }
LAB_00512758:
  if (iStack_8c == *(int *)puVar2) {
    return iVar22;
  }
  iVar3 = iStack_8c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if ((((*(int *)(iVar3 + 0x1c) == 0) || (*(int *)(iVar3 + 0x20) == 0)) ||
      (*(int *)(iVar3 + 0x10) == 0)) ||
     ((*(int *)(iVar3 + 0x14) == 0 || (*(int *)(iVar3 + 0x18) == 0)))) {
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
    iVar22 = -1;
    (*(code *)PTR_ERR_put_error_006a9030)(4,0x7b,0x41,"rsa_chk.c",0x4f);
    goto LAB_00512b20;
  }
  if (((b == (BIGNUM *)0x0) || (m == (BIGNUM *)0x0)) ||
     ((r_00 == (BIGNUM *)0x0 || ((a == (BIGNUM *)0x0 || (ctx == (BN_CTX *)0x0)))))) {
    (*(code *)PTR_ERR_put_error_006a9030)(4,0x7b,0x41,"rsa_chk.c",0x4f);
    goto LAB_00512b0c;
  }
  iVar10 = BN_is_prime_ex(*(BIGNUM **)(iVar3 + 0x1c),0,(BN_CTX *)0x0,(BN_GENCB *)0x0);
  if (iVar10 != 1) {
    iVar22 = iVar10;
    if (iVar10 == 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(4,0x7b,0x80,"rsa_chk.c",0x5a);
      goto LAB_00512ab0;
    }
    goto LAB_00512b14;
  }
LAB_00512ab0:
  iVar22 = BN_is_prime_ex(*(BIGNUM **)(iVar3 + 0x20),0,(BN_CTX *)0x0,(BN_GENCB *)0x0);
  if (iVar22 != 1) {
    if (iVar22 != 0) goto LAB_00512b14;
    (*(code *)PTR_ERR_put_error_006a9030)(4,0x7b,0x81,"rsa_chk.c",100);
    iVar10 = 0;
  }
  iVar22 = iVar10;
  iVar10 = BN_mul(r,*(BIGNUM **)(iVar3 + 0x1c),*(BIGNUM **)(iVar3 + 0x20),ctx);
  if (iVar10 == 0) {
LAB_00512b0c:
    iVar22 = -1;
  }
  else {
    iVar10 = BN_cmp(r,*(BIGNUM **)(iVar3 + 0x10));
    if (iVar10 != 0) {
      iVar22 = 0;
      (*(code *)PTR_ERR_put_error_006a9030)(4,0x7b,0x7f,"rsa_chk.c",0x6e);
    }
    uVar8 = *(undefined4 *)(iVar3 + 0x1c);
    pBVar11 = BN_value_one();
    iVar10 = (*(code *)PTR_BN_sub_006a96cc)(r,uVar8,pBVar11);
    if (iVar10 == 0) goto LAB_00512b0c;
    uVar8 = *(undefined4 *)(iVar3 + 0x20);
    pBVar11 = BN_value_one();
    iVar10 = (*(code *)PTR_BN_sub_006a96cc)(b,uVar8,pBVar11);
    if ((((iVar10 == 0) || (iVar10 = BN_mul(r_00,r,b,ctx), iVar10 == 0)) ||
        (iVar10 = (*(code *)PTR_BN_gcd_006a9840)(a,r,b,ctx), iVar10 == 0)) ||
       ((iVar10 = (*(code *)PTR_BN_div_006a967c)(m,0,r_00,a,ctx), iVar10 == 0 ||
        (iVar10 = BN_mod_mul(r,*(BIGNUM **)(iVar3 + 0x18),*(BIGNUM **)(iVar3 + 0x14),m,ctx),
        iVar10 == 0)))) goto LAB_00512b0c;
    if ((r->top != 1) || ((*r->d != 1 || (r->neg != 0)))) {
      iVar22 = 0;
      (*(code *)PTR_ERR_put_error_006a9030)(4,0x7b,0x7b,"rsa_chk.c",0x86);
    }
    if (((*(int *)(iVar3 + 0x24) != 0) && (*(int *)(iVar3 + 0x28) != 0)) &&
       (*(int *)(iVar3 + 0x2c) != 0)) {
      uVar8 = *(undefined4 *)(iVar3 + 0x1c);
      pBVar11 = BN_value_one();
      iVar10 = (*(code *)PTR_BN_sub_006a96cc)(r,uVar8,pBVar11);
      if ((iVar10 != 0) &&
         (iVar10 = (*(code *)PTR_BN_div_006a967c)(0,b,*(undefined4 *)(iVar3 + 0x18),r,ctx),
         iVar10 != 0)) {
        iVar10 = BN_cmp(b,*(BIGNUM **)(iVar3 + 0x24));
        if (iVar10 != 0) {
          iVar22 = 0;
          (*(code *)PTR_ERR_put_error_006a9030)(4,0x7b,0x7c,"rsa_chk.c",0x96);
        }
        uVar8 = *(undefined4 *)(iVar3 + 0x20);
        pBVar11 = BN_value_one();
        iVar10 = (*(code *)PTR_BN_sub_006a96cc)(r,uVar8,pBVar11);
        if ((iVar10 != 0) &&
           (iVar10 = (*(code *)PTR_BN_div_006a967c)(0,b,*(undefined4 *)(iVar3 + 0x18),r,ctx),
           iVar10 != 0)) {
          iVar10 = BN_cmp(b,*(BIGNUM **)(iVar3 + 0x28));
          if (iVar10 != 0) {
            iVar22 = 0;
            (*(code *)PTR_ERR_put_error_006a9030)(4,0x7b,0x7d,"rsa_chk.c",0xa4);
          }
          iVar10 = (*(code *)PTR_BN_mod_inverse_006a9714)
                             (r,*(undefined4 *)(iVar3 + 0x20),*(undefined4 *)(iVar3 + 0x1c),ctx);
          if (iVar10 != 0) {
            iVar3 = BN_cmp(r,*(BIGNUM **)(iVar3 + 0x2c));
            if (iVar3 != 0) {
              iVar22 = 0;
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
    return iVar22;
  }
  return iVar22;
}

