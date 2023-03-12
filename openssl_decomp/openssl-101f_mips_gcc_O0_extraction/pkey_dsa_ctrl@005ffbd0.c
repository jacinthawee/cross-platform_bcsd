
undefined4 pkey_dsa_ctrl(int param_1,int param_2,uint param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint *puVar3;
  
  puVar3 = *(uint **)(param_1 + 0x14);
  if (param_2 == 7) {
    return 1;
  }
  if (param_2 < 8) {
    if (param_2 == 2) {
      (*(code *)PTR_ERR_put_error_006a9030)(10,0x78,0x96,"dsa_pmeth.c",0xd1);
      return 0xfffffffe;
    }
    if (param_2 == 5) {
      return 1;
    }
    if (param_2 == 1) {
      iVar1 = (*(code *)PTR_EVP_MD_type_006a84cc)(param_4);
      if ((((iVar1 == 0x40) || (iVar1 = (*(code *)PTR_EVP_MD_type_006a84cc)(param_4), iVar1 == 0x74)
           ) || (iVar1 = (*(code *)PTR_EVP_MD_type_006a84cc)(param_4), iVar1 == 0x42)) ||
         (((iVar1 = (*(code *)PTR_EVP_MD_type_006a84cc)(param_4), iVar1 == 0x2a3 ||
           (iVar1 = (*(code *)PTR_EVP_MD_type_006a84cc)(param_4), iVar1 == 0x2a0)) ||
          ((iVar1 = (*(code *)PTR_EVP_MD_type_006a84cc)(param_4), iVar1 == 0x2a1 ||
           (iVar1 = (*(code *)PTR_EVP_MD_type_006a84cc)(param_4), iVar1 == 0x2a2)))))) {
LAB_005ffde8:
        puVar3[5] = param_4;
        return 1;
      }
      uVar2 = 0xc4;
LAB_005ffd58:
      (*(code *)PTR_ERR_put_error_006a9030)(10,0x78,0x6a,"dsa_pmeth.c",uVar2);
      return 0;
    }
  }
  else if (param_2 == 0x1001) {
    if (0xff < (int)param_3) {
      *puVar3 = param_3;
      return 1;
    }
  }
  else {
    if (param_2 < 0x1002) {
      if (param_2 != 0xb) {
        return 0xfffffffe;
      }
      return 1;
    }
    if (param_2 == 0x1002) {
      if (((param_3 & 0xffffffbf) == 0xa0) || ((param_3 & 0xfffffeff) == 0)) {
        puVar3[1] = param_3;
        return 1;
      }
    }
    else if (param_2 == 0x1003) {
      iVar1 = (*(code *)PTR_EVP_MD_type_006a84cc)(param_4);
      if (((iVar1 == 0x40) || (iVar1 = (*(code *)PTR_EVP_MD_type_006a84cc)(param_4), iVar1 == 0x2a3)
          ) || (iVar1 = (*(code *)PTR_EVP_MD_type_006a84cc)(param_4), iVar1 == 0x2a0))
      goto LAB_005ffde8;
      uVar2 = 0xb5;
      goto LAB_005ffd58;
    }
  }
  return 0xfffffffe;
}

