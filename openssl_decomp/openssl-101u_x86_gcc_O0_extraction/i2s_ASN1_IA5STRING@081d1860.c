
void * i2s_ASN1_IA5STRING(undefined4 param_1,size_t *param_2)

{
  void *__dest;
  void *pvVar1;
  
  if (param_2 == (size_t *)0x0) {
    pvVar1 = (void *)0x0;
  }
  else {
    pvVar1 = (void *)0x0;
    if (*param_2 != 0) {
      __dest = CRYPTO_malloc(*param_2 + 1,"v3_ia5.c",0x57);
      if (__dest == (void *)0x0) {
        ERR_put_error(0x22,0x95,0x41,"v3_ia5.c",0x58);
      }
      else {
        memcpy(__dest,(void *)param_2[2],*param_2);
        *(undefined *)((int)__dest + *param_2) = 0;
        pvVar1 = __dest;
      }
    }
  }
  return pvVar1;
}

