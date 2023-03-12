
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
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (((*(int *)(param_1 + 0xc) == 0) || (*(int *)(param_1 + 0x10) == 0)) ||
     (*(int *)(param_1 + 0x14) == 0)) {
    ERR_put_error(10,0x6b,0x65,"dsa_ossl.c",0xe0);
    puVar8 = (undefined1 *)0x0;
    goto LAB_005165e0;
  }
  (*(code *)PTR_BN_init_006a96a0)(&BStack_54);
  (*(code *)PTR_BN_init_006a96a0)(&BStack_40);
  ctx = param_2;
  if (((param_2 == (BN_CTX *)0x0) && (ctx = BN_CTX_new(), ctx == (BN_CTX *)0x0)) ||
     (iVar2 = (*(code *)PTR_BN_new_006a82b4)(), iVar2 == 0)) {
    puVar8 = (undefined1 *)0x0;
    ERR_put_error(10,0x6b,3,"dsa_ossl.c",0x129);
  }
  else {
    do {
      iVar3 = BN_rand_range(&BStack_54,*(BIGNUM **)(param_1 + 0x10));
      if (iVar3 == 0) goto LAB_0051657c;
    } while (BStack_54.top == 0);
    uVar4 = *(uint *)(param_1 + 0x28) & 1;
    pBVar7 = &BStack_54;
    if ((*(uint *)(param_1 + 0x28) & 2) == 0) {
      BStack_54.flags = BStack_54.flags | 4;
      if (uVar4 == 0) {
LAB_00516670:
        iVar3 = (*(code *)PTR_BN_copy_006a9570)(&BStack_40,&BStack_54);
        if ((iVar3 != 0) &&
           (iVar3 = (*(code *)PTR_BN_add_006a96c8)
                              (&BStack_40,&BStack_40,*(undefined4 *)(param_1 + 0x10)), iVar3 != 0))
        {
          iVar3 = (*(code *)PTR_BN_num_bits_006a82f4)(&BStack_40);
          iVar5 = (*(code *)PTR_BN_num_bits_006a82f4)(*(undefined4 *)(param_1 + 0x10));
          pBVar7 = &BStack_40;
          if ((iVar5 < iVar3) ||
             (iVar3 = (*(code *)PTR_BN_add_006a96c8)
                                (&BStack_40,&BStack_40,*(undefined4 *)(param_1 + 0x10)), iVar3 != 0)
             ) goto LAB_005166e4;
        }
      }
      else {
LAB_005167ac:
        pBVar6 = BN_MONT_CTX_set_locked
                           ((BN_MONT_CTX **)(param_1 + 0x2c),8,*(BIGNUM **)(param_1 + 0xc),ctx);
        if (pBVar6 != (BN_MONT_CTX *)0x0) {
          if ((*(uint *)(param_1 + 0x28) & 2) != 0) goto LAB_005166e4;
          goto LAB_00516670;
        }
      }
    }
    else {
      if (uVar4 != 0) goto LAB_005167ac;
LAB_005166e4:
      pcVar9 = *(code **)(*(int *)(param_1 + 0x3c) + 0x14);
      if (pcVar9 == (code *)0x0) {
        iVar3 = (*(code *)PTR_BN_mod_exp_mont_006a96f4)
                          (iVar2,*(undefined4 *)(param_1 + 0x14),pBVar7,
                           *(undefined4 *)(param_1 + 0xc),ctx,*(undefined4 *)(param_1 + 0x2c));
      }
      else {
        iVar3 = (*pcVar9)(param_1,iVar2,*(undefined4 *)(param_1 + 0x14),pBVar7,
                          *(undefined4 *)(param_1 + 0xc),ctx,*(undefined4 *)(param_1 + 0x2c));
      }
      if (((iVar3 != 0) &&
          (iVar3 = (*(code *)PTR_BN_div_006a967c)(0,iVar2,iVar2,*(undefined4 *)(param_1 + 0x10),ctx)
          , iVar3 != 0)) &&
         (iVar3 = (*(code *)PTR_BN_mod_inverse_006a9714)
                            (0,&BStack_54,*(undefined4 *)(param_1 + 0x10),ctx), iVar3 != 0)) {
        if (*param_3 != 0) {
          (*(code *)PTR_BN_clear_free_006a9130)();
        }
        *param_3 = iVar3;
        if (*param_4 != 0) {
          (*(code *)PTR_BN_clear_free_006a9130)();
        }
        puVar8 = (undefined1 *)0x1;
        *param_4 = iVar2;
        goto LAB_005165b4;
      }
    }
LAB_0051657c:
    puVar8 = (undefined1 *)0x0;
    ERR_put_error(10,0x6b,3,"dsa_ossl.c",0x129);
    (*(code *)PTR_BN_clear_free_006a9130)(iVar2);
  }
LAB_005165b4:
  if (param_2 == (BN_CTX *)0x0) {
    BN_CTX_free(ctx);
  }
  (*(code *)PTR_BN_clear_free_006a9130)(&BStack_54);
  (*(code *)PTR_BN_clear_free_006a9130)(&BStack_40);
LAB_005165e0:
  if (local_2c != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    return openssl_dsa_meth;
  }
  return puVar8;
}

