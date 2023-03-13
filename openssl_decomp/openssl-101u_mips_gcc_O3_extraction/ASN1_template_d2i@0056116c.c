
int ASN1_template_d2i(ASN1_VALUE **pval,uchar **in,long len,ASN1_TEMPLATE *tt)

{
  char cVar1;
  undefined *puVar2;
  uchar *puVar3;
  int in_zero;
  ASN1_ITEM_EXP *pAVar4;
  ulong uVar5;
  ASN1_TEMPLATE *pAVar6;
  uint uVar7;
  ASN1_VALUE **ppAVar8;
  ASN1_TEMPLATE *tt_00;
  char *pcVar9;
  ASN1_TEMPLATE *pAVar10;
  ASN1_ITEM_EXP *pAVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  char *it;
  int iVar14;
  ASN1_ITEM_EXP *unaff_s0;
  ASN1_TEMPLATE *pval_00;
  void *pvVar15;
  ASN1_TEMPLATE *unaff_s3;
  int iVar16;
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
  
  puStack_a4 = PTR___stack_chk_guard_006a9ae8;
  local_44 = 0;
  local_2c = *(ASN1_TEMPLATE **)PTR___stack_chk_guard_006a9ae8;
  uStack_a0 = 0;
  pcVar9 = (char *)in;
  pAVar11 = (ASN1_ITEM_EXP *)len;
  it = (char *)tt;
  if (pval != (ASN1_VALUE **)0x0) {
    unaff_s5 = tt->flags;
    unaff_s0 = (ASN1_ITEM_EXP *)*in;
    unaff_s3 = tt;
    unaff_s6 = in;
    local_58.flags = (ulong)unaff_s0;
    if ((unaff_s5 & 0x10) == 0) {
      uStack_a0 = asn1_template_noexp_d2i();
      pAVar11 = (ASN1_ITEM_EXP *)len;
    }
    else {
      iVar14 = tt->tag;
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
        uVar12 = 0x9b;
LAB_0056138c:
        (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x68,uVar12,s_tasn_dec_c_0066a0bc);
        local_44 = 0;
      }
      else {
        uStack_a0 = local_40 & 0x80;
        if (uStack_a0 != 0) {
          uVar12 = 0x66;
          goto LAB_0056138c;
        }
        if (iVar14 < 0) {
LAB_00561334:
          unaff_s5 = (uint)(char)local_40;
          local_58.flags = (ulong)local_58.item;
          unaff_s0 = (ASN1_ITEM_EXP *)(len - local_30);
          unaff_s8 = (ASN1_ITEM_EXP *)local_58.field_name;
          if ((local_40 & 1) != 0) {
            unaff_s8 = unaff_s0;
          }
          if ((unaff_s5 & 0x20) == 0) {
            pAVar11 = (ASN1_ITEM_EXP *)&DAT_00000078;
          }
          else {
            pcVar9 = (char *)&local_58;
            pAVar11 = unaff_s8;
            iVar14 = asn1_template_noexp_d2i(pval);
            if (iVar14 != 0) {
              unaff_s5 = unaff_s5 & 1;
              unaff_s8 = (ASN1_ITEM_EXP *)((int)unaff_s8 - (local_58.flags - (int)pAVar4));
              if (unaff_s5 == 0) {
                pAVar4 = (ASN1_ITEM_EXP *)local_58.flags;
                if (unaff_s8 != (ASN1_ITEM_EXP *)0x0) {
                  pAVar11 = (ASN1_ITEM_EXP *)&DAT_00000077;
                  goto LAB_0056143c;
                }
              }
              else {
                unaff_s8 = (ASN1_ITEM_EXP *)(uint)((int)unaff_s8 < 2);
                if (((unaff_s8 != (ASN1_ITEM_EXP *)0x0) || (*(char *)local_58.flags != '\0')) ||
                   (*(undefined *)(local_58.flags + 1) != '\0')) {
                  pAVar11 = (ASN1_ITEM_EXP *)&DAT_00000089;
LAB_0056143c:
                  it = s_tasn_dec_c_0066a0bc;
                  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x84);
                  pcVar9 = (char *)tt;
                  ASN1_template_free(pval,tt);
                  goto LAB_005611f0;
                }
                pAVar4 = (ASN1_ITEM_EXP *)(local_58.flags + 2);
              }
              *in = (uchar *)pAVar4;
              uStack_a0 = 1;
              goto LAB_005611f0;
            }
            pAVar11 = (ASN1_ITEM_EXP *)&DAT_0000003a;
          }
          it = s_tasn_dec_c_0066a0bc;
          pcVar9 = &DAT_00000084;
          (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
          goto LAB_005611f0;
        }
        if ((iVar14 == local_58.tag) && (unaff_s5 = unaff_s5 & 0xc0, unaff_s5 == local_58.offset)) {
          local_44 = 0;
          goto LAB_00561334;
        }
        local_44 = 0;
        (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x68,0xa8,s_tasn_dec_c_0066a0bc);
      }
      unaff_s0 = (ASN1_ITEM_EXP *)0x670000;
      it = s_tasn_dec_c_0066a0bc;
      pAVar11 = (ASN1_ITEM_EXP *)&DAT_0000003a;
      pcVar9 = &DAT_00000084;
      uStack_a0 = 0;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
      unaff_s8 = (ASN1_ITEM_EXP *)local_58.field_name;
    }
  }
LAB_005611f0:
  if (local_2c == *(ASN1_TEMPLATE **)puStack_a4) {
    return uStack_a0;
  }
  pcStack_84 = ASN1_item_d2i;
  pAVar10 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  pvVar15 = *(void **)((int)it + 0x10);
  pAStack_a8 = unaff_s0;
  pAStack_88 = unaff_s8;
  ppAStack_98 = unaff_s4;
  pAStack_9c = unaff_s3;
  lStack_8c = unaff_s7;
  ppuStack_90 = unaff_s6;
  uStack_94 = unaff_s5;
  auStack_d4 = (undefined  [4])0x0;
  auStack_c4[0] = 0;
  pAStack_d0 = pAVar11;
  puStack_cc = (uchar *)0x0;
  pval_00 = (ASN1_TEMPLATE *)auStack_d4;
  if (pAVar10 != (ASN1_TEMPLATE *)0x0) {
    pval_00 = pAVar10;
  }
  piStack_ac = *(int **)PTR___stack_chk_guard_006a9ae8;
  if (pvVar15 == (void *)0x0) {
    switch(*it) {
    case '\0':
      goto switchD_005619f8_caseD_0;
    case '\x01':
    case '\x06':
      pcStack_e8 = (code *)0x0;
      goto switchD_00561550_caseD_1;
    case '\x02':
      pcStack_e8 = (code *)0x0;
LAB_00561954:
      if (pval_00->flags == 0) {
        iVar14 = ASN1_item_ex_new((ASN1_VALUE **)pval_00,(ASN1_ITEM *)it);
        if (iVar14 == 0) {
          uVar13 = 0x3a;
          uVar12 = 0x13f;
          goto LAB_0056163c;
        }
        pAVar6 = *(ASN1_TEMPLATE **)((int)it + 0xc);
      }
      else {
        iVar14 = asn1_get_choice_selector((ASN1_VALUE **)pval_00,(ASN1_ITEM *)it);
        pAVar6 = *(ASN1_TEMPLATE **)((int)it + 0xc);
        if ((-1 < iVar14) && (iVar14 < (int)pAVar6)) {
          pAVar10 = *(ASN1_TEMPLATE **)((int)it + 8);
          ppAVar8 = asn1_get_field_ptr((ASN1_VALUE **)pval_00,pAVar10 + iVar14);
          ASN1_template_free(ppAVar8,pAVar10 + iVar14);
          asn1_set_choice_selector((ASN1_VALUE **)pval_00,-1,(ASN1_ITEM *)it);
          pAVar6 = *(ASN1_TEMPLATE **)((int)it + 0xc);
        }
      }
      puStack_cc = (uchar *)*(ulong *)pcVar9;
      pAVar10 = (ASN1_TEMPLATE *)0x0;
      tt_00 = *(ASN1_TEMPLATE **)((int)it + 8);
      if ((int)pAVar6 < 1) {
LAB_005615e0:
        if (pAVar10 == pAVar6) {
LAB_00561a34:
          uVar13 = 0x8f;
          uVar12 = 0x15e;
          goto LAB_0056163c;
        }
      }
      else {
        do {
          ppAVar8 = asn1_get_field_ptr((ASN1_VALUE **)pval_00,tt_00);
          iVar14 = asn1_template_ex_d2i(ppAVar8,auStack_d4 + 8,pAStack_d0,tt_00,1,auStack_c4);
          if (iVar14 != -1) {
            if (iVar14 < 1) {
              (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x78,0x3a,s_tasn_dec_c_0066a0bc,0x152);
              ASN1_item_ex_free((ASN1_VALUE **)pval_00,(ASN1_ITEM *)it);
              if (tt_00 == (ASN1_TEMPLATE *)0x0) goto LAB_00561668;
              goto LAB_00561cf8;
            }
            pAVar6 = *(ASN1_TEMPLATE **)((int)it + 0xc);
            goto LAB_005615e0;
          }
          pAVar10 = (ASN1_TEMPLATE *)((int)&pAVar10->flags + 1);
          tt_00 = tt_00 + 1;
        } while ((int)pAVar10 < (int)*(ASN1_TEMPLATE **)((int)it + 0xc));
        if (pAVar10 == *(ASN1_TEMPLATE **)((int)it + 0xc)) goto LAB_00561a34;
      }
      asn1_set_choice_selector((ASN1_VALUE **)pval_00,(int)pAVar10,(ASN1_ITEM *)it);
      goto joined_r0x00561600;
    case '\x03':
      goto switchD_005619f8_caseD_3;
    case '\x04':
      pcStack_e8 = *(code **)(in_zero + 0x10);
      goto LAB_005618f4;
    case '\x05':
      goto switchD_005619f8_caseD_5;
    }
    goto switchD_005619f8_caseD_7;
  }
  pcStack_e8 = *(code **)((int)pvVar15 + 0x10);
  switch(*it) {
  case '\0':
switchD_005619f8_caseD_0:
    if (*(ASN1_TEMPLATE **)((int)it + 8) == (ASN1_TEMPLATE *)0x0) {
      iVar14 = asn1_d2i_ex_primitive(pval_00,pcVar9,pAVar11,it,0xffffffff,0,0,auStack_c4);
      if (iVar14 < 1) {
        uVar5 = 0;
        pAVar10 = (ASN1_TEMPLATE *)pcVar9;
        goto LAB_00561684;
      }
    }
    else {
      iVar14 = asn1_template_ex_d2i
                         (pval_00,pcVar9,pAVar11,*(ASN1_TEMPLATE **)((int)it + 8),0,auStack_c4);
      if (iVar14 < 1) goto switchD_005619f8_caseD_7;
    }
    goto LAB_005617a4;
  case '\x01':
  case '\x06':
switchD_00561550_caseD_1:
    puStack_cc = (uchar *)*(ulong *)pcVar9;
    pAVar10 = (ASN1_TEMPLATE *)0x0;
    iVar14 = asn1_check_tlen(auStack_d4 + 4,0,0,&cStack_d6,&cStack_d5,auStack_d4 + 8,pAVar11,0x10,0,
                             0,auStack_c4);
    if (iVar14 == 0) {
      uVar13 = 0x3a;
      uVar12 = 0x176;
    }
    else {
      uVar5 = 0;
      if (iVar14 == -1) goto LAB_00561684;
      cVar1 = cStack_d6;
      if ((pvVar15 != (void *)0x0) && ((*(uint *)((int)pvVar15 + 4) & 4) != 0)) {
        pAStack_d0 = (ASN1_ITEM_EXP *)((int)pAVar11 - ((int)puStack_cc - (int)*(ulong *)pcVar9));
        cVar1 = '\x01';
      }
      if (cStack_d5 == '\0') {
        uVar13 = 0x95;
        uVar12 = 0x182;
      }
      else if ((pval_00->flags == 0) &&
              (iVar14 = ASN1_item_ex_new((ASN1_VALUE **)pval_00,(ASN1_ITEM *)it), iVar14 == 0)) {
        uVar13 = 0x3a;
        uVar12 = 0x187;
      }
      else {
        puStack_e0 = auStack_c4;
        if ((pcStack_e8 != (code *)0x0) && (iVar14 = (*pcStack_e8)(4,pval_00,it,0), iVar14 == 0))
        goto LAB_00561628;
        iVar14 = *(long *)((int)it + 0xc);
        iVar16 = 0;
        pAVar10 = *(ASN1_TEMPLATE **)((int)it + 8);
        if (0 < iVar14) {
          do {
            if ((pAVar10->flags & 0x300) != 0) {
              pAVar6 = asn1_do_adb((ASN1_VALUE **)pval_00,pAVar10,1);
              ppAVar8 = asn1_get_field_ptr((ASN1_VALUE **)pval_00,pAVar6);
              ASN1_template_free(ppAVar8,pAVar6);
              iVar14 = *(long *)((int)it + 0xc);
            }
            iVar16 = iVar16 + 1;
            pAVar10 = pAVar10 + 1;
          } while (iVar16 < iVar14);
          pAVar10 = *(ASN1_TEMPLATE **)((int)it + 8);
          iVar16 = 0;
          if (0 < iVar14) {
            do {
              tt_00 = asn1_do_adb((ASN1_VALUE **)pval_00,pAVar10,1);
              if (tt_00 == (ASN1_TEMPLATE *)0x0) goto LAB_00561650;
              ppAVar8 = asn1_get_field_ptr((ASN1_VALUE **)pval_00,tt_00);
              puVar3 = puStack_cc;
              if (pAStack_d0 == (ASN1_ITEM_EXP *)0x0) {
                if (cStack_d6 == '\0') goto LAB_00561c3c;
                goto LAB_00561e04;
              }
              if (((1 < (int)pAStack_d0) && (*puStack_cc == '\0')) && (puStack_cc[1] == '\0')) {
                puStack_cc = puStack_cc + 2;
                if (cStack_d6 == '\0') {
                  uVar13 = 0x9f;
                  uVar12 = 0x1a7;
                  goto LAB_0056163c;
                }
                cStack_d6 = '\0';
                pAStack_d0 = (ASN1_ITEM_EXP *)((int)&pAStack_d0[-1].sname + 2);
                goto LAB_00561c28;
              }
              uVar7 = 0;
              if (*(long *)((int)it + 0xc) + -1 != iVar16) {
                uVar7 = tt_00->flags & 1;
              }
              iVar14 = asn1_template_ex_d2i
                                 (ppAVar8,auStack_d4 + 8,pAStack_d0,tt_00,uVar7,puStack_e0);
              if (iVar14 == 0) goto LAB_00561ce4;
              if (iVar14 == -1) {
                ASN1_template_free(ppAVar8,tt_00);
              }
              else {
                pAStack_d0 = (ASN1_ITEM_EXP *)((int)pAStack_d0 - ((int)puStack_cc - (int)puVar3));
              }
              iVar16 = iVar16 + 1;
              pAVar10 = pAVar10 + 1;
            } while (iVar16 < *(long *)((int)it + 0xc));
          }
        }
        if (cStack_d6 != '\0') {
          if ((((int)pAStack_d0 < 2) || (*puStack_cc != '\0')) || (puStack_cc[1] != '\0')) {
LAB_00561e04:
            uVar13 = 0x89;
            uVar12 = 0x1ce;
            break;
          }
          puStack_cc = puStack_cc + 2;
        }
LAB_00561c28:
        if ((cVar1 != '\0') || (pAStack_d0 == (ASN1_ITEM_EXP *)0x0)) {
LAB_00561c3c:
          if (iVar16 < *(long *)((int)it + 0xc)) {
LAB_00561c90:
            tt_00 = asn1_do_adb((ASN1_VALUE **)pval_00,pAVar10,1);
            if (tt_00 != (ASN1_TEMPLATE *)0x0) {
              if ((tt_00->flags & 1) != 0) goto LAB_00561c54;
              (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x78,0x79,s_tasn_dec_c_0066a0bc,0x1e7);
LAB_00561ce4:
              ASN1_item_ex_free((ASN1_VALUE **)pval_00,(ASN1_ITEM *)it);
LAB_00561cf8:
              pcVar9 = (char *)&DAT_0066a0d0;
              (*(code *)PTR_ERR_add_error_data_006a813c)
                        (4,&DAT_0066a0d0,tt_00->field_name,", Type=",*(char **)((int)it + 0x18));
              goto switchD_005619f8_caseD_7;
            }
            goto LAB_00561650;
          }
          pAVar10 = (ASN1_TEMPLATE *)*(ulong *)pcVar9;
          goto LAB_00561a70;
        }
        uVar13 = 0x94;
        uVar12 = 0x1d3;
      }
    }
    break;
  case '\x02':
    if ((pcStack_e8 == (code *)0x0) || (iVar14 = (*pcStack_e8)(4,pval_00,it,0), iVar14 != 0))
    goto LAB_00561954;
    goto LAB_00561628;
  case '\x03':
switchD_005619f8_caseD_3:
    iVar14 = (**(code **)((int)pvVar15 + 8))(pval_00,pcVar9,pAVar11);
    if (iVar14 != 0) {
      uVar5 = pval_00->flags;
      pAVar10 = (ASN1_TEMPLATE *)pcVar9;
      goto LAB_00561684;
    }
    uVar13 = 0x3a;
    uVar12 = 0x12f;
    break;
  case '\x04':
LAB_005618f4:
    iVar14 = (*pcStack_e8)(pval_00,pcVar9,pAVar11,it,0xffffffff,0,0,auStack_c4);
    if (iVar14 < 1) {
      uVar5 = 0;
      pAVar10 = (ASN1_TEMPLATE *)pcVar9;
      goto LAB_00561684;
    }
LAB_005617a4:
    uVar5 = pval_00->flags;
    pAVar10 = (ASN1_TEMPLATE *)pcVar9;
    goto LAB_00561684;
  case '\x05':
switchD_005619f8_caseD_5:
    puStack_cc = (uchar *)*(ulong *)pcVar9;
    iVar14 = asn1_check_tlen_constprop_1
                       (0,auStack_d4 + 0xc,&cStack_d7,0,0,auStack_d4 + 8,pAVar11,1,auStack_c4);
    if (iVar14 == 0) {
      uVar13 = 0x3a;
      uVar12 = 0xdb;
    }
    else if (cStack_d7 == '\0') {
      if ((pcStack_c8 < (char *)0x1f) &&
         ((*(uint *)(tag2bit + (int)pcStack_c8 * 4) & *(long *)((int)it + 4)) != 0)) {
        iVar14 = asn1_d2i_ex_primitive(pval_00,pcVar9,pAStack_d0,it,pcStack_c8,0,0,auStack_c4);
        if (iVar14 < 1) {
          uVar5 = 0;
          pAVar10 = (ASN1_TEMPLATE *)pcVar9;
          goto LAB_00561684;
        }
        goto LAB_005617a4;
      }
      uVar13 = 0x8c;
      uVar12 = 0xec;
    }
    else {
      uVar13 = 0x8b;
      uVar12 = 0xe4;
    }
    break;
  default:
    goto switchD_005619f8_caseD_7;
  }
LAB_0056163c:
  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x78,uVar13,s_tasn_dec_c_0066a0bc,uVar12);
LAB_00561650:
  ASN1_item_ex_free((ASN1_VALUE **)pval_00,(ASN1_ITEM *)it);
LAB_00561668:
  pcVar9 = s_Type__0066a0d8;
  (*(code *)PTR_ERR_add_error_data_006a813c)(2,s_Type__0066a0d8,*(char **)((int)it + 0x18));
switchD_005619f8_caseD_7:
  uVar5 = 0;
  pAVar10 = (ASN1_TEMPLATE *)pcVar9;
LAB_00561684:
  if (piStack_ac != *(int **)puVar2) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    return *(int *)(pAVar10->tag + *piStack_ac);
  }
  return uVar5;
LAB_00561c54:
  iVar16 = iVar16 + 1;
  ppAVar8 = asn1_get_field_ptr((ASN1_VALUE **)pval_00,tt_00);
  pAVar10 = pAVar10 + 1;
  ASN1_template_free(ppAVar8,tt_00);
  if (*(long *)((int)it + 0xc) <= iVar16) goto LAB_00561a6c;
  goto LAB_00561c90;
LAB_00561a6c:
  pAVar10 = (ASN1_TEMPLATE *)*(ulong *)pcVar9;
LAB_00561a70:
  iVar14 = asn1_enc_save((ASN1_VALUE **)pval_00,(uchar *)pAVar10,(int)puStack_cc - (int)pAVar10,
                         (ASN1_ITEM *)it);
  if (iVar14 != 0) {
joined_r0x00561600:
    if ((pcStack_e8 == (code *)0x0) ||
       (pAVar10 = pval_00, iVar14 = (*pcStack_e8)(5,pval_00,it,0), iVar14 != 0)) {
      *(ulong *)pcVar9 = (ulong)puStack_cc;
      uVar5 = pval_00->flags;
      goto LAB_00561684;
    }
  }
LAB_00561628:
  uVar13 = 100;
  uVar12 = 0x1f7;
  goto LAB_0056163c;
}

