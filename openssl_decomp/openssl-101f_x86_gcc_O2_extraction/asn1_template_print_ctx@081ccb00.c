
/* WARNING: Type propagation algorithm not settling */

bool asn1_template_print_ctx(BIO *param_1,char ***param_2,int param_3,uint *param_4,uint *param_5)

{
  uint uVar1;
  _STACK *p_Var2;
  ASN1_ITEM *pAVar3;
  code *pcVar4;
  byte bVar5;
  int *piVar6;
  ASN1_INTEGER *a;
  char cVar7;
  char *pcVar8;
  int iVar9;
  int iVar10;
  ASN1_TEMPLATE *pAVar11;
  ASN1_VALUE **ppAVar12;
  ASN1_OBJECT *pAVar13;
  uint uVar14;
  char **ppcVar15;
  void *pvVar16;
  int iVar17;
  int iVar18;
  ASN1_TEMPLATE *pAVar19;
  int in_GS_OFFSET;
  bool bVar20;
  char *format;
  code *local_a8;
  code *local_a4;
  ASN1_INTEGER *local_80;
  BIO *local_7c;
  int local_78;
  uint *local_74;
  char local_70 [80];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  uVar14 = *param_4;
  uVar1 = *param_5;
  iVar18 = 0;
  if ((uVar1 & 0x80) != 0) {
    iVar18 = *(int *)(param_4[4] + 0x18);
  }
  if ((uVar1 & 0x40) == 0) {
    pcVar8 = (char *)param_4[3];
    if ((uVar14 & 6) == 0) goto LAB_081ccf13;
    if (pcVar8 != (char *)0x0) {
      if ((uVar1 & 4) == 0) {
        format = "%*s%s:\n";
      }
      else {
        pcVar8 = "SEQUENCE";
        if ((uVar14 & 2) != 0) {
          pcVar8 = "SET";
        }
        format = "%*s%s OF %s {\n";
      }
      iVar18 = BIO_printf(param_1,format,param_3,&DAT_081ec74a,pcVar8);
      if (0 < iVar18) goto LAB_081ccbab;
      goto LAB_081ccd08;
    }
LAB_081ccbab:
    p_Var2 = (_STACK *)*param_2;
    iVar18 = param_3 + 2;
    for (iVar17 = 0; iVar9 = sk_num(p_Var2), iVar17 < iVar9; iVar17 = iVar17 + 1) {
      if ((0 < iVar17) && (iVar9 = BIO_puts(param_1,"\n"), iVar9 < 1)) goto LAB_081ccd08;
      local_80 = (ASN1_INTEGER *)sk_value(p_Var2,iVar17);
      pAVar3 = (ASN1_ITEM *)param_4[4];
      pvVar16 = pAVar3->funcs;
      if (pvVar16 == (void *)0x0) {
        local_a4 = (code *)0x0;
      }
      else {
        local_a4 = *(code **)((int)pvVar16 + 0x10);
        if (local_a4 != (code *)0x0) {
          local_74 = param_5;
          local_7c = param_1;
          local_78 = iVar18;
        }
      }
      if (local_80 == (ASN1_INTEGER *)0x0) {
        if ((*(byte *)param_5 & 1) == 0) goto LAB_081cccb8;
        pcVar8 = "<ABSENT>\n";
LAB_081cce95:
        iVar9 = BIO_puts(param_1,pcVar8);
joined_r0x081ccd62:
        if (iVar9 < 1) goto LAB_081ccd08;
      }
      else {
        cVar7 = pAVar3->itype;
        switch(cVar7) {
        case '\0':
          if (pAVar3->templates != (ASN1_TEMPLATE *)0x0) {
            iVar9 = asn1_template_print_ctx(param_1,&local_80,iVar18,pAVar3->templates,param_5);
            if (iVar9 == 0) goto LAB_081ccd08;
            pvVar16 = pAVar3->funcs;
          }
LAB_081ccc62:
          iVar9 = asn1_print_fsname_isra_4(0,param_5);
          if (iVar9 == 0) goto LAB_081ccd08;
          if ((pvVar16 == (void *)0x0) || (*(code **)((int)pvVar16 + 0x1c) == (code *)0x0)) {
            if (pAVar3->itype == '\x05') {
              uVar14 = local_80->type & 0xfffffeff;
            }
            else {
              uVar14 = pAVar3->utype;
            }
            if (uVar14 == 0xfffffffc) {
              piVar6 = &local_80->type;
              uVar14 = local_80->length;
              bVar5 = *(byte *)param_5 & 0x10;
              a = (ASN1_INTEGER *)local_80->type;
            }
            else {
              piVar6 = (int *)&local_80;
              bVar5 = *(byte *)param_5 & 8;
              a = local_80;
            }
            if (bVar5 == 0) {
              pcVar8 = ASN1_tag2str(uVar14);
              if (uVar14 == 5) goto LAB_081ccef7;
              if ((pcVar8 != (char *)0x0) &&
                 ((iVar9 = BIO_puts(param_1,pcVar8), iVar9 < 1 ||
                  (iVar9 = BIO_puts(param_1,":"), iVar9 < 1)))) goto LAB_081ccd08;
            }
            else if (uVar14 == 5) {
LAB_081ccef7:
              pcVar8 = "NULL\n";
              goto LAB_081cce95;
            }
            switch(uVar14) {
            case 1:
              pAVar13 = (ASN1_OBJECT *)*piVar6;
              if ((pAVar13 == (ASN1_OBJECT *)0xffffffff) &&
                 (pAVar13 = (ASN1_OBJECT *)pAVar3->size, pAVar13 == (ASN1_OBJECT *)0xffffffff)) {
                pcVar8 = "BOOL ABSENT";
              }
              else {
                pcVar8 = "FALSE";
                if (pAVar13 != (ASN1_OBJECT *)0x0) {
                  pcVar8 = "TRUE";
                }
              }
              iVar9 = BIO_puts(param_1,pcVar8);
              if (0 < iVar9) goto LAB_081cccef;
              goto LAB_081ccd08;
            case 2:
            case 10:
              pcVar8 = i2s_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,a);
              iVar9 = BIO_puts(param_1,pcVar8);
              uVar14 = (uint)(0 < iVar9);
              CRYPTO_free(pcVar8);
              break;
            case 3:
            case 4:
              if (a->type == 3) {
                iVar9 = BIO_printf(param_1," (%ld unused bits)\n",a->flags & 7);
              }
              else {
                iVar9 = BIO_puts(param_1,"\n");
              }
              if ((0 < iVar9) &&
                 ((a->length < 1 ||
                  (iVar9 = BIO_dump_indent(param_1,(char *)a->data,a->length,param_3 + 4), 0 < iVar9
                  )))) goto LAB_081cccb8;
              goto LAB_081ccd08;
            case 6:
              pAVar13 = (ASN1_OBJECT *)*piVar6;
              iVar9 = OBJ_obj2nid(pAVar13);
              pcVar8 = OBJ_nid2ln(iVar9);
              if (pcVar8 == (char *)0x0) {
                pcVar8 = "";
              }
              OBJ_obj2txt(local_70,0x50,pAVar13,1);
              iVar9 = BIO_printf(param_1,"%s (%s)",pcVar8,local_70);
              uVar14 = (uint)(0 < iVar9);
              break;
            case 0x17:
              uVar14 = ASN1_UTCTIME_print(param_1,a);
              break;
            case 0x18:
              uVar14 = ASN1_GENERALIZEDTIME_print(param_1,a);
              break;
            case 0xfffffffd:
            case 0x10:
            case 0x11:
              iVar9 = BIO_puts(param_1,"\n");
              if (0 < iVar9) {
                iVar9 = ASN1_parse_dump(param_1,a->data,a->length,iVar18,0);
                goto joined_r0x081ccd62;
              }
              goto LAB_081ccd08;
            default:
              uVar14 = ASN1_STRING_print_ex(param_1,a,param_5[4]);
            }
            if (uVar14 != 0) {
LAB_081cccef:
              iVar9 = BIO_puts(param_1,"\n");
              goto joined_r0x081ccd62;
            }
            goto LAB_081ccd08;
          }
          iVar9 = (**(code **)((int)pvVar16 + 0x1c))(param_1,&local_80,pAVar3,iVar18,param_5);
joined_r0x081cd071:
          if (iVar9 == 0) goto LAB_081ccd08;
          break;
        case '\x01':
        case '\x06':
          if (local_a4 != (code *)0x0) {
            iVar9 = (*local_a4)(8,&local_80,pAVar3,&local_7c);
            if (iVar9 == 0) goto LAB_081ccd08;
            if (iVar9 == 2) break;
          }
          pAVar19 = pAVar3->templates;
          if (0 < pAVar3->tcount) {
            iVar9 = 0;
            do {
              pAVar11 = asn1_do_adb((ASN1_VALUE **)&local_80,pAVar19,1);
              ppAVar12 = asn1_get_field_ptr((ASN1_VALUE **)&local_80,pAVar11);
              iVar10 = asn1_template_print_ctx(param_1,ppAVar12,param_3 + 4,pAVar11,param_5);
              if (iVar10 == 0) goto LAB_081ccd08;
              iVar9 = iVar9 + 1;
              pAVar19 = pAVar19 + 1;
            } while (iVar9 < pAVar3->tcount);
          }
          if (((*(byte *)param_5 & 2) == 0) ||
             (iVar9 = BIO_printf(param_1,"%*s}\n",iVar18,&DAT_081ec74a), -1 < iVar9)) {
            if (local_a4 == (code *)0x0) break;
            iVar9 = (*local_a4)(9,&local_80,pAVar3,&local_7c);
            goto joined_r0x081cd071;
          }
          goto LAB_081ccd08;
        case '\x02':
          iVar9 = asn1_get_choice_selector((ASN1_VALUE **)&local_80,pAVar3);
          if ((-1 < iVar9) && (iVar9 < pAVar3->tcount)) {
            pAVar19 = pAVar3->templates;
            ppAVar12 = asn1_get_field_ptr((ASN1_VALUE **)&local_80,pAVar19 + iVar9);
            iVar9 = asn1_template_print_ctx(param_1,ppAVar12,iVar18,pAVar19 + iVar9,param_5);
            goto joined_r0x081cd071;
          }
          iVar9 = BIO_printf(param_1,"ERROR: selector [%d] invalid\n",iVar9);
          goto joined_r0x081ccd62;
        default:
          goto switchD_081ccf68_caseD_3;
        case '\x04':
          if ((pvVar16 == (void *)0x0) || (*(code **)((int)pvVar16 + 0x18) == (code *)0x0)) break;
          iVar9 = (**(code **)((int)pvVar16 + 0x18))(param_1,&local_80,iVar18,&DAT_081ec74a,param_5)
          ;
          if (iVar9 != 0) {
            if (iVar9 != 2) break;
            goto LAB_081cccef;
          }
          goto LAB_081ccd08;
        case '\x05':
          goto LAB_081ccc62;
        }
      }
LAB_081cccb8:
    }
    if ((iVar17 == 0) &&
       (iVar18 = BIO_printf(param_1,"%*s<EMPTY>\n",param_3 + 2,&DAT_081ec74a), iVar18 < 1))
    goto LAB_081ccd08;
    if ((*(byte *)param_5 & 2) != 0) {
      pcVar8 = "%*s}\n";
      iVar18 = param_3;
      goto LAB_081cd0e1;
    }
    goto LAB_081cd08f;
  }
  if ((uVar14 & 6) != 0) goto LAB_081ccbab;
  pcVar8 = (char *)0x0;
LAB_081ccf13:
  pAVar3 = (ASN1_ITEM *)param_4[4];
  pvVar16 = pAVar3->funcs;
  if (pvVar16 == (void *)0x0) {
    local_a8 = (code *)0x0;
  }
  else {
    local_a8 = *(code **)((int)pvVar16 + 0x10);
    if (local_a8 != (code *)0x0) {
      local_7c = param_1;
      local_78 = param_3;
      local_74 = param_5;
    }
  }
  if ((_STACK *)*param_2 == (_STACK *)0x0) {
    if ((uVar1 & 1) != 0) {
      iVar18 = asn1_print_fsname_isra_4(iVar18,param_5);
      if (iVar18 != 0) {
        pcVar8 = "<ABSENT>\n";
LAB_081cd290:
        iVar18 = BIO_puts(param_1,pcVar8);
        bVar20 = 0 < iVar18;
        goto LAB_081ccd0a;
      }
      goto LAB_081ccd08;
    }
    goto LAB_081cd08f;
  }
  cVar7 = pAVar3->itype;
  switch(cVar7) {
  case '\0':
    if (pAVar3->templates != (ASN1_TEMPLATE *)0x0) {
      iVar17 = asn1_template_print_ctx(param_1,param_2,param_3,pAVar3->templates,param_5);
      if (iVar17 == 0) break;
      pvVar16 = pAVar3->funcs;
    }
  case '\x05':
    local_a8 = (code *)pvVar16;
    iVar18 = asn1_print_fsname_isra_4(iVar18,param_5);
    if (iVar18 == 0) break;
    if ((local_a8 != (code *)0x0) && (*(code **)((int)local_a8 + 0x1c) != (code *)0x0)) {
      iVar18 = (**(code **)((int)local_a8 + 0x1c))(param_1,param_2,pAVar3,param_3,param_5);
      bVar20 = iVar18 != 0;
      goto LAB_081ccd0a;
    }
    p_Var2 = (_STACK *)*param_2;
    if (pAVar3->itype == '\x05') {
      uVar14 = (uint)p_Var2->data & 0xfffffeff;
    }
    else {
      uVar14 = pAVar3->utype;
    }
    if (uVar14 == 0xfffffffc) {
      uVar14 = p_Var2->num;
      param_2 = &p_Var2->data;
      p_Var2 = (_STACK *)p_Var2->data;
      bVar5 = *(byte *)param_5 & 0x10;
    }
    else {
      bVar5 = *(byte *)param_5 & 8;
    }
    if (bVar5 == 0) {
      pcVar8 = ASN1_tag2str(uVar14);
      if (uVar14 == 5) goto LAB_081cd582;
      if ((pcVar8 != (char *)0x0) &&
         ((iVar18 = BIO_puts(param_1,pcVar8), iVar18 < 1 ||
          (iVar18 = BIO_puts(param_1,":"), iVar18 < 1)))) break;
LAB_081cd61f:
      switch(uVar14) {
      case 1:
        ppcVar15 = *param_2;
        if (ppcVar15 == (char **)0xffffffff) {
          ppcVar15 = (char **)pAVar3->size;
          pcVar8 = "BOOL ABSENT";
          if (ppcVar15 != (char **)0xffffffff) goto LAB_081cd74a;
        }
        else {
LAB_081cd74a:
          pcVar8 = "FALSE";
          if (ppcVar15 != (char **)0x0) {
            pcVar8 = "TRUE";
          }
        }
        iVar18 = BIO_puts(param_1,pcVar8);
        if (iVar18 < 1) goto LAB_081ccd08;
        goto LAB_081cd647;
      case 2:
      case 10:
        pcVar8 = i2s_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,(ASN1_INTEGER *)p_Var2);
        iVar18 = BIO_puts(param_1,pcVar8);
        uVar14 = (uint)(0 < iVar18);
        CRYPTO_free(pcVar8);
        break;
      case 3:
      case 4:
        if (p_Var2->data == (char **)0x3) {
          iVar18 = BIO_printf(param_1," (%ld unused bits)\n",p_Var2->num_alloc & 7);
        }
        else {
          iVar18 = BIO_puts(param_1,"\n");
        }
        if (iVar18 < 1) goto LAB_081ccd08;
        if (p_Var2->num < 1) goto LAB_081cd08f;
        iVar18 = BIO_dump_indent(param_1,(char *)p_Var2->sorted,p_Var2->num,param_3 + 2);
        goto joined_r0x081cd6f6;
      case 6:
        pAVar13 = (ASN1_OBJECT *)*param_2;
        iVar18 = OBJ_obj2nid(pAVar13);
        pcVar8 = OBJ_nid2ln(iVar18);
        if (pcVar8 == (char *)0x0) {
          pcVar8 = "";
        }
        OBJ_obj2txt(local_70,0x50,pAVar13,1);
        iVar18 = BIO_printf(param_1,"%s (%s)",pcVar8,local_70);
        uVar14 = (uint)(0 < iVar18);
        break;
      case 0x17:
        uVar14 = ASN1_UTCTIME_print(param_1,(ASN1_UTCTIME *)p_Var2);
        break;
      case 0x18:
        uVar14 = ASN1_GENERALIZEDTIME_print(param_1,(ASN1_GENERALIZEDTIME *)p_Var2);
        break;
      case 0xfffffffd:
      case 0x10:
      case 0x11:
        iVar18 = BIO_puts(param_1,"\n");
        if ((iVar18 < 1) ||
           (iVar18 = ASN1_parse_dump(param_1,(uchar *)p_Var2->sorted,p_Var2->num,param_3,0),
           iVar18 < 1)) goto LAB_081ccd08;
        goto LAB_081cd08f;
      default:
        uVar14 = ASN1_STRING_print_ex(param_1,(ASN1_STRING *)p_Var2,param_5[4]);
      }
      if (uVar14 == 0) break;
LAB_081cd647:
      pcVar8 = "\n";
    }
    else {
      if (uVar14 != 5) goto LAB_081cd61f;
LAB_081cd582:
      pcVar8 = "NULL\n";
    }
    iVar18 = BIO_puts(param_1,pcVar8);
joined_r0x081cd6f6:
    if (0 < iVar18) {
LAB_081cd08f:
      bVar20 = true;
      goto LAB_081ccd0a;
    }
    break;
  case '\x01':
  case '\x06':
    iVar17 = asn1_print_fsname_isra_4(iVar18,param_5);
    if (iVar17 != 0) {
      if ((pcVar8 != (char *)0x0) || (iVar18 != 0)) {
        if ((*(byte *)param_5 & 2) == 0) {
          pcVar8 = "\n";
        }
        else {
          pcVar8 = " {\n";
        }
        iVar18 = BIO_puts(param_1,pcVar8);
        if (iVar18 < 1) break;
      }
      if (local_a8 != (code *)0x0) {
        iVar18 = (*local_a8)(8,param_2,pAVar3,&local_7c);
        if (iVar18 == 0) break;
        if (iVar18 == 2) goto LAB_081cd08f;
      }
      pAVar19 = pAVar3->templates;
      if (0 < pAVar3->tcount) {
        iVar18 = 0;
        do {
          pAVar11 = asn1_do_adb((ASN1_VALUE **)param_2,pAVar19,1);
          ppAVar12 = asn1_get_field_ptr((ASN1_VALUE **)param_2,pAVar11);
          iVar17 = asn1_template_print_ctx(param_1,ppAVar12,param_3 + 2,pAVar11,param_5);
          if (iVar17 == 0) goto LAB_081ccd08;
          iVar18 = iVar18 + 1;
          pAVar19 = pAVar19 + 1;
        } while (iVar18 < pAVar3->tcount);
      }
      if (((*(byte *)param_5 & 2) == 0) ||
         (iVar18 = BIO_printf(param_1,"%*s}\n",param_3,&DAT_081ec74a), -1 < iVar18)) {
        if (local_a8 != (code *)0x0) {
          iVar18 = (*local_a8)(9,param_2,pAVar3,&local_7c);
          bVar20 = iVar18 != 0;
          goto LAB_081ccd0a;
        }
        goto LAB_081cd08f;
      }
    }
    break;
  case '\x02':
    iVar18 = asn1_get_choice_selector((ASN1_VALUE **)param_2,pAVar3);
    if ((-1 < iVar18) && (iVar18 < pAVar3->tcount)) {
      pAVar19 = pAVar3->templates;
      ppAVar12 = asn1_get_field_ptr((ASN1_VALUE **)param_2,pAVar19 + iVar18);
      iVar18 = asn1_template_print_ctx(param_1,ppAVar12,param_3,pAVar19 + iVar18,param_5);
      bVar20 = iVar18 != 0;
      goto LAB_081ccd0a;
    }
    pcVar8 = "ERROR: selector [%d] invalid\n";
LAB_081cd0e1:
    iVar18 = BIO_printf(param_1,pcVar8,iVar18);
    bVar20 = 0 < iVar18;
    goto LAB_081ccd0a;
  default:
switchD_081ccf68_caseD_3:
    BIO_printf(param_1,"Unprocessed type %d\n",(int)cVar7);
    break;
  case '\x04':
    iVar17 = asn1_print_fsname_isra_4(iVar18,param_5);
    if (iVar17 != 0) {
      if ((pAVar3->funcs == (void *)0x0) ||
         (pcVar4 = *(code **)((int)pAVar3->funcs + 0x18), pcVar4 == (code *)0x0)) {
        if (iVar18 != 0) {
          pcVar8 = ":EXTERNAL TYPE %s\n";
          goto LAB_081cd0e1;
        }
      }
      else {
        iVar18 = (*pcVar4)(param_1,param_2,param_3,&DAT_081ec74a,param_5);
        if (iVar18 == 0) break;
        if (iVar18 == 2) {
          pcVar8 = "\n";
          goto LAB_081cd290;
        }
      }
      goto LAB_081cd08f;
    }
  }
LAB_081ccd08:
  bVar20 = false;
LAB_081ccd0a:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return bVar20;
}

