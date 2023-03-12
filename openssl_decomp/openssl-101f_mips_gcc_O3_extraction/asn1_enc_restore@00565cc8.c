
int asn1_enc_restore(int *len,uchar **out,ASN1_VALUE **pval,ASN1_ITEM *it)

{
  uint uVar1;
  void *pvVar2;
  undefined4 *puVar3;
  
  if (((pval != (ASN1_VALUE **)0x0) && (*pval != (ASN1_VALUE *)0x0)) &&
     (pvVar2 = it->funcs, pvVar2 != (void *)0x0)) {
    uVar1 = *(uint *)((int)pvVar2 + 4) & 2;
    if (uVar1 != 0) {
      puVar3 = (undefined4 *)(*pval + *(int *)((int)pvVar2 + 0x14));
      if ((puVar3 == (undefined4 *)0x0) || (puVar3[2] != 0)) {
        uVar1 = 0;
      }
      else {
        if (out != (uchar **)0x0) {
          (*(code *)PTR_memcpy_006aabf4)(*out,*puVar3,puVar3[1],it,&_gp);
          *out = *out + puVar3[1];
        }
        uVar1 = 1;
        if (len != (int *)0x0) {
          *len = puVar3[1];
        }
      }
    }
    return uVar1;
  }
  return 0;
}

