
ASN1_TEMPLATE * asn1_do_adb(ASN1_VALUE **pval,ASN1_TEMPLATE *tt,int nullerr)

{
  ASN1_ITEM_EXP *pAVar1;
  ASN1_OBJECT **ppAVar2;
  int iVar3;
  void *pvVar4;
  int *piVar5;
  
  if ((tt->flags & 0x300) != 0) {
    pAVar1 = tt->item;
    ppAVar2 = (ASN1_OBJECT **)(*pval + pAVar1->utype);
    if (ppAVar2 == (ASN1_OBJECT **)0x0) {
      tt = (ASN1_TEMPLATE *)pAVar1->sname;
    }
    else {
      if ((tt->flags & 0x100) == 0) {
        iVar3 = ASN1_INTEGER_get((ASN1_INTEGER *)*ppAVar2);
      }
      else {
        iVar3 = OBJ_obj2nid(*ppAVar2);
      }
      piVar5 = (int *)pAVar1->tcount;
      if (0 < (int)pAVar1->funcs) {
        if (iVar3 != *piVar5) {
          pvVar4 = (void *)0x0;
          do {
            pvVar4 = (void *)((int)pvVar4 + 1);
            piVar5 = piVar5 + 6;
            if (pvVar4 == pAVar1->funcs) goto LAB_0814b8d6;
          } while (iVar3 != *piVar5);
        }
        return (ASN1_TEMPLATE *)(piVar5 + 1);
      }
LAB_0814b8d6:
      tt = (ASN1_TEMPLATE *)pAVar1->size;
    }
    if (tt == (ASN1_TEMPLATE *)0x0) {
      if (nullerr == 0) {
        tt = (ASN1_TEMPLATE *)0x0;
      }
      else {
        ERR_put_error(0xd,0x6e,0xa4,"tasn_utl.c",0x111);
        tt = (ASN1_TEMPLATE *)0x0;
      }
    }
  }
  return tt;
}

