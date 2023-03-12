
/* WARNING: Type propagation algorithm not settling */

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
  code *pcVar9;
  code *pcVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  ASN1_ITEM *pAVar14;
  int iVar15;
  ASN1_TEMPLATE *pAVar16;
  ASN1_GENERALIZEDTIME *a;
  ASN1_OBJECT *pAVar17;
  ASN1_INTEGER *a_00;
  uint uVar18;
  _STACK *p_Var19;
  int *local_b4;
  char *local_a4;
  ASN1_INTEGER *local_8c;
  BIO *local_88;
  int local_84;
  uint *local_80;
  char acStack_7c [80];
  int local_2c;
  
  uVar13 = *param_5;
  uVar18 = uVar13 & 0x80;
  piVar8 = param_2;
  if (uVar18 != 0) {
    piVar8 = (int *)param_4[4];
  }
  uVar11 = *param_4;
  local_2c = __TMC_END__;
  if (uVar18 != 0) {
    uVar18 = piVar8[6];
  }
  if (-1 < (int)(uVar13 << 0x19)) {
    uVar12 = param_4[3];
    if ((uVar11 & 6) == 0) goto LAB_0010f06e;
    if (uVar12 == 0) {
LAB_0010ed6c:
      p_Var19 = (_STACK *)*param_2;
      local_a4 = "";
      iVar15 = 0;
      iVar1 = sk_num(p_Var19);
      if (0 < iVar1) {
LAB_0010ed86:
        if ((0 < iVar15) && (iVar1 = BIO_puts(param_1,"\n"), iVar1 < 1)) goto LAB_0010ef6c;
        local_8c = (ASN1_INTEGER *)sk_value(p_Var19,iVar15);
        pAVar14 = (ASN1_ITEM *)param_4[4];
        pcVar9 = (code *)pAVar14->funcs;
        iVar1 = param_3 + 2;
        local_b4 = (int *)pcVar9;
        if ((pcVar9 != (code *)0x0) && (local_b4 = *(int **)(pcVar9 + 0x10), local_b4 != (int *)0x0)
           ) {
          local_80 = param_5;
          local_88 = param_1;
          local_84 = iVar1;
        }
        if (local_8c == (ASN1_INTEGER *)0x0) {
          if (-1 < (int)(*param_5 << 0x1f)) goto LAB_0010ee1e;
          iVar1 = BIO_puts(param_1,"<ABSENT>\n");
          goto joined_r0x0010ef9a;
        }
        switch(pAVar14->itype) {
        case '\0':
          goto switchD_0010edd8_caseD_0;
        case '\x01':
        case '\x06':
          if (local_b4 != (int *)0x0) {
            iVar2 = (*(code *)local_b4)(8,&local_8c,pAVar14,&local_88);
            if (iVar2 == 0) goto LAB_0010ef6c;
            if (iVar2 == 2) goto LAB_0010ee1e;
          }
          pAVar16 = pAVar14->templates;
          if (0 < pAVar14->tcount) {
            iVar2 = 0;
            do {
              pAVar4 = asn1_do_adb((ASN1_VALUE **)&local_8c,pAVar16,1);
              ppAVar5 = asn1_get_field_ptr((ASN1_VALUE **)&local_8c,pAVar4);
              iVar3 = asn1_template_print_ctx(param_1,ppAVar5,param_3 + 4,pAVar4,param_5);
              if (iVar3 == 0) goto LAB_0010ef6c;
              iVar2 = iVar2 + 1;
              pAVar16 = pAVar16 + 1;
            } while (iVar2 < pAVar14->tcount);
          }
          if ((-1 < (int)(*param_5 << 0x1e)) ||
             (iVar1 = BIO_printf(param_1,"%*s}\n",iVar1,""), -1 < iVar1)) {
            if (local_b4 == (int *)0x0) goto LAB_0010ee1e;
            iVar1 = (*(code *)local_b4)(9,&local_8c,pAVar14,&local_88);
            goto joined_r0x0010f0d2;
          }
          goto LAB_0010ef6c;
        case '\x02':
          iVar2 = asn1_get_choice_selector((ASN1_VALUE **)&local_8c,pAVar14);
          if ((-1 < iVar2) && (iVar2 < pAVar14->tcount)) {
            pAVar16 = pAVar14->templates;
            ppAVar5 = asn1_get_field_ptr((ASN1_VALUE **)&local_8c,pAVar16 + iVar2);
            iVar1 = asn1_template_print_ctx(param_1,ppAVar5,iVar1,pAVar16 + iVar2,param_5);
            goto joined_r0x0010f0d2;
          }
          iVar1 = BIO_printf(param_1,"ERROR: selector [%d] invalid\n");
          goto joined_r0x0010eea2;
        default:
          BIO_printf(param_1,"Unprocessed type %d\n");
          goto LAB_0010ef6c;
        case '\x04':
          if ((pcVar9 == (code *)0x0) || (*(code **)(pcVar9 + 0x18) == (code *)0x0))
          goto LAB_0010ee1e;
          iVar1 = (**(code **)(pcVar9 + 0x18))(param_1,&local_8c,iVar1,"",param_5);
          if (iVar1 != 0) {
            if (iVar1 != 2) goto LAB_0010ee1e;
            goto LAB_0010ee66;
          }
          goto LAB_0010ef6c;
        case '\x05':
          goto LAB_0010ede6;
        }
      }
LAB_0010ee2a:
      if ((iVar15 == 0) && (iVar1 = BIO_printf(param_1,"%*s<EMPTY>\n",param_3 + 2,""), iVar1 < 1))
      goto LAB_0010ef6c;
      if ((int)(*param_5 << 0x1e) < 0) {
        iVar1 = BIO_printf(param_1,"%*s}\n",param_3,"");
        uVar13 = (uint)(0 < iVar1);
        goto LAB_0010ef6e;
      }
      goto LAB_0010ee3a;
    }
    if ((int)(uVar13 << 0x1d) < 0) {
      pcVar7 = "SET";
      if ((uVar11 & 2) == 0) {
        pcVar7 = "SEQUENCE";
      }
      iVar1 = BIO_printf(param_1,"%*s%s OF %s {\n",param_3,"",pcVar7,uVar12);
    }
    else {
      iVar1 = BIO_printf(param_1,"%*s%s:\n",param_3,"",uVar12);
    }
    if (0 < iVar1) goto LAB_0010ed6c;
    goto LAB_0010ef6c;
  }
  uVar12 = uVar11 & 6;
  if (uVar12 != 0) goto LAB_0010ed6c;
LAB_0010f06e:
  pAVar14 = (ASN1_ITEM *)param_4[4];
  pcVar10 = (code *)pAVar14->funcs;
  pcVar9 = pcVar10;
  if ((pcVar10 != (code *)0x0) && (pcVar9 = *(code **)(pcVar10 + 0x10), pcVar9 != (code *)0x0)) {
    local_80 = param_5;
    local_88 = param_1;
    local_84 = param_3;
  }
  if (*param_2 == 0) {
    if (-1 < (int)(uVar13 << 0x1f)) goto LAB_0010ee3a;
    iVar1 = asn1_print_fsname_isra_4(param_1,param_3,uVar12,uVar18,param_5);
    if (iVar1 != 0) {
      iVar1 = BIO_puts(param_1,"<ABSENT>\n");
      uVar13 = (uint)(0 < iVar1);
      goto LAB_0010ef6e;
    }
    goto LAB_0010ef6c;
  }
  switch(pAVar14->itype) {
  case '\0':
    goto switchD_0010f09c_caseD_0;
  case '\x01':
  case '\x06':
    iVar1 = asn1_print_fsname_isra_4(param_1,param_3,uVar12,uVar18,param_5);
    if (iVar1 != 0) {
      if (uVar18 != 0 || uVar12 != 0) {
        if ((int)(*param_5 << 0x1e) < 0) {
          iVar1 = BIO_puts(param_1,(char *)&PTR_ERR_get_error_line_data_00176568);
        }
        else {
          iVar1 = BIO_puts(param_1,"\n");
        }
        if (iVar1 < 1) goto LAB_0010ef6c;
      }
      if (pcVar9 != (code *)0x0) {
        iVar1 = (*pcVar9)(8,param_2,pAVar14,&local_88);
        if (iVar1 == 0) goto LAB_0010ef6c;
        if (iVar1 == 2) goto LAB_0010ee3a;
      }
      pAVar16 = pAVar14->templates;
      if (0 < pAVar14->tcount) {
        iVar1 = 0;
        do {
          pAVar4 = asn1_do_adb((ASN1_VALUE **)param_2,pAVar16,1);
          ppAVar5 = asn1_get_field_ptr((ASN1_VALUE **)param_2,pAVar4);
          iVar15 = asn1_template_print_ctx(param_1,ppAVar5,param_3 + 2,pAVar4,param_5);
          if (iVar15 == 0) goto LAB_0010ef6c;
          iVar1 = iVar1 + 1;
          pAVar16 = pAVar16 + 1;
        } while (iVar1 < pAVar14->tcount);
      }
      if ((-1 < (int)(*param_5 << 0x1e)) ||
         (iVar1 = BIO_printf(param_1,"%*s}\n",param_3,""), -1 < iVar1)) {
        if (pcVar9 != (code *)0x0) {
          uVar13 = (*pcVar9)(9,param_2,pAVar14,&local_88);
          if (uVar13 != 0) {
            uVar13 = 1;
          }
          goto LAB_0010ef6e;
        }
        goto LAB_0010ee3a;
      }
    }
    goto LAB_0010ef6c;
  case '\x02':
    iVar1 = asn1_get_choice_selector((ASN1_VALUE **)param_2,pAVar14);
    if ((iVar1 < 0) || (pAVar14->tcount <= iVar1)) {
      iVar1 = BIO_printf(param_1,"ERROR: selector [%d] invalid\n");
      uVar13 = (uint)(0 < iVar1);
    }
    else {
      pAVar16 = pAVar14->templates;
      ppAVar5 = asn1_get_field_ptr((ASN1_VALUE **)param_2,pAVar16 + iVar1);
      uVar13 = asn1_template_print_ctx(param_1,ppAVar5,param_3,pAVar16 + iVar1,param_5);
      if (uVar13 != 0) {
        uVar13 = 1;
      }
    }
    goto LAB_0010ef6e;
  default:
    BIO_printf(param_1,"Unprocessed type %d\n");
    uVar13 = 0;
    goto LAB_0010ef6e;
  case '\x04':
    iVar1 = asn1_print_fsname_isra_4(param_1,param_3,uVar12,uVar18,param_5);
    if (iVar1 == 0) goto LAB_0010ef6c;
    if ((pAVar14->funcs == (void *)0x0) ||
       (pcVar9 = *(code **)((int)pAVar14->funcs + 0x18), pcVar9 == (code *)0x0)) {
      if (uVar18 != 0) {
        iVar1 = BIO_printf(param_1,":EXTERNAL TYPE %s\n",uVar18);
        uVar13 = (uint)(0 < iVar1);
        goto LAB_0010ef6e;
      }
    }
    else {
      iVar1 = (*pcVar9)(param_1,param_2,param_3,"",param_5);
      if (iVar1 == 0) goto LAB_0010ef6c;
      if (iVar1 == 2) {
        iVar1 = BIO_puts(param_1,"\n");
        uVar13 = (uint)(0 < iVar1);
        goto LAB_0010ef6e;
      }
    }
    goto LAB_0010ee3a;
  case '\x05':
    goto LAB_0010f15a;
  }
switchD_0010edd8_caseD_0:
  if (pAVar14->templates != (ASN1_TEMPLATE *)0x0) {
    iVar2 = asn1_template_print_ctx(param_1,&local_8c,iVar1,pAVar14->templates,param_5);
    if (iVar2 == 0) goto LAB_0010ef6c;
    pcVar9 = (code *)pAVar14->funcs;
  }
LAB_0010ede6:
  iVar2 = asn1_print_fsname_isra_4(param_1,iVar1,0,0,param_5);
  a_00 = local_8c;
  if (iVar2 == 0) goto LAB_0010ef6c;
  if ((pcVar9 != (code *)0x0) && (*(code **)(pcVar9 + 0x1c) != (code *)0x0)) {
    iVar1 = (**(code **)(pcVar9 + 0x1c))(param_1,&local_8c,pAVar14,iVar1,param_5);
joined_r0x0010f0d2:
    if (iVar1 != 0) goto LAB_0010ee1e;
    goto LAB_0010ef6c;
  }
  if (pAVar14->itype == '\x05') {
    uVar13 = local_8c->type & 0xfffffeff;
  }
  else {
    uVar13 = pAVar14->utype;
  }
  if (uVar13 == 0xfffffffc) {
    local_b4 = &local_8c->type;
    uVar13 = local_8c->length;
    a_00 = (ASN1_INTEGER *)local_8c->type;
    if ((int)(*param_5 << 0x1b) < 0) goto LAB_0010efce;
    pcVar7 = ASN1_tag2str(uVar13);
LAB_0010f1a4:
    if (uVar13 == 5) {
LAB_0010f1f2:
      iVar1 = BIO_puts(param_1,"NULL\n");
      goto joined_r0x0010ef9a;
    }
    if ((pcVar7 != (char *)0x0) &&
       ((iVar2 = BIO_puts(param_1,pcVar7), iVar2 < 1 || (iVar2 = BIO_puts(param_1,":"), iVar2 < 1)))
       ) goto LAB_0010ef6c;
  }
  else {
    local_b4 = (int *)&local_8c;
    if ((int)(*param_5 << 0x1c) < 0) {
      local_b4 = (int *)&local_8c;
      pcVar7 = ASN1_tag2str(uVar13);
      goto LAB_0010f1a4;
    }
LAB_0010efce:
    if (uVar13 == 5) goto LAB_0010f1f2;
  }
  switch(uVar13) {
  case 1:
    pAVar17 = (ASN1_OBJECT *)*local_b4;
    if ((pAVar17 == (ASN1_OBJECT *)0xffffffff) &&
       (pAVar17 = (ASN1_OBJECT *)pAVar14->size, pAVar17 == (ASN1_OBJECT *)0xffffffff)) {
      pcVar7 = "BOOL ABSENT";
    }
    else {
      pcVar7 = "FALSE";
      if (pAVar17 != (ASN1_OBJECT *)0x0) {
        pcVar7 = "TRUE";
      }
    }
    iVar1 = BIO_puts(param_1,pcVar7);
    uVar13 = (uint)(0 < iVar1);
    break;
  case 2:
  case 10:
    pcVar7 = i2s_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,a_00);
    iVar1 = BIO_puts(param_1,pcVar7);
    uVar13 = (uint)(0 < iVar1);
    CRYPTO_free(pcVar7);
    break;
  case 3:
  case 4:
    if (a_00->type == 3) {
      iVar1 = BIO_printf(param_1," (%ld unused bits)\n",a_00->flags & 7);
    }
    else {
      iVar1 = BIO_puts(param_1,"\n");
    }
    if (0 < iVar1) {
      if (a_00->length < 1) goto LAB_0010ee1e;
      iVar1 = BIO_dump_indent(param_1,a_00->data,a_00->length,param_3 + 4);
joined_r0x0010ef9a:
      if (0 < iVar1) goto LAB_0010ee1e;
    }
    goto LAB_0010ef6c;
  case 6:
    pAVar17 = (ASN1_OBJECT *)*local_b4;
    iVar1 = OBJ_obj2nid(pAVar17);
    pcVar6 = OBJ_nid2ln(iVar1);
    pcVar7 = local_a4;
    if (pcVar6 != (char *)0x0) {
      pcVar7 = pcVar6;
    }
    OBJ_obj2txt(acStack_7c,0x50,pAVar17,1);
    iVar1 = BIO_printf(param_1,"%s (%s)",pcVar7,acStack_7c);
    uVar13 = (uint)(0 < iVar1);
    break;
  case 0x17:
    uVar13 = ASN1_UTCTIME_print(param_1,a_00);
    break;
  case 0x18:
    uVar13 = ASN1_GENERALIZEDTIME_print(param_1,a_00);
    break;
  case 0xfffffffd:
  case 0x10:
  case 0x11:
    iVar2 = BIO_puts(param_1,"\n");
    if (0 < iVar2) {
      iVar1 = ASN1_parse_dump(param_1,a_00->data,a_00->length,iVar1,0);
      goto joined_r0x0010ef9a;
    }
    goto LAB_0010ef6c;
  default:
    uVar13 = ASN1_STRING_print_ex(param_1,a_00,param_5[4]);
  }
  if (uVar13 == 0) goto LAB_0010ef6c;
LAB_0010ee66:
  iVar1 = BIO_puts(param_1,"\n");
joined_r0x0010eea2:
  if (iVar1 < 1) goto LAB_0010ef6c;
LAB_0010ee1e:
  iVar15 = iVar15 + 1;
  iVar1 = sk_num(p_Var19);
  if (iVar1 <= iVar15) goto LAB_0010ee2a;
  goto LAB_0010ed86;
switchD_0010f09c_caseD_0:
  if (pAVar14->templates != (ASN1_TEMPLATE *)0x0) {
    iVar1 = asn1_template_print_ctx(param_1,param_2,param_3,pAVar14->templates,param_5);
    if (iVar1 == 0) goto LAB_0010ef6c;
    pcVar10 = (code *)pAVar14->funcs;
  }
LAB_0010f15a:
  iVar1 = asn1_print_fsname_isra_4(param_1,param_3,uVar12,uVar18,param_5);
  if (iVar1 == 0) goto LAB_0010ef6c;
  if ((pcVar10 != (code *)0x0) && (*(code **)(pcVar10 + 0x1c) != (code *)0x0)) {
    iVar1 = (**(code **)(pcVar10 + 0x1c))(param_1,param_2,pAVar14,param_3,param_5);
    if (iVar1 == 0) goto LAB_0010ef6c;
    goto LAB_0010ee3a;
  }
  a = (ASN1_GENERALIZEDTIME *)*param_2;
  if (pAVar14->itype == '\x05') {
    uVar13 = a->type & 0xfffffeff;
  }
  else {
    uVar13 = pAVar14->utype;
  }
  if (uVar13 == 0xfffffffc) {
    iVar1 = *param_5 << 0x1b;
    param_2 = &a->type;
    uVar13 = a->length;
    a = (ASN1_GENERALIZEDTIME *)a->type;
  }
  else {
    iVar1 = *param_5 << 0x1c;
  }
  if (iVar1 < 0) {
    if (uVar13 != 5) goto LAB_0010f542;
LAB_0010f77e:
    iVar1 = BIO_puts(param_1,"NULL\n");
    goto joined_r0x0010f58e;
  }
  pcVar7 = ASN1_tag2str(uVar13);
  if (uVar13 == 5) goto LAB_0010f77e;
  if ((pcVar7 != (char *)0x0) &&
     ((iVar1 = BIO_puts(param_1,pcVar7), iVar1 < 1 || (iVar1 = BIO_puts(param_1,":"), iVar1 < 1))))
  goto LAB_0010ef6c;
LAB_0010f542:
  switch(uVar13) {
  case 1:
    iVar1 = *param_2;
    if ((iVar1 == -1) && (iVar1 = pAVar14->size, iVar1 == -1)) {
      pcVar7 = "BOOL ABSENT";
    }
    else {
      pcVar7 = "FALSE";
      if (iVar1 != 0) {
        pcVar7 = "TRUE";
      }
    }
    iVar1 = BIO_puts(param_1,pcVar7);
    uVar13 = (uint)(0 < iVar1);
    break;
  case 2:
  case 10:
    pcVar7 = i2s_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,a);
    iVar1 = BIO_puts(param_1,pcVar7);
    uVar13 = (uint)(0 < iVar1);
    CRYPTO_free(pcVar7);
    break;
  case 3:
  case 4:
    if (a->type == 3) {
      iVar1 = BIO_printf(param_1," (%ld unused bits)\n",a->flags & 7);
    }
    else {
      iVar1 = BIO_puts(param_1,"\n");
    }
    if (0 < iVar1) {
      if (a->length < 1) goto LAB_0010ee3a;
      iVar1 = BIO_dump_indent(param_1,a->data,a->length,param_3 + 2);
      goto joined_r0x0010f58e;
    }
    goto LAB_0010ef6c;
  case 6:
    pAVar17 = (ASN1_OBJECT *)*param_2;
    iVar1 = OBJ_obj2nid(pAVar17);
    pcVar6 = OBJ_nid2ln(iVar1);
    pcVar7 = "";
    if (pcVar6 != (char *)0x0) {
      pcVar7 = pcVar6;
    }
    OBJ_obj2txt(acStack_7c,0x50,pAVar17,1);
    iVar1 = BIO_printf(param_1,"%s (%s)",pcVar7,acStack_7c);
    uVar13 = (uint)(0 < iVar1);
    break;
  case 0x17:
    uVar13 = ASN1_UTCTIME_print(param_1,a);
    break;
  case 0x18:
    uVar13 = ASN1_GENERALIZEDTIME_print(param_1,a);
    break;
  case 0xfffffffd:
  case 0x10:
  case 0x11:
    iVar1 = BIO_puts(param_1,"\n");
    if (0 < iVar1) {
      iVar1 = ASN1_parse_dump(param_1,a->data,a->length,param_3,0);
      goto joined_r0x0010f58e;
    }
    goto LAB_0010ef6c;
  default:
    uVar13 = ASN1_STRING_print_ex(param_1,a,param_5[4]);
  }
  if (uVar13 != 0) {
    iVar1 = BIO_puts(param_1,"\n");
joined_r0x0010f58e:
    if (0 < iVar1) {
LAB_0010ee3a:
      uVar13 = 1;
      goto LAB_0010ef6e;
    }
  }
LAB_0010ef6c:
  uVar13 = 0;
LAB_0010ef6e:
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar13);
  }
  return;
}

