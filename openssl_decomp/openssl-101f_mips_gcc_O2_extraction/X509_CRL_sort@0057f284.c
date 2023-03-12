
int X509_CRL_sort(X509_CRL *crl)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  (*(code *)PTR_sk_sort_006a94d8)(crl->crl->revoked);
  while( true ) {
    iVar1 = (*(code *)PTR_sk_num_006a7f2c)(crl->crl->revoked);
    if (iVar1 <= iVar2) break;
    iVar1 = (*(code *)PTR_sk_value_006a7f24)(crl->crl->revoked,iVar2);
    *(int *)(iVar1 + 0x14) = iVar2;
    iVar2 = iVar2 + 1;
  }
  (crl->crl->enc).modified = 1;
  return 1;
}

