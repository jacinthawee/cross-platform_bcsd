
int asn1_enc_restore(int *len,uchar **out,ASN1_VALUE **pval,ASN1_ITEM *it)

{
  void *pvVar1;
  uint uVar2;
  void **ppvVar3;
  
  if (((pval != (ASN1_VALUE **)0x0) && (*pval != (ASN1_VALUE *)0x0)) &&
     (pvVar1 = it->funcs, pvVar1 != (void *)0x0)) {
    uVar2 = *(uint *)((int)pvVar1 + 4) & 2;
    if (uVar2 != 0) {
      uVar2 = 0;
      ppvVar3 = (void **)(*pval + *(int *)((int)pvVar1 + 0x14));
      if ((ppvVar3 != (void **)0x0) && (ppvVar3[2] == (void *)0x0)) {
        if (out != (uchar **)0x0) {
          memcpy(*out,*ppvVar3,(size_t)ppvVar3[1]);
          *out = *out + (int)ppvVar3[1];
        }
        if (len == (int *)0x0) {
          uVar2 = 1;
        }
        else {
          *len = (int)ppvVar3[1];
          uVar2 = 1;
        }
      }
    }
    return uVar2;
  }
  return 0;
}

