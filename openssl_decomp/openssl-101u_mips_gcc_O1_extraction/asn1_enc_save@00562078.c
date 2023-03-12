
int asn1_enc_save(ASN1_VALUE **pval,uchar *in,int inlen,ASN1_ITEM *it)

{
  int iVar1;
  void *pvVar2;
  int *piVar3;
  
  if ((((pval == (ASN1_VALUE **)0x0) || (*pval == (ASN1_VALUE *)0x0)) ||
      (pvVar2 = it->funcs, pvVar2 == (void *)0x0)) || ((*(uint *)((int)pvVar2 + 4) & 2) == 0)) {
    return 1;
  }
  piVar3 = (int *)(*pval + *(int *)((int)pvVar2 + 0x14));
  if (piVar3 != (int *)0x0) {
    if (*piVar3 != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    iVar1 = (*(code *)PTR_CRYPTO_malloc_006a7008)(inlen,"tasn_utl.c",0xae);
    *piVar3 = iVar1;
    if (iVar1 == 0) {
      return 0;
    }
    (*(code *)PTR_memcpy_006a9aec)(iVar1,in,inlen);
    piVar3[1] = inlen;
    piVar3[2] = 0;
  }
  return 1;
}

