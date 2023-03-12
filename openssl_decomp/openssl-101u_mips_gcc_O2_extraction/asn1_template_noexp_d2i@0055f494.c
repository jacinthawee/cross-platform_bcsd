
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
  ASN1_TEMPLATE *pAVar11;
  ASN1_ITEM *pAVar12;
  ASN1_ITEM *pAVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  char *pcVar16;
  char *pcVar17;
  char *pcVar18;
  ASN1_ITEM *unaff_s0;
  ASN1_ITEM *unaff_s1;
  void *pvVar19;
  ASN1_TEMPLATE *tt;
  ASN1_ITEM *unaff_s2;
  ASN1_ITEM *unaff_s3;
  void *unaff_s5;
  ASN1_ITEM *unaff_s6;
  ASN1_ITEM *unaff_s7;
  ASN1_ITEM *unaff_s8;
  ASN1_ITEM *local_res8 [2];
  code *pcStack_280;
  undefined *puStack_278;
  char cStack_26f;
  char cStack_26e;
  char cStack_26d;
  undefined auStack_26c [4];
  ASN1_ITEM *pAStack_268;
  ASN1_TEMPLATE *pAStack_264;
  uint uStack_260;
  undefined auStack_25c [24];
  int *piStack_244;
  ASN1_ITEM *pAStack_240;
  undefined *puStack_23c;
  uint uStack_238;
  ASN1_ITEM *pAStack_234;
  ASN1_ITEM *pAStack_230;
  ASN1_ITEM *pAStack_22c;
  ASN1_ITEM *pAStack_228;
  ASN1_ITEM *pAStack_224;
  ASN1_ITEM *pAStack_220;
  code *pcStack_21c;
  ASN1_ITEM *pAStack_1f0;
  int iStack_1ec;
  ASN1_ITEM *pAStack_1e8;
  ASN1_ITEM *pAStack_1e4;
  ASN1_ITEM *pAStack_1e0;
  undefined uStack_1dc;
  char *pcStack_1d8;
  ASN1_ITEM *pAStack_1d4;
  int iStack_1d0;
  ASN1_ITEM *pAStack_1cc;
  int iStack_1c8;
  ASN1_ITEM *pAStack_1c4;
  ASN1_ITEM *pAStack_1c0;
  ASN1_ITEM_EXP *pAStack_1bc;
  undefined *puStack_1b8;
  ASN1_ITEM *pAStack_1b4;
  ASN1_ITEM *pAStack_1b0;
  ASN1_ITEM *pAStack_1ac;
  ASN1_ITEM *pAStack_1a8;
  ASN1_ITEM *pAStack_1a4;
  undefined4 uStack_1a0;
  code *pcStack_19c;
  undefined *puStack_168;
  uint uStack_158;
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
  ASN1_ITEM *pAStack_fc;
  ASN1_ITEM *pAStack_e8;
  undefined auStack_e4 [8];
  ASN1_ITEM AStack_dc;
  ASN1_ITEM *pAStack_c0;
  void *pvStack_bc;
  ASN1_ITEM *pAStack_b8;
  ASN1_ITEM *pAStack_b4;
  ASN1_ITEM *pAStack_b0;
  code *pcStack_ac;
  char in_stack_ffffff6b;
  ASN1_VALUE *pAVar20;
  ASN1_ITEM *in_stack_ffffff6c;
  code *local_68;
  undefined local_44;
  char local_43;
  char local_42;
  ASN1_VALUE local_41;
  ASN1_ITEM *local_40;
  ASN1_ITEM *local_3c;
  ASN1_ITEM *local_38;
  ASN1_ITEM *local_34;
  ASN1_VALUE *local_30;
  ASN1_ITEM *local_2c;
  
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(ASN1_ITEM **)PTR___stack_chk_guard_006a9ae8;
  local_res8[0] = param_3;
  if (param_1 == (ASN1_ITEM **)0x0) {
    uVar5 = 0;
    pAStack_124 = param_2;
    pcVar16 = &param_4->itype;
  }
  else {
    uVar5 = *(uint *)param_4;
    local_40 = *(ASN1_ITEM **)param_2;
    in_stack_ffffff6c = (ASN1_ITEM *)(uVar5 & 0xc0);
    if ((uVar5 & 6) == 0) {
      unaff_s0 = (ASN1_ITEM *)0xffffffff;
      if ((uVar5 & 8) == 0) {
        pcVar16 = (char *)param_4->funcs;
        in_stack_ffffff6c = (ASN1_ITEM *)(uVar5 & 0x400);
        pAStack_124 = (ASN1_ITEM *)&local_40;
        in_stack_ffffff6b = -1;
        iVar6 = ASN1_item_ex_d2i((ASN1_VALUE **)param_1,(uchar **)pAStack_124,(long)param_3,
                                 (ASN1_ITEM *)pcVar16,-1,(int)in_stack_ffffff6c,param_5,
                                 (ASN1_TLC *)param_6);
        if (iVar6 != 0) goto joined_r0x0055fcbc;
        param_3 = (ASN1_ITEM *)&DAT_0000003a;
        in_stack_ffffff6b = -0x47;
      }
      else {
        iVar7 = param_4->utype;
        pAStack_124 = (ASN1_ITEM *)&local_40;
        pcVar16 = (char *)param_4->funcs;
        iVar6 = ASN1_item_ex_d2i((ASN1_VALUE **)param_1,(uchar **)pAStack_124,(long)param_3,
                                 (ASN1_ITEM *)pcVar16,iVar7,(int)in_stack_ffffff6c,param_5,
                                 (ASN1_TLC *)param_6);
        in_stack_ffffff6b = (char)iVar7;
        if (iVar6 != 0) {
joined_r0x0055fcbc:
          if (iVar6 == -1) {
            uVar5 = 0xffffffff;
          }
          else {
LAB_0055f69c:
            *(ASN1_ITEM **)param_2 = local_40;
            uVar5 = 1;
            unaff_s2 = local_40;
          }
          goto LAB_0055fc10;
        }
        param_3 = (ASN1_ITEM *)&DAT_0000003a;
        in_stack_ffffff6b = -0x50;
      }
LAB_0055fd3c:
      pcVar16 = s_tasn_dec_c_0066a0bc;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x83);
LAB_0055fbf8:
      pAStack_124 = param_4;
      ASN1_template_free((ASN1_VALUE **)param_1,(ASN1_TEMPLATE *)param_4);
      uVar5 = 0;
    }
    else {
      unaff_s7 = (ASN1_ITEM *)&local_40;
      pcVar16 = &local_44;
      param_3 = (ASN1_ITEM *)0x0;
      pAStack_124 = (ASN1_ITEM *)0x0;
      pAVar20 = (ASN1_VALUE *)0x0;
      in_stack_ffffff6c = unaff_s7;
      iVar6 = asn1_check_tlen(local_res8);
      in_stack_ffffff6b = (char)pAVar20;
      if (iVar6 == 0) {
        param_3 = (ASN1_ITEM *)&DAT_0000003a;
        pcVar16 = s_tasn_dec_c_0066a0bc;
        in_stack_ffffff6b = 's';
        pAStack_124 = (ASN1_ITEM *)0x83;
        (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
        uVar5 = 0;
      }
      else {
        uVar5 = 0xffffffff;
        if (iVar6 != -1) {
          unaff_s0 = *param_1;
          if (unaff_s0 == (ASN1_ITEM *)0x0) {
            pAVar9 = (ASN1_ITEM *)(*(code *)PTR_sk_new_null_006a6fa4)();
            *param_1 = pAVar9;
          }
          else {
            while (iVar6 = (*(code *)PTR_sk_num_006a6e2c)(unaff_s0), 0 < iVar6) {
              local_30 = (ASN1_VALUE *)(*(code *)PTR_sk_pop_006a8da4)(unaff_s0);
              pAStack_124 = (ASN1_ITEM *)param_4->funcs;
              ASN1_item_ex_free(&local_30,pAStack_124);
            }
            pAVar9 = *param_1;
          }
          in_stack_ffffff6b = (char)pAVar20;
          pAVar13 = local_res8[0];
          pAVar12 = local_40;
          if (pAVar9 == (ASN1_ITEM *)0x0) {
            param_3 = (ASN1_ITEM *)&DAT_00000041;
            in_stack_ffffff6b = -0x7a;
            unaff_s1 = local_res8[0];
          }
          else {
            do {
              unaff_s1 = pAVar13;
              local_res8[0] = unaff_s1;
              local_40 = pAVar12;
              if ((int)unaff_s1 < 1) {
                pcVar16 = "encrypt";
                if (local_44 == '\0') goto LAB_0055f69c;
                param_3 = (ASN1_ITEM *)&DAT_00000089;
                in_stack_ffffff6b = -0x59;
                goto LAB_0055fd3c;
              }
              in_stack_ffffff6b = (char)pAVar20;
              if (((unaff_s1 != (ASN1_ITEM *)0x1) && (pAVar12->itype == '\0')) &&
                 (*(undefined *)((int)pAVar12 + 1) == '\0')) {
                unaff_s2 = (ASN1_ITEM *)((int)pAVar12 + 2);
                local_40 = (ASN1_ITEM *)(undefined *)unaff_s2;
                if (local_44 != '\0') goto LAB_0055f69c;
                param_3 = (ASN1_ITEM *)0x9f;
                in_stack_ffffff6b = -0x6e;
                local_40 = (ASN1_ITEM *)(undefined *)unaff_s2;
                goto LAB_0055fd3c;
              }
              unaff_s0 = (ASN1_ITEM *)param_4->funcs;
              local_3c = (ASN1_ITEM *)0x0;
              local_34 = (ASN1_ITEM *)0x0;
              unaff_s5 = unaff_s0->funcs;
              param_3 = unaff_s1;
              local_38 = unaff_s1;
              if (unaff_s5 == (void *)0x0) {
                switch(unaff_s0->itype) {
                case '\0':
                  goto switchD_0055fc6c_caseD_55f9b0;
                case '\x01':
                case '\x06':
                  local_68 = (code *)0x0;
                  goto switchD_0055f650_caseD_1;
                case '\x02':
                  local_68 = (code *)0x0;
                  goto LAB_0055fd74;
                case '\x03':
                  goto switchD_0055fc6c_caseD_55f740;
                case '\x04':
                  goto switchD_0055fc6c_caseD_55f6ac;
                case '\x05':
                  goto switchD_0055fc6c_caseD_55f9e4;
                }
                goto switchD_0055f650_caseD_7;
              }
              local_68 = *(code **)((int)unaff_s5 + 0x10);
              switch(unaff_s0->itype) {
              case '\0':
switchD_0055fc6c_caseD_55f9b0:
                pcVar16 = (char *)unaff_s0->templates;
                if ((ASN1_ITEM *)pcVar16 == (ASN1_ITEM *)0x0) {
                  in_stack_ffffff6c = (ASN1_ITEM *)0x0;
                  pAVar20 = (ASN1_VALUE *)0xffffffff;
                  pcVar16 = (char *)unaff_s0;
                  iVar6 = asn1_d2i_ex_primitive(&local_3c,unaff_s7);
                }
                else {
                  pAVar20 = (ASN1_VALUE *)0x0;
                  in_stack_ffffff6c = param_6;
                  iVar6 = asn1_template_ex_d2i(&local_3c,unaff_s7);
                }
                break;
              case '\x01':
              case '\x06':
switchD_0055f650_caseD_1:
                unaff_s6 = (ASN1_ITEM *)&local_34;
                pcVar16 = &local_42;
                param_3 = (ASN1_ITEM *)0x0;
                pAVar20 = &local_41;
                in_stack_ffffff6c = unaff_s6;
                local_34 = pAVar12;
                iVar6 = asn1_check_tlen(&local_38,0);
                if (iVar6 == 0) {
                  uVar14 = 0x3a;
                }
                else {
                  if (iVar6 == -1) goto LAB_0055f6e8;
                  cVar2 = local_42;
                  if ((unaff_s5 != (void *)0x0) && ((*(uint *)((int)unaff_s5 + 4) & 4) != 0)) {
                    local_38 = (ASN1_ITEM *)((int)unaff_s1 - ((int)local_34 - (int)local_40));
                    cVar2 = '\x01';
                  }
                  if (local_41 != (ASN1_VALUE)0x0) {
                    if ((local_3c == (ASN1_ITEM *)0x0) &&
                       (iVar6 = ASN1_item_ex_new((ASN1_VALUE **)&local_3c,unaff_s0), iVar6 == 0)) {
                      uVar14 = 0x3a;
                    }
                    else {
                      if ((local_68 != (code *)0x0) &&
                         (iVar6 = (*local_68)(4,&local_3c,unaff_s0,0), iVar6 == 0))
                      goto LAB_0055fb7c;
                      iVar6 = unaff_s0->tcount;
                      unaff_s5 = (void *)0x0;
                      unaff_s1 = (ASN1_ITEM *)unaff_s0->templates;
                      if (0 < iVar6) {
                        do {
                          while ((*(uint *)unaff_s1 & 0x300) != 0) {
                            unaff_s8 = (ASN1_ITEM *)
                                       asn1_do_adb((ASN1_VALUE **)&local_3c,
                                                   (ASN1_TEMPLATE *)unaff_s1,1);
                            unaff_s5 = (void *)((int)unaff_s5 + 1);
                            unaff_s1 = (ASN1_ITEM *)&unaff_s1->size;
                            ppAVar8 = asn1_get_field_ptr((ASN1_VALUE **)&local_3c,
                                                         (ASN1_TEMPLATE *)unaff_s8);
                            ASN1_template_free(ppAVar8,(ASN1_TEMPLATE *)unaff_s8);
                            iVar6 = unaff_s0->tcount;
                            if (iVar6 <= (int)unaff_s5) goto LAB_0055f8c0;
                          }
                          unaff_s5 = (void *)((int)unaff_s5 + 1);
                          unaff_s1 = (ASN1_ITEM *)&unaff_s1->size;
                        } while ((int)unaff_s5 < iVar6);
LAB_0055f8c0:
                        unaff_s1 = (ASN1_ITEM *)unaff_s0->templates;
                        unaff_s5 = (void *)0x0;
                        if (0 < iVar6) {
                          do {
                            unaff_s8 = (ASN1_ITEM *)
                                       asn1_do_adb((ASN1_VALUE **)&local_3c,
                                                   (ASN1_TEMPLATE *)unaff_s1,1);
                            if (unaff_s8 == (ASN1_ITEM *)0x0) goto LAB_0055fba4;
                            ppAVar8 = asn1_get_field_ptr((ASN1_VALUE **)&local_3c,
                                                         (ASN1_TEMPLATE *)unaff_s8);
                            pAVar9 = local_34;
                            if (local_38 == (ASN1_ITEM *)0x0) {
                              if (local_42 != '\0') goto LAB_005600d0;
                              goto LAB_0055fed8;
                            }
                            if (((1 < (int)local_38) && (local_34->itype == '\0')) &&
                               (local_34->field_0x1 == '\0')) {
                              local_34 = (ASN1_ITEM *)&local_34->field_0x2;
                              if (local_42 != '\0') {
                                local_38 = (ASN1_ITEM *)((int)&local_38[-1].sname + 2);
                                local_42 = '\0';
                                goto LAB_0055fec4;
                              }
                              uVar14 = 0x9f;
                              goto LAB_0055fb90;
                            }
                            pAVar20 = (ASN1_VALUE *)0x0;
                            if (unaff_s5 != (void *)(unaff_s0->tcount + -1)) {
                              pAVar20 = (ASN1_VALUE *)(*(uint *)unaff_s8 & 1);
                            }
                            in_stack_ffffff6c = param_6;
                            iVar6 = asn1_template_ex_d2i(ppAVar8,unaff_s6,local_38,unaff_s8);
                            if (iVar6 == 0) goto LAB_005600ec;
                            if (iVar6 == -1) {
                              ASN1_template_free(ppAVar8,(ASN1_TEMPLATE *)unaff_s8);
                            }
                            else {
                              local_38 = (ASN1_ITEM *)
                                         ((int)local_38 - ((int)local_34 - (int)pAVar9));
                            }
                            unaff_s5 = (void *)((int)unaff_s5 + 1);
                            unaff_s1 = (ASN1_ITEM *)&unaff_s1->size;
                          } while ((int)unaff_s5 < unaff_s0->tcount);
                        }
                      }
                      if (local_42 != '\0') {
                        if ((((int)local_38 < 2) || (local_34->itype != '\0')) ||
                           (local_34->field_0x1 != '\0')) {
LAB_005600d0:
                          uVar14 = 0x89;
                          goto LAB_0055fb90;
                        }
                        local_34 = (ASN1_ITEM *)&local_34->field_0x2;
                      }
LAB_0055fec4:
                      if ((cVar2 != '\0') || (local_38 == (ASN1_ITEM *)0x0)) {
LAB_0055fed8:
                        if ((int)unaff_s5 < unaff_s0->tcount) {
LAB_0055ff3c:
                          unaff_s8 = (ASN1_ITEM *)
                                     asn1_do_adb((ASN1_VALUE **)&local_3c,(ASN1_TEMPLATE *)unaff_s1,
                                                 1);
                          if (unaff_s8 != (ASN1_ITEM *)0x0) {
                            if ((*(uint *)unaff_s8 & 1) != 0) goto code_r0x0055ff00;
                            (*(code *)PTR_ERR_put_error_006a7f34)
                                      (0xd,0x78,0x79,s_tasn_dec_c_0066a0bc);
LAB_005600ec:
                            ASN1_item_ex_free((ASN1_VALUE **)&local_3c,unaff_s0);
LAB_00560054:
                            unaff_s6 = (ASN1_ITEM *)&local_34;
                            unaff_s3 = (ASN1_ITEM *)&local_3c;
                            (*(code *)PTR_ERR_add_error_data_006a813c)
                                      (4,&DAT_0066a0d0,(char *)unaff_s8->tcount,", Type=");
                            goto switchD_0055f650_caseD_7;
                          }
                          goto LAB_0055fba4;
                        }
LAB_0055fe40:
                        param_3 = (ASN1_ITEM *)((int)local_34 - (int)local_40);
                        iVar6 = asn1_enc_save((ASN1_VALUE **)&local_3c,(uchar *)local_40,
                                              (int)param_3,unaff_s0);
                        if (iVar6 != 0) {
                          pcVar16 = (char *)0x0;
                          goto joined_r0x0055fb54;
                        }
                        goto LAB_0055fb7c;
                      }
                      uVar14 = 0x94;
                    }
                    goto LAB_0055fb90;
                  }
                  uVar14 = 0x95;
                }
                goto LAB_0055fa44;
              case '\x02':
                if (local_68 == (code *)0x0) {
LAB_0055fd74:
                  iVar6 = ASN1_item_ex_new((ASN1_VALUE **)&local_3c,unaff_s0);
                  if (iVar6 == 0) {
                    uVar14 = 0x3a;
                  }
                  else {
                    pAVar9 = (ASN1_ITEM *)unaff_s0->tcount;
LAB_0055fabc:
                    unaff_s1 = (ASN1_ITEM *)0x0;
                    unaff_s8 = (ASN1_ITEM *)unaff_s0->templates;
                    local_34 = local_40;
                    if (0 < (int)pAVar9) {
                      unaff_s6 = (ASN1_ITEM *)&local_34;
                      unaff_s5 = (void *)0xffffffff;
                      do {
                        ppAVar8 = asn1_get_field_ptr((ASN1_VALUE **)&local_3c,
                                                     (ASN1_TEMPLATE *)unaff_s8);
                        pAVar20 = (ASN1_VALUE *)0x1;
                        pcVar16 = &unaff_s8->itype;
                        in_stack_ffffff6c = param_6;
                        iVar6 = asn1_template_ex_d2i(ppAVar8,unaff_s6,local_38);
                        if (iVar6 != -1) {
                          if (iVar6 < 1) {
                            (*(code *)PTR_ERR_put_error_006a7f34)
                                      (0xd,0x78,0x3a,s_tasn_dec_c_0066a0bc);
                            ASN1_item_ex_free((ASN1_VALUE **)&local_3c,unaff_s0);
                            if (unaff_s8 != (ASN1_ITEM *)0x0) goto LAB_00560054;
                            goto LAB_0055fbb8;
                          }
                          pAVar9 = (ASN1_ITEM *)unaff_s0->tcount;
                          break;
                        }
                        pAVar9 = (ASN1_ITEM *)unaff_s0->tcount;
                        unaff_s1 = (ASN1_ITEM *)&unaff_s1->field_0x1;
                        unaff_s8 = (ASN1_ITEM *)&unaff_s8->size;
                      } while ((int)unaff_s1 < (int)pAVar9);
                    }
                    if (unaff_s1 != pAVar9) {
                      param_3 = unaff_s0;
                      asn1_set_choice_selector((ASN1_VALUE **)&local_3c,(int)unaff_s1,unaff_s0);
joined_r0x0055fb54:
                      if (local_68 != (code *)0x0) {
                        pcVar16 = (char *)0x0;
                        param_3 = unaff_s0;
                        iVar6 = (*local_68)(5,&local_3c);
                        if (iVar6 == 0) goto LAB_0055fb7c;
                      }
                      unaff_s3 = (ASN1_ITEM *)&local_3c;
                      local_40 = local_34;
                      goto LAB_0055f6e8;
                    }
                    uVar14 = 0x8f;
                  }
                }
                else {
                  pcVar16 = (char *)0x0;
                  iVar6 = (*local_68)(4,&local_3c,unaff_s0);
                  if (iVar6 != 0) {
                    if (local_3c == (ASN1_ITEM *)0x0) goto LAB_0055fd74;
                    iVar6 = asn1_get_choice_selector((ASN1_VALUE **)&local_3c,unaff_s0);
                    pAVar9 = (ASN1_ITEM *)unaff_s0->tcount;
                    if ((-1 < iVar6) && (iVar6 < (int)pAVar9)) {
                      pAVar11 = unaff_s0->templates;
                      ppAVar8 = asn1_get_field_ptr((ASN1_VALUE **)&local_3c,pAVar11 + iVar6);
                      ASN1_template_free(ppAVar8,pAVar11 + iVar6);
                      asn1_set_choice_selector((ASN1_VALUE **)&local_3c,-1,unaff_s0);
                      pAVar9 = (ASN1_ITEM *)unaff_s0->tcount;
                    }
                    goto LAB_0055fabc;
                  }
LAB_0055fb7c:
                  uVar14 = 100;
                }
LAB_0055fb90:
                (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x78,uVar14,s_tasn_dec_c_0066a0bc);
                goto LAB_0055fba4;
              case '\x03':
switchD_0055fc6c_caseD_55f740:
                unaff_s3 = (ASN1_ITEM *)&local_3c;
                iVar6 = (**(code **)((int)unaff_s5 + 8))(unaff_s3,unaff_s7);
                if (iVar6 == 0) {
                  uVar14 = 0x3a;
                  goto LAB_0055fb90;
                }
                goto LAB_0055f6e8;
              case '\x04':
switchD_0055fc6c_caseD_55f6ac:
                in_stack_ffffff6c = (ASN1_ITEM *)0x0;
                pAVar20 = (ASN1_VALUE *)0xffffffff;
                pcVar16 = (char *)unaff_s0;
                iVar6 = (**(code **)((int)unaff_s5 + 0x10))(&local_3c,unaff_s7);
                break;
              case '\x05':
switchD_0055fc6c_caseD_55f9e4:
                unaff_s6 = (ASN1_ITEM *)&local_34;
                in_stack_ffffff6c = unaff_s6;
                local_34 = pAVar12;
                iVar6 = asn1_check_tlen_constprop_1(0,&local_30,&local_43,0);
                if (iVar6 == 0) {
                  uVar14 = 0x3a;
                }
                else if (local_43 == '\0') {
                  unaff_s1 = (ASN1_ITEM *)0x670000;
                  if ((local_30 < (ASN1_VALUE *)0x1f) &&
                     ((*(uint *)(tag2bit + (int)local_30 * 4) & unaff_s0->utype) != 0)) {
                    in_stack_ffffff6c = (ASN1_ITEM *)0x0;
                    param_3 = local_38;
                    pcVar16 = (char *)unaff_s0;
                    pAVar20 = local_30;
                    iVar6 = asn1_d2i_ex_primitive(&local_3c,unaff_s7);
                    break;
                  }
                  uVar14 = 0x8c;
                }
                else {
                  uVar14 = 0x8b;
                }
LAB_0055fa44:
                unaff_s6 = (ASN1_ITEM *)&local_34;
                (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x78,uVar14,s_tasn_dec_c_0066a0bc);
LAB_0055fba4:
                ASN1_item_ex_free((ASN1_VALUE **)&local_3c,unaff_s0);
LAB_0055fbb8:
                unaff_s3 = (ASN1_ITEM *)&local_3c;
                (*(code *)PTR_ERR_add_error_data_006a813c)(2,s_Type__0066a0d8,unaff_s0->sname);
              default:
                goto switchD_0055f650_caseD_7;
              }
              if (iVar6 == 0) {
switchD_0055f650_caseD_7:
                unaff_s1 = (ASN1_ITEM *)0x670000;
                pcVar16 = s_tasn_dec_c_0066a0bc;
                param_3 = (ASN1_ITEM *)&DAT_0000003a;
                in_stack_ffffff6b = -99;
                (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x83);
                unaff_s2 = pAVar12;
                goto LAB_0055fbf8;
              }
LAB_0055f6e8:
              unaff_s2 = (ASN1_ITEM *)((int)local_res8[0] - ((int)local_40 - (int)pAVar12));
              pAStack_124 = local_3c;
              local_res8[0] = unaff_s2;
              iVar6 = (*(code *)PTR_sk_push_006a6fa8)(*param_1);
              in_stack_ffffff6b = (char)pAVar20;
              pAVar13 = local_res8[0];
              pAVar12 = local_40;
            } while (iVar6 != 0);
            param_3 = (ASN1_ITEM *)&DAT_00000041;
            in_stack_ffffff6b = -0x5e;
          }
          goto LAB_0055fd3c;
        }
      }
    }
  }
LAB_0055fc10:
  if (local_2c == *(ASN1_ITEM **)puVar3) {
    return uVar5;
  }
  pcStack_ac = asn1_template_ex_d2i;
  pAVar9 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_130 = PTR___stack_chk_guard_006a9ae8;
  AStack_dc.size = (long)unaff_s2;
  pAStack_b8 = unaff_s6;
  pAStack_1a8 = (ASN1_ITEM *)(int)in_stack_ffffff6b;
  AStack_dc.tcount = (long)unaff_s0;
  pAStack_b0 = unaff_s8;
  pAStack_b4 = unaff_s7;
  pvStack_bc = unaff_s5;
  pAStack_c0 = param_4;
  AStack_dc.sname = &unaff_s3->itype;
  AStack_dc.funcs = unaff_s1;
  AStack_dc.templates = (ASN1_TEMPLATE *)*(ASN1_ITEM **)PTR___stack_chk_guard_006a9ae8;
  pAVar12 = pAStack_124;
  pcVar17 = pcVar16;
  if (pAVar9 == (ASN1_ITEM *)0x0) {
    uVar5 = 0;
    pAVar13 = param_3;
  }
  else {
    unaff_s8 = *(ASN1_ITEM **)pcVar16;
    unaff_s1 = *(ASN1_ITEM **)pAStack_124;
    pAStack_e8 = unaff_s1;
    unaff_s3 = (ASN1_ITEM *)pcVar16;
    if (((uint)unaff_s8 & 0x10) == 0) {
      uVar5 = asn1_template_noexp_d2i();
      pAVar13 = param_3;
      pAStack_fc = in_stack_ffffff6c;
    }
    else {
      pcVar18 = *(char **)((int)pcVar16 + 4);
      param_4 = pAVar9;
      unaff_s7 = param_3;
      AStack_dc.utype = (long)unaff_s1;
      if (in_stack_ffffff6c == (ASN1_ITEM *)0x0) {
        pcVar17 = auStack_e4 + 4;
        pAVar13 = (ASN1_ITEM *)auStack_e4;
        pAVar12 = &AStack_dc;
        uVar5 = ASN1_get_object((uchar **)((int)&AStack_dc + 4),(long *)pAVar12,(int *)pAVar13,
                                (int *)pcVar17,(long)param_3);
        if ((uVar5 & 0x80) == 0) {
LAB_005602dc:
          pAVar10 = (ASN1_ITEM *)AStack_dc.utype;
          if (-1 < (int)pcVar18) {
            if ((pcVar18 != auStack_e4._0_4_) ||
               (unaff_s8 = (ASN1_ITEM *)((uint)unaff_s8 & 0xc0), unaff_s8 != auStack_e4._4_4_)) {
              uVar5 = 0xffffffff;
              if (pAStack_1a8 != (ASN1_ITEM *)0x0) goto LAB_00560360;
              if (in_stack_ffffff6c != (ASN1_ITEM *)0x0) {
                in_stack_ffffff6c->itype = 0;
              }
              uVar14 = 0xa8;
              goto LAB_00560310;
            }
            if (in_stack_ffffff6c != (ASN1_ITEM *)0x0) {
              in_stack_ffffff6c->itype = 0;
            }
          }
          unaff_s7 = AStack_dc._0_4_;
          if ((uVar5 & 1) != 0) {
            unaff_s7 = (ASN1_ITEM *)((int)param_3 - (AStack_dc.utype - (int)unaff_s1));
          }
          unaff_s1 = (ASN1_ITEM *)(int)(char)uVar5;
          pAStack_e8 = (ASN1_ITEM *)AStack_dc.utype;
          if (((uint)unaff_s1 & 0x20) == 0) {
            pAVar13 = (ASN1_ITEM *)&DAT_00000078;
          }
          else {
            pAVar12 = (ASN1_ITEM *)&pAStack_e8;
            pAVar13 = unaff_s7;
            pcVar17 = pcVar16;
            iVar6 = asn1_template_noexp_d2i(pAVar9);
            if (iVar6 != 0) {
              pAStack_1a8 = (ASN1_ITEM *)((int)pAStack_e8 - (int)pAVar10);
              unaff_s7 = (ASN1_ITEM *)((int)unaff_s7 - (int)pAStack_1a8);
              if (((uint)unaff_s1 & 1) == 0) {
                pAVar10 = pAStack_e8;
                if (unaff_s7 != (ASN1_ITEM *)0x0) {
                  pAVar13 = (ASN1_ITEM *)&DAT_00000077;
                  goto LAB_0056054c;
                }
              }
              else {
                unaff_s7 = (ASN1_ITEM *)(uint)((int)unaff_s7 < 2);
                if (((unaff_s7 != (ASN1_ITEM *)0x0) || (pAStack_e8->itype != '\0')) ||
                   (pAVar10 = (ASN1_ITEM *)&pAStack_e8->field_0x2, pAStack_e8->field_0x1 != '\0')) {
                  pAVar13 = (ASN1_ITEM *)&DAT_00000089;
LAB_0056054c:
                  pcVar17 = s_tasn_dec_c_0066a0bc;
                  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x84);
                  pAVar12 = (ASN1_ITEM *)pcVar16;
                  ASN1_template_free((ASN1_VALUE **)pAVar9,(ASN1_TEMPLATE *)pcVar16);
                  uVar5 = 0;
                  pAStack_fc = in_stack_ffffff6c;
                  goto LAB_00560360;
                }
              }
              *(ASN1_ITEM **)pAStack_124 = pAVar10;
              uVar5 = 1;
              pAStack_fc = in_stack_ffffff6c;
              goto LAB_00560360;
            }
            pAVar13 = (ASN1_ITEM *)&DAT_0000003a;
            pAStack_fc = in_stack_ffffff6c;
          }
          pcVar17 = s_tasn_dec_c_0066a0bc;
          pAVar12 = (ASN1_ITEM *)&DAT_00000084;
          (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
          uVar5 = 0;
          pAStack_1a8 = pAVar10;
          goto LAB_00560360;
        }
        uVar14 = 0x66;
LAB_00560310:
        (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x68,uVar14,s_tasn_dec_c_0066a0bc);
      }
      else {
        if (in_stack_ffffff6c->itype == '\0') {
          pcVar17 = auStack_e4 + 4;
          uVar5 = ASN1_get_object((uchar **)((int)&AStack_dc + 4),(long *)&AStack_dc,
                                  (int *)auStack_e4,(int *)pcVar17,(long)param_3);
          pAVar12 = (ASN1_ITEM *)(uVar5 & 0x81);
          in_stack_ffffff6c->funcs = auStack_e4._4_4_;
          in_stack_ffffff6c->utype = uVar5;
          in_stack_ffffff6c->templates = (ASN1_TEMPLATE *)AStack_dc._0_4_;
          in_stack_ffffff6c->tcount = (long)auStack_e4._0_4_;
          pAVar13 = (ASN1_ITEM *)0x1;
          in_stack_ffffff6c->size = AStack_dc.utype - (int)unaff_s1;
          in_stack_ffffff6c->itype = 1;
          if ((pAVar12 != (ASN1_ITEM *)0x0) ||
             ((int)((int)AStack_dc._0_4_ + (AStack_dc.utype - (int)unaff_s1)) <= (int)param_3))
          goto LAB_005602d4;
          uVar14 = 0x9b;
        }
        else {
          pAVar13 = (ASN1_ITEM *)in_stack_ffffff6c->templates;
          pAVar12 = (ASN1_ITEM *)in_stack_ffffff6c->funcs;
          auStack_e4._0_4_ = (char *)in_stack_ffffff6c->tcount;
          AStack_dc.utype = in_stack_ffffff6c->size + (int)&unaff_s1->itype;
          uVar5 = in_stack_ffffff6c->utype;
          auStack_e4._4_4_ = pAVar12;
          AStack_dc._0_4_ = pAVar13;
LAB_005602d4:
          if ((uVar5 & 0x80) == 0) goto LAB_005602dc;
          uVar14 = 0x66;
        }
        (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x68,uVar14,s_tasn_dec_c_0066a0bc);
        in_stack_ffffff6c->itype = 0;
      }
      unaff_s1 = (ASN1_ITEM *)0x670000;
      pcVar17 = s_tasn_dec_c_0066a0bc;
      pAVar13 = (ASN1_ITEM *)&DAT_0000003a;
      pAVar12 = (ASN1_ITEM *)&DAT_00000084;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
      uVar5 = 0;
    }
  }
LAB_00560360:
  if ((ASN1_ITEM *)AStack_dc.templates == *(ASN1_ITEM **)puStack_130) {
    return uVar5;
  }
  pcStack_114 = ASN1_item_ex_d2i;
  pAStack_240 = (ASN1_ITEM *)AStack_dc.templates;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_1b8 = PTR___stack_chk_guard_006a9ae8;
  pAStack_138 = in_stack_ffffff6c;
  pAStack_118 = unaff_s8;
  pAStack_134 = unaff_s1;
  pAStack_11c = unaff_s7;
  pAStack_120 = pAStack_1a8;
  pAStack_128 = param_4;
  pAStack_12c = unaff_s3;
  puStack_168 = &_gp;
  uStack_158 = (uint)pAStack_fc & 0x400;
  pAStack_108 = pAVar13;
  uStack_144 = 0;
  pAVar9 = *(ASN1_ITEM **)PTR___stack_chk_guard_006a9ae8;
  pAStack_1bc = *(ASN1_ITEM_EXP **)((int)pcVar17 + 0x10);
  pAStack_13c = pAVar9;
  pAStack_22c = pAStack_124;
  if (pAStack_240 != (ASN1_ITEM *)0x0) {
    if (pAStack_1bc == (ASN1_ITEM_EXP *)0x0) {
      bVar1 = *(byte *)(ulong *)pcVar17;
      pvStack_154 = (void *)0x0;
    }
    else {
      pvStack_154 = pAStack_1bc->funcs;
      bVar1 = *(byte *)(ulong *)pcVar17;
    }
    pAStack_22c = pAVar12;
    unaff_s7 = (ASN1_ITEM *)pcVar17;
    if (bVar1 < 7) {
                    /* WARNING: Could not recover jumptable at 0x005606b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar5 = (*(code *)(&PTR_LAB_0066a144)[bVar1])();
      return uVar5;
    }
  }
  if (pAVar9 == *(ASN1_ITEM **)PTR___stack_chk_guard_006a9ae8) {
    return 0;
  }
  pcStack_19c = ASN1_template_d2i;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_23c = PTR___stack_chk_guard_006a9ae8;
  uStack_1a0 = 0xffffffe0;
  pAStack_1a4 = unaff_s7;
  pAStack_1ac = pAStack_22c;
  pAStack_1b0 = param_4;
  pAStack_1b4 = unaff_s3;
  pAStack_1c0 = pAStack_240;
  uStack_1dc = 0;
  pAStack_1c4 = *(ASN1_ITEM **)PTR___stack_chk_guard_006a9ae8;
  uStack_238 = 0;
  pcVar16 = &pAVar12->itype;
  pcVar18 = pcVar17;
  pAStack_228 = pAStack_1a8;
  pAStack_220 = (ASN1_ITEM *)0xffffffe0;
  if (pAVar9 != (ASN1_ITEM *)0x0) {
    pAStack_22c = *(ASN1_ITEM **)pcVar17;
    pAStack_240 = *(ASN1_ITEM **)pAVar12;
    pAStack_1f0 = pAStack_240;
    unaff_s3 = (ASN1_ITEM *)pcVar17;
    pAStack_228 = pAVar12;
    if (((uint)pAStack_22c & 0x10) == 0) {
      uStack_238 = asn1_template_noexp_d2i();
    }
    else {
      iVar6 = *(long *)((int)pcVar17 + 4);
      pAStack_1e0 = pAStack_240;
      pcStack_1d8 = (char *)ASN1_get_object((uchar **)&pAStack_1e0,(long *)&pAStack_1e4,&iStack_1ec,
                                            (int *)&pAStack_1e8,(long)pAVar13);
      pAVar10 = pAStack_1e0;
      iStack_1c8 = (int)pAStack_1e0 - (int)pAStack_240;
      pAStack_1d4 = pAStack_1e4;
      pAStack_1cc = pAStack_1e8;
      iStack_1d0 = iStack_1ec;
      uStack_1dc = 1;
      param_4 = pAVar9;
      unaff_s7 = pAVar13;
      pAStack_220 = pAStack_1e4;
      if ((((uint)pcStack_1d8 & 0x81) == 0) && ((int)pAVar13 < (int)((int)pAStack_1e4 + iStack_1c8))
         ) {
        uVar14 = 0x9b;
LAB_0056138c:
        (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x68,uVar14,s_tasn_dec_c_0066a0bc);
        uStack_1dc = 0;
      }
      else {
        uStack_238 = (uint)pcStack_1d8 & 0x80;
        if (uStack_238 != 0) {
          uVar14 = 0x66;
          goto LAB_0056138c;
        }
        if (iVar6 < 0) {
LAB_00561334:
          pAStack_22c = (ASN1_ITEM *)(int)(char)pcStack_1d8;
          pAStack_1f0 = pAStack_1e0;
          pAStack_240 = (ASN1_ITEM *)((int)pAVar13 - iStack_1c8);
          if (((uint)pcStack_1d8 & 1) != 0) {
            pAStack_220 = pAStack_240;
          }
          if (((uint)pAStack_22c & 0x20) == 0) {
            pAVar13 = (ASN1_ITEM *)&DAT_00000078;
          }
          else {
            pcVar16 = (char *)&pAStack_1f0;
            pAVar13 = pAStack_220;
            iVar6 = asn1_template_noexp_d2i(pAVar9);
            if (iVar6 != 0) {
              pAStack_22c = (ASN1_ITEM *)((uint)pAStack_22c & 1);
              pAStack_220 = (ASN1_ITEM *)((int)pAStack_220 - ((int)pAStack_1f0 - (int)pAVar10));
              if (pAStack_22c == (ASN1_ITEM *)0x0) {
                pAVar10 = pAStack_1f0;
                if (pAStack_220 != (ASN1_ITEM *)0x0) {
                  pAVar13 = (ASN1_ITEM *)&DAT_00000077;
                  goto LAB_0056143c;
                }
              }
              else {
                pAStack_220 = (ASN1_ITEM *)(uint)((int)pAStack_220 < 2);
                if (((pAStack_220 != (ASN1_ITEM *)0x0) || (pAStack_1f0->itype != '\0')) ||
                   (pAStack_1f0->field_0x1 != '\0')) {
                  pAVar13 = (ASN1_ITEM *)&DAT_00000089;
LAB_0056143c:
                  pcVar18 = s_tasn_dec_c_0066a0bc;
                  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x84);
                  pcVar16 = pcVar17;
                  ASN1_template_free((ASN1_VALUE **)pAVar9,(ASN1_TEMPLATE *)pcVar17);
                  goto LAB_005611f0;
                }
                pAVar10 = (ASN1_ITEM *)&pAStack_1f0->field_0x2;
              }
              *(ASN1_ITEM **)pAVar12 = pAVar10;
              uStack_238 = 1;
              goto LAB_005611f0;
            }
            pAVar13 = (ASN1_ITEM *)&DAT_0000003a;
          }
          pcVar18 = s_tasn_dec_c_0066a0bc;
          pcVar16 = &DAT_00000084;
          (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
          goto LAB_005611f0;
        }
        if ((iVar6 == iStack_1ec) &&
           (pAStack_22c = (ASN1_ITEM *)((uint)pAStack_22c & 0xc0), pAStack_22c == pAStack_1e8)) {
          uStack_1dc = 0;
          goto LAB_00561334;
        }
        uStack_1dc = 0;
        (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x68,0xa8,s_tasn_dec_c_0066a0bc);
      }
      pAStack_240 = (ASN1_ITEM *)0x670000;
      pcVar18 = s_tasn_dec_c_0066a0bc;
      pAVar13 = (ASN1_ITEM *)&DAT_0000003a;
      pcVar16 = &DAT_00000084;
      uStack_238 = 0;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
    }
  }
LAB_005611f0:
  if (pAStack_1c4 == *(ASN1_ITEM **)puStack_23c) {
    return uStack_238;
  }
  pcStack_21c = ASN1_item_d2i;
  pAVar9 = pAStack_1c4;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  pvVar19 = *(void **)((int)pcVar18 + 0x10);
  pAStack_230 = param_4;
  pAStack_234 = unaff_s3;
  pAStack_224 = unaff_s7;
  auStack_26c = (undefined  [4])0x0;
  auStack_25c[0] = 0;
  pAStack_268 = pAVar13;
  pAStack_264 = (ASN1_TEMPLATE *)0x0;
  pAVar12 = (ASN1_ITEM *)auStack_26c;
  if (pAVar9 != (ASN1_ITEM *)0x0) {
    pAVar12 = pAVar9;
  }
  piStack_244 = *(int **)PTR___stack_chk_guard_006a9ae8;
  if (pvVar19 == (void *)0x0) {
    switch(*pcVar18) {
    case '\0':
      goto switchD_005619f8_caseD_0;
    case '\x01':
    case '\x06':
      pcStack_280 = (code *)0x0;
      goto switchD_00561550_caseD_1;
    case '\x02':
      pcStack_280 = (code *)0x0;
LAB_00561954:
      if (*(int *)pAVar12 == 0) {
        iVar6 = ASN1_item_ex_new((ASN1_VALUE **)pAVar12,(ASN1_ITEM *)pcVar18);
        if (iVar6 == 0) {
          uVar15 = 0x3a;
          uVar14 = 0x13f;
          goto LAB_0056163c;
        }
        pAVar13 = *(ASN1_ITEM **)((int)pcVar18 + 0xc);
      }
      else {
        iVar6 = asn1_get_choice_selector((ASN1_VALUE **)pAVar12,(ASN1_ITEM *)pcVar18);
        pAVar13 = *(ASN1_ITEM **)((int)pcVar18 + 0xc);
        if ((-1 < iVar6) && (iVar6 < (int)pAVar13)) {
          pAVar11 = *(ASN1_TEMPLATE **)((int)pcVar18 + 8);
          ppAVar8 = asn1_get_field_ptr((ASN1_VALUE **)pAVar12,pAVar11 + iVar6);
          ASN1_template_free(ppAVar8,pAVar11 + iVar6);
          asn1_set_choice_selector((ASN1_VALUE **)pAVar12,-1,(ASN1_ITEM *)pcVar18);
          pAVar13 = *(ASN1_ITEM **)((int)pcVar18 + 0xc);
        }
      }
      pAStack_264 = *(ASN1_TEMPLATE **)pcVar16;
      pAVar9 = (ASN1_ITEM *)0x0;
      pAVar11 = *(ASN1_TEMPLATE **)((int)pcVar18 + 8);
      if ((int)pAVar13 < 1) {
LAB_005615e0:
        if (pAVar9 == pAVar13) {
LAB_00561a34:
          uVar15 = 0x8f;
          uVar14 = 0x15e;
          goto LAB_0056163c;
        }
      }
      else {
        do {
          ppAVar8 = asn1_get_field_ptr((ASN1_VALUE **)pAVar12,pAVar11);
          iVar6 = asn1_template_ex_d2i(ppAVar8,auStack_26c + 8,pAStack_268,pAVar11,1,auStack_25c);
          if (iVar6 != -1) {
            if (iVar6 < 1) {
              (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x78,0x3a,s_tasn_dec_c_0066a0bc,0x152);
              ASN1_item_ex_free((ASN1_VALUE **)pAVar12,(ASN1_ITEM *)pcVar18);
              if (pAVar11 == (ASN1_TEMPLATE *)0x0) goto LAB_00561668;
              goto LAB_00561cf8;
            }
            pAVar13 = *(ASN1_ITEM **)((int)pcVar18 + 0xc);
            goto LAB_005615e0;
          }
          pAVar9 = (ASN1_ITEM *)&pAVar9->field_0x1;
          pAVar11 = pAVar11 + 1;
        } while ((int)pAVar9 < (int)*(undefined **)((int)pcVar18 + 0xc));
        if (pAVar9 == (ASN1_ITEM *)*(undefined **)((int)pcVar18 + 0xc)) goto LAB_00561a34;
      }
      asn1_set_choice_selector((ASN1_VALUE **)pAVar12,(int)pAVar9,(ASN1_ITEM *)pcVar18);
      goto joined_r0x00561600;
    case '\x03':
      goto switchD_005619f8_caseD_3;
    case '\x04':
      pcStack_280 = *(code **)(in_zero + 0x10);
      goto LAB_005618f4;
    case '\x05':
      goto switchD_005619f8_caseD_5;
    }
    goto switchD_005619f8_caseD_7;
  }
  pcStack_280 = *(code **)((int)pvVar19 + 0x10);
  switch(*pcVar18) {
  case '\0':
switchD_005619f8_caseD_0:
    if (*(ASN1_TEMPLATE **)((int)pcVar18 + 8) == (ASN1_TEMPLATE *)0x0) {
      iVar6 = asn1_d2i_ex_primitive(pAVar12,pcVar16,pAVar13,pcVar18,0xffffffff,0,0,auStack_25c);
      if (iVar6 < 1) {
        uVar5 = 0;
        pAVar9 = (ASN1_ITEM *)pcVar16;
        goto LAB_00561684;
      }
    }
    else {
      iVar6 = asn1_template_ex_d2i
                        (pAVar12,pcVar16,pAVar13,*(ASN1_TEMPLATE **)((int)pcVar18 + 8),0,auStack_25c
                        );
      if (iVar6 < 1) goto switchD_005619f8_caseD_7;
    }
    goto LAB_005617a4;
  case '\x01':
  case '\x06':
switchD_00561550_caseD_1:
    pAStack_264 = *(ASN1_TEMPLATE **)pcVar16;
    pAVar9 = (ASN1_ITEM *)0x0;
    iVar6 = asn1_check_tlen(auStack_26c + 4,0,0,&cStack_26e,&cStack_26d,auStack_26c + 8,pAVar13,0x10
                            ,0,0,auStack_25c);
    if (iVar6 == 0) {
      uVar15 = 0x3a;
      uVar14 = 0x176;
    }
    else {
      uVar5 = 0;
      if (iVar6 == -1) goto LAB_00561684;
      cVar2 = cStack_26e;
      if ((pvVar19 != (void *)0x0) && ((*(uint *)((int)pvVar19 + 4) & 4) != 0)) {
        pAStack_268 = (ASN1_ITEM *)((int)pAVar13 - ((int)pAStack_264 - (int)*(char **)pcVar16));
        cVar2 = '\x01';
      }
      if (cStack_26d == '\0') {
        uVar15 = 0x95;
        uVar14 = 0x182;
      }
      else if ((*(int *)pAVar12 == 0) &&
              (iVar6 = ASN1_item_ex_new((ASN1_VALUE **)pAVar12,(ASN1_ITEM *)pcVar18), iVar6 == 0)) {
        uVar15 = 0x3a;
        uVar14 = 0x187;
      }
      else {
        puStack_278 = auStack_25c;
        if ((pcStack_280 != (code *)0x0) &&
           (iVar6 = (*pcStack_280)(4,pAVar12,pcVar18,0), iVar6 == 0)) goto LAB_00561628;
        iVar6 = *(long *)((int)pcVar18 + 0xc);
        iVar7 = 0;
        tt = *(ASN1_TEMPLATE **)((int)pcVar18 + 8);
        if (0 < iVar6) {
          do {
            if ((tt->flags & 0x300) != 0) {
              pAVar11 = asn1_do_adb((ASN1_VALUE **)pAVar12,tt,1);
              ppAVar8 = asn1_get_field_ptr((ASN1_VALUE **)pAVar12,pAVar11);
              ASN1_template_free(ppAVar8,pAVar11);
              iVar6 = *(long *)((int)pcVar18 + 0xc);
            }
            iVar7 = iVar7 + 1;
            tt = tt + 1;
          } while (iVar7 < iVar6);
          tt = *(ASN1_TEMPLATE **)((int)pcVar18 + 8);
          iVar7 = 0;
          if (0 < iVar6) {
            do {
              pAVar11 = asn1_do_adb((ASN1_VALUE **)pAVar12,tt,1);
              if (pAVar11 == (ASN1_TEMPLATE *)0x0) goto LAB_00561650;
              ppAVar8 = asn1_get_field_ptr((ASN1_VALUE **)pAVar12,pAVar11);
              pAVar4 = pAStack_264;
              if (pAStack_268 == (ASN1_ITEM *)0x0) {
                if (cStack_26e != '\0') goto LAB_00561e04;
                goto LAB_00561c3c;
              }
              if (((1 < (int)pAStack_268) && (*(char *)&pAStack_264->flags == '\0')) &&
                 (*(char *)((int)&pAStack_264->flags + 1) == '\0')) {
                pAStack_264 = (ASN1_TEMPLATE *)((int)&pAStack_264->flags + 2);
                if (cStack_26e != '\0') {
                  cStack_26e = '\0';
                  pAStack_268 = (ASN1_ITEM *)((int)&pAStack_268[-1].sname + 2);
                  goto LAB_00561c28;
                }
                uVar15 = 0x9f;
                uVar14 = 0x1a7;
                goto LAB_0056163c;
              }
              uVar5 = 0;
              if (*(long *)((int)pcVar18 + 0xc) + -1 != iVar7) {
                uVar5 = pAVar11->flags & 1;
              }
              iVar6 = asn1_template_ex_d2i
                                (ppAVar8,auStack_26c + 8,pAStack_268,pAVar11,uVar5,puStack_278);
              if (iVar6 == 0) goto LAB_00561ce4;
              if (iVar6 == -1) {
                ASN1_template_free(ppAVar8,pAVar11);
              }
              else {
                pAStack_268 = (ASN1_ITEM *)((int)pAStack_268 - ((int)pAStack_264 - (int)pAVar4));
              }
              iVar7 = iVar7 + 1;
              tt = tt + 1;
            } while (iVar7 < *(long *)((int)pcVar18 + 0xc));
          }
        }
        if (cStack_26e != '\0') {
          if ((((int)pAStack_268 < 2) || (*(char *)&pAStack_264->flags != '\0')) ||
             (*(char *)((int)&pAStack_264->flags + 1) != '\0')) {
LAB_00561e04:
            uVar15 = 0x89;
            uVar14 = 0x1ce;
            break;
          }
          pAStack_264 = (ASN1_TEMPLATE *)((int)&pAStack_264->flags + 2);
        }
LAB_00561c28:
        if ((cVar2 != '\0') || (pAStack_268 == (ASN1_ITEM *)0x0)) {
LAB_00561c3c:
          if (iVar7 < *(long *)((int)pcVar18 + 0xc)) {
LAB_00561c90:
            pAVar11 = asn1_do_adb((ASN1_VALUE **)pAVar12,tt,1);
            if (pAVar11 != (ASN1_TEMPLATE *)0x0) {
              if ((pAVar11->flags & 1) != 0) goto LAB_00561c54;
              (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x78,0x79,s_tasn_dec_c_0066a0bc,0x1e7);
LAB_00561ce4:
              ASN1_item_ex_free((ASN1_VALUE **)pAVar12,(ASN1_ITEM *)pcVar18);
LAB_00561cf8:
              pcVar16 = (char *)&DAT_0066a0d0;
              (*(code *)PTR_ERR_add_error_data_006a813c)
                        (4,&DAT_0066a0d0,pAVar11->field_name,", Type=",
                         *(char **)((int)pcVar18 + 0x18));
              goto switchD_005619f8_caseD_7;
            }
            goto LAB_00561650;
          }
          pAVar9 = *(ASN1_ITEM **)pcVar16;
          goto LAB_00561a70;
        }
        uVar15 = 0x94;
        uVar14 = 0x1d3;
      }
    }
    break;
  case '\x02':
    if ((pcStack_280 == (code *)0x0) || (iVar6 = (*pcStack_280)(4,pAVar12,pcVar18,0), iVar6 != 0))
    goto LAB_00561954;
    goto LAB_00561628;
  case '\x03':
switchD_005619f8_caseD_3:
    iVar6 = (**(code **)((int)pvVar19 + 8))(pAVar12,pcVar16,pAVar13);
    if (iVar6 != 0) {
      uVar5 = *(uint *)pAVar12;
      pAVar9 = (ASN1_ITEM *)pcVar16;
      goto LAB_00561684;
    }
    uVar15 = 0x3a;
    uVar14 = 0x12f;
    break;
  case '\x04':
LAB_005618f4:
    iVar6 = (*pcStack_280)(pAVar12,pcVar16,pAVar13,pcVar18,0xffffffff,0,0,auStack_25c);
    if (iVar6 < 1) {
      uVar5 = 0;
      pAVar9 = (ASN1_ITEM *)pcVar16;
      goto LAB_00561684;
    }
LAB_005617a4:
    uVar5 = *(uint *)pAVar12;
    pAVar9 = (ASN1_ITEM *)pcVar16;
    goto LAB_00561684;
  case '\x05':
switchD_005619f8_caseD_5:
    pAStack_264 = *(ASN1_TEMPLATE **)pcVar16;
    iVar6 = asn1_check_tlen_constprop_1
                      (0,auStack_26c + 0xc,&cStack_26f,0,0,auStack_26c + 8,pAVar13,1,auStack_25c);
    if (iVar6 == 0) {
      uVar15 = 0x3a;
      uVar14 = 0xdb;
    }
    else if (cStack_26f == '\0') {
      if ((uStack_260 < 0x1f) &&
         ((*(uint *)(tag2bit + uStack_260 * 4) & *(long *)((int)pcVar18 + 4)) != 0)) {
        iVar6 = asn1_d2i_ex_primitive
                          (pAVar12,pcVar16,pAStack_268,pcVar18,uStack_260,0,0,auStack_25c);
        if (iVar6 < 1) {
          uVar5 = 0;
          pAVar9 = (ASN1_ITEM *)pcVar16;
          goto LAB_00561684;
        }
        goto LAB_005617a4;
      }
      uVar15 = 0x8c;
      uVar14 = 0xec;
    }
    else {
      uVar15 = 0x8b;
      uVar14 = 0xe4;
    }
    break;
  default:
    goto switchD_005619f8_caseD_7;
  }
LAB_0056163c:
  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x78,uVar15,s_tasn_dec_c_0066a0bc,uVar14);
LAB_00561650:
  ASN1_item_ex_free((ASN1_VALUE **)pAVar12,(ASN1_ITEM *)pcVar18);
LAB_00561668:
  pcVar16 = s_Type__0066a0d8;
  (*(code *)PTR_ERR_add_error_data_006a813c)(2,s_Type__0066a0d8,*(char **)((int)pcVar18 + 0x18));
switchD_005619f8_caseD_7:
  uVar5 = 0;
  pAVar9 = (ASN1_ITEM *)pcVar16;
LAB_00561684:
  if (piStack_244 == *(int **)puVar3) {
    return uVar5;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  return *(uint *)(pAVar9->utype + *piStack_244);
code_r0x0055ff00:
  unaff_s5 = (void *)((int)unaff_s5 + 1);
  ppAVar8 = asn1_get_field_ptr((ASN1_VALUE **)&local_3c,(ASN1_TEMPLATE *)unaff_s8);
  unaff_s1 = (ASN1_ITEM *)&unaff_s1->size;
  ASN1_template_free(ppAVar8,(ASN1_TEMPLATE *)unaff_s8);
  if (unaff_s0->tcount <= (int)unaff_s5) goto LAB_0055fe40;
  goto LAB_0055ff3c;
LAB_00561c54:
  iVar7 = iVar7 + 1;
  ppAVar8 = asn1_get_field_ptr((ASN1_VALUE **)pAVar12,pAVar11);
  tt = tt + 1;
  ASN1_template_free(ppAVar8,pAVar11);
  if (*(long *)((int)pcVar18 + 0xc) <= iVar7) goto LAB_00561a6c;
  goto LAB_00561c90;
LAB_00561a6c:
  pAVar9 = *(ASN1_ITEM **)pcVar16;
LAB_00561a70:
  iVar6 = asn1_enc_save((ASN1_VALUE **)pAVar12,(uchar *)pAVar9,(int)pAStack_264 - (int)pAVar9,
                        (ASN1_ITEM *)pcVar18);
  if (iVar6 != 0) {
joined_r0x00561600:
    if ((pcStack_280 == (code *)0x0) ||
       (pAVar9 = pAVar12, iVar6 = (*pcStack_280)(5,pAVar12,pcVar18,0), iVar6 != 0)) {
      *(ASN1_TEMPLATE **)pcVar16 = pAStack_264;
      uVar5 = *(uint *)pAVar12;
      goto LAB_00561684;
    }
  }
LAB_00561628:
  uVar15 = 100;
  uVar14 = 0x1f7;
  goto LAB_0056163c;
}

