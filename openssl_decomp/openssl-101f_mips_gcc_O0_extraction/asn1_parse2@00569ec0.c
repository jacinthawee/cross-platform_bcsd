
BIO * asn1_parse2(BIO *param_1,byte **param_2,int param_3,int param_4,uint param_5,int param_6,
                 int param_7)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  uint uVar5;
  int iVar6;
  ASN1_OCTET_STRING *a;
  ASN1_ENUMERATED *a_00;
  ASN1_OBJECT *pAVar7;
  byte *pbVar8;
  char *pcVar9;
  char *pcVar10;
  byte *pbVar11;
  int iVar12;
  int unaff_s3;
  int unaff_s4;
  uint uVar13;
  uint uVar14;
  byte **unaff_s7;
  byte **unaff_s8;
  undefined8 uVar15;
  int local_104;
  byte *local_100;
  long *local_f4;
  uint *local_f0;
  uint *local_ec;
  char *local_e8;
  char *local_e0;
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
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_c4 = *param_2;
  local_b0 = (ASN1_OBJECT *)0x0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  pbVar4 = local_c4 + param_3;
  if (pbVar4 <= local_c4) {
    param_1 = (BIO *)0x1;
    param_4 = unaff_s3;
    param_6 = unaff_s4;
    goto LAB_0056a084;
  }
  local_ec = &local_b4;
  local_f0 = &local_b8;
  local_e8 = "r";
  local_f4 = &local_bc;
  unaff_s8 = &local_c4;
  local_d4 = "d=%-2d hl=%ld l=inf  ";
  local_e0 = "r";
  local_cc = tag2str_7235;
  local_d0 = &DAT_00635448;
  unaff_s7 = param_2;
  do {
    pbVar11 = local_c4;
    uVar5 = ASN1_get_object(unaff_s8,local_f4,(int *)local_f0,(int *)local_ec,param_3);
    uVar13 = uVar5 & 0x80;
    if (uVar13 == 0) {
      local_100 = local_c4 + -(int)pbVar11;
      local_104 = param_3 - (int)local_100;
      iVar6 = (*(code *)PTR_BIO_printf_006a7f38)
                        (param_1,local_e8 + -0x4f00,pbVar11 + (param_4 - (int)*unaff_s7));
      if (iVar6 < 1) goto LAB_0056a204;
      if (uVar5 == 0x21) {
        iVar6 = (*(code *)PTR_BIO_printf_006a7f38)(param_1,local_d4,param_5,local_100);
        if (iVar6 < 1) goto LAB_0056a204;
        if (param_6 == 0) {
          uVar14 = 0x20;
          goto LAB_0056a260;
        }
        uVar14 = 0x20;
        pcVar9 = local_e0 + -0x4f30;
        uVar13 = param_5;
      }
      else {
        iVar6 = (*(code *)PTR_BIO_printf_006a7f38)
                          (param_1,"d=%-2d hl=%ld l=%4ld ",param_5,local_100,local_bc);
        if (iVar6 < 1) goto LAB_0056a204;
        uVar14 = uVar5 & 0x20;
        uVar13 = param_5;
        if (param_6 == 0) {
          uVar13 = 0;
        }
        if (uVar14 == 0) {
          pcVar9 = "prim: ";
        }
        else {
LAB_0056a260:
          pcVar9 = local_e0 + -0x4f30;
        }
      }
      uVar3 = local_b4;
      uVar2 = local_b8;
      iVar6 = (*(code *)PTR_BIO_write_006a7f14)(param_1,pcVar9,6);
      if (5 < iVar6) {
        (*(code *)PTR_BIO_indent_006a97d0)(param_1,uVar13,0x80);
        if ((uVar3 & 0xc0) == 0xc0) {
          pcVar9 = "priv [ %d ] ";
LAB_0056a428:
          pcVar10 = acStack_ac;
          (*(code *)PTR_BIO_snprintf_006a8060)(pcVar10,0x80,pcVar9,uVar2);
        }
        else {
          if ((uVar3 & 0x80) != 0) {
            pcVar9 = "cont [ %d ]";
            goto LAB_0056a428;
          }
          if ((uVar3 & 0x40) != 0) {
            pcVar9 = "appl [ %d ]";
            goto LAB_0056a428;
          }
          if (0x1e < (int)uVar2) {
            pcVar9 = "<ASN1 %d>";
            goto LAB_0056a428;
          }
          if (uVar2 < 0x1f) {
            pcVar10 = *(char **)(local_cc + uVar2 * 4);
          }
          else {
            pcVar10 = "(unknown)";
          }
        }
        iVar6 = (*(code *)PTR_BIO_printf_006a7f38)(param_1,"%-18s",pcVar10);
        if (0 < iVar6) {
          if (uVar14 == 0) {
            if (local_b4 == 0) {
              uVar13 = local_b8;
              if (0x1a < local_b8) goto LAB_0056a170;
              uVar15 = CONCAT44(local_b8,6);
              if ((0x5dc1000U >> (local_b8 & 0x1f) & 1) == 0) goto LAB_0056aa00;
              iVar6 = (*(code *)PTR_BIO_write_006a7f14)(param_1,":",1);
              if (iVar6 < 1) goto LAB_0056a204;
              if (local_bc < 1) goto LAB_0056a3d4;
              iVar6 = (*(code *)PTR_BIO_write_006a7f14)(param_1,local_c4);
              if (iVar6 != local_bc) goto LAB_0056a204;
              goto LAB_0056a3d4;
            }
            local_c4 = local_c4 + local_bc;
            iVar6 = (*(code *)PTR_BIO_write_006a7f14)(param_1,"\n",1);
            if (iVar6 < 1) goto LAB_0056a204;
            goto LAB_0056a318;
          }
          pbVar8 = local_c4 + local_bc;
          iVar6 = (*(code *)PTR_BIO_write_006a7f14)(param_1,"\n",1);
          if (iVar6 < 1) goto LAB_0056a204;
          if (local_104 < local_bc) {
            (*(code *)PTR_BIO_printf_006a7f38)(param_1,"length is greater than %ld\n",local_104);
            param_1 = (BIO *)0x0;
          }
          else {
            if ((uVar5 != 0x21) || (local_bc != 0)) {
              do {
                if (pbVar8 <= local_c4) goto LAB_0056a318;
                iVar6 = asn1_parse2(param_1,unaff_s8,local_bc,local_c4 + (param_4 - (int)*unaff_s7),
                                    param_5 + 1,param_6,param_7);
                if (iVar6 == 0) goto LAB_0056a204;
              } while( true );
            }
            while (iVar6 = asn1_parse2(param_1,unaff_s8,(int)pbVar4 - (int)local_c4,
                                       local_c4 + (param_4 - (int)*unaff_s7),param_5 + 1,param_6,
                                       param_7), iVar6 != 0) {
              local_100 = pbVar11;
              if (iVar6 == 2) goto LAB_0056a318;
              if (pbVar4 <= local_c4) goto LAB_0056a4f4;
            }
            local_100 = pbVar11;
            param_1 = (BIO *)0x0;
          }
          goto joined_r0x0056a074;
        }
      }
      param_1 = (BIO *)0x0;
    }
    else {
      (*(code *)PTR_BIO_write_006a7f14)(param_1,"Error in encoding\n",0x12);
      param_1 = (BIO *)0x0;
    }
joined_r0x0056a074:
    if (local_b0 != (ASN1_OBJECT *)0x0) {
      ASN1_OBJECT_free(local_b0);
    }
LAB_0056a084:
    while( true ) {
      pbVar11 = local_c4;
      *param_2 = local_c4;
      if (local_2c == *(int *)puVar1) {
        return param_1;
      }
      uVar15 = (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_0056aa00:
      uVar13 = (uint)((ulonglong)uVar15 >> 0x20);
      if (uVar13 == (uint)uVar15) {
        local_c0 = pbVar11;
        pAVar7 = d2i_ASN1_OBJECT(&local_b0,&local_c0,(long)(local_100 + local_bc));
        if (pAVar7 == (ASN1_OBJECT *)0x0) {
          iVar6 = (*(code *)PTR_BIO_write_006a7f14)(param_1,":BAD OBJECT",0xb);
          if (0 < iVar6) goto LAB_0056a3d4;
          param_1 = (BIO *)0x0;
          goto joined_r0x0056a074;
        }
        iVar6 = (*(code *)PTR_BIO_write_006a7f14)(param_1,":",1);
        if (iVar6 < 1) goto LAB_0056a204;
        i2a_ASN1_OBJECT(param_1,local_b0);
        goto LAB_0056a3d4;
      }
LAB_0056a170:
      if (uVar13 == 1) {
        local_c0 = pbVar11;
        iVar6 = (*(code *)PTR_d2i_ASN1_BOOLEAN_006a9f04)(0,&local_c0,local_100 + local_bc);
        if ((iVar6 < 0) &&
           (iVar12 = (*(code *)PTR_BIO_write_006a7f14)(param_1,"Bad boolean\n",0xc), iVar12 < 1)) {
          param_1 = (BIO *)0x0;
          goto joined_r0x0056a074;
        }
        (*(code *)PTR_BIO_printf_006a7f38)(param_1,":%d",iVar6);
        goto LAB_0056a3d4;
      }
      if (uVar13 == 0x1e) goto LAB_0056a3d4;
      if (uVar13 != 4) break;
      local_c0 = pbVar11;
      a = d2i_ASN1_OCTET_STRING((ASN1_OCTET_STRING **)0x0,&local_c0,(long)(local_100 + local_bc));
      if (a == (ASN1_OCTET_STRING *)0x0) goto LAB_0056a3d4;
      if (a->length < 1) {
LAB_0056a898:
        ASN1_STRING_free(a);
        goto LAB_0056a3d4;
      }
      local_c0 = a->data;
      pbVar8 = local_c0;
      do {
        uVar13 = (uint)*pbVar8;
        if (uVar13 < 0x20) {
          if ((uVar13 != 0xd) && (1 < uVar13 - 9)) goto LAB_0056a634;
        }
        else if (0x7e < uVar13) {
LAB_0056a634:
          if (param_7 == 0) {
            iVar6 = (*(code *)PTR_BIO_write_006a7f14)(param_1,"[HEX DUMP]:",0xb);
            if (iVar6 < 1) goto LAB_0056a6a8;
            iVar6 = 0;
            if (0 < a->length) goto LAB_0056a688;
            goto LAB_0056a898;
          }
          iVar6 = (*(code *)PTR_BIO_write_006a7f14)(param_1,"\n",1);
          if (iVar6 < 1) goto LAB_0056a6a8;
          if (param_7 == -1) {
            iVar6 = a->length;
          }
          else {
            iVar6 = a->length;
            if (param_7 <= a->length) {
              iVar6 = param_7;
            }
          }
          iVar6 = (*(code *)PTR_BIO_dump_indent_006a8434)(param_1,local_c0,iVar6,6);
          if (iVar6 < 1) goto LAB_0056a6a8;
          ASN1_STRING_free(a);
          goto LAB_0056a3f0;
        }
        pbVar8 = pbVar8 + 1;
      } while (pbVar8 != local_c0 + a->length);
      iVar6 = (*(code *)PTR_BIO_write_006a7f14)(param_1,":",1);
      if ((0 < iVar6) &&
         (iVar6 = (*(code *)PTR_BIO_write_006a7f14)(param_1,local_c0,a->length), 0 < iVar6))
      goto LAB_0056a898;
LAB_0056a6a8:
      if (local_b0 != (ASN1_OBJECT *)0x0) {
        ASN1_OBJECT_free(local_b0);
      }
      param_1 = (BIO *)0x0;
      ASN1_STRING_free(a);
    }
    if (uVar13 != 2) {
      if (uVar13 == 10) {
        local_c0 = pbVar11;
        a_00 = d2i_ASN1_ENUMERATED((ASN1_ENUMERATED **)0x0,&local_c0,(long)(local_100 + local_bc));
        if (a_00 == (ASN1_ENUMERATED *)0x0) {
          iVar6 = (*(code *)PTR_BIO_write_006a7f14)(param_1,"BAD ENUMERATED",0xb);
          if (0 < iVar6) goto LAB_0056a83c;
          param_1 = (BIO *)0x0;
          goto joined_r0x0056a074;
        }
        iVar6 = (*(code *)PTR_BIO_write_006a7f14)(param_1,":",1);
        if (0 < iVar6) {
          if ((a_00->type != 0x10a) ||
             (iVar6 = (*(code *)PTR_BIO_write_006a7f14)(param_1,&DAT_00662b74,1), 0 < iVar6)) {
            iVar6 = a_00->length;
            iVar12 = 0;
            if (0 < iVar6) {
              do {
                iVar6 = (*(code *)PTR_BIO_printf_006a7f38)(param_1,local_d0,a_00->data[iVar12]);
                if (iVar6 < 1) {
                  param_1 = (BIO *)0x0;
                  goto joined_r0x0056a074;
                }
                iVar6 = a_00->length;
                iVar12 = iVar12 + 1;
              } while (iVar12 < iVar6);
            }
            goto LAB_0056a834;
          }
          param_1 = (BIO *)0x0;
          goto joined_r0x0056a074;
        }
      }
      else {
        if ((local_bc < 1) || (param_7 == 0)) goto LAB_0056a3d4;
        iVar6 = (*(code *)PTR_BIO_write_006a7f14)(param_1,"\n",1);
        if (0 < iVar6) {
          iVar6 = local_bc;
          if ((param_7 != -1) && (param_7 <= local_bc)) {
            iVar6 = param_7;
          }
          iVar6 = (*(code *)PTR_BIO_dump_indent_006a8434)(param_1,local_c4,iVar6,6);
          goto joined_r0x0056a1fc;
        }
      }
LAB_0056a204:
      param_1 = (BIO *)0x0;
      goto joined_r0x0056a074;
    }
    local_c0 = pbVar11;
    a_00 = d2i_ASN1_INTEGER((ASN1_INTEGER **)0x0,&local_c0,(long)(local_100 + local_bc));
    if (a_00 == (ASN1_INTEGER *)0x0) {
      iVar6 = (*(code *)PTR_BIO_write_006a7f14)(param_1,"BAD INTEGER",0xb);
      if (0 < iVar6) goto LAB_0056a83c;
      param_1 = (BIO *)0x0;
      goto joined_r0x0056a074;
    }
    iVar6 = (*(code *)PTR_BIO_write_006a7f14)(param_1,":",1);
    if (iVar6 < 1) goto LAB_0056a204;
    if ((a_00->type == 0x102) &&
       (iVar6 = (*(code *)PTR_BIO_write_006a7f14)(param_1,&DAT_00662b74,1), iVar6 < 1)) {
      param_1 = (BIO *)0x0;
      goto joined_r0x0056a074;
    }
    iVar6 = a_00->length;
    iVar12 = 0;
    if (0 < iVar6) {
      do {
        iVar6 = (*(code *)PTR_BIO_printf_006a7f38)(param_1,local_d0,a_00->data[iVar12]);
        if (iVar6 < 1) {
          param_1 = (BIO *)0x0;
          goto joined_r0x0056a074;
        }
        iVar6 = a_00->length;
        iVar12 = iVar12 + 1;
      } while (iVar12 < iVar6);
    }
LAB_0056a834:
    if ((iVar6 == 0) && (iVar6 = (*(code *)PTR_BIO_write_006a7f14)(param_1,"00",2), iVar6 < 1)) {
      param_1 = (BIO *)0x0;
      goto joined_r0x0056a074;
    }
LAB_0056a83c:
    ASN1_STRING_free(a_00);
LAB_0056a3d4:
    iVar6 = (*(code *)PTR_BIO_write_006a7f14)(param_1,"\n",1);
joined_r0x0056a1fc:
    if (iVar6 < 1) goto LAB_0056a204;
LAB_0056a3f0:
    local_c4 = local_c4 + local_bc;
    if ((local_b8 == 0) && (local_b4 == 0)) {
      param_1 = (BIO *)&SUB_00000002;
      goto joined_r0x0056a074;
    }
LAB_0056a318:
    param_3 = local_104 - local_bc;
    if ((pbVar4 <= local_c4) || (local_c4 <= pbVar11)) {
LAB_0056a4f4:
      param_1 = (BIO *)0x1;
      goto joined_r0x0056a074;
    }
  } while( true );
LAB_0056a688:
  iVar12 = (*(code *)PTR_BIO_printf_006a7f38)(param_1,local_d0,local_c0[iVar6]);
  if (iVar12 < 1) goto LAB_0056a6a8;
  iVar6 = iVar6 + 1;
  if (a->length <= iVar6) goto LAB_0056a898;
  goto LAB_0056a688;
}

