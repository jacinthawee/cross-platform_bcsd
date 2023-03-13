
uint dsa_do_verify(undefined4 param_1,int param_2,BIGNUM **param_3,uint param_4)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  BN_MONT_CTX *pBVar4;
  BIGNUM *pBVar5;
  int reason;
  uint unaff_s0;
  BIGNUM *unaff_s2;
  BN_CTX *unaff_s5;
  BIGNUM *unaff_s7;
  code *pcVar6;
  undefined *unaff_s8;
  BIGNUM BStack_68;
  BIGNUM BStack_54;
  undefined auStack_40 [20];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (((*(int *)(param_4 + 0xc) == 0) || (unaff_s0 = param_4, *(int *)(param_4 + 0x10) == 0)) ||
     (*(int *)(param_4 + 0x14) == 0)) {
    reason = 0x65;
    iVar3 = 0x148;
  }
  else {
    uVar2 = (*(code *)PTR_BN_num_bits_006a71f4)();
    if (((uVar2 & 0xffffffbf) == 0xa0) || (uVar2 == 0x100)) {
      iVar3 = (*(code *)PTR_BN_num_bits_006a71f4)(*(undefined4 *)(param_4 + 0xc));
      if (iVar3 < 0x2711) {
        unaff_s2 = &BStack_68;
        unaff_s7 = &BStack_54;
        (*(code *)PTR_BN_init_006a857c)(unaff_s2);
        unaff_s8 = auStack_40;
        (*(code *)PTR_BN_init_006a857c)(unaff_s7);
        (*(code *)PTR_BN_init_006a857c)(unaff_s8);
        unaff_s5 = BN_CTX_new();
        if (unaff_s5 != (BN_CTX *)0x0) {
          pBVar5 = *param_3;
          if (((pBVar5->top == 0) || (pBVar5->neg != 0)) ||
             ((iVar3 = (*(code *)PTR_BN_ucmp_006a7fb4)(pBVar5,*(undefined4 *)(param_4 + 0x10)),
              -1 < iVar3 ||
              (((pBVar5 = param_3[1], pBVar5->top == 0 || (pBVar5->neg != 0)) ||
               (iVar3 = (*(code *)PTR_BN_ucmp_006a7fb4)(pBVar5,*(undefined4 *)(param_4 + 0x10)),
               -1 < iVar3)))))) {
            ERR_put_error(10,0x71,3,s_dsa_ossl_c_00666e7c,0x19b);
            uVar2 = 0;
            goto LAB_00513df0;
          }
          iVar3 = (*(code *)PTR_BN_mod_inverse_006a85f0)
                            (unaff_s7,param_3[1],*(undefined4 *)(param_4 + 0x10),unaff_s5);
          if (iVar3 != 0) {
            if ((int)uVar2 >> 3 <= param_2) {
              param_2 = (int)uVar2 >> 3;
            }
            iVar3 = (*(code *)PTR_BN_bin2bn_006a7904)(param_1,param_2,unaff_s2);
            if (((iVar3 != 0) &&
                (iVar3 = BN_mod_mul(unaff_s2,unaff_s2,unaff_s7,*(BIGNUM **)(param_4 + 0x10),unaff_s5
                                   ), iVar3 != 0)) &&
               ((iVar3 = BN_mod_mul(unaff_s7,*param_3,unaff_s7,*(BIGNUM **)(param_4 + 0x10),unaff_s5
                                   ), iVar3 != 0 &&
                ((pBVar4 = (BN_MONT_CTX *)0x0, (*(uint *)(param_4 + 0x28) & 1) == 0 ||
                 (pBVar4 = BN_MONT_CTX_set_locked
                                     ((BN_MONT_CTX **)(param_4 + 0x2c),8,*(BIGNUM **)(param_4 + 0xc)
                                      ,unaff_s5), pBVar4 != (BN_MONT_CTX *)0x0)))))) {
              pcVar6 = *(code **)(*(int *)(param_4 + 0x3c) + 0x10);
              if (pcVar6 == (code *)0x0) {
                iVar3 = (*(code *)PTR_BN_mod_exp2_mont_006a8764)
                                  (unaff_s8,*(undefined4 *)(param_4 + 0x14),unaff_s2,
                                   *(undefined4 *)(param_4 + 0x18),unaff_s7,
                                   *(undefined4 *)(param_4 + 0xc),unaff_s5,pBVar4);
              }
              else {
                iVar3 = (*pcVar6)(param_4,unaff_s8,*(undefined4 *)(param_4 + 0x14),unaff_s2,
                                  *(undefined4 *)(param_4 + 0x18),unaff_s7,
                                  *(undefined4 *)(param_4 + 0xc),unaff_s5,pBVar4);
              }
              if ((iVar3 != 0) &&
                 (iVar3 = (*(code *)PTR_BN_div_006a855c)
                                    (0,unaff_s2,unaff_s8,*(undefined4 *)(param_4 + 0x10),unaff_s5),
                 iVar3 != 0)) {
                iVar3 = (*(code *)PTR_BN_ucmp_006a7fb4)(unaff_s2,*param_3);
                unaff_s0 = (uint)(iVar3 == 0);
                if (iVar3 != 0) goto LAB_005140ac;
                uVar2 = 1;
                goto LAB_00513df0;
              }
            }
          }
        }
        uVar2 = 0xffffffff;
        ERR_put_error(10,0x71,3,s_dsa_ossl_c_00666e7c,0x19b);
        if (unaff_s5 == (BN_CTX *)0x0) goto LAB_00513dfc;
        goto LAB_00513df0;
      }
      reason = 0x67;
      iVar3 = 0x154;
    }
    else {
      reason = 0x66;
      iVar3 = 0x14f;
    }
  }
  ERR_put_error(10,0x71,reason,s_dsa_ossl_c_00666e7c,iVar3);
  uVar2 = 0xffffffff;
  while (local_2c != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_005140ac:
    ERR_put_error(10,0x71,3,s_dsa_ossl_c_00666e7c,0x19b);
    uVar2 = unaff_s0;
LAB_00513df0:
    BN_CTX_free(unaff_s5);
LAB_00513dfc:
    (*(code *)PTR_BN_free_006a701c)(unaff_s2);
    (*(code *)PTR_BN_free_006a701c)(unaff_s7);
    (*(code *)PTR_BN_free_006a701c)(unaff_s8);
    unaff_s0 = uVar2;
  }
  return uVar2;
}

