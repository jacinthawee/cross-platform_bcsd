
stack_st_X509 * CMS_get1_certs(CMS_ContentInfo *cms)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  _STACK *st;
  _STACK **pp_Var4;
  
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  if (iVar1 == 0x16) {
    pp_Var4 = (_STACK **)(*(int *)(cms + 4) + 0xc);
  }
  else {
    if (iVar1 != 0x17) {
      ERR_put_error(0x2e,0x80,0x98,"cms_lib.c",0x1a4);
      return (stack_st_X509 *)0x0;
    }
    pp_Var4 = *(_STACK ***)(*(int *)(cms + 4) + 4);
  }
  if (pp_Var4 != (_STACK **)0x0) {
    iVar1 = 0;
    st = (_STACK *)0x0;
    do {
      iVar2 = sk_num(*pp_Var4);
      if (iVar2 <= iVar1) {
        return (stack_st_X509 *)st;
      }
      piVar3 = (int *)sk_value(*pp_Var4,iVar1);
      if (*piVar3 == 0) {
        if ((st == (_STACK *)0x0) && (st = sk_new_null(), st == (_STACK *)0x0)) {
          return (stack_st_X509 *)0x0;
        }
        iVar2 = sk_push(st,(void *)piVar3[1]);
        if (iVar2 == 0) {
          sk_pop_free(st,X509_free);
          return (stack_st_X509 *)0x0;
        }
        CRYPTO_add_lock((int *)(piVar3[1] + 0x10),1,3,"cms_lib.c",0x233);
      }
      iVar1 = iVar1 + 1;
    } while( true );
  }
  return (stack_st_X509 *)0x0;
}

