
stack_st_X509 * CMS_get0_signers(CMS_ContentInfo *cms)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  void *data;
  _STACK *st;
  _STACK *p_Var4;
  
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  if (iVar1 == 0x16) {
    if (*(int *)(cms + 4) == 0) {
      p_Var4 = (_STACK *)0x0;
    }
    else {
      p_Var4 = *(_STACK **)(*(int *)(cms + 4) + 0x14);
    }
  }
  else {
    p_Var4 = (_STACK *)0x0;
    ERR_put_error(0x2e,0x85,0x6c,"cms_sd.c",0x47);
  }
  iVar1 = 0;
  st = (_STACK *)0x0;
  do {
    iVar2 = sk_num(p_Var4);
    if (iVar2 <= iVar1) {
      return (stack_st_X509 *)st;
    }
    pvVar3 = sk_value(p_Var4,iVar1);
    data = *(void **)((int)pvVar3 + 0x1c);
    if (data != (void *)0x0) {
      if (st == (_STACK *)0x0) {
        st = sk_new_null();
        if (st == (_STACK *)0x0) {
          return (stack_st_X509 *)0x0;
        }
        data = *(void **)((int)pvVar3 + 0x1c);
      }
      iVar2 = sk_push(st,data);
      if (iVar2 == 0) {
        sk_free(st);
        return (stack_st_X509 *)0x0;
      }
    }
    iVar1 = iVar1 + 1;
  } while( true );
}

