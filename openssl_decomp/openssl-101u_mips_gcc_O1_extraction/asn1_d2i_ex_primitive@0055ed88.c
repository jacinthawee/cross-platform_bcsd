
/* WARNING: Type propagation algorithm not settling */

ASN1_ITEM *
asn1_d2i_ex_primitive
          (ASN1_ITEM *param_1,ASN1_ITEM **param_2,ASN1_ITEM *param_3,ASN1_ITEM *param_4,
          ASN1_ITEM *param_5,ASN1_ITEM *param_6,char param_7,ASN1_ITEM *param_8)

{
  byte bVar1;
  undefined *puVar2;
  ASN1_TEMPLATE *pAVar3;
  ASN1_ITEM *pAVar4;
  int in_zero;
  uint uVar5;
  ASN1_ITEM *pAVar6;
  int iVar7;
  ASN1_ITEM *pAVar8;
  int iVar9;
  ASN1_VALUE **ppAVar10;
  ASN1_TEMPLATE *pAVar11;
  ASN1_ITEM **pval;
  ASN1_ITEM *pAVar12;
  ASN1_ITEM *pAVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  char *pcVar16;
  char *pcVar17;
  char *pcVar18;
  ASN1_ITEM *unaff_s1;
  void *pvVar19;
  ASN1_TEMPLATE *tt;
  ASN1_ITEM *unaff_s4;
  ASN1_ITEM **unaff_s5;
  ASN1_ITEM *unaff_s6;
  ASN1_ITEM *unaff_s7;
  code *pcStack_310;
  undefined *puStack_308;
  char cStack_2ff;
  char cStack_2fe;
  char cStack_2fd;
  undefined auStack_2fc [4];
  ASN1_ITEM *pAStack_2f8;
  ASN1_TEMPLATE *pAStack_2f4;
  uint uStack_2f0;
  undefined auStack_2ec [24];
  int *piStack_2d4;
  ASN1_ITEM *pAStack_2d0;
  undefined *puStack_2cc;
  ASN1_ITEM *pAStack_2c8;
  ASN1_ITEM *pAStack_2c4;
  char *pcStack_2c0;
  ASN1_ITEM *pAStack_2bc;
  ASN1_ITEM *pAStack_2b8;
  ASN1_ITEM *pAStack_2b4;
  ASN1_ITEM *pAStack_2b0;
  code *pcStack_2ac;
  ASN1_ITEM *pAStack_280;
  int iStack_27c;
  ASN1_ITEM *pAStack_278;
  ASN1_ITEM *pAStack_274;
  ASN1_ITEM *pAStack_270;
  undefined uStack_26c;
  char *pcStack_268;
  ASN1_ITEM *pAStack_264;
  int iStack_260;
  ASN1_ITEM *pAStack_25c;
  int iStack_258;
  ASN1_ITEM *pAStack_254;
  ASN1_ITEM *pAStack_250;
  ASN1_ITEM_EXP *pAStack_24c;
  undefined *puStack_248;
  ASN1_ITEM *pAStack_244;
  ASN1_ITEM *pAStack_240;
  ASN1_ITEM *pAStack_23c;
  ASN1_ITEM *pAStack_238;
  ASN1_ITEM *pAStack_234;
  undefined4 uStack_230;
  code *pcStack_22c;
  undefined *puStack_1f8;
  uint uStack_1e8;
  void *pvStack_1e4;
  undefined4 uStack_1d4;
  ASN1_ITEM *pAStack_1cc;
  ASN1_ITEM *pAStack_1c8;
  ASN1_ITEM *pAStack_1c4;
  undefined *puStack_1c0;
  ASN1_ITEM *pAStack_1bc;
  ASN1_ITEM *pAStack_1b8;
  ASN1_ITEM *pAStack_1b4;
  ASN1_ITEM *pAStack_1b0;
  ASN1_ITEM *pAStack_1ac;
  ASN1_ITEM *pAStack_1a8;
  code *pcStack_1a4;
  ASN1_ITEM *pAStack_198;
  ASN1_ITEM *pAStack_18c;
  ASN1_ITEM *pAStack_178;
  undefined auStack_174 [8];
  ASN1_ITEM AStack_16c;
  ASN1_ITEM *pAStack_150;
  ASN1_ITEM **ppAStack_14c;
  ASN1_ITEM *pAStack_148;
  ASN1_ITEM *pAStack_144;
  ASN1_ITEM *pAStack_140;
  code *pcStack_13c;
  undefined4 in_stack_fffffed8;
  ASN1_VALUE *pAVar20;
  char cVar21;
  ASN1_ITEM *in_stack_fffffedc;
  ASN1_ITEM *pAStack_f8;
  undefined uStack_d4;
  char cStack_d3;
  undefined uStack_d2;
  ASN1_VALUE AStack_d1;
  ASN1_ITEM *pAStack_d0;
  undefined auStack_cc [4];
  ASN1_ITEM *pAStack_c8;
  ASN1_ITEM *pAStack_c4;
  ASN1_VALUE *pAStack_c0;
  ASN1_ITEM *pAStack_bc;
  ASN1_ITEM *pAStack_b8;
  ASN1_ITEM *pAStack_b4;
  undefined *puStack_b0;
  ASN1_ITEM *pAStack_ac;
  ASN1_ITEM *pAStack_a8;
  ASN1_ITEM **ppAStack_a4;
  ASN1_ITEM *pAStack_a0;
  ASN1_ITEM *pAStack_9c;
  ASN1_ITEM *pAStack_98;
  code *pcStack_94;
  ASN1_ITEM *apAStack_88 [2];
  char in_stack_ffffff83;
  ASN1_ITEM *in_stack_ffffff84;
  char local_4d;
  ASN1_ITEM *local_4c;
  ASN1_ITEM *local_48;
  undefined local_44 [12];
  ASN1_ITEM *local_38;
  ASN1_ITEM *local_34;
  ASN1_TEMPLATE *local_30;
  ASN1_ITEM **local_2c;
  
  AStack_16c.size = (long)PTR___stack_chk_guard_006a9ae8;
  cVar21 = (char)in_stack_fffffed8;
  pAStack_1a8 = (ASN1_ITEM *)(int)param_7;
  local_4d = '\0';
  local_2c = *(ASN1_ITEM ***)PTR___stack_chk_guard_006a9ae8;
  if (param_1 == (ASN1_ITEM *)0x0) {
    pAVar13 = (ASN1_ITEM *)0x7d;
    in_stack_ffffff83 = -0x2c;
    param_3 = unaff_s7;
    goto LAB_0055f0f8;
  }
  pcStack_2c0 = &param_4->itype;
  if (param_4->itype == '\x05') {
    local_4c = param_5;
    if (param_5 == (ASN1_ITEM *)0xfffffffc) {
      param_5 = (ASN1_ITEM *)0xffffffff;
LAB_0055f0c4:
      pAVar12 = (ASN1_ITEM *)&local_48;
      if (pAStack_1a8 == (ASN1_ITEM *)0x0) {
        local_48 = *param_2;
        pcStack_2c0 = (char *)0x0;
        in_stack_ffffff83 = '\0';
        iVar7 = asn1_check_tlen_constprop_1(0,&local_4c,&local_38);
        cVar21 = (char)in_stack_fffffed8;
        if (iVar7 != 0) {
          if (local_38._0_1_ != '\0') {
            local_4c = (ASN1_ITEM *)0xfffffffd;
          }
          goto LAB_0055ee14;
        }
        pAVar13 = (ASN1_ITEM *)&DAT_0000003a;
        in_stack_ffffff83 = -0x12;
        in_stack_ffffff84 = pAVar12;
      }
      else {
        pAVar13 = (ASN1_ITEM *)0x7e;
        in_stack_ffffff83 = -0x19;
      }
      goto LAB_0055efc0;
    }
    param_6 = (ASN1_ITEM *)0x0;
    pAVar8 = param_5;
    local_4c = param_5;
LAB_0055ee1c:
    unaff_s1 = *param_2;
    local_48 = unaff_s1;
    local_38 = unaff_s1;
    if (param_8 != (ASN1_ITEM *)0x0) {
      if (param_8->itype == '\0') {
        pcStack_2c0 = local_44 + 4;
        pAVar13 = param_3;
        uVar5 = ASN1_get_object((uchar **)&local_38,(long *)(local_44 + 8),(int *)local_44,
                                (int *)pcStack_2c0,(long)param_3);
        cVar21 = (char)in_stack_fffffed8;
        in_stack_ffffff83 = (char)pAVar13;
        pAVar12 = (ASN1_ITEM *)(uVar5 & 0x81);
        param_8->funcs = local_44._4_4_;
        param_8->utype = uVar5;
        param_8->templates = (ASN1_TEMPLATE *)local_44._8_4_;
        param_8->size = (int)local_38 - (int)unaff_s1;
        param_8->tcount = (long)local_44._0_4_;
        pAVar13 = (ASN1_ITEM *)0x1;
        param_8->itype = '\x01';
        if ((pAVar12 != (ASN1_ITEM *)0x0) ||
           ((int)local_44._8_4_ + ((int)local_38 - (int)unaff_s1) <= (int)param_3))
        goto LAB_0055ee64;
        uVar14 = 0x9b;
      }
      else {
        pAVar13 = (ASN1_ITEM *)param_8->templates;
        pAVar12 = (ASN1_ITEM *)param_8->funcs;
        local_44._0_4_ = (ASN1_ITEM *)param_8->tcount;
        local_38 = (ASN1_ITEM *)((int)&unaff_s1->itype + param_8->size);
        uVar5 = param_8->utype;
        local_44._4_4_ = pAVar12;
        local_44._8_4_ = pAVar13;
LAB_0055ee64:
        cVar21 = (char)in_stack_fffffed8;
        if ((uVar5 & 0x80) == 0) goto LAB_0055ee6c;
        uVar14 = 0x66;
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x68,uVar14,s_tasn_dec_c_0066a0bc);
      param_8->itype = '\0';
LAB_0055eeb4:
      unaff_s1 = (ASN1_ITEM *)0x670000;
      pcStack_2c0 = s_tasn_dec_c_0066a0bc;
      pAVar13 = (ASN1_ITEM *)&DAT_0000003a;
      pAVar12 = (ASN1_ITEM *)&DAT_0000006c;
      in_stack_ffffff83 = -3;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
      param_5 = pAVar8;
      goto LAB_0055eed8;
    }
    pcStack_2c0 = local_44 + 4;
    pAVar13 = (ASN1_ITEM *)local_44;
    pAVar12 = (ASN1_ITEM *)(local_44 + 8);
    pAVar6 = param_3;
    uVar5 = ASN1_get_object((uchar **)&local_38,(long *)pAVar12,(int *)pAVar13,(int *)pcStack_2c0,
                            (long)param_3);
    cVar21 = (char)in_stack_fffffed8;
    in_stack_ffffff83 = (char)pAVar6;
    if ((uVar5 & 0x80) != 0) {
      uVar14 = 0x66;
LAB_0055eea0:
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x68,uVar14,s_tasn_dec_c_0066a0bc);
      goto LAB_0055eeb4;
    }
LAB_0055ee6c:
    param_5 = local_38;
    cVar21 = (char)in_stack_fffffed8;
    if ((int)pAVar8 < 0) {
LAB_0055f020:
      pAVar13 = local_44._8_4_;
      if ((uVar5 & 1) != 0) {
        pAVar13 = (ASN1_ITEM *)((int)param_3 - ((int)local_38 - (int)unaff_s1));
      }
      unaff_s1 = pAVar13;
      local_48 = local_38;
      pcStack_2c0 = (char *)((int)(char)uVar5 & 1);
      unaff_s4 = param_4;
      unaff_s5 = param_2;
      unaff_s6 = param_1;
      if (&local_4c[-1].tcount < &SUB_00000002) {
        if ((uVar5 & 0x20) != 0) goto LAB_0055f11c;
        pAVar13 = (ASN1_ITEM *)&DAT_0000009c;
        in_stack_ffffff83 = '\x0f';
LAB_0055f0f8:
        pcStack_2c0 = s_tasn_dec_c_0066a0bc;
        pAVar12 = (ASN1_ITEM *)&DAT_0000006c;
        (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
        pAVar6 = (ASN1_ITEM *)0x0;
        param_4 = unaff_s4;
        param_2 = unaff_s5;
        param_1 = unaff_s6;
      }
      else {
        if (local_4c == (ASN1_ITEM *)0xfffffffd) {
          if (param_8 != (ASN1_ITEM *)0x0) {
            param_8->itype = '\0';
          }
LAB_0055f11c:
          pAVar12 = *param_2;
          if ((ASN1_ITEM *)pcStack_2c0 == (ASN1_ITEM *)0x0) {
            local_48 = (ASN1_ITEM *)((int)&unaff_s1->itype + (int)&local_38->itype);
            local_34 = (ASN1_ITEM *)0x0;
            pAVar13 = (ASN1_ITEM *)(((int)local_38 - (int)pAVar12) + (int)unaff_s1);
            goto LAB_0055f138;
          }
          param_3 = (ASN1_ITEM *)0x1;
          if (0 < (int)unaff_s1) {
            pAStack_1a8 = (ASN1_ITEM *)&local_38;
            do {
              cVar21 = (char)in_stack_fffffed8;
              if (((unaff_s1 == (ASN1_ITEM *)0x1) || (param_5->itype != '\0')) ||
                 (param_5->field_0x1 != '\0')) {
                local_38 = param_5;
                uVar5 = ASN1_get_object((uchar **)pAStack_1a8,(long *)(local_44 + 8),(int *)local_44
                                        ,(int *)(local_44 + 4),(long)unaff_s1);
                cVar21 = (char)in_stack_fffffed8;
                if ((uVar5 & 0x80) != 0) {
                  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x68,0x66,s_tasn_dec_c_0066a0bc);
                  pcStack_2c0 = s_tasn_dec_c_0066a0bc;
                  pAVar13 = (ASN1_ITEM *)&DAT_0000003a;
                  pAVar12 = (ASN1_ITEM *)0xbe;
                  in_stack_ffffff83 = -4;
                  pAVar6 = (ASN1_ITEM *)0x0;
                  (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
                  goto LAB_0055f164;
                }
                pAVar13 = local_44._8_4_;
                if (((uVar5 & 1) == 0) ||
                   (pAVar13 = (ASN1_ITEM *)((int)unaff_s1 - ((int)local_38 - (int)param_5)),
                   (uVar5 & 1) == 0)) {
                  pAVar13 = (ASN1_ITEM *)((int)&pAVar13->itype + (int)&local_38->itype);
                  unaff_s1 = (ASN1_ITEM *)((int)unaff_s1 - ((int)pAVar13 - (int)param_5));
                  param_5 = pAVar13;
                }
                else {
                  param_3 = (ASN1_ITEM *)&param_3->field_0x1;
                  unaff_s1 = (ASN1_ITEM *)((int)unaff_s1 - ((int)local_38 - (int)param_5));
                  param_5 = local_38;
                }
              }
              else {
                param_3 = (ASN1_ITEM *)((int)&param_3[-1].sname + 3);
                param_5 = (ASN1_ITEM *)&param_5->field_0x2;
                if (param_3 == (ASN1_ITEM *)0x0) {
                  pAVar13 = (ASN1_ITEM *)((int)param_5 + -(int)pAVar12);
                  local_48 = param_5;
                  goto LAB_0055f138;
                }
                unaff_s1 = (ASN1_ITEM *)((int)&unaff_s1[-1].sname + 2);
              }
              cVar21 = (char)in_stack_fffffed8;
            } while (0 < (int)unaff_s1);
          }
          pAVar13 = (ASN1_ITEM *)&DAT_00000089;
          pcStack_2c0 = s_tasn_dec_c_0066a0bc;
          in_stack_ffffff83 = '\x06';
          pAVar12 = (ASN1_ITEM *)0xbe;
          (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
LAB_0055f214:
          pAVar6 = (ASN1_ITEM *)0x0;
LAB_0055f164:
          param_8 = pAVar6;
          if (local_4d == '\0') goto LAB_0055eedc;
        }
        else {
          pAVar13 = unaff_s1;
          if ((uVar5 & 0x20) == 0) {
            local_48 = (ASN1_ITEM *)((int)&unaff_s1->itype + (int)&local_38->itype);
            pAVar12 = local_38;
LAB_0055f138:
            pcVar16 = &local_4d;
            pcStack_2c0 = &local_4c->itype;
            in_stack_ffffff84 = param_4;
            iVar7 = asn1_ex_c2i((ASN1_VALUE **)param_1,(uchar *)pAVar12,(int)pAVar13,(int)local_4c,
                                pcVar16,param_4);
            in_stack_ffffff83 = (char)pcVar16;
            if (iVar7 == 0) goto LAB_0055f214;
            pAVar6 = (ASN1_ITEM *)0x1;
            *param_2 = local_48;
            goto LAB_0055f164;
          }
          if ((((uint)local_4c & 0xfffffffb) - 1 < 2) ||
             (param_8 = (ASN1_ITEM *)&local_38, local_4c == (ASN1_ITEM *)&DAT_0000000a)) {
            pAVar13 = (ASN1_ITEM *)0xda;
            in_stack_ffffff83 = '\"';
            goto LAB_0055f0f8;
          }
          in_stack_ffffff83 = '\0';
          pAVar12 = (ASN1_ITEM *)&local_48;
          local_38 = (ASN1_ITEM *)0x0;
          local_30 = (ASN1_TEMPLATE *)0x0;
          local_34 = (ASN1_ITEM *)0x0;
          iVar7 = asn1_collect_constprop_0(param_8);
          pAVar8 = local_38;
          if (iVar7 != 0) {
            pAVar6 = (ASN1_ITEM *)
                     (*(code *)PTR_BUF_MEM_grow_clean_006a7b40)(param_8,&local_38->field_0x1);
            if (pAVar6 == (ASN1_ITEM *)0x0) {
              pAVar13 = (ASN1_ITEM *)&DAT_00000041;
              pcStack_2c0 = s_tasn_dec_c_0066a0bc;
              in_stack_ffffff83 = '5';
              pAVar12 = (ASN1_ITEM *)&DAT_0000006c;
              (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
              goto LAB_0055eedc;
            }
            *(undefined *)((int)&pAVar8->itype + (int)&local_34->itype) = 0;
            local_4d = '\x01';
            pAVar13 = pAVar8;
            pAVar12 = local_34;
            goto LAB_0055f138;
          }
          pAVar6 = (ASN1_ITEM *)0x0;
          local_4d = '\x01';
        }
        param_8 = pAVar6;
        if (local_34 != (ASN1_ITEM *)0x0) {
          (*(code *)PTR_CRYPTO_free_006a6e88)();
        }
      }
    }
    else {
      if ((pAVar8 == local_44._0_4_) && (param_6 == local_44._4_4_)) {
        if (param_8 != (ASN1_ITEM *)0x0) {
          param_8->itype = '\0';
        }
        goto LAB_0055f020;
      }
      pAVar6 = (ASN1_ITEM *)0xffffffff;
      param_5 = pAVar8;
      if (pAStack_1a8 == (ASN1_ITEM *)0x0) {
        if (param_8 != (ASN1_ITEM *)0x0) {
          param_8->itype = '\0';
        }
        uVar14 = 0xa8;
        goto LAB_0055eea0;
      }
    }
  }
  else {
    local_4c = (ASN1_ITEM *)param_4->utype;
    pAVar12 = in_stack_ffffff84;
    if (local_4c != (ASN1_ITEM *)0xfffffffc) {
LAB_0055ee14:
      pAVar8 = param_5;
      in_stack_ffffff84 = pAVar12;
      if (param_5 == (ASN1_ITEM *)0xffffffff) {
        param_6 = (ASN1_ITEM *)0x0;
        pAVar8 = local_4c;
      }
      goto LAB_0055ee1c;
    }
    if ((int)param_5 < 0) goto LAB_0055f0c4;
    pAVar13 = (ASN1_ITEM *)0x7f;
    in_stack_ffffff83 = -0x1e;
LAB_0055efc0:
    pcStack_2c0 = s_tasn_dec_c_0066a0bc;
    pAVar12 = (ASN1_ITEM *)&DAT_0000006c;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
LAB_0055eed8:
    pAVar6 = (ASN1_ITEM *)0x0;
  }
LAB_0055eedc:
  if (local_2c == *(ASN1_ITEM ***)AStack_16c.size) {
    return pAVar6;
  }
  pcStack_94 = asn1_template_noexp_d2i;
  pval = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  pAStack_98 = pAStack_1a8;
  pAStack_9c = param_3;
  pAStack_a0 = param_1;
  ppAStack_a4 = param_2;
  pAStack_a8 = param_4;
  pAStack_ac = param_5;
  puStack_b0 = (undefined *)AStack_16c.size;
  pAStack_b4 = unaff_s1;
  pAStack_b8 = param_8;
  apAStack_88[0] = pAVar13;
  pAStack_bc = *(ASN1_ITEM **)PTR___stack_chk_guard_006a9ae8;
  if (pval == (ASN1_ITEM **)0x0) {
    pAVar8 = (ASN1_ITEM *)0x0;
    pAStack_1b4 = pAVar12;
    pcVar16 = pcStack_2c0;
  }
  else {
    uVar5 = *(uint *)pcStack_2c0;
    in_stack_fffffedc = (ASN1_ITEM *)(uVar5 & 0xc0);
    pAStack_d0 = *(ASN1_ITEM **)pAVar12;
    if ((uVar5 & 6) == 0) {
      param_8 = (ASN1_ITEM *)0xffffffff;
      if ((uVar5 & 8) == 0) {
        pcVar16 = *(char **)((int)pcStack_2c0 + 0x10);
        in_stack_fffffedc = (ASN1_ITEM *)(uVar5 & 0x400);
        pAStack_1b4 = (ASN1_ITEM *)&pAStack_d0;
        cVar21 = -1;
        iVar7 = ASN1_item_ex_d2i((ASN1_VALUE **)pval,(uchar **)pAStack_1b4,(long)pAVar13,
                                 (ASN1_ITEM *)pcVar16,-1,(int)in_stack_fffffedc,in_stack_ffffff83,
                                 (ASN1_TLC *)in_stack_ffffff84);
        if (iVar7 != 0) goto joined_r0x0055fcbc;
        pAVar13 = (ASN1_ITEM *)&DAT_0000003a;
        cVar21 = -0x47;
      }
      else {
        iVar9 = *(long *)((int)pcStack_2c0 + 4);
        pAStack_1b4 = (ASN1_ITEM *)&pAStack_d0;
        pcVar16 = *(char **)((int)pcStack_2c0 + 0x10);
        iVar7 = ASN1_item_ex_d2i((ASN1_VALUE **)pval,(uchar **)pAStack_1b4,(long)pAVar13,
                                 (ASN1_ITEM *)pcVar16,iVar9,(int)in_stack_fffffedc,in_stack_ffffff83
                                 ,(ASN1_TLC *)in_stack_ffffff84);
        cVar21 = (char)iVar9;
        if (iVar7 != 0) {
joined_r0x0055fcbc:
          if (iVar7 == -1) {
            pAVar8 = (ASN1_ITEM *)0xffffffff;
          }
          else {
LAB_0055f69c:
            *(ASN1_ITEM **)pAVar12 = pAStack_d0;
            pAVar8 = (ASN1_ITEM *)0x1;
            AStack_16c.size = (long)pAStack_d0;
          }
          goto LAB_0055fc10;
        }
        pAVar13 = (ASN1_ITEM *)&DAT_0000003a;
        cVar21 = -0x50;
      }
LAB_0055fd3c:
      pcVar16 = s_tasn_dec_c_0066a0bc;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x83);
LAB_0055fbf8:
      pAStack_1b4 = (ASN1_ITEM *)pcStack_2c0;
      ASN1_template_free((ASN1_VALUE **)pval,(ASN1_TEMPLATE *)pcStack_2c0);
      pAVar8 = (ASN1_ITEM *)0x0;
    }
    else {
      param_3 = (ASN1_ITEM *)&pAStack_d0;
      pcVar16 = &uStack_d4;
      pAVar13 = (ASN1_ITEM *)0x0;
      pAStack_1b4 = (ASN1_ITEM *)0x0;
      pAVar20 = (ASN1_VALUE *)0x0;
      in_stack_fffffedc = param_3;
      iVar7 = asn1_check_tlen(apAStack_88);
      cVar21 = (char)pAVar20;
      if (iVar7 == 0) {
        pAVar13 = (ASN1_ITEM *)&DAT_0000003a;
        pcVar16 = s_tasn_dec_c_0066a0bc;
        cVar21 = 's';
        pAStack_1b4 = (ASN1_ITEM *)0x83;
        (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
        pAVar8 = (ASN1_ITEM *)0x0;
      }
      else {
        pAVar8 = (ASN1_ITEM *)0xffffffff;
        if (iVar7 != -1) {
          param_8 = *pval;
          if (param_8 == (ASN1_ITEM *)0x0) {
            pAVar8 = (ASN1_ITEM *)(*(code *)PTR_sk_new_null_006a6fa4)();
            *pval = pAVar8;
          }
          else {
            while (iVar7 = (*(code *)PTR_sk_num_006a6e2c)(param_8), 0 < iVar7) {
              pAStack_c0 = (ASN1_VALUE *)(*(code *)PTR_sk_pop_006a8da4)(param_8);
              pAStack_1b4 = *(ASN1_ITEM **)((int)pcStack_2c0 + 0x10);
              ASN1_item_ex_free(&pAStack_c0,pAStack_1b4);
            }
            pAVar8 = *pval;
          }
          cVar21 = (char)pAVar20;
          pAVar6 = pAStack_d0;
          pAVar4 = apAStack_88[0];
          if (pAVar8 == (ASN1_ITEM *)0x0) {
            pAVar13 = (ASN1_ITEM *)&DAT_00000041;
            cVar21 = -0x7a;
            unaff_s1 = apAStack_88[0];
          }
          else {
            do {
              unaff_s1 = pAVar4;
              pAStack_d0 = pAVar6;
              apAStack_88[0] = unaff_s1;
              if ((int)unaff_s1 < 1) {
                pcVar16 = "encrypt";
                if (uStack_d4 == '\0') goto LAB_0055f69c;
                pAVar13 = (ASN1_ITEM *)&DAT_00000089;
                cVar21 = -0x59;
                goto LAB_0055fd3c;
              }
              cVar21 = (char)pAVar20;
              if (((unaff_s1 != (ASN1_ITEM *)0x1) && (pAVar6->itype == '\0')) &&
                 (*(undefined *)((int)pAVar6 + 1) == '\0')) {
                AStack_16c.size = (int)pAVar6 + 2;
                pAStack_d0 = (ASN1_ITEM *)AStack_16c.size;
                if (uStack_d4 != '\0') goto LAB_0055f69c;
                pAVar13 = (ASN1_ITEM *)0x9f;
                cVar21 = -0x6e;
                goto LAB_0055fd3c;
              }
              param_8 = *(ASN1_ITEM **)((int)pcStack_2c0 + 0x10);
              auStack_cc = (undefined  [4])0x0;
              pAStack_c4 = (ASN1_ITEM *)0x0;
              param_2 = (ASN1_ITEM **)param_8->funcs;
              pAVar13 = unaff_s1;
              pAStack_c8 = unaff_s1;
              if (param_2 == (ASN1_ITEM **)0x0) {
                switch(param_8->itype) {
                case '\0':
                  goto switchD_0055fc6c_caseD_55f9b0;
                case '\x01':
                case '\x06':
                  pAStack_f8 = (ASN1_ITEM *)0x0;
                  goto switchD_0055f650_caseD_1;
                case '\x02':
                  pAStack_f8 = (ASN1_ITEM *)0x0;
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
              pAStack_f8 = param_2[4];
              switch(param_8->itype) {
              case '\0':
switchD_0055fc6c_caseD_55f9b0:
                pcVar16 = (char *)param_8->templates;
                if ((ASN1_ITEM *)pcVar16 == (ASN1_ITEM *)0x0) {
                  in_stack_fffffedc = (ASN1_ITEM *)0x0;
                  pAVar20 = (ASN1_VALUE *)0xffffffff;
                  pcVar16 = &param_8->itype;
                  iVar7 = asn1_d2i_ex_primitive(auStack_cc,param_3);
                }
                else {
                  pAVar20 = (ASN1_VALUE *)0x0;
                  in_stack_fffffedc = in_stack_ffffff84;
                  iVar7 = asn1_template_ex_d2i(auStack_cc,param_3);
                }
                break;
              case '\x01':
              case '\x06':
switchD_0055f650_caseD_1:
                param_1 = (ASN1_ITEM *)(auStack_cc + 8);
                pcVar16 = &uStack_d2;
                pAVar13 = (ASN1_ITEM *)0x0;
                pAVar20 = &AStack_d1;
                in_stack_fffffedc = param_1;
                pAStack_c4 = pAVar6;
                iVar7 = asn1_check_tlen(auStack_cc + 4,0);
                if (iVar7 == 0) {
                  uVar14 = 0x3a;
                }
                else {
                  if (iVar7 == -1) goto LAB_0055f6e8;
                  cVar21 = uStack_d2;
                  if ((param_2 != (ASN1_ITEM **)0x0) && (((uint)param_2[1] & 4) != 0)) {
                    pAStack_c8 = (ASN1_ITEM *)((int)unaff_s1 - ((int)pAStack_c4 - (int)pAStack_d0));
                    cVar21 = '\x01';
                  }
                  if (AStack_d1 != (ASN1_VALUE)0x0) {
                    if ((auStack_cc == (undefined  [4])0x0) &&
                       (iVar7 = ASN1_item_ex_new((ASN1_VALUE **)auStack_cc,param_8), iVar7 == 0)) {
                      uVar14 = 0x3a;
                    }
                    else {
                      if ((pAStack_f8 != (ASN1_ITEM *)0x0) &&
                         (iVar7 = (*(code *)pAStack_f8)(4,auStack_cc,param_8,0), iVar7 == 0))
                      goto LAB_0055fb7c;
                      iVar7 = param_8->tcount;
                      param_2 = (ASN1_ITEM **)0x0;
                      unaff_s1 = (ASN1_ITEM *)param_8->templates;
                      if (0 < iVar7) {
                        do {
                          while ((*(uint *)unaff_s1 & 0x300) != 0) {
                            pAStack_1a8 = (ASN1_ITEM *)
                                          asn1_do_adb((ASN1_VALUE **)auStack_cc,
                                                      (ASN1_TEMPLATE *)unaff_s1,1);
                            param_2 = (ASN1_ITEM **)((int)param_2 + 1);
                            unaff_s1 = (ASN1_ITEM *)&unaff_s1->size;
                            ppAVar10 = asn1_get_field_ptr((ASN1_VALUE **)auStack_cc,
                                                          (ASN1_TEMPLATE *)pAStack_1a8);
                            ASN1_template_free(ppAVar10,(ASN1_TEMPLATE *)pAStack_1a8);
                            iVar7 = param_8->tcount;
                            if (iVar7 <= (int)param_2) goto LAB_0055f8c0;
                          }
                          param_2 = (ASN1_ITEM **)((int)param_2 + 1);
                          unaff_s1 = (ASN1_ITEM *)&unaff_s1->size;
                        } while ((int)param_2 < iVar7);
LAB_0055f8c0:
                        unaff_s1 = (ASN1_ITEM *)param_8->templates;
                        param_2 = (ASN1_ITEM **)0x0;
                        if (0 < iVar7) {
                          do {
                            pAStack_1a8 = (ASN1_ITEM *)
                                          asn1_do_adb((ASN1_VALUE **)auStack_cc,
                                                      (ASN1_TEMPLATE *)unaff_s1,1);
                            if (pAStack_1a8 == (ASN1_ITEM *)0x0) goto LAB_0055fba4;
                            ppAVar10 = asn1_get_field_ptr((ASN1_VALUE **)auStack_cc,
                                                          (ASN1_TEMPLATE *)pAStack_1a8);
                            pAVar13 = pAStack_c4;
                            if (pAStack_c8 == (ASN1_ITEM *)0x0) {
                              if (uStack_d2 != '\0') goto LAB_005600d0;
                              goto LAB_0055fed8;
                            }
                            if (((1 < (int)pAStack_c8) && (pAStack_c4->itype == '\0')) &&
                               (pAStack_c4->field_0x1 == '\0')) {
                              pAStack_c4 = (ASN1_ITEM *)&pAStack_c4->field_0x2;
                              if (uStack_d2 != '\0') {
                                pAStack_c8 = (ASN1_ITEM *)((int)&pAStack_c8[-1].sname + 2);
                                uStack_d2 = '\0';
                                goto LAB_0055fec4;
                              }
                              uVar14 = 0x9f;
                              goto LAB_0055fb90;
                            }
                            pAVar20 = (ASN1_VALUE *)0x0;
                            if (param_2 != (ASN1_ITEM **)(param_8->tcount + -1)) {
                              pAVar20 = (ASN1_VALUE *)(*(uint *)pAStack_1a8 & 1);
                            }
                            in_stack_fffffedc = in_stack_ffffff84;
                            iVar7 = asn1_template_ex_d2i(ppAVar10,param_1,pAStack_c8,pAStack_1a8);
                            if (iVar7 == 0) goto LAB_005600ec;
                            if (iVar7 == -1) {
                              ASN1_template_free(ppAVar10,(ASN1_TEMPLATE *)pAStack_1a8);
                            }
                            else {
                              pAStack_c8 = (ASN1_ITEM *)
                                           ((int)pAStack_c8 - ((int)pAStack_c4 - (int)pAVar13));
                            }
                            param_2 = (ASN1_ITEM **)((int)param_2 + 1);
                            unaff_s1 = (ASN1_ITEM *)&unaff_s1->size;
                          } while ((int)param_2 < param_8->tcount);
                        }
                      }
                      if (uStack_d2 != '\0') {
                        if ((((int)pAStack_c8 < 2) || (pAStack_c4->itype != '\0')) ||
                           (pAStack_c4->field_0x1 != '\0')) {
LAB_005600d0:
                          uVar14 = 0x89;
                          goto LAB_0055fb90;
                        }
                        pAStack_c4 = (ASN1_ITEM *)&pAStack_c4->field_0x2;
                      }
LAB_0055fec4:
                      if ((cVar21 != '\0') || (pAStack_c8 == (ASN1_ITEM *)0x0)) {
LAB_0055fed8:
                        if ((int)param_2 < param_8->tcount) {
LAB_0055ff3c:
                          pAStack_1a8 = (ASN1_ITEM *)
                                        asn1_do_adb((ASN1_VALUE **)auStack_cc,
                                                    (ASN1_TEMPLATE *)unaff_s1,1);
                          if (pAStack_1a8 != (ASN1_ITEM *)0x0) {
                            if ((*(uint *)pAStack_1a8 & 1) != 0) goto code_r0x0055ff00;
                            (*(code *)PTR_ERR_put_error_006a7f34)
                                      (0xd,0x78,0x79,s_tasn_dec_c_0066a0bc);
LAB_005600ec:
                            ASN1_item_ex_free((ASN1_VALUE **)auStack_cc,param_8);
LAB_00560054:
                            param_1 = (ASN1_ITEM *)(auStack_cc + 8);
                            param_5 = (ASN1_ITEM *)auStack_cc;
                            (*(code *)PTR_ERR_add_error_data_006a813c)
                                      (4,&DAT_0066a0d0,(char *)pAStack_1a8->tcount,", Type=");
                            goto switchD_0055f650_caseD_7;
                          }
                          goto LAB_0055fba4;
                        }
LAB_0055fe40:
                        pAVar13 = (ASN1_ITEM *)((int)pAStack_c4 - (int)pAStack_d0);
                        iVar7 = asn1_enc_save((ASN1_VALUE **)auStack_cc,(uchar *)pAStack_d0,
                                              (int)pAVar13,param_8);
                        if (iVar7 != 0) {
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
                if (pAStack_f8 == (ASN1_ITEM *)0x0) {
LAB_0055fd74:
                  iVar7 = ASN1_item_ex_new((ASN1_VALUE **)auStack_cc,param_8);
                  if (iVar7 == 0) {
                    uVar14 = 0x3a;
                  }
                  else {
                    pAVar13 = (ASN1_ITEM *)param_8->tcount;
LAB_0055fabc:
                    unaff_s1 = (ASN1_ITEM *)0x0;
                    pAStack_1a8 = (ASN1_ITEM *)param_8->templates;
                    pAStack_c4 = pAStack_d0;
                    if (0 < (int)pAVar13) {
                      param_1 = (ASN1_ITEM *)(auStack_cc + 8);
                      param_2 = (ASN1_ITEM **)0xffffffff;
                      do {
                        ppAVar10 = asn1_get_field_ptr((ASN1_VALUE **)auStack_cc,
                                                      (ASN1_TEMPLATE *)pAStack_1a8);
                        pAVar20 = (ASN1_VALUE *)0x1;
                        pcVar16 = &pAStack_1a8->itype;
                        in_stack_fffffedc = in_stack_ffffff84;
                        iVar7 = asn1_template_ex_d2i(ppAVar10,param_1,pAStack_c8);
                        if (iVar7 != -1) {
                          if (iVar7 < 1) {
                            (*(code *)PTR_ERR_put_error_006a7f34)
                                      (0xd,0x78,0x3a,s_tasn_dec_c_0066a0bc);
                            ASN1_item_ex_free((ASN1_VALUE **)auStack_cc,param_8);
                            if (pAStack_1a8 != (ASN1_ITEM *)0x0) goto LAB_00560054;
                            goto LAB_0055fbb8;
                          }
                          pAVar13 = (ASN1_ITEM *)param_8->tcount;
                          break;
                        }
                        pAVar13 = (ASN1_ITEM *)param_8->tcount;
                        unaff_s1 = (ASN1_ITEM *)&unaff_s1->field_0x1;
                        pAStack_1a8 = (ASN1_ITEM *)&pAStack_1a8->size;
                      } while ((int)unaff_s1 < (int)pAVar13);
                    }
                    if (unaff_s1 != pAVar13) {
                      pAVar13 = param_8;
                      asn1_set_choice_selector((ASN1_VALUE **)auStack_cc,(int)unaff_s1,param_8);
joined_r0x0055fb54:
                      if (pAStack_f8 != (ASN1_ITEM *)0x0) {
                        pcVar16 = (char *)0x0;
                        pAVar13 = param_8;
                        iVar7 = (*(code *)pAStack_f8)(5,auStack_cc);
                        if (iVar7 == 0) goto LAB_0055fb7c;
                      }
                      param_5 = (ASN1_ITEM *)auStack_cc;
                      pAStack_d0 = pAStack_c4;
                      goto LAB_0055f6e8;
                    }
                    uVar14 = 0x8f;
                  }
                }
                else {
                  pcVar16 = (char *)0x0;
                  iVar7 = (*(code *)pAStack_f8)(4,auStack_cc,param_8);
                  if (iVar7 != 0) {
                    if (auStack_cc == (undefined  [4])0x0) goto LAB_0055fd74;
                    iVar7 = asn1_get_choice_selector((ASN1_VALUE **)auStack_cc,param_8);
                    pAVar13 = (ASN1_ITEM *)param_8->tcount;
                    if ((-1 < iVar7) && (iVar7 < (int)pAVar13)) {
                      pAVar11 = param_8->templates;
                      ppAVar10 = asn1_get_field_ptr((ASN1_VALUE **)auStack_cc,pAVar11 + iVar7);
                      ASN1_template_free(ppAVar10,pAVar11 + iVar7);
                      asn1_set_choice_selector((ASN1_VALUE **)auStack_cc,-1,param_8);
                      pAVar13 = (ASN1_ITEM *)param_8->tcount;
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
                param_5 = (ASN1_ITEM *)auStack_cc;
                iVar7 = (*(code *)param_2[2])(param_5,param_3);
                if (iVar7 == 0) {
                  uVar14 = 0x3a;
                  goto LAB_0055fb90;
                }
                goto LAB_0055f6e8;
              case '\x04':
switchD_0055fc6c_caseD_55f6ac:
                in_stack_fffffedc = (ASN1_ITEM *)0x0;
                pAVar20 = (ASN1_VALUE *)0xffffffff;
                pcVar16 = &param_8->itype;
                iVar7 = (*(code *)param_2[4])(auStack_cc,param_3);
                break;
              case '\x05':
switchD_0055fc6c_caseD_55f9e4:
                param_1 = (ASN1_ITEM *)(auStack_cc + 8);
                in_stack_fffffedc = param_1;
                pAStack_c4 = pAVar6;
                iVar7 = asn1_check_tlen_constprop_1(0,&pAStack_c0,&cStack_d3,0);
                if (iVar7 == 0) {
                  uVar14 = 0x3a;
                }
                else if (cStack_d3 == '\0') {
                  unaff_s1 = (ASN1_ITEM *)0x670000;
                  if ((pAStack_c0 < (ASN1_VALUE *)0x1f) &&
                     ((*(uint *)(tag2bit + (int)pAStack_c0 * 4) & param_8->utype) != 0)) {
                    in_stack_fffffedc = (ASN1_ITEM *)0x0;
                    pAVar13 = pAStack_c8;
                    pcVar16 = &param_8->itype;
                    pAVar20 = pAStack_c0;
                    iVar7 = asn1_d2i_ex_primitive(auStack_cc,param_3);
                    break;
                  }
                  uVar14 = 0x8c;
                }
                else {
                  uVar14 = 0x8b;
                }
LAB_0055fa44:
                param_1 = (ASN1_ITEM *)(auStack_cc + 8);
                (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x78,uVar14,s_tasn_dec_c_0066a0bc);
LAB_0055fba4:
                ASN1_item_ex_free((ASN1_VALUE **)auStack_cc,param_8);
LAB_0055fbb8:
                param_5 = (ASN1_ITEM *)auStack_cc;
                (*(code *)PTR_ERR_add_error_data_006a813c)(2,s_Type__0066a0d8,param_8->sname);
              default:
                goto switchD_0055f650_caseD_7;
              }
              if (iVar7 == 0) {
switchD_0055f650_caseD_7:
                unaff_s1 = (ASN1_ITEM *)0x670000;
                pcVar16 = s_tasn_dec_c_0066a0bc;
                pAVar13 = (ASN1_ITEM *)&DAT_0000003a;
                cVar21 = -99;
                (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x83);
                AStack_16c.size = (long)pAVar6;
                goto LAB_0055fbf8;
              }
LAB_0055f6e8:
              AStack_16c.size = (int)apAStack_88[0] - ((int)pAStack_d0 - (int)pAVar6);
              pAStack_1b4 = (ASN1_ITEM *)auStack_cc;
              apAStack_88[0] = (ASN1_ITEM *)AStack_16c.size;
              iVar7 = (*(code *)PTR_sk_push_006a6fa8)(*pval);
              cVar21 = (char)pAVar20;
              pAVar6 = pAStack_d0;
              pAVar4 = apAStack_88[0];
            } while (iVar7 != 0);
            pAVar13 = (ASN1_ITEM *)&DAT_00000041;
            cVar21 = -0x5e;
          }
          goto LAB_0055fd3c;
        }
      }
    }
  }
LAB_0055fc10:
  if (pAStack_bc == *(ASN1_ITEM **)puVar2) {
    return pAVar8;
  }
  pcStack_13c = asn1_template_ex_d2i;
  pAVar8 = pAStack_bc;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_1c0 = PTR___stack_chk_guard_006a9ae8;
  pAStack_148 = param_1;
  pAStack_238 = (ASN1_ITEM *)(int)cVar21;
  AStack_16c.tcount = (long)param_8;
  pAStack_140 = pAStack_1a8;
  pAStack_144 = param_3;
  ppAStack_14c = param_2;
  pAStack_150 = (ASN1_ITEM *)pcStack_2c0;
  AStack_16c.sname = &param_5->itype;
  AStack_16c.funcs = unaff_s1;
  AStack_16c.templates = (ASN1_TEMPLATE *)*(ASN1_ITEM **)PTR___stack_chk_guard_006a9ae8;
  pAVar12 = pAStack_1b4;
  pcVar17 = pcVar16;
  if (pAVar8 == (ASN1_ITEM *)0x0) {
    pAVar8 = (ASN1_ITEM *)0x0;
    pAVar6 = pAVar13;
  }
  else {
    pAStack_1a8 = *(ASN1_ITEM **)pcVar16;
    unaff_s1 = *(ASN1_ITEM **)pAStack_1b4;
    pAStack_178 = unaff_s1;
    param_5 = (ASN1_ITEM *)pcVar16;
    if (((uint)pAStack_1a8 & 0x10) == 0) {
      pAVar8 = (ASN1_ITEM *)asn1_template_noexp_d2i();
      pAVar6 = pAVar13;
      pAStack_18c = in_stack_fffffedc;
    }
    else {
      pcVar18 = *(char **)((int)pcVar16 + 4);
      pcStack_2c0 = &pAVar8->itype;
      param_3 = pAVar13;
      AStack_16c.utype = (long)unaff_s1;
      if (in_stack_fffffedc == (ASN1_ITEM *)0x0) {
        pcVar17 = auStack_174 + 4;
        pAVar6 = (ASN1_ITEM *)auStack_174;
        pAVar12 = &AStack_16c;
        uVar5 = ASN1_get_object((uchar **)((int)&AStack_16c + 4),(long *)pAVar12,(int *)pAVar6,
                                (int *)pcVar17,(long)pAVar13);
        if ((uVar5 & 0x80) == 0) {
LAB_005602dc:
          pAVar4 = (ASN1_ITEM *)AStack_16c.utype;
          if (-1 < (int)pcVar18) {
            if ((pcVar18 != auStack_174._0_4_) ||
               (pAStack_1a8 = (ASN1_ITEM *)((uint)pAStack_1a8 & 0xc0),
               pAStack_1a8 != auStack_174._4_4_)) {
              pAVar8 = (ASN1_ITEM *)0xffffffff;
              if (pAStack_238 != (ASN1_ITEM *)0x0) goto LAB_00560360;
              if (in_stack_fffffedc != (ASN1_ITEM *)0x0) {
                in_stack_fffffedc->itype = 0;
              }
              uVar14 = 0xa8;
              goto LAB_00560310;
            }
            if (in_stack_fffffedc != (ASN1_ITEM *)0x0) {
              in_stack_fffffedc->itype = 0;
            }
          }
          param_3 = AStack_16c._0_4_;
          if ((uVar5 & 1) != 0) {
            param_3 = (ASN1_ITEM *)((int)pAVar13 - (AStack_16c.utype - (int)unaff_s1));
          }
          unaff_s1 = (ASN1_ITEM *)(int)(char)uVar5;
          pAStack_178 = (ASN1_ITEM *)AStack_16c.utype;
          if (((uint)unaff_s1 & 0x20) == 0) {
            pAVar6 = (ASN1_ITEM *)&DAT_00000078;
          }
          else {
            pAVar12 = (ASN1_ITEM *)&pAStack_178;
            pAVar6 = param_3;
            pcVar17 = pcVar16;
            iVar7 = asn1_template_noexp_d2i(pAVar8);
            if (iVar7 != 0) {
              pAStack_238 = (ASN1_ITEM *)((int)pAStack_178 - (int)pAVar4);
              param_3 = (ASN1_ITEM *)((int)param_3 - (int)pAStack_238);
              if (((uint)unaff_s1 & 1) == 0) {
                pAVar13 = pAStack_178;
                if (param_3 != (ASN1_ITEM *)0x0) {
                  pAVar6 = (ASN1_ITEM *)&DAT_00000077;
                  goto LAB_0056054c;
                }
              }
              else {
                param_3 = (ASN1_ITEM *)(uint)((int)param_3 < 2);
                if (((param_3 != (ASN1_ITEM *)0x0) || (pAStack_178->itype != '\0')) ||
                   (pAVar13 = (ASN1_ITEM *)&pAStack_178->field_0x2, pAStack_178->field_0x1 != '\0'))
                {
                  pAVar6 = (ASN1_ITEM *)&DAT_00000089;
LAB_0056054c:
                  pcVar17 = s_tasn_dec_c_0066a0bc;
                  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x84);
                  pAVar12 = (ASN1_ITEM *)pcVar16;
                  ASN1_template_free((ASN1_VALUE **)pAVar8,(ASN1_TEMPLATE *)pcVar16);
                  pAVar8 = (ASN1_ITEM *)0x0;
                  pAStack_18c = in_stack_fffffedc;
                  goto LAB_00560360;
                }
              }
              *(ASN1_ITEM **)pAStack_1b4 = pAVar13;
              pAVar8 = (ASN1_ITEM *)0x1;
              pAStack_18c = in_stack_fffffedc;
              goto LAB_00560360;
            }
            pAVar6 = (ASN1_ITEM *)&DAT_0000003a;
            pAStack_18c = in_stack_fffffedc;
          }
          pcVar17 = s_tasn_dec_c_0066a0bc;
          pAVar12 = (ASN1_ITEM *)&DAT_00000084;
          (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
          pAVar8 = (ASN1_ITEM *)0x0;
          pAStack_238 = pAVar4;
          goto LAB_00560360;
        }
        uVar14 = 0x66;
LAB_00560310:
        (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x68,uVar14,s_tasn_dec_c_0066a0bc);
      }
      else {
        if (in_stack_fffffedc->itype == '\0') {
          pcVar17 = auStack_174 + 4;
          uVar5 = ASN1_get_object((uchar **)((int)&AStack_16c + 4),(long *)&AStack_16c,
                                  (int *)auStack_174,(int *)pcVar17,(long)pAVar13);
          pAVar12 = (ASN1_ITEM *)(uVar5 & 0x81);
          in_stack_fffffedc->funcs = auStack_174._4_4_;
          in_stack_fffffedc->utype = uVar5;
          in_stack_fffffedc->templates = (ASN1_TEMPLATE *)AStack_16c._0_4_;
          in_stack_fffffedc->tcount = (long)auStack_174._0_4_;
          pAVar6 = (ASN1_ITEM *)0x1;
          in_stack_fffffedc->size = AStack_16c.utype - (int)unaff_s1;
          in_stack_fffffedc->itype = 1;
          if ((pAVar12 != (ASN1_ITEM *)0x0) ||
             ((int)AStack_16c._0_4_ + (AStack_16c.utype - (int)unaff_s1) <= (int)pAVar13))
          goto LAB_005602d4;
          uVar14 = 0x9b;
        }
        else {
          pAVar6 = (ASN1_ITEM *)in_stack_fffffedc->templates;
          pAVar12 = (ASN1_ITEM *)in_stack_fffffedc->funcs;
          auStack_174._0_4_ = (char *)in_stack_fffffedc->tcount;
          AStack_16c.utype = in_stack_fffffedc->size + (int)&unaff_s1->itype;
          uVar5 = in_stack_fffffedc->utype;
          auStack_174._4_4_ = pAVar12;
          AStack_16c._0_4_ = pAVar6;
LAB_005602d4:
          if ((uVar5 & 0x80) == 0) goto LAB_005602dc;
          uVar14 = 0x66;
        }
        (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x68,uVar14,s_tasn_dec_c_0066a0bc);
        in_stack_fffffedc->itype = 0;
      }
      unaff_s1 = (ASN1_ITEM *)0x670000;
      pcVar17 = s_tasn_dec_c_0066a0bc;
      pAVar6 = (ASN1_ITEM *)&DAT_0000003a;
      pAVar12 = (ASN1_ITEM *)&DAT_00000084;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
      pAVar8 = (ASN1_ITEM *)0x0;
    }
  }
LAB_00560360:
  if ((ASN1_ITEM *)AStack_16c.templates == *(ASN1_ITEM **)puStack_1c0) {
    return pAVar8;
  }
  pcStack_1a4 = ASN1_item_ex_d2i;
  pAStack_2d0 = (ASN1_ITEM *)AStack_16c.templates;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_248 = PTR___stack_chk_guard_006a9ae8;
  pAStack_1c8 = in_stack_fffffedc;
  pAStack_1c4 = unaff_s1;
  pAStack_1ac = param_3;
  pAStack_1b0 = pAStack_238;
  pAStack_1b8 = (ASN1_ITEM *)pcStack_2c0;
  pAStack_1bc = param_5;
  puStack_1f8 = &_gp;
  uStack_1e8 = (uint)pAStack_18c & 0x400;
  pAStack_198 = pAVar6;
  uStack_1d4 = 0;
  pAVar13 = *(ASN1_ITEM **)PTR___stack_chk_guard_006a9ae8;
  pAStack_24c = *(ASN1_ITEM_EXP **)((int)pcVar17 + 0x10);
  pAStack_1cc = pAVar13;
  pAStack_2bc = pAStack_1b4;
  if (pAStack_2d0 != (ASN1_ITEM *)0x0) {
    if (pAStack_24c == (ASN1_ITEM_EXP *)0x0) {
      bVar1 = *(byte *)(ulong *)pcVar17;
      pvStack_1e4 = (void *)0x0;
    }
    else {
      pvStack_1e4 = pAStack_24c->funcs;
      bVar1 = *(byte *)(ulong *)pcVar17;
    }
    pAStack_2bc = pAVar12;
    param_3 = (ASN1_ITEM *)pcVar17;
    if (bVar1 < 7) {
                    /* WARNING: Could not recover jumptable at 0x005606b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      pAVar13 = (ASN1_ITEM *)(*(code *)(&PTR_LAB_0066a144)[bVar1])();
      return pAVar13;
    }
  }
  if (pAVar13 == *(ASN1_ITEM **)PTR___stack_chk_guard_006a9ae8) {
    return (ASN1_ITEM *)0x0;
  }
  pcStack_22c = ASN1_template_d2i;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_2cc = PTR___stack_chk_guard_006a9ae8;
  uStack_230 = 0xffffffe0;
  pAStack_234 = param_3;
  pAStack_23c = pAStack_2bc;
  pAStack_240 = (ASN1_ITEM *)pcStack_2c0;
  pAStack_244 = param_5;
  pAStack_250 = pAStack_2d0;
  uStack_26c = 0;
  pAStack_254 = *(ASN1_ITEM **)PTR___stack_chk_guard_006a9ae8;
  pAStack_2c8 = (ASN1_ITEM *)0x0;
  pcVar16 = &pAVar12->itype;
  pcVar18 = pcVar17;
  pAStack_2b8 = pAStack_238;
  pAStack_2b0 = (ASN1_ITEM *)0xffffffe0;
  if (pAVar13 != (ASN1_ITEM *)0x0) {
    pAStack_2bc = *(ASN1_ITEM **)pcVar17;
    pAStack_2d0 = *(ASN1_ITEM **)pAVar12;
    pAStack_280 = pAStack_2d0;
    param_5 = (ASN1_ITEM *)pcVar17;
    pAStack_2b8 = pAVar12;
    if (((uint)pAStack_2bc & 0x10) == 0) {
      pAStack_2c8 = (ASN1_ITEM *)asn1_template_noexp_d2i();
    }
    else {
      iVar7 = *(long *)((int)pcVar17 + 4);
      pAStack_270 = pAStack_2d0;
      pcStack_268 = (char *)ASN1_get_object((uchar **)&pAStack_270,(long *)&pAStack_274,&iStack_27c,
                                            (int *)&pAStack_278,(long)pAVar6);
      pAVar8 = pAStack_270;
      iStack_258 = (int)pAStack_270 - (int)pAStack_2d0;
      pAStack_264 = pAStack_274;
      pAStack_25c = pAStack_278;
      iStack_260 = iStack_27c;
      uStack_26c = 1;
      pcStack_2c0 = &pAVar13->itype;
      param_3 = pAVar6;
      pAStack_2b0 = pAStack_274;
      if ((((uint)pcStack_268 & 0x81) == 0) && ((int)pAVar6 < (int)pAStack_274 + iStack_258)) {
        uVar14 = 0x9b;
LAB_0056138c:
        (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x68,uVar14,s_tasn_dec_c_0066a0bc);
        uStack_26c = 0;
      }
      else {
        pAStack_2c8 = (ASN1_ITEM *)((uint)pcStack_268 & 0x80);
        if (pAStack_2c8 != (ASN1_ITEM *)0x0) {
          uVar14 = 0x66;
          goto LAB_0056138c;
        }
        if (iVar7 < 0) {
LAB_00561334:
          pAStack_2bc = (ASN1_ITEM *)(int)(char)pcStack_268;
          pAStack_280 = pAStack_270;
          pAStack_2d0 = (ASN1_ITEM *)((int)pAVar6 - iStack_258);
          if (((uint)pcStack_268 & 1) != 0) {
            pAStack_2b0 = pAStack_2d0;
          }
          if (((uint)pAStack_2bc & 0x20) == 0) {
            pAVar6 = (ASN1_ITEM *)&DAT_00000078;
          }
          else {
            pcVar16 = (char *)&pAStack_280;
            pAVar6 = pAStack_2b0;
            iVar7 = asn1_template_noexp_d2i(pAVar13);
            if (iVar7 != 0) {
              pAStack_2bc = (ASN1_ITEM *)((uint)pAStack_2bc & 1);
              pAStack_2b0 = (ASN1_ITEM *)((int)pAStack_2b0 - ((int)pAStack_280 - (int)pAVar8));
              if (pAStack_2bc == (ASN1_ITEM *)0x0) {
                pAVar8 = pAStack_280;
                if (pAStack_2b0 != (ASN1_ITEM *)0x0) {
                  pAVar6 = (ASN1_ITEM *)&DAT_00000077;
                  goto LAB_0056143c;
                }
              }
              else {
                pAStack_2b0 = (ASN1_ITEM *)(uint)((int)pAStack_2b0 < 2);
                if (((pAStack_2b0 != (ASN1_ITEM *)0x0) || (pAStack_280->itype != '\0')) ||
                   (pAStack_280->field_0x1 != '\0')) {
                  pAVar6 = (ASN1_ITEM *)&DAT_00000089;
LAB_0056143c:
                  pcVar18 = s_tasn_dec_c_0066a0bc;
                  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x84);
                  pcVar16 = pcVar17;
                  ASN1_template_free((ASN1_VALUE **)pAVar13,(ASN1_TEMPLATE *)pcVar17);
                  goto LAB_005611f0;
                }
                pAVar8 = (ASN1_ITEM *)&pAStack_280->field_0x2;
              }
              *(ASN1_ITEM **)pAVar12 = pAVar8;
              pAStack_2c8 = (ASN1_ITEM *)0x1;
              goto LAB_005611f0;
            }
            pAVar6 = (ASN1_ITEM *)&DAT_0000003a;
          }
          pcVar18 = s_tasn_dec_c_0066a0bc;
          pcVar16 = &DAT_00000084;
          (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
          goto LAB_005611f0;
        }
        if ((iVar7 == iStack_27c) &&
           (pAStack_2bc = (ASN1_ITEM *)((uint)pAStack_2bc & 0xc0), pAStack_2bc == pAStack_278)) {
          uStack_26c = 0;
          goto LAB_00561334;
        }
        uStack_26c = 0;
        (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x68,0xa8,s_tasn_dec_c_0066a0bc);
      }
      pAStack_2d0 = (ASN1_ITEM *)0x670000;
      pcVar18 = s_tasn_dec_c_0066a0bc;
      pAVar6 = (ASN1_ITEM *)&DAT_0000003a;
      pcVar16 = &DAT_00000084;
      pAStack_2c8 = (ASN1_ITEM *)0x0;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
    }
  }
LAB_005611f0:
  if (pAStack_254 == *(ASN1_ITEM **)puStack_2cc) {
    return pAStack_2c8;
  }
  pcStack_2ac = ASN1_item_d2i;
  pAVar13 = pAStack_254;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  pvVar19 = *(void **)((int)pcVar18 + 0x10);
  pAStack_2c4 = param_5;
  pAStack_2b4 = param_3;
  auStack_2fc = (undefined  [4])0x0;
  auStack_2ec[0] = 0;
  pAStack_2f8 = pAVar6;
  pAStack_2f4 = (ASN1_TEMPLATE *)0x0;
  pAVar8 = (ASN1_ITEM *)auStack_2fc;
  if (pAVar13 != (ASN1_ITEM *)0x0) {
    pAVar8 = pAVar13;
  }
  piStack_2d4 = *(int **)PTR___stack_chk_guard_006a9ae8;
  if (pvVar19 == (void *)0x0) {
    switch(*pcVar18) {
    case '\0':
      goto switchD_005619f8_caseD_0;
    case '\x01':
    case '\x06':
      pcStack_310 = (code *)0x0;
      goto switchD_00561550_caseD_1;
    case '\x02':
      pcStack_310 = (code *)0x0;
LAB_00561954:
      if (*(int *)pAVar8 == 0) {
        iVar7 = ASN1_item_ex_new((ASN1_VALUE **)pAVar8,(ASN1_ITEM *)pcVar18);
        if (iVar7 == 0) {
          uVar15 = 0x3a;
          uVar14 = 0x13f;
          goto LAB_0056163c;
        }
        pAVar12 = *(ASN1_ITEM **)((int)pcVar18 + 0xc);
      }
      else {
        iVar7 = asn1_get_choice_selector((ASN1_VALUE **)pAVar8,(ASN1_ITEM *)pcVar18);
        pAVar12 = *(ASN1_ITEM **)((int)pcVar18 + 0xc);
        if ((-1 < iVar7) && (iVar7 < (int)pAVar12)) {
          pAVar11 = *(ASN1_TEMPLATE **)((int)pcVar18 + 8);
          ppAVar10 = asn1_get_field_ptr((ASN1_VALUE **)pAVar8,pAVar11 + iVar7);
          ASN1_template_free(ppAVar10,pAVar11 + iVar7);
          asn1_set_choice_selector((ASN1_VALUE **)pAVar8,-1,(ASN1_ITEM *)pcVar18);
          pAVar12 = *(ASN1_ITEM **)((int)pcVar18 + 0xc);
        }
      }
      pAStack_2f4 = *(ASN1_TEMPLATE **)pcVar16;
      pAVar13 = (ASN1_ITEM *)0x0;
      pAVar11 = *(ASN1_TEMPLATE **)((int)pcVar18 + 8);
      if ((int)pAVar12 < 1) {
LAB_005615e0:
        if (pAVar13 == pAVar12) {
LAB_00561a34:
          uVar15 = 0x8f;
          uVar14 = 0x15e;
          goto LAB_0056163c;
        }
      }
      else {
        do {
          ppAVar10 = asn1_get_field_ptr((ASN1_VALUE **)pAVar8,pAVar11);
          iVar7 = asn1_template_ex_d2i(ppAVar10,auStack_2fc + 8,pAStack_2f8,pAVar11,1,auStack_2ec);
          if (iVar7 != -1) {
            if (iVar7 < 1) {
              (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x78,0x3a,s_tasn_dec_c_0066a0bc,0x152);
              ASN1_item_ex_free((ASN1_VALUE **)pAVar8,(ASN1_ITEM *)pcVar18);
              if (pAVar11 == (ASN1_TEMPLATE *)0x0) goto LAB_00561668;
              goto LAB_00561cf8;
            }
            pAVar12 = *(ASN1_ITEM **)((int)pcVar18 + 0xc);
            goto LAB_005615e0;
          }
          pAVar13 = (ASN1_ITEM *)&pAVar13->field_0x1;
          pAVar11 = pAVar11 + 1;
        } while ((int)pAVar13 < (int)*(undefined **)((int)pcVar18 + 0xc));
        if (pAVar13 == (ASN1_ITEM *)*(undefined **)((int)pcVar18 + 0xc)) goto LAB_00561a34;
      }
      asn1_set_choice_selector((ASN1_VALUE **)pAVar8,(int)pAVar13,(ASN1_ITEM *)pcVar18);
      goto joined_r0x00561600;
    case '\x03':
      goto switchD_005619f8_caseD_3;
    case '\x04':
      pcStack_310 = *(code **)(in_zero + 0x10);
      goto LAB_005618f4;
    case '\x05':
      goto switchD_005619f8_caseD_5;
    }
    goto switchD_005619f8_caseD_7;
  }
  pcStack_310 = *(code **)((int)pvVar19 + 0x10);
  switch(*pcVar18) {
  case '\0':
switchD_005619f8_caseD_0:
    if (*(ASN1_TEMPLATE **)((int)pcVar18 + 8) == (ASN1_TEMPLATE *)0x0) {
      iVar7 = asn1_d2i_ex_primitive(pAVar8,pcVar16,pAVar6,pcVar18,0xffffffff,0,0,auStack_2ec);
      if (iVar7 < 1) {
        pAVar12 = (ASN1_ITEM *)0x0;
        pAVar13 = (ASN1_ITEM *)pcVar16;
        goto LAB_00561684;
      }
    }
    else {
      iVar7 = asn1_template_ex_d2i
                        (pAVar8,pcVar16,pAVar6,*(ASN1_TEMPLATE **)((int)pcVar18 + 8),0,auStack_2ec);
      if (iVar7 < 1) goto switchD_005619f8_caseD_7;
    }
    goto LAB_005617a4;
  case '\x01':
  case '\x06':
switchD_00561550_caseD_1:
    pAStack_2f4 = *(ASN1_TEMPLATE **)pcVar16;
    pAVar13 = (ASN1_ITEM *)0x0;
    iVar7 = asn1_check_tlen(auStack_2fc + 4,0,0,&cStack_2fe,&cStack_2fd,auStack_2fc + 8,pAVar6,0x10,
                            0,0,auStack_2ec);
    if (iVar7 == 0) {
      uVar15 = 0x3a;
      uVar14 = 0x176;
    }
    else {
      pAVar12 = (ASN1_ITEM *)0x0;
      if (iVar7 == -1) goto LAB_00561684;
      cVar21 = cStack_2fe;
      if ((pvVar19 != (void *)0x0) && ((*(uint *)((int)pvVar19 + 4) & 4) != 0)) {
        pAStack_2f8 = (ASN1_ITEM *)((int)pAVar6 - ((int)pAStack_2f4 - *(int *)pcVar16));
        cVar21 = '\x01';
      }
      if (cStack_2fd == '\0') {
        uVar15 = 0x95;
        uVar14 = 0x182;
      }
      else if ((*(int *)pAVar8 == 0) &&
              (iVar7 = ASN1_item_ex_new((ASN1_VALUE **)pAVar8,(ASN1_ITEM *)pcVar18), iVar7 == 0)) {
        uVar15 = 0x3a;
        uVar14 = 0x187;
      }
      else {
        puStack_308 = auStack_2ec;
        if ((pcStack_310 != (code *)0x0) && (iVar7 = (*pcStack_310)(4,pAVar8,pcVar18,0), iVar7 == 0)
           ) goto LAB_00561628;
        iVar7 = *(long *)((int)pcVar18 + 0xc);
        iVar9 = 0;
        tt = *(ASN1_TEMPLATE **)((int)pcVar18 + 8);
        if (0 < iVar7) {
          do {
            if ((tt->flags & 0x300) != 0) {
              pAVar11 = asn1_do_adb((ASN1_VALUE **)pAVar8,tt,1);
              ppAVar10 = asn1_get_field_ptr((ASN1_VALUE **)pAVar8,pAVar11);
              ASN1_template_free(ppAVar10,pAVar11);
              iVar7 = *(long *)((int)pcVar18 + 0xc);
            }
            iVar9 = iVar9 + 1;
            tt = tt + 1;
          } while (iVar9 < iVar7);
          tt = *(ASN1_TEMPLATE **)((int)pcVar18 + 8);
          iVar9 = 0;
          if (0 < iVar7) {
            do {
              pAVar11 = asn1_do_adb((ASN1_VALUE **)pAVar8,tt,1);
              if (pAVar11 == (ASN1_TEMPLATE *)0x0) goto LAB_00561650;
              ppAVar10 = asn1_get_field_ptr((ASN1_VALUE **)pAVar8,pAVar11);
              pAVar3 = pAStack_2f4;
              if (pAStack_2f8 == (ASN1_ITEM *)0x0) {
                if (cStack_2fe != '\0') goto LAB_00561e04;
                goto LAB_00561c3c;
              }
              if (((1 < (int)pAStack_2f8) && (*(char *)&pAStack_2f4->flags == '\0')) &&
                 (*(char *)((int)&pAStack_2f4->flags + 1) == '\0')) {
                pAStack_2f4 = (ASN1_TEMPLATE *)((int)&pAStack_2f4->flags + 2);
                if (cStack_2fe != '\0') {
                  cStack_2fe = '\0';
                  pAStack_2f8 = (ASN1_ITEM *)((int)&pAStack_2f8[-1].sname + 2);
                  goto LAB_00561c28;
                }
                uVar15 = 0x9f;
                uVar14 = 0x1a7;
                goto LAB_0056163c;
              }
              uVar5 = 0;
              if (*(long *)((int)pcVar18 + 0xc) + -1 != iVar9) {
                uVar5 = pAVar11->flags & 1;
              }
              iVar7 = asn1_template_ex_d2i
                                (ppAVar10,auStack_2fc + 8,pAStack_2f8,pAVar11,uVar5,puStack_308);
              if (iVar7 == 0) goto LAB_00561ce4;
              if (iVar7 == -1) {
                ASN1_template_free(ppAVar10,pAVar11);
              }
              else {
                pAStack_2f8 = (ASN1_ITEM *)((int)pAStack_2f8 - ((int)pAStack_2f4 - (int)pAVar3));
              }
              iVar9 = iVar9 + 1;
              tt = tt + 1;
            } while (iVar9 < *(long *)((int)pcVar18 + 0xc));
          }
        }
        if (cStack_2fe != '\0') {
          if ((((int)pAStack_2f8 < 2) || (*(char *)&pAStack_2f4->flags != '\0')) ||
             (*(char *)((int)&pAStack_2f4->flags + 1) != '\0')) {
LAB_00561e04:
            uVar15 = 0x89;
            uVar14 = 0x1ce;
            break;
          }
          pAStack_2f4 = (ASN1_TEMPLATE *)((int)&pAStack_2f4->flags + 2);
        }
LAB_00561c28:
        if ((cVar21 != '\0') || (pAStack_2f8 == (ASN1_ITEM *)0x0)) {
LAB_00561c3c:
          if (iVar9 < *(long *)((int)pcVar18 + 0xc)) {
LAB_00561c90:
            pAVar11 = asn1_do_adb((ASN1_VALUE **)pAVar8,tt,1);
            if (pAVar11 != (ASN1_TEMPLATE *)0x0) {
              if ((pAVar11->flags & 1) != 0) goto LAB_00561c54;
              (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x78,0x79,s_tasn_dec_c_0066a0bc,0x1e7);
LAB_00561ce4:
              ASN1_item_ex_free((ASN1_VALUE **)pAVar8,(ASN1_ITEM *)pcVar18);
LAB_00561cf8:
              pcVar16 = (char *)&DAT_0066a0d0;
              (*(code *)PTR_ERR_add_error_data_006a813c)
                        (4,&DAT_0066a0d0,pAVar11->field_name,", Type=",
                         *(char **)((int)pcVar18 + 0x18));
              goto switchD_005619f8_caseD_7;
            }
            goto LAB_00561650;
          }
          pAVar13 = *(ASN1_ITEM **)pcVar16;
          goto LAB_00561a70;
        }
        uVar15 = 0x94;
        uVar14 = 0x1d3;
      }
    }
    break;
  case '\x02':
    if ((pcStack_310 == (code *)0x0) || (iVar7 = (*pcStack_310)(4,pAVar8,pcVar18,0), iVar7 != 0))
    goto LAB_00561954;
    goto LAB_00561628;
  case '\x03':
switchD_005619f8_caseD_3:
    iVar7 = (**(code **)((int)pvVar19 + 8))(pAVar8,pcVar16,pAVar6);
    if (iVar7 != 0) {
      pAVar12 = *(ASN1_ITEM **)pAVar8;
      pAVar13 = (ASN1_ITEM *)pcVar16;
      goto LAB_00561684;
    }
    uVar15 = 0x3a;
    uVar14 = 0x12f;
    break;
  case '\x04':
LAB_005618f4:
    iVar7 = (*pcStack_310)(pAVar8,pcVar16,pAVar6,pcVar18,0xffffffff,0,0,auStack_2ec);
    if (iVar7 < 1) {
      pAVar12 = (ASN1_ITEM *)0x0;
      pAVar13 = (ASN1_ITEM *)pcVar16;
      goto LAB_00561684;
    }
LAB_005617a4:
    pAVar12 = *(ASN1_ITEM **)pAVar8;
    pAVar13 = (ASN1_ITEM *)pcVar16;
    goto LAB_00561684;
  case '\x05':
switchD_005619f8_caseD_5:
    pAStack_2f4 = *(ASN1_TEMPLATE **)pcVar16;
    iVar7 = asn1_check_tlen_constprop_1
                      (0,auStack_2fc + 0xc,&cStack_2ff,0,0,auStack_2fc + 8,pAVar6,1,auStack_2ec);
    if (iVar7 == 0) {
      uVar15 = 0x3a;
      uVar14 = 0xdb;
    }
    else if (cStack_2ff == '\0') {
      if ((uStack_2f0 < 0x1f) &&
         ((*(uint *)(tag2bit + uStack_2f0 * 4) & *(long *)((int)pcVar18 + 4)) != 0)) {
        iVar7 = asn1_d2i_ex_primitive(pAVar8,pcVar16,pAStack_2f8,pcVar18,uStack_2f0,0,0,auStack_2ec)
        ;
        if (iVar7 < 1) {
          pAVar12 = (ASN1_ITEM *)0x0;
          pAVar13 = (ASN1_ITEM *)pcVar16;
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
  ASN1_item_ex_free((ASN1_VALUE **)pAVar8,(ASN1_ITEM *)pcVar18);
LAB_00561668:
  pcVar16 = s_Type__0066a0d8;
  (*(code *)PTR_ERR_add_error_data_006a813c)(2,s_Type__0066a0d8,*(char **)((int)pcVar18 + 0x18));
switchD_005619f8_caseD_7:
  pAVar12 = (ASN1_ITEM *)0x0;
  pAVar13 = (ASN1_ITEM *)pcVar16;
LAB_00561684:
  if (piStack_2d4 == *(int **)puVar2) {
    return pAVar12;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  return *(ASN1_ITEM **)(pAVar13->utype + *piStack_2d4);
code_r0x0055ff00:
  param_2 = (ASN1_ITEM **)((int)param_2 + 1);
  ppAVar10 = asn1_get_field_ptr((ASN1_VALUE **)auStack_cc,(ASN1_TEMPLATE *)pAStack_1a8);
  unaff_s1 = (ASN1_ITEM *)&unaff_s1->size;
  ASN1_template_free(ppAVar10,(ASN1_TEMPLATE *)pAStack_1a8);
  if (param_8->tcount <= (int)param_2) goto LAB_0055fe40;
  goto LAB_0055ff3c;
LAB_00561c54:
  iVar9 = iVar9 + 1;
  ppAVar10 = asn1_get_field_ptr((ASN1_VALUE **)pAVar8,pAVar11);
  tt = tt + 1;
  ASN1_template_free(ppAVar10,pAVar11);
  if (*(long *)((int)pcVar18 + 0xc) <= iVar9) goto LAB_00561a6c;
  goto LAB_00561c90;
LAB_00561a6c:
  pAVar13 = *(ASN1_ITEM **)pcVar16;
LAB_00561a70:
  iVar7 = asn1_enc_save((ASN1_VALUE **)pAVar8,(uchar *)pAVar13,(int)pAStack_2f4 - (int)pAVar13,
                        (ASN1_ITEM *)pcVar18);
  if (iVar7 != 0) {
joined_r0x00561600:
    if ((pcStack_310 == (code *)0x0) ||
       (pAVar13 = pAVar8, iVar7 = (*pcStack_310)(5,pAVar8,pcVar18,0), iVar7 != 0)) {
      *(ASN1_TEMPLATE **)pcVar16 = pAStack_2f4;
      pAVar12 = *(ASN1_ITEM **)pAVar8;
      goto LAB_00561684;
    }
  }
LAB_00561628:
  uVar15 = 100;
  uVar14 = 0x1f7;
  goto LAB_0056163c;
}

