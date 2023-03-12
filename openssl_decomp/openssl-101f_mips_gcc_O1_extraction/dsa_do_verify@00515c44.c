
uint dsa_do_verify(uchar *param_1,int param_2,BIGNUM **param_3,uint param_4)

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
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (((*(int *)(param_4 + 0xc) == 0) || (unaff_s0 = param_4, *(int *)(param_4 + 0x10) == 0)) ||
     (*(int *)(param_4 + 0x14) == 0)) {
    reason = 0x65;
    iVar3 = 0x13c;
  }
  else {
    uVar2 = (*(code *)PTR_BN_num_bits_006a82f4)();
    if (((uVar2 & 0xffffffbf) == 0xa0) || (uVar2 == 0x100)) {
      iVar3 = (*(code *)PTR_BN_num_bits_006a82f4)(*(undefined4 *)(param_4 + 0xc));
      if (iVar3 < 0x2711) {
        unaff_s2 = &BStack_68;
        unaff_s7 = &BStack_54;
        (*(code *)PTR_BN_init_006a96a0)(unaff_s2);
        unaff_s8 = auStack_40;
        (*(code *)PTR_BN_init_006a96a0)(unaff_s7);
        (*(code *)PTR_BN_init_006a96a0)(unaff_s8);
        unaff_s5 = BN_CTX_new();
        if (unaff_s5 != (BN_CTX *)0x0) {
          pBVar5 = *param_3;
          if (((pBVar5->top == 0) || (pBVar5->neg != 0)) ||
             ((iVar3 = BN_ucmp(pBVar5,*(BIGNUM **)(param_4 + 0x10)), -1 < iVar3 ||
              (((pBVar5 = param_3[1], pBVar5->top == 0 || (pBVar5->neg != 0)) ||
               (iVar3 = BN_ucmp(pBVar5,*(BIGNUM **)(param_4 + 0x10)), -1 < iVar3)))))) {
            ERR_put_error(10,0x71,3,"dsa_ossl.c",0x188);
            uVar2 = 0;
            goto LAB_00515d90;
          }
          iVar3 = (*(code *)PTR_BN_mod_inverse_006a9714)
                            (unaff_s7,param_3[1],*(undefined4 *)(param_4 + 0x10),unaff_s5);
          if (iVar3 != 0) {
            if ((int)uVar2 >> 3 <= param_2) {
              param_2 = (int)uVar2 >> 3;
            }
            pBVar5 = BN_bin2bn(param_1,param_2,unaff_s2);
            if (((pBVar5 != (BIGNUM *)0x0) &&
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
                iVar3 = (*(code *)PTR_BN_mod_exp2_mont_006a9888)
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
                 (iVar3 = (*(code *)PTR_BN_div_006a967c)
                                    (0,unaff_s2,unaff_s8,*(undefined4 *)(param_4 + 0x10),unaff_s5),
                 iVar3 != 0)) {
                iVar3 = BN_ucmp(unaff_s2,*param_3);
                unaff_s0 = (uint)(iVar3 == 0);
                if (iVar3 != 0) goto LAB_0051604c;
                uVar2 = 1;
                goto LAB_00515d90;
              }
            }
          }
        }
        uVar2 = 0xffffffff;
        ERR_put_error(10,0x71,3,"dsa_ossl.c",0x188);
        if (unaff_s5 == (BN_CTX *)0x0) goto LAB_00515d9c;
        goto LAB_00515d90;
      }
      reason = 0x67;
      iVar3 = 0x14a;
    }
    else {
      reason = 0x66;
      iVar3 = 0x144;
    }
  }
  ERR_put_error(10,0x71,reason,"dsa_ossl.c",iVar3);
  uVar2 = 0xffffffff;
  while (local_2c != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_0051604c:
    ERR_put_error(10,0x71,3,"dsa_ossl.c",0x188);
    uVar2 = unaff_s0;
LAB_00515d90:
    BN_CTX_free(unaff_s5);
LAB_00515d9c:
    (*(code *)PTR_BN_free_006a811c)(unaff_s2);
    (*(code *)PTR_BN_free_006a811c)(unaff_s7);
    (*(code *)PTR_BN_free_006a811c)(unaff_s8);
    unaff_s0 = uVar2;
  }
  return uVar2;
}

