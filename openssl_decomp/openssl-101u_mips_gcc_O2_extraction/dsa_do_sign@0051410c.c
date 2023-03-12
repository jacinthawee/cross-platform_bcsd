
DSA_SIG * dsa_do_sign(undefined4 param_1,int param_2,DSA *param_3)

{
  undefined *puVar1;
  BIGNUM *pBVar2;
  int iVar3;
  int iVar4;
  ulong *puVar5;
  uint uVar6;
  int iVar7;
  ulong *puVar8;
  BN_MONT_CTX *pBVar9;
  BIGNUM *ctx;
  BIGNUM *pBVar10;
  char *m;
  BIGNUM *pBVar11;
  DSA_SIG *pDVar12;
  BN_CTX *unaff_s3;
  int unaff_s6;
  BIGNUM **unaff_s7;
  code *pcVar13;
  BIGNUM **unaff_s8;
  BIGNUM BStack_dc;
  BIGNUM BStack_c8;
  int iStack_b4;
  DSA_SIG *pDStack_b0;
  BIGNUM *pBStack_ac;
  int iStack_a8;
  BN_CTX *pBStack_a4;
  undefined *puStack_a0;
  BIGNUM *pBStack_9c;
  int iStack_98;
  BIGNUM **ppBStack_94;
  BIGNUM **ppBStack_90;
  code *pcStack_8c;
  BIGNUM *local_5c;
  BIGNUM *local_58;
  undefined auStack_54 [20];
  BIGNUM BStack_40;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  puStack_a0 = auStack_54;
  pBStack_9c = &BStack_40;
  local_5c = (BIGNUM *)0x0;
  local_58 = (BIGNUM *)0x0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_BN_init_006a857c)(puStack_a0);
  (*(code *)PTR_BN_init_006a857c)(pBStack_9c);
  if (((param_3->p == (BIGNUM *)0x0) || (param_3->q == (BIGNUM *)0x0)) ||
     (param_3->g == (BIGNUM *)0x0)) {
    pBVar2 = (BIGNUM *)&DAT_00000065;
    pBStack_ac = (BIGNUM *)0x0;
LAB_00514484:
    pBVar10 = (BIGNUM *)&DAT_00000070;
    m = s_dsa_ossl_c_00666e7c;
    pDStack_b0 = (DSA_SIG *)0x0;
    ERR_put_error(10,0x70,(int)pBVar2,s_dsa_ossl_c_00666e7c,0xd1);
    (*(code *)PTR_BN_free_006a701c)(local_58);
    (*(code *)PTR_BN_free_006a701c)(pBStack_ac);
  }
  else {
    pBStack_ac = (BIGNUM *)(*(code *)PTR_BN_new_006a71b4)();
    if ((pBStack_ac == (BIGNUM *)0x0) || (unaff_s3 = BN_CTX_new(), unaff_s3 == (BN_CTX *)0x0)) {
      pBVar2 = (BIGNUM *)0x3;
      goto LAB_00514484;
    }
    unaff_s7 = &local_58;
    unaff_s8 = &local_5c;
    do {
      pBVar2 = param_3->kinv;
      if (pBVar2 == (BIGNUM *)0x0) {
LAB_00514200:
        iVar3 = DSA_sign_setup(param_3,unaff_s3,unaff_s8,unaff_s7);
        if (iVar3 != 0) {
          unaff_s6 = 0;
          goto LAB_00514220;
        }
LAB_0051436c:
        pBVar2 = (BIGNUM *)0x3;
        break;
      }
      pBVar10 = param_3->r;
      unaff_s6 = 1;
      if (pBVar10 == (BIGNUM *)0x0) goto LAB_00514200;
      param_3->kinv = (BIGNUM *)0x0;
      param_3->r = (BIGNUM *)0x0;
      local_5c = pBVar2;
      local_58 = pBVar10;
LAB_00514220:
      iVar4 = (*(code *)PTR_BN_num_bits_006a71f4)(param_3->q);
      iVar3 = iVar4 + 7;
      if (iVar4 + 7 < 0) {
        iVar3 = iVar4 + 0xe;
      }
      if (iVar3 >> 3 < param_2) {
        iVar3 = (*(code *)PTR_BN_num_bits_006a71f4)(param_3->q);
        param_2 = iVar3 + 7;
        if (iVar3 + 7 < 0) {
          param_2 = iVar3 + 0xe;
        }
        param_2 = param_2 >> 3;
        iVar3 = (*(code *)PTR_BN_bin2bn_006a7904)(param_1,param_2,puStack_a0);
        if (iVar3 != 0) goto LAB_00514268;
        goto LAB_0051436c;
      }
      iVar3 = (*(code *)PTR_BN_bin2bn_006a7904)(param_1,param_2,puStack_a0);
      if (iVar3 == 0) goto LAB_0051436c;
LAB_00514268:
      iVar3 = BN_mod_mul(pBStack_9c,param_3->priv_key,local_58,param_3->q,unaff_s3);
      if (((iVar3 == 0) ||
          (iVar3 = (*(code *)PTR_BN_add_006a85a4)(pBStack_ac,pBStack_9c,puStack_a0), iVar3 == 0)) ||
         ((iVar3 = (*(code *)PTR_BN_cmp_006a7960)(pBStack_ac,param_3->q), 0 < iVar3 &&
          (iVar3 = (*(code *)PTR_BN_sub_006a85a8)(pBStack_ac,pBStack_ac,param_3->q), iVar3 == 0))))
      goto LAB_0051436c;
      m = (char *)param_3->q;
      pBVar10 = pBStack_ac;
      pBVar2 = local_5c;
      iVar3 = BN_mod_mul(pBStack_ac,pBStack_ac,local_5c,(BIGNUM *)m,unaff_s3);
      if (iVar3 == 0) goto LAB_0051436c;
      if ((local_58->top != 0) && (pBStack_ac->top != 0)) {
        pDStack_b0 = DSA_SIG_new();
        if (pDStack_b0 == (DSA_SIG *)0x0) goto LAB_0051436c;
        pDStack_b0->s = pBStack_ac;
        pDStack_b0->r = local_58;
        goto LAB_005143b8;
      }
      pBVar2 = (BIGNUM *)&DAT_0000006e;
    } while (unaff_s6 == 0);
    pBVar10 = (BIGNUM *)&DAT_00000070;
    m = s_dsa_ossl_c_00666e7c;
    pDStack_b0 = (DSA_SIG *)0x0;
    ERR_put_error(10,0x70,(int)pBVar2,s_dsa_ossl_c_00666e7c,0xd1);
    (*(code *)PTR_BN_free_006a701c)(local_58);
    (*(code *)PTR_BN_free_006a701c)(pBStack_ac);
LAB_005143b8:
    BN_CTX_free(unaff_s3);
  }
  (*(code *)PTR_BN_clear_free_006a7fa8)(puStack_a0);
  (*(code *)PTR_BN_clear_free_006a7fa8)(pBStack_9c);
  if (local_5c != (BIGNUM *)0x0) {
    (*(code *)PTR_BN_clear_free_006a7fa8)();
  }
  if (local_2c == *(int *)puVar1) {
    return pDStack_b0;
  }
  pcStack_8c = dsa_sign_setup;
  iVar3 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStack_b4 = *(int *)PTR___stack_chk_guard_006a9ae8;
  iStack_a8 = param_2;
  pBStack_a4 = unaff_s3;
  iStack_98 = unaff_s6;
  ppBStack_94 = unaff_s7;
  ppBStack_90 = unaff_s8;
  if (((*(int *)(iVar3 + 0xc) == 0) || (*(int *)(iVar3 + 0x10) == 0)) ||
     (*(int *)(iVar3 + 0x14) == 0)) {
    ERR_put_error(10,0x6b,0x65,s_dsa_ossl_c_00666e7c,0xe6);
    pDVar12 = (DSA_SIG *)0x0;
    goto LAB_00514630;
  }
  (*(code *)PTR_BN_init_006a857c)(&BStack_dc);
  (*(code *)PTR_BN_init_006a857c)(&BStack_c8);
  ctx = pBVar10;
  if (((pBVar10 == (BIGNUM *)0x0) &&
      (ctx = (BIGNUM *)(*(code *)PTR_BN_CTX_new_006a794c)(), ctx == (BIGNUM *)0x0)) ||
     (puVar5 = (ulong *)(*(code *)PTR_BN_new_006a71b4)(), puVar5 == (ulong *)0x0)) {
    pDVar12 = (DSA_SIG *)0x0;
    ERR_put_error(10,0x6b,3,s_dsa_ossl_c_00666e7c,0x135);
  }
  else {
    do {
      iVar4 = BN_rand_range(&BStack_dc,*(BIGNUM **)(iVar3 + 0x10));
      if (iVar4 == 0) goto LAB_005145cc;
    } while (BStack_dc.top == 0);
    uVar6 = *(uint *)(iVar3 + 0x28) & 1;
    pBVar11 = &BStack_dc;
    if ((*(uint *)(iVar3 + 0x28) & 2) == 0) {
      BStack_dc.flags = BStack_dc.flags | 4;
      if (uVar6 == 0) {
LAB_005146c0:
        iVar4 = (*(code *)PTR_BN_copy_006a8450)(&BStack_c8,&BStack_dc);
        if (iVar4 != 0) {
          BStack_c8.flags = BStack_c8.flags | 4;
          iVar4 = (*(code *)PTR_BN_add_006a85a4)
                            (&BStack_c8,&BStack_c8,*(undefined4 *)(iVar3 + 0x10));
          if (iVar4 != 0) {
            iVar4 = (*(code *)PTR_BN_num_bits_006a71f4)(&BStack_c8);
            iVar7 = (*(code *)PTR_BN_num_bits_006a71f4)(*(undefined4 *)(iVar3 + 0x10));
            pBVar11 = &BStack_c8;
            if ((iVar7 < iVar4) ||
               (iVar4 = (*(code *)PTR_BN_add_006a85a4)
                                  (&BStack_c8,&BStack_c8,*(undefined4 *)(iVar3 + 0x10)), iVar4 != 0)
               ) goto LAB_00514740;
          }
        }
      }
      else {
LAB_00514808:
        pBVar9 = BN_MONT_CTX_set_locked
                           ((BN_MONT_CTX **)(iVar3 + 0x2c),8,*(BIGNUM **)(iVar3 + 0xc),(BN_CTX *)ctx
                           );
        if (pBVar9 != (BN_MONT_CTX *)0x0) {
          if ((*(uint *)(iVar3 + 0x28) & 2) != 0) goto LAB_00514740;
          goto LAB_005146c0;
        }
      }
    }
    else {
      if (uVar6 != 0) goto LAB_00514808;
LAB_00514740:
      pcVar13 = *(code **)(*(int *)(iVar3 + 0x3c) + 0x14);
      if (pcVar13 == (code *)0x0) {
        iVar4 = (*(code *)PTR_BN_mod_exp_mont_006a85d0)
                          (puVar5,*(undefined4 *)(iVar3 + 0x14),pBVar11,*(undefined4 *)(iVar3 + 0xc)
                           ,ctx,*(undefined4 *)(iVar3 + 0x2c));
      }
      else {
        iVar4 = (*pcVar13)(iVar3,puVar5,*(undefined4 *)(iVar3 + 0x14),pBVar11,
                           *(undefined4 *)(iVar3 + 0xc),ctx,*(undefined4 *)(iVar3 + 0x2c));
      }
      if (((iVar4 != 0) &&
          (iVar4 = (*(code *)PTR_BN_div_006a855c)(0,puVar5,puVar5,*(undefined4 *)(iVar3 + 0x10),ctx)
          , iVar4 != 0)) &&
         (puVar8 = (ulong *)(*(code *)PTR_BN_mod_inverse_006a85f0)
                                      (0,&BStack_dc,*(undefined4 *)(iVar3 + 0x10),ctx),
         puVar8 != (ulong *)0x0)) {
        if (pBVar2->d != (ulong *)0x0) {
          (*(code *)PTR_BN_clear_free_006a7fa8)();
        }
        pBVar2->d = puVar8;
        if (*(ulong **)m != (ulong *)0x0) {
          (*(code *)PTR_BN_clear_free_006a7fa8)();
        }
        pDVar12 = (DSA_SIG *)0x1;
        *(ulong **)m = puVar5;
        goto LAB_00514604;
      }
    }
LAB_005145cc:
    pDVar12 = (DSA_SIG *)0x0;
    ERR_put_error(10,0x6b,3,s_dsa_ossl_c_00666e7c,0x135);
    (*(code *)PTR_BN_clear_free_006a7fa8)(puVar5);
  }
LAB_00514604:
  if (pBVar10 == (BIGNUM *)0x0) {
    (*(code *)PTR_BN_CTX_free_006a7954)(ctx);
  }
  (*(code *)PTR_BN_clear_free_006a7fa8)(&BStack_dc);
  (*(code *)PTR_BN_clear_free_006a7fa8)(&BStack_c8);
LAB_00514630:
  if (iStack_b4 != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    return (DSA_SIG *)openssl_dsa_meth;
  }
  return pDVar12;
}

