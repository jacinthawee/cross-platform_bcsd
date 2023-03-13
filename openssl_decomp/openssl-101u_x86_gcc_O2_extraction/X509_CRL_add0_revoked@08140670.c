
int X509_CRL_add0_revoked(X509_CRL *crl,X509_REVOKED *rev)

{
  X509_CRL_INFO *pXVar1;
  int iVar2;
  _STACK *st;
  
  pXVar1 = crl->crl;
  st = (_STACK *)pXVar1->revoked;
  if (st == (_STACK *)0x0) {
    st = sk_new(X509_REVOKED_cmp);
    pXVar1->revoked = (stack_st_X509_REVOKED *)st;
    if (st == (_STACK *)0x0) goto LAB_081406c7;
  }
  iVar2 = sk_push(st,rev);
  if (iVar2 != 0) {
    (pXVar1->enc).modified = 1;
    return 1;
  }
LAB_081406c7:
  ERR_put_error(0xd,0xa9,0x41,"x_crl.c",0x16c);
  return 0;
}

