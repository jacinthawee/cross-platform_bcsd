
int X509_CRL_sort(X509_CRL *crl)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  
  sk_sort((_STACK *)crl->crl->revoked);
  for (iVar3 = 0; iVar2 = sk_num((_STACK *)crl->crl->revoked), iVar3 < iVar2; iVar3 = iVar3 + 1) {
    pvVar1 = sk_value((_STACK *)crl->crl->revoked,iVar3);
    *(int *)((int)pvVar1 + 0x14) = iVar3;
  }
  (crl->crl->enc).modified = 1;
  return 1;
}

