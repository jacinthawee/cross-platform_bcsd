
stack_st_X509_CRL * CMS_get1_crls(CMS_ContentInfo *cms)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  _STACK **pp_Var5;
  _STACK *st;
  
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  if (iVar1 == 0x16) {
    pp_Var5 = (_STACK **)(*(int *)(cms + 4) + 0x10);
  }
  else {
    if (iVar1 != 0x17) {
      ERR_put_error(0x2e,0x84,0x98,"cms_lib.c",0x201);
      return (stack_st_X509_CRL *)0x0;
    }
    pp_Var5 = (_STACK **)(*(int *)(*(int *)(cms + 4) + 4) + 4);
  }
  if (pp_Var5 != (_STACK **)0x0) {
    st = (_STACK *)0x0;
    iVar1 = 0;
    while( true ) {
      do {
        iVar2 = sk_num(*pp_Var5);
        iVar4 = iVar1 + 1;
        if (iVar2 <= iVar1) {
          return (stack_st_X509_CRL *)st;
        }
        piVar3 = (int *)sk_value(*pp_Var5,iVar1);
        iVar1 = iVar4;
      } while (*piVar3 != 0);
      if ((st == (_STACK *)0x0) && (st = sk_new_null(), st == (_STACK *)0x0)) break;
      iVar2 = sk_push(st,(void *)piVar3[1]);
      if (iVar2 == 0) {
        sk_pop_free(st,X509_CRL_free + 1);
        return (stack_st_X509_CRL *)0x0;
      }
      CRYPTO_add_lock((int *)(piVar3[1] + 0xc),1,6,"cms_lib.c",0x26c);
    }
  }
  return (stack_st_X509_CRL *)0x0;
}

