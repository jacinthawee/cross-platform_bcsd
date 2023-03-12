
uint param_missing_gost94(EVP_PKEY *param_1)

{
  void *pvVar1;
  uint uVar2;
  
  pvVar1 = EVP_PKEY_get0(param_1);
  if (pvVar1 != (void *)0x0) {
    uVar2 = count_leading_zeroes(*(undefined4 *)((int)pvVar1 + 0x10));
    return uVar2 >> 5;
  }
  return 1;
}

