
PBEPARAM * d2i_PBEPARAM(PBEPARAM **a,uchar **in,long len)

{
  char cVar1;
  undefined *puVar2;
  uchar *puVar3;
  int in_zero;
  undefined4 uVar4;
  PBEPARAM *pPVar5;
  int iVar6;
  int iVar7;
  ASN1_TEMPLATE *pAVar8;
  uint uVar9;
  ASN1_VALUE **ppAVar10;
  ASN1_TEMPLATE *pAVar11;
  char *pcVar12;
  PBEPARAM **ppPVar13;
  undefined4 uVar14;
  PBEPARAM **pval;
  code *pcStack_68;
  undefined *puStack_60;
  char cStack_57;
  char cStack_56;
  char cStack_55;
  PBEPARAM *pPStack_54;
  long lStack_50;
  uchar *puStack_4c;
  uint uStack_48;
  undefined auStack_44 [24];
  int *piStack_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  iVar7 = PBEPARAM_it._16_4_;
  pPStack_54 = (PBEPARAM *)0x0;
  auStack_44[0] = 0;
  lStack_50 = len;
  puStack_4c = (uchar *)0x0;
  pval = &pPStack_54;
  if (a != (PBEPARAM **)0x0) {
    pval = a;
  }
  piStack_2c = *(int **)PTR___stack_chk_guard_006a9ae8;
  if (PBEPARAM_it._16_4_ == 0) {
    switch(PBEPARAM_it[0]) {
    case 0:
      goto switchD_005619f8_caseD_0;
    case 1:
    case 6:
      pcStack_68 = (code *)0x0;
      goto switchD_00561550_caseD_1;
    case 2:
      pcStack_68 = (code *)0x0;
LAB_00561954:
      if (*pval == (PBEPARAM *)0x0) {
        iVar7 = ASN1_item_ex_new((ASN1_VALUE **)pval,(ASN1_ITEM *)PBEPARAM_it);
        if (iVar7 == 0) {
          uVar14 = 0x3a;
          uVar4 = 0x13f;
          goto LAB_0056163c;
        }
      }
      else {
        iVar7 = asn1_get_choice_selector((ASN1_VALUE **)pval,(ASN1_ITEM *)PBEPARAM_it);
        if ((-1 < iVar7) && (iVar7 < (int)PBEPARAM_it._12_4_)) {
          pAVar11 = PBEPARAM_it._8_4_ + iVar7;
          ppAVar10 = asn1_get_field_ptr((ASN1_VALUE **)pval,pAVar11);
          ASN1_template_free(ppAVar10,pAVar11);
          asn1_set_choice_selector((ASN1_VALUE **)pval,-1,(ASN1_ITEM *)PBEPARAM_it);
        }
      }
      puStack_4c = *in;
      ppPVar13 = (PBEPARAM **)0x0;
      if ((int)PBEPARAM_it._12_4_ < 1) {
LAB_005615e0:
        if (ppPVar13 == PBEPARAM_it._12_4_) {
LAB_00561a34:
          uVar14 = 0x8f;
          uVar4 = 0x15e;
          goto LAB_0056163c;
        }
      }
      else {
        pAVar11 = PBEPARAM_it._8_4_;
        do {
          ppAVar10 = asn1_get_field_ptr((ASN1_VALUE **)pval,pAVar11);
          iVar7 = asn1_template_ex_d2i(ppAVar10,&puStack_4c,lStack_50,pAVar11,1,auStack_44);
          if (iVar7 != -1) {
            if (0 < iVar7) goto LAB_005615e0;
            (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x78,0x3a,s_tasn_dec_c_0066a0bc,0x152);
            ASN1_item_ex_free((ASN1_VALUE **)pval,(ASN1_ITEM *)PBEPARAM_it);
            if (pAVar11 == (ASN1_TEMPLATE *)0x0) goto LAB_00561668;
            goto LAB_00561cf8;
          }
          ppPVar13 = (PBEPARAM **)((int)ppPVar13 + 1);
          pAVar11 = pAVar11 + 1;
        } while ((int)ppPVar13 < (int)PBEPARAM_it._12_4_);
        if (ppPVar13 == PBEPARAM_it._12_4_) goto LAB_00561a34;
      }
      asn1_set_choice_selector((ASN1_VALUE **)pval,(int)ppPVar13,(ASN1_ITEM *)PBEPARAM_it);
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
  pcStack_68 = *(code **)(PBEPARAM_it._16_4_ + 0x10);
  switch(PBEPARAM_it[0]) {
  case 0:
switchD_005619f8_caseD_0:
    if (PBEPARAM_it._8_4_ == (ASN1_TEMPLATE *)0x0) {
      iVar7 = asn1_d2i_ex_primitive(pval,in,len,PBEPARAM_it,0xffffffff,0,0,auStack_44);
      if (iVar7 < 1) {
        pPVar5 = (PBEPARAM *)0x0;
        ppPVar13 = (PBEPARAM **)in;
        goto LAB_00561684;
      }
    }
    else {
      iVar7 = asn1_template_ex_d2i(pval,in,len,PBEPARAM_it._8_4_,0,auStack_44);
      if (iVar7 < 1) goto switchD_005619f8_caseD_7;
    }
    goto LAB_005617a4;
  case 1:
  case 6:
switchD_00561550_caseD_1:
    puStack_4c = *in;
    ppPVar13 = (PBEPARAM **)0x0;
    iVar6 = asn1_check_tlen(&lStack_50,0,0,&cStack_56,&cStack_55,&puStack_4c,len,0x10,0,0,auStack_44
                           );
    if (iVar6 == 0) {
      uVar14 = 0x3a;
      uVar4 = 0x176;
    }
    else {
      pPVar5 = (PBEPARAM *)0x0;
      if (iVar6 == -1) goto LAB_00561684;
      cVar1 = cStack_56;
      if ((iVar7 != 0) && ((*(uint *)(iVar7 + 4) & 4) != 0)) {
        lStack_50 = len - ((int)puStack_4c - (int)*in);
        cVar1 = '\x01';
      }
      if (cStack_55 == '\0') {
        uVar14 = 0x95;
        uVar4 = 0x182;
      }
      else if ((*pval == (PBEPARAM *)0x0) &&
              (iVar7 = ASN1_item_ex_new((ASN1_VALUE **)pval,(ASN1_ITEM *)PBEPARAM_it), iVar7 == 0))
      {
        uVar14 = 0x3a;
        uVar4 = 0x187;
      }
      else {
        puStack_60 = auStack_44;
        if ((pcStack_68 != (code *)0x0) && (iVar7 = (*pcStack_68)(4,pval,PBEPARAM_it,0), iVar7 == 0)
           ) goto LAB_00561628;
        iVar7 = 0;
        ppPVar13 = PBEPARAM_it._12_4_;
        pAVar8 = PBEPARAM_it._8_4_;
        pAVar11 = PBEPARAM_it._8_4_;
        if (0 < (int)PBEPARAM_it._12_4_) {
          do {
            if ((pAVar11->flags & 0x300) != 0) {
              pAVar8 = asn1_do_adb((ASN1_VALUE **)pval,pAVar11,1);
              ppAVar10 = asn1_get_field_ptr((ASN1_VALUE **)pval,pAVar8);
              ASN1_template_free(ppAVar10,pAVar8);
              ppPVar13 = PBEPARAM_it._12_4_;
            }
            iVar7 = iVar7 + 1;
            pAVar11 = pAVar11 + 1;
          } while (iVar7 < (int)ppPVar13);
          iVar7 = 0;
          pAVar8 = PBEPARAM_it._8_4_;
          if (0 < (int)ppPVar13) {
            do {
              pAVar11 = asn1_do_adb((ASN1_VALUE **)pval,pAVar8,1);
              if (pAVar11 == (ASN1_TEMPLATE *)0x0) goto LAB_00561650;
              ppAVar10 = asn1_get_field_ptr((ASN1_VALUE **)pval,pAVar11);
              puVar3 = puStack_4c;
              if (lStack_50 == 0) {
                if (cStack_56 == '\0') goto LAB_00561c3c;
                goto LAB_00561e04;
              }
              if (((1 < lStack_50) && (*puStack_4c == '\0')) && (puStack_4c[1] == '\0')) {
                if (cStack_56 == '\0') {
                  uVar14 = 0x9f;
                  uVar4 = 0x1a7;
                  puStack_4c = puStack_4c + 2;
                  goto LAB_0056163c;
                }
                lStack_50 = lStack_50 + -2;
                cStack_56 = '\0';
                puStack_4c = puStack_4c + 2;
                goto LAB_00561c28;
              }
              uVar9 = 0;
              if ((int)PBEPARAM_it._12_4_ + -1 != iVar7) {
                uVar9 = pAVar11->flags & 1;
              }
              iVar6 = asn1_template_ex_d2i(ppAVar10,&puStack_4c,lStack_50,pAVar11,uVar9,puStack_60);
              if (iVar6 == 0) goto LAB_00561ce4;
              if (iVar6 == -1) {
                ASN1_template_free(ppAVar10,pAVar11);
              }
              else {
                lStack_50 = lStack_50 - ((int)puStack_4c - (int)puVar3);
              }
              iVar7 = iVar7 + 1;
              pAVar8 = pAVar8 + 1;
            } while (iVar7 < (int)PBEPARAM_it._12_4_);
          }
        }
        if (cStack_56 != '\0') {
          if (((lStack_50 < 2) || (*puStack_4c != '\0')) || (puStack_4c[1] != '\0')) {
LAB_00561e04:
            uVar14 = 0x89;
            uVar4 = 0x1ce;
            break;
          }
          puStack_4c = puStack_4c + 2;
        }
LAB_00561c28:
        if ((cVar1 != '\0') || (lStack_50 == 0)) {
LAB_00561c3c:
          if (iVar7 < (int)PBEPARAM_it._12_4_) {
LAB_00561c90:
            pAVar11 = asn1_do_adb((ASN1_VALUE **)pval,pAVar8,1);
            if (pAVar11 != (ASN1_TEMPLATE *)0x0) {
              if ((pAVar11->flags & 1) != 0) goto LAB_00561c54;
              (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x78,0x79,s_tasn_dec_c_0066a0bc,0x1e7);
LAB_00561ce4:
              ASN1_item_ex_free((ASN1_VALUE **)pval,(ASN1_ITEM *)PBEPARAM_it);
LAB_00561cf8:
              in = (uchar **)&DAT_0066a0d0;
              (*(code *)PTR_ERR_add_error_data_006a813c)
                        (4,&DAT_0066a0d0,pAVar11->field_name,", Type=",PBEPARAM_it._24_4_);
              goto switchD_005619f8_caseD_7;
            }
            goto LAB_00561650;
          }
          ppPVar13 = (PBEPARAM **)*in;
          goto LAB_00561a70;
        }
        uVar14 = 0x94;
        uVar4 = 0x1d3;
      }
    }
    break;
  case 2:
    if ((pcStack_68 == (code *)0x0) || (iVar7 = (*pcStack_68)(4,pval,PBEPARAM_it,0), iVar7 != 0))
    goto LAB_00561954;
    goto LAB_00561628;
  case 3:
switchD_005619f8_caseD_3:
    iVar7 = (**(code **)(PBEPARAM_it._16_4_ + 8))(pval,in,len);
    if (iVar7 != 0) {
      pPVar5 = *pval;
      ppPVar13 = (PBEPARAM **)in;
      goto LAB_00561684;
    }
    uVar14 = 0x3a;
    uVar4 = 0x12f;
    break;
  case 4:
LAB_005618f4:
    iVar7 = (*pcStack_68)(pval,in,len,PBEPARAM_it,0xffffffff,0,0,auStack_44);
    if (iVar7 < 1) {
      pPVar5 = (PBEPARAM *)0x0;
      ppPVar13 = (PBEPARAM **)in;
      goto LAB_00561684;
    }
LAB_005617a4:
    pPVar5 = *pval;
    ppPVar13 = (PBEPARAM **)in;
    goto LAB_00561684;
  case 5:
switchD_005619f8_caseD_5:
    puStack_4c = *in;
    iVar7 = asn1_check_tlen_constprop_1(0,&uStack_48,&cStack_57,0,0,&puStack_4c,len,1,auStack_44);
    if (iVar7 == 0) {
      uVar14 = 0x3a;
      uVar4 = 0xdb;
    }
    else if (cStack_57 == '\0') {
      if ((uStack_48 < 0x1f) && ((*(uint *)(tag2bit + uStack_48 * 4) & PBEPARAM_it._4_4_) != 0)) {
        iVar7 = asn1_d2i_ex_primitive(pval,in,lStack_50,PBEPARAM_it,uStack_48,0,0,auStack_44);
        if (iVar7 < 1) {
          pPVar5 = (PBEPARAM *)0x0;
          ppPVar13 = (PBEPARAM **)in;
          goto LAB_00561684;
        }
        goto LAB_005617a4;
      }
      uVar14 = 0x8c;
      uVar4 = 0xec;
    }
    else {
      uVar14 = 0x8b;
      uVar4 = 0xe4;
    }
    break;
  default:
    goto switchD_005619f8_caseD_7;
  }
LAB_0056163c:
  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x78,uVar14,s_tasn_dec_c_0066a0bc,uVar4);
LAB_00561650:
  ASN1_item_ex_free((ASN1_VALUE **)pval,(ASN1_ITEM *)PBEPARAM_it);
LAB_00561668:
  pcVar12 = s_Type__0066a0d8;
  (*(code *)PTR_ERR_add_error_data_006a813c)(2,s_Type__0066a0d8,PBEPARAM_it._24_4_);
  in = (uchar **)pcVar12;
switchD_005619f8_caseD_7:
  pPVar5 = (PBEPARAM *)0x0;
  ppPVar13 = (PBEPARAM **)in;
LAB_00561684:
  if (piStack_2c != *(int **)puVar2) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    return *(PBEPARAM **)((int)&ppPVar13[1]->salt + *piStack_2c);
  }
  return pPVar5;
LAB_00561c54:
  iVar7 = iVar7 + 1;
  ppAVar10 = asn1_get_field_ptr((ASN1_VALUE **)pval,pAVar11);
  pAVar8 = pAVar8 + 1;
  ASN1_template_free(ppAVar10,pAVar11);
  if ((int)PBEPARAM_it._12_4_ <= iVar7) goto LAB_00561a6c;
  goto LAB_00561c90;
LAB_00561a6c:
  ppPVar13 = (PBEPARAM **)*in;
LAB_00561a70:
  iVar7 = asn1_enc_save((ASN1_VALUE **)pval,(uchar *)ppPVar13,(int)puStack_4c - (int)ppPVar13,
                        (ASN1_ITEM *)PBEPARAM_it);
  if (iVar7 != 0) {
joined_r0x00561600:
    if ((pcStack_68 == (code *)0x0) ||
       (ppPVar13 = pval, iVar7 = (*pcStack_68)(5,pval,PBEPARAM_it,0), iVar7 != 0)) {
      *in = puStack_4c;
      pPVar5 = *pval;
      goto LAB_00561684;
    }
  }
LAB_00561628:
  uVar14 = 100;
  uVar4 = 0x1f7;
  goto LAB_0056163c;
}

