
undefined4 asn1_item_ex_combine_new(ASN1_VALUE **param_1,ASN1_ITEM *param_2,int param_3)

{
  ASN1_VALUE **ppAVar1;
  ASN1_VALUE *pAVar2;
  int iVar3;
  code **ppcVar4;
  uint uVar5;
  ASN1_TEMPLATE *tt;
  code *pcVar6;
  int iVar7;
  
  ppcVar4 = (code **)param_2->funcs;
  if ((ppcVar4 == (code **)0x0) || (pcVar6 = ppcVar4[4], pcVar6 == (code *)0x0)) {
    switch(param_2->itype) {
    case '\0':
      goto switchD_0055aab4_caseD_0;
    case '\x01':
    case '\x06':
      pcVar6 = (code *)0x0;
      goto LAB_0055ac8c;
    case '\x02':
      if (param_3 != 0) {
        asn1_set_choice_selector(param_1,-1,param_2);
        return 1;
      }
      pAVar2 = (ASN1_VALUE *)(*(code *)PTR_CRYPTO_malloc_006a7008)(param_2->size,"tasn_new.c",0x9a);
      *param_1 = pAVar2;
      if (pAVar2 != (ASN1_VALUE *)0x0) {
        (*(code *)PTR_memset_006a99f4)(pAVar2,0,param_2->size);
        asn1_set_choice_selector(param_1,-1,param_2);
        return 1;
      }
      goto LAB_0055aad4;
    case '\x03':
      if (ppcVar4 == (code **)0x0) {
        return 1;
      }
      goto switchD_0055aa10_caseD_3;
    case '\x04':
      if (ppcVar4 == (code **)0x0) {
        return 1;
      }
      goto switchD_0055aa10_caseD_4;
    case '\x05':
      goto switchD_0055aab4_caseD_5;
    default:
      goto switchD_0055aab4_caseD_7;
    }
  }
  switch(param_2->itype) {
  case '\0':
switchD_0055aab4_caseD_0:
    if (param_2->templates == (ASN1_TEMPLATE *)0x0) goto switchD_0055aab4_caseD_5;
    iVar7 = ASN1_template_new(param_1,param_2->templates);
    break;
  case '\x01':
  case '\x06':
    iVar7 = (*pcVar6)(0,param_1,param_2,0);
    if (iVar7 == 0) goto LAB_0055ac00;
    if (iVar7 == 2) {
      return 1;
    }
LAB_0055ac8c:
    if (param_3 == 0) {
      pAVar2 = (ASN1_VALUE *)(*(code *)PTR_CRYPTO_malloc_006a7008)(param_2->size,"tasn_new.c",0xb3);
      *param_1 = pAVar2;
      if (pAVar2 == (ASN1_VALUE *)0x0) goto LAB_0055aad4;
      (*(code *)PTR_memset_006a99f4)(pAVar2,0,param_2->size);
      asn1_do_lock(param_1,0,param_2);
      asn1_enc_init(param_1,param_2);
    }
    iVar7 = 0;
    tt = param_2->templates;
    if (0 < param_2->tcount) {
      do {
        ppAVar1 = asn1_get_field_ptr(param_1,tt);
        uVar5 = tt->flags;
        if ((uVar5 & 1) == 0) {
          if ((uVar5 & 0x300) != 0) goto LAB_0055acd8;
          if ((uVar5 & 6) == 0) {
            iVar3 = asn1_item_ex_combine_new(ppAVar1,tt->item,uVar5 & 0x400);
            if (iVar3 == 0) goto LAB_0055aad4;
          }
          else {
            pAVar2 = (ASN1_VALUE *)(*(code *)PTR_sk_new_null_006a6fa4)();
            if (pAVar2 == (ASN1_VALUE *)0x0) {
              (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x85,0x41,"tasn_new.c",0x115);
              goto LAB_0055aad4;
            }
            *ppAVar1 = pAVar2;
          }
        }
        else if ((uVar5 & 0x306) == 0) {
          asn1_item_clear(ppAVar1);
        }
        else {
LAB_0055acd8:
          *ppAVar1 = (ASN1_VALUE *)0x0;
        }
        iVar7 = iVar7 + 1;
        tt = tt + 1;
      } while (iVar7 < param_2->tcount);
    }
    if (pcVar6 == (code *)0x0) {
      return 1;
    }
    goto LAB_0055abe4;
  case '\x02':
    iVar7 = (*pcVar6)(0,param_1,param_2,0);
    if (iVar7 == 0) goto LAB_0055ac00;
    if (iVar7 == 2) {
      return 1;
    }
    if (param_3 == 0) {
      pAVar2 = (ASN1_VALUE *)(*(code *)PTR_CRYPTO_malloc_006a7008)(param_2->size,"tasn_new.c",0x9a);
      *param_1 = pAVar2;
      if (pAVar2 == (ASN1_VALUE *)0x0) goto LAB_0055aad4;
      (*(code *)PTR_memset_006a99f4)(pAVar2,0,param_2->size);
      asn1_set_choice_selector(param_1,-1,param_2);
    }
    else {
      asn1_set_choice_selector(param_1,-1,param_2);
    }
LAB_0055abe4:
    iVar7 = (*pcVar6)(1,param_1,param_2,0);
    if (iVar7 != 0) {
      return 1;
    }
LAB_0055ac00:
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x79,100,"tasn_new.c",0xd2);
    ASN1_item_ex_free(param_1,param_2);
    return 0;
  case '\x03':
switchD_0055aa10_caseD_3:
    if (*ppcVar4 == (code *)0x0) {
      return 1;
    }
    pAVar2 = (ASN1_VALUE *)(**ppcVar4)();
    *param_1 = pAVar2;
    if (pAVar2 != (ASN1_VALUE *)0x0) {
      return 1;
    }
    goto LAB_0055aad4;
  case '\x04':
switchD_0055aa10_caseD_4:
    if (ppcVar4[1] == (code *)0x0) {
      return 1;
    }
    iVar7 = (*ppcVar4[1])(param_1,param_2);
    break;
  case '\x05':
    goto switchD_0055aab4_caseD_5;
  default:
    goto switchD_0055aab4_caseD_7;
  }
joined_r0x0055ab30:
  if (iVar7 != 0) {
switchD_0055aab4_caseD_7:
    return 1;
  }
LAB_0055aad4:
  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x79,0x41,"tasn_new.c",0xca);
  return 0;
switchD_0055aab4_caseD_5:
  iVar7 = ASN1_primitive_new(param_1,param_2);
  goto joined_r0x0055ab30;
}

