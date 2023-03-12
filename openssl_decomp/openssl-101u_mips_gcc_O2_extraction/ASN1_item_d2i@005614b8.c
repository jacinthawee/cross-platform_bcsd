
ASN1_VALUE * ASN1_item_d2i(ASN1_VALUE **val,uchar **in,long len,ASN1_ITEM *it)

{
  char cVar1;
  undefined *puVar2;
  uchar *puVar3;
  int in_zero;
  undefined4 uVar4;
  ASN1_VALUE *pAVar5;
  int iVar6;
  uint uVar7;
  ASN1_TEMPLATE *pAVar8;
  ASN1_VALUE **ppAVar9;
  char *pcVar10;
  ASN1_VALUE **ppAVar11;
  undefined4 uVar12;
  ASN1_VALUE **pval;
  void *pvVar13;
  ASN1_TEMPLATE *tt;
  int iVar14;
  code *local_68;
  undefined *local_60;
  char local_57;
  char local_56;
  char local_55;
  ASN1_VALUE *local_54;
  long local_50;
  uchar *local_4c;
  uint local_48;
  undefined local_44 [24];
  int *local_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  pvVar13 = it->funcs;
  local_54 = (ASN1_VALUE *)0x0;
  local_44[0] = 0;
  local_50 = len;
  local_4c = (uchar *)0x0;
  pval = &local_54;
  if (val != (ASN1_VALUE **)0x0) {
    pval = val;
  }
  local_2c = *(int **)PTR___stack_chk_guard_006a9ae8;
  if (pvVar13 == (void *)0x0) {
    switch(it->itype) {
    case '\0':
      goto switchD_005619f8_caseD_0;
    case '\x01':
    case '\x06':
      local_68 = (code *)0x0;
      goto switchD_00561550_caseD_1;
    case '\x02':
      local_68 = (code *)0x0;
LAB_00561954:
      if (*pval == (ASN1_VALUE *)0x0) {
        iVar6 = ASN1_item_ex_new(pval,it);
        if (iVar6 == 0) {
          uVar12 = 0x3a;
          uVar4 = 0x13f;
          goto LAB_0056163c;
        }
        ppAVar9 = (ASN1_VALUE **)it->tcount;
      }
      else {
        iVar6 = asn1_get_choice_selector(pval,it);
        ppAVar9 = (ASN1_VALUE **)it->tcount;
        if ((-1 < iVar6) && (iVar6 < (int)ppAVar9)) {
          pAVar8 = it->templates;
          ppAVar11 = asn1_get_field_ptr(pval,pAVar8 + iVar6);
          ASN1_template_free(ppAVar11,pAVar8 + iVar6);
          asn1_set_choice_selector(pval,-1,it);
          ppAVar9 = (ASN1_VALUE **)it->tcount;
        }
      }
      local_4c = *in;
      ppAVar11 = (ASN1_VALUE **)0x0;
      pAVar8 = it->templates;
      if ((int)ppAVar9 < 1) {
LAB_005615e0:
        if (ppAVar11 == ppAVar9) {
LAB_00561a34:
          uVar12 = 0x8f;
          uVar4 = 0x15e;
          goto LAB_0056163c;
        }
      }
      else {
        do {
          ppAVar9 = asn1_get_field_ptr(pval,pAVar8);
          iVar6 = asn1_template_ex_d2i(ppAVar9,&local_4c,local_50,pAVar8,1,local_44);
          if (iVar6 != -1) {
            if (iVar6 < 1) {
              (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x78,0x3a,s_tasn_dec_c_0066a0bc,0x152);
              ASN1_item_ex_free(pval,it);
              if (pAVar8 == (ASN1_TEMPLATE *)0x0) goto LAB_00561668;
              goto LAB_00561cf8;
            }
            ppAVar9 = (ASN1_VALUE **)it->tcount;
            goto LAB_005615e0;
          }
          ppAVar11 = (ASN1_VALUE **)((int)ppAVar11 + 1);
          pAVar8 = pAVar8 + 1;
        } while ((int)ppAVar11 < (int)(ASN1_VALUE **)it->tcount);
        if (ppAVar11 == (ASN1_VALUE **)it->tcount) goto LAB_00561a34;
      }
      asn1_set_choice_selector(pval,(int)ppAVar11,it);
      goto joined_r0x00561600;
    case '\x03':
      goto switchD_005619f8_caseD_3;
    case '\x04':
      local_68 = *(code **)(in_zero + 0x10);
      goto LAB_005618f4;
    case '\x05':
      goto switchD_005619f8_caseD_5;
    }
    goto switchD_005619f8_caseD_7;
  }
  local_68 = *(code **)((int)pvVar13 + 0x10);
  switch(it->itype) {
  case '\0':
switchD_005619f8_caseD_0:
    if (it->templates == (ASN1_TEMPLATE *)0x0) {
      iVar6 = asn1_d2i_ex_primitive(pval,in,len,it,0xffffffff,0,0,local_44);
      if (iVar6 < 1) {
        pAVar5 = (ASN1_VALUE *)0x0;
        ppAVar11 = (ASN1_VALUE **)in;
        goto LAB_00561684;
      }
    }
    else {
      iVar6 = asn1_template_ex_d2i(pval,in,len,it->templates,0,local_44);
      if (iVar6 < 1) goto switchD_005619f8_caseD_7;
    }
    goto LAB_005617a4;
  case '\x01':
  case '\x06':
switchD_00561550_caseD_1:
    local_4c = *in;
    ppAVar11 = (ASN1_VALUE **)0x0;
    iVar6 = asn1_check_tlen(&local_50,0,0,&local_56,&local_55,&local_4c,len,0x10,0,0,local_44);
    if (iVar6 == 0) {
      uVar12 = 0x3a;
      uVar4 = 0x176;
    }
    else {
      pAVar5 = (ASN1_VALUE *)0x0;
      if (iVar6 == -1) goto LAB_00561684;
      cVar1 = local_56;
      if ((pvVar13 != (void *)0x0) && ((*(uint *)((int)pvVar13 + 4) & 4) != 0)) {
        local_50 = len - ((int)local_4c - (int)*in);
        cVar1 = '\x01';
      }
      if (local_55 == '\0') {
        uVar12 = 0x95;
        uVar4 = 0x182;
      }
      else if ((*pval == (ASN1_VALUE *)0x0) && (iVar6 = ASN1_item_ex_new(pval,it), iVar6 == 0)) {
        uVar12 = 0x3a;
        uVar4 = 0x187;
      }
      else {
        local_60 = local_44;
        if ((local_68 != (code *)0x0) && (iVar6 = (*local_68)(4,pval,it,0), iVar6 == 0))
        goto LAB_00561628;
        iVar6 = it->tcount;
        iVar14 = 0;
        tt = it->templates;
        if (0 < iVar6) {
          do {
            if ((tt->flags & 0x300) != 0) {
              pAVar8 = asn1_do_adb(pval,tt,1);
              ppAVar11 = asn1_get_field_ptr(pval,pAVar8);
              ASN1_template_free(ppAVar11,pAVar8);
              iVar6 = it->tcount;
            }
            iVar14 = iVar14 + 1;
            tt = tt + 1;
          } while (iVar14 < iVar6);
          tt = it->templates;
          iVar14 = 0;
          if (0 < iVar6) {
            do {
              pAVar8 = asn1_do_adb(pval,tt,1);
              if (pAVar8 == (ASN1_TEMPLATE *)0x0) goto LAB_00561650;
              ppAVar11 = asn1_get_field_ptr(pval,pAVar8);
              puVar3 = local_4c;
              if (local_50 == 0) {
                if (local_56 == '\0') goto LAB_00561c3c;
                goto LAB_00561e04;
              }
              if (((1 < local_50) && (*local_4c == '\0')) && (local_4c[1] == '\0')) {
                if (local_56 == '\0') {
                  uVar12 = 0x9f;
                  uVar4 = 0x1a7;
                  local_4c = local_4c + 2;
                  goto LAB_0056163c;
                }
                local_50 = local_50 + -2;
                local_56 = '\0';
                local_4c = local_4c + 2;
                goto LAB_00561c28;
              }
              uVar7 = 0;
              if (it->tcount + -1 != iVar14) {
                uVar7 = pAVar8->flags & 1;
              }
              iVar6 = asn1_template_ex_d2i(ppAVar11,&local_4c,local_50,pAVar8,uVar7,local_60);
              if (iVar6 == 0) goto LAB_00561ce4;
              if (iVar6 == -1) {
                ASN1_template_free(ppAVar11,pAVar8);
              }
              else {
                local_50 = local_50 - ((int)local_4c - (int)puVar3);
              }
              iVar14 = iVar14 + 1;
              tt = tt + 1;
            } while (iVar14 < it->tcount);
          }
        }
        if (local_56 != '\0') {
          if (((local_50 < 2) || (*local_4c != '\0')) || (local_4c[1] != '\0')) {
LAB_00561e04:
            uVar12 = 0x89;
            uVar4 = 0x1ce;
            break;
          }
          local_4c = local_4c + 2;
        }
LAB_00561c28:
        if ((cVar1 != '\0') || (local_50 == 0)) {
LAB_00561c3c:
          if (iVar14 < it->tcount) {
LAB_00561c90:
            pAVar8 = asn1_do_adb(pval,tt,1);
            if (pAVar8 != (ASN1_TEMPLATE *)0x0) {
              if ((pAVar8->flags & 1) != 0) goto LAB_00561c54;
              (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x78,0x79,s_tasn_dec_c_0066a0bc,0x1e7);
LAB_00561ce4:
              ASN1_item_ex_free(pval,it);
LAB_00561cf8:
              in = (uchar **)&DAT_0066a0d0;
              (*(code *)PTR_ERR_add_error_data_006a813c)
                        (4,&DAT_0066a0d0,pAVar8->field_name,", Type=",it->sname);
              goto switchD_005619f8_caseD_7;
            }
            goto LAB_00561650;
          }
          ppAVar11 = (ASN1_VALUE **)*in;
          goto LAB_00561a70;
        }
        uVar12 = 0x94;
        uVar4 = 0x1d3;
      }
    }
    break;
  case '\x02':
    if ((local_68 == (code *)0x0) || (iVar6 = (*local_68)(4,pval,it,0), iVar6 != 0))
    goto LAB_00561954;
    goto LAB_00561628;
  case '\x03':
switchD_005619f8_caseD_3:
    iVar6 = (**(code **)((int)pvVar13 + 8))(pval,in,len);
    if (iVar6 != 0) {
      pAVar5 = *pval;
      ppAVar11 = (ASN1_VALUE **)in;
      goto LAB_00561684;
    }
    uVar12 = 0x3a;
    uVar4 = 0x12f;
    break;
  case '\x04':
LAB_005618f4:
    iVar6 = (*local_68)(pval,in,len,it,0xffffffff,0,0,local_44);
    if (iVar6 < 1) {
      pAVar5 = (ASN1_VALUE *)0x0;
      ppAVar11 = (ASN1_VALUE **)in;
      goto LAB_00561684;
    }
LAB_005617a4:
    pAVar5 = *pval;
    ppAVar11 = (ASN1_VALUE **)in;
    goto LAB_00561684;
  case '\x05':
switchD_005619f8_caseD_5:
    local_4c = *in;
    iVar6 = asn1_check_tlen_constprop_1(0,&local_48,&local_57,0,0,&local_4c,len,1,local_44);
    if (iVar6 == 0) {
      uVar12 = 0x3a;
      uVar4 = 0xdb;
    }
    else if (local_57 == '\0') {
      if ((local_48 < 0x1f) && ((*(uint *)(tag2bit + local_48 * 4) & it->utype) != 0)) {
        iVar6 = asn1_d2i_ex_primitive(pval,in,local_50,it,local_48,0,0,local_44);
        if (iVar6 < 1) {
          pAVar5 = (ASN1_VALUE *)0x0;
          ppAVar11 = (ASN1_VALUE **)in;
          goto LAB_00561684;
        }
        goto LAB_005617a4;
      }
      uVar12 = 0x8c;
      uVar4 = 0xec;
    }
    else {
      uVar12 = 0x8b;
      uVar4 = 0xe4;
    }
    break;
  default:
    goto switchD_005619f8_caseD_7;
  }
LAB_0056163c:
  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x78,uVar12,s_tasn_dec_c_0066a0bc,uVar4);
LAB_00561650:
  ASN1_item_ex_free(pval,it);
LAB_00561668:
  pcVar10 = s_Type__0066a0d8;
  (*(code *)PTR_ERR_add_error_data_006a813c)(2,s_Type__0066a0d8,it->sname);
  in = (uchar **)pcVar10;
switchD_005619f8_caseD_7:
  pAVar5 = (ASN1_VALUE *)0x0;
  ppAVar11 = (ASN1_VALUE **)in;
LAB_00561684:
  if (local_2c != *(int **)puVar2) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    return *(ASN1_VALUE **)(ppAVar11[1] + *local_2c);
  }
  return pAVar5;
LAB_00561c54:
  iVar14 = iVar14 + 1;
  ppAVar11 = asn1_get_field_ptr(pval,pAVar8);
  tt = tt + 1;
  ASN1_template_free(ppAVar11,pAVar8);
  if (it->tcount <= iVar14) goto LAB_00561a6c;
  goto LAB_00561c90;
LAB_00561a6c:
  ppAVar11 = (ASN1_VALUE **)*in;
LAB_00561a70:
  iVar6 = asn1_enc_save(pval,(uchar *)ppAVar11,(int)local_4c - (int)ppAVar11,it);
  if (iVar6 != 0) {
joined_r0x00561600:
    if ((local_68 == (code *)0x0) || (ppAVar11 = pval, iVar6 = (*local_68)(5,pval,it,0), iVar6 != 0)
       ) {
      *in = local_4c;
      pAVar5 = *pval;
      goto LAB_00561684;
    }
  }
LAB_00561628:
  uVar12 = 100;
  uVar4 = 0x1f7;
  goto LAB_0056163c;
}

