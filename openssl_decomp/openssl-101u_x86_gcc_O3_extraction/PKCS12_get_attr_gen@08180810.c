
ASN1_TYPE * PKCS12_get_attr_gen(stack_st_X509_ATTRIBUTE *attrs,int attr_nid)

{
  ASN1_OBJECT **ppAVar1;
  int iVar2;
  ASN1_TYPE *pAVar3;
  int iVar4;
  
  if (attrs != (stack_st_X509_ATTRIBUTE *)0x0) {
    for (iVar4 = 0; iVar2 = sk_num(&attrs->stack), iVar4 < iVar2; iVar4 = iVar4 + 1) {
      ppAVar1 = (ASN1_OBJECT **)sk_value(&attrs->stack,iVar4);
      iVar2 = OBJ_obj2nid(*ppAVar1);
      if (iVar2 == attr_nid) {
        iVar4 = sk_num((_STACK *)ppAVar1[2]);
        if (iVar4 == 0) {
          return (ASN1_TYPE *)0x0;
        }
        pAVar3 = (ASN1_TYPE *)sk_value((_STACK *)ppAVar1[2],0);
        return pAVar3;
      }
    }
  }
  return (ASN1_TYPE *)0x0;
}

