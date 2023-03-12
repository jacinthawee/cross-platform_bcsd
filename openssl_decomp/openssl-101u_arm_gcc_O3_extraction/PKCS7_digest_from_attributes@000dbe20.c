
ASN1_OCTET_STRING * PKCS7_digest_from_attributes(stack_st_X509_ATTRIBUTE *sk)

{
  ASN1_OBJECT *b;
  ASN1_OBJECT **ppAVar1;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  
  b = OBJ_nid2obj(0x33);
  uVar4 = (uint)(sk == (stack_st_X509_ATTRIBUTE *)0x0 || b == (ASN1_OBJECT *)0x0);
  if (sk != (stack_st_X509_ATTRIBUTE *)0x0 && b != (ASN1_OBJECT *)0x0) {
    do {
      iVar2 = sk_num(&sk->stack);
      if (iVar2 <= (int)uVar4) {
        return (ASN1_OCTET_STRING *)0x0;
      }
      ppAVar1 = (ASN1_OBJECT **)sk_value(&sk->stack,uVar4);
      iVar2 = OBJ_cmp(*ppAVar1,b);
      uVar4 = uVar4 + 1;
    } while (iVar2 != 0);
    if ((ppAVar1[1] == (ASN1_OBJECT *)0x0) && (iVar2 = sk_num((_STACK *)ppAVar1[2]), iVar2 != 0)) {
      pvVar3 = sk_value((_STACK *)ppAVar1[2],0);
      if (pvVar3 != (void *)0x0) {
        return *(ASN1_OCTET_STRING **)((int)pvVar3 + 4);
      }
      return (ASN1_OCTET_STRING *)0x0;
    }
  }
  return (ASN1_OCTET_STRING *)0x0;
}

