
undefined4 __regparm3 asn1_item_ex_combine_new(ASN1_VALUE **param_1,ASN1_ITEM *param_2,int param_3)

{
  code **ppcVar1;
  uint uVar2;
  _STACK **pp_Var3;
  _STACK *p_Var4;
  int iVar5;
  ASN1_VALUE *pAVar6;
  int iVar7;
  ASN1_TEMPLATE *tt;
  code *local_24;
  
  ppcVar1 = (code **)param_2->funcs;
  if ((ppcVar1 == (code **)0x0) || (local_24 = ppcVar1[4], local_24 == (code *)0x0)) {
    if (6 < (byte)param_2->itype) {
      return 1;
    }
    switch(param_2->itype) {
    case '\0':
      goto switchD_08144a70_caseD_0;
    default:
      local_24 = (code *)0x0;
      goto LAB_08144bf8;
    case '\x02':
      if (param_3 != 0) {
LAB_08144a48:
        asn1_set_choice_selector(param_1,-1,param_2);
        return 1;
      }
      pAVar6 = (ASN1_VALUE *)CRYPTO_malloc(param_2->size,"tasn_new.c",0x9a);
      *param_1 = pAVar6;
      if (pAVar6 != (ASN1_VALUE *)0x0) {
        memset(pAVar6,0,param_2->size);
        goto LAB_08144a48;
      }
      goto LAB_08144a91;
    case '\x03':
      if (ppcVar1 == (code **)0x0) {
        return 1;
      }
      goto switchD_08144a05_caseD_3;
    case '\x04':
      if (ppcVar1 == (code **)0x0) {
        return 1;
      }
      goto switchD_08144a05_caseD_4;
    case '\x05':
      goto switchD_08144a70_caseD_5;
    }
  }
  if (6 < (byte)param_2->itype) {
    return 1;
  }
  switch(param_2->itype) {
  case '\0':
switchD_08144a70_caseD_0:
    if (param_2->templates == (ASN1_TEMPLATE *)0x0) goto switchD_08144a70_caseD_5;
    iVar7 = ASN1_template_new(param_1,param_2->templates);
    break;
  default:
    iVar7 = (*local_24)(0,param_1,param_2,0);
    if (iVar7 == 0) goto LAB_08144b92;
    if (iVar7 == 2) {
      return 1;
    }
LAB_08144bf8:
    if (param_3 == 0) {
      pAVar6 = (ASN1_VALUE *)CRYPTO_malloc(param_2->size,"tasn_new.c",0xb3);
      *param_1 = pAVar6;
      if (pAVar6 == (ASN1_VALUE *)0x0) goto LAB_08144a91;
      memset(pAVar6,0,param_2->size);
      asn1_do_lock(param_1,0,param_2);
      asn1_enc_init(param_1,param_2);
    }
    iVar7 = 0;
    tt = param_2->templates;
    if (0 < param_2->tcount) {
      do {
        pp_Var3 = (_STACK **)asn1_get_field_ptr(param_1,tt);
        uVar2 = tt->flags;
        if ((uVar2 & 1) == 0) {
          if ((uVar2 & 0x300) == 0) {
            if ((uVar2 & 6) == 0) {
              iVar5 = asn1_item_ex_combine_new();
              if (iVar5 == 0) goto LAB_08144a91;
            }
            else {
              p_Var4 = sk_new_null();
              if (p_Var4 == (_STACK *)0x0) {
                ERR_put_error(0xd,0x85,0x41,"tasn_new.c",0x115);
                goto LAB_08144a91;
              }
              *pp_Var3 = p_Var4;
            }
          }
          else {
LAB_08144c28:
            *pp_Var3 = (_STACK *)0x0;
          }
        }
        else {
          if ((uVar2 & 0x306) != 0) goto LAB_08144c28;
          asn1_item_clear();
        }
        tt = tt + 1;
        iVar7 = iVar7 + 1;
      } while (param_2->tcount != iVar7 && iVar7 <= param_2->tcount);
    }
    if (local_24 == (code *)0x0) {
      return 1;
    }
    goto LAB_08144b7b;
  case '\x02':
    iVar7 = (*local_24)(0,param_1,param_2,0);
    if (iVar7 == 0) goto LAB_08144b92;
    if (iVar7 == 2) {
      return 1;
    }
    if (param_3 == 0) {
      pAVar6 = (ASN1_VALUE *)CRYPTO_malloc(param_2->size,"tasn_new.c",0x9a);
      *param_1 = pAVar6;
      if (pAVar6 == (ASN1_VALUE *)0x0) goto LAB_08144a91;
      memset(pAVar6,0,param_2->size);
    }
    asn1_set_choice_selector(param_1,-1,param_2);
LAB_08144b7b:
    iVar7 = (*local_24)(1,param_1,param_2,0);
    if (iVar7 != 0) {
      return 1;
    }
LAB_08144b92:
    ERR_put_error(0xd,0x79,100,"tasn_new.c",0xd2);
    ASN1_item_ex_free(param_1,param_2);
    return 0;
  case '\x03':
switchD_08144a05_caseD_3:
    if (*ppcVar1 == (code *)0x0) {
      return 1;
    }
    pAVar6 = (ASN1_VALUE *)(**ppcVar1)();
    *param_1 = pAVar6;
    if (pAVar6 != (ASN1_VALUE *)0x0) {
      return 1;
    }
    goto LAB_08144a91;
  case '\x04':
switchD_08144a05_caseD_4:
    if (ppcVar1[1] == (code *)0x0) {
      return 1;
    }
    iVar7 = (*ppcVar1[1])(param_1,param_2);
    break;
  case '\x05':
    goto switchD_08144a70_caseD_5;
  }
joined_r0x08144b07:
  if (iVar7 != 0) {
    return 1;
  }
LAB_08144a91:
  ERR_put_error(0xd,0x79,0x41,"tasn_new.c",0xca);
  return 0;
switchD_08144a70_caseD_5:
  iVar7 = ASN1_primitive_new(param_1,param_2);
  goto joined_r0x08144b07;
}

