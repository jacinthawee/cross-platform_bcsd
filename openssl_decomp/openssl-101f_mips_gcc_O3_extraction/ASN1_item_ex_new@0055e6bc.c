
int ASN1_item_ex_new(ASN1_VALUE **pval,ASN1_ITEM *it)

{
  ASN1_VALUE *pAVar1;
  ASN1_VALUE **ppAVar2;
  int iVar3;
  uint uVar4;
  ASN1_TEMPLATE *tt;
  code *pcVar5;
  int iVar6;
  
  if ((it->funcs == (void *)0x0) ||
     (pcVar5 = *(code **)((int)it->funcs + 0x10), pcVar5 == (code *)0x0)) {
    *pval = (ASN1_VALUE *)0x0;
    switch(it->itype) {
    case '\0':
      goto switchD_0055e7d4_caseD_0;
    case '\x01':
    case '\x06':
      pcVar5 = (code *)0x0;
      goto LAB_0055e9a4;
    case '\x02':
      pAVar1 = (ASN1_VALUE *)(*(code *)PTR_CRYPTO_malloc_006a8108)(it->size,"tasn_new.c",0xa3);
      *pval = pAVar1;
      if (pAVar1 != (ASN1_VALUE *)0x0) {
        (*(code *)PTR_memset_006aab00)(pAVar1,0,it->size);
        asn1_set_choice_selector(pval,-1,it);
        return 1;
      }
      goto LAB_0055e7f8;
    case '\x03':
      goto switchD_0055e7d4_caseD_3;
    case '\x04':
      goto switchD_0055e7d4_caseD_4;
    case '\x05':
      goto switchD_0055e7d4_caseD_5;
    default:
      goto switchD_0055e7d4_caseD_7;
    }
  }
  *pval = (ASN1_VALUE *)0x0;
  switch(it->itype) {
  case '\0':
switchD_0055e7d4_caseD_0:
    if (it->templates == (ASN1_TEMPLATE *)0x0) goto switchD_0055e7d4_caseD_5;
    iVar6 = ASN1_template_new(pval,it->templates);
    break;
  case '\x01':
  case '\x06':
    iVar6 = (*pcVar5)(0,pval,it,0);
    if (iVar6 == 0) goto LAB_0055ead0;
    if (iVar6 == 2) {
      return 1;
    }
LAB_0055e9a4:
    pAVar1 = (ASN1_VALUE *)(*(code *)PTR_CRYPTO_malloc_006a8108)(it->size,"tasn_new.c",0xbf);
    *pval = pAVar1;
    if (pAVar1 == (ASN1_VALUE *)0x0) goto LAB_0055e7f8;
    iVar6 = 0;
    (*(code *)PTR_memset_006aab00)(pAVar1,0,it->size);
    asn1_do_lock(pval,0,it);
    asn1_enc_init(pval,it);
    tt = it->templates;
    if (0 < it->tcount) {
      do {
        ppAVar2 = asn1_get_field_ptr(pval,tt);
        uVar4 = tt->flags;
        if ((uVar4 & 1) == 0) {
          if ((uVar4 & 0x300) != 0) goto LAB_0055ea4c;
          if ((uVar4 & 6) == 0) {
            iVar3 = asn1_item_ex_combine_new(ppAVar2,tt->item,uVar4 & 0x400);
            if (iVar3 == 0) goto LAB_0055e7f8;
          }
          else {
            pAVar1 = (ASN1_VALUE *)(*(code *)PTR_sk_new_null_006a80a4)();
            if (pAVar1 == (ASN1_VALUE *)0x0) {
              (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x85,0x41,"tasn_new.c",0x125);
              goto LAB_0055e7f8;
            }
            *ppAVar2 = pAVar1;
          }
        }
        else if ((uVar4 & 0x306) == 0) {
          asn1_item_clear(ppAVar2);
        }
        else {
LAB_0055ea4c:
          *ppAVar2 = (ASN1_VALUE *)0x0;
        }
        iVar6 = iVar6 + 1;
        tt = tt + 1;
      } while (iVar6 < it->tcount);
    }
    if (pcVar5 == (code *)0x0) {
      return 1;
    }
    goto LAB_0055e948;
  case '\x02':
    iVar6 = (*pcVar5)(0,pval,it,0);
    if (iVar6 == 0) goto LAB_0055ead0;
    if (iVar6 == 2) {
      return 1;
    }
    pAVar1 = (ASN1_VALUE *)(*(code *)PTR_CRYPTO_malloc_006a8108)(it->size,"tasn_new.c",0xa3);
    *pval = pAVar1;
    if (pAVar1 == (ASN1_VALUE *)0x0) goto LAB_0055e7f8;
    (*(code *)PTR_memset_006aab00)(pAVar1,0,it->size);
    asn1_set_choice_selector(pval,-1,it);
LAB_0055e948:
    iVar6 = (*pcVar5)(1,pval,it,0);
    if (iVar6 != 0) {
      return 1;
    }
LAB_0055ead0:
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x79,100,"tasn_new.c",0xdd);
    ASN1_item_ex_free(pval,it);
    return 0;
  case '\x03':
switchD_0055e7d4_caseD_3:
    if ((code **)it->funcs == (code **)0x0) {
      return 1;
    }
                    /* WARNING: Load size is inaccurate */
    pcVar5 = *it->funcs;
    if (pcVar5 == (code *)0x0) {
      return 1;
    }
    pAVar1 = (ASN1_VALUE *)(*pcVar5)();
    *pval = pAVar1;
    if (pAVar1 != (ASN1_VALUE *)0x0) {
      return 1;
    }
    goto LAB_0055e7f8;
  case '\x04':
switchD_0055e7d4_caseD_4:
    if (it->funcs == (void *)0x0) {
      return 1;
    }
    pcVar5 = *(code **)((int)it->funcs + 4);
    if (pcVar5 == (code *)0x0) {
      return 1;
    }
    iVar6 = (*pcVar5)(pval,it);
    break;
  case '\x05':
    goto switchD_0055e7d4_caseD_5;
  default:
    goto switchD_0055e7d4_caseD_7;
  }
joined_r0x0055e854:
  if (iVar6 != 0) {
switchD_0055e7d4_caseD_7:
    return 1;
  }
LAB_0055e7f8:
  (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x79,0x41,"tasn_new.c",0xd6);
  return 0;
switchD_0055e7d4_caseD_5:
  iVar6 = ASN1_primitive_new(pval,it);
  goto joined_r0x0055e854;
}

