
/* WARNING: Removing unreachable block (ram,0x00514a94) */

int RSA_blinding_on(RSA *rsa,BN_CTX *ctx)

{
  char cVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uVar4;
  void **ppvVar5;
  BIGNUM *pBVar6;
  int iVar7;
  BIGNUM *pBVar8;
  BIGNUM *pBVar9;
  BIGNUM *pBVar10;
  BIGNUM *a;
  BIGNUM *pBVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  char *pcVar15;
  ulong **ppuVar16;
  uint uVar17;
  BIGNUM *in_a2;
  char *in_a3;
  uint uVar18;
  int iVar19;
  BIGNUM *unaff_s3;
  BIGNUM *pBVar20;
  BN_BLINDING *unaff_s4;
  ulong *puVar21;
  BIGNUM *unaff_s6;
  BIGNUM *unaff_s7;
  BIGNUM *unaff_s8;
  uint num;
  double in_f12_13;
  BIGNUM *pBStack_1ec;
  BN_CTX *pBStack_1d0;
  BIGNUM *pBStack_1c0;
  BN_MONT_CTX *pBStack_1bc;
  BIGNUM *pBStack_1b8;
  int iStack_1b0;
  int iStack_1ac;
  BIGNUM *pBStack_1a8;
  BIGNUM *pBStack_1a4;
  BIGNUM *pBStack_18c;
  BIGNUM *pBStack_188;
  int iStack_184;
  BIGNUM BStack_17c;
  byte bStack_15d;
  undefined4 uStack_15c;
  uint uStack_158;
  uint uStack_154;
  uint uStack_150;
  uint uStack_14c;
  uint uStack_148;
  uint uStack_144;
  undefined4 uStack_140;
  undefined auStack_13c [32];
  undefined4 uStack_11c;
  uint uStack_118;
  uint uStack_114;
  uint uStack_110;
  uint uStack_10c;
  uint uStack_108;
  uint uStack_104;
  uint uStack_100;
  int iStack_fc;
  int iStack_f8;
  BIGNUM *pBStack_f4;
  BIGNUM *pBStack_f0;
  BIGNUM *pBStack_ec;
  BIGNUM *pBStack_e8;
  undefined *puStack_e4;
  BIGNUM *pBStack_e0;
  BIGNUM *pBStack_dc;
  BIGNUM *pBStack_d8;
  undefined4 uStack_d4;
  int in_stack_ffffff40;
  uint uStack_bc;
  int *piStack_b4;
  BIGNUM *pBStack_b0;
  BIGNUM *pBStack_ac;
  BIGNUM BStack_a8;
  int iStack_94;
  RSA *pRStack_90;
  BIGNUM *pBStack_8c;
  undefined *puStack_88;
  BIGNUM *pBStack_84;
  BN_BLINDING *pBStack_80;
  BN_CTX *pBStack_7c;
  BIGNUM *pBStack_78;
  BIGNUM *pBStack_74;
  BIGNUM *pBStack_70;
  code *pcStack_6c;
  BIGNUM local_40;
  int local_2c;
  
  pBStack_f0 = (BIGNUM *)PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  pBStack_e8 = (BIGNUM *)ctx;
  if (rsa->blinding != (BN_BLINDING *)0x0) {
    (*(code *)PTR_BN_BLINDING_free_006a984c)();
    rsa->blinding = (BN_BLINDING *)0x0;
    rsa->flags = rsa->flags & 0xfffffff7U | 0x80;
  }
  pBStack_8c = (BIGNUM *)ctx;
  if ((ctx == (BN_CTX *)0x0) && (pBStack_8c = (BIGNUM *)BN_CTX_new(), pBStack_8c == (BIGNUM *)0x0))
  {
    rsa->blinding = (BN_BLINDING *)0x0;
    iVar3 = 0;
  }
  else {
    BN_CTX_start((BN_CTX *)pBStack_8c);
    unaff_s3 = BN_CTX_get((BN_CTX *)pBStack_8c);
    if (unaff_s3 == (BIGNUM *)0x0) {
      in_a2 = (BIGNUM *)&DAT_00000041;
      iVar3 = 0xd0;
LAB_00513a40:
      in_a3 = "rsa_crpt.c";
      pBStack_e8 = (BIGNUM *)&DAT_00000088;
      unaff_s4 = (BN_BLINDING *)0x0;
      ERR_put_error(4,0x88,(int)in_a2,"rsa_crpt.c",iVar3);
    }
    else {
      pBVar20 = rsa->e;
      unaff_s3 = pBVar20;
      if (pBVar20 == (BIGNUM *)0x0) {
        unaff_s6 = rsa->d;
        unaff_s7 = rsa->p;
        pBVar6 = rsa->q;
        if (((unaff_s6 != (BIGNUM *)0x0) && (unaff_s7 != (BIGNUM *)0x0)) &&
           (pBVar6 != (BIGNUM *)0x0)) {
          BN_CTX_start((BN_CTX *)pBStack_8c);
          pBVar8 = BN_CTX_get((BN_CTX *)pBStack_8c);
          pBVar9 = BN_CTX_get((BN_CTX *)pBStack_8c);
          unaff_s8 = BN_CTX_get((BN_CTX *)pBStack_8c);
          if (unaff_s8 != (BIGNUM *)0x0) {
            pBVar10 = BN_value_one();
            iVar3 = (*(code *)PTR_BN_sub_006a96cc)(pBVar9,unaff_s7,pBVar10);
            if (iVar3 != 0) {
              pBVar10 = BN_value_one();
              iVar3 = (*(code *)PTR_BN_sub_006a96cc)(unaff_s8,pBVar6,pBVar10);
              if ((iVar3 != 0) &&
                 (iVar3 = BN_mul(pBVar8,pBVar9,unaff_s8,(BN_CTX *)pBStack_8c), iVar3 != 0)) {
                unaff_s3 = (BIGNUM *)
                           (*(code *)PTR_BN_mod_inverse_006a9714)(0,unaff_s6,pBVar8,pBStack_8c);
                BN_CTX_end((BN_CTX *)pBStack_8c);
                if (unaff_s3 != (BIGNUM *)0x0) goto LAB_005137f4;
                goto LAB_00513a30;
              }
            }
          }
          BN_CTX_end((BN_CTX *)pBStack_8c);
        }
LAB_00513a30:
        in_a2 = (BIGNUM *)&DAT_0000008c;
        iVar3 = 0xd9;
        unaff_s3 = pBVar20;
        goto LAB_00513a40;
      }
LAB_005137f4:
      iVar3 = RAND_status();
      if (((iVar3 == 0) && (pBVar20 = rsa->d, pBVar20 != (BIGNUM *)0x0)) &&
         (pBVar20->d != (ulong *)0x0)) {
        RAND_add(pBVar20->d,pBVar20->dmax << 2,in_f12_13);
      }
      in_a2 = &local_40;
      if ((rsa->flags & 0x100U) == 0) {
        pBVar20 = rsa->n;
        local_40.d = pBVar20->d;
        local_40.top = pBVar20->top;
        local_40.dmax = pBVar20->dmax;
        local_40.neg = pBVar20->neg;
        local_40.flags = local_40.flags & 1U | pBVar20->flags & 0xfffffffeU | 6;
      }
      else {
        in_a2 = rsa->n;
      }
      pBStack_e8 = unaff_s3;
      in_a3 = (char *)pBStack_8c;
      unaff_s4 = (BN_BLINDING *)(*(code *)PTR_BN_BLINDING_create_param_006a9864)(0);
      if (unaff_s4 == (BN_BLINDING *)0x0) {
        in_a2 = (BIGNUM *)0x0;
        in_a3 = "rsa_crpt.c";
        pBStack_e8 = (BIGNUM *)&DAT_00000088;
        ERR_put_error(4,0x88,3,"rsa_crpt.c",0xf5);
      }
      else {
        uVar4 = (*(code *)PTR_BN_BLINDING_thread_id_006a9800)(unaff_s4);
        (*(code *)PTR_CRYPTO_THREADID_current_006a95ac)(uVar4);
      }
    }
    BN_CTX_end((BN_CTX *)pBStack_8c);
    if (ctx == (BN_CTX *)0x0) {
      BN_CTX_free((BN_CTX *)pBStack_8c);
    }
    if (rsa->e == (BIGNUM *)0x0) {
      BN_free(unaff_s3);
    }
    rsa->blinding = unaff_s4;
    if (unaff_s4 == (BN_BLINDING *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = 1;
      rsa->flags = rsa->flags & 0xffffff7fU | 8;
    }
  }
  if (local_2c == *(int *)pBStack_f0) {
    return iVar3;
  }
  pcStack_6c = RSA_setup_blinding;
  iStack_f8 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_e4 = PTR___stack_chk_guard_006aabf0;
  puStack_88 = (undefined *)pBStack_f0;
  iStack_94 = *(int *)PTR___stack_chk_guard_006aabf0;
  pBStack_f4 = pBStack_e8;
  pRStack_90 = rsa;
  pBStack_84 = unaff_s3;
  pBStack_80 = unaff_s4;
  pBStack_7c = ctx;
  pBStack_78 = unaff_s6;
  pBStack_74 = unaff_s7;
  pBStack_70 = unaff_s8;
  if ((pBStack_e8 == (BIGNUM *)0x0) &&
     (pBVar20 = pBStack_e8, pBStack_f4 = (BIGNUM *)BN_CTX_new(), pBStack_f4 == (BIGNUM *)0x0)) {
    pBVar6 = (BIGNUM *)0x0;
  }
  else {
    BN_CTX_start((BN_CTX *)pBStack_f4);
    unaff_s3 = BN_CTX_get((BN_CTX *)pBStack_f4);
    if (unaff_s3 == (BIGNUM *)0x0) {
      in_a2 = (BIGNUM *)&DAT_00000041;
      in_stack_ffffff40 = 0xd0;
LAB_00513e14:
      in_a3 = "rsa_crpt.c";
      pBVar20 = (BIGNUM *)&DAT_00000088;
      pBVar6 = (BIGNUM *)0x0;
      ERR_put_error(4,0x88,(int)in_a2,"rsa_crpt.c",in_stack_ffffff40);
    }
    else {
      pBVar20 = *(BIGNUM **)(iStack_f8 + 0x14);
      unaff_s3 = pBVar20;
      if (pBVar20 == (BIGNUM *)0x0) {
        unaff_s6 = *(BIGNUM **)(iStack_f8 + 0x18);
        unaff_s7 = *(BIGNUM **)(iStack_f8 + 0x1c);
        iVar3 = *(int *)(iStack_f8 + 0x20);
        if (((unaff_s6 != (BIGNUM *)0x0) && (unaff_s7 != (BIGNUM *)0x0)) && (iVar3 != 0)) {
          BN_CTX_start((BN_CTX *)pBStack_f4);
          pBStack_ac = BN_CTX_get((BN_CTX *)pBStack_f4);
          pBStack_b0 = BN_CTX_get((BN_CTX *)pBStack_f4);
          unaff_s8 = BN_CTX_get((BN_CTX *)pBStack_f4);
          if (unaff_s8 != (BIGNUM *)0x0) {
            pBVar6 = BN_value_one();
            iVar7 = (*(code *)PTR_BN_sub_006a96cc)(pBStack_b0,unaff_s7,pBVar6);
            if (iVar7 != 0) {
              pBVar6 = BN_value_one();
              iVar3 = (*(code *)PTR_BN_sub_006a96cc)(unaff_s8,iVar3,pBVar6);
              if ((iVar3 != 0) &&
                 (iVar3 = BN_mul(pBStack_ac,pBStack_b0,unaff_s8,(BN_CTX *)pBStack_f4), iVar3 != 0))
              {
                unaff_s3 = (BIGNUM *)
                           (*(code *)PTR_BN_mod_inverse_006a9714)(0,unaff_s6,pBStack_ac,pBStack_f4);
                BN_CTX_end((BN_CTX *)pBStack_f4);
                if (unaff_s3 != (BIGNUM *)0x0) goto LAB_00513bec;
                goto LAB_00513e04;
              }
            }
          }
          BN_CTX_end((BN_CTX *)pBStack_f4);
        }
LAB_00513e04:
        in_a2 = (BIGNUM *)&DAT_0000008c;
        in_stack_ffffff40 = 0xd9;
        unaff_s3 = pBVar20;
        goto LAB_00513e14;
      }
LAB_00513bec:
      iVar3 = RAND_status();
      if (((iVar3 == 0) && (ppvVar5 = *(void ***)(iStack_f8 + 0x18), ppvVar5 != (void **)0x0)) &&
         (*ppvVar5 != (void *)0x0)) {
        RAND_add(*ppvVar5,(int)ppvVar5[2] << 2,in_f12_13);
      }
      in_a2 = &BStack_a8;
      if ((*(uint *)(iStack_f8 + 0x3c) & 0x100) == 0) {
        ppuVar16 = *(ulong ***)(iStack_f8 + 0x10);
        BStack_a8.d = *ppuVar16;
        BStack_a8.top = (int)ppuVar16[1];
        BStack_a8.dmax = (int)ppuVar16[2];
        BStack_a8.neg = (int)ppuVar16[3];
        BStack_a8.flags = BStack_a8.flags & 1U | (uint)ppuVar16[4] & 0xfffffffe | 6;
      }
      else {
        in_a2 = *(BIGNUM **)(iStack_f8 + 0x10);
      }
      uStack_bc = *(uint *)(iStack_f8 + 0x40);
      in_stack_ffffff40 = *(int *)(*(int *)(iStack_f8 + 8) + 0x18);
      pBVar20 = unaff_s3;
      in_a3 = (char *)pBStack_f4;
      pBVar6 = (BIGNUM *)(*(code *)PTR_BN_BLINDING_create_param_006a9864)(0);
      if (pBVar6 == (BIGNUM *)0x0) {
        in_a2 = (BIGNUM *)0x0;
        in_a3 = "rsa_crpt.c";
        in_stack_ffffff40 = 0xf5;
        pBVar20 = (BIGNUM *)&DAT_00000088;
        ERR_put_error(4,0x88,3,"rsa_crpt.c",0xf5);
      }
      else {
        uVar4 = (*(code *)PTR_BN_BLINDING_thread_id_006a9800)(pBVar6);
        (*(code *)PTR_CRYPTO_THREADID_current_006a95ac)(uVar4);
      }
    }
    BN_CTX_end((BN_CTX *)pBStack_f4);
    if (pBStack_e8 == (BIGNUM *)0x0) {
      BN_CTX_free((BN_CTX *)pBStack_f4);
    }
    pBStack_f0 = pBVar6;
    if (*(int *)(iStack_f8 + 0x14) == 0) {
      BN_free(unaff_s3);
      pBStack_b0 = pBVar6;
    }
  }
  if (iStack_94 == *(int *)puStack_e4) {
    return (int)pBVar6;
  }
  uStack_d4 = 0x513f38;
  iVar3 = iStack_94;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar2 = PTR___stack_chk_guard_006aabf0;
  num = (uint)in_a2 >> 3;
  iStack_fc = *(int *)PTR___stack_chk_guard_006aabf0;
  pBStack_ec = unaff_s3;
  pBStack_e0 = unaff_s6;
  pBStack_dc = unaff_s7;
  pBStack_d8 = unaff_s8;
  if (((num & 0xfffffff7) != 0x14) && (iVar7 = 0, num != 0x20)) goto LAB_00513fe0;
  pBStack_1ec = (BIGNUM *)in_a3;
  if ((BIGNUM *)in_a3 == (BIGNUM *)0x0) {
    pBStack_1ec = (BIGNUM *)(*(code *)PTR_EVP_sha1_006a86c4)();
  }
  if (pBVar20 < (BIGNUM *)0x200) {
    uVar18 = 0x200;
    if (uStack_bc == 0) goto LAB_00514084;
LAB_0051403c:
    if (num <= uStack_bc) {
      if (num < uStack_bc) {
        uStack_bc = num;
      }
      goto LAB_00514084;
    }
    if (num < uStack_bc) {
      uStack_bc = num;
    }
    pBStack_1d0 = BN_CTX_new();
  }
  else {
    uVar18 = (uint)((int)&pBVar20[3].d + 3) & 0xffffffc0;
    if (uStack_bc != 0) goto LAB_0051403c;
LAB_00514084:
    if (in_stack_ffffff40 != 0) {
      (*(code *)PTR___memcpy_chk_006aab54)(&BStack_17c,in_stack_ffffff40,uStack_bc,0x20);
    }
    pBStack_1d0 = BN_CTX_new();
  }
  if (pBStack_1d0 != (BN_CTX *)0x0) {
    pBStack_1bc = BN_MONT_CTX_new();
    if (pBStack_1bc == (BN_MONT_CTX *)0x0) goto LAB_0051479c;
    uVar18 = uVar18 - 1;
    BN_CTX_start(pBStack_1d0);
    pBStack_1a8 = BN_CTX_get(pBStack_1d0);
    pBVar20 = BN_CTX_get(pBStack_1d0);
    pBVar6 = BN_CTX_get(pBStack_1d0);
    pBVar8 = BN_CTX_get(pBStack_1d0);
    pBVar9 = BN_CTX_get(pBStack_1d0);
    pBVar10 = BN_CTX_get(pBStack_1d0);
    a = BN_CTX_get(pBStack_1d0);
    pBStack_1a4 = BN_CTX_get(pBStack_1d0);
    pBVar11 = BN_value_one();
    iVar7 = BN_lshift(pBStack_1a4,pBVar11,uVar18);
    pBStack_1c0 = pBVar6;
    if (iVar7 == 0) goto LAB_0051479c;
    iStack_1b0 = 0;
    uVar17 = num - 1;
    iVar7 = (num - 4 >> 2) + 1;
    do {
      iVar12 = BN_GENCB_call((BN_GENCB *)pBStack_ac,0,iStack_1b0);
      pBStack_1b8 = pBVar8;
      pBStack_18c = a;
      pBStack_188 = pBVar20;
      iStack_184 = iVar3;
      if (iVar12 == 0) goto LAB_0051479c;
      pBStack_1c0 = &BStack_17c;
      if (uStack_bc == 0) {
        RAND_pseudo_bytes((uchar *)pBStack_1c0,num);
      }
      (*(code *)PTR___memcpy_chk_006aab54)(auStack_13c,pBStack_1c0,num,0x20);
      (*(code *)PTR___memcpy_chk_006aab54)(&uStack_11c,pBStack_1c0,num,0x20);
      if ((uVar17 != 0xffffffff) &&
         (cVar1 = auStack_13c[num - 1], auStack_13c[num - 1] = cVar1 + '\x01',
         (char)(cVar1 + '\x01') == '\0')) {
        pcVar15 = auStack_13c + (num - 2);
        do {
          if (pcVar15 == (char *)((int)&uStack_140 + 3)) break;
          cVar1 = *pcVar15;
          *pcVar15 = cVar1 + '\x01';
          pcVar15 = pcVar15 + -1;
        } while ((char)(cVar1 + '\x01') == '\0');
      }
      iVar12 = (*(code *)PTR_EVP_Digest_006a8b04)(pBStack_1c0,num,&uStack_15c,0,pBStack_1ec,0);
      if (iVar12 == 0) goto LAB_0051479c;
      iVar12 = (*(code *)PTR_EVP_Digest_006a8b04)(auStack_13c,num,&uStack_11c,0,pBStack_1ec,0);
      if (iVar12 == 0) goto LAB_0051479c;
      if (num != 0) {
        if (uVar17 < 3) {
          uVar14 = 0;
        }
        else {
          uStack_15c = uStack_11c ^ uStack_15c;
          if (((((iVar7 != 1) && (uStack_158 = uStack_118 ^ uStack_158, iVar7 != 2)) &&
               (uStack_154 = uStack_154 ^ uStack_114, iVar7 != 3)) &&
              ((uStack_150 = uStack_150 ^ uStack_110, iVar7 != 4 &&
               (uStack_14c = uStack_14c ^ uStack_10c, iVar7 != 5)))) &&
             ((uStack_148 = uStack_148 ^ uStack_108, iVar7 != 6 &&
              (uStack_144 = uStack_144 ^ uStack_104, iVar7 != 7)))) {
            uStack_140 = uStack_140 ^ uStack_100;
          }
          uVar14 = iVar7 * 4;
          if (num == iVar7 * 4) goto LAB_00514484;
        }
        *(byte *)((int)&uStack_15c + uVar14) =
             *(byte *)((int)&uStack_11c + uVar14) ^ *(byte *)((int)&uStack_15c + uVar14);
        if ((int)(uVar14 + 1) < (int)num) {
          *(byte *)((int)&uStack_15c + uVar14 + 1) =
               *(byte *)((int)&uStack_11c + uVar14 + 1) ^ *(byte *)((int)&uStack_15c + uVar14 + 1);
          if ((int)(uVar14 + 2) < (int)num) {
            *(byte *)((int)&uStack_15c + uVar14 + 2) =
                 *(byte *)((int)&uStack_15c + uVar14 + 2) ^ *(byte *)((int)&uStack_11c + uVar14 + 2)
            ;
          }
        }
      }
LAB_00514484:
      uStack_15c = uStack_15c | 0x80000000;
      (&bStack_15d)[num] = (&bStack_15d)[num] | 1;
      pBVar11 = BN_bin2bn((uchar *)&uStack_15c,num,pBVar8);
      if (pBVar11 == (BIGNUM *)0x0) goto LAB_0051479c;
      iVar12 = BN_is_prime_fasttest_ex
                         (pBVar8,0x32,pBStack_1d0,(uint)(uStack_bc == 0),(BN_GENCB *)pBStack_ac);
      if (0 < iVar12) {
        iVar12 = BN_GENCB_call((BN_GENCB *)pBStack_ac,2,0);
        if (iVar12 == 0) goto LAB_0051479c;
        iVar12 = BN_GENCB_call((BN_GENCB *)pBStack_ac,3,0);
        if (iVar12 == 0) goto LAB_0051479c;
        iStack_1ac = 0;
        do {
          iVar12 = 0;
          BN_set_word(pBVar6,0);
          iVar19 = 0;
          do {
            if ((uVar17 != 0xffffffff) &&
               (cVar1 = auStack_13c[num - 1], auStack_13c[num - 1] = cVar1 + '\x01',
               (char)(cVar1 + '\x01') == '\0')) {
              pcVar15 = auStack_13c + (num - 2);
              do {
                if ((char *)((int)&uStack_140 + 3) == pcVar15) break;
                cVar1 = *pcVar15;
                *pcVar15 = cVar1 + '\x01';
                pcVar15 = pcVar15 + -1;
              } while ((char)(cVar1 + '\x01') == '\0');
            }
            iVar13 = (*(code *)PTR_EVP_Digest_006a8b04)(auStack_13c,num,&uStack_15c,0,pBStack_1ec,0)
            ;
            if (iVar13 == 0) goto LAB_0051479c;
            pBVar11 = BN_bin2bn((uchar *)&uStack_15c,num,pBStack_1a8);
            if (pBVar11 == (BIGNUM *)0x0) goto LAB_0051479c;
            iVar13 = BN_lshift(pBStack_1a8,pBStack_1a8,iVar12);
            if (iVar13 == 0) goto LAB_0051479c;
            iVar13 = (*(code *)PTR_BN_add_006a96c8)(pBVar6,pBVar6,pBStack_1a8);
            if (iVar13 == 0) goto LAB_0051479c;
            iVar19 = iVar19 + 1;
            iVar12 = iVar12 + ((uint)in_a2 & 0xfffffff8);
          } while (iVar19 <= (int)(uVar18 / 0xa0));
          iVar12 = BN_mask_bits(pBVar6,uVar18);
          if (iVar12 == 0) goto LAB_0051479c;
          pBVar11 = BN_copy(pBVar9,pBVar6);
          if (pBVar11 == (BIGNUM *)0x0) goto LAB_0051479c;
          iVar12 = (*(code *)PTR_BN_add_006a96c8)(pBVar9,pBVar9,pBStack_1a4);
          if (iVar12 == 0) goto LAB_0051479c;
          iVar12 = BN_lshift1(pBStack_1a8,pBVar8);
          if (iVar12 == 0) goto LAB_0051479c;
          iVar12 = (*(code *)PTR_BN_div_006a967c)(0,pBVar10,pBVar9,pBStack_1a8,pBStack_1d0);
          if (iVar12 == 0) goto LAB_0051479c;
          pBVar11 = BN_value_one();
          iVar12 = (*(code *)PTR_BN_sub_006a96cc)(pBStack_1a8,pBVar10,pBVar11);
          if (iVar12 == 0) goto LAB_0051479c;
          iVar12 = (*(code *)PTR_BN_sub_006a96cc)(a,pBVar9,pBStack_1a8);
          if (iVar12 == 0) goto LAB_0051479c;
          iVar12 = BN_cmp(a,pBStack_1a4);
          if (-1 < iVar12) {
            iVar12 = BN_is_prime_fasttest_ex(a,0x32,pBStack_1d0,1,(BN_GENCB *)pBStack_ac);
            if (0 < iVar12) goto LAB_0051484c;
            if (iVar12 != 0) goto LAB_0051479c;
          }
          iStack_1ac = iStack_1ac + 1;
          if (iStack_1ac == 0x1000) goto LAB_005144ec;
          iVar12 = BN_GENCB_call((BN_GENCB *)pBStack_ac,0,iStack_1ac);
          if (iVar12 == 0) goto LAB_0051479c;
        } while( true );
      }
      if (iVar12 != 0) goto LAB_0051479c;
LAB_005144ec:
      uStack_bc = 0;
      iStack_1b0 = iStack_1b0 + 1;
    } while( true );
  }
  iVar7 = 0;
LAB_00513fe0:
  do {
    if (iStack_fc == *(int *)puVar2) {
      return iVar7;
    }
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_0051484c:
    iVar3 = BN_GENCB_call((BN_GENCB *)pBStack_ac,2,1);
    if (iVar3 != 0) {
      pBVar20 = BN_value_one();
      iVar3 = (*(code *)PTR_BN_sub_006a96cc)(pBStack_1a4,pBStack_18c,pBVar20);
      if ((((iVar3 != 0) &&
           (iVar3 = (*(code *)PTR_BN_div_006a967c)
                              (pBStack_1a8,0,pBStack_1a4,pBStack_1b8,pBStack_1d0), iVar3 != 0)) &&
          (iVar3 = BN_set_word(pBStack_1a4,2), iVar3 != 0)) &&
         (iVar3 = BN_MONT_CTX_set(pBStack_1bc,pBStack_18c,pBStack_1d0), iVar3 != 0)) {
        puVar21 = (ulong *)0x2;
        while (iVar3 = (*(code *)PTR_BN_mod_exp_mont_006a96f4)
                                 (pBStack_188,pBStack_1a4,pBStack_1a8,pBStack_18c,pBStack_1d0,
                                  pBStack_1bc), iVar3 != 0) {
          if (((pBStack_188->top != 1) || (*pBStack_188->d != 1)) || (pBStack_188->neg != 0)) {
            iVar3 = BN_GENCB_call((BN_GENCB *)pBStack_ac,3,1);
            if (iVar3 != 0) {
              if (*(BIGNUM **)(iStack_184 + 0xc) != (BIGNUM *)0x0) {
                BN_free(*(BIGNUM **)(iStack_184 + 0xc));
              }
              if (*(BIGNUM **)(iStack_184 + 0x10) != (BIGNUM *)0x0) {
                BN_free(*(BIGNUM **)(iStack_184 + 0x10));
              }
              if (*(BIGNUM **)(iStack_184 + 0x14) != (BIGNUM *)0x0) {
                BN_free(*(BIGNUM **)(iStack_184 + 0x14));
              }
              pBVar20 = BN_dup(pBStack_18c);
              *(BIGNUM **)(iStack_184 + 0xc) = pBVar20;
              pBVar20 = BN_dup(pBStack_1b8);
              *(BIGNUM **)(iStack_184 + 0x10) = pBVar20;
              pBVar20 = BN_dup(pBStack_188);
              *(BIGNUM **)(iStack_184 + 0x14) = pBVar20;
              if (*(int *)(iStack_184 + 0xc) != 0) {
                iVar7 = 0;
                if ((*(int *)(iStack_184 + 0x10) != 0) && (pBVar20 != (BIGNUM *)0x0)) {
                  if (piStack_b4 != (int *)0x0) {
                    *piStack_b4 = iStack_1ac;
                  }
                  if (pBStack_b0 != (BIGNUM *)0x0) {
                    pBStack_b0->d = puVar21;
                  }
                  iVar7 = 1;
                  (*(code *)PTR_memcpy_006aabf4)(&_gp,pBStack_1c0,num);
                }
                goto LAB_005147a0;
              }
            }
            break;
          }
          pBVar20 = BN_value_one();
          iVar3 = (*(code *)PTR_BN_add_006a96c8)(pBStack_1a4,pBStack_1a4,pBVar20);
          if (iVar3 == 0) break;
          puVar21 = (ulong *)((int)puVar21 + 1);
        }
      }
    }
LAB_0051479c:
    iVar7 = 0;
LAB_005147a0:
    BN_CTX_end(pBStack_1d0);
    BN_CTX_free(pBStack_1d0);
    if (pBStack_1bc != (BN_MONT_CTX *)0x0) {
      BN_MONT_CTX_free(pBStack_1bc);
    }
  } while( true );
}

