
void __regparm3 asn1_item_combine_free(_STACK **param_1,ASN1_ITEM *param_2,int param_3)

{
  char cVar1;
  void *pvVar2;
  int iVar3;
  _STACK *p_Var4;
  int iVar5;
  ASN1_TEMPLATE *tt;
  _STACK **pp_Var6;
  int iVar7;
  ASN1_TEMPLATE *pAVar8;
  int in_GS_OFFSET;
  int local_40;
  code *local_38;
  
  pvVar2 = param_2->funcs;
  iVar3 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_1 == (_STACK **)0x0) goto switchD_081458ee_caseD_0;
  cVar1 = param_2->itype;
  if (cVar1 != '\0') {
    if (*param_1 == (_STACK *)0x0) goto switchD_081458ee_caseD_0;
    if (pvVar2 != (void *)0x0) goto LAB_08145887;
    switch(cVar1) {
    default:
      goto switchD_081458ee_caseD_0;
    case '\x01':
    case '\x06':
      goto switchD_081458ee_caseD_1;
    case '\x02':
      goto switchD_081458ee_caseD_2;
    case '\x05':
      goto switchD_081458ee_caseD_5;
    }
  }
  if (pvVar2 == (void *)0x0) {
switchD_08145b50_caseD_0:
    if (param_2->templates != (ASN1_TEMPLATE *)0x0) {
      if ((param_2->templates->flags & 6) == 0) {
        asn1_item_combine_free();
      }
      else {
        p_Var4 = *param_1;
        for (iVar7 = 0; iVar5 = sk_num(p_Var4), iVar7 < iVar5; iVar7 = iVar7 + 1) {
          sk_value(p_Var4,iVar7);
          asn1_item_combine_free();
        }
        sk_free(p_Var4);
        *param_1 = (_STACK *)0x0;
      }
      goto switchD_081458ee_caseD_0;
    }
switchD_081458ee_caseD_5:
    ASN1_primitive_free((ASN1_VALUE **)param_1,param_2);
  }
  else {
LAB_08145887:
    local_38 = *(code **)((int)pvVar2 + 0x10);
    if (local_38 == (code *)0x0) {
      switch(cVar1) {
      case '\0':
        goto switchD_08145b50_caseD_0;
      case '\x01':
      case '\x06':
switchD_081458ee_caseD_1:
        iVar7 = asn1_do_lock((ASN1_VALUE **)param_1,-1,param_2);
        if (0 < iVar7) goto switchD_081458ee_caseD_0;
        asn1_enc_free((ASN1_VALUE **)param_1,param_2);
        pAVar8 = param_2->templates + param_2->tcount + -1;
        if (0 < param_2->tcount) {
          local_38 = (code *)0x0;
          goto LAB_08145a7a;
        }
        break;
      case '\x02':
switchD_081458ee_caseD_2:
        iVar7 = asn1_get_choice_selector((ASN1_VALUE **)param_1,param_2);
        if ((-1 < iVar7) && (local_38 = (code *)0x0, iVar7 < param_2->tcount)) {
LAB_08145bd5:
          pAVar8 = param_2->templates;
          pp_Var6 = (_STACK **)asn1_get_field_ptr((ASN1_VALUE **)param_1,pAVar8 + iVar7);
          if ((pAVar8[iVar7].flags & 6) == 0) {
            asn1_item_combine_free();
          }
          else {
            p_Var4 = *pp_Var6;
            for (iVar7 = 0; iVar5 = sk_num(p_Var4), iVar7 < iVar5; iVar7 = iVar7 + 1) {
              sk_value(p_Var4,iVar7);
              asn1_item_combine_free();
            }
            sk_free(p_Var4);
            *pp_Var6 = (_STACK *)0x0;
          }
joined_r0x08145c56:
          if (local_38 != (code *)0x0) goto LAB_0814592c;
        }
        break;
      case '\x03':
        goto switchD_08145b50_caseD_3;
      case '\x04':
        goto switchD_08145b50_caseD_4;
      case '\x05':
        goto switchD_081458ee_caseD_5;
      default:
        goto switchD_081458ee_caseD_0;
      }
    }
    else {
      switch(cVar1) {
      case '\0':
        goto switchD_08145b50_caseD_0;
      case '\x01':
      case '\x06':
        iVar7 = asn1_do_lock((ASN1_VALUE **)param_1,-1,param_2);
        if ((0 < iVar7) || (iVar7 = (*local_38)(2,param_1,param_2,0), iVar7 == 2))
        goto switchD_081458ee_caseD_0;
        asn1_enc_free((ASN1_VALUE **)param_1,param_2);
        pAVar8 = param_2->templates + param_2->tcount + -1;
        if (0 < param_2->tcount) {
LAB_08145a7a:
          local_40 = 0;
          do {
            tt = asn1_do_adb((ASN1_VALUE **)param_1,pAVar8,0);
            if (tt != (ASN1_TEMPLATE *)0x0) {
              pp_Var6 = (_STACK **)asn1_get_field_ptr((ASN1_VALUE **)param_1,tt);
              if ((tt->flags & 6) == 0) {
                asn1_item_combine_free();
              }
              else {
                p_Var4 = *pp_Var6;
                for (iVar7 = 0; iVar5 = sk_num(p_Var4), iVar7 < iVar5; iVar7 = iVar7 + 1) {
                  sk_value(p_Var4,iVar7);
                  asn1_item_combine_free();
                }
                sk_free(p_Var4);
                *pp_Var6 = (_STACK *)0x0;
              }
            }
            local_40 = local_40 + 1;
            pAVar8 = pAVar8 + -1;
          } while (param_2->tcount != local_40 && local_40 <= param_2->tcount);
          goto joined_r0x08145c56;
        }
        break;
      case '\x02':
        iVar7 = (*local_38)(2,param_1,param_2,0);
        if (iVar7 == 2) goto switchD_081458ee_caseD_0;
        iVar7 = asn1_get_choice_selector((ASN1_VALUE **)param_1,param_2);
        if ((-1 < iVar7) && (param_2->tcount != iVar7 && iVar7 <= param_2->tcount))
        goto LAB_08145bd5;
        break;
      case '\x03':
switchD_08145b50_caseD_3:
        if (*(code **)((int)pvVar2 + 4) != (code *)0x0) {
          (**(code **)((int)pvVar2 + 4))(*param_1);
        }
        goto switchD_081458ee_caseD_0;
      case '\x04':
switchD_08145b50_caseD_4:
        if (*(code **)((int)pvVar2 + 8) != (code *)0x0) {
          (**(code **)((int)pvVar2 + 8))(param_1,param_2);
        }
        goto switchD_081458ee_caseD_0;
      case '\x05':
        goto switchD_081458ee_caseD_5;
      default:
        goto switchD_081458ee_caseD_0;
      }
LAB_0814592c:
      (*local_38)(3,param_1,param_2,0);
    }
    if (param_3 == 0) {
      CRYPTO_free(*param_1);
      *param_1 = (_STACK *)0x0;
    }
  }
switchD_081458ee_caseD_0:
  if (iVar3 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

