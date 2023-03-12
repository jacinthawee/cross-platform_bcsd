
uint hwcrhk_mutex_init(int *param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = CRYPTO_get_new_dynlockid();
  uVar2 = count_leading_zeroes(iVar1);
  *param_1 = iVar1;
  return uVar2 >> 5;
}

