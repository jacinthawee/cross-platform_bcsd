
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
LAB_0816b038:
    pXVar2 = X509V3_EXT_i2d(nid,crit,value);
    if (pXVar2 == (X509_EXTENSION *)0x0) {
LAB_0816b070:
      ERR_put_error(0x22,0x8c,0x90,"v3_lib.c",0x11e);
      return 0;
    }
    st = (_STACK *)*x;
    if (st != (_STACK *)0x0) {
LAB_0816b059:
      pvVar3 = (void *)sk_push(st,pXVar2);
      goto joined_r0x0816b068;
    }
    st = sk_new_null();
    *x = (stack_st_X509_EXTENSION *)st;
    if (st != (_STACK *)0x0) goto LAB_0816b059;
LAB_0816b0ac:
    iVar1 = -1;
  }
  else {
    iVar1 = X509v3_get_ext_by_NID(*x,nid,-1);
    if (iVar1 < 0) {
      iVar1 = 0x66;
      if ((uVar4 - 3 & 0xfffffffd) == 0) {
LAB_0816af68:
        if ((flags & 0x10) != 0) {
          return 0;
        }
        ERR_put_error(0x22,0x8c,iVar1,"v3_lib.c",0x131);
        return 0;
      }
      goto LAB_0816b038;
    }
    if (uVar4 != 4) {
      if (uVar4 == 0) {
        iVar1 = 0x91;
        goto LAB_0816af68;
      }
      if (uVar4 != 5) {
        pXVar2 = X509V3_EXT_i2d(nid,crit,value);
        if (pXVar2 == (X509_EXTENSION *)0x0) goto LAB_0816b070;
        a = (X509_EXTENSION *)sk_value((_STACK *)*x,iVar1);
        X509_EXTENSION_free(a);
        pvVar3 = sk_set((_STACK *)*x,iVar1,pXVar2);
        if (pvVar3 != (void *)0x0) goto LAB_0816afc0;
        goto LAB_0816b0ac;
      }
      pvVar3 = sk_delete((_STACK *)*x,iVar1);
joined_r0x0816b068:
      if (pvVar3 == (void *)0x0) goto LAB_0816b0ac;
    }
LAB_0816afc0:
    iVar1 = 1;
  }
  return iVar1;
}

