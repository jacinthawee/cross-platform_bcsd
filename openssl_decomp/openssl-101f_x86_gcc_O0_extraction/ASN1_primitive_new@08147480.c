
int ASN1_primitive_new(ASN1_VALUE **pval,ASN1_ITEM *it)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  ASN1_OBJECT *pAVar2;
  ASN1_STRING *pAVar3;
  undefined4 *puVar4;
  bool bVar5;
  
  if (it == (ASN1_ITEM *)0x0) {
LAB_081474f0:
    iVar1 = -1;
  }
  else {
    if ((it->funcs != (void *)0x0) &&
       (UNRECOVERED_JUMPTABLE = *(code **)((int)it->funcs + 8), UNRECOVERED_JUMPTABLE != (code *)0x0
       )) {
                    /* WARNING: Could not recover jumptable at 0x081474a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*UNRECOVERED_JUMPTABLE)();
      return iVar1;
    }
    if (it->itype == '\x05') goto LAB_081474f0;
    iVar1 = it->utype;
    if (iVar1 == 1) {
      *pval = (ASN1_VALUE *)it->size;
      return 1;
    }
    if (iVar1 < 2) {
      if (iVar1 == -4) {
        puVar4 = (undefined4 *)CRYPTO_malloc(8,"tasn_new.c",0x165);
        if (puVar4 == (undefined4 *)0x0) {
          return 0;
        }
        puVar4[1] = 0;
        *puVar4 = 0xffffffff;
        bVar5 = true;
        *pval = (ASN1_VALUE *)puVar4;
        goto LAB_08147554;
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
  pAVar3 = ASN1_STRING_type_new(iVar1);
  bVar5 = pAVar3 != (ASN1_STRING *)0x0;
  if ((it->itype == '\x05') && (bVar5)) {
    pAVar3->flags = pAVar3->flags | 0x40;
  }
  *pval = (ASN1_VALUE *)pAVar3;
LAB_08147554:
  return (uint)bVar5;
}

