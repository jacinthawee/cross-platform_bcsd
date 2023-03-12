
int ASN1_TYPE_get_int_octetstring(ASN1_TYPE *a,long *num,uchar *data,int max_len)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  undefined *puVar4;
  int in_zero;
  ASN1_VALUE **ppAVar5;
  undefined4 uVar6;
  ASN1_VALUE *pAVar7;
  int iVar8;
  uint uVar9;
  ASN1_TEMPLATE *tt;
  ASN1_STRING *pAVar10;
  int iVar11;
  long lVar12;
  ASN1_VALUE **ppAVar13;
  char *pcVar14;
  undefined4 uVar15;
  ASN1_VALUE **pval;
  undefined *puVar16;
  uchar *unaff_s2;
  ASN1_TEMPLATE *tt_00;
  int unaff_s4;
  ASN1_const_CTX *unaff_s5;
  ASN1_OCTET_STRING *unaff_s6;
  code *pcStack_e0;
  undefined *puStack_d8;
  char cStack_cf;
  char cStack_ce;
  char cStack_cd;
  ASN1_VALUE *pAStack_cc;
  int iStack_c8;
  ASN1_VALUE *pAStack_c4;
  uint uStack_c0;
  undefined auStack_bc [24];
  int *piStack_a4;
  ASN1_INTEGER *pAStack_a0;
  undefined *puStack_9c;
  uchar *puStack_98;
  int iStack_94;
  int iStack_90;
  ASN1_const_CTX *pAStack_8c;
  ASN1_OCTET_STRING *pAStack_88;
  uchar *local_58;
  int local_54;
  ASN1_const_CTX local_50;
  ASN1_VALUE **local_24;
  
  puStack_9c = PTR___stack_chk_guard_006aabf0;
  local_24 = *(ASN1_VALUE ***)PTR___stack_chk_guard_006aabf0;
  if ((a->type == 0x10) && (pAVar10 = (a->value).asn1_string, pAVar10 != (ASN1_STRING *)0x0)) {
    local_58 = pAVar10->data;
    local_54 = pAVar10->length;
    unaff_s5 = &local_50;
    local_50.error = 0x6d;
    local_50.max = local_58 + local_54;
    local_50.pp = &local_58;
    local_50.p = local_58;
    iVar11 = asn1_GetSequence(unaff_s5,&local_54);
    if (iVar11 == 0) {
      pAStack_a0 = (ASN1_INTEGER *)0x0;
      local_50.line = 0xa0;
      goto LAB_0056c818;
    }
    local_50.q = local_50.p;
    pAStack_a0 = d2i_ASN1_INTEGER((ASN1_INTEGER **)0x0,&unaff_s5->p,local_50.slen);
    unaff_s2 = data;
    unaff_s4 = max_len;
    if (pAStack_a0 == (ASN1_INTEGER *)0x0) goto LAB_0056c814;
    iVar11 = (int)local_50.p - (int)local_50.q;
    local_50.q = local_50.p;
    iVar11 = local_50.slen - iVar11;
    local_50.slen = iVar11;
    unaff_s6 = d2i_ASN1_OCTET_STRING((ASN1_OCTET_STRING **)0x0,&unaff_s5->p,iVar11);
    if (unaff_s6 == (ASN1_OCTET_STRING *)0x0) goto LAB_0056c818;
    local_50.slen = local_50.slen - ((int)local_50.p - (int)local_50.q);
    if ((local_50.inf & 1U) == 0) {
      bVar1 = 0 < local_50.slen;
    }
    else {
      local_50.eos = ASN1_const_check_infinite_end(&unaff_s5->p,local_50.slen);
      bVar1 = local_50.eos == 0;
    }
    pcVar14 = (char *)(uint)bVar1;
    if ((ASN1_VALUE **)pcVar14 == (ASN1_VALUE **)0x0) {
      if (num != (long *)0x0) {
        lVar12 = ASN1_INTEGER_get(pAStack_a0);
        *num = lVar12;
      }
      iStack_94 = unaff_s6->length;
      if (data != (uchar *)0x0) {
        if (iStack_94 <= max_len) {
          max_len = iStack_94;
        }
        pcVar14 = (char *)unaff_s6->data;
        iVar11 = max_len;
        (*(code *)PTR_memcpy_006aabf4)(data);
      }
    }
    else {
      iVar11 = 0x6d;
      pcVar14 = (char *)0x86;
      iStack_94 = -1;
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x86,0x6d,"evp_asn1.c");
    }
    ASN1_STRING_free(unaff_s6);
LAB_0056c7d0:
    ASN1_STRING_free(pAStack_a0);
  }
  else {
LAB_0056c814:
    max_len = unaff_s4;
    data = unaff_s2;
    pAStack_a0 = (ASN1_INTEGER *)0x0;
LAB_0056c818:
    iVar11 = 0x6d;
    pcVar14 = (char *)0x86;
    iStack_94 = -1;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x86,0x6d,"evp_asn1.c");
    if (pAStack_a0 != (ASN1_INTEGER *)0x0) goto LAB_0056c7d0;
  }
  if (local_24 == *(ASN1_VALUE ***)puStack_9c) {
    return iStack_94;
  }
  ppAVar13 = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar4 = PTR___stack_chk_guard_006aabf0;
  iVar3 = PBEPARAM_it._16_4_;
  puStack_98 = data;
  iStack_90 = max_len;
  pAStack_88 = unaff_s6;
  pAStack_8c = unaff_s5;
  pAStack_cc = (ASN1_VALUE *)0x0;
  auStack_bc[0] = 0;
  iStack_c8 = iVar11;
  pAStack_c4 = (ASN1_VALUE *)0x0;
  pval = &pAStack_cc;
  if (ppAVar13 != (ASN1_VALUE **)0x0) {
    pval = ppAVar13;
  }
  piStack_a4 = *(int **)PTR___stack_chk_guard_006aabf0;
  if (PBEPARAM_it._16_4_ == 0) {
    switch(PBEPARAM_it[0]) {
    case 0:
      goto switchD_00565630_caseD_0;
    case 1:
    case 6:
      pcStack_e0 = (code *)0x0;
      goto switchD_005651a0_caseD_1;
    case 2:
      pcStack_e0 = (code *)0x0;
LAB_005651ac:
      if ((*pval == (ASN1_VALUE *)0x0) &&
         (iVar11 = ASN1_item_ex_new(pval,(ASN1_ITEM *)PBEPARAM_it), iVar11 == 0)) {
        uVar15 = 0x3a;
        uVar6 = 0x13e;
        goto LAB_00565288;
      }
      pAStack_c4 = *(ASN1_VALUE **)pcVar14;
      ppAVar13 = (ASN1_VALUE **)0x0;
      if ((int)PBEPARAM_it._12_4_ < 1) {
LAB_00565228:
        if (ppAVar13 == PBEPARAM_it._12_4_) {
LAB_0056566c:
          uVar15 = 0x8f;
          uVar6 = 0x162;
          goto LAB_00565288;
        }
      }
      else {
        tt = PBEPARAM_it._8_4_;
        do {
          ppAVar5 = asn1_get_field_ptr(pval,tt);
          iVar11 = asn1_template_ex_d2i(ppAVar5,&pAStack_c4,iStack_c8,tt,1,auStack_bc);
          if (iVar11 != -1) {
            if (0 < iVar11) goto LAB_00565228;
            (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x78,0x3a,s_tasn_dec_c_0066ab0c,0x153);
            ASN1_item_ex_free(pval,(ASN1_ITEM *)PBEPARAM_it);
            if (tt != (ASN1_TEMPLATE *)0x0) goto LAB_005657fc;
            goto LAB_005652b4;
          }
          ppAVar13 = (ASN1_VALUE **)((int)ppAVar13 + 1);
          tt = tt + 1;
        } while ((int)ppAVar13 < (int)PBEPARAM_it._12_4_);
        if (ppAVar13 == PBEPARAM_it._12_4_) goto LAB_0056566c;
      }
      asn1_set_choice_selector(pval,(int)ppAVar13,(ASN1_ITEM *)PBEPARAM_it);
      *(ASN1_VALUE **)pcVar14 = pAStack_c4;
      if (pcStack_e0 == (code *)0x0) goto LAB_00565328;
      goto LAB_00565258;
    case 3:
      goto switchD_00565630_caseD_3;
    case 4:
      pcStack_e0 = *(code **)(in_zero + 0x10);
      goto LAB_005655ac;
    case 5:
      goto switchD_00565630_caseD_5;
    }
    goto switchD_00565630_caseD_7;
  }
  pcStack_e0 = *(code **)(PBEPARAM_it._16_4_ + 0x10);
  switch(PBEPARAM_it[0]) {
  case 0:
switchD_00565630_caseD_0:
    if (PBEPARAM_it._8_4_ == (ASN1_TEMPLATE *)0x0) {
      iVar11 = asn1_d2i_ex_primitive(pval,pcVar14,iVar11,PBEPARAM_it,0xffffffff,0,0,auStack_bc);
      if (iVar11 < 1) {
        pAVar7 = (ASN1_VALUE *)0x0;
        ppAVar13 = (ASN1_VALUE **)pcVar14;
        goto LAB_005652d0;
      }
    }
    else {
      iVar11 = asn1_template_ex_d2i(pval,pcVar14,iVar11,PBEPARAM_it._8_4_,0,auStack_bc);
      if (iVar11 < 1) goto switchD_00565630_caseD_7;
    }
    goto LAB_005653f0;
  case 1:
  case 6:
switchD_005651a0_caseD_1:
    pAStack_c4 = *(ASN1_VALUE **)pcVar14;
    ppAVar13 = (ASN1_VALUE **)0x0;
    iVar8 = asn1_check_tlen(&iStack_c8,0,0,&cStack_ce,&cStack_cd,&pAStack_c4,iVar11,0x10,0,0,
                            auStack_bc);
    if (iVar8 == 0) {
      uVar15 = 0x3a;
      uVar6 = 0x17d;
    }
    else {
      pAVar7 = (ASN1_VALUE *)0x0;
      if (iVar8 == -1) goto LAB_005652d0;
      cVar2 = cStack_ce;
      if ((iVar3 != 0) && ((*(uint *)(iVar3 + 4) & 4) != 0)) {
        iStack_c8 = iVar11 - ((int)pAStack_c4 - (int)*(ASN1_VALUE **)pcVar14);
        cVar2 = '\x01';
      }
      if (cStack_cd == '\0') {
        uVar15 = 0x95;
        uVar6 = 0x18c;
      }
      else if ((*pval == (ASN1_VALUE *)0x0) &&
              (iVar11 = ASN1_item_ex_new(pval,(ASN1_ITEM *)PBEPARAM_it), iVar11 == 0)) {
        uVar15 = 0x3a;
        uVar6 = 0x193;
      }
      else {
        puStack_d8 = auStack_bc;
        if ((pcStack_e0 != (code *)0x0) &&
           (iVar11 = (*pcStack_e0)(4,pval,PBEPARAM_it,0), iVar11 == 0)) goto LAB_00565278;
        puVar16 = (undefined *)0x0;
        tt_00 = PBEPARAM_it._8_4_;
        if (0 < (int)PBEPARAM_it._12_4_) {
          do {
            tt = asn1_do_adb(pval,tt_00,1);
            if (tt == (ASN1_TEMPLATE *)0x0) goto LAB_0056529c;
            ppAVar13 = asn1_get_field_ptr(pval,tt);
            pAVar7 = pAStack_c4;
            if (iStack_c8 == 0) {
              if (cStack_ce != '\0') goto LAB_00565908;
              goto LAB_00565740;
            }
            if (((1 < iStack_c8) && (*pAStack_c4 == (ASN1_VALUE)0x0)) &&
               (pAStack_c4[1] == (ASN1_VALUE)0x0)) {
              if (cStack_ce != '\0') {
                iStack_c8 = iStack_c8 + -2;
                cStack_ce = '\0';
                pAStack_c4 = pAStack_c4 + 2;
                goto LAB_0056572c;
              }
              uVar15 = 0x9f;
              uVar6 = 0x1ac;
              pAStack_c4 = pAStack_c4 + 2;
              goto LAB_00565288;
            }
            uVar9 = 0;
            if (puVar16 != (undefined *)((int)PBEPARAM_it._12_4_ + -1)) {
              uVar9 = tt->flags & 1;
            }
            iVar11 = asn1_template_ex_d2i(ppAVar13,&pAStack_c4,iStack_c8,tt,uVar9,puStack_d8);
            if (iVar11 == 0) goto LAB_005657e8;
            if (iVar11 == -1) {
              ASN1_template_free(ppAVar13,tt);
            }
            else {
              iStack_c8 = iStack_c8 - ((int)pAStack_c4 - (int)pAVar7);
            }
            puVar16 = puVar16 + 1;
            tt_00 = tt_00 + 1;
          } while ((int)puVar16 < (int)PBEPARAM_it._12_4_);
        }
        if (cStack_ce != '\0') {
          if (((iStack_c8 < 2) || (*pAStack_c4 != (ASN1_VALUE)0x0)) ||
             (pAStack_c4[1] != (ASN1_VALUE)0x0)) {
LAB_00565908:
            uVar15 = 0x89;
            uVar6 = 0x1d6;
            break;
          }
          pAStack_c4 = pAStack_c4 + 2;
        }
LAB_0056572c:
        if ((cVar2 != '\0') || (iStack_c8 == 0)) {
LAB_00565740:
          if ((int)puVar16 < (int)PBEPARAM_it._12_4_) {
LAB_00565794:
            tt = asn1_do_adb(pval,tt_00,1);
            if (tt != (ASN1_TEMPLATE *)0x0) {
              if ((tt->flags & 1) != 0) goto LAB_00565758;
              (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x78,0x79,s_tasn_dec_c_0066ab0c,0x1f5);
LAB_005657e8:
              ASN1_item_ex_free(pval,(ASN1_ITEM *)PBEPARAM_it);
LAB_005657fc:
              pcVar14 = &DAT_0066ab20;
              (*(code *)PTR_ERR_add_error_data_006a9264)
                        (4,&DAT_0066ab20,tt->field_name,", Type=",PBEPARAM_it._24_4_);
              goto switchD_00565630_caseD_7;
            }
            goto LAB_0056529c;
          }
          ppAVar13 = *(ASN1_VALUE ***)pcVar14;
          goto LAB_00565954;
        }
        uVar15 = 0x94;
        uVar6 = 0x1dd;
      }
    }
    break;
  case 2:
    if ((pcStack_e0 == (code *)0x0) || (iVar11 = (*pcStack_e0)(4,pval,PBEPARAM_it,0), iVar11 != 0))
    goto LAB_005651ac;
    goto LAB_00565278;
  case 3:
switchD_00565630_caseD_3:
    iVar11 = (**(code **)(PBEPARAM_it._16_4_ + 8))(pval,pcVar14,iVar11);
    ppAVar13 = (ASN1_VALUE **)pcVar14;
    if (iVar11 != 0) goto LAB_00565328;
    uVar15 = 0x3a;
    uVar6 = 0x132;
    break;
  case 4:
LAB_005655ac:
    iVar11 = (*pcStack_e0)(pval,pcVar14,iVar11,PBEPARAM_it,0xffffffff,0,0,auStack_bc);
    if (iVar11 < 1) {
      pAVar7 = (ASN1_VALUE *)0x0;
      ppAVar13 = (ASN1_VALUE **)pcVar14;
      goto LAB_005652d0;
    }
LAB_005653f0:
    pAVar7 = *pval;
    ppAVar13 = (ASN1_VALUE **)pcVar14;
    goto LAB_005652d0;
  case 5:
switchD_00565630_caseD_5:
    pAStack_c4 = *(ASN1_VALUE **)pcVar14;
    iVar11 = asn1_check_tlen_constprop_1
                       (0,&uStack_c0,&cStack_cf,0,0,&pAStack_c4,iVar11,1,auStack_bc);
    if (iVar11 == 0) {
      uVar15 = 0x3a;
      uVar6 = 0xd2;
    }
    else if (cStack_cf == '\0') {
      if ((uStack_c0 < 0x1f) && ((*(uint *)(tag2bit + uStack_c0 * 4) & PBEPARAM_it._4_4_) != 0)) {
        iVar11 = asn1_d2i_ex_primitive(pval,pcVar14,iStack_c8,PBEPARAM_it,uStack_c0,0,0,auStack_bc);
        if (iVar11 < 1) {
          pAVar7 = (ASN1_VALUE *)0x0;
          ppAVar13 = (ASN1_VALUE **)pcVar14;
          goto LAB_005652d0;
        }
        goto LAB_005653f0;
      }
      uVar15 = 0x8c;
      uVar6 = 0xe6;
    }
    else {
      uVar15 = 0x8b;
      uVar6 = 0xdc;
    }
    break;
  default:
    goto switchD_00565630_caseD_7;
  }
LAB_00565288:
  (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x78,uVar15,s_tasn_dec_c_0066ab0c,uVar6);
LAB_0056529c:
  ASN1_item_ex_free(pval,(ASN1_ITEM *)PBEPARAM_it);
LAB_005652b4:
  pcVar14 = s_Type__0066ab28;
  (*(code *)PTR_ERR_add_error_data_006a9264)(2,s_Type__0066ab28,PBEPARAM_it._24_4_);
switchD_00565630_caseD_7:
  pAVar7 = (ASN1_VALUE *)0x0;
  ppAVar13 = (ASN1_VALUE **)pcVar14;
LAB_005652d0:
  if (piStack_a4 == *(int **)puVar4) {
    return (int)pAVar7;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  return *(int *)(ppAVar13[1] + *piStack_a4);
LAB_00565758:
  puVar16 = puVar16 + 1;
  ppAVar13 = asn1_get_field_ptr(pval,tt);
  tt_00 = tt_00 + 1;
  ASN1_template_free(ppAVar13,tt);
  if ((int)PBEPARAM_it._12_4_ <= (int)puVar16) goto LAB_00565950;
  goto LAB_00565794;
LAB_00565950:
  ppAVar13 = *(ASN1_VALUE ***)pcVar14;
LAB_00565954:
  iVar11 = asn1_enc_save(pval,(uchar *)ppAVar13,(int)pAStack_c4 - (int)ppAVar13,
                         (ASN1_ITEM *)PBEPARAM_it);
  if (iVar11 != 0) {
    *(ASN1_VALUE **)pcVar14 = pAStack_c4;
    if (pcStack_e0 == (code *)0x0) {
      pAVar7 = *pval;
      goto LAB_005652d0;
    }
LAB_00565258:
    ppAVar13 = pval;
    iVar11 = (*pcStack_e0)(5,pval,PBEPARAM_it,0);
    if (iVar11 != 0) {
LAB_00565328:
      pAVar7 = *pval;
      goto LAB_005652d0;
    }
  }
LAB_00565278:
  uVar15 = 100;
  uVar6 = 0x205;
  goto LAB_00565288;
}

