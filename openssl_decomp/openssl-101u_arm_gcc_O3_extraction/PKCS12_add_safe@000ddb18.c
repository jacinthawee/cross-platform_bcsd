
int PKCS12_add_safe(stack_st_PKCS7 **psafes,stack_st_PKCS12_SAFEBAG *bags,int safe_nid,int iter,
                   char *pass)

{
  bool bVar1;
  PKCS7 *a;
  int iVar2;
  _STACK *p_Var3;
  
  bVar1 = false;
  if (*psafes == (stack_st_PKCS7 *)0x0) {
    bVar1 = true;
    p_Var3 = sk_new_null();
    *psafes = (stack_st_PKCS7 *)p_Var3;
    if (p_Var3 == (_STACK *)0x0) {
      return 0;
    }
    if (safe_nid != 0) goto LAB_000ddb5c;
LAB_000ddb26:
    safe_nid = 0x95;
  }
  else {
    if (safe_nid == 0) goto LAB_000ddb26;
LAB_000ddb5c:
    if (safe_nid == -1) {
      a = PKCS12_pack_p7data(bags);
      goto LAB_000ddb40;
    }
  }
  a = PKCS12_pack_p7encdata(safe_nid,pass,-1,(uchar *)0x0,0,iter,bags);
LAB_000ddb40:
  if ((a != (PKCS7 *)0x0) && (iVar2 = sk_push((_STACK *)*psafes,a), iVar2 != 0)) {
    return 1;
  }
  if (bVar1) {
    sk_free((_STACK *)*psafes);
    *psafes = (stack_st_PKCS7 *)0x0;
  }
  if (a != (PKCS7 *)0x0) {
    PKCS7_free(a);
  }
  return 0;
}

