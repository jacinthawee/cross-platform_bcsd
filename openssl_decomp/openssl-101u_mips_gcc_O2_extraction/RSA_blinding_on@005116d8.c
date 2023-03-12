
/* WARNING: Removing unreachable block (ram,0x00512a48) */

int RSA_blinding_on(RSA *rsa,BN_CTX *ctx)

{
  char cVar1;
  undefined *puVar2;
  int iVar3;
  BIGNUM *pBVar4;
  undefined4 uVar5;
  void **ppvVar6;
  EVP_MD *pEVar7;
  int iVar8;
  EVP_MD *pEVar9;
  undefined *n;
  BIGNUM *pBVar10;
  BIGNUM *pBVar11;
  BIGNUM *pBVar12;
  BIGNUM *pBVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  char *pcVar18;
  ulong **ppuVar19;
  uint uVar20;
  BIGNUM *in_a2;
  char *in_a3;
  EVP_MD *ret;
  EVP_MD *pEVar21;
  EVP_MD *unaff_s3;
  EVP_MD *pEVar22;
  EVP_MD *pEVar23;
  BN_BLINDING *unaff_s4;
  BIGNUM *unaff_s6;
  BIGNUM *unaff_s7;
  BIGNUM *unaff_s8;
  uint count;
  double in_f12_13;
  EVP_MD *pEStack_1ec;
  int iStack_1dc;
  BN_MONT_CTX *pBStack_1c0;
  EVP_MD *pEStack_1bc;
  uchar *puStack_1b8;
  int iStack_1ac;
  int iStack_1a8;
  uchar auStack_17c [31];
  byte bStack_15d;
  undefined auStack_15c [2];
  byte abStack_15a [2];
  uint uStack_158;
  uint uStack_154;
  uint uStack_150;
  _func_1078 *p_Stack_14c;
  _func_1079 *p_Stack_148;
  _func_1080 *p_Stack_144;
  undefined4 uStack_140;
  undefined auStack_13c [32];
  undefined4 uStack_11c;
  uint uStack_118;
  _func_1085 *p_Stack_114;
  uint uStack_110;
  uint uStack_10c;
  uint uStack_108;
  uint uStack_104;
  uint uStack_100;
  int iStack_fc;
  int iStack_f8;
  EVP_MD *pEStack_f4;
  EVP_MD *pEStack_f0;
  EVP_MD *pEStack_ec;
  EVP_MD *pEStack_e8;
  undefined *puStack_e4;
  BIGNUM *pBStack_e0;
  BIGNUM *pBStack_dc;
  BIGNUM *pBStack_d8;
  undefined4 uStack_d4;
  int in_stack_ffffff40;
  uint uStack_bc;
  int *piStack_b4;
  EVP_MD *pEStack_b0;
  BIGNUM *pBStack_ac;
  BIGNUM BStack_a8;
  int iStack_94;
  RSA *pRStack_90;
  EVP_MD *pEStack_8c;
  undefined *puStack_88;
  EVP_MD *pEStack_84;
  BN_BLINDING *pBStack_80;
  BN_CTX *pBStack_7c;
  BIGNUM *pBStack_78;
  BIGNUM *pBStack_74;
  BIGNUM *pBStack_70;
  code *pcStack_6c;
  BIGNUM local_40;
  int local_2c;
  
  pEVar23 = (EVP_MD *)PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pEVar22 = (EVP_MD *)ctx;
  if (rsa->blinding != (BN_BLINDING *)0x0) {
    (*(code *)PTR_BN_BLINDING_free_006a8728)();
    rsa->blinding = (BN_BLINDING *)0x0;
    rsa->flags = rsa->flags & 0xfffffff7U | 0x80;
  }
  pEStack_8c = (EVP_MD *)ctx;
  if ((ctx == (BN_CTX *)0x0) && (pEStack_8c = (EVP_MD *)BN_CTX_new(), pEStack_8c == (EVP_MD *)0x0))
  {
    rsa->blinding = (BN_BLINDING *)0x0;
    iVar3 = 0;
  }
  else {
    BN_CTX_start((BN_CTX *)pEStack_8c);
    unaff_s3 = (EVP_MD *)BN_CTX_get((BN_CTX *)pEStack_8c);
    if (unaff_s3 == (EVP_MD *)0x0) {
      in_a2 = (BIGNUM *)&DAT_00000041;
      iVar3 = 0xcc;
LAB_005119e0:
      in_a3 = "rsa_crpt.c";
      pEVar22 = (EVP_MD *)&DAT_00000088;
      unaff_s4 = (BN_BLINDING *)0x0;
      ERR_put_error(4,0x88,(int)in_a2,"rsa_crpt.c",iVar3);
    }
    else {
      pEVar22 = (EVP_MD *)rsa->e;
      unaff_s3 = pEVar22;
      if (pEVar22 == (EVP_MD *)0x0) {
        unaff_s6 = rsa->d;
        unaff_s7 = rsa->p;
        pBVar4 = rsa->q;
        if (((unaff_s6 != (BIGNUM *)0x0) && (unaff_s7 != (BIGNUM *)0x0)) &&
           (pBVar4 != (BIGNUM *)0x0)) {
          BN_CTX_start((BN_CTX *)pEStack_8c);
          pBVar10 = BN_CTX_get((BN_CTX *)pEStack_8c);
          pBVar11 = BN_CTX_get((BN_CTX *)pEStack_8c);
          unaff_s8 = BN_CTX_get((BN_CTX *)pEStack_8c);
          if (unaff_s8 != (BIGNUM *)0x0) {
            pBVar12 = BN_value_one();
            iVar3 = (*(code *)PTR_BN_sub_006a85a8)(pBVar11,unaff_s7,pBVar12);
            if (iVar3 != 0) {
              pBVar12 = BN_value_one();
              iVar3 = (*(code *)PTR_BN_sub_006a85a8)(unaff_s8,pBVar4,pBVar12);
              if ((iVar3 != 0) &&
                 (iVar3 = BN_mul(pBVar10,pBVar11,unaff_s8,(BN_CTX *)pEStack_8c), iVar3 != 0)) {
                unaff_s3 = (EVP_MD *)
                           (*(code *)PTR_BN_mod_inverse_006a85f0)(0,unaff_s6,pBVar10,pEStack_8c);
                BN_CTX_end((BN_CTX *)pEStack_8c);
                if (unaff_s3 != (EVP_MD *)0x0) goto LAB_00511794;
                goto LAB_005119d0;
              }
            }
          }
          BN_CTX_end((BN_CTX *)pEStack_8c);
        }
LAB_005119d0:
        in_a2 = (BIGNUM *)&DAT_0000008c;
        iVar3 = 0xd3;
        unaff_s3 = pEVar22;
        goto LAB_005119e0;
      }
LAB_00511794:
      iVar3 = RAND_status();
      if (((iVar3 == 0) && (pBVar4 = rsa->d, pBVar4 != (BIGNUM *)0x0)) &&
         (pBVar4->d != (ulong *)0x0)) {
        RAND_add(pBVar4->d,pBVar4->dmax << 2,in_f12_13);
      }
      in_a2 = &local_40;
      if ((rsa->flags & 0x100U) == 0) {
        pBVar4 = rsa->n;
        local_40.d = pBVar4->d;
        local_40.top = pBVar4->top;
        local_40.dmax = pBVar4->dmax;
        local_40.neg = pBVar4->neg;
        local_40.flags = local_40.flags & 1U | pBVar4->flags & 0xfffffffeU | 6;
      }
      else {
        in_a2 = rsa->n;
      }
      pEVar22 = unaff_s3;
      in_a3 = (char *)pEStack_8c;
      unaff_s4 = (BN_BLINDING *)(*(code *)PTR_BN_BLINDING_create_param_006a8740)(0);
      if (unaff_s4 == (BN_BLINDING *)0x0) {
        in_a2 = (BIGNUM *)0x0;
        in_a3 = "rsa_crpt.c";
        pEVar22 = (EVP_MD *)&DAT_00000088;
        ERR_put_error(4,0x88,3,"rsa_crpt.c",0xeb);
      }
      else {
        uVar5 = (*(code *)PTR_BN_BLINDING_thread_id_006a86dc)(unaff_s4);
        (*(code *)PTR_CRYPTO_THREADID_current_006a848c)(uVar5);
      }
    }
    BN_CTX_end((BN_CTX *)pEStack_8c);
    if (ctx == (BN_CTX *)0x0) {
      BN_CTX_free((BN_CTX *)pEStack_8c);
    }
    if (rsa->e == (BIGNUM *)0x0) {
      BN_free((BIGNUM *)unaff_s3);
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
  if (local_2c == pEVar23->type) {
    return iVar3;
  }
  pcStack_6c = RSA_setup_blinding;
  iStack_f8 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_e4 = PTR___stack_chk_guard_006a9ae8;
  puStack_88 = (undefined *)pEVar23;
  iStack_94 = *(int *)PTR___stack_chk_guard_006a9ae8;
  ret = pEVar22;
  pRStack_90 = rsa;
  pEStack_84 = unaff_s3;
  pBStack_80 = unaff_s4;
  pBStack_7c = ctx;
  pBStack_78 = unaff_s6;
  pBStack_74 = unaff_s7;
  pBStack_70 = unaff_s8;
  if ((pEVar22 == (EVP_MD *)0x0) &&
     (pEVar9 = pEVar22, ret = (EVP_MD *)BN_CTX_new(), ret == (EVP_MD *)0x0)) {
    pEVar7 = (EVP_MD *)0x0;
  }
  else {
    BN_CTX_start((BN_CTX *)ret);
    unaff_s3 = (EVP_MD *)BN_CTX_get((BN_CTX *)ret);
    if (unaff_s3 == (EVP_MD *)0x0) {
      in_a2 = (BIGNUM *)&DAT_00000041;
      in_stack_ffffff40 = 0xcc;
LAB_00511db4:
      in_a3 = "rsa_crpt.c";
      pEVar9 = (EVP_MD *)&DAT_00000088;
      pEVar7 = (EVP_MD *)0x0;
      ERR_put_error(4,0x88,(int)in_a2,"rsa_crpt.c",in_stack_ffffff40);
    }
    else {
      pEVar23 = *(EVP_MD **)(iStack_f8 + 0x14);
      unaff_s3 = pEVar23;
      if (pEVar23 == (EVP_MD *)0x0) {
        unaff_s6 = *(BIGNUM **)(iStack_f8 + 0x18);
        unaff_s7 = *(BIGNUM **)(iStack_f8 + 0x1c);
        iVar3 = *(int *)(iStack_f8 + 0x20);
        if (((unaff_s6 != (BIGNUM *)0x0) && (unaff_s7 != (BIGNUM *)0x0)) && (iVar3 != 0)) {
          BN_CTX_start((BN_CTX *)ret);
          pBStack_ac = BN_CTX_get((BN_CTX *)ret);
          pEStack_b0 = (EVP_MD *)BN_CTX_get((BN_CTX *)ret);
          unaff_s8 = BN_CTX_get((BN_CTX *)ret);
          if (unaff_s8 != (BIGNUM *)0x0) {
            pBVar4 = BN_value_one();
            iVar8 = (*(code *)PTR_BN_sub_006a85a8)(pEStack_b0,unaff_s7,pBVar4);
            if (iVar8 != 0) {
              pBVar4 = BN_value_one();
              iVar3 = (*(code *)PTR_BN_sub_006a85a8)(unaff_s8,iVar3,pBVar4);
              if ((iVar3 != 0) &&
                 (iVar3 = BN_mul(pBStack_ac,(BIGNUM *)pEStack_b0,unaff_s8,(BN_CTX *)ret), iVar3 != 0
                 )) {
                unaff_s3 = (EVP_MD *)
                           (*(code *)PTR_BN_mod_inverse_006a85f0)(0,unaff_s6,pBStack_ac,ret);
                BN_CTX_end((BN_CTX *)ret);
                if (unaff_s3 != (EVP_MD *)0x0) goto LAB_00511b8c;
                goto LAB_00511da4;
              }
            }
          }
          BN_CTX_end((BN_CTX *)ret);
        }
LAB_00511da4:
        in_a2 = (BIGNUM *)&DAT_0000008c;
        in_stack_ffffff40 = 0xd3;
        unaff_s3 = pEVar23;
        goto LAB_00511db4;
      }
LAB_00511b8c:
      iVar3 = RAND_status();
      if (((iVar3 == 0) && (ppvVar6 = *(void ***)(iStack_f8 + 0x18), ppvVar6 != (void **)0x0)) &&
         (*ppvVar6 != (void *)0x0)) {
        RAND_add(*ppvVar6,(int)ppvVar6[2] << 2,in_f12_13);
      }
      in_a2 = &BStack_a8;
      if ((*(uint *)(iStack_f8 + 0x3c) & 0x100) == 0) {
        ppuVar19 = *(ulong ***)(iStack_f8 + 0x10);
        BStack_a8.d = *ppuVar19;
        BStack_a8.top = (int)ppuVar19[1];
        BStack_a8.dmax = (int)ppuVar19[2];
        BStack_a8.neg = (int)ppuVar19[3];
        BStack_a8.flags = BStack_a8.flags & 1U | (uint)ppuVar19[4] & 0xfffffffe | 6;
      }
      else {
        in_a2 = *(BIGNUM **)(iStack_f8 + 0x10);
      }
      uStack_bc = *(uint *)(iStack_f8 + 0x40);
      in_stack_ffffff40 = *(int *)(*(int *)(iStack_f8 + 8) + 0x18);
      pEVar9 = unaff_s3;
      in_a3 = (char *)ret;
      pEVar7 = (EVP_MD *)(*(code *)PTR_BN_BLINDING_create_param_006a8740)(0);
      if (pEVar7 == (EVP_MD *)0x0) {
        in_a2 = (BIGNUM *)0x0;
        in_a3 = "rsa_crpt.c";
        in_stack_ffffff40 = 0xeb;
        pEVar9 = (EVP_MD *)&DAT_00000088;
        ERR_put_error(4,0x88,3,"rsa_crpt.c",0xeb);
      }
      else {
        uVar5 = (*(code *)PTR_BN_BLINDING_thread_id_006a86dc)(pEVar7);
        (*(code *)PTR_CRYPTO_THREADID_current_006a848c)(uVar5);
      }
    }
    BN_CTX_end((BN_CTX *)ret);
    if (pEVar22 == (EVP_MD *)0x0) {
      BN_CTX_free((BN_CTX *)ret);
    }
    pEVar23 = pEVar7;
    if (*(int *)(iStack_f8 + 0x14) == 0) {
      BN_free((BIGNUM *)unaff_s3);
      pEStack_b0 = pEVar7;
    }
  }
  if (iStack_94 == *(int *)puStack_e4) {
    return (int)pEVar7;
  }
  uStack_d4 = 0x511ed8;
  iVar3 = iStack_94;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  count = (uint)in_a2 >> 3;
  iStack_fc = *(int *)PTR___stack_chk_guard_006a9ae8;
  pEVar7 = unaff_s3;
  pEStack_f4 = ret;
  pEStack_f0 = pEVar23;
  pEStack_ec = unaff_s3;
  pEStack_e8 = pEVar22;
  pBStack_e0 = unaff_s6;
  pBStack_dc = unaff_s7;
  pBStack_d8 = unaff_s8;
  if (((count & 0xfffffff7) != 0x14) && (iVar8 = 0, count != 0x20)) goto LAB_00511f80;
  pEStack_1ec = (EVP_MD *)in_a3;
  if ((EVP_MD *)in_a3 == (EVP_MD *)0x0) {
    pEStack_1ec = (EVP_MD *)(*(code *)PTR_EVP_sha1_006a75d0)();
  }
  if (pEVar9 < (EVP_MD *)0x200) {
    ret = (EVP_MD *)0x200;
    if (uStack_bc != 0) goto LAB_00511fe4;
LAB_0051202c:
    if (in_stack_ffffff40 != 0) {
      (*(code *)PTR___memcpy_chk_006a9a48)(auStack_17c,in_stack_ffffff40,uStack_bc,0x20);
    }
    pBStack_1c0 = BN_MONT_CTX_new();
  }
  else {
    ret = (EVP_MD *)((uint)((int)pEVar9->required_pkey_type + 0x13U) & 0xffffffc0);
    if (uStack_bc == 0) goto LAB_0051202c;
LAB_00511fe4:
    if (count <= uStack_bc) {
      if (count < uStack_bc) {
        uStack_bc = count;
      }
      goto LAB_0051202c;
    }
    iStack_1dc = 0;
    if (count < uStack_bc) {
      uStack_bc = count;
    }
    pBStack_1c0 = BN_MONT_CTX_new();
    in_stack_ffffff40 = iStack_1dc;
  }
  if (pBStack_1c0 != (BN_MONT_CTX *)0x0) {
    pEVar9 = (EVP_MD *)BN_CTX_new();
    pEStack_1bc = pEVar9;
    if (pEVar9 == (EVP_MD *)0x0) {
      iVar8 = 0;
      goto LAB_00512778;
    }
    n = (undefined *)((int)&ret[-1].md_ctrl + 3);
    BN_CTX_start((BN_CTX *)pEVar9);
    pBVar4 = BN_CTX_get((BN_CTX *)pEVar9);
    pEVar7 = (EVP_MD *)BN_CTX_get((BN_CTX *)pEVar9);
    pEVar22 = (EVP_MD *)BN_CTX_get((BN_CTX *)pEVar9);
    ret = (EVP_MD *)BN_CTX_get((BN_CTX *)pEVar9);
    pBVar10 = BN_CTX_get((BN_CTX *)pEVar9);
    pBVar11 = BN_CTX_get((BN_CTX *)pEVar9);
    pEVar23 = (EVP_MD *)BN_CTX_get((BN_CTX *)pEVar9);
    pBVar12 = BN_CTX_get((BN_CTX *)pEVar9);
    pBVar13 = BN_value_one();
    iVar8 = BN_lshift(pBVar12,pBVar13,(int)n);
    pEVar21 = pEVar23;
    unaff_s3 = pEVar7;
    if (iVar8 == 0) goto LAB_00512750;
    iStack_1ac = 0;
    uVar20 = count - 1;
    iVar17 = (count - 4 >> 2) + 1;
    puStack_1b8 = auStack_17c;
    pEVar21 = (EVP_MD *)((int)&iStack_fc + count + 3);
    do {
      iVar8 = BN_GENCB_call((BN_GENCB *)pBStack_ac,0,iStack_1ac);
      if (iVar8 == 0) goto LAB_00512750;
      if ((uStack_bc == 0) || (iVar8 = 0, in_stack_ffffff40 == 0)) {
        iVar8 = RAND_bytes(puStack_1b8,count);
        if (iVar8 < 1) goto LAB_00512750;
        iVar8 = 1;
      }
      else {
        uStack_bc = 0;
      }
      (*(code *)PTR___memcpy_chk_006a9a48)(auStack_13c,puStack_1b8,count,0x20);
      (*(code *)PTR___memcpy_chk_006a9a48)(&uStack_11c,puStack_1b8,count,0x20);
      if ((uVar20 != 0xffffffff) &&
         (cVar1 = auStack_13c[count - 1], auStack_13c[count - 1] = cVar1 + '\x01',
         (char)(cVar1 + '\x01') == '\0')) {
        pcVar18 = auStack_13c + (count - 2);
        do {
          if (pcVar18 == (char *)((int)&uStack_140 + 3)) break;
          cVar1 = *pcVar18;
          *pcVar18 = cVar1 + '\x01';
          pcVar18 = pcVar18 + -1;
        } while ((char)(cVar1 + '\x01') == '\0');
      }
      unaff_s3 = (EVP_MD *)auStack_15c;
      iVar14 = (*(code *)PTR_EVP_Digest_006a7a14)(puStack_1b8,count,unaff_s3,0,pEStack_1ec,0);
      if (iVar14 == 0) goto LAB_00512750;
      iVar14 = (*(code *)PTR_EVP_Digest_006a7a14)(auStack_13c,count,&uStack_11c,0,pEStack_1ec,0);
      if (iVar14 == 0) goto LAB_00512750;
      if (count != 0) {
        if (uVar20 < 3) {
          uVar16 = 0;
        }
        else {
          _auStack_15c = uStack_11c ^ _auStack_15c;
          if (((((iVar17 != 1) && (uStack_158 = uStack_118 ^ uStack_158, iVar17 != 2)) &&
               (uStack_154 = uStack_154 ^ (uint)p_Stack_114, iVar17 != 3)) &&
              ((uStack_150 = uStack_150 ^ uStack_110, iVar17 != 4 &&
               (p_Stack_14c = (_func_1078 *)((uint)p_Stack_14c ^ uStack_10c), iVar17 != 5)))) &&
             ((p_Stack_148 = (_func_1079 *)((uint)p_Stack_148 ^ uStack_108), iVar17 != 6 &&
              (p_Stack_144 = (_func_1080 *)((uint)p_Stack_144 ^ uStack_104), iVar17 != 7)))) {
            uStack_140 = (_func_1081 *)((uint)uStack_140 ^ uStack_100);
          }
          uVar16 = iVar17 * 4;
          if (count == iVar17 * 4) goto LAB_00512438;
        }
        auStack_15c[uVar16] = auStack_15c[uVar16] ^ *(byte *)((int)&uStack_11c + uVar16);
        if ((int)(uVar16 + 1) < (int)count) {
          auStack_15c[uVar16 + 1] =
               auStack_15c[uVar16 + 1] ^ *(byte *)((int)&uStack_11c + uVar16 + 1);
          if ((int)(uVar16 + 2) < (int)count) {
            auStack_15c[uVar16 + 2] =
                 auStack_15c[uVar16 + 2] ^ *(byte *)((int)&uStack_11c + uVar16 + 2);
          }
        }
      }
LAB_00512438:
      _auStack_15c = _auStack_15c | 0x80000000;
      (&bStack_15d)[count] = (&bStack_15d)[count] | 1;
      pBVar13 = BN_bin2bn((uchar *)unaff_s3,count,(BIGNUM *)ret);
      if (pBVar13 == (BIGNUM *)0x0) goto LAB_00512750;
      iVar14 = BN_is_prime_fasttest_ex
                         ((BIGNUM *)ret,0x32,(BN_CTX *)pEVar9,iVar8,(BN_GENCB *)pBStack_ac);
      if (0 < iVar14) {
        iVar8 = BN_GENCB_call((BN_GENCB *)pBStack_ac,2,0);
        if (iVar8 == 0) goto LAB_00512750;
        iVar8 = BN_GENCB_call((BN_GENCB *)pBStack_ac,3,0);
        if (iVar8 == 0) goto LAB_00512750;
        iStack_1a8 = 0;
        do {
          iVar8 = 0;
          BN_set_word((BIGNUM *)pEVar22,0);
          iVar14 = 0;
          do {
            if ((uVar20 != 0xffffffff) &&
               (cVar1 = auStack_13c[count - 1], auStack_13c[count - 1] = cVar1 + '\x01',
               (char)(cVar1 + '\x01') == '\0')) {
              pcVar18 = auStack_13c + (count - 2);
              do {
                if ((char *)((int)&uStack_140 + 3) == pcVar18) break;
                cVar1 = *pcVar18;
                *pcVar18 = cVar1 + '\x01';
                pcVar18 = pcVar18 + -1;
              } while ((char)(cVar1 + '\x01') == '\0');
            }
            iVar15 = EVP_Digest(auStack_13c,count,(uchar *)unaff_s3,(uint *)0x0,pEStack_1ec,
                                (ENGINE *)0x0);
            if (iVar15 == 0) goto LAB_00512750;
            pBVar13 = BN_bin2bn((uchar *)unaff_s3,count,pBVar4);
            if (pBVar13 == (BIGNUM *)0x0) goto LAB_00512750;
            iVar15 = BN_lshift(pBVar4,pBVar4,iVar8);
            if (iVar15 == 0) goto LAB_00512750;
            iVar15 = (*(code *)PTR_BN_add_006a85a4)(pEVar22,pEVar22,pBVar4);
            if (iVar15 == 0) goto LAB_00512750;
            iVar14 = iVar14 + 1;
            iVar8 = iVar8 + ((uint)in_a2 & 0xfffffff8);
          } while (iVar14 <= (int)((uint)n / 0xa0));
          iVar8 = BN_mask_bits((BIGNUM *)pEVar22,(int)n);
          if (iVar8 == 0) goto LAB_00512750;
          pBVar13 = BN_copy(pBVar10,(BIGNUM *)pEVar22);
          if (pBVar13 == (BIGNUM *)0x0) goto LAB_00512750;
          iVar8 = (*(code *)PTR_BN_add_006a85a4)(pBVar10,pBVar10,pBVar12);
          if (iVar8 == 0) goto LAB_00512750;
          iVar8 = BN_lshift1(pBVar4,(BIGNUM *)ret);
          if (iVar8 == 0) goto LAB_00512750;
          iVar8 = (*(code *)PTR_BN_div_006a855c)(0,pBVar11,pBVar10,pBVar4,pEVar9);
          if (iVar8 == 0) goto LAB_00512750;
          pBVar13 = BN_value_one();
          iVar8 = (*(code *)PTR_BN_sub_006a85a8)(pBVar4,pBVar11,pBVar13);
          if (iVar8 == 0) goto LAB_00512750;
          iVar8 = (*(code *)PTR_BN_sub_006a85a8)(pEVar23,pBVar10,pBVar4);
          if (iVar8 == 0) goto LAB_00512750;
          iVar8 = BN_cmp((BIGNUM *)pEVar23,pBVar12);
          if (-1 < iVar8) {
            iVar14 = BN_is_prime_fasttest_ex
                               ((BIGNUM *)pEVar23,0x32,(BN_CTX *)pEVar9,1,(BN_GENCB *)pBStack_ac);
            if (0 < iVar14) {
              iVar8 = BN_GENCB_call((BN_GENCB *)pBStack_ac,2,1);
              pEVar21 = pEVar23;
              unaff_s3 = pEVar7;
              if (iVar8 == 0) goto LAB_00512750;
              pBVar10 = BN_value_one();
              iVar8 = (*(code *)PTR_BN_sub_006a85a8)(pBVar12,pEVar23,pBVar10);
              if (iVar8 == 0) goto LAB_00512750;
              iVar8 = (*(code *)PTR_BN_div_006a855c)(pBVar4,0,pBVar12,ret,pEVar9);
              if (iVar8 == 0) goto LAB_00512750;
              iVar8 = BN_set_word(pBVar12,2);
              if (iVar8 == 0) goto LAB_00512750;
              iVar8 = BN_MONT_CTX_set(pBStack_1c0,(BIGNUM *)pEVar23,(BN_CTX *)pEVar9);
              if (iVar8 == 0) goto LAB_00512750;
              pEVar22 = (EVP_MD *)&SUB_00000002;
              do {
                iVar8 = (*(code *)PTR_BN_mod_exp_mont_006a85d0)
                                  (pEVar7,pBVar12,pBVar4,pEVar23,pEVar9,pBStack_1c0);
                if (iVar8 == 0) goto LAB_00512750;
                if (pEVar7->pkey_type != 1) goto LAB_0051294c;
                if (*(ulong *)pEVar7->type != 1) goto LAB_0051294c;
                if (pEVar7->flags != 0) goto LAB_0051294c;
                pBVar10 = BN_value_one();
                iVar8 = (*(code *)PTR_BN_add_006a85a4)(pBVar12,pBVar12,pBVar10);
                if (iVar8 == 0) goto LAB_00512750;
                pEVar22 = (EVP_MD *)((int)&pEVar22->type + 1);
              } while( true );
            }
            iVar8 = 0;
            if (iVar14 != 0) goto LAB_00512754;
          }
          iStack_1a8 = iStack_1a8 + 1;
          if (iStack_1a8 == 0x1000) goto LAB_005124a0;
          iVar8 = BN_GENCB_call((BN_GENCB *)pBStack_ac,0,iStack_1a8);
          if (iVar8 == 0) goto LAB_00512750;
        } while( true );
      }
      iVar8 = 0;
      if (iVar14 != 0) goto LAB_00512754;
LAB_005124a0:
      iStack_1ac = iStack_1ac + 1;
    } while( true );
  }
  iVar8 = 0;
LAB_00511f80:
  do {
    if (iStack_fc == *(int *)puVar2) {
      return iVar8;
    }
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_0051294c:
    iVar8 = BN_GENCB_call((BN_GENCB *)pBStack_ac,3,1);
    pEVar21 = pEVar23;
    unaff_s3 = pEVar7;
    if (iVar8 == 0) {
LAB_00512750:
      iVar8 = 0;
    }
    else {
      if (*(BIGNUM **)(iVar3 + 0xc) != (BIGNUM *)0x0) {
        BN_free(*(BIGNUM **)(iVar3 + 0xc));
      }
      if (*(BIGNUM **)(iVar3 + 0x10) != (BIGNUM *)0x0) {
        BN_free(*(BIGNUM **)(iVar3 + 0x10));
      }
      if (*(BIGNUM **)(iVar3 + 0x14) != (BIGNUM *)0x0) {
        BN_free(*(BIGNUM **)(iVar3 + 0x14));
      }
      pBVar4 = BN_dup((BIGNUM *)pEVar23);
      *(BIGNUM **)(iVar3 + 0xc) = pBVar4;
      pBVar4 = BN_dup((BIGNUM *)ret);
      *(BIGNUM **)(iVar3 + 0x10) = pBVar4;
      pBVar4 = BN_dup((BIGNUM *)pEVar7);
      *(BIGNUM **)(iVar3 + 0x14) = pBVar4;
      if (*(int *)(iVar3 + 0xc) == 0) goto LAB_00512750;
      iVar8 = 0;
      if ((*(int *)(iVar3 + 0x10) != 0) && (pBVar4 != (BIGNUM *)0x0)) {
        if (piStack_b4 != (int *)0x0) {
          *piStack_b4 = iStack_1a8;
        }
        if (pEStack_b0 != (EVP_MD *)0x0) {
          pEStack_b0->type = (int)pEVar22;
        }
        iVar8 = 1;
        (*(code *)PTR_memcpy_006a9aec)(&_gp,puStack_1b8,count);
      }
    }
LAB_00512754:
    BN_CTX_end((BN_CTX *)pEStack_1bc);
    BN_CTX_free((BN_CTX *)pEStack_1bc);
    ret = pEStack_1bc;
    pEVar9 = pEVar21;
LAB_00512778:
    BN_MONT_CTX_free(pBStack_1c0);
    iVar3 = iVar8;
    pEVar23 = pEVar9;
    pEVar7 = unaff_s3;
  } while( true );
}

