
bool pub_cmp_gost94(EVP_PKEY *param_1,EVP_PKEY *param_2)

{
  void *pvVar1;
  void *pvVar2;
  int iVar3;
  bool bVar4;
  
  pvVar1 = EVP_PKEY_get0(param_1);
  pvVar2 = EVP_PKEY_get0(param_2);
  if (((pvVar1 != (void *)0x0) && (pvVar2 != (void *)0x0)) &&
     (*(BIGNUM **)((int)pvVar1 + 0x18) != (BIGNUM *)0x0)) {
    bVar4 = false;
    if (*(BIGNUM **)((int)pvVar2 + 0x18) != (BIGNUM *)0x0) {
      iVar3 = BN_cmp(*(BIGNUM **)((int)pvVar1 + 0x18),*(BIGNUM **)((int)pvVar2 + 0x18));
      bVar4 = iVar3 == 0;
    }
    return bVar4;
  }
  return false;
}

