
int ec_GFp_mont_group_set_curve
              (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  if (*(int *)(param_1 + 0xa0) != 0) {
    (*(code *)PTR_BN_MONT_CTX_free_006a9690)();
    *(undefined4 *)(param_1 + 0xa0) = 0;
  }
  if (*(int *)(param_1 + 0xa4) != 0) {
    (*(code *)PTR_BN_free_006a811c)();
    *(undefined4 *)(param_1 + 0xa4) = 0;
  }
  if (param_5 == 0) {
    param_5 = (*(code *)PTR_BN_CTX_new_006a8a38)();
    if (param_5 == 0) {
      return 0;
    }
    iVar2 = (*(code *)PTR_BN_MONT_CTX_new_006a9688)();
    iVar6 = param_5;
    if (iVar2 == 0) {
      iVar2 = 0;
      goto LAB_00627a80;
    }
  }
  else {
    iVar2 = (*(code *)PTR_BN_MONT_CTX_new_006a9688)();
    if (iVar2 == 0) {
      return 0;
    }
    iVar6 = 0;
  }
  iVar3 = (*(code *)PTR_BN_MONT_CTX_set_006a968c)(iVar2,param_2,param_5);
  if (iVar3 == 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xbd,3,"ecp_mont.c",0xe9);
  }
  else {
    iVar3 = (*(code *)PTR_BN_new_006a82b4)();
    if (iVar3 != 0) {
      uVar4 = (*(code *)PTR_BN_value_one_006a9670)();
      iVar5 = (*(code *)PTR_BN_mod_mul_montgomery_006a9674)(iVar3,uVar4,iVar2 + 4,iVar2,param_5);
      if (iVar5 != 0) {
        *(int *)(param_1 + 0xa0) = iVar2;
        *(int *)(param_1 + 0xa4) = iVar3;
        iVar2 = ec_GFp_simple_group_set_curve(param_1,param_2,param_3,param_4,param_5);
        if (iVar2 == 0) {
          (*(code *)PTR_BN_MONT_CTX_free_006a9690)(*(undefined4 *)(param_1 + 0xa0));
          puVar1 = PTR_BN_free_006a811c;
          *(undefined4 *)(param_1 + 0xa0) = 0;
          (*(code *)puVar1)(*(undefined4 *)(param_1 + 0xa4));
          *(undefined4 *)(param_1 + 0xa4) = 0;
        }
        param_5 = iVar6;
        if (iVar6 == 0) {
          return iVar2;
        }
LAB_00627a80:
        (*(code *)PTR_BN_CTX_free_006a8a40)(param_5);
        return iVar2;
      }
    }
  }
  if (iVar6 != 0) {
    (*(code *)PTR_BN_CTX_free_006a8a40)(iVar6);
  }
  (*(code *)PTR_BN_MONT_CTX_free_006a9690)(iVar2);
  return 0;
}

