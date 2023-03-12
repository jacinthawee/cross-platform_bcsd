
undefined4 pkey_dsa_ctrl(int param_1,int param_2,uint param_3,EVP_MD *param_4)

{
  uint *puVar1;
  int iVar2;
  
  puVar1 = *(uint **)(param_1 + 0x14);
  if (param_2 == 7) {
    return 1;
  }
  if (param_2 < 8) {
    if (param_2 == 2) {
      ERR_put_error(10,0x78,0x96,"dsa_pmeth.c",0xd1);
      return 0xfffffffe;
    }
    if (param_2 == 5) {
      return 1;
    }
    if (param_2 != 1) {
      return 0xfffffffe;
    }
    iVar2 = EVP_MD_type(param_4);
    if ((((iVar2 == 0x40) || (iVar2 = EVP_MD_type(param_4), iVar2 == 0x74)) ||
        (iVar2 = EVP_MD_type(param_4), iVar2 == 0x42)) ||
       (((iVar2 = EVP_MD_type(param_4), iVar2 == 0x2a3 ||
         (iVar2 = EVP_MD_type(param_4), iVar2 == 0x2a0)) ||
        ((iVar2 = EVP_MD_type(param_4), iVar2 == 0x2a1 ||
         (iVar2 = EVP_MD_type(param_4), iVar2 == 0x2a2)))))) goto LAB_081c44c0;
    iVar2 = 0xc4;
  }
  else {
    if (param_2 == 0x1001) {
      if ((int)param_3 < 0x100) {
        return 0xfffffffe;
      }
      *puVar1 = param_3;
      return 1;
    }
    if (param_2 < 0x1002) {
      if (param_2 != 0xb) {
        return 0xfffffffe;
      }
      return 1;
    }
    if (param_2 == 0x1002) {
      if (((param_3 & 0xffffffbf) != 0xa0) && ((param_3 & 0xfffffeff) != 0)) {
        return 0xfffffffe;
      }
      puVar1[1] = param_3;
      return 1;
    }
    if (param_2 != 0x1003) {
      return 0xfffffffe;
    }
    iVar2 = EVP_MD_type(param_4);
    if (((iVar2 == 0x40) || (iVar2 = EVP_MD_type(param_4), iVar2 == 0x2a3)) ||
       (iVar2 = EVP_MD_type(param_4), iVar2 == 0x2a0)) {
LAB_081c44c0:
      puVar1[5] = (uint)param_4;
      return 1;
    }
    iVar2 = 0xb5;
  }
  ERR_put_error(10,0x78,0x6a,"dsa_pmeth.c",iVar2);
  return 0;
}

