
int X509_ALGOR_cmp(X509_ALGOR *a,X509_ALGOR *b)

{
  int iVar1;
  ASN1_TYPE *pAVar2;
  ASN1_TYPE *pAVar3;
  undefined4 in_a2;
  undefined4 in_a3;
  
  iVar1 = (*(code *)PTR_OBJ_cmp_006a8cc4)(a->algorithm,b->algorithm,in_a2,in_a3,&_gp);
  if (iVar1 == 0) {
    pAVar2 = a->parameter;
    pAVar3 = b->parameter;
    if ((pAVar2 != (ASN1_TYPE *)0x0) || (pAVar3 != (ASN1_TYPE *)0x0)) {
      if (((pAVar2 == (ASN1_TYPE *)0x0) || (pAVar3 == (ASN1_TYPE *)0x0)) ||
         (iVar1 = pAVar2->type, iVar1 != pAVar3->type)) {
        return -1;
      }
      if (iVar1 == 5) {
        return 0;
      }
      if (iVar1 == 6) {
                    /* WARNING: Could not recover jumptable at 0x0054bd98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar1 = (*(code *)PTR_OBJ_cmp_006a8cc4)((pAVar2->value).ptr,(pAVar3->value).ptr);
        return iVar1;
      }
      if (iVar1 == 1) {
        return (int)(pAVar2->value).ptr - (pAVar3->value).boolean;
      }
      iVar1 = ASN1_STRING_cmp((pAVar2->value).asn1_string,(pAVar3->value).asn1_string);
      return iVar1;
    }
    iVar1 = 0;
  }
  return iVar1;
}

