
undefined1 * dsa_sign_setup(int param_1,BN_CTX *param_2,int *param_3,int *param_4)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  BN_MONT_CTX *pBVar6;
  BN_CTX *ctx;
  BIGNUM *pBVar7;
  undefined1 *puVar8;
  code *pcVar9;
  BIGNUM BStack_54;
  BIGNUM BStack_40;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (((*(int *)(param_1 + 0xc) == 0) || (*(int *)(param_1 + 0x10) == 0)) ||
     (*(int *)(param_1 + 0x14) == 0)) {
    ERR_put_error(10,0x6b,0x65,s_dsa_ossl_c_00666e7c,0xe6);
    puVar8 = (undefined1 *)0x0;
    goto LAB_00514630;
  }
  (*(code *)PTR_BN_init_006a857c)(&BStack_54);
  (*(code *)PTR_BN_init_006a857c)(&BStack_40);
  ctx = param_2;
  if (((param_2 == (BN_CTX *)0x0) &&
      (ctx = (BN_CTX *)(*(code *)PTR_BN_CTX_new_006a794c)(), ctx == (BN_CTX *)0x0)) ||
     (iVar2 = (*(code *)PTR_BN_new_006a71b4)(), iVar2 == 0)) {
    puVar8 = (undefined1 *)0x0;
    ERR_put_error(10,0x6b,3,s_dsa_ossl_c_00666e7c,0x135);
  }
  else {
    do {
      iVar3 = BN_rand_range(&BStack_54,*(BIGNUM **)(param_1 + 0x10));
      if (iVar3 == 0) goto LAB_005145cc;
    } while (BStack_54.top == 0);
    uVar4 = *(uint *)(param_1 + 0x28) & 1;
    pBVar7 = &BStack_54;
    if ((*(uint *)(param_1 + 0x28) & 2) == 0) {
      BStack_54.flags = BStack_54.flags | 4;
      if (uVar4 == 0) {
LAB_005146c0:
        iVar3 = (*(code *)PTR_BN_copy_006a8450)(&BStack_40,&BStack_54);
        if (iVar3 != 0) {
          BStack_40.flags = BStack_40.flags | 4;
          iVar3 = (*(code *)PTR_BN_add_006a85a4)
                            (&BStack_40,&BStack_40,*(undefined4 *)(param_1 + 0x10));
          if (iVar3 != 0) {
            iVar3 = (*(code *)PTR_BN_num_bits_006a71f4)(&BStack_40);
            iVar5 = (*(code *)PTR_BN_num_bits_006a71f4)(*(undefined4 *)(param_1 + 0x10));
            pBVar7 = &BStack_40;
            if ((iVar5 < iVar3) ||
               (iVar3 = (*(code *)PTR_BN_add_006a85a4)
                                  (&BStack_40,&BStack_40,*(undefined4 *)(param_1 + 0x10)),
               iVar3 != 0)) goto LAB_00514740;
          }
        }
      }
      else {
LAB_00514808:
        pBVar6 = BN_MONT_CTX_set_locked
                           ((BN_MONT_CTX **)(param_1 + 0x2c),8,*(BIGNUM **)(param_1 + 0xc),ctx);
        if (pBVar6 != (BN_MONT_CTX *)0x0) {
          if ((*(uint *)(param_1 + 0x28) & 2) != 0) goto LAB_00514740;
          goto LAB_005146c0;
        }
      }
    }
    else {
      if (uVar4 != 0) goto LAB_00514808;
LAB_00514740:
      pcVar9 = *(code **)(*(int *)(param_1 + 0x3c) + 0x14);
      if (pcVar9 == (code *)0x0) {
        iVar3 = (*(code *)PTR_BN_mod_exp_mont_006a85d0)
                          (iVar2,*(undefined4 *)(param_1 + 0x14),pBVar7,
                           *(undefined4 *)(param_1 + 0xc),ctx,*(undefined4 *)(param_1 + 0x2c));
      }
      else {
        iVar3 = (*pcVar9)(param_1,iVar2,*(undefined4 *)(param_1 + 0x14),pBVar7,
                          *(undefined4 *)(param_1 + 0xc),ctx,*(undefined4 *)(param_1 + 0x2c));
      }
      if (((iVar3 != 0) &&
          (iVar3 = (*(code *)PTR_BN_div_006a855c)(0,iVar2,iVar2,*(undefined4 *)(param_1 + 0x10),ctx)
          , iVar3 != 0)) &&
         (iVar3 = (*(code *)PTR_BN_mod_inverse_006a85f0)
                            (0,&BStack_54,*(undefined4 *)(param_1 + 0x10),ctx), iVar3 != 0)) {
        if (*param_3 != 0) {
          (*(code *)PTR_BN_clear_free_006a7fa8)();
        }
        *param_3 = iVar3;
        if (*param_4 != 0) {
          (*(code *)PTR_BN_clear_free_006a7fa8)();
        }
        puVar8 = (undefined1 *)0x1;
        *param_4 = iVar2;
        goto LAB_00514604;
      }
    }
LAB_005145cc:
    puVar8 = (undefined1 *)0x0;
    ERR_put_error(10,0x6b,3,s_dsa_ossl_c_00666e7c,0x135);
    (*(code *)PTR_BN_clear_free_006a7fa8)(iVar2);
  }
LAB_00514604:
  if (param_2 == (BN_CTX *)0x0) {
    (*(code *)PTR_BN_CTX_free_006a7954)(ctx);
  }
  (*(code *)PTR_BN_clear_free_006a7fa8)(&BStack_54);
  (*(code *)PTR_BN_clear_free_006a7fa8)(&BStack_40);
LAB_00514630:
  if (local_2c != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    return openssl_dsa_meth;
  }
  return puVar8;
}

