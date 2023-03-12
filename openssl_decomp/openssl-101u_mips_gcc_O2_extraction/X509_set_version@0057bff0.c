
int X509_set_version(X509 *x,long version)

{
  int iVar1;
  ASN1_STRING *pAVar2;
  X509_CINF *pXVar3;
  
  if (x == (X509 *)0x0) {
    return 0;
  }
  pXVar3 = x->cert_info;
  if (pXVar3->version != (ASN1_INTEGER *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0057c030. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*(code *)PTR_ASN1_INTEGER_set_006a7164)();
    return iVar1;
  }
  pAVar2 = ASN1_STRING_type_new(2);
  pXVar3->version = pAVar2;
  if (pAVar2 != (ASN1_STRING *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0057c070. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*(code *)PTR_ASN1_INTEGER_set_006a7164)(x->cert_info->version,version);
    return iVar1;
  }
  return 0;
}

