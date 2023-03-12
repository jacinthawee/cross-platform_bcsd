
undefined4 asn1_item_ex_combine_new(ASN1_VALUE **param_1,ASN1_ITEM *param_2,int param_3)

{
  int iVar1;
  ASN1_VALUE **ppAVar2;
  ASN1_VALUE *pAVar3;
  int iVar4;
  uint uVar5;
  ASN1_TEMPLATE *tt;
  code *pcVar6;
  
  if (param_2->funcs == (void *)0x0) {
    pcVar6 = (code *)0x0;
  }
  else {
    pcVar6 = *(code **)((int)param_2->funcs + 0x10);
  }
  if (param_3 == 0) {
    *param_1 = (ASN1_VALUE *)0x0;
  }
  switch(param_2->itype) {
  case '\0':
    if (param_2->templates == (ASN1_TEMPLATE *)0x0) goto switchD_0055e0e4_caseD_5;
    pAVar3 = (ASN1_VALUE *)ASN1_template_new(param_1,param_2->templates);
    break;
  case '\x01':
  case '\x06':
    if (pcVar6 != (code *)0x0) {
      iVar1 = (*pcVar6)(0,param_1,param_2,0);
      if (iVar1 == 0) goto LAB_0055e2f8;
      if (iVar1 == 2) {
        return 1;
      }
    }
    if (param_3 == 0) {
      pAVar3 = (ASN1_VALUE *)(*(code *)PTR_CRYPTO_malloc_006a8108)(param_2->size,"tasn_new.c",0xbf);
      *param_1 = pAVar3;
      if (pAVar3 == (ASN1_VALUE *)0x0) goto LAB_0055e180;
      (*(code *)PTR_memset_006aab00)(pAVar3,0,param_2->size);
      asn1_do_lock(param_1,0,param_2);
      asn1_enc_init(param_1,param_2);
    }
    iVar1 = 0;
    tt = param_2->templates;
    if (0 < param_2->tcount) {
      do {
        ppAVar2 = asn1_get_field_ptr(param_1,tt);
        uVar5 = tt->flags;
        if ((uVar5 & 1) == 0) {
          if ((uVar5 & 0x300) != 0) goto LAB_0055e268;
          if ((uVar5 & 6) == 0) {
            iVar4 = asn1_item_ex_combine_new(ppAVar2,tt->item,uVar5 & 0x400);
            if (iVar4 == 0) goto LAB_0055e180;
          }
          else {
            pAVar3 = (ASN1_VALUE *)(*(code *)PTR_sk_new_null_006a80a4)();
            if (pAVar3 == (ASN1_VALUE *)0x0) {
              (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x85,0x41,"tasn_new.c",0x125);
              goto LAB_0055e180;
            }
            *ppAVar2 = pAVar3;
          }
        }
        else if ((uVar5 & 0x306) == 0) {
          asn1_item_clear(ppAVar2);
        }
        else {
LAB_0055e268:
          *ppAVar2 = (ASN1_VALUE *)0x0;
        }
        iVar1 = iVar1 + 1;
        tt = tt + 1;
      } while (iVar1 < param_2->tcount);
    }
    if (pcVar6 == (code *)0x0) {
      return 1;
    }
    goto LAB_0055e2dc;
  case '\x02':
    if (pcVar6 == (code *)0x0) {
      if (param_3 != 0) {
        asn1_set_choice_selector(param_1,-1,param_2);
        return 1;
      }
      pAVar3 = (ASN1_VALUE *)
               (*(code *)PTR_CRYPTO_malloc_006a8108)(param_2->size,"tasn_new.c",0xa3,0);
      *param_1 = pAVar3;
      if (pAVar3 != (ASN1_VALUE *)0x0) {
        (*(code *)PTR_memset_006aab00)(pAVar3,0,param_2->size);
        asn1_set_choice_selector(param_1,-1,param_2);
        return 1;
      }
      goto LAB_0055e180;
    }
    iVar1 = (*pcVar6)(0,param_1,param_2);
    if (iVar1 == 0) goto LAB_0055e2f8;
    if (iVar1 == 2) {
      return 1;
    }
    if (param_3 == 0) {
      pAVar3 = (ASN1_VALUE *)(*(code *)PTR_CRYPTO_malloc_006a8108)(param_2->size,"tasn_new.c",0xa3);
      *param_1 = pAVar3;
      if (pAVar3 == (ASN1_VALUE *)0x0) goto LAB_0055e180;
      (*(code *)PTR_memset_006aab00)(pAVar3,0,param_2->size);
      asn1_set_choice_selector(param_1,-1,param_2);
    }
    else {
      asn1_set_choice_selector(param_1,-1,param_2);
    }
LAB_0055e2dc:
    iVar1 = (*pcVar6)(1,param_1,param_2,0);
    if (iVar1 != 0) {
      return 1;
    }
LAB_0055e2f8:
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x79,100,"tasn_new.c",0xdd);
    ASN1_item_ex_free(param_1,param_2);
    return 0;
  case '\x03':
    if ((code **)param_2->funcs == (code **)0x0) {
      return 1;
    }
                    /* WARNING: Load size is inaccurate */
    pcVar6 = *param_2->funcs;
    if (pcVar6 == (code *)0x0) {
      return 1;
    }
    pAVar3 = (ASN1_VALUE *)(*pcVar6)();
    *param_1 = pAVar3;
    break;
  case '\x04':
    if (param_2->funcs == (void *)0x0) {
      return 1;
    }
    pcVar6 = *(code **)((int)param_2->funcs + 4);
    if (pcVar6 == (code *)0x0) {
      return 1;
    }
    iVar1 = (*pcVar6)();
    if (iVar1 != 0) {
      return 1;
    }
    goto LAB_0055e180;
  case '\x05':
switchD_0055e0e4_caseD_5:
    pAVar3 = (ASN1_VALUE *)ASN1_primitive_new(param_1,param_2);
    break;
  default:
    goto switchD_0055e0e4_caseD_7;
  }
  if (pAVar3 == (ASN1_VALUE *)0x0) {
LAB_0055e180:
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x79,0x41,"tasn_new.c",0xd6);
    return 0;
  }
switchD_0055e0e4_caseD_7:
  return 1;
}

