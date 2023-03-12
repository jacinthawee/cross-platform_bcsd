
int x509_object_cmp(int **param_1,int **param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  piVar3 = *param_1;
  piVar4 = *param_2;
  iVar2 = *piVar3;
  iVar1 = iVar2 - *piVar4;
  if (iVar1 == 0) {
    if (iVar2 == 1) {
      iVar1 = X509_subject_name_cmp((X509 *)piVar3[1],(X509 *)piVar4[1]);
      return iVar1;
    }
    if (iVar2 == 2) {
      iVar1 = X509_CRL_cmp((X509_CRL *)piVar3[1],(X509_CRL *)piVar4[1]);
      return iVar1;
    }
    iVar1 = 0;
  }
  return iVar1;
}

