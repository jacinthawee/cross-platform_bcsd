
ASN1_VALUE *
d2i_RSA_NET_2_isra_0(undefined4 param_1,int *param_2,int **param_3,code *param_4,int param_5)

{
  char cVar1;
  undefined *puVar2;
  int in_zero;
  ASN1_VALUE **ppAVar3;
  ASN1_VALUE *pAVar4;
  int iVar5;
  ASN1_TEMPLATE *pAVar6;
  uint uVar7;
  ASN1_TEMPLATE *pAVar8;
  int iVar9;
  undefined4 uVar10;
  char *pcVar11;
  ASN1_VALUE **ppAVar12;
  undefined1 *puVar13;
  undefined4 uVar14;
  int *piVar15;
  ASN1_VALUE **pval;
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
  
  puStack_250 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(ASN1_VALUE ***)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_EVP_CIPHER_CTX_init_006a7a64)(auStack_1f8);
  local_204 = (*param_4)(aiStack_12c,0x100,"Enter Private Key password:",0);
  if (local_204 == 0) {
    iVar9 = (*(code *)PTR_strlen_006a9a24)(aiStack_12c);
    local_204 = iVar9;
    if (param_5 == 0) {
LAB_00563c64:
      unaff_s7 = (int **)(*(code *)PTR_EVP_rc4_006a8408)();
      uVar10 = (*(code *)PTR_EVP_md5_006a70c8)();
      piVar15 = (int *)0x0;
      iVar9 = (*(code *)PTR_EVP_BytesToKey_006a754c)(unaff_s7,uVar10,0,aiStack_12c);
      if (iVar9 != 0) {
        (*(code *)PTR_OPENSSL_cleanse_006a7074)(aiStack_12c,0x100);
        uVar10 = (*(code *)PTR_EVP_rc4_006a8408)();
        piVar15 = (int *)0x0;
        iVar9 = (*(code *)PTR_EVP_DecryptInit_ex_006a7a68)(auStack_1f8,uVar10,0,auStack_16c);
        if (iVar9 != 0) {
          piVar15 = &local_204;
          iVar9 = (*(code *)PTR_EVP_DecryptUpdate_006a7a70)(auStack_1f8,*param_3);
          if (iVar9 != 0) {
            piVar15 = &local_200;
            iVar9 = (*(code *)PTR_EVP_DecryptFinal_ex_006a7a6c)
                              (auStack_1f8,(int)*param_3 + local_204);
            if (iVar9 != 0) {
              unaff_s7 = &local_1fc;
              local_1fc = *param_3;
              *param_2 = local_204 + local_200;
              pAStack_258 = ASN1_item_d2i((ASN1_VALUE **)0x0,(uchar **)unaff_s7,
                                          local_204 + local_200,(ASN1_ITEM *)NETSCAPE_PKEY_it);
              if (pAStack_258 == (ASN1_VALUE *)0x0) {
                piVar15 = (int *)&DAT_0000009e;
                pAStack_248 = (ASN1_VALUE *)0x0;
                (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xc9,0x9e,"n_pkey.c");
              }
              else {
                local_1fc = (*(int ***)(pAStack_258 + 8))[2];
                piVar15 = **(int ***)(pAStack_258 + 8);
                pAStack_248 = (ASN1_VALUE *)
                              (*(code *)PTR_d2i_RSAPrivateKey_006a79e4)(param_1,unaff_s7);
                if (pAStack_248 == (ASN1_VALUE *)0x0) {
                  piVar15 = (int *)0x9d;
                  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xc9,0x9d,"n_pkey.c");
                }
              }
              goto LAB_00563df8;
            }
          }
        }
      }
    }
    else {
      (*(code *)PTR_EVP_md5_006a70c8)();
      piVar15 = aiStack_12c;
      iVar9 = (*(code *)PTR_EVP_Digest_006a7a14)(aiStack_12c,iVar9,aiStack_12c,0);
      if (iVar9 != 0) {
        local_11c = s_SGCKEYSALT_0066a3a4._0_4_;
        local_204 = 0x1a;
        local_118 = s_SGCKEYSALT_0066a3a4._4_4_;
        local_114 = s_SGCKEYSALT_0066a3a4._8_2_;
        goto LAB_00563c64;
      }
    }
    pAStack_248 = (ASN1_VALUE *)0x0;
    pAStack_258 = (ASN1_VALUE *)0x0;
  }
  else {
    piVar15 = (int *)0x67;
    pAStack_248 = (ASN1_VALUE *)0x0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xc9,0x67,"n_pkey.c");
    pAStack_258 = (ASN1_VALUE *)0x0;
  }
LAB_00563df8:
  (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a7a74)(auStack_1f8);
  puVar13 = NETSCAPE_PKEY_it;
  ASN1_item_free(pAStack_258,(ASN1_ITEM *)NETSCAPE_PKEY_it);
  if (local_2c == *(ASN1_VALUE ***)puStack_250) {
    return pAStack_248;
  }
  ppAVar12 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  iVar9 = NETSCAPE_ENCRYPTED_PKEY_it._16_4_;
  puStack_254 = auStack_1f8;
  uStack_24c = 0x690000;
  ppiStack_23c = unaff_s7;
  piStack_240 = param_2;
  uStack_244 = param_1;
  pAStack_284 = (ASN1_VALUE *)0x0;
  auStack_274[0] = 0;
  piStack_280 = piVar15;
  pAStack_27c = (ASN1_VALUE *)0x0;
  pval = &pAStack_284;
  if (ppAVar12 != (ASN1_VALUE **)0x0) {
    pval = ppAVar12;
  }
  piStack_25c = *(int **)PTR___stack_chk_guard_006a9ae8;
  if (NETSCAPE_ENCRYPTED_PKEY_it._16_4_ == 0) {
    switch(NETSCAPE_ENCRYPTED_PKEY_it[0]) {
    case 0:
      goto switchD_005619f8_caseD_0;
    case 1:
    case 6:
      pcStack_298 = (code *)0x0;
      goto switchD_00561550_caseD_1;
    case 2:
      pcStack_298 = (code *)0x0;
LAB_00561954:
      if (*pval == (ASN1_VALUE *)0x0) {
        iVar9 = ASN1_item_ex_new(pval,(ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
        if (iVar9 == 0) {
          uVar14 = 0x3a;
          uVar10 = 0x13f;
          goto LAB_0056163c;
        }
      }
      else {
        iVar9 = asn1_get_choice_selector(pval,(ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
        if ((-1 < iVar9) && (iVar9 < (int)NETSCAPE_ENCRYPTED_PKEY_it._12_4_)) {
          pAVar8 = NETSCAPE_ENCRYPTED_PKEY_it._8_4_ + iVar9;
          ppAVar12 = asn1_get_field_ptr(pval,pAVar8);
          ASN1_template_free(ppAVar12,pAVar8);
          asn1_set_choice_selector(pval,-1,(ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
        }
      }
      pAStack_27c = *(ASN1_VALUE **)puVar13;
      ppAVar12 = (ASN1_VALUE **)0x0;
      if ((int)NETSCAPE_ENCRYPTED_PKEY_it._12_4_ < 1) {
LAB_005615e0:
        if (ppAVar12 == NETSCAPE_ENCRYPTED_PKEY_it._12_4_) {
LAB_00561a34:
          uVar14 = 0x8f;
          uVar10 = 0x15e;
          goto LAB_0056163c;
        }
      }
      else {
        pAVar8 = NETSCAPE_ENCRYPTED_PKEY_it._8_4_;
        do {
          ppAVar3 = asn1_get_field_ptr(pval,pAVar8);
          iVar9 = asn1_template_ex_d2i(ppAVar3,&pAStack_27c,piStack_280,pAVar8,1,auStack_274);
          if (iVar9 != -1) {
            if (0 < iVar9) goto LAB_005615e0;
            (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x78,0x3a,s_tasn_dec_c_0066a0bc,0x152);
            ASN1_item_ex_free(pval,(ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
            if (pAVar8 == (ASN1_TEMPLATE *)0x0) goto LAB_00561668;
            goto LAB_00561cf8;
          }
          ppAVar12 = (ASN1_VALUE **)((int)ppAVar12 + 1);
          pAVar8 = pAVar8 + 1;
        } while ((int)ppAVar12 < (int)NETSCAPE_ENCRYPTED_PKEY_it._12_4_);
        if (ppAVar12 == NETSCAPE_ENCRYPTED_PKEY_it._12_4_) goto LAB_00561a34;
      }
      asn1_set_choice_selector(pval,(int)ppAVar12,(ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
      goto joined_r0x00561600;
    case 3:
      goto switchD_005619f8_caseD_3;
    case 4:
      pcStack_298 = *(code **)(in_zero + 0x10);
      goto LAB_005618f4;
    case 5:
      goto switchD_005619f8_caseD_5;
    }
    goto switchD_005619f8_caseD_7;
  }
  pcStack_298 = *(code **)(NETSCAPE_ENCRYPTED_PKEY_it._16_4_ + 0x10);
  switch(NETSCAPE_ENCRYPTED_PKEY_it[0]) {
  case 0:
switchD_005619f8_caseD_0:
    if (NETSCAPE_ENCRYPTED_PKEY_it._8_4_ == (ASN1_TEMPLATE *)0x0) {
      iVar9 = asn1_d2i_ex_primitive
                        (pval,puVar13,piVar15,NETSCAPE_ENCRYPTED_PKEY_it,0xffffffff,0,0,auStack_274)
      ;
      if (iVar9 < 1) {
        pAVar4 = (ASN1_VALUE *)0x0;
        ppAVar12 = (ASN1_VALUE **)puVar13;
        goto LAB_00561684;
      }
    }
    else {
      iVar9 = asn1_template_ex_d2i
                        (pval,puVar13,piVar15,NETSCAPE_ENCRYPTED_PKEY_it._8_4_,0,auStack_274);
      if (iVar9 < 1) goto switchD_005619f8_caseD_7;
    }
    goto LAB_005617a4;
  case 1:
  case 6:
switchD_00561550_caseD_1:
    pAStack_27c = *(ASN1_VALUE **)puVar13;
    ppAVar12 = (ASN1_VALUE **)0x0;
    iVar5 = asn1_check_tlen(&piStack_280,0,0,&cStack_286,&cStack_285,&pAStack_27c,piVar15,0x10,0,0,
                            auStack_274);
    if (iVar5 == 0) {
      uVar14 = 0x3a;
      uVar10 = 0x176;
    }
    else {
      pAVar4 = (ASN1_VALUE *)0x0;
      if (iVar5 == -1) goto LAB_00561684;
      cVar1 = cStack_286;
      if ((iVar9 != 0) && ((*(uint *)(iVar9 + 4) & 4) != 0)) {
        piStack_280 = (int *)((int)piVar15 - ((int)pAStack_27c - (int)*(ASN1_VALUE **)puVar13));
        cVar1 = '\x01';
      }
      if (cStack_285 == '\0') {
        uVar14 = 0x95;
        uVar10 = 0x182;
      }
      else if ((*pval == (ASN1_VALUE *)0x0) &&
              (iVar9 = ASN1_item_ex_new(pval,(ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it), iVar9 == 0))
      {
        uVar14 = 0x3a;
        uVar10 = 0x187;
      }
      else {
        puStack_290 = auStack_274;
        if ((pcStack_298 != (code *)0x0) &&
           (iVar9 = (*pcStack_298)(4,pval,NETSCAPE_ENCRYPTED_PKEY_it,0), iVar9 == 0))
        goto LAB_00561628;
        iVar9 = 0;
        ppAVar12 = NETSCAPE_ENCRYPTED_PKEY_it._12_4_;
        pAVar6 = NETSCAPE_ENCRYPTED_PKEY_it._8_4_;
        pAVar8 = NETSCAPE_ENCRYPTED_PKEY_it._8_4_;
        if (0 < (int)NETSCAPE_ENCRYPTED_PKEY_it._12_4_) {
          do {
            if ((pAVar8->flags & 0x300) != 0) {
              pAVar6 = asn1_do_adb(pval,pAVar8,1);
              ppAVar12 = asn1_get_field_ptr(pval,pAVar6);
              ASN1_template_free(ppAVar12,pAVar6);
              ppAVar12 = NETSCAPE_ENCRYPTED_PKEY_it._12_4_;
            }
            iVar9 = iVar9 + 1;
            pAVar8 = pAVar8 + 1;
          } while (iVar9 < (int)ppAVar12);
          iVar9 = 0;
          pAVar6 = NETSCAPE_ENCRYPTED_PKEY_it._8_4_;
          if (0 < (int)ppAVar12) {
            do {
              pAVar8 = asn1_do_adb(pval,pAVar6,1);
              if (pAVar8 == (ASN1_TEMPLATE *)0x0) goto LAB_00561650;
              ppAVar12 = asn1_get_field_ptr(pval,pAVar8);
              pAVar4 = pAStack_27c;
              if (piStack_280 == (int *)0x0) {
                if (cStack_286 == '\0') goto LAB_00561c3c;
                goto LAB_00561e04;
              }
              if (((1 < (int)piStack_280) && (*pAStack_27c == (ASN1_VALUE)0x0)) &&
                 (pAStack_27c[1] == (ASN1_VALUE)0x0)) {
                if (cStack_286 == '\0') {
                  uVar14 = 0x9f;
                  uVar10 = 0x1a7;
                  pAStack_27c = pAStack_27c + 2;
                  goto LAB_0056163c;
                }
                piStack_280 = (int *)((int)piStack_280 + -2);
                cStack_286 = '\0';
                pAStack_27c = pAStack_27c + 2;
                goto LAB_00561c28;
              }
              uVar7 = 0;
              if ((int)NETSCAPE_ENCRYPTED_PKEY_it._12_4_ + -1 != iVar9) {
                uVar7 = pAVar8->flags & 1;
              }
              iVar5 = asn1_template_ex_d2i
                                (ppAVar12,&pAStack_27c,piStack_280,pAVar8,uVar7,puStack_290);
              if (iVar5 == 0) goto LAB_00561ce4;
              if (iVar5 == -1) {
                ASN1_template_free(ppAVar12,pAVar8);
              }
              else {
                piStack_280 = (int *)((int)piStack_280 - ((int)pAStack_27c - (int)pAVar4));
              }
              iVar9 = iVar9 + 1;
              pAVar6 = pAVar6 + 1;
            } while (iVar9 < (int)NETSCAPE_ENCRYPTED_PKEY_it._12_4_);
          }
        }
        if (cStack_286 != '\0') {
          if ((((int)piStack_280 < 2) || (*pAStack_27c != (ASN1_VALUE)0x0)) ||
             (pAStack_27c[1] != (ASN1_VALUE)0x0)) {
LAB_00561e04:
            uVar14 = 0x89;
            uVar10 = 0x1ce;
            break;
          }
          pAStack_27c = pAStack_27c + 2;
        }
LAB_00561c28:
        if ((cVar1 != '\0') || (piStack_280 == (int *)0x0)) {
LAB_00561c3c:
          if (iVar9 < (int)NETSCAPE_ENCRYPTED_PKEY_it._12_4_) {
LAB_00561c90:
            pAVar8 = asn1_do_adb(pval,pAVar6,1);
            if (pAVar8 != (ASN1_TEMPLATE *)0x0) {
              if ((pAVar8->flags & 1) != 0) goto LAB_00561c54;
              (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x78,0x79,s_tasn_dec_c_0066a0bc,0x1e7);
LAB_00561ce4:
              ASN1_item_ex_free(pval,(ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
LAB_00561cf8:
              puVar13 = (undefined1 *)&DAT_0066a0d0;
              (*(code *)PTR_ERR_add_error_data_006a813c)
                        (4,&DAT_0066a0d0,pAVar8->field_name,", Type=",
                         NETSCAPE_ENCRYPTED_PKEY_it._24_4_);
              goto switchD_005619f8_caseD_7;
            }
            goto LAB_00561650;
          }
          ppAVar12 = *(ASN1_VALUE ***)puVar13;
          goto LAB_00561a70;
        }
        uVar14 = 0x94;
        uVar10 = 0x1d3;
      }
    }
    break;
  case 2:
    if ((pcStack_298 == (code *)0x0) ||
       (iVar9 = (*pcStack_298)(4,pval,NETSCAPE_ENCRYPTED_PKEY_it,0), iVar9 != 0)) goto LAB_00561954;
    goto LAB_00561628;
  case 3:
switchD_005619f8_caseD_3:
    iVar9 = (**(code **)(NETSCAPE_ENCRYPTED_PKEY_it._16_4_ + 8))(pval,puVar13,piVar15);
    if (iVar9 != 0) {
      pAVar4 = *pval;
      ppAVar12 = (ASN1_VALUE **)puVar13;
      goto LAB_00561684;
    }
    uVar14 = 0x3a;
    uVar10 = 0x12f;
    break;
  case 4:
LAB_005618f4:
    iVar9 = (*pcStack_298)(pval,puVar13,piVar15,NETSCAPE_ENCRYPTED_PKEY_it,0xffffffff,0,0,
                           auStack_274);
    if (iVar9 < 1) {
      pAVar4 = (ASN1_VALUE *)0x0;
      ppAVar12 = (ASN1_VALUE **)puVar13;
      goto LAB_00561684;
    }
LAB_005617a4:
    pAVar4 = *pval;
    ppAVar12 = (ASN1_VALUE **)puVar13;
    goto LAB_00561684;
  case 5:
switchD_005619f8_caseD_5:
    pAStack_27c = *(ASN1_VALUE **)puVar13;
    iVar9 = asn1_check_tlen_constprop_1
                      (0,&uStack_278,&cStack_287,0,0,&pAStack_27c,piVar15,1,auStack_274);
    if (iVar9 == 0) {
      uVar14 = 0x3a;
      uVar10 = 0xdb;
    }
    else if (cStack_287 == '\0') {
      if ((uStack_278 < 0x1f) &&
         ((*(uint *)(tag2bit + uStack_278 * 4) & NETSCAPE_ENCRYPTED_PKEY_it._4_4_) != 0)) {
        iVar9 = asn1_d2i_ex_primitive
                          (pval,puVar13,piStack_280,NETSCAPE_ENCRYPTED_PKEY_it,uStack_278,0,0,
                           auStack_274);
        if (iVar9 < 1) {
          pAVar4 = (ASN1_VALUE *)0x0;
          ppAVar12 = (ASN1_VALUE **)puVar13;
          goto LAB_00561684;
        }
        goto LAB_005617a4;
      }
      uVar14 = 0x8c;
      uVar10 = 0xec;
    }
    else {
      uVar14 = 0x8b;
      uVar10 = 0xe4;
    }
    break;
  default:
    goto switchD_005619f8_caseD_7;
  }
LAB_0056163c:
  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x78,uVar14,s_tasn_dec_c_0066a0bc,uVar10);
LAB_00561650:
  ASN1_item_ex_free(pval,(ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
LAB_00561668:
  pcVar11 = s_Type__0066a0d8;
  (*(code *)PTR_ERR_add_error_data_006a813c)(2,s_Type__0066a0d8,NETSCAPE_ENCRYPTED_PKEY_it._24_4_);
  puVar13 = pcVar11;
switchD_005619f8_caseD_7:
  pAVar4 = (ASN1_VALUE *)0x0;
  ppAVar12 = (ASN1_VALUE **)puVar13;
LAB_00561684:
  if (piStack_25c != *(int **)puVar2) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    return *(ASN1_VALUE **)(ppAVar12[1] + *piStack_25c);
  }
  return pAVar4;
LAB_00561c54:
  iVar9 = iVar9 + 1;
  ppAVar12 = asn1_get_field_ptr(pval,pAVar8);
  pAVar6 = pAVar6 + 1;
  ASN1_template_free(ppAVar12,pAVar8);
  if ((int)NETSCAPE_ENCRYPTED_PKEY_it._12_4_ <= iVar9) goto LAB_00561a6c;
  goto LAB_00561c90;
LAB_00561a6c:
  ppAVar12 = *(ASN1_VALUE ***)puVar13;
LAB_00561a70:
  iVar9 = asn1_enc_save(pval,(uchar *)ppAVar12,(int)pAStack_27c - (int)ppAVar12,
                        (ASN1_ITEM *)NETSCAPE_ENCRYPTED_PKEY_it);
  if (iVar9 != 0) {
joined_r0x00561600:
    if ((pcStack_298 == (code *)0x0) ||
       (ppAVar12 = pval, iVar9 = (*pcStack_298)(5,pval,NETSCAPE_ENCRYPTED_PKEY_it,0), iVar9 != 0)) {
      *(ASN1_VALUE **)puVar13 = pAStack_27c;
      pAVar4 = *pval;
      goto LAB_00561684;
    }
  }
LAB_00561628:
  uVar14 = 100;
  uVar10 = 0x1f7;
  goto LAB_0056163c;
}

