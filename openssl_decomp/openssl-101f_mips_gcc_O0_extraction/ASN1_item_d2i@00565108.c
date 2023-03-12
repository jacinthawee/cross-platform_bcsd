
ASN1_VALUE * ASN1_item_d2i(ASN1_VALUE **val,uchar **in,long len,ASN1_ITEM *it)

{
  char cVar1;
  undefined *puVar2;
  uchar *puVar3;
  int in_zero;
  ASN1_VALUE **ppAVar4;
  undefined4 uVar5;
  ASN1_VALUE *pAVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  ASN1_TEMPLATE *tt;
  char *pcVar10;
  ASN1_VALUE **ppAVar11;
  undefined4 uVar12;
  ASN1_VALUE **pval;
  void *pvVar13;
  ASN1_TEMPLATE *tt_00;
  code *local_68;
  undefined *local_60;
  char local_57;
  char local_56;
  char local_55;
  ASN1_VALUE *local_54;
  int local_50;
  uchar *local_4c;
  uint local_48;
  undefined local_44 [24];
  int *local_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  pvVar13 = it->funcs;
  local_54 = (ASN1_VALUE *)0x0;
  local_44[0] = 0;
  local_50 = len;
  local_4c = (uchar *)0x0;
  pval = &local_54;
  if (val != (ASN1_VALUE **)0x0) {
    pval = val;
  }
  local_2c = *(int **)PTR___stack_chk_guard_006aabf0;
  if (pvVar13 == (void *)0x0) {
    switch(it->itype) {
    case '\0':
      goto switchD_00565630_caseD_0;
    case '\x01':
    case '\x06':
      local_68 = (code *)0x0;
      goto switchD_005651a0_caseD_1;
    case '\x02':
      local_68 = (code *)0x0;
LAB_005651ac:
      if ((*pval == (ASN1_VALUE *)0x0) && (iVar7 = ASN1_item_ex_new(pval,it), iVar7 == 0)) {
        uVar12 = 0x3a;
        uVar5 = 0x13e;
        goto LAB_00565288;
      }
      local_4c = *in;
      ppAVar11 = (ASN1_VALUE **)0x0;
      ppAVar4 = (ASN1_VALUE **)it->tcount;
      tt = it->templates;
      if ((int)ppAVar4 < 1) {
LAB_00565228:
        if (ppAVar11 == ppAVar4) {
LAB_0056566c:
          uVar12 = 0x8f;
          uVar5 = 0x162;
          goto LAB_00565288;
        }
      }
      else {
        do {
          ppAVar4 = asn1_get_field_ptr(pval,tt);
          iVar7 = asn1_template_ex_d2i(ppAVar4,&local_4c,local_50,tt,1,local_44);
          if (iVar7 != -1) {
            if (0 < iVar7) {
              ppAVar4 = (ASN1_VALUE **)it->tcount;
              goto LAB_00565228;
            }
            (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x78,0x3a,s_tasn_dec_c_0066ab0c,0x153);
            ASN1_item_ex_free(pval,it);
            if (tt != (ASN1_TEMPLATE *)0x0) goto LAB_005657fc;
            goto LAB_005652b4;
          }
          ppAVar11 = (ASN1_VALUE **)((int)ppAVar11 + 1);
          tt = tt + 1;
        } while ((int)ppAVar11 < (int)(ASN1_VALUE **)it->tcount);
        if (ppAVar11 == (ASN1_VALUE **)it->tcount) goto LAB_0056566c;
      }
      asn1_set_choice_selector(pval,(int)ppAVar11,it);
      *in = local_4c;
      if (local_68 == (code *)0x0) goto LAB_00565328;
      goto LAB_00565258;
    case '\x03':
      goto switchD_00565630_caseD_3;
    case '\x04':
      local_68 = *(code **)(in_zero + 0x10);
      goto LAB_005655ac;
    case '\x05':
      goto switchD_00565630_caseD_5;
    }
    goto switchD_00565630_caseD_7;
  }
  local_68 = *(code **)((int)pvVar13 + 0x10);
  switch(it->itype) {
  case '\0':
switchD_00565630_caseD_0:
    if (it->templates == (ASN1_TEMPLATE *)0x0) {
      iVar7 = asn1_d2i_ex_primitive(pval,in,len,it,0xffffffff,0,0,local_44);
      if (iVar7 < 1) {
        pAVar6 = (ASN1_VALUE *)0x0;
        ppAVar11 = (ASN1_VALUE **)in;
        goto LAB_005652d0;
      }
    }
    else {
      iVar7 = asn1_template_ex_d2i(pval,in,len,it->templates,0,local_44);
      if (iVar7 < 1) goto switchD_00565630_caseD_7;
    }
    goto LAB_005653f0;
  case '\x01':
  case '\x06':
switchD_005651a0_caseD_1:
    local_4c = *in;
    ppAVar11 = (ASN1_VALUE **)0x0;
    iVar7 = asn1_check_tlen(&local_50,0,0,&local_56,&local_55,&local_4c,len,0x10,0,0,local_44);
    if (iVar7 == 0) {
      uVar12 = 0x3a;
      uVar5 = 0x17d;
    }
    else {
      pAVar6 = (ASN1_VALUE *)0x0;
      if (iVar7 == -1) goto LAB_005652d0;
      cVar1 = local_56;
      if ((pvVar13 != (void *)0x0) && ((*(uint *)((int)pvVar13 + 4) & 4) != 0)) {
        local_50 = len - ((int)local_4c - (int)*in);
        cVar1 = '\x01';
      }
      if (local_55 == '\0') {
        uVar12 = 0x95;
        uVar5 = 0x18c;
      }
      else if ((*pval == (ASN1_VALUE *)0x0) && (iVar7 = ASN1_item_ex_new(pval,it), iVar7 == 0)) {
        uVar12 = 0x3a;
        uVar5 = 0x193;
      }
      else {
        local_60 = local_44;
        if ((local_68 != (code *)0x0) && (iVar7 = (*local_68)(4,pval,it,0), iVar7 == 0))
        goto LAB_00565278;
        iVar7 = 0;
        tt_00 = it->templates;
        if (0 < it->tcount) {
          do {
            tt = asn1_do_adb(pval,tt_00,1);
            if (tt == (ASN1_TEMPLATE *)0x0) goto LAB_0056529c;
            ppAVar11 = asn1_get_field_ptr(pval,tt);
            puVar3 = local_4c;
            if (local_50 == 0) {
              if (local_56 != '\0') goto LAB_00565908;
              goto LAB_00565740;
            }
            if (((1 < local_50) && (*local_4c == '\0')) && (local_4c[1] == '\0')) {
              if (local_56 != '\0') {
                local_50 = local_50 + -2;
                local_56 = '\0';
                local_4c = local_4c + 2;
                goto LAB_0056572c;
              }
              uVar12 = 0x9f;
              uVar5 = 0x1ac;
              local_4c = local_4c + 2;
              goto LAB_00565288;
            }
            uVar9 = 0;
            if (iVar7 != it->tcount + -1) {
              uVar9 = tt->flags & 1;
            }
            iVar8 = asn1_template_ex_d2i(ppAVar11,&local_4c,local_50,tt,uVar9,local_60);
            if (iVar8 == 0) goto LAB_005657e8;
            if (iVar8 == -1) {
              ASN1_template_free(ppAVar11,tt);
            }
            else {
              local_50 = local_50 - ((int)local_4c - (int)puVar3);
            }
            iVar7 = iVar7 + 1;
            tt_00 = tt_00 + 1;
          } while (iVar7 < it->tcount);
        }
        if (local_56 != '\0') {
          if (((local_50 < 2) || (*local_4c != '\0')) || (local_4c[1] != '\0')) {
LAB_00565908:
            uVar12 = 0x89;
            uVar5 = 0x1d6;
            break;
          }
          local_4c = local_4c + 2;
        }
LAB_0056572c:
        if ((cVar1 != '\0') || (local_50 == 0)) {
LAB_00565740:
          if (iVar7 < it->tcount) {
LAB_00565794:
            tt = asn1_do_adb(pval,tt_00,1);
            if (tt != (ASN1_TEMPLATE *)0x0) {
              if ((tt->flags & 1) != 0) goto LAB_00565758;
              (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x78,0x79,s_tasn_dec_c_0066ab0c,0x1f5);
LAB_005657e8:
              ASN1_item_ex_free(pval,it);
LAB_005657fc:
              in = (uchar **)&DAT_0066ab20;
              (*(code *)PTR_ERR_add_error_data_006a9264)
                        (4,&DAT_0066ab20,tt->field_name,", Type=",it->sname);
              goto switchD_00565630_caseD_7;
            }
            goto LAB_0056529c;
          }
          ppAVar11 = (ASN1_VALUE **)*in;
          goto LAB_00565954;
        }
        uVar12 = 0x94;
        uVar5 = 0x1dd;
      }
    }
    break;
  case '\x02':
    if ((local_68 == (code *)0x0) || (iVar7 = (*local_68)(4,pval,it,0), iVar7 != 0))
    goto LAB_005651ac;
    goto LAB_00565278;
  case '\x03':
switchD_00565630_caseD_3:
    iVar7 = (**(code **)((int)pvVar13 + 8))(pval,in,len);
    ppAVar11 = (ASN1_VALUE **)in;
    if (iVar7 != 0) goto LAB_00565328;
    uVar12 = 0x3a;
    uVar5 = 0x132;
    break;
  case '\x04':
LAB_005655ac:
    iVar7 = (*local_68)(pval,in,len,it,0xffffffff,0,0,local_44);
    if (iVar7 < 1) {
      pAVar6 = (ASN1_VALUE *)0x0;
      ppAVar11 = (ASN1_VALUE **)in;
      goto LAB_005652d0;
    }
LAB_005653f0:
    pAVar6 = *pval;
    ppAVar11 = (ASN1_VALUE **)in;
    goto LAB_005652d0;
  case '\x05':
switchD_00565630_caseD_5:
    local_4c = *in;
    iVar7 = asn1_check_tlen_constprop_1(0,&local_48,&local_57,0,0,&local_4c,len,1,local_44);
    if (iVar7 == 0) {
      uVar12 = 0x3a;
      uVar5 = 0xd2;
    }
    else if (local_57 == '\0') {
      if ((local_48 < 0x1f) && ((*(uint *)(tag2bit + local_48 * 4) & it->utype) != 0)) {
        iVar7 = asn1_d2i_ex_primitive(pval,in,local_50,it,local_48,0,0,local_44);
        if (iVar7 < 1) {
          pAVar6 = (ASN1_VALUE *)0x0;
          ppAVar11 = (ASN1_VALUE **)in;
          goto LAB_005652d0;
        }
        goto LAB_005653f0;
      }
      uVar12 = 0x8c;
      uVar5 = 0xe6;
    }
    else {
      uVar12 = 0x8b;
      uVar5 = 0xdc;
    }
    break;
  default:
    goto switchD_00565630_caseD_7;
  }
LAB_00565288:
  (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x78,uVar12,s_tasn_dec_c_0066ab0c,uVar5);
LAB_0056529c:
  ASN1_item_ex_free(pval,it);
LAB_005652b4:
  pcVar10 = s_Type__0066ab28;
  (*(code *)PTR_ERR_add_error_data_006a9264)(2,s_Type__0066ab28,it->sname);
  in = (uchar **)pcVar10;
switchD_00565630_caseD_7:
  pAVar6 = (ASN1_VALUE *)0x0;
  ppAVar11 = (ASN1_VALUE **)in;
LAB_005652d0:
  if (local_2c == *(int **)puVar2) {
    return pAVar6;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  return *(ASN1_VALUE **)(ppAVar11[1] + *local_2c);
LAB_00565758:
  iVar7 = iVar7 + 1;
  ppAVar11 = asn1_get_field_ptr(pval,tt);
  tt_00 = tt_00 + 1;
  ASN1_template_free(ppAVar11,tt);
  if (it->tcount <= iVar7) goto LAB_00565950;
  goto LAB_00565794;
LAB_00565950:
  ppAVar11 = (ASN1_VALUE **)*in;
LAB_00565954:
  iVar7 = asn1_enc_save(pval,(uchar *)ppAVar11,(int)local_4c - (int)ppAVar11,it);
  if (iVar7 != 0) {
    *in = local_4c;
    if (local_68 == (code *)0x0) {
      pAVar6 = *pval;
      goto LAB_005652d0;
    }
LAB_00565258:
    ppAVar11 = pval;
    iVar7 = (*local_68)(5,pval,it,0);
    if (iVar7 != 0) {
LAB_00565328:
      pAVar6 = *pval;
      goto LAB_005652d0;
    }
  }
LAB_00565278:
  uVar12 = 100;
  uVar5 = 0x205;
  goto LAB_00565288;
}

