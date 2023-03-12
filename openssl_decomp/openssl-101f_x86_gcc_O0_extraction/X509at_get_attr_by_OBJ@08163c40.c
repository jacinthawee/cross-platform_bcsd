
int X509at_get_attr_by_OBJ(stack_st_X509_ATTRIBUTE *sk,ASN1_OBJECT *obj,int lastpos)

{
  int iVar1;
  ASN1_OBJECT **ppAVar2;
  int iVar3;
  int iVar4;
  
  if (sk != (stack_st_X509_ATTRIBUTE *)0x0) {
    iVar4 = 0;
    if (-1 < lastpos + 1) {
      iVar4 = lastpos + 1;
    }
    iVar1 = sk_num(&sk->stack);
    if (iVar4 < iVar1) {
      do {
        ppAVar2 = (ASN1_OBJECT **)sk_value(&sk->stack,iVar4);
        iVar3 = OBJ_cmp(*ppAVar2,obj);
        if (iVar3 == 0) {
          return iVar4;
        }
        iVar4 = iVar4 + 1;
      } while (iVar1 != iVar4);
    }
  }
  return -1;
}

