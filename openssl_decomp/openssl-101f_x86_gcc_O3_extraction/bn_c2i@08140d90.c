
undefined4
bn_c2i(BIGNUM **param_1,uchar *param_2,int param_3,undefined4 param_4,undefined4 param_5,int param_6
      )

{
  BIGNUM *pBVar1;
  undefined4 uVar2;
  
  pBVar1 = *param_1;
  if (pBVar1 == (BIGNUM *)0x0) {
    pBVar1 = BN_new();
    *param_1 = pBVar1;
  }
  pBVar1 = BN_bin2bn(param_2,param_3,pBVar1);
  uVar2 = 1;
  if (pBVar1 == (BIGNUM *)0x0) {
    pBVar1 = *param_1;
    if (pBVar1 == (BIGNUM *)0x0) {
      uVar2 = 0;
    }
    else {
      if ((*(byte *)(param_6 + 0x14) & 1) == 0) {
        BN_free(pBVar1);
      }
      else {
        BN_clear_free(pBVar1);
      }
      *param_1 = (BIGNUM *)0x0;
      uVar2 = 0;
    }
  }
  return uVar2;
}

