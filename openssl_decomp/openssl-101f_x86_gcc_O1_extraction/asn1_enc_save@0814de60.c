
int asn1_enc_save(ASN1_VALUE **pval,uchar *in,int inlen,ASN1_ITEM *it)

{
  void *pvVar1;
  int iVar2;
  void **ppvVar3;
  
  if ((pval != (ASN1_VALUE **)0x0) && (*pval != (ASN1_VALUE *)0x0)) {
    iVar2 = 1;
    pvVar1 = it->funcs;
    if (((pvVar1 != (void *)0x0) && ((*(byte *)((int)pvVar1 + 4) & 2) != 0)) &&
       (ppvVar3 = (void **)(*pval + *(int *)((int)pvVar1 + 0x14)), ppvVar3 != (void **)0x0)) {
      if (*ppvVar3 != (void *)0x0) {
        CRYPTO_free(*ppvVar3);
      }
      pvVar1 = CRYPTO_malloc(inlen,"tasn_utl.c",0xaf);
      iVar2 = 0;
      *ppvVar3 = pvVar1;
      if (pvVar1 != (void *)0x0) {
        memcpy(pvVar1,in,inlen);
        ppvVar3[1] = (void *)inlen;
        ppvVar3[2] = (void *)0x0;
        iVar2 = 1;
      }
    }
    return iVar2;
  }
  return 1;
}

