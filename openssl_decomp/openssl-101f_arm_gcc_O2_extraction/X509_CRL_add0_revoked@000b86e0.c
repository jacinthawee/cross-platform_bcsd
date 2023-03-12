
int X509_CRL_add0_revoked(X509_CRL *crl,X509_REVOKED *rev)

{
  _STACK *st;
  int iVar1;
  X509_CRL_INFO *pXVar2;
  
  pXVar2 = crl->crl;
  st = (_STACK *)pXVar2->revoked;
  if (st == (_STACK *)0x0) {
    st = sk_new(X509_REVOKED_cmp + 1);
    pXVar2->revoked = (stack_st_X509_REVOKED *)st;
    if (st == (_STACK *)0x0) goto LAB_000b870e;
  }
  iVar1 = sk_push(st,rev);
  if (iVar1 != 0) {
    (pXVar2->enc).modified = 1;
    return 1;
  }
LAB_000b870e:
  ERR_put_error(0xd,0xa9,0x41,"x_crl.c",0x17a);
  return 0;
}

