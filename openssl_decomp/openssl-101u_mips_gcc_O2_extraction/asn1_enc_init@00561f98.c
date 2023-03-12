
void asn1_enc_init(ASN1_VALUE **pval,ASN1_ITEM *it)

{
  undefined4 *puVar1;
  void *pvVar2;
  
  if ((((pval != (ASN1_VALUE **)0x0) && (*pval != (ASN1_VALUE *)0x0)) &&
      (pvVar2 = it->funcs, pvVar2 != (void *)0x0)) &&
     (((*(uint *)((int)pvVar2 + 4) & 2) != 0 &&
      (puVar1 = (undefined4 *)(*pval + *(int *)((int)pvVar2 + 0x14)), puVar1 != (undefined4 *)0x0)))
     ) {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 1;
  }
  return;
}

