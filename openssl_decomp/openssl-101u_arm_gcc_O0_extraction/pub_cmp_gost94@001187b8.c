
BIGNUM * pub_cmp_gost94(EVP_PKEY *param_1,EVP_PKEY *param_2)

{
  void *pvVar1;
  void *pvVar2;
  int iVar3;
  uint uVar4;
  BIGNUM *a;
  
  pvVar1 = EVP_PKEY_get0(param_1);
  pvVar2 = EVP_PKEY_get0(param_2);
  if (pvVar2 == (void *)0x0 || pvVar1 == (void *)0x0) {
    a = (BIGNUM *)0x0;
  }
  else {
    a = *(BIGNUM **)((int)pvVar1 + 0x18);
    if (a != (BIGNUM *)0x0) {
      if (*(BIGNUM **)((int)pvVar2 + 0x18) == (BIGNUM *)0x0) {
        return (BIGNUM *)0x0;
      }
      iVar3 = BN_cmp(a,*(BIGNUM **)((int)pvVar2 + 0x18));
      uVar4 = count_leading_zeroes(iVar3);
      return (BIGNUM *)(uVar4 >> 5);
    }
  }
  return a;
}

