
int X509_check_akid(X509 *issuer,AUTHORITY_KEYID *akid)

{
  int iVar1;
  ASN1_INTEGER *pAVar2;
  int *piVar3;
  int iVar4;
  X509_NAME *b;
  X509_NAME *a;
  GENERAL_NAMES *pGVar5;
  
  if (akid == (AUTHORITY_KEYID *)0x0) {
    return 0;
  }
  if (((akid->keyid != (ASN1_OCTET_STRING *)0x0) && (issuer->skid != (ASN1_OCTET_STRING *)0x0)) &&
     (iVar1 = (*(code *)PTR_ASN1_OCTET_STRING_cmp_006a9ffc)(), iVar1 != 0)) {
    return 0x1e;
  }
  if (akid->serial != (ASN1_INTEGER *)0x0) {
    pAVar2 = X509_get_serialNumber(issuer);
    iVar1 = (*(code *)PTR_ASN1_INTEGER_cmp_006a9e58)(pAVar2,akid->serial);
    if (iVar1 != 0) {
      return 0x1f;
    }
  }
  pGVar5 = akid->issuer;
  iVar1 = 0;
  if (pGVar5 != (GENERAL_NAMES *)0x0) {
    do {
      iVar4 = (*(code *)PTR_sk_num_006a7f2c)(pGVar5);
      if (iVar4 <= iVar1) {
        return 0;
      }
      piVar3 = (int *)(*(code *)PTR_sk_value_006a7f24)(pGVar5,iVar1);
      iVar1 = iVar1 + 1;
    } while (*piVar3 != 4);
    a = (X509_NAME *)piVar3[1];
    if (a != (X509_NAME *)0x0) {
      b = X509_get_issuer_name(issuer);
      iVar1 = X509_NAME_cmp(a,b);
      if (iVar1 != 0) {
        return 0x1f;
      }
    }
  }
  return 0;
}

