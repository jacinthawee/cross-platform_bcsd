
int ASN1_item_ex_new(ASN1_VALUE **pval,ASN1_ITEM *it)

{
  int iVar1;
  ASN1_VALUE *pAVar2;
  _STACK **pp_Var3;
  _STACK *p_Var4;
  int iVar5;
  uint uVar6;
  code **ppcVar7;
  ASN1_TEMPLATE *pAVar8;
  code **ppcVar9;
  
  ppcVar7 = (code **)it->funcs;
  ppcVar9 = ppcVar7;
  if (ppcVar7 != (code **)0x0) {
    ppcVar9 = (code **)ppcVar7[4];
  }
  switch(it->itype) {
  case '\0':
    pAVar8 = it->templates;
    if (pAVar8 == (ASN1_TEMPLATE *)0x0) goto switchD_000b8cd6_caseD_5;
    uVar6 = pAVar8->flags;
    if ((int)(uVar6 << 0x1f) < 0) {
      if ((uVar6 & 0x306) == 0) {
        asn1_item_clear(pval);
        return 1;
      }
LAB_000b8d4e:
      *pval = (ASN1_VALUE *)0x0;
      return 1;
    }
    if ((uVar6 & 0x300) != 0) goto LAB_000b8d4e;
    if ((uVar6 & 6) != 0) {
      p_Var4 = sk_new_null();
      if (p_Var4 != (_STACK *)0x0) {
        *pval = (ASN1_VALUE *)p_Var4;
        return 1;
      }
LAB_000b8eea:
      ERR_put_error(0xd,0x85,0x41,"tasn_new.c",0x115);
      goto LAB_000b8d16;
    }
    pAVar2 = (ASN1_VALUE *)asn1_item_ex_combine_new(pval,pAVar8->item,uVar6 & 0x400);
    break;
  case '\x01':
  case '\x06':
    if (ppcVar9 != (code **)0x0) {
      iVar1 = (*(code *)ppcVar9)(0,pval,it,0);
      if (iVar1 == 0) goto LAB_000b8e56;
      if (iVar1 == 2) {
        return 1;
      }
    }
    pAVar2 = (ASN1_VALUE *)CRYPTO_malloc(it->size,"tasn_new.c",0xb3);
    *pval = pAVar2;
    if (pAVar2 == (ASN1_VALUE *)0x0) goto LAB_000b8d16;
    memset(pAVar2,0,it->size);
    asn1_do_lock(pval,0,it);
    asn1_enc_init(pval,it);
    pAVar8 = it->templates;
    if (0 < it->tcount) {
      iVar1 = 0;
      do {
        pp_Var3 = (_STACK **)asn1_get_field_ptr(pval,pAVar8);
        uVar6 = pAVar8->flags;
        if ((uVar6 & 1) == 0) {
          if ((uVar6 & 0x300) == 0) {
            if ((uVar6 & 6) == 0) {
              iVar5 = asn1_item_ex_combine_new(pp_Var3,pAVar8->item,uVar6 & 0x400);
              if (iVar5 == 0) goto LAB_000b8d16;
            }
            else {
              p_Var4 = sk_new_null();
              if (p_Var4 == (_STACK *)0x0) goto LAB_000b8eea;
              *pp_Var3 = p_Var4;
            }
          }
          else {
            *pp_Var3 = (_STACK *)0x0;
          }
        }
        else if ((uVar6 & 0x306) == 0) {
          asn1_item_clear(pp_Var3,pAVar8->item);
        }
        else {
          *pp_Var3 = (_STACK *)0x0;
        }
        iVar1 = iVar1 + 1;
        pAVar8 = pAVar8 + 1;
      } while (iVar1 < it->tcount);
    }
    goto joined_r0x000b8e42;
  case '\x02':
    if (ppcVar9 != (code **)0x0) {
      iVar1 = (*(code *)ppcVar9)(0,pval,it,0);
      if (iVar1 == 0) goto LAB_000b8e56;
      if (iVar1 == 2) {
        return 1;
      }
    }
    pAVar2 = (ASN1_VALUE *)CRYPTO_malloc(it->size,"tasn_new.c",0x9a);
    *pval = pAVar2;
    if (pAVar2 == (ASN1_VALUE *)0x0) goto LAB_000b8d16;
    memset(pAVar2,0,it->size);
    asn1_set_choice_selector(pval,-1,it);
joined_r0x000b8e42:
    if (ppcVar9 == (code **)0x0) {
      return 1;
    }
    iVar1 = (*(code *)ppcVar9)(1,pval,it,0);
    if (iVar1 != 0) {
      return 1;
    }
LAB_000b8e56:
    ERR_put_error(0xd,0x79,100,"tasn_new.c",0xd2);
    ASN1_item_ex_free(pval,it);
    return 0;
  case '\x03':
    if (ppcVar7 == (code **)0x0) {
      return 1;
    }
    if (*ppcVar7 == (code *)0x0) {
      return 1;
    }
    pAVar2 = (ASN1_VALUE *)(**ppcVar7)();
    *pval = pAVar2;
    break;
  case '\x04':
    if (ppcVar7 == (code **)0x0) {
      return 1;
    }
    if (ppcVar7[1] == (code *)0x0) {
      return 1;
    }
    pAVar2 = (ASN1_VALUE *)(*ppcVar7[1])(pval,it);
    break;
  case '\x05':
switchD_000b8cd6_caseD_5:
    pAVar2 = (ASN1_VALUE *)ASN1_primitive_new(pval,it);
    break;
  default:
    goto switchD_000b8cd6_caseD_7;
  }
  if (pAVar2 == (ASN1_VALUE *)0x0) {
LAB_000b8d16:
    ERR_put_error(0xd,0x79,0x41,"tasn_new.c",0xca);
    return 0;
  }
switchD_000b8cd6_caseD_7:
  return 1;
}

