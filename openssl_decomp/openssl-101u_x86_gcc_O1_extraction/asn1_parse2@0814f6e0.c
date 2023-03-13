
undefined4 __regparm3
asn1_parse2(BIO *param_1_00,byte **param_2_00,int param_3_00,int param_1,uint param_2,int param_3,
           int param_4)

{
  byte *pbVar1;
  byte bVar2;
  byte *pbVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  int iVar11;
  ASN1_OCTET_STRING *a;
  ASN1_ENUMERATED *a_00;
  ASN1_OBJECT *pAVar12;
  byte *pbVar13;
  uint indent;
  undefined4 uVar14;
  int in_GS_OFFSET;
  uint local_d0;
  byte *local_b8;
  byte *local_b4;
  int local_b0;
  uint local_ac;
  uint local_a8;
  ASN1_OBJECT *local_a4;
  char local_a0 [128];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_a4 = (ASN1_OBJECT *)0x0;
  if (0x80 < (int)param_2) {
    BIO_puts(param_1_00,"BAD RECURSION DEPTH\n");
    uVar14 = 0;
    goto LAB_0814f83f;
  }
  local_b8 = *param_2_00;
  pbVar1 = local_b8 + param_3_00;
  if (local_b8 < pbVar1) {
LAB_0814f733:
    pbVar3 = local_b8;
    uVar7 = ASN1_get_object(&local_b8,&local_b0,(int *)&local_ac,(int *)&local_a8,param_3_00);
    indent = uVar7 & 0x80;
    if (indent != 0) {
      uVar14 = 0;
      BIO_write(param_1_00,"Error in encoding\n",0x12);
      goto joined_r0x0814f958;
    }
    iVar8 = (int)local_b8 - (int)pbVar3;
    param_3_00 = param_3_00 - iVar8;
    iVar9 = BIO_printf(param_1_00,"%5ld:",pbVar3 + (param_1 - (int)*param_2_00));
    if (iVar9 < 1) goto LAB_0814f950;
    if (uVar7 == 0x21) {
      iVar9 = BIO_printf(param_1_00,"d=%-2d hl=%ld l=inf  ",param_2,iVar8);
      if (0 < iVar9) {
        if (param_3 == 0) {
          local_d0 = 0x20;
          pcVar10 = "cons: ";
        }
        else {
          local_d0 = 0x20;
          pcVar10 = "cons: ";
          indent = param_2;
        }
        goto LAB_0814f805;
      }
      goto LAB_0814f950;
    }
    iVar9 = BIO_printf(param_1_00,"d=%-2d hl=%ld l=%4ld ",param_2,iVar8,local_b0);
    if (iVar9 < 1) goto LAB_0814f950;
    if (param_3 != 0) {
      indent = param_2;
    }
    local_d0 = uVar7 & 0x20;
    pcVar10 = "prim: ";
    if (local_d0 != 0) {
      pcVar10 = "cons: ";
    }
LAB_0814f805:
    uVar6 = local_a8;
    uVar5 = local_ac;
    iVar9 = BIO_write(param_1_00,pcVar10,6);
    if (iVar9 < 6) {
LAB_0814f819:
      uVar14 = 0;
      goto joined_r0x0814f958;
    }
    BIO_indent(param_1_00,indent,0x80);
    if ((uVar6 & 0xc0) == 0xc0) {
      pcVar10 = "priv [ %d ] ";
LAB_0814f9e9:
      BIO_snprintf(local_a0,0x80,pcVar10,uVar5);
      pcVar10 = local_a0;
    }
    else {
      if ((uVar6 & 0x80) != 0) {
        pcVar10 = "cont [ %d ]";
        goto LAB_0814f9e9;
      }
      if ((uVar6 & 0x40) != 0) {
        pcVar10 = "appl [ %d ]";
        goto LAB_0814f9e9;
      }
      if (0x1e < (int)uVar5) {
        pcVar10 = "<ASN1 %d>";
        goto LAB_0814f9e9;
      }
      pcVar10 = "(unknown)";
      if (uVar5 < 0x1f) {
        pcVar10 = *(char **)(tag2str_7224 + uVar5 * 4);
      }
    }
    iVar11 = BIO_printf(param_1_00,"%-18s",pcVar10);
    iVar9 = local_b0;
    pbVar13 = local_b8;
    if (iVar11 < 1) goto LAB_0814f819;
    if (local_d0 != 0) {
      iVar8 = BIO_write(param_1_00,&DAT_081f15cb,1);
      pbVar4 = local_b8;
      if (iVar8 < 1) goto LAB_0814f950;
      if (local_b0 <= param_3_00) {
        if ((local_b0 == 0) && (uVar7 == 0x21)) {
          do {
            iVar8 = asn1_parse2(local_b8 + (param_1 - (int)*param_2_00),param_2 + 1,param_3,param_4)
            ;
            if (iVar8 == 0) goto LAB_0814f950;
          } while ((iVar8 != 2) && (local_b8 < pbVar1));
          local_b0 = (int)local_b8 - (int)pbVar4;
        }
        else {
          while (local_b8 < pbVar13 + iVar9) {
            iVar8 = asn1_parse2(local_b8 + (param_1 - (int)*param_2_00),param_2 + 1,param_3,param_4)
            ;
            if (iVar8 == 0) goto LAB_0814f950;
          }
        }
        goto LAB_0814fb61;
      }
      uVar14 = 0;
      BIO_printf(param_1_00,"length is greater than %ld\n",param_3_00);
      goto joined_r0x0814f958;
    }
    if (local_a8 != 0) {
      local_b8 = local_b8 + local_b0;
      iVar8 = BIO_write(param_1_00,&DAT_081f15cb,1);
      if (iVar8 < 1) goto LAB_0814f950;
      goto LAB_0814fb61;
    }
    if (local_ac < 0x1b) {
      if ((0x5dc1000U >> (local_ac & 0x1f) & 1) != 0) {
        iVar8 = BIO_write(param_1_00,":",1);
        if ((0 < iVar8) &&
           ((local_b0 < 1 || (iVar8 = BIO_write(param_1_00,local_b8,local_b0), iVar8 == local_b0))))
        goto LAB_0814fb24;
        goto LAB_0814f950;
      }
      if (local_ac != 6) goto LAB_0814fa3e;
      local_b4 = pbVar3;
      pAVar12 = d2i_ASN1_OBJECT(&local_a4,&local_b4,iVar8 + local_b0);
      if (pAVar12 == (ASN1_OBJECT *)0x0) {
        iVar8 = BIO_write(param_1_00,":BAD OBJECT",0xb);
        if (0 < iVar8) goto LAB_0814fb24;
      }
      else {
        iVar8 = BIO_write(param_1_00,":",1);
        if (0 < iVar8) {
          i2a_ASN1_OBJECT(param_1_00,local_a4);
          goto LAB_0814fb24;
        }
      }
      goto LAB_0814f950;
    }
LAB_0814fa3e:
    if (local_ac == 1) {
      local_b4 = pbVar3;
      iVar8 = d2i_ASN1_BOOLEAN((int *)0x0,&local_b4,iVar8 + local_b0);
      if ((-1 < iVar8) || (iVar9 = BIO_write(param_1_00,"Bad boolean\n",0xc), 0 < iVar9)) {
        BIO_printf(param_1_00,":%d",iVar8);
        goto LAB_0814fb24;
      }
      goto LAB_0814f950;
    }
    if (local_ac == 0x1e) goto LAB_0814fb24;
    if (local_ac != 4) {
      if (local_ac == 2) {
        local_b4 = pbVar3;
        a_00 = d2i_ASN1_INTEGER((ASN1_INTEGER **)0x0,&local_b4,iVar8 + local_b0);
        if (a_00 == (ASN1_INTEGER *)0x0) {
          iVar8 = 0xb;
          pcVar10 = "BAD INTEGER";
          goto LAB_0814fffa;
        }
        iVar8 = BIO_write(param_1_00,":",1);
        if ((iVar8 < 1) ||
           ((a_00->type == 0x102 && (iVar8 = BIO_write(param_1_00,&DAT_0823b914,1), iVar8 < 1))))
        goto LAB_0814f950;
        iVar8 = a_00->length;
        iVar9 = 0;
        if (0 < iVar8) {
          do {
            iVar8 = BIO_printf(param_1_00,"%02X",(uint)a_00->data[iVar9]);
            if (iVar8 < 1) goto LAB_0814f950;
            iVar8 = a_00->length;
            iVar9 = iVar9 + 1;
          } while (iVar9 < iVar8);
        }
LAB_0814ff73:
        if (iVar8 == 0) {
          iVar8 = 2;
          pcVar10 = "00";
          goto LAB_0814fffa;
        }
LAB_0814ff77:
        ASN1_STRING_free(a_00);
        goto LAB_0814fb24;
      }
      if (local_ac == 10) {
        local_b4 = pbVar3;
        a_00 = d2i_ASN1_ENUMERATED((ASN1_ENUMERATED **)0x0,&local_b4,iVar8 + local_b0);
        if (a_00 != (ASN1_ENUMERATED *)0x0) {
          iVar8 = BIO_write(param_1_00,":",1);
          if ((0 < iVar8) &&
             ((a_00->type != 0x10a || (iVar8 = BIO_write(param_1_00,&DAT_0823b914,1), 0 < iVar8))))
          {
            iVar8 = a_00->length;
            iVar9 = 0;
            if (0 < iVar8) {
              do {
                iVar8 = BIO_printf(param_1_00,"%02X",(uint)a_00->data[iVar9]);
                if (iVar8 < 1) goto LAB_0814f950;
                iVar8 = a_00->length;
                iVar9 = iVar9 + 1;
              } while (iVar9 < iVar8);
            }
            goto LAB_0814ff73;
          }
          goto LAB_0814f950;
        }
        iVar8 = 0xe;
        pcVar10 = "BAD ENUMERATED";
LAB_0814fffa:
        iVar8 = BIO_write(param_1_00,pcVar10,iVar8);
        if (iVar8 < 1) goto LAB_0814f950;
        goto LAB_0814ff77;
      }
      if ((local_b0 < 1) || (param_4 == 0)) goto LAB_0814fb24;
      iVar8 = BIO_write(param_1_00,&DAT_081f15cb,1);
      if (iVar8 < 1) goto LAB_0814f950;
      if ((param_4 == -1) || (iVar8 = param_4, local_b0 < param_4)) {
        iVar8 = local_b0;
      }
      iVar8 = BIO_dump_indent(param_1_00,(char *)local_b8,iVar8,6);
      goto joined_r0x0814face;
    }
    local_b4 = pbVar3;
    a = d2i_ASN1_OCTET_STRING((ASN1_OCTET_STRING **)0x0,&local_b4,iVar8 + local_b0);
    if (a == (ASN1_OCTET_STRING *)0x0) goto LAB_0814fb24;
    if (a->length < 1) goto LAB_0814ffbd;
    local_b4 = a->data;
    pbVar13 = local_b4;
    do {
      bVar2 = *pbVar13;
      if ((bVar2 < 0x20) && (bVar2 != 10)) {
        if ((bVar2 & 0xfb) != 9) {
LAB_0814fe51:
          if (param_4 == 0) {
            iVar8 = BIO_write(param_1_00,"[HEX DUMP]:",0xb);
            if (iVar8 < 1) goto LAB_0814feb1;
            if (a->length < 1) goto LAB_0814ffbd;
            iVar8 = 0;
            goto LAB_0814fe93;
          }
          iVar8 = BIO_write(param_1_00,&DAT_081f15cb,1);
          if (iVar8 < 1) goto LAB_0814feb1;
          iVar8 = a->length;
          if ((param_4 != -1) && (param_4 <= iVar8)) {
            iVar8 = param_4;
          }
          iVar8 = BIO_dump_indent(param_1_00,(char *)local_b4,iVar8,6);
          if (iVar8 < 1) goto LAB_0814feb1;
          ASN1_STRING_free(a);
          goto LAB_0814fb3f;
        }
      }
      else if (0x7e < bVar2) goto LAB_0814fe51;
      pbVar13 = pbVar13 + 1;
    } while (pbVar13 != local_b4 + a->length);
    iVar8 = BIO_write(param_1_00,":",1);
    if ((iVar8 < 1) || (iVar8 = BIO_write(param_1_00,local_b4,a->length), iVar8 < 1)) {
LAB_0814feb1:
      if (local_a4 != (ASN1_OBJECT *)0x0) {
        ASN1_OBJECT_free(local_a4);
      }
      uVar14 = 0;
      ASN1_STRING_free(a);
      goto LAB_0814f837;
    }
    goto LAB_0814ffbd;
  }
  uVar14 = 1;
  goto LAB_0814f837;
  while (iVar8 = iVar8 + 1, a->length != iVar8 && iVar8 <= a->length) {
LAB_0814fe93:
    iVar9 = BIO_printf(param_1_00,"%02X",(uint)local_b4[iVar8]);
    if (iVar9 < 1) goto LAB_0814feb1;
  }
LAB_0814ffbd:
  ASN1_STRING_free(a);
LAB_0814fb24:
  iVar8 = BIO_write(param_1_00,&DAT_081f15cb,1);
joined_r0x0814face:
  if (iVar8 < 1) {
LAB_0814f950:
    uVar14 = 0;
    goto joined_r0x0814f958;
  }
LAB_0814fb3f:
  local_b8 = local_b8 + local_b0;
  if ((local_ac == 0) && (local_a8 == 0)) {
    uVar14 = 2;
    goto joined_r0x0814f958;
  }
LAB_0814fb61:
  param_3_00 = param_3_00 - local_b0;
  if ((pbVar1 <= local_b8) || (local_b8 <= pbVar3)) goto LAB_0814fd9c;
  goto LAB_0814f733;
LAB_0814fd9c:
  uVar14 = 1;
joined_r0x0814f958:
  if (local_a4 != (ASN1_OBJECT *)0x0) {
    ASN1_OBJECT_free(local_a4);
  }
LAB_0814f837:
  *param_2_00 = local_b8;
LAB_0814f83f:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar14;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

