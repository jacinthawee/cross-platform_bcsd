
bool hwcrhk_mutex_init(int *param_1)

{
  int iVar1;
  
  iVar1 = CRYPTO_get_new_dynlockid();
  *param_1 = iVar1;
  return iVar1 == 0;
}

