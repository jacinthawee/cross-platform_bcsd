
undefined4 __regparm3 asn1_item_ex_combine_new(ASN1_VALUE **param_1,ASN1_ITEM *param_2,int param_3)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  _STACK **pp_Var4;
  _STACK *p_Var5;
  int iVar6;
  ASN1_VALUE *pAVar7;
  ASN1_TEMPLATE *tt;
  code *local_24;
  
  if (param_2->funcs == (void *)0x0) {
    local_24 = (code *)0x0;
  }
  else {
    local_24 = *(code **)((int)param_2->funcs + 0x10);
  }
  if (param_3 == 0) {
    *param_1 = (ASN1_VALUE *)0x0;
  }
  if (6 < (byte)param_2->itype) {
    return 1;
  }
  switch(param_2->itype) {
  case '\0':
    if (param_2->templates == (ASN1_TEMPLATE *)0x0) goto switchD_081475c1_caseD_5;
    pAVar7 = (ASN1_VALUE *)ASN1_template_new(param_1,param_2->templates);
    break;
  default:
    if (local_24 != (code *)0x0) {
      iVar3 = (*local_24)(0,param_1,param_2,0);
      if (iVar3 == 0) goto LAB_08147782;
      if (iVar3 == 2) {
        return 1;
      }
    }
    if (param_3 == 0) {
      pAVar7 = (ASN1_VALUE *)CRYPTO_malloc(param_2->size,"tasn_new.c",0xbf);
      *param_1 = pAVar7;
      if (pAVar7 == (ASN1_VALUE *)0x0) goto LAB_08147639;
      memset(pAVar7,0,param_2->size);
      asn1_do_lock(param_1,0,param_2);
      asn1_enc_init(param_1,param_2);
    }
    iVar3 = 0;
    tt = param_2->templates;
    if (0 < param_2->tcount) {
      do {
        pp_Var4 = (_STACK **)asn1_get_field_ptr(param_1,tt);
        uVar1 = tt->flags;
        if ((uVar1 & 1) == 0) {
          if ((uVar1 & 0x300) == 0) {
            if ((uVar1 & 6) == 0) {
              iVar6 = asn1_item_ex_combine_new();
              if (iVar6 == 0) goto LAB_08147639;
            }
            else {
              p_Var5 = sk_new_null();
              if (p_Var5 == (_STACK *)0x0) {
                ERR_put_error(0xd,0x85,0x41,"tasn_new.c",0x125);
                goto LAB_08147639;
              }
              *pp_Var4 = p_Var5;
            }
          }
          else {
LAB_081476dc:
            *pp_Var4 = (_STACK *)0x0;
          }
        }
        else {
          if ((uVar1 & 0x306) != 0) goto LAB_081476dc;
          asn1_item_clear();
        }
        tt = tt + 1;
        iVar3 = iVar3 + 1;
      } while (param_2->tcount != iVar3 && iVar3 <= param_2->tcount);
    }
    if (local_24 == (code *)0x0) {
      return 1;
    }
    goto LAB_0814776b;
  case '\x02':
    if (local_24 == (code *)0x0) {
      if (param_3 == 0) {
        pAVar7 = (ASN1_VALUE *)CRYPTO_malloc(param_2->size,"tasn_new.c",0xa3);
        *param_1 = pAVar7;
        if (pAVar7 == (ASN1_VALUE *)0x0) goto LAB_08147639;
        memset(pAVar7,0,param_2->size);
      }
      asn1_set_choice_selector(param_1,-1,param_2);
      return 1;
    }
    iVar3 = (*local_24)(0,param_1,param_2,0);
    if (iVar3 == 0) goto LAB_08147782;
    if (iVar3 == 2) {
      return 1;
    }
    if (param_3 == 0) {
      pAVar7 = (ASN1_VALUE *)CRYPTO_malloc(param_2->size,"tasn_new.c",0xa3);
      *param_1 = pAVar7;
      if (pAVar7 == (ASN1_VALUE *)0x0) goto LAB_08147639;
      memset(pAVar7,0,param_2->size);
    }
    asn1_set_choice_selector(param_1,-1,param_2);
LAB_0814776b:
    iVar3 = (*local_24)(1,param_1,param_2,0);
    if (iVar3 != 0) {
      return 1;
    }
LAB_08147782:
    ERR_put_error(0xd,0x79,100,"tasn_new.c",0xdd);
    ASN1_item_ex_free(param_1,param_2);
    return 0;
  case '\x03':
    if ((code **)param_2->funcs == (code **)0x0) {
      return 1;
    }
                    /* WARNING: Load size is inaccurate */
    pcVar2 = *param_2->funcs;
    if (pcVar2 == (code *)0x0) {
      return 1;
    }
    pAVar7 = (ASN1_VALUE *)(*pcVar2)();
    *param_1 = pAVar7;
    break;
  case '\x04':
    if (param_2->funcs == (void *)0x0) {
      return 1;
    }
    pcVar2 = *(code **)((int)param_2->funcs + 4);
    if (pcVar2 == (code *)0x0) {
      return 1;
    }
    iVar3 = (*pcVar2)(param_1,param_2);
    if (iVar3 != 0) {
      return 1;
    }
    goto LAB_08147639;
  case '\x05':
switchD_081475c1_caseD_5:
    pAVar7 = (ASN1_VALUE *)ASN1_primitive_new(param_1,param_2);
  }
  if (pAVar7 != (ASN1_VALUE *)0x0) {
    return 1;
  }
LAB_08147639:
  ERR_put_error(0xd,0x79,0x41,"tasn_new.c",0xd6);
  return 0;
}

