
int PKCS12_add_safe(stack_st_PKCS7 **psafes,stack_st_PKCS12_SAFEBAG *bags,int safe_nid,int iter,
                   char *pass)

{
  bool bVar1;
  PKCS7 *a;
  int iVar2;
  stack_st_PKCS7 *psVar3;
  
  bVar1 = false;
  if (*psafes == (stack_st_PKCS7 *)0x0) {
    bVar1 = true;
    psVar3 = (stack_st_PKCS7 *)(*(code *)PTR_sk_new_null_006a6fa4)();
    *psafes = psVar3;
    if (psVar3 == (stack_st_PKCS7 *)0x0) {
      return 0;
    }
    if (safe_nid == 0) goto LAB_005a8118;
LAB_005a8194:
    if (safe_nid == -1) {
      a = PKCS12_pack_p7data(bags);
      goto joined_r0x005a81a8;
    }
  }
  else {
    if (safe_nid != 0) goto LAB_005a8194;
LAB_005a8118:
    safe_nid = 0x95;
  }
  a = PKCS12_pack_p7encdata(safe_nid,pass,-1,(uchar *)0x0,0,iter,bags);
joined_r0x005a81a8:
  if (a == (PKCS7 *)0x0) {
    if (bVar1) {
      (*(code *)PTR_sk_free_006a6e80)(*psafes);
      *psafes = (stack_st_PKCS7 *)0x0;
    }
    return 0;
  }
  iVar2 = (*(code *)PTR_sk_push_006a6fa8)(*psafes,a);
  if (iVar2 != 0) {
    return 1;
  }
  if (bVar1) {
    (*(code *)PTR_sk_free_006a6e80)(*psafes);
    *psafes = (stack_st_PKCS7 *)0x0;
  }
  PKCS7_free(a);
  return 0;
}

