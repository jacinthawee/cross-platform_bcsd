
X509_EXTENSION * OCSP_archive_cutoff_new(char *tim)

{
  int iVar1;
  int iVar2;
  X509_EXTENSION *pXVar3;
  
  iVar1 = (*(code *)PTR_ASN1_GENERALIZEDTIME_new_006a813c)();
  if (iVar1 == 0) {
    pXVar3 = (X509_EXTENSION *)0x0;
  }
  else {
    iVar2 = (*(code *)PTR_ASN1_GENERALIZEDTIME_set_string_006a80fc)(iVar1,tim);
    if (iVar2 == 0) {
      pXVar3 = (X509_EXTENSION *)0x0;
    }
    else {
      pXVar3 = (X509_EXTENSION *)(*(code *)PTR_X509V3_EXT_i2d_006aa130)(0x172,0,iVar1);
    }
    (*(code *)PTR_ASN1_GENERALIZEDTIME_free_006a8138)(iVar1);
  }
  return pXVar3;
}

