
ASN1_TYPE * PKCS7_get_attribute(PKCS7_SIGNER_INFO *si,int nid)

{
  _STACK *p_Var1;
  ASN1_OBJECT *b;
  ASN1_OBJECT **ppAVar2;
  int iVar3;
  ASN1_TYPE *pAVar4;
  int iVar5;
  
  p_Var1 = (_STACK *)si->unauth_attr;
  b = OBJ_nid2obj(nid);
  if ((b != (ASN1_OBJECT *)0x0) && (p_Var1 != (_STACK *)0x0)) {
    for (iVar5 = 0; iVar3 = sk_num(p_Var1), iVar5 < iVar3; iVar5 = iVar5 + 1) {
      ppAVar2 = (ASN1_OBJECT **)sk_value(p_Var1,iVar5);
      iVar3 = OBJ_cmp(*ppAVar2,b);
      if (iVar3 == 0) {
        if (ppAVar2[1] != (ASN1_OBJECT *)0x0) {
          return (ASN1_TYPE *)0x0;
        }
        iVar5 = sk_num((_STACK *)ppAVar2[2]);
        if (iVar5 == 0) {
          return (ASN1_TYPE *)0x0;
        }
        pAVar4 = (ASN1_TYPE *)sk_value((_STACK *)ppAVar2[2],0);
        return pAVar4;
      }
    }
  }
  return (ASN1_TYPE *)0x0;
}

