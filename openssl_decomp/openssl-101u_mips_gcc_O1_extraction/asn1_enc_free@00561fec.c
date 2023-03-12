
void asn1_enc_free(ASN1_VALUE **pval,ASN1_ITEM *it)

{
  void *pvVar1;
  int *piVar2;
  
  if ((((pval != (ASN1_VALUE **)0x0) && (*pval != (ASN1_VALUE *)0x0)) &&
      (pvVar1 = it->funcs, pvVar1 != (void *)0x0)) &&
     (((*(uint *)((int)pvVar1 + 4) & 2) != 0 &&
      (piVar2 = (int *)(*pval + *(int *)((int)pvVar1 + 0x14)), piVar2 != (int *)0x0)))) {
    if (*piVar2 != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    *piVar2 = 0;
    piVar2[1] = 0;
    piVar2[2] = 1;
  }
  return;
}

