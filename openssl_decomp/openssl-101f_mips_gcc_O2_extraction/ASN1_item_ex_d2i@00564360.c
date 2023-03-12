
int ASN1_item_ex_d2i(ASN1_VALUE **pval,uchar **in,long len,ASN1_ITEM *it,int tag,int aclass,char opt
                    ,ASN1_TLC *ctx)

{
  byte bVar1;
  char cVar2;
  undefined *puVar3;
  ASN1_TEMPLATE *pAVar4;
  int in_zero;
  ASN1_VALUE **ppAVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  ASN1_TEMPLATE *tt;
  char *pcVar9;
  ASN1_ITEM *pAVar10;
  ASN1_ITEM *pAVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  char *it_00;
  ASN1_ITEM *unaff_s0;
  ASN1_ITEM *pval_00;
  void *pvVar14;
  ASN1_ITEM *unaff_s3;
  ASN1_VALUE **unaff_s4;
  ASN1_TEMPLATE *tt_00;
  ASN1_TEMPLATE *unaff_s5;
  ASN1_ITEM *unaff_s6;
  ASN1_ITEM *unaff_s8;
  code *pcStack_168;
  undefined *puStack_160;
  char cStack_157;
  char cStack_156;
  char cStack_155;
  undefined auStack_154 [4];
  ASN1_ITEM *pAStack_150;
  ASN1_TEMPLATE *pAStack_14c;
  uint uStack_148;
  undefined auStack_144 [24];
  int *piStack_12c;
  ASN1_ITEM *pAStack_128;
  undefined *puStack_124;
  uint uStack_120;
  ASN1_ITEM *pAStack_11c;
  ASN1_VALUE **ppAStack_118;
  ASN1_TEMPLATE *pAStack_114;
  ASN1_ITEM *pAStack_110;
  ASN1_ITEM *pAStack_10c;
  ASN1_ITEM *pAStack_108;
  code *pcStack_104;
  ASN1_ITEM *pAStack_d8;
  int iStack_d4;
  ASN1_TEMPLATE *pAStack_d0;
  ASN1_ITEM *pAStack_cc;
  ASN1_ITEM *pAStack_c8;
  undefined uStack_c4;
  char *pcStack_c0;
  ASN1_ITEM *pAStack_bc;
  int iStack_b8;
  ASN1_TEMPLATE *pAStack_b4;
  int iStack_b0;
  ASN1_ITEM *pAStack_ac;
  ASN1_ITEM *pAStack_a8;
  undefined *puStack_a4;
  void *pvStack_a0;
  
  puStack_a4 = PTR___stack_chk_guard_006aabf0;
  ppAVar5 = *(ASN1_VALUE ***)PTR___stack_chk_guard_006aabf0;
  pvStack_a0 = it->funcs;
  pAStack_a8 = unaff_s0;
  if (pval != (ASN1_VALUE **)0x0) {
    if (pvStack_a0 == (void *)0x0) {
      bVar1 = it->itype;
    }
    else {
      bVar1 = it->itype;
    }
    pAStack_a8 = (ASN1_ITEM *)pval;
    unaff_s4 = (ASN1_VALUE **)in;
    unaff_s8 = it;
    if (bVar1 < 7) {
                    /* WARNING: Could not recover jumptable at 0x00564400. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar6 = (*(code *)(&PTR_LAB_0066ab88)[bVar1])();
      return iVar6;
    }
  }
  if (ppAVar5 == *(ASN1_VALUE ***)PTR___stack_chk_guard_006aabf0) {
    return 0;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_124 = PTR___stack_chk_guard_006aabf0;
  uStack_c4 = 0;
  pAStack_ac = *(ASN1_ITEM **)PTR___stack_chk_guard_006aabf0;
  uStack_120 = 0;
  pcVar9 = (char *)in;
  pAVar11 = (ASN1_ITEM *)len;
  it_00 = &it->itype;
  pAStack_128 = pAStack_a8;
  pAStack_10c = (ASN1_ITEM *)(int)opt;
  if (ppAVar5 != (ASN1_VALUE **)0x0) {
    unaff_s5 = *(ASN1_TEMPLATE **)it;
    pAStack_128 = (ASN1_ITEM *)*in;
    unaff_s3 = it;
    unaff_s6 = (ASN1_ITEM *)in;
    pAStack_d8 = pAStack_128;
    if (((uint)unaff_s5 & 0x10) == 0) {
      uStack_120 = asn1_template_noexp_d2i();
      pAVar11 = (ASN1_ITEM *)len;
    }
    else {
      iVar6 = it->utype;
      pAStack_c8 = pAStack_128;
      pcStack_c0 = (char *)ASN1_get_object((uchar **)&pAStack_c8,(long *)&pAStack_cc,&iStack_d4,
                                           (int *)&pAStack_d0,len);
      pAVar10 = pAStack_c8;
      iStack_b0 = (int)pAStack_c8 - (int)pAStack_128;
      pAStack_bc = pAStack_cc;
      pAStack_b4 = pAStack_d0;
      iStack_b8 = iStack_d4;
      uStack_c4 = 1;
      unaff_s4 = ppAVar5;
      pAStack_10c = (ASN1_ITEM *)len;
      unaff_s8 = pAStack_cc;
      if ((((uint)pcStack_c0 & 0x81) == 0) && (len < (int)((int)pAStack_cc + iStack_b0))) {
        uVar12 = 0x9b;
LAB_00564fdc:
        (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x68,uVar12,s_tasn_dec_c_0066ab2c);
        uStack_c4 = 0;
      }
      else {
        uStack_120 = (uint)pcStack_c0 & 0x80;
        if (uStack_120 != 0) {
          uVar12 = 0x66;
          goto LAB_00564fdc;
        }
        if (iVar6 < 0) {
LAB_00564f84:
          unaff_s5 = (ASN1_TEMPLATE *)(int)(char)pcStack_c0;
          pAStack_d8 = pAStack_c8;
          pAStack_128 = (ASN1_ITEM *)(len - iStack_b0);
          if (((uint)pcStack_c0 & 1) != 0) {
            unaff_s8 = pAStack_128;
          }
          if (((uint)unaff_s5 & 0x20) == 0) {
            pAVar11 = (ASN1_ITEM *)&DAT_00000078;
          }
          else {
            pcVar9 = (char *)&pAStack_d8;
            pAVar11 = unaff_s8;
            iVar6 = asn1_template_noexp_d2i(ppAVar5);
            if (iVar6 != 0) {
              unaff_s5 = (ASN1_TEMPLATE *)((uint)unaff_s5 & 1);
              unaff_s8 = (ASN1_ITEM *)((int)unaff_s8 - ((int)pAStack_d8 - (int)pAVar10));
              if (unaff_s5 == (ASN1_TEMPLATE *)0x0) {
                pAVar10 = pAStack_d8;
                if (unaff_s8 != (ASN1_ITEM *)0x0) {
                  pAVar11 = (ASN1_ITEM *)&DAT_00000077;
                  goto LAB_0056508c;
                }
              }
              else {
                unaff_s8 = (ASN1_ITEM *)(uint)((int)unaff_s8 < 2);
                if (((unaff_s8 != (ASN1_ITEM *)0x0) || (pAStack_d8->itype != '\0')) ||
                   (pAStack_d8->field_0x1 != '\0')) {
                  pAVar11 = (ASN1_ITEM *)&DAT_00000089;
LAB_0056508c:
                  it_00 = s_tasn_dec_c_0066ab2c;
                  (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x84);
                  pcVar9 = &it->itype;
                  ASN1_template_free(ppAVar5,(ASN1_TEMPLATE *)it);
                  goto LAB_00564e40;
                }
                pAVar10 = (ASN1_ITEM *)&pAStack_d8->field_0x2;
              }
              *in = (uchar *)pAVar10;
              uStack_120 = 1;
              goto LAB_00564e40;
            }
            pAVar11 = (ASN1_ITEM *)&DAT_0000003a;
          }
          it_00 = s_tasn_dec_c_0066ab2c;
          pcVar9 = &DAT_00000084;
          (*(code *)PTR_ERR_put_error_006a9030)(0xd);
          goto LAB_00564e40;
        }
        if ((iVar6 == iStack_d4) &&
           (unaff_s5 = (ASN1_TEMPLATE *)((uint)unaff_s5 & 0xc0), unaff_s5 == pAStack_d0)) {
          uStack_c4 = 0;
          goto LAB_00564f84;
        }
        uStack_c4 = 0;
        (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x68,0xa8,s_tasn_dec_c_0066ab2c);
      }
      pAStack_128 = (ASN1_ITEM *)0x670000;
      it_00 = s_tasn_dec_c_0066ab2c;
      pAVar11 = (ASN1_ITEM *)&DAT_0000003a;
      pcVar9 = &DAT_00000084;
      uStack_120 = 0;
      (*(code *)PTR_ERR_put_error_006a9030)(0xd);
    }
  }
LAB_00564e40:
  if (pAStack_ac == *(ASN1_ITEM **)puStack_124) {
    return uStack_120;
  }
  pcStack_104 = ASN1_item_d2i;
  pAVar10 = pAStack_ac;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar3 = PTR___stack_chk_guard_006aabf0;
  pvVar14 = *(void **)((int)it_00 + 0x10);
  pAStack_108 = unaff_s8;
  ppAStack_118 = unaff_s4;
  pAStack_11c = unaff_s3;
  pAStack_110 = unaff_s6;
  pAStack_114 = unaff_s5;
  auStack_154 = (undefined  [4])0x0;
  auStack_144[0] = 0;
  pAStack_150 = pAVar11;
  pAStack_14c = (ASN1_TEMPLATE *)0x0;
  pval_00 = (ASN1_ITEM *)auStack_154;
  if (pAVar10 != (ASN1_ITEM *)0x0) {
    pval_00 = pAVar10;
  }
  piStack_12c = *(int **)PTR___stack_chk_guard_006aabf0;
  if (pvVar14 == (void *)0x0) {
    switch(*it_00) {
    case '\0':
      goto switchD_00565630_caseD_0;
    case '\x01':
    case '\x06':
      pcStack_168 = (code *)0x0;
      goto switchD_005651a0_caseD_1;
    case '\x02':
      pcStack_168 = (code *)0x0;
LAB_005651ac:
      if ((*(int *)pval_00 == 0) &&
         (iVar6 = ASN1_item_ex_new((ASN1_VALUE **)pval_00,(ASN1_ITEM *)it_00), iVar6 == 0)) {
        uVar13 = 0x3a;
        uVar12 = 0x13e;
        goto LAB_00565288;
      }
      pAStack_14c = *(ASN1_TEMPLATE **)pcVar9;
      pAVar10 = (ASN1_ITEM *)0x0;
      pAVar11 = *(ASN1_ITEM **)((int)it_00 + 0xc);
      tt = *(ASN1_TEMPLATE **)((int)it_00 + 8);
      if ((int)pAVar11 < 1) {
LAB_00565228:
        if (pAVar10 == pAVar11) {
LAB_0056566c:
          uVar13 = 0x8f;
          uVar12 = 0x162;
          goto LAB_00565288;
        }
      }
      else {
        do {
          ppAVar5 = asn1_get_field_ptr((ASN1_VALUE **)pval_00,tt);
          iVar6 = asn1_template_ex_d2i(ppAVar5,auStack_154 + 8,pAStack_150,tt,1,auStack_144);
          if (iVar6 != -1) {
            if (0 < iVar6) {
              pAVar11 = *(ASN1_ITEM **)((int)it_00 + 0xc);
              goto LAB_00565228;
            }
            (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x78,0x3a,s_tasn_dec_c_0066ab2c,0x153);
            ASN1_item_ex_free((ASN1_VALUE **)pval_00,(ASN1_ITEM *)it_00);
            if (tt != (ASN1_TEMPLATE *)0x0) goto LAB_005657fc;
            goto LAB_005652b4;
          }
          pAVar10 = (ASN1_ITEM *)&pAVar10->field_0x1;
          tt = tt + 1;
        } while ((int)pAVar10 < (int)*(undefined **)((int)it_00 + 0xc));
        if (pAVar10 == (ASN1_ITEM *)*(undefined **)((int)it_00 + 0xc)) goto LAB_0056566c;
      }
      asn1_set_choice_selector((ASN1_VALUE **)pval_00,(int)pAVar10,(ASN1_ITEM *)it_00);
      *(ASN1_TEMPLATE **)pcVar9 = pAStack_14c;
      if (pcStack_168 == (code *)0x0) goto LAB_00565328;
      goto LAB_00565258;
    case '\x03':
      goto switchD_00565630_caseD_3;
    case '\x04':
      pcStack_168 = *(code **)(in_zero + 0x10);
      goto LAB_005655ac;
    case '\x05':
      goto switchD_00565630_caseD_5;
    }
    goto switchD_00565630_caseD_7;
  }
  pcStack_168 = *(code **)((int)pvVar14 + 0x10);
  switch(*it_00) {
  case '\0':
switchD_00565630_caseD_0:
    if (*(ASN1_TEMPLATE **)((int)it_00 + 8) == (ASN1_TEMPLATE *)0x0) {
      iVar6 = asn1_d2i_ex_primitive(pval_00,pcVar9,pAVar11,it_00,0xffffffff,0,0,auStack_144);
      if (iVar6 < 1) {
        iVar6 = 0;
        pAVar10 = (ASN1_ITEM *)pcVar9;
        goto LAB_005652d0;
      }
    }
    else {
      iVar6 = asn1_template_ex_d2i
                        (pval_00,pcVar9,pAVar11,*(ASN1_TEMPLATE **)((int)it_00 + 8),0,auStack_144);
      if (iVar6 < 1) goto switchD_00565630_caseD_7;
    }
    goto LAB_005653f0;
  case '\x01':
  case '\x06':
switchD_005651a0_caseD_1:
    pAStack_14c = *(ASN1_TEMPLATE **)pcVar9;
    pAVar10 = (ASN1_ITEM *)0x0;
    iVar7 = asn1_check_tlen(auStack_154 + 4,0,0,&cStack_156,&cStack_155,auStack_154 + 8,pAVar11,0x10
                            ,0,0,auStack_144);
    if (iVar7 == 0) {
      uVar13 = 0x3a;
      uVar12 = 0x17d;
    }
    else {
      iVar6 = 0;
      if (iVar7 == -1) goto LAB_005652d0;
      cVar2 = cStack_156;
      if ((pvVar14 != (void *)0x0) && ((*(uint *)((int)pvVar14 + 4) & 4) != 0)) {
        pAStack_150 = (ASN1_ITEM *)((int)pAVar11 - ((int)pAStack_14c - (int)*(uchar **)pcVar9));
        cVar2 = '\x01';
      }
      if (cStack_155 == '\0') {
        uVar13 = 0x95;
        uVar12 = 0x18c;
      }
      else if ((*(int *)pval_00 == 0) &&
              (iVar6 = ASN1_item_ex_new((ASN1_VALUE **)pval_00,(ASN1_ITEM *)it_00), iVar6 == 0)) {
        uVar13 = 0x3a;
        uVar12 = 0x193;
      }
      else {
        puStack_160 = auStack_144;
        if ((pcStack_168 != (code *)0x0) && (iVar6 = (*pcStack_168)(4,pval_00,it_00,0), iVar6 == 0))
        goto LAB_00565278;
        iVar6 = 0;
        tt_00 = *(ASN1_TEMPLATE **)((int)it_00 + 8);
        if (0 < *(long *)((int)it_00 + 0xc)) {
          do {
            tt = asn1_do_adb((ASN1_VALUE **)pval_00,tt_00,1);
            if (tt == (ASN1_TEMPLATE *)0x0) goto LAB_0056529c;
            ppAVar5 = asn1_get_field_ptr((ASN1_VALUE **)pval_00,tt);
            pAVar4 = pAStack_14c;
            if (pAStack_150 == (ASN1_ITEM *)0x0) {
              if (cStack_156 == '\0') goto LAB_00565740;
              goto LAB_00565908;
            }
            if (((1 < (int)pAStack_150) && (*(uchar *)&pAStack_14c->flags == '\0')) &&
               (*(uchar *)((int)&pAStack_14c->flags + 1) == '\0')) {
              pAStack_14c = (ASN1_TEMPLATE *)((int)&pAStack_14c->flags + 2);
              if (cStack_156 == '\0') {
                uVar13 = 0x9f;
                uVar12 = 0x1ac;
                goto LAB_00565288;
              }
              cStack_156 = '\0';
              pAStack_150 = (ASN1_ITEM *)((int)&pAStack_150[-1].sname + 2);
              goto LAB_0056572c;
            }
            uVar8 = 0;
            if (iVar6 != *(long *)((int)it_00 + 0xc) + -1) {
              uVar8 = tt->flags & 1;
            }
            iVar7 = asn1_template_ex_d2i(ppAVar5,auStack_154 + 8,pAStack_150,tt,uVar8,puStack_160);
            if (iVar7 == 0) goto LAB_005657e8;
            if (iVar7 == -1) {
              ASN1_template_free(ppAVar5,tt);
            }
            else {
              pAStack_150 = (ASN1_ITEM *)((int)pAStack_150 - ((int)pAStack_14c - (int)pAVar4));
            }
            iVar6 = iVar6 + 1;
            tt_00 = tt_00 + 1;
          } while (iVar6 < *(long *)((int)it_00 + 0xc));
        }
        if (cStack_156 != '\0') {
          if ((((int)pAStack_150 < 2) || (*(uchar *)&pAStack_14c->flags != '\0')) ||
             (*(uchar *)((int)&pAStack_14c->flags + 1) != '\0')) {
LAB_00565908:
            uVar13 = 0x89;
            uVar12 = 0x1d6;
            break;
          }
          pAStack_14c = (ASN1_TEMPLATE *)((int)&pAStack_14c->flags + 2);
        }
LAB_0056572c:
        if ((cVar2 != '\0') || (pAStack_150 == (ASN1_ITEM *)0x0)) {
LAB_00565740:
          if (iVar6 < *(long *)((int)it_00 + 0xc)) {
LAB_00565794:
            tt = asn1_do_adb((ASN1_VALUE **)pval_00,tt_00,1);
            if (tt != (ASN1_TEMPLATE *)0x0) {
              if ((tt->flags & 1) != 0) goto LAB_00565758;
              (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x78,0x79,s_tasn_dec_c_0066ab2c,0x1f5);
LAB_005657e8:
              ASN1_item_ex_free((ASN1_VALUE **)pval_00,(ASN1_ITEM *)it_00);
LAB_005657fc:
              pcVar9 = &DAT_0066ab40;
              (*(code *)PTR_ERR_add_error_data_006a9264)
                        (4,&DAT_0066ab40,tt->field_name,", Type=",*(char **)((int)it_00 + 0x18));
              goto switchD_00565630_caseD_7;
            }
            goto LAB_0056529c;
          }
          pAVar10 = *(ASN1_ITEM **)pcVar9;
          goto LAB_00565954;
        }
        uVar13 = 0x94;
        uVar12 = 0x1dd;
      }
    }
    break;
  case '\x02':
    if ((pcStack_168 == (code *)0x0) || (iVar6 = (*pcStack_168)(4,pval_00,it_00,0), iVar6 != 0))
    goto LAB_005651ac;
    goto LAB_00565278;
  case '\x03':
switchD_00565630_caseD_3:
    iVar6 = (**(code **)((int)pvVar14 + 8))(pval_00,pcVar9,pAVar11);
    pAVar10 = (ASN1_ITEM *)pcVar9;
    if (iVar6 != 0) goto LAB_00565328;
    uVar13 = 0x3a;
    uVar12 = 0x132;
    break;
  case '\x04':
LAB_005655ac:
    iVar6 = (*pcStack_168)(pval_00,pcVar9,pAVar11,it_00,0xffffffff,0,0,auStack_144);
    if (iVar6 < 1) {
      iVar6 = 0;
      pAVar10 = (ASN1_ITEM *)pcVar9;
      goto LAB_005652d0;
    }
LAB_005653f0:
    iVar6 = *(int *)pval_00;
    pAVar10 = (ASN1_ITEM *)pcVar9;
    goto LAB_005652d0;
  case '\x05':
switchD_00565630_caseD_5:
    pAStack_14c = *(ASN1_TEMPLATE **)pcVar9;
    iVar6 = asn1_check_tlen_constprop_1
                      (0,auStack_154 + 0xc,&cStack_157,0,0,auStack_154 + 8,pAVar11,1,auStack_144);
    if (iVar6 == 0) {
      uVar13 = 0x3a;
      uVar12 = 0xd2;
    }
    else if (cStack_157 == '\0') {
      if ((uStack_148 < 0x1f) &&
         ((*(uint *)(tag2bit + uStack_148 * 4) & *(long *)((int)it_00 + 4)) != 0)) {
        iVar6 = asn1_d2i_ex_primitive(pval_00,pcVar9,pAStack_150,it_00,uStack_148,0,0,auStack_144);
        if (iVar6 < 1) {
          iVar6 = 0;
          pAVar10 = (ASN1_ITEM *)pcVar9;
          goto LAB_005652d0;
        }
        goto LAB_005653f0;
      }
      uVar13 = 0x8c;
      uVar12 = 0xe6;
    }
    else {
      uVar13 = 0x8b;
      uVar12 = 0xdc;
    }
    break;
  default:
    goto switchD_00565630_caseD_7;
  }
LAB_00565288:
  (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x78,uVar13,s_tasn_dec_c_0066ab2c,uVar12);
LAB_0056529c:
  ASN1_item_ex_free((ASN1_VALUE **)pval_00,(ASN1_ITEM *)it_00);
LAB_005652b4:
  pcVar9 = s_Type__0066ab48;
  (*(code *)PTR_ERR_add_error_data_006a9264)(2,s_Type__0066ab48,*(char **)((int)it_00 + 0x18));
switchD_00565630_caseD_7:
  iVar6 = 0;
  pAVar10 = (ASN1_ITEM *)pcVar9;
LAB_005652d0:
  if (piStack_12c != *(int **)puVar3) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    return *(int *)(pAVar10->utype + *piStack_12c);
  }
  return iVar6;
LAB_00565758:
  iVar6 = iVar6 + 1;
  ppAVar5 = asn1_get_field_ptr((ASN1_VALUE **)pval_00,tt);
  tt_00 = tt_00 + 1;
  ASN1_template_free(ppAVar5,tt);
  if (*(long *)((int)it_00 + 0xc) <= iVar6) goto LAB_00565950;
  goto LAB_00565794;
LAB_00565950:
  pAVar10 = *(ASN1_ITEM **)pcVar9;
LAB_00565954:
  iVar6 = asn1_enc_save((ASN1_VALUE **)pval_00,(uchar *)pAVar10,(int)pAStack_14c - (int)pAVar10,
                        (ASN1_ITEM *)it_00);
  if (iVar6 != 0) {
    *(ASN1_TEMPLATE **)pcVar9 = pAStack_14c;
    if (pcStack_168 == (code *)0x0) {
      iVar6 = *(int *)pval_00;
      goto LAB_005652d0;
    }
LAB_00565258:
    pAVar10 = pval_00;
    iVar6 = (*pcStack_168)(5,pval_00,it_00,0);
    if (iVar6 != 0) {
LAB_00565328:
      iVar6 = *(int *)pval_00;
      goto LAB_005652d0;
    }
  }
LAB_00565278:
  uVar13 = 100;
  uVar12 = 0x205;
  goto LAB_00565288;
}

