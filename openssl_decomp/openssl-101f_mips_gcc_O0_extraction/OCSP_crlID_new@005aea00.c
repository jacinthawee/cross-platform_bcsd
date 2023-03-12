
X509_EXTENSION * OCSP_crlID_new(char *url,long *n,char *tim)

{
  OCSP_CRLID *a;
  ASN1_IA5STRING *pAVar1;
  int iVar2;
  ASN1_INTEGER *pAVar3;
  ASN1_GENERALIZEDTIME *pAVar4;
  X509_EXTENSION *pXVar5;
  
  a = OCSP_CRLID_new();
  if (a == (OCSP_CRLID *)0x0) {
    return (X509_EXTENSION *)0x0;
  }
  if (url == (char *)0x0) {
LAB_005aea7c:
    if (n != (long *)0x0) {
      pAVar3 = (ASN1_INTEGER *)(*(code *)PTR_ASN1_INTEGER_new_006a8260)();
      a->crlNum = pAVar3;
      if ((pAVar3 == (ASN1_INTEGER *)0x0) ||
         (iVar2 = (*(code *)PTR_ASN1_INTEGER_set_006a8264)(pAVar3,*n), iVar2 == 0))
      goto LAB_005aeb2c;
    }
    if (tim != (char *)0x0) {
      pAVar4 = (ASN1_GENERALIZEDTIME *)(*(code *)PTR_ASN1_GENERALIZEDTIME_new_006a813c)();
      a->crlTime = pAVar4;
      if ((pAVar4 == (ASN1_GENERALIZEDTIME *)0x0) ||
         (iVar2 = (*(code *)PTR_ASN1_GENERALIZEDTIME_set_string_006a80fc)(pAVar4,tim), iVar2 == 0))
      goto LAB_005aeb2c;
    }
    pXVar5 = (X509_EXTENSION *)(*(code *)PTR_X509V3_EXT_i2d_006aa130)(0x16f,0,a);
  }
  else {
    pAVar1 = (ASN1_IA5STRING *)(*(code *)PTR_ASN1_IA5STRING_new_006aa360)();
    a->crlUrl = pAVar1;
    if ((pAVar1 != (ASN1_IA5STRING *)0x0) &&
       (iVar2 = (*(code *)PTR_ASN1_STRING_set_006a8e0c)(pAVar1,url,0xffffffff), iVar2 != 0))
    goto LAB_005aea7c;
LAB_005aeb2c:
    pXVar5 = (X509_EXTENSION *)0x0;
  }
  OCSP_CRLID_free(a);
  return pXVar5;
}

