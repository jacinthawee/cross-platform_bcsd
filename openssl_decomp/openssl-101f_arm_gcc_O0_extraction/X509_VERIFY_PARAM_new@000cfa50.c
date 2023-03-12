
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

X509_VERIFY_PARAM * X509_VERIFY_PARAM_new(void)

{
  X509_VERIFY_PARAM *__s;
  
  __s = (X509_VERIFY_PARAM *)CRYPTO_malloc(0x20,"x509_vpm.c",0x5b);
  memset(__s,0,0x20);
  if (__s != (X509_VERIFY_PARAM *)0x0) {
    __s->name = (char *)0x0;
    __s->purpose = 0;
    __s->trust = 0;
    __s->inh_flags = 0;
    __s->flags = 0;
    __s->depth = -1;
    if ((_STACK *)__s->policies != (_STACK *)0x0) {
      sk_pop_free((_STACK *)__s->policies,ASN1_OBJECT_free + 1);
      __s->policies = (stack_st_ASN1_OBJECT *)0x0;
    }
  }
  return __s;
}

