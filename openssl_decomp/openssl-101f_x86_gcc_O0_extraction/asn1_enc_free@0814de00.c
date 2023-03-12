
void asn1_enc_free(ASN1_VALUE **pval,ASN1_ITEM *it)

{
  void *pvVar1;
  void **ppvVar2;
  
  if ((((pval != (ASN1_VALUE **)0x0) && (*pval != (ASN1_VALUE *)0x0)) &&
      (pvVar1 = it->funcs, pvVar1 != (void *)0x0)) &&
     (((*(byte *)((int)pvVar1 + 4) & 2) != 0 &&
      (ppvVar2 = (void **)(*pval + *(int *)((int)pvVar1 + 0x14)), ppvVar2 != (void **)0x0)))) {
    if (*ppvVar2 != (void *)0x0) {
      CRYPTO_free(*ppvVar2);
    }
    *ppvVar2 = (void *)0x0;
    ppvVar2[1] = (void *)0x0;
    ppvVar2[2] = (void *)0x1;
  }
  return;
}

