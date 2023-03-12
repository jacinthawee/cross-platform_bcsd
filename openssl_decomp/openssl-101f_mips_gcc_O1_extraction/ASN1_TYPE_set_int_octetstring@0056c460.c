
int ASN1_TYPE_set_int_octetstring(ASN1_TYPE *a,long num,uchar *data,int len)

{
  bool bVar1;
  char cVar2;
  undefined *puVar3;
  int *piVar4;
  int in_zero;
  ASN1_VALUE **ppAVar5;
  undefined4 uVar6;
  ASN1_VALUE *pAVar7;
  uint uVar8;
  ASN1_TEMPLATE *tt;
  int iVar9;
  int iVar10;
  ASN1_const_CTX *pAVar11;
  int *piVar12;
  uchar *puVar13;
  ASN1_VALUE **ppAVar14;
  uchar **ppuVar15;
  char *pcVar16;
  undefined4 uVar17;
  ASN1_VALUE **pval;
  ASN1_const_CTX *unaff_s0;
  undefined *puVar18;
  ASN1_TEMPLATE *tt_00;
  code *pcStack_170;
  undefined *puStack_168;
  char cStack_15f;
  char cStack_15e;
  char cStack_15d;
  ASN1_VALUE *pAStack_15c;
  int *piStack_158;
  ASN1_VALUE *pAStack_154;
  uint uStack_150;
  undefined auStack_14c [24];
  int *piStack_134;
  ASN1_INTEGER *pAStack_130;
  undefined *puStack_12c;
  ASN1_const_CTX *pAStack_128;
  int *piStack_124;
  int *piStack_120;
  ASN1_const_CTX *pAStack_11c;
  ASN1_OCTET_STRING *pAStack_118;
  uchar *puStack_e8;
  int iStack_e4;
  ASN1_const_CTX AStack_e0;
  ASN1_VALUE **ppAStack_b4;
  ASN1_const_CTX *pAStack_b0;
  uchar **ppuStack_ac;
  ASN1_const_CTX *pAStack_a8;
  undefined *puStack_a4;
  int *piStack_a0;
  ASN1_const_CTX *pAStack_9c;
  ASN1_TYPE *pAStack_98;
  code *pcStack_94;
  uchar *local_68;
  int local_64;
  undefined4 local_60;
  uchar *local_5c;
  undefined local_54 [48];
  int *local_24;
  
  puStack_a4 = PTR___stack_chk_guard_006aabf0;
  local_54._0_4_ = &DAT_00000020;
  local_60 = 4;
  local_54._8_4_ = local_54 + 0x10;
  pAStack_a8 = (ASN1_const_CTX *)local_54;
  piStack_a0 = &local_64;
  local_24 = *(int **)PTR___stack_chk_guard_006aabf0;
  local_64 = len;
  local_5c = data;
  ASN1_INTEGER_set((ASN1_INTEGER *)pAStack_a8,num);
  iVar9 = i2d_ASN1_INTEGER((ASN1_INTEGER *)pAStack_a8,(uchar **)0x0);
  piStack_120 = (int *)0x0;
  iVar10 = (*(code *)PTR_i2d_ASN1_bytes_006a9f10)(piStack_a0,0,4);
  pAStack_128 = (ASN1_const_CTX *)&SUB_00000010;
  ppuStack_ac = (uchar **)(iVar9 + iVar10);
  ppuVar15 = ppuStack_ac;
  pAStack_9c = (ASN1_const_CTX *)ASN1_object_size(1,(int)ppuStack_ac,0x10);
  pAVar11 = (ASN1_const_CTX *)ASN1_STRING_new();
  if (pAVar11 == (ASN1_const_CTX *)0x0) {
    iVar9 = 0;
  }
  else {
    ppuVar15 = (uchar **)0x0;
    pAStack_128 = pAStack_9c;
    iVar9 = ASN1_STRING_set((ASN1_STRING *)pAVar11,(void *)0x0,(int)pAStack_9c);
    unaff_s0 = pAVar11;
    if (iVar9 == 0) {
      ASN1_STRING_free((ASN1_STRING *)pAVar11);
    }
    else {
      local_68 = (uchar *)pAVar11->error;
      pAVar11->p = (uchar *)pAStack_9c;
      ASN1_put_object(&local_68,1,(int)ppuStack_ac,0x10,0);
      i2d_ASN1_INTEGER((ASN1_INTEGER *)pAStack_a8,&local_68);
      piStack_120 = (int *)0x0;
      (*(code *)PTR_i2d_ASN1_bytes_006a9f10)(piStack_a0,&local_68,4);
      ppuVar15 = (uchar **)&SUB_00000010;
      pAStack_128 = pAVar11;
      ASN1_TYPE_set(a,0x10,pAVar11);
      iVar9 = 1;
      ppuStack_ac = &local_68;
    }
  }
  if (local_24 == *(int **)puStack_a4) {
    return iVar9;
  }
  pcStack_94 = ASN1_TYPE_get_int_octetstring;
  piVar12 = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_12c = PTR___stack_chk_guard_006aabf0;
  ppAStack_b4 = *(ASN1_VALUE ***)PTR___stack_chk_guard_006aabf0;
  pAVar11 = pAStack_a8;
  piVar4 = piStack_a0;
  pAStack_11c = pAStack_9c;
  pAStack_b0 = unaff_s0;
  pAStack_98 = a;
  if ((*piVar12 == 0x10) && (piVar12 = (int *)piVar12[1], piVar12 != (int *)0x0)) {
    puStack_e8 = (uchar *)piVar12[2];
    iStack_e4 = *piVar12;
    pAStack_11c = &AStack_e0;
    AStack_e0.error = 0x6d;
    AStack_e0.max = puStack_e8 + iStack_e4;
    AStack_e0.pp = &puStack_e8;
    AStack_e0.p = puStack_e8;
    iVar9 = asn1_GetSequence(pAStack_11c,&iStack_e4);
    if (iVar9 == 0) {
      pAStack_130 = (ASN1_INTEGER *)0x0;
      AStack_e0.line = 0xa0;
      goto LAB_0056c818;
    }
    AStack_e0.q = AStack_e0.p;
    pAStack_130 = d2i_ASN1_INTEGER((ASN1_INTEGER **)0x0,&pAStack_11c->p,AStack_e0.slen);
    pAVar11 = pAStack_128;
    piVar4 = piStack_120;
    if (pAStack_130 == (ASN1_INTEGER *)0x0) goto LAB_0056c814;
    iVar9 = (int)AStack_e0.p - (int)AStack_e0.q;
    AStack_e0.q = AStack_e0.p;
    piVar12 = (int *)(AStack_e0.slen - iVar9);
    AStack_e0.slen = (long)piVar12;
    a = (ASN1_TYPE *)d2i_ASN1_OCTET_STRING((ASN1_OCTET_STRING **)0x0,&pAStack_11c->p,(long)piVar12);
    if ((ASN1_OCTET_STRING *)a == (ASN1_OCTET_STRING *)0x0) goto LAB_0056c818;
    AStack_e0.slen = AStack_e0.slen - ((int)AStack_e0.p - (int)AStack_e0.q);
    if ((AStack_e0.inf & 1U) == 0) {
      bVar1 = 0 < AStack_e0.slen;
    }
    else {
      AStack_e0.eos = ASN1_const_check_infinite_end(&pAStack_11c->p,AStack_e0.slen);
      bVar1 = AStack_e0.eos == 0;
    }
    pcVar16 = (char *)(uint)bVar1;
    if ((ASN1_VALUE **)pcVar16 == (ASN1_VALUE **)0x0) {
      if (ppuVar15 != (uchar **)0x0) {
        puVar13 = (uchar *)ASN1_INTEGER_get(pAStack_130);
        *ppuVar15 = puVar13;
      }
      piStack_124 = (int *)((ASN1_OCTET_STRING *)a)->length;
      if (pAStack_128 != (ASN1_const_CTX *)0x0) {
        if ((int)piStack_124 <= (int)piStack_120) {
          piStack_120 = piStack_124;
        }
        pcVar16 = *(char **)((int)a + 8);
        piVar12 = piStack_120;
        (*(code *)PTR_memcpy_006aabf4)(pAStack_128);
      }
    }
    else {
      piVar12 = (int *)&DAT_0000006d;
      pcVar16 = (char *)0x86;
      piStack_124 = (int *)0xffffffff;
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x86,0x6d,"evp_asn1.c");
    }
    ASN1_STRING_free((ASN1_STRING *)a);
LAB_0056c7d0:
    ASN1_STRING_free(pAStack_130);
  }
  else {
LAB_0056c814:
    piStack_120 = piVar4;
    pAStack_128 = pAVar11;
    pAStack_130 = (ASN1_INTEGER *)0x0;
LAB_0056c818:
    piVar12 = (int *)&DAT_0000006d;
    pcVar16 = (char *)0x86;
    piStack_124 = (int *)0xffffffff;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x86,0x6d,"evp_asn1.c");
    if (pAStack_130 != (ASN1_INTEGER *)0x0) goto LAB_0056c7d0;
  }
  if (ppAStack_b4 == *(ASN1_VALUE ***)puStack_12c) {
    return (int)piStack_124;
  }
  ppAVar14 = ppAStack_b4;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar3 = PTR___stack_chk_guard_006aabf0;
  iVar9 = PBEPARAM_it._16_4_;
  pAStack_118 = (ASN1_OCTET_STRING *)a;
  pAStack_15c = (ASN1_VALUE *)0x0;
  auStack_14c[0] = 0;
  piStack_158 = piVar12;
  pAStack_154 = (ASN1_VALUE *)0x0;
  pval = &pAStack_15c;
  if (ppAVar14 != (ASN1_VALUE **)0x0) {
    pval = ppAVar14;
  }
  piStack_134 = *(int **)PTR___stack_chk_guard_006aabf0;
  if (PBEPARAM_it._16_4_ == 0) {
    switch(PBEPARAM_it[0]) {
    case 0:
      goto switchD_00565630_caseD_0;
    case 1:
    case 6:
      pcStack_170 = (code *)0x0;
      goto switchD_005651a0_caseD_1;
    case 2:
      pcStack_170 = (code *)0x0;
LAB_005651ac:
      if ((*pval == (ASN1_VALUE *)0x0) &&
         (iVar9 = ASN1_item_ex_new(pval,(ASN1_ITEM *)PBEPARAM_it), iVar9 == 0)) {
        uVar17 = 0x3a;
        uVar6 = 0x13e;
        goto LAB_00565288;
      }
      pAStack_154 = *(ASN1_VALUE **)pcVar16;
      ppAVar14 = (ASN1_VALUE **)0x0;
      if ((int)PBEPARAM_it._12_4_ < 1) {
LAB_00565228:
        if (ppAVar14 == PBEPARAM_it._12_4_) {
LAB_0056566c:
          uVar17 = 0x8f;
          uVar6 = 0x162;
          goto LAB_00565288;
        }
      }
      else {
        tt = PBEPARAM_it._8_4_;
        do {
          ppAVar5 = asn1_get_field_ptr(pval,tt);
          iVar9 = asn1_template_ex_d2i(ppAVar5,&pAStack_154,piStack_158,tt,1,auStack_14c);
          if (iVar9 != -1) {
            if (0 < iVar9) goto LAB_00565228;
            (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x78,0x3a,s_tasn_dec_c_0066ab2c,0x153);
            ASN1_item_ex_free(pval,(ASN1_ITEM *)PBEPARAM_it);
            if (tt != (ASN1_TEMPLATE *)0x0) goto LAB_005657fc;
            goto LAB_005652b4;
          }
          ppAVar14 = (ASN1_VALUE **)((int)ppAVar14 + 1);
          tt = tt + 1;
        } while ((int)ppAVar14 < (int)PBEPARAM_it._12_4_);
        if (ppAVar14 == PBEPARAM_it._12_4_) goto LAB_0056566c;
      }
      asn1_set_choice_selector(pval,(int)ppAVar14,(ASN1_ITEM *)PBEPARAM_it);
      *(ASN1_VALUE **)pcVar16 = pAStack_154;
      if (pcStack_170 == (code *)0x0) goto LAB_00565328;
      goto LAB_00565258;
    case 3:
      goto switchD_00565630_caseD_3;
    case 4:
      pcStack_170 = *(code **)(in_zero + 0x10);
      goto LAB_005655ac;
    case 5:
      goto switchD_00565630_caseD_5;
    }
    goto switchD_00565630_caseD_7;
  }
  pcStack_170 = *(code **)(PBEPARAM_it._16_4_ + 0x10);
  switch(PBEPARAM_it[0]) {
  case 0:
switchD_00565630_caseD_0:
    if (PBEPARAM_it._8_4_ == (ASN1_TEMPLATE *)0x0) {
      iVar9 = asn1_d2i_ex_primitive(pval,pcVar16,piVar12,PBEPARAM_it,0xffffffff,0,0,auStack_14c);
      if (iVar9 < 1) {
        pAVar7 = (ASN1_VALUE *)0x0;
        ppAVar14 = (ASN1_VALUE **)pcVar16;
        goto LAB_005652d0;
      }
    }
    else {
      iVar9 = asn1_template_ex_d2i(pval,pcVar16,piVar12,PBEPARAM_it._8_4_,0,auStack_14c);
      if (iVar9 < 1) goto switchD_00565630_caseD_7;
    }
    goto LAB_005653f0;
  case 1:
  case 6:
switchD_005651a0_caseD_1:
    pAStack_154 = *(ASN1_VALUE **)pcVar16;
    ppAVar14 = (ASN1_VALUE **)0x0;
    iVar10 = asn1_check_tlen(&piStack_158,0,0,&cStack_15e,&cStack_15d,&pAStack_154,piVar12,0x10,0,0,
                             auStack_14c);
    if (iVar10 == 0) {
      uVar17 = 0x3a;
      uVar6 = 0x17d;
    }
    else {
      pAVar7 = (ASN1_VALUE *)0x0;
      if (iVar10 == -1) goto LAB_005652d0;
      cVar2 = cStack_15e;
      if ((iVar9 != 0) && ((*(uint *)(iVar9 + 4) & 4) != 0)) {
        piStack_158 = (int *)((int)piVar12 - ((int)pAStack_154 - (int)*(ASN1_VALUE **)pcVar16));
        cVar2 = '\x01';
      }
      if (cStack_15d == '\0') {
        uVar17 = 0x95;
        uVar6 = 0x18c;
      }
      else if ((*pval == (ASN1_VALUE *)0x0) &&
              (iVar9 = ASN1_item_ex_new(pval,(ASN1_ITEM *)PBEPARAM_it), iVar9 == 0)) {
        uVar17 = 0x3a;
        uVar6 = 0x193;
      }
      else {
        puStack_168 = auStack_14c;
        if ((pcStack_170 != (code *)0x0) &&
           (iVar9 = (*pcStack_170)(4,pval,PBEPARAM_it,0), iVar9 == 0)) goto LAB_00565278;
        puVar18 = (undefined *)0x0;
        tt_00 = PBEPARAM_it._8_4_;
        if (0 < (int)PBEPARAM_it._12_4_) {
          do {
            tt = asn1_do_adb(pval,tt_00,1);
            if (tt == (ASN1_TEMPLATE *)0x0) goto LAB_0056529c;
            ppAVar14 = asn1_get_field_ptr(pval,tt);
            pAVar7 = pAStack_154;
            if (piStack_158 == (int *)0x0) {
              if (cStack_15e != '\0') goto LAB_00565908;
              goto LAB_00565740;
            }
            if (((1 < (int)piStack_158) && (*pAStack_154 == (ASN1_VALUE)0x0)) &&
               (pAStack_154[1] == (ASN1_VALUE)0x0)) {
              if (cStack_15e != '\0') {
                piStack_158 = (int *)((int)piStack_158 + -2);
                cStack_15e = '\0';
                pAStack_154 = pAStack_154 + 2;
                goto LAB_0056572c;
              }
              uVar17 = 0x9f;
              uVar6 = 0x1ac;
              pAStack_154 = pAStack_154 + 2;
              goto LAB_00565288;
            }
            uVar8 = 0;
            if (puVar18 != (undefined *)((int)PBEPARAM_it._12_4_ + -1)) {
              uVar8 = tt->flags & 1;
            }
            iVar9 = asn1_template_ex_d2i(ppAVar14,&pAStack_154,piStack_158,tt,uVar8,puStack_168);
            if (iVar9 == 0) goto LAB_005657e8;
            if (iVar9 == -1) {
              ASN1_template_free(ppAVar14,tt);
            }
            else {
              piStack_158 = (int *)((int)piStack_158 - ((int)pAStack_154 - (int)pAVar7));
            }
            puVar18 = puVar18 + 1;
            tt_00 = tt_00 + 1;
          } while ((int)puVar18 < (int)PBEPARAM_it._12_4_);
        }
        if (cStack_15e != '\0') {
          if ((((int)piStack_158 < 2) || (*pAStack_154 != (ASN1_VALUE)0x0)) ||
             (pAStack_154[1] != (ASN1_VALUE)0x0)) {
LAB_00565908:
            uVar17 = 0x89;
            uVar6 = 0x1d6;
            break;
          }
          pAStack_154 = pAStack_154 + 2;
        }
LAB_0056572c:
        if ((cVar2 != '\0') || (piStack_158 == (int *)0x0)) {
LAB_00565740:
          if ((int)puVar18 < (int)PBEPARAM_it._12_4_) {
LAB_00565794:
            tt = asn1_do_adb(pval,tt_00,1);
            if (tt != (ASN1_TEMPLATE *)0x0) {
              if ((tt->flags & 1) != 0) goto LAB_00565758;
              (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x78,0x79,s_tasn_dec_c_0066ab2c,0x1f5);
LAB_005657e8:
              ASN1_item_ex_free(pval,(ASN1_ITEM *)PBEPARAM_it);
LAB_005657fc:
              pcVar16 = &DAT_0066ab40;
              (*(code *)PTR_ERR_add_error_data_006a9264)
                        (4,&DAT_0066ab40,tt->field_name,", Type=",PBEPARAM_it._24_4_);
              goto switchD_00565630_caseD_7;
            }
            goto LAB_0056529c;
          }
          ppAVar14 = *(ASN1_VALUE ***)pcVar16;
          goto LAB_00565954;
        }
        uVar17 = 0x94;
        uVar6 = 0x1dd;
      }
    }
    break;
  case 2:
    if ((pcStack_170 == (code *)0x0) || (iVar9 = (*pcStack_170)(4,pval,PBEPARAM_it,0), iVar9 != 0))
    goto LAB_005651ac;
    goto LAB_00565278;
  case 3:
switchD_00565630_caseD_3:
    iVar9 = (**(code **)(PBEPARAM_it._16_4_ + 8))(pval,pcVar16,piVar12);
    ppAVar14 = (ASN1_VALUE **)pcVar16;
    if (iVar9 != 0) goto LAB_00565328;
    uVar17 = 0x3a;
    uVar6 = 0x132;
    break;
  case 4:
LAB_005655ac:
    iVar9 = (*pcStack_170)(pval,pcVar16,piVar12,PBEPARAM_it,0xffffffff,0,0,auStack_14c);
    if (iVar9 < 1) {
      pAVar7 = (ASN1_VALUE *)0x0;
      ppAVar14 = (ASN1_VALUE **)pcVar16;
      goto LAB_005652d0;
    }
LAB_005653f0:
    pAVar7 = *pval;
    ppAVar14 = (ASN1_VALUE **)pcVar16;
    goto LAB_005652d0;
  case 5:
switchD_00565630_caseD_5:
    pAStack_154 = *(ASN1_VALUE **)pcVar16;
    iVar9 = asn1_check_tlen_constprop_1
                      (0,&uStack_150,&cStack_15f,0,0,&pAStack_154,piVar12,1,auStack_14c);
    if (iVar9 == 0) {
      uVar17 = 0x3a;
      uVar6 = 0xd2;
    }
    else if (cStack_15f == '\0') {
      if ((uStack_150 < 0x1f) && ((*(uint *)(tag2bit + uStack_150 * 4) & PBEPARAM_it._4_4_) != 0)) {
        iVar9 = asn1_d2i_ex_primitive
                          (pval,pcVar16,piStack_158,PBEPARAM_it,uStack_150,0,0,auStack_14c);
        if (iVar9 < 1) {
          pAVar7 = (ASN1_VALUE *)0x0;
          ppAVar14 = (ASN1_VALUE **)pcVar16;
          goto LAB_005652d0;
        }
        goto LAB_005653f0;
      }
      uVar17 = 0x8c;
      uVar6 = 0xe6;
    }
    else {
      uVar17 = 0x8b;
      uVar6 = 0xdc;
    }
    break;
  default:
    goto switchD_00565630_caseD_7;
  }
LAB_00565288:
  (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x78,uVar17,s_tasn_dec_c_0066ab2c,uVar6);
LAB_0056529c:
  ASN1_item_ex_free(pval,(ASN1_ITEM *)PBEPARAM_it);
LAB_005652b4:
  pcVar16 = s_Type__0066ab48;
  (*(code *)PTR_ERR_add_error_data_006a9264)(2,s_Type__0066ab48,PBEPARAM_it._24_4_);
switchD_00565630_caseD_7:
  pAVar7 = (ASN1_VALUE *)0x0;
  ppAVar14 = (ASN1_VALUE **)pcVar16;
LAB_005652d0:
  if (piStack_134 == *(int **)puVar3) {
    return (int)pAVar7;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  return *(int *)(ppAVar14[1] + *piStack_134);
LAB_00565758:
  puVar18 = puVar18 + 1;
  ppAVar14 = asn1_get_field_ptr(pval,tt);
  tt_00 = tt_00 + 1;
  ASN1_template_free(ppAVar14,tt);
  if ((int)PBEPARAM_it._12_4_ <= (int)puVar18) goto LAB_00565950;
  goto LAB_00565794;
LAB_00565950:
  ppAVar14 = *(ASN1_VALUE ***)pcVar16;
LAB_00565954:
  iVar9 = asn1_enc_save(pval,(uchar *)ppAVar14,(int)pAStack_154 - (int)ppAVar14,
                        (ASN1_ITEM *)PBEPARAM_it);
  if (iVar9 != 0) {
    *(ASN1_VALUE **)pcVar16 = pAStack_154;
    if (pcStack_170 == (code *)0x0) {
      pAVar7 = *pval;
      goto LAB_005652d0;
    }
LAB_00565258:
    ppAVar14 = pval;
    iVar9 = (*pcStack_170)(5,pval,PBEPARAM_it,0);
    if (iVar9 != 0) {
LAB_00565328:
      pAVar7 = *pval;
      goto LAB_005652d0;
    }
  }
LAB_00565278:
  uVar17 = 100;
  uVar6 = 0x205;
  goto LAB_00565288;
}

