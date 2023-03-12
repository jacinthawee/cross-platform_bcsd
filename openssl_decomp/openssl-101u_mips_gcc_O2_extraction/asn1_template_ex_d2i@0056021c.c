
ASN1_TEMPLATE *
asn1_template_ex_d2i
          (ASN1_VALUE **param_1,ASN1_ITEM *param_2,ASN1_ITEM *param_3,ASN1_ITEM *param_4,
          char param_5,char *param_6)

{
  byte bVar1;
  char cVar2;
  undefined *puVar3;
  ASN1_TEMPLATE *pAVar4;
  int in_zero;
  uint uVar5;
  ASN1_TEMPLATE *pAVar6;
  ASN1_ITEM *pAVar7;
  ASN1_VALUE **ppAVar8;
  ASN1_ITEM *pAVar9;
  char *pcVar10;
  ASN1_ITEM *pAVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  char *pcVar14;
  char *it;
  int iVar15;
  ASN1_ITEM *unaff_s1;
  void *pvVar16;
  ASN1_TEMPLATE *tt;
  ASN1_ITEM *unaff_s3;
  int iVar17;
  ASN1_VALUE **unaff_s4;
  ASN1_ITEM *unaff_s7;
  ASN1_ITEM *unaff_s8;
  code *pcStack_1d8;
  undefined *puStack_1d0;
  char cStack_1c7;
  char cStack_1c6;
  char cStack_1c5;
  undefined auStack_1c4 [4];
  ASN1_ITEM *pAStack_1c0;
  ASN1_TEMPLATE *pAStack_1bc;
  uint uStack_1b8;
  undefined auStack_1b4 [24];
  int *piStack_19c;
  ASN1_ITEM *pAStack_198;
  undefined *puStack_194;
  ASN1_TEMPLATE *pAStack_190;
  ASN1_ITEM *pAStack_18c;
  ASN1_VALUE **ppAStack_188;
  ASN1_ITEM *pAStack_184;
  ASN1_ITEM *pAStack_180;
  ASN1_ITEM *pAStack_17c;
  ASN1_ITEM *pAStack_178;
  code *pcStack_174;
  ASN1_ITEM *pAStack_148;
  int iStack_144;
  ASN1_ITEM *pAStack_140;
  ASN1_ITEM *pAStack_13c;
  ASN1_ITEM *pAStack_138;
  undefined uStack_134;
  char *pcStack_130;
  ASN1_ITEM *pAStack_12c;
  int iStack_128;
  ASN1_ITEM *pAStack_124;
  int iStack_120;
  ASN1_ITEM *pAStack_11c;
  ASN1_ITEM *pAStack_118;
  ASN1_ITEM_EXP *pAStack_114;
  undefined *puStack_110;
  ASN1_ITEM *pAStack_10c;
  ASN1_VALUE **ppAStack_108;
  ASN1_ITEM *pAStack_104;
  ASN1_ITEM *pAStack_100;
  ASN1_ITEM *pAStack_fc;
  undefined4 uStack_f8;
  code *pcStack_f4;
  undefined *puStack_c0;
  uint uStack_b0;
  void *pvStack_ac;
  undefined4 uStack_9c;
  ASN1_VALUE **ppAStack_94;
  char *pcStack_90;
  ASN1_ITEM *pAStack_8c;
  undefined *puStack_88;
  ASN1_ITEM *pAStack_84;
  ASN1_VALUE **ppAStack_80;
  ASN1_ITEM *pAStack_7c;
  ASN1_ITEM *pAStack_78;
  ASN1_ITEM *pAStack_74;
  ASN1_ITEM *pAStack_70;
  code *pcStack_6c;
  ASN1_ITEM *pAStack_60;
  char *local_54;
  ASN1_ITEM *local_40;
  int local_3c;
  ASN1_ITEM *local_38;
  ASN1_ITEM *local_34;
  ASN1_ITEM *local_30;
  ASN1_ITEM *local_2c;
  
  puStack_88 = PTR___stack_chk_guard_006a9ae8;
  pAStack_100 = (ASN1_ITEM *)(int)param_5;
  local_2c = *(ASN1_ITEM **)PTR___stack_chk_guard_006a9ae8;
  pAVar9 = param_2;
  pcVar14 = &param_4->itype;
  if (param_1 == (ASN1_VALUE **)0x0) {
    pAVar6 = (ASN1_TEMPLATE *)0x0;
    pAVar11 = param_3;
  }
  else {
    unaff_s8 = *(ASN1_ITEM **)param_4;
    unaff_s1 = *(ASN1_ITEM **)param_2;
    unaff_s3 = param_4;
    local_40 = unaff_s1;
    if (((uint)unaff_s8 & 0x10) == 0) {
      local_54 = param_6;
      pAVar6 = (ASN1_TEMPLATE *)asn1_template_noexp_d2i();
      pAVar11 = param_3;
    }
    else {
      iVar15 = param_4->utype;
      unaff_s4 = param_1;
      unaff_s7 = param_3;
      local_30 = unaff_s1;
      if (param_6 == (char *)0x0) {
        pcVar14 = (char *)&local_38;
        pAVar11 = (ASN1_ITEM *)&local_3c;
        pAVar9 = (ASN1_ITEM *)&local_34;
        uVar5 = ASN1_get_object((uchar **)&local_30,(long *)pAVar9,(int *)pAVar11,(int *)pcVar14,
                                (long)param_3);
        if ((uVar5 & 0x80) == 0) {
LAB_005602dc:
          pAVar7 = local_30;
          if (-1 < iVar15) {
            if ((iVar15 != local_3c) ||
               (unaff_s8 = (ASN1_ITEM *)((uint)unaff_s8 & 0xc0), unaff_s8 != local_38)) {
              pAVar6 = (ASN1_TEMPLATE *)0xffffffff;
              if (pAStack_100 != (ASN1_ITEM *)0x0) goto LAB_00560360;
              if (param_6 != (char *)0x0) {
                *param_6 = '\0';
              }
              uVar12 = 0xa8;
              goto LAB_00560310;
            }
            if (param_6 != (char *)0x0) {
              *param_6 = '\0';
            }
          }
          unaff_s7 = local_34;
          if ((uVar5 & 1) != 0) {
            unaff_s7 = (ASN1_ITEM *)((int)param_3 - ((int)local_30 - (int)unaff_s1));
          }
          unaff_s1 = (ASN1_ITEM *)(int)(char)uVar5;
          local_40 = local_30;
          if (((uint)unaff_s1 & 0x20) == 0) {
            pAVar11 = (ASN1_ITEM *)&DAT_00000078;
          }
          else {
            pAVar9 = (ASN1_ITEM *)&local_40;
            local_54 = param_6;
            pAVar11 = unaff_s7;
            pcVar14 = &param_4->itype;
            iVar15 = asn1_template_noexp_d2i(param_1);
            if (iVar15 != 0) {
              pAStack_100 = (ASN1_ITEM *)((int)local_40 - (int)pAVar7);
              unaff_s7 = (ASN1_ITEM *)((int)unaff_s7 - (int)pAStack_100);
              if (((uint)unaff_s1 & 1) == 0) {
                pAVar7 = local_40;
                if (unaff_s7 != (ASN1_ITEM *)0x0) {
                  pAVar11 = (ASN1_ITEM *)&DAT_00000077;
                  goto LAB_0056054c;
                }
              }
              else {
                unaff_s7 = (ASN1_ITEM *)(uint)((int)unaff_s7 < 2);
                if (((unaff_s7 != (ASN1_ITEM *)0x0) || (local_40->itype != '\0')) ||
                   (pAVar7 = (ASN1_ITEM *)&local_40->field_0x2, local_40->field_0x1 != '\0')) {
                  pAVar11 = (ASN1_ITEM *)&DAT_00000089;
LAB_0056054c:
                  pcVar14 = s_tasn_dec_c_0066a0bc;
                  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x84);
                  pAVar9 = param_4;
                  ASN1_template_free(param_1,(ASN1_TEMPLATE *)param_4);
                  pAVar6 = (ASN1_TEMPLATE *)0x0;
                  goto LAB_00560360;
                }
              }
              *(ASN1_ITEM **)param_2 = pAVar7;
              pAVar6 = (ASN1_TEMPLATE *)0x1;
              goto LAB_00560360;
            }
            pAVar11 = (ASN1_ITEM *)&DAT_0000003a;
          }
          pcVar14 = s_tasn_dec_c_0066a0bc;
          pAVar9 = (ASN1_ITEM *)&DAT_00000084;
          (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
          pAVar6 = (ASN1_TEMPLATE *)0x0;
          pAStack_100 = pAVar7;
          goto LAB_00560360;
        }
        uVar12 = 0x66;
LAB_00560310:
        (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x68,uVar12,s_tasn_dec_c_0066a0bc);
      }
      else {
        if (*param_6 == '\0') {
          pcVar14 = (char *)&local_38;
          uVar5 = ASN1_get_object((uchar **)&local_30,(long *)&local_34,&local_3c,(int *)pcVar14,
                                  (long)param_3);
          pAVar9 = (ASN1_ITEM *)(uVar5 & 0x81);
          *(ASN1_ITEM **)(param_6 + 0x10) = local_38;
          *(uint *)(param_6 + 4) = uVar5;
          *(ASN1_ITEM **)(param_6 + 8) = local_34;
          *(int *)(param_6 + 0xc) = local_3c;
          pAVar11 = (ASN1_ITEM *)0x1;
          *(int *)(param_6 + 0x14) = (int)local_30 - (int)unaff_s1;
          *param_6 = '\x01';
          if ((pAVar9 != (ASN1_ITEM *)0x0) ||
             ((int)((int)local_34 + ((int)local_30 - (int)unaff_s1)) <= (int)param_3))
          goto LAB_005602d4;
          uVar12 = 0x9b;
        }
        else {
          pAVar11 = *(ASN1_ITEM **)(param_6 + 8);
          pAVar9 = *(ASN1_ITEM **)(param_6 + 0x10);
          local_3c = *(int *)(param_6 + 0xc);
          local_30 = (ASN1_ITEM *)((int)&unaff_s1->itype + *(int *)(param_6 + 0x14));
          uVar5 = *(uint *)(param_6 + 4);
          local_38 = pAVar9;
          local_34 = pAVar11;
LAB_005602d4:
          if ((uVar5 & 0x80) == 0) goto LAB_005602dc;
          uVar12 = 0x66;
        }
        (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x68,uVar12,s_tasn_dec_c_0066a0bc);
        *param_6 = '\0';
      }
      unaff_s1 = (ASN1_ITEM *)0x670000;
      pcVar14 = s_tasn_dec_c_0066a0bc;
      pAVar11 = (ASN1_ITEM *)&DAT_0000003a;
      pAVar9 = (ASN1_ITEM *)&DAT_00000084;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
      pAVar6 = (ASN1_TEMPLATE *)0x0;
    }
  }
LAB_00560360:
  if (local_2c == *(ASN1_ITEM **)puStack_88) {
    return pAVar6;
  }
  pcStack_6c = ASN1_item_ex_d2i;
  pAStack_198 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_110 = PTR___stack_chk_guard_006a9ae8;
  pcStack_90 = param_6;
  pAStack_70 = unaff_s8;
  pAStack_8c = unaff_s1;
  pAStack_74 = unaff_s7;
  pAStack_78 = pAStack_100;
  pAStack_7c = param_2;
  ppAStack_80 = unaff_s4;
  pAStack_84 = unaff_s3;
  puStack_c0 = &_gp;
  uStack_b0 = (uint)local_54 & 0x400;
  pAStack_60 = pAVar11;
  uStack_9c = 0;
  ppAVar8 = *(ASN1_VALUE ***)PTR___stack_chk_guard_006a9ae8;
  pAStack_114 = *(ASN1_ITEM_EXP **)((int)pcVar14 + 0x10);
  ppAStack_94 = ppAVar8;
  if (pAStack_198 != (ASN1_ITEM *)0x0) {
    if (pAStack_114 == (ASN1_ITEM_EXP *)0x0) {
      bVar1 = *(byte *)(ulong *)pcVar14;
      pvStack_ac = (void *)0x0;
    }
    else {
      pvStack_ac = pAStack_114->funcs;
      bVar1 = *(byte *)(ulong *)pcVar14;
    }
    param_2 = pAVar9;
    unaff_s7 = (ASN1_ITEM *)pcVar14;
    if (bVar1 < 7) {
                    /* WARNING: Could not recover jumptable at 0x005606b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      pAVar6 = (ASN1_TEMPLATE *)(*(code *)(&PTR_LAB_0066a144)[bVar1])();
      return pAVar6;
    }
  }
  if (ppAVar8 == *(ASN1_VALUE ***)PTR___stack_chk_guard_006a9ae8) {
    return (ASN1_TEMPLATE *)0x0;
  }
  pcStack_f4 = ASN1_template_d2i;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_194 = PTR___stack_chk_guard_006a9ae8;
  uStack_f8 = 0xffffffe0;
  pAStack_fc = unaff_s7;
  pAStack_104 = param_2;
  ppAStack_108 = unaff_s4;
  pAStack_10c = unaff_s3;
  pAStack_118 = pAStack_198;
  uStack_134 = 0;
  pAStack_11c = *(ASN1_ITEM **)PTR___stack_chk_guard_006a9ae8;
  pAStack_190 = (ASN1_TEMPLATE *)0x0;
  pcVar10 = &pAVar9->itype;
  it = pcVar14;
  pAStack_180 = pAStack_100;
  pAStack_178 = (ASN1_ITEM *)0xffffffe0;
  if (ppAVar8 != (ASN1_VALUE **)0x0) {
    param_2 = *(ASN1_ITEM **)pcVar14;
    pAStack_198 = *(ASN1_ITEM **)pAVar9;
    pAStack_148 = pAStack_198;
    unaff_s3 = (ASN1_ITEM *)pcVar14;
    pAStack_180 = pAVar9;
    if (((uint)param_2 & 0x10) == 0) {
      pAStack_190 = (ASN1_TEMPLATE *)asn1_template_noexp_d2i();
    }
    else {
      iVar15 = *(long *)((int)pcVar14 + 4);
      pAStack_138 = pAStack_198;
      pcStack_130 = (char *)ASN1_get_object((uchar **)&pAStack_138,(long *)&pAStack_13c,&iStack_144,
                                            (int *)&pAStack_140,(long)pAVar11);
      pAVar7 = pAStack_138;
      iStack_120 = (int)pAStack_138 - (int)pAStack_198;
      pAStack_12c = pAStack_13c;
      pAStack_124 = pAStack_140;
      iStack_128 = iStack_144;
      uStack_134 = 1;
      unaff_s4 = ppAVar8;
      unaff_s7 = pAVar11;
      pAStack_178 = pAStack_13c;
      if ((((uint)pcStack_130 & 0x81) == 0) && ((int)pAVar11 < (int)((int)pAStack_13c + iStack_120))
         ) {
        uVar12 = 0x9b;
LAB_0056138c:
        (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x68,uVar12,s_tasn_dec_c_0066a0bc);
        uStack_134 = 0;
      }
      else {
        pAStack_190 = (ASN1_TEMPLATE *)((uint)pcStack_130 & 0x80);
        if (pAStack_190 != (ASN1_TEMPLATE *)0x0) {
          uVar12 = 0x66;
          goto LAB_0056138c;
        }
        if (iVar15 < 0) {
LAB_00561334:
          param_2 = (ASN1_ITEM *)(int)(char)pcStack_130;
          pAStack_148 = pAStack_138;
          pAStack_198 = (ASN1_ITEM *)((int)pAVar11 - iStack_120);
          if (((uint)pcStack_130 & 1) != 0) {
            pAStack_178 = pAStack_198;
          }
          if (((uint)param_2 & 0x20) == 0) {
            pAVar11 = (ASN1_ITEM *)&DAT_00000078;
          }
          else {
            pcVar10 = (char *)&pAStack_148;
            pAVar11 = pAStack_178;
            iVar15 = asn1_template_noexp_d2i(ppAVar8);
            if (iVar15 != 0) {
              param_2 = (ASN1_ITEM *)((uint)param_2 & 1);
              pAStack_178 = (ASN1_ITEM *)((int)pAStack_178 - ((int)pAStack_148 - (int)pAVar7));
              if (param_2 == (ASN1_ITEM *)0x0) {
                pAVar7 = pAStack_148;
                if (pAStack_178 != (ASN1_ITEM *)0x0) {
                  pAVar11 = (ASN1_ITEM *)&DAT_00000077;
                  goto LAB_0056143c;
                }
              }
              else {
                pAStack_178 = (ASN1_ITEM *)(uint)((int)pAStack_178 < 2);
                if (((pAStack_178 != (ASN1_ITEM *)0x0) || (pAStack_148->itype != '\0')) ||
                   (pAStack_148->field_0x1 != '\0')) {
                  pAVar11 = (ASN1_ITEM *)&DAT_00000089;
LAB_0056143c:
                  it = s_tasn_dec_c_0066a0bc;
                  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x84);
                  pcVar10 = pcVar14;
                  ASN1_template_free(ppAVar8,(ASN1_TEMPLATE *)pcVar14);
                  goto LAB_005611f0;
                }
                pAVar7 = (ASN1_ITEM *)&pAStack_148->field_0x2;
              }
              *(ASN1_ITEM **)pAVar9 = pAVar7;
              pAStack_190 = (ASN1_TEMPLATE *)0x1;
              goto LAB_005611f0;
            }
            pAVar11 = (ASN1_ITEM *)&DAT_0000003a;
          }
          it = s_tasn_dec_c_0066a0bc;
          pcVar10 = &DAT_00000084;
          (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
          goto LAB_005611f0;
        }
        if ((iVar15 == iStack_144) &&
           (param_2 = (ASN1_ITEM *)((uint)param_2 & 0xc0), param_2 == pAStack_140)) {
          uStack_134 = 0;
          goto LAB_00561334;
        }
        uStack_134 = 0;
        (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x68,0xa8,s_tasn_dec_c_0066a0bc);
      }
      pAStack_198 = (ASN1_ITEM *)0x670000;
      it = s_tasn_dec_c_0066a0bc;
      pAVar11 = (ASN1_ITEM *)&DAT_0000003a;
      pcVar10 = &DAT_00000084;
      pAStack_190 = (ASN1_TEMPLATE *)0x0;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
    }
  }
LAB_005611f0:
  if (pAStack_11c == *(ASN1_ITEM **)puStack_194) {
    return pAStack_190;
  }
  pcStack_174 = ASN1_item_d2i;
  pAVar9 = pAStack_11c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  pvVar16 = *(void **)((int)it + 0x10);
  ppAStack_188 = unaff_s4;
  pAStack_18c = unaff_s3;
  pAStack_17c = unaff_s7;
  pAStack_184 = param_2;
  auStack_1c4 = (undefined  [4])0x0;
  auStack_1b4[0] = 0;
  pAStack_1c0 = pAVar11;
  pAStack_1bc = (ASN1_TEMPLATE *)0x0;
  pAVar7 = (ASN1_ITEM *)auStack_1c4;
  if (pAVar9 != (ASN1_ITEM *)0x0) {
    pAVar7 = pAVar9;
  }
  piStack_19c = *(int **)PTR___stack_chk_guard_006a9ae8;
  if (pvVar16 == (void *)0x0) {
    switch(*it) {
    case '\0':
      goto switchD_005619f8_caseD_0;
    case '\x01':
    case '\x06':
      pcStack_1d8 = (code *)0x0;
      goto switchD_00561550_caseD_1;
    case '\x02':
      pcStack_1d8 = (code *)0x0;
LAB_00561954:
      if (*(ASN1_TEMPLATE **)pAVar7 == (ASN1_TEMPLATE *)0x0) {
        iVar15 = ASN1_item_ex_new((ASN1_VALUE **)pAVar7,(ASN1_ITEM *)it);
        if (iVar15 == 0) {
          uVar13 = 0x3a;
          uVar12 = 0x13f;
          goto LAB_0056163c;
        }
        pAVar11 = *(ASN1_ITEM **)((int)it + 0xc);
      }
      else {
        iVar15 = asn1_get_choice_selector((ASN1_VALUE **)pAVar7,(ASN1_ITEM *)it);
        pAVar11 = *(ASN1_ITEM **)((int)it + 0xc);
        if ((-1 < iVar15) && (iVar15 < (int)pAVar11)) {
          pAVar6 = *(ASN1_TEMPLATE **)((int)it + 8);
          ppAVar8 = asn1_get_field_ptr((ASN1_VALUE **)pAVar7,pAVar6 + iVar15);
          ASN1_template_free(ppAVar8,pAVar6 + iVar15);
          asn1_set_choice_selector((ASN1_VALUE **)pAVar7,-1,(ASN1_ITEM *)it);
          pAVar11 = *(ASN1_ITEM **)((int)it + 0xc);
        }
      }
      pAStack_1bc = *(ASN1_TEMPLATE **)pcVar10;
      pAVar9 = (ASN1_ITEM *)0x0;
      pAVar6 = *(ASN1_TEMPLATE **)((int)it + 8);
      if ((int)pAVar11 < 1) {
LAB_005615e0:
        if (pAVar9 == pAVar11) {
LAB_00561a34:
          uVar13 = 0x8f;
          uVar12 = 0x15e;
          goto LAB_0056163c;
        }
      }
      else {
        do {
          ppAVar8 = asn1_get_field_ptr((ASN1_VALUE **)pAVar7,pAVar6);
          iVar15 = asn1_template_ex_d2i(ppAVar8,auStack_1c4 + 8,pAStack_1c0,pAVar6,1,auStack_1b4);
          if (iVar15 != -1) {
            if (iVar15 < 1) {
              (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x78,0x3a,s_tasn_dec_c_0066a0bc,0x152);
              ASN1_item_ex_free((ASN1_VALUE **)pAVar7,(ASN1_ITEM *)it);
              if (pAVar6 == (ASN1_TEMPLATE *)0x0) goto LAB_00561668;
              goto LAB_00561cf8;
            }
            pAVar11 = *(ASN1_ITEM **)((int)it + 0xc);
            goto LAB_005615e0;
          }
          pAVar9 = (ASN1_ITEM *)&pAVar9->field_0x1;
          pAVar6 = pAVar6 + 1;
        } while ((int)pAVar9 < (int)*(undefined **)((int)it + 0xc));
        if (pAVar9 == (ASN1_ITEM *)*(undefined **)((int)it + 0xc)) goto LAB_00561a34;
      }
      asn1_set_choice_selector((ASN1_VALUE **)pAVar7,(int)pAVar9,(ASN1_ITEM *)it);
      goto joined_r0x00561600;
    case '\x03':
      goto switchD_005619f8_caseD_3;
    case '\x04':
      pcStack_1d8 = *(code **)(in_zero + 0x10);
      goto LAB_005618f4;
    case '\x05':
      goto switchD_005619f8_caseD_5;
    }
    goto switchD_005619f8_caseD_7;
  }
  pcStack_1d8 = *(code **)((int)pvVar16 + 0x10);
  switch(*it) {
  case '\0':
switchD_005619f8_caseD_0:
    if (*(ASN1_TEMPLATE **)((int)it + 8) == (ASN1_TEMPLATE *)0x0) {
      iVar15 = asn1_d2i_ex_primitive(pAVar7,pcVar10,pAVar11,it,0xffffffff,0,0,auStack_1b4);
      if (iVar15 < 1) {
        pAVar6 = (ASN1_TEMPLATE *)0x0;
        pAVar9 = (ASN1_ITEM *)pcVar10;
        goto LAB_00561684;
      }
    }
    else {
      iVar15 = asn1_template_ex_d2i
                         (pAVar7,pcVar10,pAVar11,*(ASN1_TEMPLATE **)((int)it + 8),0,auStack_1b4);
      if (iVar15 < 1) goto switchD_005619f8_caseD_7;
    }
    goto LAB_005617a4;
  case '\x01':
  case '\x06':
switchD_00561550_caseD_1:
    pAStack_1bc = *(ASN1_TEMPLATE **)pcVar10;
    pAVar9 = (ASN1_ITEM *)0x0;
    iVar15 = asn1_check_tlen(auStack_1c4 + 4,0,0,&cStack_1c6,&cStack_1c5,auStack_1c4 + 8,pAVar11,
                             0x10,0,0,auStack_1b4);
    if (iVar15 == 0) {
      uVar13 = 0x3a;
      uVar12 = 0x176;
    }
    else {
      pAVar6 = (ASN1_TEMPLATE *)0x0;
      if (iVar15 == -1) goto LAB_00561684;
      cVar2 = cStack_1c6;
      if ((pvVar16 != (void *)0x0) && ((*(uint *)((int)pvVar16 + 4) & 4) != 0)) {
        pAStack_1c0 = (ASN1_ITEM *)
                      ((int)pAVar11 - ((int)pAStack_1bc - (int)*(ASN1_TEMPLATE **)pcVar10));
        cVar2 = '\x01';
      }
      if (cStack_1c5 == '\0') {
        uVar13 = 0x95;
        uVar12 = 0x182;
      }
      else if ((*(ASN1_TEMPLATE **)pAVar7 == (ASN1_TEMPLATE *)0x0) &&
              (iVar15 = ASN1_item_ex_new((ASN1_VALUE **)pAVar7,(ASN1_ITEM *)it), iVar15 == 0)) {
        uVar13 = 0x3a;
        uVar12 = 0x187;
      }
      else {
        puStack_1d0 = auStack_1b4;
        if ((pcStack_1d8 != (code *)0x0) && (iVar15 = (*pcStack_1d8)(4,pAVar7,it,0), iVar15 == 0))
        goto LAB_00561628;
        iVar15 = *(long *)((int)it + 0xc);
        iVar17 = 0;
        tt = *(ASN1_TEMPLATE **)((int)it + 8);
        if (0 < iVar15) {
          do {
            if ((tt->flags & 0x300) != 0) {
              pAVar6 = asn1_do_adb((ASN1_VALUE **)pAVar7,tt,1);
              ppAVar8 = asn1_get_field_ptr((ASN1_VALUE **)pAVar7,pAVar6);
              ASN1_template_free(ppAVar8,pAVar6);
              iVar15 = *(long *)((int)it + 0xc);
            }
            iVar17 = iVar17 + 1;
            tt = tt + 1;
          } while (iVar17 < iVar15);
          tt = *(ASN1_TEMPLATE **)((int)it + 8);
          iVar17 = 0;
          if (0 < iVar15) {
            do {
              pAVar6 = asn1_do_adb((ASN1_VALUE **)pAVar7,tt,1);
              if (pAVar6 == (ASN1_TEMPLATE *)0x0) goto LAB_00561650;
              ppAVar8 = asn1_get_field_ptr((ASN1_VALUE **)pAVar7,pAVar6);
              pAVar4 = pAStack_1bc;
              if (pAStack_1c0 == (ASN1_ITEM *)0x0) {
                if (cStack_1c6 != '\0') goto LAB_00561e04;
                goto LAB_00561c3c;
              }
              if (((1 < (int)pAStack_1c0) && (*(char *)&pAStack_1bc->flags == '\0')) &&
                 (*(char *)((int)&pAStack_1bc->flags + 1) == '\0')) {
                pAStack_1bc = (ASN1_TEMPLATE *)((int)&pAStack_1bc->flags + 2);
                if (cStack_1c6 != '\0') {
                  cStack_1c6 = '\0';
                  pAStack_1c0 = (ASN1_ITEM *)((int)&pAStack_1c0[-1].sname + 2);
                  goto LAB_00561c28;
                }
                uVar13 = 0x9f;
                uVar12 = 0x1a7;
                goto LAB_0056163c;
              }
              uVar5 = 0;
              if (*(long *)((int)it + 0xc) + -1 != iVar17) {
                uVar5 = pAVar6->flags & 1;
              }
              iVar15 = asn1_template_ex_d2i
                                 (ppAVar8,auStack_1c4 + 8,pAStack_1c0,pAVar6,uVar5,puStack_1d0);
              if (iVar15 == 0) goto LAB_00561ce4;
              if (iVar15 == -1) {
                ASN1_template_free(ppAVar8,pAVar6);
              }
              else {
                pAStack_1c0 = (ASN1_ITEM *)((int)pAStack_1c0 - ((int)pAStack_1bc - (int)pAVar4));
              }
              iVar17 = iVar17 + 1;
              tt = tt + 1;
            } while (iVar17 < *(long *)((int)it + 0xc));
          }
        }
        if (cStack_1c6 != '\0') {
          if ((((int)pAStack_1c0 < 2) || (*(char *)&pAStack_1bc->flags != '\0')) ||
             (*(char *)((int)&pAStack_1bc->flags + 1) != '\0')) {
LAB_00561e04:
            uVar13 = 0x89;
            uVar12 = 0x1ce;
            break;
          }
          pAStack_1bc = (ASN1_TEMPLATE *)((int)&pAStack_1bc->flags + 2);
        }
LAB_00561c28:
        if ((cVar2 != '\0') || (pAStack_1c0 == (ASN1_ITEM *)0x0)) {
LAB_00561c3c:
          if (iVar17 < *(long *)((int)it + 0xc)) {
LAB_00561c90:
            pAVar6 = asn1_do_adb((ASN1_VALUE **)pAVar7,tt,1);
            if (pAVar6 != (ASN1_TEMPLATE *)0x0) {
              if ((pAVar6->flags & 1) != 0) goto LAB_00561c54;
              (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x78,0x79,s_tasn_dec_c_0066a0bc,0x1e7);
LAB_00561ce4:
              ASN1_item_ex_free((ASN1_VALUE **)pAVar7,(ASN1_ITEM *)it);
LAB_00561cf8:
              pcVar10 = (char *)&DAT_0066a0d0;
              (*(code *)PTR_ERR_add_error_data_006a813c)
                        (4,&DAT_0066a0d0,pAVar6->field_name,", Type=",*(char **)((int)it + 0x18));
              goto switchD_005619f8_caseD_7;
            }
            goto LAB_00561650;
          }
          pAVar9 = *(ASN1_ITEM **)pcVar10;
          goto LAB_00561a70;
        }
        uVar13 = 0x94;
        uVar12 = 0x1d3;
      }
    }
    break;
  case '\x02':
    if ((pcStack_1d8 == (code *)0x0) || (iVar15 = (*pcStack_1d8)(4,pAVar7,it,0), iVar15 != 0))
    goto LAB_00561954;
    goto LAB_00561628;
  case '\x03':
switchD_005619f8_caseD_3:
    iVar15 = (**(code **)((int)pvVar16 + 8))(pAVar7,pcVar10,pAVar11);
    if (iVar15 != 0) {
      pAVar6 = *(ASN1_TEMPLATE **)pAVar7;
      pAVar9 = (ASN1_ITEM *)pcVar10;
      goto LAB_00561684;
    }
    uVar13 = 0x3a;
    uVar12 = 0x12f;
    break;
  case '\x04':
LAB_005618f4:
    iVar15 = (*pcStack_1d8)(pAVar7,pcVar10,pAVar11,it,0xffffffff,0,0,auStack_1b4);
    if (iVar15 < 1) {
      pAVar6 = (ASN1_TEMPLATE *)0x0;
      pAVar9 = (ASN1_ITEM *)pcVar10;
      goto LAB_00561684;
    }
LAB_005617a4:
    pAVar6 = *(ASN1_TEMPLATE **)pAVar7;
    pAVar9 = (ASN1_ITEM *)pcVar10;
    goto LAB_00561684;
  case '\x05':
switchD_005619f8_caseD_5:
    pAStack_1bc = *(ASN1_TEMPLATE **)pcVar10;
    iVar15 = asn1_check_tlen_constprop_1
                       (0,auStack_1c4 + 0xc,&cStack_1c7,0,0,auStack_1c4 + 8,pAVar11,1,auStack_1b4);
    if (iVar15 == 0) {
      uVar13 = 0x3a;
      uVar12 = 0xdb;
    }
    else if (cStack_1c7 == '\0') {
      if ((uStack_1b8 < 0x1f) &&
         ((*(uint *)(tag2bit + uStack_1b8 * 4) & *(long *)((int)it + 4)) != 0)) {
        iVar15 = asn1_d2i_ex_primitive(pAVar7,pcVar10,pAStack_1c0,it,uStack_1b8,0,0,auStack_1b4);
        if (iVar15 < 1) {
          pAVar6 = (ASN1_TEMPLATE *)0x0;
          pAVar9 = (ASN1_ITEM *)pcVar10;
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
  ASN1_item_ex_free((ASN1_VALUE **)pAVar7,(ASN1_ITEM *)it);
LAB_00561668:
  pcVar10 = s_Type__0066a0d8;
  (*(code *)PTR_ERR_add_error_data_006a813c)(2,s_Type__0066a0d8,*(char **)((int)it + 0x18));
switchD_005619f8_caseD_7:
  pAVar6 = (ASN1_TEMPLATE *)0x0;
  pAVar9 = (ASN1_ITEM *)pcVar10;
LAB_00561684:
  if (piStack_19c == *(int **)puVar3) {
    return pAVar6;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  return *(ASN1_TEMPLATE **)(pAVar9->utype + *piStack_19c);
LAB_00561c54:
  iVar17 = iVar17 + 1;
  ppAVar8 = asn1_get_field_ptr((ASN1_VALUE **)pAVar7,pAVar6);
  tt = tt + 1;
  ASN1_template_free(ppAVar8,pAVar6);
  if (*(long *)((int)it + 0xc) <= iVar17) goto LAB_00561a6c;
  goto LAB_00561c90;
LAB_00561a6c:
  pAVar9 = *(ASN1_ITEM **)pcVar10;
LAB_00561a70:
  iVar15 = asn1_enc_save((ASN1_VALUE **)pAVar7,(uchar *)pAVar9,(int)pAStack_1bc - (int)pAVar9,
                         (ASN1_ITEM *)it);
  if (iVar15 != 0) {
joined_r0x00561600:
    if ((pcStack_1d8 == (code *)0x0) ||
       (pAVar9 = pAVar7, iVar15 = (*pcStack_1d8)(5,pAVar7,it,0), iVar15 != 0)) {
      *(ASN1_TEMPLATE **)pcVar10 = pAStack_1bc;
      pAVar6 = *(ASN1_TEMPLATE **)pAVar7;
      goto LAB_00561684;
    }
  }
LAB_00561628:
  uVar13 = 100;
  uVar12 = 0x1f7;
  goto LAB_0056163c;
}

