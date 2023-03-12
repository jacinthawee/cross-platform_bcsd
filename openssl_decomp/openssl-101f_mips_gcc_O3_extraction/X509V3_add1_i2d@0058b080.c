
int X509V3_add1_i2d(stack_st_X509_EXTENSION **x,int nid,void *value,int crit,ulong flags)

{
  int iVar1;
  X509_EXTENSION *pXVar2;
  stack_st_X509_EXTENSION *psVar3;
  undefined4 uVar4;
  uint uVar5;
  
  uVar5 = flags & 0xf;
  if (uVar5 != 1) {
    iVar1 = X509v3_get_ext_by_NID(*x,nid,-1);
    if (-1 < iVar1) {
      if (uVar5 == 4) {
        return 1;
      }
      if (uVar5 == 0) {
        uVar4 = 0x91;
        goto LAB_0058b104;
      }
      if (uVar5 != 5) {
        pXVar2 = X509V3_EXT_i2d(nid,crit,value);
        if (pXVar2 != (X509_EXTENSION *)0x0) {
          uVar4 = (*(code *)PTR_sk_value_006a7f24)(*x,iVar1);
          (*(code *)PTR_X509_EXTENSION_free_006a8268)(uVar4);
          iVar1 = (*(code *)PTR_sk_set_006a9478)(*x,iVar1,pXVar2);
          if (iVar1 == 0) {
            return -1;
          }
          return 1;
        }
        goto LAB_0058b238;
      }
      iVar1 = (*(code *)PTR_sk_delete_006a8398)(*x,iVar1);
      goto joined_r0x0058b228;
    }
    if (uVar5 == 3) {
      uVar4 = 0x66;
LAB_0058b104:
      if ((flags & 0x10) != 0) {
        return 0;
      }
      (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x8c,uVar4,"v3_lib.c",0x131);
      return 0;
    }
    uVar4 = 0x66;
    if (uVar5 == 5) goto LAB_0058b104;
  }
  pXVar2 = X509V3_EXT_i2d(nid,crit,value);
  if (pXVar2 == (X509_EXTENSION *)0x0) {
LAB_0058b238:
    (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x8c,0x90,"v3_lib.c",0x11e);
    return 0;
  }
  psVar3 = *x;
  if (psVar3 == (stack_st_X509_EXTENSION *)0x0) {
    psVar3 = (stack_st_X509_EXTENSION *)(*(code *)PTR_sk_new_null_006a80a4)();
    *x = psVar3;
    if (psVar3 == (stack_st_X509_EXTENSION *)0x0) {
      return -1;
    }
  }
  iVar1 = (*(code *)PTR_sk_push_006a80a8)(psVar3,pXVar2);
joined_r0x0058b228:
  if (iVar1 != 0) {
    return 1;
  }
  return -1;
}

