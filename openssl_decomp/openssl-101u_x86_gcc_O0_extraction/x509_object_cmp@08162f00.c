
int x509_object_cmp(int **param_1,int **param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  piVar1 = *param_1;
  iVar4 = *piVar1;
  piVar2 = *param_2;
  iVar3 = iVar4 - *piVar2;
  if (iVar3 == 0) {
    if (iVar4 == 1) {
      iVar4 = X509_subject_name_cmp((X509 *)piVar1[1],(X509 *)piVar2[1]);
      return iVar4;
    }
    if (iVar4 == 2) {
      iVar4 = X509_CRL_cmp((X509_CRL *)piVar1[1],(X509_CRL *)piVar2[1]);
      return iVar4;
    }
    iVar3 = 0;
  }
  return iVar3;
}

