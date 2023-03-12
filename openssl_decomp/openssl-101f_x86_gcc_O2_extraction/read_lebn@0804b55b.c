
undefined4 __regparm3 read_lebn(int *param_1,int param_2,BIGNUM **param_3)

{
  int iVar1;
  uchar *s;
  BIGNUM *pBVar2;
  int len;
  
  iVar1 = *param_1;
  s = (uchar *)CRYPTO_malloc(param_2,"pvkfmt.c",0x60);
  if (s != (uchar *)0x0) {
    for (len = 0; len != param_2; len = len + 1) {
      s[len] = *(uchar *)((iVar1 + -1 + param_2) - len);
    }
    pBVar2 = BN_bin2bn(s,len,(BIGNUM *)0x0);
    *param_3 = pBVar2;
    CRYPTO_free(s);
    if (*param_3 != (BIGNUM *)0x0) {
      *param_1 = *param_1 + len;
      return 1;
    }
  }
  return 0;
}

