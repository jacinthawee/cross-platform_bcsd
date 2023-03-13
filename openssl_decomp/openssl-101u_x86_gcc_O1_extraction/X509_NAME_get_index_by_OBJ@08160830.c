
int X509_NAME_get_index_by_OBJ(X509_NAME *name,ASN1_OBJECT *obj,int lastpos)

{
  _STACK *p_Var1;
  int iVar2;
  ASN1_OBJECT **ppAVar3;
  int iVar4;
  int iVar5;
  
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
        iVar4 = OBJ_cmp(*ppAVar3,obj);
        if (iVar4 == 0) {
          return iVar5;
        }
        iVar5 = iVar5 + 1;
      } while (iVar2 != iVar5);
    }
  }
  return -1;
}

