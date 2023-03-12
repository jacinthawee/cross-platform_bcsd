
ASN1_VALUE * d2i_NETSCAPE_PKEY(ASN1_VALUE **param_1,char *param_2,int param_3)

{
  char cVar1;
  undefined *puVar2;
  int in_zero;
  ASN1_VALUE **ppAVar3;
  undefined4 uVar4;
  ASN1_VALUE *pAVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  ASN1_TEMPLATE *tt;
  ASN1_VALUE **ppAVar9;
  undefined4 uVar10;
  ASN1_VALUE **pval;
  undefined *puVar11;
  ASN1_TEMPLATE *tt_00;
  code *pcStack_68;
  undefined *puStack_60;
  char cStack_57;
  char cStack_56;
  char cStack_55;
  ASN1_VALUE *pAStack_54;
  int iStack_50;
  ASN1_VALUE *pAStack_4c;
  uint uStack_48;
  undefined auStack_44 [24];
  int *piStack_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  iVar7 = NETSCAPE_PKEY_it._16_4_;
  pAStack_54 = (ASN1_VALUE *)0x0;
  auStack_44[0] = 0;
  iStack_50 = param_3;
  pAStack_4c = (ASN1_VALUE *)0x0;
  pval = &pAStack_54;
  if (param_1 != (ASN1_VALUE **)0x0) {
    pval = param_1;
  }
  piStack_2c = *(int **)PTR___stack_chk_guard_006aabf0;
  if (NETSCAPE_PKEY_it._16_4_ == 0) {
    switch(NETSCAPE_PKEY_it[0]) {
    case 0:
      goto switchD_00565630_caseD_0;
    case 1:
    case 6:
      pcStack_68 = (code *)0x0;
      goto switchD_005651a0_caseD_1;
    case 2:
      pcStack_68 = (code *)0x0;
LAB_005651ac:
      if ((*pval == (ASN1_VALUE *)0x0) &&
         (iVar7 = ASN1_item_ex_new(pval,(ASN1_ITEM *)NETSCAPE_PKEY_it), iVar7 == 0)) {
        uVar10 = 0x3a;
        uVar4 = 0x13e;
        goto LAB_00565288;
      }
      pAStack_4c = *(ASN1_VALUE **)param_2;
      ppAVar9 = (ASN1_VALUE **)0x0;
      if ((int)NETSCAPE_PKEY_it._12_4_ < 1) {
LAB_00565228:
        if (ppAVar9 == NETSCAPE_PKEY_it._12_4_) {
LAB_0056566c:
          uVar10 = 0x8f;
          uVar4 = 0x162;
          goto LAB_00565288;
        }
      }
      else {
        tt = NETSCAPE_PKEY_it._8_4_;
        do {
          ppAVar3 = asn1_get_field_ptr(pval,tt);
          iVar7 = asn1_template_ex_d2i(ppAVar3,&pAStack_4c,iStack_50,tt,1,auStack_44);
          if (iVar7 != -1) {
            if (0 < iVar7) goto LAB_00565228;
            (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x78,0x3a,s_tasn_dec_c_0066ab2c,0x153);
            ASN1_item_ex_free(pval,(ASN1_ITEM *)NETSCAPE_PKEY_it);
            if (tt != (ASN1_TEMPLATE *)0x0) goto LAB_005657fc;
            goto LAB_005652b4;
          }
          ppAVar9 = (ASN1_VALUE **)((int)ppAVar9 + 1);
          tt = tt + 1;
        } while ((int)ppAVar9 < (int)NETSCAPE_PKEY_it._12_4_);
        if (ppAVar9 == NETSCAPE_PKEY_it._12_4_) goto LAB_0056566c;
      }
      asn1_set_choice_selector(pval,(int)ppAVar9,(ASN1_ITEM *)NETSCAPE_PKEY_it);
      *(ASN1_VALUE **)param_2 = pAStack_4c;
      if (pcStack_68 == (code *)0x0) goto LAB_00565328;
      goto LAB_00565258;
    case 3:
      goto switchD_00565630_caseD_3;
    case 4:
      pcStack_68 = *(code **)(in_zero + 0x10);
      goto LAB_005655ac;
    case 5:
      goto switchD_00565630_caseD_5;
    }
    goto switchD_00565630_caseD_7;
  }
  pcStack_68 = *(code **)(NETSCAPE_PKEY_it._16_4_ + 0x10);
  switch(NETSCAPE_PKEY_it[0]) {
  case 0:
switchD_00565630_caseD_0:
    if (NETSCAPE_PKEY_it._8_4_ == (ASN1_TEMPLATE *)0x0) {
      iVar7 = asn1_d2i_ex_primitive(pval,param_2,param_3,NETSCAPE_PKEY_it,0xffffffff,0,0,auStack_44)
      ;
      if (iVar7 < 1) {
        pAVar5 = (ASN1_VALUE *)0x0;
        ppAVar9 = (ASN1_VALUE **)param_2;
        goto LAB_005652d0;
      }
    }
    else {
      iVar7 = asn1_template_ex_d2i(pval,param_2,param_3,NETSCAPE_PKEY_it._8_4_,0,auStack_44);
      if (iVar7 < 1) goto switchD_00565630_caseD_7;
    }
    goto LAB_005653f0;
  case 1:
  case 6:
switchD_005651a0_caseD_1:
    pAStack_4c = *(ASN1_VALUE **)param_2;
    ppAVar9 = (ASN1_VALUE **)0x0;
    iVar6 = asn1_check_tlen(&iStack_50,0,0,&cStack_56,&cStack_55,&pAStack_4c,param_3,0x10,0,0,
                            auStack_44);
    if (iVar6 == 0) {
      uVar10 = 0x3a;
      uVar4 = 0x17d;
    }
    else {
      pAVar5 = (ASN1_VALUE *)0x0;
      if (iVar6 == -1) goto LAB_005652d0;
      cVar1 = cStack_56;
      if ((iVar7 != 0) && ((*(uint *)(iVar7 + 4) & 4) != 0)) {
        iStack_50 = param_3 - ((int)pAStack_4c - (int)*(ASN1_VALUE **)param_2);
        cVar1 = '\x01';
      }
      if (cStack_55 == '\0') {
        uVar10 = 0x95;
        uVar4 = 0x18c;
      }
      else if ((*pval == (ASN1_VALUE *)0x0) &&
              (iVar7 = ASN1_item_ex_new(pval,(ASN1_ITEM *)NETSCAPE_PKEY_it), iVar7 == 0)) {
        uVar10 = 0x3a;
        uVar4 = 0x193;
      }
      else {
        puStack_60 = auStack_44;
        if ((pcStack_68 != (code *)0x0) &&
           (iVar7 = (*pcStack_68)(4,pval,NETSCAPE_PKEY_it,0), iVar7 == 0)) goto LAB_00565278;
        puVar11 = (undefined *)0x0;
        tt_00 = NETSCAPE_PKEY_it._8_4_;
        if (0 < (int)NETSCAPE_PKEY_it._12_4_) {
          do {
            tt = asn1_do_adb(pval,tt_00,1);
            if (tt == (ASN1_TEMPLATE *)0x0) goto LAB_0056529c;
            ppAVar9 = asn1_get_field_ptr(pval,tt);
            pAVar5 = pAStack_4c;
            if (iStack_50 == 0) {
              if (cStack_56 != '\0') goto LAB_00565908;
              goto LAB_00565740;
            }
            if (((1 < iStack_50) && (*pAStack_4c == (ASN1_VALUE)0x0)) &&
               (pAStack_4c[1] == (ASN1_VALUE)0x0)) {
              if (cStack_56 != '\0') {
                iStack_50 = iStack_50 + -2;
                cStack_56 = '\0';
                pAStack_4c = pAStack_4c + 2;
                goto LAB_0056572c;
              }
              uVar10 = 0x9f;
              uVar4 = 0x1ac;
              pAStack_4c = pAStack_4c + 2;
              goto LAB_00565288;
            }
            uVar8 = 0;
            if (puVar11 != (undefined *)((int)NETSCAPE_PKEY_it._12_4_ + -1)) {
              uVar8 = tt->flags & 1;
            }
            iVar7 = asn1_template_ex_d2i(ppAVar9,&pAStack_4c,iStack_50,tt,uVar8,puStack_60);
            if (iVar7 == 0) goto LAB_005657e8;
            if (iVar7 == -1) {
              ASN1_template_free(ppAVar9,tt);
            }
            else {
              iStack_50 = iStack_50 - ((int)pAStack_4c - (int)pAVar5);
            }
            puVar11 = puVar11 + 1;
            tt_00 = tt_00 + 1;
          } while ((int)puVar11 < (int)NETSCAPE_PKEY_it._12_4_);
        }
        if (cStack_56 != '\0') {
          if (((iStack_50 < 2) || (*pAStack_4c != (ASN1_VALUE)0x0)) ||
             (pAStack_4c[1] != (ASN1_VALUE)0x0)) {
LAB_00565908:
            uVar10 = 0x89;
            uVar4 = 0x1d6;
            break;
          }
          pAStack_4c = pAStack_4c + 2;
        }
LAB_0056572c:
        if ((cVar1 != '\0') || (iStack_50 == 0)) {
LAB_00565740:
          if ((int)puVar11 < (int)NETSCAPE_PKEY_it._12_4_) {
LAB_00565794:
            tt = asn1_do_adb(pval,tt_00,1);
            if (tt != (ASN1_TEMPLATE *)0x0) {
              if ((tt->flags & 1) != 0) goto LAB_00565758;
              (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x78,0x79,s_tasn_dec_c_0066ab2c,0x1f5);
LAB_005657e8:
              ASN1_item_ex_free(pval,(ASN1_ITEM *)NETSCAPE_PKEY_it);
LAB_005657fc:
              param_2 = &DAT_0066ab40;
              (*(code *)PTR_ERR_add_error_data_006a9264)
                        (4,&DAT_0066ab40,tt->field_name,", Type=",NETSCAPE_PKEY_it._24_4_);
              goto switchD_00565630_caseD_7;
            }
            goto LAB_0056529c;
          }
          ppAVar9 = *(ASN1_VALUE ***)param_2;
          goto LAB_00565954;
        }
        uVar10 = 0x94;
        uVar4 = 0x1dd;
      }
    }
    break;
  case 2:
    if ((pcStack_68 == (code *)0x0) ||
       (iVar7 = (*pcStack_68)(4,pval,NETSCAPE_PKEY_it,0), iVar7 != 0)) goto LAB_005651ac;
    goto LAB_00565278;
  case 3:
switchD_00565630_caseD_3:
    iVar7 = (**(code **)(NETSCAPE_PKEY_it._16_4_ + 8))(pval,param_2,param_3);
    ppAVar9 = (ASN1_VALUE **)param_2;
    if (iVar7 != 0) goto LAB_00565328;
    uVar10 = 0x3a;
    uVar4 = 0x132;
    break;
  case 4:
LAB_005655ac:
    iVar7 = (*pcStack_68)(pval,param_2,param_3,NETSCAPE_PKEY_it,0xffffffff,0,0,auStack_44);
    if (iVar7 < 1) {
      pAVar5 = (ASN1_VALUE *)0x0;
      ppAVar9 = (ASN1_VALUE **)param_2;
      goto LAB_005652d0;
    }
LAB_005653f0:
    pAVar5 = *pval;
    ppAVar9 = (ASN1_VALUE **)param_2;
    goto LAB_005652d0;
  case 5:
switchD_00565630_caseD_5:
    pAStack_4c = *(ASN1_VALUE **)param_2;
    iVar7 = asn1_check_tlen_constprop_1
                      (0,&uStack_48,&cStack_57,0,0,&pAStack_4c,param_3,1,auStack_44);
    if (iVar7 == 0) {
      uVar10 = 0x3a;
      uVar4 = 0xd2;
    }
    else if (cStack_57 == '\0') {
      if ((uStack_48 < 0x1f) && ((*(uint *)(tag2bit + uStack_48 * 4) & NETSCAPE_PKEY_it._4_4_) != 0)
         ) {
        iVar7 = asn1_d2i_ex_primitive
                          (pval,param_2,iStack_50,NETSCAPE_PKEY_it,uStack_48,0,0,auStack_44);
        if (iVar7 < 1) {
          pAVar5 = (ASN1_VALUE *)0x0;
          ppAVar9 = (ASN1_VALUE **)param_2;
          goto LAB_005652d0;
        }
        goto LAB_005653f0;
      }
      uVar10 = 0x8c;
      uVar4 = 0xe6;
    }
    else {
      uVar10 = 0x8b;
      uVar4 = 0xdc;
    }
    break;
  default:
    goto switchD_00565630_caseD_7;
  }
LAB_00565288:
  (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x78,uVar10,s_tasn_dec_c_0066ab2c,uVar4);
LAB_0056529c:
  ASN1_item_ex_free(pval,(ASN1_ITEM *)NETSCAPE_PKEY_it);
LAB_005652b4:
  param_2 = s_Type__0066ab48;
  (*(code *)PTR_ERR_add_error_data_006a9264)(2,s_Type__0066ab48,NETSCAPE_PKEY_it._24_4_);
switchD_00565630_caseD_7:
  pAVar5 = (ASN1_VALUE *)0x0;
  ppAVar9 = (ASN1_VALUE **)param_2;
LAB_005652d0:
  if (piStack_2c == *(int **)puVar2) {
    return pAVar5;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  return *(ASN1_VALUE **)(ppAVar9[1] + *piStack_2c);
LAB_00565758:
  puVar11 = puVar11 + 1;
  ppAVar9 = asn1_get_field_ptr(pval,tt);
  tt_00 = tt_00 + 1;
  ASN1_template_free(ppAVar9,tt);
  if ((int)NETSCAPE_PKEY_it._12_4_ <= (int)puVar11) goto LAB_00565950;
  goto LAB_00565794;
LAB_00565950:
  ppAVar9 = *(ASN1_VALUE ***)param_2;
LAB_00565954:
  iVar7 = asn1_enc_save(pval,(uchar *)ppAVar9,(int)pAStack_4c - (int)ppAVar9,
                        (ASN1_ITEM *)NETSCAPE_PKEY_it);
  if (iVar7 != 0) {
    *(ASN1_VALUE **)param_2 = pAStack_4c;
    if (pcStack_68 == (code *)0x0) {
      pAVar5 = *pval;
      goto LAB_005652d0;
    }
LAB_00565258:
    ppAVar9 = pval;
    iVar7 = (*pcStack_68)(5,pval,NETSCAPE_PKEY_it,0);
    if (iVar7 != 0) {
LAB_00565328:
      pAVar5 = *pval;
      goto LAB_005652d0;
    }
  }
LAB_00565278:
  uVar10 = 100;
  uVar4 = 0x205;
  goto LAB_00565288;
}

