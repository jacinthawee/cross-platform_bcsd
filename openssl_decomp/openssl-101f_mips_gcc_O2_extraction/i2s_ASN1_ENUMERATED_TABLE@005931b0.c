
char * i2s_ASN1_ENUMERATED_TABLE(X509V3_EXT_METHOD *meth,ASN1_ENUMERATED *aint)

{
  int iVar1;
  char *pcVar2;
  int *piVar3;
  int iVar4;
  
  iVar1 = (*(code *)PTR_ASN1_ENUMERATED_get_006a9e4c)(aint);
  piVar3 = (int *)meth->usr_data;
  if (piVar3[1] != 0) {
    iVar4 = *piVar3;
    while( true ) {
      if (iVar1 == iVar4) {
                    /* WARNING: Could not recover jumptable at 0x0059324c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        pcVar2 = (char *)(*(code *)PTR_BUF_strdup_006a80dc)();
        return pcVar2;
      }
      if (piVar3[4] == 0) break;
      iVar4 = piVar3[3];
      piVar3 = piVar3 + 3;
    }
  }
  pcVar2 = i2s_ASN1_ENUMERATED(meth,aint);
  return pcVar2;
}

