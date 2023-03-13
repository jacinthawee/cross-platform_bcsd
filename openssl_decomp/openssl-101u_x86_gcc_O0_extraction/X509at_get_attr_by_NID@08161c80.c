
int X509at_get_attr_by_NID(stack_st_X509_ATTRIBUTE *x,int nid,int lastpos)

{
  ASN1_OBJECT *b;
  int iVar1;
  ASN1_OBJECT **ppAVar2;
  int iVar3;
  int iVar4;
  
  b = OBJ_nid2obj(nid);
  if (b == (ASN1_OBJECT *)0x0) {
    iVar4 = -2;
  }
  else {
    if (x != (stack_st_X509_ATTRIBUTE *)0x0) {
      iVar4 = 0;
      if (-1 < lastpos + 1) {
        iVar4 = lastpos + 1;
      }
      iVar1 = sk_num(&x->stack);
      if (iVar4 < iVar1) {
        do {
          ppAVar2 = (ASN1_OBJECT **)sk_value(&x->stack,iVar4);
          iVar3 = OBJ_cmp(*ppAVar2,b);
          if (iVar3 == 0) {
            return iVar4;
          }
          iVar4 = iVar4 + 1;
        } while (iVar1 != iVar4);
      }
    }
    iVar4 = -1;
  }
  return iVar4;
}

