
int X509_NAME_get_index_by_NID(X509_NAME *name,int nid,int lastpos)

{
  _STACK *p_Var1;
  ASN1_OBJECT *b;
  int iVar2;
  ASN1_OBJECT **ppAVar3;
  int iVar4;
  int iVar5;
  
  b = OBJ_nid2obj(nid);
  if (b == (ASN1_OBJECT *)0x0) {
    iVar5 = -2;
  }
  else {
    if (name != (X509_NAME *)0x0) {
      iVar5 = lastpos + 1;
      p_Var1 = (_STACK *)name->entries;
      if (lastpos < 0) {
        iVar5 = 0;
      }
      iVar2 = sk_num(p_Var1);
      if (iVar5 < iVar2) {
        do {
          ppAVar3 = (ASN1_OBJECT **)sk_value(p_Var1,iVar5);
          iVar4 = OBJ_cmp(*ppAVar3,b);
          if (iVar4 == 0) {
            return iVar5;
          }
          iVar5 = iVar5 + 1;
        } while (iVar2 != iVar5);
      }
    }
    iVar5 = -1;
  }
  return iVar5;
}

