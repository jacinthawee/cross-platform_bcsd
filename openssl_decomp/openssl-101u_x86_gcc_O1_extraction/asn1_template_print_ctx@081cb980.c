
bool asn1_template_print_ctx(BIO *param_1,char ***param_2,int param_3,uint *param_4,uint *param_5)

{
  uint uVar1;
  _STACK *p_Var2;
  ASN1_ITEM *pAVar3;
  void *pvVar4;
  code *pcVar5;
  byte bVar6;
  int *piVar7;
  ASN1_INTEGER *a;
  char cVar8;
  char *pcVar9;
  int iVar10;
  int iVar11;
  ASN1_INTEGER **ppAVar12;
  ASN1_VALUE **ppAVar13;
  ASN1_TEMPLATE *pAVar14;
  ASN1_OBJECT *pAVar15;
  uint uVar16;
  char **ppcVar17;
  ASN1_TEMPLATE *pAVar18;
  int iVar19;
  int iVar20;
  int in_GS_OFFSET;
  bool bVar21;
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
  uVar16 = *param_4;
  uVar1 = *param_5;
  iVar20 = 0;
  if ((uVar1 & 0x80) != 0) {
    iVar20 = *(int *)(param_4[4] + 0x18);
  }
  if ((uVar1 & 0x40) == 0) {
    pcVar9 = (char *)param_4[3];
    if ((uVar16 & 6) == 0) goto LAB_081cbd3b;
    if (pcVar9 == (char *)0x0) {
LAB_081cba2b:
      p_Var2 = (_STACK *)*param_2;
      iVar20 = param_3 + 2;
      for (iVar19 = 0; iVar10 = sk_num(p_Var2), iVar19 < iVar10; iVar19 = iVar19 + 1) {
        if ((0 < iVar19) && (iVar10 = BIO_puts(param_1,"\n"), iVar10 < 1)) goto LAB_081cbb30;
        local_80 = (ASN1_INTEGER *)sk_value(p_Var2,iVar19);
        pAVar3 = (ASN1_ITEM *)param_4[4];
        pvVar4 = pAVar3->funcs;
        if (pvVar4 == (void *)0x0) {
          local_a4 = (code *)0x0;
        }
        else {
          local_a4 = *(code **)((int)pvVar4 + 0x10);
          if (local_a4 != (code *)0x0) {
            local_74 = param_5;
            local_7c = param_1;
            local_78 = iVar20;
          }
        }
        if (local_80 == (ASN1_INTEGER *)0x0) {
          if ((*(byte *)param_5 & 1) == 0) goto LAB_081cbbd0;
          pcVar9 = "<ABSENT>\n";
          goto LAB_081cbd05;
        }
        cVar8 = pAVar3->itype;
        switch(cVar8) {
        case '\0':
          pAVar18 = pAVar3->templates;
          if (pAVar18 == (ASN1_TEMPLATE *)0x0) goto switchD_081cbad7_caseD_5;
          ppAVar12 = &local_80;
LAB_081cbbfc:
          iVar10 = asn1_template_print_ctx(param_1,ppAVar12,iVar20,pAVar18,param_5);
joined_r0x081cbee3:
          if (iVar10 == 0) goto LAB_081cbb30;
          break;
        case '\x01':
        case '\x06':
          if (local_a4 != (code *)0x0) {
            iVar10 = (*local_a4)(8,&local_80,pAVar3,&local_7c);
            if (iVar10 == 0) goto LAB_081cbb30;
            if (iVar10 == 2) break;
          }
          pAVar18 = pAVar3->templates;
          if (0 < pAVar3->tcount) {
            iVar10 = 0;
            do {
              pAVar14 = asn1_do_adb((ASN1_VALUE **)&local_80,pAVar18,1);
              if (pAVar14 == (ASN1_TEMPLATE *)0x0) goto LAB_081cbb30;
              ppAVar13 = asn1_get_field_ptr((ASN1_VALUE **)&local_80,pAVar14);
              iVar11 = asn1_template_print_ctx(param_1,ppAVar13,param_3 + 4,pAVar14,param_5);
              if (iVar11 == 0) goto LAB_081cbb30;
              iVar10 = iVar10 + 1;
              pAVar18 = pAVar18 + 1;
            } while (iVar10 < pAVar3->tcount);
          }
          if (((*(byte *)param_5 & 2) != 0) &&
             (iVar10 = BIO_printf(param_1,"%*s}\n",iVar20,&DAT_081eca46), iVar10 < 0))
          goto LAB_081cbb30;
          if (local_a4 != (code *)0x0) {
            iVar10 = (*local_a4)(9,&local_80,pAVar3,&local_7c);
            goto joined_r0x081cbee3;
          }
          break;
        case '\x02':
          iVar10 = asn1_get_choice_selector((ASN1_VALUE **)&local_80,pAVar3);
          if ((-1 < iVar10) && (iVar10 < pAVar3->tcount)) {
            pAVar18 = pAVar3->templates + iVar10;
            ppAVar12 = (ASN1_INTEGER **)asn1_get_field_ptr((ASN1_VALUE **)&local_80,pAVar18);
            goto LAB_081cbbfc;
          }
          iVar10 = BIO_printf(param_1,"ERROR: selector [%d] invalid\n",iVar10);
          goto joined_r0x081cbbca;
        default:
          goto switchD_081cbd94_caseD_3;
        case '\x04':
          if ((pvVar4 == (void *)0x0) || (*(code **)((int)pvVar4 + 0x18) == (code *)0x0)) break;
          iVar10 = (**(code **)((int)pvVar4 + 0x18))(param_1,&local_80,iVar20,&DAT_081eca46,param_5)
          ;
          if (iVar10 != 0) {
            if (iVar10 != 2) break;
            goto LAB_081cbb87;
          }
          goto LAB_081cbb30;
        case '\x05':
switchD_081cbad7_caseD_5:
          iVar10 = asn1_print_fsname_isra_4(0,param_5);
          if (iVar10 == 0) goto LAB_081cbb30;
          if ((pvVar4 != (void *)0x0) && (*(code **)((int)pvVar4 + 0x1c) != (code *)0x0)) {
            iVar10 = (**(code **)((int)pvVar4 + 0x1c))(param_1,&local_80,pAVar3,iVar20,param_5);
            if (iVar10 != 0) break;
            goto LAB_081cbb30;
          }
          if (pAVar3->itype == '\x05') {
            uVar16 = local_80->type & 0xfffffeff;
          }
          else {
            uVar16 = pAVar3->utype;
          }
          if (uVar16 == 0xfffffffc) {
            piVar7 = &local_80->type;
            uVar16 = local_80->length;
            bVar6 = *(byte *)param_5 & 0x10;
            a = (ASN1_INTEGER *)local_80->type;
          }
          else {
            piVar7 = (int *)&local_80;
            bVar6 = *(byte *)param_5 & 8;
            a = local_80;
          }
          if (bVar6 == 0) {
            pcVar9 = ASN1_tag2str(uVar16);
            if (uVar16 == 5) goto LAB_081cbdcb;
            if ((pcVar9 != (char *)0x0) &&
               ((iVar10 = BIO_puts(param_1,pcVar9), iVar10 < 1 ||
                (iVar10 = BIO_puts(param_1,":"), iVar10 < 1)))) goto LAB_081cbb30;
          }
          else if (uVar16 == 5) {
LAB_081cbdcb:
            pcVar9 = "NULL\n";
            goto LAB_081cbd05;
          }
          switch(uVar16) {
          case 1:
            pAVar15 = (ASN1_OBJECT *)*piVar7;
            if ((pAVar15 == (ASN1_OBJECT *)0xffffffff) &&
               (pAVar15 = (ASN1_OBJECT *)pAVar3->size, pAVar15 == (ASN1_OBJECT *)0xffffffff)) {
              pcVar9 = "BOOL ABSENT";
            }
            else {
              pcVar9 = "FALSE";
              if (pAVar15 != (ASN1_OBJECT *)0x0) {
                pcVar9 = "TRUE";
              }
            }
            iVar10 = BIO_puts(param_1,pcVar9);
            if (0 < iVar10) goto LAB_081cbb87;
            goto LAB_081cbb30;
          case 2:
          case 10:
            pcVar9 = i2s_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,a);
            if (pcVar9 == (char *)0x0) goto LAB_081cbb30;
            iVar10 = BIO_puts(param_1,pcVar9);
            uVar16 = (uint)(0 < iVar10);
            CRYPTO_free(pcVar9);
            break;
          case 3:
          case 4:
            if (a->type == 3) {
              iVar10 = BIO_printf(param_1," (%ld unused bits)\n",a->flags & 7);
            }
            else {
              iVar10 = BIO_puts(param_1,"\n");
            }
            if (0 < iVar10) {
              if (a->length < 1) goto LAB_081cbbd0;
              iVar10 = BIO_dump_indent(param_1,(char *)a->data,a->length,param_3 + 4);
joined_r0x081cc339:
              if (0 < iVar10) goto LAB_081cbbd0;
            }
            goto LAB_081cbb30;
          case 6:
            pAVar15 = (ASN1_OBJECT *)*piVar7;
            iVar10 = OBJ_obj2nid(pAVar15);
            pcVar9 = OBJ_nid2ln(iVar10);
            if (pcVar9 == (char *)0x0) {
              pcVar9 = "";
            }
            OBJ_obj2txt(local_70,0x50,pAVar15,1);
            iVar10 = BIO_printf(param_1,"%s (%s)",pcVar9,local_70);
            uVar16 = (uint)(0 < iVar10);
            break;
          case 0x17:
            uVar16 = ASN1_UTCTIME_print(param_1,a);
            break;
          case 0x18:
            uVar16 = ASN1_GENERALIZEDTIME_print(param_1,a);
            break;
          case 0xfffffffd:
          case 0x10:
          case 0x11:
            iVar10 = BIO_puts(param_1,"\n");
            if (0 < iVar10) {
              iVar10 = ASN1_parse_dump(param_1,a->data,a->length,iVar20,0);
              goto joined_r0x081cc339;
            }
            goto LAB_081cbb30;
          default:
            uVar16 = ASN1_STRING_print_ex(param_1,a,param_5[4]);
          }
          if (uVar16 == 0) goto LAB_081cbb30;
LAB_081cbb87:
          pcVar9 = "\n";
LAB_081cbd05:
          iVar10 = BIO_puts(param_1,pcVar9);
joined_r0x081cbbca:
          if (iVar10 < 1) goto LAB_081cbb30;
        }
LAB_081cbbd0:
      }
      if ((iVar19 == 0) &&
         (iVar20 = BIO_printf(param_1,"%*s<EMPTY>\n",param_3 + 2,&DAT_081eca46), iVar20 < 1))
      goto LAB_081cbb30;
      if ((*(byte *)param_5 & 2) != 0) {
        pcVar9 = "%*s}\n";
        iVar20 = param_3;
        goto LAB_081cbf21;
      }
      goto LAB_081cbe99;
    }
    if ((uVar1 & 4) == 0) {
      format = "%*s%s:\n";
    }
    else {
      pcVar9 = "SEQUENCE";
      if ((uVar16 & 2) != 0) {
        pcVar9 = "SET";
      }
      format = "%*s%s OF %s {\n";
    }
    iVar20 = BIO_printf(param_1,format,param_3,&DAT_081eca46,pcVar9);
    if (0 < iVar20) goto LAB_081cba2b;
    goto LAB_081cbb30;
  }
  if ((uVar16 & 6) != 0) goto LAB_081cba2b;
  pcVar9 = (char *)0x0;
LAB_081cbd3b:
  pAVar3 = (ASN1_ITEM *)param_4[4];
  pvVar4 = pAVar3->funcs;
  if (pvVar4 == (void *)0x0) {
    local_a8 = (code *)0x0;
  }
  else {
    local_a8 = *(code **)((int)pvVar4 + 0x10);
    if (local_a8 != (code *)0x0) {
      local_7c = param_1;
      local_78 = param_3;
      local_74 = param_5;
    }
  }
  if ((_STACK *)*param_2 == (_STACK *)0x0) {
    if ((uVar1 & 1) == 0) goto LAB_081cbe99;
    iVar20 = asn1_print_fsname_isra_4(iVar20,param_5);
    if (iVar20 != 0) {
      pcVar9 = "<ABSENT>\n";
LAB_081cc06b:
      iVar20 = BIO_puts(param_1,pcVar9);
      bVar21 = 0 < iVar20;
      goto LAB_081cbb32;
    }
    goto LAB_081cbb30;
  }
  cVar8 = pAVar3->itype;
  switch(cVar8) {
  case '\0':
    pAVar18 = pAVar3->templates;
    if (pAVar18 == (ASN1_TEMPLATE *)0x0) goto switchD_081cbd94_caseD_5;
    goto LAB_081cc0a0;
  case '\x01':
  case '\x06':
    iVar19 = asn1_print_fsname_isra_4(iVar20,param_5);
    if (iVar19 != 0) {
      if ((pcVar9 != (char *)0x0) || (iVar20 != 0)) {
        if ((*(byte *)param_5 & 2) == 0) {
          pcVar9 = "\n";
        }
        else {
          pcVar9 = " {\n";
        }
        iVar20 = BIO_puts(param_1,pcVar9);
        if (iVar20 < 1) break;
      }
      if (local_a8 != (code *)0x0) {
        iVar20 = (*local_a8)(8,param_2,pAVar3,&local_7c);
        if (iVar20 == 0) break;
        if (iVar20 == 2) goto LAB_081cbe99;
      }
      iVar20 = 0;
      pAVar18 = pAVar3->templates;
      if (0 < pAVar3->tcount) {
        do {
          pAVar14 = asn1_do_adb((ASN1_VALUE **)param_2,pAVar18,1);
          if (pAVar14 == (ASN1_TEMPLATE *)0x0) goto LAB_081cbb30;
          ppAVar13 = asn1_get_field_ptr((ASN1_VALUE **)param_2,pAVar14);
          iVar19 = asn1_template_print_ctx(param_1,ppAVar13,param_3 + 2,pAVar14,param_5);
          if (iVar19 == 0) goto LAB_081cbb30;
          iVar20 = iVar20 + 1;
          pAVar18 = pAVar18 + 1;
        } while (iVar20 < pAVar3->tcount);
      }
      if (((*(byte *)param_5 & 2) == 0) ||
         (iVar20 = BIO_printf(param_1,"%*s}\n",param_3,&DAT_081eca46), -1 < iVar20)) {
        if (local_a8 != (code *)0x0) {
          iVar20 = (*local_a8)(9,param_2,pAVar3,&local_7c);
          bVar21 = iVar20 != 0;
          goto LAB_081cbb32;
        }
        goto LAB_081cbe99;
      }
    }
    break;
  case '\x02':
    iVar20 = asn1_get_choice_selector((ASN1_VALUE **)param_2,pAVar3);
    if ((iVar20 < 0) || (pAVar3->tcount <= iVar20)) {
      pcVar9 = "ERROR: selector [%d] invalid\n";
LAB_081cbf21:
      iVar20 = BIO_printf(param_1,pcVar9,iVar20);
      bVar21 = 0 < iVar20;
      goto LAB_081cbb32;
    }
    pAVar18 = pAVar3->templates + iVar20;
    param_2 = (char ***)asn1_get_field_ptr((ASN1_VALUE **)param_2,pAVar18);
LAB_081cc0a0:
    iVar20 = asn1_template_print_ctx(param_1,param_2,param_3,pAVar18,param_5);
    bVar21 = iVar20 != 0;
    goto LAB_081cbb32;
  default:
switchD_081cbd94_caseD_3:
    BIO_printf(param_1,"Unprocessed type %d\n",(int)cVar8);
    break;
  case '\x04':
    iVar19 = asn1_print_fsname_isra_4(iVar20,param_5);
    if (iVar19 != 0) {
      if ((pAVar3->funcs == (void *)0x0) ||
         (pcVar5 = *(code **)((int)pAVar3->funcs + 0x18), pcVar5 == (code *)0x0)) {
        if (iVar20 != 0) {
          pcVar9 = ":EXTERNAL TYPE %s\n";
          goto LAB_081cbf21;
        }
      }
      else {
        iVar20 = (*pcVar5)(param_1,param_2,param_3,&DAT_081eca46,param_5);
        if (iVar20 == 0) break;
        if (iVar20 == 2) {
          pcVar9 = "\n";
          goto LAB_081cc06b;
        }
      }
      goto LAB_081cbe99;
    }
    break;
  case '\x05':
switchD_081cbd94_caseD_5:
    iVar20 = asn1_print_fsname_isra_4(iVar20,param_5);
    if (iVar20 == 0) break;
    if ((pvVar4 != (void *)0x0) && (*(code **)((int)pvVar4 + 0x1c) != (code *)0x0)) {
      iVar20 = (**(code **)((int)pvVar4 + 0x1c))(param_1,param_2,pAVar3,param_3,param_5);
      bVar21 = iVar20 != 0;
      goto LAB_081cbb32;
    }
    p_Var2 = (_STACK *)*param_2;
    if (pAVar3->itype == '\x05') {
      uVar16 = (uint)p_Var2->data & 0xfffffeff;
    }
    else {
      uVar16 = pAVar3->utype;
    }
    if (uVar16 == 0xfffffffc) {
      uVar16 = p_Var2->num;
      param_2 = &p_Var2->data;
      p_Var2 = (_STACK *)p_Var2->data;
      bVar6 = *(byte *)param_5 & 0x10;
    }
    else {
      bVar6 = *(byte *)param_5 & 8;
    }
    if (bVar6 == 0) {
      pcVar9 = ASN1_tag2str(uVar16);
      if (uVar16 == 5) goto LAB_081cc3d4;
      if ((pcVar9 != (char *)0x0) &&
         ((iVar20 = BIO_puts(param_1,pcVar9), iVar20 < 1 ||
          (iVar20 = BIO_puts(param_1,":"), iVar20 < 1)))) break;
LAB_081cc4b9:
      switch(uVar16) {
      case 1:
        ppcVar17 = *param_2;
        if (ppcVar17 == (char **)0xffffffff) {
          ppcVar17 = (char **)pAVar3->size;
          pcVar9 = "BOOL ABSENT";
          if (ppcVar17 != (char **)0xffffffff) goto LAB_081cc5ee;
        }
        else {
LAB_081cc5ee:
          pcVar9 = "FALSE";
          if (ppcVar17 != (char **)0x0) {
            pcVar9 = "TRUE";
          }
        }
        iVar20 = BIO_puts(param_1,pcVar9);
        if (iVar20 < 1) goto LAB_081cbb30;
        goto LAB_081cc4e1;
      case 2:
      case 10:
        pcVar9 = i2s_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,(ASN1_INTEGER *)p_Var2);
        if (pcVar9 == (char *)0x0) goto LAB_081cbb30;
        iVar20 = BIO_puts(param_1,pcVar9);
        uVar16 = (uint)(0 < iVar20);
        CRYPTO_free(pcVar9);
        break;
      case 3:
      case 4:
        if (p_Var2->data == (char **)0x3) {
          iVar20 = BIO_printf(param_1," (%ld unused bits)\n",p_Var2->num_alloc & 7,param_2);
        }
        else {
          iVar20 = BIO_puts(param_1,"\n");
        }
        if (iVar20 < 1) goto LAB_081cbb30;
        if (p_Var2->num < 1) goto LAB_081cbe99;
        iVar20 = BIO_dump_indent(param_1,(char *)p_Var2->sorted,p_Var2->num,param_3 + 2);
        goto joined_r0x081cc590;
      case 6:
        pAVar15 = (ASN1_OBJECT *)*param_2;
        iVar20 = OBJ_obj2nid(pAVar15);
        pcVar9 = OBJ_nid2ln(iVar20);
        if (pcVar9 == (char *)0x0) {
          pcVar9 = "";
        }
        OBJ_obj2txt(local_70,0x50,pAVar15,1);
        iVar20 = BIO_printf(param_1,"%s (%s)",pcVar9,local_70);
        uVar16 = (uint)(0 < iVar20);
        break;
      case 0x17:
        uVar16 = ASN1_UTCTIME_print(param_1,(ASN1_UTCTIME *)p_Var2);
        break;
      case 0x18:
        uVar16 = ASN1_GENERALIZEDTIME_print(param_1,(ASN1_GENERALIZEDTIME *)p_Var2);
        break;
      case 0xfffffffd:
      case 0x10:
      case 0x11:
        iVar20 = BIO_puts(param_1,"\n");
        if ((iVar20 < 1) ||
           (iVar20 = ASN1_parse_dump(param_1,(uchar *)p_Var2->sorted,p_Var2->num,param_3,0),
           iVar20 < 1)) goto LAB_081cbb30;
        goto LAB_081cbe99;
      default:
        uVar16 = ASN1_STRING_print_ex(param_1,(ASN1_STRING *)p_Var2,param_5[4]);
      }
      if (uVar16 == 0) break;
LAB_081cc4e1:
      pcVar9 = "\n";
    }
    else {
      if (uVar16 != 5) goto LAB_081cc4b9;
LAB_081cc3d4:
      pcVar9 = "NULL\n";
    }
    iVar20 = BIO_puts(param_1,pcVar9);
joined_r0x081cc590:
    if (0 < iVar20) {
LAB_081cbe99:
      bVar21 = true;
      goto LAB_081cbb32;
    }
  }
LAB_081cbb30:
  bVar21 = false;
LAB_081cbb32:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return bVar21;
}

