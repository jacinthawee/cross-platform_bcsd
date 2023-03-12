
int ASN1_template_d2i(ASN1_VALUE **pval,uchar **in,long len,ASN1_TEMPLATE *tt)

{
  char cVar1;
  undefined *puVar2;
  uchar *puVar3;
  int in_zero;
  ASN1_ITEM_EXP *pAVar4;
  ASN1_TEMPLATE *pAVar5;
  ulong uVar6;
  int iVar7;
  uint uVar8;
  ASN1_VALUE **ppAVar9;
  ASN1_TEMPLATE *tt_00;
  char *pcVar10;
  ASN1_TEMPLATE *pAVar11;
  ASN1_ITEM_EXP *pAVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  char *it;
  int iVar15;
  ASN1_ITEM_EXP *unaff_s0;
  ASN1_TEMPLATE *pval_00;
  void *pvVar16;
  ASN1_TEMPLATE *unaff_s3;
  ASN1_VALUE **unaff_s4;
  uint unaff_s5;
  uchar **unaff_s6;
  long unaff_s7;
  ASN1_ITEM_EXP *unaff_s8;
  code *pcStack_e8;
  undefined *puStack_e0;
  char cStack_d7;
  char cStack_d6;
  char cStack_d5;
  undefined auStack_d4 [4];
  ASN1_ITEM_EXP *pAStack_d0;
  uchar *puStack_cc;
  char *pcStack_c8;
  undefined auStack_c4 [24];
  int *piStack_ac;
  ASN1_ITEM_EXP *pAStack_a8;
  undefined *puStack_a4;
  uint uStack_a0;
  ASN1_TEMPLATE *pAStack_9c;
  ASN1_VALUE **ppAStack_98;
  uint uStack_94;
  uchar **ppuStack_90;
  long lStack_8c;
  ASN1_ITEM_EXP *pAStack_88;
  code *pcStack_84;
  ASN1_TEMPLATE local_58;
  undefined local_44;
  uint local_40;
  ASN1_ITEM_EXP *local_3c;
  int local_38;
  uint local_34;
  int local_30;
  ASN1_TEMPLATE *local_2c;
  
  puStack_a4 = PTR___stack_chk_guard_006aabf0;
  local_44 = 0;
  local_2c = *(ASN1_TEMPLATE **)PTR___stack_chk_guard_006aabf0;
  uStack_a0 = 0;
  pcVar10 = (char *)in;
  pAVar12 = (ASN1_ITEM_EXP *)len;
  it = (char *)tt;
  if (pval != (ASN1_VALUE **)0x0) {
    unaff_s5 = tt->flags;
    unaff_s0 = (ASN1_ITEM_EXP *)*in;
    unaff_s3 = tt;
    unaff_s6 = in;
    local_58.flags = (ulong)unaff_s0;
    if ((unaff_s5 & 0x10) == 0) {
      uStack_a0 = asn1_template_noexp_d2i();
      pAVar12 = (ASN1_ITEM_EXP *)len;
    }
    else {
      iVar15 = tt->tag;
      local_58.item = unaff_s0;
      local_40 = ASN1_get_object((uchar **)&local_58.item,(long *)&local_58.field_name,&local_58.tag
                                 ,(int *)&local_58.offset,len);
      pAVar4 = local_58.item;
      local_30 = (int)local_58.item - (int)unaff_s0;
      local_3c = (ASN1_ITEM_EXP *)local_58.field_name;
      local_34 = local_58.offset;
      local_38 = local_58.tag;
      local_44 = 1;
      unaff_s4 = pval;
      unaff_s7 = len;
      if (((local_40 & 0x81) == 0) && (len < (int)((int)local_58.field_name + local_30))) {
        uVar13 = 0x9b;
LAB_00564fdc:
        (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x68,uVar13,s_tasn_dec_c_0066ab0c);
        local_44 = 0;
      }
      else {
        uStack_a0 = local_40 & 0x80;
        if (uStack_a0 != 0) {
          uVar13 = 0x66;
          goto LAB_00564fdc;
        }
        if (iVar15 < 0) {
LAB_00564f84:
          unaff_s5 = (uint)(char)local_40;
          local_58.flags = (ulong)local_58.item;
          unaff_s0 = (ASN1_ITEM_EXP *)(len - local_30);
          unaff_s8 = (ASN1_ITEM_EXP *)local_58.field_name;
          if ((local_40 & 1) != 0) {
            unaff_s8 = unaff_s0;
          }
          if ((unaff_s5 & 0x20) == 0) {
            pAVar12 = (ASN1_ITEM_EXP *)&DAT_00000078;
          }
          else {
            pcVar10 = (char *)&local_58;
            pAVar12 = unaff_s8;
            iVar15 = asn1_template_noexp_d2i(pval);
            if (iVar15 != 0) {
              unaff_s5 = unaff_s5 & 1;
              unaff_s8 = (ASN1_ITEM_EXP *)((int)unaff_s8 - (local_58.flags - (int)pAVar4));
              if (unaff_s5 == 0) {
                pAVar4 = (ASN1_ITEM_EXP *)local_58.flags;
                if (unaff_s8 != (ASN1_ITEM_EXP *)0x0) {
                  pAVar12 = (ASN1_ITEM_EXP *)&DAT_00000077;
                  goto LAB_0056508c;
                }
              }
              else {
                unaff_s8 = (ASN1_ITEM_EXP *)(uint)((int)unaff_s8 < 2);
                if (((unaff_s8 != (ASN1_ITEM_EXP *)0x0) || (*(char *)local_58.flags != '\0')) ||
                   (*(undefined *)(local_58.flags + 1) != '\0')) {
                  pAVar12 = (ASN1_ITEM_EXP *)&DAT_00000089;
LAB_0056508c:
                  it = s_tasn_dec_c_0066ab0c;
                  (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x84);
                  pcVar10 = (char *)tt;
                  ASN1_template_free(pval,tt);
                  goto LAB_00564e40;
                }
                pAVar4 = (ASN1_ITEM_EXP *)(local_58.flags + 2);
              }
              *in = (uchar *)pAVar4;
              uStack_a0 = 1;
              goto LAB_00564e40;
            }
            pAVar12 = (ASN1_ITEM_EXP *)&DAT_0000003a;
          }
          it = s_tasn_dec_c_0066ab0c;
          pcVar10 = &DAT_00000084;
          (*(code *)PTR_ERR_put_error_006a9030)(0xd);
          goto LAB_00564e40;
        }
        if ((iVar15 == local_58.tag) && (unaff_s5 = unaff_s5 & 0xc0, unaff_s5 == local_58.offset)) {
          local_44 = 0;
          goto LAB_00564f84;
        }
        local_44 = 0;
        (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x68,0xa8,s_tasn_dec_c_0066ab0c);
      }
      unaff_s0 = (ASN1_ITEM_EXP *)0x670000;
      it = s_tasn_dec_c_0066ab0c;
      pAVar12 = (ASN1_ITEM_EXP *)&DAT_0000003a;
      pcVar10 = &DAT_00000084;
      uStack_a0 = 0;
      (*(code *)PTR_ERR_put_error_006a9030)(0xd);
      unaff_s8 = (ASN1_ITEM_EXP *)local_58.field_name;
    }
  }
LAB_00564e40:
  if (local_2c == *(ASN1_TEMPLATE **)puStack_a4) {
    return uStack_a0;
  }
  pcStack_84 = ASN1_item_d2i;
  pAVar11 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar2 = PTR___stack_chk_guard_006aabf0;
  pvVar16 = *(void **)((int)it + 0x10);
  pAStack_a8 = unaff_s0;
  pAStack_88 = unaff_s8;
  ppAStack_98 = unaff_s4;
  pAStack_9c = unaff_s3;
  lStack_8c = unaff_s7;
  ppuStack_90 = unaff_s6;
  uStack_94 = unaff_s5;
  auStack_d4 = (undefined  [4])0x0;
  auStack_c4[0] = 0;
  pAStack_d0 = pAVar12;
  puStack_cc = (uchar *)0x0;
  pval_00 = (ASN1_TEMPLATE *)auStack_d4;
  if (pAVar11 != (ASN1_TEMPLATE *)0x0) {
    pval_00 = pAVar11;
  }
  piStack_ac = *(int **)PTR___stack_chk_guard_006aabf0;
  if (pvVar16 == (void *)0x0) {
    switch(*it) {
    case '\0':
      goto switchD_00565630_caseD_0;
    case '\x01':
    case '\x06':
      pcStack_e8 = (code *)0x0;
      goto switchD_005651a0_caseD_1;
    case '\x02':
      pcStack_e8 = (code *)0x0;
LAB_005651ac:
      if ((pval_00->flags == 0) &&
         (iVar15 = ASN1_item_ex_new((ASN1_VALUE **)pval_00,(ASN1_ITEM *)it), iVar15 == 0)) {
        uVar14 = 0x3a;
        uVar13 = 0x13e;
        goto LAB_00565288;
      }
      puStack_cc = (uchar *)*(ulong *)pcVar10;
      pAVar11 = (ASN1_TEMPLATE *)0x0;
      pAVar5 = *(ASN1_TEMPLATE **)((int)it + 0xc);
      tt_00 = *(ASN1_TEMPLATE **)((int)it + 8);
      if ((int)pAVar5 < 1) {
LAB_00565228:
        if (pAVar11 == pAVar5) {
LAB_0056566c:
          uVar14 = 0x8f;
          uVar13 = 0x162;
          goto LAB_00565288;
        }
      }
      else {
        do {
          ppAVar9 = asn1_get_field_ptr((ASN1_VALUE **)pval_00,tt_00);
          iVar15 = asn1_template_ex_d2i(ppAVar9,auStack_d4 + 8,pAStack_d0,tt_00,1,auStack_c4);
          if (iVar15 != -1) {
            if (0 < iVar15) {
              pAVar5 = *(ASN1_TEMPLATE **)((int)it + 0xc);
              goto LAB_00565228;
            }
            (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x78,0x3a,s_tasn_dec_c_0066ab0c,0x153);
            ASN1_item_ex_free((ASN1_VALUE **)pval_00,(ASN1_ITEM *)it);
            if (tt_00 != (ASN1_TEMPLATE *)0x0) goto LAB_005657fc;
            goto LAB_005652b4;
          }
          pAVar11 = (ASN1_TEMPLATE *)((int)&pAVar11->flags + 1);
          tt_00 = tt_00 + 1;
        } while ((int)pAVar11 < (int)*(ASN1_TEMPLATE **)((int)it + 0xc));
        if (pAVar11 == *(ASN1_TEMPLATE **)((int)it + 0xc)) goto LAB_0056566c;
      }
      asn1_set_choice_selector((ASN1_VALUE **)pval_00,(int)pAVar11,(ASN1_ITEM *)it);
      *(ulong *)pcVar10 = (ulong)puStack_cc;
      if (pcStack_e8 == (code *)0x0) goto LAB_00565328;
      goto LAB_00565258;
    case '\x03':
      goto switchD_00565630_caseD_3;
    case '\x04':
      pcStack_e8 = *(code **)(in_zero + 0x10);
      goto LAB_005655ac;
    case '\x05':
      goto switchD_00565630_caseD_5;
    }
    goto switchD_00565630_caseD_7;
  }
  pcStack_e8 = *(code **)((int)pvVar16 + 0x10);
  switch(*it) {
  case '\0':
switchD_00565630_caseD_0:
    if (*(ASN1_TEMPLATE **)((int)it + 8) == (ASN1_TEMPLATE *)0x0) {
      iVar15 = asn1_d2i_ex_primitive(pval_00,pcVar10,pAVar12,it,0xffffffff,0,0,auStack_c4);
      if (iVar15 < 1) {
        uVar6 = 0;
        pAVar11 = (ASN1_TEMPLATE *)pcVar10;
        goto LAB_005652d0;
      }
    }
    else {
      iVar15 = asn1_template_ex_d2i
                         (pval_00,pcVar10,pAVar12,*(ASN1_TEMPLATE **)((int)it + 8),0,auStack_c4);
      if (iVar15 < 1) goto switchD_00565630_caseD_7;
    }
    goto LAB_005653f0;
  case '\x01':
  case '\x06':
switchD_005651a0_caseD_1:
    puStack_cc = (uchar *)*(ulong *)pcVar10;
    pAVar11 = (ASN1_TEMPLATE *)0x0;
    iVar15 = asn1_check_tlen(auStack_d4 + 4,0,0,&cStack_d6,&cStack_d5,auStack_d4 + 8,pAVar12,0x10,0,
                             0,auStack_c4);
    if (iVar15 == 0) {
      uVar14 = 0x3a;
      uVar13 = 0x17d;
    }
    else {
      uVar6 = 0;
      if (iVar15 == -1) goto LAB_005652d0;
      cVar1 = cStack_d6;
      if ((pvVar16 != (void *)0x0) && ((*(uint *)((int)pvVar16 + 4) & 4) != 0)) {
        pAStack_d0 = (ASN1_ITEM_EXP *)((int)pAVar12 - ((int)puStack_cc - (int)*(ulong *)pcVar10));
        cVar1 = '\x01';
      }
      if (cStack_d5 == '\0') {
        uVar14 = 0x95;
        uVar13 = 0x18c;
      }
      else if ((pval_00->flags == 0) &&
              (iVar15 = ASN1_item_ex_new((ASN1_VALUE **)pval_00,(ASN1_ITEM *)it), iVar15 == 0)) {
        uVar14 = 0x3a;
        uVar13 = 0x193;
      }
      else {
        puStack_e0 = auStack_c4;
        if ((pcStack_e8 != (code *)0x0) && (iVar15 = (*pcStack_e8)(4,pval_00,it,0), iVar15 == 0))
        goto LAB_00565278;
        iVar15 = 0;
        pAVar11 = *(ASN1_TEMPLATE **)((int)it + 8);
        if (0 < *(long *)((int)it + 0xc)) {
          do {
            tt_00 = asn1_do_adb((ASN1_VALUE **)pval_00,pAVar11,1);
            if (tt_00 == (ASN1_TEMPLATE *)0x0) goto LAB_0056529c;
            ppAVar9 = asn1_get_field_ptr((ASN1_VALUE **)pval_00,tt_00);
            puVar3 = puStack_cc;
            if (pAStack_d0 == (ASN1_ITEM_EXP *)0x0) {
              if (cStack_d6 != '\0') goto LAB_00565908;
              goto LAB_00565740;
            }
            if (((1 < (int)pAStack_d0) && (*puStack_cc == '\0')) && (puStack_cc[1] == '\0')) {
              puStack_cc = puStack_cc + 2;
              if (cStack_d6 != '\0') {
                cStack_d6 = '\0';
                pAStack_d0 = (ASN1_ITEM_EXP *)((int)&pAStack_d0[-1].sname + 2);
                goto LAB_0056572c;
              }
              uVar14 = 0x9f;
              uVar13 = 0x1ac;
              goto LAB_00565288;
            }
            uVar8 = 0;
            if (iVar15 != *(long *)((int)it + 0xc) + -1) {
              uVar8 = tt_00->flags & 1;
            }
            iVar7 = asn1_template_ex_d2i(ppAVar9,auStack_d4 + 8,pAStack_d0,tt_00,uVar8,puStack_e0);
            if (iVar7 == 0) goto LAB_005657e8;
            if (iVar7 == -1) {
              ASN1_template_free(ppAVar9,tt_00);
            }
            else {
              pAStack_d0 = (ASN1_ITEM_EXP *)((int)pAStack_d0 - ((int)puStack_cc - (int)puVar3));
            }
            iVar15 = iVar15 + 1;
            pAVar11 = pAVar11 + 1;
          } while (iVar15 < *(long *)((int)it + 0xc));
        }
        if (cStack_d6 != '\0') {
          if ((((int)pAStack_d0 < 2) || (*puStack_cc != '\0')) || (puStack_cc[1] != '\0')) {
LAB_00565908:
            uVar14 = 0x89;
            uVar13 = 0x1d6;
            break;
          }
          puStack_cc = puStack_cc + 2;
        }
LAB_0056572c:
        if ((cVar1 != '\0') || (pAStack_d0 == (ASN1_ITEM_EXP *)0x0)) {
LAB_00565740:
          if (iVar15 < *(long *)((int)it + 0xc)) {
LAB_00565794:
            tt_00 = asn1_do_adb((ASN1_VALUE **)pval_00,pAVar11,1);
            if (tt_00 != (ASN1_TEMPLATE *)0x0) {
              if ((tt_00->flags & 1) != 0) goto LAB_00565758;
              (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x78,0x79,s_tasn_dec_c_0066ab0c,0x1f5);
LAB_005657e8:
              ASN1_item_ex_free((ASN1_VALUE **)pval_00,(ASN1_ITEM *)it);
LAB_005657fc:
              pcVar10 = &DAT_0066ab20;
              (*(code *)PTR_ERR_add_error_data_006a9264)
                        (4,&DAT_0066ab20,tt_00->field_name,", Type=",*(char **)((int)it + 0x18));
              goto switchD_00565630_caseD_7;
            }
            goto LAB_0056529c;
          }
          pAVar11 = (ASN1_TEMPLATE *)*(ulong *)pcVar10;
          goto LAB_00565954;
        }
        uVar14 = 0x94;
        uVar13 = 0x1dd;
      }
    }
    break;
  case '\x02':
    if ((pcStack_e8 == (code *)0x0) || (iVar15 = (*pcStack_e8)(4,pval_00,it,0), iVar15 != 0))
    goto LAB_005651ac;
    goto LAB_00565278;
  case '\x03':
switchD_00565630_caseD_3:
    iVar15 = (**(code **)((int)pvVar16 + 8))(pval_00,pcVar10,pAVar12);
    pAVar11 = (ASN1_TEMPLATE *)pcVar10;
    if (iVar15 != 0) goto LAB_00565328;
    uVar14 = 0x3a;
    uVar13 = 0x132;
    break;
  case '\x04':
LAB_005655ac:
    iVar15 = (*pcStack_e8)(pval_00,pcVar10,pAVar12,it,0xffffffff,0,0,auStack_c4);
    if (iVar15 < 1) {
      uVar6 = 0;
      pAVar11 = (ASN1_TEMPLATE *)pcVar10;
      goto LAB_005652d0;
    }
LAB_005653f0:
    uVar6 = pval_00->flags;
    pAVar11 = (ASN1_TEMPLATE *)pcVar10;
    goto LAB_005652d0;
  case '\x05':
switchD_00565630_caseD_5:
    puStack_cc = (uchar *)*(ulong *)pcVar10;
    iVar15 = asn1_check_tlen_constprop_1
                       (0,auStack_d4 + 0xc,&cStack_d7,0,0,auStack_d4 + 8,pAVar12,1,auStack_c4);
    if (iVar15 == 0) {
      uVar14 = 0x3a;
      uVar13 = 0xd2;
    }
    else if (cStack_d7 == '\0') {
      if ((pcStack_c8 < (char *)0x1f) &&
         ((*(uint *)(tag2bit + (int)pcStack_c8 * 4) & *(long *)((int)it + 4)) != 0)) {
        iVar15 = asn1_d2i_ex_primitive(pval_00,pcVar10,pAStack_d0,it,pcStack_c8,0,0,auStack_c4);
        if (iVar15 < 1) {
          uVar6 = 0;
          pAVar11 = (ASN1_TEMPLATE *)pcVar10;
          goto LAB_005652d0;
        }
        goto LAB_005653f0;
      }
      uVar14 = 0x8c;
      uVar13 = 0xe6;
    }
    else {
      uVar14 = 0x8b;
      uVar13 = 0xdc;
    }
    break;
  default:
    goto switchD_00565630_caseD_7;
  }
LAB_00565288:
  (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x78,uVar14,s_tasn_dec_c_0066ab0c,uVar13);
LAB_0056529c:
  ASN1_item_ex_free((ASN1_VALUE **)pval_00,(ASN1_ITEM *)it);
LAB_005652b4:
  pcVar10 = s_Type__0066ab28;
  (*(code *)PTR_ERR_add_error_data_006a9264)(2,s_Type__0066ab28,*(char **)((int)it + 0x18));
switchD_00565630_caseD_7:
  uVar6 = 0;
  pAVar11 = (ASN1_TEMPLATE *)pcVar10;
LAB_005652d0:
  if (piStack_ac == *(int **)puVar2) {
    return uVar6;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  return *(int *)(pAVar11->tag + *piStack_ac);
LAB_00565758:
  iVar15 = iVar15 + 1;
  ppAVar9 = asn1_get_field_ptr((ASN1_VALUE **)pval_00,tt_00);
  pAVar11 = pAVar11 + 1;
  ASN1_template_free(ppAVar9,tt_00);
  if (*(long *)((int)it + 0xc) <= iVar15) goto LAB_00565950;
  goto LAB_00565794;
LAB_00565950:
  pAVar11 = (ASN1_TEMPLATE *)*(ulong *)pcVar10;
LAB_00565954:
  iVar15 = asn1_enc_save((ASN1_VALUE **)pval_00,(uchar *)pAVar11,(int)puStack_cc - (int)pAVar11,
                         (ASN1_ITEM *)it);
  if (iVar15 != 0) {
    *(ulong *)pcVar10 = (ulong)puStack_cc;
    if (pcStack_e8 == (code *)0x0) {
      uVar6 = pval_00->flags;
      goto LAB_005652d0;
    }
LAB_00565258:
    pAVar11 = pval_00;
    iVar15 = (*pcStack_e8)(5,pval_00,it,0);
    if (iVar15 != 0) {
LAB_00565328:
      uVar6 = pval_00->flags;
      goto LAB_005652d0;
    }
  }
LAB_00565278:
  uVar14 = 100;
  uVar13 = 0x205;
  goto LAB_00565288;
}

