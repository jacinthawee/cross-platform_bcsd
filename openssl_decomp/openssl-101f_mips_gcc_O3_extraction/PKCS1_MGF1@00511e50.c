
/* WARNING: Removing unreachable block (ram,0x005127e8) */

int PKCS1_MGF1(uchar *mask,long len,uchar *seed,long seedlen,EVP_MD *dgst)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  _func_1078 *p_Var4;
  code *pcVar5;
  EVP_MD *pEVar6;
  uint uVar7;
  undefined *puVar8;
  undefined4 uVar9;
  uint *puVar10;
  BIGNUM *r;
  BIGNUM *b;
  BIGNUM *m;
  BIGNUM *r_00;
  BIGNUM *a;
  BN_CTX *ctx;
  BIGNUM *pBVar11;
  undefined *puVar12;
  code *pcVar13;
  byte *pbVar14;
  _func_1082 *p_Var15;
  EVP_MD *pEVar16;
  _func_1079 *p_Var17;
  undefined *puVar18;
  byte bVar19;
  EVP_MD *pEVar20;
  uint *puVar21;
  uint *puVar22;
  EVP_MD *pEVar23;
  char *pcVar24;
  uint uVar25;
  uint uVar26;
  int iVar27;
  undefined *seedlen_00;
  uint *puVar28;
  _func_1082 *unaff_s2;
  int unaff_s5;
  uint *puVar29;
  EVP_MD *unaff_s8;
  uint uStack_164;
  uint uStack_160;
  uint uStack_15c;
  uint uStack_158;
  uint uStack_154;
  uint auStack_150 [5];
  int iStack_13c;
  EVP_MD *pEStack_138;
  undefined *puStack_134;
  _func_1082 *p_Stack_130;
  _func_1078 *p_Stack_12c;
  EVP_MD *pEStack_128;
  EVP_MD *pEStack_124;
  uint *puStack_120;
  EVP_MD *pEStack_11c;
  EVP_MD *pEStack_118;
  code *pcStack_114;
  _func_1078 *p_Stack_10c;
  undefined4 uStack_fc;
  EVP_MD EStack_f0;
  EVP_MD *local_a0;
  _func_1078 *p_Stack_9c;
  _func_1082 *local_94;
  uchar *local_90;
  _func_1082 **local_8c;
  EVP_MD_CTX EStack_88;
  undefined local_70;
  undefined local_6f;
  undefined local_6e;
  undefined local_6d;
  _func_1082 *local_2c;
  uint *seed_00;
  
  EStack_f0.copy = (_func_1081 *)&EStack_88;
  local_8c = (_func_1082 **)PTR___stack_chk_guard_006aabf0;
  local_a0 = (EVP_MD *)&_gp;
  local_2c = *(_func_1082 **)PTR___stack_chk_guard_006aabf0;
  pEVar20 = (EVP_MD *)len;
  puVar22 = (uint *)seed;
  pEVar16 = (EVP_MD *)seedlen;
  local_90 = mask;
  (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(EStack_f0.copy);
  iVar2 = (*(code *)local_a0[-0x179].required_pkey_type[3])(dgst);
  pEVar6 = pEVar20;
  EStack_f0.required_pkey_type[0] = unaff_s5;
  if (iVar2 < 0) {
LAB_00512034:
    pEStack_138 = (EVP_MD *)0xffffffff;
  }
  else {
    iVar27 = 0;
    if (0 < len) {
      unaff_s8 = (EVP_MD *)&local_70;
      p_Var15 = (_func_1082 *)0x0;
      do {
        unaff_s2 = p_Var15;
        local_6d = (undefined)iVar27;
        puVar22 = (uint *)0x0;
        local_70 = (undefined)((uint)iVar27 >> 0x18);
        local_6f = (undefined)((uint)iVar27 >> 0x10);
        local_6e = (undefined)((uint)iVar27 >> 8);
        pEVar6 = dgst;
        iVar3 = (*local_a0[-0x196].final)((EVP_MD_CTX *)EStack_f0.copy,(uchar *)dgst);
        EStack_f0.required_pkey_type[0] = iVar2;
        if ((iVar3 == 0) ||
           (pEVar6 = (EVP_MD *)seed, puVar22 = (uint *)seedlen,
           iVar3 = (*local_a0[-0x196].copy)((EVP_MD_CTX *)EStack_f0.copy,(EVP_MD_CTX *)seed),
           iVar3 == 0)) goto LAB_00512034;
        puVar22 = (uint *)&SUB_00000004;
        pEVar6 = unaff_s8;
        iVar3 = (*local_a0[-0x196].copy)((EVP_MD_CTX *)EStack_f0.copy,(EVP_MD_CTX *)unaff_s8);
        if (iVar3 == 0) goto LAB_00512034;
        local_94 = unaff_s2 + iVar2;
        if (len < (int)local_94) {
          pEVar20 = (EVP_MD *)&stack0xffffff94;
          puVar22 = (uint *)0x0;
          pEVar6 = pEVar20;
          iVar2 = (*local_a0[-0x196].cleanup)((EVP_MD_CTX *)EStack_f0.copy);
          if (iVar2 == 0) goto LAB_00512034;
          puVar22 = (uint *)(len - (int)unaff_s2);
          (*(code *)local_a0[-0x118].required_pkey_type[2])(local_90 + (int)unaff_s2);
          break;
        }
        puVar22 = (uint *)0x0;
        pEVar20 = (EVP_MD *)(local_90 + (int)unaff_s2);
        iVar3 = (*local_a0[-0x196].cleanup)((EVP_MD_CTX *)EStack_f0.copy);
        pEVar6 = pEVar20;
        if (iVar3 == 0) goto LAB_00512034;
        iVar27 = iVar27 + 1;
        p_Var15 = local_94;
      } while ((int)local_94 < len);
    }
    pEStack_138 = (EVP_MD *)0x0;
    pEVar6 = pEVar20;
  }
  (*local_a0[-0x1af].md_ctrl)((EVP_MD_CTX *)EStack_f0.copy,(int)pEVar6,(int)puVar22,pEVar16);
  if (local_2c == *local_8c) {
    return (int)pEStack_138;
  }
  EStack_f0.required_pkey_type[4] = (int)RSA_padding_add_PKCS1_OAEP;
  p_Var15 = local_2c;
  (*(code *)local_a0[-0x119].ctx_size)();
  pEStack_124 = local_a0;
  puStack_134 = PTR___stack_chk_guard_006aabf0;
  puVar12 = PTR_EVP_sha1_006a86c4;
  EStack_f0.verify = (_func_1084 *)dgst;
  EStack_f0.update = *(_func_1079 **)PTR___stack_chk_guard_006aabf0;
  p_Stack_12c = (_func_1078 *)((int)&pEVar6[-1].md_ctrl + 3);
  EStack_f0.final = (_func_1080 *)pEStack_138;
  EStack_f0.cleanup = unaff_s2;
  EStack_f0.sign = (_func_1083 *)len;
  EStack_f0.required_pkey_type[1] = (int)seed;
  EStack_f0.required_pkey_type[2] = seedlen;
  EStack_f0.required_pkey_type[3] = (int)unaff_s8;
  if ((int)pEVar16 < (int)((int)&pEVar6[-1].cleanup + 3)) {
    if ((int)p_Stack_12c < 0x29) {
      EStack_f0.flags = (ulong)&DAT_00000078;
      pEVar20 = (EVP_MD *)0x33;
      goto LAB_00512110;
    }
    dgst = (EVP_MD *)(p_Var15 + 0x15);
    *p_Var15 = (_func_1082)0x0;
    pEVar20 = (EVP_MD *)(*(code *)puVar12)();
    pcVar24 = (char *)0x0;
    uStack_fc = 0;
    pEVar23 = dgst;
    iVar2 = (*(code *)PTR_EVP_Digest_006a8b04)(pEStack_124);
    seed = (uchar *)puVar22;
    seedlen = (long)pEVar16;
    unaff_s2 = p_Var15;
    if (iVar2 == 0) {
LAB_005120f4:
      EStack_f0.flags = (ulong)pEVar23;
      iVar2 = 0;
      pEStack_138 = pEVar6;
    }
    else {
      iVar2 = (int)p_Stack_12c - (int)pEVar16;
      pEStack_124 = (EVP_MD *)(p_Var15 + 1);
      (*(code *)PTR_memset_006aab00)(p_Var15 + 0x29,0,iVar2 + -0x29);
      unaff_s8 = (EVP_MD *)((int)dgst + iVar2);
      *(undefined *)((int)unaff_s8[-1].required_pkey_type + 0xb) = 1;
      pEVar23 = pEVar16;
      (*(code *)PTR_memcpy_006aabf4)((byte *)((int)dgst + iVar2 + -0x14),puVar22);
      p_Stack_9c = (_func_1078 *)&DAT_00000014;
      iVar2 = RAND_bytes((uchar *)pEStack_124,0x14);
      if (iVar2 < 1) goto LAB_005120f4;
      seedlen = (long)(CAST_S_table6 + 0x350);
      p_Stack_12c = (_func_1078 *)((int)pEVar6[-1].required_pkey_type + 0xb);
      seed = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a8108)(p_Stack_12c,"rsa_oaep.c",0x49);
      if ((uint *)seed != (uint *)0x0) {
        pEVar20 = (EVP_MD *)(*(code *)PTR_EVP_sha1_006a86c4)();
        pcVar24 = &DAT_00000014;
        p_Stack_9c = p_Stack_12c;
        pEVar23 = pEStack_124;
        iVar2 = PKCS1_MGF1(seed,(long)p_Stack_12c,(uchar *)pEStack_124,0x14,pEVar20);
        if (-1 < iVar2) {
          if (0 < (int)p_Stack_12c) {
            if ((&DAT_00000006 < p_Stack_12c &&
                 ((EVP_MD *)((int)seed + 4) <= dgst || p_Var15 + 0x19 <= seed)) &&
               (puVar12 = (undefined *)((int)pEVar6[-1].required_pkey_type + 7),
               (((uint)dgst | (uint)seed) & 3) == 0)) {
              uVar25 = 0;
              uVar7 = (uint)puVar12 >> 2;
              p_Var4 = (_func_1078 *)(((uint)puVar12 & 0xfffffffc) + 4);
              pEVar20 = dgst;
              puVar22 = (uint *)seed;
              do {
                uVar26 = *puVar22;
                uVar25 = uVar25 + 1;
                puVar22 = puVar22 + 1;
                pEVar20->type = uVar26 ^ pEVar20->type;
                pEVar20 = (EVP_MD *)&pEVar20->pkey_type;
              } while (uVar25 < uVar7 + 1);
              if (p_Stack_12c != p_Var4) {
                pcVar13 = p_Var4 + 1;
                p_Var4[(int)(dgst->required_pkey_type + -0xb)] =
                     (_func_1078)
                     (*(byte *)((int)seed + (uVar7 + 1) * 4) ^
                     (byte)p_Var4[(int)(dgst->required_pkey_type + -0xb)]);
                if ((int)pcVar13 < (int)p_Stack_12c) {
                  pcVar5 = p_Var4 + 2;
                  pcVar13[(int)(dgst->required_pkey_type + -0xb)] =
                       (code)((byte)*(code *)((int)seed + (int)pcVar13) ^
                             (byte)pcVar13[(int)(dgst->required_pkey_type + -0xb)]);
                  if ((int)pcVar5 < (int)p_Stack_12c) {
                    pcVar5[(int)(dgst->required_pkey_type + -0xb)] =
                         (code)((byte)*(code *)((int)seed + (int)pcVar5) ^
                               (byte)pcVar5[(int)(dgst->required_pkey_type + -0xb)]);
                  }
                }
              }
            }
            else {
              pEVar20 = dgst;
              puVar22 = (uint *)seed;
              do {
                pEVar16 = (EVP_MD *)((int)&pEVar20->type + 1);
                bVar19 = *(byte *)puVar22;
                puVar22 = (uint *)((int)puVar22 + 1);
                *(byte *)&pEVar20->type = *(byte *)&pEVar20->type ^ bVar19;
                pEVar20 = pEVar16;
              } while (pEVar16 != (EVP_MD *)(p_Var15 + (int)pEVar6));
            }
          }
          pEVar6 = &EStack_f0;
          pEVar20 = (EVP_MD *)(*(code *)PTR_EVP_sha1_006a86c4)();
          p_Stack_9c = (_func_1078 *)&DAT_00000014;
          pEVar23 = dgst;
          pcVar24 = (char *)p_Stack_12c;
          iVar2 = PKCS1_MGF1((uchar *)pEVar6,0x14,(uchar *)dgst,(long)p_Stack_12c,pEVar20);
          if (-1 < iVar2) {
            pEVar16 = pEVar6;
            if (((uint)pEStack_124 & 3) == 0) {
              *(uint *)(p_Var15 + 1) = EStack_f0.type ^ *(uint *)(p_Var15 + 1);
              *(uint *)(p_Var15 + 5) = *(uint *)(p_Var15 + 5) ^ EStack_f0.pkey_type;
              *(uint *)(p_Var15 + 9) = *(uint *)(p_Var15 + 9) ^ EStack_f0.md_size;
              *(uint *)(p_Var15 + 0xd) = *(uint *)(p_Var15 + 0xd) ^ EStack_f0.flags;
              *(uint *)(p_Var15 + 0x11) = *(uint *)(p_Var15 + 0x11) ^ (uint)EStack_f0.init;
              p_Stack_9c = EStack_f0.init;
              pcVar24 = (char *)EStack_f0.md_size;
              pEVar23 = pEStack_124;
            }
            else {
              do {
                pEVar23 = (EVP_MD *)((int)&pEStack_124->type + 1);
                *(byte *)&pEStack_124->type = *(byte *)&pEStack_124->type ^ *(byte *)&pEVar16->type;
                pEVar16 = (EVP_MD *)((int)&pEVar16->type + 1);
                EStack_f0.flags = EStack_f0.type;
                pEStack_124 = pEVar23;
              } while (dgst != pEVar23);
            }
            (*(code *)PTR_CRYPTO_free_006a7f88)(seed);
            iVar2 = 1;
            pEStack_138 = pEVar6;
            pEStack_124 = pEVar23;
            goto LAB_00512128;
          }
        }
        goto LAB_005120f4;
      }
      pcVar24 = "rsa_oaep.c";
      EStack_f0.flags = (ulong)&DAT_00000041;
      p_Stack_9c = (_func_1078 *)0x79;
      pEVar20 = (EVP_MD *)0x4c;
      (*(code *)PTR_ERR_put_error_006a9030)(4);
      iVar2 = 0;
      pEStack_138 = pEVar6;
    }
  }
  else {
    EStack_f0.flags = (ulong)&DAT_0000006e;
    pEVar20 = (EVP_MD *)&DAT_0000002d;
LAB_00512110:
    pcVar24 = "rsa_oaep.c";
    p_Stack_9c = (_func_1078 *)0x79;
    (*(code *)PTR_ERR_put_error_006a9030)(4);
    iVar2 = 0;
  }
LAB_00512128:
  if (EStack_f0.update == *(_func_1079 **)puStack_134) {
    return iVar2;
  }
  pcStack_114 = RSA_padding_check_PKCS1_OAEP;
  p_Var17 = EStack_f0.update;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar12 = PTR___stack_chk_guard_006aabf0;
  p_Var4 = (_func_1078 *)((int)&pEVar20[-1].md_ctrl + 3);
  iStack_13c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar2 = (int)p_Var4 - (int)pcVar24;
  p_Stack_130 = unaff_s2;
  pEStack_128 = dgst;
  puStack_120 = (uint *)seed;
  pEStack_11c = (EVP_MD *)seedlen;
  pEStack_118 = unaff_s8;
  p_Stack_10c = p_Stack_9c;
  if ((int)p_Var4 < 0x29) {
    (*(code *)PTR_ERR_put_error_006a9030)(4,0x7a,0x79,"rsa_oaep.c",0xb5);
    iVar2 = -1;
  }
  else {
    bVar1 = iVar2 < 0;
    if (bVar1) {
      iVar2 = 0;
      pcVar24 = (char *)p_Var4;
    }
    seedlen_00 = (undefined *)((int)pEVar20[-1].required_pkey_type + 0xb);
    puVar22 = (uint *)(*(code *)PTR_CRYPTO_malloc_006a8108)
                                (p_Var4 + (int)seedlen_00,"rsa_oaep.c",0x7c);
    if (puVar22 == (uint *)0x0) {
      (*(code *)PTR_ERR_put_error_006a9030)(4,0x7a,0x41,"rsa_oaep.c",0x7f);
      iVar2 = -1;
    }
    else {
      puVar29 = (uint *)((int)puVar22 + (int)seedlen_00);
      (*(code *)PTR_memset_006aab00)(puVar29,0,iVar2);
      seed_00 = puVar29 + 5;
      (*(code *)PTR_memcpy_006aabf4)((byte *)((int)puVar29 + iVar2),EStack_f0.flags,pcVar24);
      pEVar6 = (EVP_MD *)(*(code *)PTR_EVP_sha1_006a86c4)();
      iVar2 = PKCS1_MGF1((uchar *)&uStack_164,0x14,(uchar *)seed_00,(long)seedlen_00,pEVar6);
      if (iVar2 == 0) {
        if ((&uStack_164 < (uint *)((int)puVar22 + (int)((int)pEVar20[-1].required_pkey_type + 0xf))
             && puVar29 < &uStack_160) || (((uint)puVar29 & 3) != 0)) {
          puVar21 = &uStack_164;
          puVar28 = puVar29;
          do {
            puVar10 = (uint *)((int)puVar21 + 1);
            bVar19 = *(byte *)puVar28;
            puVar28 = (uint *)((int)puVar28 + 1);
            *(byte *)puVar21 = *(byte *)puVar21 ^ bVar19;
            puVar21 = puVar10;
          } while (puVar10 != auStack_150);
        }
        else {
          uStack_164 = uStack_164 ^ *puVar29;
          uStack_15c = uStack_15c ^ puVar29[2];
          uStack_160 = puVar29[1] ^ uStack_160;
          uStack_158 = uStack_158 ^ puVar29[3];
          uStack_154 = uStack_154 ^ puVar29[4];
        }
        pEVar6 = (EVP_MD *)(*(code *)PTR_EVP_sha1_006a86c4)();
        iVar2 = PKCS1_MGF1((uchar *)puVar22,(long)seedlen_00,(uchar *)&uStack_164,0x14,pEVar6);
        if (iVar2 == 0) {
          puVar21 = (uint *)((int)puVar22 + (int)p_Var4);
          if (0 < (int)seedlen_00) {
            if ((&DAT_00000006 < seedlen_00 &&
                 (puVar22 + 1 <= puVar21 || (int)((int)&pEVar20->type + 3) < 1)) &&
               ((((uint)puVar21 | (uint)puVar22) & 3) == 0)) {
              uVar25 = 0;
              uVar7 = ((uint)((int)pEVar20[-1].required_pkey_type + 7) >> 2) + 1;
              puVar18 = (undefined *)(uVar7 * 4);
              puVar29 = puVar22;
              do {
                uVar25 = uVar25 + 1;
                uVar26 = *puVar21;
                puVar21 = puVar21 + 1;
                *puVar29 = *puVar29 ^ uVar26;
                puVar29 = puVar29 + 1;
              } while (uVar25 < uVar7);
              if (puVar18 != seedlen_00) {
                puVar8 = puVar18 + 1;
                *(byte *)(puVar22 + uVar7) = *(byte *)(seed_00 + uVar7) ^ *(byte *)(puVar22 + uVar7)
                ;
                if ((int)puVar8 < (int)seedlen_00) {
                  puVar18 = puVar18 + 2;
                  *(byte *)((int)puVar22 + (int)puVar8) =
                       *(byte *)((int)seed_00 + (int)puVar8) ^ *(byte *)((int)puVar22 + (int)puVar8)
                  ;
                  if ((int)puVar18 < (int)seedlen_00) {
                    *(byte *)((int)puVar22 + (int)puVar18) =
                         *(byte *)((int)seed_00 + (int)puVar18) ^
                         *(byte *)((int)puVar22 + (int)puVar18);
                  }
                }
              }
            }
            else {
              puVar21 = puVar22;
              do {
                puVar28 = (uint *)((int)seed_00 + 1);
                *(byte *)puVar21 = *(byte *)puVar21 ^ *(byte *)seed_00;
                puVar21 = (uint *)((int)puVar21 + 1);
                seed_00 = puVar28;
              } while ((uint *)((int)puVar29 + (int)p_Var4) != puVar28);
            }
          }
          uVar9 = (*(code *)PTR_EVP_sha1_006a86c4)();
          iVar2 = (*(code *)PTR_EVP_Digest_006a8b04)(uStack_fc,&_gp,auStack_150,0,uVar9,0);
          if (iVar2 != 0) {
            iVar2 = (*(code *)PTR_CRYPTO_memcmp_006a9088)(puVar22,auStack_150,0x14);
            if ((iVar2 == 0) && (!bVar1)) {
              if ((int)seedlen_00 < 0x15) {
                if (seedlen_00 == &DAT_00000014) goto LAB_00512724;
                puVar18 = &DAT_00000014;
                bVar19 = *(byte *)(puVar22 + 5);
              }
              else {
                bVar19 = *(byte *)(puVar22 + 5);
                puVar18 = &DAT_00000014;
                if (bVar19 == 0) {
                  puVar18 = &DAT_00000014;
                  pbVar14 = (byte *)((int)puVar22 + 0x15);
                  do {
                    puVar18 = puVar18 + 1;
                    if (puVar18 == seedlen_00) goto LAB_00512724;
                    bVar19 = *pbVar14;
                    pbVar14 = pbVar14 + 1;
                  } while (bVar19 == 0);
                }
              }
              if (bVar19 == 1) {
                iVar2 = (int)seedlen_00 - (int)(puVar18 + 1);
                if ((int)p_Stack_10c < iVar2) {
                  iVar2 = -1;
                  (*(code *)PTR_ERR_put_error_006a9030)(4,0x7a,0x6d,"rsa_oaep.c",0xa8);
                }
                else {
                  (*(code *)PTR_memcpy_006aabf4)
                            (p_Var17,(byte *)((int)puVar22 + (int)(puVar18 + 1)),iVar2);
                }
                (*(code *)PTR_CRYPTO_free_006a7f88)(puVar22);
                goto LAB_00512758;
              }
            }
LAB_00512724:
            (*(code *)PTR_ERR_put_error_006a9030)(4,0x7a,0x79,"rsa_oaep.c",0xb5);
            (*(code *)PTR_CRYPTO_free_006a7f88)(puVar22);
          }
        }
      }
      iVar2 = -1;
    }
  }
LAB_00512758:
  if (iStack_13c == *(int *)puVar12) {
    return iVar2;
  }
  iVar2 = iStack_13c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if ((((*(int *)(iVar2 + 0x1c) == 0) || (*(int *)(iVar2 + 0x20) == 0)) ||
      (*(int *)(iVar2 + 0x10) == 0)) ||
     ((*(int *)(iVar2 + 0x14) == 0 || (*(int *)(iVar2 + 0x18) == 0)))) {
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
    iVar27 = -1;
    (*(code *)PTR_ERR_put_error_006a9030)(4,0x7b,0x41,"rsa_chk.c",0x4f);
    goto LAB_00512b20;
  }
  if (((b == (BIGNUM *)0x0) || (m == (BIGNUM *)0x0)) ||
     ((r_00 == (BIGNUM *)0x0 || ((a == (BIGNUM *)0x0 || (ctx == (BN_CTX *)0x0)))))) {
    (*(code *)PTR_ERR_put_error_006a9030)(4,0x7b,0x41,"rsa_chk.c",0x4f);
    goto LAB_00512b0c;
  }
  iVar3 = BN_is_prime_ex(*(BIGNUM **)(iVar2 + 0x1c),0,(BN_CTX *)0x0,(BN_GENCB *)0x0);
  if (iVar3 != 1) {
    iVar27 = iVar3;
    if (iVar3 == 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(4,0x7b,0x80,"rsa_chk.c",0x5a);
      goto LAB_00512ab0;
    }
    goto LAB_00512b14;
  }
LAB_00512ab0:
  iVar27 = BN_is_prime_ex(*(BIGNUM **)(iVar2 + 0x20),0,(BN_CTX *)0x0,(BN_GENCB *)0x0);
  if (iVar27 != 1) {
    if (iVar27 != 0) goto LAB_00512b14;
    (*(code *)PTR_ERR_put_error_006a9030)(4,0x7b,0x81,"rsa_chk.c",100);
    iVar3 = 0;
  }
  iVar27 = iVar3;
  iVar3 = BN_mul(r,*(BIGNUM **)(iVar2 + 0x1c),*(BIGNUM **)(iVar2 + 0x20),ctx);
  if (iVar3 == 0) {
LAB_00512b0c:
    iVar27 = -1;
  }
  else {
    iVar3 = BN_cmp(r,*(BIGNUM **)(iVar2 + 0x10));
    if (iVar3 != 0) {
      iVar27 = 0;
      (*(code *)PTR_ERR_put_error_006a9030)(4,0x7b,0x7f,"rsa_chk.c",0x6e);
    }
    uVar9 = *(undefined4 *)(iVar2 + 0x1c);
    pBVar11 = BN_value_one();
    iVar3 = (*(code *)PTR_BN_sub_006a96cc)(r,uVar9,pBVar11);
    if (iVar3 == 0) goto LAB_00512b0c;
    uVar9 = *(undefined4 *)(iVar2 + 0x20);
    pBVar11 = BN_value_one();
    iVar3 = (*(code *)PTR_BN_sub_006a96cc)(b,uVar9,pBVar11);
    if ((((iVar3 == 0) || (iVar3 = BN_mul(r_00,r,b,ctx), iVar3 == 0)) ||
        (iVar3 = (*(code *)PTR_BN_gcd_006a9840)(a,r,b,ctx), iVar3 == 0)) ||
       ((iVar3 = (*(code *)PTR_BN_div_006a967c)(m,0,r_00,a,ctx), iVar3 == 0 ||
        (iVar3 = BN_mod_mul(r,*(BIGNUM **)(iVar2 + 0x18),*(BIGNUM **)(iVar2 + 0x14),m,ctx),
        iVar3 == 0)))) goto LAB_00512b0c;
    if ((r->top != 1) || ((*r->d != 1 || (r->neg != 0)))) {
      iVar27 = 0;
      (*(code *)PTR_ERR_put_error_006a9030)(4,0x7b,0x7b,"rsa_chk.c",0x86);
    }
    if (((*(int *)(iVar2 + 0x24) != 0) && (*(int *)(iVar2 + 0x28) != 0)) &&
       (*(int *)(iVar2 + 0x2c) != 0)) {
      uVar9 = *(undefined4 *)(iVar2 + 0x1c);
      pBVar11 = BN_value_one();
      iVar3 = (*(code *)PTR_BN_sub_006a96cc)(r,uVar9,pBVar11);
      if ((iVar3 != 0) &&
         (iVar3 = (*(code *)PTR_BN_div_006a967c)(0,b,*(undefined4 *)(iVar2 + 0x18),r,ctx),
         iVar3 != 0)) {
        iVar3 = BN_cmp(b,*(BIGNUM **)(iVar2 + 0x24));
        if (iVar3 != 0) {
          iVar27 = 0;
          (*(code *)PTR_ERR_put_error_006a9030)(4,0x7b,0x7c,"rsa_chk.c",0x96);
        }
        uVar9 = *(undefined4 *)(iVar2 + 0x20);
        pBVar11 = BN_value_one();
        iVar3 = (*(code *)PTR_BN_sub_006a96cc)(r,uVar9,pBVar11);
        if ((iVar3 != 0) &&
           (iVar3 = (*(code *)PTR_BN_div_006a967c)(0,b,*(undefined4 *)(iVar2 + 0x18),r,ctx),
           iVar3 != 0)) {
          iVar3 = BN_cmp(b,*(BIGNUM **)(iVar2 + 0x28));
          if (iVar3 != 0) {
            iVar27 = 0;
            (*(code *)PTR_ERR_put_error_006a9030)(4,0x7b,0x7d,"rsa_chk.c",0xa4);
          }
          iVar3 = (*(code *)PTR_BN_mod_inverse_006a9714)
                            (r,*(undefined4 *)(iVar2 + 0x20),*(undefined4 *)(iVar2 + 0x1c),ctx);
          if (iVar3 != 0) {
            iVar2 = BN_cmp(r,*(BIGNUM **)(iVar2 + 0x2c));
            if (iVar2 != 0) {
              iVar27 = 0;
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
    return iVar27;
  }
  return iVar27;
}

