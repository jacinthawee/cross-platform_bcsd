
int X509V3_add1_i2d(stack_st_X509_EXTENSION **x,int nid,void *value,int crit,ulong flags)

{
  int iVar1;
  X509_EXTENSION *pXVar2;
  X509_EXTENSION *a;
  void *pvVar3;
  _STACK *st;
  uint uVar4;
  
  uVar4 = flags & 0xf;
  if (uVar4 == 1) {
LAB_000d1048:
    pXVar2 = X509V3_EXT_i2d(nid,crit,value);
    if (pXVar2 == (X509_EXTENSION *)0x0) {
LAB_000d1078:
      ERR_put_error(0x22,0x8c,0x90,"v3_lib.c",0x11e);
      return 0;
    }
    st = (_STACK *)*x;
    if (st != (_STACK *)0x0) {
LAB_000d105a:
      pvVar3 = (void *)sk_push(st,pXVar2);
      goto joined_r0x000d1060;
    }
    st = sk_new_null();
    *x = (stack_st_X509_EXTENSION *)st;
    if (st != (_STACK *)0x0) goto LAB_000d105a;
LAB_000d1072:
    iVar1 = -1;
  }
  else {
    iVar1 = X509v3_get_ext_by_NID(*x,nid,-1);
    if (iVar1 < 0) {
      if ((uVar4 == 5) || (uVar4 == 3)) {
        iVar1 = 0x66;
LAB_000d0fdc:
        if ((flags & 0x10) != 0) {
          return 0;
        }
        ERR_put_error(0x22,0x8c,iVar1,"v3_lib.c",0x131);
        return 0;
      }
      goto LAB_000d1048;
    }
    if (uVar4 != 4) {
      if (uVar4 == 0) {
        iVar1 = 0x91;
        goto LAB_000d0fdc;
      }
      if (uVar4 != 5) {
        pXVar2 = X509V3_EXT_i2d(nid,crit,value);
        if (pXVar2 == (X509_EXTENSION *)0x0) goto LAB_000d1078;
        a = (X509_EXTENSION *)sk_value((_STACK *)*x,iVar1);
        X509_EXTENSION_free(a);
        pvVar3 = sk_set((_STACK *)*x,iVar1,pXVar2);
        if (pvVar3 != (void *)0x0) goto LAB_000d100e;
        goto LAB_000d1072;
      }
      pvVar3 = sk_delete((_STACK *)*x,iVar1);
joined_r0x000d1060:
      if (pvVar3 == (void *)0x0) goto LAB_000d1072;
    }
LAB_000d100e:
    iVar1 = 1;
  }
  return iVar1;
}
