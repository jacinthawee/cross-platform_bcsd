
int ASN1_primitive_new(ASN1_VALUE **pval,ASN1_ITEM *it)

{
  int iVar1;
  ASN1_VALUE *pAVar2;
  ASN1_STRING *pAVar3;
  undefined4 in_a3;
  code *UNRECOVERED_JUMPTABLE;
  
  if (it == (ASN1_ITEM *)0x0) {
LAB_0055df88:
    iVar1 = -1;
  }
  else {
    if ((it->funcs != (void *)0x0) &&
       (UNRECOVERED_JUMPTABLE = *(code **)((int)it->funcs + 8), UNRECOVERED_JUMPTABLE != (code *)0x0
       )) {
                    /* WARNING: Could not recover jumptable at 0x0055df20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*UNRECOVERED_JUMPTABLE)();
      return iVar1;
    }
    if (it->itype == '\x05') goto LAB_0055df88;
    iVar1 = it->utype;
    if (iVar1 == 1) {
      *pval = (ASN1_VALUE *)it->size;
      return 1;
    }
    if (iVar1 < 2) {
      if (iVar1 == -4) {
        pAVar3 = (ASN1_STRING *)
                 (*(code *)PTR_CRYPTO_malloc_006a8108)(8,"tasn_new.c",0x165,in_a3,&_gp);
        if (pAVar3 == (ASN1_STRING *)0x0) {
          return 0;
        }
        pAVar3->type = 0;
        pAVar3->length = -1;
        *pval = (ASN1_VALUE *)pAVar3;
        goto LAB_0055dfb4;
      }
    }
    else {
      if (iVar1 == 5) {
        *pval = (ASN1_VALUE *)0x1;
        return 1;
      }
      if (iVar1 == 6) {
        pAVar2 = (ASN1_VALUE *)(*(code *)PTR_OBJ_nid2obj_006a8240)(0);
        *pval = pAVar2;
        return 1;
      }
    }
  }
  pAVar3 = ASN1_STRING_type_new(iVar1);
  if ((it->itype == '\x05') && (pAVar3 != (ASN1_STRING *)0x0)) {
    pAVar3->flags = pAVar3->flags | 0x40;
    *pval = (ASN1_VALUE *)pAVar3;
  }
  else {
    *pval = (ASN1_VALUE *)pAVar3;
  }
LAB_0055dfb4:
  return (uint)(pAVar3 != (ASN1_STRING *)0x0);
}

