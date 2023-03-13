
void asn1_enc_init(ASN1_VALUE **pval,ASN1_ITEM *it)

{
  void *pvVar1;
  undefined4 *puVar2;
  
  if ((((pval != (ASN1_VALUE **)0x0) && (*pval != (ASN1_VALUE *)0x0)) &&
      (pvVar1 = it->funcs, pvVar1 != (void *)0x0)) &&
     (((*(byte *)((int)pvVar1 + 4) & 2) != 0 &&
      (puVar2 = (undefined4 *)(*pval + *(int *)((int)pvVar1 + 0x14)), puVar2 != (undefined4 *)0x0)))
     ) {
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 1;
  }
  return;
}

