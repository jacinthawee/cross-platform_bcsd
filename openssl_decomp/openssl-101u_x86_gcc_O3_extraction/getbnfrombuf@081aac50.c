
BIGNUM * getbnfrombuf(uchar *param_1,int param_2)

{
  uchar uVar1;
  BIGNUM *pBVar2;
  
  uVar1 = *param_1;
  while (uVar1 == '\0') {
    if (param_2 == 0) goto LAB_081aac77;
    param_1 = param_1 + 1;
    param_2 = param_2 + -1;
    uVar1 = *param_1;
  }
  if (param_2 != 0) {
    pBVar2 = BN_bin2bn(param_1,param_2,(BIGNUM *)0x0);
    return pBVar2;
  }
LAB_081aac77:
  pBVar2 = BN_new();
  BN_set_word(pBVar2,0);
  return pBVar2;
}

