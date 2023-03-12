
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
  ASN1_TEMPLATE *pAVar8;
  uint uVar9;
  ASN1_TEMPLATE *pAVar10;
  int iVar11;
  int iVar12;
  ASN1_const_CTX *pAVar13;
  int *piVar14;
  uchar *puVar15;
  ASN1_VALUE **ppAVar16;
  uchar **ppuVar17;
  char *pcVar18;
  undefined4 uVar19;
  ASN1_VALUE **pval;
  ASN1_const_CTX *unaff_s0;
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
  
  puStack_a4 = PTR___stack_chk_guard_006a9ae8;
  local_54._0_4_ = &DAT_00000020;
  local_60 = 4;
  local_54._8_4_ = local_54 + 0x10;
  pAStack_a8 = (ASN1_const_CTX *)local_54;
  piStack_a0 = &local_64;
  local_24 = *(int **)PTR___stack_chk_guard_006a9ae8;
  local_64 = len;
  local_5c = data;
  ASN1_INTEGER_set((ASN1_INTEGER *)pAStack_a8,num);
  iVar11 = i2d_ASN1_INTEGER((ASN1_INTEGER *)pAStack_a8,(uchar **)0x0);
  piStack_120 = (int *)0x0;
  iVar12 = (*(code *)PTR_i2d_ASN1_bytes_006a8df0)(piStack_a0,0,4);
  pAStack_128 = (ASN1_const_CTX *)&SUB_00000010;
  ppuStack_ac = (uchar **)(iVar11 + iVar12);
  ppuVar17 = ppuStack_ac;
  pAStack_9c = (ASN1_const_CTX *)ASN1_object_size(1,(int)ppuStack_ac,0x10);
  pAVar13 = (ASN1_const_CTX *)ASN1_STRING_new();
  if (pAVar13 == (ASN1_const_CTX *)0x0) {
    iVar11 = 0;
  }
  else {
    ppuVar17 = (uchar **)0x0;
    pAStack_128 = pAStack_9c;
    iVar11 = ASN1_STRING_set((ASN1_STRING *)pAVar13,(void *)0x0,(int)pAStack_9c);
    unaff_s0 = pAVar13;
    if (iVar11 == 0) {
      ASN1_STRING_free((ASN1_STRING *)pAVar13);
    }
    else {
      local_68 = (uchar *)pAVar13->error;
      pAVar13->p = (uchar *)pAStack_9c;
      ASN1_put_object(&local_68,1,(int)ppuStack_ac,0x10,0);
      i2d_ASN1_INTEGER((ASN1_INTEGER *)pAStack_a8,&local_68);
      piStack_120 = (int *)0x0;
      (*(code *)PTR_i2d_ASN1_bytes_006a8df0)(piStack_a0,&local_68,4);
      ppuVar17 = (uchar **)&SUB_00000010;
      pAStack_128 = pAVar13;
      ASN1_TYPE_set(a,0x10,pAVar13);
      iVar11 = 1;
      ppuStack_ac = &local_68;
    }
  }
  if (local_24 == *(int **)puStack_a4) {
    return iVar11;
  }
  pcStack_94 = ASN1_TYPE_get_int_octetstring;
  piVar14 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_12c = PTR___stack_chk_guard_006a9ae8;
  ppAStack_b4 = *(ASN1_VALUE ***)PTR___stack_chk_guard_006a9ae8;
  pAVar13 = pAStack_a8;
  piVar4 = piStack_a0;
  pAStack_11c = pAStack_9c;
  pAStack_b0 = unaff_s0;
  pAStack_98 = a;
  if ((*piVar14 == 0x10) && (piVar14 = (int *)piVar14[1], piVar14 != (int *)0x0)) {
    puStack_e8 = (uchar *)piVar14[2];
    iStack_e4 = *piVar14;
    pAStack_11c = &AStack_e0;
    AStack_e0.error = 0x6d;
    AStack_e0.max = puStack_e8 + iStack_e4;
    AStack_e0.pp = &puStack_e8;
    AStack_e0.p = puStack_e8;
    iVar11 = asn1_GetSequence(pAStack_11c,&iStack_e4);
    if (iVar11 == 0) {
      pAStack_130 = (ASN1_INTEGER *)0x0;
      AStack_e0.line = 0xa3;
      goto LAB_00568f28;
    }
    AStack_e0.q = AStack_e0.p;
    pAStack_130 = d2i_ASN1_INTEGER((ASN1_INTEGER **)0x0,&pAStack_11c->p,AStack_e0.slen);
    pAVar13 = pAStack_128;
    piVar4 = piStack_120;
    if (pAStack_130 == (ASN1_INTEGER *)0x0) goto LAB_00568f24;
    iVar11 = (int)AStack_e0.p - (int)AStack_e0.q;
    AStack_e0.q = AStack_e0.p;
    piVar14 = (int *)(AStack_e0.slen - iVar11);
    AStack_e0.slen = (long)piVar14;
    a = (ASN1_TYPE *)d2i_ASN1_OCTET_STRING((ASN1_OCTET_STRING **)0x0,&pAStack_11c->p,(long)piVar14);
    if ((ASN1_OCTET_STRING *)a == (ASN1_OCTET_STRING *)0x0) goto LAB_00568f28;
    AStack_e0.slen = AStack_e0.slen - ((int)AStack_e0.p - (int)AStack_e0.q);
    if ((AStack_e0.inf & 1U) == 0) {
      bVar1 = 0 < AStack_e0.slen;
    }
    else {
      AStack_e0.eos = ASN1_const_check_infinite_end(&pAStack_11c->p,AStack_e0.slen);
      bVar1 = AStack_e0.eos == 0;
    }
    pcVar18 = (char *)(uint)bVar1;
    if ((ASN1_VALUE **)pcVar18 == (ASN1_VALUE **)0x0) {
      if (ppuVar17 != (uchar **)0x0) {
        puVar15 = (uchar *)ASN1_INTEGER_get(pAStack_130);
        *ppuVar17 = puVar15;
      }
      piStack_124 = (int *)((ASN1_OCTET_STRING *)a)->length;
      if (pAStack_128 != (ASN1_const_CTX *)0x0) {
        if ((int)piStack_124 <= (int)piStack_120) {
          piStack_120 = piStack_124;
        }
        pcVar18 = *(char **)((int)a + 8);
        piVar14 = piStack_120;
        (*(code *)PTR_memcpy_006a9aec)(pAStack_128);
      }
    }
    else {
      piVar14 = (int *)&DAT_0000006d;
      pcVar18 = (char *)0x86;
      piStack_124 = (int *)0xffffffff;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x86,0x6d,"evp_asn1.c");
    }
    ASN1_STRING_free((ASN1_STRING *)a);
LAB_00568ee0:
    ASN1_STRING_free(pAStack_130);
  }
  else {
LAB_00568f24:
    piStack_120 = piVar4;
    pAStack_128 = pAVar13;
    pAStack_130 = (ASN1_INTEGER *)0x0;
LAB_00568f28:
    piVar14 = (int *)&DAT_0000006d;
    pcVar18 = (char *)0x86;
    piStack_124 = (int *)0xffffffff;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x86,0x6d,"evp_asn1.c");
    if (pAStack_130 != (ASN1_INTEGER *)0x0) goto LAB_00568ee0;
  }
  if (ppAStack_b4 == *(ASN1_VALUE ***)puStack_12c) {
    return (int)piStack_124;
  }
  ppAVar16 = ppAStack_b4;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  iVar11 = PBEPARAM_it._16_4_;
  pAStack_118 = (ASN1_OCTET_STRING *)a;
  pAStack_15c = (ASN1_VALUE *)0x0;
  auStack_14c[0] = 0;
  piStack_158 = piVar14;
  pAStack_154 = (ASN1_VALUE *)0x0;
  pval = &pAStack_15c;
  if (ppAVar16 != (ASN1_VALUE **)0x0) {
    pval = ppAVar16;
  }
  piStack_134 = *(int **)PTR___stack_chk_guard_006a9ae8;
  if (PBEPARAM_it._16_4_ == 0) {
    switch(PBEPARAM_it[0]) {
    case 0:
      goto switchD_005619f8_caseD_0;
    case 1:
    case 6:
      pcStack_170 = (code *)0x0;
      goto switchD_00561550_caseD_1;
    case 2:
      pcStack_170 = (code *)0x0;
LAB_00561954:
      if (*pval == (ASN1_VALUE *)0x0) {
        iVar11 = ASN1_item_ex_new(pval,(ASN1_ITEM *)PBEPARAM_it);
        if (iVar11 == 0) {
          uVar19 = 0x3a;
          uVar6 = 0x13f;
          goto LAB_0056163c;
        }
      }
      else {
        iVar11 = asn1_get_choice_selector(pval,(ASN1_ITEM *)PBEPARAM_it);
        if ((-1 < iVar11) && (iVar11 < (int)PBEPARAM_it._12_4_)) {
          pAVar10 = PBEPARAM_it._8_4_ + iVar11;
          ppAVar16 = asn1_get_field_ptr(pval,pAVar10);
          ASN1_template_free(ppAVar16,pAVar10);
          asn1_set_choice_selector(pval,-1,(ASN1_ITEM *)PBEPARAM_it);
        }
      }
      pAStack_154 = *(ASN1_VALUE **)pcVar18;
      ppAVar16 = (ASN1_VALUE **)0x0;
      if ((int)PBEPARAM_it._12_4_ < 1) {
LAB_005615e0:
        if (ppAVar16 == PBEPARAM_it._12_4_) {
LAB_00561a34:
          uVar19 = 0x8f;
          uVar6 = 0x15e;
          goto LAB_0056163c;
        }
      }
      else {
        pAVar10 = PBEPARAM_it._8_4_;
        do {
          ppAVar5 = asn1_get_field_ptr(pval,pAVar10);
          iVar11 = asn1_template_ex_d2i(ppAVar5,&pAStack_154,piStack_158,pAVar10,1,auStack_14c);
          if (iVar11 != -1) {
            if (0 < iVar11) goto LAB_005615e0;
            (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x78,0x3a,s_tasn_dec_c_0066a0bc,0x152);
            ASN1_item_ex_free(pval,(ASN1_ITEM *)PBEPARAM_it);
            if (pAVar10 == (ASN1_TEMPLATE *)0x0) goto LAB_00561668;
            goto LAB_00561cf8;
          }
          ppAVar16 = (ASN1_VALUE **)((int)ppAVar16 + 1);
          pAVar10 = pAVar10 + 1;
        } while ((int)ppAVar16 < (int)PBEPARAM_it._12_4_);
        if (ppAVar16 == PBEPARAM_it._12_4_) goto LAB_00561a34;
      }
      asn1_set_choice_selector(pval,(int)ppAVar16,(ASN1_ITEM *)PBEPARAM_it);
      goto joined_r0x00561600;
    case 3:
      goto switchD_005619f8_caseD_3;
    case 4:
      pcStack_170 = *(code **)(in_zero + 0x10);
      goto LAB_005618f4;
    case 5:
      goto switchD_005619f8_caseD_5;
    }
    goto switchD_005619f8_caseD_7;
  }
  pcStack_170 = *(code **)(PBEPARAM_it._16_4_ + 0x10);
  switch(PBEPARAM_it[0]) {
  case 0:
switchD_005619f8_caseD_0:
    if (PBEPARAM_it._8_4_ == (ASN1_TEMPLATE *)0x0) {
      iVar11 = asn1_d2i_ex_primitive(pval,pcVar18,piVar14,PBEPARAM_it,0xffffffff,0,0,auStack_14c);
      if (iVar11 < 1) {
        pAVar7 = (ASN1_VALUE *)0x0;
        ppAVar16 = (ASN1_VALUE **)pcVar18;
        goto LAB_00561684;
      }
    }
    else {
      iVar11 = asn1_template_ex_d2i(pval,pcVar18,piVar14,PBEPARAM_it._8_4_,0,auStack_14c);
      if (iVar11 < 1) goto switchD_005619f8_caseD_7;
    }
    goto LAB_005617a4;
  case 1:
  case 6:
switchD_00561550_caseD_1:
    pAStack_154 = *(ASN1_VALUE **)pcVar18;
    ppAVar16 = (ASN1_VALUE **)0x0;
    iVar12 = asn1_check_tlen(&piStack_158,0,0,&cStack_15e,&cStack_15d,&pAStack_154,piVar14,0x10,0,0,
                             auStack_14c);
    if (iVar12 == 0) {
      uVar19 = 0x3a;
      uVar6 = 0x176;
    }
    else {
      pAVar7 = (ASN1_VALUE *)0x0;
      if (iVar12 == -1) goto LAB_00561684;
      cVar2 = cStack_15e;
      if ((iVar11 != 0) && ((*(uint *)(iVar11 + 4) & 4) != 0)) {
        piStack_158 = (int *)((int)piVar14 - ((int)pAStack_154 - (int)*(ASN1_VALUE **)pcVar18));
        cVar2 = '\x01';
      }
      if (cStack_15d == '\0') {
        uVar19 = 0x95;
        uVar6 = 0x182;
      }
      else if ((*pval == (ASN1_VALUE *)0x0) &&
              (iVar11 = ASN1_item_ex_new(pval,(ASN1_ITEM *)PBEPARAM_it), iVar11 == 0)) {
        uVar19 = 0x3a;
        uVar6 = 0x187;
      }
      else {
        puStack_168 = auStack_14c;
        if ((pcStack_170 != (code *)0x0) &&
           (iVar11 = (*pcStack_170)(4,pval,PBEPARAM_it,0), iVar11 == 0)) goto LAB_00561628;
        iVar11 = 0;
        ppAVar16 = PBEPARAM_it._12_4_;
        pAVar8 = PBEPARAM_it._8_4_;
        pAVar10 = PBEPARAM_it._8_4_;
        if (0 < (int)PBEPARAM_it._12_4_) {
          do {
            if ((pAVar10->flags & 0x300) != 0) {
              pAVar8 = asn1_do_adb(pval,pAVar10,1);
              ppAVar16 = asn1_get_field_ptr(pval,pAVar8);
              ASN1_template_free(ppAVar16,pAVar8);
              ppAVar16 = PBEPARAM_it._12_4_;
            }
            iVar11 = iVar11 + 1;
            pAVar10 = pAVar10 + 1;
          } while (iVar11 < (int)ppAVar16);
          iVar11 = 0;
          pAVar8 = PBEPARAM_it._8_4_;
          if (0 < (int)ppAVar16) {
            do {
              pAVar10 = asn1_do_adb(pval,pAVar8,1);
              if (pAVar10 == (ASN1_TEMPLATE *)0x0) goto LAB_00561650;
              ppAVar16 = asn1_get_field_ptr(pval,pAVar10);
              pAVar7 = pAStack_154;
              if (piStack_158 == (int *)0x0) {
                if (cStack_15e == '\0') goto LAB_00561c3c;
                goto LAB_00561e04;
              }
              if (((1 < (int)piStack_158) && (*pAStack_154 == (ASN1_VALUE)0x0)) &&
                 (pAStack_154[1] == (ASN1_VALUE)0x0)) {
                if (cStack_15e == '\0') {
                  uVar19 = 0x9f;
                  uVar6 = 0x1a7;
                  pAStack_154 = pAStack_154 + 2;
                  goto LAB_0056163c;
                }
                piStack_158 = (int *)((int)piStack_158 + -2);
                cStack_15e = '\0';
                pAStack_154 = pAStack_154 + 2;
                goto LAB_00561c28;
              }
              uVar9 = 0;
              if ((int)PBEPARAM_it._12_4_ + -1 != iVar11) {
                uVar9 = pAVar10->flags & 1;
              }
              iVar12 = asn1_template_ex_d2i
                                 (ppAVar16,&pAStack_154,piStack_158,pAVar10,uVar9,puStack_168);
              if (iVar12 == 0) goto LAB_00561ce4;
              if (iVar12 == -1) {
                ASN1_template_free(ppAVar16,pAVar10);
              }
              else {
                piStack_158 = (int *)((int)piStack_158 - ((int)pAStack_154 - (int)pAVar7));
              }
              iVar11 = iVar11 + 1;
              pAVar8 = pAVar8 + 1;
            } while (iVar11 < (int)PBEPARAM_it._12_4_);
          }
        }
        if (cStack_15e != '\0') {
          if ((((int)piStack_158 < 2) || (*pAStack_154 != (ASN1_VALUE)0x0)) ||
             (pAStack_154[1] != (ASN1_VALUE)0x0)) {
LAB_00561e04:
            uVar19 = 0x89;
            uVar6 = 0x1ce;
            break;
          }
          pAStack_154 = pAStack_154 + 2;
        }
LAB_00561c28:
        if ((cVar2 != '\0') || (piStack_158 == (int *)0x0)) {
LAB_00561c3c:
          if (iVar11 < (int)PBEPARAM_it._12_4_) {
LAB_00561c90:
            pAVar10 = asn1_do_adb(pval,pAVar8,1);
            if (pAVar10 != (ASN1_TEMPLATE *)0x0) {
              if ((pAVar10->flags & 1) != 0) goto LAB_00561c54;
              (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x78,0x79,s_tasn_dec_c_0066a0bc,0x1e7);
LAB_00561ce4:
              ASN1_item_ex_free(pval,(ASN1_ITEM *)PBEPARAM_it);
LAB_00561cf8:
              pcVar18 = (char *)&DAT_0066a0d0;
              (*(code *)PTR_ERR_add_error_data_006a813c)
                        (4,&DAT_0066a0d0,pAVar10->field_name,", Type=",PBEPARAM_it._24_4_);
              goto switchD_005619f8_caseD_7;
            }
            goto LAB_00561650;
          }
          ppAVar16 = *(ASN1_VALUE ***)pcVar18;
          goto LAB_00561a70;
        }
        uVar19 = 0x94;
        uVar6 = 0x1d3;
      }
    }
    break;
  case 2:
    if ((pcStack_170 == (code *)0x0) || (iVar11 = (*pcStack_170)(4,pval,PBEPARAM_it,0), iVar11 != 0)
       ) goto LAB_00561954;
    goto LAB_00561628;
  case 3:
switchD_005619f8_caseD_3:
    iVar11 = (**(code **)(PBEPARAM_it._16_4_ + 8))(pval,pcVar18,piVar14);
    if (iVar11 != 0) {
      pAVar7 = *pval;
      ppAVar16 = (ASN1_VALUE **)pcVar18;
      goto LAB_00561684;
    }
    uVar19 = 0x3a;
    uVar6 = 0x12f;
    break;
  case 4:
LAB_005618f4:
    iVar11 = (*pcStack_170)(pval,pcVar18,piVar14,PBEPARAM_it,0xffffffff,0,0,auStack_14c);
    if (iVar11 < 1) {
      pAVar7 = (ASN1_VALUE *)0x0;
      ppAVar16 = (ASN1_VALUE **)pcVar18;
      goto LAB_00561684;
    }
LAB_005617a4:
    pAVar7 = *pval;
    ppAVar16 = (ASN1_VALUE **)pcVar18;
    goto LAB_00561684;
  case 5:
switchD_005619f8_caseD_5:
    pAStack_154 = *(ASN1_VALUE **)pcVar18;
    iVar11 = asn1_check_tlen_constprop_1
                       (0,&uStack_150,&cStack_15f,0,0,&pAStack_154,piVar14,1,auStack_14c);
    if (iVar11 == 0) {
      uVar19 = 0x3a;
      uVar6 = 0xdb;
    }
    else if (cStack_15f == '\0') {
      if ((uStack_150 < 0x1f) && ((*(uint *)(tag2bit + uStack_150 * 4) & PBEPARAM_it._4_4_) != 0)) {
        iVar11 = asn1_d2i_ex_primitive
                           (pval,pcVar18,piStack_158,PBEPARAM_it,uStack_150,0,0,auStack_14c);
        if (iVar11 < 1) {
          pAVar7 = (ASN1_VALUE *)0x0;
          ppAVar16 = (ASN1_VALUE **)pcVar18;
          goto LAB_00561684;
        }
        goto LAB_005617a4;
      }
      uVar19 = 0x8c;
      uVar6 = 0xec;
    }
    else {
      uVar19 = 0x8b;
      uVar6 = 0xe4;
    }
    break;
  default:
    goto switchD_005619f8_caseD_7;
  }
LAB_0056163c:
  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x78,uVar19,s_tasn_dec_c_0066a0bc,uVar6);
LAB_00561650:
  ASN1_item_ex_free(pval,(ASN1_ITEM *)PBEPARAM_it);
LAB_00561668:
  pcVar18 = s_Type__0066a0d8;
  (*(code *)PTR_ERR_add_error_data_006a813c)(2,s_Type__0066a0d8,PBEPARAM_it._24_4_);
switchD_005619f8_caseD_7:
  pAVar7 = (ASN1_VALUE *)0x0;
  ppAVar16 = (ASN1_VALUE **)pcVar18;
LAB_00561684:
  if (piStack_134 != *(int **)puVar3) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    return *(int *)(ppAVar16[1] + *piStack_134);
  }
  return (int)pAVar7;
LAB_00561c54:
  iVar11 = iVar11 + 1;
  ppAVar16 = asn1_get_field_ptr(pval,pAVar10);
  pAVar8 = pAVar8 + 1;
  ASN1_template_free(ppAVar16,pAVar10);
  if ((int)PBEPARAM_it._12_4_ <= iVar11) goto LAB_00561a6c;
  goto LAB_00561c90;
LAB_00561a6c:
  ppAVar16 = *(ASN1_VALUE ***)pcVar18;
LAB_00561a70:
  iVar11 = asn1_enc_save(pval,(uchar *)ppAVar16,(int)pAStack_154 - (int)ppAVar16,
                         (ASN1_ITEM *)PBEPARAM_it);
  if (iVar11 != 0) {
joined_r0x00561600:
    if ((pcStack_170 == (code *)0x0) ||
       (ppAVar16 = pval, iVar11 = (*pcStack_170)(5,pval,PBEPARAM_it,0), iVar11 != 0)) {
      *(ASN1_VALUE **)pcVar18 = pAStack_154;
      pAVar7 = *pval;
      goto LAB_00561684;
    }
  }
LAB_00561628:
  uVar19 = 100;
  uVar6 = 0x1f7;
  goto LAB_0056163c;
}

