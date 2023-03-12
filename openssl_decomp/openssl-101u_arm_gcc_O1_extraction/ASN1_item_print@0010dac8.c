
int ASN1_item_print(BIO *out,ASN1_VALUE *ifld,int indent,ASN1_ITEM *it,ASN1_PCTX *pctx)

{
  uint uVar1;
  int iVar2;
  ASN1_VALUE **ppAVar3;
  int iVar4;
  ASN1_TEMPLATE *tt;
  char *pcVar5;
  ASN1_OBJECT *pAVar6;
  code *pcVar7;
  code *pcVar8;
  ASN1_TEMPLATE *pAVar9;
  ASN1_GENERALIZEDTIME *a;
  char *pcVar10;
  int *piVar11;
  ASN1_GENERALIZEDTIME *local_8c;
  BIO *local_88;
  int local_84;
  int *local_80;
  char acStack_7c [80];
  int local_2c;
  
  pcVar8 = (code *)it->funcs;
  if (pctx == (ASN1_PCTX *)0x0) {
    pctx = (ASN1_PCTX *)PTR_default_pctx_0010dde4;
  }
  local_2c = __stack_chk_guard;
  if (*(int *)pctx << 0x17 < 0) {
    pcVar10 = (char *)0x0;
  }
  else {
    pcVar10 = it->sname;
  }
  pcVar7 = pcVar8;
  if ((pcVar8 != (code *)0x0) && (pcVar7 = *(code **)(pcVar8 + 0x10), pcVar7 != (code *)0x0)) {
    local_88 = out;
    local_84 = indent;
    local_80 = (int *)pctx;
  }
  local_8c = (ASN1_GENERALIZEDTIME *)ifld;
  if (ifld == (ASN1_VALUE *)0x0) {
    if (-1 < *(int *)pctx << 0x1f) goto LAB_0010db72;
    iVar2 = asn1_print_fsname_isra_4(out,indent,0,pcVar10,pctx);
    if (iVar2 != 0) {
      iVar2 = BIO_puts(out,"<ABSENT>\n");
      uVar1 = (uint)(0 < iVar2);
      goto LAB_0010db74;
    }
    goto LAB_0010dcfa;
  }
  switch(it->itype) {
  case '\0':
    break;
  case '\x01':
  case '\x06':
    iVar2 = asn1_print_fsname_isra_4(out,indent,0,pcVar10,pctx);
    if (iVar2 != 0) {
      if (pcVar10 != (char *)0x0) {
        if (*(int *)pctx << 0x1e < 0) {
          iVar2 = BIO_puts(out," {\n");
        }
        else {
          iVar2 = BIO_puts(out,"\n");
        }
        if (iVar2 < 1) goto LAB_0010dcfa;
      }
      if (pcVar7 != (code *)0x0) {
        iVar2 = (*pcVar7)(8,&local_8c,it,&local_88);
        if (iVar2 == 0) goto LAB_0010dcfa;
        if (iVar2 == 2) goto LAB_0010db72;
      }
      pAVar9 = it->templates;
      if (0 < it->tcount) {
        iVar2 = 0;
        do {
          tt = asn1_do_adb((ASN1_VALUE **)&local_8c,pAVar9,1);
          if (tt == (ASN1_TEMPLATE *)0x0) goto LAB_0010dcfa;
          ppAVar3 = asn1_get_field_ptr((ASN1_VALUE **)&local_8c,tt);
          iVar4 = asn1_template_print_ctx(out,ppAVar3,indent + 2,tt,pctx);
          if (iVar4 == 0) goto LAB_0010dcfa;
          iVar2 = iVar2 + 1;
          pAVar9 = pAVar9 + 1;
        } while (iVar2 < it->tcount);
      }
      if ((-1 < *(int *)pctx << 0x1e) || (iVar2 = BIO_printf(out,"%*s}\n",indent,""), -1 < iVar2)) {
        if (pcVar7 != (code *)0x0) {
          uVar1 = (*pcVar7)(9,&local_8c,it,&local_88);
          if (uVar1 != 0) {
            uVar1 = 1;
          }
          goto LAB_0010db74;
        }
        goto LAB_0010db72;
      }
    }
    goto LAB_0010dcfa;
  case '\x02':
    iVar2 = asn1_get_choice_selector((ASN1_VALUE **)&local_8c,it);
    if ((iVar2 < 0) || (it->tcount <= iVar2)) {
      iVar2 = BIO_printf(out,"ERROR: selector [%d] invalid\n");
      uVar1 = (uint)(0 < iVar2);
    }
    else {
      pAVar9 = it->templates;
      ppAVar3 = asn1_get_field_ptr((ASN1_VALUE **)&local_8c,pAVar9 + iVar2);
      uVar1 = asn1_template_print_ctx(out,ppAVar3,indent,pAVar9 + iVar2,pctx);
      if (uVar1 != 0) {
        uVar1 = 1;
      }
    }
    goto LAB_0010db74;
  default:
    BIO_printf(out,"Unprocessed type %d\n");
    uVar1 = 0;
    goto LAB_0010db74;
  case '\x04':
    iVar2 = asn1_print_fsname_isra_4(out,indent,0,pcVar10,pctx);
    if (iVar2 == 0) goto LAB_0010dcfa;
    if ((it->funcs == (void *)0x0) ||
       (pcVar8 = *(code **)((int)it->funcs + 0x18), pcVar8 == (code *)0x0)) {
      if (pcVar10 != (char *)0x0) {
        iVar2 = BIO_printf(out,":EXTERNAL TYPE %s\n",pcVar10);
        uVar1 = (uint)(0 < iVar2);
        goto LAB_0010db74;
      }
    }
    else {
      iVar2 = (*pcVar8)(out,&local_8c,indent,"",pctx);
      if (iVar2 == 0) goto LAB_0010dcfa;
      if (iVar2 == 2) {
        iVar2 = BIO_puts(out,"\n");
        uVar1 = (uint)(0 < iVar2);
        goto LAB_0010db74;
      }
    }
    goto LAB_0010db72;
  case '\x05':
    goto switchD_0010db2c_caseD_5;
  }
  if (it->templates != (ASN1_TEMPLATE *)0x0) {
    uVar1 = asn1_template_print_ctx(out,&local_8c,indent,it->templates,pctx);
    if (uVar1 != 0) {
      uVar1 = 1;
    }
    goto LAB_0010db74;
  }
switchD_0010db2c_caseD_5:
  iVar2 = asn1_print_fsname_isra_4(out,indent,0,pcVar10,pctx);
  a = local_8c;
  if (iVar2 == 0) goto LAB_0010dcfa;
  if ((pcVar8 != (code *)0x0) && (*(code **)(pcVar8 + 0x1c) != (code *)0x0)) {
    iVar2 = (**(code **)(pcVar8 + 0x1c))(out,&local_8c,it,indent,pctx);
    if (iVar2 == 0) goto LAB_0010dcfa;
    goto LAB_0010db72;
  }
  if (it->itype == '\x05') {
    uVar1 = local_8c->type & 0xfffffeff;
  }
  else {
    uVar1 = it->utype;
  }
  if (uVar1 == 0xfffffffc) {
    piVar11 = &local_8c->type;
    uVar1 = local_8c->length;
    a = (ASN1_GENERALIZEDTIME *)local_8c->type;
    if (-1 < *(int *)pctx << 0x1b) {
      pcVar10 = ASN1_tag2str(uVar1);
      goto LAB_0010de40;
    }
LAB_0010dd58:
    if (uVar1 != 5) goto LAB_0010dd60;
LAB_0010e00a:
    iVar2 = BIO_puts(out,"NULL\n");
    goto joined_r0x0010e01a;
  }
  if (-1 < *(int *)pctx << 0x1c) {
    piVar11 = (int *)&local_8c;
    goto LAB_0010dd58;
  }
  piVar11 = (int *)&local_8c;
  pcVar10 = ASN1_tag2str(uVar1);
LAB_0010de40:
  if (uVar1 == 5) goto LAB_0010e00a;
  if ((pcVar10 != (char *)0x0) &&
     ((iVar2 = BIO_puts(out,pcVar10), iVar2 < 1 || (iVar2 = BIO_puts(out,":"), iVar2 < 1))))
  goto LAB_0010dcfa;
LAB_0010dd60:
  switch(uVar1) {
  case 1:
    pAVar6 = (ASN1_OBJECT *)*piVar11;
    if ((pAVar6 == (ASN1_OBJECT *)0xffffffff) &&
       (pAVar6 = (ASN1_OBJECT *)it->size, pAVar6 == (ASN1_OBJECT *)0xffffffff)) {
      pcVar10 = "BOOL ABSENT";
    }
    else {
      pcVar10 = "FALSE";
      if (pAVar6 != (ASN1_OBJECT *)0x0) {
        pcVar10 = "TRUE";
      }
    }
    iVar2 = BIO_puts(out,pcVar10);
    uVar1 = (uint)(0 < iVar2);
    break;
  case 2:
  case 10:
    pcVar10 = i2s_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,a);
    if (pcVar10 != (char *)0x0) {
      iVar2 = BIO_puts(out,pcVar10);
      uVar1 = (uint)(0 < iVar2);
      CRYPTO_free(pcVar10);
      break;
    }
    goto LAB_0010dcfa;
  case 3:
  case 4:
    if (a->type == 3) {
      iVar2 = BIO_printf(out," (%ld unused bits)\n",a->flags & 7);
    }
    else {
      iVar2 = BIO_puts(out,"\n");
    }
    if (0 < iVar2) {
      if (a->length < 1) goto LAB_0010db72;
      iVar2 = BIO_dump_indent(out,a->data,a->length,indent + 2);
      goto joined_r0x0010e01a;
    }
    goto LAB_0010dcfa;
  case 6:
    pAVar6 = (ASN1_OBJECT *)*piVar11;
    iVar2 = OBJ_obj2nid(pAVar6);
    pcVar5 = OBJ_nid2ln(iVar2);
    pcVar10 = "";
    if (pcVar5 != (char *)0x0) {
      pcVar10 = pcVar5;
    }
    OBJ_obj2txt(acStack_7c,0x50,pAVar6,1);
    iVar2 = BIO_printf(out,"%s (%s)",pcVar10,acStack_7c);
    uVar1 = (uint)(0 < iVar2);
    break;
  case 0x17:
    uVar1 = ASN1_UTCTIME_print(out,a);
    break;
  case 0x18:
    uVar1 = ASN1_GENERALIZEDTIME_print(out,a);
    break;
  case 0xfffffffd:
  case 0x10:
  case 0x11:
    iVar2 = BIO_puts(out,"\n");
    if (iVar2 < 1) goto LAB_0010dcfa;
    iVar2 = ASN1_parse_dump(out,a->data,a->length,indent,0);
    goto joined_r0x0010e01a;
  default:
    uVar1 = ASN1_STRING_print_ex(out,a,*(ulong *)((int)pctx + 0x10));
  }
  if (uVar1 != 0) {
    iVar2 = BIO_puts(out,"\n");
joined_r0x0010e01a:
    if (0 < iVar2) {
LAB_0010db72:
      uVar1 = 1;
      goto LAB_0010db74;
    }
  }
LAB_0010dcfa:
  uVar1 = 0;
LAB_0010db74:
  if (local_2c == __stack_chk_guard) {
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

