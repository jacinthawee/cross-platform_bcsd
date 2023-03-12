
DSA_SIG * unpack_cp_signature(uchar *param_1,uint param_2)

{
  uchar uVar1;
  DSA_SIG *pDVar2;
  BIGNUM *pBVar3;
  uchar *s;
  uint len;
  
  pDVar2 = DSA_SIG_new();
  if (pDVar2 == (DSA_SIG *)0x0) {
    ERR_GOST_error(0x89,0x76,"gost_sign.c",0x111);
    pDVar2 = (DSA_SIG *)0x0;
  }
  else {
    param_2 = param_2 >> 1;
    uVar1 = *param_1;
    len = param_2;
    s = param_1;
    while (uVar1 == '\0') {
      if (len == 0) goto LAB_081abe30;
      s = s + 1;
      len = len - 1;
      uVar1 = *s;
    }
    if (len == 0) {
LAB_081abe30:
      pBVar3 = BN_new();
      BN_set_word(pBVar3,0);
    }
    else {
      pBVar3 = BN_bin2bn(s,len,(BIGNUM *)0x0);
    }
    param_1 = param_1 + param_2;
    pDVar2->s = pBVar3;
    uVar1 = *param_1;
    while (uVar1 == '\0') {
      if (param_2 == 0) goto LAB_081abe67;
      param_1 = param_1 + 1;
      param_2 = param_2 - 1;
      uVar1 = *param_1;
    }
    if (param_2 == 0) {
LAB_081abe67:
      pBVar3 = BN_new();
      BN_set_word(pBVar3,0);
    }
    else {
      pBVar3 = BN_bin2bn(param_1,param_2,(BIGNUM *)0x0);
    }
    pDVar2->r = pBVar3;
  }
  return pDVar2;
}

