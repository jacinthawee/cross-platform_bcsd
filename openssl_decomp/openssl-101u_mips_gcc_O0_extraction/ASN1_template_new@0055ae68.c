
int ASN1_template_new(ASN1_VALUE **pval,ASN1_TEMPLATE *tt)

{
  ASN1_VALUE *pAVar1;
  int iVar2;
  void *pvVar3;
  ASN1_TEMPLATE *pAVar4;
  ASN1_ITEM_EXP *pAVar5;
  uint uVar6;
  code *pcVar7;
  
  uVar6 = tt->flags;
  pAVar5 = tt->item;
  if ((uVar6 & 1) == 0) {
    if ((uVar6 & 0x300) == 0) {
      if ((uVar6 & 6) == 0) {
        iVar2 = asn1_item_ex_combine_new(pval,pAVar5,uVar6 & 0x400);
        return iVar2;
      }
      pAVar1 = (ASN1_VALUE *)(*(code *)PTR_sk_new_null_006a6fa4)();
      if (pAVar1 == (ASN1_VALUE *)0x0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x85,0x41,"tasn_new.c",0x115);
        return 0;
      }
      *pval = pAVar1;
      return 1;
    }
    goto LAB_0055aea4;
  }
  if ((uVar6 & 0x306) != 0) goto LAB_0055aea4;
  switch(pAVar5->itype) {
  case '\0':
    pAVar4 = pAVar5->templates;
    if (pAVar4 != (ASN1_TEMPLATE *)0x0) {
      if ((pAVar4->flags & 0x306) == 0) {
        asn1_item_clear(pval,pAVar4->item);
        return 1;
      }
      goto LAB_0055aea4;
    }
    pvVar3 = pAVar5->funcs;
    if (pvVar3 == (void *)0x0) {
      if (pAVar5->utype == 1) {
        *pval = (ASN1_VALUE *)pAVar5->size;
        return 1;
      }
      goto LAB_0055aea4;
    }
    break;
  case '\x01':
  case '\x02':
  case '\x03':
  case '\x06':
    goto LAB_0055aea4;
  case '\x04':
    if (pAVar5->funcs == (void *)0x0) goto LAB_0055aea4;
    pcVar7 = *(code **)((int)pAVar5->funcs + 0xc);
    goto joined_r0x0055af40;
  case '\x05':
    pvVar3 = pAVar5->funcs;
    if (pvVar3 == (void *)0x0) goto LAB_0055aea4;
    break;
  default:
    return 1;
  }
  pcVar7 = *(code **)((int)pvVar3 + 0x10);
joined_r0x0055af40:
  if (pcVar7 != (code *)0x0) {
    (*pcVar7)(pval);
    return 1;
  }
LAB_0055aea4:
  *pval = (ASN1_VALUE *)0x0;
  return 1;
}

