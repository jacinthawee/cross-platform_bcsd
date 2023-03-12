
uint asn1_template_ex_d2i
               (ASN1_ITEM_EXP *param_1,ASN1_ITEM_EXP *param_2,ASN1_ITEM_EXP *param_3,
               ASN1_ITEM_EXP *param_4,char param_5,ASN1_ITEM_EXP *param_6)

{
  byte bVar1;
  char cVar2;
  undefined *puVar3;
  ASN1_TEMPLATE *pAVar4;
  int in_zero;
  uint uVar5;
  ASN1_ITEM_EXP *pval;
  ASN1_ITEM_EXP *pAVar6;
  int iVar7;
  ASN1_VALUE **ppAVar8;
  ASN1_TEMPLATE *tt;
  ASN1_ITEM_EXP *pAVar9;
  char *pcVar10;
  ASN1_ITEM_EXP *pAVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  char *pcVar14;
  char *it;
  ASN1_VALUE *pAVar15;
  int iVar16;
  ASN1_ITEM_EXP *unaff_s1;
  void *pvVar17;
  ASN1_ITEM_EXP *unaff_s3;
  ASN1_ITEM_EXP *unaff_s4;
  ASN1_TEMPLATE *tt_00;
  ASN1_ITEM_EXP *unaff_s7;
  ASN1_ITEM_EXP *unaff_s8;
  code *pcStack_1d0;
  undefined *puStack_1c8;
  char cStack_1bf;
  char cStack_1be;
  char cStack_1bd;
  undefined auStack_1bc [4];
  ASN1_ITEM_EXP *pAStack_1b8;
  ASN1_TEMPLATE *pAStack_1b4;
  uint uStack_1b0;
  undefined auStack_1ac [24];
  int *piStack_194;
  ASN1_ITEM_EXP *pAStack_190;
  undefined *puStack_18c;
  uint uStack_188;
  ASN1_ITEM_EXP *pAStack_184;
  ASN1_ITEM_EXP *pAStack_180;
  ASN1_ITEM_EXP *pAStack_17c;
  ASN1_ITEM_EXP *pAStack_178;
  ASN1_ITEM_EXP *pAStack_174;
  ASN1_ITEM_EXP *pAStack_170;
  code *pcStack_16c;
  ASN1_ITEM_EXP *pAStack_140;
  int iStack_13c;
  ASN1_ITEM_EXP *pAStack_138;
  ASN1_ITEM_EXP *pAStack_134;
  ASN1_ITEM_EXP *pAStack_130;
  undefined uStack_12c;
  char *pcStack_128;
  ASN1_ITEM_EXP *pAStack_124;
  int iStack_120;
  ASN1_ITEM_EXP *pAStack_11c;
  int iStack_118;
  ASN1_ITEM_EXP *pAStack_114;
  ASN1_ITEM_EXP *pAStack_110;
  undefined *puStack_10c;
  void *pvStack_108;
  ASN1_ITEM_EXP *pAStack_104;
  ASN1_ITEM_EXP *pAStack_100;
  ASN1_ITEM_EXP *pAStack_fc;
  ASN1_ITEM_EXP *pAStack_f8;
  undefined4 uStack_f4;
  ASN1_ITEM_EXP *pAStack_f0;
  code *pcStack_ec;
  undefined *puStack_b8;
  undefined4 uStack_ac;
  undefined4 uStack_9c;
  ASN1_ITEM_EXP *pAStack_94;
  ASN1_ITEM_EXP *pAStack_90;
  ASN1_ITEM_EXP *pAStack_8c;
  undefined *puStack_88;
  ASN1_ITEM_EXP *pAStack_84;
  ASN1_ITEM_EXP *pAStack_80;
  ASN1_ITEM_EXP *pAStack_7c;
  ASN1_ITEM_EXP *pAStack_78;
  ASN1_ITEM_EXP *pAStack_74;
  ASN1_ITEM_EXP *pAStack_70;
  code *pcStack_6c;
  ASN1_ITEM_EXP *pAStack_60;
  ASN1_ITEM_EXP *local_40;
  ASN1_VALUE *local_3c;
  ASN1_ITEM_EXP *local_38;
  ASN1_ITEM_EXP *local_34;
  ASN1_ITEM_EXP *local_30;
  ASN1_ITEM_EXP *local_2c;
  
  puStack_88 = PTR___stack_chk_guard_006aabf0;
  pAStack_f8 = (ASN1_ITEM_EXP *)(int)param_5;
  local_2c = *(ASN1_ITEM_EXP **)PTR___stack_chk_guard_006aabf0;
  pAVar9 = param_2;
  pcVar14 = &param_4->itype;
  if (param_1 == (ASN1_ITEM_EXP *)0x0) {
    uVar5 = 0;
    pAVar11 = param_3;
  }
  else {
    unaff_s8 = *(ASN1_ITEM_EXP **)param_4;
    unaff_s1 = *(ASN1_ITEM_EXP **)param_2;
    unaff_s3 = param_4;
    local_40 = unaff_s1;
    if (((uint)unaff_s8 & 0x10) == 0) {
      uVar5 = asn1_template_noexp_d2i();
      pAVar11 = param_3;
    }
    else {
      pAVar15 = (ASN1_VALUE *)param_4->utype;
      unaff_s4 = param_1;
      unaff_s7 = param_3;
      local_30 = unaff_s1;
      if (param_6 == (ASN1_ITEM_EXP *)0x0) {
        pcVar14 = (char *)&local_38;
        pAVar11 = (ASN1_ITEM_EXP *)&local_3c;
        pAVar9 = (ASN1_ITEM_EXP *)&local_34;
        uVar5 = ASN1_get_object((uchar **)&local_30,(long *)pAVar9,(int *)pAVar11,(int *)pcVar14,
                                (long)param_3);
        if ((uVar5 & 0x80) == 0) {
LAB_0056403c:
          pAVar6 = local_30;
          if (-1 < (int)pAVar15) {
            if ((pAVar15 != local_3c) ||
               (unaff_s8 = (ASN1_ITEM_EXP *)((uint)unaff_s8 & 0xc0), unaff_s8 != local_38)) {
              uVar5 = 0xffffffff;
              if (pAStack_f8 != (ASN1_ITEM_EXP *)0x0) goto LAB_005640c0;
              if (param_6 != (ASN1_ITEM_EXP *)0x0) {
                param_6->itype = '\0';
              }
              uVar12 = 0xa8;
              goto LAB_00564070;
            }
            if (param_6 != (ASN1_ITEM_EXP *)0x0) {
              param_6->itype = '\0';
            }
          }
          unaff_s7 = local_34;
          if ((uVar5 & 1) != 0) {
            unaff_s7 = (ASN1_ITEM_EXP *)((int)param_3 - ((int)local_30 - (int)unaff_s1));
          }
          unaff_s1 = (ASN1_ITEM_EXP *)(int)(char)uVar5;
          local_40 = local_30;
          if (((uint)unaff_s1 & 0x20) == 0) {
            pAVar11 = (ASN1_ITEM_EXP *)&DAT_00000078;
          }
          else {
            pAVar9 = (ASN1_ITEM_EXP *)&local_40;
            pAVar11 = unaff_s7;
            pcVar14 = &param_4->itype;
            iVar16 = asn1_template_noexp_d2i(param_1);
            if (iVar16 != 0) {
              pAStack_f8 = (ASN1_ITEM_EXP *)((int)local_40 - (int)pAVar6);
              unaff_s7 = (ASN1_ITEM_EXP *)((int)unaff_s7 - (int)pAStack_f8);
              if (((uint)unaff_s1 & 1) == 0) {
                pAVar6 = local_40;
                if (unaff_s7 != (ASN1_ITEM_EXP *)0x0) {
                  pAVar11 = (ASN1_ITEM_EXP *)&DAT_00000077;
                  goto LAB_005642ac;
                }
              }
              else {
                unaff_s7 = (ASN1_ITEM_EXP *)(uint)((int)unaff_s7 < 2);
                if (((unaff_s7 != (ASN1_ITEM_EXP *)0x0) || (local_40->itype != '\0')) ||
                   (pAVar6 = (ASN1_ITEM_EXP *)&local_40->field_0x2, local_40->field_0x1 != '\0')) {
                  pAVar11 = (ASN1_ITEM_EXP *)&DAT_00000089;
LAB_005642ac:
                  pcVar14 = s_tasn_dec_c_0066ab0c;
                  (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x84);
                  pAVar9 = param_4;
                  ASN1_template_free((ASN1_VALUE **)param_1,(ASN1_TEMPLATE *)param_4);
                  uVar5 = 0;
                  goto LAB_005640c0;
                }
              }
              *(ASN1_ITEM_EXP **)param_2 = pAVar6;
              uVar5 = 1;
              goto LAB_005640c0;
            }
            pAVar11 = (ASN1_ITEM_EXP *)&DAT_0000003a;
          }
          pcVar14 = s_tasn_dec_c_0066ab0c;
          pAVar9 = (ASN1_ITEM_EXP *)&DAT_00000084;
          (*(code *)PTR_ERR_put_error_006a9030)(0xd);
          uVar5 = 0;
          pAStack_f8 = pAVar6;
          goto LAB_005640c0;
        }
        uVar12 = 0x66;
LAB_00564070:
        (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x68,uVar12,s_tasn_dec_c_0066ab0c);
      }
      else {
        if (param_6->itype == '\0') {
          pcVar14 = (char *)&local_38;
          uVar5 = ASN1_get_object((uchar **)&local_30,(long *)&local_34,(int *)&local_3c,
                                  (int *)pcVar14,(long)param_3);
          pAVar9 = (ASN1_ITEM_EXP *)(uVar5 & 0x81);
          param_6->funcs = local_38;
          param_6->utype = uVar5;
          param_6->templates = (ASN1_TEMPLATE *)local_34;
          param_6->tcount = (long)local_3c;
          pAVar11 = (ASN1_ITEM_EXP *)0x1;
          param_6->size = (int)local_30 - (int)unaff_s1;
          param_6->itype = '\x01';
          if ((pAVar9 != (ASN1_ITEM_EXP *)0x0) ||
             ((int)((int)local_34 + ((int)local_30 - (int)unaff_s1)) <= (int)param_3))
          goto LAB_00564034;
          uVar12 = 0x9b;
        }
        else {
          pAVar11 = (ASN1_ITEM_EXP *)param_6->templates;
          pAVar9 = (ASN1_ITEM_EXP *)param_6->funcs;
          local_3c = (ASN1_VALUE *)param_6->tcount;
          local_30 = (ASN1_ITEM_EXP *)(&unaff_s1->itype + param_6->size);
          uVar5 = param_6->utype;
          local_38 = pAVar9;
          local_34 = pAVar11;
LAB_00564034:
          if ((uVar5 & 0x80) == 0) goto LAB_0056403c;
          uVar12 = 0x66;
        }
        (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x68,uVar12,s_tasn_dec_c_0066ab0c);
        param_6->itype = '\0';
      }
      unaff_s1 = (ASN1_ITEM_EXP *)0x670000;
      pcVar14 = s_tasn_dec_c_0066ab0c;
      pAVar11 = (ASN1_ITEM_EXP *)&DAT_0000003a;
      pAVar9 = (ASN1_ITEM_EXP *)&DAT_00000084;
      (*(code *)PTR_ERR_put_error_006a9030)(0xd);
      uVar5 = 0;
    }
  }
LAB_005640c0:
  if (local_2c == *(ASN1_ITEM_EXP **)puStack_88) {
    return uVar5;
  }
  pcStack_6c = ASN1_item_ex_d2i;
  pAVar6 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_10c = PTR___stack_chk_guard_006aabf0;
  pAStack_8c = unaff_s1;
  pAStack_74 = unaff_s7;
  pAStack_70 = unaff_s8;
  pAStack_78 = pAStack_f8;
  pAStack_7c = param_2;
  pAStack_80 = unaff_s4;
  pAStack_84 = unaff_s3;
  pAStack_90 = param_6;
  puStack_b8 = &_gp;
  pAStack_60 = pAVar11;
  uStack_9c = 0;
  pval = *(ASN1_ITEM_EXP **)PTR___stack_chk_guard_006aabf0;
  pvStack_108 = *(void **)((int)pcVar14 + 0x10);
  pAStack_94 = pval;
  if (pAVar6 != (ASN1_ITEM_EXP *)0x0) {
    if (pvStack_108 == (void *)0x0) {
      bVar1 = *pcVar14;
      uStack_ac = 0;
    }
    else {
      uStack_ac = *(undefined4 *)((int)pvStack_108 + 0x10);
      bVar1 = *pcVar14;
    }
    param_6 = pAVar6;
    unaff_s4 = pAVar9;
    unaff_s8 = (ASN1_ITEM_EXP *)pcVar14;
    if (bVar1 < 7) {
                    /* WARNING: Could not recover jumptable at 0x00564400. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar5 = (*(code *)(&PTR_LAB_0066ab68)[bVar1])();
      return uVar5;
    }
  }
  if (pval == *(ASN1_ITEM_EXP **)PTR___stack_chk_guard_006aabf0) {
    return 0;
  }
  pcStack_ec = ASN1_template_d2i;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_18c = PTR___stack_chk_guard_006aabf0;
  pAStack_f0 = unaff_s8;
  uStack_f4 = 0xffffffe0;
  pAStack_fc = param_2;
  pAStack_100 = unaff_s4;
  pAStack_104 = unaff_s3;
  pAStack_110 = param_6;
  uStack_12c = 0;
  pAStack_114 = *(ASN1_ITEM_EXP **)PTR___stack_chk_guard_006aabf0;
  uStack_188 = 0;
  pcVar10 = &pAVar9->itype;
  it = pcVar14;
  pAStack_178 = pAStack_f8;
  pAStack_174 = (ASN1_ITEM_EXP *)0xffffffe0;
  if (pval != (ASN1_ITEM_EXP *)0x0) {
    param_2 = *(ASN1_ITEM_EXP **)pcVar14;
    param_6 = *(ASN1_ITEM_EXP **)pAVar9;
    pAStack_140 = param_6;
    unaff_s3 = (ASN1_ITEM_EXP *)pcVar14;
    pAStack_178 = pAVar9;
    if (((uint)param_2 & 0x10) == 0) {
      uStack_188 = asn1_template_noexp_d2i();
    }
    else {
      iVar16 = *(long *)((int)pcVar14 + 4);
      pAStack_130 = param_6;
      pcStack_128 = (char *)ASN1_get_object((uchar **)&pAStack_130,(long *)&pAStack_134,&iStack_13c,
                                            (int *)&pAStack_138,(long)pAVar11);
      pAVar6 = pAStack_130;
      iStack_118 = (int)pAStack_130 - (int)param_6;
      pAStack_124 = pAStack_134;
      pAStack_11c = pAStack_138;
      iStack_120 = iStack_13c;
      uStack_12c = 1;
      unaff_s4 = pval;
      pAStack_174 = pAVar11;
      unaff_s8 = pAStack_134;
      if ((((uint)pcStack_128 & 0x81) == 0) && ((int)pAVar11 < (int)((int)pAStack_134 + iStack_118))
         ) {
        uVar12 = 0x9b;
LAB_00564fdc:
        (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x68,uVar12,s_tasn_dec_c_0066ab0c);
        uStack_12c = 0;
      }
      else {
        uStack_188 = (uint)pcStack_128 & 0x80;
        if (uStack_188 != 0) {
          uVar12 = 0x66;
          goto LAB_00564fdc;
        }
        if (iVar16 < 0) {
LAB_00564f84:
          param_2 = (ASN1_ITEM_EXP *)(int)(char)pcStack_128;
          pAStack_140 = pAStack_130;
          param_6 = (ASN1_ITEM_EXP *)((int)pAVar11 - iStack_118);
          if (((uint)pcStack_128 & 1) != 0) {
            unaff_s8 = param_6;
          }
          if (((uint)param_2 & 0x20) == 0) {
            pAVar11 = (ASN1_ITEM_EXP *)&DAT_00000078;
          }
          else {
            pcVar10 = (char *)&pAStack_140;
            pAVar11 = unaff_s8;
            iVar16 = asn1_template_noexp_d2i(pval);
            if (iVar16 != 0) {
              param_2 = (ASN1_ITEM_EXP *)((uint)param_2 & 1);
              unaff_s8 = (ASN1_ITEM_EXP *)((int)unaff_s8 - ((int)pAStack_140 - (int)pAVar6));
              if (param_2 == (ASN1_ITEM_EXP *)0x0) {
                pAVar6 = pAStack_140;
                if (unaff_s8 != (ASN1_ITEM_EXP *)0x0) {
                  pAVar11 = (ASN1_ITEM_EXP *)&DAT_00000077;
                  goto LAB_0056508c;
                }
              }
              else {
                unaff_s8 = (ASN1_ITEM_EXP *)(uint)((int)unaff_s8 < 2);
                if (((unaff_s8 != (ASN1_ITEM_EXP *)0x0) || (pAStack_140->itype != '\0')) ||
                   (pAStack_140->field_0x1 != '\0')) {
                  pAVar11 = (ASN1_ITEM_EXP *)&DAT_00000089;
LAB_0056508c:
                  it = s_tasn_dec_c_0066ab0c;
                  (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x84);
                  pcVar10 = pcVar14;
                  ASN1_template_free((ASN1_VALUE **)pval,(ASN1_TEMPLATE *)pcVar14);
                  goto LAB_00564e40;
                }
                pAVar6 = (ASN1_ITEM_EXP *)&pAStack_140->field_0x2;
              }
              *(ASN1_ITEM_EXP **)pAVar9 = pAVar6;
              uStack_188 = 1;
              goto LAB_00564e40;
            }
            pAVar11 = (ASN1_ITEM_EXP *)&DAT_0000003a;
          }
          it = s_tasn_dec_c_0066ab0c;
          pcVar10 = &DAT_00000084;
          (*(code *)PTR_ERR_put_error_006a9030)(0xd);
          goto LAB_00564e40;
        }
        if ((iVar16 == iStack_13c) &&
           (param_2 = (ASN1_ITEM_EXP *)((uint)param_2 & 0xc0), param_2 == pAStack_138)) {
          uStack_12c = 0;
          goto LAB_00564f84;
        }
        uStack_12c = 0;
        (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x68,0xa8,s_tasn_dec_c_0066ab0c);
      }
      param_6 = (ASN1_ITEM_EXP *)0x670000;
      it = s_tasn_dec_c_0066ab0c;
      pAVar11 = (ASN1_ITEM_EXP *)&DAT_0000003a;
      pcVar10 = &DAT_00000084;
      uStack_188 = 0;
      (*(code *)PTR_ERR_put_error_006a9030)(0xd);
    }
  }
LAB_00564e40:
  if (pAStack_114 == *(ASN1_ITEM_EXP **)puStack_18c) {
    return uStack_188;
  }
  pcStack_16c = ASN1_item_d2i;
  pAVar9 = pAStack_114;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar3 = PTR___stack_chk_guard_006aabf0;
  pvVar17 = *(void **)((int)it + 0x10);
  pAStack_190 = param_6;
  pAStack_170 = unaff_s8;
  pAStack_180 = unaff_s4;
  pAStack_184 = unaff_s3;
  pAStack_17c = param_2;
  auStack_1bc = (undefined  [4])0x0;
  auStack_1ac[0] = 0;
  pAStack_1b8 = pAVar11;
  pAStack_1b4 = (ASN1_TEMPLATE *)0x0;
  pAVar6 = (ASN1_ITEM_EXP *)auStack_1bc;
  if (pAVar9 != (ASN1_ITEM_EXP *)0x0) {
    pAVar6 = pAVar9;
  }
  piStack_194 = *(int **)PTR___stack_chk_guard_006aabf0;
  if (pvVar17 == (void *)0x0) {
    switch(*it) {
    case '\0':
      goto switchD_00565630_caseD_0;
    case '\x01':
    case '\x06':
      pcStack_1d0 = (code *)0x0;
      goto switchD_005651a0_caseD_1;
    case '\x02':
      pcStack_1d0 = (code *)0x0;
LAB_005651ac:
      if ((*(int *)pAVar6 == 0) &&
         (iVar16 = ASN1_item_ex_new((ASN1_VALUE **)pAVar6,(ASN1_ITEM *)it), iVar16 == 0)) {
        uVar13 = 0x3a;
        uVar12 = 0x13e;
        goto LAB_00565288;
      }
      pAStack_1b4 = *(ASN1_TEMPLATE **)pcVar10;
      pAVar9 = (ASN1_ITEM_EXP *)0x0;
      pAVar11 = *(ASN1_ITEM_EXP **)((int)it + 0xc);
      tt = *(ASN1_TEMPLATE **)((int)it + 8);
      if ((int)pAVar11 < 1) {
LAB_00565228:
        if (pAVar9 == pAVar11) {
LAB_0056566c:
          uVar13 = 0x8f;
          uVar12 = 0x162;
          goto LAB_00565288;
        }
      }
      else {
        do {
          ppAVar8 = asn1_get_field_ptr((ASN1_VALUE **)pAVar6,tt);
          iVar16 = asn1_template_ex_d2i(ppAVar8,auStack_1bc + 8,pAStack_1b8,tt,1,auStack_1ac);
          if (iVar16 != -1) {
            if (0 < iVar16) {
              pAVar11 = *(ASN1_ITEM_EXP **)((int)it + 0xc);
              goto LAB_00565228;
            }
            (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x78,0x3a,s_tasn_dec_c_0066ab0c,0x153);
            ASN1_item_ex_free((ASN1_VALUE **)pAVar6,(ASN1_ITEM *)it);
            if (tt != (ASN1_TEMPLATE *)0x0) goto LAB_005657fc;
            goto LAB_005652b4;
          }
          pAVar9 = (ASN1_ITEM_EXP *)&pAVar9->field_0x1;
          tt = tt + 1;
        } while ((int)pAVar9 < (int)*(undefined **)((int)it + 0xc));
        if (pAVar9 == (ASN1_ITEM_EXP *)*(undefined **)((int)it + 0xc)) goto LAB_0056566c;
      }
      asn1_set_choice_selector((ASN1_VALUE **)pAVar6,(int)pAVar9,(ASN1_ITEM *)it);
      *(ASN1_TEMPLATE **)pcVar10 = pAStack_1b4;
      if (pcStack_1d0 == (code *)0x0) goto LAB_00565328;
      goto LAB_00565258;
    case '\x03':
      goto switchD_00565630_caseD_3;
    case '\x04':
      pcStack_1d0 = *(code **)(in_zero + 0x10);
      goto LAB_005655ac;
    case '\x05':
      goto switchD_00565630_caseD_5;
    }
    goto switchD_00565630_caseD_7;
  }
  pcStack_1d0 = *(code **)((int)pvVar17 + 0x10);
  switch(*it) {
  case '\0':
switchD_00565630_caseD_0:
    if (*(ASN1_TEMPLATE **)((int)it + 8) == (ASN1_TEMPLATE *)0x0) {
      iVar16 = asn1_d2i_ex_primitive(pAVar6,pcVar10,pAVar11,it,0xffffffff,0,0,auStack_1ac);
      if (iVar16 < 1) {
        uVar5 = 0;
        pAVar9 = (ASN1_ITEM_EXP *)pcVar10;
        goto LAB_005652d0;
      }
    }
    else {
      iVar16 = asn1_template_ex_d2i
                         (pAVar6,pcVar10,pAVar11,*(ASN1_TEMPLATE **)((int)it + 8),0,auStack_1ac);
      if (iVar16 < 1) goto switchD_00565630_caseD_7;
    }
    goto LAB_005653f0;
  case '\x01':
  case '\x06':
switchD_005651a0_caseD_1:
    pAStack_1b4 = *(ASN1_TEMPLATE **)pcVar10;
    pAVar9 = (ASN1_ITEM_EXP *)0x0;
    iVar16 = asn1_check_tlen(auStack_1bc + 4,0,0,&cStack_1be,&cStack_1bd,auStack_1bc + 8,pAVar11,
                             0x10,0,0,auStack_1ac);
    if (iVar16 == 0) {
      uVar13 = 0x3a;
      uVar12 = 0x17d;
    }
    else {
      uVar5 = 0;
      if (iVar16 == -1) goto LAB_005652d0;
      cVar2 = cStack_1be;
      if ((pvVar17 != (void *)0x0) && ((*(uint *)((int)pvVar17 + 4) & 4) != 0)) {
        pAStack_1b8 = (ASN1_ITEM_EXP *)
                      ((int)pAVar11 - ((int)pAStack_1b4 - (int)*(ASN1_VALUE **)pcVar10));
        cVar2 = '\x01';
      }
      if (cStack_1bd == '\0') {
        uVar13 = 0x95;
        uVar12 = 0x18c;
      }
      else if ((*(int *)pAVar6 == 0) &&
              (iVar16 = ASN1_item_ex_new((ASN1_VALUE **)pAVar6,(ASN1_ITEM *)it), iVar16 == 0)) {
        uVar13 = 0x3a;
        uVar12 = 0x193;
      }
      else {
        puStack_1c8 = auStack_1ac;
        if ((pcStack_1d0 != (code *)0x0) && (iVar16 = (*pcStack_1d0)(4,pAVar6,it,0), iVar16 == 0))
        goto LAB_00565278;
        iVar16 = 0;
        tt_00 = *(ASN1_TEMPLATE **)((int)it + 8);
        if (0 < *(long *)((int)it + 0xc)) {
          do {
            tt = asn1_do_adb((ASN1_VALUE **)pAVar6,tt_00,1);
            if (tt == (ASN1_TEMPLATE *)0x0) goto LAB_0056529c;
            ppAVar8 = asn1_get_field_ptr((ASN1_VALUE **)pAVar6,tt);
            pAVar4 = pAStack_1b4;
            if (pAStack_1b8 == (ASN1_ITEM_EXP *)0x0) {
              if (cStack_1be == '\0') goto LAB_00565740;
              goto LAB_00565908;
            }
            if (((1 < (int)pAStack_1b8) && (*(char *)&pAStack_1b4->flags == '\0')) &&
               (*(char *)((int)&pAStack_1b4->flags + 1) == '\0')) {
              pAStack_1b4 = (ASN1_TEMPLATE *)((int)&pAStack_1b4->flags + 2);
              if (cStack_1be == '\0') {
                uVar13 = 0x9f;
                uVar12 = 0x1ac;
                goto LAB_00565288;
              }
              cStack_1be = '\0';
              pAStack_1b8 = (ASN1_ITEM_EXP *)((int)&pAStack_1b8[-1].sname + 2);
              goto LAB_0056572c;
            }
            uVar5 = 0;
            if (iVar16 != *(long *)((int)it + 0xc) + -1) {
              uVar5 = tt->flags & 1;
            }
            iVar7 = asn1_template_ex_d2i(ppAVar8,auStack_1bc + 8,pAStack_1b8,tt,uVar5,puStack_1c8);
            if (iVar7 == 0) goto LAB_005657e8;
            if (iVar7 == -1) {
              ASN1_template_free(ppAVar8,tt);
            }
            else {
              pAStack_1b8 = (ASN1_ITEM_EXP *)((int)pAStack_1b8 - ((int)pAStack_1b4 - (int)pAVar4));
            }
            iVar16 = iVar16 + 1;
            tt_00 = tt_00 + 1;
          } while (iVar16 < *(long *)((int)it + 0xc));
        }
        if (cStack_1be != '\0') {
          if ((((int)pAStack_1b8 < 2) || (*(char *)&pAStack_1b4->flags != '\0')) ||
             (*(char *)((int)&pAStack_1b4->flags + 1) != '\0')) {
LAB_00565908:
            uVar13 = 0x89;
            uVar12 = 0x1d6;
            break;
          }
          pAStack_1b4 = (ASN1_TEMPLATE *)((int)&pAStack_1b4->flags + 2);
        }
LAB_0056572c:
        if ((cVar2 != '\0') || (pAStack_1b8 == (ASN1_ITEM_EXP *)0x0)) {
LAB_00565740:
          if (iVar16 < *(long *)((int)it + 0xc)) {
LAB_00565794:
            tt = asn1_do_adb((ASN1_VALUE **)pAVar6,tt_00,1);
            if (tt != (ASN1_TEMPLATE *)0x0) {
              if ((tt->flags & 1) != 0) goto LAB_00565758;
              (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x78,0x79,s_tasn_dec_c_0066ab0c,0x1f5);
LAB_005657e8:
              ASN1_item_ex_free((ASN1_VALUE **)pAVar6,(ASN1_ITEM *)it);
LAB_005657fc:
              pcVar10 = &DAT_0066ab20;
              (*(code *)PTR_ERR_add_error_data_006a9264)
                        (4,&DAT_0066ab20,tt->field_name,", Type=",*(char **)((int)it + 0x18));
              goto switchD_00565630_caseD_7;
            }
            goto LAB_0056529c;
          }
          pAVar9 = *(ASN1_ITEM_EXP **)pcVar10;
          goto LAB_00565954;
        }
        uVar13 = 0x94;
        uVar12 = 0x1dd;
      }
    }
    break;
  case '\x02':
    if ((pcStack_1d0 == (code *)0x0) || (iVar16 = (*pcStack_1d0)(4,pAVar6,it,0), iVar16 != 0))
    goto LAB_005651ac;
    goto LAB_00565278;
  case '\x03':
switchD_00565630_caseD_3:
    iVar16 = (**(code **)((int)pvVar17 + 8))(pAVar6,pcVar10,pAVar11);
    pAVar9 = (ASN1_ITEM_EXP *)pcVar10;
    if (iVar16 != 0) goto LAB_00565328;
    uVar13 = 0x3a;
    uVar12 = 0x132;
    break;
  case '\x04':
LAB_005655ac:
    iVar16 = (*pcStack_1d0)(pAVar6,pcVar10,pAVar11,it,0xffffffff,0,0,auStack_1ac);
    if (iVar16 < 1) {
      uVar5 = 0;
      pAVar9 = (ASN1_ITEM_EXP *)pcVar10;
      goto LAB_005652d0;
    }
LAB_005653f0:
    uVar5 = *(uint *)pAVar6;
    pAVar9 = (ASN1_ITEM_EXP *)pcVar10;
    goto LAB_005652d0;
  case '\x05':
switchD_00565630_caseD_5:
    pAStack_1b4 = *(ASN1_TEMPLATE **)pcVar10;
    iVar16 = asn1_check_tlen_constprop_1
                       (0,auStack_1bc + 0xc,&cStack_1bf,0,0,auStack_1bc + 8,pAVar11,1,auStack_1ac);
    if (iVar16 == 0) {
      uVar13 = 0x3a;
      uVar12 = 0xd2;
    }
    else if (cStack_1bf == '\0') {
      if ((uStack_1b0 < 0x1f) &&
         ((*(uint *)(tag2bit + uStack_1b0 * 4) & *(long *)((int)it + 4)) != 0)) {
        iVar16 = asn1_d2i_ex_primitive(pAVar6,pcVar10,pAStack_1b8,it,uStack_1b0,0,0,auStack_1ac);
        if (iVar16 < 1) {
          uVar5 = 0;
          pAVar9 = (ASN1_ITEM_EXP *)pcVar10;
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
  (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x78,uVar13,s_tasn_dec_c_0066ab0c,uVar12);
LAB_0056529c:
  ASN1_item_ex_free((ASN1_VALUE **)pAVar6,(ASN1_ITEM *)it);
LAB_005652b4:
  pcVar10 = s_Type__0066ab28;
  (*(code *)PTR_ERR_add_error_data_006a9264)(2,s_Type__0066ab28,*(char **)((int)it + 0x18));
switchD_00565630_caseD_7:
  uVar5 = 0;
  pAVar9 = (ASN1_ITEM_EXP *)pcVar10;
LAB_005652d0:
  if (piStack_194 != *(int **)puVar3) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    return *(uint *)(pAVar9->utype + *piStack_194);
  }
  return uVar5;
LAB_00565758:
  iVar16 = iVar16 + 1;
  ppAVar8 = asn1_get_field_ptr((ASN1_VALUE **)pAVar6,tt);
  tt_00 = tt_00 + 1;
  ASN1_template_free(ppAVar8,tt);
  if (*(long *)((int)it + 0xc) <= iVar16) goto LAB_00565950;
  goto LAB_00565794;
LAB_00565950:
  pAVar9 = *(ASN1_ITEM_EXP **)pcVar10;
LAB_00565954:
  iVar16 = asn1_enc_save((ASN1_VALUE **)pAVar6,(uchar *)pAVar9,(int)pAStack_1b4 - (int)pAVar9,
                         (ASN1_ITEM *)it);
  if (iVar16 != 0) {
    *(ASN1_TEMPLATE **)pcVar10 = pAStack_1b4;
    if (pcStack_1d0 == (code *)0x0) {
      uVar5 = *(uint *)pAVar6;
      goto LAB_005652d0;
    }
LAB_00565258:
    pAVar9 = pAVar6;
    iVar16 = (*pcStack_1d0)(5,pAVar6,it,0);
    if (iVar16 != 0) {
LAB_00565328:
      uVar5 = *(uint *)pAVar6;
      goto LAB_005652d0;
    }
  }
LAB_00565278:
  uVar13 = 100;
  uVar12 = 0x205;
  goto LAB_00565288;
}

