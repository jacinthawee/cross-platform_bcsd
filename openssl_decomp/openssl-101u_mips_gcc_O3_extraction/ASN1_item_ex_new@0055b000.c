
int ASN1_item_ex_new(ASN1_VALUE **pval,ASN1_ITEM *it)

{
  ASN1_VALUE *pAVar1;
  ASN1_VALUE **ppAVar2;
  int iVar3;
  code **ppcVar4;
  uint uVar5;
  ASN1_TEMPLATE *tt;
  code *pcVar6;
  int iVar7;
  
  ppcVar4 = (code **)it->funcs;
  if ((ppcVar4 == (code **)0x0) || (pcVar6 = ppcVar4[4], pcVar6 == (code *)0x0)) {
    switch(it->itype) {
    case '\0':
      goto switchD_0055b110_caseD_0;
    case '\x01':
    case '\x06':
      pcVar6 = (code *)0x0;
      goto LAB_0055b2d8;
    case '\x02':
      pAVar1 = (ASN1_VALUE *)(*(code *)PTR_CRYPTO_malloc_006a7008)(it->size,"tasn_new.c",0x9a);
      *pval = pAVar1;
      if (pAVar1 != (ASN1_VALUE *)0x0) {
        (*(code *)PTR_memset_006a99f4)(pAVar1,0,it->size);
        asn1_set_choice_selector(pval,-1,it);
        return 1;
      }
      goto LAB_0055b134;
    case '\x03':
      if (ppcVar4 == (code **)0x0) {
        return 1;
      }
      goto switchD_0055b06c_caseD_3;
    case '\x04':
      if (ppcVar4 == (code **)0x0) {
        return 1;
      }
      goto switchD_0055b06c_caseD_4;
    case '\x05':
      goto switchD_0055b110_caseD_5;
    default:
      goto switchD_0055b110_caseD_7;
    }
  }
  switch(it->itype) {
  case '\0':
switchD_0055b110_caseD_0:
    if (it->templates == (ASN1_TEMPLATE *)0x0) goto switchD_0055b110_caseD_5;
    iVar7 = ASN1_template_new(pval,it->templates);
    break;
  case '\x01':
  case '\x06':
    iVar7 = (*pcVar6)(0,pval,it,0);
    if (iVar7 == 0) goto LAB_0055b404;
    if (iVar7 == 2) {
      return 1;
    }
LAB_0055b2d8:
    pAVar1 = (ASN1_VALUE *)(*(code *)PTR_CRYPTO_malloc_006a7008)(it->size,"tasn_new.c",0xb3);
    *pval = pAVar1;
    if (pAVar1 == (ASN1_VALUE *)0x0) goto LAB_0055b134;
    iVar7 = 0;
    (*(code *)PTR_memset_006a99f4)(pAVar1,0,it->size);
    asn1_do_lock(pval,0,it);
    asn1_enc_init(pval,it);
    tt = it->templates;
    if (0 < it->tcount) {
      do {
        ppAVar2 = asn1_get_field_ptr(pval,tt);
        uVar5 = tt->flags;
        if ((uVar5 & 1) == 0) {
          if ((uVar5 & 0x300) != 0) goto LAB_0055b380;
          if ((uVar5 & 6) == 0) {
            iVar3 = asn1_item_ex_combine_new(ppAVar2,tt->item,uVar5 & 0x400);
            if (iVar3 == 0) goto LAB_0055b134;
          }
          else {
            pAVar1 = (ASN1_VALUE *)(*(code *)PTR_sk_new_null_006a6fa4)();
            if (pAVar1 == (ASN1_VALUE *)0x0) {
              (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x85,0x41,"tasn_new.c",0x115);
              goto LAB_0055b134;
            }
            *ppAVar2 = pAVar1;
          }
        }
        else if ((uVar5 & 0x306) == 0) {
          asn1_item_clear(ppAVar2);
        }
        else {
LAB_0055b380:
          *ppAVar2 = (ASN1_VALUE *)0x0;
        }
        iVar7 = iVar7 + 1;
        tt = tt + 1;
      } while (iVar7 < it->tcount);
    }
    if (pcVar6 == (code *)0x0) {
      return 1;
    }
    goto LAB_0055b27c;
  case '\x02':
    iVar7 = (*pcVar6)(0,pval,it,0);
    if (iVar7 == 0) goto LAB_0055b404;
    if (iVar7 == 2) {
      return 1;
    }
    pAVar1 = (ASN1_VALUE *)(*(code *)PTR_CRYPTO_malloc_006a7008)(it->size,"tasn_new.c",0x9a);
    *pval = pAVar1;
    if (pAVar1 == (ASN1_VALUE *)0x0) goto LAB_0055b134;
    (*(code *)PTR_memset_006a99f4)(pAVar1,0,it->size);
    asn1_set_choice_selector(pval,-1,it);
LAB_0055b27c:
    iVar7 = (*pcVar6)(1,pval,it,0);
    if (iVar7 != 0) {
      return 1;
    }
LAB_0055b404:
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x79,100,"tasn_new.c",0xd2);
    ASN1_item_ex_free(pval,it);
    return 0;
  case '\x03':
switchD_0055b06c_caseD_3:
    if (*ppcVar4 == (code *)0x0) {
      return 1;
    }
    pAVar1 = (ASN1_VALUE *)(**ppcVar4)();
    *pval = pAVar1;
    if (pAVar1 != (ASN1_VALUE *)0x0) {
      return 1;
    }
    goto LAB_0055b134;
  case '\x04':
switchD_0055b06c_caseD_4:
    if (ppcVar4[1] == (code *)0x0) {
      return 1;
    }
    iVar7 = (*ppcVar4[1])(pval,it);
    break;
  case '\x05':
    goto switchD_0055b110_caseD_5;
  default:
    goto switchD_0055b110_caseD_7;
  }
joined_r0x0055b190:
  if (iVar7 != 0) {
switchD_0055b110_caseD_7:
    return 1;
  }
LAB_0055b134:
  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x79,0x41,"tasn_new.c",0xca);
  return 0;
switchD_0055b110_caseD_5:
  iVar7 = ASN1_primitive_new(pval,it);
  goto joined_r0x0055b190;
}

