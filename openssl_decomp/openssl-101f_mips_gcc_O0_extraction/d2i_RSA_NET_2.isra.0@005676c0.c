
ASN1_VALUE *
d2i_RSA_NET_2_isra_0(undefined4 param_1,int *param_2,int **param_3,code *param_4,int param_5)

{
  char cVar1;
  undefined *puVar2;
  int in_zero;
  ASN1_VALUE **ppAVar3;
  ASN1_VALUE *pAVar4;
  int iVar5;
  uint uVar6;
  ASN1_TEMPLATE *tt;
  int iVar7;
  undefined4 uVar8;
  char *pcVar9;
  ASN1_VALUE **ppAVar10;
  undefined1 *puVar11;
  undefined4 uVar12;
  int *piVar13;
  ASN1_VALUE **pval;
  undefined *puVar14;
  ASN1_TEMPLATE *tt_00;
  int **unaff_s7;
  code *pcStack_298;
  undefined *puStack_290;
  char cStack_287;
  char cStack_286;
  char cStack_285;
  ASN1_VALUE *pAStack_284;
  int *piStack_280;
  ASN1_VALUE *pAStack_27c;
  uint uStack_278;
  undefined auStack_274 [24];
  int *piStack_25c;
  ASN1_VALUE *pAStack_258;
  undefined *puStack_254;
  undefined *puStack_250;
  undefined4 uStack_24c;
  ASN1_VALUE *pAStack_248;
  undefined4 uStack_244;
  int *piStack_240;
  int **ppiStack_23c;
  int local_204;
  int local_200;
  int *local_1fc;
  undefined auStack_1f8 [140];
  undefined auStack_16c [64];
  int aiStack_12c [4];
  undefined4 local_11c;
  undefined4 local_118;
  undefined2 local_114;
  ASN1_VALUE **local_2c;
  
  puStack_250 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(ASN1_VALUE ***)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_EVP_CIPHER_CTX_init_006a8b50)(auStack_1f8);
  local_204 = (*param_4)(aiStack_12c,0x100,"Enter Private Key password:",0);
  if (local_204 == 0) {
    iVar7 = (*(code *)PTR_strlen_006aab30)(aiStack_12c);
    local_204 = iVar7;
    if (param_5 == 0) {
LAB_00567774:
      unaff_s7 = (int **)(*(code *)PTR_EVP_rc4_006a9528)();
      uVar8 = (*(code *)PTR_EVP_md5_006a81c8)();
      piVar13 = (int *)0x0;
      iVar7 = (*(code *)PTR_EVP_BytesToKey_006a8644)(unaff_s7,uVar8,0,aiStack_12c);
      if (iVar7 != 0) {
        (*(code *)PTR_OPENSSL_cleanse_006a8174)(aiStack_12c,0x100);
        uVar8 = (*(code *)PTR_EVP_rc4_006a9528)();
        piVar13 = (int *)0x0;
        iVar7 = (*(code *)PTR_EVP_DecryptInit_ex_006a8b54)(auStack_1f8,uVar8,0,auStack_16c);
        if (iVar7 != 0) {
          piVar13 = &local_204;
          iVar7 = (*(code *)PTR_EVP_DecryptUpdate_006a8b5c)(auStack_1f8,*param_3);
          if (iVar7 != 0) {
            piVar13 = &local_200;
            iVar7 = (*(code *)PTR_EVP_DecryptFinal_ex_006a8b58)
                              (auStack_1f8,(int)*param_3 + local_204);
            if (iVar7 != 0) {
              unaff_s7 = &local_1fc;
              local_1fc = *param_3;
              *param_2 = local_204 + local_200;
              pAStack_258 = ASN1_item_d2i((ASN1_VALUE **)0x0,(uchar **)unaff_s7,
                                          local_204 + local_200,(ASN1_ITEM *)NETSCAPE_PKEY_it);
              if (pAStack_258 == (ASN1_VALUE *)0x0) {
                piVar13 = (int *)&DAT_0000009e;
                pAStack_248 = (ASN1_VALUE *)0x0;
                (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xc9,0x9e,"n_pkey.c");
              }
              else {
                local_1fc = (*(int ***)(pAStack_258 + 8))[2];
                piVar13 = **(int ***)(pAStack_258 + 8);
                pAStack_248 = (ASN1_VALUE *)
                              (*(code *)PTR_d2i_RSAPrivateKey_006a8ad4)(param_1,unaff_s7);
                if (pAStack_248 == (ASN1_VALUE *)0x0) {
                  piVar13 = (int *)&DAT_0000009d;
                  (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xc9,0x9d,"n_pkey.c");
                }
              }
              goto LAB_00567908;
            }
          }
        }
      }
    }
    else {
      (*(code *)PTR_EVP_md5_006a81c8)();
      piVar13 = aiStack_12c;
      iVar7 = (*(code *)PTR_EVP_Digest_006a8b04)(aiStack_12c,iVar7,aiStack_12c,0);
      if (iVar7 != 0) {
        local_11c = s_SGCKEYSALT_0066adc4._0_4_;
        local_204 = 0x1a;
        local_118 = s_SGCKEYSALT_0066adc4._4_4_;
        local_114 = s_SGCKEYSALT_0066adc4._8_2_;
        goto LAB_00567774;
      }
    }
    pAStack_248 = (ASN1_VALUE *)0x0;
    pAStack_258 = (ASN1_VALUE *)0x0;
  }
  else {
    piVar13 = (int *)0x67;
    pAStack_248 = (ASN1_VALUE *)0x0;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xc9,0x67,"n_pkey.c");
    pAStack_258 = (ASN1_VALUE *)0x0;
  }
LAB_00567908:
  (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a8b60)(auStack_1f8);
  puVar11 = NETSCAPE_PKEY_it;
  ASN1_item_free(pAStack_258,(ASN1_ITEM *)NETSCAPE_PKEY_it);
  if (local_2c == *(ASN1_VALUE ***)puStack_250) {
    return pAStack_248;
  }
  ppAVar10 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar2 = PTR___stack_chk_guard_006aabf0;
  iVar7 = NETSCAPE_ENCRYPTED_PKEY_it._16_4_;
  puStack_254 = auStack_1f8;
  uStack_24c = 0x690000;
  ppiStack_23c = unaff_s7;
  piStack_240 = param_2;
  uStack_244 = param_1;
  pAStack_284 = (ASN1_VALUE *)0x0;
  auStack_274[0] = 0;
  piStack_280 = piVar13;
  pAStack_27c = (ASN1_VALUE *)0x0;
  pval = &pAStack_284;
  if (ppAVar10 != (ASN1_VALUE **)0x0) {
    pval = ppAVar10;
  }
  piStack_25c = *(int **)PTR___stack_chk_guard_006aabf0;
  if (NETSCAPE_ENCRYPTED_PKEY_it._16_4_ == 0) {
    switch(NETSCAPE_ENCRYPTED_PKEY_it[0]) {
    case 0:
      goto switchD_00565630_caseD_0;
    case 1:
    case 6:
      pcStack_298 = (code *)0x0;
      goto switchD_005651a0_caseD_1;
    case 2:
      pcStack_298 = (code *)0x0;
LAB_005651ac:
      if ((*pval == (ASN1_VALUE *)0x0) &&
         (iVar7 = ASN1_item_ex_new(pval,(ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it), iVar7 == 0)) {
        uVar12 = 0x3a;
        uVar8 = 0x13e;
        goto LAB_00565288;
      }
      pAStack_27c = *(ASN1_VALUE **)puVar11;
      ppAVar10 = (ASN1_VALUE **)0x0;
      if ((int)NETSCAPE_ENCRYPTED_PKEY_it._12_4_ < 1) {
LAB_00565228:
        if (ppAVar10 == NETSCAPE_ENCRYPTED_PKEY_it._12_4_) {
LAB_0056566c:
          uVar12 = 0x8f;
          uVar8 = 0x162;
          goto LAB_00565288;
        }
      }
      else {
        tt = NETSCAPE_ENCRYPTED_PKEY_it._8_4_;
        do {
          ppAVar3 = asn1_get_field_ptr(pval,tt);
          iVar7 = asn1_template_ex_d2i(ppAVar3,&pAStack_27c,piStack_280,tt,1,auStack_274);
          if (iVar7 != -1) {
            if (0 < iVar7) goto LAB_00565228;
            (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x78,0x3a,s_tasn_dec_c_0066ab0c,0x153);
            ASN1_item_ex_free(pval,(ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
            if (tt != (ASN1_TEMPLATE *)0x0) goto LAB_005657fc;
            goto LAB_005652b4;
          }
          ppAVar10 = (ASN1_VALUE **)((int)ppAVar10 + 1);
          tt = tt + 1;
        } while ((int)ppAVar10 < (int)NETSCAPE_ENCRYPTED_PKEY_it._12_4_);
        if (ppAVar10 == NETSCAPE_ENCRYPTED_PKEY_it._12_4_) goto LAB_0056566c;
      }
      asn1_set_choice_selector(pval,(int)ppAVar10,(ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
      *(ASN1_VALUE **)puVar11 = pAStack_27c;
      if (pcStack_298 == (code *)0x0) goto LAB_00565328;
      goto LAB_00565258;
    case 3:
      goto switchD_00565630_caseD_3;
    case 4:
      pcStack_298 = *(code **)(in_zero + 0x10);
      goto LAB_005655ac;
    case 5:
      goto switchD_00565630_caseD_5;
    }
    goto switchD_00565630_caseD_7;
  }
  pcStack_298 = *(code **)(NETSCAPE_ENCRYPTED_PKEY_it._16_4_ + 0x10);
  switch(NETSCAPE_ENCRYPTED_PKEY_it[0]) {
  case 0:
switchD_00565630_caseD_0:
    if (NETSCAPE_ENCRYPTED_PKEY_it._8_4_ == (ASN1_TEMPLATE *)0x0) {
      iVar7 = asn1_d2i_ex_primitive
                        (pval,puVar11,piVar13,NETSCAPE_ENCRYPTED_PKEY_it,0xffffffff,0,0,auStack_274)
      ;
      if (iVar7 < 1) {
        pAVar4 = (ASN1_VALUE *)0x0;
        ppAVar10 = (ASN1_VALUE **)puVar11;
        goto LAB_005652d0;
      }
    }
    else {
      iVar7 = asn1_template_ex_d2i
                        (pval,puVar11,piVar13,NETSCAPE_ENCRYPTED_PKEY_it._8_4_,0,auStack_274);
      if (iVar7 < 1) goto switchD_00565630_caseD_7;
    }
    goto LAB_005653f0;
  case 1:
  case 6:
switchD_005651a0_caseD_1:
    pAStack_27c = *(ASN1_VALUE **)puVar11;
    ppAVar10 = (ASN1_VALUE **)0x0;
    iVar5 = asn1_check_tlen(&piStack_280,0,0,&cStack_286,&cStack_285,&pAStack_27c,piVar13,0x10,0,0,
                            auStack_274);
    if (iVar5 == 0) {
      uVar12 = 0x3a;
      uVar8 = 0x17d;
    }
    else {
      pAVar4 = (ASN1_VALUE *)0x0;
      if (iVar5 == -1) goto LAB_005652d0;
      cVar1 = cStack_286;
      if ((iVar7 != 0) && ((*(uint *)(iVar7 + 4) & 4) != 0)) {
        piStack_280 = (int *)((int)piVar13 - ((int)pAStack_27c - (int)*(ASN1_VALUE **)puVar11));
        cVar1 = '\x01';
      }
      if (cStack_285 == '\0') {
        uVar12 = 0x95;
        uVar8 = 0x18c;
      }
      else if ((*pval == (ASN1_VALUE *)0x0) &&
              (iVar7 = ASN1_item_ex_new(pval,(ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it), iVar7 == 0))
      {
        uVar12 = 0x3a;
        uVar8 = 0x193;
      }
      else {
        puStack_290 = auStack_274;
        if ((pcStack_298 != (code *)0x0) &&
           (iVar7 = (*pcStack_298)(4,pval,NETSCAPE_ENCRYPTED_PKEY_it,0), iVar7 == 0))
        goto LAB_00565278;
        puVar14 = (undefined *)0x0;
        tt_00 = NETSCAPE_ENCRYPTED_PKEY_it._8_4_;
        if (0 < (int)NETSCAPE_ENCRYPTED_PKEY_it._12_4_) {
          do {
            tt = asn1_do_adb(pval,tt_00,1);
            if (tt == (ASN1_TEMPLATE *)0x0) goto LAB_0056529c;
            ppAVar10 = asn1_get_field_ptr(pval,tt);
            pAVar4 = pAStack_27c;
            if (piStack_280 == (int *)0x0) {
              if (cStack_286 != '\0') goto LAB_00565908;
              goto LAB_00565740;
            }
            if (((1 < (int)piStack_280) && (*pAStack_27c == (ASN1_VALUE)0x0)) &&
               (pAStack_27c[1] == (ASN1_VALUE)0x0)) {
              if (cStack_286 != '\0') {
                piStack_280 = (int *)((int)piStack_280 + -2);
                cStack_286 = '\0';
                pAStack_27c = pAStack_27c + 2;
                goto LAB_0056572c;
              }
              uVar12 = 0x9f;
              uVar8 = 0x1ac;
              pAStack_27c = pAStack_27c + 2;
              goto LAB_00565288;
            }
            uVar6 = 0;
            if (puVar14 != (undefined *)((int)NETSCAPE_ENCRYPTED_PKEY_it._12_4_ + -1)) {
              uVar6 = tt->flags & 1;
            }
            iVar7 = asn1_template_ex_d2i(ppAVar10,&pAStack_27c,piStack_280,tt,uVar6,puStack_290);
            if (iVar7 == 0) goto LAB_005657e8;
            if (iVar7 == -1) {
              ASN1_template_free(ppAVar10,tt);
            }
            else {
              piStack_280 = (int *)((int)piStack_280 - ((int)pAStack_27c - (int)pAVar4));
            }
            puVar14 = puVar14 + 1;
            tt_00 = tt_00 + 1;
          } while ((int)puVar14 < (int)NETSCAPE_ENCRYPTED_PKEY_it._12_4_);
        }
        if (cStack_286 != '\0') {
          if ((((int)piStack_280 < 2) || (*pAStack_27c != (ASN1_VALUE)0x0)) ||
             (pAStack_27c[1] != (ASN1_VALUE)0x0)) {
LAB_00565908:
            uVar12 = 0x89;
            uVar8 = 0x1d6;
            break;
          }
          pAStack_27c = pAStack_27c + 2;
        }
LAB_0056572c:
        if ((cVar1 != '\0') || (piStack_280 == (int *)0x0)) {
LAB_00565740:
          if ((int)puVar14 < (int)NETSCAPE_ENCRYPTED_PKEY_it._12_4_) {
LAB_00565794:
            tt = asn1_do_adb(pval,tt_00,1);
            if (tt != (ASN1_TEMPLATE *)0x0) {
              if ((tt->flags & 1) != 0) goto LAB_00565758;
              (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x78,0x79,s_tasn_dec_c_0066ab0c,0x1f5);
LAB_005657e8:
              ASN1_item_ex_free(pval,(ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
LAB_005657fc:
              puVar11 = &DAT_0066ab20;
              (*(code *)PTR_ERR_add_error_data_006a9264)
                        (4,&DAT_0066ab20,tt->field_name,", Type=",NETSCAPE_ENCRYPTED_PKEY_it._24_4_)
              ;
              goto switchD_00565630_caseD_7;
            }
            goto LAB_0056529c;
          }
          ppAVar10 = *(ASN1_VALUE ***)puVar11;
          goto LAB_00565954;
        }
        uVar12 = 0x94;
        uVar8 = 0x1dd;
      }
    }
    break;
  case 2:
    if ((pcStack_298 == (code *)0x0) ||
       (iVar7 = (*pcStack_298)(4,pval,NETSCAPE_ENCRYPTED_PKEY_it,0), iVar7 != 0)) goto LAB_005651ac;
    goto LAB_00565278;
  case 3:
switchD_00565630_caseD_3:
    iVar7 = (**(code **)(NETSCAPE_ENCRYPTED_PKEY_it._16_4_ + 8))(pval,puVar11,piVar13);
    ppAVar10 = (ASN1_VALUE **)puVar11;
    if (iVar7 != 0) goto LAB_00565328;
    uVar12 = 0x3a;
    uVar8 = 0x132;
    break;
  case 4:
LAB_005655ac:
    iVar7 = (*pcStack_298)(pval,puVar11,piVar13,NETSCAPE_ENCRYPTED_PKEY_it,0xffffffff,0,0,
                           auStack_274);
    if (iVar7 < 1) {
      pAVar4 = (ASN1_VALUE *)0x0;
      ppAVar10 = (ASN1_VALUE **)puVar11;
      goto LAB_005652d0;
    }
LAB_005653f0:
    pAVar4 = *pval;
    ppAVar10 = (ASN1_VALUE **)puVar11;
    goto LAB_005652d0;
  case 5:
switchD_00565630_caseD_5:
    pAStack_27c = *(ASN1_VALUE **)puVar11;
    iVar7 = asn1_check_tlen_constprop_1
                      (0,&uStack_278,&cStack_287,0,0,&pAStack_27c,piVar13,1,auStack_274);
    if (iVar7 == 0) {
      uVar12 = 0x3a;
      uVar8 = 0xd2;
    }
    else if (cStack_287 == '\0') {
      if ((uStack_278 < 0x1f) &&
         ((*(uint *)(tag2bit + uStack_278 * 4) & NETSCAPE_ENCRYPTED_PKEY_it._4_4_) != 0)) {
        iVar7 = asn1_d2i_ex_primitive
                          (pval,puVar11,piStack_280,NETSCAPE_ENCRYPTED_PKEY_it,uStack_278,0,0,
                           auStack_274);
        if (iVar7 < 1) {
          pAVar4 = (ASN1_VALUE *)0x0;
          ppAVar10 = (ASN1_VALUE **)puVar11;
          goto LAB_005652d0;
        }
        goto LAB_005653f0;
      }
      uVar12 = 0x8c;
      uVar8 = 0xe6;
    }
    else {
      uVar12 = 0x8b;
      uVar8 = 0xdc;
    }
    break;
  default:
    goto switchD_00565630_caseD_7;
  }
LAB_00565288:
  (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x78,uVar12,s_tasn_dec_c_0066ab0c,uVar8);
LAB_0056529c:
  ASN1_item_ex_free(pval,(ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
LAB_005652b4:
  pcVar9 = s_Type__0066ab28;
  (*(code *)PTR_ERR_add_error_data_006a9264)(2,s_Type__0066ab28,NETSCAPE_ENCRYPTED_PKEY_it._24_4_);
  puVar11 = pcVar9;
switchD_00565630_caseD_7:
  pAVar4 = (ASN1_VALUE *)0x0;
  ppAVar10 = (ASN1_VALUE **)puVar11;
LAB_005652d0:
  if (piStack_25c == *(int **)puVar2) {
    return pAVar4;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  return *(ASN1_VALUE **)(ppAVar10[1] + *piStack_25c);
LAB_00565758:
  puVar14 = puVar14 + 1;
  ppAVar10 = asn1_get_field_ptr(pval,tt);
  tt_00 = tt_00 + 1;
  ASN1_template_free(ppAVar10,tt);
  if ((int)NETSCAPE_ENCRYPTED_PKEY_it._12_4_ <= (int)puVar14) goto LAB_00565950;
  goto LAB_00565794;
LAB_00565950:
  ppAVar10 = *(ASN1_VALUE ***)puVar11;
LAB_00565954:
  iVar7 = asn1_enc_save(pval,(uchar *)ppAVar10,(int)pAStack_27c - (int)ppAVar10,
                        (ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
  if (iVar7 != 0) {
    *(ASN1_VALUE **)puVar11 = pAStack_27c;
    if (pcStack_298 == (code *)0x0) {
      pAVar4 = *pval;
      goto LAB_005652d0;
    }
LAB_00565258:
    ppAVar10 = pval;
    iVar7 = (*pcStack_298)(5,pval,NETSCAPE_ENCRYPTED_PKEY_it,0);
    if (iVar7 != 0) {
LAB_00565328:
      pAVar4 = *pval;
      goto LAB_005652d0;
    }
  }
LAB_00565278:
  uVar12 = 100;
  uVar8 = 0x205;
  goto LAB_00565288;
}

