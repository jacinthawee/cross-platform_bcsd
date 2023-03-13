
int ASN1_item_print(BIO *out,ASN1_VALUE *ifld,int indent,ASN1_ITEM *it,ASN1_PCTX *pctx)

{
  void *pvVar1;
  code *pcVar2;
  byte bVar3;
  int *piVar4;
  ASN1_GENERALIZEDTIME *a;
  ASN1_VALUE **ppAVar5;
  int iVar6;
  ASN1_TEMPLATE *tt;
  uint uVar7;
  int iVar8;
  ASN1_GENERALIZEDTIME **ppAVar9;
  ASN1_OBJECT *pAVar10;
  char *pcVar11;
  ASN1_TEMPLATE *pAVar12;
  int in_GS_OFFSET;
  char *format;
  code *local_90;
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
  pcVar11 = (char *)0x0;
  if ((*(uint *)pctx & 0x100) == 0) {
    pcVar11 = it->sname;
  }
  pvVar1 = it->funcs;
  if (pvVar1 == (void *)0x0) {
    local_90 = (code *)0x0;
    if (ifld != (ASN1_VALUE *)0x0) goto LAB_081cc809;
LAB_081ccac8:
    if ((*(uint *)pctx & 1) == 0) goto LAB_081ccb68;
    iVar8 = asn1_print_fsname_isra_4(pcVar11,pctx);
    if (iVar8 != 0) {
      pcVar11 = "<ABSENT>\n";
LAB_081ccafd:
      iVar8 = BIO_puts(out,pcVar11);
      uVar7 = (uint)(0 < iVar8);
      goto LAB_081cc880;
    }
    goto LAB_081cc9d8;
  }
  local_90 = *(code **)((int)pvVar1 + 0x10);
  if (local_90 != (code *)0x0) {
    local_7c = out;
    local_78 = indent;
    local_74 = (uint *)pctx;
  }
  if (ifld == (ASN1_VALUE *)0x0) goto LAB_081ccac8;
LAB_081cc809:
  switch(it->itype) {
  case '\0':
    pAVar12 = it->templates;
    if (pAVar12 == (ASN1_TEMPLATE *)0x0) goto switchD_081cc817_caseD_5;
    ppAVar9 = &local_80;
    break;
  case '\x01':
  case '\x06':
    iVar8 = asn1_print_fsname_isra_4(pcVar11,pctx);
    if (iVar8 == 0) goto LAB_081cc9d8;
    if (pcVar11 != (char *)0x0) {
      if ((*(byte *)pctx & 2) == 0) {
        pcVar11 = "\n";
      }
      else {
        pcVar11 = " {\n";
      }
      iVar8 = BIO_puts(out,pcVar11);
      if (iVar8 < 1) goto LAB_081cc9d8;
    }
    if (local_90 != (code *)0x0) {
      iVar8 = (*local_90)(8,&local_80,it,&local_7c);
      if (iVar8 == 0) goto LAB_081cc9d8;
      if (iVar8 == 2) goto LAB_081ccb68;
    }
    iVar8 = 0;
    pAVar12 = it->templates;
    if (0 < it->tcount) {
      do {
        tt = asn1_do_adb((ASN1_VALUE **)&local_80,pAVar12,1);
        if (tt == (ASN1_TEMPLATE *)0x0) goto LAB_081cc9d8;
        ppAVar5 = asn1_get_field_ptr((ASN1_VALUE **)&local_80,tt);
        iVar6 = asn1_template_print_ctx(out,ppAVar5,indent + 2,tt,pctx);
        if (iVar6 == 0) goto LAB_081cc9d8;
        iVar8 = iVar8 + 1;
        pAVar12 = pAVar12 + 1;
      } while (iVar8 < it->tcount);
    }
    if (((*(byte *)pctx & 2) != 0) &&
       (iVar8 = BIO_printf(out,"%*s}\n",indent,&DAT_081eca46), iVar8 < 0)) {
      uVar7 = 0;
      goto LAB_081cc880;
    }
    if (local_90 != (code *)0x0) {
      iVar8 = (*local_90)(9,&local_80,it,&local_7c);
      uVar7 = (uint)(iVar8 != 0);
      goto LAB_081cc880;
    }
    goto LAB_081ccb68;
  case '\x02':
    pcVar11 = (char *)asn1_get_choice_selector((ASN1_VALUE **)&local_80,it);
    if (((int)pcVar11 < 0) || (it->tcount <= (int)pcVar11)) {
      format = "ERROR: selector [%d] invalid\n";
LAB_081cca07:
      iVar8 = BIO_printf(out,format,pcVar11);
      uVar7 = (uint)(0 < iVar8);
      goto LAB_081cc880;
    }
    pAVar12 = it->templates + (int)pcVar11;
    ppAVar9 = (ASN1_GENERALIZEDTIME **)asn1_get_field_ptr((ASN1_VALUE **)&local_80,pAVar12);
    break;
  default:
    BIO_printf(out,"Unprocessed type %d\n",(int)it->itype);
    uVar7 = 0;
    goto LAB_081cc880;
  case '\x04':
    iVar8 = asn1_print_fsname_isra_4(pcVar11,pctx);
    if (iVar8 == 0) goto LAB_081cc9d8;
    if ((it->funcs == (void *)0x0) ||
       (pcVar2 = *(code **)((int)it->funcs + 0x18), pcVar2 == (code *)0x0)) {
      if (pcVar11 != (char *)0x0) {
        format = ":EXTERNAL TYPE %s\n";
        goto LAB_081cca07;
      }
    }
    else {
      iVar8 = (*pcVar2)(out,&local_80,indent,&DAT_081eca46,pctx);
      if (iVar8 == 0) goto LAB_081cc9d8;
      if (iVar8 == 2) {
        pcVar11 = "\n";
        goto LAB_081ccafd;
      }
    }
LAB_081ccb68:
    uVar7 = 1;
    goto LAB_081cc880;
  case '\x05':
switchD_081cc817_caseD_5:
    iVar8 = asn1_print_fsname_isra_4(pcVar11,pctx);
    if (iVar8 == 0) goto LAB_081cc9d8;
    if ((pvVar1 != (void *)0x0) && (*(code **)((int)pvVar1 + 0x1c) != (code *)0x0)) {
      iVar8 = (**(code **)((int)pvVar1 + 0x1c))(out,&local_80,it,indent,pctx);
      uVar7 = (uint)(iVar8 != 0);
      goto LAB_081cc880;
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
    if (bVar3 != 0) {
      if (uVar7 != 5) goto LAB_081cccc2;
LAB_081ccba7:
      pcVar11 = "NULL\n";
      goto LAB_081ccbaf;
    }
    pcVar11 = ASN1_tag2str(uVar7);
    if (uVar7 == 5) goto LAB_081ccba7;
    if ((pcVar11 != (char *)0x0) &&
       ((iVar8 = BIO_puts(out,pcVar11), iVar8 < 1 || (iVar8 = BIO_puts(out,":"), iVar8 < 1))))
    goto LAB_081cc9d8;
LAB_081cccc2:
    switch(uVar7) {
    case 1:
      pAVar10 = (ASN1_OBJECT *)*piVar4;
      if ((pAVar10 == (ASN1_OBJECT *)0xffffffff) &&
         (pAVar10 = (ASN1_OBJECT *)it->size, pAVar10 == (ASN1_OBJECT *)0xffffffff)) {
        pcVar11 = "BOOL ABSENT";
      }
      else {
        pcVar11 = "FALSE";
        if (pAVar10 != (ASN1_OBJECT *)0x0) {
          pcVar11 = "TRUE";
        }
      }
      iVar8 = BIO_puts(out,pcVar11);
      if (iVar8 < 1) {
        uVar7 = 0;
        goto LAB_081cc880;
      }
      goto LAB_081ccced;
    case 2:
    case 10:
      pcVar11 = i2s_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,a);
      if (pcVar11 == (char *)0x0) goto LAB_081cc9d8;
      iVar8 = BIO_puts(out,pcVar11);
      uVar7 = (uint)(0 < iVar8);
      CRYPTO_free(pcVar11);
      break;
    case 3:
    case 4:
      if (a->type == 3) {
        iVar8 = BIO_printf(out," (%ld unused bits)\n",a->flags & 7);
        if (iVar8 < 1) {
          uVar7 = 0;
          goto LAB_081cc880;
        }
      }
      else {
        iVar8 = BIO_puts(out,"\n");
        if (iVar8 < 1) goto LAB_081cc9d8;
      }
      if (a->length < 1) goto LAB_081ccb68;
      iVar8 = BIO_dump_indent(out,(char *)a->data,a->length,indent + 2);
      goto joined_r0x081ccb5b;
    case 6:
      pAVar10 = (ASN1_OBJECT *)*piVar4;
      iVar8 = OBJ_obj2nid(pAVar10);
      pcVar11 = OBJ_nid2ln(iVar8);
      if (pcVar11 == (char *)0x0) {
        pcVar11 = "";
      }
      OBJ_obj2txt(local_70,0x50,pAVar10,1);
      iVar8 = BIO_printf(out,"%s (%s)",pcVar11,local_70);
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
      if (iVar8 < 1) goto LAB_081cc9d8;
      iVar8 = ASN1_parse_dump(out,a->data,a->length,indent,0);
      goto joined_r0x081ccb5b;
    default:
      uVar7 = ASN1_STRING_print_ex(out,a,*(uint *)((int)pctx + 0x10));
    }
    if (uVar7 != 0) {
LAB_081ccced:
      pcVar11 = "\n";
LAB_081ccbaf:
      iVar8 = BIO_puts(out,pcVar11);
joined_r0x081ccb5b:
      if (0 < iVar8) goto LAB_081ccb68;
    }
LAB_081cc9d8:
    uVar7 = 0;
    goto LAB_081cc880;
  }
  iVar8 = asn1_template_print_ctx(out,ppAVar9,indent,pAVar12,pctx);
  uVar7 = (uint)(iVar8 != 0);
LAB_081cc880:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7;
}

