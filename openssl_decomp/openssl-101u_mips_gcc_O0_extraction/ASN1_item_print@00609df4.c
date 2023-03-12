
int ASN1_item_print(BIO *out,ASN1_VALUE *ifld,int indent,ASN1_ITEM *it,ASN1_PCTX *pctx)

{
  undefined *puVar1;
  byte bVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  ASN1_TEMPLATE *pAVar8;
  undefined4 uVar9;
  uint uVar10;
  ASN1_ITEM *pAVar11;
  char *pcVar12;
  ASN1_ITEM *pAVar13;
  byte *pbVar14;
  ASN1_ITEM *pAVar15;
  int iVar16;
  uint uVar17;
  undefined4 uVar18;
  char *pcVar19;
  char *pcVar20;
  byte *pbVar21;
  byte *pbVar22;
  uint *puVar23;
  uint *puVar24;
  undefined **ppuVar25;
  ASN1_TEMPLATE *pAVar26;
  int iVar27;
  byte bVar28;
  code *pcVar29;
  undefined *unaff_s8;
  ASN1_ITEM *pAStack_ec;
  undefined auStack_e8 [4];
  int iStack_e4;
  ASN1_ITEM *pAStack_e0;
  ASN1_ITEM *pAStack_dc;
  BIO *pBStack_d8;
  undefined *puStack_d4;
  char *pcStack_d0;
  undefined **ppuStack_cc;
  ASN1_ITEM *pAStack_c8;
  ASN1_ITEM *pAStack_c4;
  undefined *puStack_c0;
  undefined4 uStack_bc;
  ASN1_ITEM *local_a8;
  undefined *local_a0;
  ASN1_ITEM *local_94;
  ASN1_ITEM *local_90;
  undefined local_8c [8];
  ASN1_TEMPLATE *local_84;
  ASN1_ITEM *local_80;
  ASN1_ITEM aAStack_7c [2];
  int local_2c;
  
  puStack_d4 = PTR___stack_chk_guard_006a9ae8;
  local_a0 = &_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (pctx == (ASN1_PCTX *)0x0) {
    pctx = (ASN1_PCTX *)default_pctx;
  }
  pcVar12 = (char *)indent;
  pcVar19 = &it->itype;
  local_8c._0_4_ = (ASN1_ITEM *)ifld;
  if (((uint)*(uint **)pctx & 0x100) != 0) {
    pAStack_c8 = (ASN1_ITEM *)it->funcs;
    pAStack_c4 = (ASN1_ITEM *)0x0;
    if (pAStack_c8 == (ASN1_ITEM *)0x0) goto LAB_00609ecc;
LAB_00609e70:
    ppuStack_cc = (undefined **)pAStack_c8->funcs;
    if (ppuStack_cc != (undefined **)0x0) {
      local_8c._4_4_ = out;
      local_84 = (ASN1_TEMPLATE *)indent;
      local_80 = (ASN1_ITEM *)pctx;
    }
    if (ifld != (ASN1_VALUE *)0x0) goto LAB_00609e94;
LAB_00609edc:
    pAVar15 = (ASN1_ITEM *)0x0;
    pcVar12 = (char *)ifld;
    if (((uint)*(uint **)pctx & 1) != 0) {
      pcVar12 = (char *)indent;
      pcVar19 = &pAStack_c4->itype;
      local_a8 = (ASN1_ITEM *)pctx;
      iVar6 = asn1_print_fsname_isra_4(out,indent,0,pAStack_c4);
      if (iVar6 == 0) goto LAB_0060a0d4;
      pcVar12 = "<ABSENT>\n";
      iVar6 = (**(code **)(local_a0 + -0x7e88))(out);
      uVar4 = (uint)(0 < iVar6);
      goto LAB_00609f70;
    }
    goto LAB_0060a224;
  }
  pAStack_c8 = (ASN1_ITEM *)it->funcs;
  pAStack_c4 = (ASN1_ITEM *)it->sname;
  if (pAStack_c8 != (ASN1_ITEM *)0x0) goto LAB_00609e70;
LAB_00609ecc:
  ppuStack_cc = (undefined **)0x0;
  if (ifld == (ASN1_VALUE *)0x0) goto LAB_00609edc;
LAB_00609e94:
  pAVar15 = (ASN1_ITEM *)(int)it->itype;
  switch((uint)pAVar15 & 0xff) {
  case 0:
    pcVar19 = (char *)it->templates;
    pcVar12 = local_8c;
    if ((ASN1_ITEM *)pcVar19 == (ASN1_ITEM *)0x0) goto switchD_00609eb8_caseD_5;
    pAVar15 = (ASN1_ITEM *)indent;
    local_a8 = (ASN1_ITEM *)pctx;
    iVar6 = asn1_template_print_ctx(out);
    uVar4 = (uint)(iVar6 != 0);
    break;
  case 1:
  case 6:
    pAVar15 = (ASN1_ITEM *)0x0;
    pcVar19 = &pAStack_c4->itype;
    local_a8 = (ASN1_ITEM *)pctx;
    iVar6 = asn1_print_fsname_isra_4(out,indent,0,pAStack_c4);
    if (iVar6 == 0) goto LAB_0060a0d4;
    if (pAStack_c4 != (ASN1_ITEM *)0x0) {
      if (((uint)*(uint **)pctx & 2) == 0) {
        pcVar12 = "\n";
        iVar6 = (**(code **)(local_a0 + -0x7e88))(out);
        if (iVar6 < 1) {
          uVar4 = 0;
          break;
        }
      }
      else {
        pcVar12 = &DAT_0067985c;
        iVar6 = (**(code **)(local_a0 + -0x7e88))();
        if (iVar6 < 1) goto LAB_0060a0d4;
      }
    }
    pcVar19 = local_8c + 4;
    if (ppuStack_cc != (undefined **)0x0) {
      pcVar12 = local_8c;
      pAVar15 = it;
      iVar6 = (*(code *)ppuStack_cc)(8,pcVar12,it,pcVar19);
      if (iVar6 == 0) goto LAB_0060a0d4;
      uVar4 = 1;
      if (iVar6 == 2) break;
    }
    pAStack_c8 = (ASN1_ITEM *)it->templates;
    if (0 < it->tcount) {
      local_90 = (ASN1_ITEM *)(indent + 2);
      pAStack_c4 = (ASN1_ITEM *)0x0;
      unaff_s8 = local_8c;
      do {
        pAVar15 = (ASN1_ITEM *)0x1;
        pcVar12 = &pAStack_c8->itype;
        pAVar13 = (ASN1_ITEM *)(**(code **)(local_a0 + -0x605c))(unaff_s8);
        if (pAVar13 == (ASN1_ITEM *)0x0) goto LAB_0060a0d4;
        local_94 = pAVar13;
        pcVar12 = (char *)(**(code **)(local_a0 + -0x6070))(unaff_s8,pAVar13);
        pAVar15 = local_90;
        pcVar19 = &local_94->itype;
        local_a8 = (ASN1_ITEM *)pctx;
        iVar6 = asn1_template_print_ctx(out,pcVar12,local_90,local_94);
        if (iVar6 == 0) goto LAB_0060a0d4;
        pAStack_c4 = (ASN1_ITEM *)&pAStack_c4->field_0x1;
        pAStack_c8 = (ASN1_ITEM *)&pAStack_c8->size;
      } while ((int)pAStack_c4 < it->tcount);
    }
    if (((uint)*(uint **)pctx & 2) != 0) {
      pcVar19 = "";
      pcVar12 = "%*s}\n";
      pAVar15 = (ASN1_ITEM *)indent;
      iVar6 = (**(code **)(local_a0 + -0x7fa8))(out,"%*s}\n",indent,"");
      if (iVar6 < 0) {
        uVar4 = 0;
        break;
      }
    }
    pcVar19 = local_8c + 4;
    if (ppuStack_cc == (undefined **)0x0) goto LAB_0060a224;
    pcVar12 = local_8c;
    pAVar15 = it;
    iVar6 = (*(code *)ppuStack_cc)(9,pcVar12,it,pcVar19);
    uVar4 = (uint)(iVar6 != 0);
    break;
  case 2:
    ppuStack_cc = (undefined **)local_8c;
    pAVar15 = (ASN1_ITEM *)(*(code *)PTR_asn1_get_choice_selector_006a8d7c)(ppuStack_cc,it);
    if (((int)pAVar15 < 0) || (pcVar19 = (char *)((int)pAVar15 * 4), it->tcount <= (int)pAVar15)) {
      pcVar12 = "ERROR: selector [%d] invalid\n";
      iVar6 = (**(code **)(local_a0 + -0x7fa8))(out);
      uVar4 = (uint)(0 < iVar6);
    }
    else {
      it = (ASN1_ITEM *)(it->templates + (int)pAVar15);
      pcVar12 = (char *)(**(code **)(local_a0 + -0x6070))(ppuStack_cc,it);
      pAVar15 = (ASN1_ITEM *)indent;
      pcVar19 = (char *)it;
      local_a8 = (ASN1_ITEM *)pctx;
      iVar6 = asn1_template_print_ctx(out,pcVar12,indent,it);
      uVar4 = (uint)(iVar6 != 0);
    }
    break;
  default:
    pcVar12 = "Unprocessed type %d\n";
    (*(code *)PTR_BIO_printf_006a6e38)(out);
    uVar4 = 0;
    break;
  case 4:
    pAVar15 = (ASN1_ITEM *)0x0;
    pcVar19 = &pAStack_c4->itype;
    local_a8 = (ASN1_ITEM *)pctx;
    iVar6 = asn1_print_fsname_isra_4(out,indent,0,pAStack_c4);
    if (iVar6 == 0) goto LAB_0060a0d4;
    if (it->funcs != (void *)0x0) {
      pcVar29 = *(code **)((int)it->funcs + 0x18);
      pcVar19 = "-check_ss_sig";
      if (pcVar29 != (code *)0x0) {
        pcVar12 = local_8c;
        pcVar19 = "";
        pAVar15 = (ASN1_ITEM *)indent;
        local_a8 = (ASN1_ITEM *)pctx;
        iVar6 = (*pcVar29)(out,pcVar12,indent,"");
        if (iVar6 != 0) {
          pcVar12 = "-check_ss_sig";
          if (iVar6 != 2) goto LAB_0060a224;
          pcVar12 = "\n";
          iVar6 = (**(code **)(local_a0 + -0x7e88))(out);
          uVar4 = (uint)(0 < iVar6);
          break;
        }
        goto LAB_0060a0d4;
      }
    }
    pcVar12 = (char *)0x680000;
    if (pAStack_c4 == (ASN1_ITEM *)0x0) goto LAB_0060a224;
    pcVar12 = ":EXTERNAL TYPE %s\n";
    pAVar15 = pAStack_c4;
    iVar6 = (**(code **)(local_a0 + -0x7fa8))(out);
    uVar4 = (uint)(0 < iVar6);
    break;
  case 5:
switchD_00609eb8_caseD_5:
    pAVar15 = (ASN1_ITEM *)0x0;
    pcVar12 = (char *)indent;
    pcVar19 = &pAStack_c4->itype;
    local_a8 = (ASN1_ITEM *)pctx;
    iVar6 = asn1_print_fsname_isra_4(out,indent,0,pAStack_c4);
    pAVar13 = local_8c._0_4_;
    if (iVar6 == 0) goto LAB_0060a0d4;
    if (pAStack_c8 != (ASN1_ITEM *)0x0) {
      pcVar12 = local_8c;
      if (*(uint **)(pAStack_c8 + 1) != (uint *)0x0) {
        pAVar15 = it;
        pcVar19 = (char *)indent;
        local_a8 = (ASN1_ITEM *)pctx;
        iVar6 = (*(code *)*(uint **)(pAStack_c8 + 1))(out,pcVar12,it,indent);
        uVar4 = (uint)(iVar6 != 0);
        break;
      }
    }
    if (it->itype == '\x05') {
      ppuStack_cc = (undefined **)((local_8c._0_4_)->utype & 0xfffffeff);
    }
    else {
      ppuStack_cc = (undefined **)it->utype;
    }
    pAStack_c8 = (ASN1_ITEM *)&(local_8c._0_4_)->utype;
    if (ppuStack_cc == (undefined **)0xfffffffc) {
      ppuStack_cc = *(undefined ***)local_8c._0_4_;
      pAStack_c4 = (ASN1_ITEM *)(local_8c._0_4_)->utype;
      if (((uint)*(uint **)pctx & 0x10) == 0) {
        pcVar12 = (char *)(**(code **)(local_a0 + -0x792c))(ppuStack_cc);
        goto LAB_0060a350;
      }
LAB_0060a260:
      ppuVar25 = ppuStack_cc;
      if (ppuStack_cc != (undefined **)&DAT_00000005) goto LAB_0060a390;
LAB_0060a26c:
      pcVar12 = "NULL\n";
      iVar6 = (**(code **)(local_a0 + -0x7e88))(out);
      if (iVar6 < 1) goto LAB_0060a0d4;
      uVar4 = 1;
      break;
    }
    if (((uint)*(uint **)pctx & 8) == 0) {
      pAStack_c8 = (ASN1_ITEM *)local_8c;
      pAStack_c4 = local_8c._0_4_;
      goto LAB_0060a260;
    }
    pAStack_c8 = (ASN1_ITEM *)local_8c;
    pcVar12 = (char *)(**(code **)(local_a0 + -0x792c))(ppuStack_cc);
    pAStack_c4 = pAVar13;
LAB_0060a350:
    if (ppuStack_cc == (undefined **)&DAT_00000005) goto LAB_0060a26c;
    ppuVar25 = ppuStack_cc;
    if ((ASN1_ITEM *)pcVar12 != (ASN1_ITEM *)0x0) {
      iVar6 = (**(code **)(local_a0 + -0x7e88))(out);
      if (0 < iVar6) {
        pcVar12 = ":";
        iVar6 = (**(code **)(local_a0 + -0x7e88))(out);
        if (0 < iVar6) goto LAB_0060a390;
      }
      goto LAB_0060a0d4;
    }
LAB_0060a390:
    ppuStack_cc = &switchD_0060a3b0::switchdataD_00679994 + (int)((int)ppuVar25 + 3);
    pcVar12 = &pAStack_c4->itype;
    switch(ppuVar25) {
    case (undefined **)0x1:
      puVar23 = *(uint **)pAStack_c8;
      if (puVar23 == (uint *)0xffffffff) {
        puVar23 = (uint *)it->size;
      }
      if (puVar23 == (uint *)0xffffffff) {
        pcVar12 = "BOOL ABSENT";
      }
      else if (puVar23 == (uint *)0x0) {
        pcVar12 = "FALSE";
      }
      else {
        pcVar12 = &DAT_0066d6c8;
      }
      iVar6 = (**(code **)(local_a0 + -0x7e88))(out);
      if (iVar6 < 1) {
        uVar4 = 0;
        goto LAB_00609f70;
      }
      goto LAB_0060a3d4;
    case (undefined **)0x2:
    case (undefined **)0xa:
      pctx = (ASN1_PCTX *)(**(code **)(local_a0 + -0x5d7c))(0);
      if ((ASN1_ITEM *)pctx != (ASN1_ITEM *)0x0) {
        pcVar12 = (char *)pctx;
        iVar6 = (**(code **)(local_a0 + -0x7e88))(out);
        local_94 = (ASN1_ITEM *)(uint)(0 < iVar6);
        (**(code **)(local_a0 + -0x7f58))(pctx);
        pAVar13 = local_94;
        break;
      }
      goto LAB_0060a0d4;
    case (undefined **)0x3:
    case (undefined **)0x4:
      if (pAStack_c4->utype == 3) {
        pcVar12 = " (%ld unused bits)\n";
        pAVar15 = (ASN1_ITEM *)(pAStack_c4->tcount & 7);
        iVar6 = (**(code **)(local_a0 + -0x7fa8))(out);
        if (iVar6 < 1) {
          uVar4 = 0;
          goto LAB_00609f70;
        }
      }
      else {
        pcVar12 = "\n";
        iVar6 = (**(code **)(local_a0 + -0x7e88))(out);
        if (iVar6 < 1) goto LAB_0060a0d4;
      }
      pAVar15 = *(ASN1_ITEM **)pAStack_c4;
      if (0 < (int)pAVar15) {
        pcVar19 = (char *)(indent + 2);
        pcVar12 = (char *)pAStack_c4->templates;
        iVar6 = (**(code **)(local_a0 + -0x7aac))(out,pcVar12,pAVar15,pcVar19);
        if (iVar6 < 1) goto LAB_0060a0d4;
      }
LAB_0060a224:
      uVar4 = 1;
      goto LAB_00609f70;
    case (undefined **)0x6:
      puVar23 = *(uint **)pAStack_c8;
      uVar9 = (**(code **)(local_a0 + -0x7cb4))(puVar23);
      it = (ASN1_ITEM *)(**(code **)(local_a0 + -0x7cc4))(uVar9);
      if (it == (ASN1_ITEM *)0x0) {
        it = (ASN1_ITEM *)0x638d8c;
      }
      pctx = (ASN1_PCTX *)aAStack_7c;
      (**(code **)(local_a0 + -0x6144))(pctx,0x50,puVar23,1);
      pcVar12 = "%s (%s)";
      pAVar15 = it;
      pcVar19 = (char *)pctx;
      iVar6 = (**(code **)(local_a0 + -0x7fa8))(out,"%s (%s)",it,pctx);
      pAVar13 = (ASN1_ITEM *)(uint)(0 < iVar6);
      break;
    case (undefined **)0x17:
      pAVar13 = (ASN1_ITEM *)(**(code **)(local_a0 + -0x55fc))(out);
      break;
    case (undefined **)0x18:
      pAVar13 = (ASN1_ITEM *)(**(code **)(local_a0 + -0x6fc0))(out);
      break;
    case (undefined **)0xfffffffd:
    case (undefined **)0x10:
    case (undefined **)0x11:
      pcVar12 = "\n";
      iVar6 = (**(code **)(local_a0 + -0x7e88))(out);
      if (0 < iVar6) {
        pAVar15 = *(ASN1_ITEM **)pAStack_c4;
        pcVar12 = (char *)pAStack_c4->templates;
        local_a8 = (ASN1_ITEM *)0x0;
        pcVar19 = (char *)indent;
        iVar6 = (**(code **)(local_a0 + -0x7928))(out,pcVar12,pAVar15,indent);
        if (0 < iVar6) {
          uVar4 = 1;
          goto LAB_00609f70;
        }
      }
      goto LAB_0060a0d4;
    default:
      pAVar15 = *(ASN1_ITEM **)((int)pctx + 0x10);
      pAVar13 = (ASN1_ITEM *)(**(code **)(local_a0 + -0x599c))(out);
    }
    uVar4 = 0;
    if (pAVar13 != (ASN1_ITEM *)0x0) {
LAB_0060a3d4:
      pcVar12 = "\n";
      iVar6 = (**(code **)(local_a0 + -0x7e88))(out);
      if (iVar6 < 1) {
LAB_0060a0d4:
        uVar4 = 0;
      }
      else {
        uVar4 = 1;
      }
    }
  }
LAB_00609f70:
  if (local_2c == *(int *)puStack_d4) {
    return uVar4;
  }
  uStack_bc = 0x60a658;
  iVar6 = local_2c;
  (**(code **)(local_a0 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStack_e4 = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar5 = 0;
  pAVar13 = (ASN1_ITEM *)pcVar12;
  pAStack_e0 = (ASN1_ITEM *)pctx;
  pAStack_dc = it;
  pBStack_d8 = out;
  pcStack_d0 = (char *)indent;
  puStack_c0 = unaff_s8;
  if ((ASN1_ITEM *)pcVar12 != (ASN1_ITEM *)0x0) {
    if (*(uint **)pcVar12 == (uint *)0x0) {
      pAVar15 = (ASN1_ITEM *)0x1;
      pAVar13 = (ASN1_ITEM *)0x63500c;
      iVar5 = (*(code *)PTR_BIO_write_006a6e14)();
      if (iVar5 == 1) goto LAB_0060a7b4;
    }
    else {
      if ((int)*(uint **)pcVar12 < 1) {
        iVar5 = 0;
        goto LAB_0060a7b4;
      }
      iVar27 = 0;
      pAStack_ec = (ASN1_ITEM *)&DAT_0066a370;
      iVar5 = 0;
      while( true ) {
        iVar16 = iVar5;
        pAVar15 = (ASN1_ITEM *)&SUB_00000002;
        pbVar22 = (byte *)((int)&(*(ASN1_TEMPLATE **)((int)pcVar12 + 8))->flags + iVar27);
        auStack_e8[0] = "0123456789ABCDEF"[*pbVar22 >> 4];
        auStack_e8[1] = "0123456789ABCDEF"[*pbVar22 & 0xf];
        pAVar13 = (ASN1_ITEM *)auStack_e8;
        iVar5 = (*(code *)PTR_BIO_write_006a6e14)(iVar6);
        if (iVar5 != 2) break;
        iVar27 = iVar27 + 1;
        iVar5 = iVar16 + 2;
        if ((int)*(uint **)pcVar12 <= iVar27) goto LAB_0060a7b4;
        if ((iVar27 != 0) && (iVar27 == (iVar27 / 0x23) * 0x23)) {
          pAVar15 = (ASN1_ITEM *)&SUB_00000002;
          pAVar13 = pAStack_ec;
          iVar5 = (*(code *)PTR_BIO_write_006a6e14)(iVar6);
          if (iVar5 != 2) break;
          iVar5 = iVar16 + 4;
        }
      }
    }
    iVar5 = -1;
  }
LAB_0060a7b4:
  if (iStack_e4 == *(int *)puVar1) {
    return iVar5;
  }
  iVar5 = iStack_e4;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar6 = (*(code *)PTR_BIO_gets_006a74d4)();
  if (iVar6 < 1) {
    puVar24 = (uint *)0x0;
    pAVar8 = (ASN1_TEMPLATE *)0x0;
LAB_0060ab88:
    *(uint **)pAVar13 = puVar24;
    iVar6 = 1;
    pAVar13->templates = pAVar8;
  }
  else {
    iVar27 = 0;
    puVar23 = (uint *)0x0;
    pAVar26 = (ASN1_TEMPLATE *)0x0;
    do {
      pcVar12 = &pAVar15->itype + iVar6;
      bVar28 = pcVar12[-1];
      if (bVar28 == 10) {
        iVar6 = iVar6 + -1;
        pcVar12 = (char *)((int)pAVar15 + iVar6);
        *pcVar12 = 0;
        if (iVar6 == 0) break;
        bVar28 = pcVar12[-1];
      }
      if (bVar28 == 0xd) {
        iVar6 = iVar6 + -1;
        pcVar12 = (char *)((int)pAVar15 + iVar6);
        *pcVar12 = 0;
        if (iVar6 == 0) break;
        bVar28 = pcVar12[-1];
      }
      iVar16 = iVar6 + -1;
      pcVar3 = (char *)((int)pAVar15 + iVar16);
      for (; iVar7 = iVar6, pcVar20 = pcVar12, iVar16 != 0; iVar16 = iVar16 + -1) {
        if ((9 < (byte)*pcVar3 - 0x30) &&
           (iVar7 = iVar16, pcVar20 = pcVar3, 5 < ((byte)*pcVar3 & 0xffffffdf) - 0x41)) break;
        pcVar3 = pcVar3 + -1;
      }
      *pcVar20 = 0;
      if (iVar7 == 1) break;
      uVar4 = iVar7 - (uint)(bVar28 == 0x5c);
      iVar6 = (int)uVar4 >> 1;
      if ((uVar4 & 1) != 0) {
        uVar18 = 0x91;
        uVar9 = 0x9b;
        goto LAB_0060aad0;
      }
      puVar24 = (uint *)((int)puVar23 + iVar6);
      pAVar8 = pAVar26;
      if (iVar27 < (int)puVar24) {
        if (pAVar26 == (ASN1_TEMPLATE *)0x0) {
          pAVar8 = (ASN1_TEMPLATE *)
                   (*(code *)PTR_CRYPTO_malloc_006a7008)((int)puVar24 + iVar6,"f_string.c",0xa2);
        }
        else {
          pAVar8 = (ASN1_TEMPLATE *)
                   (*(code *)PTR_CRYPTO_realloc_006a7b58)
                             (pAVar26,(int)puVar24 + iVar6,"f_string.c",0xa6);
        }
        iVar27 = (int)puVar24 + iVar6;
        if (pAVar8 == (ASN1_TEMPLATE *)0x0) {
          (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x67,0x41,"f_string.c",0xa8);
          goto LAB_0060aae4;
        }
      }
      pAVar26 = pAVar8;
      if (iVar6 != 0) {
        pbVar14 = (byte *)((int)puVar24 + (int)&pAVar8->flags);
        pAVar11 = pAVar15;
        pbVar22 = (byte *)((int)puVar23 + (int)&pAVar8->flags);
LAB_0060aa18:
        do {
          uVar10 = (uint)(byte)pAVar11->itype;
          uVar4 = uVar10 - 0x30;
          if (9 < uVar4) {
            uVar4 = uVar10 - 0x57;
            if (uVar10 - 0x61 < 6) {
              bVar2 = *pbVar22;
              goto LAB_0060a9bc;
            }
            uVar4 = uVar10 - 0x37;
            if (uVar10 - 0x41 < 6) goto LAB_0060a9b8;
LAB_0060aabc:
            uVar18 = 0x8d;
            uVar9 = 0xb9;
            goto LAB_0060aad0;
          }
LAB_0060a9b8:
          bVar2 = *pbVar22;
LAB_0060a9bc:
          uVar4 = ((uint)bVar2 << 4 | uVar4) & 0xff;
          *pbVar22 = (byte)uVar4;
          puVar1 = &pAVar11->field_0x1;
          uVar17 = (uint)(byte)*puVar1;
          uVar10 = uVar17 - 0x30;
          if (uVar10 < 10) {
LAB_0060aa00:
            pbVar21 = pbVar22 + 1;
            pAVar11 = (ASN1_ITEM *)&pAVar11->field_0x2;
            *pbVar22 = (byte)(uVar4 << 4) | (byte)uVar10;
            pbVar22 = pbVar21;
            if (pbVar21 == pbVar14) break;
            goto LAB_0060aa18;
          }
          if (5 < uVar17 - 0x61) {
            uVar10 = uVar17 - 0x37;
            if (5 < uVar17 - 0x41) goto LAB_0060aabc;
            goto LAB_0060aa00;
          }
          pbVar21 = pbVar22 + 1;
          pAVar11 = (ASN1_ITEM *)&pAVar11->field_0x2;
          *pbVar22 = (byte)(uVar4 << 4) | *puVar1 + 0xa9;
          pbVar22 = pbVar21;
        } while (pbVar21 != pbVar14);
      }
      if (bVar28 != 0x5c) goto LAB_0060ab88;
      iVar6 = (*(code *)PTR_BIO_gets_006a74d4)(iVar5,pAVar15,pcVar19);
      puVar23 = puVar24;
    } while (0 < iVar6);
    uVar18 = 0x96;
    uVar9 = 0xcc;
LAB_0060aad0:
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x67,uVar18,"f_string.c",uVar9);
LAB_0060aae4:
    (*(code *)PTR_CRYPTO_free_006a6e88)(pAVar26);
    iVar6 = 0;
  }
  return iVar6;
}

