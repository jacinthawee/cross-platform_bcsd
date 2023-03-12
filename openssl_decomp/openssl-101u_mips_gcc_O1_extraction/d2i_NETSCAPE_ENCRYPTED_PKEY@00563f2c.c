
ASN1_VALUE * d2i_NETSCAPE_ENCRYPTED_PKEY(ASN1_VALUE **param_1,char *param_2,int param_3)

{
  char cVar1;
  undefined *puVar2;
  int in_zero;
  ASN1_VALUE **ppAVar3;
  undefined4 uVar4;
  ASN1_VALUE *pAVar5;
  int iVar6;
  int iVar7;
  ASN1_TEMPLATE *pAVar8;
  uint uVar9;
  ASN1_TEMPLATE *pAVar10;
  ASN1_VALUE **ppAVar11;
  undefined4 uVar12;
  ASN1_VALUE **pval;
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
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  iVar7 = NETSCAPE_ENCRYPTED_PKEY_it._16_4_;
  pAStack_54 = (ASN1_VALUE *)0x0;
  auStack_44[0] = 0;
  iStack_50 = param_3;
  pAStack_4c = (ASN1_VALUE *)0x0;
  pval = &pAStack_54;
  if (param_1 != (ASN1_VALUE **)0x0) {
    pval = param_1;
  }
  piStack_2c = *(int **)PTR___stack_chk_guard_006a9ae8;
  if (NETSCAPE_ENCRYPTED_PKEY_it._16_4_ == 0) {
    switch(NETSCAPE_ENCRYPTED_PKEY_it[0]) {
    case 0:
      goto switchD_005619f8_caseD_0;
    case 1:
    case 6:
      pcStack_68 = (code *)0x0;
      goto switchD_00561550_caseD_1;
    case 2:
      pcStack_68 = (code *)0x0;
LAB_00561954:
      if (*pval == (ASN1_VALUE *)0x0) {
        iVar7 = ASN1_item_ex_new(pval,(ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
        if (iVar7 == 0) {
          uVar12 = 0x3a;
          uVar4 = 0x13f;
          goto LAB_0056163c;
        }
      }
      else {
        iVar7 = asn1_get_choice_selector(pval,(ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
        if ((-1 < iVar7) && (iVar7 < (int)NETSCAPE_ENCRYPTED_PKEY_it._12_4_)) {
          pAVar10 = NETSCAPE_ENCRYPTED_PKEY_it._8_4_ + iVar7;
          ppAVar11 = asn1_get_field_ptr(pval,pAVar10);
          ASN1_template_free(ppAVar11,pAVar10);
          asn1_set_choice_selector(pval,-1,(ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
        }
      }
      pAStack_4c = *(ASN1_VALUE **)param_2;
      ppAVar11 = (ASN1_VALUE **)0x0;
      if ((int)NETSCAPE_ENCRYPTED_PKEY_it._12_4_ < 1) {
LAB_005615e0:
        if (ppAVar11 == NETSCAPE_ENCRYPTED_PKEY_it._12_4_) {
LAB_00561a34:
          uVar12 = 0x8f;
          uVar4 = 0x15e;
          goto LAB_0056163c;
        }
      }
      else {
        pAVar10 = NETSCAPE_ENCRYPTED_PKEY_it._8_4_;
        do {
          ppAVar3 = asn1_get_field_ptr(pval,pAVar10);
          iVar7 = asn1_template_ex_d2i(ppAVar3,&pAStack_4c,iStack_50,pAVar10,1,auStack_44);
          if (iVar7 != -1) {
            if (0 < iVar7) goto LAB_005615e0;
            (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x78,0x3a,s_tasn_dec_c_0066a0bc,0x152);
            ASN1_item_ex_free(pval,(ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
            if (pAVar10 == (ASN1_TEMPLATE *)0x0) goto LAB_00561668;
            goto LAB_00561cf8;
          }
          ppAVar11 = (ASN1_VALUE **)((int)ppAVar11 + 1);
          pAVar10 = pAVar10 + 1;
        } while ((int)ppAVar11 < (int)NETSCAPE_ENCRYPTED_PKEY_it._12_4_);
        if (ppAVar11 == NETSCAPE_ENCRYPTED_PKEY_it._12_4_) goto LAB_00561a34;
      }
      asn1_set_choice_selector(pval,(int)ppAVar11,(ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
      goto joined_r0x00561600;
    case 3:
      goto switchD_005619f8_caseD_3;
    case 4:
      pcStack_68 = *(code **)(in_zero + 0x10);
      goto LAB_005618f4;
    case 5:
      goto switchD_005619f8_caseD_5;
    }
    goto switchD_005619f8_caseD_7;
  }
  pcStack_68 = *(code **)(NETSCAPE_ENCRYPTED_PKEY_it._16_4_ + 0x10);
  switch(NETSCAPE_ENCRYPTED_PKEY_it[0]) {
  case 0:
switchD_005619f8_caseD_0:
    if (NETSCAPE_ENCRYPTED_PKEY_it._8_4_ == (ASN1_TEMPLATE *)0x0) {
      iVar7 = asn1_d2i_ex_primitive
                        (pval,param_2,param_3,NETSCAPE_ENCRYPTED_PKEY_it,0xffffffff,0,0,auStack_44);
      if (iVar7 < 1) {
        pAVar5 = (ASN1_VALUE *)0x0;
        ppAVar11 = (ASN1_VALUE **)param_2;
        goto LAB_00561684;
      }
    }
    else {
      iVar7 = asn1_template_ex_d2i
                        (pval,param_2,param_3,NETSCAPE_ENCRYPTED_PKEY_it._8_4_,0,auStack_44);
      if (iVar7 < 1) goto switchD_005619f8_caseD_7;
    }
    goto LAB_005617a4;
  case 1:
  case 6:
switchD_00561550_caseD_1:
    pAStack_4c = *(ASN1_VALUE **)param_2;
    ppAVar11 = (ASN1_VALUE **)0x0;
    iVar6 = asn1_check_tlen(&iStack_50,0,0,&cStack_56,&cStack_55,&pAStack_4c,param_3,0x10,0,0,
                            auStack_44);
    if (iVar6 == 0) {
      uVar12 = 0x3a;
      uVar4 = 0x176;
    }
    else {
      pAVar5 = (ASN1_VALUE *)0x0;
      if (iVar6 == -1) goto LAB_00561684;
      cVar1 = cStack_56;
      if ((iVar7 != 0) && ((*(uint *)(iVar7 + 4) & 4) != 0)) {
        iStack_50 = param_3 - ((int)pAStack_4c - (int)*(ASN1_VALUE **)param_2);
        cVar1 = '\x01';
      }
      if (cStack_55 == '\0') {
        uVar12 = 0x95;
        uVar4 = 0x182;
      }
      else if ((*pval == (ASN1_VALUE *)0x0) &&
              (iVar7 = ASN1_item_ex_new(pval,(ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it), iVar7 == 0))
      {
        uVar12 = 0x3a;
        uVar4 = 0x187;
      }
      else {
        puStack_60 = auStack_44;
        if ((pcStack_68 != (code *)0x0) &&
           (iVar7 = (*pcStack_68)(4,pval,NETSCAPE_ENCRYPTED_PKEY_it,0), iVar7 == 0))
        goto LAB_00561628;
        iVar7 = 0;
        ppAVar11 = NETSCAPE_ENCRYPTED_PKEY_it._12_4_;
        pAVar8 = NETSCAPE_ENCRYPTED_PKEY_it._8_4_;
        pAVar10 = NETSCAPE_ENCRYPTED_PKEY_it._8_4_;
        if (0 < (int)NETSCAPE_ENCRYPTED_PKEY_it._12_4_) {
          do {
            if ((pAVar10->flags & 0x300) != 0) {
              pAVar8 = asn1_do_adb(pval,pAVar10,1);
              ppAVar11 = asn1_get_field_ptr(pval,pAVar8);
              ASN1_template_free(ppAVar11,pAVar8);
              ppAVar11 = NETSCAPE_ENCRYPTED_PKEY_it._12_4_;
            }
            iVar7 = iVar7 + 1;
            pAVar10 = pAVar10 + 1;
          } while (iVar7 < (int)ppAVar11);
          iVar7 = 0;
          pAVar8 = NETSCAPE_ENCRYPTED_PKEY_it._8_4_;
          if (0 < (int)ppAVar11) {
            do {
              pAVar10 = asn1_do_adb(pval,pAVar8,1);
              if (pAVar10 == (ASN1_TEMPLATE *)0x0) goto LAB_00561650;
              ppAVar11 = asn1_get_field_ptr(pval,pAVar10);
              pAVar5 = pAStack_4c;
              if (iStack_50 == 0) {
                if (cStack_56 == '\0') goto LAB_00561c3c;
                goto LAB_00561e04;
              }
              if (((1 < iStack_50) && (*pAStack_4c == (ASN1_VALUE)0x0)) &&
                 (pAStack_4c[1] == (ASN1_VALUE)0x0)) {
                if (cStack_56 == '\0') {
                  uVar12 = 0x9f;
                  uVar4 = 0x1a7;
                  pAStack_4c = pAStack_4c + 2;
                  goto LAB_0056163c;
                }
                iStack_50 = iStack_50 + -2;
                cStack_56 = '\0';
                pAStack_4c = pAStack_4c + 2;
                goto LAB_00561c28;
              }
              uVar9 = 0;
              if ((int)NETSCAPE_ENCRYPTED_PKEY_it._12_4_ + -1 != iVar7) {
                uVar9 = pAVar10->flags & 1;
              }
              iVar6 = asn1_template_ex_d2i(ppAVar11,&pAStack_4c,iStack_50,pAVar10,uVar9,puStack_60);
              if (iVar6 == 0) goto LAB_00561ce4;
              if (iVar6 == -1) {
                ASN1_template_free(ppAVar11,pAVar10);
              }
              else {
                iStack_50 = iStack_50 - ((int)pAStack_4c - (int)pAVar5);
              }
              iVar7 = iVar7 + 1;
              pAVar8 = pAVar8 + 1;
            } while (iVar7 < (int)NETSCAPE_ENCRYPTED_PKEY_it._12_4_);
          }
        }
        if (cStack_56 != '\0') {
          if (((iStack_50 < 2) || (*pAStack_4c != (ASN1_VALUE)0x0)) ||
             (pAStack_4c[1] != (ASN1_VALUE)0x0)) {
LAB_00561e04:
            uVar12 = 0x89;
            uVar4 = 0x1ce;
            break;
          }
          pAStack_4c = pAStack_4c + 2;
        }
LAB_00561c28:
        if ((cVar1 != '\0') || (iStack_50 == 0)) {
LAB_00561c3c:
          if (iVar7 < (int)NETSCAPE_ENCRYPTED_PKEY_it._12_4_) {
LAB_00561c90:
            pAVar10 = asn1_do_adb(pval,pAVar8,1);
            if (pAVar10 != (ASN1_TEMPLATE *)0x0) {
              if ((pAVar10->flags & 1) != 0) goto LAB_00561c54;
              (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x78,0x79,s_tasn_dec_c_0066a0bc,0x1e7);
LAB_00561ce4:
              ASN1_item_ex_free(pval,(ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
LAB_00561cf8:
              param_2 = (char *)&DAT_0066a0d0;
              (*(code *)PTR_ERR_add_error_data_006a813c)
                        (4,&DAT_0066a0d0,pAVar10->field_name,", Type=",
                         NETSCAPE_ENCRYPTED_PKEY_it._24_4_);
              goto switchD_005619f8_caseD_7;
            }
            goto LAB_00561650;
          }
          ppAVar11 = *(ASN1_VALUE ***)param_2;
          goto LAB_00561a70;
        }
        uVar12 = 0x94;
        uVar4 = 0x1d3;
      }
    }
    break;
  case 2:
    if ((pcStack_68 == (code *)0x0) ||
       (iVar7 = (*pcStack_68)(4,pval,NETSCAPE_ENCRYPTED_PKEY_it,0), iVar7 != 0)) goto LAB_00561954;
    goto LAB_00561628;
  case 3:
switchD_005619f8_caseD_3:
    iVar7 = (**(code **)(NETSCAPE_ENCRYPTED_PKEY_it._16_4_ + 8))(pval,param_2,param_3);
    if (iVar7 != 0) {
      pAVar5 = *pval;
      ppAVar11 = (ASN1_VALUE **)param_2;
      goto LAB_00561684;
    }
    uVar12 = 0x3a;
    uVar4 = 0x12f;
    break;
  case 4:
LAB_005618f4:
    iVar7 = (*pcStack_68)(pval,param_2,param_3,NETSCAPE_ENCRYPTED_PKEY_it,0xffffffff,0,0,auStack_44)
    ;
    if (iVar7 < 1) {
      pAVar5 = (ASN1_VALUE *)0x0;
      ppAVar11 = (ASN1_VALUE **)param_2;
      goto LAB_00561684;
    }
LAB_005617a4:
    pAVar5 = *pval;
    ppAVar11 = (ASN1_VALUE **)param_2;
    goto LAB_00561684;
  case 5:
switchD_005619f8_caseD_5:
    pAStack_4c = *(ASN1_VALUE **)param_2;
    iVar7 = asn1_check_tlen_constprop_1
                      (0,&uStack_48,&cStack_57,0,0,&pAStack_4c,param_3,1,auStack_44);
    if (iVar7 == 0) {
      uVar12 = 0x3a;
      uVar4 = 0xdb;
    }
    else if (cStack_57 == '\0') {
      if ((uStack_48 < 0x1f) &&
         ((*(uint *)(tag2bit + uStack_48 * 4) & NETSCAPE_ENCRYPTED_PKEY_it._4_4_) != 0)) {
        iVar7 = asn1_d2i_ex_primitive
                          (pval,param_2,iStack_50,NETSCAPE_ENCRYPTED_PKEY_it,uStack_48,0,0,
                           auStack_44);
        if (iVar7 < 1) {
          pAVar5 = (ASN1_VALUE *)0x0;
          ppAVar11 = (ASN1_VALUE **)param_2;
          goto LAB_00561684;
        }
        goto LAB_005617a4;
      }
      uVar12 = 0x8c;
      uVar4 = 0xec;
    }
    else {
      uVar12 = 0x8b;
      uVar4 = 0xe4;
    }
    break;
  default:
    goto switchD_005619f8_caseD_7;
  }
LAB_0056163c:
  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x78,uVar12,s_tasn_dec_c_0066a0bc,uVar4);
LAB_00561650:
  ASN1_item_ex_free(pval,(ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
LAB_00561668:
  param_2 = s_Type__0066a0d8;
  (*(code *)PTR_ERR_add_error_data_006a813c)(2,s_Type__0066a0d8,NETSCAPE_ENCRYPTED_PKEY_it._24_4_);
switchD_005619f8_caseD_7:
  pAVar5 = (ASN1_VALUE *)0x0;
  ppAVar11 = (ASN1_VALUE **)param_2;
LAB_00561684:
  if (piStack_2c != *(int **)puVar2) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    return *(ASN1_VALUE **)(ppAVar11[1] + *piStack_2c);
  }
  return pAVar5;
LAB_00561c54:
  iVar7 = iVar7 + 1;
  ppAVar11 = asn1_get_field_ptr(pval,pAVar10);
  pAVar8 = pAVar8 + 1;
  ASN1_template_free(ppAVar11,pAVar10);
  if ((int)NETSCAPE_ENCRYPTED_PKEY_it._12_4_ <= iVar7) goto LAB_00561a6c;
  goto LAB_00561c90;
LAB_00561a6c:
  ppAVar11 = *(ASN1_VALUE ***)param_2;
LAB_00561a70:
  iVar7 = asn1_enc_save(pval,(uchar *)ppAVar11,(int)pAStack_4c - (int)ppAVar11,
                        (ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
  if (iVar7 != 0) {
joined_r0x00561600:
    if ((pcStack_68 == (code *)0x0) ||
       (ppAVar11 = pval, iVar7 = (*pcStack_68)(5,pval,NETSCAPE_ENCRYPTED_PKEY_it,0), iVar7 != 0)) {
      *(ASN1_VALUE **)param_2 = pAStack_4c;
      pAVar5 = *pval;
      goto LAB_00561684;
    }
  }
LAB_00561628:
  uVar12 = 100;
  uVar4 = 0x1f7;
  goto LAB_0056163c;
}

