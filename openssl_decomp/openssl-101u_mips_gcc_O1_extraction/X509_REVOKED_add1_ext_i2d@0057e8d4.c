
int X509_REVOKED_add1_ext_i2d(X509_REVOKED *x,int nid,void *value,int crit,ulong flags)

{
  int iVar1;
  X509_EXTENSION *pXVar2;
  stack_st_X509_EXTENSION **ppsVar3;
  stack_st_X509_EXTENSION *psVar4;
  undefined4 uVar5;
  uint uVar6;
  
  ppsVar3 = &x->extensions;
  uVar6 = flags & 0xf;
  if (uVar6 != 1) {
    iVar1 = X509v3_get_ext_by_NID(*ppsVar3,nid,-1);
    if (-1 < iVar1) {
      if (uVar6 == 4) {
        return 1;
      }
      if (uVar6 == 0) {
        uVar5 = 0x91;
        goto LAB_00588394;
      }
      if (uVar6 != 5) {
        pXVar2 = X509V3_EXT_i2d(nid,crit,value);
        if (pXVar2 != (X509_EXTENSION *)0x0) {
          uVar5 = (*(code *)PTR_sk_value_006a6e24)(*ppsVar3,iVar1);
          (*(code *)PTR_X509_EXTENSION_free_006a7168)(uVar5);
          iVar1 = (*(code *)PTR_sk_set_006a8358)(*ppsVar3,iVar1,pXVar2);
          if (iVar1 == 0) {
            return -1;
          }
          return 1;
        }
        goto LAB_005884c8;
      }
      iVar1 = (*(code *)PTR_sk_delete_006a7288)(*ppsVar3,iVar1);
      goto joined_r0x005884b8;
    }
    if (uVar6 == 3) {
      uVar5 = 0x66;
LAB_00588394:
      if ((flags & 0x10) != 0) {
        return 0;
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x8c,uVar5,"v3_lib.c",0x151);
      return 0;
    }
    uVar5 = 0x66;
    if (uVar6 == 5) goto LAB_00588394;
  }
  pXVar2 = X509V3_EXT_i2d(nid,crit,value);
  if (pXVar2 == (X509_EXTENSION *)0x0) {
LAB_005884c8:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x8c,0x90,"v3_lib.c",0x13b);
    return 0;
  }
  psVar4 = *ppsVar3;
  if (psVar4 == (stack_st_X509_EXTENSION *)0x0) {
    psVar4 = (stack_st_X509_EXTENSION *)(*(code *)PTR_sk_new_null_006a6fa4)();
    *ppsVar3 = psVar4;
    if (psVar4 == (stack_st_X509_EXTENSION *)0x0) {
      return -1;
    }
  }
  iVar1 = (*(code *)PTR_sk_push_006a6fa8)(psVar4,pXVar2);
joined_r0x005884b8:
  if (iVar1 != 0) {
    return 1;
  }
  return -1;
}

