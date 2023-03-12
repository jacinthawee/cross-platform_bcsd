
void hwcrhk_mutex_unlock(char **param_1)

{
  CRYPTO_lock((int)param_1,10,*param_1,(int)"e_chil.c");
  return;
}

