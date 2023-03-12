
int GENERAL_NAME_cmp(GENERAL_NAME *a,GENERAL_NAME *b)

{
  int iVar1;
  ASN1_TYPE *pAVar2;
  ASN1_TYPE *pAVar3;
  OTHERNAME *pOVar4;
  OTHERNAME *pOVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  if (((a != (GENERAL_NAME *)0x0) && (b != (GENERAL_NAME *)0x0)) && (a->type == b->type)) {
    switch(a->type) {
    case 0:
      pOVar4 = (a->d).otherName;
      pOVar5 = (b->d).otherName;
      if ((pOVar4 == (OTHERNAME *)0x0) || (pOVar5 == (OTHERNAME *)0x0)) {
        iVar1 = -1;
      }
      else {
        iVar1 = (*(code *)PTR_OBJ_cmp_006a8cc4)(pOVar4->type_id,pOVar5->type_id);
        if (iVar1 == 0) {
          pAVar3 = pOVar5->value;
          pAVar2 = pOVar4->value;
          UNRECOVERED_JUMPTABLE = (code *)PTR_ASN1_TYPE_cmp_006a8cdc;
          goto LAB_0058c38c;
        }
      }
      return iVar1;
    case 1:
    case 2:
    case 6:
                    /* WARNING: Could not recover jumptable at 0x0058c414. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*(code *)PTR_ASN1_STRING_cmp_006a7148)((a->d).ptr,(b->d).ptr);
      return iVar1;
    case 3:
    case 5:
                    /* WARNING: Could not recover jumptable at 0x0058c434. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*(code *)PTR_ASN1_TYPE_cmp_006a8cdc)((a->d).ptr,(b->d).ptr);
      return iVar1;
    case 4:
      iVar1 = X509_NAME_cmp((a->d).directoryName,(b->d).directoryName);
      return iVar1;
    case 7:
      pAVar3 = (ASN1_TYPE *)(b->d).ptr;
      pAVar2 = (ASN1_TYPE *)(a->d).ptr;
      UNRECOVERED_JUMPTABLE = (code *)PTR_ASN1_OCTET_STRING_cmp_006a8ee0;
LAB_0058c38c:
                    /* WARNING: Could not recover jumptable at 0x0058c398. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*UNRECOVERED_JUMPTABLE)(pAVar2,pAVar3);
      return iVar1;
    case 8:
                    /* WARNING: Could not recover jumptable at 0x0058c3b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*(code *)PTR_OBJ_cmp_006a8cc4)((a->d).ptr,(b->d).ptr);
      return iVar1;
    }
  }
  return -1;
}

