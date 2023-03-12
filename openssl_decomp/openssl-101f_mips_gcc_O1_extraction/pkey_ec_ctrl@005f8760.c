
undefined4 pkey_ec_ctrl(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int *piVar4;
  
  piVar4 = *(int **)(param_1 + 0x14);
  if (param_2 != 5) {
    if (param_2 < 6) {
      if (param_2 == 1) {
        iVar1 = (*(code *)PTR_EVP_MD_type_006a84cc)(param_4);
        if ((((iVar1 == 0x40) ||
             (iVar1 = (*(code *)PTR_EVP_MD_type_006a84cc)(param_4), iVar1 == 0x1a0)) ||
            (iVar1 = (*(code *)PTR_EVP_MD_type_006a84cc)(param_4), iVar1 == 0x2a3)) ||
           (((iVar1 = (*(code *)PTR_EVP_MD_type_006a84cc)(param_4), iVar1 == 0x2a0 ||
             (iVar1 = (*(code *)PTR_EVP_MD_type_006a84cc)(param_4), iVar1 == 0x2a1)) ||
            (iVar1 = (*(code *)PTR_EVP_MD_type_006a84cc)(param_4), iVar1 == 0x2a2)))) {
          piVar4[1] = param_4;
          return 1;
        }
        uVar3 = 0x8a;
        uVar2 = 0xe6;
LAB_005f88c0:
        (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xc5,uVar3,"ec_pmeth.c",uVar2);
        return 0;
      }
      if (param_2 != 2) {
        return 0xfffffffe;
      }
    }
    else if (param_2 != 0xb) {
      if (param_2 == 0x1001) {
        iVar1 = (*(code *)PTR_EC_GROUP_new_by_curve_name_006a8284)(param_3);
        if (iVar1 != 0) {
          if (*piVar4 != 0) {
            (*(code *)PTR_EC_GROUP_free_006a829c)();
          }
          *piVar4 = iVar1;
          return 1;
        }
        uVar3 = 0x8d;
        uVar2 = 0xd6;
        goto LAB_005f88c0;
      }
      if (param_2 != 7) {
        return 0xfffffffe;
      }
    }
  }
  return 1;
}

