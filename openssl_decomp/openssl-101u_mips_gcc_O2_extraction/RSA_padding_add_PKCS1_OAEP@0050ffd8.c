
int RSA_padding_add_PKCS1_OAEP(uchar *to,int tlen,uchar *f,int fl,uchar *p,int pl)

{
  byte bVar1;
  byte bVar2;
  undefined *puVar3;
  EVP_MD *dgst;
  int iVar4;
  int iVar5;
  undefined *seedlen;
  EVP_MD *pEVar6;
  undefined *puVar7;
  uint *puVar8;
  BIGNUM *r;
  BIGNUM *b;
  BIGNUM *m;
  BIGNUM *r_00;
  BIGNUM *a;
  BN_CTX *ctx;
  int iVar10;
  BIGNUM *pBVar11;
  char *pcVar12;
  uint **ppuVar13;
  uint uVar14;
  undefined *puVar15;
  uint uVar16;
  uint *puVar17;
  uint uVar18;
  uint uVar19;
  char *pcVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint **unaff_s0;
  uint *puVar24;
  uchar *unaff_s2;
  uint *unaff_s4;
  uint *unaff_s6;
  uint *puVar25;
  int unaff_s7;
  byte *pbVar26;
  byte *unaff_s8;
  undefined4 uVar27;
  uint uStack_10c;
  uint uStack_108;
  uint uStack_104;
  uint uStack_100;
  uint uStack_fc;
  uint auStack_f8 [11];
  undefined auStack_cc [64];
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
  undefined4 local_4c;
  uint *local_40;
  uint local_3c;
  char *local_38;
  uint *local_34;
  char *local_30;
  int local_2c;
  uint *puVar9;
  
  puStack_84 = PTR___stack_chk_guard_006a9ae8;
  puVar3 = PTR_EVP_sha1_006a75d0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pcStack_7c = (char *)(tlen + -1);
  if (fl < tlen + -0x29) {
    if ((int)pcStack_7c < 0x29) {
      local_34 = (uint *)&DAT_00000078;
      dgst = (EVP_MD *)&DAT_00000031;
      goto LAB_005100a0;
    }
    unaff_s4 = (uint *)(to + 0x15);
    *to = '\0';
    dgst = (EVP_MD *)(*(code *)puVar3)();
    pcVar20 = (char *)0x0;
    local_4c = 0;
    puVar24 = unaff_s4;
    iVar4 = (*(code *)PTR_EVP_Digest_006a7a14)(p);
    unaff_s6 = (uint *)f;
    unaff_s7 = fl;
    unaff_s2 = to;
    if (iVar4 == 0) {
LAB_00510084:
      local_34 = puVar24;
      iVar4 = 0;
      unaff_s0 = (uint **)tlen;
    }
    else {
      iVar4 = (int)pcStack_7c - fl;
      p = to + 1;
      (*(code *)PTR_memset_006a99f4)(to + 0x29,0,iVar4 + -0x29);
      unaff_s8 = (byte *)((int)unaff_s4 + iVar4);
      unaff_s8[-0x15] = 1;
      puVar24 = (uint *)fl;
      (*(code *)PTR_memcpy_006a9aec)((byte *)((int)unaff_s4 + iVar4 + -0x14),f);
      pl = 0x14;
      iVar4 = RAND_bytes(p,0x14);
      if (iVar4 < 1) goto LAB_00510084;
      unaff_s7 = 0x660000;
      pcStack_7c = (char *)(tlen + -0x15);
      unaff_s6 = (uint *)(*(code *)PTR_CRYPTO_malloc_006a7008)(pcStack_7c,"rsa_oaep.c",0x47);
      if (unaff_s6 != (uint *)0x0) {
        dgst = (EVP_MD *)(*(code *)PTR_EVP_sha1_006a75d0)();
        pcVar20 = (char *)0x14;
        pl = (int)pcStack_7c;
        puVar24 = (uint *)p;
        iVar4 = PKCS1_MGF1((uchar *)unaff_s6,(long)pcStack_7c,p,0x14,dgst);
        if (-1 < iVar4) {
          if (0 < (int)pcStack_7c) {
            if ((pcStack_7c < &DAT_00000007 || unaff_s4 < unaff_s6 + 1 && unaff_s6 < to + 0x19) ||
               ((((uint)unaff_s4 | (uint)unaff_s6) & 3) != 0)) {
              puVar24 = unaff_s4;
              puVar25 = unaff_s6;
              do {
                puVar17 = (uint *)((int)puVar24 + 1);
                bVar1 = *(byte *)puVar25;
                puVar25 = (uint *)((int)puVar25 + 1);
                *(byte *)puVar24 = *(byte *)puVar24 ^ bVar1;
                puVar24 = puVar17;
              } while (puVar17 != (uint *)(to + tlen));
            }
            else {
              uVar22 = 0;
              uVar14 = (tlen - 0x19U >> 2) + 1;
              pcVar20 = (char *)(uVar14 * 4);
              puVar24 = unaff_s4;
              puVar25 = unaff_s6;
              do {
                uVar23 = *puVar25;
                uVar22 = uVar22 + 1;
                puVar25 = puVar25 + 1;
                *puVar24 = uVar23 ^ *puVar24;
                puVar24 = puVar24 + 1;
              } while (uVar22 < uVar14);
              if (pcStack_7c != pcVar20) {
                pcVar12 = pcVar20 + 1;
                *(byte *)(unaff_s4 + uVar14) =
                     *(byte *)(unaff_s6 + uVar14) ^ *(byte *)(unaff_s4 + uVar14);
                if ((int)pcVar12 < (int)pcStack_7c) {
                  pcVar20 = pcVar20 + 2;
                  *(byte *)((int)unaff_s4 + (int)pcVar12) =
                       *(byte *)((int)unaff_s6 + (int)pcVar12) ^
                       *(byte *)((int)unaff_s4 + (int)pcVar12);
                  if ((int)pcVar20 < (int)pcStack_7c) {
                    *(byte *)((int)unaff_s4 + (int)pcVar20) =
                         *(byte *)((int)unaff_s6 + (int)pcVar20) ^
                         *(byte *)((int)unaff_s4 + (int)pcVar20);
                  }
                }
              }
            }
          }
          tlen = (int)&local_40;
          dgst = (EVP_MD *)(*(code *)PTR_EVP_sha1_006a75d0)();
          pl = 0x14;
          puVar24 = unaff_s4;
          pcVar20 = pcStack_7c;
          iVar4 = PKCS1_MGF1((uchar *)tlen,0x14,(uchar *)unaff_s4,(long)pcStack_7c,dgst);
          if (-1 < iVar4) {
            ppuVar13 = (uint **)tlen;
            if (((uint)p & 3) == 0) {
              *(uint *)(to + 1) = (uint)local_40 ^ *(uint *)(to + 1);
              *(uint *)(to + 5) = *(uint *)(to + 5) ^ local_3c;
              *(uint *)(to + 9) = *(uint *)(to + 9) ^ (uint)local_38;
              *(uint *)(to + 0xd) = *(uint *)(to + 0xd) ^ (uint)local_34;
              *(uint *)(to + 0x11) = *(uint *)(to + 0x11) ^ (uint)local_30;
              pl = (int)local_30;
              pcVar20 = local_38;
              puVar24 = (uint *)p;
            }
            else {
              do {
                puVar24 = (uint *)((int)p + 1);
                *p = *p ^ *(byte *)ppuVar13;
                ppuVar13 = (uint **)((int)ppuVar13 + 1);
                local_34 = local_40;
                p = (uchar *)puVar24;
              } while (unaff_s4 != puVar24);
            }
            (*(code *)PTR_CRYPTO_free_006a6e88)(unaff_s6);
            iVar4 = 1;
            unaff_s0 = (uint **)tlen;
            p = (uchar *)puVar24;
            goto LAB_005100b8;
          }
        }
        goto LAB_00510084;
      }
      pcVar20 = "rsa_oaep.c";
      local_34 = (uint *)&DAT_00000041;
      pl = 0x79;
      dgst = (EVP_MD *)0x49;
      ERR_put_error(4,0x79,0x41,"rsa_oaep.c",0x49);
      iVar4 = 0;
      unaff_s0 = (uint **)tlen;
    }
  }
  else {
    local_34 = (uint *)&DAT_0000006e;
    dgst = (EVP_MD *)&DAT_0000002c;
LAB_005100a0:
    pcVar20 = "rsa_oaep.c";
    pl = 0x79;
    (*(code *)PTR_ERR_put_error_006a7f34)(4);
    iVar4 = 0;
  }
LAB_005100b8:
  if (local_2c == *(int *)puStack_84) {
    return iVar4;
  }
  pcStack_64 = RSA_padding_check_PKCS1_OAEP;
  iVar4 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  iStack_8c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar5 = -1;
  ppuStack_88 = unaff_s0;
  puStack_80 = unaff_s2;
  puStack_78 = unaff_s4;
  puStack_74 = (uint *)p;
  puStack_70 = unaff_s6;
  iStack_6c = unaff_s7;
  pbStack_68 = unaff_s8;
  if ((0 < pl) && (0 < (int)pcVar20)) {
    if (((int)dgst < (int)pcVar20) ||
       (seedlen = (undefined *)((int)dgst[-1].required_pkey_type + 0xb), (int)dgst < 0x2a)) {
      pbVar26 = (byte *)0x0;
      puVar24 = (uint *)0x0;
      goto LAB_00510448;
    }
    puVar24 = (uint *)(*(code *)PTR_CRYPTO_malloc_006a7008)(seedlen,"rsa_oaep.c",0x78);
    pbVar26 = (byte *)(*(code *)PTR_CRYPTO_malloc_006a7008)(dgst,"rsa_oaep.c",0x79);
    if ((puVar24 == (uint *)0x0) || (pbVar26 == (byte *)0x0)) {
      ERR_put_error(4,0x7a,0x41,"rsa_oaep.c",0x7b);
LAB_0051046c:
      iVar5 = -1;
      if (puVar24 != (uint *)0x0) goto LAB_00510474;
    }
    else {
      (*(code *)PTR_memset_006a99f4)(pbVar26,0,dgst);
      puVar25 = (uint *)(pbVar26 + 0x15);
      (*(code *)PTR_memcpy_006a9aec)(pbVar26 + ((int)dgst - (int)pcVar20),local_34,pcVar20);
      bVar1 = *pbVar26;
      pEVar6 = (EVP_MD *)(*(code *)PTR_EVP_sha1_006a75d0)();
      iVar5 = PKCS1_MGF1((uchar *)&uStack_10c,0x14,(uchar *)puVar25,(long)seedlen,pEVar6);
      if (iVar5 == 0) {
        puVar17 = (uint *)(pbVar26 + 1);
        if ((&uStack_10c < pbVar26 + 5 && puVar17 < &uStack_108) || (((uint)puVar17 & 3) != 0)) {
          puVar9 = &uStack_10c;
          do {
            puVar8 = (uint *)((int)puVar9 + 1);
            bVar2 = *(byte *)puVar17;
            puVar17 = (uint *)((int)puVar17 + 1);
            *(byte *)puVar9 = bVar2 ^ *(byte *)puVar9;
            puVar9 = puVar8;
          } while (puVar8 != auStack_f8);
        }
        else {
          uStack_10c = *(uint *)(pbVar26 + 1) ^ uStack_10c;
          uStack_104 = uStack_104 ^ *(uint *)(pbVar26 + 9);
          uStack_108 = *(uint *)(pbVar26 + 5) ^ uStack_108;
          uStack_100 = uStack_100 ^ *(uint *)(pbVar26 + 0xd);
          uStack_fc = uStack_fc ^ *(uint *)(pbVar26 + 0x11);
        }
        pEVar6 = (EVP_MD *)(*(code *)PTR_EVP_sha1_006a75d0)();
        iVar5 = PKCS1_MGF1((uchar *)puVar24,(long)seedlen,(uchar *)&uStack_10c,0x14,pEVar6);
        if (iVar5 == 0) {
          if (((((uint)puVar25 | (uint)puVar24) & 3) == 0) &&
             (pbVar26 + 0x19 <= puVar24 || puVar24 + 1 <= puVar25)) {
            uVar22 = 0;
            uVar14 = ((uint)((int)dgst[-1].required_pkey_type + 7) >> 2) + 1;
            puVar7 = (undefined *)(uVar14 * 4);
            puVar17 = puVar24;
            puVar9 = puVar25;
            do {
              uVar22 = uVar22 + 1;
              uVar23 = *puVar9;
              puVar9 = puVar9 + 1;
              *puVar17 = *puVar17 ^ uVar23;
              puVar17 = puVar17 + 1;
            } while (uVar22 < uVar14);
            if (puVar7 != seedlen) {
              puVar15 = puVar7 + 1;
              *(byte *)(puVar24 + uVar14) =
                   *(byte *)(puVar25 + uVar14) ^ *(byte *)(puVar24 + uVar14);
              if ((int)puVar15 < (int)seedlen) {
                puVar7 = puVar7 + 2;
                *(byte *)((int)puVar24 + (int)puVar15) =
                     *(byte *)((int)puVar25 + (int)puVar15) ^ *(byte *)((int)puVar24 + (int)puVar15)
                ;
                if ((int)puVar7 < (int)seedlen) {
                  *(byte *)((int)puVar24 + (int)puVar7) =
                       *(byte *)((int)puVar25 + (int)puVar7) ^ *(byte *)((int)puVar24 + (int)puVar7)
                  ;
                }
              }
            }
          }
          else {
            puVar17 = puVar24;
            do {
              bVar2 = *(byte *)puVar25;
              puVar25 = (uint *)((int)puVar25 + 1);
              *(byte *)puVar17 = bVar2 ^ *(byte *)puVar17;
              puVar17 = (uint *)((int)puVar17 + 1);
            } while ((uint *)(pbVar26 + (int)dgst) != puVar25);
          }
          uVar27 = (*(code *)PTR_EVP_sha1_006a75d0)();
          iVar5 = (*(code *)PTR_EVP_Digest_006a7a14)(local_4c,&_gp,auStack_cc,0,uVar27,0);
          if (iVar5 != 0) {
            uVar14 = (*(code *)PTR_CRYPTO_memcmp_006a8128)(puVar24,auStack_cc,0x14);
            puVar25 = puVar24 + 5;
            uVar23 = (int)(~uVar14 & uVar14 - 1 & ~(uint)bVar1 & bVar1 - 1) >> 0x1f;
            uVar14 = 0;
            uVar22 = 0;
            puVar7 = &DAT_00000014;
            do {
              uVar16 = (uint)*(byte *)puVar25;
              uVar21 = (uint)puVar7 ^ uVar22;
              uVar18 = ~uVar14;
              uVar19 = (int)(~(uVar16 ^ 1) & (uVar16 ^ 1) - 1) >> 0x1f;
              uVar14 = uVar14 | uVar19;
              puVar7 = puVar7 + 1;
              uVar22 = uVar18 & uVar21 & uVar19 ^ uVar22;
              uVar23 = uVar23 & ((int)(~uVar16 & uVar16 - 1) >> 0x1f | uVar14);
              puVar25 = (uint *)((int)puVar25 + 1);
            } while (puVar7 != seedlen);
            if ((uVar14 & uVar23) == 0) {
LAB_00510448:
              ERR_put_error(4,0x7a,0x79,"rsa_oaep.c",0xcb);
              goto LAB_0051046c;
            }
            iVar5 = (int)puVar7 - (uVar22 + 1);
            if (pl < iVar5) {
              ERR_put_error(4,0x7a,0x6d,"rsa_oaep.c",0xbf);
              goto LAB_00510448;
            }
            (*(code *)PTR_memcpy_006a9aec)(iVar4,(byte *)((int)puVar24 + uVar22 + 1),iVar5);
            goto LAB_00510474;
          }
        }
      }
      iVar5 = -1;
LAB_00510474:
      (*(code *)PTR_CRYPTO_free_006a6e88)(puVar24);
    }
    if (pbVar26 != (byte *)0x0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)(pbVar26);
    }
  }
  if (iStack_8c == *(int *)puVar3) {
    return iVar5;
  }
  iVar4 = iStack_8c;
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
    iVar5 = -1;
    ERR_put_error(4,0x7b,0x41,"rsa_chk.c",0x4c);
    goto LAB_00510ac0;
  }
  if (((b == (BIGNUM *)0x0) || (m == (BIGNUM *)0x0)) ||
     ((r_00 == (BIGNUM *)0x0 || ((a == (BIGNUM *)0x0 || (ctx == (BN_CTX *)0x0)))))) {
    ERR_put_error(4,0x7b,0x41,"rsa_chk.c",0x4c);
    goto LAB_00510aac;
  }
  iVar10 = BN_is_prime_ex(*(BIGNUM **)(iVar4 + 0x1c),0,(BN_CTX *)0x0,(BN_GENCB *)0x0);
  if (iVar10 != 1) {
    iVar5 = iVar10;
    if (iVar10 == 0) {
      ERR_put_error(4,0x7b,0x80,"rsa_chk.c",0x56);
      goto LAB_00510a50;
    }
    goto LAB_00510ab4;
  }
LAB_00510a50:
  iVar5 = BN_is_prime_ex(*(BIGNUM **)(iVar4 + 0x20),0,(BN_CTX *)0x0,(BN_GENCB *)0x0);
  if (iVar5 != 1) {
    if (iVar5 != 0) goto LAB_00510ab4;
    ERR_put_error(4,0x7b,0x81,"rsa_chk.c",0x5f);
    iVar10 = 0;
  }
  iVar5 = iVar10;
  iVar10 = BN_mul(r,*(BIGNUM **)(iVar4 + 0x1c),*(BIGNUM **)(iVar4 + 0x20),ctx);
  if (iVar10 == 0) {
LAB_00510aac:
    iVar5 = -1;
  }
  else {
    iVar10 = BN_cmp(r,*(BIGNUM **)(iVar4 + 0x10));
    if (iVar10 != 0) {
      iVar5 = 0;
      ERR_put_error(4,0x7b,0x7f,"rsa_chk.c",0x6b);
    }
    uVar27 = *(undefined4 *)(iVar4 + 0x1c);
    pBVar11 = BN_value_one();
    iVar10 = (*(code *)PTR_BN_sub_006a85a8)(r,uVar27,pBVar11);
    if (iVar10 == 0) goto LAB_00510aac;
    uVar27 = *(undefined4 *)(iVar4 + 0x20);
    pBVar11 = BN_value_one();
    iVar10 = (*(code *)PTR_BN_sub_006a85a8)(b,uVar27,pBVar11);
    if ((((iVar10 == 0) || (iVar10 = BN_mul(r_00,r,b,ctx), iVar10 == 0)) ||
        (iVar10 = (*(code *)PTR_BN_gcd_006a871c)(a,r,b,ctx), iVar10 == 0)) ||
       ((iVar10 = (*(code *)PTR_BN_div_006a855c)(m,0,r_00,a,ctx), iVar10 == 0 ||
        (iVar10 = BN_mod_mul(r,*(BIGNUM **)(iVar4 + 0x18),*(BIGNUM **)(iVar4 + 0x14),m,ctx),
        iVar10 == 0)))) goto LAB_00510aac;
    if ((r->top != 1) || ((*r->d != 1 || (r->neg != 0)))) {
      iVar5 = 0;
      ERR_put_error(4,0x7b,0x7b,"rsa_chk.c",0x94);
    }
    if (((*(int *)(iVar4 + 0x24) != 0) && (*(int *)(iVar4 + 0x28) != 0)) &&
       (*(int *)(iVar4 + 0x2c) != 0)) {
      uVar27 = *(undefined4 *)(iVar4 + 0x1c);
      pBVar11 = BN_value_one();
      iVar10 = (*(code *)PTR_BN_sub_006a85a8)(r,uVar27,pBVar11);
      if ((iVar10 != 0) &&
         (iVar10 = (*(code *)PTR_BN_div_006a855c)(0,b,*(undefined4 *)(iVar4 + 0x18),r,ctx),
         iVar10 != 0)) {
        iVar10 = BN_cmp(b,*(BIGNUM **)(iVar4 + 0x24));
        if (iVar10 != 0) {
          iVar5 = 0;
          ERR_put_error(4,0x7b,0x7c,"rsa_chk.c",0xa7);
        }
        uVar27 = *(undefined4 *)(iVar4 + 0x20);
        pBVar11 = BN_value_one();
        iVar10 = (*(code *)PTR_BN_sub_006a85a8)(r,uVar27,pBVar11);
        if ((iVar10 != 0) &&
           (iVar10 = (*(code *)PTR_BN_div_006a855c)(0,b,*(undefined4 *)(iVar4 + 0x18),r,ctx),
           iVar10 != 0)) {
          iVar10 = BN_cmp(b,*(BIGNUM **)(iVar4 + 0x28));
          if (iVar10 != 0) {
            iVar5 = 0;
            ERR_put_error(4,0x7b,0x7d,"rsa_chk.c",0xb9);
          }
          iVar10 = (*(code *)PTR_BN_mod_inverse_006a85f0)
                             (r,*(undefined4 *)(iVar4 + 0x20),*(undefined4 *)(iVar4 + 0x1c),ctx);
          if (iVar10 != 0) {
            iVar4 = BN_cmp(r,*(BIGNUM **)(iVar4 + 0x2c));
            if (iVar4 != 0) {
              iVar5 = 0;
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
    return iVar5;
  }
  BN_CTX_free(ctx);
  return iVar5;
}

