
undefined4 pkey_ec_ctrl(int param_1,int param_2,int param_3,EVP_MD *param_4)

{
  EC_GROUP *pEVar1;
  int iVar2;
  EC_GROUP **ppEVar3;
  
  ppEVar3 = *(EC_GROUP ***)(param_1 + 0x14);
  if (param_2 != 5) {
    if (param_2 < 6) {
      if (param_2 == 1) {
        iVar2 = EVP_MD_type(param_4);
        if ((((iVar2 != 0x40) && (iVar2 = EVP_MD_type(param_4), iVar2 != 0x1a0)) &&
            (iVar2 = EVP_MD_type(param_4), iVar2 != 0x2a3)) &&
           (((iVar2 = EVP_MD_type(param_4), iVar2 != 0x2a0 &&
             (iVar2 = EVP_MD_type(param_4), iVar2 != 0x2a1)) &&
            (iVar2 = EVP_MD_type(param_4), iVar2 != 0x2a2)))) {
          ERR_put_error(0x10,0xc5,0x8a,"ec_pmeth.c",0xdf);
          return 0;
        }
        ppEVar3[1] = (EC_GROUP *)param_4;
        return 1;
      }
      if (param_2 != 2) {
        return 0xfffffffe;
      }
    }
    else if (param_2 != 0xb) {
      if (param_2 == 0x1001) {
        pEVar1 = EC_GROUP_new_by_curve_name(param_3);
        if (pEVar1 == (EC_GROUP *)0x0) {
          ERR_put_error(0x10,0xc5,0x8d,"ec_pmeth.c",0xd0);
          return 0;
        }
        if (*ppEVar3 != (EC_GROUP *)0x0) {
          EC_GROUP_free(*ppEVar3);
        }
        *ppEVar3 = pEVar1;
      }
      else if (param_2 != 7) {
        return 0xfffffffe;
      }
    }
  }
  return 1;
}

