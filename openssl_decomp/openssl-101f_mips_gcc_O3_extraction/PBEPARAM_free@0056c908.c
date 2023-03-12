
void PBEPARAM_free(PBEPARAM *a)

{
  uint *puVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  ASN1_ITEM_EXP *pAVar5;
  ASN1_VALUE **ppAVar6;
  int iVar7;
  ASN1_ITEM_EXP *pAVar8;
  undefined1 *puVar9;
  int iVar10;
  ASN1_VALUE *pAVar11;
  ASN1_ITEM_EXP *pAVar12;
  ASN1_ITEM_EXP *pAStack_3c;
  ASN1_ITEM_EXP *pAStack_34;
  undefined4 uStack_30;
  int iStack_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  puVar1 = PBEPARAM_it._8_4_;
  puVar9 = PBEPARAM_it;
  uVar3 = (uint)PBEPARAM_it[0];
  iStack_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  pAVar5 = (ASN1_ITEM_EXP *)a;
  pAVar8 = PBEPARAM_it._16_4_;
  pAStack_34 = (ASN1_ITEM_EXP *)a;
  if (uVar3 != 0) {
    if (a == (PBEPARAM *)0x0) goto switchD_0055fb90_caseD_0;
    if (PBEPARAM_it._16_4_ != (ASN1_ITEM_EXP *)0x0) goto LAB_0055fa60;
    switch(uVar3 & 0xff) {
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
  if (PBEPARAM_it._16_4_ == (ASN1_ITEM_EXP *)0x0) {
switchD_0055fdcc_caseD_0:
    if (PBEPARAM_it._8_4_ != (uint *)0x0) {
      iVar10 = 0;
      if ((*PBEPARAM_it._8_4_ & 6) == 0) {
        pAVar8 = (ASN1_ITEM_EXP *)PBEPARAM_it._8_4_[4];
        pAVar5 = (ASN1_ITEM_EXP *)&pAStack_34;
        asn1_item_combine_free(pAVar5,pAVar8,*PBEPARAM_it._8_4_ & 0x400);
      }
      else {
        for (; iVar4 = (*(code *)PTR_sk_num_006a7f2c)(a), iVar10 < iVar4; iVar10 = iVar10 + 1) {
          uStack_30 = (*(code *)PTR_sk_value_006a7f24)(a,iVar10);
          pAVar8 = (ASN1_ITEM_EXP *)puVar1[4];
          asn1_item_combine_free(&uStack_30,pAVar8,0);
        }
        (*(code *)PTR_sk_free_006a7f80)();
        pAVar5 = (ASN1_ITEM_EXP *)a;
      }
      goto switchD_0055fb90_caseD_0;
    }
LAB_0055fc1c:
    pAVar5 = (ASN1_ITEM_EXP *)&pAStack_34;
    ASN1_primitive_free((ASN1_VALUE **)pAVar5,(ASN1_ITEM *)PBEPARAM_it);
    pAVar8 = (ASN1_ITEM_EXP *)puVar9;
  }
  else {
LAB_0055fa60:
    pAVar12 = *(ASN1_ITEM_EXP **)&(PBEPARAM_it._16_4_)->field_0x10;
    if (pAVar12 == (ASN1_ITEM_EXP *)0x0) {
      switch(uVar3 & 0xff) {
      case 0:
        goto switchD_0055fdcc_caseD_0;
      case 1:
      case 6:
switchD_0055fb90_caseD_1:
        pAVar8 = (ASN1_ITEM_EXP *)0xffffffff;
        pAVar5 = (ASN1_ITEM_EXP *)&pAStack_34;
        iVar10 = asn1_do_lock((ASN1_VALUE **)(ASN1_ITEM_EXP *)&pAStack_34,-1,
                              (ASN1_ITEM *)PBEPARAM_it);
        if (0 < iVar10) goto switchD_0055fb90_caseD_0;
        asn1_enc_free((ASN1_VALUE **)(ASN1_ITEM_EXP *)&pAStack_34,(ASN1_ITEM *)PBEPARAM_it);
        if (0 < PBEPARAM_it._12_4_) {
          pAVar12 = (ASN1_ITEM_EXP *)0x0;
          pAStack_3c = (ASN1_ITEM_EXP *)(PBEPARAM_it._8_4_ + PBEPARAM_it._12_4_ * 5 + -5);
LAB_0055fcc4:
          iVar10 = 0;
          do {
            puVar9 = (undefined1 *)pAStack_3c;
            pAVar5 = (ASN1_ITEM_EXP *)
                     asn1_do_adb((ASN1_VALUE **)&pAStack_34,(ASN1_TEMPLATE *)pAStack_3c,0);
            if (pAVar5 != (ASN1_ITEM_EXP *)0x0) {
              puVar9 = (undefined1 *)pAVar5;
              ppAVar6 = asn1_get_field_ptr((ASN1_VALUE **)&pAStack_34,(ASN1_TEMPLATE *)pAVar5);
              if ((*(uint *)pAVar5 & 6) == 0) {
                puVar9 = *(undefined1 **)&pAVar5->field_0x10;
                asn1_item_combine_free(ppAVar6,puVar9,*(uint *)pAVar5 & 0x400);
              }
              else {
                pAVar11 = *ppAVar6;
                for (iVar4 = 0; iVar7 = (*(code *)PTR_sk_num_006a7f2c)(pAVar11), iVar4 < iVar7;
                    iVar4 = iVar4 + 1) {
                  uStack_30 = (*(code *)PTR_sk_value_006a7f24)(pAVar11,iVar4);
                  puVar9 = *(undefined1 **)&pAVar5->field_0x10;
                  asn1_item_combine_free(&uStack_30,puVar9,0);
                }
                (*(code *)PTR_sk_free_006a7f80)(pAVar11);
                *ppAVar6 = (ASN1_VALUE *)0x0;
              }
            }
            iVar10 = iVar10 + 1;
            pAStack_3c = (ASN1_ITEM_EXP *)&pAStack_3c[-1].field_0x8;
          } while (iVar10 < PBEPARAM_it._12_4_);
          goto joined_r0x0055ff4c;
        }
        break;
      case 2:
switchD_0055fb90_caseD_2:
        iVar10 = asn1_get_choice_selector((ASN1_VALUE **)&pAStack_34,(ASN1_ITEM *)PBEPARAM_it);
        if ((-1 < iVar10) && (iVar10 < PBEPARAM_it._12_4_)) {
          pAVar12 = (ASN1_ITEM_EXP *)0x0;
LAB_0055fe08:
          pAVar5 = (ASN1_ITEM_EXP *)(PBEPARAM_it._8_4_ + iVar10 * 5);
          puVar9 = (undefined1 *)pAVar5;
          ppAVar6 = asn1_get_field_ptr((ASN1_VALUE **)&pAStack_34,(ASN1_TEMPLATE *)pAVar5);
          if ((*(uint *)pAVar5 & 6) == 0) {
            puVar9 = *(undefined1 **)&pAVar5->field_0x10;
            asn1_item_combine_free(ppAVar6,puVar9,*(uint *)pAVar5 & 0x400);
          }
          else {
            pAVar11 = *ppAVar6;
            for (iVar10 = 0; iVar4 = (*(code *)PTR_sk_num_006a7f2c)(pAVar11), iVar10 < iVar4;
                iVar10 = iVar10 + 1) {
              uStack_30 = (*(code *)PTR_sk_value_006a7f24)(pAVar11,iVar10);
              puVar9 = *(undefined1 **)&pAVar5->field_0x10;
              asn1_item_combine_free(&uStack_30,puVar9,0);
            }
            (*(code *)PTR_sk_free_006a7f80)(pAVar11);
            *ppAVar6 = (ASN1_VALUE *)0x0;
          }
joined_r0x0055ff4c:
          if (pAVar12 != (ASN1_ITEM_EXP *)0x0) goto LAB_0055fbec;
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
      switch(uVar3 & 0xff) {
      case 0:
        goto switchD_0055fdcc_caseD_0;
      case 1:
      case 6:
        pAVar8 = (ASN1_ITEM_EXP *)0xffffffff;
        pAVar5 = (ASN1_ITEM_EXP *)&pAStack_34;
        iVar10 = asn1_do_lock((ASN1_VALUE **)(ASN1_ITEM_EXP *)&pAStack_34,-1,
                              (ASN1_ITEM *)PBEPARAM_it);
        if (0 < iVar10) goto switchD_0055fb90_caseD_0;
        pAVar5 = (ASN1_ITEM_EXP *)&SUB_00000002;
        pAVar8 = (ASN1_ITEM_EXP *)&pAStack_34;
        iVar10 = (*(code *)pAVar12)(2,(ASN1_ITEM_EXP *)&pAStack_34,PBEPARAM_it,0);
        if (iVar10 == 2) goto switchD_0055fb90_caseD_0;
        asn1_enc_free((ASN1_VALUE **)(ASN1_ITEM_EXP *)&pAStack_34,(ASN1_ITEM *)PBEPARAM_it);
        pAStack_3c = (ASN1_ITEM_EXP *)(PBEPARAM_it._8_4_ + PBEPARAM_it._12_4_ * 5 + -5);
        if (0 < PBEPARAM_it._12_4_) goto LAB_0055fcc4;
        break;
      case 2:
        pAVar5 = (ASN1_ITEM_EXP *)&SUB_00000002;
        pAVar8 = (ASN1_ITEM_EXP *)&pAStack_34;
        iVar10 = (*(code *)pAVar12)(2,(ASN1_ITEM_EXP *)&pAStack_34,PBEPARAM_it,0);
        if (iVar10 == 2) goto switchD_0055fb90_caseD_0;
        iVar10 = asn1_get_choice_selector
                           ((ASN1_VALUE **)(ASN1_ITEM_EXP *)&pAStack_34,(ASN1_ITEM *)PBEPARAM_it);
        if ((-1 < iVar10) && (iVar10 < PBEPARAM_it._12_4_)) goto LAB_0055fe08;
        break;
      case 3:
switchD_0055fdcc_caseD_3:
        if (*(code **)&(PBEPARAM_it._16_4_)->field_0x4 != (code *)0x0) {
          (**(code **)&(PBEPARAM_it._16_4_)->field_0x4)();
          pAVar5 = (ASN1_ITEM_EXP *)a;
        }
        goto switchD_0055fb90_caseD_0;
      case 4:
switchD_0055fdcc_caseD_4:
        pAVar5 = (ASN1_ITEM_EXP *)&pAStack_34;
        if (*(code **)&(PBEPARAM_it._16_4_)->field_0x8 != (code *)0x0) {
          (**(code **)&(PBEPARAM_it._16_4_)->field_0x8)();
          pAVar8 = (ASN1_ITEM_EXP *)puVar9;
        }
        goto switchD_0055fb90_caseD_0;
      case 5:
        goto LAB_0055fc1c;
      default:
        goto switchD_0055fb90_caseD_0;
      }
LAB_0055fbec:
      puVar9 = (undefined1 *)&pAStack_34;
      (*(code *)pAVar12)(3,puVar9,PBEPARAM_it,0);
    }
    pAVar5 = pAStack_34;
    (*(code *)PTR_CRYPTO_free_006a7f88)();
    pAVar8 = (ASN1_ITEM_EXP *)puVar9;
  }
switchD_0055fb90_caseD_0:
  if (iStack_2c == *(int *)puVar2) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar10 = *(int *)&pAVar5->field_0x4;
  if (*(int *)&pAVar8->field_0x4 <= *(int *)&pAVar5->field_0x4) {
    iVar10 = *(int *)&pAVar8->field_0x4;
  }
  (*(code *)PTR_memcmp_006aabd8)(*(undefined4 *)pAVar5,*(undefined4 *)pAVar8,iVar10);
  return;
}

