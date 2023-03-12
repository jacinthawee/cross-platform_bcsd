
ASN1_TYPE * ASN1_generate_nconf(char *str,CONF *nconf)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  ASN1_TYPE *pAVar4;
  byte *pbVar5;
  uint uVar6;
  int iVar7;
  ASN1_OCTET_STRING *a;
  ASN1_ENUMERATED *a_00;
  ASN1_OBJECT *pAVar8;
  byte *pbVar9;
  X509V3_CTX *ctx;
  char *pcVar10;
  int in_a2;
  char *pcVar11;
  int in_a3;
  X509V3_CTX *unaff_s0;
  BIO *bp;
  byte *pbVar12;
  char *unaff_s2;
  int iVar13;
  int unaff_s3;
  int unaff_s4;
  undefined *puVar14;
  uint uVar15;
  X509V3_CTX *unaff_s7;
  byte **unaff_s8;
  undefined8 uVar16;
  int iStack_14c;
  byte *pbStack_148;
  long *plStack_13c;
  uint *puStack_138;
  uint *puStack_134;
  char *pcStack_130;
  char *pcStack_128;
  char *pcStack_11c;
  undefined *puStack_118;
  undefined1 *puStack_114;
  byte *pbStack_10c;
  byte *pbStack_108;
  int iStack_104;
  uint uStack_100;
  uint uStack_fc;
  ASN1_OBJECT *pAStack_f8;
  char acStack_f4 [128];
  int iStack_74;
  X509V3_CTX *pXStack_70;
  undefined *puStack_6c;
  char *pcStack_68;
  undefined *local_38;
  int iStack_34;
  X509V3_CTX XStack_30;
  BIO *local_14;
  
  puStack_6c = PTR___stack_chk_guard_006aabf0;
  local_38 = &_gp;
  local_14 = *(BIO **)PTR___stack_chk_guard_006aabf0;
  ctx = (X509V3_CTX *)nconf;
  pXStack_70 = unaff_s0;
  pcStack_68 = unaff_s2;
  if (nconf != (CONF *)0x0) {
    ctx = &XStack_30;
    X509V3_set_nconf(ctx,nconf);
    pXStack_70 = ctx;
    pcStack_68 = str;
  }
  pAVar4 = ASN1_generate_v3(str,ctx);
  if (local_14 == *(BIO **)puStack_6c) {
    return pAVar4;
  }
  bp = local_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  pbStack_10c = (byte *)ctx->flags;
  pAStack_f8 = (ASN1_OBJECT *)0x0;
  iStack_74 = *(int *)PTR___stack_chk_guard_006aabf0;
  pbVar5 = pbStack_10c + in_a2;
  if (pbVar5 <= pbStack_10c) {
    bp = (BIO *)0x1;
    in_a3 = unaff_s3;
    iStack_34 = unaff_s4;
    goto LAB_0056a084;
  }
  puStack_134 = &uStack_fc;
  puStack_138 = &uStack_100;
  pcStack_130 = "7 datafinal";
  plStack_13c = &iStack_104;
  unaff_s8 = &pbStack_10c;
  pcStack_11c = "d=%-2d hl=%ld l=inf  ";
  pcStack_128 = "7 datafinal";
  puStack_114 = tag2str_7235;
  puStack_118 = &DAT_00635448;
  unaff_s7 = ctx;
  do {
    pbVar12 = pbStack_10c;
    uVar6 = ASN1_get_object(unaff_s8,plStack_13c,(int *)puStack_138,(int *)puStack_134,in_a2);
    puVar14 = (undefined *)(uVar6 & 0x80);
    if (puVar14 == (undefined *)0x0) {
      pbStack_148 = pbStack_10c + -(int)pbVar12;
      iStack_14c = in_a2 - (int)pbStack_148;
      iVar7 = (*(code *)PTR_BIO_printf_006a7f38)
                        (bp,pcStack_130 + -0x4ee0,pbVar12 + (in_a3 - unaff_s7->flags));
      if (iVar7 < 1) goto LAB_0056a204;
      if (uVar6 == 0x21) {
        iVar7 = (*(code *)PTR_BIO_printf_006a7f38)(bp,pcStack_11c,&_gp,pbStack_148);
        if (iVar7 < 1) goto LAB_0056a204;
        if (iStack_34 == 0) {
          uVar15 = 0x20;
          goto LAB_0056a260;
        }
        uVar15 = 0x20;
        pcVar10 = pcStack_128 + -0x4f10;
        puVar14 = local_38;
      }
      else {
        iVar7 = (*(code *)PTR_BIO_printf_006a7f38)
                          (bp,"d=%-2d hl=%ld l=%4ld ",&_gp,pbStack_148,iStack_104);
        if (iVar7 < 1) goto LAB_0056a204;
        uVar15 = uVar6 & 0x20;
        puVar14 = local_38;
        if (iStack_34 == 0) {
          puVar14 = (undefined *)0x0;
        }
        if (uVar15 == 0) {
          pcVar10 = "prim: ";
        }
        else {
LAB_0056a260:
          pcVar10 = pcStack_128 + -0x4f10;
        }
      }
      uVar3 = uStack_fc;
      uVar2 = uStack_100;
      iVar7 = (*(code *)PTR_BIO_write_006a7f14)(bp,pcVar10,6);
      if (5 < iVar7) {
        (*(code *)PTR_BIO_indent_006a97d0)(bp,puVar14,0x80);
        if ((uVar3 & 0xc0) == 0xc0) {
          pcVar10 = "priv [ %d ] ";
LAB_0056a428:
          pcVar11 = acStack_f4;
          (*(code *)PTR_BIO_snprintf_006a8060)(pcVar11,0x80,pcVar10,uVar2);
        }
        else {
          if ((uVar3 & 0x80) != 0) {
            pcVar10 = "cont [ %d ]";
            goto LAB_0056a428;
          }
          if ((uVar3 & 0x40) != 0) {
            pcVar10 = "appl [ %d ]";
            goto LAB_0056a428;
          }
          if (0x1e < (int)uVar2) {
            pcVar10 = "<ASN1 %d>";
            goto LAB_0056a428;
          }
          if (uVar2 < 0x1f) {
            pcVar11 = *(char **)(puStack_114 + uVar2 * 4);
          }
          else {
            pcVar11 = "(unknown)";
          }
        }
        iVar7 = (*(code *)PTR_BIO_printf_006a7f38)(bp,"%-18s",pcVar11);
        if (0 < iVar7) {
          if (uVar15 == 0) {
            if (uStack_fc == 0) {
              uVar6 = uStack_100;
              if (0x1a < uStack_100) goto LAB_0056a170;
              uVar16 = CONCAT44(uStack_100,6);
              if ((0x5dc1000U >> (uStack_100 & 0x1f) & 1) == 0) goto LAB_0056aa00;
              iVar7 = (*(code *)PTR_BIO_write_006a7f14)(bp,":",1);
              if (iVar7 < 1) goto LAB_0056a204;
              if (iStack_104 < 1) goto LAB_0056a3d4;
              iVar7 = (*(code *)PTR_BIO_write_006a7f14)(bp,pbStack_10c);
              if (iVar7 != iStack_104) goto LAB_0056a204;
              goto LAB_0056a3d4;
            }
            pbStack_10c = pbStack_10c + iStack_104;
            iVar7 = (*(code *)PTR_BIO_write_006a7f14)(bp,"\n",1);
            if (iVar7 < 1) goto LAB_0056a204;
            goto LAB_0056a318;
          }
          pbVar9 = pbStack_10c + iStack_104;
          iVar13 = (*(code *)PTR_BIO_write_006a7f14)(bp,"\n",1);
          iVar7 = XStack_30.flags;
          if (iVar13 < 1) goto LAB_0056a204;
          if (iStack_14c < iStack_104) {
            (*(code *)PTR_BIO_printf_006a7f38)(bp,"length is greater than %ld\n",iStack_14c);
            bp = (BIO *)0x0;
          }
          else {
            if ((uVar6 != 0x21) || (iStack_104 != 0)) {
              do {
                if (pbVar9 <= pbStack_10c) goto LAB_0056a318;
                iVar13 = asn1_parse2(bp,unaff_s8,iStack_104,pbStack_10c + (in_a3 - unaff_s7->flags),
                                     &DAT_006afee1,iStack_34,iVar7);
                if (iVar13 == 0) goto LAB_0056a204;
              } while( true );
            }
            while (iVar13 = asn1_parse2(bp,unaff_s8,(int)pbVar5 - (int)pbStack_10c,
                                        pbStack_10c + (in_a3 - unaff_s7->flags),&DAT_006afee1,
                                        iStack_34,iVar7), iVar13 != 0) {
              pbStack_148 = pbVar12;
              if (iVar13 == 2) goto LAB_0056a318;
              if (pbVar5 <= pbStack_10c) goto LAB_0056a4f4;
            }
            pbStack_148 = pbVar12;
            bp = (BIO *)0x0;
          }
          goto joined_r0x0056a074;
        }
      }
      bp = (BIO *)0x0;
    }
    else {
      (*(code *)PTR_BIO_write_006a7f14)(bp,"Error in encoding\n",0x12);
      bp = (BIO *)0x0;
    }
joined_r0x0056a074:
    if (pAStack_f8 != (ASN1_OBJECT *)0x0) {
      ASN1_OBJECT_free(pAStack_f8);
    }
LAB_0056a084:
    while( true ) {
      pbVar12 = pbStack_10c;
      ctx->flags = (int)pbStack_10c;
      if (iStack_74 == *(int *)puVar1) {
        return (ASN1_TYPE *)bp;
      }
      uVar16 = (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_0056aa00:
      uVar6 = (uint)((ulonglong)uVar16 >> 0x20);
      if (uVar6 == (uint)uVar16) {
        pbStack_108 = pbVar12;
        pAVar8 = d2i_ASN1_OBJECT(&pAStack_f8,&pbStack_108,(long)(pbStack_148 + iStack_104));
        if (pAVar8 == (ASN1_OBJECT *)0x0) {
          iVar7 = (*(code *)PTR_BIO_write_006a7f14)(bp,":BAD OBJECT",0xb);
          if (0 < iVar7) goto LAB_0056a3d4;
          bp = (BIO *)0x0;
          goto joined_r0x0056a074;
        }
        iVar7 = (*(code *)PTR_BIO_write_006a7f14)(bp,":",1);
        if (iVar7 < 1) goto LAB_0056a204;
        i2a_ASN1_OBJECT(bp,pAStack_f8);
        goto LAB_0056a3d4;
      }
LAB_0056a170:
      if (uVar6 == 1) {
        pbStack_108 = pbVar12;
        iVar7 = (*(code *)PTR_d2i_ASN1_BOOLEAN_006a9f04)(0,&pbStack_108,pbStack_148 + iStack_104);
        if ((iVar7 < 0) &&
           (iVar13 = (*(code *)PTR_BIO_write_006a7f14)(bp,"Bad boolean\n",0xc), iVar13 < 1)) {
          bp = (BIO *)0x0;
          goto joined_r0x0056a074;
        }
        (*(code *)PTR_BIO_printf_006a7f38)(bp,":%d",iVar7);
        goto LAB_0056a3d4;
      }
      if (uVar6 == 0x1e) goto LAB_0056a3d4;
      if (uVar6 != 4) break;
      pbStack_108 = pbVar12;
      a = d2i_ASN1_OCTET_STRING
                    ((ASN1_OCTET_STRING **)0x0,&pbStack_108,(long)(pbStack_148 + iStack_104));
      if (a == (ASN1_OCTET_STRING *)0x0) goto LAB_0056a3d4;
      if (a->length < 1) {
LAB_0056a898:
        ASN1_STRING_free(a);
        goto LAB_0056a3d4;
      }
      pbStack_108 = a->data;
      pbVar9 = pbStack_108;
      do {
        uVar6 = (uint)*pbVar9;
        if (uVar6 < 0x20) {
          if ((uVar6 != 0xd) && (1 < uVar6 - 9)) goto LAB_0056a634;
        }
        else if (0x7e < uVar6) {
LAB_0056a634:
          if (XStack_30.flags == 0) {
            iVar7 = (*(code *)PTR_BIO_write_006a7f14)(bp,"[HEX DUMP]:",0xb);
            if (iVar7 < 1) goto LAB_0056a6a8;
            iVar7 = 0;
            if (0 < a->length) goto LAB_0056a688;
            goto LAB_0056a898;
          }
          iVar7 = (*(code *)PTR_BIO_write_006a7f14)(bp,"\n",1);
          if (iVar7 < 1) goto LAB_0056a6a8;
          if (XStack_30.flags == -1) {
            iVar7 = a->length;
          }
          else {
            iVar7 = a->length;
            if (XStack_30.flags <= a->length) {
              iVar7 = XStack_30.flags;
            }
          }
          iVar7 = (*(code *)PTR_BIO_dump_indent_006a8434)(bp,pbStack_108,iVar7,6);
          if (iVar7 < 1) goto LAB_0056a6a8;
          ASN1_STRING_free(a);
          goto LAB_0056a3f0;
        }
        pbVar9 = pbVar9 + 1;
      } while (pbVar9 != pbStack_108 + a->length);
      iVar7 = (*(code *)PTR_BIO_write_006a7f14)(bp,":",1);
      if ((0 < iVar7) &&
         (iVar7 = (*(code *)PTR_BIO_write_006a7f14)(bp,pbStack_108,a->length), 0 < iVar7))
      goto LAB_0056a898;
LAB_0056a6a8:
      if (pAStack_f8 != (ASN1_OBJECT *)0x0) {
        ASN1_OBJECT_free(pAStack_f8);
      }
      bp = (BIO *)0x0;
      ASN1_STRING_free(a);
    }
    if (uVar6 != 2) {
      if (uVar6 == 10) {
        pbStack_108 = pbVar12;
        a_00 = d2i_ASN1_ENUMERATED((ASN1_ENUMERATED **)0x0,&pbStack_108,
                                   (long)(pbStack_148 + iStack_104));
        if (a_00 == (ASN1_ENUMERATED *)0x0) {
          iVar7 = (*(code *)PTR_BIO_write_006a7f14)(bp,"BAD ENUMERATED",0xb);
          if (0 < iVar7) goto LAB_0056a83c;
          bp = (BIO *)0x0;
          goto joined_r0x0056a074;
        }
        iVar7 = (*(code *)PTR_BIO_write_006a7f14)(bp,":",1);
        if (0 < iVar7) {
          if ((a_00->type != 0x10a) ||
             (iVar7 = (*(code *)PTR_BIO_write_006a7f14)(bp,&DAT_00662b94,1), 0 < iVar7)) {
            iVar7 = a_00->length;
            iVar13 = 0;
            if (0 < iVar7) {
              do {
                iVar7 = (*(code *)PTR_BIO_printf_006a7f38)(bp,puStack_118,a_00->data[iVar13]);
                if (iVar7 < 1) {
                  bp = (BIO *)0x0;
                  goto joined_r0x0056a074;
                }
                iVar7 = a_00->length;
                iVar13 = iVar13 + 1;
              } while (iVar13 < iVar7);
            }
            goto LAB_0056a834;
          }
          bp = (BIO *)0x0;
          goto joined_r0x0056a074;
        }
      }
      else {
        if ((iStack_104 < 1) || (XStack_30.flags == 0)) goto LAB_0056a3d4;
        iVar7 = (*(code *)PTR_BIO_write_006a7f14)(bp,"\n",1);
        if (0 < iVar7) {
          iVar7 = iStack_104;
          if ((XStack_30.flags != -1) && (XStack_30.flags <= iStack_104)) {
            iVar7 = XStack_30.flags;
          }
          iVar7 = (*(code *)PTR_BIO_dump_indent_006a8434)(bp,pbStack_10c,iVar7,6);
          goto joined_r0x0056a1fc;
        }
      }
LAB_0056a204:
      bp = (BIO *)0x0;
      goto joined_r0x0056a074;
    }
    pbStack_108 = pbVar12;
    a_00 = d2i_ASN1_INTEGER((ASN1_INTEGER **)0x0,&pbStack_108,(long)(pbStack_148 + iStack_104));
    if (a_00 == (ASN1_INTEGER *)0x0) {
      iVar7 = (*(code *)PTR_BIO_write_006a7f14)(bp,"BAD INTEGER",0xb);
      if (0 < iVar7) goto LAB_0056a83c;
      bp = (BIO *)0x0;
      goto joined_r0x0056a074;
    }
    iVar7 = (*(code *)PTR_BIO_write_006a7f14)(bp,":",1);
    if (iVar7 < 1) goto LAB_0056a204;
    if ((a_00->type == 0x102) &&
       (iVar7 = (*(code *)PTR_BIO_write_006a7f14)(bp,&DAT_00662b94,1), iVar7 < 1)) {
      bp = (BIO *)0x0;
      goto joined_r0x0056a074;
    }
    iVar7 = a_00->length;
    iVar13 = 0;
    if (0 < iVar7) {
      do {
        iVar7 = (*(code *)PTR_BIO_printf_006a7f38)(bp,puStack_118,a_00->data[iVar13]);
        if (iVar7 < 1) {
          bp = (BIO *)0x0;
          goto joined_r0x0056a074;
        }
        iVar7 = a_00->length;
        iVar13 = iVar13 + 1;
      } while (iVar13 < iVar7);
    }
LAB_0056a834:
    if ((iVar7 == 0) && (iVar7 = (*(code *)PTR_BIO_write_006a7f14)(bp,"00",2), iVar7 < 1)) {
      bp = (BIO *)0x0;
      goto joined_r0x0056a074;
    }
LAB_0056a83c:
    ASN1_STRING_free(a_00);
LAB_0056a3d4:
    iVar7 = (*(code *)PTR_BIO_write_006a7f14)(bp,"\n",1);
joined_r0x0056a1fc:
    if (iVar7 < 1) goto LAB_0056a204;
LAB_0056a3f0:
    pbStack_10c = pbStack_10c + iStack_104;
    if ((uStack_100 == 0) && (uStack_fc == 0)) {
      bp = (BIO *)&SUB_00000002;
      goto joined_r0x0056a074;
    }
LAB_0056a318:
    in_a2 = iStack_14c - iStack_104;
    if ((pbVar5 <= pbStack_10c) || (pbStack_10c <= pbVar12)) {
LAB_0056a4f4:
      bp = (BIO *)0x1;
      goto joined_r0x0056a074;
    }
  } while( true );
LAB_0056a688:
  iVar13 = (*(code *)PTR_BIO_printf_006a7f38)(bp,puStack_118,pbStack_108[iVar7]);
  if (iVar13 < 1) goto LAB_0056a6a8;
  iVar7 = iVar7 + 1;
  if (a->length <= iVar7) goto LAB_0056a898;
  goto LAB_0056a688;
}

