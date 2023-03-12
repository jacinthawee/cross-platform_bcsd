
int asn1_enc_restore(int *len,uchar **out,ASN1_VALUE **pval,ASN1_ITEM *it)

{
  uint uVar1;
  void *pvVar2;
  ASN1_VALUE *pAVar3;
  ASN1_VALUE *pAVar4;
  
  if (pval == (ASN1_VALUE **)0x0) {
    return 0;
  }
  pAVar3 = *pval;
  if (pAVar3 == (ASN1_VALUE *)0x0) {
    return 0;
  }
  pvVar2 = it->funcs;
  if (pvVar2 == (void *)0x0) {
    return 0;
  }
  uVar1 = *(uint *)((int)pvVar2 + 4) & 2;
  if (uVar1 != 0) {
    pAVar4 = pAVar3 + *(int *)((int)pvVar2 + 0x14);
    if (pAVar4 == (ASN1_VALUE *)0x0) {
      return 0;
    }
    if (*(int *)(pAVar4 + 8) != 0) {
      return 0;
    }
    if (out != (uchar **)0x0) {
      memcpy(*out,*(void **)(pAVar3 + *(int *)((int)pvVar2 + 0x14)),*(size_t *)(pAVar4 + 4));
      *out = *out + *(int *)(pAVar4 + 4);
    }
    if (len != (int *)0x0) {
      *len = *(int *)(pAVar4 + 4);
      return 1;
    }
    uVar1 = 1;
  }
  return uVar1;
}

