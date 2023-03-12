
undefined4 __regparm3
asn1_parse2(BIO *param_1_00,byte **param_2_00,int param_3_00,int param_1,uint param_2,int param_3,
           int param_4)

{
  byte *pbVar1;
  byte bVar2;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  int iVar10;
  ASN1_OCTET_STRING *a;
  ASN1_ENUMERATED *a_00;
  ASN1_OBJECT *pAVar11;
  byte *pbVar12;
  undefined4 uVar13;
  uint uVar14;
  int in_GS_OFFSET;
  uint local_d8;
  byte *local_b8;
  byte *local_b4;
  int local_b0;
  uint local_ac;
  uint local_a8;
  ASN1_OBJECT *local_a4;
  char local_a0 [128];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_b8 = *param_2_00;
  local_a4 = (ASN1_OBJECT *)0x0;
  pbVar1 = local_b8 + param_3_00;
  if (local_b8 < pbVar1) {
LAB_08151cb4:
    pbVar3 = local_b8;
    uVar6 = ASN1_get_object(&local_b8,&local_b0,(int *)&local_ac,(int *)&local_a8,param_3_00);
    local_d8 = uVar6 & 0x80;
    if (local_d8 != 0) {
      uVar13 = 0;
      BIO_write(param_1_00,"Error in encoding\n",0x12);
      goto LAB_08151f14;
    }
    iVar7 = (int)local_b8 - (int)pbVar3;
    param_3_00 = param_3_00 - iVar7;
    iVar8 = BIO_printf(param_1_00,"%5ld:",pbVar3 + (param_1 - (int)*param_2_00));
    if (iVar8 < 1) goto LAB_08151f10;
    if (uVar6 == 0x21) {
      iVar8 = BIO_printf(param_1_00,"d=%-2d hl=%ld l=inf  ",param_2,iVar7);
      if (0 < iVar8) {
        if (param_3 == 0) {
          uVar14 = 0x20;
          pcVar9 = "cons: ";
        }
        else {
          uVar14 = 0x20;
          local_d8 = param_2;
          pcVar9 = "cons: ";
        }
        goto LAB_08151d8c;
      }
      goto LAB_08151f10;
    }
    iVar8 = BIO_printf(param_1_00,"d=%-2d hl=%ld l=%4ld ",param_2,iVar7,local_b0);
    if (iVar8 < 1) goto LAB_08151f10;
    if (param_3 != 0) {
      local_d8 = param_2;
    }
    uVar14 = uVar6 & 0x20;
    pcVar9 = "prim: ";
    if (uVar14 != 0) {
      pcVar9 = "cons: ";
    }
LAB_08151d8c:
    uVar5 = local_a8;
    uVar4 = local_ac;
    iVar8 = BIO_write(param_1_00,pcVar9,6);
    if (iVar8 < 6) {
LAB_08151da0:
      if (local_a4 == (ASN1_OBJECT *)0x0) {
        uVar13 = 0;
        goto LAB_08151db4;
      }
      uVar13 = 0;
      goto LAB_08151f20;
    }
    BIO_indent(param_1_00,local_d8,0x80);
    if ((uVar5 & 0xc0) == 0xc0) {
      pcVar9 = "priv [ %d ] ";
LAB_08152139:
      BIO_snprintf(local_a0,0x80,pcVar9,uVar4);
      pcVar9 = local_a0;
    }
    else {
      if ((uVar5 & 0x80) != 0) {
        pcVar9 = "cont [ %d ]";
        goto LAB_08152139;
      }
      if ((uVar5 & 0x40) != 0) {
        pcVar9 = "appl [ %d ]";
        goto LAB_08152139;
      }
      if (0x1e < (int)uVar4) {
        pcVar9 = "<ASN1 %d>";
        goto LAB_08152139;
      }
      pcVar9 = "(unknown)";
      if (uVar4 < 0x1f) {
        pcVar9 = *(char **)(tag2str_7215 + uVar4 * 4);
      }
    }
    iVar10 = BIO_printf(param_1_00,"%-18s",pcVar9);
    iVar8 = local_b0;
    pbVar12 = local_b8;
    if (iVar10 < 1) goto LAB_08151da0;
    if (uVar14 != 0) {
      iVar7 = BIO_write(param_1_00,&DAT_081f11d3,1);
      if (iVar7 < 1) goto LAB_08151f10;
      if (local_b0 <= param_3_00) {
        if ((local_b0 == 0) && (uVar6 == 0x21)) {
          while( true ) {
            iVar7 = asn1_parse2(local_b8 + (param_1 - (int)*param_2_00),param_2 + 1,param_3,param_4)
            ;
            if (iVar7 == 0) goto LAB_08151f10;
            if (iVar7 == 2) break;
            if (pbVar1 <= local_b8) goto LAB_08152226;
          }
        }
        else {
          while (local_b8 < pbVar12 + iVar8) {
            iVar7 = asn1_parse2(local_b8 + (param_1 - (int)*param_2_00),param_2 + 1,param_3,param_4)
            ;
            if (iVar7 == 0) goto LAB_08151f10;
          }
        }
        goto LAB_08152029;
      }
      uVar13 = 0;
      BIO_printf(param_1_00,"length is greater than %ld\n",param_3_00);
      goto LAB_08151f14;
    }
    if (local_a8 != 0) {
      local_b8 = local_b8 + local_b0;
      iVar7 = BIO_write(param_1_00,&DAT_081f11d3,1);
      if (iVar7 < 1) goto LAB_08151f10;
      goto LAB_08152029;
    }
    if (local_ac < 0x1b) {
      if ((0x5dc1000U >> (local_ac & 0x1f) & 1) != 0) {
        iVar7 = BIO_write(param_1_00,":",1);
        if ((0 < iVar7) &&
           ((local_b0 < 1 || (iVar7 = BIO_write(param_1_00,local_b8,local_b0), iVar7 == local_b0))))
        goto LAB_08151fec;
        goto LAB_08151f10;
      }
      if (local_ac != 6) goto LAB_08151e7b;
      local_b4 = pbVar3;
      pAVar11 = d2i_ASN1_OBJECT(&local_a4,&local_b4,iVar7 + local_b0);
      if (pAVar11 == (ASN1_OBJECT *)0x0) {
        iVar7 = BIO_write(param_1_00,":BAD OBJECT",0xb);
        if (0 < iVar7) goto LAB_08151fec;
      }
      else {
        iVar7 = BIO_write(param_1_00,":",1);
        if (0 < iVar7) {
          i2a_ASN1_OBJECT(param_1_00,local_a4);
          goto LAB_08151fec;
        }
      }
      goto LAB_08151f10;
    }
LAB_08151e7b:
    if (local_ac == 1) {
      local_b4 = pbVar3;
      iVar7 = d2i_ASN1_BOOLEAN((int *)0x0,&local_b4,iVar7 + local_b0);
      if ((-1 < iVar7) || (iVar8 = BIO_write(param_1_00,"Bad boolean\n",0xc), 0 < iVar8)) {
        BIO_printf(param_1_00,":%d",iVar7);
        goto LAB_08151fec;
      }
      goto LAB_08151f10;
    }
    if (local_ac == 0x1e) goto LAB_08151fec;
    if (local_ac != 4) {
      if (local_ac == 2) {
        local_b4 = pbVar3;
        a_00 = d2i_ASN1_INTEGER((ASN1_INTEGER **)0x0,&local_b4,iVar7 + local_b0);
        if (a_00 == (ASN1_INTEGER *)0x0) {
          iVar7 = 0xb;
          pcVar9 = "BAD INTEGER";
          goto LAB_081525c9;
        }
        iVar7 = BIO_write(param_1_00,":",1);
        if ((iVar7 < 1) ||
           ((a_00->type == 0x102 && (iVar7 = BIO_write(param_1_00,&DAT_0823b414,1), iVar7 < 1))))
        goto LAB_08151f10;
        iVar7 = a_00->length;
        iVar8 = 0;
        if (0 < iVar7) {
          do {
            iVar7 = BIO_printf(param_1_00,"%02X",(uint)a_00->data[iVar8]);
            if (iVar7 < 1) goto LAB_08151f10;
            iVar7 = a_00->length;
            iVar8 = iVar8 + 1;
          } while (iVar8 < iVar7);
        }
LAB_081524db:
        if (iVar7 == 0) {
          iVar7 = 2;
          pcVar9 = "00";
          goto LAB_081525c9;
        }
LAB_081524e3:
        ASN1_STRING_free(a_00);
        goto LAB_08151fec;
      }
      if (local_ac == 10) {
        local_b4 = pbVar3;
        a_00 = d2i_ASN1_ENUMERATED((ASN1_ENUMERATED **)0x0,&local_b4,iVar7 + local_b0);
        if (a_00 != (ASN1_ENUMERATED *)0x0) {
          iVar7 = BIO_write(param_1_00,":",1);
          if ((0 < iVar7) &&
             ((a_00->type != 0x10a || (iVar7 = BIO_write(param_1_00,&DAT_0823b414,1), 0 < iVar7))))
          {
            iVar7 = a_00->length;
            iVar8 = 0;
            if (0 < iVar7) {
              do {
                iVar7 = BIO_printf(param_1_00,"%02X",(uint)a_00->data[iVar8]);
                if (iVar7 < 1) goto LAB_08151f10;
                iVar7 = a_00->length;
                iVar8 = iVar8 + 1;
              } while (iVar8 < iVar7);
            }
            goto LAB_081524db;
          }
          goto LAB_08151f10;
        }
        iVar7 = 0xb;
        pcVar9 = "BAD ENUMERATED";
LAB_081525c9:
        iVar7 = BIO_write(param_1_00,pcVar9,iVar7);
        if (iVar7 < 1) goto LAB_08151f10;
        goto LAB_081524e3;
      }
      if ((local_b0 < 1) || (param_4 == 0)) goto LAB_08151fec;
      iVar7 = BIO_write(param_1_00,&DAT_081f11d3,1);
      if (iVar7 < 1) goto LAB_08151f10;
      if ((param_4 == -1) || (iVar7 = param_4, local_b0 < param_4)) {
        iVar7 = local_b0;
      }
      iVar7 = BIO_dump_indent(param_1_00,(char *)local_b8,iVar7,6);
      goto joined_r0x08151f07;
    }
    local_b4 = pbVar3;
    a = d2i_ASN1_OCTET_STRING((ASN1_OCTET_STRING **)0x0,&local_b4,iVar7 + local_b0);
    if (a == (ASN1_OCTET_STRING *)0x0) goto LAB_08151fec;
    if (a->length < 1) goto LAB_08152529;
    local_b4 = a->data;
    pbVar12 = local_b4;
    do {
      bVar2 = *pbVar12;
      if ((bVar2 < 0x20) && (bVar2 != 10)) {
        if ((bVar2 & 0xfb) != 9) {
LAB_08152321:
          if (param_4 == 0) {
            iVar7 = BIO_write(param_1_00,"[HEX DUMP]:",0xb);
            if (iVar7 < 1) goto LAB_08152381;
            if (a->length < 1) goto LAB_08152529;
            iVar7 = 0;
            goto LAB_08152363;
          }
          iVar7 = BIO_write(param_1_00,&DAT_081f11d3,1);
          if (iVar7 < 1) goto LAB_08152381;
          iVar7 = a->length;
          if ((param_4 != -1) && (param_4 <= iVar7)) {
            iVar7 = param_4;
          }
          iVar7 = BIO_dump_indent(param_1_00,(char *)local_b4,iVar7,6);
          if (iVar7 < 1) goto LAB_08152381;
          ASN1_STRING_free(a);
          goto LAB_08152007;
        }
      }
      else if (0x7e < bVar2) goto LAB_08152321;
      pbVar12 = pbVar12 + 1;
    } while (local_b4 + a->length != pbVar12);
    iVar7 = BIO_write(param_1_00,":",1);
    if ((iVar7 < 1) || (iVar7 = BIO_write(param_1_00,local_b4,a->length), iVar7 < 1)) {
LAB_08152381:
      if (local_a4 != (ASN1_OBJECT *)0x0) {
        ASN1_OBJECT_free(local_a4);
      }
      uVar13 = 0;
      ASN1_STRING_free(a);
      goto LAB_08151db4;
    }
    goto LAB_08152529;
  }
  uVar13 = 1;
  goto LAB_08151db4;
  while (iVar7 = iVar7 + 1, a->length != iVar7 && iVar7 <= a->length) {
LAB_08152363:
    iVar8 = BIO_printf(param_1_00,"%02X",(uint)local_b4[iVar7]);
    if (iVar8 < 1) goto LAB_08152381;
  }
LAB_08152529:
  ASN1_STRING_free(a);
LAB_08151fec:
  iVar7 = BIO_write(param_1_00,&DAT_081f11d3,1);
joined_r0x08151f07:
  if (iVar7 < 1) {
LAB_08151f10:
    uVar13 = 0;
    goto LAB_08151f14;
  }
LAB_08152007:
  local_b8 = local_b8 + local_b0;
  if ((local_ac == 0) && (local_a8 == 0)) {
    uVar13 = 2;
    goto LAB_08151f14;
  }
LAB_08152029:
  param_3_00 = param_3_00 - local_b0;
  if ((pbVar1 <= local_b8) || (local_b8 <= pbVar3)) goto LAB_08152226;
  goto LAB_08151cb4;
LAB_08152226:
  uVar13 = 1;
LAB_08151f14:
  if (local_a4 != (ASN1_OBJECT *)0x0) {
LAB_08151f20:
    ASN1_OBJECT_free(local_a4);
  }
LAB_08151db4:
  *param_2_00 = local_b8;
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar13;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

