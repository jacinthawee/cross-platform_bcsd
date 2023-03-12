
size_t ** i2s_ASN1_IA5STRING(undefined4 param_1,size_t **param_2)

{
  size_t **__dest;
  
  __dest = param_2;
  if ((param_2 != (size_t **)0x0) && (__dest = (size_t **)*param_2, __dest != (size_t **)0x0)) {
    __dest = (size_t **)CRYPTO_malloc((int)__dest + 1,"v3_ia5.c",0x57);
    if (__dest == (size_t **)0x0) {
      ERR_put_error(0x22,0x95,0x41,"v3_ia5.c",0x58);
    }
    else {
      memcpy(__dest,param_2[2],(size_t)*param_2);
      *(undefined *)((int)__dest + (int)*param_2) = 0;
    }
  }
  return __dest;
}

