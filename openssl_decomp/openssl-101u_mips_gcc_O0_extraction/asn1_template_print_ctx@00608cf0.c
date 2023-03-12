
/* WARNING: Type propagation algorithm not settling */

bool asn1_template_print_ctx
               (undefined4 param_1,uint **param_2,int param_3,uint *param_4,uint *param_5)

{
  undefined *puVar1;
  uint uVar2;
  char *pcVar3;
  bool bVar6;
  int iVar4;
  undefined4 uVar5;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint **ppuVar10;
  int iVar11;
  code *pcVar12;
  int iVar13;
  uint *puVar14;
  int iVar15;
  char *unaff_s7;
  uint *puVar16;
  code *local_b4;
  char *local_9c;
  uint *local_8c;
  undefined4 local_88;
  int local_84;
  uint *local_80;
  undefined auStack_7c [80];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  uVar7 = *param_4;
  uVar2 = *param_5;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar13 = 0;
  if ((uVar2 & 0x80) != 0) {
    iVar13 = *(int *)(param_4[4] + 0x18);
  }
  if ((uVar2 & 0x40) != 0) {
    uVar9 = 0;
    if ((uVar7 & 6) == 0) goto LAB_00609194;
LAB_00608dd4:
    puVar16 = *param_2;
    iVar8 = 0;
    local_9c = "";
    iVar13 = (*(code *)PTR_sk_num_006a6e2c)(puVar16);
    if (0 < iVar13) {
      do {
        if ((0 < iVar8) && (iVar13 = (*(code *)PTR_BIO_puts_006a6f58)(param_1,"\n"), iVar13 < 1))
        goto LAB_00608fac;
        iVar15 = param_3 + 2;
        local_8c = (uint *)(*(code *)PTR_sk_value_006a6e24)(puVar16,iVar8);
        unaff_s7 = (char *)param_4[4];
        iVar13 = *(int *)(unaff_s7 + 0x10);
        if (iVar13 != 0) {
          local_b4 = *(code **)(iVar13 + 0x10);
          if (local_b4 != (code *)0x0) {
            local_80 = param_5;
            local_88 = param_1;
            local_84 = iVar15;
          }
          if (local_8c != (uint *)0x0) goto LAB_00608e9c;
LAB_00609158:
          if ((*param_5 & 1) != 0) {
            iVar13 = (*(code *)PTR_BIO_puts_006a6f58)(param_1,"<ABSENT>\n");
            goto joined_r0x00609178;
          }
          goto LAB_00608f1c;
        }
        local_b4 = (code *)0x0;
        if (local_8c == (uint *)0x0) goto LAB_00609158;
LAB_00608e9c:
        switch(*unaff_s7) {
        case '\0':
          if (*(int *)(unaff_s7 + 8) == 0) goto switchD_00608ebc_caseD_5;
          iVar13 = asn1_template_print_ctx(param_1,&local_8c,iVar15,*(int *)(unaff_s7 + 8),param_5);
joined_r0x00609310:
          if (iVar13 == 0) goto LAB_00608fac;
          break;
        case '\x01':
        case '\x06':
          if (local_b4 != (code *)0x0) {
            iVar13 = (*local_b4)(8,&local_8c,unaff_s7,&local_88);
            if (iVar13 == 0) goto LAB_00608fac;
            if (iVar13 == 2) break;
          }
          iVar13 = *(int *)(unaff_s7 + 8);
          if (0 < *(int *)(unaff_s7 + 0xc)) {
            iVar11 = 0;
            do {
              iVar4 = (*(code *)PTR_asn1_do_adb_006a8d84)(&local_8c,iVar13,1);
              if (iVar4 == 0) {
                bVar6 = false;
                goto LAB_00608fb0;
              }
              uVar5 = (*(code *)PTR_asn1_get_field_ptr_006a8d70)(&local_8c,iVar4);
              iVar4 = asn1_template_print_ctx(param_1,uVar5,param_3 + 4,iVar4,param_5);
              if (iVar4 == 0) goto LAB_00608fac;
              iVar11 = iVar11 + 1;
              iVar13 = iVar13 + 0x14;
            } while (iVar11 < *(int *)(unaff_s7 + 0xc));
          }
          if (((*param_5 & 2) != 0) &&
             (iVar13 = (*(code *)PTR_BIO_printf_006a6e38)(param_1,"%*s}\n",iVar15,""), iVar13 < 0))
          {
            bVar6 = false;
            goto LAB_00608fb0;
          }
          if (local_b4 != (code *)0x0) {
            iVar13 = (*local_b4)(9,&local_8c,unaff_s7,&local_88);
            goto joined_r0x00609310;
          }
          break;
        case '\x02':
          iVar13 = (*(code *)PTR_asn1_get_choice_selector_006a8d7c)(&local_8c,unaff_s7);
          if ((-1 < iVar13) && (iVar13 < *(int *)(unaff_s7 + 0xc))) {
            iVar13 = *(int *)(unaff_s7 + 8) + iVar13 * 0x14;
            uVar5 = (*(code *)PTR_asn1_get_field_ptr_006a8d70)(&local_8c,iVar13);
            iVar13 = asn1_template_print_ctx(param_1,uVar5,iVar15,iVar13,param_5);
            goto joined_r0x00609310;
          }
          iVar13 = (*(code *)PTR_BIO_printf_006a6e38)
                             (param_1,"ERROR: selector [%d] invalid\n",iVar13);
          goto joined_r0x00609178;
        default:
          (*(code *)PTR_BIO_printf_006a6e38)(param_1,"Unprocessed type %d\n");
          goto LAB_00608fac;
        case '\x04':
          if ((iVar13 != 0) && (*(code **)(iVar13 + 0x18) != (code *)0x0)) {
            iVar13 = (**(code **)(iVar13 + 0x18))(param_1,&local_8c,iVar15,"",param_5);
            if (iVar13 == 0) goto LAB_00608fac;
            if (iVar13 != 2) break;
            goto LAB_00608f90;
          }
          break;
        case '\x05':
switchD_00608ebc_caseD_5:
          iVar11 = asn1_print_fsname_isra_4(param_1,iVar15,0,0,param_5);
          puVar14 = local_8c;
          if (iVar11 == 0) goto LAB_00608fac;
          if ((iVar13 != 0) && (*(code **)(iVar13 + 0x1c) != (code *)0x0)) {
            iVar13 = (**(code **)(iVar13 + 0x1c))(param_1,&local_8c,unaff_s7,iVar15,param_5);
            goto joined_r0x00609310;
          }
          if (*unaff_s7 == '\x05') {
            uVar2 = local_8c[1] & 0xfffffeff;
          }
          else {
            uVar2 = *(uint *)(unaff_s7 + 4);
          }
          if (uVar2 == 0xfffffffc) {
            ppuVar10 = (uint **)(local_8c + 1);
            uVar2 = *local_8c;
            puVar14 = (uint *)local_8c[1];
            if ((*param_5 & 0x10) == 0) {
              iVar13 = (*(code *)PTR_ASN1_tag2str_006a74b4)(uVar2);
              goto LAB_00609274;
            }
LAB_0060922c:
            if (uVar2 == 5) goto LAB_00609238;
          }
          else {
            if ((*param_5 & 8) == 0) {
              ppuVar10 = &local_8c;
              goto LAB_0060922c;
            }
            ppuVar10 = &local_8c;
            iVar13 = (*(code *)PTR_ASN1_tag2str_006a74b4)(uVar2);
LAB_00609274:
            if (uVar2 == 5) {
LAB_00609238:
              iVar13 = (*(code *)PTR_BIO_puts_006a6f58)(param_1,"NULL\n");
              goto joined_r0x00609178;
            }
            if (iVar13 != 0) {
              iVar13 = (*(code *)PTR_BIO_puts_006a6f58)(param_1);
              if (iVar13 < 1) goto LAB_00608fac;
              iVar13 = (*(code *)PTR_BIO_puts_006a6f58)(param_1,":");
              if (iVar13 < 1) goto LAB_00608fac;
            }
          }
          switch(uVar2) {
          case 1:
            puVar14 = *ppuVar10;
            if (puVar14 == (uint *)0xffffffff) {
              puVar14 = *(uint **)(unaff_s7 + 0x14);
            }
            if (puVar14 == (uint *)0xffffffff) {
              pcVar3 = "BOOL ABSENT";
            }
            else if (puVar14 == (uint *)0x0) {
              pcVar3 = "FALSE";
            }
            else {
              pcVar3 = "TRUE";
            }
            iVar13 = (*(code *)PTR_BIO_puts_006a6f58)(param_1,pcVar3);
            if (iVar13 < 1) {
              bVar6 = false;
              goto LAB_00608fb0;
            }
            break;
          case 2:
          case 10:
            iVar13 = (*(code *)PTR_i2s_ASN1_INTEGER_006a9064)(0,puVar14);
            if (iVar13 == 0) goto LAB_00608fac;
            iVar15 = (*(code *)PTR_BIO_puts_006a6f58)(param_1,iVar13);
            (*(code *)PTR_CRYPTO_free_006a6e88)(iVar13);
            if (iVar15 < 1) {
              bVar6 = false;
              goto LAB_00608fb0;
            }
            break;
          case 3:
          case 4:
            if (puVar14[1] == 3) {
              iVar13 = (*(code *)PTR_BIO_printf_006a6e38)
                                 (param_1," (%ld unused bits)\n",puVar14[3] & 7);
              if (iVar13 < 1) {
                bVar6 = false;
                goto LAB_00608fb0;
              }
            }
            else {
              iVar13 = (*(code *)PTR_BIO_puts_006a6f58)(param_1,"\n");
              if (iVar13 < 1) goto LAB_00608fac;
            }
            if ((int)*puVar14 < 1) goto LAB_00608f1c;
            iVar13 = (*(code *)PTR_BIO_dump_indent_006a7334)
                               (param_1,puVar14[2],*puVar14,param_3 + 4);
            goto joined_r0x00609178;
          case 6:
            puVar14 = *ppuVar10;
            uVar5 = (*(code *)PTR_OBJ_obj2nid_006a712c)(puVar14);
            pcVar3 = (char *)(*(code *)PTR_OBJ_nid2ln_006a711c)(uVar5);
            if (pcVar3 == (char *)0x0) {
              pcVar3 = local_9c;
            }
            (*(code *)PTR_OBJ_obj2txt_006a8c9c)(auStack_7c,0x50,puVar14,1);
            iVar13 = (*(code *)PTR_BIO_printf_006a6e38)(param_1,"%s (%s)",pcVar3,auStack_7c);
            if (iVar13 < 1) {
              bVar6 = false;
              goto LAB_00608fb0;
            }
            break;
          case 0x17:
            iVar13 = (*(code *)PTR_ASN1_UTCTIME_print_006a97e4)(param_1,puVar14);
            if (iVar13 == 0) {
              bVar6 = false;
              goto LAB_00608fb0;
            }
            break;
          case 0x18:
            iVar13 = (*(code *)PTR_ASN1_GENERALIZEDTIME_print_006a7e20)(param_1,puVar14);
            if (iVar13 == 0) {
              bVar6 = false;
              goto LAB_00608fb0;
            }
            break;
          case 0xfffffffd:
          case 0x10:
          case 0x11:
            iVar13 = (*(code *)PTR_BIO_puts_006a6f58)(param_1,"\n");
            if (iVar13 < 1) goto LAB_00608fac;
            iVar13 = (*(code *)PTR_ASN1_parse_dump_006a74b8)(param_1,puVar14[2],*puVar14,iVar15,0);
            goto joined_r0x00609178;
          default:
            iVar13 = (*(code *)PTR_ASN1_STRING_print_ex_006a9444)(param_1,puVar14,param_5[4]);
            if (iVar13 == 0) {
              bVar6 = false;
              goto LAB_00608fb0;
            }
          }
LAB_00608f90:
          iVar13 = (*(code *)PTR_BIO_puts_006a6f58)(param_1,"\n");
joined_r0x00609178:
          if (iVar13 < 1) goto LAB_00608fac;
        }
LAB_00608f1c:
        iVar8 = iVar8 + 1;
        iVar13 = (*(code *)PTR_sk_num_006a6e2c)(puVar16);
      } while (iVar8 < iVar13);
    }
    if ((iVar8 == 0) &&
       (iVar13 = (*(code *)PTR_BIO_printf_006a6e38)(param_1,"%*s<EMPTY>\n",param_3 + 2,""),
       iVar13 < 1)) {
      bVar6 = false;
      goto LAB_00608fb0;
    }
    if ((*param_5 & 2) != 0) {
      iVar13 = (*(code *)PTR_BIO_printf_006a6e38)(param_1,"%*s}\n",param_3,"");
      bVar6 = 0 < iVar13;
      goto LAB_00608fb0;
    }
    goto LAB_00608f4c;
  }
  uVar9 = param_4[3];
  if ((uVar7 & 6) != 0) {
    if (uVar9 != 0) {
      if ((uVar2 & 4) == 0) {
        iVar13 = (*(code *)PTR_BIO_printf_006a6e38)(param_1,"%*s%s:\n",param_3,"",uVar9);
        if (iVar13 < 1) {
          bVar6 = false;
          goto LAB_00608fb0;
        }
      }
      else {
        if ((uVar7 & 2) == 0) {
          pcVar3 = "SEQUENCE";
        }
        else {
          pcVar3 = "SET";
        }
        iVar13 = (*(code *)PTR_BIO_printf_006a6e38)
                           (param_1,"%*s%s OF %s {\n",param_3,"",pcVar3,uVar9);
        if (iVar13 < 1) goto LAB_00608fac;
      }
    }
    goto LAB_00608dd4;
  }
LAB_00609194:
  unaff_s7 = (char *)param_4[4];
  iVar8 = *(int *)(unaff_s7 + 0x10);
  pcVar12 = (code *)0x0;
  if ((iVar8 != 0) && (pcVar12 = *(code **)(iVar8 + 0x10), pcVar12 != (code *)0x0)) {
    local_80 = param_5;
    local_88 = param_1;
    local_84 = param_3;
  }
  if (*param_2 == (uint *)0x0) {
    if ((uVar2 & 1) != 0) {
      iVar13 = asn1_print_fsname_isra_4(param_1,param_3,uVar9,iVar13,param_5);
      if (iVar13 == 0) goto LAB_00608fac;
      iVar13 = (*(code *)PTR_BIO_puts_006a6f58)(param_1,"<ABSENT>\n");
      bVar6 = 0 < iVar13;
      goto LAB_00608fb0;
    }
    goto LAB_00608f4c;
  }
  switch(*unaff_s7) {
  case '\0':
    if (*(int *)(unaff_s7 + 8) != 0) {
      iVar13 = asn1_template_print_ctx(param_1,param_2,param_3,*(int *)(unaff_s7 + 8),param_5);
      bVar6 = iVar13 != 0;
      goto LAB_00608fb0;
    }
  case '\x05':
    iVar13 = asn1_print_fsname_isra_4(param_1,param_3,uVar9,iVar13,param_5);
    if (iVar13 == 0) goto LAB_00608fac;
    if ((iVar8 != 0) && (*(code **)(iVar8 + 0x1c) != (code *)0x0)) {
      iVar13 = (**(code **)(iVar8 + 0x1c))(param_1,param_2,unaff_s7,param_3,param_5);
      bVar6 = iVar13 != 0;
      goto LAB_00608fb0;
    }
    puVar16 = *param_2;
    if (*unaff_s7 == '\x05') {
      uVar2 = puVar16[1] & 0xfffffeff;
    }
    else {
      uVar2 = *(uint *)(unaff_s7 + 4);
    }
    if (uVar2 == 0xfffffffc) {
      param_2 = (uint **)(puVar16 + 1);
      uVar2 = *puVar16;
      uVar7 = *param_5 & 0x10;
      puVar16 = (uint *)puVar16[1];
    }
    else {
      uVar7 = *param_5 & 8;
    }
    if (uVar7 == 0) {
      iVar13 = (*(code *)PTR_ASN1_tag2str_006a74b4)(uVar2);
      if (uVar2 != 5) {
        if (iVar13 != 0) {
          iVar13 = (*(code *)PTR_BIO_puts_006a6f58)(param_1,iVar13);
          if (iVar13 < 1) goto LAB_00608fac;
          iVar13 = (*(code *)PTR_BIO_puts_006a6f58)(param_1,":");
          if (iVar13 < 1) goto LAB_00608fac;
        }
        goto LAB_00609a98;
      }
    }
    else if (uVar2 != 5) {
LAB_00609a98:
      switch(uVar2) {
      case 1:
        puVar16 = *param_2;
        if (puVar16 == (uint *)0xffffffff) goto LAB_00609db4;
        goto LAB_00609ca8;
      case 2:
      case 10:
        iVar13 = (*(code *)PTR_i2s_ASN1_INTEGER_006a9064)(0,puVar16);
        if (iVar13 == 0) goto LAB_00608fac;
        iVar8 = (*(code *)PTR_BIO_puts_006a6f58)(param_1,iVar13);
        uVar2 = (uint)(0 < iVar8);
        (*(code *)PTR_CRYPTO_free_006a6e88)(iVar13);
        break;
      case 3:
      case 4:
        if (puVar16[1] == 3) {
          iVar13 = (*(code *)PTR_BIO_printf_006a6e38)(param_1," (%ld unused bits)\n",puVar16[3] & 7)
          ;
          if (iVar13 < 1) {
            bVar6 = false;
            goto LAB_00608fb0;
          }
        }
        else {
          iVar13 = (*(code *)PTR_BIO_puts_006a6f58)(param_1,"\n");
          if (iVar13 < 1) goto LAB_00608fac;
        }
        if (0 < (int)*puVar16) {
          iVar13 = (*(code *)PTR_BIO_dump_indent_006a7334)(param_1,puVar16[2],*puVar16,param_3 + 2);
          if (iVar13 < 1) goto LAB_00608fac;
          bVar6 = true;
          goto LAB_00608fb0;
        }
        goto LAB_00608f4c;
      case 6:
        puVar16 = *param_2;
        uVar5 = (*(code *)PTR_OBJ_obj2nid_006a712c)(puVar16);
        pcVar3 = (char *)(*(code *)PTR_OBJ_nid2ln_006a711c)(uVar5);
        if (pcVar3 == (char *)0x0) {
          pcVar3 = "";
        }
        (*(code *)PTR_OBJ_obj2txt_006a8c9c)(auStack_7c,0x50,puVar16,1);
        iVar13 = (*(code *)PTR_BIO_printf_006a6e38)(param_1,"%s (%s)",pcVar3,auStack_7c);
        uVar2 = (uint)(0 < iVar13);
        break;
      case 0x17:
        uVar2 = (*(code *)PTR_ASN1_UTCTIME_print_006a97e4)(param_1,puVar16);
        break;
      case 0x18:
        uVar2 = (*(code *)PTR_ASN1_GENERALIZEDTIME_print_006a7e20)(param_1,puVar16);
        break;
      case 0xfffffffd:
      case 0x10:
      case 0x11:
        iVar13 = (*(code *)PTR_BIO_puts_006a6f58)(param_1,"\n");
        if (iVar13 < 1) goto LAB_00608fac;
        iVar13 = (*(code *)PTR_ASN1_parse_dump_006a74b8)(param_1,puVar16[2],*puVar16,param_3,0);
        if (iVar13 < 1) goto LAB_00608fac;
        bVar6 = true;
        goto LAB_00608fb0;
      default:
        uVar2 = (*(code *)PTR_ASN1_STRING_print_ex_006a9444)(param_1,puVar16,param_5[4]);
      }
      bVar6 = false;
      if (uVar2 != 0) goto LAB_00609adc;
      goto LAB_00608fb0;
    }
    iVar13 = (*(code *)PTR_BIO_puts_006a6f58)(param_1,"NULL\n");
    if (iVar13 < 1) goto LAB_00608fac;
    bVar6 = true;
    goto LAB_00608fb0;
  case '\x01':
  case '\x06':
    iVar8 = asn1_print_fsname_isra_4(param_1,param_3,uVar9,iVar13,param_5);
    if (iVar8 == 0) goto LAB_00608fac;
    if ((uVar9 != 0) || (iVar13 != 0)) {
      if ((*param_5 & 2) == 0) {
        iVar13 = (*(code *)PTR_BIO_puts_006a6f58)(param_1,"\n");
        if (iVar13 < 1) {
          bVar6 = false;
          goto LAB_00608fb0;
        }
      }
      else {
        iVar13 = (*(code *)PTR_BIO_puts_006a6f58)(param_1,&DAT_0067985c);
        if (iVar13 < 1) goto LAB_00608fac;
      }
    }
    if (pcVar12 != (code *)0x0) {
      iVar13 = (*pcVar12)(8,param_2,unaff_s7,&local_88);
      if (iVar13 == 0) goto LAB_00608fac;
      bVar6 = true;
      if (iVar13 == 2) goto LAB_00608fb0;
    }
    iVar8 = 0;
    iVar13 = *(int *)(unaff_s7 + 8);
    if (*(int *)(unaff_s7 + 0xc) < 1) {
      uVar2 = *param_5;
    }
    else {
      do {
        iVar15 = (*(code *)PTR_asn1_do_adb_006a8d84)(param_2,iVar13,1);
        if (iVar15 == 0) {
          bVar6 = false;
          goto LAB_00608fb0;
        }
        uVar5 = (*(code *)PTR_asn1_get_field_ptr_006a8d70)(param_2,iVar15);
        iVar15 = asn1_template_print_ctx(param_1,uVar5,param_3 + 2,iVar15,param_5);
        if (iVar15 == 0) goto LAB_00608fac;
        iVar8 = iVar8 + 1;
        iVar13 = iVar13 + 0x14;
      } while (iVar8 < *(int *)(unaff_s7 + 0xc));
      uVar2 = *param_5;
    }
    if (((uVar2 & 2) != 0) &&
       (iVar13 = (*(code *)PTR_BIO_printf_006a6e38)(param_1,"%*s}\n",param_3,""), iVar13 < 0)) {
      bVar6 = false;
      goto LAB_00608fb0;
    }
    if (pcVar12 != (code *)0x0) {
      iVar13 = (*pcVar12)(9,param_2,unaff_s7,&local_88);
      bVar6 = iVar13 != 0;
      goto LAB_00608fb0;
    }
    break;
  case '\x02':
    iVar13 = (*(code *)PTR_asn1_get_choice_selector_006a8d7c)(param_2,unaff_s7);
    if ((iVar13 < 0) || (*(int *)(unaff_s7 + 0xc) <= iVar13)) {
      iVar13 = (*(code *)PTR_BIO_printf_006a6e38)(param_1,"ERROR: selector [%d] invalid\n",iVar13);
      bVar6 = 0 < iVar13;
    }
    else {
      iVar13 = *(int *)(unaff_s7 + 8) + iVar13 * 0x14;
      uVar5 = (*(code *)PTR_asn1_get_field_ptr_006a8d70)(param_2,iVar13);
      iVar13 = asn1_template_print_ctx(param_1,uVar5,param_3,iVar13,param_5);
      bVar6 = iVar13 != 0;
    }
    goto LAB_00608fb0;
  default:
    (*(code *)PTR_BIO_printf_006a6e38)(param_1,"Unprocessed type %d\n");
    bVar6 = false;
    goto LAB_00608fb0;
  case '\x04':
    iVar8 = asn1_print_fsname_isra_4(param_1,param_3,uVar9,iVar13,param_5);
    if (iVar8 == 0) goto LAB_00608fac;
    if ((*(int *)(unaff_s7 + 0x10) == 0) ||
       (pcVar12 = *(code **)(*(int *)(unaff_s7 + 0x10) + 0x18), pcVar12 == (code *)0x0)) {
      if (iVar13 != 0) {
        iVar13 = (*(code *)PTR_BIO_printf_006a6e38)(param_1,":EXTERNAL TYPE %s\n",iVar13);
        bVar6 = 0 < iVar13;
        goto LAB_00608fb0;
      }
    }
    else {
      iVar13 = (*pcVar12)(param_1,param_2,param_3,"",param_5);
      if (iVar13 == 0) goto LAB_00608fac;
      if (iVar13 == 2) {
        iVar13 = (*(code *)PTR_BIO_puts_006a6f58)(param_1,"\n");
        bVar6 = 0 < iVar13;
        goto LAB_00608fb0;
      }
    }
  }
LAB_00608f4c:
  bVar6 = true;
LAB_00608fb0:
  while (local_2c != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_00609db4:
    puVar16 = *(uint **)(unaff_s7 + 0x14);
LAB_00609ca8:
    if (puVar16 == (uint *)0xffffffff) {
      pcVar3 = "BOOL ABSENT";
    }
    else if (puVar16 == (uint *)0x0) {
      pcVar3 = "FALSE";
    }
    else {
      pcVar3 = "TRUE";
    }
    iVar13 = (*(code *)PTR_BIO_puts_006a6f58)(param_1,pcVar3);
    if (iVar13 < 1) {
      bVar6 = false;
    }
    else {
LAB_00609adc:
      iVar13 = (*(code *)PTR_BIO_puts_006a6f58)(param_1,"\n");
      if (iVar13 < 1) {
LAB_00608fac:
        bVar6 = false;
      }
      else {
        bVar6 = true;
      }
    }
  }
  return bVar6;
}

