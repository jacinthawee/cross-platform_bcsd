
undefined4 pkey_dsa_ctrl(int param_1,int param_2,uint param_3,EVP_MD *param_4)

{
  int iVar1;
  uint *puVar2;
  
  puVar2 = *(uint **)(param_1 + 0x14);
  if (param_2 != 7) {
    if (param_2 < 8) {
      if (param_2 == 2) {
        ERR_put_error(10,0x78,0x96,"dsa_pmeth.c",0xcf);
        return 0xfffffffe;
      }
      if (param_2 == 5) {
        return 1;
      }
      if (param_2 != 1) {
        return 0xfffffffe;
      }
      iVar1 = EVP_MD_type(param_4);
      if ((((iVar1 != 0x40) && (iVar1 = EVP_MD_type(param_4), iVar1 != 0x74)) &&
          (iVar1 = EVP_MD_type(param_4), iVar1 != 0x42)) &&
         (((iVar1 = EVP_MD_type(param_4), iVar1 != 0x2a3 &&
           (iVar1 = EVP_MD_type(param_4), iVar1 != 0x2a0)) &&
          ((iVar1 = EVP_MD_type(param_4), iVar1 != 0x2a1 &&
           (iVar1 = EVP_MD_type(param_4), iVar1 != 0x2a2)))))) {
        iVar1 = 0xc2;
        goto LAB_00107c7c;
      }
    }
    else {
      if (param_2 == 0x1001) {
        if (0xff < (int)param_3) {
          *puVar2 = param_3;
          return 1;
        }
        return 0xfffffffe;
      }
      if (param_2 < 0x1002) {
        if (param_2 == 0xb) {
          return 1;
        }
        return 0xfffffffe;
      }
      if (param_2 == 0x1002) {
        if (((param_3 & 0xffffffbf) != 0xa0) && ((param_3 & 0xfffffeff) != 0)) {
          return 0xfffffffe;
        }
        puVar2[1] = param_3;
        return 1;
      }
      if (param_2 != 0x1003) {
        return 0xfffffffe;
      }
      iVar1 = EVP_MD_type(param_4);
      if (((iVar1 != 0x40) && (iVar1 = EVP_MD_type(param_4), iVar1 != 0x2a3)) &&
         (iVar1 = EVP_MD_type(param_4), iVar1 != 0x2a0)) {
        iVar1 = 0xb4;
LAB_00107c7c:
        ERR_put_error(10,0x78,0x6a,"dsa_pmeth.c",iVar1);
        return 0;
      }
    }
    puVar2[5] = (uint)param_4;
  }
  return 1;
}

