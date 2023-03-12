
DSA_SIG * dsa_do_sign(uchar *param_1,BIGNUM *param_2,DSA *param_3,char *param_4)

{
  bool bVar1;
  undefined *puVar2;
  BIGNUM *pBVar3;
  int iVar4;
  int iVar5;
  BIGNUM *pBVar6;
  ulong *puVar7;
  uint uVar8;
  int iVar9;
  ulong *puVar10;
  BN_MONT_CTX *pBVar11;
  BIGNUM *pBVar12;
  BIGNUM *pBVar13;
  DSA_SIG *pDVar14;
  BIGNUM *unaff_s3;
  BIGNUM *unaff_s7;
  code *pcVar15;
  BIGNUM *unaff_s8;
  BIGNUM BStack_e4;
  BIGNUM BStack_d0;
  int iStack_bc;
  DSA *pDStack_b8;
  BIGNUM *pBStack_b4;
  BIGNUM *pBStack_b0;
  BIGNUM *pBStack_ac;
  BIGNUM *pBStack_a8;
  BIGNUM *pBStack_a4;
  DSA_SIG *pDStack_a0;
  BIGNUM *pBStack_9c;
  BIGNUM *pBStack_98;
  code *pcStack_94;
  undefined local_5c [8];
  BIGNUM BStack_54;
  BIGNUM BStack_40;
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  pBStack_a8 = &BStack_54;
  pBStack_a4 = &BStack_40;
  local_5c._0_4_ = (BIGNUM *)0x0;
  local_5c._4_4_ = (BIGNUM *)0x0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_BN_init_006a96a0)(pBStack_a8);
  (*(code *)PTR_BN_init_006a96a0)(pBStack_a4);
  if (((param_3->p == (BIGNUM *)0x0) || (param_3->q == (BIGNUM *)0x0)) ||
     (param_3->g == (BIGNUM *)0x0)) {
    pBVar3 = (BIGNUM *)&DAT_00000065;
    pBStack_b4 = (BIGNUM *)0x0;
LAB_00516428:
    pBVar12 = (BIGNUM *)&DAT_00000070;
    param_4 = "dsa_ossl.c";
    pDStack_a0 = (DSA_SIG *)0x0;
    ERR_put_error(10,0x70,(int)pBVar3,"dsa_ossl.c",0xcc);
    (*(code *)PTR_BN_free_006a811c)(local_5c._4_4_);
    (*(code *)PTR_BN_free_006a811c)(pBStack_b4);
  }
  else {
    pBStack_b4 = (BIGNUM *)(*(code *)PTR_BN_new_006a82b4)();
    if ((pBStack_b4 == (BIGNUM *)0x0) ||
       (unaff_s3 = (BIGNUM *)BN_CTX_new(), unaff_s3 == (BIGNUM *)0x0)) {
      pBVar3 = (BIGNUM *)0x3;
      goto LAB_00516428;
    }
    pDStack_a0 = (DSA_SIG *)0x0;
    unaff_s7 = (BIGNUM *)(local_5c + 4);
    unaff_s8 = (BIGNUM *)local_5c;
    do {
      pBVar3 = param_3->kinv;
      if ((pBVar3 == (BIGNUM *)0x0) || (pBVar12 = param_3->r, pBVar12 == (BIGNUM *)0x0)) {
        pBVar12 = unaff_s3;
        pBVar3 = unaff_s8;
        param_4 = (char *)unaff_s7;
        iVar4 = DSA_sign_setup(param_3,(BN_CTX *)unaff_s3,(BIGNUM **)unaff_s8,(BIGNUM **)unaff_s7);
        if (iVar4 != 0) {
          bVar1 = false;
          goto LAB_005162bc;
        }
LAB_00516328:
        if (pDStack_a0 == (DSA_SIG *)0x0) {
LAB_005163d8:
          pBVar3 = (BIGNUM *)0x3;
          param_4 = "dsa_ossl.c";
          pBVar12 = (BIGNUM *)&DAT_00000070;
          ERR_put_error(10,0x70,3,"dsa_ossl.c",0xcc);
          (*(code *)PTR_BN_free_006a811c)(local_5c._4_4_);
          (*(code *)PTR_BN_free_006a811c)(pBStack_b4);
        }
        break;
      }
      param_3->kinv = (BIGNUM *)0x0;
      bVar1 = true;
      param_3->r = (BIGNUM *)0x0;
      local_5c._0_4_ = pBVar3;
      local_5c._4_4_ = pBVar12;
LAB_005162bc:
      iVar5 = (*(code *)PTR_BN_num_bits_006a82f4)(param_3->q);
      iVar4 = iVar5 + 7;
      if (iVar5 + 7 < 0) {
        iVar4 = iVar5 + 0xe;
      }
      pBVar3 = pBStack_a8;
      if ((int)param_2 <= iVar4 >> 3) {
        pBVar12 = param_2;
        pBVar6 = BN_bin2bn(param_1,(int)param_2,pBStack_a8);
        if (pBVar6 != (BIGNUM *)0x0) goto LAB_005161ac;
        goto LAB_00516328;
      }
      iVar5 = (*(code *)PTR_BN_num_bits_006a82f4)(param_3->q);
      iVar4 = iVar5 + 7;
      if (iVar5 + 7 < 0) {
        iVar4 = iVar5 + 0xe;
      }
      param_2 = (BIGNUM *)(iVar4 >> 3);
      pBVar12 = param_2;
      pBVar6 = BN_bin2bn(param_1,(int)param_2,pBStack_a8);
      if (pBVar6 == (BIGNUM *)0x0) goto LAB_00516328;
LAB_005161ac:
      pBVar12 = param_3->priv_key;
      param_4 = (char *)param_3->q;
      pBVar3 = local_5c._4_4_;
      iVar4 = BN_mod_mul(pBStack_a4,pBVar12,local_5c._4_4_,(BIGNUM *)param_4,(BN_CTX *)unaff_s3);
      if ((iVar4 == 0) ||
         (pBVar12 = pBStack_a4, pBVar3 = pBStack_a8,
         iVar4 = (*(code *)PTR_BN_add_006a96c8)(pBStack_b4), iVar4 == 0)) goto LAB_00516328;
      iVar4 = BN_cmp(pBStack_b4,param_3->q);
      if (0 < iVar4) {
        pBVar3 = param_3->q;
        pBVar12 = pBStack_b4;
        iVar4 = (*(code *)PTR_BN_sub_006a96cc)(pBStack_b4);
        if (iVar4 == 0) goto LAB_00516328;
      }
      param_4 = (char *)param_3->q;
      pBVar12 = pBStack_b4;
      pBVar3 = local_5c._0_4_;
      iVar4 = BN_mod_mul(pBStack_b4,pBStack_b4,local_5c._0_4_,(BIGNUM *)param_4,(BN_CTX *)unaff_s3);
      if (iVar4 == 0) goto LAB_00516328;
      pDStack_a0 = DSA_SIG_new();
      if (pDStack_a0 == (DSA_SIG *)0x0) goto LAB_005163d8;
      if (((local_5c._4_4_)->top != 0) && (pBStack_b4->top != 0)) {
        pDStack_a0->r = local_5c._4_4_;
        pDStack_a0->s = pBStack_b4;
        break;
      }
    } while (!bVar1);
    BN_CTX_free((BN_CTX *)unaff_s3);
  }
  (*(code *)PTR_BN_clear_free_006a9130)(pBStack_a8);
  (*(code *)PTR_BN_clear_free_006a9130)(pBStack_a4);
  if (local_5c._0_4_ != (BIGNUM *)0x0) {
    (*(code *)PTR_BN_clear_free_006a9130)();
  }
  if (local_2c == *(int *)puVar2) {
    return pDStack_a0;
  }
  pcStack_94 = dsa_sign_setup;
  iVar4 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar2 = PTR___stack_chk_guard_006aabf0;
  iStack_bc = *(int *)PTR___stack_chk_guard_006aabf0;
  pDStack_b8 = param_3;
  pBStack_b0 = param_2;
  pBStack_ac = unaff_s3;
  pBStack_9c = unaff_s7;
  pBStack_98 = unaff_s8;
  if (((*(int *)(iVar4 + 0xc) == 0) || (*(int *)(iVar4 + 0x10) == 0)) ||
     (*(int *)(iVar4 + 0x14) == 0)) {
    ERR_put_error(10,0x6b,0x65,"dsa_ossl.c",0xe0);
    pDVar14 = (DSA_SIG *)0x0;
    goto LAB_005165e0;
  }
  (*(code *)PTR_BN_init_006a96a0)(&BStack_e4);
  (*(code *)PTR_BN_init_006a96a0)(&BStack_d0);
  pBVar6 = pBVar12;
  if (((pBVar12 == (BIGNUM *)0x0) && (pBVar6 = (BIGNUM *)BN_CTX_new(), pBVar6 == (BIGNUM *)0x0)) ||
     (puVar7 = (ulong *)(*(code *)PTR_BN_new_006a82b4)(), puVar7 == (ulong *)0x0)) {
    pDVar14 = (DSA_SIG *)0x0;
    ERR_put_error(10,0x6b,3,"dsa_ossl.c",0x129);
  }
  else {
    do {
      iVar5 = BN_rand_range(&BStack_e4,*(BIGNUM **)(iVar4 + 0x10));
      if (iVar5 == 0) goto LAB_0051657c;
    } while (BStack_e4.top == 0);
    uVar8 = *(uint *)(iVar4 + 0x28) & 1;
    pBVar13 = &BStack_e4;
    if ((*(uint *)(iVar4 + 0x28) & 2) == 0) {
      BStack_e4.flags = BStack_e4.flags | 4;
      if (uVar8 == 0) {
LAB_00516670:
        iVar5 = (*(code *)PTR_BN_copy_006a9570)(&BStack_d0,&BStack_e4);
        if ((iVar5 != 0) &&
           (iVar5 = (*(code *)PTR_BN_add_006a96c8)
                              (&BStack_d0,&BStack_d0,*(undefined4 *)(iVar4 + 0x10)), iVar5 != 0)) {
          iVar5 = (*(code *)PTR_BN_num_bits_006a82f4)(&BStack_d0);
          iVar9 = (*(code *)PTR_BN_num_bits_006a82f4)(*(undefined4 *)(iVar4 + 0x10));
          pBVar13 = &BStack_d0;
          if ((iVar9 < iVar5) ||
             (iVar5 = (*(code *)PTR_BN_add_006a96c8)
                                (&BStack_d0,&BStack_d0,*(undefined4 *)(iVar4 + 0x10)), iVar5 != 0))
          goto LAB_005166e4;
        }
      }
      else {
LAB_005167ac:
        pBVar11 = BN_MONT_CTX_set_locked
                            ((BN_MONT_CTX **)(iVar4 + 0x2c),8,*(BIGNUM **)(iVar4 + 0xc),
                             (BN_CTX *)pBVar6);
        if (pBVar11 != (BN_MONT_CTX *)0x0) {
          if ((*(uint *)(iVar4 + 0x28) & 2) != 0) goto LAB_005166e4;
          goto LAB_00516670;
        }
      }
    }
    else {
      if (uVar8 != 0) goto LAB_005167ac;
LAB_005166e4:
      pcVar15 = *(code **)(*(int *)(iVar4 + 0x3c) + 0x14);
      if (pcVar15 == (code *)0x0) {
        iVar5 = (*(code *)PTR_BN_mod_exp_mont_006a96f4)
                          (puVar7,*(undefined4 *)(iVar4 + 0x14),pBVar13,*(undefined4 *)(iVar4 + 0xc)
                           ,pBVar6,*(undefined4 *)(iVar4 + 0x2c));
      }
      else {
        iVar5 = (*pcVar15)(iVar4,puVar7,*(undefined4 *)(iVar4 + 0x14),pBVar13,
                           *(undefined4 *)(iVar4 + 0xc),pBVar6,*(undefined4 *)(iVar4 + 0x2c));
      }
      if (((iVar5 != 0) &&
          (iVar5 = (*(code *)PTR_BN_div_006a967c)
                             (0,puVar7,puVar7,*(undefined4 *)(iVar4 + 0x10),pBVar6), iVar5 != 0)) &&
         (puVar10 = (ulong *)(*(code *)PTR_BN_mod_inverse_006a9714)
                                       (0,&BStack_e4,*(undefined4 *)(iVar4 + 0x10),pBVar6),
         puVar10 != (ulong *)0x0)) {
        if (pBVar3->d != (ulong *)0x0) {
          (*(code *)PTR_BN_clear_free_006a9130)();
        }
        pBVar3->d = puVar10;
        if (*(ulong **)param_4 != (ulong *)0x0) {
          (*(code *)PTR_BN_clear_free_006a9130)();
        }
        pDVar14 = (DSA_SIG *)0x1;
        *(ulong **)param_4 = puVar7;
        goto LAB_005165b4;
      }
    }
LAB_0051657c:
    pDVar14 = (DSA_SIG *)0x0;
    ERR_put_error(10,0x6b,3,"dsa_ossl.c",0x129);
    (*(code *)PTR_BN_clear_free_006a9130)(puVar7);
  }
LAB_005165b4:
  if (pBVar12 == (BIGNUM *)0x0) {
    BN_CTX_free((BN_CTX *)pBVar6);
  }
  (*(code *)PTR_BN_clear_free_006a9130)(&BStack_e4);
  (*(code *)PTR_BN_clear_free_006a9130)(&BStack_d0);
LAB_005165e0:
  if (iStack_bc != *(int *)puVar2) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    return (DSA_SIG *)openssl_dsa_meth;
  }
  return pDVar14;
}

