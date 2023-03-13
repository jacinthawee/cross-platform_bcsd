
int X509v3_get_ext_by_critical(stack_st_X509_EXTENSION *x,int crit,int lastpos)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  
  if (x != (stack_st_X509_EXTENSION *)0x0) {
    iVar3 = 0;
    if (-1 < lastpos + 1) {
      iVar3 = lastpos + 1;
    }
    iVar1 = sk_num(&x->stack);
    if (iVar3 < iVar1) {
      if (crit == 0) {
        do {
          pvVar2 = sk_value(&x->stack,iVar3);
          if (*(int *)((int)pvVar2 + 4) < 1) {
            return iVar3;
          }
          iVar3 = iVar3 + 1;
        } while (iVar1 != iVar3);
      }
      else {
        do {
          pvVar2 = sk_value(&x->stack,iVar3);
          if (0 < *(int *)((int)pvVar2 + 4)) {
            return iVar3;
          }
          iVar3 = iVar3 + 1;
        } while (iVar1 != iVar3);
      }
    }
  }
  return -1;
}

