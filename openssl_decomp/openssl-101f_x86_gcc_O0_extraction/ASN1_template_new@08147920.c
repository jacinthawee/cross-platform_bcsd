
int ASN1_template_new(ASN1_VALUE **pval,ASN1_TEMPLATE *tt)

{
  uint uVar1;
  ASN1_ITEM_EXP *pAVar2;
  code *pcVar3;
  _STACK *p_Var4;
  int iVar5;
  void *pvVar6;
  
  uVar1 = tt->flags;
  pAVar2 = tt->item;
  if ((uVar1 & 1) == 0) {
    if ((uVar1 & 0x300) == 0) {
      if ((uVar1 & 6) == 0) {
        iVar5 = asn1_item_ex_combine_new();
        return iVar5;
      }
      p_Var4 = sk_new_null();
      if (p_Var4 == (_STACK *)0x0) {
        ERR_put_error(0xd,0x85,0x41,"tasn_new.c",0x125);
        return 0;
      }
      *pval = (ASN1_VALUE *)p_Var4;
      return 1;
    }
    goto switchD_0814799c_caseD_1;
  }
  if ((uVar1 & 0x306) != 0) goto switchD_0814799c_caseD_1;
  if (6 < (byte)pAVar2->itype) {
    return 1;
  }
  switch(pAVar2->itype) {
  case '\0':
    if (pAVar2->templates != (ASN1_TEMPLATE *)0x0) {
      if ((pAVar2->templates->flags & 0x306) == 0) {
        asn1_item_clear();
        return 1;
      }
      goto switchD_0814799c_caseD_1;
    }
    pvVar6 = pAVar2->funcs;
    if (pvVar6 == (void *)0x0) {
      if (pAVar2->utype == 1) {
        *pval = (ASN1_VALUE *)pAVar2->size;
        return 1;
      }
      goto switchD_0814799c_caseD_1;
    }
    break;
  default:
    goto switchD_0814799c_caseD_1;
  case '\x04':
    if (pAVar2->funcs == (void *)0x0) goto switchD_0814799c_caseD_1;
    pcVar3 = *(code **)((int)pAVar2->funcs + 0xc);
    goto joined_r0x081479b4;
  case '\x05':
    pvVar6 = pAVar2->funcs;
    if (pvVar6 == (void *)0x0) goto switchD_0814799c_caseD_1;
  }
  pcVar3 = *(code **)((int)pvVar6 + 0x10);
joined_r0x081479b4:
  if (pcVar3 != (code *)0x0) {
    (*pcVar3)(pval,pAVar2);
    return 1;
  }
switchD_0814799c_caseD_1:
  *pval = (ASN1_VALUE *)0x0;
  return 1;
}

