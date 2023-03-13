
ASN1_OCTET_STRING * SXNET_get_id_asc(SXNET *sx,char *zone)

{
  ASN1_INTEGER *b;
  ASN1_STRING **ppAVar1;
  int iVar2;
  int iVar3;
  ASN1_STRING *pAVar4;
  
  b = s2i_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,zone);
  if (b == (ASN1_INTEGER *)0x0) {
    pAVar4 = (ASN1_STRING *)0x0;
    ERR_put_error(0x22,0x80,0x83,"v3_sxnet.c",0xed);
  }
  else {
    iVar3 = 0;
    while( true ) {
      iVar2 = sk_num((_STACK *)sx->ids);
      if (iVar2 <= iVar3) break;
      ppAVar1 = (ASN1_STRING **)sk_value((_STACK *)sx->ids,iVar3);
      iVar2 = ASN1_STRING_cmp(*ppAVar1,b);
      if (iVar2 == 0) {
        pAVar4 = ppAVar1[1];
        goto LAB_0816f54f;
      }
      iVar3 = iVar3 + 1;
    }
    pAVar4 = (ASN1_STRING *)0x0;
LAB_0816f54f:
    ASN1_STRING_free(b);
  }
  return pAVar4;
}

