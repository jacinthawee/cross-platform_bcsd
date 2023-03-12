
int ASN1_item_ex_new(ASN1_VALUE **pval,ASN1_ITEM *it)

{
  uint uVar1;
  ASN1_VALUE *pAVar2;
  _STACK **pp_Var3;
  _STACK *p_Var4;
  int iVar5;
  int iVar6;
  ASN1_TEMPLATE *tt;
  code *pcVar7;
  
  if ((it->funcs == (void *)0x0) ||
     (pcVar7 = *(code **)((int)it->funcs + 0x10), pcVar7 == (code *)0x0)) {
    *pval = (ASN1_VALUE *)0x0;
    if (6 < (byte)it->itype) {
      return 1;
    }
    switch(it->itype) {
    case '\0':
      goto switchD_08147b07_caseD_0;
    default:
      pcVar7 = (code *)0x0;
      goto LAB_08147c82;
    case '\x02':
      pAVar2 = (ASN1_VALUE *)CRYPTO_malloc(it->size,"tasn_new.c",0xa3);
      *pval = pAVar2;
      if (pAVar2 != (ASN1_VALUE *)0x0) {
        memset(pAVar2,0,it->size);
        asn1_set_choice_selector(pval,-1,it);
        return 1;
      }
      goto LAB_08147b21;
    case '\x03':
      goto switchD_08147b07_caseD_3;
    case '\x04':
      goto switchD_08147b07_caseD_4;
    case '\x05':
      goto switchD_08147b07_caseD_5;
    }
  }
  *pval = (ASN1_VALUE *)0x0;
  if (6 < (byte)it->itype) {
    return 1;
  }
  switch(it->itype) {
  case '\0':
switchD_08147b07_caseD_0:
    if (it->templates == (ASN1_TEMPLATE *)0x0) goto switchD_08147b07_caseD_5;
    iVar6 = ASN1_template_new(pval,it->templates);
    break;
  default:
    iVar6 = (*pcVar7)(0,pval,it,0);
    if (iVar6 == 0) goto LAB_08147c30;
    if (iVar6 == 2) {
      return 1;
    }
LAB_08147c82:
    pAVar2 = (ASN1_VALUE *)CRYPTO_malloc(it->size,"tasn_new.c",0xbf);
    *pval = pAVar2;
    if (pAVar2 == (ASN1_VALUE *)0x0) goto LAB_08147b21;
    memset(pAVar2,0,it->size);
    asn1_do_lock(pval,0,it);
    asn1_enc_init(pval,it);
    tt = it->templates;
    if (0 < it->tcount) {
      iVar6 = 0;
      do {
        pp_Var3 = (_STACK **)asn1_get_field_ptr(pval,tt);
        uVar1 = tt->flags;
        if ((uVar1 & 1) == 0) {
          if ((uVar1 & 0x300) == 0) {
            if ((uVar1 & 6) == 0) {
              iVar5 = asn1_item_ex_combine_new();
              if (iVar5 == 0) goto LAB_08147b21;
            }
            else {
              p_Var4 = sk_new_null();
              if (p_Var4 == (_STACK *)0x0) {
                ERR_put_error(0xd,0x85,0x41,"tasn_new.c",0x125);
                goto LAB_08147b21;
              }
              *pp_Var3 = p_Var4;
            }
          }
          else {
LAB_08147cf8:
            *pp_Var3 = (_STACK *)0x0;
          }
        }
        else {
          if ((uVar1 & 0x306) != 0) goto LAB_08147cf8;
          asn1_item_clear();
        }
        tt = tt + 1;
        iVar6 = iVar6 + 1;
      } while (iVar6 < it->tcount);
    }
    if (pcVar7 == (code *)0x0) {
      return 1;
    }
    iVar6 = (*pcVar7)(1,pval,it,0);
    goto joined_r0x08147c2a;
  case '\x02':
    iVar6 = (*pcVar7)(0,pval,it,0);
    if (iVar6 == 0) goto LAB_08147c30;
    if (iVar6 == 2) {
      return 1;
    }
    pAVar2 = (ASN1_VALUE *)CRYPTO_malloc(it->size,"tasn_new.c",0xa3);
    *pval = pAVar2;
    if (pAVar2 == (ASN1_VALUE *)0x0) goto LAB_08147b21;
    memset(pAVar2,0,it->size);
    asn1_set_choice_selector(pval,-1,it);
    iVar6 = (*pcVar7)(1,pval,it,0);
joined_r0x08147c2a:
    if (iVar6 != 0) {
      return 1;
    }
LAB_08147c30:
    ERR_put_error(0xd,0x79,100,"tasn_new.c",0xdd);
    ASN1_item_ex_free(pval,it);
    return 0;
  case '\x03':
switchD_08147b07_caseD_3:
    if ((code **)it->funcs == (code **)0x0) {
      return 1;
    }
                    /* WARNING: Load size is inaccurate */
    pcVar7 = *it->funcs;
    if (pcVar7 == (code *)0x0) {
      return 1;
    }
    pAVar2 = (ASN1_VALUE *)(*pcVar7)();
    *pval = pAVar2;
    if (pAVar2 != (ASN1_VALUE *)0x0) {
      return 1;
    }
    goto LAB_08147b21;
  case '\x04':
switchD_08147b07_caseD_4:
    if (it->funcs == (void *)0x0) {
      return 1;
    }
    pcVar7 = *(code **)((int)it->funcs + 4);
    if (pcVar7 == (code *)0x0) {
      return 1;
    }
    iVar6 = (*pcVar7)(pval,it);
    break;
  case '\x05':
    goto switchD_08147b07_caseD_5;
  }
joined_r0x08147bba:
  if (iVar6 != 0) {
    return 1;
  }
LAB_08147b21:
  ERR_put_error(0xd,0x79,0x41,"tasn_new.c",0xd6);
  return 0;
switchD_08147b07_caseD_5:
  iVar6 = ASN1_primitive_new(pval,it);
  goto joined_r0x08147bba;
}

