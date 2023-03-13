
int ASN1_primitive_new(ASN1_VALUE **pval,ASN1_ITEM *it)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  ASN1_OBJECT *pAVar2;
  undefined4 *puVar3;
  ASN1_STRING *pAVar4;
  
  if (it == (ASN1_ITEM *)0x0) {
    return 0;
  }
  if ((it->funcs != (void *)0x0) &&
     (UNRECOVERED_JUMPTABLE = *(code **)((int)it->funcs + 8), UNRECOVERED_JUMPTABLE != (code *)0x0))
  {
                    /* WARNING: Could not recover jumptable at 0x08144900. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*UNRECOVERED_JUMPTABLE)();
    return iVar1;
  }
  if (it->itype == '\x05') {
    iVar1 = -1;
  }
  else {
    iVar1 = it->utype;
    if (iVar1 == 1) {
      *pval = (ASN1_VALUE *)it->size;
      return 1;
    }
    if (iVar1 < 2) {
      if (iVar1 == -4) {
        puVar3 = (undefined4 *)CRYPTO_malloc(8,"tasn_new.c",0x156);
        if (puVar3 != (undefined4 *)0x0) {
          puVar3[1] = 0;
          *puVar3 = 0xffffffff;
          *pval = (ASN1_VALUE *)puVar3;
          return 1;
        }
        return 0;
      }
    }
    else {
      if (iVar1 == 5) {
        *pval = (ASN1_VALUE *)0x1;
        return 1;
      }
      if (iVar1 == 6) {
        pAVar2 = OBJ_nid2obj(0);
        *pval = (ASN1_VALUE *)pAVar2;
        return 1;
      }
    }
  }
  pAVar4 = ASN1_STRING_type_new(iVar1);
  if ((it->itype == '\x05') && (pAVar4 != (ASN1_STRING *)0x0)) {
    pAVar4->flags = pAVar4->flags | 0x40;
  }
  *pval = (ASN1_VALUE *)pAVar4;
  return (uint)(pAVar4 != (ASN1_STRING *)0x0);
}

