
ASN1_TYPE * PKCS7_get_signed_attribute(PKCS7_SIGNER_INFO *si,int nid)

{
  ASN1_OBJECT *b;
  ASN1_OBJECT **ppAVar1;
  int iVar2;
  ASN1_TYPE *pAVar3;
  uint uVar4;
  _STACK *p_Var5;
  
  p_Var5 = (_STACK *)si->auth_attr;
  b = OBJ_nid2obj(nid);
  uVar4 = (uint)(p_Var5 == (_STACK *)0x0 || b == (ASN1_OBJECT *)0x0);
  if (p_Var5 != (_STACK *)0x0 && b != (ASN1_OBJECT *)0x0) {
    do {
      iVar2 = sk_num(p_Var5);
      if (iVar2 <= (int)uVar4) {
        return (ASN1_TYPE *)0x0;
      }
      ppAVar1 = (ASN1_OBJECT **)sk_value(p_Var5,uVar4);
      iVar2 = OBJ_cmp(*ppAVar1,b);
      uVar4 = uVar4 + 1;
    } while (iVar2 != 0);
    if ((ppAVar1[1] == (ASN1_OBJECT *)0x0) && (iVar2 = sk_num((_STACK *)ppAVar1[2]), iVar2 != 0)) {
      pAVar3 = (ASN1_TYPE *)sk_value((_STACK *)ppAVar1[2],0);
      return pAVar3;
    }
  }
  return (ASN1_TYPE *)0x0;
}

