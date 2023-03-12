
int NETSCAPE_ENCRYPTED_PKEY_free(ASN1_ITEM_EXP *param_1)

{
  uint *puVar1;
  undefined *puVar2;
  uint uVar3;
  ASN1_VALUE **ppAVar4;
  int iVar5;
  ASN1_ITEM_EXP *pAVar6;
  undefined1 *puVar7;
  ASN1_VALUE *pAVar8;
  int iVar9;
  int iVar10;
  ASN1_ITEM_EXP *pAVar11;
  ASN1_ITEM_EXP *pAStack_3c;
  ASN1_ITEM_EXP *pAStack_34;
  undefined4 uStack_30;
  int iStack_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  puVar1 = NETSCAPE_ENCRYPTED_PKEY_it._8_4_;
  puVar7 = NETSCAPE_ENCRYPTED_PKEY_it;
  uVar3 = (uint)NETSCAPE_ENCRYPTED_PKEY_it[0];
  iStack_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  pAVar6 = NETSCAPE_ENCRYPTED_PKEY_it._16_4_;
  pAStack_34 = param_1;
  if (uVar3 != 0) {
    if (param_1 == (ASN1_ITEM_EXP *)0x0) goto switchD_0055fb90_caseD_0;
    if (NETSCAPE_ENCRYPTED_PKEY_it._16_4_ != (ASN1_ITEM_EXP *)0x0) goto LAB_0055fa60;
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
  if (NETSCAPE_ENCRYPTED_PKEY_it._16_4_ == (ASN1_ITEM_EXP *)0x0) {
switchD_0055fdcc_caseD_0:
    if (NETSCAPE_ENCRYPTED_PKEY_it._8_4_ != (uint *)0x0) {
      iVar5 = 0;
      if ((*NETSCAPE_ENCRYPTED_PKEY_it._8_4_ & 6) == 0) {
        pAVar6 = (ASN1_ITEM_EXP *)NETSCAPE_ENCRYPTED_PKEY_it._8_4_[4];
        param_1 = (ASN1_ITEM_EXP *)&pAStack_34;
        asn1_item_combine_free(param_1,pAVar6,*NETSCAPE_ENCRYPTED_PKEY_it._8_4_ & 0x400);
      }
      else {
        for (; iVar9 = (*(code *)PTR_sk_num_006a7f2c)(param_1), iVar5 < iVar9; iVar5 = iVar5 + 1) {
          uStack_30 = (*(code *)PTR_sk_value_006a7f24)(param_1,iVar5);
          pAVar6 = (ASN1_ITEM_EXP *)puVar1[4];
          asn1_item_combine_free(&uStack_30,pAVar6,0);
        }
        (*(code *)PTR_sk_free_006a7f80)();
      }
      goto switchD_0055fb90_caseD_0;
    }
LAB_0055fc1c:
    param_1 = (ASN1_ITEM_EXP *)&pAStack_34;
    ASN1_primitive_free((ASN1_VALUE **)param_1,(ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
    pAVar6 = (ASN1_ITEM_EXP *)puVar7;
  }
  else {
LAB_0055fa60:
    pAVar11 = *(ASN1_ITEM_EXP **)&(NETSCAPE_ENCRYPTED_PKEY_it._16_4_)->field_0x10;
    if (pAVar11 == (ASN1_ITEM_EXP *)0x0) {
      switch(uVar3 & 0xff) {
      case 0:
        goto switchD_0055fdcc_caseD_0;
      case 1:
      case 6:
switchD_0055fb90_caseD_1:
        pAVar6 = (ASN1_ITEM_EXP *)0xffffffff;
        param_1 = (ASN1_ITEM_EXP *)&pAStack_34;
        iVar5 = asn1_do_lock((ASN1_VALUE **)(ASN1_ITEM_EXP *)&pAStack_34,-1,
                             (ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
        if (0 < iVar5) goto switchD_0055fb90_caseD_0;
        asn1_enc_free((ASN1_VALUE **)(ASN1_ITEM_EXP *)&pAStack_34,
                      (ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
        if (0 < NETSCAPE_ENCRYPTED_PKEY_it._12_4_) {
          pAVar11 = (ASN1_ITEM_EXP *)0x0;
          pAStack_3c = (ASN1_ITEM_EXP *)
                       (NETSCAPE_ENCRYPTED_PKEY_it._8_4_ +
                       NETSCAPE_ENCRYPTED_PKEY_it._12_4_ * 5 + -5);
LAB_0055fcc4:
          iVar5 = 0;
          do {
            puVar7 = (undefined1 *)pAStack_3c;
            pAVar6 = (ASN1_ITEM_EXP *)
                     asn1_do_adb((ASN1_VALUE **)&pAStack_34,(ASN1_TEMPLATE *)pAStack_3c,0);
            if (pAVar6 != (ASN1_ITEM_EXP *)0x0) {
              puVar7 = (undefined1 *)pAVar6;
              ppAVar4 = asn1_get_field_ptr((ASN1_VALUE **)&pAStack_34,(ASN1_TEMPLATE *)pAVar6);
              if ((*(uint *)pAVar6 & 6) == 0) {
                puVar7 = *(undefined1 **)&pAVar6->field_0x10;
                asn1_item_combine_free(ppAVar4,puVar7,*(uint *)pAVar6 & 0x400);
              }
              else {
                pAVar8 = *ppAVar4;
                for (iVar9 = 0; iVar10 = (*(code *)PTR_sk_num_006a7f2c)(pAVar8), iVar9 < iVar10;
                    iVar9 = iVar9 + 1) {
                  uStack_30 = (*(code *)PTR_sk_value_006a7f24)(pAVar8,iVar9);
                  puVar7 = *(undefined1 **)&pAVar6->field_0x10;
                  asn1_item_combine_free(&uStack_30,puVar7,0);
                }
                (*(code *)PTR_sk_free_006a7f80)(pAVar8);
                *ppAVar4 = (ASN1_VALUE *)0x0;
              }
            }
            iVar5 = iVar5 + 1;
            pAStack_3c = (ASN1_ITEM_EXP *)&pAStack_3c[-1].field_0x8;
          } while (iVar5 < NETSCAPE_ENCRYPTED_PKEY_it._12_4_);
          goto joined_r0x0055ff4c;
        }
        break;
      case 2:
switchD_0055fb90_caseD_2:
        iVar5 = asn1_get_choice_selector
                          ((ASN1_VALUE **)&pAStack_34,(ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
        if ((-1 < iVar5) && (iVar5 < NETSCAPE_ENCRYPTED_PKEY_it._12_4_)) {
          pAVar11 = (ASN1_ITEM_EXP *)0x0;
LAB_0055fe08:
          pAVar6 = (ASN1_ITEM_EXP *)(NETSCAPE_ENCRYPTED_PKEY_it._8_4_ + iVar5 * 5);
          puVar7 = (undefined1 *)pAVar6;
          ppAVar4 = asn1_get_field_ptr((ASN1_VALUE **)&pAStack_34,(ASN1_TEMPLATE *)pAVar6);
          if ((*(uint *)pAVar6 & 6) == 0) {
            puVar7 = *(undefined1 **)&pAVar6->field_0x10;
            asn1_item_combine_free(ppAVar4,puVar7,*(uint *)pAVar6 & 0x400);
          }
          else {
            pAVar8 = *ppAVar4;
            for (iVar5 = 0; iVar9 = (*(code *)PTR_sk_num_006a7f2c)(pAVar8), iVar5 < iVar9;
                iVar5 = iVar5 + 1) {
              uStack_30 = (*(code *)PTR_sk_value_006a7f24)(pAVar8,iVar5);
              puVar7 = *(undefined1 **)&pAVar6->field_0x10;
              asn1_item_combine_free(&uStack_30,puVar7,0);
            }
            (*(code *)PTR_sk_free_006a7f80)(pAVar8);
            *ppAVar4 = (ASN1_VALUE *)0x0;
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
      switch(uVar3 & 0xff) {
      case 0:
        goto switchD_0055fdcc_caseD_0;
      case 1:
      case 6:
        pAVar6 = (ASN1_ITEM_EXP *)0xffffffff;
        param_1 = (ASN1_ITEM_EXP *)&pAStack_34;
        iVar5 = asn1_do_lock((ASN1_VALUE **)(ASN1_ITEM_EXP *)&pAStack_34,-1,
                             (ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
        if (0 < iVar5) goto switchD_0055fb90_caseD_0;
        param_1 = (ASN1_ITEM_EXP *)&SUB_00000002;
        pAVar6 = (ASN1_ITEM_EXP *)&pAStack_34;
        iVar5 = (*(code *)pAVar11)(2,(ASN1_ITEM_EXP *)&pAStack_34,NETSCAPE_ENCRYPTED_PKEY_it,0);
        if (iVar5 == 2) goto switchD_0055fb90_caseD_0;
        asn1_enc_free((ASN1_VALUE **)(ASN1_ITEM_EXP *)&pAStack_34,
                      (ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
        pAStack_3c = (ASN1_ITEM_EXP *)
                     (NETSCAPE_ENCRYPTED_PKEY_it._8_4_ + NETSCAPE_ENCRYPTED_PKEY_it._12_4_ * 5 + -5)
        ;
        if (0 < NETSCAPE_ENCRYPTED_PKEY_it._12_4_) goto LAB_0055fcc4;
        break;
      case 2:
        param_1 = (ASN1_ITEM_EXP *)&SUB_00000002;
        pAVar6 = (ASN1_ITEM_EXP *)&pAStack_34;
        iVar5 = (*(code *)pAVar11)(2,(ASN1_ITEM_EXP *)&pAStack_34,NETSCAPE_ENCRYPTED_PKEY_it,0);
        if (iVar5 == 2) goto switchD_0055fb90_caseD_0;
        iVar5 = asn1_get_choice_selector
                          ((ASN1_VALUE **)(ASN1_ITEM_EXP *)&pAStack_34,
                           (ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
        if ((-1 < iVar5) && (iVar5 < NETSCAPE_ENCRYPTED_PKEY_it._12_4_)) goto LAB_0055fe08;
        break;
      case 3:
switchD_0055fdcc_caseD_3:
        if (*(code **)&(NETSCAPE_ENCRYPTED_PKEY_it._16_4_)->field_0x4 != (code *)0x0) {
          (**(code **)&(NETSCAPE_ENCRYPTED_PKEY_it._16_4_)->field_0x4)();
        }
        goto switchD_0055fb90_caseD_0;
      case 4:
switchD_0055fdcc_caseD_4:
        param_1 = (ASN1_ITEM_EXP *)&pAStack_34;
        if (*(code **)&(NETSCAPE_ENCRYPTED_PKEY_it._16_4_)->field_0x8 != (code *)0x0) {
          (**(code **)&(NETSCAPE_ENCRYPTED_PKEY_it._16_4_)->field_0x8)();
          pAVar6 = (ASN1_ITEM_EXP *)puVar7;
        }
        goto switchD_0055fb90_caseD_0;
      case 5:
        goto LAB_0055fc1c;
      default:
        goto switchD_0055fb90_caseD_0;
      }
LAB_0055fbec:
      puVar7 = (undefined1 *)&pAStack_34;
      (*(code *)pAVar11)(3,puVar7,NETSCAPE_ENCRYPTED_PKEY_it,0);
    }
    param_1 = pAStack_34;
    (*(code *)PTR_CRYPTO_free_006a7f88)();
    pAVar6 = (ASN1_ITEM_EXP *)puVar7;
  }
switchD_0055fb90_caseD_0:
  if (iStack_2c == *(int *)puVar2) {
    return *(int *)puVar2;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar10 = *(int *)&param_1->field_0x4;
  iVar9 = *(int *)&pAVar6->field_0x4;
  iVar5 = iVar10;
  if (iVar9 <= iVar10) {
    iVar5 = iVar9;
  }
  iVar5 = (*(code *)PTR_memcmp_006aabd8)(*(undefined4 *)param_1,*(undefined4 *)pAVar6,iVar5);
  if (iVar5 == 0) {
    iVar5 = iVar10 - iVar9;
  }
  return iVar5;
}

