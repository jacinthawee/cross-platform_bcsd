
size_t old_hmac_encode(int param_1,void **param_2)

{
  size_t *psVar1;
  size_t sVar2;
  void *__dest;
  
  psVar1 = *(size_t **)(param_1 + 0x14);
  if (param_2 != (void **)0x0) {
    if (*param_2 == (void *)0x0) {
      __dest = CRYPTO_malloc(*psVar1,"hm_ameth.c",0x7d);
      *param_2 = __dest;
      memcpy(__dest,(void *)psVar1[2],*psVar1);
      sVar2 = *psVar1;
    }
    else {
      memcpy(*param_2,(void *)psVar1[2],*psVar1);
      sVar2 = *psVar1;
      *param_2 = (void *)((int)*param_2 + sVar2);
    }
    return sVar2;
  }
  return *psVar1;
}

