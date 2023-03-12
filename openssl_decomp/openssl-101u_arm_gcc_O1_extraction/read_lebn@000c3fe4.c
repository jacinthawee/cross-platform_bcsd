
undefined4 read_lebn(int *param_1,int param_2,BIGNUM **param_3)

{
  uchar *s;
  BIGNUM *pBVar1;
  int iVar2;
  uchar *puVar3;
  uchar *puVar4;
  uchar *puVar5;
  
  iVar2 = *param_1;
  s = (uchar *)CRYPTO_malloc(param_2,"pvkfmt.c",100);
  if (s != (uchar *)0x0) {
    puVar3 = s;
    puVar5 = (uchar *)(param_2 + -1 + iVar2);
    if (param_2 != 0) {
      do {
        puVar4 = puVar3 + 1;
        *puVar3 = *puVar5;
        puVar3 = puVar4;
        puVar5 = puVar5 + -1;
      } while (puVar4 != s + param_2);
    }
    pBVar1 = BN_bin2bn(s,param_2,(BIGNUM *)0x0);
    *param_3 = pBVar1;
    CRYPTO_free(s);
    if (*param_3 != (BIGNUM *)0x0) {
      *param_1 = param_2 + *param_1;
      return 1;
    }
  }
  return 0;
}

