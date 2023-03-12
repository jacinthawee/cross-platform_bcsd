
int X509_CRL_sort(X509_CRL *crl)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  sk_sort((_STACK *)crl->crl->revoked);
  while( true ) {
    iVar2 = sk_num((_STACK *)crl->crl->revoked);
    if (iVar2 <= iVar3) break;
    pvVar1 = sk_value((_STACK *)crl->crl->revoked,iVar3);
    *(int *)((int)pvVar1 + 0x14) = iVar3;
    iVar3 = iVar3 + 1;
  }
  (crl->crl->enc).modified = 1;
  return 1;
}

