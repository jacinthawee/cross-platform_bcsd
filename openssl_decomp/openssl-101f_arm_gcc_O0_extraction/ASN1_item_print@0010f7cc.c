
int ASN1_item_print(BIO *out,ASN1_VALUE *ifld,int indent,ASN1_ITEM *it,ASN1_PCTX *pctx)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  ASN1_TEMPLATE *tt;
  ASN1_VALUE **ppAVar4;
  int iVar5;
  char *pcVar6;
  ASN1_OBJECT *pAVar7;
  code *pcVar8;
  char *pcVar9;
  ASN1_TEMPLATE *pAVar10;
  ASN1_GENERALIZEDTIME *a;
  int *piVar11;
  ASN1_GENERALIZEDTIME *local_8c;
  BIO *local_88;
  int local_84;
  int *local_80;
  char acStack_7c [80];
  int local_2c;
  
  if (pctx == (ASN1_PCTX *)0x0) {
    pctx = (ASN1_PCTX *)PTR_default_pctx_0010fadc;
  }
  local_2c = __TMC_END__;
  pcVar1 = (code *)it->funcs;
  if (*(int *)pctx << 0x17 < 0) {
    pcVar9 = (char *)0x0;
  }
  else {
    pcVar9 = it->sname;
  }
  pcVar8 = pcVar1;
  if ((pcVar1 != (code *)0x0) && (pcVar8 = *(code **)(pcVar1 + 0x10), pcVar8 != (code *)0x0)) {
    local_88 = out;
    local_84 = indent;
    local_80 = (int *)pctx;
  }
  local_8c = (ASN1_GENERALIZEDTIME *)ifld;
  if (ifld == (ASN1_VALUE *)0x0) {
    if (-1 < *(int *)pctx << 0x1f) goto LAB_0010f870;
    iVar3 = asn1_print_fsname_isra_4(out,indent,0,pcVar9,pctx);
    if (iVar3 != 0) {
      iVar3 = BIO_puts(out,"<ABSENT>\n");
      uVar2 = (uint)(0 < iVar3);
      goto LAB_0010f872;
    }
    goto LAB_0010f9f4;
  }
  switch(it->itype) {
  case '\0':
    break;
  case '\x01':
  case '\x06':
    iVar3 = asn1_print_fsname_isra_4(out,indent,0,pcVar9,pctx);
    if (iVar3 != 0) {
      if (pcVar9 != (char *)0x0) {
        if (*(int *)pctx << 0x1e < 0) {
          iVar3 = BIO_puts(out,(char *)&PTR_ERR_get_error_line_data_00176568);
        }
        else {
          iVar3 = BIO_puts(out,"\n");
        }
        if (iVar3 < 1) goto LAB_0010f9f4;
      }
      if (pcVar8 != (code *)0x0) {
        iVar3 = (*pcVar8)(8,&local_8c,it,&local_88);
        if (iVar3 == 0) goto LAB_0010f9f4;
        if (iVar3 == 2) goto LAB_0010f870;
      }
      pAVar10 = it->templates;
      if (0 < it->tcount) {
        iVar3 = 0;
        do {
          tt = asn1_do_adb((ASN1_VALUE **)&local_8c,pAVar10,1);
          ppAVar4 = asn1_get_field_ptr((ASN1_VALUE **)&local_8c,tt);
          iVar5 = asn1_template_print_ctx(out,ppAVar4,indent + 2,tt,pctx);
          if (iVar5 == 0) goto LAB_0010f9f4;
          iVar3 = iVar3 + 1;
          pAVar10 = pAVar10 + 1;
        } while (iVar3 < it->tcount);
      }
      if ((-1 < *(int *)pctx << 0x1e) || (iVar3 = BIO_printf(out,"%*s}\n",indent,""), -1 < iVar3)) {
        if (pcVar8 != (code *)0x0) {
          uVar2 = (*pcVar8)(9,&local_8c,it,&local_88);
          if (uVar2 != 0) {
            uVar2 = 1;
          }
          goto LAB_0010f872;
        }
        goto LAB_0010f870;
      }
    }
    goto LAB_0010f9f4;
  case '\x02':
    iVar3 = asn1_get_choice_selector((ASN1_VALUE **)&local_8c,it);
    if ((iVar3 < 0) || (it->tcount <= iVar3)) {
      iVar3 = BIO_printf(out,"ERROR: selector [%d] invalid\n");
      uVar2 = (uint)(0 < iVar3);
    }
    else {
      pAVar10 = it->templates;
      ppAVar4 = asn1_get_field_ptr((ASN1_VALUE **)&local_8c,pAVar10 + iVar3);
      uVar2 = asn1_template_print_ctx(out,ppAVar4,indent,pAVar10 + iVar3,pctx);
      if (uVar2 != 0) {
        uVar2 = 1;
      }
    }
    goto LAB_0010f872;
  default:
    BIO_printf(out,"Unprocessed type %d\n");
    uVar2 = 0;
    goto LAB_0010f872;
  case '\x04':
    iVar3 = asn1_print_fsname_isra_4(out,indent,0,pcVar9,pctx);
    if (iVar3 == 0) goto LAB_0010f9f4;
    if ((it->funcs == (void *)0x0) ||
       (pcVar1 = *(code **)((int)it->funcs + 0x18), pcVar1 == (code *)0x0)) {
      if (pcVar9 != (char *)0x0) {
        iVar3 = BIO_printf(out,":EXTERNAL TYPE %s\n",pcVar9);
        uVar2 = (uint)(0 < iVar3);
        goto LAB_0010f872;
      }
    }
    else {
      iVar3 = (*pcVar1)(out,&local_8c,indent,"",pctx);
      if (iVar3 == 0) goto LAB_0010f9f4;
      if (iVar3 == 2) {
        iVar3 = BIO_puts(out,"\n");
        uVar2 = (uint)(0 < iVar3);
        goto LAB_0010f872;
      }
    }
    goto LAB_0010f870;
  case '\x05':
    goto LAB_0010f836;
  }
  if (it->templates != (ASN1_TEMPLATE *)0x0) {
    iVar3 = asn1_template_print_ctx(out,&local_8c,indent,it->templates,pctx);
    if (iVar3 == 0) goto LAB_0010f9f4;
    pcVar1 = (code *)it->funcs;
  }
LAB_0010f836:
  iVar3 = asn1_print_fsname_isra_4(out,indent,0,pcVar9,pctx);
  a = local_8c;
  if (iVar3 == 0) goto LAB_0010f9f4;
  if ((pcVar1 == (code *)0x0) || (*(code **)(pcVar1 + 0x1c) == (code *)0x0)) {
    if (it->itype == '\x05') {
      uVar2 = local_8c->type & 0xfffffeff;
    }
    else {
      uVar2 = it->utype;
    }
    if (uVar2 == 0xfffffffc) {
      piVar11 = &local_8c->type;
      uVar2 = local_8c->length;
      a = (ASN1_GENERALIZEDTIME *)local_8c->type;
      if (-1 < *(int *)pctx << 0x1b) {
        pcVar9 = ASN1_tag2str(uVar2);
        goto LAB_0010fb26;
      }
LAB_0010fa50:
      if (uVar2 == 5) goto LAB_0010fcf2;
LAB_0010fa58:
      switch(uVar2) {
      case 1:
        pAVar7 = (ASN1_OBJECT *)*piVar11;
        if ((pAVar7 == (ASN1_OBJECT *)0xffffffff) &&
           (pAVar7 = (ASN1_OBJECT *)it->size, pAVar7 == (ASN1_OBJECT *)0xffffffff)) {
          pcVar9 = "BOOL ABSENT";
        }
        else {
          pcVar9 = "FALSE";
          if (pAVar7 != (ASN1_OBJECT *)0x0) {
            pcVar9 = "TRUE";
          }
        }
        iVar3 = BIO_puts(out,pcVar9);
        uVar2 = (uint)(0 < iVar3);
        break;
      case 2:
      case 10:
        pcVar9 = i2s_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,a);
        iVar3 = BIO_puts(out,pcVar9);
        uVar2 = (uint)(0 < iVar3);
        CRYPTO_free(pcVar9);
        break;
      case 3:
      case 4:
        if (a->type == 3) {
          iVar3 = BIO_printf(out," (%ld unused bits)\n",a->flags & 7);
        }
        else {
          iVar3 = BIO_puts(out,"\n");
        }
        if (0 < iVar3) {
          if (a->length < 1) goto LAB_0010f870;
          iVar3 = BIO_dump_indent(out,a->data,a->length,indent + 2);
          goto joined_r0x0010fd02;
        }
        goto LAB_0010f9f4;
      case 6:
        pAVar7 = (ASN1_OBJECT *)*piVar11;
        iVar3 = OBJ_obj2nid(pAVar7);
        pcVar6 = OBJ_nid2ln(iVar3);
        pcVar9 = "";
        if (pcVar6 != (char *)0x0) {
          pcVar9 = pcVar6;
        }
        OBJ_obj2txt(acStack_7c,0x50,pAVar7,1);
        iVar3 = BIO_printf(out,"%s (%s)",pcVar9,acStack_7c);
        uVar2 = (uint)(0 < iVar3);
        break;
      case 0x17:
        uVar2 = ASN1_UTCTIME_print(out,a);
        break;
      case 0x18:
        uVar2 = ASN1_GENERALIZEDTIME_print(out,a);
        break;
      case 0xfffffffd:
      case 0x10:
      case 0x11:
        iVar3 = BIO_puts(out,"\n");
        if (iVar3 < 1) goto LAB_0010f9f4;
        iVar3 = ASN1_parse_dump(out,a->data,a->length,indent,0);
        goto joined_r0x0010fd02;
      default:
        uVar2 = ASN1_STRING_print_ex(out,a,*(ulong *)((int)pctx + 0x10));
      }
      if (uVar2 != 0) {
        iVar3 = BIO_puts(out,"\n");
        goto joined_r0x0010fd02;
      }
    }
    else {
      if (-1 < *(int *)pctx << 0x1c) {
        piVar11 = (int *)&local_8c;
        goto LAB_0010fa50;
      }
      piVar11 = (int *)&local_8c;
      pcVar9 = ASN1_tag2str(uVar2);
LAB_0010fb26:
      if (uVar2 != 5) {
        if ((pcVar9 != (char *)0x0) &&
           ((iVar3 = BIO_puts(out,pcVar9), iVar3 < 1 || (iVar3 = BIO_puts(out,":"), iVar3 < 1))))
        goto LAB_0010f9f4;
        goto LAB_0010fa58;
      }
LAB_0010fcf2:
      iVar3 = BIO_puts(out,"NULL\n");
joined_r0x0010fd02:
      if (0 < iVar3) goto LAB_0010f870;
    }
LAB_0010f9f4:
    uVar2 = 0;
  }
  else {
    iVar3 = (**(code **)(pcVar1 + 0x1c))(out,&local_8c,it,indent,pctx);
    if (iVar3 == 0) goto LAB_0010f9f4;
LAB_0010f870:
    uVar2 = 1;
  }
LAB_0010f872:
  if (local_2c == __TMC_END__) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

