
/* WARNING: Type propagation algorithm not settling */

void ASN1_template_free(ASN1_VALUE **pval,ASN1_TEMPLATE *tt)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  ASN1_ITEM_EXP *pAVar5;
  ASN1_VALUE **ppAVar6;
  int iVar7;
  ASN1_ITEM_EXP *it;
  ASN1_ITEM_EXP *pAVar8;
  int unaff_s0;
  ASN1_VALUE *pAVar9;
  ASN1_ITEM_EXP *unaff_s1;
  ASN1_TEMPLATE *pAVar10;
  undefined4 *unaff_s3;
  ASN1_ITEM_EXP *pAVar11;
  ASN1_ITEM_EXP *pAStack_7c;
  ASN1_ITEM_EXP AStack_74;
  undefined *puStack_58;
  ASN1_VALUE **ppAStack_54;
  undefined4 local_28;
  int local_24;
  
  puStack_58 = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  if ((tt->flags & 6) == 0) {
    it = tt->item;
    pAVar5 = (ASN1_ITEM_EXP *)pval;
    asn1_item_combine_free(pval,it,tt->flags & 0x400);
  }
  else {
    unaff_s1 = (ASN1_ITEM_EXP *)*pval;
    unaff_s3 = &local_28;
    it = (ASN1_ITEM_EXP *)tt;
    for (unaff_s0 = 0; iVar2 = (*(code *)PTR_sk_num_006a6e2c)(unaff_s1), unaff_s0 < iVar2;
        unaff_s0 = unaff_s0 + 1) {
      local_28 = (*(code *)PTR_sk_value_006a6e24)(unaff_s1,unaff_s0);
      it = tt->item;
      asn1_item_combine_free(unaff_s3,it,0);
    }
    pAVar5 = unaff_s1;
    (*(code *)PTR_sk_free_006a6e80)();
    *pval = (ASN1_VALUE *)0x0;
  }
  if (local_24 == *(int *)puStack_58) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  uVar3 = (uint)it->itype;
  pAVar8 = (ASN1_ITEM_EXP *)it->funcs;
  AStack_74.templates = *(ASN1_TEMPLATE **)PTR___stack_chk_guard_006a9ae8;
  AStack_74._0_4_ = pAVar5;
  AStack_74.tcount = unaff_s0;
  AStack_74.funcs = unaff_s1;
  AStack_74.size = (long)tt;
  AStack_74.sname = (char *)unaff_s3;
  ppAStack_54 = pval;
  if (uVar3 != 0) {
    if (pAVar5 == (ASN1_ITEM_EXP *)0x0) goto switchD_0055c4c0_caseD_0;
    if (pAVar8 != (ASN1_ITEM_EXP *)0x0) goto LAB_0055c390;
    switch(uVar3 & 0xff) {
    default:
      goto switchD_0055c4c0_caseD_0;
    case 1:
    case 6:
      goto switchD_0055c4c0_caseD_1;
    case 2:
      goto switchD_0055c4c0_caseD_2;
    case 5:
      goto LAB_0055c54c;
    }
  }
  if (pAVar8 == (ASN1_ITEM_EXP *)0x0) {
switchD_0055c6fc_caseD_0:
    pAVar10 = it->templates;
    if (pAVar10 != (ASN1_TEMPLATE *)0x0) {
      iVar2 = 0;
      if ((pAVar10->flags & 6) == 0) {
        pAVar8 = pAVar10->item;
        pAVar5 = &AStack_74;
        asn1_item_combine_free(pAVar5,pAVar8,pAVar10->flags & 0x400);
      }
      else {
        for (; iVar4 = (*(code *)PTR_sk_num_006a6e2c)(pAVar5), iVar2 < iVar4; iVar2 = iVar2 + 1) {
          AStack_74.utype = (*(code *)PTR_sk_value_006a6e24)(pAVar5,iVar2);
          pAVar8 = pAVar10->item;
          asn1_item_combine_free((int)&AStack_74 + 4,pAVar8,0);
        }
        (*(code *)PTR_sk_free_006a6e80)();
      }
      goto switchD_0055c4c0_caseD_0;
    }
LAB_0055c54c:
    pAVar5 = &AStack_74;
    ASN1_primitive_free((ASN1_VALUE **)pAVar5,it);
    pAVar8 = it;
  }
  else {
LAB_0055c390:
    pAVar11 = (ASN1_ITEM_EXP *)pAVar8->funcs;
    if (pAVar11 == (ASN1_ITEM_EXP *)0x0) {
      switch(uVar3 & 0xff) {
      case 0:
        goto switchD_0055c6fc_caseD_0;
      case 1:
      case 6:
switchD_0055c4c0_caseD_1:
        pAVar8 = (ASN1_ITEM_EXP *)0xffffffff;
        pAVar5 = &AStack_74;
        iVar2 = asn1_do_lock((ASN1_VALUE **)&AStack_74,-1,it);
        if (0 < iVar2) goto switchD_0055c4c0_caseD_0;
        pAVar8 = it;
        asn1_enc_free((ASN1_VALUE **)&AStack_74,it);
        if (0 < it->tcount) {
          pAVar11 = (ASN1_ITEM_EXP *)0x0;
          pAStack_7c = (ASN1_ITEM_EXP *)(it->templates + it->tcount + -1);
LAB_0055c5f4:
          iVar2 = 0;
          do {
            pAVar8 = pAStack_7c;
            pAVar5 = (ASN1_ITEM_EXP *)
                     asn1_do_adb((ASN1_VALUE **)&AStack_74,(ASN1_TEMPLATE *)pAStack_7c,0);
            if (pAVar5 != (ASN1_ITEM_EXP *)0x0) {
              pAVar8 = pAVar5;
              ppAVar6 = asn1_get_field_ptr((ASN1_VALUE **)&AStack_74,(ASN1_TEMPLATE *)pAVar5);
              if ((*(uint *)pAVar5 & 6) == 0) {
                pAVar8 = (ASN1_ITEM_EXP *)pAVar5->funcs;
                asn1_item_combine_free(ppAVar6,pAVar8,*(uint *)pAVar5 & 0x400);
              }
              else {
                pAVar9 = *ppAVar6;
                for (iVar4 = 0; iVar7 = (*(code *)PTR_sk_num_006a6e2c)(pAVar9), iVar4 < iVar7;
                    iVar4 = iVar4 + 1) {
                  AStack_74.utype = (*(code *)PTR_sk_value_006a6e24)(pAVar9,iVar4);
                  pAVar8 = (ASN1_ITEM_EXP *)pAVar5->funcs;
                  asn1_item_combine_free((int)&AStack_74 + 4,pAVar8,0);
                }
                (*(code *)PTR_sk_free_006a6e80)(pAVar9);
                *ppAVar6 = (ASN1_VALUE *)0x0;
              }
            }
            iVar2 = iVar2 + 1;
            pAStack_7c = (ASN1_ITEM_EXP *)&pAStack_7c[-1].templates;
          } while (iVar2 < it->tcount);
          goto joined_r0x0055c87c;
        }
        break;
      case 2:
switchD_0055c4c0_caseD_2:
        pAVar8 = it;
        iVar2 = asn1_get_choice_selector((ASN1_VALUE **)&AStack_74,it);
        if ((-1 < iVar2) && (iVar2 < it->tcount)) {
          pAVar11 = (ASN1_ITEM_EXP *)0x0;
LAB_0055c738:
          pAVar5 = (ASN1_ITEM_EXP *)(it->templates + iVar2);
          pAVar8 = pAVar5;
          ppAVar6 = asn1_get_field_ptr((ASN1_VALUE **)&AStack_74,(ASN1_TEMPLATE *)pAVar5);
          if ((*(uint *)pAVar5 & 6) == 0) {
            pAVar8 = (ASN1_ITEM_EXP *)pAVar5->funcs;
            asn1_item_combine_free(ppAVar6,pAVar8,*(uint *)pAVar5 & 0x400);
          }
          else {
            pAVar9 = *ppAVar6;
            for (iVar2 = 0; iVar4 = (*(code *)PTR_sk_num_006a6e2c)(pAVar9), iVar2 < iVar4;
                iVar2 = iVar2 + 1) {
              AStack_74.utype = (*(code *)PTR_sk_value_006a6e24)(pAVar9,iVar2);
              pAVar8 = (ASN1_ITEM_EXP *)pAVar5->funcs;
              asn1_item_combine_free((int)&AStack_74 + 4,pAVar8,0);
            }
            (*(code *)PTR_sk_free_006a6e80)(pAVar9);
            *ppAVar6 = (ASN1_VALUE *)0x0;
          }
joined_r0x0055c87c:
          if (pAVar11 != (ASN1_ITEM_EXP *)0x0) goto LAB_0055c51c;
        }
        break;
      case 3:
        goto switchD_0055c6fc_caseD_3;
      case 4:
        goto switchD_0055c6fc_caseD_4;
      case 5:
        goto LAB_0055c54c;
      default:
        goto switchD_0055c4c0_caseD_0;
      }
    }
    else {
      switch(uVar3 & 0xff) {
      case 0:
        goto switchD_0055c6fc_caseD_0;
      case 1:
      case 6:
        pAVar8 = (ASN1_ITEM_EXP *)0xffffffff;
        pAVar5 = &AStack_74;
        iVar2 = asn1_do_lock((ASN1_VALUE **)&AStack_74,-1,it);
        if (0 < iVar2) goto switchD_0055c4c0_caseD_0;
        pAVar5 = (ASN1_ITEM_EXP *)&SUB_00000002;
        pAVar8 = &AStack_74;
        iVar2 = (*(code *)pAVar11)(2,&AStack_74,it,0);
        if (iVar2 == 2) goto switchD_0055c4c0_caseD_0;
        asn1_enc_free((ASN1_VALUE **)&AStack_74,it);
        pAStack_7c = (ASN1_ITEM_EXP *)(it->templates + it->tcount + -1);
        if (0 < it->tcount) goto LAB_0055c5f4;
        break;
      case 2:
        pAVar5 = (ASN1_ITEM_EXP *)&SUB_00000002;
        pAVar8 = &AStack_74;
        iVar2 = (*(code *)pAVar11)(2,&AStack_74,it,0);
        if (iVar2 == 2) goto switchD_0055c4c0_caseD_0;
        iVar2 = asn1_get_choice_selector((ASN1_VALUE **)&AStack_74,it);
        if ((-1 < iVar2) && (iVar2 < it->tcount)) goto LAB_0055c738;
        break;
      case 3:
switchD_0055c6fc_caseD_3:
        if ((code *)pAVar8->utype != (code *)0x0) {
          (*(code *)pAVar8->utype)();
        }
        goto switchD_0055c4c0_caseD_0;
      case 4:
switchD_0055c6fc_caseD_4:
        pAVar5 = &AStack_74;
        if (pAVar8->templates != (ASN1_TEMPLATE *)0x0) {
          (*(code *)pAVar8->templates)();
          pAVar8 = it;
        }
        goto switchD_0055c4c0_caseD_0;
      case 5:
        goto LAB_0055c54c;
      default:
        goto switchD_0055c4c0_caseD_0;
      }
LAB_0055c51c:
      pAVar8 = &AStack_74;
      (*(code *)pAVar11)(3,pAVar8,it,0);
    }
    pAVar5 = AStack_74._0_4_;
    (*(code *)PTR_CRYPTO_free_006a6e88)();
  }
switchD_0055c4c0_caseD_0:
  if (AStack_74.templates == *(ASN1_TEMPLATE **)puVar1) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar2 = pAVar5->utype;
  if (pAVar8->utype <= pAVar5->utype) {
    iVar2 = pAVar8->utype;
  }
  (*(code *)PTR_memcmp_006a9ad0)(*(undefined4 *)pAVar5,*(undefined4 *)pAVar8,iVar2);
  return;
}

