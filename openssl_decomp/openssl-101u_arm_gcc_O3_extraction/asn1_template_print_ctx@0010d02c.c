
void asn1_template_print_ctx(BIO *param_1,int *param_2,int param_3,uint *param_4,uint *param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  ASN1_TEMPLATE *pAVar4;
  ASN1_VALUE **ppAVar5;
  char *pcVar6;
  char *pcVar7;
  int *piVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  code *pcVar13;
  ASN1_GENERALIZEDTIME *pAVar14;
  ASN1_OBJECT *pAVar15;
  ASN1_TEMPLATE *pAVar16;
  uint uVar17;
  ASN1_ITEM *pAVar18;
  code *pcVar19;
  _STACK *p_Var20;
  code *local_ac;
  char *local_9c;
  ASN1_GENERALIZEDTIME *local_8c;
  BIO *local_88;
  int local_84;
  uint *local_80;
  char acStack_7c [80];
  int local_2c;
  
  uVar11 = *param_5;
  uVar17 = uVar11 & 0x80;
  piVar8 = param_2;
  if (uVar17 != 0) {
    piVar8 = (int *)param_4[4];
  }
  uVar9 = *param_4;
  local_2c = __stack_chk_guard;
  if (uVar17 != 0) {
    uVar17 = piVar8[6];
  }
  if (-1 < (int)(uVar11 << 0x19)) {
    uVar10 = param_4[3];
    if ((uVar9 & 6) == 0) goto LAB_0010d36c;
    if (uVar10 == 0) {
LAB_0010d070:
      p_Var20 = (_STACK *)*param_2;
      local_9c = "";
      iVar12 = 0;
      iVar1 = sk_num(p_Var20);
      if (0 < iVar1) {
        do {
          if ((0 < iVar12) && (iVar1 = BIO_puts(param_1,"\n"), iVar1 < 1)) goto LAB_0010d266;
          local_8c = (ASN1_GENERALIZEDTIME *)sk_value(p_Var20,iVar12);
          pAVar18 = (ASN1_ITEM *)param_4[4];
          iVar1 = param_3 + 2;
          pcVar13 = (code *)pAVar18->funcs;
          local_ac = pcVar13;
          if ((pcVar13 != (code *)0x0) &&
             (local_ac = *(code **)(pcVar13 + 0x10), local_ac != (code *)0x0)) {
            local_80 = param_5;
            local_88 = param_1;
            local_84 = iVar1;
          }
          if (local_8c == (ASN1_GENERALIZEDTIME *)0x0) {
            if (-1 < (int)(*param_5 << 0x1f)) goto LAB_0010d18a;
            iVar1 = BIO_puts(param_1,"<ABSENT>\n");
            goto joined_r0x0010d74c;
          }
          switch(pAVar18->itype) {
          case '\0':
            if (pAVar18->templates == (ASN1_TEMPLATE *)0x0) goto switchD_0010d0e4_caseD_5;
            iVar1 = asn1_template_print_ctx(param_1,&local_8c,iVar1,pAVar18->templates,param_5);
joined_r0x0010d1c4:
            if (iVar1 == 0) goto LAB_0010d266;
            break;
          case '\x01':
          case '\x06':
            if (local_ac != (code *)0x0) {
              iVar2 = (*local_ac)(8,&local_8c,pAVar18,&local_88);
              if (iVar2 == 0) goto LAB_0010d266;
              if (iVar2 == 2) break;
            }
            pAVar16 = pAVar18->templates;
            if (0 < pAVar18->tcount) {
              iVar2 = 0;
              do {
                pAVar4 = asn1_do_adb((ASN1_VALUE **)&local_8c,pAVar16,1);
                if (pAVar4 == (ASN1_TEMPLATE *)0x0) goto LAB_0010d266;
                ppAVar5 = asn1_get_field_ptr((ASN1_VALUE **)&local_8c,pAVar4);
                iVar3 = asn1_template_print_ctx(param_1,ppAVar5,param_3 + 4,pAVar4,param_5);
                if (iVar3 == 0) goto LAB_0010d266;
                iVar2 = iVar2 + 1;
                pAVar16 = pAVar16 + 1;
              } while (iVar2 < pAVar18->tcount);
            }
            if (((int)(*param_5 << 0x1e) < 0) &&
               (iVar1 = BIO_printf(param_1,"%*s}\n",iVar1,""), iVar1 < 0)) goto LAB_0010d266;
            if (local_ac != (code *)0x0) {
              iVar1 = (*local_ac)(9,&local_8c,pAVar18,&local_88);
              goto joined_r0x0010d1c4;
            }
            break;
          case '\x02':
            iVar2 = asn1_get_choice_selector((ASN1_VALUE **)&local_8c,pAVar18);
            if ((-1 < iVar2) && (iVar2 < pAVar18->tcount)) {
              pAVar16 = pAVar18->templates;
              ppAVar5 = asn1_get_field_ptr((ASN1_VALUE **)&local_8c,pAVar16 + iVar2);
              iVar1 = asn1_template_print_ctx(param_1,ppAVar5,iVar1,pAVar16 + iVar2,param_5);
              goto joined_r0x0010d1c4;
            }
            iVar1 = BIO_printf(param_1,"ERROR: selector [%d] invalid\n");
            goto joined_r0x0010d188;
          default:
            BIO_printf(param_1,"Unprocessed type %d\n");
            goto LAB_0010d266;
          case '\x04':
            if ((pcVar13 == (code *)0x0) || (*(code **)(pcVar13 + 0x18) == (code *)0x0)) break;
            iVar1 = (**(code **)(pcVar13 + 0x18))(param_1,&local_8c,iVar1,"",param_5);
            if (iVar1 != 0) {
              if (iVar1 != 2) break;
              goto LAB_0010d14a;
            }
            goto LAB_0010d266;
          case '\x05':
switchD_0010d0e4_caseD_5:
            iVar2 = asn1_print_fsname_isra_4(param_1,iVar1,0,0,param_5);
            pAVar14 = local_8c;
            if (iVar2 == 0) goto LAB_0010d266;
            if ((pcVar13 != (code *)0x0) && (*(code **)(pcVar13 + 0x1c) != (code *)0x0)) {
              iVar1 = (**(code **)(pcVar13 + 0x1c))(param_1,&local_8c,pAVar18,iVar1,param_5);
              if (iVar1 != 0) break;
              goto LAB_0010d266;
            }
            if (pAVar18->itype == '\x05') {
              uVar11 = local_8c->type & 0xfffffeff;
            }
            else {
              uVar11 = pAVar18->utype;
            }
            if (uVar11 == 0xfffffffc) {
              piVar8 = &local_8c->type;
              uVar11 = local_8c->length;
              pAVar14 = (ASN1_GENERALIZEDTIME *)local_8c->type;
              if (-1 < (int)(*param_5 << 0x1b)) {
                pcVar7 = ASN1_tag2str(uVar11);
                goto LAB_0010d4c2;
              }
LAB_0010d318:
              if (uVar11 == 5) {
LAB_0010d4f0:
                iVar1 = BIO_puts(param_1,"NULL\n");
                goto joined_r0x0010d74c;
              }
            }
            else {
              piVar8 = (int *)&local_8c;
              if (-1 < (int)(*param_5 << 0x1c)) goto LAB_0010d318;
              piVar8 = (int *)&local_8c;
              pcVar7 = ASN1_tag2str(uVar11);
LAB_0010d4c2:
              if (uVar11 == 5) goto LAB_0010d4f0;
              if ((pcVar7 != (char *)0x0) &&
                 ((iVar2 = BIO_puts(param_1,pcVar7), iVar2 < 1 ||
                  (iVar2 = BIO_puts(param_1,":"), iVar2 < 1)))) goto LAB_0010d266;
            }
            switch(uVar11) {
            case 1:
              iVar1 = *piVar8;
              if ((iVar1 == -1) && (iVar1 = pAVar18->size, iVar1 == -1)) {
                pcVar7 = "BOOL ABSENT";
              }
              else {
                pcVar7 = "FALSE";
                if (iVar1 != 0) {
                  pcVar7 = "TRUE";
                }
              }
              iVar1 = BIO_puts(param_1,pcVar7);
              uVar11 = (uint)(0 < iVar1);
              break;
            case 2:
            case 10:
              pcVar7 = i2s_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,pAVar14);
              if (pcVar7 == (char *)0x0) goto LAB_0010d266;
              iVar1 = BIO_puts(param_1,pcVar7);
              uVar11 = (uint)(0 < iVar1);
              CRYPTO_free(pcVar7);
              break;
            case 3:
            case 4:
              if (pAVar14->type == 3) {
                iVar1 = BIO_printf(param_1," (%ld unused bits)\n",pAVar14->flags & 7);
              }
              else {
                iVar1 = BIO_puts(param_1,"\n");
              }
              if (0 < iVar1) {
                if (pAVar14->length < 1) goto LAB_0010d18a;
                iVar1 = BIO_dump_indent(param_1,pAVar14->data,pAVar14->length,param_3 + 4);
joined_r0x0010d74c:
                if (0 < iVar1) goto LAB_0010d18a;
              }
              goto LAB_0010d266;
            case 6:
              pAVar15 = (ASN1_OBJECT *)*piVar8;
              iVar1 = OBJ_obj2nid(pAVar15);
              pcVar6 = OBJ_nid2ln(iVar1);
              pcVar7 = local_9c;
              if (pcVar6 != (char *)0x0) {
                pcVar7 = pcVar6;
              }
              OBJ_obj2txt(acStack_7c,0x50,pAVar15,1);
              iVar1 = BIO_printf(param_1,"%s (%s)",pcVar7,acStack_7c);
              uVar11 = (uint)(0 < iVar1);
              break;
            case 0x17:
              uVar11 = ASN1_UTCTIME_print(param_1,pAVar14);
              break;
            case 0x18:
              uVar11 = ASN1_GENERALIZEDTIME_print(param_1,pAVar14);
              break;
            case 0xfffffffd:
            case 0x10:
            case 0x11:
              iVar2 = BIO_puts(param_1,"\n");
              if (0 < iVar2) {
                iVar1 = ASN1_parse_dump(param_1,pAVar14->data,pAVar14->length,iVar1,0);
                goto joined_r0x0010d74c;
              }
              goto LAB_0010d266;
            default:
              uVar11 = ASN1_STRING_print_ex(param_1,pAVar14,param_5[4]);
            }
            if (uVar11 == 0) goto LAB_0010d266;
LAB_0010d14a:
            iVar1 = BIO_puts(param_1,"\n");
joined_r0x0010d188:
            if (iVar1 < 1) goto LAB_0010d266;
          }
LAB_0010d18a:
          iVar12 = iVar12 + 1;
          iVar1 = sk_num(p_Var20);
        } while (iVar12 < iVar1);
      }
      if ((iVar12 == 0) && (iVar1 = BIO_printf(param_1,"%*s<EMPTY>\n",param_3 + 2,""), iVar1 < 1))
      goto LAB_0010d266;
      if ((int)(*param_5 << 0x1e) < 0) {
        iVar1 = BIO_printf(param_1,"%*s}\n",param_3,"");
        uVar11 = (uint)(0 < iVar1);
        goto LAB_0010d268;
      }
      goto LAB_0010d1a8;
    }
    if ((int)(uVar11 << 0x1d) < 0) {
      pcVar7 = "SET";
      if ((uVar9 & 2) == 0) {
        pcVar7 = "SEQUENCE";
      }
      iVar1 = BIO_printf(param_1,"%*s%s OF %s {\n",param_3,"",pcVar7,uVar10);
    }
    else {
      iVar1 = BIO_printf(param_1,"%*s%s:\n",param_3,"",uVar10);
    }
    if (0 < iVar1) goto LAB_0010d070;
    goto LAB_0010d266;
  }
  uVar10 = uVar9 & 6;
  if (uVar10 != 0) goto LAB_0010d070;
LAB_0010d36c:
  pAVar18 = (ASN1_ITEM *)param_4[4];
  pcVar19 = (code *)pAVar18->funcs;
  pcVar13 = pcVar19;
  if ((pcVar19 != (code *)0x0) && (pcVar13 = *(code **)(pcVar19 + 0x10), pcVar13 != (code *)0x0)) {
    local_80 = param_5;
    local_88 = param_1;
    local_84 = param_3;
  }
  if (*param_2 == 0) {
    if (-1 < (int)(uVar11 << 0x1f)) goto LAB_0010d1a8;
    iVar1 = asn1_print_fsname_isra_4(param_1,param_3,uVar10,uVar17,param_5);
    if (iVar1 != 0) {
      iVar1 = BIO_puts(param_1,"<ABSENT>\n");
      uVar11 = (uint)(0 < iVar1);
      goto LAB_0010d268;
    }
    goto LAB_0010d266;
  }
  switch(pAVar18->itype) {
  case '\0':
    break;
  case '\x01':
  case '\x06':
    iVar1 = asn1_print_fsname_isra_4(param_1,param_3,uVar10,uVar17,param_5);
    if (iVar1 != 0) {
      if (uVar17 != 0 || uVar10 != 0) {
        if ((int)(*param_5 << 0x1e) < 0) {
          iVar1 = BIO_puts(param_1," {\n");
        }
        else {
          iVar1 = BIO_puts(param_1,"\n");
        }
        if (iVar1 < 1) goto LAB_0010d266;
      }
      if (pcVar13 != (code *)0x0) {
        iVar1 = (*pcVar13)(8,param_2,pAVar18,&local_88);
        if (iVar1 == 0) goto LAB_0010d266;
        if (iVar1 == 2) goto LAB_0010d1a8;
      }
      pAVar16 = pAVar18->templates;
      if (0 < pAVar18->tcount) {
        iVar1 = 0;
        do {
          pAVar4 = asn1_do_adb((ASN1_VALUE **)param_2,pAVar16,1);
          if (pAVar4 == (ASN1_TEMPLATE *)0x0) goto LAB_0010d266;
          ppAVar5 = asn1_get_field_ptr((ASN1_VALUE **)param_2,pAVar4);
          iVar12 = asn1_template_print_ctx(param_1,ppAVar5,param_3 + 2,pAVar4,param_5);
          if (iVar12 == 0) goto LAB_0010d266;
          iVar1 = iVar1 + 1;
          pAVar16 = pAVar16 + 1;
        } while (iVar1 < pAVar18->tcount);
      }
      if ((-1 < (int)(*param_5 << 0x1e)) ||
         (iVar1 = BIO_printf(param_1,"%*s}\n",param_3,""), -1 < iVar1)) {
        if (pcVar13 != (code *)0x0) {
          uVar11 = (*pcVar13)(9,param_2,pAVar18,&local_88);
          if (uVar11 != 0) {
            uVar11 = 1;
          }
          goto LAB_0010d268;
        }
        goto LAB_0010d1a8;
      }
    }
    goto LAB_0010d266;
  case '\x02':
    iVar1 = asn1_get_choice_selector((ASN1_VALUE **)param_2,pAVar18);
    if ((iVar1 < 0) || (pAVar18->tcount <= iVar1)) {
      iVar1 = BIO_printf(param_1,"ERROR: selector [%d] invalid\n");
      uVar11 = (uint)(0 < iVar1);
    }
    else {
      pAVar16 = pAVar18->templates;
      ppAVar5 = asn1_get_field_ptr((ASN1_VALUE **)param_2,pAVar16 + iVar1);
      uVar11 = asn1_template_print_ctx(param_1,ppAVar5,param_3,pAVar16 + iVar1,param_5);
      if (uVar11 != 0) {
        uVar11 = 1;
      }
    }
    goto LAB_0010d268;
  default:
    BIO_printf(param_1,"Unprocessed type %d\n");
    uVar11 = 0;
    goto LAB_0010d268;
  case '\x04':
    iVar1 = asn1_print_fsname_isra_4(param_1,param_3,uVar10,uVar17,param_5);
    if (iVar1 == 0) goto LAB_0010d266;
    if ((pAVar18->funcs == (void *)0x0) ||
       (pcVar13 = *(code **)((int)pAVar18->funcs + 0x18), pcVar13 == (code *)0x0)) {
      if (uVar17 != 0) {
        iVar1 = BIO_printf(param_1,":EXTERNAL TYPE %s\n",uVar17);
        uVar11 = (uint)(0 < iVar1);
        goto LAB_0010d268;
      }
    }
    else {
      iVar1 = (*pcVar13)(param_1,param_2,param_3,"",param_5);
      if (iVar1 == 0) goto LAB_0010d266;
      if (iVar1 == 2) {
        iVar1 = BIO_puts(param_1,"\n");
        uVar11 = (uint)(0 < iVar1);
        goto LAB_0010d268;
      }
    }
    goto LAB_0010d1a8;
  case '\x05':
    goto switchD_0010d39e_caseD_5;
  }
  if (pAVar18->templates != (ASN1_TEMPLATE *)0x0) {
    uVar11 = asn1_template_print_ctx(param_1,param_2,param_3,pAVar18->templates,param_5);
    if (uVar11 != 0) {
      uVar11 = 1;
    }
    goto LAB_0010d268;
  }
switchD_0010d39e_caseD_5:
  iVar1 = asn1_print_fsname_isra_4(param_1,param_3,uVar10,uVar17,param_5);
  if (iVar1 == 0) goto LAB_0010d266;
  if ((pcVar19 != (code *)0x0) && (*(code **)(pcVar19 + 0x1c) != (code *)0x0)) {
    iVar1 = (**(code **)(pcVar19 + 0x1c))(param_1,param_2,pAVar18,param_3,param_5);
    if (iVar1 == 0) goto LAB_0010d266;
    goto LAB_0010d1a8;
  }
  pAVar14 = (ASN1_GENERALIZEDTIME *)*param_2;
  if (pAVar18->itype == '\x05') {
    uVar11 = pAVar14->type & 0xfffffeff;
  }
  else {
    uVar11 = pAVar18->utype;
  }
  if (uVar11 == 0xfffffffc) {
    iVar1 = *param_5 << 0x1b;
    param_2 = &pAVar14->type;
    uVar11 = pAVar14->length;
    pAVar14 = (ASN1_GENERALIZEDTIME *)pAVar14->type;
  }
  else {
    iVar1 = *param_5 << 0x1c;
  }
  if (iVar1 < 0) {
    if (uVar11 != 5) goto LAB_0010d83a;
LAB_0010da7a:
    iVar1 = BIO_puts(param_1,"NULL\n");
joined_r0x0010da8a:
    if (0 < iVar1) goto LAB_0010d1a8;
    goto LAB_0010d266;
  }
  pcVar7 = ASN1_tag2str(uVar11);
  if (uVar11 == 5) goto LAB_0010da7a;
  if ((pcVar7 != (char *)0x0) &&
     ((iVar1 = BIO_puts(param_1,pcVar7), iVar1 < 1 || (iVar1 = BIO_puts(param_1,":"), iVar1 < 1))))
  goto LAB_0010d266;
LAB_0010d83a:
  switch(uVar11) {
  case 1:
    iVar1 = *param_2;
    if ((iVar1 == -1) && (iVar1 = pAVar18->size, iVar1 == -1)) {
      pcVar7 = "BOOL ABSENT";
    }
    else {
      pcVar7 = "FALSE";
      if (iVar1 != 0) {
        pcVar7 = "TRUE";
      }
    }
    iVar1 = BIO_puts(param_1,pcVar7);
    uVar11 = (uint)(0 < iVar1);
    break;
  case 2:
  case 10:
    pcVar7 = i2s_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,pAVar14);
    if (pcVar7 != (char *)0x0) {
      iVar1 = BIO_puts(param_1,pcVar7);
      uVar11 = (uint)(0 < iVar1);
      CRYPTO_free(pcVar7);
      break;
    }
    goto LAB_0010d266;
  case 3:
  case 4:
    if (pAVar14->type == 3) {
      iVar1 = BIO_printf(param_1," (%ld unused bits)\n",pAVar14->flags & 7);
    }
    else {
      iVar1 = BIO_puts(param_1,"\n");
    }
    if (0 < iVar1) {
      if (pAVar14->length < 1) goto LAB_0010d1a8;
      iVar1 = BIO_dump_indent(param_1,pAVar14->data,pAVar14->length,param_3 + 2);
      goto joined_r0x0010da8a;
    }
    goto LAB_0010d266;
  case 6:
    pAVar15 = (ASN1_OBJECT *)*param_2;
    iVar1 = OBJ_obj2nid(pAVar15);
    pcVar6 = OBJ_nid2ln(iVar1);
    pcVar7 = "";
    if (pcVar6 != (char *)0x0) {
      pcVar7 = pcVar6;
    }
    OBJ_obj2txt(acStack_7c,0x50,pAVar15,1);
    iVar1 = BIO_printf(param_1,"%s (%s)",pcVar7,acStack_7c);
    uVar11 = (uint)(0 < iVar1);
    break;
  case 0x17:
    uVar11 = ASN1_UTCTIME_print(param_1,pAVar14);
    break;
  case 0x18:
    uVar11 = ASN1_GENERALIZEDTIME_print(param_1,pAVar14);
    break;
  case 0xfffffffd:
  case 0x10:
  case 0x11:
    iVar1 = BIO_puts(param_1,"\n");
    if (0 < iVar1) {
      iVar1 = ASN1_parse_dump(param_1,pAVar14->data,pAVar14->length,param_3,0);
      goto joined_r0x0010da8a;
    }
    goto LAB_0010d266;
  default:
    uVar11 = ASN1_STRING_print_ex(param_1,pAVar14,param_5[4]);
  }
  if ((uVar11 == 0) || (iVar1 = BIO_puts(param_1,"\n"), iVar1 < 1)) {
LAB_0010d266:
    uVar11 = 0;
  }
  else {
LAB_0010d1a8:
    uVar11 = 1;
  }
LAB_0010d268:
  if (local_2c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar11);
}

