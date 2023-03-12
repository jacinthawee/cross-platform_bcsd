
int ASN1_TYPE_get_int_octetstring(ASN1_TYPE *a,long *num,uchar *data,int max_len)

{
  bool bVar1;
  char cVar2;
  undefined *puVar3;
  int in_zero;
  ASN1_VALUE **ppAVar4;
  undefined4 uVar5;
  ASN1_VALUE *pAVar6;
  int iVar7;
  ASN1_TEMPLATE *pAVar8;
  int iVar9;
  uint uVar10;
  ASN1_TEMPLATE *pAVar11;
  ASN1_STRING *pAVar12;
  int iVar13;
  long lVar14;
  ASN1_VALUE **ppAVar15;
  char *pcVar16;
  undefined4 uVar17;
  ASN1_VALUE **pval;
  uchar *unaff_s2;
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
  
  puStack_9c = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(ASN1_VALUE ***)PTR___stack_chk_guard_006a9ae8;
  if ((a->type == 0x10) && (pAVar12 = (a->value).asn1_string, pAVar12 != (ASN1_STRING *)0x0)) {
    local_58 = pAVar12->data;
    local_54 = pAVar12->length;
    unaff_s5 = &local_50;
    local_50.error = 0x6d;
    local_50.max = local_58 + local_54;
    local_50.pp = &local_58;
    local_50.p = local_58;
    iVar13 = asn1_GetSequence(unaff_s5,&local_54);
    if (iVar13 == 0) {
      pAStack_a0 = (ASN1_INTEGER *)0x0;
      local_50.line = 0xa3;
      goto LAB_00568f28;
    }
    local_50.q = local_50.p;
    pAStack_a0 = d2i_ASN1_INTEGER((ASN1_INTEGER **)0x0,&unaff_s5->p,local_50.slen);
    unaff_s2 = data;
    unaff_s4 = max_len;
    if (pAStack_a0 == (ASN1_INTEGER *)0x0) goto LAB_00568f24;
    iVar13 = (int)local_50.p - (int)local_50.q;
    local_50.q = local_50.p;
    iVar13 = local_50.slen - iVar13;
    local_50.slen = iVar13;
    unaff_s6 = d2i_ASN1_OCTET_STRING((ASN1_OCTET_STRING **)0x0,&unaff_s5->p,iVar13);
    if (unaff_s6 == (ASN1_OCTET_STRING *)0x0) goto LAB_00568f28;
    local_50.slen = local_50.slen - ((int)local_50.p - (int)local_50.q);
    if ((local_50.inf & 1U) == 0) {
      bVar1 = 0 < local_50.slen;
    }
    else {
      local_50.eos = ASN1_const_check_infinite_end(&unaff_s5->p,local_50.slen);
      bVar1 = local_50.eos == 0;
    }
    pcVar16 = (char *)(uint)bVar1;
    if ((ASN1_VALUE **)pcVar16 == (ASN1_VALUE **)0x0) {
      if (num != (long *)0x0) {
        lVar14 = ASN1_INTEGER_get(pAStack_a0);
        *num = lVar14;
      }
      iStack_94 = unaff_s6->length;
      if (data != (uchar *)0x0) {
        if (iStack_94 <= max_len) {
          max_len = iStack_94;
        }
        pcVar16 = (char *)unaff_s6->data;
        iVar13 = max_len;
        (*(code *)PTR_memcpy_006a9aec)(data);
      }
    }
    else {
      iVar13 = 0x6d;
      pcVar16 = (char *)0x86;
      iStack_94 = -1;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x86,0x6d,"evp_asn1.c");
    }
    ASN1_STRING_free(unaff_s6);
LAB_00568ee0:
    ASN1_STRING_free(pAStack_a0);
  }
  else {
LAB_00568f24:
    max_len = unaff_s4;
    data = unaff_s2;
    pAStack_a0 = (ASN1_INTEGER *)0x0;
LAB_00568f28:
    iVar13 = 0x6d;
    pcVar16 = (char *)0x86;
    iStack_94 = -1;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x86,0x6d,"evp_asn1.c");
    if (pAStack_a0 != (ASN1_INTEGER *)0x0) goto LAB_00568ee0;
  }
  if (local_24 == *(ASN1_VALUE ***)puStack_9c) {
    return iStack_94;
  }
  ppAVar15 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  iVar9 = PBEPARAM_it._16_4_;
  puStack_98 = data;
  iStack_90 = max_len;
  pAStack_88 = unaff_s6;
  pAStack_8c = unaff_s5;
  pAStack_cc = (ASN1_VALUE *)0x0;
  auStack_bc[0] = 0;
  iStack_c8 = iVar13;
  pAStack_c4 = (ASN1_VALUE *)0x0;
  pval = &pAStack_cc;
  if (ppAVar15 != (ASN1_VALUE **)0x0) {
    pval = ppAVar15;
  }
  piStack_a4 = *(int **)PTR___stack_chk_guard_006a9ae8;
  if (PBEPARAM_it._16_4_ == 0) {
    switch(PBEPARAM_it[0]) {
    case 0:
      goto switchD_005619f8_caseD_0;
    case 1:
    case 6:
      pcStack_e0 = (code *)0x0;
      goto switchD_00561550_caseD_1;
    case 2:
      pcStack_e0 = (code *)0x0;
LAB_00561954:
      if (*pval == (ASN1_VALUE *)0x0) {
        iVar13 = ASN1_item_ex_new(pval,(ASN1_ITEM *)PBEPARAM_it);
        if (iVar13 == 0) {
          uVar17 = 0x3a;
          uVar5 = 0x13f;
          goto LAB_0056163c;
        }
      }
      else {
        iVar13 = asn1_get_choice_selector(pval,(ASN1_ITEM *)PBEPARAM_it);
        if ((-1 < iVar13) && (iVar13 < (int)PBEPARAM_it._12_4_)) {
          pAVar11 = PBEPARAM_it._8_4_ + iVar13;
          ppAVar15 = asn1_get_field_ptr(pval,pAVar11);
          ASN1_template_free(ppAVar15,pAVar11);
          asn1_set_choice_selector(pval,-1,(ASN1_ITEM *)PBEPARAM_it);
        }
      }
      pAStack_c4 = *(ASN1_VALUE **)pcVar16;
      ppAVar15 = (ASN1_VALUE **)0x0;
      if ((int)PBEPARAM_it._12_4_ < 1) {
LAB_005615e0:
        if (ppAVar15 == PBEPARAM_it._12_4_) {
LAB_00561a34:
          uVar17 = 0x8f;
          uVar5 = 0x15e;
          goto LAB_0056163c;
        }
      }
      else {
        pAVar11 = PBEPARAM_it._8_4_;
        do {
          ppAVar4 = asn1_get_field_ptr(pval,pAVar11);
          iVar13 = asn1_template_ex_d2i(ppAVar4,&pAStack_c4,iStack_c8,pAVar11,1,auStack_bc);
          if (iVar13 != -1) {
            if (0 < iVar13) goto LAB_005615e0;
            (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x78,0x3a,s_tasn_dec_c_0066a0bc,0x152);
            ASN1_item_ex_free(pval,(ASN1_ITEM *)PBEPARAM_it);
            if (pAVar11 == (ASN1_TEMPLATE *)0x0) goto LAB_00561668;
            goto LAB_00561cf8;
          }
          ppAVar15 = (ASN1_VALUE **)((int)ppAVar15 + 1);
          pAVar11 = pAVar11 + 1;
        } while ((int)ppAVar15 < (int)PBEPARAM_it._12_4_);
        if (ppAVar15 == PBEPARAM_it._12_4_) goto LAB_00561a34;
      }
      asn1_set_choice_selector(pval,(int)ppAVar15,(ASN1_ITEM *)PBEPARAM_it);
      goto joined_r0x00561600;
    case 3:
      goto switchD_005619f8_caseD_3;
    case 4:
      pcStack_e0 = *(code **)(in_zero + 0x10);
      goto LAB_005618f4;
    case 5:
      goto switchD_005619f8_caseD_5;
    }
    goto switchD_005619f8_caseD_7;
  }
  pcStack_e0 = *(code **)(PBEPARAM_it._16_4_ + 0x10);
  switch(PBEPARAM_it[0]) {
  case 0:
switchD_005619f8_caseD_0:
    if (PBEPARAM_it._8_4_ == (ASN1_TEMPLATE *)0x0) {
      iVar13 = asn1_d2i_ex_primitive(pval,pcVar16,iVar13,PBEPARAM_it,0xffffffff,0,0,auStack_bc);
      if (iVar13 < 1) {
        pAVar6 = (ASN1_VALUE *)0x0;
        ppAVar15 = (ASN1_VALUE **)pcVar16;
        goto LAB_00561684;
      }
    }
    else {
      iVar13 = asn1_template_ex_d2i(pval,pcVar16,iVar13,PBEPARAM_it._8_4_,0,auStack_bc);
      if (iVar13 < 1) goto switchD_005619f8_caseD_7;
    }
    goto LAB_005617a4;
  case 1:
  case 6:
switchD_00561550_caseD_1:
    pAStack_c4 = *(ASN1_VALUE **)pcVar16;
    ppAVar15 = (ASN1_VALUE **)0x0;
    iVar7 = asn1_check_tlen(&iStack_c8,0,0,&cStack_ce,&cStack_cd,&pAStack_c4,iVar13,0x10,0,0,
                            auStack_bc);
    if (iVar7 == 0) {
      uVar17 = 0x3a;
      uVar5 = 0x176;
    }
    else {
      pAVar6 = (ASN1_VALUE *)0x0;
      if (iVar7 == -1) goto LAB_00561684;
      cVar2 = cStack_ce;
      if ((iVar9 != 0) && ((*(uint *)(iVar9 + 4) & 4) != 0)) {
        iStack_c8 = iVar13 - ((int)pAStack_c4 - (int)*(ASN1_VALUE **)pcVar16);
        cVar2 = '\x01';
      }
      if (cStack_cd == '\0') {
        uVar17 = 0x95;
        uVar5 = 0x182;
      }
      else if ((*pval == (ASN1_VALUE *)0x0) &&
              (iVar13 = ASN1_item_ex_new(pval,(ASN1_ITEM *)PBEPARAM_it), iVar13 == 0)) {
        uVar17 = 0x3a;
        uVar5 = 0x187;
      }
      else {
        puStack_d8 = auStack_bc;
        if ((pcStack_e0 != (code *)0x0) &&
           (iVar13 = (*pcStack_e0)(4,pval,PBEPARAM_it,0), iVar13 == 0)) goto LAB_00561628;
        iVar13 = 0;
        ppAVar15 = PBEPARAM_it._12_4_;
        pAVar8 = PBEPARAM_it._8_4_;
        pAVar11 = PBEPARAM_it._8_4_;
        if (0 < (int)PBEPARAM_it._12_4_) {
          do {
            if ((pAVar11->flags & 0x300) != 0) {
              pAVar8 = asn1_do_adb(pval,pAVar11,1);
              ppAVar15 = asn1_get_field_ptr(pval,pAVar8);
              ASN1_template_free(ppAVar15,pAVar8);
              ppAVar15 = PBEPARAM_it._12_4_;
            }
            iVar13 = iVar13 + 1;
            pAVar11 = pAVar11 + 1;
          } while (iVar13 < (int)ppAVar15);
          iVar13 = 0;
          pAVar8 = PBEPARAM_it._8_4_;
          if (0 < (int)ppAVar15) {
            do {
              pAVar11 = asn1_do_adb(pval,pAVar8,1);
              if (pAVar11 == (ASN1_TEMPLATE *)0x0) goto LAB_00561650;
              ppAVar15 = asn1_get_field_ptr(pval,pAVar11);
              pAVar6 = pAStack_c4;
              if (iStack_c8 == 0) {
                if (cStack_ce == '\0') goto LAB_00561c3c;
                goto LAB_00561e04;
              }
              if (((1 < iStack_c8) && (*pAStack_c4 == (ASN1_VALUE)0x0)) &&
                 (pAStack_c4[1] == (ASN1_VALUE)0x0)) {
                if (cStack_ce == '\0') {
                  uVar17 = 0x9f;
                  uVar5 = 0x1a7;
                  pAStack_c4 = pAStack_c4 + 2;
                  goto LAB_0056163c;
                }
                iStack_c8 = iStack_c8 + -2;
                cStack_ce = '\0';
                pAStack_c4 = pAStack_c4 + 2;
                goto LAB_00561c28;
              }
              uVar10 = 0;
              if ((int)PBEPARAM_it._12_4_ + -1 != iVar13) {
                uVar10 = pAVar11->flags & 1;
              }
              iVar9 = asn1_template_ex_d2i(ppAVar15,&pAStack_c4,iStack_c8,pAVar11,uVar10,puStack_d8)
              ;
              if (iVar9 == 0) goto LAB_00561ce4;
              if (iVar9 == -1) {
                ASN1_template_free(ppAVar15,pAVar11);
              }
              else {
                iStack_c8 = iStack_c8 - ((int)pAStack_c4 - (int)pAVar6);
              }
              iVar13 = iVar13 + 1;
              pAVar8 = pAVar8 + 1;
            } while (iVar13 < (int)PBEPARAM_it._12_4_);
          }
        }
        if (cStack_ce != '\0') {
          if (((iStack_c8 < 2) || (*pAStack_c4 != (ASN1_VALUE)0x0)) ||
             (pAStack_c4[1] != (ASN1_VALUE)0x0)) {
LAB_00561e04:
            uVar17 = 0x89;
            uVar5 = 0x1ce;
            break;
          }
          pAStack_c4 = pAStack_c4 + 2;
        }
LAB_00561c28:
        if ((cVar2 != '\0') || (iStack_c8 == 0)) {
LAB_00561c3c:
          if (iVar13 < (int)PBEPARAM_it._12_4_) {
LAB_00561c90:
            pAVar11 = asn1_do_adb(pval,pAVar8,1);
            if (pAVar11 != (ASN1_TEMPLATE *)0x0) {
              if ((pAVar11->flags & 1) != 0) goto LAB_00561c54;
              (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x78,0x79,s_tasn_dec_c_0066a0bc,0x1e7);
LAB_00561ce4:
              ASN1_item_ex_free(pval,(ASN1_ITEM *)PBEPARAM_it);
LAB_00561cf8:
              pcVar16 = (char *)&DAT_0066a0d0;
              (*(code *)PTR_ERR_add_error_data_006a813c)
                        (4,&DAT_0066a0d0,pAVar11->field_name,", Type=",PBEPARAM_it._24_4_);
              goto switchD_005619f8_caseD_7;
            }
            goto LAB_00561650;
          }
          ppAVar15 = *(ASN1_VALUE ***)pcVar16;
          goto LAB_00561a70;
        }
        uVar17 = 0x94;
        uVar5 = 0x1d3;
      }
    }
    break;
  case 2:
    if ((pcStack_e0 == (code *)0x0) || (iVar13 = (*pcStack_e0)(4,pval,PBEPARAM_it,0), iVar13 != 0))
    goto LAB_00561954;
    goto LAB_00561628;
  case 3:
switchD_005619f8_caseD_3:
    iVar13 = (**(code **)(PBEPARAM_it._16_4_ + 8))(pval,pcVar16,iVar13);
    if (iVar13 != 0) {
      pAVar6 = *pval;
      ppAVar15 = (ASN1_VALUE **)pcVar16;
      goto LAB_00561684;
    }
    uVar17 = 0x3a;
    uVar5 = 0x12f;
    break;
  case 4:
LAB_005618f4:
    iVar13 = (*pcStack_e0)(pval,pcVar16,iVar13,PBEPARAM_it,0xffffffff,0,0,auStack_bc);
    if (iVar13 < 1) {
      pAVar6 = (ASN1_VALUE *)0x0;
      ppAVar15 = (ASN1_VALUE **)pcVar16;
      goto LAB_00561684;
    }
LAB_005617a4:
    pAVar6 = *pval;
    ppAVar15 = (ASN1_VALUE **)pcVar16;
    goto LAB_00561684;
  case 5:
switchD_005619f8_caseD_5:
    pAStack_c4 = *(ASN1_VALUE **)pcVar16;
    iVar13 = asn1_check_tlen_constprop_1
                       (0,&uStack_c0,&cStack_cf,0,0,&pAStack_c4,iVar13,1,auStack_bc);
    if (iVar13 == 0) {
      uVar17 = 0x3a;
      uVar5 = 0xdb;
    }
    else if (cStack_cf == '\0') {
      if ((uStack_c0 < 0x1f) && ((*(uint *)(tag2bit + uStack_c0 * 4) & PBEPARAM_it._4_4_) != 0)) {
        iVar13 = asn1_d2i_ex_primitive(pval,pcVar16,iStack_c8,PBEPARAM_it,uStack_c0,0,0,auStack_bc);
        if (iVar13 < 1) {
          pAVar6 = (ASN1_VALUE *)0x0;
          ppAVar15 = (ASN1_VALUE **)pcVar16;
          goto LAB_00561684;
        }
        goto LAB_005617a4;
      }
      uVar17 = 0x8c;
      uVar5 = 0xec;
    }
    else {
      uVar17 = 0x8b;
      uVar5 = 0xe4;
    }
    break;
  default:
    goto switchD_005619f8_caseD_7;
  }
LAB_0056163c:
  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x78,uVar17,s_tasn_dec_c_0066a0bc,uVar5);
LAB_00561650:
  ASN1_item_ex_free(pval,(ASN1_ITEM *)PBEPARAM_it);
LAB_00561668:
  pcVar16 = s_Type__0066a0d8;
  (*(code *)PTR_ERR_add_error_data_006a813c)(2,s_Type__0066a0d8,PBEPARAM_it._24_4_);
switchD_005619f8_caseD_7:
  pAVar6 = (ASN1_VALUE *)0x0;
  ppAVar15 = (ASN1_VALUE **)pcVar16;
LAB_00561684:
  if (piStack_a4 != *(int **)puVar3) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    return *(int *)(ppAVar15[1] + *piStack_a4);
  }
  return (int)pAVar6;
LAB_00561c54:
  iVar13 = iVar13 + 1;
  ppAVar15 = asn1_get_field_ptr(pval,pAVar11);
  pAVar8 = pAVar8 + 1;
  ASN1_template_free(ppAVar15,pAVar11);
  if ((int)PBEPARAM_it._12_4_ <= iVar13) goto LAB_00561a6c;
  goto LAB_00561c90;
LAB_00561a6c:
  ppAVar15 = *(ASN1_VALUE ***)pcVar16;
LAB_00561a70:
  iVar13 = asn1_enc_save(pval,(uchar *)ppAVar15,(int)pAStack_c4 - (int)ppAVar15,
                         (ASN1_ITEM *)PBEPARAM_it);
  if (iVar13 != 0) {
joined_r0x00561600:
    if ((pcStack_e0 == (code *)0x0) ||
       (ppAVar15 = pval, iVar13 = (*pcStack_e0)(5,pval,PBEPARAM_it,0), iVar13 != 0)) {
      *(ASN1_VALUE **)pcVar16 = pAStack_c4;
      pAVar6 = *pval;
      goto LAB_00561684;
    }
  }
LAB_00561628:
  uVar17 = 100;
  uVar5 = 0x1f7;
  goto LAB_0056163c;
}

