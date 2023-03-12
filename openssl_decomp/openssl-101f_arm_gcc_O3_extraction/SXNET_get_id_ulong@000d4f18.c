
ASN1_OCTET_STRING * SXNET_get_id_ulong(SXNET *sx,ulong lzone)

{
  ASN1_STRING *a;
  int iVar1;
  ASN1_STRING **ppAVar2;
  int iVar3;
  ASN1_STRING *pAVar4;
  
  a = ASN1_STRING_type_new(2);
  if (a != (ASN1_STRING *)0x0) {
    iVar1 = ASN1_INTEGER_set(a,lzone);
    iVar3 = 0;
    if (iVar1 != 0) {
      do {
        iVar1 = sk_num((_STACK *)sx->ids);
        if (iVar1 <= iVar3) {
          pAVar4 = (ASN1_STRING *)0x0;
          goto LAB_000d4f5a;
        }
        ppAVar2 = (ASN1_STRING **)sk_value((_STACK *)sx->ids,iVar3);
        iVar1 = ASN1_STRING_cmp(*ppAVar2,a);
        iVar3 = iVar3 + 1;
      } while (iVar1 != 0);
      pAVar4 = ppAVar2[1];
LAB_000d4f5a:
      ASN1_STRING_free(a);
      return pAVar4;
    }
  }
  ERR_put_error(0x22,0x81,0x41,"v3_sxnet.c",0xf1);
  ASN1_STRING_free(a);
  return (ASN1_OCTET_STRING *)0x0;
}

