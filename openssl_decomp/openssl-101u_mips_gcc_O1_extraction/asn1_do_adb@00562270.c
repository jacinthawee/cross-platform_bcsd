
ASN1_TEMPLATE * asn1_do_adb(ASN1_VALUE **pval,ASN1_TEMPLATE *tt,int nullerr)

{
  int iVar1;
  ASN1_TEMPLATE *pAVar2;
  ASN1_INTEGER **ppAVar3;
  void *pvVar4;
  int *piVar5;
  ASN1_ITEM_EXP *pAVar6;
  
  if ((tt->flags & 0x300) == 0) {
    return tt;
  }
  pAVar6 = tt->item;
  ppAVar3 = (ASN1_INTEGER **)(*pval + pAVar6->utype);
  if (ppAVar3 == (ASN1_INTEGER **)0x0) {
    pAVar2 = (ASN1_TEMPLATE *)pAVar6->sname;
  }
  else {
    if ((tt->flags & 0x100) == 0) {
      iVar1 = ASN1_INTEGER_get(*ppAVar3);
    }
    else {
      iVar1 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*ppAVar3);
    }
    piVar5 = (int *)pAVar6->tcount;
    if (0 < (int)pAVar6->funcs) {
      if (iVar1 == *piVar5) {
LAB_00562344:
        return (ASN1_TEMPLATE *)(piVar5 + 1);
      }
      for (pvVar4 = (void *)0x1; piVar5 = piVar5 + 6, pvVar4 != pAVar6->funcs;
          pvVar4 = (void *)((int)pvVar4 + 1)) {
        if (iVar1 == *piVar5) goto LAB_00562344;
      }
    }
    pAVar2 = (ASN1_TEMPLATE *)pAVar6->size;
  }
  if (pAVar2 == (ASN1_TEMPLATE *)0x0) {
    if (nullerr == 0) {
      pAVar2 = (ASN1_TEMPLATE *)0x0;
    }
    else {
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x6e,0xa4,"tasn_utl.c",0x111);
      pAVar2 = (ASN1_TEMPLATE *)0x0;
    }
  }
  return pAVar2;
}

