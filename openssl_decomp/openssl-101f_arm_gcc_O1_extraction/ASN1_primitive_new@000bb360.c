
int ASN1_primitive_new(ASN1_VALUE **pval,ASN1_ITEM *it)

{
  int iVar1;
  ASN1_STRING *pAVar2;
  ASN1_OBJECT *pAVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  if (it == (ASN1_ITEM *)0x0) {
LAB_000bb394:
    iVar1 = -1;
  }
  else {
    if ((it->funcs != (void *)0x0) &&
       (UNRECOVERED_JUMPTABLE = *(code **)((int)it->funcs + 8), UNRECOVERED_JUMPTABLE != (code *)0x0
       )) {
                    /* WARNING: Could not recover jumptable at 0x000bb374. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*UNRECOVERED_JUMPTABLE)();
      return iVar1;
    }
    if (it->itype == '\x05') goto LAB_000bb394;
    iVar1 = it->utype;
    switch(iVar1) {
    case 1:
      *pval = (ASN1_VALUE *)it->size;
      return 1;
    case 5:
      *pval = (ASN1_VALUE *)0x1;
      return 1;
    case 6:
      pAVar3 = OBJ_nid2obj(0);
      *pval = (ASN1_VALUE *)pAVar3;
      return 1;
    case -4:
      pAVar2 = (ASN1_STRING *)CRYPTO_malloc(8,"tasn_new.c",0x165);
      if (pAVar2 == (ASN1_STRING *)0x0) {
        return 0;
      }
      pAVar2->type = 0;
      pAVar2->length = -1;
      *pval = (ASN1_VALUE *)pAVar2;
      goto LAB_000bb3ea;
    }
  }
  pAVar2 = ASN1_STRING_type_new(iVar1);
  if ((it->itype == '\x05') && (pAVar2 != (ASN1_STRING *)0x0)) {
    pAVar2->flags = pAVar2->flags | 0x40;
  }
  *pval = (ASN1_VALUE *)pAVar2;
LAB_000bb3ea:
  if (pAVar2 != (ASN1_STRING *)0x0) {
    pAVar2 = (ASN1_STRING *)0x1;
  }
  return (int)pAVar2;
}

