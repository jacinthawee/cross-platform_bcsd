
stack_st_OPENSSL_STRING * X509_get1_ocsp(X509 *x)

{
  char **ppcVar1;
  _STACK *a;
  int iVar2;
  ASN1_OBJECT **ppAVar3;
  char *pcVar4;
  int iVar5;
  _STACK *st;
  
  a = (_STACK *)X509_get_ext_d2i(x,0xb1,(int *)0x0,(int *)0x0);
  if (a == (_STACK *)0x0) {
    st = (_STACK *)0x0;
  }
  else {
    st = (_STACK *)0x0;
    iVar5 = 0;
    while( true ) {
      iVar2 = sk_num(a);
      if (iVar2 <= iVar5) break;
      ppAVar3 = (ASN1_OBJECT **)sk_value(a,iVar5);
      iVar2 = OBJ_obj2nid(*ppAVar3);
      if ((((iVar2 == 0xb2) && (ppAVar3[1]->sn == (char *)0x6)) &&
          (ppcVar1 = ppAVar3[1]->ln, ppcVar1[1] == (char *)0x16)) &&
         ((pcVar4 = ppcVar1[2], pcVar4 != (char *)0x0 && (*ppcVar1 != (char *)0x0)))) {
        if (st == (_STACK *)0x0) {
          st = sk_new(sk_strcmp);
          if (st != (_STACK *)0x0) {
            pcVar4 = ppcVar1[2];
            goto LAB_0816b2e7;
          }
        }
        else {
LAB_0816b2e7:
          iVar2 = sk_find(st,pcVar4);
          if (iVar2 != -1) goto LAB_0816b290;
          pcVar4 = BUF_strdup(ppcVar1[2]);
          if (pcVar4 != (char *)0x0) {
            iVar2 = sk_push(st,pcVar4);
            if (iVar2 != 0) goto LAB_0816b290;
          }
          sk_pop_free(st,str_free);
        }
        st = (_STACK *)0x0;
        break;
      }
LAB_0816b290:
      iVar5 = iVar5 + 1;
    }
    AUTHORITY_INFO_ACCESS_free((AUTHORITY_INFO_ACCESS *)a);
  }
  return (stack_st_OPENSSL_STRING *)st;
}

