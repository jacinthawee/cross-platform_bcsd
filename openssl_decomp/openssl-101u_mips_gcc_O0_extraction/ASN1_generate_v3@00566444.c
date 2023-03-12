
/* WARNING: Removing unreachable block (ram,0x00566f5c) */
/* WARNING: Removing unreachable block (ram,0x00566cdc) */
/* WARNING: Removing unreachable block (ram,0x00566cfc) */
/* WARNING: Removing unreachable block (ram,0x00566d08) */
/* WARNING: Removing unreachable block (ram,0x00566d24) */
/* WARNING: Removing unreachable block (ram,0x00566d10) */
/* WARNING: Removing unreachable block (ram,0x00567088) */

ASN1_TYPE * ASN1_generate_v3(char *str,X509V3_CTX *cnf)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  ASN1_TYPE *pAVar4;
  uint uVar5;
  int iVar6;
  ASN1_ENUMERATED *a;
  ASN1_OBJECT *pAVar7;
  BIO *bp;
  char *pcVar8;
  char *pcVar9;
  byte *pbVar10;
  undefined *puVar11;
  char *pcVar12;
  BIO *pBVar13;
  byte *unaff_s1;
  int iVar14;
  int *unaff_s3;
  int unaff_s4;
  uint uVar15;
  byte *pbVar16;
  byte *pbVar17;
  uint uVar18;
  X509V3_CTX *unaff_s7;
  byte **unaff_s8;
  byte *pbStack_13c;
  int iStack_138;
  byte **ppbStack_12c;
  uint *puStack_128;
  uint *puStack_124;
  char *pcStack_120;
  byte *pbStack_11c;
  char *pcStack_114;
  char *pcStack_10c;
  undefined *puStack_108;
  undefined1 *puStack_104;
  byte *pbStack_fc;
  byte *pbStack_f8;
  byte *pbStack_f4;
  uint uStack_f0;
  uint uStack_ec;
  ASN1_OBJECT *pAStack_e8;
  char acStack_e4 [128];
  int iStack_64;
  undefined *puStack_60;
  uint local_28;
  int iStack_24;
  undefined *local_20;
  int local_10;
  BIO *local_c;
  
  puStack_60 = PTR___stack_chk_guard_006a9ae8;
  pcVar12 = (char *)&local_10;
  local_20 = &_gp;
  local_10 = 0;
  local_c = *(BIO **)PTR___stack_chk_guard_006a9ae8;
  pAVar4 = (ASN1_TYPE *)generate_v3(str,cnf,0);
  iVar6 = local_10;
  if (local_10 != 0) {
    cnf = (X509V3_CTX *)&DAT_000000b2;
    pcVar12 = "asn1_gen.c";
    local_28 = 0x90;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
  }
  if (local_c == *(BIO **)puStack_60) {
    return pAVar4;
  }
  bp = local_c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  pAStack_e8 = (ASN1_OBJECT *)0x0;
  iStack_64 = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (0x80 < (int)local_28) {
    (*(code *)PTR_BIO_puts_006a6f58)();
    pBVar13 = (BIO *)0x0;
    pcVar12 = (char *)unaff_s3;
    iStack_24 = unaff_s4;
    goto LAB_005666d0;
  }
  pbStack_13c = (byte *)cnf->flags;
  pbStack_11c = pbStack_13c + iVar6;
  pbStack_fc = pbStack_13c;
  if (pbStack_11c <= pbStack_13c) {
    pBVar13 = (BIO *)0x1;
    pcVar12 = (char *)unaff_s3;
    iStack_24 = unaff_s4;
    goto LAB_005666c8;
  }
  puStack_128 = &uStack_f0;
  puStack_124 = &uStack_ec;
  pcStack_120 = "encrypt";
  ppbStack_12c = &pbStack_f4;
  unaff_s8 = &pbStack_fc;
  pcStack_10c = "d=%-2d hl=%ld l=inf  ";
  pcStack_114 = "encrypt";
  puStack_104 = tag2str_7244;
  puStack_108 = &DAT_00634b80;
  unaff_s7 = cnf;
  do {
    pbVar10 = pbStack_fc;
    pbStack_13c = pbStack_fc;
    uVar5 = ASN1_get_object(unaff_s8,(long *)ppbStack_12c,(int *)puStack_128,(int *)puStack_124,
                            iVar6);
    uVar15 = uVar5 & 0x80;
    if (uVar15 != 0) {
      (*(code *)PTR_BIO_write_006a6e14)(bp,"Error in encoding\n",0x12);
      pBVar13 = (BIO *)0x0;
      goto LAB_00566878;
    }
    unaff_s1 = pbStack_fc + -(int)pbVar10;
    iStack_138 = iVar6 - (int)unaff_s1;
    iVar6 = (*(code *)PTR_BIO_printf_006a6e38)
                      (bp,pcStack_120 + -0x58f8,
                       (char *)(((int)pbVar10 - unaff_s7->flags) + (int)pcVar12));
    if (iVar6 < 1) goto LAB_00566874;
    if (uVar5 == 0x21) {
      iVar6 = (*(code *)PTR_BIO_printf_006a6e38)(bp,pcStack_10c,local_28,unaff_s1);
      if (iVar6 < 1) goto LAB_00566874;
      if (iStack_24 == 0) {
        uVar18 = 0x20;
        goto LAB_005667a8;
      }
      uVar18 = 0x20;
      pcVar8 = pcStack_114 + -0x5940;
      uVar15 = local_28;
    }
    else {
      iVar6 = (*(code *)PTR_BIO_printf_006a6e38)
                        (bp,"d=%-2d hl=%ld l=%4ld ",local_28,unaff_s1,pbStack_f4);
      if (iVar6 < 1) goto LAB_00566874;
      uVar18 = uVar5 & 0x20;
      uVar15 = local_28;
      if (iStack_24 == 0) {
        uVar15 = 0;
      }
      if (uVar18 == 0) {
        pcVar8 = "prim: ";
      }
      else {
LAB_005667a8:
        pcVar8 = pcStack_114 + -0x5940;
      }
    }
    uVar3 = uStack_ec;
    uVar2 = uStack_f0;
    iVar6 = (*(code *)PTR_BIO_write_006a6e14)(bp,pcVar8,6);
    if (iVar6 < 6) goto LAB_005666a0;
    (*(code *)PTR_BIO_indent_006a86ac)(bp,uVar15,0x80);
    if ((uVar3 & 0xc0) == 0xc0) {
      pcVar8 = "priv [ %d ] ";
LAB_005668b0:
      pcVar9 = acStack_e4;
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
        pcVar9 = *(char **)(puStack_104 + uVar2 * 4);
      }
      else {
        pcVar9 = "(unknown)";
      }
    }
    iVar6 = (*(code *)PTR_BIO_printf_006a6e38)(bp,"%-18s",pcVar9);
    if (iVar6 < 1) {
LAB_005666a0:
      if (pAStack_e8 != (ASN1_OBJECT *)0x0) {
        pBVar13 = (BIO *)0x0;
        goto LAB_005666b4;
      }
      pBVar13 = (BIO *)0x0;
      goto LAB_005666c8;
    }
    if (uVar18 == 0) {
      if (uStack_ec == 0) {
        uVar15 = uStack_f0;
        if (0x1a < uStack_f0) goto LAB_00566904;
        if ((0x5dc1000U >> (uStack_f0 & 0x1f) & 1) == 0) goto LAB_0056709c;
        iVar6 = (*(code *)PTR_BIO_write_006a6e14)(bp,":",1);
        if (iVar6 < 1) goto LAB_00566874;
        if ((int)pbStack_f4 < 1) goto LAB_00566a6c;
        pbVar10 = (byte *)(*(code *)PTR_BIO_write_006a6e14)(bp,pbStack_fc);
        if (pbVar10 != pbStack_f4) goto LAB_00566874;
        goto LAB_00566a6c;
      }
      pbStack_fc = pbStack_fc + (int)pbStack_f4;
      iVar6 = (*(code *)PTR_BIO_write_006a6e14)(bp,"\n",1);
      if (iVar6 < 1) goto LAB_00566874;
    }
    else {
      pbVar16 = pbStack_fc + (int)pbStack_f4;
      iVar6 = (*(code *)PTR_BIO_write_006a6e14)(bp,"\n",1);
      pbVar10 = pbStack_fc;
      if (iVar6 < 1) goto LAB_00566874;
      if (iStack_138 < (int)pbStack_f4) {
        pBVar13 = (BIO *)0x0;
        (*(code *)PTR_BIO_printf_006a6e38)(bp,"length is greater than %ld\n",iStack_138);
        goto LAB_00566878;
      }
      if ((uVar5 == 0x21) && (pbStack_f4 == (byte *)0x0)) {
        do {
          iVar6 = asn1_parse2(bp,unaff_s8,(int)pbStack_11c - (int)pbStack_fc,
                              (char *)(((int)pbStack_fc - unaff_s7->flags) + (int)pcVar12),
                              local_28 + 1,iStack_24,&_gp);
          if (iVar6 == 0) {
            pBVar13 = (BIO *)0x0;
            goto LAB_00566878;
          }
        } while ((iVar6 != 2) && (pbStack_fc < pbStack_11c));
        pbStack_f4 = pbStack_fc + -(int)pbVar10;
      }
      else {
        pbVar17 = pbStack_f4;
        while (pbStack_fc = pbVar10, pbVar10 < pbVar16) {
          iVar6 = asn1_parse2(bp,unaff_s8,pbVar17,
                              (char *)(((int)pbVar10 - unaff_s7->flags) + (int)pcVar12),local_28 + 1
                              ,iStack_24,&_gp);
          if (iVar6 == 0) goto LAB_00566874;
          pbVar17 = pbVar17 + -((int)pbStack_fc - (int)pbVar10);
          pbVar10 = pbStack_fc;
        }
      }
    }
LAB_005669b4:
    iVar6 = iStack_138 - (int)pbStack_f4;
    if ((pbStack_11c <= pbStack_fc) || (pbStack_fc <= pbStack_13c)) {
      pBVar13 = (BIO *)0x1;
LAB_00566878:
      if (pAStack_e8 != (ASN1_OBJECT *)0x0) {
LAB_005666b4:
        ASN1_OBJECT_free(pAStack_e8);
      }
LAB_005666c8:
      while( true ) {
        cnf->flags = (int)pbStack_fc;
        bp = pBVar13;
        unaff_s1 = pbStack_fc;
LAB_005666d0:
        if (iStack_64 == *(int *)puVar1) {
          return (ASN1_TYPE *)pBVar13;
        }
        uVar15 = (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_0056709c:
        if (uVar15 == 6) {
          pbStack_f8 = pbStack_13c;
          pAVar7 = d2i_ASN1_OBJECT(&pAStack_e8,&pbStack_f8,(long)(unaff_s1 + (int)pbStack_f4));
          if (pAVar7 != (ASN1_OBJECT *)0x0) {
            iVar6 = (*(code *)PTR_BIO_write_006a6e14)(bp,":",1);
            if (iVar6 < 1) goto LAB_00566874;
            i2a_ASN1_OBJECT(bp,pAStack_e8);
            goto LAB_00566a6c;
          }
          iVar6 = (*(code *)PTR_BIO_write_006a6e14)(bp,":BAD OBJECT",0xb);
          if (0 < iVar6) goto LAB_00566a6c;
          pBVar13 = (BIO *)0x0;
          goto LAB_00566878;
        }
LAB_00566904:
        if (uVar15 == 1) {
          pbStack_f8 = pbStack_13c;
          iVar6 = (*(code *)PTR_d2i_ASN1_BOOLEAN_006a8de4)(0,&pbStack_f8,unaff_s1 + (int)pbStack_f4)
          ;
          if ((-1 < iVar6) ||
             (iVar14 = (*(code *)PTR_BIO_write_006a6e14)(bp,"Bad boolean\n",0xc), 0 < iVar14)) {
            (*(code *)PTR_BIO_printf_006a6e38)(bp,":%d",iVar6);
            goto LAB_00566a6c;
          }
          pBVar13 = (BIO *)0x0;
          goto LAB_00566878;
        }
        if (uVar15 == 0x1e) goto LAB_00566a6c;
        if (uVar15 != 4) break;
        pbStack_f8 = pbStack_13c;
        a = d2i_ASN1_OCTET_STRING
                      ((ASN1_OCTET_STRING **)0x0,&pbStack_f8,(long)(unaff_s1 + (int)pbStack_f4));
        if (a == (ASN1_OCTET_STRING *)0x0) goto LAB_00566a6c;
        if (a->length < 1) goto LAB_00566dbc;
        pbStack_f8 = a->data;
        pbVar10 = pbStack_f8;
        do {
          uVar15 = (uint)*pbVar10;
          if (uVar15 < 0x20) {
            if ((uVar15 != 0xd) && (1 < uVar15 - 9)) goto LAB_00566f90;
          }
          else if (0x7e < uVar15) {
LAB_00566f90:
            iVar6 = (*(code *)PTR_BIO_write_006a6e14)(bp,"\n",1);
            if (iVar6 < 1) goto LAB_00566d48;
            puVar11 = (undefined *)a->length;
            if (0x6aeddf < (int)(undefined *)a->length) {
              puVar11 = local_20;
            }
            iVar6 = (*(code *)PTR_BIO_dump_indent_006a7334)(bp,pbStack_f8,puVar11,6);
            if (iVar6 < 1) goto LAB_00566d48;
            ASN1_STRING_free(a);
            goto LAB_00566a8c;
          }
          pbVar10 = pbVar10 + 1;
        } while (pbVar10 != pbStack_f8 + a->length);
        iVar6 = (*(code *)PTR_BIO_write_006a6e14)(bp,":",1);
        if ((0 < iVar6) &&
           (iVar6 = (*(code *)PTR_BIO_write_006a6e14)(bp,pbStack_f8,a->length), 0 < iVar6))
        goto LAB_00566dbc;
LAB_00566d48:
        if (pAStack_e8 != (ASN1_OBJECT *)0x0) {
          ASN1_OBJECT_free(pAStack_e8);
        }
        pBVar13 = (BIO *)0x0;
        ASN1_STRING_free(a);
      }
      if (uVar15 == 2) {
        pbStack_f8 = pbStack_13c;
        a = d2i_ASN1_INTEGER((ASN1_INTEGER **)0x0,&pbStack_f8,(long)(unaff_s1 + (int)pbStack_f4));
        if (a == (ASN1_INTEGER *)0x0) {
          iVar6 = (*(code *)PTR_BIO_write_006a6e14)(bp,"BAD INTEGER",0xb);
          if (0 < iVar6) goto LAB_00566dbc;
          pBVar13 = (BIO *)0x0;
        }
        else {
          iVar6 = (*(code *)PTR_BIO_write_006a6e14)(bp,":",1);
          if (iVar6 < 1) goto LAB_00566874;
          if ((a->type == 0x102) &&
             (iVar6 = (*(code *)PTR_BIO_write_006a6e14)(bp,&DAT_006621f4,1), iVar6 < 1)) {
            pBVar13 = (BIO *)0x0;
          }
          else {
            iVar6 = a->length;
            iVar14 = 0;
            if (0 < iVar6) {
              do {
                iVar6 = (*(code *)PTR_BIO_printf_006a6e38)(bp,puStack_108,a->data[iVar14]);
                if (iVar6 < 1) {
                  pBVar13 = (BIO *)0x0;
                  goto LAB_00566878;
                }
                iVar6 = a->length;
                iVar14 = iVar14 + 1;
              } while (iVar14 < iVar6);
            }
LAB_00566f2c:
            if ((iVar6 == 0) && (iVar6 = (*(code *)PTR_BIO_write_006a6e14)(bp,"00",2), iVar6 < 1)) {
              pBVar13 = (BIO *)0x0;
            }
            else {
LAB_00566dbc:
              ASN1_STRING_free(a);
LAB_00566a6c:
              iVar6 = (*(code *)PTR_BIO_write_006a6e14)(bp,"\n",1);
              if (iVar6 < 1) goto LAB_00566874;
LAB_00566a8c:
              pbStack_fc = pbStack_fc + (int)pbStack_f4;
              if ((uStack_f0 != 0) || (uStack_ec != 0)) goto LAB_005669b4;
              pBVar13 = (BIO *)&SUB_00000002;
            }
          }
        }
        goto LAB_00566878;
      }
      if (uVar15 == 10) {
        pbStack_f8 = pbStack_13c;
        a = d2i_ASN1_ENUMERATED((ASN1_ENUMERATED **)0x0,&pbStack_f8,
                                (long)(unaff_s1 + (int)pbStack_f4));
        if (a == (ASN1_ENUMERATED *)0x0) {
          iVar6 = (*(code *)PTR_BIO_write_006a6e14)(bp,"BAD ENUMERATED",0xe);
          if (0 < iVar6) goto LAB_00566dbc;
          pBVar13 = (BIO *)0x0;
          goto LAB_00566878;
        }
        iVar6 = (*(code *)PTR_BIO_write_006a6e14)(bp,":",1);
        if (0 < iVar6) {
          if ((a->type != 0x10a) ||
             (iVar6 = (*(code *)PTR_BIO_write_006a6e14)(bp,&DAT_006621f4,1), 0 < iVar6)) {
            iVar6 = a->length;
            iVar14 = 0;
            if (0 < iVar6) {
              do {
                iVar6 = (*(code *)PTR_BIO_printf_006a6e38)(bp,puStack_108,a->data[iVar14]);
                if (iVar6 < 1) {
                  pBVar13 = (BIO *)0x0;
                  goto LAB_00566878;
                }
                iVar6 = a->length;
                iVar14 = iVar14 + 1;
              } while (iVar14 < iVar6);
            }
            goto LAB_00566f2c;
          }
          pBVar13 = (BIO *)0x0;
          goto LAB_00566878;
        }
      }
      else {
        if ((int)pbStack_f4 < 1) goto LAB_00566a6c;
        iVar6 = (*(code *)PTR_BIO_write_006a6e14)(bp,"\n",1);
        if (0 < iVar6) {
          pbVar10 = pbStack_f4;
          if (0x6aeddf < (int)pbStack_f4) {
            pbVar10 = &_gp;
          }
          iVar6 = (*(code *)PTR_BIO_dump_indent_006a7334)(bp,pbStack_fc,pbVar10,6);
          if (0 < iVar6) goto LAB_00566a8c;
          pBVar13 = (BIO *)0x0;
          goto LAB_00566878;
        }
      }
LAB_00566874:
      pBVar13 = (BIO *)0x0;
      goto LAB_00566878;
    }
  } while( true );
}

