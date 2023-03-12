
BIO * asn1_parse2(BIO *param_1,byte **param_2,int param_3,int param_4,uint param_5,int param_6,
                 int param_7)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  ASN1_ENUMERATED *a;
  ASN1_OBJECT *pAVar6;
  byte *pbVar7;
  char *pcVar8;
  char *pcVar9;
  BIO *pBVar10;
  byte *unaff_s1;
  int iVar11;
  int unaff_s3;
  int unaff_s4;
  uint uVar12;
  byte *pbVar13;
  uint uVar14;
  byte **unaff_s7;
  byte **unaff_s8;
  byte *local_104;
  int local_100;
  int *local_f4;
  uint *local_f0;
  uint *local_ec;
  char *local_e8;
  byte *local_e4;
  char *local_dc;
  char *local_d4;
  undefined *local_d0;
  undefined1 *local_cc;
  byte *local_c4;
  byte *local_c0;
  int local_bc;
  uint local_b8;
  uint local_b4;
  ASN1_OBJECT *local_b0;
  char acStack_ac [128];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_b0 = (ASN1_OBJECT *)0x0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (0x80 < (int)param_5) {
    (*(code *)PTR_BIO_puts_006a6f58)(param_1,"BAD RECURSION DEPTH\n");
    pBVar10 = (BIO *)0x0;
    param_4 = unaff_s3;
    param_6 = unaff_s4;
    goto LAB_005666d0;
  }
  local_104 = *param_2;
  local_e4 = local_104 + param_3;
  local_c4 = local_104;
  if (local_e4 <= local_104) {
    pBVar10 = (BIO *)0x1;
    param_4 = unaff_s3;
    param_6 = unaff_s4;
    goto LAB_005666c8;
  }
  local_f0 = &local_b8;
  local_ec = &local_b4;
  local_e8 = "encrypt";
  local_f4 = &local_bc;
  unaff_s8 = &local_c4;
  local_d4 = "d=%-2d hl=%ld l=inf  ";
  local_dc = "encrypt";
  local_cc = tag2str_7244;
  local_d0 = &DAT_00634b80;
  unaff_s7 = param_2;
  do {
    pbVar7 = local_c4;
    local_104 = local_c4;
    uVar4 = ASN1_get_object(unaff_s8,local_f4,(int *)local_f0,(int *)local_ec,param_3);
    uVar12 = uVar4 & 0x80;
    if (uVar12 != 0) {
      (*(code *)PTR_BIO_write_006a6e14)(param_1,"Error in encoding\n",0x12);
      pBVar10 = (BIO *)0x0;
      goto LAB_00566878;
    }
    unaff_s1 = local_c4 + -(int)pbVar7;
    local_100 = param_3 - (int)unaff_s1;
    iVar5 = (*(code *)PTR_BIO_printf_006a6e38)
                      (param_1,local_e8 + -0x58f8,pbVar7 + (param_4 - (int)*unaff_s7));
    if (iVar5 < 1) goto LAB_00566874;
    if (uVar4 == 0x21) {
      iVar5 = (*(code *)PTR_BIO_printf_006a6e38)(param_1,local_d4,param_5,unaff_s1);
      if (iVar5 < 1) goto LAB_00566874;
      if (param_6 == 0) {
        uVar14 = 0x20;
        goto LAB_005667a8;
      }
      uVar14 = 0x20;
      pcVar8 = local_dc + -0x5940;
      uVar12 = param_5;
    }
    else {
      iVar5 = (*(code *)PTR_BIO_printf_006a6e38)
                        (param_1,"d=%-2d hl=%ld l=%4ld ",param_5,unaff_s1,local_bc);
      if (iVar5 < 1) goto LAB_00566874;
      uVar14 = uVar4 & 0x20;
      uVar12 = param_5;
      if (param_6 == 0) {
        uVar12 = 0;
      }
      if (uVar14 == 0) {
        pcVar8 = "prim: ";
      }
      else {
LAB_005667a8:
        pcVar8 = local_dc + -0x5940;
      }
    }
    uVar3 = local_b4;
    uVar2 = local_b8;
    iVar5 = (*(code *)PTR_BIO_write_006a6e14)(param_1,pcVar8,6);
    if (iVar5 < 6) goto LAB_005666a0;
    (*(code *)PTR_BIO_indent_006a86ac)(param_1,uVar12,0x80);
    if ((uVar3 & 0xc0) == 0xc0) {
      pcVar8 = "priv [ %d ] ";
LAB_005668b0:
      pcVar9 = acStack_ac;
      (*(code *)PTR_BIO_snprintf_006a6f60)(pcVar9,0x80,pcVar8,uVar2);
    }
    else {
      if ((uVar3 & 0x80) != 0) {
        pcVar8 = "cont [ %d ]";
        goto LAB_005668b0;
      }
      if ((uVar3 & 0x40) != 0) {
        pcVar8 = "appl [ %d ]";
        goto LAB_005668b0;
      }
      if (0x1e < (int)uVar2) {
        pcVar8 = "<ASN1 %d>";
        goto LAB_005668b0;
      }
      if (uVar2 < 0x1f) {
        pcVar9 = *(char **)(local_cc + uVar2 * 4);
      }
      else {
        pcVar9 = "(unknown)";
      }
    }
    iVar5 = (*(code *)PTR_BIO_printf_006a6e38)(param_1,"%-18s",pcVar9);
    if (iVar5 < 1) {
LAB_005666a0:
      if (local_b0 == (ASN1_OBJECT *)0x0) {
        pBVar10 = (BIO *)0x0;
        goto LAB_005666c8;
      }
      pBVar10 = (BIO *)0x0;
      goto LAB_005666b4;
    }
    if (uVar14 == 0) {
      if (local_b4 == 0) {
        uVar12 = local_b8;
        if (0x1a < local_b8) goto LAB_00566904;
        if ((0x5dc1000U >> (local_b8 & 0x1f) & 1) == 0) goto LAB_0056709c;
        iVar5 = (*(code *)PTR_BIO_write_006a6e14)(param_1,":",1);
        if (iVar5 < 1) goto LAB_00566874;
        if (local_bc < 1) goto LAB_00566a70;
        iVar5 = (*(code *)PTR_BIO_write_006a6e14)(param_1,local_c4);
        if (iVar5 != local_bc) goto LAB_00566874;
        goto LAB_00566a70;
      }
      local_c4 = local_c4 + local_bc;
      iVar5 = (*(code *)PTR_BIO_write_006a6e14)(param_1,"\n",1);
      if (iVar5 < 1) goto LAB_00566874;
    }
    else {
      pbVar13 = local_c4 + local_bc;
      iVar5 = (*(code *)PTR_BIO_write_006a6e14)(param_1,"\n",1);
      pbVar7 = local_c4;
      if (iVar5 < 1) goto LAB_00566874;
      if (local_100 < local_bc) {
        pBVar10 = (BIO *)0x0;
        (*(code *)PTR_BIO_printf_006a6e38)(param_1,"length is greater than %ld\n",local_100);
        goto LAB_00566878;
      }
      if ((uVar4 == 0x21) && (local_bc == 0)) {
        do {
          iVar5 = asn1_parse2(param_1,unaff_s8,(int)local_e4 - (int)local_c4,
                              local_c4 + (param_4 - (int)*unaff_s7),param_5 + 1,param_6,param_7);
          if (iVar5 == 0) {
            pBVar10 = (BIO *)0x0;
            goto LAB_00566878;
          }
        } while ((iVar5 != 2) && (local_c4 < local_e4));
        local_bc = (int)local_c4 - (int)pbVar7;
      }
      else {
        iVar5 = local_bc;
        while (local_c4 = pbVar7, pbVar7 < pbVar13) {
          iVar11 = asn1_parse2(param_1,unaff_s8,iVar5,pbVar7 + (param_4 - (int)*unaff_s7),
                               param_5 + 1,param_6,param_7);
          if (iVar11 == 0) goto LAB_00566874;
          iVar5 = iVar5 - ((int)local_c4 - (int)pbVar7);
          pbVar7 = local_c4;
        }
      }
    }
LAB_005669b4:
    param_3 = local_100 - local_bc;
    if ((local_e4 <= local_c4) || (local_c4 <= local_104)) {
      pBVar10 = (BIO *)0x1;
LAB_00566878:
      if (local_b0 != (ASN1_OBJECT *)0x0) {
LAB_005666b4:
        ASN1_OBJECT_free(local_b0);
      }
LAB_005666c8:
      while( true ) {
        *param_2 = local_c4;
        param_1 = pBVar10;
        unaff_s1 = local_c4;
LAB_005666d0:
        if (local_2c == *(int *)puVar1) {
          return pBVar10;
        }
        uVar12 = (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_0056709c:
        if (uVar12 == 6) {
          local_c0 = local_104;
          pAVar6 = d2i_ASN1_OBJECT(&local_b0,&local_c0,(long)(unaff_s1 + local_bc));
          if (pAVar6 == (ASN1_OBJECT *)0x0) {
            iVar5 = (*(code *)PTR_BIO_write_006a6e14)(param_1,":BAD OBJECT",0xb);
            if (0 < iVar5) goto LAB_00566a70;
            pBVar10 = (BIO *)0x0;
            goto LAB_00566878;
          }
          iVar5 = (*(code *)PTR_BIO_write_006a6e14)(param_1,":",1);
          if (iVar5 < 1) goto LAB_00566874;
          i2a_ASN1_OBJECT(param_1,local_b0);
          goto LAB_00566a70;
        }
LAB_00566904:
        if (uVar12 == 1) {
          local_c0 = local_104;
          iVar5 = (*(code *)PTR_d2i_ASN1_BOOLEAN_006a8de4)(0,&local_c0,unaff_s1 + local_bc);
          if ((iVar5 < 0) &&
             (iVar11 = (*(code *)PTR_BIO_write_006a6e14)(param_1,"Bad boolean\n",0xc), iVar11 < 1))
          {
            pBVar10 = (BIO *)0x0;
            goto LAB_00566878;
          }
          (*(code *)PTR_BIO_printf_006a6e38)(param_1,":%d",iVar5);
          goto LAB_00566a70;
        }
        if (uVar12 == 0x1e) goto LAB_00566a70;
        if (uVar12 != 4) break;
        local_c0 = local_104;
        a = d2i_ASN1_OCTET_STRING((ASN1_OCTET_STRING **)0x0,&local_c0,(long)(unaff_s1 + local_bc));
        if (a == (ASN1_OCTET_STRING *)0x0) goto LAB_00566a70;
        if (a->length < 1) goto LAB_00566dbc;
        local_c0 = a->data;
        pbVar7 = local_c0;
        do {
          uVar12 = (uint)*pbVar7;
          if (uVar12 < 0x20) {
            if ((uVar12 != 0xd) && (1 < uVar12 - 9)) goto LAB_00566cd4;
          }
          else if (0x7e < uVar12) {
LAB_00566cd4:
            if (param_7 == 0) {
              iVar5 = (*(code *)PTR_BIO_write_006a6e14)(param_1,"[HEX DUMP]:",0xb);
              if (iVar5 < 1) goto LAB_00566d48;
              if (a->length < 1) goto LAB_00566dbc;
              iVar5 = 0;
              goto LAB_00566d24;
            }
            iVar5 = (*(code *)PTR_BIO_write_006a6e14)(param_1,"\n",1);
            if (iVar5 < 1) goto LAB_00566d48;
            if (param_7 == -1) {
              iVar5 = a->length;
            }
            else {
              iVar5 = a->length;
              if (param_7 <= a->length) {
                iVar5 = param_7;
              }
            }
            iVar5 = (*(code *)PTR_BIO_dump_indent_006a7334)(param_1,local_c0,iVar5,6);
            if (iVar5 < 1) goto LAB_00566d48;
            ASN1_STRING_free(a);
            goto LAB_00566a8c;
          }
          pbVar7 = pbVar7 + 1;
        } while (pbVar7 != local_c0 + a->length);
        iVar5 = (*(code *)PTR_BIO_write_006a6e14)(param_1,":",1);
        if ((0 < iVar5) &&
           (iVar5 = (*(code *)PTR_BIO_write_006a6e14)(param_1,local_c0,a->length), 0 < iVar5))
        goto LAB_00566dbc;
LAB_00566d48:
        if (local_b0 != (ASN1_OBJECT *)0x0) {
          ASN1_OBJECT_free(local_b0);
        }
        pBVar10 = (BIO *)0x0;
        ASN1_STRING_free(a);
      }
      if (uVar12 == 2) {
        local_c0 = local_104;
        a = d2i_ASN1_INTEGER((ASN1_INTEGER **)0x0,&local_c0,(long)(unaff_s1 + local_bc));
        if (a == (ASN1_INTEGER *)0x0) {
          iVar5 = (*(code *)PTR_BIO_write_006a6e14)(param_1,"BAD INTEGER",0xb);
          if (0 < iVar5) goto LAB_00566dbc;
          pBVar10 = (BIO *)0x0;
        }
        else {
          iVar5 = (*(code *)PTR_BIO_write_006a6e14)(param_1,":",1);
          if (iVar5 < 1) goto LAB_00566874;
          if ((a->type == 0x102) &&
             (iVar5 = (*(code *)PTR_BIO_write_006a6e14)(param_1,&DAT_006621f4,1), iVar5 < 1)) {
            pBVar10 = (BIO *)0x0;
          }
          else {
            iVar5 = a->length;
            iVar11 = 0;
            if (0 < iVar5) {
              do {
                iVar5 = (*(code *)PTR_BIO_printf_006a6e38)(param_1,local_d0,a->data[iVar11]);
                if (iVar5 < 1) {
                  pBVar10 = (BIO *)0x0;
                  goto LAB_00566878;
                }
                iVar5 = a->length;
                iVar11 = iVar11 + 1;
              } while (iVar11 < iVar5);
            }
LAB_00566f2c:
            if ((iVar5 == 0) &&
               (iVar5 = (*(code *)PTR_BIO_write_006a6e14)(param_1,"00",2), iVar5 < 1)) {
              pBVar10 = (BIO *)0x0;
            }
            else {
LAB_00566dbc:
              ASN1_STRING_free(a);
LAB_00566a70:
              iVar5 = (*(code *)PTR_BIO_write_006a6e14)(param_1,"\n",1);
              if (iVar5 < 1) goto LAB_00566874;
LAB_00566a8c:
              local_c4 = local_c4 + local_bc;
              if ((local_b8 != 0) || (local_b4 != 0)) goto LAB_005669b4;
              pBVar10 = (BIO *)&SUB_00000002;
            }
          }
        }
        goto LAB_00566878;
      }
      if (uVar12 == 10) {
        local_c0 = local_104;
        a = d2i_ASN1_ENUMERATED((ASN1_ENUMERATED **)0x0,&local_c0,(long)(unaff_s1 + local_bc));
        if (a == (ASN1_ENUMERATED *)0x0) {
          iVar5 = (*(code *)PTR_BIO_write_006a6e14)(param_1,"BAD ENUMERATED",0xe);
          if (0 < iVar5) goto LAB_00566dbc;
          pBVar10 = (BIO *)0x0;
          goto LAB_00566878;
        }
        iVar5 = (*(code *)PTR_BIO_write_006a6e14)(param_1,":",1);
        if (0 < iVar5) {
          if ((a->type != 0x10a) ||
             (iVar5 = (*(code *)PTR_BIO_write_006a6e14)(param_1,&DAT_006621f4,1), 0 < iVar5)) {
            iVar5 = a->length;
            iVar11 = 0;
            if (0 < iVar5) {
              do {
                iVar5 = (*(code *)PTR_BIO_printf_006a6e38)(param_1,local_d0,a->data[iVar11]);
                if (iVar5 < 1) {
                  pBVar10 = (BIO *)0x0;
                  goto LAB_00566878;
                }
                iVar5 = a->length;
                iVar11 = iVar11 + 1;
              } while (iVar11 < iVar5);
            }
            goto LAB_00566f2c;
          }
          pBVar10 = (BIO *)0x0;
          goto LAB_00566878;
        }
      }
      else {
        if ((local_bc < 1) || (param_7 == 0)) goto LAB_00566a70;
        iVar5 = (*(code *)PTR_BIO_write_006a6e14)(param_1,"\n",1);
        if (0 < iVar5) {
          iVar5 = local_bc;
          if ((param_7 != -1) && (param_7 <= local_bc)) {
            iVar5 = param_7;
          }
          iVar5 = (*(code *)PTR_BIO_dump_indent_006a7334)(param_1,local_c4,iVar5,6);
          if (0 < iVar5) goto LAB_00566a8c;
          pBVar10 = (BIO *)0x0;
          goto LAB_00566878;
        }
      }
LAB_00566874:
      pBVar10 = (BIO *)0x0;
      goto LAB_00566878;
    }
  } while( true );
LAB_00566d24:
  iVar11 = (*(code *)PTR_BIO_printf_006a6e38)(param_1,local_d0,local_c0[iVar5]);
  if (iVar11 < 1) goto LAB_00566d48;
  iVar5 = iVar5 + 1;
  if (a->length <= iVar5) goto LAB_00566dbc;
  goto LAB_00566d24;
}

