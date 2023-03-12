
stack_st_OPENSSL_STRING * X509_get1_ocsp(X509 *x)

{
  _STACK *a;
  int iVar1;
  ASN1_OBJECT **ppAVar2;
  char *pcVar3;
  int iVar4;
  char **ppcVar5;
  _STACK *st;
  _STACK *p_Var6;
  
  a = (_STACK *)X509_get_ext_d2i(x,0xb1,(int *)0x0,(int *)0x0);
  if (a == (_STACK *)0x0) {
    return (stack_st_OPENSSL_STRING *)0x0;
  }
  iVar4 = 0;
  p_Var6 = (_STACK *)0x0;
  do {
    iVar1 = sk_num(a);
    if (iVar1 <= iVar4) {
LAB_000d04a8:
      AUTHORITY_INFO_ACCESS_free((AUTHORITY_INFO_ACCESS *)a);
      return (stack_st_OPENSSL_STRING *)p_Var6;
    }
    ppAVar2 = (ASN1_OBJECT **)sk_value(a,iVar4);
    iVar1 = OBJ_obj2nid(*ppAVar2);
    st = p_Var6;
    if ((((iVar1 == 0xb2) && (ppAVar2[1]->sn == (char *)0x6)) &&
        (ppcVar5 = ppAVar2[1]->ln, ppcVar5[1] == (char *)0x16)) &&
       ((pcVar3 = ppcVar5[2], pcVar3 != (char *)0x0 && (*ppcVar5 != (char *)0x0)))) {
      if (p_Var6 == (_STACK *)0x0) {
        p_Var6 = sk_new(sk_strcmp + 1);
        if (p_Var6 == (_STACK *)0x0) goto LAB_000d04a8;
        pcVar3 = ppcVar5[2];
        st = p_Var6;
      }
      iVar1 = sk_find(st,pcVar3);
      if ((iVar1 == -1) &&
         ((pcVar3 = BUF_strdup(ppcVar5[2]), pcVar3 == (char *)0x0 ||
          (iVar1 = sk_push(st,pcVar3), iVar1 == 0)))) {
        p_Var6 = (_STACK *)0x0;
        sk_pop_free(st,str_free + 1);
        goto LAB_000d04a8;
      }
    }
    iVar4 = iVar4 + 1;
    p_Var6 = st;
  } while( true );
}

