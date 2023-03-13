
int ASN1_item_ex_new(ASN1_VALUE **pval,ASN1_ITEM *it)

{
  code **ppcVar1;
  uint uVar2;
  ASN1_VALUE *pAVar3;
  _STACK **pp_Var4;
  _STACK *p_Var5;
  int iVar6;
  int iVar7;
  ASN1_TEMPLATE *tt;
  code *pcVar8;
  
  ppcVar1 = (code **)it->funcs;
  if ((ppcVar1 == (code **)0x0) || (pcVar8 = ppcVar1[4], pcVar8 == (code *)0x0)) {
    if (6 < (byte)it->itype) {
      return 1;
    }
    switch(it->itype) {
    case '\0':
      goto switchD_08144f48_caseD_0;
    default:
      pcVar8 = (code *)0x0;
      goto LAB_081450e2;
    case '\x02':
      pAVar3 = (ASN1_VALUE *)CRYPTO_malloc(it->size,"tasn_new.c",0x9a);
      *pval = pAVar3;
      if (pAVar3 != (ASN1_VALUE *)0x0) {
        memset(pAVar3,0,it->size);
        asn1_set_choice_selector(pval,-1,it);
        return 1;
      }
      goto LAB_08144f64;
    case '\x03':
      if (ppcVar1 == (code **)0x0) {
        return 1;
      }
      goto switchD_08144ee1_caseD_3;
    case '\x04':
      if (ppcVar1 == (code **)0x0) {
        return 1;
      }
      goto switchD_08144ee1_caseD_4;
    case '\x05':
      goto switchD_08144f48_caseD_5;
    }
  }
  if (6 < (byte)it->itype) {
    return 1;
  }
  switch(it->itype) {
  case '\0':
switchD_08144f48_caseD_0:
    if (it->templates == (ASN1_TEMPLATE *)0x0) goto switchD_08144f48_caseD_5;
    iVar7 = ASN1_template_new(pval,it->templates);
    break;
  default:
    iVar7 = (*pcVar8)(0,pval,it,0);
    if (iVar7 == 0) goto LAB_08145084;
    if (iVar7 == 2) {
      return 1;
    }
LAB_081450e2:
    pAVar3 = (ASN1_VALUE *)CRYPTO_malloc(it->size,"tasn_new.c",0xb3);
    *pval = pAVar3;
    if (pAVar3 == (ASN1_VALUE *)0x0) goto LAB_08144f64;
    iVar7 = 0;
    memset(pAVar3,0,it->size);
    asn1_do_lock(pval,0,it);
    asn1_enc_init(pval,it);
    tt = it->templates;
    if (0 < it->tcount) {
      do {
        pp_Var4 = (_STACK **)asn1_get_field_ptr(pval,tt);
        uVar2 = tt->flags;
        if ((uVar2 & 1) == 0) {
          if ((uVar2 & 0x300) == 0) {
            if ((uVar2 & 6) == 0) {
              iVar6 = asn1_item_ex_combine_new();
              if (iVar6 == 0) goto LAB_08144f64;
            }
            else {
              p_Var5 = sk_new_null();
              if (p_Var5 == (_STACK *)0x0) {
                ERR_put_error(0xd,0x85,0x41,"tasn_new.c",0x115);
                goto LAB_08144f64;
              }
              *pp_Var4 = p_Var5;
            }
          }
          else {
LAB_08145158:
            *pp_Var4 = (_STACK *)0x0;
          }
        }
        else {
          if ((uVar2 & 0x306) != 0) goto LAB_08145158;
          asn1_item_clear();
        }
        tt = tt + 1;
        iVar7 = iVar7 + 1;
      } while (iVar7 < it->tcount);
    }
    if (pcVar8 == (code *)0x0) {
      return 1;
    }
    iVar7 = (*pcVar8)(1,pval,it,0);
    goto joined_r0x0814507e;
  case '\x02':
    iVar7 = (*pcVar8)(0,pval,it,0);
    if (iVar7 == 0) goto LAB_08145084;
    if (iVar7 == 2) {
      return 1;
    }
    pAVar3 = (ASN1_VALUE *)CRYPTO_malloc(it->size,"tasn_new.c",0x9a);
    *pval = pAVar3;
    if (pAVar3 == (ASN1_VALUE *)0x0) goto LAB_08144f64;
    memset(pAVar3,0,it->size);
    asn1_set_choice_selector(pval,-1,it);
    iVar7 = (*pcVar8)(1,pval,it,0);
joined_r0x0814507e:
    if (iVar7 != 0) {
      return 1;
    }
LAB_08145084:
    ERR_put_error(0xd,0x79,100,"tasn_new.c",0xd2);
    ASN1_item_ex_free(pval,it);
    return 0;
  case '\x03':
switchD_08144ee1_caseD_3:
    if (*ppcVar1 == (code *)0x0) {
      return 1;
    }
    pAVar3 = (ASN1_VALUE *)(**ppcVar1)();
    *pval = pAVar3;
    if (pAVar3 != (ASN1_VALUE *)0x0) {
      return 1;
    }
    goto LAB_08144f64;
  case '\x04':
switchD_08144ee1_caseD_4:
    if (ppcVar1[1] == (code *)0x0) {
      return 1;
    }
    iVar7 = (*ppcVar1[1])(pval,it);
    break;
  case '\x05':
    goto switchD_08144f48_caseD_5;
  }
joined_r0x08144fda:
  if (iVar7 != 0) {
    return 1;
  }
LAB_08144f64:
  ERR_put_error(0xd,0x79,0x41,"tasn_new.c",0xca);
  return 0;
switchD_08144f48_caseD_5:
  iVar7 = ASN1_primitive_new(pval,it);
  goto joined_r0x08144fda;
}

