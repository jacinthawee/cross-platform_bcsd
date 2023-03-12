
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
  undefined **ppuVar11;
  ASN1_ITEM *pAVar12;
  char *pcVar13;
  ASN1_ITEM *pAVar14;
  byte *pbVar15;
  ASN1_ITEM *pAVar16;
  int iVar17;
  uint uVar18;
  undefined4 uVar19;
  ASN1_ITEM *pAVar20;
  char *pcVar21;
  uint *puVar22;
  byte *pbVar23;
  byte *pbVar24;
  uint *puVar25;
  ASN1_TEMPLATE *pAVar26;
  int iVar27;
  ASN1_ITEM *unaff_s7;
  byte bVar28;
  code *pcVar29;
  ASN1_ITEM *unaff_s8;
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
  ASN1_ITEM *pAStack_c0;
  code *pcStack_bc;
  ASN1_ITEM *local_a8;
  undefined *local_a0;
  uint local_94;
  ASN1_ITEM *local_90;
  undefined local_8c [8];
  ASN1_TEMPLATE *local_84;
  ASN1_ITEM *local_80;
  ASN1_ITEM aAStack_7c [2];
  int local_2c;
  
  puStack_d4 = PTR___stack_chk_guard_006aabf0;
  local_a0 = &_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (pctx == (ASN1_PCTX *)0x0) {
    pctx = (ASN1_PCTX *)default_pctx;
  }
  pcVar13 = (char *)indent;
  pAVar20 = it;
  local_8c._0_4_ = (ASN1_ITEM *)ifld;
  if ((*(uint *)pctx & 0x100) != 0) {
    ppuVar11 = (undefined **)it->funcs;
    pAStack_c8 = (ASN1_ITEM *)0x0;
    if (ppuVar11 != (undefined **)0x0) goto LAB_0060bbf0;
LAB_0060bc4c:
    ppuStack_cc = (undefined **)0x0;
    if (ifld != (ASN1_VALUE *)0x0) goto LAB_0060bc14;
LAB_0060bc5c:
    pAVar16 = (ASN1_ITEM *)0x0;
    pcVar13 = (char *)ifld;
    if ((*(uint *)pctx & 1) != 0) {
      pcVar13 = (char *)indent;
      pAVar20 = pAStack_c8;
      local_a8 = (ASN1_ITEM *)pctx;
      iVar6 = asn1_print_fsname_isra_4(out,indent,0,pAStack_c8);
      if (iVar6 == 0) goto LAB_0060be60;
      pcVar13 = "<ABSENT>\n";
      iVar6 = (**(code **)(local_a0 + -0x7e88))(out);
      uVar4 = (uint)(0 < iVar6);
      goto LAB_0060bcf4;
    }
    goto LAB_0060bfb0;
  }
  ppuVar11 = (undefined **)it->funcs;
  pAStack_c8 = (ASN1_ITEM *)it->sname;
  if (ppuVar11 == (undefined **)0x0) goto LAB_0060bc4c;
LAB_0060bbf0:
  ppuStack_cc = (undefined **)ppuVar11[4];
  if (ppuStack_cc != (undefined **)0x0) {
    local_8c._4_4_ = out;
    local_84 = (ASN1_TEMPLATE *)indent;
    local_80 = (ASN1_ITEM *)pctx;
  }
  if (ifld == (ASN1_VALUE *)0x0) goto LAB_0060bc5c;
LAB_0060bc14:
  pAVar16 = (ASN1_ITEM *)(int)it->itype;
  switch((uint)pAVar16 & 0xff) {
  case 0:
    pAVar20 = (ASN1_ITEM *)it->templates;
    pcVar13 = local_8c;
    if (pAVar20 != (ASN1_ITEM *)0x0) {
      pAVar16 = (ASN1_ITEM *)indent;
      local_a8 = (ASN1_ITEM *)pctx;
      iVar6 = asn1_template_print_ctx(out);
      if (iVar6 == 0) goto LAB_0060be60;
      ppuVar11 = (undefined **)it->funcs;
    }
  case 5:
    ppuStack_cc = ppuVar11;
    pAVar16 = (ASN1_ITEM *)0x0;
    pcVar13 = (char *)indent;
    pAVar20 = pAStack_c8;
    local_a8 = (ASN1_ITEM *)pctx;
    iVar6 = asn1_print_fsname_isra_4(out,indent,0,pAStack_c8);
    pAVar14 = local_8c._0_4_;
    if (iVar6 == 0) goto LAB_0060be60;
    if (ppuStack_cc != (undefined **)0x0) {
      pcVar13 = local_8c;
      if ((code *)ppuStack_cc[7] != (code *)0x0) {
        pAVar16 = it;
        pAVar20 = (ASN1_ITEM *)indent;
        local_a8 = (ASN1_ITEM *)pctx;
        iVar6 = (*(code *)ppuStack_cc[7])(out,pcVar13,it,indent);
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
      unaff_s7 = (ASN1_ITEM *)(local_8c._0_4_)->utype;
      if ((*(uint *)pctx & 0x10) != 0) goto LAB_0060bfec;
      pcVar13 = (char *)(**(code **)(local_a0 + -0x60f8))(ppuStack_cc);
LAB_0060c04c:
      if (ppuStack_cc == (undefined **)&DAT_00000005) goto LAB_0060bff8;
      ppuVar11 = ppuStack_cc;
      if ((ASN1_ITEM *)pcVar13 != (ASN1_ITEM *)0x0) {
        iVar6 = (**(code **)(local_a0 + -0x7e88))(out);
        if (0 < iVar6) {
          pcVar13 = ":";
          iVar6 = (**(code **)(local_a0 + -0x7e88))(out);
          if (0 < iVar6) goto LAB_0060c08c;
        }
        goto LAB_0060be60;
      }
LAB_0060c08c:
      ppuStack_cc = &switchD_0060c0ac::switchdataD_0067a264 + (int)((int)ppuVar11 + 3);
      pcVar13 = &unaff_s7->itype;
      switch(ppuVar11) {
      case (undefined **)0x1:
        uVar4 = *(uint *)pAStack_c8;
        if (uVar4 == 0xffffffff) {
          uVar4 = it->size;
        }
        if (uVar4 == 0xffffffff) {
          pcVar13 = "BOOL ABSENT";
        }
        else if (uVar4 == 0) {
          pcVar13 = "FALSE";
        }
        else {
          pcVar13 = &DAT_0066dff8;
        }
        iVar6 = (**(code **)(local_a0 + -0x7e88))(out);
        if (iVar6 < 1) {
          uVar4 = 0;
          goto LAB_0060bcf4;
        }
        goto LAB_0060c0d0;
      case (undefined **)0x2:
      case (undefined **)0xa:
        pctx = (ASN1_PCTX *)(**(code **)(local_a0 + -0x5d60))(0,unaff_s7);
        pcVar13 = (char *)pctx;
        iVar6 = (**(code **)(local_a0 + -0x7e88))(out);
        local_94 = (uint)(0 < iVar6);
        (**(code **)(local_a0 + -0x7f58))(pctx);
        uVar10 = local_94;
        break;
      case (undefined **)0x3:
      case (undefined **)0x4:
        if (unaff_s7->utype == 3) {
          pcVar13 = " (%ld unused bits)\n";
          pAVar16 = (ASN1_ITEM *)(unaff_s7->tcount & 7);
          iVar6 = (**(code **)(local_a0 + -0x7fa8))(out);
          if (iVar6 < 1) {
            uVar4 = 0;
            goto LAB_0060bcf4;
          }
        }
        else {
          pcVar13 = "\n";
          iVar6 = (**(code **)(local_a0 + -0x7e88))(out);
          if (iVar6 < 1) goto LAB_0060be60;
        }
        pAVar16 = *(ASN1_ITEM **)unaff_s7;
        if (0 < (int)pAVar16) {
          pAVar20 = (ASN1_ITEM *)(indent + 2);
          pcVar13 = (char *)unaff_s7->templates;
          iVar6 = (**(code **)(local_a0 + -0x7aac))(out,pcVar13,pAVar16,pAVar20);
          if (iVar6 < 1) goto LAB_0060be60;
        }
LAB_0060bfb0:
        uVar4 = 1;
        goto LAB_0060bcf4;
      case (undefined **)0x6:
        uVar4 = *(uint *)pAStack_c8;
        uVar9 = (**(code **)(local_a0 + -0x7cb4))(uVar4);
        it = (ASN1_ITEM *)(**(code **)(local_a0 + -0x7cc4))(uVar9);
        if (it == (ASN1_ITEM *)0x0) {
          it = (ASN1_ITEM *)0x6395d0;
        }
        pctx = (ASN1_PCTX *)aAStack_7c;
        (**(code **)(local_a0 + -0x6124))(pctx,0x50,uVar4,1);
        pcVar13 = "%s (%s)";
        pAVar16 = it;
        pAVar20 = (ASN1_ITEM *)pctx;
        iVar6 = (**(code **)(local_a0 + -0x7fa8))(out,"%s (%s)",it,pctx);
        uVar10 = (uint)(0 < iVar6);
        break;
      case (undefined **)0x17:
        uVar10 = (**(code **)(local_a0 + -0x55ec))(out);
        break;
      case (undefined **)0x18:
        uVar10 = (**(code **)(local_a0 + -0x6fd0))(out);
        break;
      case (undefined **)0xfffffffd:
      case (undefined **)0x10:
      case (undefined **)0x11:
        pcVar13 = "\n";
        iVar6 = (**(code **)(local_a0 + -0x7e88))(out);
        if (0 < iVar6) {
          pAVar16 = *(ASN1_ITEM **)unaff_s7;
          pcVar13 = (char *)unaff_s7->templates;
          local_a8 = (ASN1_ITEM *)0x0;
          pAVar20 = (ASN1_ITEM *)indent;
          iVar6 = (**(code **)(local_a0 + -0x792c))(out,pcVar13,pAVar16,indent);
          if (0 < iVar6) {
            uVar4 = 1;
            goto LAB_0060bcf4;
          }
        }
        goto LAB_0060be60;
      default:
        pAVar16 = *(ASN1_ITEM **)((int)pctx + 0x10);
        uVar10 = (**(code **)(local_a0 + -0x5990))(out);
      }
      uVar4 = 0;
      if (uVar10 != 0) {
LAB_0060c0d0:
        pcVar13 = "\n";
        iVar6 = (**(code **)(local_a0 + -0x7e88))(out);
        if (iVar6 < 1) goto LAB_0060be60;
        uVar4 = 1;
      }
    }
    else {
      if ((*(uint *)pctx & 8) != 0) {
        pAStack_c8 = (ASN1_ITEM *)local_8c;
        pcVar13 = (char *)(**(code **)(local_a0 + -0x60f8))(ppuStack_cc);
        unaff_s7 = pAVar14;
        goto LAB_0060c04c;
      }
      pAStack_c8 = (ASN1_ITEM *)local_8c;
      unaff_s7 = local_8c._0_4_;
LAB_0060bfec:
      ppuVar11 = ppuStack_cc;
      if (ppuStack_cc != (undefined **)&DAT_00000005) goto LAB_0060c08c;
LAB_0060bff8:
      pcVar13 = "NULL\n";
      iVar6 = (**(code **)(local_a0 + -0x7e88))(out);
      if (0 < iVar6) {
        uVar4 = 1;
        break;
      }
LAB_0060be60:
      uVar4 = 0;
    }
    break;
  case 1:
  case 6:
    pAVar16 = (ASN1_ITEM *)0x0;
    pAVar20 = pAStack_c8;
    local_a8 = (ASN1_ITEM *)pctx;
    iVar6 = asn1_print_fsname_isra_4(out,indent,0,pAStack_c8);
    if (iVar6 != 0) {
      if (pAStack_c8 != (ASN1_ITEM *)0x0) {
        if ((*(uint *)pctx & 2) == 0) {
          pcVar13 = "\n";
          iVar6 = (**(code **)(local_a0 + -0x7e88))(out);
          if (iVar6 < 1) {
            uVar4 = 0;
            break;
          }
        }
        else {
          pcVar13 = &DAT_0067a12c;
          iVar6 = (**(code **)(local_a0 + -0x7e88))();
          if (iVar6 < 1) goto LAB_0060be60;
        }
      }
      pAVar20 = (ASN1_ITEM *)(local_8c + 4);
      if (ppuStack_cc != (undefined **)0x0) {
        pcVar13 = local_8c;
        pAVar16 = it;
        iVar6 = (*(code *)ppuStack_cc)(8,pcVar13,it,pAVar20);
        if (iVar6 == 0) goto LAB_0060be60;
        uVar4 = 1;
        if (iVar6 == 2) break;
      }
      unaff_s7 = (ASN1_ITEM *)it->templates;
      if (0 < it->tcount) {
        local_90 = (ASN1_ITEM *)(indent + 2);
        uVar4 = 0;
        pAStack_c8 = (ASN1_ITEM *)local_8c;
        do {
          local_94 = uVar4;
          unaff_s8 = (ASN1_ITEM *)(**(code **)(local_a0 + -0x603c))(pAStack_c8,unaff_s7,1);
          pcVar13 = (char *)(**(code **)(local_a0 + -0x6054))(pAStack_c8,unaff_s8);
          pAVar16 = local_90;
          pAVar20 = unaff_s8;
          local_a8 = (ASN1_ITEM *)pctx;
          iVar6 = asn1_template_print_ctx(out,pcVar13,local_90,unaff_s8);
          if (iVar6 == 0) goto LAB_0060be60;
          uVar4 = local_94 + 1;
          unaff_s7 = (ASN1_ITEM *)&unaff_s7->size;
        } while ((int)uVar4 < it->tcount);
      }
      if ((*(uint *)pctx & 2) != 0) {
        pAVar20 = (ASN1_ITEM *)0x6395d0;
        pcVar13 = "%*s}\n";
        pAVar16 = (ASN1_ITEM *)indent;
        iVar6 = (**(code **)(local_a0 + -0x7fa8))(out,"%*s}\n",indent,"");
        if (iVar6 < 0) {
          uVar4 = 0;
          break;
        }
      }
      pAVar20 = (ASN1_ITEM *)(local_8c + 4);
      if (ppuStack_cc == (undefined **)0x0) goto LAB_0060bfb0;
      pcVar13 = local_8c;
      pAVar16 = it;
      iVar6 = (*(code *)ppuStack_cc)(9,pcVar13,it,pAVar20);
      uVar4 = (uint)(iVar6 != 0);
      break;
    }
    goto LAB_0060be60;
  case 2:
    ppuStack_cc = (undefined **)local_8c;
    pAVar16 = (ASN1_ITEM *)(*(code *)PTR_asn1_get_choice_selector_006a9e9c)(ppuStack_cc,it);
    if (((int)pAVar16 < 0) ||
       (pAVar20 = (ASN1_ITEM *)((int)pAVar16 * 4), it->tcount <= (int)pAVar16)) {
      pcVar13 = "ERROR: selector [%d] invalid\n";
      iVar6 = (**(code **)(local_a0 + -0x7fa8))(out);
      uVar4 = (uint)(0 < iVar6);
    }
    else {
      it = (ASN1_ITEM *)(it->templates + (int)pAVar16);
      pcVar13 = (char *)(**(code **)(local_a0 + -0x6054))(ppuStack_cc,it);
      pAVar16 = (ASN1_ITEM *)indent;
      pAVar20 = it;
      local_a8 = (ASN1_ITEM *)pctx;
      iVar6 = asn1_template_print_ctx(out,pcVar13,indent,it);
      uVar4 = (uint)(iVar6 != 0);
    }
    break;
  default:
    pcVar13 = "Unprocessed type %d\n";
    (*(code *)PTR_BIO_printf_006a7f38)(out);
    uVar4 = 0;
    break;
  case 4:
    pAVar16 = (ASN1_ITEM *)0x0;
    pAVar20 = pAStack_c8;
    local_a8 = (ASN1_ITEM *)pctx;
    iVar6 = asn1_print_fsname_isra_4(out,indent,0,pAStack_c8);
    if (iVar6 == 0) goto LAB_0060be60;
    if (it->funcs != (void *)0x0) {
      pcVar29 = *(code **)((int)it->funcs + 0x18);
      pAVar20 = (ASN1_ITEM *)0x640000;
      if (pcVar29 != (code *)0x0) {
        pcVar13 = local_8c;
        pAVar20 = (ASN1_ITEM *)0x6395d0;
        pAVar16 = (ASN1_ITEM *)indent;
        local_a8 = (ASN1_ITEM *)pctx;
        iVar6 = (*pcVar29)(out,pcVar13,indent,"");
        if (iVar6 != 0) {
          pcVar13 = "s\n";
          if (iVar6 != 2) goto LAB_0060bfb0;
          pcVar13 = "\n";
          iVar6 = (**(code **)(local_a0 + -0x7e88))(out);
          uVar4 = (uint)(0 < iVar6);
          break;
        }
        goto LAB_0060be60;
      }
    }
    pcVar13 = (char *)0x680000;
    if (pAStack_c8 == (ASN1_ITEM *)0x0) goto LAB_0060bfb0;
    pcVar13 = ":EXTERNAL TYPE %s\n";
    pAVar16 = pAStack_c8;
    iVar6 = (**(code **)(local_a0 + -0x7fa8))(out);
    uVar4 = (uint)(0 < iVar6);
  }
LAB_0060bcf4:
  if (local_2c == *(int *)puStack_d4) {
    return uVar4;
  }
  pcStack_bc = i2a_ASN1_STRING;
  iVar6 = local_2c;
  (**(code **)(local_a0 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_e4 = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar5 = 0;
  pAVar14 = (ASN1_ITEM *)pcVar13;
  pAStack_e0 = (ASN1_ITEM *)pctx;
  pAStack_dc = it;
  pBStack_d8 = out;
  pcStack_d0 = (char *)indent;
  pAStack_c4 = unaff_s7;
  pAStack_c0 = unaff_s8;
  if ((ASN1_ITEM *)pcVar13 != (ASN1_ITEM *)0x0) {
    if (*(uint **)pcVar13 == (uint *)0x0) {
      pAVar16 = (ASN1_ITEM *)0x1;
      pAVar14 = (ASN1_ITEM *)0x6358cc;
      iVar5 = (*(code *)PTR_BIO_write_006a7f14)();
      if (iVar5 == 1) goto LAB_0060c534;
    }
    else {
      if ((int)*(uint **)pcVar13 < 1) {
        iVar5 = 0;
        goto LAB_0060c534;
      }
      iVar27 = 0;
      pAStack_ec = (ASN1_ITEM *)&DAT_0066adb0;
      iVar5 = 0;
      while( true ) {
        iVar17 = iVar5;
        pAVar16 = (ASN1_ITEM *)&SUB_00000002;
        pbVar24 = (byte *)((int)&(*(ASN1_TEMPLATE **)((int)pcVar13 + 8))->flags + iVar27);
        auStack_e8[0] = "0123456789ABCDEF"[*pbVar24 >> 4];
        auStack_e8[1] = "0123456789ABCDEF"[*pbVar24 & 0xf];
        pAVar14 = (ASN1_ITEM *)auStack_e8;
        iVar5 = (*(code *)PTR_BIO_write_006a7f14)(iVar6);
        if (iVar5 != 2) break;
        iVar27 = iVar27 + 1;
        iVar5 = iVar17 + 2;
        if ((int)*(uint **)pcVar13 <= iVar27) goto LAB_0060c534;
        if ((iVar27 != 0) && (iVar27 == (iVar27 / 0x23) * 0x23)) {
          pAVar16 = (ASN1_ITEM *)&SUB_00000002;
          pAVar14 = pAStack_ec;
          iVar5 = (*(code *)PTR_BIO_write_006a7f14)(iVar6);
          if (iVar5 != 2) break;
          iVar5 = iVar17 + 4;
        }
      }
    }
    iVar5 = -1;
  }
LAB_0060c534:
  if (iStack_e4 == *(int *)puVar1) {
    return iVar5;
  }
  iVar5 = iStack_e4;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar6 = (*(code *)PTR_BIO_gets_006a85d0)();
  if (iVar6 < 1) {
    puVar25 = (uint *)0x0;
    pAVar8 = (ASN1_TEMPLATE *)0x0;
LAB_0060c910:
    *(uint **)pAVar14 = puVar25;
    iVar6 = 1;
    pAVar14->templates = pAVar8;
  }
  else {
    iVar27 = 0;
    puVar22 = (uint *)0x0;
    pAVar26 = (ASN1_TEMPLATE *)0x0;
    do {
      pcVar13 = &pAVar16->itype + iVar6;
      bVar28 = pcVar13[-1];
      if (bVar28 == 10) {
        iVar6 = iVar6 + -1;
        pcVar13 = (char *)((int)pAVar16 + iVar6);
        *pcVar13 = 0;
        if (iVar6 == 0) break;
        bVar28 = pcVar13[-1];
      }
      if (bVar28 == 0xd) {
        iVar6 = iVar6 + -1;
        pcVar13 = (char *)((int)pAVar16 + iVar6);
        *pcVar13 = 0;
        if (iVar6 == 0) break;
        bVar28 = pcVar13[-1];
      }
      iVar17 = iVar6 + -1;
      pcVar3 = (char *)((int)pAVar16 + iVar17);
      for (; iVar7 = iVar6, pcVar21 = pcVar13, iVar17 != 0; iVar17 = iVar17 + -1) {
        if ((9 < (byte)*pcVar3 - 0x30) &&
           (iVar7 = iVar17, pcVar21 = pcVar3, 5 < ((byte)*pcVar3 & 0xffffffdf) - 0x41)) break;
        pcVar3 = pcVar3 + -1;
      }
      *pcVar21 = 0;
      if (iVar7 == 1) break;
      uVar4 = iVar7 - (uint)(bVar28 == 0x5c);
      iVar6 = (int)uVar4 >> 1;
      if ((uVar4 & 1) != 0) {
        uVar19 = 0x91;
        uVar9 = 0x9a;
        goto LAB_0060c850;
      }
      puVar25 = (uint *)((int)puVar22 + iVar6);
      pAVar8 = pAVar26;
      if (iVar27 < (int)puVar25) {
        if (pAVar26 == (ASN1_TEMPLATE *)0x0) {
          pAVar8 = (ASN1_TEMPLATE *)
                   (*(code *)PTR_CRYPTO_malloc_006a8108)((int)puVar25 + iVar6,"f_string.c",0xa2);
        }
        else {
          pAVar8 = (ASN1_TEMPLATE *)
                   (*(code *)PTR_CRYPTO_realloc_006a8c44)
                             (pAVar26,(int)puVar25 + iVar6,"f_string.c",0xa5);
        }
        iVar27 = (int)puVar25 + iVar6;
        if (pAVar8 == (ASN1_TEMPLATE *)0x0) {
          (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x67,0x41,"f_string.c",0xa8);
          if (pAVar26 != (ASN1_TEMPLATE *)0x0) {
            (*(code *)PTR_CRYPTO_free_006a7f88)(pAVar26);
            return 0;
          }
          return 0;
        }
      }
      if (iVar6 != 0) {
        pbVar15 = (byte *)((int)puVar25 + (int)&pAVar8->flags);
        pAVar12 = pAVar16;
        pbVar24 = (byte *)((int)puVar22 + (int)&pAVar8->flags);
LAB_0060c798:
        do {
          uVar10 = (uint)(byte)pAVar12->itype;
          uVar4 = uVar10 - 0x30;
          if (9 < uVar4) {
            uVar4 = uVar10 - 0x57;
            if (uVar10 - 0x61 < 6) {
              bVar2 = *pbVar24;
              goto LAB_0060c73c;
            }
            uVar4 = uVar10 - 0x37;
            if (uVar10 - 0x41 < 6) goto LAB_0060c738;
LAB_0060c83c:
            uVar19 = 0x8d;
            uVar9 = 0xbc;
            goto LAB_0060c850;
          }
LAB_0060c738:
          bVar2 = *pbVar24;
LAB_0060c73c:
          uVar4 = ((uint)bVar2 << 4 | uVar4) & 0xff;
          *pbVar24 = (byte)uVar4;
          puVar1 = &pAVar12->field_0x1;
          uVar18 = (uint)(byte)*puVar1;
          uVar10 = uVar18 - 0x30;
          if (9 < uVar10) {
            if (uVar18 - 0x61 < 6) {
              pbVar23 = pbVar24 + 1;
              pAVar12 = (ASN1_ITEM *)&pAVar12->field_0x2;
              *pbVar24 = (byte)(uVar4 << 4) | *puVar1 + 0xa9;
              pbVar24 = pbVar23;
              if (pbVar23 == pbVar15) break;
              goto LAB_0060c798;
            }
            uVar10 = uVar18 - 0x37;
            if (5 < uVar18 - 0x41) goto LAB_0060c83c;
          }
          pbVar23 = pbVar24 + 1;
          pAVar12 = (ASN1_ITEM *)&pAVar12->field_0x2;
          *pbVar24 = (byte)(uVar4 << 4) | (byte)uVar10;
          pbVar24 = pbVar23;
        } while (pbVar23 != pbVar15);
      }
      if (bVar28 != 0x5c) goto LAB_0060c910;
      iVar6 = (*(code *)PTR_BIO_gets_006a85d0)(iVar5,pAVar16,pAVar20);
      puVar22 = puVar25;
      pAVar26 = pAVar8;
    } while (0 < iVar6);
    uVar19 = 0x96;
    uVar9 = 0xd0;
LAB_0060c850:
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x67,uVar19,"f_string.c",uVar9);
    iVar6 = 0;
  }
  return iVar6;
}

