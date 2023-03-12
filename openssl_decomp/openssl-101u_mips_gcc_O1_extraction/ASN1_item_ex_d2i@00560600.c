
int ASN1_item_ex_d2i(ASN1_VALUE **pval,uchar **in,long len,ASN1_ITEM *it,int tag,int aclass,char opt
                    ,ASN1_TLC *ctx)

{
  byte bVar1;
  char cVar2;
  undefined *puVar3;
  ASN1_TEMPLATE *pAVar4;
  int in_zero;
  int iVar5;
  int iVar6;
  uint uVar7;
  ASN1_TEMPLATE *pAVar8;
  ASN1_VALUE **ppAVar9;
  char *pcVar10;
  ASN1_ITEM *pAVar11;
  ASN1_ITEM *pAVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  char *it_00;
  ASN1_ITEM *pval_00;
  void *pvVar15;
  ASN1_TEMPLATE *tt;
  ASN1_ITEM *unaff_s3;
  ASN1_VALUE **unaff_s4;
  ASN1_TEMPLATE *unaff_s5;
  ASN1_ITEM *unaff_s6;
  ASN1_ITEM *unaff_s7;
  code *pcStack_170;
  undefined *puStack_168;
  char cStack_15f;
  char cStack_15e;
  char cStack_15d;
  undefined auStack_15c [4];
  ASN1_ITEM *pAStack_158;
  ASN1_TEMPLATE *pAStack_154;
  uint uStack_150;
  undefined auStack_14c [24];
  int *piStack_134;
  ASN1_ITEM *pAStack_130;
  undefined *puStack_12c;
  uint uStack_128;
  ASN1_ITEM *pAStack_124;
  ASN1_VALUE **ppAStack_120;
  ASN1_TEMPLATE *pAStack_11c;
  ASN1_ITEM *pAStack_118;
  ASN1_ITEM *pAStack_114;
  ASN1_ITEM *pAStack_110;
  code *pcStack_10c;
  ASN1_ITEM *pAStack_e0;
  int iStack_dc;
  ASN1_TEMPLATE *pAStack_d8;
  ASN1_ITEM *pAStack_d4;
  ASN1_ITEM *pAStack_d0;
  undefined uStack_cc;
  char *pcStack_c8;
  ASN1_ITEM *pAStack_c4;
  int iStack_c0;
  ASN1_TEMPLATE *pAStack_bc;
  int iStack_b8;
  ASN1_ITEM *pAStack_b4;
  ASN1_VALUE **ppAStack_b0;
  void *pvStack_ac;
  undefined *puStack_a8;
  
  puStack_a8 = PTR___stack_chk_guard_006a9ae8;
  ppAVar9 = *(ASN1_VALUE ***)PTR___stack_chk_guard_006a9ae8;
  pvStack_ac = it->funcs;
  if (pval != (ASN1_VALUE **)0x0) {
    if (pvStack_ac == (void *)0x0) {
      bVar1 = it->itype;
    }
    else {
      bVar1 = it->itype;
    }
    unaff_s5 = (ASN1_TEMPLATE *)in;
    unaff_s7 = it;
    if (bVar1 < 7) {
                    /* WARNING: Could not recover jumptable at 0x005606b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar5 = (*(code *)(&PTR_LAB_0066a144)[bVar1])();
      return iVar5;
    }
  }
  if (ppAVar9 == *(ASN1_VALUE ***)PTR___stack_chk_guard_006a9ae8) {
    return 0;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_12c = PTR___stack_chk_guard_006a9ae8;
  uStack_cc = 0;
  pAStack_b4 = *(ASN1_ITEM **)PTR___stack_chk_guard_006a9ae8;
  uStack_128 = 0;
  pcVar10 = (char *)in;
  pAVar12 = (ASN1_ITEM *)len;
  it_00 = &it->itype;
  pAStack_130 = (ASN1_ITEM *)pval;
  pAStack_110 = (ASN1_ITEM *)(int)opt;
  ppAStack_b0 = pval;
  if (ppAVar9 != (ASN1_VALUE **)0x0) {
    unaff_s5 = *(ASN1_TEMPLATE **)it;
    pAStack_130 = (ASN1_ITEM *)*in;
    unaff_s3 = it;
    unaff_s6 = (ASN1_ITEM *)in;
    pAStack_e0 = pAStack_130;
    if (((uint)unaff_s5 & 0x10) == 0) {
      uStack_128 = asn1_template_noexp_d2i();
      pAVar12 = (ASN1_ITEM *)len;
    }
    else {
      iVar5 = it->utype;
      pAStack_d0 = pAStack_130;
      pcStack_c8 = (char *)ASN1_get_object((uchar **)&pAStack_d0,(long *)&pAStack_d4,&iStack_dc,
                                           (int *)&pAStack_d8,len);
      pAVar11 = pAStack_d0;
      iStack_b8 = (int)pAStack_d0 - (int)pAStack_130;
      pAStack_c4 = pAStack_d4;
      pAStack_bc = pAStack_d8;
      iStack_c0 = iStack_dc;
      uStack_cc = 1;
      unaff_s4 = ppAVar9;
      unaff_s7 = (ASN1_ITEM *)len;
      pAStack_110 = pAStack_d4;
      if ((((uint)pcStack_c8 & 0x81) == 0) && (len < (int)((int)pAStack_d4 + iStack_b8))) {
        uVar13 = 0x9b;
LAB_0056138c:
        (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x68,uVar13,s_tasn_dec_c_0066a0bc);
        uStack_cc = 0;
      }
      else {
        uStack_128 = (uint)pcStack_c8 & 0x80;
        if (uStack_128 != 0) {
          uVar13 = 0x66;
          goto LAB_0056138c;
        }
        if (iVar5 < 0) {
LAB_00561334:
          unaff_s5 = (ASN1_TEMPLATE *)(int)(char)pcStack_c8;
          pAStack_e0 = pAStack_d0;
          pAStack_130 = (ASN1_ITEM *)(len - iStack_b8);
          if (((uint)pcStack_c8 & 1) != 0) {
            pAStack_110 = pAStack_130;
          }
          if (((uint)unaff_s5 & 0x20) == 0) {
            pAVar12 = (ASN1_ITEM *)&DAT_00000078;
          }
          else {
            pcVar10 = (char *)&pAStack_e0;
            pAVar12 = pAStack_110;
            iVar5 = asn1_template_noexp_d2i(ppAVar9);
            if (iVar5 != 0) {
              unaff_s5 = (ASN1_TEMPLATE *)((uint)unaff_s5 & 1);
              pAStack_110 = (ASN1_ITEM *)((int)pAStack_110 - ((int)pAStack_e0 - (int)pAVar11));
              if (unaff_s5 == (ASN1_TEMPLATE *)0x0) {
                pAVar11 = pAStack_e0;
                if (pAStack_110 != (ASN1_ITEM *)0x0) {
                  pAVar12 = (ASN1_ITEM *)&DAT_00000077;
                  goto LAB_0056143c;
                }
              }
              else {
                pAStack_110 = (ASN1_ITEM *)(uint)((int)pAStack_110 < 2);
                if (((pAStack_110 != (ASN1_ITEM *)0x0) || (pAStack_e0->itype != '\0')) ||
                   (pAStack_e0->field_0x1 != '\0')) {
                  pAVar12 = (ASN1_ITEM *)&DAT_00000089;
LAB_0056143c:
                  it_00 = s_tasn_dec_c_0066a0bc;
                  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x84);
                  pcVar10 = &it->itype;
                  ASN1_template_free(ppAVar9,(ASN1_TEMPLATE *)it);
                  goto LAB_005611f0;
                }
                pAVar11 = (ASN1_ITEM *)&pAStack_e0->field_0x2;
              }
              *in = (uchar *)pAVar11;
              uStack_128 = 1;
              goto LAB_005611f0;
            }
            pAVar12 = (ASN1_ITEM *)&DAT_0000003a;
          }
          it_00 = s_tasn_dec_c_0066a0bc;
          pcVar10 = &DAT_00000084;
          (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
          goto LAB_005611f0;
        }
        if ((iVar5 == iStack_dc) &&
           (unaff_s5 = (ASN1_TEMPLATE *)((uint)unaff_s5 & 0xc0), unaff_s5 == pAStack_d8)) {
          uStack_cc = 0;
          goto LAB_00561334;
        }
        uStack_cc = 0;
        (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x68,0xa8,s_tasn_dec_c_0066a0bc);
      }
      pAStack_130 = (ASN1_ITEM *)0x670000;
      it_00 = s_tasn_dec_c_0066a0bc;
      pAVar12 = (ASN1_ITEM *)&DAT_0000003a;
      pcVar10 = &DAT_00000084;
      uStack_128 = 0;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
    }
  }
LAB_005611f0:
  if (pAStack_b4 == *(ASN1_ITEM **)puStack_12c) {
    return uStack_128;
  }
  pcStack_10c = ASN1_item_d2i;
  pAVar11 = pAStack_b4;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  pvVar15 = *(void **)((int)it_00 + 0x10);
  ppAStack_120 = unaff_s4;
  pAStack_124 = unaff_s3;
  pAStack_114 = unaff_s7;
  pAStack_118 = unaff_s6;
  pAStack_11c = unaff_s5;
  auStack_15c = (undefined  [4])0x0;
  auStack_14c[0] = 0;
  pAStack_158 = pAVar12;
  pAStack_154 = (ASN1_TEMPLATE *)0x0;
  pval_00 = (ASN1_ITEM *)auStack_15c;
  if (pAVar11 != (ASN1_ITEM *)0x0) {
    pval_00 = pAVar11;
  }
  piStack_134 = *(int **)PTR___stack_chk_guard_006a9ae8;
  if (pvVar15 == (void *)0x0) {
    switch(*it_00) {
    case '\0':
      goto switchD_005619f8_caseD_0;
    case '\x01':
    case '\x06':
      pcStack_170 = (code *)0x0;
      goto switchD_00561550_caseD_1;
    case '\x02':
      pcStack_170 = (code *)0x0;
LAB_00561954:
      if (*(int *)pval_00 == 0) {
        iVar5 = ASN1_item_ex_new((ASN1_VALUE **)pval_00,(ASN1_ITEM *)it_00);
        if (iVar5 == 0) {
          uVar14 = 0x3a;
          uVar13 = 0x13f;
          goto LAB_0056163c;
        }
        pAVar12 = *(ASN1_ITEM **)((int)it_00 + 0xc);
      }
      else {
        iVar5 = asn1_get_choice_selector((ASN1_VALUE **)pval_00,(ASN1_ITEM *)it_00);
        pAVar12 = *(ASN1_ITEM **)((int)it_00 + 0xc);
        if ((-1 < iVar5) && (iVar5 < (int)pAVar12)) {
          pAVar8 = *(ASN1_TEMPLATE **)((int)it_00 + 8);
          ppAVar9 = asn1_get_field_ptr((ASN1_VALUE **)pval_00,pAVar8 + iVar5);
          ASN1_template_free(ppAVar9,pAVar8 + iVar5);
          asn1_set_choice_selector((ASN1_VALUE **)pval_00,-1,(ASN1_ITEM *)it_00);
          pAVar12 = *(ASN1_ITEM **)((int)it_00 + 0xc);
        }
      }
      pAStack_154 = *(ASN1_TEMPLATE **)pcVar10;
      pAVar11 = (ASN1_ITEM *)0x0;
      pAVar8 = *(ASN1_TEMPLATE **)((int)it_00 + 8);
      if ((int)pAVar12 < 1) {
LAB_005615e0:
        if (pAVar11 == pAVar12) {
LAB_00561a34:
          uVar14 = 0x8f;
          uVar13 = 0x15e;
          goto LAB_0056163c;
        }
      }
      else {
        do {
          ppAVar9 = asn1_get_field_ptr((ASN1_VALUE **)pval_00,pAVar8);
          iVar5 = asn1_template_ex_d2i(ppAVar9,auStack_15c + 8,pAStack_158,pAVar8,1,auStack_14c);
          if (iVar5 != -1) {
            if (iVar5 < 1) {
              (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x78,0x3a,s_tasn_dec_c_0066a0bc,0x152);
              ASN1_item_ex_free((ASN1_VALUE **)pval_00,(ASN1_ITEM *)it_00);
              if (pAVar8 == (ASN1_TEMPLATE *)0x0) goto LAB_00561668;
              goto LAB_00561cf8;
            }
            pAVar12 = *(ASN1_ITEM **)((int)it_00 + 0xc);
            goto LAB_005615e0;
          }
          pAVar11 = (ASN1_ITEM *)&pAVar11->field_0x1;
          pAVar8 = pAVar8 + 1;
        } while ((int)pAVar11 < (int)*(undefined **)((int)it_00 + 0xc));
        if (pAVar11 == (ASN1_ITEM *)*(undefined **)((int)it_00 + 0xc)) goto LAB_00561a34;
      }
      asn1_set_choice_selector((ASN1_VALUE **)pval_00,(int)pAVar11,(ASN1_ITEM *)it_00);
      goto joined_r0x00561600;
    case '\x03':
      goto switchD_005619f8_caseD_3;
    case '\x04':
      pcStack_170 = *(code **)(in_zero + 0x10);
      goto LAB_005618f4;
    case '\x05':
      goto switchD_005619f8_caseD_5;
    }
    goto switchD_005619f8_caseD_7;
  }
  pcStack_170 = *(code **)((int)pvVar15 + 0x10);
  switch(*it_00) {
  case '\0':
switchD_005619f8_caseD_0:
    if (*(ASN1_TEMPLATE **)((int)it_00 + 8) == (ASN1_TEMPLATE *)0x0) {
      iVar5 = asn1_d2i_ex_primitive(pval_00,pcVar10,pAVar12,it_00,0xffffffff,0,0,auStack_14c);
      if (iVar5 < 1) {
        iVar5 = 0;
        pAVar11 = (ASN1_ITEM *)pcVar10;
        goto LAB_00561684;
      }
    }
    else {
      iVar5 = asn1_template_ex_d2i
                        (pval_00,pcVar10,pAVar12,*(ASN1_TEMPLATE **)((int)it_00 + 8),0,auStack_14c);
      if (iVar5 < 1) goto switchD_005619f8_caseD_7;
    }
    goto LAB_005617a4;
  case '\x01':
  case '\x06':
switchD_00561550_caseD_1:
    pAStack_154 = *(ASN1_TEMPLATE **)pcVar10;
    pAVar11 = (ASN1_ITEM *)0x0;
    iVar6 = asn1_check_tlen(auStack_15c + 4,0,0,&cStack_15e,&cStack_15d,auStack_15c + 8,pAVar12,0x10
                            ,0,0,auStack_14c);
    if (iVar6 == 0) {
      uVar14 = 0x3a;
      uVar13 = 0x176;
    }
    else {
      iVar5 = 0;
      if (iVar6 == -1) goto LAB_00561684;
      cVar2 = cStack_15e;
      if ((pvVar15 != (void *)0x0) && ((*(uint *)((int)pvVar15 + 4) & 4) != 0)) {
        pAStack_158 = (ASN1_ITEM *)((int)pAVar12 - ((int)pAStack_154 - (int)*(uchar **)pcVar10));
        cVar2 = '\x01';
      }
      if (cStack_15d == '\0') {
        uVar14 = 0x95;
        uVar13 = 0x182;
      }
      else if ((*(int *)pval_00 == 0) &&
              (iVar5 = ASN1_item_ex_new((ASN1_VALUE **)pval_00,(ASN1_ITEM *)it_00), iVar5 == 0)) {
        uVar14 = 0x3a;
        uVar13 = 0x187;
      }
      else {
        puStack_168 = auStack_14c;
        if ((pcStack_170 != (code *)0x0) && (iVar5 = (*pcStack_170)(4,pval_00,it_00,0), iVar5 == 0))
        goto LAB_00561628;
        iVar5 = *(long *)((int)it_00 + 0xc);
        iVar6 = 0;
        tt = *(ASN1_TEMPLATE **)((int)it_00 + 8);
        if (0 < iVar5) {
          do {
            if ((tt->flags & 0x300) != 0) {
              pAVar8 = asn1_do_adb((ASN1_VALUE **)pval_00,tt,1);
              ppAVar9 = asn1_get_field_ptr((ASN1_VALUE **)pval_00,pAVar8);
              ASN1_template_free(ppAVar9,pAVar8);
              iVar5 = *(long *)((int)it_00 + 0xc);
            }
            iVar6 = iVar6 + 1;
            tt = tt + 1;
          } while (iVar6 < iVar5);
          tt = *(ASN1_TEMPLATE **)((int)it_00 + 8);
          iVar6 = 0;
          if (0 < iVar5) {
            do {
              pAVar8 = asn1_do_adb((ASN1_VALUE **)pval_00,tt,1);
              if (pAVar8 == (ASN1_TEMPLATE *)0x0) goto LAB_00561650;
              ppAVar9 = asn1_get_field_ptr((ASN1_VALUE **)pval_00,pAVar8);
              pAVar4 = pAStack_154;
              if (pAStack_158 == (ASN1_ITEM *)0x0) {
                if (cStack_15e != '\0') goto LAB_00561e04;
                goto LAB_00561c3c;
              }
              if (((1 < (int)pAStack_158) && (*(uchar *)&pAStack_154->flags == '\0')) &&
                 (*(uchar *)((int)&pAStack_154->flags + 1) == '\0')) {
                pAStack_154 = (ASN1_TEMPLATE *)((int)&pAStack_154->flags + 2);
                if (cStack_15e != '\0') {
                  cStack_15e = '\0';
                  pAStack_158 = (ASN1_ITEM *)((int)&pAStack_158[-1].sname + 2);
                  goto LAB_00561c28;
                }
                uVar14 = 0x9f;
                uVar13 = 0x1a7;
                goto LAB_0056163c;
              }
              uVar7 = 0;
              if (*(long *)((int)it_00 + 0xc) + -1 != iVar6) {
                uVar7 = pAVar8->flags & 1;
              }
              iVar5 = asn1_template_ex_d2i
                                (ppAVar9,auStack_15c + 8,pAStack_158,pAVar8,uVar7,puStack_168);
              if (iVar5 == 0) goto LAB_00561ce4;
              if (iVar5 == -1) {
                ASN1_template_free(ppAVar9,pAVar8);
              }
              else {
                pAStack_158 = (ASN1_ITEM *)((int)pAStack_158 - ((int)pAStack_154 - (int)pAVar4));
              }
              iVar6 = iVar6 + 1;
              tt = tt + 1;
            } while (iVar6 < *(long *)((int)it_00 + 0xc));
          }
        }
        if (cStack_15e != '\0') {
          if ((((int)pAStack_158 < 2) || (*(uchar *)&pAStack_154->flags != '\0')) ||
             (*(uchar *)((int)&pAStack_154->flags + 1) != '\0')) {
LAB_00561e04:
            uVar14 = 0x89;
            uVar13 = 0x1ce;
            break;
          }
          pAStack_154 = (ASN1_TEMPLATE *)((int)&pAStack_154->flags + 2);
        }
LAB_00561c28:
        if ((cVar2 != '\0') || (pAStack_158 == (ASN1_ITEM *)0x0)) {
LAB_00561c3c:
          if (iVar6 < *(long *)((int)it_00 + 0xc)) {
LAB_00561c90:
            pAVar8 = asn1_do_adb((ASN1_VALUE **)pval_00,tt,1);
            if (pAVar8 != (ASN1_TEMPLATE *)0x0) {
              if ((pAVar8->flags & 1) != 0) goto LAB_00561c54;
              (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x78,0x79,s_tasn_dec_c_0066a0bc,0x1e7);
LAB_00561ce4:
              ASN1_item_ex_free((ASN1_VALUE **)pval_00,(ASN1_ITEM *)it_00);
LAB_00561cf8:
              pcVar10 = (char *)&DAT_0066a0d0;
              (*(code *)PTR_ERR_add_error_data_006a813c)
                        (4,&DAT_0066a0d0,pAVar8->field_name,", Type=",*(char **)((int)it_00 + 0x18))
              ;
              goto switchD_005619f8_caseD_7;
            }
            goto LAB_00561650;
          }
          pAVar11 = *(ASN1_ITEM **)pcVar10;
          goto LAB_00561a70;
        }
        uVar14 = 0x94;
        uVar13 = 0x1d3;
      }
    }
    break;
  case '\x02':
    if ((pcStack_170 == (code *)0x0) || (iVar5 = (*pcStack_170)(4,pval_00,it_00,0), iVar5 != 0))
    goto LAB_00561954;
    goto LAB_00561628;
  case '\x03':
switchD_005619f8_caseD_3:
    iVar5 = (**(code **)((int)pvVar15 + 8))(pval_00,pcVar10,pAVar12);
    if (iVar5 != 0) {
      iVar5 = *(int *)pval_00;
      pAVar11 = (ASN1_ITEM *)pcVar10;
      goto LAB_00561684;
    }
    uVar14 = 0x3a;
    uVar13 = 0x12f;
    break;
  case '\x04':
LAB_005618f4:
    iVar5 = (*pcStack_170)(pval_00,pcVar10,pAVar12,it_00,0xffffffff,0,0,auStack_14c);
    if (iVar5 < 1) {
      iVar5 = 0;
      pAVar11 = (ASN1_ITEM *)pcVar10;
      goto LAB_00561684;
    }
LAB_005617a4:
    iVar5 = *(int *)pval_00;
    pAVar11 = (ASN1_ITEM *)pcVar10;
    goto LAB_00561684;
  case '\x05':
switchD_005619f8_caseD_5:
    pAStack_154 = *(ASN1_TEMPLATE **)pcVar10;
    iVar5 = asn1_check_tlen_constprop_1
                      (0,auStack_15c + 0xc,&cStack_15f,0,0,auStack_15c + 8,pAVar12,1,auStack_14c);
    if (iVar5 == 0) {
      uVar14 = 0x3a;
      uVar13 = 0xdb;
    }
    else if (cStack_15f == '\0') {
      if ((uStack_150 < 0x1f) &&
         ((*(uint *)(tag2bit + uStack_150 * 4) & *(long *)((int)it_00 + 4)) != 0)) {
        iVar5 = asn1_d2i_ex_primitive(pval_00,pcVar10,pAStack_158,it_00,uStack_150,0,0,auStack_14c);
        if (iVar5 < 1) {
          iVar5 = 0;
          pAVar11 = (ASN1_ITEM *)pcVar10;
          goto LAB_00561684;
        }
        goto LAB_005617a4;
      }
      uVar14 = 0x8c;
      uVar13 = 0xec;
    }
    else {
      uVar14 = 0x8b;
      uVar13 = 0xe4;
    }
    break;
  default:
    goto switchD_005619f8_caseD_7;
  }
LAB_0056163c:
  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x78,uVar14,s_tasn_dec_c_0066a0bc,uVar13);
LAB_00561650:
  ASN1_item_ex_free((ASN1_VALUE **)pval_00,(ASN1_ITEM *)it_00);
LAB_00561668:
  pcVar10 = s_Type__0066a0d8;
  (*(code *)PTR_ERR_add_error_data_006a813c)(2,s_Type__0066a0d8,*(char **)((int)it_00 + 0x18));
switchD_005619f8_caseD_7:
  iVar5 = 0;
  pAVar11 = (ASN1_ITEM *)pcVar10;
LAB_00561684:
  if (piStack_134 == *(int **)puVar3) {
    return iVar5;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  return *(int *)(pAVar11->utype + *piStack_134);
LAB_00561c54:
  iVar6 = iVar6 + 1;
  ppAVar9 = asn1_get_field_ptr((ASN1_VALUE **)pval_00,pAVar8);
  tt = tt + 1;
  ASN1_template_free(ppAVar9,pAVar8);
  if (*(long *)((int)it_00 + 0xc) <= iVar6) goto LAB_00561a6c;
  goto LAB_00561c90;
LAB_00561a6c:
  pAVar11 = *(ASN1_ITEM **)pcVar10;
LAB_00561a70:
  iVar5 = asn1_enc_save((ASN1_VALUE **)pval_00,(uchar *)pAVar11,(int)pAStack_154 - (int)pAVar11,
                        (ASN1_ITEM *)it_00);
  if (iVar5 != 0) {
joined_r0x00561600:
    if ((pcStack_170 == (code *)0x0) ||
       (pAVar11 = pval_00, iVar5 = (*pcStack_170)(5,pval_00,it_00,0), iVar5 != 0)) {
      *(ASN1_TEMPLATE **)pcVar10 = pAStack_154;
      iVar5 = *(int *)pval_00;
      goto LAB_00561684;
    }
  }
LAB_00561628:
  uVar14 = 100;
  uVar13 = 0x1f7;
  goto LAB_0056163c;
}

