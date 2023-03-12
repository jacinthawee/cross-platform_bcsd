
void ASN1_item_free(ASN1_VALUE *val,ASN1_ITEM *it)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  ASN1_ITEM *pAVar4;
  ASN1_VALUE **ppAVar5;
  int iVar6;
  ASN1_ITEM *pAVar7;
  int iVar8;
  ASN1_VALUE *pAVar9;
  ASN1_TEMPLATE *pAVar10;
  ASN1_ITEM_EXP *pAVar11;
  ASN1_ITEM *local_3c;
  ASN1_ITEM *local_34;
  long local_30;
  ASN1_TEMPLATE *local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  uVar2 = (uint)it->itype;
  pAVar7 = (ASN1_ITEM *)it->funcs;
  local_2c = *(ASN1_TEMPLATE **)PTR___stack_chk_guard_006aabf0;
  pAVar4 = (ASN1_ITEM *)val;
  local_34 = (ASN1_ITEM *)val;
  if (uVar2 != 0) {
    if (val == (ASN1_VALUE *)0x0) goto switchD_0055fb90_caseD_0;
    if (pAVar7 != (ASN1_ITEM *)0x0) goto LAB_0055fa60;
    switch(uVar2 & 0xff) {
    default:
      goto switchD_0055fb90_caseD_0;
    case 1:
    case 6:
      goto switchD_0055fb90_caseD_1;
    case 2:
      goto switchD_0055fb90_caseD_2;
    case 5:
      goto LAB_0055fc1c;
    }
  }
  if (pAVar7 == (ASN1_ITEM *)0x0) {
switchD_0055fdcc_caseD_0:
    pAVar10 = it->templates;
    if (pAVar10 != (ASN1_TEMPLATE *)0x0) {
      iVar8 = 0;
      if ((pAVar10->flags & 6) == 0) {
        pAVar7 = pAVar10->item;
        pAVar4 = (ASN1_ITEM *)&local_34;
        asn1_item_combine_free(pAVar4,pAVar7,pAVar10->flags & 0x400);
      }
      else {
        for (; iVar3 = (*(code *)PTR_sk_num_006a7f2c)(val), iVar8 < iVar3; iVar8 = iVar8 + 1) {
          local_30 = (*(code *)PTR_sk_value_006a7f24)(val,iVar8);
          pAVar7 = pAVar10->item;
          asn1_item_combine_free(&local_30,pAVar7,0);
        }
        (*(code *)PTR_sk_free_006a7f80)();
        pAVar4 = (ASN1_ITEM *)val;
      }
      goto switchD_0055fb90_caseD_0;
    }
LAB_0055fc1c:
    pAVar4 = (ASN1_ITEM *)&local_34;
    ASN1_primitive_free((ASN1_VALUE **)pAVar4,it);
    pAVar7 = it;
  }
  else {
LAB_0055fa60:
    pAVar11 = (ASN1_ITEM_EXP *)pAVar7->funcs;
    if (pAVar11 == (ASN1_ITEM_EXP *)0x0) {
      switch(uVar2 & 0xff) {
      case 0:
        goto switchD_0055fdcc_caseD_0;
      case 1:
      case 6:
switchD_0055fb90_caseD_1:
        pAVar7 = (ASN1_ITEM *)0xffffffff;
        pAVar4 = (ASN1_ITEM *)&local_34;
        iVar8 = asn1_do_lock((ASN1_VALUE **)(ASN1_ITEM *)&local_34,-1,it);
        if (0 < iVar8) goto switchD_0055fb90_caseD_0;
        pAVar7 = it;
        asn1_enc_free((ASN1_VALUE **)(ASN1_ITEM *)&local_34,it);
        if (0 < it->tcount) {
          pAVar11 = (ASN1_ITEM_EXP *)0x0;
          local_3c = (ASN1_ITEM *)(it->templates + it->tcount + -1);
LAB_0055fcc4:
          iVar8 = 0;
          do {
            pAVar7 = local_3c;
            pAVar4 = (ASN1_ITEM *)asn1_do_adb((ASN1_VALUE **)&local_34,(ASN1_TEMPLATE *)local_3c,0);
            if (pAVar4 != (ASN1_ITEM *)0x0) {
              pAVar7 = pAVar4;
              ppAVar5 = asn1_get_field_ptr((ASN1_VALUE **)&local_34,(ASN1_TEMPLATE *)pAVar4);
              if ((*(uint *)pAVar4 & 6) == 0) {
                pAVar7 = (ASN1_ITEM *)pAVar4->funcs;
                asn1_item_combine_free(ppAVar5,pAVar7,*(uint *)pAVar4 & 0x400);
              }
              else {
                pAVar9 = *ppAVar5;
                for (iVar3 = 0; iVar6 = (*(code *)PTR_sk_num_006a7f2c)(pAVar9), iVar3 < iVar6;
                    iVar3 = iVar3 + 1) {
                  local_30 = (*(code *)PTR_sk_value_006a7f24)(pAVar9,iVar3);
                  pAVar7 = (ASN1_ITEM *)pAVar4->funcs;
                  asn1_item_combine_free(&local_30,pAVar7,0);
                }
                (*(code *)PTR_sk_free_006a7f80)(pAVar9);
                *ppAVar5 = (ASN1_VALUE *)0x0;
              }
            }
            iVar8 = iVar8 + 1;
            local_3c = (ASN1_ITEM *)&local_3c[-1].templates;
          } while (iVar8 < it->tcount);
          goto joined_r0x0055ff4c;
        }
        break;
      case 2:
switchD_0055fb90_caseD_2:
        pAVar7 = it;
        iVar8 = asn1_get_choice_selector((ASN1_VALUE **)&local_34,it);
        if ((-1 < iVar8) && (iVar8 < it->tcount)) {
          pAVar11 = (ASN1_ITEM_EXP *)0x0;
LAB_0055fe08:
          pAVar4 = (ASN1_ITEM *)(it->templates + iVar8);
          pAVar7 = pAVar4;
          ppAVar5 = asn1_get_field_ptr((ASN1_VALUE **)&local_34,(ASN1_TEMPLATE *)pAVar4);
          if ((*(uint *)pAVar4 & 6) == 0) {
            pAVar7 = (ASN1_ITEM *)pAVar4->funcs;
            asn1_item_combine_free(ppAVar5,pAVar7,*(uint *)pAVar4 & 0x400);
          }
          else {
            pAVar9 = *ppAVar5;
            for (iVar8 = 0; iVar3 = (*(code *)PTR_sk_num_006a7f2c)(pAVar9), iVar8 < iVar3;
                iVar8 = iVar8 + 1) {
              local_30 = (*(code *)PTR_sk_value_006a7f24)(pAVar9,iVar8);
              pAVar7 = (ASN1_ITEM *)pAVar4->funcs;
              asn1_item_combine_free(&local_30,pAVar7,0);
            }
            (*(code *)PTR_sk_free_006a7f80)(pAVar9);
            *ppAVar5 = (ASN1_VALUE *)0x0;
          }
joined_r0x0055ff4c:
          if (pAVar11 != (ASN1_ITEM_EXP *)0x0) goto LAB_0055fbec;
        }
        break;
      case 3:
        goto switchD_0055fdcc_caseD_3;
      case 4:
        goto switchD_0055fdcc_caseD_4;
      case 5:
        goto LAB_0055fc1c;
      default:
        goto switchD_0055fb90_caseD_0;
      }
    }
    else {
      switch(uVar2 & 0xff) {
      case 0:
        goto switchD_0055fdcc_caseD_0;
      case 1:
      case 6:
        pAVar7 = (ASN1_ITEM *)0xffffffff;
        pAVar4 = (ASN1_ITEM *)&local_34;
        iVar8 = asn1_do_lock((ASN1_VALUE **)(ASN1_ITEM *)&local_34,-1,it);
        if (0 < iVar8) goto switchD_0055fb90_caseD_0;
        pAVar4 = (ASN1_ITEM *)&SUB_00000002;
        pAVar7 = (ASN1_ITEM *)&local_34;
        iVar8 = (*(code *)pAVar11)(2,(ASN1_ITEM *)&local_34,it,0);
        if (iVar8 == 2) goto switchD_0055fb90_caseD_0;
        asn1_enc_free((ASN1_VALUE **)(ASN1_ITEM *)&local_34,it);
        local_3c = (ASN1_ITEM *)(it->templates + it->tcount + -1);
        if (0 < it->tcount) goto LAB_0055fcc4;
        break;
      case 2:
        pAVar4 = (ASN1_ITEM *)&SUB_00000002;
        pAVar7 = (ASN1_ITEM *)&local_34;
        iVar8 = (*(code *)pAVar11)(2,(ASN1_ITEM *)&local_34,it,0);
        if (iVar8 == 2) goto switchD_0055fb90_caseD_0;
        iVar8 = asn1_get_choice_selector((ASN1_VALUE **)(ASN1_ITEM *)&local_34,it);
        if ((-1 < iVar8) && (iVar8 < it->tcount)) goto LAB_0055fe08;
        break;
      case 3:
switchD_0055fdcc_caseD_3:
        if ((code *)pAVar7->utype != (code *)0x0) {
          (*(code *)pAVar7->utype)();
          pAVar4 = (ASN1_ITEM *)val;
        }
        goto switchD_0055fb90_caseD_0;
      case 4:
switchD_0055fdcc_caseD_4:
        pAVar4 = (ASN1_ITEM *)&local_34;
        if (pAVar7->templates != (ASN1_TEMPLATE *)0x0) {
          (*(code *)pAVar7->templates)();
          pAVar7 = it;
        }
        goto switchD_0055fb90_caseD_0;
      case 5:
        goto LAB_0055fc1c;
      default:
        goto switchD_0055fb90_caseD_0;
      }
LAB_0055fbec:
      pAVar7 = (ASN1_ITEM *)&local_34;
      (*(code *)pAVar11)(3,pAVar7,it,0);
    }
    pAVar4 = local_34;
    (*(code *)PTR_CRYPTO_free_006a7f88)();
  }
switchD_0055fb90_caseD_0:
  if (local_2c == *(ASN1_TEMPLATE **)puVar1) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar8 = pAVar4->utype;
  if (pAVar7->utype <= pAVar4->utype) {
    iVar8 = pAVar7->utype;
  }
  (*(code *)PTR_memcmp_006aabd8)(*(undefined4 *)pAVar4,*(undefined4 *)pAVar7,iVar8);
  return;
}

