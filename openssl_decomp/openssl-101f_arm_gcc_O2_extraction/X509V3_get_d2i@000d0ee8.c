
void * X509V3_get_d2i(stack_st_X509_EXTENSION *x,int nid,int *crit,int *idx)

{
  int iVar1;
  X509_EXTENSION *ex;
  void *pvVar2;
  X509_EXTENSION *pXVar3;
  int iVar4;
  int *piVar5;
  bool bVar6;
  
  if (x != (stack_st_X509_EXTENSION *)0x0) {
    if (idx == (int *)0x0) {
      ex = (X509_EXTENSION *)0x0;
      while( true ) {
        iVar4 = sk_num(&x->stack);
        piVar5 = (int *)((int)idx + 1);
        if (iVar4 <= (int)idx) break;
        pXVar3 = (X509_EXTENSION *)sk_value(&x->stack,(int)idx);
        iVar4 = OBJ_obj2nid(pXVar3->object);
        idx = piVar5;
        if ((iVar4 == nid) && (bVar6 = ex != (X509_EXTENSION *)0x0, ex = pXVar3, bVar6)) {
          if (crit == (int *)0x0) {
            return (void *)0x0;
          }
          *crit = -2;
          return (void *)0x0;
        }
      }
      if (ex != (X509_EXTENSION *)0x0) {
LAB_000d0f26:
        if (crit != (int *)0x0) {
          iVar4 = X509_EXTENSION_get_critical(ex);
          *crit = iVar4;
        }
        pvVar2 = X509V3_EXT_d2i(ex);
        return pvVar2;
      }
      goto LAB_000d0f48;
    }
    iVar4 = *idx + 1;
    if (iVar4 < 0) {
      iVar4 = 0;
    }
    for (; iVar1 = sk_num(&x->stack), iVar4 < iVar1; iVar4 = iVar4 + 1) {
      ex = (X509_EXTENSION *)sk_value(&x->stack,iVar4);
      iVar1 = OBJ_obj2nid(ex->object);
      if (iVar1 == nid) {
        *idx = iVar4;
        goto LAB_000d0f26;
      }
    }
  }
  if (idx != (int *)0x0) {
    *idx = -1;
  }
LAB_000d0f48:
  if (crit != (int *)0x0) {
    *crit = -1;
  }
  return (void *)0x0;
}

