
/* WARNING: Type propagation algorithm not settling */

uint asn1_template_noexp_d2i
               (ASN1_ITEM **param_1,ASN1_ITEM *param_2,ASN1_ITEM *param_3,ASN1_ITEM *param_4,
               char param_5,ASN1_ITEM *param_6)

{
  byte bVar1;
  char cVar2;
  undefined *puVar3;
  ASN1_TEMPLATE *pAVar4;
  int in_zero;
  uint uVar5;
  int iVar6;
  int iVar7;
  ASN1_VALUE **ppAVar8;
  ASN1_ITEM *pAVar9;
  ASN1_ITEM *pAVar10;
  ASN1_TEMPLATE *tt;
  ASN1_ITEM *pAVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  char *pcVar14;
  char *pcVar15;
  char *pcVar16;
  ASN1_ITEM *unaff_s0;
  ASN1_ITEM **unaff_s2;
  void *pvVar17;
  ASN1_ITEM *unaff_s3;
  ASN1_ITEM *unaff_s4;
  ASN1_TEMPLATE *tt_00;
  ASN1_TEMPLATE *unaff_s5;
  ASN1_ITEM *unaff_s6;
  ASN1_ITEM *unaff_s7;
  ASN1_ITEM *unaff_s8;
  ASN1_ITEM *local_res8 [2];
  code *pcStack_278;
  undefined *puStack_270;
  char cStack_267;
  char cStack_266;
  char cStack_265;
  undefined auStack_264 [4];
  ASN1_ITEM *pAStack_260;
  ASN1_TEMPLATE *pAStack_25c;
  uint uStack_258;
  undefined auStack_254 [24];
  int *piStack_23c;
  ASN1_ITEM *pAStack_238;
  undefined *puStack_234;
  uint uStack_230;
  ASN1_ITEM *pAStack_22c;
  ASN1_ITEM *pAStack_228;
  ASN1_ITEM *pAStack_224;
  ASN1_ITEM *pAStack_220;
  ASN1_ITEM *pAStack_21c;
  ASN1_ITEM *pAStack_218;
  code *pcStack_214;
  ASN1_ITEM *pAStack_1e8;
  int iStack_1e4;
  ASN1_ITEM *pAStack_1e0;
  ASN1_ITEM *pAStack_1dc;
  ASN1_ITEM *pAStack_1d8;
  undefined uStack_1d4;
  char *pcStack_1d0;
  ASN1_ITEM *pAStack_1cc;
  int iStack_1c8;
  ASN1_ITEM *pAStack_1c4;
  int iStack_1c0;
  ASN1_ITEM *pAStack_1bc;
  ASN1_ITEM *pAStack_1b8;
  undefined *puStack_1b4;
  ASN1_ITEM_EXP *pAStack_1b0;
  ASN1_ITEM *pAStack_1ac;
  ASN1_ITEM *pAStack_1a8;
  ASN1_ITEM *pAStack_1a4;
  ASN1_ITEM *pAStack_1a0;
  undefined4 uStack_19c;
  ASN1_ITEM *pAStack_198;
  code *pcStack_194;
  undefined *puStack_160;
  void *pvStack_154;
  undefined4 uStack_144;
  ASN1_ITEM *pAStack_13c;
  ASN1_ITEM *pAStack_138;
  ASN1_ITEM *pAStack_134;
  undefined *puStack_130;
  ASN1_ITEM *pAStack_12c;
  ASN1_ITEM *pAStack_128;
  ASN1_ITEM *pAStack_124;
  ASN1_ITEM *pAStack_120;
  ASN1_ITEM *pAStack_11c;
  ASN1_ITEM *pAStack_118;
  code *pcStack_114;
  ASN1_ITEM *pAStack_108;
  ASN1_ITEM *pAStack_e8;
  undefined auStack_e4 [8];
  ASN1_ITEM AStack_dc;
  ASN1_ITEM *pAStack_c0;
  ASN1_TEMPLATE *pAStack_bc;
  ASN1_ITEM *pAStack_b8;
  ASN1_ITEM *pAStack_b4;
  ASN1_ITEM *pAStack_b0;
  code *pcStack_ac;
  char in_stack_ffffff6b;
  ASN1_ITEM *pAVar18;
  ASN1_ITEM *in_stack_ffffff6c;
  ASN1_ITEM_EXP *local_68;
  undefined local_44;
  char local_43;
  char local_42;
  char local_41;
  ASN1_ITEM *local_40;
  ASN1_ITEM *local_3c;
  ASN1_ITEM *local_38;
  ASN1_ITEM *local_34;
  ASN1_ITEM *local_30;
  ASN1_ITEM *local_2c;
  
  puVar3 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(ASN1_ITEM **)PTR___stack_chk_guard_006aabf0;
  local_res8[0] = param_3;
  if (param_1 == (ASN1_ITEM **)0x0) {
    uVar5 = 0;
    pAStack_224 = param_2;
    pcVar14 = &param_4->itype;
  }
  else {
    uVar5 = *(uint *)param_4;
    local_40 = *(ASN1_ITEM **)param_2;
    in_stack_ffffff6c = (ASN1_ITEM *)(uVar5 & 0xc0);
    if ((uVar5 & 6) == 0) {
      if ((uVar5 & 8) == 0) {
        unaff_s0 = (ASN1_ITEM *)0xffffffff;
        pcVar14 = (char *)param_4->funcs;
        pAStack_224 = (ASN1_ITEM *)&local_40;
        in_stack_ffffff6c = (ASN1_ITEM *)0x0;
        in_stack_ffffff6b = -1;
        iVar6 = ASN1_item_ex_d2i((ASN1_VALUE **)param_1,(uchar **)pAStack_224,(long)param_3,
                                 (ASN1_ITEM *)pcVar14,-1,0,param_5,(ASN1_TLC *)param_6);
        pAVar18 = local_40;
        if (iVar6 != 0) goto joined_r0x00563a7c;
        param_3 = (ASN1_ITEM *)&DAT_0000003a;
        in_stack_ffffff6b = -0x11;
      }
      else {
        iVar7 = param_4->utype;
        pAStack_224 = (ASN1_ITEM *)&local_40;
        pcVar14 = (char *)param_4->funcs;
        iVar6 = ASN1_item_ex_d2i((ASN1_VALUE **)param_1,(uchar **)pAStack_224,(long)param_3,
                                 (ASN1_ITEM *)pcVar14,iVar7,(int)in_stack_ffffff6c,param_5,
                                 (ASN1_TLC *)param_6);
        in_stack_ffffff6b = (char)iVar7;
        pAVar18 = local_40;
        if (iVar6 != 0) {
joined_r0x00563a7c:
          unaff_s0 = pAVar18;
          local_40 = unaff_s0;
          if (iVar6 == -1) {
            uVar5 = 0xffffffff;
          }
          else {
LAB_00563500:
            *(ASN1_ITEM **)param_2 = local_40;
            uVar5 = 1;
            unaff_s0 = local_40;
          }
          goto LAB_005639d4;
        }
        param_3 = (ASN1_ITEM *)&DAT_0000003a;
        in_stack_ffffff6b = -0x1f;
      }
LAB_00563afc:
      pcVar14 = s_tasn_dec_c_0066ab2c;
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x83);
LAB_005639bc:
      pAStack_224 = param_4;
      ASN1_template_free((ASN1_VALUE **)param_1,(ASN1_TEMPLATE *)param_4);
      uVar5 = 0;
    }
    else {
      unaff_s6 = (ASN1_ITEM *)&local_40;
      pcVar14 = &local_44;
      param_3 = (ASN1_ITEM *)0x0;
      pAStack_224 = (ASN1_ITEM *)0x0;
      pAVar18 = (ASN1_ITEM *)0x0;
      in_stack_ffffff6c = unaff_s6;
      iVar6 = asn1_check_tlen(local_res8);
      in_stack_ffffff6b = (char)pAVar18;
      if (iVar6 == 0) {
        param_3 = (ASN1_ITEM *)&DAT_0000003a;
        pcVar14 = s_tasn_dec_c_0066ab2c;
        in_stack_ffffff6b = -0x6d;
        pAStack_224 = (ASN1_ITEM *)0x83;
        (*(code *)PTR_ERR_put_error_006a9030)(0xd);
        uVar5 = 0;
      }
      else {
        uVar5 = 0xffffffff;
        if (iVar6 != -1) {
          unaff_s0 = *param_1;
          unaff_s2 = &local_30;
          if (unaff_s0 == (ASN1_ITEM *)0x0) {
            pAVar9 = (ASN1_ITEM *)(*(code *)PTR_sk_new_null_006a80a4)();
            *param_1 = pAVar9;
          }
          else {
            while (iVar6 = (*(code *)PTR_sk_num_006a7f2c)(unaff_s0), 0 < iVar6) {
              local_30 = (ASN1_ITEM *)(*(code *)PTR_sk_pop_006a9ec4)(unaff_s0);
              pAStack_224 = (ASN1_ITEM *)param_4->funcs;
              ASN1_item_ex_free((ASN1_VALUE **)unaff_s2,pAStack_224);
            }
            pAVar9 = *param_1;
          }
          in_stack_ffffff6b = (char)pAVar18;
          if (pAVar9 == (ASN1_ITEM *)0x0) {
            param_3 = (ASN1_ITEM *)&DAT_00000041;
            in_stack_ffffff6b = -0x55;
            unaff_s3 = local_res8[0];
          }
          else {
            if (0 < (int)local_res8[0]) {
LAB_0056345c:
              pAVar9 = local_40;
              unaff_s3 = local_res8[0];
              in_stack_ffffff6b = (char)pAVar18;
              if (((local_res8[0] != (ASN1_ITEM *)0x1) && (local_40->itype == '\0')) &&
                 (local_40->field_0x1 == '\0')) {
                local_40 = (ASN1_ITEM *)&local_40->field_0x2;
                if (local_44 != '\0') goto LAB_00563500;
                param_3 = (ASN1_ITEM *)0x9f;
                in_stack_ffffff6b = -0x46;
                unaff_s0 = local_40;
                goto LAB_00563afc;
              }
              unaff_s8 = (ASN1_ITEM *)param_4->funcs;
              local_3c = (ASN1_ITEM *)0x0;
              local_38 = local_res8[0];
              local_34 = (ASN1_ITEM *)0x0;
              unaff_s5 = (ASN1_TEMPLATE *)unaff_s8->funcs;
              param_3 = local_res8[0];
              if (unaff_s5 == (ASN1_TEMPLATE *)0x0) {
                switch(unaff_s8->itype) {
                case '\0':
                  goto switchD_00563a30_caseD_563790;
                case '\x01':
                case '\x06':
                  local_68 = (ASN1_ITEM_EXP *)0x0;
                  goto switchD_005634b4_caseD_1;
                case '\x02':
                  local_68 = (ASN1_ITEM_EXP *)0x0;
                  goto LAB_00563b38;
                case '\x03':
                  goto switchD_00563a30_caseD_5635a8;
                case '\x04':
                  goto switchD_00563a30_caseD_563510;
                case '\x05':
                  goto switchD_00563a30_caseD_5637c4;
                }
                goto switchD_005634b4_caseD_7;
              }
              local_68 = unaff_s5->item;
              switch(unaff_s8->itype) {
              case '\0':
switchD_00563a30_caseD_563790:
                pcVar14 = (char *)unaff_s8->templates;
                if ((ASN1_ITEM *)pcVar14 == (ASN1_ITEM *)0x0) {
                  in_stack_ffffff6c = (ASN1_ITEM *)0x0;
                  pAVar18 = (ASN1_ITEM *)0xffffffff;
                  pcVar14 = (char *)unaff_s8;
                  iVar6 = asn1_d2i_ex_primitive(&local_3c,unaff_s6);
                }
                else {
                  pAVar18 = (ASN1_ITEM *)0x0;
                  in_stack_ffffff6c = param_6;
                  iVar6 = asn1_template_ex_d2i(&local_3c,unaff_s6);
                }
                goto joined_r0x00563d40;
              case '\x01':
              case '\x06':
switchD_005634b4_caseD_1:
                unaff_s4 = (ASN1_ITEM *)&local_34;
                pcVar14 = &local_42;
                param_3 = (ASN1_ITEM *)0x0;
                local_34 = local_40;
                pAVar18 = (ASN1_ITEM *)&local_41;
                in_stack_ffffff6c = unaff_s4;
                iVar6 = asn1_check_tlen(&local_38,0);
                if (iVar6 == 0) {
                  uVar12 = 0x3a;
                  goto LAB_00563824;
                }
                if (iVar6 == -1) goto LAB_0056354c;
                cVar2 = local_42;
                if ((unaff_s5 != (ASN1_TEMPLATE *)0x0) && ((unaff_s5->tag & 4U) != 0)) {
                  unaff_s3 = (ASN1_ITEM *)((int)unaff_s3 - ((int)local_34 - (int)local_40));
                  local_38 = unaff_s3;
                  cVar2 = '\x01';
                }
                if (local_41 == '\0') {
                  uVar12 = 0x95;
                  goto LAB_00563824;
                }
                unaff_s2 = &local_3c;
                if ((local_3c == (ASN1_ITEM *)0x0) &&
                   (iVar6 = ASN1_item_ex_new((ASN1_VALUE **)unaff_s2,unaff_s8), iVar6 == 0)) {
                  uVar12 = 0x3a;
LAB_00563954:
                  (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x78,uVar12,s_tasn_dec_c_0066ab2c);
                  goto LAB_00563968;
                }
                if ((local_68 != (ASN1_ITEM_EXP *)0x0) &&
                   (iVar6 = (*(code *)local_68)(4,unaff_s2,unaff_s8,0), iVar6 == 0))
                goto LAB_00563940;
                unaff_s3 = (ASN1_ITEM *)0x0;
                unaff_s5 = unaff_s8->templates;
                if (0 < unaff_s8->tcount) {
                  do {
                    unaff_s7 = (ASN1_ITEM *)asn1_do_adb((ASN1_VALUE **)unaff_s2,unaff_s5,1);
                    if (unaff_s7 == (ASN1_ITEM *)0x0) goto LAB_00563968;
                    ppAVar8 = asn1_get_field_ptr((ASN1_VALUE **)unaff_s2,(ASN1_TEMPLATE *)unaff_s7);
                    pAVar11 = local_34;
                    if (local_38 == (ASN1_ITEM *)0x0) {
                      if (local_42 == '\0') goto LAB_00563c68;
                      goto LAB_00563e08;
                    }
                    if (((1 < (int)local_38) && (local_34->itype == '\0')) &&
                       (local_34->field_0x1 == '\0')) {
                      local_34 = (ASN1_ITEM *)&local_34->field_0x2;
                      if (local_42 == '\0') {
                        uVar12 = 0x9f;
                        goto LAB_00563954;
                      }
                      local_38 = (ASN1_ITEM *)((int)&local_38[-1].sname + 2);
                      local_42 = '\0';
                      goto LAB_00563c54;
                    }
                    pAVar18 = (ASN1_ITEM *)0x0;
                    if ((ASN1_ITEM *)(unaff_s8->tcount + -1) != unaff_s3) {
                      pAVar18 = (ASN1_ITEM *)(*(uint *)unaff_s7 & 1);
                    }
                    in_stack_ffffff6c = param_6;
                    iVar6 = asn1_template_ex_d2i(ppAVar8,unaff_s4,local_38,unaff_s7);
                    if (iVar6 == 0) goto LAB_00563e24;
                    if (iVar6 == -1) {
                      ASN1_template_free(ppAVar8,(ASN1_TEMPLATE *)unaff_s7);
                    }
                    else {
                      local_38 = (ASN1_ITEM *)((int)local_38 - ((int)local_34 - (int)pAVar11));
                    }
                    unaff_s3 = (ASN1_ITEM *)&unaff_s3->field_0x1;
                    unaff_s5 = unaff_s5 + 1;
                  } while ((int)unaff_s3 < unaff_s8->tcount);
                }
                if (local_42 != '\0') {
                  if ((((int)local_38 < 2) || (local_34->itype != '\0')) ||
                     (local_34->field_0x1 != '\0')) {
LAB_00563e08:
                    uVar12 = 0x89;
                    goto LAB_00563954;
                  }
                  local_34 = (ASN1_ITEM *)&local_34->field_0x2;
                }
LAB_00563c54:
                if ((cVar2 == '\0') && (local_38 != (ASN1_ITEM *)0x0)) {
                  uVar12 = 0x94;
                  goto LAB_00563954;
                }
LAB_00563c68:
                if ((int)unaff_s3 < unaff_s8->tcount) {
LAB_00563ccc:
                  unaff_s7 = (ASN1_ITEM *)asn1_do_adb((ASN1_VALUE **)unaff_s2,unaff_s5,1);
                  if (unaff_s7 != (ASN1_ITEM *)0x0) {
                    if ((*(uint *)unaff_s7 & 1) != 0) goto code_r0x00563c90;
                    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x78,0x79,s_tasn_dec_c_0066ab2c);
LAB_00563e24:
                    ASN1_item_ex_free((ASN1_VALUE **)unaff_s2,unaff_s8);
LAB_00563d8c:
                    unaff_s4 = (ASN1_ITEM *)&local_34;
                    unaff_s2 = &local_3c;
                    (*(code *)PTR_ERR_add_error_data_006a9264)
                              (4,&DAT_0066ab40,(char *)unaff_s7->tcount,", Type=");
                    goto switchD_005634b4_caseD_7;
                  }
                  goto LAB_00563968;
                }
LAB_00563eac:
                param_3 = (ASN1_ITEM *)((int)local_34 - (int)local_40);
                pcVar14 = (char *)unaff_s8;
                iVar6 = asn1_enc_save((ASN1_VALUE **)unaff_s2,(uchar *)local_40,(int)param_3,
                                      unaff_s8);
                if (iVar6 == 0) goto LAB_00563940;
                local_40 = local_34;
                if (local_68 != (ASN1_ITEM_EXP *)0x0) goto LAB_00563924;
                iVar6 = (int)local_34 - (int)pAVar9;
                goto LAB_00563550;
              case '\x02':
                if (local_68 == (ASN1_ITEM_EXP *)0x0) {
LAB_00563b38:
                  iVar6 = ASN1_item_ex_new((ASN1_VALUE **)&local_3c,unaff_s8);
                  if (iVar6 == 0) {
                    uVar12 = 0x3a;
                  }
                  else {
LAB_00563878:
                    unaff_s2 = &local_3c;
                    unaff_s3 = (ASN1_ITEM *)0x0;
                    pAVar11 = (ASN1_ITEM *)unaff_s8->tcount;
                    unaff_s7 = (ASN1_ITEM *)unaff_s8->templates;
                    local_34 = local_40;
                    if (0 < (int)pAVar11) {
                      unaff_s4 = (ASN1_ITEM *)&local_34;
                      unaff_s5 = (ASN1_TEMPLATE *)0xffffffff;
                      do {
                        ppAVar8 = asn1_get_field_ptr((ASN1_VALUE **)unaff_s2,
                                                     (ASN1_TEMPLATE *)unaff_s7);
                        pAVar18 = (ASN1_ITEM *)0x1;
                        pcVar14 = &unaff_s7->itype;
                        in_stack_ffffff6c = param_6;
                        iVar6 = asn1_template_ex_d2i(ppAVar8,unaff_s4,local_38);
                        if (iVar6 != -1) {
                          if (iVar6 < 1) {
                            (*(code *)PTR_ERR_put_error_006a9030)
                                      (0xd,0x78,0x3a,s_tasn_dec_c_0066ab2c);
                            ASN1_item_ex_free((ASN1_VALUE **)unaff_s2,unaff_s8);
                            if (unaff_s7 == (ASN1_ITEM *)0x0) goto LAB_0056397c;
                            goto LAB_00563d8c;
                          }
                          pAVar11 = (ASN1_ITEM *)unaff_s8->tcount;
                          break;
                        }
                        pAVar11 = (ASN1_ITEM *)unaff_s8->tcount;
                        unaff_s3 = (ASN1_ITEM *)&unaff_s3->field_0x1;
                        unaff_s7 = (ASN1_ITEM *)&unaff_s7->size;
                      } while ((int)unaff_s3 < (int)pAVar11);
                    }
                    if (unaff_s3 != pAVar11) {
                      param_3 = unaff_s8;
                      asn1_set_choice_selector((ASN1_VALUE **)unaff_s2,(int)unaff_s3,unaff_s8);
                      local_40 = local_34;
                      if (local_68 == (ASN1_ITEM_EXP *)0x0) goto LAB_0056354c;
LAB_00563924:
                      unaff_s2 = &local_3c;
                      pcVar14 = (char *)0x0;
                      param_3 = unaff_s8;
                      local_40 = local_34;
                      iVar6 = (*(code *)local_68)(5,unaff_s2);
                      if (iVar6 != 0) goto LAB_0056354c;
                      goto LAB_00563940;
                    }
                    uVar12 = 0x8f;
                  }
                }
                else {
                  pcVar14 = (char *)0x0;
                  iVar6 = (*(code *)local_68)(4,&local_3c,unaff_s8);
                  if (iVar6 != 0) {
                    if (local_3c == (ASN1_ITEM *)0x0) goto LAB_00563b38;
                    goto LAB_00563878;
                  }
LAB_00563940:
                  uVar12 = 100;
                }
                goto LAB_00563954;
              case '\x03':
switchD_00563a30_caseD_5635a8:
                unaff_s2 = &local_3c;
                iVar6 = (*(code *)unaff_s5->offset)(unaff_s2,unaff_s6);
                if (iVar6 == 0) {
                  uVar12 = 0x3a;
                  goto LAB_00563954;
                }
                goto LAB_0056354c;
              case '\x04':
switchD_00563a30_caseD_563510:
                in_stack_ffffff6c = (ASN1_ITEM *)0x0;
                pAVar18 = (ASN1_ITEM *)0xffffffff;
                pcVar14 = (char *)unaff_s8;
                iVar6 = (*(code *)unaff_s5->item)(&local_3c,unaff_s6);
joined_r0x00563d40:
                if (iVar6 == 0) goto switchD_005634b4_caseD_7;
LAB_0056354c:
                iVar6 = (int)local_40 - (int)pAVar9;
LAB_00563550:
                unaff_s0 = (ASN1_ITEM *)((int)local_res8[0] - iVar6);
                pAStack_224 = local_3c;
                local_res8[0] = unaff_s0;
                iVar6 = (*(code *)PTR_sk_push_006a80a8)(*param_1);
                in_stack_ffffff6b = (char)pAVar18;
                if (iVar6 != 0) goto code_r0x00563578;
                param_3 = (ASN1_ITEM *)&DAT_00000041;
                in_stack_ffffff6b = -0x31;
                goto LAB_00563afc;
              case '\x05':
switchD_00563a30_caseD_5637c4:
                unaff_s4 = (ASN1_ITEM *)&local_34;
                local_34 = local_40;
                in_stack_ffffff6c = unaff_s4;
                iVar6 = asn1_check_tlen_constprop_1(0,&local_30,&local_43,0);
                if (iVar6 == 0) {
                  uVar12 = 0x3a;
                }
                else if (local_43 == '\0') {
                  if ((local_30 < (ASN1_ITEM *)0x1f) &&
                     ((*(uint *)(tag2bit + (int)local_30 * 4) & unaff_s8->utype) != 0)) {
                    in_stack_ffffff6c = (ASN1_ITEM *)0x0;
                    param_3 = local_38;
                    pcVar14 = (char *)unaff_s8;
                    pAVar18 = local_30;
                    iVar6 = asn1_d2i_ex_primitive(&local_3c,unaff_s6);
                    goto joined_r0x00563d40;
                  }
                  uVar12 = 0x8c;
                }
                else {
                  uVar12 = 0x8b;
                }
LAB_00563824:
                unaff_s4 = (ASN1_ITEM *)&local_34;
                (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x78,uVar12,s_tasn_dec_c_0066ab2c);
LAB_00563968:
                ASN1_item_ex_free((ASN1_VALUE **)&local_3c,unaff_s8);
LAB_0056397c:
                unaff_s2 = &local_3c;
                (*(code *)PTR_ERR_add_error_data_006a9264)(2,s_Type__0066ab48,unaff_s8->sname);
              default:
switchD_005634b4_caseD_7:
                unaff_s0 = (ASN1_ITEM *)0x670000;
                pcVar14 = s_tasn_dec_c_0066ab2c;
                param_3 = (ASN1_ITEM *)&DAT_0000003a;
                in_stack_ffffff6b = -0x39;
                (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x83);
              }
              goto LAB_005639bc;
            }
LAB_00563584:
            unaff_s3 = local_res8[0];
            if (local_44 == '\0') goto LAB_00563500;
            param_3 = (ASN1_ITEM *)&DAT_00000089;
            in_stack_ffffff6b = -0x2b;
            unaff_s0 = local_40;
          }
          goto LAB_00563afc;
        }
      }
    }
  }
LAB_005639d4:
  if (local_2c == *(ASN1_ITEM **)puVar3) {
    return uVar5;
  }
  pcStack_ac = asn1_template_ex_d2i;
  pAVar18 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_130 = PTR___stack_chk_guard_006aabf0;
  AStack_dc.size = (long)unaff_s2;
  pAStack_b8 = unaff_s6;
  pAStack_1a0 = (ASN1_ITEM *)(int)in_stack_ffffff6b;
  AStack_dc.tcount = (long)unaff_s0;
  pAStack_b0 = unaff_s8;
  pAStack_b4 = unaff_s7;
  pAStack_bc = unaff_s5;
  pAStack_c0 = unaff_s4;
  AStack_dc.sname = &unaff_s3->itype;
  AStack_dc.funcs = param_4;
  AStack_dc.templates = (ASN1_TEMPLATE *)*(ASN1_ITEM **)PTR___stack_chk_guard_006aabf0;
  pAVar9 = pAStack_224;
  pcVar15 = pcVar14;
  if (pAVar18 == (ASN1_ITEM *)0x0) {
    uVar5 = 0;
    pAVar11 = param_3;
  }
  else {
    unaff_s8 = *(ASN1_ITEM **)pcVar14;
    param_4 = *(ASN1_ITEM **)pAStack_224;
    pAStack_e8 = param_4;
    unaff_s3 = (ASN1_ITEM *)pcVar14;
    if (((uint)unaff_s8 & 0x10) == 0) {
      uVar5 = asn1_template_noexp_d2i();
      pAVar11 = param_3;
    }
    else {
      pcVar16 = *(char **)((int)pcVar14 + 4);
      unaff_s4 = pAVar18;
      unaff_s7 = param_3;
      AStack_dc.utype = (long)param_4;
      if (in_stack_ffffff6c == (ASN1_ITEM *)0x0) {
        pcVar15 = auStack_e4 + 4;
        pAVar11 = (ASN1_ITEM *)auStack_e4;
        pAVar9 = &AStack_dc;
        uVar5 = ASN1_get_object((uchar **)((int)&AStack_dc + 4),(long *)pAVar9,(int *)pAVar11,
                                (int *)pcVar15,(long)param_3);
        if ((uVar5 & 0x80) == 0) {
LAB_0056403c:
          pAVar10 = (ASN1_ITEM *)AStack_dc.utype;
          if (-1 < (int)pcVar16) {
            if ((pcVar16 != auStack_e4._0_4_) ||
               (unaff_s8 = (ASN1_ITEM *)((uint)unaff_s8 & 0xc0), unaff_s8 != auStack_e4._4_4_)) {
              uVar5 = 0xffffffff;
              if (pAStack_1a0 != (ASN1_ITEM *)0x0) goto LAB_005640c0;
              if (in_stack_ffffff6c != (ASN1_ITEM *)0x0) {
                in_stack_ffffff6c->itype = '\0';
              }
              uVar12 = 0xa8;
              goto LAB_00564070;
            }
            if (in_stack_ffffff6c != (ASN1_ITEM *)0x0) {
              in_stack_ffffff6c->itype = '\0';
            }
          }
          unaff_s7 = AStack_dc._0_4_;
          if ((uVar5 & 1) != 0) {
            unaff_s7 = (ASN1_ITEM *)((int)param_3 - (AStack_dc.utype - (int)param_4));
          }
          param_4 = (ASN1_ITEM *)(int)(char)uVar5;
          pAStack_e8 = (ASN1_ITEM *)AStack_dc.utype;
          if (((uint)param_4 & 0x20) == 0) {
            pAVar11 = (ASN1_ITEM *)&DAT_00000078;
          }
          else {
            pAVar9 = (ASN1_ITEM *)&pAStack_e8;
            pAVar11 = unaff_s7;
            pcVar15 = pcVar14;
            iVar6 = asn1_template_noexp_d2i(pAVar18);
            if (iVar6 != 0) {
              pAStack_1a0 = (ASN1_ITEM *)((int)pAStack_e8 - (int)pAVar10);
              unaff_s7 = (ASN1_ITEM *)((int)unaff_s7 - (int)pAStack_1a0);
              if (((uint)param_4 & 1) == 0) {
                pAVar10 = pAStack_e8;
                if (unaff_s7 != (ASN1_ITEM *)0x0) {
                  pAVar11 = (ASN1_ITEM *)&DAT_00000077;
                  goto LAB_005642ac;
                }
              }
              else {
                unaff_s7 = (ASN1_ITEM *)(uint)((int)unaff_s7 < 2);
                if (((unaff_s7 != (ASN1_ITEM *)0x0) || (pAStack_e8->itype != '\0')) ||
                   (pAVar10 = (ASN1_ITEM *)&pAStack_e8->field_0x2, pAStack_e8->field_0x1 != '\0')) {
                  pAVar11 = (ASN1_ITEM *)&DAT_00000089;
LAB_005642ac:
                  pcVar15 = s_tasn_dec_c_0066ab2c;
                  (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x84);
                  pAVar9 = (ASN1_ITEM *)pcVar14;
                  ASN1_template_free((ASN1_VALUE **)pAVar18,(ASN1_TEMPLATE *)pcVar14);
                  uVar5 = 0;
                  goto LAB_005640c0;
                }
              }
              *(ASN1_ITEM **)pAStack_224 = pAVar10;
              uVar5 = 1;
              goto LAB_005640c0;
            }
            pAVar11 = (ASN1_ITEM *)&DAT_0000003a;
          }
          pcVar15 = s_tasn_dec_c_0066ab2c;
          pAVar9 = (ASN1_ITEM *)&DAT_00000084;
          (*(code *)PTR_ERR_put_error_006a9030)(0xd);
          uVar5 = 0;
          pAStack_1a0 = pAVar10;
          goto LAB_005640c0;
        }
        uVar12 = 0x66;
LAB_00564070:
        (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x68,uVar12,s_tasn_dec_c_0066ab2c);
      }
      else {
        if (in_stack_ffffff6c->itype == '\0') {
          pcVar15 = auStack_e4 + 4;
          uVar5 = ASN1_get_object((uchar **)((int)&AStack_dc + 4),(long *)&AStack_dc,
                                  (int *)auStack_e4,(int *)pcVar15,(long)param_3);
          pAVar9 = (ASN1_ITEM *)(uVar5 & 0x81);
          in_stack_ffffff6c->funcs = auStack_e4._4_4_;
          in_stack_ffffff6c->utype = uVar5;
          in_stack_ffffff6c->templates = (ASN1_TEMPLATE *)AStack_dc._0_4_;
          in_stack_ffffff6c->tcount = (long)auStack_e4._0_4_;
          pAVar11 = (ASN1_ITEM *)0x1;
          in_stack_ffffff6c->size = AStack_dc.utype - (int)param_4;
          in_stack_ffffff6c->itype = '\x01';
          if ((pAVar9 != (ASN1_ITEM *)0x0) ||
             ((int)((int)AStack_dc._0_4_ + (AStack_dc.utype - (int)param_4)) <= (int)param_3))
          goto LAB_00564034;
          uVar12 = 0x9b;
        }
        else {
          pAVar11 = (ASN1_ITEM *)in_stack_ffffff6c->templates;
          pAVar9 = (ASN1_ITEM *)in_stack_ffffff6c->funcs;
          auStack_e4._0_4_ = (char *)in_stack_ffffff6c->tcount;
          AStack_dc.utype = in_stack_ffffff6c->size + (int)&param_4->itype;
          uVar5 = in_stack_ffffff6c->utype;
          auStack_e4._4_4_ = pAVar9;
          AStack_dc._0_4_ = pAVar11;
LAB_00564034:
          if ((uVar5 & 0x80) == 0) goto LAB_0056403c;
          uVar12 = 0x66;
        }
        (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x68,uVar12,s_tasn_dec_c_0066ab2c);
        in_stack_ffffff6c->itype = '\0';
      }
      param_4 = (ASN1_ITEM *)0x670000;
      pcVar15 = s_tasn_dec_c_0066ab2c;
      pAVar11 = (ASN1_ITEM *)&DAT_0000003a;
      pAVar9 = (ASN1_ITEM *)&DAT_00000084;
      (*(code *)PTR_ERR_put_error_006a9030)(0xd);
      uVar5 = 0;
    }
  }
LAB_005640c0:
  if ((ASN1_ITEM *)AStack_dc.templates == *(ASN1_ITEM **)puStack_130) {
    return uVar5;
  }
  pcStack_114 = ASN1_item_ex_d2i;
  pAVar18 = (ASN1_ITEM *)AStack_dc.templates;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_1b4 = PTR___stack_chk_guard_006aabf0;
  pAStack_134 = param_4;
  pAStack_11c = unaff_s7;
  pAStack_118 = unaff_s8;
  pAStack_120 = pAStack_1a0;
  pAStack_124 = pAStack_224;
  pAStack_128 = unaff_s4;
  pAStack_12c = unaff_s3;
  pAStack_138 = in_stack_ffffff6c;
  puStack_160 = &_gp;
  pAStack_108 = pAVar11;
  uStack_144 = 0;
  pAVar10 = *(ASN1_ITEM **)PTR___stack_chk_guard_006aabf0;
  pAStack_1b0 = *(ASN1_ITEM_EXP **)((int)pcVar15 + 0x10);
  pAStack_13c = pAVar10;
  if (pAVar18 != (ASN1_ITEM *)0x0) {
    if (pAStack_1b0 == (ASN1_ITEM_EXP *)0x0) {
      bVar1 = *(byte *)(ulong *)pcVar15;
      pvStack_154 = (void *)0x0;
    }
    else {
      pvStack_154 = pAStack_1b0->funcs;
      bVar1 = *(byte *)(ulong *)pcVar15;
    }
    in_stack_ffffff6c = pAVar18;
    unaff_s4 = pAVar9;
    unaff_s8 = (ASN1_ITEM *)pcVar15;
    if (bVar1 < 7) {
                    /* WARNING: Could not recover jumptable at 0x00564400. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar5 = (*(code *)(&PTR_LAB_0066ab88)[bVar1])();
      return uVar5;
    }
  }
  if (pAVar10 == *(ASN1_ITEM **)PTR___stack_chk_guard_006aabf0) {
    return 0;
  }
  pcStack_194 = ASN1_template_d2i;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_234 = PTR___stack_chk_guard_006aabf0;
  pAStack_198 = unaff_s8;
  uStack_19c = 0xffffffe0;
  pAStack_1a4 = pAStack_224;
  pAStack_1a8 = unaff_s4;
  pAStack_1ac = unaff_s3;
  pAStack_1b8 = in_stack_ffffff6c;
  uStack_1d4 = 0;
  pAStack_1bc = *(ASN1_ITEM **)PTR___stack_chk_guard_006aabf0;
  uStack_230 = 0;
  pcVar14 = &pAVar9->itype;
  pcVar16 = pcVar15;
  pAStack_220 = pAStack_1a0;
  pAStack_21c = (ASN1_ITEM *)0xffffffe0;
  if (pAVar10 != (ASN1_ITEM *)0x0) {
    pAStack_224 = *(ASN1_ITEM **)pcVar15;
    in_stack_ffffff6c = *(ASN1_ITEM **)pAVar9;
    pAStack_1e8 = in_stack_ffffff6c;
    unaff_s3 = (ASN1_ITEM *)pcVar15;
    pAStack_220 = pAVar9;
    if (((uint)pAStack_224 & 0x10) == 0) {
      uStack_230 = asn1_template_noexp_d2i();
    }
    else {
      iVar6 = *(long *)((int)pcVar15 + 4);
      pAStack_1d8 = in_stack_ffffff6c;
      pcStack_1d0 = (char *)ASN1_get_object((uchar **)&pAStack_1d8,(long *)&pAStack_1dc,&iStack_1e4,
                                            (int *)&pAStack_1e0,(long)pAVar11);
      pAVar18 = pAStack_1d8;
      iStack_1c0 = (int)pAStack_1d8 - (int)in_stack_ffffff6c;
      pAStack_1cc = pAStack_1dc;
      pAStack_1c4 = pAStack_1e0;
      iStack_1c8 = iStack_1e4;
      uStack_1d4 = 1;
      unaff_s4 = pAVar10;
      pAStack_21c = pAVar11;
      unaff_s8 = pAStack_1dc;
      if ((((uint)pcStack_1d0 & 0x81) == 0) && ((int)pAVar11 < (int)((int)pAStack_1dc + iStack_1c0))
         ) {
        uVar12 = 0x9b;
LAB_00564fdc:
        (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x68,uVar12,s_tasn_dec_c_0066ab2c);
        uStack_1d4 = 0;
      }
      else {
        uStack_230 = (uint)pcStack_1d0 & 0x80;
        if (uStack_230 != 0) {
          uVar12 = 0x66;
          goto LAB_00564fdc;
        }
        if (iVar6 < 0) {
LAB_00564f84:
          pAStack_224 = (ASN1_ITEM *)(int)(char)pcStack_1d0;
          pAStack_1e8 = pAStack_1d8;
          in_stack_ffffff6c = (ASN1_ITEM *)((int)pAVar11 - iStack_1c0);
          if (((uint)pcStack_1d0 & 1) != 0) {
            unaff_s8 = in_stack_ffffff6c;
          }
          if (((uint)pAStack_224 & 0x20) == 0) {
            pAVar11 = (ASN1_ITEM *)&DAT_00000078;
          }
          else {
            pcVar14 = (char *)&pAStack_1e8;
            pAVar11 = unaff_s8;
            iVar6 = asn1_template_noexp_d2i(pAVar10);
            if (iVar6 != 0) {
              pAStack_224 = (ASN1_ITEM *)((uint)pAStack_224 & 1);
              unaff_s8 = (ASN1_ITEM *)((int)unaff_s8 - ((int)pAStack_1e8 - (int)pAVar18));
              if (pAStack_224 == (ASN1_ITEM *)0x0) {
                pAVar18 = pAStack_1e8;
                if (unaff_s8 != (ASN1_ITEM *)0x0) {
                  pAVar11 = (ASN1_ITEM *)&DAT_00000077;
                  goto LAB_0056508c;
                }
              }
              else {
                unaff_s8 = (ASN1_ITEM *)(uint)((int)unaff_s8 < 2);
                if (((unaff_s8 != (ASN1_ITEM *)0x0) || (pAStack_1e8->itype != '\0')) ||
                   (pAStack_1e8->field_0x1 != '\0')) {
                  pAVar11 = (ASN1_ITEM *)&DAT_00000089;
LAB_0056508c:
                  pcVar16 = s_tasn_dec_c_0066ab2c;
                  (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x84);
                  pcVar14 = pcVar15;
                  ASN1_template_free((ASN1_VALUE **)pAVar10,(ASN1_TEMPLATE *)pcVar15);
                  goto LAB_00564e40;
                }
                pAVar18 = (ASN1_ITEM *)&pAStack_1e8->field_0x2;
              }
              *(ASN1_ITEM **)pAVar9 = pAVar18;
              uStack_230 = 1;
              goto LAB_00564e40;
            }
            pAVar11 = (ASN1_ITEM *)&DAT_0000003a;
          }
          pcVar16 = s_tasn_dec_c_0066ab2c;
          pcVar14 = &DAT_00000084;
          (*(code *)PTR_ERR_put_error_006a9030)(0xd);
          goto LAB_00564e40;
        }
        if ((iVar6 == iStack_1e4) &&
           (pAStack_224 = (ASN1_ITEM *)((uint)pAStack_224 & 0xc0), pAStack_224 == pAStack_1e0)) {
          uStack_1d4 = 0;
          goto LAB_00564f84;
        }
        uStack_1d4 = 0;
        (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x68,0xa8,s_tasn_dec_c_0066ab2c);
      }
      in_stack_ffffff6c = (ASN1_ITEM *)0x670000;
      pcVar16 = s_tasn_dec_c_0066ab2c;
      pAVar11 = (ASN1_ITEM *)&DAT_0000003a;
      pcVar14 = &DAT_00000084;
      uStack_230 = 0;
      (*(code *)PTR_ERR_put_error_006a9030)(0xd);
    }
  }
LAB_00564e40:
  if (pAStack_1bc == *(ASN1_ITEM **)puStack_234) {
    return uStack_230;
  }
  pcStack_214 = ASN1_item_d2i;
  pAVar18 = pAStack_1bc;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar3 = PTR___stack_chk_guard_006aabf0;
  pvVar17 = *(void **)((int)pcVar16 + 0x10);
  pAStack_238 = in_stack_ffffff6c;
  pAStack_218 = unaff_s8;
  pAStack_228 = unaff_s4;
  pAStack_22c = unaff_s3;
  auStack_264 = (undefined  [4])0x0;
  auStack_254[0] = 0;
  pAStack_260 = pAVar11;
  pAStack_25c = (ASN1_TEMPLATE *)0x0;
  pAVar9 = (ASN1_ITEM *)auStack_264;
  if (pAVar18 != (ASN1_ITEM *)0x0) {
    pAVar9 = pAVar18;
  }
  piStack_23c = *(int **)PTR___stack_chk_guard_006aabf0;
  if (pvVar17 == (void *)0x0) {
    switch(*pcVar16) {
    case '\0':
      goto switchD_00565630_caseD_0;
    case '\x01':
    case '\x06':
      pcStack_278 = (code *)0x0;
      goto switchD_005651a0_caseD_1;
    case '\x02':
      pcStack_278 = (code *)0x0;
LAB_005651ac:
      if ((*(int *)pAVar9 == 0) &&
         (iVar6 = ASN1_item_ex_new((ASN1_VALUE **)pAVar9,(ASN1_ITEM *)pcVar16), iVar6 == 0)) {
        uVar13 = 0x3a;
        uVar12 = 0x13e;
        goto LAB_00565288;
      }
      pAStack_25c = *(ASN1_TEMPLATE **)pcVar14;
      pAVar18 = (ASN1_ITEM *)0x0;
      pAVar11 = *(ASN1_ITEM **)((int)pcVar16 + 0xc);
      tt = *(ASN1_TEMPLATE **)((int)pcVar16 + 8);
      if ((int)pAVar11 < 1) {
LAB_00565228:
        if (pAVar18 == pAVar11) {
LAB_0056566c:
          uVar13 = 0x8f;
          uVar12 = 0x162;
          goto LAB_00565288;
        }
      }
      else {
        do {
          ppAVar8 = asn1_get_field_ptr((ASN1_VALUE **)pAVar9,tt);
          iVar6 = asn1_template_ex_d2i(ppAVar8,auStack_264 + 8,pAStack_260,tt,1,auStack_254);
          if (iVar6 != -1) {
            if (0 < iVar6) {
              pAVar11 = *(ASN1_ITEM **)((int)pcVar16 + 0xc);
              goto LAB_00565228;
            }
            (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x78,0x3a,s_tasn_dec_c_0066ab2c,0x153);
            ASN1_item_ex_free((ASN1_VALUE **)pAVar9,(ASN1_ITEM *)pcVar16);
            if (tt != (ASN1_TEMPLATE *)0x0) goto LAB_005657fc;
            goto LAB_005652b4;
          }
          pAVar18 = (ASN1_ITEM *)&pAVar18->field_0x1;
          tt = tt + 1;
        } while ((int)pAVar18 < (int)*(undefined **)((int)pcVar16 + 0xc));
        if (pAVar18 == (ASN1_ITEM *)*(undefined **)((int)pcVar16 + 0xc)) goto LAB_0056566c;
      }
      asn1_set_choice_selector((ASN1_VALUE **)pAVar9,(int)pAVar18,(ASN1_ITEM *)pcVar16);
      *(ASN1_TEMPLATE **)pcVar14 = pAStack_25c;
      if (pcStack_278 == (code *)0x0) goto LAB_00565328;
      goto LAB_00565258;
    case '\x03':
      goto switchD_00565630_caseD_3;
    case '\x04':
      pcStack_278 = *(code **)(in_zero + 0x10);
      goto LAB_005655ac;
    case '\x05':
      goto switchD_00565630_caseD_5;
    }
    goto switchD_00565630_caseD_7;
  }
  pcStack_278 = *(code **)((int)pvVar17 + 0x10);
  switch(*pcVar16) {
  case '\0':
switchD_00565630_caseD_0:
    if (*(ASN1_TEMPLATE **)((int)pcVar16 + 8) == (ASN1_TEMPLATE *)0x0) {
      iVar6 = asn1_d2i_ex_primitive(pAVar9,pcVar14,pAVar11,pcVar16,0xffffffff,0,0,auStack_254);
      if (iVar6 < 1) {
        uVar5 = 0;
        pAVar18 = (ASN1_ITEM *)pcVar14;
        goto LAB_005652d0;
      }
    }
    else {
      iVar6 = asn1_template_ex_d2i
                        (pAVar9,pcVar14,pAVar11,*(ASN1_TEMPLATE **)((int)pcVar16 + 8),0,auStack_254)
      ;
      if (iVar6 < 1) goto switchD_00565630_caseD_7;
    }
    goto LAB_005653f0;
  case '\x01':
  case '\x06':
switchD_005651a0_caseD_1:
    pAStack_25c = *(ASN1_TEMPLATE **)pcVar14;
    pAVar18 = (ASN1_ITEM *)0x0;
    iVar6 = asn1_check_tlen(auStack_264 + 4,0,0,&cStack_266,&cStack_265,auStack_264 + 8,pAVar11,0x10
                            ,0,0,auStack_254);
    if (iVar6 == 0) {
      uVar13 = 0x3a;
      uVar12 = 0x17d;
    }
    else {
      uVar5 = 0;
      if (iVar6 == -1) goto LAB_005652d0;
      cVar2 = cStack_266;
      if ((pvVar17 != (void *)0x0) && ((*(uint *)((int)pvVar17 + 4) & 4) != 0)) {
        pAStack_260 = (ASN1_ITEM *)((int)pAVar11 - ((int)pAStack_25c - (int)*(char **)pcVar14));
        cVar2 = '\x01';
      }
      if (cStack_265 == '\0') {
        uVar13 = 0x95;
        uVar12 = 0x18c;
      }
      else if ((*(int *)pAVar9 == 0) &&
              (iVar6 = ASN1_item_ex_new((ASN1_VALUE **)pAVar9,(ASN1_ITEM *)pcVar16), iVar6 == 0)) {
        uVar13 = 0x3a;
        uVar12 = 0x193;
      }
      else {
        puStack_270 = auStack_254;
        if ((pcStack_278 != (code *)0x0) && (iVar6 = (*pcStack_278)(4,pAVar9,pcVar16,0), iVar6 == 0)
           ) goto LAB_00565278;
        iVar6 = 0;
        tt_00 = *(ASN1_TEMPLATE **)((int)pcVar16 + 8);
        if (0 < *(long *)((int)pcVar16 + 0xc)) {
          do {
            tt = asn1_do_adb((ASN1_VALUE **)pAVar9,tt_00,1);
            if (tt == (ASN1_TEMPLATE *)0x0) goto LAB_0056529c;
            ppAVar8 = asn1_get_field_ptr((ASN1_VALUE **)pAVar9,tt);
            pAVar4 = pAStack_25c;
            if (pAStack_260 == (ASN1_ITEM *)0x0) {
              if (cStack_266 == '\0') goto LAB_00565740;
              goto LAB_00565908;
            }
            if (((1 < (int)pAStack_260) && (*(char *)&pAStack_25c->flags == '\0')) &&
               (*(char *)((int)&pAStack_25c->flags + 1) == '\0')) {
              pAStack_25c = (ASN1_TEMPLATE *)((int)&pAStack_25c->flags + 2);
              if (cStack_266 == '\0') {
                uVar13 = 0x9f;
                uVar12 = 0x1ac;
                goto LAB_00565288;
              }
              cStack_266 = '\0';
              pAStack_260 = (ASN1_ITEM *)((int)&pAStack_260[-1].sname + 2);
              goto LAB_0056572c;
            }
            uVar5 = 0;
            if (iVar6 != *(long *)((int)pcVar16 + 0xc) + -1) {
              uVar5 = tt->flags & 1;
            }
            iVar7 = asn1_template_ex_d2i(ppAVar8,auStack_264 + 8,pAStack_260,tt,uVar5,puStack_270);
            if (iVar7 == 0) goto LAB_005657e8;
            if (iVar7 == -1) {
              ASN1_template_free(ppAVar8,tt);
            }
            else {
              pAStack_260 = (ASN1_ITEM *)((int)pAStack_260 - ((int)pAStack_25c - (int)pAVar4));
            }
            iVar6 = iVar6 + 1;
            tt_00 = tt_00 + 1;
          } while (iVar6 < *(long *)((int)pcVar16 + 0xc));
        }
        if (cStack_266 != '\0') {
          if ((((int)pAStack_260 < 2) || (*(char *)&pAStack_25c->flags != '\0')) ||
             (*(char *)((int)&pAStack_25c->flags + 1) != '\0')) {
LAB_00565908:
            uVar13 = 0x89;
            uVar12 = 0x1d6;
            break;
          }
          pAStack_25c = (ASN1_TEMPLATE *)((int)&pAStack_25c->flags + 2);
        }
LAB_0056572c:
        if ((cVar2 != '\0') || (pAStack_260 == (ASN1_ITEM *)0x0)) {
LAB_00565740:
          if (iVar6 < *(long *)((int)pcVar16 + 0xc)) {
LAB_00565794:
            tt = asn1_do_adb((ASN1_VALUE **)pAVar9,tt_00,1);
            if (tt != (ASN1_TEMPLATE *)0x0) {
              if ((tt->flags & 1) != 0) goto LAB_00565758;
              (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x78,0x79,s_tasn_dec_c_0066ab2c,0x1f5);
LAB_005657e8:
              ASN1_item_ex_free((ASN1_VALUE **)pAVar9,(ASN1_ITEM *)pcVar16);
LAB_005657fc:
              pcVar14 = &DAT_0066ab40;
              (*(code *)PTR_ERR_add_error_data_006a9264)
                        (4,&DAT_0066ab40,tt->field_name,", Type=",*(char **)((int)pcVar16 + 0x18));
              goto switchD_00565630_caseD_7;
            }
            goto LAB_0056529c;
          }
          pAVar18 = *(ASN1_ITEM **)pcVar14;
          goto LAB_00565954;
        }
        uVar13 = 0x94;
        uVar12 = 0x1dd;
      }
    }
    break;
  case '\x02':
    if ((pcStack_278 == (code *)0x0) || (iVar6 = (*pcStack_278)(4,pAVar9,pcVar16,0), iVar6 != 0))
    goto LAB_005651ac;
    goto LAB_00565278;
  case '\x03':
switchD_00565630_caseD_3:
    iVar6 = (**(code **)((int)pvVar17 + 8))(pAVar9,pcVar14,pAVar11);
    pAVar18 = (ASN1_ITEM *)pcVar14;
    if (iVar6 != 0) goto LAB_00565328;
    uVar13 = 0x3a;
    uVar12 = 0x132;
    break;
  case '\x04':
LAB_005655ac:
    iVar6 = (*pcStack_278)(pAVar9,pcVar14,pAVar11,pcVar16,0xffffffff,0,0,auStack_254);
    if (iVar6 < 1) {
      uVar5 = 0;
      pAVar18 = (ASN1_ITEM *)pcVar14;
      goto LAB_005652d0;
    }
LAB_005653f0:
    uVar5 = *(uint *)pAVar9;
    pAVar18 = (ASN1_ITEM *)pcVar14;
    goto LAB_005652d0;
  case '\x05':
switchD_00565630_caseD_5:
    pAStack_25c = *(ASN1_TEMPLATE **)pcVar14;
    iVar6 = asn1_check_tlen_constprop_1
                      (0,auStack_264 + 0xc,&cStack_267,0,0,auStack_264 + 8,pAVar11,1,auStack_254);
    if (iVar6 == 0) {
      uVar13 = 0x3a;
      uVar12 = 0xd2;
    }
    else if (cStack_267 == '\0') {
      if ((uStack_258 < 0x1f) &&
         ((*(uint *)(tag2bit + uStack_258 * 4) & *(long *)((int)pcVar16 + 4)) != 0)) {
        iVar6 = asn1_d2i_ex_primitive(pAVar9,pcVar14,pAStack_260,pcVar16,uStack_258,0,0,auStack_254)
        ;
        if (iVar6 < 1) {
          uVar5 = 0;
          pAVar18 = (ASN1_ITEM *)pcVar14;
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
  ASN1_item_ex_free((ASN1_VALUE **)pAVar9,(ASN1_ITEM *)pcVar16);
LAB_005652b4:
  pcVar14 = s_Type__0066ab48;
  (*(code *)PTR_ERR_add_error_data_006a9264)(2,s_Type__0066ab48,*(char **)((int)pcVar16 + 0x18));
switchD_00565630_caseD_7:
  uVar5 = 0;
  pAVar18 = (ASN1_ITEM *)pcVar14;
LAB_005652d0:
  if (piStack_23c != *(int **)puVar3) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    return *(uint *)(pAVar18->utype + *piStack_23c);
  }
  return uVar5;
code_r0x00563c90:
  unaff_s3 = (ASN1_ITEM *)&unaff_s3->field_0x1;
  ppAVar8 = asn1_get_field_ptr((ASN1_VALUE **)unaff_s2,(ASN1_TEMPLATE *)unaff_s7);
  unaff_s5 = unaff_s5 + 1;
  ASN1_template_free(ppAVar8,(ASN1_TEMPLATE *)unaff_s7);
  if (unaff_s8->tcount <= (int)unaff_s3) goto LAB_00563eac;
  goto LAB_00563ccc;
code_r0x00563578:
  if ((int)local_res8[0] < 1) goto LAB_00563584;
  goto LAB_0056345c;
LAB_00565758:
  iVar6 = iVar6 + 1;
  ppAVar8 = asn1_get_field_ptr((ASN1_VALUE **)pAVar9,tt);
  tt_00 = tt_00 + 1;
  ASN1_template_free(ppAVar8,tt);
  if (*(long *)((int)pcVar16 + 0xc) <= iVar6) goto LAB_00565950;
  goto LAB_00565794;
LAB_00565950:
  pAVar18 = *(ASN1_ITEM **)pcVar14;
LAB_00565954:
  iVar6 = asn1_enc_save((ASN1_VALUE **)pAVar9,(uchar *)pAVar18,(int)pAStack_25c - (int)pAVar18,
                        (ASN1_ITEM *)pcVar16);
  if (iVar6 != 0) {
    *(ASN1_TEMPLATE **)pcVar14 = pAStack_25c;
    if (pcStack_278 == (code *)0x0) {
      uVar5 = *(uint *)pAVar9;
      goto LAB_005652d0;
    }
LAB_00565258:
    pAVar18 = pAVar9;
    iVar6 = (*pcStack_278)(5,pAVar9,pcVar16,0);
    if (iVar6 != 0) {
LAB_00565328:
      uVar5 = *(uint *)pAVar9;
      goto LAB_005652d0;
    }
  }
LAB_00565278:
  uVar13 = 100;
  uVar12 = 0x205;
  goto LAB_00565288;
}

