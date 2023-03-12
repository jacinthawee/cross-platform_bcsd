
undefined4 pkey_ec_ctrl(int param_1,int param_2,int param_3,EVP_MD *param_4)

{
  EC_GROUP **ppEVar1;
  EC_GROUP *pEVar2;
  int iVar3;
  int line;
  
  ppEVar1 = *(EC_GROUP ***)(param_1 + 0x14);
  if (param_2 != 5) {
    if (param_2 < 6) {
      if (param_2 == 1) {
        iVar3 = EVP_MD_type(param_4);
        if ((((iVar3 == 0x40) || (iVar3 = EVP_MD_type(param_4), iVar3 == 0x1a0)) ||
            (iVar3 = EVP_MD_type(param_4), iVar3 == 0x2a3)) ||
           (((iVar3 = EVP_MD_type(param_4), iVar3 == 0x2a0 ||
             (iVar3 = EVP_MD_type(param_4), iVar3 == 0x2a1)) ||
            (iVar3 = EVP_MD_type(param_4), iVar3 == 0x2a2)))) {
          ppEVar1[1] = (EC_GROUP *)param_4;
          return 1;
        }
        line = 0xe6;
        iVar3 = 0x8a;
LAB_081be915:
        ERR_put_error(0x10,0xc5,iVar3,"ec_pmeth.c",line);
        return 0;
      }
      if (param_2 != 2) {
        return 0xfffffffe;
      }
    }
    else if (param_2 != 0xb) {
      if (param_2 == 0x1001) {
        pEVar2 = EC_GROUP_new_by_curve_name(param_3);
        if (pEVar2 != (EC_GROUP *)0x0) {
          if (*ppEVar1 != (EC_GROUP *)0x0) {
            EC_GROUP_free(*ppEVar1);
          }
          *ppEVar1 = pEVar2;
          return 1;
        }
        line = 0xd6;
        iVar3 = 0x8d;
        goto LAB_081be915;
      }
      if (param_2 != 7) {
        return 0xfffffffe;
      }
    }
  }
  return 1;
}

