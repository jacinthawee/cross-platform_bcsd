
/* WARNING: Type propagation algorithm not settling */

ASN1_ITEM_EXP *
asn1_d2i_ex_primitive
          (ASN1_TEMPLATE *param_1,ASN1_ITEM_EXP *param_2,ASN1_ITEM_EXP *param_3,
          ASN1_ITEM_EXP *param_4,ASN1_ITEM_EXP *param_5,ASN1_ITEM_EXP *param_6,char param_7,
          ASN1_ITEM_EXP *param_8)

{
  byte bVar1;
  undefined *puVar2;
  ASN1_TEMPLATE *pAVar3;
  ASN1_ITEM_EXP *pAVar4;
  int in_zero;
  uint uVar5;
  ASN1_ITEM_EXP *pAVar6;
  int iVar7;
  ASN1_ITEM_EXP *pAVar8;
  int iVar9;
  ASN1_VALUE **ppAVar10;
  ASN1_TEMPLATE *tt;
  ASN1_ITEM_EXP **pval;
  ASN1_ITEM_EXP *pAVar11;
  ASN1_ITEM_EXP *pAVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  char *pcVar15;
  char *pcVar16;
  char *it;
  ASN1_ITEM_EXP *unaff_s1;
  void *pvVar17;
  ASN1_ITEM *unaff_s4;
  ASN1_TEMPLATE *tt_00;
  ASN1_TEMPLATE *unaff_s5;
  ASN1_ITEM_EXP *unaff_s6;
  ASN1_ITEM_EXP *unaff_s7;
  code *pcStack_308;
  undefined *puStack_300;
  char cStack_2f7;
  char cStack_2f6;
  char cStack_2f5;
  undefined auStack_2f4 [4];
  ASN1_ITEM_EXP *pAStack_2f0;
  ASN1_TEMPLATE *pAStack_2ec;
  uint uStack_2e8;
  undefined auStack_2e4 [24];
  int *piStack_2cc;
  ASN1_ITEM_EXP *pAStack_2c8;
  undefined *puStack_2c4;
  ASN1_ITEM_EXP *pAStack_2c0;
  ASN1_ITEM_EXP *pAStack_2bc;
  ASN1_ITEM_EXP *pAStack_2b8;
  ASN1_ITEM *pAStack_2b4;
  ASN1_ITEM_EXP *pAStack_2b0;
  ASN1_ITEM_EXP *pAStack_2ac;
  ASN1_ITEM_EXP *pAStack_2a8;
  code *pcStack_2a4;
  ASN1_ITEM_EXP *pAStack_278;
  int iStack_274;
  ASN1_ITEM_EXP *pAStack_270;
  ASN1_ITEM_EXP *pAStack_26c;
  ASN1_ITEM_EXP *pAStack_268;
  undefined uStack_264;
  char *pcStack_260;
  ASN1_ITEM_EXP *pAStack_25c;
  int iStack_258;
  ASN1_ITEM_EXP *pAStack_254;
  int iStack_250;
  ASN1_ITEM_EXP *pAStack_24c;
  ASN1_ITEM_EXP *pAStack_248;
  undefined *puStack_244;
  void *pvStack_240;
  ASN1_ITEM_EXP *pAStack_23c;
  ASN1_ITEM_EXP *pAStack_238;
  ASN1_ITEM_EXP *pAStack_234;
  ASN1_ITEM_EXP *pAStack_230;
  undefined4 uStack_22c;
  ASN1_ITEM_EXP *pAStack_228;
  code *pcStack_224;
  undefined *puStack_1f0;
  undefined4 uStack_1e4;
  undefined4 uStack_1d4;
  ASN1_ITEM_EXP *pAStack_1cc;
  ASN1_ITEM_EXP *pAStack_1c8;
  char *pcStack_1c4;
  undefined *puStack_1c0;
  ASN1_ITEM_EXP *pAStack_1bc;
  ASN1_ITEM_EXP *pAStack_1b8;
  ASN1_ITEM_EXP *pAStack_1b4;
  ASN1_ITEM_EXP *pAStack_1b0;
  ASN1_ITEM_EXP *pAStack_1ac;
  ASN1_ITEM_EXP *pAStack_1a8;
  code *pcStack_1a4;
  ASN1_ITEM_EXP *pAStack_198;
  ASN1_ITEM_EXP *pAStack_178;
  undefined auStack_174 [8];
  ASN1_ITEM_EXP AStack_16c;
  ASN1_ITEM_EXP *pAStack_150;
  ASN1_TEMPLATE *pAStack_14c;
  ASN1_ITEM_EXP *pAStack_148;
  ASN1_ITEM_EXP *pAStack_144;
  ASN1_ITEM_EXP *pAStack_140;
  code *pcStack_13c;
  undefined4 in_stack_fffffed8;
  ASN1_ITEM *pAVar18;
  char cVar19;
  ASN1_ITEM_EXP *in_stack_fffffedc;
  ASN1_ITEM_EXP *pAStack_f8;
  undefined uStack_d4;
  char cStack_d3;
  undefined uStack_d2;
  undefined uStack_d1;
  undefined auStack_d0 [4];
  ASN1_ITEM *pAStack_cc;
  ASN1_ITEM_EXP *pAStack_c8;
  ASN1_ITEM_EXP *pAStack_c4;
  ASN1_ITEM *pAStack_c0;
  ASN1_ITEM_EXP *pAStack_bc;
  ASN1_ITEM_EXP *pAStack_b8;
  ASN1_ITEM_EXP *pAStack_b4;
  undefined *puStack_b0;
  ASN1_ITEM_EXP *pAStack_ac;
  ASN1_ITEM_EXP *pAStack_a8;
  ASN1_TEMPLATE *pAStack_a4;
  ASN1_ITEM_EXP *pAStack_a0;
  ASN1_ITEM_EXP *pAStack_9c;
  ASN1_ITEM_EXP *pAStack_98;
  code *pcStack_94;
  ASN1_ITEM_EXP *apAStack_88 [2];
  char in_stack_ffffff83;
  ASN1_ITEM *in_stack_ffffff84;
  char local_4d;
  ASN1_ITEM_EXP *local_4c;
  ASN1_ITEM_EXP *local_48;
  undefined local_44 [12];
  ASN1_ITEM_EXP *local_38;
  ASN1_ITEM_EXP *local_34;
  ASN1_TEMPLATE *local_30;
  ASN1_ITEM_EXP **local_2c;
  
  AStack_16c.size = (long)PTR___stack_chk_guard_006aabf0;
  cVar19 = (char)in_stack_fffffed8;
  pAStack_1a8 = (ASN1_ITEM_EXP *)(int)param_7;
  local_4d = '\0';
  local_2c = *(ASN1_ITEM_EXP ***)PTR___stack_chk_guard_006aabf0;
  if (param_1 == (ASN1_TEMPLATE *)0x0) {
    pAVar12 = (ASN1_ITEM_EXP *)0x7d;
    in_stack_ffffff83 = '\f';
    param_3 = unaff_s7;
LAB_00563154:
    pcStack_1c4 = s_tasn_dec_c_0066ab0c;
    pAVar11 = (ASN1_ITEM_EXP *)&DAT_0000006c;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd);
    pAVar6 = (ASN1_ITEM_EXP *)0x0;
    param_4 = unaff_s4;
    param_1 = unaff_s5;
    param_2 = unaff_s6;
  }
  else {
    pcStack_1c4 = &param_4->itype;
    if (param_4->itype == '\x05') {
      local_4c = param_5;
      if (param_5 != (ASN1_ITEM_EXP *)0xfffffffc) {
        param_6 = (ASN1_ITEM_EXP *)0x0;
        pAVar8 = param_5;
        local_4c = param_5;
        goto LAB_00562cbc;
      }
      param_5 = (ASN1_ITEM_EXP *)0xffffffff;
LAB_00562f6c:
      pAVar11 = (ASN1_ITEM_EXP *)&local_48;
      if (pAStack_1a8 == (ASN1_ITEM_EXP *)0x0) {
        local_48 = *(ASN1_ITEM_EXP **)param_2;
        pcStack_1c4 = (char *)0x0;
        in_stack_ffffff83 = '\0';
        iVar7 = asn1_check_tlen_constprop_1(0,&local_4c,&local_38);
        cVar19 = (char)in_stack_fffffed8;
        if (iVar7 != 0) {
          if (local_38._0_1_ != '\0') {
            local_4c = (ASN1_ITEM_EXP *)0xfffffffd;
          }
          goto LAB_00562cb4;
        }
        pAVar12 = (ASN1_ITEM_EXP *)&DAT_0000003a;
        in_stack_ffffff83 = '.';
        in_stack_ffffff84 = pAVar11;
      }
      else {
        pAVar12 = (ASN1_ITEM_EXP *)0x7e;
        in_stack_ffffff83 = '%';
      }
LAB_00562e60:
      pcStack_1c4 = s_tasn_dec_c_0066ab0c;
      pAVar11 = (ASN1_ITEM_EXP *)&DAT_0000006c;
      (*(code *)PTR_ERR_put_error_006a9030)(0xd);
    }
    else {
      local_4c = (ASN1_ITEM_EXP *)param_4->utype;
      pAVar11 = in_stack_ffffff84;
      if (local_4c == (ASN1_ITEM_EXP *)0xfffffffc) {
        if ((int)param_5 < 0) goto LAB_00562f6c;
        pAVar12 = (ASN1_ITEM_EXP *)0x7f;
        in_stack_ffffff83 = '\x1f';
        goto LAB_00562e60;
      }
LAB_00562cb4:
      pAVar8 = param_5;
      in_stack_ffffff84 = pAVar11;
      if (param_5 == (ASN1_ITEM_EXP *)0xffffffff) {
        param_6 = (ASN1_ITEM_EXP *)0x0;
        pAVar8 = local_4c;
      }
LAB_00562cbc:
      unaff_s1 = *(ASN1_ITEM_EXP **)param_2;
      local_48 = unaff_s1;
      local_38 = unaff_s1;
      if (param_8 == (ASN1_ITEM_EXP *)0x0) {
        pcStack_1c4 = local_44 + 4;
        pAVar12 = (ASN1_ITEM_EXP *)local_44;
        pAVar11 = (ASN1_ITEM_EXP *)(local_44 + 8);
        pAVar6 = param_3;
        uVar5 = ASN1_get_object((uchar **)&local_38,(long *)pAVar11,(int *)pAVar12,
                                (int *)pcStack_1c4,(long)param_3);
        cVar19 = (char)in_stack_fffffed8;
        in_stack_ffffff83 = (char)pAVar6;
        if ((uVar5 & 0x80) == 0) {
LAB_00562d0c:
          param_5 = local_38;
          cVar19 = (char)in_stack_fffffed8;
          if (-1 < (int)pAVar8) {
            if ((pAVar8 == local_44._0_4_) && (param_6 == local_44._4_4_)) {
              if (param_8 != (ASN1_ITEM_EXP *)0x0) {
                param_8->itype = 0;
              }
              goto LAB_00562ec0;
            }
            pAVar6 = (ASN1_ITEM_EXP *)0xffffffff;
            param_5 = pAVar8;
            if (pAStack_1a8 == (ASN1_ITEM_EXP *)0x0) {
              if (param_8 != (ASN1_ITEM_EXP *)0x0) {
                param_8->itype = 0;
              }
              uVar13 = 0xa8;
              goto LAB_00562d40;
            }
            goto LAB_00562d7c;
          }
LAB_00562ec0:
          pAVar8 = local_44._8_4_;
          if ((uVar5 & 1) != 0) {
            pAVar8 = (ASN1_ITEM_EXP *)((int)param_3 - ((int)local_38 - (int)unaff_s1));
          }
          local_48 = local_38;
          pcStack_1c4 = (char *)((int)(char)uVar5 & 1);
          unaff_s1 = pAVar8;
          if (&local_4c[-1].tcount < &SUB_00000002) {
            if ((uVar5 & 0x20) == 0) {
              pAVar12 = (ASN1_ITEM_EXP *)&DAT_0000009c;
              in_stack_ffffff83 = 'T';
              unaff_s4 = param_4;
              unaff_s5 = param_1;
              unaff_s6 = param_2;
              goto LAB_00563154;
            }
LAB_00563020:
            pAVar11 = *(ASN1_ITEM_EXP **)param_2;
            if ((ASN1_ITEM_EXP *)pcStack_1c4 == (ASN1_ITEM_EXP *)0x0) {
              local_48 = (ASN1_ITEM_EXP *)((int)&pAVar8->itype + (int)&local_38->itype);
              local_34 = (ASN1_ITEM_EXP *)0x0;
              param_5 = (ASN1_ITEM_EXP *)((int)local_38 - (int)pAVar11);
              unaff_s1 = (ASN1_ITEM_EXP *)((int)&pAVar8->itype + (int)&param_5->itype);
LAB_00562f0c:
              pcVar15 = &local_4d;
              pAVar12 = unaff_s1;
              pcStack_1c4 = &local_4c->itype;
              in_stack_ffffff84 = param_4;
              iVar7 = asn1_ex_c2i((ASN1_VALUE **)param_1,(uchar *)pAVar11,(int)unaff_s1,
                                  (int)local_4c,pcVar15,param_4);
              in_stack_ffffff83 = (char)pcVar15;
              pAVar8 = unaff_s1;
              if (iVar7 == 0) goto LAB_00563010;
              pAVar6 = (ASN1_ITEM_EXP *)0x1;
              *(ASN1_ITEM_EXP **)param_2 = local_48;
            }
            else {
              param_3 = (ASN1_ITEM_EXP *)0x1;
              if (0 < (int)pAVar8) {
                pAStack_1a8 = (ASN1_ITEM_EXP *)&local_38;
                do {
                  cVar19 = (char)in_stack_fffffed8;
                  if (((pAVar8 == (ASN1_ITEM_EXP *)0x1) || (param_5->itype != '\0')) ||
                     (param_5->field_0x1 != '\0')) {
                    local_38 = param_5;
                    uVar5 = ASN1_get_object((uchar **)pAStack_1a8,(long *)(local_44 + 8),
                                            (int *)local_44,(int *)(local_44 + 4),(long)pAVar8);
                    cVar19 = (char)in_stack_fffffed8;
                    if ((uVar5 & 0x80) != 0) {
                      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x68,0x66,s_tasn_dec_c_0066ab0c);
                      pcStack_1c4 = s_tasn_dec_c_0066ab0c;
                      pAVar12 = (ASN1_ITEM_EXP *)&DAT_0000003a;
                      pAVar11 = (ASN1_ITEM_EXP *)0xbe;
                      in_stack_ffffff83 = 'a';
                      pAVar6 = (ASN1_ITEM_EXP *)0x0;
                      (*(code *)PTR_ERR_put_error_006a9030)(0xd);
                      goto LAB_00562f3c;
                    }
                    pAVar12 = local_44._8_4_;
                    if (((uVar5 & 1) == 0) ||
                       (pAVar12 = (ASN1_ITEM_EXP *)((int)pAVar8 - ((int)local_38 - (int)param_5)),
                       (uVar5 & 1) == 0)) {
                      pAVar12 = (ASN1_ITEM_EXP *)((int)&pAVar12->itype + (int)&local_38->itype);
                      pAVar8 = (ASN1_ITEM_EXP *)((int)pAVar8 - ((int)pAVar12 - (int)param_5));
                      param_5 = pAVar12;
                    }
                    else {
                      param_3 = (ASN1_ITEM_EXP *)&param_3->field_0x1;
                      pAVar8 = (ASN1_ITEM_EXP *)((int)pAVar8 - ((int)local_38 - (int)param_5));
                      param_5 = local_38;
                    }
                  }
                  else {
                    param_3 = (ASN1_ITEM_EXP *)((int)&param_3[-1].sname + 3);
                    param_5 = (ASN1_ITEM_EXP *)&param_5->field_0x2;
                    if (param_3 == (ASN1_ITEM_EXP *)0x0) {
                      unaff_s1 = (ASN1_ITEM_EXP *)((int)param_5 + -(int)pAVar11);
                      local_48 = param_5;
                      goto LAB_00562f0c;
                    }
                    pAVar8 = (ASN1_ITEM_EXP *)((int)&pAVar8[-1].sname + 2);
                  }
                  cVar19 = (char)in_stack_fffffed8;
                } while (0 < (int)pAVar8);
              }
              pAVar12 = (ASN1_ITEM_EXP *)&DAT_00000089;
              pcStack_1c4 = s_tasn_dec_c_0066ab0c;
              in_stack_ffffff83 = 'l';
              pAVar11 = (ASN1_ITEM_EXP *)0xbe;
              (*(code *)PTR_ERR_put_error_006a9030)(0xd);
LAB_00563010:
              pAVar6 = (ASN1_ITEM_EXP *)0x0;
            }
LAB_00562f3c:
            param_8 = pAVar6;
            unaff_s1 = pAVar8;
            if (local_4d == '\0') goto LAB_00562d7c;
          }
          else {
            if (local_4c == (ASN1_ITEM_EXP *)0xfffffffd) {
              if (param_8 != (ASN1_ITEM_EXP *)0x0) {
                param_8->itype = 0;
              }
              goto LAB_00563020;
            }
            if ((uVar5 & 0x20) == 0) {
              local_48 = (ASN1_ITEM_EXP *)((int)&pAVar8->itype + (int)&local_38->itype);
              pAVar11 = local_38;
              goto LAB_00562f0c;
            }
            in_stack_ffffff83 = '\0';
            pAVar11 = (ASN1_ITEM_EXP *)&local_48;
            local_38 = (ASN1_ITEM_EXP *)0x0;
            local_30 = (ASN1_TEMPLATE *)0x0;
            local_34 = (ASN1_ITEM_EXP *)0x0;
            pAVar12 = pAVar8;
            iVar7 = asn1_collect_constprop_0((ASN1_ITEM_EXP *)&local_38);
            unaff_s1 = local_38;
            if (iVar7 != 0) {
              pAVar6 = (ASN1_ITEM_EXP *)
                       (*(code *)PTR_BUF_MEM_grow_clean_006a8c2c)
                                 ((ASN1_ITEM_EXP *)&local_38,&local_38->field_0x1);
              if (pAVar6 == (ASN1_ITEM_EXP *)0x0) {
                pAVar12 = (ASN1_ITEM_EXP *)&DAT_00000041;
                pcStack_1c4 = s_tasn_dec_c_0066ab0c;
                in_stack_ffffff83 = '|';
                pAVar11 = (ASN1_ITEM_EXP *)&DAT_0000006c;
                (*(code *)PTR_ERR_put_error_006a9030)(0xd);
                param_8 = (ASN1_ITEM_EXP *)&local_38;
                goto LAB_00562d7c;
              }
              *(undefined *)((int)&unaff_s1->itype + (int)&local_34->itype) = 0;
              local_4d = '\x01';
              pAVar11 = local_34;
              goto LAB_00562f0c;
            }
            pAVar6 = (ASN1_ITEM_EXP *)0x0;
            local_4d = '\x01';
            unaff_s1 = pAVar8;
          }
          param_8 = pAVar6;
          if (local_34 != (ASN1_ITEM_EXP *)0x0) {
            (*(code *)PTR_CRYPTO_free_006a7f88)();
          }
          goto LAB_00562d7c;
        }
        uVar13 = 0x66;
LAB_00562d40:
        (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x68,uVar13,s_tasn_dec_c_0066ab0c);
      }
      else {
        if (param_8->itype == '\0') {
          pcStack_1c4 = local_44 + 4;
          pAVar12 = param_3;
          uVar5 = ASN1_get_object((uchar **)&local_38,(long *)(local_44 + 8),(int *)local_44,
                                  (int *)pcStack_1c4,(long)param_3);
          cVar19 = (char)in_stack_fffffed8;
          in_stack_ffffff83 = (char)pAVar12;
          pAVar11 = (ASN1_ITEM_EXP *)(uVar5 & 0x81);
          param_8->funcs = local_44._4_4_;
          param_8->utype = uVar5;
          param_8->templates = (ASN1_TEMPLATE *)local_44._8_4_;
          param_8->size = (int)local_38 - (int)unaff_s1;
          param_8->tcount = (long)local_44._0_4_;
          pAVar12 = (ASN1_ITEM_EXP *)0x1;
          param_8->itype = 1;
          if ((pAVar11 != (ASN1_ITEM_EXP *)0x0) ||
             ((int)local_44._8_4_ + ((int)local_38 - (int)unaff_s1) <= (int)param_3))
          goto LAB_00562d04;
          uVar13 = 0x9b;
        }
        else {
          pAVar12 = (ASN1_ITEM_EXP *)param_8->templates;
          pAVar11 = (ASN1_ITEM_EXP *)param_8->funcs;
          local_44._0_4_ = (ASN1_ITEM_EXP *)param_8->tcount;
          local_38 = (ASN1_ITEM_EXP *)(param_8->size + (int)&unaff_s1->itype);
          uVar5 = param_8->utype;
          local_44._4_4_ = pAVar11;
          local_44._8_4_ = pAVar12;
LAB_00562d04:
          cVar19 = (char)in_stack_fffffed8;
          if ((uVar5 & 0x80) == 0) goto LAB_00562d0c;
          uVar13 = 0x66;
        }
        (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x68,uVar13,s_tasn_dec_c_0066ab0c);
        param_8->itype = 0;
      }
      unaff_s1 = (ASN1_ITEM_EXP *)0x670000;
      pcStack_1c4 = s_tasn_dec_c_0066ab0c;
      pAVar12 = (ASN1_ITEM_EXP *)&DAT_0000003a;
      pAVar11 = (ASN1_ITEM_EXP *)&DAT_0000006c;
      in_stack_ffffff83 = '?';
      (*(code *)PTR_ERR_put_error_006a9030)(0xd);
      param_5 = pAVar8;
    }
    pAVar6 = (ASN1_ITEM_EXP *)0x0;
  }
LAB_00562d7c:
  if (local_2c == *(ASN1_ITEM_EXP ***)AStack_16c.size) {
    return pAVar6;
  }
  pcStack_94 = asn1_template_noexp_d2i;
  pval = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar2 = PTR___stack_chk_guard_006aabf0;
  pAStack_98 = pAStack_1a8;
  pAStack_9c = param_3;
  pAStack_a0 = param_2;
  pAStack_a4 = param_1;
  pAStack_a8 = param_4;
  pAStack_ac = param_5;
  puStack_b0 = (undefined *)AStack_16c.size;
  pAStack_b4 = unaff_s1;
  pAStack_b8 = param_8;
  apAStack_88[0] = pAVar12;
  pAStack_bc = *(ASN1_ITEM_EXP **)PTR___stack_chk_guard_006aabf0;
  if (pval == (ASN1_ITEM_EXP **)0x0) {
    pAVar8 = (ASN1_ITEM_EXP *)0x0;
    pAStack_2b4 = pAVar11;
    pcVar15 = pcStack_1c4;
  }
  else {
    uVar5 = *(uint *)pcStack_1c4;
    in_stack_fffffedc = (ASN1_ITEM_EXP *)(uVar5 & 0xc0);
    auStack_d0 = (undefined  [4])*(ASN1_ITEM_EXP **)pAVar11;
    if ((uVar5 & 6) == 0) {
      if ((uVar5 & 8) == 0) {
        param_8 = (ASN1_ITEM_EXP *)0xffffffff;
        pcVar15 = *(char **)((int)pcStack_1c4 + 0x10);
        pAStack_2b4 = (ASN1_ITEM *)auStack_d0;
        in_stack_fffffedc = (ASN1_ITEM_EXP *)0x0;
        cVar19 = -1;
        iVar7 = ASN1_item_ex_d2i((ASN1_VALUE **)pval,(uchar **)pAStack_2b4,(long)pAVar12,
                                 (ASN1_ITEM *)pcVar15,-1,0,in_stack_ffffff83,
                                 (ASN1_TLC *)in_stack_ffffff84);
        if (iVar7 != 0) goto joined_r0x00563a7c;
        pAVar12 = (ASN1_ITEM_EXP *)&DAT_0000003a;
        cVar19 = -0x11;
      }
      else {
        iVar9 = *(long *)((int)pcStack_1c4 + 4);
        pAStack_2b4 = (ASN1_ITEM *)auStack_d0;
        pcVar15 = *(char **)((int)pcStack_1c4 + 0x10);
        iVar7 = ASN1_item_ex_d2i((ASN1_VALUE **)pval,(uchar **)pAStack_2b4,(long)pAVar12,
                                 (ASN1_ITEM *)pcVar15,iVar9,(int)in_stack_fffffedc,in_stack_ffffff83
                                 ,(ASN1_TLC *)in_stack_ffffff84);
        cVar19 = (char)iVar9;
        if (iVar7 != 0) {
joined_r0x00563a7c:
          param_8 = (ASN1_ITEM_EXP *)auStack_d0;
          auStack_d0 = (undefined  [4])param_8;
          if (iVar7 == -1) {
            pAVar8 = (ASN1_ITEM_EXP *)0xffffffff;
          }
          else {
LAB_00563500:
            pAVar11->itype = auStack_d0;
            pAVar8 = (ASN1_ITEM_EXP *)0x1;
            param_8 = (ASN1_ITEM_EXP *)auStack_d0;
          }
          goto LAB_005639d4;
        }
        pAVar12 = (ASN1_ITEM_EXP *)&DAT_0000003a;
        cVar19 = -0x1f;
      }
LAB_00563afc:
      pcVar15 = s_tasn_dec_c_0066ab0c;
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x83);
LAB_005639bc:
      pAStack_2b4 = (ASN1_ITEM *)pcStack_1c4;
      ASN1_template_free((ASN1_VALUE **)pval,(ASN1_TEMPLATE *)pcStack_1c4);
      pAVar8 = (ASN1_ITEM_EXP *)0x0;
    }
    else {
      param_2 = (ASN1_ITEM_EXP *)auStack_d0;
      pcVar15 = &uStack_d4;
      pAVar12 = (ASN1_ITEM_EXP *)0x0;
      pAStack_2b4 = (ASN1_ITEM *)0x0;
      pAVar18 = (ASN1_ITEM *)0x0;
      in_stack_fffffedc = param_2;
      iVar7 = asn1_check_tlen(apAStack_88);
      cVar19 = (char)pAVar18;
      if (iVar7 == 0) {
        pAVar12 = (ASN1_ITEM_EXP *)&DAT_0000003a;
        pcVar15 = s_tasn_dec_c_0066ab0c;
        cVar19 = -0x6d;
        pAStack_2b4 = (ASN1_ITEM_EXP *)0x83;
        (*(code *)PTR_ERR_put_error_006a9030)(0xd);
        pAVar8 = (ASN1_ITEM_EXP *)0x0;
      }
      else {
        pAVar8 = (ASN1_ITEM_EXP *)0xffffffff;
        if (iVar7 != -1) {
          param_8 = *pval;
          AStack_16c.size = (long)&pAStack_c0;
          if (param_8 == (ASN1_ITEM_EXP *)0x0) {
            pAVar8 = (ASN1_ITEM_EXP *)(*(code *)PTR_sk_new_null_006a80a4)();
            *pval = pAVar8;
          }
          else {
            while (iVar7 = (*(code *)PTR_sk_num_006a7f2c)(param_8), 0 < iVar7) {
              pAStack_c0 = (ASN1_ITEM *)(*(code *)PTR_sk_pop_006a9ec4)(param_8);
              pAStack_2b4 = *(ASN1_ITEM **)((int)pcStack_1c4 + 0x10);
              ASN1_item_ex_free((ASN1_VALUE **)AStack_16c.size,pAStack_2b4);
            }
            pAVar8 = *pval;
          }
          cVar19 = (char)pAVar18;
          if (pAVar8 == (ASN1_ITEM_EXP *)0x0) {
            pAVar12 = (ASN1_ITEM_EXP *)&DAT_00000041;
            cVar19 = -0x55;
            param_5 = apAStack_88[0];
          }
          else {
            if (0 < (int)apAStack_88[0]) {
LAB_0056345c:
              param_5 = apAStack_88[0];
              pAVar8 = (ASN1_ITEM_EXP *)auStack_d0;
              cVar19 = (char)pAVar18;
              if (((apAStack_88[0] != (ASN1_ITEM_EXP *)0x1) && (*(char *)auStack_d0 == '\0')) &&
                 (*(undefined *)((int)auStack_d0 + 1) == '\0')) {
                auStack_d0 = (undefined  [4])((int)auStack_d0 + 2);
                if (uStack_d4 != '\0') goto LAB_00563500;
                pAVar12 = (ASN1_ITEM_EXP *)0x9f;
                cVar19 = -0x46;
                param_8 = (ASN1_ITEM_EXP *)auStack_d0;
                goto LAB_00563afc;
              }
              pAStack_1a8 = *(ASN1_ITEM_EXP **)((int)pcStack_1c4 + 0x10);
              pAStack_cc = (ASN1_ITEM *)0x0;
              pAStack_c8 = apAStack_88[0];
              pAStack_c4 = (ASN1_ITEM_EXP *)0x0;
              param_1 = (ASN1_TEMPLATE *)pAStack_1a8->funcs;
              pAVar12 = apAStack_88[0];
              if (param_1 == (ASN1_TEMPLATE *)0x0) {
                switch(pAStack_1a8->itype) {
                case '\0':
                  goto switchD_00563a30_caseD_563790;
                case '\x01':
                case '\x06':
                  pAStack_f8 = (ASN1_ITEM_EXP *)0x0;
                  goto switchD_005634b4_caseD_1;
                case '\x02':
                  pAStack_f8 = (ASN1_ITEM_EXP *)0x0;
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
              pAStack_f8 = param_1->item;
              switch(pAStack_1a8->itype) {
              case '\0':
switchD_00563a30_caseD_563790:
                pcVar15 = (char *)pAStack_1a8->templates;
                if ((ASN1_ITEM_EXP *)pcVar15 == (ASN1_ITEM_EXP *)0x0) {
                  in_stack_fffffedc = (ASN1_ITEM_EXP *)0x0;
                  pAVar18 = (ASN1_ITEM *)0xffffffff;
                  pcVar15 = &pAStack_1a8->itype;
                  iVar7 = asn1_d2i_ex_primitive(auStack_d0 + 4,param_2);
                }
                else {
                  pAVar18 = (ASN1_ITEM *)0x0;
                  in_stack_fffffedc = in_stack_ffffff84;
                  iVar7 = asn1_template_ex_d2i(auStack_d0 + 4,param_2);
                }
                goto joined_r0x00563d40;
              case '\x01':
              case '\x06':
switchD_005634b4_caseD_1:
                param_4 = (ASN1_ITEM_EXP *)(auStack_d0 + 0xc);
                pcVar15 = &uStack_d2;
                pAVar12 = (ASN1_ITEM_EXP *)0x0;
                pAStack_c4 = (ASN1_ITEM_EXP *)auStack_d0;
                pAVar18 = (ASN1_ITEM *)&uStack_d1;
                in_stack_fffffedc = param_4;
                iVar7 = asn1_check_tlen(auStack_d0 + 8,0);
                if (iVar7 == 0) {
                  uVar13 = 0x3a;
                  goto LAB_00563824;
                }
                if (iVar7 == -1) goto LAB_0056354c;
                cVar19 = uStack_d2;
                if ((param_1 != (ASN1_TEMPLATE *)0x0) && ((param_1->tag & 4U) != 0)) {
                  param_5 = (ASN1_ITEM_EXP *)((int)param_5 - ((int)pAStack_c4 - (int)auStack_d0));
                  pAStack_c8 = param_5;
                  cVar19 = '\x01';
                }
                if (uStack_d1 == '\0') {
                  uVar13 = 0x95;
                  goto LAB_00563824;
                }
                AStack_16c.size = (long)(auStack_d0 + 4);
                if ((pAStack_cc == (ASN1_ITEM *)0x0) &&
                   (iVar7 = ASN1_item_ex_new((ASN1_VALUE **)AStack_16c.size,pAStack_1a8), iVar7 == 0
                   )) {
                  uVar13 = 0x3a;
LAB_00563954:
                  (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x78,uVar13,s_tasn_dec_c_0066ab0c);
                  goto LAB_00563968;
                }
                if ((pAStack_f8 != (ASN1_ITEM_EXP *)0x0) &&
                   (iVar7 = (*(code *)pAStack_f8)(4,AStack_16c.size,pAStack_1a8,0), iVar7 == 0))
                goto LAB_00563940;
                param_5 = (ASN1_ITEM_EXP *)0x0;
                param_1 = pAStack_1a8->templates;
                if (0 < pAStack_1a8->tcount) {
                  do {
                    param_3 = (ASN1_ITEM_EXP *)asn1_do_adb((ASN1_VALUE **)AStack_16c.size,param_1,1)
                    ;
                    if (param_3 == (ASN1_ITEM_EXP *)0x0) goto LAB_00563968;
                    ppAVar10 = asn1_get_field_ptr((ASN1_VALUE **)AStack_16c.size,
                                                  (ASN1_TEMPLATE *)param_3);
                    pAVar12 = pAStack_c4;
                    if (pAStack_c8 == (ASN1_ITEM_EXP *)0x0) {
                      if (uStack_d2 == '\0') goto LAB_00563c68;
                      goto LAB_00563e08;
                    }
                    if (((1 < (int)pAStack_c8) && (pAStack_c4->itype == '\0')) &&
                       (pAStack_c4->field_0x1 == '\0')) {
                      pAStack_c4 = (ASN1_ITEM_EXP *)&pAStack_c4->field_0x2;
                      if (uStack_d2 == '\0') {
                        uVar13 = 0x9f;
                        goto LAB_00563954;
                      }
                      pAStack_c8 = (ASN1_ITEM_EXP *)((int)&pAStack_c8[-1].sname + 2);
                      uStack_d2 = '\0';
                      goto LAB_00563c54;
                    }
                    pAVar18 = (ASN1_ITEM *)0x0;
                    if ((ASN1_ITEM_EXP *)(pAStack_1a8->tcount + -1) != param_5) {
                      pAVar18 = (ASN1_ITEM *)(*(uint *)param_3 & 1);
                    }
                    in_stack_fffffedc = in_stack_ffffff84;
                    iVar7 = asn1_template_ex_d2i(ppAVar10,param_4,pAStack_c8,param_3);
                    if (iVar7 == 0) goto LAB_00563e24;
                    if (iVar7 == -1) {
                      ASN1_template_free(ppAVar10,(ASN1_TEMPLATE *)param_3);
                    }
                    else {
                      pAStack_c8 = (ASN1_ITEM_EXP *)
                                   ((int)pAStack_c8 - ((int)pAStack_c4 - (int)pAVar12));
                    }
                    param_5 = (ASN1_ITEM_EXP *)&param_5->field_0x1;
                    param_1 = param_1 + 1;
                  } while ((int)param_5 < pAStack_1a8->tcount);
                }
                if (uStack_d2 != '\0') {
                  if ((((int)pAStack_c8 < 2) || (pAStack_c4->itype != '\0')) ||
                     (pAStack_c4->field_0x1 != '\0')) {
LAB_00563e08:
                    uVar13 = 0x89;
                    goto LAB_00563954;
                  }
                  pAStack_c4 = (ASN1_ITEM_EXP *)&pAStack_c4->field_0x2;
                }
LAB_00563c54:
                if ((cVar19 == '\0') && (pAStack_c8 != (ASN1_ITEM_EXP *)0x0)) {
                  uVar13 = 0x94;
                  goto LAB_00563954;
                }
LAB_00563c68:
                if ((int)param_5 < pAStack_1a8->tcount) {
LAB_00563ccc:
                  param_3 = (ASN1_ITEM_EXP *)asn1_do_adb((ASN1_VALUE **)AStack_16c.size,param_1,1);
                  if (param_3 != (ASN1_ITEM_EXP *)0x0) {
                    if ((*(uint *)param_3 & 1) != 0) goto code_r0x00563c90;
                    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x78,0x79,s_tasn_dec_c_0066ab0c);
LAB_00563e24:
                    ASN1_item_ex_free((ASN1_VALUE **)AStack_16c.size,pAStack_1a8);
LAB_00563d8c:
                    param_4 = (ASN1_ITEM_EXP *)(auStack_d0 + 0xc);
                    AStack_16c.size = (long)(auStack_d0 + 4);
                    (*(code *)PTR_ERR_add_error_data_006a9264)
                              (4,&DAT_0066ab20,param_3->tcount,", Type=");
                    goto switchD_005634b4_caseD_7;
                  }
                  goto LAB_00563968;
                }
LAB_00563eac:
                pAVar12 = (ASN1_ITEM_EXP *)((int)pAStack_c4 - (int)auStack_d0);
                pcVar15 = &pAStack_1a8->itype;
                iVar7 = asn1_enc_save((ASN1_VALUE **)AStack_16c.size,(uchar *)auStack_d0,
                                      (int)pAVar12,pAStack_1a8);
                if (iVar7 == 0) goto LAB_00563940;
                auStack_d0 = (undefined  [4])pAStack_c4;
                if (pAStack_f8 != (ASN1_ITEM_EXP *)0x0) goto LAB_00563924;
                iVar7 = (int)pAStack_c4 - (int)pAVar8;
                goto LAB_00563550;
              case '\x02':
                if (pAStack_f8 == (ASN1_ITEM_EXP *)0x0) {
LAB_00563b38:
                  iVar7 = ASN1_item_ex_new((ASN1_VALUE **)(auStack_d0 + 4),pAStack_1a8);
                  if (iVar7 == 0) {
                    uVar13 = 0x3a;
                  }
                  else {
LAB_00563878:
                    AStack_16c.size = (long)(auStack_d0 + 4);
                    param_5 = (ASN1_ITEM_EXP *)0x0;
                    pAVar12 = (ASN1_ITEM_EXP *)pAStack_1a8->tcount;
                    param_3 = (ASN1_ITEM_EXP *)pAStack_1a8->templates;
                    pAStack_c4 = (ASN1_ITEM_EXP *)auStack_d0;
                    if (0 < (int)pAVar12) {
                      param_4 = (ASN1_ITEM_EXP *)(auStack_d0 + 0xc);
                      param_1 = (ASN1_TEMPLATE *)0xffffffff;
                      do {
                        ppAVar10 = asn1_get_field_ptr((ASN1_VALUE **)AStack_16c.size,
                                                      (ASN1_TEMPLATE *)param_3);
                        pAVar18 = (ASN1_ITEM *)0x1;
                        pcVar15 = &param_3->itype;
                        in_stack_fffffedc = in_stack_ffffff84;
                        iVar7 = asn1_template_ex_d2i(ppAVar10,param_4,pAStack_c8);
                        if (iVar7 != -1) {
                          if (iVar7 < 1) {
                            (*(code *)PTR_ERR_put_error_006a9030)
                                      (0xd,0x78,0x3a,s_tasn_dec_c_0066ab0c);
                            ASN1_item_ex_free((ASN1_VALUE **)AStack_16c.size,pAStack_1a8);
                            if (param_3 == (ASN1_ITEM_EXP *)0x0) goto LAB_0056397c;
                            goto LAB_00563d8c;
                          }
                          pAVar12 = (ASN1_ITEM_EXP *)pAStack_1a8->tcount;
                          break;
                        }
                        pAVar12 = (ASN1_ITEM_EXP *)pAStack_1a8->tcount;
                        param_5 = (ASN1_ITEM_EXP *)&param_5->field_0x1;
                        param_3 = (ASN1_ITEM_EXP *)&param_3->size;
                      } while ((int)param_5 < (int)pAVar12);
                    }
                    if (param_5 != pAVar12) {
                      pAVar12 = pAStack_1a8;
                      asn1_set_choice_selector
                                ((ASN1_VALUE **)AStack_16c.size,(int)param_5,pAStack_1a8);
                      auStack_d0 = (undefined  [4])pAStack_c4;
                      if (pAStack_f8 == (ASN1_ITEM_EXP *)0x0) goto LAB_0056354c;
LAB_00563924:
                      AStack_16c.size = (long)(auStack_d0 + 4);
                      pcVar15 = (char *)0x0;
                      pAVar12 = pAStack_1a8;
                      auStack_d0 = (undefined  [4])pAStack_c4;
                      iVar7 = (*(code *)pAStack_f8)(5,AStack_16c.size);
                      if (iVar7 != 0) goto LAB_0056354c;
                      goto LAB_00563940;
                    }
                    uVar13 = 0x8f;
                  }
                }
                else {
                  pcVar15 = (char *)0x0;
                  iVar7 = (*(code *)pAStack_f8)(4,auStack_d0 + 4,pAStack_1a8);
                  if (iVar7 != 0) {
                    if (pAStack_cc == (ASN1_ITEM *)0x0) goto LAB_00563b38;
                    goto LAB_00563878;
                  }
LAB_00563940:
                  uVar13 = 100;
                }
                goto LAB_00563954;
              case '\x03':
switchD_00563a30_caseD_5635a8:
                AStack_16c.size = (long)(auStack_d0 + 4);
                iVar7 = (*(code *)param_1->offset)(AStack_16c.size,param_2);
                if (iVar7 == 0) {
                  uVar13 = 0x3a;
                  goto LAB_00563954;
                }
                goto LAB_0056354c;
              case '\x04':
switchD_00563a30_caseD_563510:
                in_stack_fffffedc = (ASN1_ITEM_EXP *)0x0;
                pAVar18 = (ASN1_ITEM *)0xffffffff;
                pcVar15 = &pAStack_1a8->itype;
                iVar7 = (*(code *)param_1->item)(auStack_d0 + 4,param_2);
joined_r0x00563d40:
                if (iVar7 == 0) goto switchD_005634b4_caseD_7;
LAB_0056354c:
                iVar7 = (int)auStack_d0 - (int)pAVar8;
LAB_00563550:
                param_8 = (ASN1_ITEM_EXP *)((int)apAStack_88[0] - iVar7);
                pAStack_2b4 = pAStack_cc;
                apAStack_88[0] = param_8;
                iVar7 = (*(code *)PTR_sk_push_006a80a8)(*pval);
                cVar19 = (char)pAVar18;
                if (iVar7 != 0) goto code_r0x00563578;
                pAVar12 = (ASN1_ITEM_EXP *)&DAT_00000041;
                cVar19 = -0x31;
                goto LAB_00563afc;
              case '\x05':
switchD_00563a30_caseD_5637c4:
                param_4 = (ASN1_ITEM_EXP *)(auStack_d0 + 0xc);
                pAStack_c4 = (ASN1_ITEM_EXP *)auStack_d0;
                in_stack_fffffedc = param_4;
                iVar7 = asn1_check_tlen_constprop_1(0,&pAStack_c0,&cStack_d3,0);
                if (iVar7 == 0) {
                  uVar13 = 0x3a;
                }
                else if (cStack_d3 == '\0') {
                  if ((pAStack_c0 < (ASN1_ITEM *)0x1f) &&
                     ((*(uint *)(tag2bit + (int)pAStack_c0 * 4) & pAStack_1a8->utype) != 0)) {
                    in_stack_fffffedc = (ASN1_ITEM_EXP *)0x0;
                    pAVar12 = pAStack_c8;
                    pcVar15 = &pAStack_1a8->itype;
                    pAVar18 = pAStack_c0;
                    iVar7 = asn1_d2i_ex_primitive(auStack_d0 + 4,param_2);
                    goto joined_r0x00563d40;
                  }
                  uVar13 = 0x8c;
                }
                else {
                  uVar13 = 0x8b;
                }
LAB_00563824:
                param_4 = (ASN1_ITEM_EXP *)(auStack_d0 + 0xc);
                (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x78,uVar13,s_tasn_dec_c_0066ab0c);
LAB_00563968:
                ASN1_item_ex_free((ASN1_VALUE **)(auStack_d0 + 4),pAStack_1a8);
LAB_0056397c:
                AStack_16c.size = (long)(auStack_d0 + 4);
                (*(code *)PTR_ERR_add_error_data_006a9264)(2,s_Type__0066ab28,pAStack_1a8->sname);
              default:
switchD_005634b4_caseD_7:
                param_8 = (ASN1_ITEM_EXP *)0x670000;
                pcVar15 = s_tasn_dec_c_0066ab0c;
                pAVar12 = (ASN1_ITEM_EXP *)&DAT_0000003a;
                cVar19 = -0x39;
                (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x83);
              }
              goto LAB_005639bc;
            }
LAB_00563584:
            param_5 = apAStack_88[0];
            if (uStack_d4 == '\0') goto LAB_00563500;
            pAVar12 = (ASN1_ITEM_EXP *)&DAT_00000089;
            cVar19 = -0x2b;
            param_8 = (ASN1_ITEM_EXP *)auStack_d0;
          }
          goto LAB_00563afc;
        }
      }
    }
  }
LAB_005639d4:
  if (pAStack_bc == *(ASN1_ITEM_EXP **)puVar2) {
    return pAVar8;
  }
  pcStack_13c = asn1_template_ex_d2i;
  pAVar8 = pAStack_bc;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_1c0 = PTR___stack_chk_guard_006aabf0;
  pAStack_148 = param_2;
  pAStack_230 = (ASN1_ITEM_EXP *)(int)cVar19;
  AStack_16c.tcount = (long)param_8;
  pAStack_140 = pAStack_1a8;
  pAStack_144 = param_3;
  pAStack_14c = param_1;
  pAStack_150 = param_4;
  AStack_16c.sname = &param_5->itype;
  AStack_16c.funcs = pcStack_1c4;
  AStack_16c.templates = (ASN1_TEMPLATE *)*(ASN1_ITEM_EXP **)PTR___stack_chk_guard_006aabf0;
  pAVar11 = pAStack_2b4;
  pcVar16 = pcVar15;
  if (pAVar8 == (ASN1_ITEM_EXP *)0x0) {
    pAVar8 = (ASN1_ITEM_EXP *)0x0;
    pAVar6 = pAVar12;
  }
  else {
    pAStack_1a8 = *(ASN1_ITEM_EXP **)pcVar15;
    pcStack_1c4 = *(char **)pAStack_2b4;
    pAStack_178 = (ASN1_ITEM_EXP *)pcStack_1c4;
    param_5 = (ASN1_ITEM_EXP *)pcVar15;
    if (((uint)pAStack_1a8 & 0x10) == 0) {
      pAVar8 = (ASN1_ITEM_EXP *)asn1_template_noexp_d2i();
      pAVar6 = pAVar12;
    }
    else {
      iVar7 = *(long *)((int)pcVar15 + 4);
      param_4 = pAVar8;
      param_3 = pAVar12;
      AStack_16c.utype = (long)pcStack_1c4;
      if (in_stack_fffffedc == (ASN1_ITEM_EXP *)0x0) {
        pcVar16 = auStack_174 + 4;
        pAVar6 = (ASN1_ITEM_EXP *)auStack_174;
        pAVar11 = &AStack_16c;
        uVar5 = ASN1_get_object((uchar **)((int)&AStack_16c + 4),(long *)pAVar11,(int *)pAVar6,
                                (int *)pcVar16,(long)pAVar12);
        if ((uVar5 & 0x80) == 0) {
LAB_0056403c:
          pAVar4 = (ASN1_ITEM_EXP *)AStack_16c.utype;
          if (-1 < iVar7) {
            if ((iVar7 != auStack_174._0_4_) ||
               (pAStack_1a8 = (ASN1_ITEM_EXP *)((uint)pAStack_1a8 & 0xc0),
               pAStack_1a8 != auStack_174._4_4_)) {
              pAVar8 = (ASN1_ITEM_EXP *)0xffffffff;
              if (pAStack_230 != (ASN1_ITEM_EXP *)0x0) goto LAB_005640c0;
              if (in_stack_fffffedc != (ASN1_ITEM_EXP *)0x0) {
                in_stack_fffffedc->itype = '\0';
              }
              uVar13 = 0xa8;
              goto LAB_00564070;
            }
            if (in_stack_fffffedc != (ASN1_ITEM_EXP *)0x0) {
              in_stack_fffffedc->itype = '\0';
            }
          }
          param_3 = AStack_16c._0_4_;
          if ((uVar5 & 1) != 0) {
            param_3 = (ASN1_ITEM_EXP *)((int)pAVar12 - (AStack_16c.utype - (int)pcStack_1c4));
          }
          pcStack_1c4 = (char *)(int)(char)uVar5;
          pAStack_178 = (ASN1_ITEM_EXP *)AStack_16c.utype;
          if (((uint)pcStack_1c4 & 0x20) == 0) {
            pAVar6 = (ASN1_ITEM_EXP *)&DAT_00000078;
          }
          else {
            pAVar11 = (ASN1_ITEM_EXP *)&pAStack_178;
            pAVar6 = param_3;
            pcVar16 = pcVar15;
            iVar7 = asn1_template_noexp_d2i(pAVar8);
            if (iVar7 != 0) {
              pAStack_230 = (ASN1_ITEM_EXP *)((int)pAStack_178 - (int)pAVar4);
              param_3 = (ASN1_ITEM_EXP *)((int)param_3 - (int)pAStack_230);
              if (((uint)pcStack_1c4 & 1) == 0) {
                pAVar12 = pAStack_178;
                if (param_3 != (ASN1_ITEM_EXP *)0x0) {
                  pAVar6 = (ASN1_ITEM_EXP *)&DAT_00000077;
                  goto LAB_005642ac;
                }
              }
              else {
                param_3 = (ASN1_ITEM_EXP *)(uint)((int)param_3 < 2);
                if (((param_3 != (ASN1_ITEM_EXP *)0x0) || (pAStack_178->itype != '\0')) ||
                   (pAVar12 = (ASN1_ITEM_EXP *)&pAStack_178->field_0x2,
                   pAStack_178->field_0x1 != '\0')) {
                  pAVar6 = (ASN1_ITEM_EXP *)&DAT_00000089;
LAB_005642ac:
                  pcVar16 = s_tasn_dec_c_0066ab0c;
                  (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x84);
                  pAVar11 = (ASN1_ITEM_EXP *)pcVar15;
                  ASN1_template_free((ASN1_VALUE **)pAVar8,(ASN1_TEMPLATE *)pcVar15);
                  pAVar8 = (ASN1_ITEM_EXP *)0x0;
                  goto LAB_005640c0;
                }
              }
              *(ASN1_ITEM_EXP **)pAStack_2b4 = pAVar12;
              pAVar8 = (ASN1_ITEM_EXP *)0x1;
              goto LAB_005640c0;
            }
            pAVar6 = (ASN1_ITEM_EXP *)&DAT_0000003a;
          }
          pcVar16 = s_tasn_dec_c_0066ab0c;
          pAVar11 = (ASN1_ITEM_EXP *)&DAT_00000084;
          (*(code *)PTR_ERR_put_error_006a9030)(0xd);
          pAVar8 = (ASN1_ITEM_EXP *)0x0;
          pAStack_230 = pAVar4;
          goto LAB_005640c0;
        }
        uVar13 = 0x66;
LAB_00564070:
        (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x68,uVar13,s_tasn_dec_c_0066ab0c);
      }
      else {
        if (in_stack_fffffedc->itype == '\0') {
          pcVar16 = auStack_174 + 4;
          uVar5 = ASN1_get_object((uchar **)((int)&AStack_16c + 4),(long *)&AStack_16c,
                                  (int *)auStack_174,(int *)pcVar16,(long)pAVar12);
          pAVar11 = (ASN1_ITEM_EXP *)(uVar5 & 0x81);
          in_stack_fffffedc->funcs = auStack_174._4_4_;
          in_stack_fffffedc->utype = uVar5;
          in_stack_fffffedc->templates = (ASN1_TEMPLATE *)AStack_16c._0_4_;
          in_stack_fffffedc->tcount = auStack_174._0_4_;
          pAVar6 = (ASN1_ITEM_EXP *)0x1;
          in_stack_fffffedc->size = AStack_16c.utype - (int)pcStack_1c4;
          in_stack_fffffedc->itype = '\x01';
          if ((pAVar11 != (ASN1_ITEM_EXP *)0x0) ||
             ((int)((int)AStack_16c._0_4_ + (AStack_16c.utype - (int)pcStack_1c4)) <= (int)pAVar12))
          goto LAB_00564034;
          uVar13 = 0x9b;
        }
        else {
          pAVar6 = (ASN1_ITEM_EXP *)in_stack_fffffedc->templates;
          pAVar11 = (ASN1_ITEM_EXP *)in_stack_fffffedc->funcs;
          auStack_174._0_4_ = in_stack_fffffedc->tcount;
          AStack_16c.utype = (long)(pcStack_1c4 + in_stack_fffffedc->size);
          uVar5 = in_stack_fffffedc->utype;
          auStack_174._4_4_ = pAVar11;
          AStack_16c._0_4_ = pAVar6;
LAB_00564034:
          if ((uVar5 & 0x80) == 0) goto LAB_0056403c;
          uVar13 = 0x66;
        }
        (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x68,uVar13,s_tasn_dec_c_0066ab0c);
        in_stack_fffffedc->itype = '\0';
      }
      pcStack_1c4 = "r";
      pcVar16 = s_tasn_dec_c_0066ab0c;
      pAVar6 = (ASN1_ITEM_EXP *)&DAT_0000003a;
      pAVar11 = (ASN1_ITEM_EXP *)&DAT_00000084;
      (*(code *)PTR_ERR_put_error_006a9030)(0xd);
      pAVar8 = (ASN1_ITEM_EXP *)0x0;
    }
  }
LAB_005640c0:
  if ((ASN1_ITEM_EXP *)AStack_16c.templates == *(ASN1_ITEM_EXP **)puStack_1c0) {
    return pAVar8;
  }
  pcStack_1a4 = ASN1_item_ex_d2i;
  pAVar12 = (ASN1_ITEM_EXP *)AStack_16c.templates;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_244 = PTR___stack_chk_guard_006aabf0;
  pAStack_1ac = param_3;
  pAStack_1b0 = pAStack_230;
  pAStack_1b4 = pAStack_2b4;
  pAStack_1b8 = param_4;
  pAStack_1bc = param_5;
  pAStack_1c8 = in_stack_fffffedc;
  puStack_1f0 = &_gp;
  pAStack_198 = pAVar6;
  uStack_1d4 = 0;
  pAVar8 = *(ASN1_ITEM_EXP **)PTR___stack_chk_guard_006aabf0;
  pvStack_240 = *(void **)((int)pcVar16 + 0x10);
  pAStack_1cc = pAVar8;
  pAStack_2a8 = pAStack_1a8;
  if (pAVar12 != (ASN1_ITEM_EXP *)0x0) {
    if (pvStack_240 == (void *)0x0) {
      bVar1 = *pcVar16;
      uStack_1e4 = 0;
    }
    else {
      uStack_1e4 = *(undefined4 *)((int)pvStack_240 + 0x10);
      bVar1 = *pcVar16;
    }
    in_stack_fffffedc = pAVar12;
    param_4 = pAVar11;
    pAStack_2a8 = (ASN1_ITEM_EXP *)pcVar16;
    if (bVar1 < 7) {
                    /* WARNING: Could not recover jumptable at 0x00564400. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      pAVar12 = (ASN1_ITEM_EXP *)(*(code *)(&PTR_LAB_0066ab68)[bVar1])();
      return pAVar12;
    }
  }
  if (pAVar8 == *(ASN1_ITEM_EXP **)PTR___stack_chk_guard_006aabf0) {
    return (ASN1_ITEM_EXP *)0x0;
  }
  pcStack_224 = ASN1_template_d2i;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_2c4 = PTR___stack_chk_guard_006aabf0;
  pAStack_228 = pAStack_2a8;
  uStack_22c = 0xffffffe0;
  pAStack_234 = pAStack_2b4;
  pAStack_238 = param_4;
  pAStack_23c = param_5;
  pAStack_248 = in_stack_fffffedc;
  uStack_264 = 0;
  pAStack_24c = *(ASN1_ITEM_EXP **)PTR___stack_chk_guard_006aabf0;
  pAStack_2c0 = (ASN1_ITEM_EXP *)0x0;
  pcVar15 = &pAVar11->itype;
  it = pcVar16;
  pAStack_2b0 = pAStack_230;
  pAStack_2ac = (ASN1_ITEM_EXP *)0xffffffe0;
  if (pAVar8 != (ASN1_ITEM_EXP *)0x0) {
    pAStack_2b4 = *(ASN1_ITEM **)pcVar16;
    in_stack_fffffedc = *(ASN1_ITEM_EXP **)pAVar11;
    pAStack_278 = in_stack_fffffedc;
    param_5 = (ASN1_ITEM_EXP *)pcVar16;
    pAStack_2b0 = pAVar11;
    if (((uint)pAStack_2b4 & 0x10) == 0) {
      pAStack_2c0 = (ASN1_ITEM_EXP *)asn1_template_noexp_d2i();
    }
    else {
      iVar7 = *(long *)((int)pcVar16 + 4);
      pAStack_268 = in_stack_fffffedc;
      pcStack_260 = (char *)ASN1_get_object((uchar **)&pAStack_268,(long *)&pAStack_26c,&iStack_274,
                                            (int *)&pAStack_270,(long)pAVar6);
      pAVar12 = pAStack_268;
      iStack_250 = (int)pAStack_268 - (int)in_stack_fffffedc;
      pAStack_25c = pAStack_26c;
      pAStack_254 = pAStack_270;
      iStack_258 = iStack_274;
      uStack_264 = 1;
      param_4 = pAVar8;
      pAStack_2ac = pAVar6;
      pAStack_2a8 = pAStack_26c;
      if ((((uint)pcStack_260 & 0x81) == 0) && ((int)pAVar6 < (int)((int)pAStack_26c + iStack_250)))
      {
        uVar13 = 0x9b;
LAB_00564fdc:
        (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x68,uVar13,s_tasn_dec_c_0066ab0c);
        uStack_264 = 0;
      }
      else {
        pAStack_2c0 = (ASN1_ITEM_EXP *)((uint)pcStack_260 & 0x80);
        if (pAStack_2c0 != (ASN1_ITEM_EXP *)0x0) {
          uVar13 = 0x66;
          goto LAB_00564fdc;
        }
        if (iVar7 < 0) {
LAB_00564f84:
          pAStack_2b4 = (ASN1_ITEM *)(int)(char)pcStack_260;
          pAStack_278 = pAStack_268;
          in_stack_fffffedc = (ASN1_ITEM_EXP *)((int)pAVar6 - iStack_250);
          if (((uint)pcStack_260 & 1) != 0) {
            pAStack_2a8 = in_stack_fffffedc;
          }
          if (((uint)pAStack_2b4 & 0x20) == 0) {
            pAVar6 = (ASN1_ITEM_EXP *)&DAT_00000078;
          }
          else {
            pcVar15 = (char *)&pAStack_278;
            pAVar6 = pAStack_2a8;
            iVar7 = asn1_template_noexp_d2i(pAVar8);
            if (iVar7 != 0) {
              pAStack_2b4 = (ASN1_ITEM *)((uint)pAStack_2b4 & 1);
              pAStack_2a8 = (ASN1_ITEM_EXP *)((int)pAStack_2a8 - ((int)pAStack_278 - (int)pAVar12));
              if (pAStack_2b4 == (ASN1_ITEM_EXP *)0x0) {
                pAVar12 = pAStack_278;
                if (pAStack_2a8 != (ASN1_ITEM_EXP *)0x0) {
                  pAVar6 = (ASN1_ITEM_EXP *)&DAT_00000077;
                  goto LAB_0056508c;
                }
              }
              else {
                pAStack_2a8 = (ASN1_ITEM_EXP *)(uint)((int)pAStack_2a8 < 2);
                if (((pAStack_2a8 != (ASN1_ITEM_EXP *)0x0) || (pAStack_278->itype != '\0')) ||
                   (pAStack_278->field_0x1 != '\0')) {
                  pAVar6 = (ASN1_ITEM_EXP *)&DAT_00000089;
LAB_0056508c:
                  it = s_tasn_dec_c_0066ab0c;
                  (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x84);
                  pcVar15 = pcVar16;
                  ASN1_template_free((ASN1_VALUE **)pAVar8,(ASN1_TEMPLATE *)pcVar16);
                  goto LAB_00564e40;
                }
                pAVar12 = (ASN1_ITEM_EXP *)&pAStack_278->field_0x2;
              }
              *(ASN1_ITEM_EXP **)pAVar11 = pAVar12;
              pAStack_2c0 = (ASN1_ITEM_EXP *)0x1;
              goto LAB_00564e40;
            }
            pAVar6 = (ASN1_ITEM_EXP *)&DAT_0000003a;
          }
          it = s_tasn_dec_c_0066ab0c;
          pcVar15 = &DAT_00000084;
          (*(code *)PTR_ERR_put_error_006a9030)(0xd);
          goto LAB_00564e40;
        }
        if ((iVar7 == iStack_274) &&
           (pAStack_2b4 = (ASN1_ITEM *)((uint)pAStack_2b4 & 0xc0), pAStack_2b4 == pAStack_270)) {
          uStack_264 = 0;
          goto LAB_00564f84;
        }
        uStack_264 = 0;
        (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x68,0xa8,s_tasn_dec_c_0066ab0c);
      }
      in_stack_fffffedc = (ASN1_ITEM_EXP *)0x670000;
      it = s_tasn_dec_c_0066ab0c;
      pAVar6 = (ASN1_ITEM_EXP *)&DAT_0000003a;
      pcVar15 = &DAT_00000084;
      pAStack_2c0 = (ASN1_ITEM_EXP *)0x0;
      (*(code *)PTR_ERR_put_error_006a9030)(0xd);
    }
  }
LAB_00564e40:
  if (pAStack_24c == *(ASN1_ITEM_EXP **)puStack_2c4) {
    return pAStack_2c0;
  }
  pcStack_2a4 = ASN1_item_d2i;
  pAVar12 = pAStack_24c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar2 = PTR___stack_chk_guard_006aabf0;
  pvVar17 = *(void **)((int)it + 0x10);
  pAStack_2c8 = in_stack_fffffedc;
  pAStack_2b8 = param_4;
  pAStack_2bc = param_5;
  auStack_2f4 = (undefined  [4])0x0;
  auStack_2e4[0] = 0;
  pAStack_2f0 = pAVar6;
  pAStack_2ec = (ASN1_TEMPLATE *)0x0;
  pAVar8 = (ASN1_ITEM_EXP *)auStack_2f4;
  if (pAVar12 != (ASN1_ITEM_EXP *)0x0) {
    pAVar8 = pAVar12;
  }
  piStack_2cc = *(int **)PTR___stack_chk_guard_006aabf0;
  if (pvVar17 == (void *)0x0) {
    switch(*it) {
    case '\0':
      goto switchD_00565630_caseD_0;
    case '\x01':
    case '\x06':
      pcStack_308 = (code *)0x0;
      goto switchD_005651a0_caseD_1;
    case '\x02':
      pcStack_308 = (code *)0x0;
LAB_005651ac:
      if ((*(int *)pAVar8 == 0) &&
         (iVar7 = ASN1_item_ex_new((ASN1_VALUE **)pAVar8,(ASN1_ITEM *)it), iVar7 == 0)) {
        uVar14 = 0x3a;
        uVar13 = 0x13e;
        goto LAB_00565288;
      }
      pAStack_2ec = *(ASN1_TEMPLATE **)pcVar15;
      pAVar12 = (ASN1_ITEM_EXP *)0x0;
      pAVar11 = *(ASN1_ITEM_EXP **)((int)it + 0xc);
      tt = *(ASN1_TEMPLATE **)((int)it + 8);
      if ((int)pAVar11 < 1) {
LAB_00565228:
        if (pAVar12 == pAVar11) {
LAB_0056566c:
          uVar14 = 0x8f;
          uVar13 = 0x162;
          goto LAB_00565288;
        }
      }
      else {
        do {
          ppAVar10 = asn1_get_field_ptr((ASN1_VALUE **)pAVar8,tt);
          iVar7 = asn1_template_ex_d2i(ppAVar10,auStack_2f4 + 8,pAStack_2f0,tt,1,auStack_2e4);
          if (iVar7 != -1) {
            if (0 < iVar7) {
              pAVar11 = *(ASN1_ITEM_EXP **)((int)it + 0xc);
              goto LAB_00565228;
            }
            (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x78,0x3a,s_tasn_dec_c_0066ab0c,0x153);
            ASN1_item_ex_free((ASN1_VALUE **)pAVar8,(ASN1_ITEM *)it);
            if (tt != (ASN1_TEMPLATE *)0x0) goto LAB_005657fc;
            goto LAB_005652b4;
          }
          pAVar12 = (ASN1_ITEM_EXP *)&pAVar12->field_0x1;
          tt = tt + 1;
        } while ((int)pAVar12 < (int)*(undefined **)((int)it + 0xc));
        if (pAVar12 == (ASN1_ITEM_EXP *)*(undefined **)((int)it + 0xc)) goto LAB_0056566c;
      }
      asn1_set_choice_selector((ASN1_VALUE **)pAVar8,(int)pAVar12,(ASN1_ITEM *)it);
      *(ASN1_TEMPLATE **)pcVar15 = pAStack_2ec;
      if (pcStack_308 == (code *)0x0) goto LAB_00565328;
      goto LAB_00565258;
    case '\x03':
      goto switchD_00565630_caseD_3;
    case '\x04':
      pcStack_308 = *(code **)(in_zero + 0x10);
      goto LAB_005655ac;
    case '\x05':
      goto switchD_00565630_caseD_5;
    }
    goto switchD_00565630_caseD_7;
  }
  pcStack_308 = *(code **)((int)pvVar17 + 0x10);
  switch(*it) {
  case '\0':
switchD_00565630_caseD_0:
    if (*(ASN1_TEMPLATE **)((int)it + 8) == (ASN1_TEMPLATE *)0x0) {
      iVar7 = asn1_d2i_ex_primitive(pAVar8,pcVar15,pAVar6,it,0xffffffff,0,0,auStack_2e4);
      if (iVar7 < 1) {
        pAVar11 = (ASN1_ITEM_EXP *)0x0;
        pAVar12 = (ASN1_ITEM_EXP *)pcVar15;
        goto LAB_005652d0;
      }
    }
    else {
      iVar7 = asn1_template_ex_d2i
                        (pAVar8,pcVar15,pAVar6,*(ASN1_TEMPLATE **)((int)it + 8),0,auStack_2e4);
      if (iVar7 < 1) goto switchD_00565630_caseD_7;
    }
    goto LAB_005653f0;
  case '\x01':
  case '\x06':
switchD_005651a0_caseD_1:
    pAStack_2ec = *(ASN1_TEMPLATE **)pcVar15;
    pAVar12 = (ASN1_ITEM_EXP *)0x0;
    iVar7 = asn1_check_tlen(auStack_2f4 + 4,0,0,&cStack_2f6,&cStack_2f5,auStack_2f4 + 8,pAVar6,0x10,
                            0,0,auStack_2e4);
    if (iVar7 == 0) {
      uVar14 = 0x3a;
      uVar13 = 0x17d;
    }
    else {
      pAVar11 = (ASN1_ITEM_EXP *)0x0;
      if (iVar7 == -1) goto LAB_005652d0;
      cVar19 = cStack_2f6;
      if ((pvVar17 != (void *)0x0) && ((*(uint *)((int)pvVar17 + 4) & 4) != 0)) {
        pAStack_2f0 = (ASN1_ITEM_EXP *)((int)pAVar6 - ((int)pAStack_2ec - *(int *)pcVar15));
        cVar19 = '\x01';
      }
      if (cStack_2f5 == '\0') {
        uVar14 = 0x95;
        uVar13 = 0x18c;
      }
      else if ((*(int *)pAVar8 == 0) &&
              (iVar7 = ASN1_item_ex_new((ASN1_VALUE **)pAVar8,(ASN1_ITEM *)it), iVar7 == 0)) {
        uVar14 = 0x3a;
        uVar13 = 0x193;
      }
      else {
        puStack_300 = auStack_2e4;
        if ((pcStack_308 != (code *)0x0) && (iVar7 = (*pcStack_308)(4,pAVar8,it,0), iVar7 == 0))
        goto LAB_00565278;
        iVar7 = 0;
        tt_00 = *(ASN1_TEMPLATE **)((int)it + 8);
        if (0 < *(long *)((int)it + 0xc)) {
          do {
            tt = asn1_do_adb((ASN1_VALUE **)pAVar8,tt_00,1);
            if (tt == (ASN1_TEMPLATE *)0x0) goto LAB_0056529c;
            ppAVar10 = asn1_get_field_ptr((ASN1_VALUE **)pAVar8,tt);
            pAVar3 = pAStack_2ec;
            if (pAStack_2f0 == (ASN1_ITEM_EXP *)0x0) {
              if (cStack_2f6 == '\0') goto LAB_00565740;
              goto LAB_00565908;
            }
            if (((1 < (int)pAStack_2f0) && (*(char *)&pAStack_2ec->flags == '\0')) &&
               (*(char *)((int)&pAStack_2ec->flags + 1) == '\0')) {
              pAStack_2ec = (ASN1_TEMPLATE *)((int)&pAStack_2ec->flags + 2);
              if (cStack_2f6 == '\0') {
                uVar14 = 0x9f;
                uVar13 = 0x1ac;
                goto LAB_00565288;
              }
              cStack_2f6 = '\0';
              pAStack_2f0 = (ASN1_ITEM_EXP *)((int)&pAStack_2f0[-1].sname + 2);
              goto LAB_0056572c;
            }
            uVar5 = 0;
            if (iVar7 != *(long *)((int)it + 0xc) + -1) {
              uVar5 = tt->flags & 1;
            }
            iVar9 = asn1_template_ex_d2i(ppAVar10,auStack_2f4 + 8,pAStack_2f0,tt,uVar5,puStack_300);
            if (iVar9 == 0) goto LAB_005657e8;
            if (iVar9 == -1) {
              ASN1_template_free(ppAVar10,tt);
            }
            else {
              pAStack_2f0 = (ASN1_ITEM_EXP *)((int)pAStack_2f0 - ((int)pAStack_2ec - (int)pAVar3));
            }
            iVar7 = iVar7 + 1;
            tt_00 = tt_00 + 1;
          } while (iVar7 < *(long *)((int)it + 0xc));
        }
        if (cStack_2f6 != '\0') {
          if ((((int)pAStack_2f0 < 2) || (*(char *)&pAStack_2ec->flags != '\0')) ||
             (*(char *)((int)&pAStack_2ec->flags + 1) != '\0')) {
LAB_00565908:
            uVar14 = 0x89;
            uVar13 = 0x1d6;
            break;
          }
          pAStack_2ec = (ASN1_TEMPLATE *)((int)&pAStack_2ec->flags + 2);
        }
LAB_0056572c:
        if ((cVar19 != '\0') || (pAStack_2f0 == (ASN1_ITEM_EXP *)0x0)) {
LAB_00565740:
          if (iVar7 < *(long *)((int)it + 0xc)) {
LAB_00565794:
            tt = asn1_do_adb((ASN1_VALUE **)pAVar8,tt_00,1);
            if (tt != (ASN1_TEMPLATE *)0x0) {
              if ((tt->flags & 1) != 0) goto LAB_00565758;
              (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x78,0x79,s_tasn_dec_c_0066ab0c,0x1f5);
LAB_005657e8:
              ASN1_item_ex_free((ASN1_VALUE **)pAVar8,(ASN1_ITEM *)it);
LAB_005657fc:
              pcVar15 = &DAT_0066ab20;
              (*(code *)PTR_ERR_add_error_data_006a9264)
                        (4,&DAT_0066ab20,tt->field_name,", Type=",*(char **)((int)it + 0x18));
              goto switchD_00565630_caseD_7;
            }
            goto LAB_0056529c;
          }
          pAVar12 = *(ASN1_ITEM_EXP **)pcVar15;
          goto LAB_00565954;
        }
        uVar14 = 0x94;
        uVar13 = 0x1dd;
      }
    }
    break;
  case '\x02':
    if ((pcStack_308 == (code *)0x0) || (iVar7 = (*pcStack_308)(4,pAVar8,it,0), iVar7 != 0))
    goto LAB_005651ac;
    goto LAB_00565278;
  case '\x03':
switchD_00565630_caseD_3:
    iVar7 = (**(code **)((int)pvVar17 + 8))(pAVar8,pcVar15,pAVar6);
    pAVar12 = (ASN1_ITEM_EXP *)pcVar15;
    if (iVar7 != 0) goto LAB_00565328;
    uVar14 = 0x3a;
    uVar13 = 0x132;
    break;
  case '\x04':
LAB_005655ac:
    iVar7 = (*pcStack_308)(pAVar8,pcVar15,pAVar6,it,0xffffffff,0,0,auStack_2e4);
    if (iVar7 < 1) {
      pAVar11 = (ASN1_ITEM_EXP *)0x0;
      pAVar12 = (ASN1_ITEM_EXP *)pcVar15;
      goto LAB_005652d0;
    }
LAB_005653f0:
    pAVar11 = *(ASN1_ITEM_EXP **)pAVar8;
    pAVar12 = (ASN1_ITEM_EXP *)pcVar15;
    goto LAB_005652d0;
  case '\x05':
switchD_00565630_caseD_5:
    pAStack_2ec = *(ASN1_TEMPLATE **)pcVar15;
    iVar7 = asn1_check_tlen_constprop_1
                      (0,auStack_2f4 + 0xc,&cStack_2f7,0,0,auStack_2f4 + 8,pAVar6,1,auStack_2e4);
    if (iVar7 == 0) {
      uVar14 = 0x3a;
      uVar13 = 0xd2;
    }
    else if (cStack_2f7 == '\0') {
      if ((uStack_2e8 < 0x1f) &&
         ((*(uint *)(tag2bit + uStack_2e8 * 4) & *(long *)((int)it + 4)) != 0)) {
        iVar7 = asn1_d2i_ex_primitive(pAVar8,pcVar15,pAStack_2f0,it,uStack_2e8,0,0,auStack_2e4);
        if (iVar7 < 1) {
          pAVar11 = (ASN1_ITEM_EXP *)0x0;
          pAVar12 = (ASN1_ITEM_EXP *)pcVar15;
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
  ASN1_item_ex_free((ASN1_VALUE **)pAVar8,(ASN1_ITEM *)it);
LAB_005652b4:
  pcVar15 = s_Type__0066ab28;
  (*(code *)PTR_ERR_add_error_data_006a9264)(2,s_Type__0066ab28,*(char **)((int)it + 0x18));
switchD_00565630_caseD_7:
  pAVar11 = (ASN1_ITEM_EXP *)0x0;
  pAVar12 = (ASN1_ITEM_EXP *)pcVar15;
LAB_005652d0:
  if (piStack_2cc != *(int **)puVar2) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    return *(ASN1_ITEM_EXP **)(pAVar12->utype + *piStack_2cc);
  }
  return pAVar11;
code_r0x00563c90:
  param_5 = (ASN1_ITEM_EXP *)&param_5->field_0x1;
  ppAVar10 = asn1_get_field_ptr((ASN1_VALUE **)AStack_16c.size,(ASN1_TEMPLATE *)param_3);
  param_1 = param_1 + 1;
  ASN1_template_free(ppAVar10,(ASN1_TEMPLATE *)param_3);
  if (pAStack_1a8->tcount <= (int)param_5) goto LAB_00563eac;
  goto LAB_00563ccc;
code_r0x00563578:
  if ((int)apAStack_88[0] < 1) goto LAB_00563584;
  goto LAB_0056345c;
LAB_00565758:
  iVar7 = iVar7 + 1;
  ppAVar10 = asn1_get_field_ptr((ASN1_VALUE **)pAVar8,tt);
  tt_00 = tt_00 + 1;
  ASN1_template_free(ppAVar10,tt);
  if (*(long *)((int)it + 0xc) <= iVar7) goto LAB_00565950;
  goto LAB_00565794;
LAB_00565950:
  pAVar12 = *(ASN1_ITEM_EXP **)pcVar15;
LAB_00565954:
  iVar7 = asn1_enc_save((ASN1_VALUE **)pAVar8,(uchar *)pAVar12,(int)pAStack_2ec - (int)pAVar12,
                        (ASN1_ITEM *)it);
  if (iVar7 != 0) {
    *(ASN1_TEMPLATE **)pcVar15 = pAStack_2ec;
    if (pcStack_308 == (code *)0x0) {
      pAVar11 = *(ASN1_ITEM_EXP **)pAVar8;
      goto LAB_005652d0;
    }
LAB_00565258:
    pAVar12 = pAVar8;
    iVar7 = (*pcStack_308)(5,pAVar8,it,0);
    if (iVar7 != 0) {
LAB_00565328:
      pAVar11 = *(ASN1_ITEM_EXP **)pAVar8;
      goto LAB_005652d0;
    }
  }
LAB_00565278:
  uVar14 = 100;
  uVar13 = 0x205;
  goto LAB_00565288;
}

