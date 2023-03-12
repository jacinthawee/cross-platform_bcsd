
ASN1_TEMPLATE * asn1_do_adb(ASN1_VALUE **pval,ASN1_TEMPLATE *tt,int nullerr)

{
  ASN1_OBJECT *o;
  int iVar1;
  ASN1_TEMPLATE *pAVar2;
  int *piVar3;
  void *pvVar4;
  ASN1_ITEM_EXP *pAVar5;
  
  if ((tt->flags & 0x300) == 0) {
    return tt;
  }
  pAVar5 = tt->item;
  if (*pval + pAVar5->utype == (ASN1_VALUE *)0x0) {
    pAVar2 = (ASN1_TEMPLATE *)pAVar5->sname;
  }
  else {
    o = *(ASN1_OBJECT **)(*pval + pAVar5->utype);
    if ((int)(tt->flags << 0x17) < 0) {
      iVar1 = OBJ_obj2nid(o);
    }
    else {
      iVar1 = ASN1_INTEGER_get((ASN1_INTEGER *)o);
    }
    piVar3 = (int *)pAVar5->tcount;
    if (0 < (int)pAVar5->funcs) {
      if (*piVar3 != iVar1) {
        pvVar4 = (void *)0x0;
        do {
          pvVar4 = (void *)((int)pvVar4 + 1);
          piVar3 = piVar3 + 6;
          if (pvVar4 == pAVar5->funcs) goto LAB_000bf43c;
        } while (*piVar3 != iVar1);
      }
      return (ASN1_TEMPLATE *)(piVar3 + 1);
    }
LAB_000bf43c:
    pAVar2 = (ASN1_TEMPLATE *)pAVar5->size;
  }
  if ((pAVar2 == (ASN1_TEMPLATE *)0x0) && (pAVar2 = (ASN1_TEMPLATE *)nullerr, nullerr != 0)) {
    ERR_put_error(0xd,0x6e,0xa4,"tasn_utl.c",0x115);
    pAVar2 = (ASN1_TEMPLATE *)0x0;
  }
  return pAVar2;
}

