
int ASN1_item_print(BIO *out,ASN1_VALUE *ifld,int indent,ASN1_ITEM *it,ASN1_PCTX *pctx)

{
  void *pvVar1;
  code *pcVar2;
  byte bVar3;
  int *piVar4;
  ASN1_GENERALIZEDTIME *a;
  ASN1_TEMPLATE *tt;
  ASN1_VALUE **ppAVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  ASN1_OBJECT *pAVar9;
  char *pcVar10;
  ASN1_TEMPLATE *pAVar11;
  int in_GS_OFFSET;
  char *format;
  code *local_94;
  ASN1_GENERALIZEDTIME *local_80;
  BIO *local_7c;
  int local_78;
  uint *local_74;
  char local_70 [80];
  int local_20;
  
  local_80 = (ASN1_GENERALIZEDTIME *)ifld;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (pctx == (ASN1_PCTX *)0x0) {
    pctx = (ASN1_PCTX *)default_pctx;
  }
  pcVar10 = (char *)0x0;
  if ((*(uint *)pctx & 0x100) == 0) {
    pcVar10 = it->sname;
  }
  pvVar1 = it->funcs;
  if (pvVar1 == (void *)0x0) {
    local_94 = (code *)0x0;
    if (ifld == (ASN1_VALUE *)0x0) goto LAB_081cdc78;
LAB_081cd9b1:
    switch(it->itype) {
    case '\0':
      goto switchD_081cd9c0_caseD_0;
    case '\x01':
    case '\x06':
      iVar8 = asn1_print_fsname_isra_4(pcVar10,pctx);
      if (iVar8 == 0) goto LAB_081cdb88;
      if (pcVar10 != (char *)0x0) {
        if ((*(byte *)pctx & 2) == 0) {
          pcVar10 = "\n";
        }
        else {
          pcVar10 = " {\n";
        }
        iVar8 = BIO_puts(out,pcVar10);
        if (iVar8 < 1) goto LAB_081cdb88;
      }
      if (local_94 != (code *)0x0) {
        iVar8 = (*local_94)(8,&local_80,it,&local_7c);
        if (iVar8 == 0) goto LAB_081cdb88;
        if (iVar8 == 2) goto LAB_081cdd10;
      }
      pAVar11 = it->templates;
      if (0 < it->tcount) {
        iVar8 = 0;
        do {
          tt = asn1_do_adb((ASN1_VALUE **)&local_80,pAVar11,1);
          ppAVar5 = asn1_get_field_ptr((ASN1_VALUE **)&local_80,tt);
          iVar6 = asn1_template_print_ctx(out,ppAVar5,indent + 2,tt,pctx);
          if (iVar6 == 0) goto LAB_081cdb88;
          iVar8 = iVar8 + 1;
          pAVar11 = pAVar11 + 1;
        } while (iVar8 < it->tcount);
      }
      if (((*(byte *)pctx & 2) != 0) &&
         (iVar8 = BIO_printf(out,"%*s}\n",indent,&DAT_081ec74a), iVar8 < 0)) {
        uVar7 = 0;
        goto LAB_081cda30;
      }
      if (local_94 != (code *)0x0) {
        iVar8 = (*local_94)(9,&local_80,it,&local_7c);
        uVar7 = (uint)(iVar8 != 0);
        goto LAB_081cda30;
      }
      goto LAB_081cdd10;
    case '\x02':
      pcVar10 = (char *)asn1_get_choice_selector((ASN1_VALUE **)&local_80,it);
      if ((-1 < (int)pcVar10) && ((int)pcVar10 < it->tcount)) {
        pAVar11 = it->templates;
        ppAVar5 = asn1_get_field_ptr((ASN1_VALUE **)&local_80,pAVar11 + (int)pcVar10);
        iVar8 = asn1_template_print_ctx(out,ppAVar5,indent,pAVar11 + (int)pcVar10,pctx);
        uVar7 = (uint)(iVar8 != 0);
        goto LAB_081cda30;
      }
      format = "ERROR: selector [%d] invalid\n";
LAB_081cdbb7:
      iVar8 = BIO_printf(out,format,pcVar10);
      uVar7 = (uint)(0 < iVar8);
      goto LAB_081cda30;
    default:
      BIO_printf(out,"Unprocessed type %d\n",(int)it->itype);
      uVar7 = 0;
      goto LAB_081cda30;
    case '\x04':
      iVar8 = asn1_print_fsname_isra_4(pcVar10,pctx);
      if (iVar8 != 0) {
        if ((it->funcs == (void *)0x0) ||
           (pcVar2 = *(code **)((int)it->funcs + 0x18), pcVar2 == (code *)0x0)) {
          if (pcVar10 != (char *)0x0) {
            format = ":EXTERNAL TYPE %s\n";
            goto LAB_081cdbb7;
          }
        }
        else {
          iVar8 = (*pcVar2)(out,&local_80,indent,&DAT_081ec74a,pctx);
          if (iVar8 == 0) goto LAB_081cdb88;
          if (iVar8 == 2) {
            pcVar10 = "\n";
            goto LAB_081cdca9;
          }
        }
        goto LAB_081cdd10;
      }
      goto LAB_081cdb88;
    case '\x05':
      goto LAB_081cd9d4;
    }
  }
  local_94 = *(code **)((int)pvVar1 + 0x10);
  if (local_94 != (code *)0x0) {
    local_7c = out;
    local_78 = indent;
    local_74 = (uint *)pctx;
  }
  if (ifld != (ASN1_VALUE *)0x0) goto LAB_081cd9b1;
LAB_081cdc78:
  if ((*(uint *)pctx & 1) == 0) goto LAB_081cdd10;
  iVar8 = asn1_print_fsname_isra_4(pcVar10,pctx);
  if (iVar8 != 0) {
    pcVar10 = "<ABSENT>\n";
LAB_081cdca9:
    iVar8 = BIO_puts(out,pcVar10);
    uVar7 = (uint)(0 < iVar8);
    goto LAB_081cda30;
  }
LAB_081cdb88:
  uVar7 = 0;
LAB_081cda30:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar7;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
switchD_081cd9c0_caseD_0:
  if (it->templates != (ASN1_TEMPLATE *)0x0) {
    iVar8 = asn1_template_print_ctx(out,&local_80,indent,it->templates,pctx);
    if (iVar8 == 0) goto LAB_081cdb88;
    pvVar1 = it->funcs;
  }
LAB_081cd9d4:
  local_94 = (code *)pvVar1;
  iVar8 = asn1_print_fsname_isra_4(pcVar10,pctx);
  if (iVar8 == 0) goto LAB_081cdb88;
  if ((local_94 != (code *)0x0) && (*(code **)((int)local_94 + 0x1c) != (code *)0x0)) {
    iVar8 = (**(code **)((int)local_94 + 0x1c))(out,&local_80,it,indent,pctx);
    uVar7 = (uint)(iVar8 != 0);
    goto LAB_081cda30;
  }
  if (it->itype == '\x05') {
    uVar7 = local_80->type & 0xfffffeff;
  }
  else {
    uVar7 = it->utype;
  }
  if (uVar7 == 0xfffffffc) {
    bVar3 = *(byte *)pctx & 0x10;
    piVar4 = &local_80->type;
    uVar7 = local_80->length;
    a = (ASN1_GENERALIZEDTIME *)local_80->type;
  }
  else {
    bVar3 = *(byte *)pctx & 8;
    piVar4 = (int *)&local_80;
    a = local_80;
  }
  if (bVar3 == 0) {
    pcVar10 = ASN1_tag2str(uVar7);
    if (uVar7 != 5) {
      if ((pcVar10 != (char *)0x0) &&
         ((iVar8 = BIO_puts(out,pcVar10), iVar8 < 1 || (iVar8 = BIO_puts(out,":"), iVar8 < 1))))
      goto LAB_081cdb88;
      goto LAB_081cddcc;
    }
LAB_081cdd4b:
    pcVar10 = "NULL\n";
  }
  else {
    if (uVar7 == 5) goto LAB_081cdd4b;
LAB_081cddcc:
    switch(uVar7) {
    case 1:
      pAVar9 = (ASN1_OBJECT *)*piVar4;
      if ((pAVar9 == (ASN1_OBJECT *)0xffffffff) &&
         (pAVar9 = (ASN1_OBJECT *)it->size, pAVar9 == (ASN1_OBJECT *)0xffffffff)) {
        pcVar10 = "BOOL ABSENT";
      }
      else {
        pcVar10 = "FALSE";
        if (pAVar9 != (ASN1_OBJECT *)0x0) {
          pcVar10 = "TRUE";
        }
      }
      iVar8 = BIO_puts(out,pcVar10);
      if (iVar8 < 1) {
        uVar7 = 0;
        goto LAB_081cda30;
      }
      goto LAB_081cddf4;
    case 2:
    case 10:
      pcVar10 = i2s_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,a);
      iVar8 = BIO_puts(out,pcVar10);
      uVar7 = (uint)(0 < iVar8);
      CRYPTO_free(pcVar10);
      break;
    case 3:
    case 4:
      if (a->type == 3) {
        iVar8 = BIO_printf(out," (%ld unused bits)\n",a->flags & 7);
        if (iVar8 < 1) {
          uVar7 = 0;
          goto LAB_081cda30;
        }
      }
      else {
        iVar8 = BIO_puts(out,"\n");
        if (iVar8 < 1) goto LAB_081cdb88;
      }
      if (a->length < 1) goto LAB_081cdd10;
      iVar8 = BIO_dump_indent(out,(char *)a->data,a->length,indent + 2);
      goto joined_r0x081cdd0a;
    case 6:
      pAVar9 = (ASN1_OBJECT *)*piVar4;
      iVar8 = OBJ_obj2nid(pAVar9);
      pcVar10 = OBJ_nid2ln(iVar8);
      if (pcVar10 == (char *)0x0) {
        pcVar10 = "";
      }
      OBJ_obj2txt(local_70,0x50,pAVar9,1);
      iVar8 = BIO_printf(out,"%s (%s)",pcVar10,local_70);
      uVar7 = (uint)(0 < iVar8);
      break;
    case 0x17:
      uVar7 = ASN1_UTCTIME_print(out,a);
      break;
    case 0x18:
      uVar7 = ASN1_GENERALIZEDTIME_print(out,a);
      break;
    case 0xfffffffd:
    case 0x10:
    case 0x11:
      iVar8 = BIO_puts(out,"\n");
      if ((iVar8 < 1) || (iVar8 = ASN1_parse_dump(out,a->data,a->length,indent,0), iVar8 < 1))
      goto LAB_081cdb88;
      goto LAB_081cdd10;
    default:
      uVar7 = ASN1_STRING_print_ex(out,a,*(uint *)((int)pctx + 0x10));
    }
    if (uVar7 == 0) goto LAB_081cdb88;
LAB_081cddf4:
    pcVar10 = "\n";
  }
  iVar8 = BIO_puts(out,pcVar10);
joined_r0x081cdd0a:
  if (0 < iVar8) {
LAB_081cdd10:
    uVar7 = 1;
    goto LAB_081cda30;
  }
  goto LAB_081cdb88;
}

