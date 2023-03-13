
int PKCS1_MGF1(uchar *mask,long len,uchar *seed,long seedlen,EVP_MD *dgst)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  _func_1078 *p_Var5;
  code *pcVar6;
  undefined *seedlen_00;
  EVP_MD *pEVar7;
  undefined *puVar8;
  uint *puVar9;
  BIGNUM *r;
  BIGNUM *b;
  BIGNUM *m;
  BIGNUM *r_00;
  BIGNUM *a;
  BN_CTX *ctx;
  BIGNUM *pBVar11;
  _func_1082 *p_Var12;
  undefined *puVar13;
  code *pcVar14;
  EVP_MD *pEVar15;
  _func_1079 *p_Var16;
  uint uVar17;
  undefined *puVar18;
  uint uVar19;
  EVP_MD *pEVar20;
  uint *puVar21;
  uint uVar22;
  uint uVar23;
  uint *puVar24;
  EVP_MD *pEVar25;
  char *pcVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  int iVar30;
  _func_1082 *unaff_s2;
  int unaff_s5;
  uint *puVar31;
  byte *pbVar32;
  EVP_MD *unaff_s8;
  undefined4 uVar33;
  uint uStack_1bc;
  uint uStack_1b8;
  uint uStack_1b4;
  uint uStack_1b0;
  uint uStack_1ac;
  uint auStack_1a8 [11];
  undefined auStack_17c [64];
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
  undefined4 uStack_fc;
  EVP_MD EStack_f0;
  _func_1078 *in_stack_ffffff64;
  EVP_MD_CTX EStack_88;
  undefined local_70;
  undefined local_6f;
  undefined local_6e;
  undefined local_6d;
  _func_1082 *local_2c;
  uint *puVar10;
  
  puVar13 = PTR___stack_chk_guard_006a9ae8;
  EStack_f0.copy = (_func_1081 *)&EStack_88;
  pEStack_124 = (EVP_MD *)&_gp;
  local_2c = *(_func_1082 **)PTR___stack_chk_guard_006a9ae8;
  pEVar20 = (EVP_MD *)len;
  puVar24 = (uint *)seed;
  pEVar15 = (EVP_MD *)seedlen;
  (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(EStack_f0.copy);
  iVar3 = (*pEStack_124[-0x179].md_ctrl)((EVP_MD_CTX *)dgst,(int)pEVar20,(int)puVar24,pEVar15);
  pEVar7 = pEVar20;
  EStack_f0.required_pkey_type[0] = unaff_s5;
  if (iVar3 < 0) {
LAB_0050ffc4:
    pEStack_138 = (EVP_MD *)0xffffffff;
  }
  else {
    iVar30 = 0;
    if (0 < len) {
      unaff_s8 = (EVP_MD *)&local_70;
      p_Var12 = (_func_1082 *)0x0;
      do {
        unaff_s2 = p_Var12;
        local_6d = (undefined)iVar30;
        puVar24 = (uint *)0x0;
        local_70 = (undefined)((uint)iVar30 >> 0x18);
        local_6f = (undefined)((uint)iVar30 >> 0x10);
        local_6e = (undefined)((uint)iVar30 >> 8);
        pEVar7 = dgst;
        iVar4 = (*pEStack_124[-0x196].sign)
                          ((int)EStack_f0.copy,(uchar *)dgst,0,(uchar *)pEVar15,(uint *)pEStack_124,
                           in_stack_ffffff64);
        EStack_f0.required_pkey_type[0] = iVar3;
        if ((iVar4 == 0) ||
           (pEVar7 = (EVP_MD *)seed, puVar24 = (uint *)seedlen,
           iVar4 = (*pEStack_124[-0x196].verify)
                             ((int)EStack_f0.copy,seed,seedlen,(uchar *)pEVar15,(uint)pEStack_124,
                              in_stack_ffffff64), iVar4 == 0)) goto LAB_0050ffc4;
        puVar24 = (uint *)&SUB_00000004;
        pEVar7 = unaff_s8;
        iVar4 = (*pEStack_124[-0x196].verify)
                          ((int)EStack_f0.copy,(uchar *)unaff_s8,4,(uchar *)pEVar15,
                           (uint)pEStack_124,in_stack_ffffff64);
        if (iVar4 == 0) goto LAB_0050ffc4;
        p_Var12 = unaff_s2 + iVar3;
        if (len < (int)p_Var12) {
          pEVar20 = (EVP_MD *)&stack0xffffff94;
          puVar24 = (uint *)0x0;
          pEVar7 = pEVar20;
          iVar3 = (*(code *)pEStack_124[-0x196].required_pkey_type[0])(EStack_f0.copy);
          if (iVar3 == 0) goto LAB_0050ffc4;
          puVar24 = (uint *)(len - (int)unaff_s2);
          (*(code *)pEStack_124[-0x118].required_pkey_type[0])(mask + (int)unaff_s2);
          break;
        }
        puVar24 = (uint *)0x0;
        pEVar20 = (EVP_MD *)(mask + (int)unaff_s2);
        iVar4 = (*(code *)pEStack_124[-0x196].required_pkey_type[0])(EStack_f0.copy);
        pEVar7 = pEVar20;
        if (iVar4 == 0) goto LAB_0050ffc4;
        iVar30 = iVar30 + 1;
      } while ((int)p_Var12 < len);
    }
    pEStack_138 = (EVP_MD *)0x0;
    pEVar7 = pEVar20;
  }
  (*pEStack_124[-0x1af].md_ctrl)((EVP_MD_CTX *)EStack_f0.copy,(int)pEVar7,(int)puVar24,pEVar15);
  if (local_2c == *(_func_1082 **)puVar13) {
    return (int)pEStack_138;
  }
  EStack_f0.required_pkey_type[4] = (int)RSA_padding_add_PKCS1_OAEP;
  p_Var12 = local_2c;
  (*(code *)pEStack_124[-0x119].required_pkey_type[4])();
  puStack_134 = PTR___stack_chk_guard_006a9ae8;
  puVar13 = PTR_EVP_sha1_006a75d0;
  EStack_f0.verify = (_func_1084 *)dgst;
  EStack_f0.update = *(_func_1079 **)PTR___stack_chk_guard_006a9ae8;
  p_Stack_12c = (_func_1078 *)((int)&pEVar7[-1].md_ctrl + 3);
  EStack_f0.final = (_func_1080 *)pEStack_138;
  EStack_f0.cleanup = unaff_s2;
  EStack_f0.sign = (_func_1083 *)len;
  EStack_f0.required_pkey_type[1] = (int)seed;
  EStack_f0.required_pkey_type[2] = seedlen;
  EStack_f0.required_pkey_type[3] = (int)unaff_s8;
  if ((int)pEVar15 < (int)((int)&pEVar7[-1].cleanup + 3)) {
    if ((int)p_Stack_12c < 0x29) {
      EStack_f0.flags = (ulong)&DAT_00000078;
      pEVar20 = (EVP_MD *)&DAT_00000031;
      goto LAB_005100a0;
    }
    dgst = (EVP_MD *)(p_Var12 + 0x15);
    *p_Var12 = (_func_1082)0x0;
    pEVar20 = (EVP_MD *)(*(code *)puVar13)();
    pcVar26 = (char *)0x0;
    uStack_fc = 0;
    pEVar25 = dgst;
    iVar3 = (*(code *)PTR_EVP_Digest_006a7a14)(pEStack_124);
    seed = (uchar *)puVar24;
    seedlen = (long)pEVar15;
    unaff_s2 = p_Var12;
    if (iVar3 == 0) {
LAB_00510084:
      EStack_f0.flags = (ulong)pEVar25;
      iVar3 = 0;
      pEStack_138 = pEVar7;
    }
    else {
      iVar3 = (int)p_Stack_12c - (int)pEVar15;
      pEStack_124 = (EVP_MD *)(p_Var12 + 1);
      (*(code *)PTR_memset_006a99f4)(p_Var12 + 0x29,0,iVar3 + -0x29);
      unaff_s8 = (EVP_MD *)((int)dgst + iVar3);
      *(undefined *)((int)unaff_s8[-1].required_pkey_type + 0xb) = 1;
      pEVar25 = pEVar15;
      (*(code *)PTR_memcpy_006a9aec)((byte *)((int)dgst + iVar3 + -0x14),puVar24);
      in_stack_ffffff64 = (_func_1078 *)&DAT_00000014;
      iVar3 = RAND_bytes((uchar *)pEStack_124,0x14);
      if (iVar3 < 1) goto LAB_00510084;
      seedlen = (long)(CAST_S_table3 + 0x110);
      p_Stack_12c = (_func_1078 *)((int)pEVar7[-1].required_pkey_type + 0xb);
      seed = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a7008)(p_Stack_12c,"rsa_oaep.c",0x47);
      if ((uint *)seed != (uint *)0x0) {
        pEVar20 = (EVP_MD *)(*(code *)PTR_EVP_sha1_006a75d0)();
        pcVar26 = &DAT_00000014;
        in_stack_ffffff64 = p_Stack_12c;
        pEVar25 = pEStack_124;
        iVar3 = PKCS1_MGF1(seed,(long)p_Stack_12c,(uchar *)pEStack_124,0x14,pEVar20);
        if (-1 < iVar3) {
          if (0 < (int)p_Stack_12c) {
            if ((&DAT_00000006 < p_Stack_12c &&
                 ((EVP_MD *)((int)seed + 4) <= dgst || p_Var12 + 0x19 <= seed)) &&
               (puVar13 = (undefined *)((int)pEVar7[-1].required_pkey_type + 7),
               (((uint)dgst | (uint)seed) & 3) == 0)) {
              uVar28 = 0;
              uVar17 = (uint)puVar13 >> 2;
              p_Var5 = (_func_1078 *)(((uint)puVar13 & 0xfffffffc) + 4);
              pEVar20 = dgst;
              puVar24 = (uint *)seed;
              do {
                uVar29 = *puVar24;
                uVar28 = uVar28 + 1;
                puVar24 = puVar24 + 1;
                pEVar20->type = uVar29 ^ pEVar20->type;
                pEVar20 = (EVP_MD *)&pEVar20->pkey_type;
              } while (uVar28 < uVar17 + 1);
              if (p_Stack_12c != p_Var5) {
                pcVar14 = p_Var5 + 1;
                p_Var5[(int)(dgst->required_pkey_type + -0xb)] =
                     (_func_1078)
                     (*(byte *)((int)seed + (uVar17 + 1) * 4) ^
                     (byte)p_Var5[(int)(dgst->required_pkey_type + -0xb)]);
                if ((int)pcVar14 < (int)p_Stack_12c) {
                  pcVar6 = p_Var5 + 2;
                  pcVar14[(int)(dgst->required_pkey_type + -0xb)] =
                       (code)((byte)*(code *)((int)seed + (int)pcVar14) ^
                             (byte)pcVar14[(int)(dgst->required_pkey_type + -0xb)]);
                  if ((int)pcVar6 < (int)p_Stack_12c) {
                    pcVar6[(int)(dgst->required_pkey_type + -0xb)] =
                         (code)((byte)*(code *)((int)seed + (int)pcVar6) ^
                               (byte)pcVar6[(int)(dgst->required_pkey_type + -0xb)]);
                  }
                }
              }
            }
            else {
              pEVar20 = dgst;
              puVar24 = (uint *)seed;
              do {
                pEVar15 = (EVP_MD *)((int)&pEVar20->type + 1);
                bVar1 = *(byte *)puVar24;
                puVar24 = (uint *)((int)puVar24 + 1);
                *(byte *)&pEVar20->type = *(byte *)&pEVar20->type ^ bVar1;
                pEVar20 = pEVar15;
              } while (pEVar15 != (EVP_MD *)(p_Var12 + (int)pEVar7));
            }
          }
          pEVar7 = &EStack_f0;
          pEVar20 = (EVP_MD *)(*(code *)PTR_EVP_sha1_006a75d0)();
          in_stack_ffffff64 = (_func_1078 *)&DAT_00000014;
          pEVar25 = dgst;
          pcVar26 = (char *)p_Stack_12c;
          iVar3 = PKCS1_MGF1((uchar *)pEVar7,0x14,(uchar *)dgst,(long)p_Stack_12c,pEVar20);
          if (-1 < iVar3) {
            pEVar15 = pEVar7;
            if (((uint)pEStack_124 & 3) == 0) {
              *(uint *)(p_Var12 + 1) = EStack_f0.type ^ *(uint *)(p_Var12 + 1);
              *(uint *)(p_Var12 + 5) = *(uint *)(p_Var12 + 5) ^ EStack_f0.pkey_type;
              *(uint *)(p_Var12 + 9) = *(uint *)(p_Var12 + 9) ^ EStack_f0.md_size;
              *(uint *)(p_Var12 + 0xd) = *(uint *)(p_Var12 + 0xd) ^ EStack_f0.flags;
              *(uint *)(p_Var12 + 0x11) = *(uint *)(p_Var12 + 0x11) ^ (uint)EStack_f0.init;
              in_stack_ffffff64 = EStack_f0.init;
              pcVar26 = (char *)EStack_f0.md_size;
              pEVar25 = pEStack_124;
            }
            else {
              do {
                pEVar25 = (EVP_MD *)((int)&pEStack_124->type + 1);
                *(byte *)&pEStack_124->type = *(byte *)&pEStack_124->type ^ *(byte *)&pEVar15->type;
                pEVar15 = (EVP_MD *)((int)&pEVar15->type + 1);
                EStack_f0.flags = EStack_f0.type;
                pEStack_124 = pEVar25;
              } while (dgst != pEVar25);
            }
            (*(code *)PTR_CRYPTO_free_006a6e88)(seed);
            iVar3 = 1;
            pEStack_138 = pEVar7;
            pEStack_124 = pEVar25;
            goto LAB_005100b8;
          }
        }
        goto LAB_00510084;
      }
      pcVar26 = "rsa_oaep.c";
      EStack_f0.flags = (ulong)&DAT_00000041;
      in_stack_ffffff64 = (_func_1078 *)&DAT_00000079;
      pEVar20 = (EVP_MD *)0x49;
      ERR_put_error(4,0x79,0x41,"rsa_oaep.c",0x49);
      iVar3 = 0;
      pEStack_138 = pEVar7;
    }
  }
  else {
    EStack_f0.flags = (ulong)&DAT_0000006e;
    pEVar20 = (EVP_MD *)&DAT_0000002c;
LAB_005100a0:
    pcVar26 = "rsa_oaep.c";
    in_stack_ffffff64 = (_func_1078 *)&DAT_00000079;
    (*(code *)PTR_ERR_put_error_006a7f34)(4);
    iVar3 = 0;
  }
LAB_005100b8:
  if (EStack_f0.update == *(_func_1079 **)puStack_134) {
    return iVar3;
  }
  pcStack_114 = RSA_padding_check_PKCS1_OAEP;
  p_Var16 = EStack_f0.update;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar13 = PTR___stack_chk_guard_006a9ae8;
  iStack_13c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar3 = -1;
  p_Stack_130 = unaff_s2;
  pEStack_128 = dgst;
  puStack_120 = (uint *)seed;
  pEStack_11c = (EVP_MD *)seedlen;
  pEStack_118 = unaff_s8;
  if ((0 < (int)in_stack_ffffff64) && (0 < (int)pcVar26)) {
    if (((int)pEVar20 < (int)pcVar26) ||
       (seedlen_00 = (undefined *)((int)pEVar20[-1].required_pkey_type + 0xb), (int)pEVar20 < 0x2a))
    {
      pbVar32 = (byte *)0x0;
      puVar24 = (uint *)0x0;
      goto LAB_00510448;
    }
    puVar24 = (uint *)(*(code *)PTR_CRYPTO_malloc_006a7008)(seedlen_00,"rsa_oaep.c",0x78);
    pbVar32 = (byte *)(*(code *)PTR_CRYPTO_malloc_006a7008)(pEVar20,"rsa_oaep.c",0x79);
    if ((puVar24 == (uint *)0x0) || (pbVar32 == (byte *)0x0)) {
      ERR_put_error(4,0x7a,0x41,"rsa_oaep.c",0x7b);
LAB_0051046c:
      iVar3 = -1;
      if (puVar24 != (uint *)0x0) goto LAB_00510474;
    }
    else {
      (*(code *)PTR_memset_006a99f4)(pbVar32,0,pEVar20);
      puVar31 = (uint *)(pbVar32 + 0x15);
      (*(code *)PTR_memcpy_006a9aec)
                (pbVar32 + ((int)pEVar20 - (int)pcVar26),EStack_f0.flags,pcVar26);
      bVar1 = *pbVar32;
      pEVar7 = (EVP_MD *)(*(code *)PTR_EVP_sha1_006a75d0)();
      iVar3 = PKCS1_MGF1((uchar *)&uStack_1bc,0x14,(uchar *)puVar31,(long)seedlen_00,pEVar7);
      if (iVar3 == 0) {
        puVar21 = (uint *)(pbVar32 + 1);
        if ((&uStack_1bc < pbVar32 + 5 && puVar21 < &uStack_1b8) || (((uint)puVar21 & 3) != 0)) {
          puVar10 = &uStack_1bc;
          do {
            puVar9 = (uint *)((int)puVar10 + 1);
            bVar2 = *(byte *)puVar21;
            puVar21 = (uint *)((int)puVar21 + 1);
            *(byte *)puVar10 = bVar2 ^ *(byte *)puVar10;
            puVar10 = puVar9;
          } while (puVar9 != auStack_1a8);
        }
        else {
          uStack_1bc = *(uint *)(pbVar32 + 1) ^ uStack_1bc;
          uStack_1b4 = uStack_1b4 ^ *(uint *)(pbVar32 + 9);
          uStack_1b8 = *(uint *)(pbVar32 + 5) ^ uStack_1b8;
          uStack_1b0 = uStack_1b0 ^ *(uint *)(pbVar32 + 0xd);
          uStack_1ac = uStack_1ac ^ *(uint *)(pbVar32 + 0x11);
        }
        pEVar7 = (EVP_MD *)(*(code *)PTR_EVP_sha1_006a75d0)();
        iVar3 = PKCS1_MGF1((uchar *)puVar24,(long)seedlen_00,(uchar *)&uStack_1bc,0x14,pEVar7);
        if (iVar3 == 0) {
          if (((((uint)puVar31 | (uint)puVar24) & 3) == 0) &&
             (pbVar32 + 0x19 <= puVar24 || puVar24 + 1 <= puVar31)) {
            uVar28 = 0;
            uVar17 = ((uint)((int)pEVar20[-1].required_pkey_type + 7) >> 2) + 1;
            puVar8 = (undefined *)(uVar17 * 4);
            puVar21 = puVar24;
            puVar10 = puVar31;
            do {
              uVar28 = uVar28 + 1;
              uVar29 = *puVar10;
              puVar10 = puVar10 + 1;
              *puVar21 = *puVar21 ^ uVar29;
              puVar21 = puVar21 + 1;
            } while (uVar28 < uVar17);
            if (puVar8 != seedlen_00) {
              puVar18 = puVar8 + 1;
              *(byte *)(puVar24 + uVar17) =
                   *(byte *)(puVar31 + uVar17) ^ *(byte *)(puVar24 + uVar17);
              if ((int)puVar18 < (int)seedlen_00) {
                puVar8 = puVar8 + 2;
                *(byte *)((int)puVar24 + (int)puVar18) =
                     *(byte *)((int)puVar31 + (int)puVar18) ^ *(byte *)((int)puVar24 + (int)puVar18)
                ;
                if ((int)puVar8 < (int)seedlen_00) {
                  *(byte *)((int)puVar24 + (int)puVar8) =
                       *(byte *)((int)puVar31 + (int)puVar8) ^ *(byte *)((int)puVar24 + (int)puVar8)
                  ;
                }
              }
            }
          }
          else {
            puVar21 = puVar24;
            do {
              bVar2 = *(byte *)puVar31;
              puVar31 = (uint *)((int)puVar31 + 1);
              *(byte *)puVar21 = bVar2 ^ *(byte *)puVar21;
              puVar21 = (uint *)((int)puVar21 + 1);
            } while ((uint *)(pbVar32 + (int)pEVar20) != puVar31);
          }
          uVar33 = (*(code *)PTR_EVP_sha1_006a75d0)();
          iVar3 = (*(code *)PTR_EVP_Digest_006a7a14)(uStack_fc,&_gp,auStack_17c,0,uVar33,0);
          if (iVar3 != 0) {
            uVar17 = (*(code *)PTR_CRYPTO_memcmp_006a8128)(puVar24,auStack_17c,0x14);
            puVar31 = puVar24 + 5;
            uVar29 = (int)(~uVar17 & uVar17 - 1 & ~(uint)bVar1 & bVar1 - 1) >> 0x1f;
            uVar17 = 0;
            uVar28 = 0;
            puVar8 = &DAT_00000014;
            do {
              uVar19 = (uint)*(byte *)puVar31;
              uVar27 = (uint)puVar8 ^ uVar28;
              uVar22 = ~uVar17;
              uVar23 = (int)(~(uVar19 ^ 1) & (uVar19 ^ 1) - 1) >> 0x1f;
              uVar17 = uVar17 | uVar23;
              puVar8 = puVar8 + 1;
              uVar28 = uVar22 & uVar27 & uVar23 ^ uVar28;
              uVar29 = uVar29 & ((int)(~uVar19 & uVar19 - 1) >> 0x1f | uVar17);
              puVar31 = (uint *)((int)puVar31 + 1);
            } while (puVar8 != seedlen_00);
            if ((uVar17 & uVar29) == 0) {
LAB_00510448:
              ERR_put_error(4,0x7a,0x79,"rsa_oaep.c",0xcb);
              goto LAB_0051046c;
            }
            iVar3 = (int)puVar8 - (uVar28 + 1);
            if ((int)in_stack_ffffff64 < iVar3) {
              ERR_put_error(4,0x7a,0x6d,"rsa_oaep.c",0xbf);
              goto LAB_00510448;
            }
            (*(code *)PTR_memcpy_006a9aec)(p_Var16,(byte *)((int)puVar24 + uVar28 + 1),iVar3);
            goto LAB_00510474;
          }
        }
      }
      iVar3 = -1;
LAB_00510474:
      (*(code *)PTR_CRYPTO_free_006a6e88)(puVar24);
    }
    if (pbVar32 != (byte *)0x0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)(pbVar32);
    }
  }
  if (iStack_13c == *(int *)puVar13) {
    return iVar3;
  }
  iVar3 = iStack_13c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if ((((*(int *)(iVar3 + 0x1c) == 0) || (*(int *)(iVar3 + 0x20) == 0)) ||
      (*(int *)(iVar3 + 0x10) == 0)) ||
     ((*(int *)(iVar3 + 0x14) == 0 || (*(int *)(iVar3 + 0x18) == 0)))) {
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
    iVar30 = -1;
    ERR_put_error(4,0x7b,0x41,"rsa_chk.c",0x4c);
    goto LAB_00510ac0;
  }
  if (((b == (BIGNUM *)0x0) || (m == (BIGNUM *)0x0)) ||
     ((r_00 == (BIGNUM *)0x0 || ((a == (BIGNUM *)0x0 || (ctx == (BN_CTX *)0x0)))))) {
    ERR_put_error(4,0x7b,0x41,"rsa_chk.c",0x4c);
    goto LAB_00510aac;
  }
  iVar4 = BN_is_prime_ex(*(BIGNUM **)(iVar3 + 0x1c),0,(BN_CTX *)0x0,(BN_GENCB *)0x0);
  if (iVar4 != 1) {
    iVar30 = iVar4;
    if (iVar4 == 0) {
      ERR_put_error(4,0x7b,0x80,"rsa_chk.c",0x56);
      goto LAB_00510a50;
    }
    goto LAB_00510ab4;
  }
LAB_00510a50:
  iVar30 = BN_is_prime_ex(*(BIGNUM **)(iVar3 + 0x20),0,(BN_CTX *)0x0,(BN_GENCB *)0x0);
  if (iVar30 != 1) {
    if (iVar30 != 0) goto LAB_00510ab4;
    ERR_put_error(4,0x7b,0x81,"rsa_chk.c",0x5f);
    iVar4 = 0;
  }
  iVar30 = iVar4;
  iVar4 = BN_mul(r,*(BIGNUM **)(iVar3 + 0x1c),*(BIGNUM **)(iVar3 + 0x20),ctx);
  if (iVar4 == 0) {
LAB_00510aac:
    iVar30 = -1;
  }
  else {
    iVar4 = BN_cmp(r,*(BIGNUM **)(iVar3 + 0x10));
    if (iVar4 != 0) {
      iVar30 = 0;
      ERR_put_error(4,0x7b,0x7f,"rsa_chk.c",0x6b);
    }
    uVar33 = *(undefined4 *)(iVar3 + 0x1c);
    pBVar11 = BN_value_one();
    iVar4 = (*(code *)PTR_BN_sub_006a85a8)(r,uVar33,pBVar11);
    if (iVar4 == 0) goto LAB_00510aac;
    uVar33 = *(undefined4 *)(iVar3 + 0x20);
    pBVar11 = BN_value_one();
    iVar4 = (*(code *)PTR_BN_sub_006a85a8)(b,uVar33,pBVar11);
    if ((((iVar4 == 0) || (iVar4 = BN_mul(r_00,r,b,ctx), iVar4 == 0)) ||
        (iVar4 = (*(code *)PTR_BN_gcd_006a871c)(a,r,b,ctx), iVar4 == 0)) ||
       ((iVar4 = (*(code *)PTR_BN_div_006a855c)(m,0,r_00,a,ctx), iVar4 == 0 ||
        (iVar4 = BN_mod_mul(r,*(BIGNUM **)(iVar3 + 0x18),*(BIGNUM **)(iVar3 + 0x14),m,ctx),
        iVar4 == 0)))) goto LAB_00510aac;
    if ((r->top != 1) || ((*r->d != 1 || (r->neg != 0)))) {
      iVar30 = 0;
      ERR_put_error(4,0x7b,0x7b,"rsa_chk.c",0x94);
    }
    if (((*(int *)(iVar3 + 0x24) != 0) && (*(int *)(iVar3 + 0x28) != 0)) &&
       (*(int *)(iVar3 + 0x2c) != 0)) {
      uVar33 = *(undefined4 *)(iVar3 + 0x1c);
      pBVar11 = BN_value_one();
      iVar4 = (*(code *)PTR_BN_sub_006a85a8)(r,uVar33,pBVar11);
      if ((iVar4 != 0) &&
         (iVar4 = (*(code *)PTR_BN_div_006a855c)(0,b,*(undefined4 *)(iVar3 + 0x18),r,ctx),
         iVar4 != 0)) {
        iVar4 = BN_cmp(b,*(BIGNUM **)(iVar3 + 0x24));
        if (iVar4 != 0) {
          iVar30 = 0;
          ERR_put_error(4,0x7b,0x7c,"rsa_chk.c",0xa7);
        }
        uVar33 = *(undefined4 *)(iVar3 + 0x20);
        pBVar11 = BN_value_one();
        iVar4 = (*(code *)PTR_BN_sub_006a85a8)(r,uVar33,pBVar11);
        if ((iVar4 != 0) &&
           (iVar4 = (*(code *)PTR_BN_div_006a855c)(0,b,*(undefined4 *)(iVar3 + 0x18),r,ctx),
           iVar4 != 0)) {
          iVar4 = BN_cmp(b,*(BIGNUM **)(iVar3 + 0x28));
          if (iVar4 != 0) {
            iVar30 = 0;
            ERR_put_error(4,0x7b,0x7d,"rsa_chk.c",0xb9);
          }
          iVar4 = (*(code *)PTR_BN_mod_inverse_006a85f0)
                            (r,*(undefined4 *)(iVar3 + 0x20),*(undefined4 *)(iVar3 + 0x1c),ctx);
          if (iVar4 != 0) {
            iVar3 = BN_cmp(r,*(BIGNUM **)(iVar3 + 0x2c));
            if (iVar3 != 0) {
              iVar30 = 0;
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
    return iVar30;
  }
  BN_CTX_free(ctx);
  return iVar30;
}

