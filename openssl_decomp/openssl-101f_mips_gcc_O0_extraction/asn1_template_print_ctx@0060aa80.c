
/* WARNING: Type propagation algorithm not settling */

bool asn1_template_print_ctx
               (undefined4 param_1,undefined **param_2,int param_3,uint *param_4,uint *param_5)

{
  undefined *puVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  bool bVar8;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint **ppuVar12;
  int iVar13;
  undefined **ppuVar14;
  undefined *puVar15;
  undefined *puVar16;
  code *pcVar17;
  int iVar18;
  uint ***pppuVar19;
  char *local_9c;
  uint **local_8c;
  undefined4 local_88;
  int local_84;
  uint *local_80;
  undefined auStack_7c [80];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  uVar9 = *param_4;
  uVar2 = *param_5;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  ppuVar14 = (undefined **)0x0;
  if ((uVar2 & 0x80) != 0) {
    ppuVar14 = *(undefined ***)(param_4[4] + 0x18);
  }
  if ((uVar2 & 0x40) == 0) {
    uVar11 = param_4[3];
    if ((uVar9 & 6) != 0) {
      if (uVar11 != 0) {
        if ((uVar2 & 4) == 0) {
          iVar4 = (*(code *)PTR_BIO_printf_006a7f38)(param_1,"%*s%s:\n",param_3,"",uVar11);
          if (iVar4 < 1) {
            bVar8 = false;
            goto LAB_0060ad44;
          }
        }
        else {
          if ((uVar9 & 2) == 0) {
            pcVar3 = "SEQUENCE";
          }
          else {
            pcVar3 = "SET";
          }
          iVar4 = (*(code *)PTR_BIO_printf_006a7f38)
                            (param_1,"%*s%s OF %s {\n",param_3,"",pcVar3,uVar11);
          if (iVar4 < 1) goto LAB_0060ad40;
        }
      }
LAB_0060ab64:
      puVar16 = *param_2;
      iVar10 = 0;
      local_9c = "";
      iVar4 = (*(code *)PTR_sk_num_006a7f2c)(puVar16);
      if (0 < iVar4) {
        do {
          if ((0 < iVar10) && (iVar4 = (*(code *)PTR_BIO_puts_006a8058)(param_1,"\n"), iVar4 < 1))
          goto LAB_0060ad40;
          iVar13 = param_3 + 2;
          local_8c = (uint **)(*(code *)PTR_sk_value_006a7f24)(puVar16,iVar10);
          pcVar3 = (char *)param_4[4];
          iVar4 = *(int *)(pcVar3 + 0x10);
          ppuVar14 = (undefined **)0x0;
          if ((iVar4 != 0) &&
             (ppuVar14 = *(undefined ***)(iVar4 + 0x10), ppuVar14 != (undefined **)0x0)) {
            local_80 = param_5;
            local_88 = param_1;
            local_84 = iVar13;
          }
          if (local_8c == (uint **)0x0) {
            if ((*param_5 & 1) == 0) goto LAB_0060acb0;
            iVar4 = (*(code *)PTR_BIO_puts_006a8058)(param_1,"<ABSENT>\n");
            goto joined_r0x0060af04;
          }
          switch(*pcVar3) {
          case '\0':
            if (*(int *)(pcVar3 + 8) != 0) {
              iVar4 = asn1_template_print_ctx(param_1,&local_8c,iVar13,*(int *)(pcVar3 + 8),param_5)
              ;
              if (iVar4 == 0) goto LAB_0060ad40;
              iVar4 = *(int *)(pcVar3 + 0x10);
            }
          case '\x05':
            iVar18 = asn1_print_fsname_isra_4(param_1,iVar13,0,0,param_5);
            ppuVar12 = local_8c;
            if (iVar18 == 0) goto LAB_0060ad40;
            if ((iVar4 != 0) && (*(code **)(iVar4 + 0x1c) != (code *)0x0)) {
              iVar4 = (**(code **)(iVar4 + 0x1c))(param_1,&local_8c,pcVar3,iVar13,param_5);
              break;
            }
            if (*pcVar3 == '\x05') {
              ppuVar14 = (undefined **)((uint)local_8c[1] & 0xfffffeff);
              if (ppuVar14 == (undefined **)0xfffffffc) goto LAB_0060b13c;
LAB_0060af34:
              if ((*param_5 & 8) == 0) {
                pppuVar19 = &local_8c;
                goto LAB_0060af48;
              }
              pppuVar19 = &local_8c;
              iVar4 = (*(code *)PTR_ASN1_tag2str_006a9de8)(ppuVar14);
LAB_0060b03c:
              if (ppuVar14 == (undefined **)&DAT_00000005) goto LAB_0060af54;
              if (iVar4 != 0) {
                iVar4 = (*(code *)PTR_BIO_puts_006a8058)(param_1);
                if (iVar4 < 1) goto LAB_0060ad40;
                iVar4 = (*(code *)PTR_BIO_puts_006a8058)(param_1,":");
                if (iVar4 < 1) goto LAB_0060ad40;
              }
LAB_0060b07c:
              puVar15 = (undefined *)((int)ppuVar14 + 3);
              ppuVar14 = &switchD_0060b098::switchdataD_0067a148 + (int)puVar15;
              switch(puVar15) {
              case (undefined *)0x0:
              case (undefined *)0x13:
              case (undefined *)0x14:
                iVar4 = (*(code *)PTR_BIO_puts_006a8058)(param_1,"\n");
                if (iVar4 < 1) goto LAB_0060ad40;
                iVar4 = (*(code *)PTR_ASN1_parse_dump_006a85b4)
                                  (param_1,ppuVar12[2],*ppuVar12,iVar13,0);
                goto joined_r0x0060af04;
              default:
                iVar4 = (*(code *)PTR_ASN1_STRING_print_ex_006aa550)(param_1,ppuVar12,param_5[4]);
                if (iVar4 == 0) {
                  bVar8 = false;
                  goto LAB_0060ad44;
                }
                break;
              case (undefined *)0x4:
                ppuVar12 = *pppuVar19;
                if (ppuVar12 == (uint **)0xffffffff) {
                  ppuVar12 = *(uint ***)(pcVar3 + 0x14);
                }
                if (ppuVar12 == (uint **)0xffffffff) {
                  pcVar3 = "BOOL ABSENT";
                }
                else if (ppuVar12 == (uint **)0x0) {
                  pcVar3 = "FALSE";
                }
                else {
                  pcVar3 = "TRUE";
                }
                iVar4 = (*(code *)PTR_BIO_puts_006a8058)(param_1,pcVar3);
                if (iVar4 < 1) {
                  bVar8 = false;
                  goto LAB_0060ad44;
                }
                break;
              case (undefined *)0x5:
              case (undefined *)0xd:
                uVar7 = (*(code *)PTR_i2s_ASN1_INTEGER_006aa180)(0,ppuVar12);
                iVar4 = (*(code *)PTR_BIO_puts_006a8058)(param_1,uVar7);
                (*(code *)PTR_CRYPTO_free_006a7f88)(uVar7);
                if (iVar4 < 1) {
                  bVar8 = false;
                  goto LAB_0060ad44;
                }
                break;
              case (undefined *)0x6:
              case (undefined *)0x7:
                if (ppuVar12[1] == (uint *)0x3) {
                  iVar4 = (*(code *)PTR_BIO_printf_006a7f38)
                                    (param_1," (%ld unused bits)\n",(uint)ppuVar12[3] & 7);
                  if (iVar4 < 1) {
                    bVar8 = false;
                    goto LAB_0060ad44;
                  }
                }
                else {
                  iVar4 = (*(code *)PTR_BIO_puts_006a8058)(param_1,"\n");
                  if (iVar4 < 1) goto LAB_0060ad40;
                }
                if (0 < (int)*ppuVar12) {
                  iVar4 = (*(code *)PTR_BIO_dump_indent_006a8434)
                                    (param_1,ppuVar12[2],*ppuVar12,param_3 + 4);
                  goto joined_r0x0060af04;
                }
                goto LAB_0060acb0;
              case (undefined *)0x9:
                ppuVar12 = *pppuVar19;
                uVar7 = (*(code *)PTR_OBJ_obj2nid_006a822c)(ppuVar12);
                pcVar3 = (char *)(*(code *)PTR_OBJ_nid2ln_006a821c)(uVar7);
                if (pcVar3 == (char *)0x0) {
                  pcVar3 = local_9c;
                }
                (*(code *)PTR_OBJ_obj2txt_006a9dbc)(auStack_7c,0x50,ppuVar12,1);
                iVar4 = (*(code *)PTR_BIO_printf_006a7f38)(param_1,"%s (%s)",pcVar3,auStack_7c);
                if (iVar4 < 1) {
                  bVar8 = false;
                  goto LAB_0060ad44;
                }
                break;
              case (undefined *)0x1a:
                iVar4 = (*(code *)PTR_ASN1_UTCTIME_print_006aa8f4)(param_1,ppuVar12);
                if (iVar4 == 0) {
                  bVar8 = false;
                  goto LAB_0060ad44;
                }
                break;
              case (undefined *)0x1b:
                iVar4 = (*(code *)PTR_ASN1_GENERALIZEDTIME_print_006a8f10)(param_1,ppuVar12);
                if (iVar4 == 0) {
                  bVar8 = false;
                  goto LAB_0060ad44;
                }
              }
LAB_0060ad24:
              iVar4 = (*(code *)PTR_BIO_puts_006a8058)(param_1,"\n");
            }
            else {
              ppuVar14 = *(undefined ***)(pcVar3 + 4);
              if (ppuVar14 != (undefined **)0xfffffffc) goto LAB_0060af34;
LAB_0060b13c:
              pppuVar19 = (uint ***)(local_8c + 1);
              ppuVar14 = (undefined **)*local_8c;
              ppuVar12 = (uint **)local_8c[1];
              if ((*param_5 & 0x10) == 0) {
                iVar4 = (*(code *)PTR_ASN1_tag2str_006a9de8)(ppuVar14);
                goto LAB_0060b03c;
              }
LAB_0060af48:
              if (ppuVar14 != (undefined **)&DAT_00000005) goto LAB_0060b07c;
LAB_0060af54:
              iVar4 = (*(code *)PTR_BIO_puts_006a8058)(param_1,"NULL\n");
            }
joined_r0x0060af04:
            if (iVar4 < 1) goto LAB_0060ad40;
            goto LAB_0060acb0;
          case '\x01':
          case '\x06':
            if (ppuVar14 != (undefined **)0x0) {
              iVar4 = (*(code *)ppuVar14)(8,&local_8c,pcVar3,&local_88);
              if (iVar4 == 0) goto LAB_0060ad40;
              if (iVar4 == 2) goto LAB_0060acb0;
            }
            iVar4 = *(int *)(pcVar3 + 8);
            if (0 < *(int *)(pcVar3 + 0xc)) {
              iVar18 = 0;
              do {
                uVar7 = (*(code *)PTR_asn1_do_adb_006a9ea4)(&local_8c,iVar4,1);
                uVar5 = (*(code *)PTR_asn1_get_field_ptr_006a9e8c)(&local_8c,uVar7);
                iVar6 = asn1_template_print_ctx(param_1,uVar5,param_3 + 4,uVar7,param_5);
                if (iVar6 == 0) {
                  bVar8 = false;
                  goto LAB_0060ad44;
                }
                iVar18 = iVar18 + 1;
                iVar4 = iVar4 + 0x14;
              } while (iVar18 < *(int *)(pcVar3 + 0xc));
            }
            if (((*param_5 & 2) != 0) &&
               (iVar4 = (*(code *)PTR_BIO_printf_006a7f38)(param_1,"%*s}\n",iVar13,""), iVar4 < 0))
            {
              bVar8 = false;
              goto LAB_0060ad44;
            }
            if (ppuVar14 == (undefined **)0x0) goto LAB_0060acb0;
            iVar4 = (*(code *)ppuVar14)(9,&local_8c,pcVar3,&local_88);
            break;
          case '\x02':
            iVar4 = (*(code *)PTR_asn1_get_choice_selector_006a9e9c)(&local_8c,pcVar3);
            if ((iVar4 < 0) || (*(int *)(pcVar3 + 0xc) <= iVar4)) {
              iVar4 = (*(code *)PTR_BIO_printf_006a7f38)
                                (param_1,"ERROR: selector [%d] invalid\n",iVar4);
              goto joined_r0x0060af04;
            }
            iVar4 = *(int *)(pcVar3 + 8) + iVar4 * 0x14;
            uVar7 = (*(code *)PTR_asn1_get_field_ptr_006a9e8c)(&local_8c,iVar4);
            iVar4 = asn1_template_print_ctx(param_1,uVar7,iVar13,iVar4,param_5);
            break;
          default:
            (*(code *)PTR_BIO_printf_006a7f38)(param_1,"Unprocessed type %d\n");
            goto LAB_0060ad40;
          case '\x04':
            if ((iVar4 != 0) && (*(code **)(iVar4 + 0x18) != (code *)0x0)) {
              iVar4 = (**(code **)(iVar4 + 0x18))(param_1,&local_8c,iVar13,"",param_5);
              if (iVar4 == 0) goto LAB_0060ad40;
              if (iVar4 != 2) goto LAB_0060acb0;
              goto LAB_0060ad24;
            }
            goto LAB_0060acb0;
          }
          if (iVar4 == 0) goto LAB_0060ad40;
LAB_0060acb0:
          iVar10 = iVar10 + 1;
          iVar4 = (*(code *)PTR_sk_num_006a7f2c)(puVar16);
        } while (iVar10 < iVar4);
      }
      if ((iVar10 == 0) &&
         (iVar4 = (*(code *)PTR_BIO_printf_006a7f38)(param_1,"%*s<EMPTY>\n",param_3 + 2,""),
         iVar4 < 1)) {
        bVar8 = false;
      }
      else {
        if ((*param_5 & 2) == 0) goto LAB_0060ace0;
        iVar4 = (*(code *)PTR_BIO_printf_006a7f38)(param_1,"%*s}\n",param_3,"");
        bVar8 = 0 < iVar4;
      }
      goto LAB_0060ad44;
    }
  }
  else {
    uVar11 = 0;
    if ((uVar9 & 6) != 0) goto LAB_0060ab64;
  }
  pcVar3 = (char *)param_4[4];
  iVar4 = *(int *)(pcVar3 + 0x10);
  pcVar17 = (code *)0x0;
  if ((iVar4 != 0) && (pcVar17 = *(code **)(iVar4 + 0x10), pcVar17 != (code *)0x0)) {
    local_80 = param_5;
    local_88 = param_1;
    local_84 = param_3;
  }
  if (*param_2 == (undefined *)0x0) {
    if ((uVar2 & 1) == 0) goto LAB_0060ace0;
    iVar4 = asn1_print_fsname_isra_4(param_1,param_3,uVar11,ppuVar14,param_5);
    if (iVar4 == 0) goto LAB_0060ad40;
    iVar4 = (*(code *)PTR_BIO_puts_006a8058)(param_1,"<ABSENT>\n");
    bVar8 = 0 < iVar4;
    goto LAB_0060ad44;
  }
  switch(*pcVar3) {
  case '\0':
    if (*(int *)(pcVar3 + 8) != 0) {
      iVar4 = asn1_template_print_ctx(param_1,param_2,param_3,*(int *)(pcVar3 + 8),param_5);
      if (iVar4 == 0) goto LAB_0060ad40;
      iVar4 = *(int *)(pcVar3 + 0x10);
    }
  case '\x05':
    iVar10 = asn1_print_fsname_isra_4(param_1,param_3,uVar11,ppuVar14,param_5);
    if (iVar10 == 0) goto LAB_0060ad40;
    if ((iVar4 != 0) && (*(code **)(iVar4 + 0x1c) != (code *)0x0)) {
      iVar4 = (**(code **)(iVar4 + 0x1c))(param_1,param_2,pcVar3,param_3,param_5);
      bVar8 = iVar4 != 0;
      break;
    }
    ppuVar14 = (undefined **)*param_2;
    if (*pcVar3 == '\x05') {
      puVar16 = (undefined *)((uint)ppuVar14[1] & 0xfffffeff);
    }
    else {
      puVar16 = *(undefined **)(pcVar3 + 4);
    }
    if (puVar16 == (undefined *)0xfffffffc) {
      param_2 = ppuVar14 + 1;
      puVar16 = *ppuVar14;
      uVar2 = *param_5 & 0x10;
      ppuVar14 = (undefined **)ppuVar14[1];
    }
    else {
      uVar2 = *param_5 & 8;
    }
    if (uVar2 == 0) {
      iVar4 = (*(code *)PTR_ASN1_tag2str_006a9de8)(puVar16);
      if (puVar16 == (undefined *)0x5) goto LAB_0060b700;
      if (iVar4 != 0) {
        iVar4 = (*(code *)PTR_BIO_puts_006a8058)(param_1,iVar4);
        if (iVar4 < 1) goto LAB_0060ad40;
        iVar4 = (*(code *)PTR_BIO_puts_006a8058)(param_1,":");
        if (iVar4 < 1) goto LAB_0060ad40;
      }
    }
    else if (puVar16 == (undefined *)0x5) {
LAB_0060b700:
      iVar4 = (*(code *)PTR_BIO_puts_006a8058)(param_1,"NULL\n");
      if (iVar4 < 1) goto LAB_0060ad40;
      bVar8 = true;
      break;
    }
    switch(puVar16) {
    case (undefined *)0x1:
      puVar16 = *param_2;
      if (puVar16 == (undefined *)0xffffffff) {
        puVar16 = *(undefined **)(pcVar3 + 0x14);
      }
      if (puVar16 == (undefined *)0xffffffff) {
        pcVar3 = "BOOL ABSENT";
      }
      else if (puVar16 == (undefined *)0x0) {
        pcVar3 = "FALSE";
      }
      else {
        pcVar3 = "TRUE";
      }
      iVar4 = (*(code *)PTR_BIO_puts_006a8058)(param_1,pcVar3);
      if (iVar4 < 1) {
        bVar8 = false;
        goto LAB_0060ad44;
      }
      goto LAB_0060b7e0;
    case (undefined *)0x2:
    case (undefined *)0xa:
      uVar7 = (*(code *)PTR_i2s_ASN1_INTEGER_006aa180)(0,ppuVar14);
      iVar4 = (*(code *)PTR_BIO_puts_006a8058)(param_1,uVar7);
      uVar2 = (uint)(0 < iVar4);
      (*(code *)PTR_CRYPTO_free_006a7f88)(uVar7);
      break;
    case (undefined *)0x3:
    case (undefined *)0x4:
      if (ppuVar14[1] == (undefined *)0x3) goto LAB_0060bb2c;
      iVar4 = (*(code *)PTR_BIO_puts_006a8058)(param_1,"\n");
      if (iVar4 < 1) goto LAB_0060ad40;
      goto LAB_0060b8b8;
    case (undefined *)0x6:
      puVar16 = *param_2;
      uVar7 = (*(code *)PTR_OBJ_obj2nid_006a822c)(puVar16);
      pcVar3 = (char *)(*(code *)PTR_OBJ_nid2ln_006a821c)(uVar7);
      if (pcVar3 == (char *)0x0) {
        pcVar3 = "";
      }
      (*(code *)PTR_OBJ_obj2txt_006a9dbc)(auStack_7c,0x50,puVar16,1);
      iVar4 = (*(code *)PTR_BIO_printf_006a7f38)(param_1,"%s (%s)",pcVar3,auStack_7c);
      uVar2 = (uint)(0 < iVar4);
      break;
    case (undefined *)0x17:
      uVar2 = (*(code *)PTR_ASN1_UTCTIME_print_006aa8f4)(param_1,ppuVar14);
      break;
    case (undefined *)0x18:
      uVar2 = (*(code *)PTR_ASN1_GENERALIZEDTIME_print_006a8f10)(param_1,ppuVar14);
      break;
    case (undefined *)0xfffffffd:
    case (undefined *)0x10:
    case (undefined *)0x11:
      iVar4 = (*(code *)PTR_BIO_puts_006a8058)(param_1,"\n");
      if (iVar4 < 1) goto LAB_0060ad40;
      iVar4 = (*(code *)PTR_ASN1_parse_dump_006a85b4)(param_1,ppuVar14[2],*ppuVar14,param_3,0);
      if (iVar4 < 1) goto LAB_0060ad40;
      bVar8 = true;
      goto LAB_0060ad44;
    default:
      uVar2 = (*(code *)PTR_ASN1_STRING_print_ex_006aa550)(param_1,ppuVar14,param_5[4]);
    }
    bVar8 = false;
    if (uVar2 != 0) {
LAB_0060b7e0:
      iVar4 = (*(code *)PTR_BIO_puts_006a8058)(param_1,"\n");
      if (iVar4 < 1) goto LAB_0060ad40;
      bVar8 = true;
    }
    break;
  case '\x01':
  case '\x06':
    iVar4 = asn1_print_fsname_isra_4(param_1,param_3,uVar11,ppuVar14,param_5);
    if (iVar4 == 0) goto LAB_0060ad40;
    if ((uVar11 != 0) || (ppuVar14 != (undefined **)0x0)) {
      if ((*param_5 & 2) == 0) {
        iVar4 = (*(code *)PTR_BIO_puts_006a8058)(param_1,"\n");
        if (iVar4 < 1) {
          bVar8 = false;
          break;
        }
      }
      else {
        iVar4 = (*(code *)PTR_BIO_puts_006a8058)(param_1,&DAT_0067a10c);
        if (iVar4 < 1) goto LAB_0060ad40;
      }
    }
    if (pcVar17 != (code *)0x0) {
      iVar4 = (*pcVar17)(8,param_2,pcVar3,&local_88);
      if (iVar4 == 0) goto LAB_0060ad40;
      bVar8 = true;
      if (iVar4 == 2) break;
    }
    iVar4 = *(int *)(pcVar3 + 8);
    if (0 < *(int *)(pcVar3 + 0xc)) {
      iVar10 = 0;
      do {
        ppuVar14 = (undefined **)(*(code *)PTR_asn1_do_adb_006a9ea4)(param_2,iVar4,1);
        uVar7 = (*(code *)PTR_asn1_get_field_ptr_006a9e8c)(param_2,ppuVar14);
        iVar13 = asn1_template_print_ctx(param_1,uVar7,param_3 + 2,ppuVar14,param_5);
        if (iVar13 == 0) {
          bVar8 = false;
          goto LAB_0060ad44;
        }
        iVar10 = iVar10 + 1;
        iVar4 = iVar4 + 0x14;
      } while (iVar10 < *(int *)(pcVar3 + 0xc));
    }
    if (((*param_5 & 2) == 0) ||
       (iVar4 = (*(code *)PTR_BIO_printf_006a7f38)(param_1,"%*s}\n",param_3,""), -1 < iVar4)) {
      if (pcVar17 == (code *)0x0) goto LAB_0060ace0;
      iVar4 = (*pcVar17)(9,param_2,pcVar3,&local_88);
      bVar8 = iVar4 != 0;
    }
    else {
      bVar8 = false;
    }
    break;
  case '\x02':
    iVar4 = (*(code *)PTR_asn1_get_choice_selector_006a9e9c)(param_2,pcVar3);
    if ((iVar4 < 0) || (*(int *)(pcVar3 + 0xc) <= iVar4)) {
      iVar4 = (*(code *)PTR_BIO_printf_006a7f38)(param_1,"ERROR: selector [%d] invalid\n",iVar4);
      bVar8 = 0 < iVar4;
    }
    else {
      iVar4 = *(int *)(pcVar3 + 8) + iVar4 * 0x14;
      uVar7 = (*(code *)PTR_asn1_get_field_ptr_006a9e8c)(param_2,iVar4);
      iVar4 = asn1_template_print_ctx(param_1,uVar7,param_3,iVar4,param_5);
      bVar8 = iVar4 != 0;
    }
    break;
  default:
    (*(code *)PTR_BIO_printf_006a7f38)(param_1,"Unprocessed type %d\n");
    bVar8 = false;
    break;
  case '\x04':
    iVar4 = asn1_print_fsname_isra_4(param_1,param_3,uVar11,ppuVar14,param_5);
    if (iVar4 == 0) goto LAB_0060ad40;
    if ((*(int *)(pcVar3 + 0x10) == 0) ||
       (pcVar17 = *(code **)(*(int *)(pcVar3 + 0x10) + 0x18), pcVar17 == (code *)0x0)) {
      if (ppuVar14 == (undefined **)0x0) goto LAB_0060ace0;
      iVar4 = (*(code *)PTR_BIO_printf_006a7f38)(param_1,":EXTERNAL TYPE %s\n",ppuVar14);
      bVar8 = 0 < iVar4;
    }
    else {
      iVar4 = (*pcVar17)(param_1,param_2,param_3,"",param_5);
      if (iVar4 == 0) goto LAB_0060ad40;
      if (iVar4 != 2) goto LAB_0060ace0;
      iVar4 = (*(code *)PTR_BIO_puts_006a8058)(param_1,"\n");
      bVar8 = 0 < iVar4;
    }
  }
LAB_0060ad44:
  while (local_2c != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_0060bb2c:
    iVar4 = (*(code *)PTR_BIO_printf_006a7f38)(param_1," (%ld unused bits)\n",(uint)ppuVar14[3] & 7)
    ;
    if (iVar4 < 1) {
      bVar8 = false;
    }
    else {
LAB_0060b8b8:
      if ((int)*ppuVar14 < 1) {
LAB_0060ace0:
        bVar8 = true;
      }
      else {
        iVar4 = (*(code *)PTR_BIO_dump_indent_006a8434)(param_1,ppuVar14[2],*ppuVar14,param_3 + 2);
        if (iVar4 < 1) {
LAB_0060ad40:
          bVar8 = false;
        }
        else {
          bVar8 = true;
        }
      }
    }
  }
  return bVar8;
}

