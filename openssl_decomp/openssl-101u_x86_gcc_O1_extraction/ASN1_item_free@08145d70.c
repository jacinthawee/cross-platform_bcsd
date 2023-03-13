
void ASN1_item_free(ASN1_VALUE *val,ASN1_ITEM *it)

{
  char cVar1;
  void *pvVar2;
  _STACK *p_Var3;
  int iVar4;
  ASN1_TEMPLATE *tt;
  _STACK **pp_Var5;
  int iVar6;
  ASN1_TEMPLATE *pAVar7;
  int in_GS_OFFSET;
  int local_44;
  code *local_40;
  ASN1_VALUE **local_3c;
  ASN1_VALUE *local_30 [3];
  void *local_24;
  int local_20;
  
  local_30[0] = val;
  pvVar2 = it->funcs;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  cVar1 = it->itype;
  if (cVar1 != '\0') {
    if (val == (ASN1_VALUE *)0x0) goto switchD_08145e80_caseD_0;
    if (pvVar2 != (void *)0x0) goto LAB_08145daa;
    switch(cVar1) {
    default:
      goto switchD_08145e80_caseD_0;
    case '\x01':
    case '\x06':
      goto switchD_08145e80_caseD_1;
    case '\x02':
      goto switchD_08145e80_caseD_2;
    case '\x05':
      goto switchD_08145e80_caseD_5;
    }
  }
  if (pvVar2 == (void *)0x0) {
switchD_08146060_caseD_0:
    if (it->templates != (ASN1_TEMPLATE *)0x0) {
      if ((it->templates->flags & 6) == 0) {
        asn1_item_combine_free();
      }
      else {
        for (iVar6 = 0; iVar4 = sk_num((_STACK *)val), iVar6 < iVar4; iVar6 = iVar6 + 1) {
          local_24 = sk_value((_STACK *)val,iVar6);
          asn1_item_combine_free();
        }
        sk_free((_STACK *)val);
      }
      goto switchD_08145e80_caseD_0;
    }
switchD_08145e80_caseD_5:
    ASN1_primitive_free(local_30,it);
  }
  else {
LAB_08145daa:
    local_40 = *(code **)((int)pvVar2 + 0x10);
    if (local_40 == (code *)0x0) {
      switch(cVar1) {
      case '\0':
        goto switchD_08146060_caseD_0;
      case '\x01':
      case '\x06':
switchD_08145e80_caseD_1:
        iVar6 = asn1_do_lock(local_30,-1,it);
        if (0 < iVar6) goto switchD_08145e80_caseD_0;
        asn1_enc_free(local_30,it);
        if (0 < it->tcount) {
          local_40 = (code *)0x0;
          pAVar7 = it->templates + it->tcount + -1;
          goto LAB_08145f8f;
        }
        break;
      case '\x02':
switchD_08145e80_caseD_2:
        iVar6 = asn1_get_choice_selector(local_30,it);
        if ((-1 < iVar6) && (iVar6 < it->tcount)) {
          local_40 = (code *)0x0;
LAB_08146098:
          local_3c = local_30;
          pAVar7 = it->templates;
          pp_Var5 = (_STACK **)asn1_get_field_ptr(local_3c,pAVar7 + iVar6);
          if ((pAVar7[iVar6].flags & 6) == 0) {
            asn1_item_combine_free();
          }
          else {
            p_Var3 = *pp_Var5;
            for (iVar6 = 0; iVar4 = sk_num(p_Var3), iVar6 < iVar4; iVar6 = iVar6 + 1) {
              local_24 = sk_value(p_Var3,iVar6);
              asn1_item_combine_free();
            }
            sk_free(p_Var3);
            *pp_Var5 = (_STACK *)0x0;
          }
LAB_08146043:
          if (local_40 != (code *)0x0) goto LAB_08145ecd;
        }
        break;
      case '\x03':
        goto switchD_08146060_caseD_3;
      case '\x04':
        goto switchD_08146060_caseD_4;
      case '\x05':
        goto switchD_08145e80_caseD_5;
      default:
        goto switchD_08145e80_caseD_0;
      }
    }
    else {
      switch(cVar1) {
      case '\0':
        goto switchD_08146060_caseD_0;
      case '\x01':
      case '\x06':
        iVar6 = asn1_do_lock(local_30,-1,it);
        if ((0 < iVar6) || (iVar6 = (*local_40)(2,local_30,it,0), iVar6 == 2))
        goto switchD_08145e80_caseD_0;
        asn1_enc_free(local_30,it);
        pAVar7 = it->templates + it->tcount + -1;
        if (0 < it->tcount) {
LAB_08145f8f:
          local_3c = local_30;
          local_44 = 0;
          do {
            tt = asn1_do_adb(local_3c,pAVar7,0);
            if (tt != (ASN1_TEMPLATE *)0x0) {
              pp_Var5 = (_STACK **)asn1_get_field_ptr(local_3c,tt);
              if ((tt->flags & 6) == 0) {
                asn1_item_combine_free();
              }
              else {
                p_Var3 = *pp_Var5;
                for (iVar6 = 0; iVar4 = sk_num(p_Var3), iVar6 < iVar4; iVar6 = iVar6 + 1) {
                  local_24 = sk_value(p_Var3,iVar6);
                  asn1_item_combine_free();
                }
                sk_free(p_Var3);
                *pp_Var5 = (_STACK *)0x0;
              }
            }
            local_44 = local_44 + 1;
            pAVar7 = pAVar7 + -1;
          } while (local_44 < it->tcount);
          goto LAB_08146043;
        }
        break;
      case '\x02':
        iVar6 = (*local_40)(2,local_30,it,0);
        if (iVar6 == 2) goto switchD_08145e80_caseD_0;
        iVar6 = asn1_get_choice_selector(local_30,it);
        if ((-1 < iVar6) && (iVar6 < it->tcount)) goto LAB_08146098;
        break;
      case '\x03':
switchD_08146060_caseD_3:
        if (*(code **)((int)pvVar2 + 4) != (code *)0x0) {
          (**(code **)((int)pvVar2 + 4))(val);
        }
        goto switchD_08145e80_caseD_0;
      case '\x04':
switchD_08146060_caseD_4:
        if (*(code **)((int)pvVar2 + 8) != (code *)0x0) {
          (**(code **)((int)pvVar2 + 8))(local_30,it);
        }
        goto switchD_08145e80_caseD_0;
      case '\x05':
        goto switchD_08145e80_caseD_5;
      default:
        goto switchD_08145e80_caseD_0;
      }
LAB_08145ecd:
      local_3c = local_30;
      (*local_40)(3,local_3c,it,0);
    }
    CRYPTO_free(local_30[0]);
  }
switchD_08145e80_caseD_0:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

