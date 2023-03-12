
/* WARNING: Removing unreachable block (ram,0x00566f5c) */
/* WARNING: Removing unreachable block (ram,0x00566cdc) */
/* WARNING: Removing unreachable block (ram,0x00566cfc) */
/* WARNING: Removing unreachable block (ram,0x00566d08) */
/* WARNING: Removing unreachable block (ram,0x00566d24) */
/* WARNING: Removing unreachable block (ram,0x00566d10) */
/* WARNING: Removing unreachable block (ram,0x00567088) */

ASN1_TYPE * ASN1_generate_nconf(char *str,CONF *nconf)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  ASN1_TYPE *pAVar4;
  ASN1_TYPE *pAVar5;
  uint uVar6;
  int iVar7;
  ASN1_ENUMERATED *a;
  ASN1_OBJECT *pAVar8;
  BIO *bp;
  char *pcVar9;
  char *pcVar10;
  undefined *puVar11;
  char *pcVar12;
  CONF *unaff_s0;
  BIO *pBVar13;
  CONF_METHOD *pCVar14;
  int iVar15;
  char *unaff_s2;
  int *unaff_s3;
  int unaff_s4;
  uint uVar16;
  CONF_METHOD *pCVar17;
  uint uVar18;
  CONF *unaff_s7;
  CONF_METHOD **unaff_s8;
  CONF_METHOD *pCStack_19c;
  int iStack_198;
  undefined **ppuStack_18c;
  uint *puStack_188;
  uint *puStack_184;
  char *pcStack_180;
  CONF_METHOD *pCStack_17c;
  char *pcStack_174;
  char *pcStack_16c;
  undefined *puStack_168;
  undefined1 *puStack_164;
  CONF_METHOD *pCStack_15c;
  CONF_METHOD *pCStack_158;
  undefined *puStack_154;
  uint uStack_150;
  uint uStack_14c;
  ASN1_OBJECT *pAStack_148;
  char acStack_144 [128];
  int iStack_c4;
  undefined *puStack_c0;
  undefined *puStack_bc;
  char *pcStack_b8;
  uint uStack_88;
  int iStack_84;
  undefined *puStack_80;
  int iStack_70;
  BIO *pBStack_6c;
  CONF *pCStack_68;
  code *pcStack_64;
  undefined4 local_50;
  undefined *local_48;
  ASN1_TYPE *local_3c;
  CONF_METHOD *local_34;
  CONF local_30 [2];
  int local_14;
  
  pCVar14 = (CONF_METHOD *)PTR___stack_chk_guard_006a9ae8;
  local_48 = &_gp;
  local_14 = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (nconf == (CONF *)0x0) {
    local_30[0].meth = (CONF_METHOD *)0x0;
    pAVar4 = (ASN1_TYPE *)generate_v3(str,0,0,local_30);
    pcStack_b8 = unaff_s2;
    pCStack_68 = unaff_s0;
    pAVar5 = local_3c;
    pCVar17 = local_30[0].meth;
  }
  else {
    pCStack_68 = local_30;
    (*(code *)PTR_X509V3_set_nconf_006a6eb8)(pCStack_68);
    local_34 = (CONF_METHOD *)0x0;
    nconf = pCStack_68;
    pAVar4 = (ASN1_TYPE *)generate_v3(str,pCStack_68,0,&local_34);
    pcStack_b8 = str;
    pAVar5 = local_3c;
    pCVar17 = local_34;
  }
  local_3c = pAVar4;
  pAVar4 = local_3c;
  if (pCVar17 != (CONF_METHOD *)0x0) {
    nconf = (CONF *)&DAT_000000b2;
    local_50 = 0x90;
    (**(code **)(local_48 + -0x6eac))(0xd,0xb2,pCVar17,"asn1_gen.c");
    pAVar4 = local_3c;
    pAVar5 = local_3c;
  }
  local_3c = pAVar5;
  if (local_14 == *(int *)pCVar14) {
    return pAVar4;
  }
  pcStack_64 = ASN1_generate_v3;
  (**(code **)(local_48 + -0x5330))();
  puStack_c0 = PTR___stack_chk_guard_006a9ae8;
  pcVar12 = (char *)&iStack_70;
  puStack_80 = &_gp;
  iStack_70 = 0;
  pBStack_6c = *(BIO **)PTR___stack_chk_guard_006a9ae8;
  pAVar5 = (ASN1_TYPE *)generate_v3();
  iVar7 = iStack_70;
  if (iStack_70 != 0) {
    nconf = (CONF *)&DAT_000000b2;
    pcVar12 = "asn1_gen.c";
    uStack_88 = 0x90;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
  }
  if (pBStack_6c == *(BIO **)puStack_c0) {
    return pAVar5;
  }
  bp = pBStack_6c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  puStack_bc = (undefined *)pCVar14;
  pAStack_148 = (ASN1_OBJECT *)0x0;
  iStack_c4 = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (0x80 < (int)uStack_88) {
    (*(code *)PTR_BIO_puts_006a6f58)();
    pBVar13 = (BIO *)0x0;
    pcVar12 = (char *)unaff_s3;
    iStack_84 = unaff_s4;
    goto LAB_005666d0;
  }
  pCStack_19c = nconf->meth;
  pCStack_17c = (CONF_METHOD *)((int)&pCStack_19c->name + iVar7);
  pCStack_15c = pCStack_19c;
  if (pCStack_17c <= pCStack_19c) {
    pBVar13 = (BIO *)0x1;
    pcVar12 = (char *)unaff_s3;
    iStack_84 = unaff_s4;
    goto LAB_005666c8;
  }
  puStack_188 = &uStack_150;
  puStack_184 = &uStack_14c;
  pcStack_180 = "encrypt";
  ppuStack_18c = &puStack_154;
  unaff_s8 = &pCStack_15c;
  pcStack_16c = "d=%-2d hl=%ld l=inf  ";
  pcStack_174 = "encrypt";
  puStack_164 = tag2str_7244;
  puStack_168 = &DAT_00634b80;
  unaff_s7 = nconf;
  do {
    pCVar17 = pCStack_15c;
    pCStack_19c = pCStack_15c;
    uVar6 = ASN1_get_object((uchar **)unaff_s8,(long *)ppuStack_18c,(int *)puStack_188,
                            (int *)puStack_184,iVar7);
    uVar16 = uVar6 & 0x80;
    if (uVar16 != 0) {
      (*(code *)PTR_BIO_write_006a6e14)(bp,"Error in encoding\n",0x12);
      pBVar13 = (BIO *)0x0;
      goto LAB_00566878;
    }
    pCVar14 = (CONF_METHOD *)((int)pCStack_15c - (int)pCVar17);
    iStack_198 = iVar7 - (int)pCVar14;
    iVar7 = (*(code *)PTR_BIO_printf_006a6e38)
                      (bp,pcStack_180 + -0x58f8,
                       (char *)(((int)pCVar17 - (int)unaff_s7->meth) + (int)pcVar12));
    if (iVar7 < 1) goto LAB_00566874;
    if (uVar6 == 0x21) {
      iVar7 = (*(code *)PTR_BIO_printf_006a6e38)(bp,pcStack_16c,uStack_88,pCVar14);
      if (iVar7 < 1) goto LAB_00566874;
      if (iStack_84 == 0) {
        uVar18 = 0x20;
        goto LAB_005667a8;
      }
      uVar18 = 0x20;
      pcVar9 = pcStack_174 + -0x5940;
      uVar16 = uStack_88;
    }
    else {
      iVar7 = (*(code *)PTR_BIO_printf_006a6e38)
                        (bp,"d=%-2d hl=%ld l=%4ld ",uStack_88,pCVar14,puStack_154);
      if (iVar7 < 1) goto LAB_00566874;
      uVar18 = uVar6 & 0x20;
      uVar16 = uStack_88;
      if (iStack_84 == 0) {
        uVar16 = 0;
      }
      if (uVar18 == 0) {
        pcVar9 = "prim: ";
      }
      else {
LAB_005667a8:
        pcVar9 = pcStack_174 + -0x5940;
      }
    }
    uVar3 = uStack_14c;
    uVar2 = uStack_150;
    iVar7 = (*(code *)PTR_BIO_write_006a6e14)(bp,pcVar9,6);
    if (iVar7 < 6) goto LAB_005666a0;
    (*(code *)PTR_BIO_indent_006a86ac)(bp,uVar16,0x80);
    if ((uVar3 & 0xc0) == 0xc0) {
      pcVar9 = "priv [ %d ] ";
LAB_005668b0:
      pcVar10 = acStack_144;
      (*(code *)PTR_BIO_snprintf_006a6f60)(pcVar10,0x80,pcVar9,uVar2);
    }
    else {
      if ((uVar3 & 0x80) != 0) {
        pcVar9 = "cont [ %d ]";
        goto LAB_005668b0;
      }
      if ((uVar3 & 0x40) != 0) {
        pcVar9 = "appl [ %d ]";
        goto LAB_005668b0;
      }
      if (0x1e < (int)uVar2) {
        pcVar9 = "<ASN1 %d>";
        goto LAB_005668b0;
      }
      if (uVar2 < 0x1f) {
        pcVar10 = *(char **)(puStack_164 + uVar2 * 4);
      }
      else {
        pcVar10 = "(unknown)";
      }
    }
    iVar7 = (*(code *)PTR_BIO_printf_006a6e38)(bp,"%-18s",pcVar10);
    if (iVar7 < 1) {
LAB_005666a0:
      if (pAStack_148 != (ASN1_OBJECT *)0x0) {
        pBVar13 = (BIO *)0x0;
        goto LAB_005666b4;
      }
      pBVar13 = (BIO *)0x0;
      goto LAB_005666c8;
    }
    if (uVar18 == 0) {
      if (uStack_14c == 0) {
        uVar16 = uStack_150;
        if (0x1a < uStack_150) goto LAB_00566904;
        if ((0x5dc1000U >> (uStack_150 & 0x1f) & 1) == 0) goto LAB_0056709c;
        iVar7 = (*(code *)PTR_BIO_write_006a6e14)(bp,":",1);
        if (iVar7 < 1) goto LAB_00566874;
        if ((int)puStack_154 < 1) goto LAB_00566a6c;
        puVar11 = (undefined *)(*(code *)PTR_BIO_write_006a6e14)(bp,pCStack_15c);
        if (puVar11 != puStack_154) goto LAB_00566874;
        goto LAB_00566a6c;
      }
      pCStack_15c = (CONF_METHOD *)(puStack_154 + (int)&pCStack_15c->name);
      iVar7 = (*(code *)PTR_BIO_write_006a6e14)(bp,"\n",1);
      if (iVar7 < 1) goto LAB_00566874;
    }
    else {
      pCVar17 = (CONF_METHOD *)(puStack_154 + (int)&pCStack_15c->name);
      iVar7 = (*(code *)PTR_BIO_write_006a6e14)(bp,"\n",1);
      pCVar14 = pCStack_15c;
      if (iVar7 < 1) goto LAB_00566874;
      if (iStack_198 < (int)puStack_154) {
        pBVar13 = (BIO *)0x0;
        (*(code *)PTR_BIO_printf_006a6e38)(bp,"length is greater than %ld\n",iStack_198);
        goto LAB_00566878;
      }
      if ((uVar6 == 0x21) && (puStack_154 == (undefined *)0x0)) {
        do {
          iVar7 = asn1_parse2(bp,unaff_s8,(int)pCStack_17c - (int)pCStack_15c,
                              (char *)(((int)pCStack_15c - (int)unaff_s7->meth) + (int)pcVar12),
                              uStack_88 + 1,iStack_84,&_gp);
          if (iVar7 == 0) {
            pBVar13 = (BIO *)0x0;
            goto LAB_00566878;
          }
        } while ((iVar7 != 2) && (pCStack_15c < pCStack_17c));
        puStack_154 = (undefined *)((int)pCStack_15c - (int)pCVar14);
      }
      else {
        puVar11 = puStack_154;
        while (pCStack_15c = pCVar14, pCVar14 < pCVar17) {
          iVar7 = asn1_parse2(bp,unaff_s8,puVar11,
                              (char *)(((int)pCVar14 - (int)unaff_s7->meth) + (int)pcVar12),
                              uStack_88 + 1,iStack_84,&_gp);
          if (iVar7 == 0) goto LAB_00566874;
          puVar11 = puVar11 + -((int)pCStack_15c - (int)pCVar14);
          pCVar14 = pCStack_15c;
        }
      }
    }
LAB_005669b4:
    iVar7 = iStack_198 - (int)puStack_154;
    if ((pCStack_17c <= pCStack_15c) || (pCStack_15c <= pCStack_19c)) {
      pBVar13 = (BIO *)0x1;
LAB_00566878:
      if (pAStack_148 != (ASN1_OBJECT *)0x0) {
LAB_005666b4:
        ASN1_OBJECT_free(pAStack_148);
      }
LAB_005666c8:
      while( true ) {
        nconf->meth = pCStack_15c;
        bp = pBVar13;
        pCVar14 = pCStack_15c;
LAB_005666d0:
        if (iStack_c4 == *(int *)puVar1) {
          return (ASN1_TYPE *)pBVar13;
        }
        uVar16 = (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_0056709c:
        if (uVar16 == 6) {
          pCStack_158 = pCStack_19c;
          pAVar8 = d2i_ASN1_OBJECT(&pAStack_148,(uchar **)&pCStack_158,
                                   (long)(puStack_154 + (int)&pCVar14->name));
          if (pAVar8 != (ASN1_OBJECT *)0x0) {
            iVar7 = (*(code *)PTR_BIO_write_006a6e14)(bp,":",1);
            if (iVar7 < 1) goto LAB_00566874;
            i2a_ASN1_OBJECT(bp,pAStack_148);
            goto LAB_00566a6c;
          }
          iVar7 = (*(code *)PTR_BIO_write_006a6e14)(bp,":BAD OBJECT",0xb);
          if (0 < iVar7) goto LAB_00566a6c;
          pBVar13 = (BIO *)0x0;
          goto LAB_00566878;
        }
LAB_00566904:
        if (uVar16 == 1) {
          pCStack_158 = pCStack_19c;
          iVar7 = (*(code *)PTR_d2i_ASN1_BOOLEAN_006a8de4)
                            (0,&pCStack_158,puStack_154 + (int)&pCVar14->name);
          if ((-1 < iVar7) ||
             (iVar15 = (*(code *)PTR_BIO_write_006a6e14)(bp,"Bad boolean\n",0xc), 0 < iVar15)) {
            (*(code *)PTR_BIO_printf_006a6e38)(bp,":%d",iVar7);
            goto LAB_00566a6c;
          }
          pBVar13 = (BIO *)0x0;
          goto LAB_00566878;
        }
        if (uVar16 == 0x1e) goto LAB_00566a6c;
        if (uVar16 != 4) break;
        pCStack_158 = pCStack_19c;
        a = d2i_ASN1_OCTET_STRING
                      ((ASN1_OCTET_STRING **)0x0,(uchar **)&pCStack_158,
                       (long)(puStack_154 + (int)&pCVar14->name));
        if (a == (ASN1_OCTET_STRING *)0x0) goto LAB_00566a6c;
        if (a->length < 1) goto LAB_00566dbc;
        pCStack_158 = (CONF_METHOD *)a->data;
        pCVar14 = pCStack_158;
        do {
          uVar16 = (uint)*(byte *)&pCVar14->name;
          if (uVar16 < 0x20) {
            if ((uVar16 != 0xd) && (1 < uVar16 - 9)) goto LAB_00566f90;
          }
          else if (0x7e < uVar16) {
LAB_00566f90:
            iVar7 = (*(code *)PTR_BIO_write_006a6e14)(bp,"\n",1);
            if (iVar7 < 1) goto LAB_00566d48;
            puVar11 = (undefined *)a->length;
            if (0x6aeddf < (int)(undefined *)a->length) {
              puVar11 = puStack_80;
            }
            iVar7 = (*(code *)PTR_BIO_dump_indent_006a7334)(bp,pCStack_158,puVar11,6);
            if (iVar7 < 1) goto LAB_00566d48;
            ASN1_STRING_free(a);
            goto LAB_00566a8c;
          }
          pCVar14 = (CONF_METHOD *)((int)&pCVar14->name + 1);
        } while (pCVar14 != (CONF_METHOD *)((int)&pCStack_158->name + a->length));
        iVar7 = (*(code *)PTR_BIO_write_006a6e14)(bp,":",1);
        if ((0 < iVar7) &&
           (iVar7 = (*(code *)PTR_BIO_write_006a6e14)(bp,pCStack_158,a->length), 0 < iVar7))
        goto LAB_00566dbc;
LAB_00566d48:
        if (pAStack_148 != (ASN1_OBJECT *)0x0) {
          ASN1_OBJECT_free(pAStack_148);
        }
        pBVar13 = (BIO *)0x0;
        ASN1_STRING_free(a);
      }
      if (uVar16 == 2) {
        pCStack_158 = pCStack_19c;
        a = d2i_ASN1_INTEGER((ASN1_INTEGER **)0x0,(uchar **)&pCStack_158,
                             (long)(puStack_154 + (int)&pCVar14->name));
        if (a == (ASN1_INTEGER *)0x0) {
          iVar7 = (*(code *)PTR_BIO_write_006a6e14)(bp,"BAD INTEGER",0xb);
          if (0 < iVar7) goto LAB_00566dbc;
          pBVar13 = (BIO *)0x0;
        }
        else {
          iVar7 = (*(code *)PTR_BIO_write_006a6e14)(bp,":",1);
          if (iVar7 < 1) goto LAB_00566874;
          if ((a->type == 0x102) &&
             (iVar7 = (*(code *)PTR_BIO_write_006a6e14)(bp,&DAT_006621f4,1), iVar7 < 1)) {
            pBVar13 = (BIO *)0x0;
          }
          else {
            iVar7 = a->length;
            iVar15 = 0;
            if (0 < iVar7) {
              do {
                iVar7 = (*(code *)PTR_BIO_printf_006a6e38)(bp,puStack_168,a->data[iVar15]);
                if (iVar7 < 1) {
                  pBVar13 = (BIO *)0x0;
                  goto LAB_00566878;
                }
                iVar7 = a->length;
                iVar15 = iVar15 + 1;
              } while (iVar15 < iVar7);
            }
LAB_00566f2c:
            if ((iVar7 == 0) && (iVar7 = (*(code *)PTR_BIO_write_006a6e14)(bp,"00",2), iVar7 < 1)) {
              pBVar13 = (BIO *)0x0;
            }
            else {
LAB_00566dbc:
              ASN1_STRING_free(a);
LAB_00566a6c:
              iVar7 = (*(code *)PTR_BIO_write_006a6e14)(bp,"\n",1);
              if (iVar7 < 1) goto LAB_00566874;
LAB_00566a8c:
              pCStack_15c = (CONF_METHOD *)(puStack_154 + (int)&pCStack_15c->name);
              if ((uStack_150 != 0) || (uStack_14c != 0)) goto LAB_005669b4;
              pBVar13 = (BIO *)&SUB_00000002;
            }
          }
        }
        goto LAB_00566878;
      }
      if (uVar16 == 10) {
        pCStack_158 = pCStack_19c;
        a = d2i_ASN1_ENUMERATED((ASN1_ENUMERATED **)0x0,(uchar **)&pCStack_158,
                                (long)(puStack_154 + (int)&pCVar14->name));
        if (a == (ASN1_ENUMERATED *)0x0) {
          iVar7 = (*(code *)PTR_BIO_write_006a6e14)(bp,"BAD ENUMERATED",0xe);
          if (0 < iVar7) goto LAB_00566dbc;
          pBVar13 = (BIO *)0x0;
          goto LAB_00566878;
        }
        iVar7 = (*(code *)PTR_BIO_write_006a6e14)(bp,":",1);
        if (0 < iVar7) {
          if ((a->type != 0x10a) ||
             (iVar7 = (*(code *)PTR_BIO_write_006a6e14)(bp,&DAT_006621f4,1), 0 < iVar7)) {
            iVar7 = a->length;
            iVar15 = 0;
            if (0 < iVar7) {
              do {
                iVar7 = (*(code *)PTR_BIO_printf_006a6e38)(bp,puStack_168,a->data[iVar15]);
                if (iVar7 < 1) {
                  pBVar13 = (BIO *)0x0;
                  goto LAB_00566878;
                }
                iVar7 = a->length;
                iVar15 = iVar15 + 1;
              } while (iVar15 < iVar7);
            }
            goto LAB_00566f2c;
          }
          pBVar13 = (BIO *)0x0;
          goto LAB_00566878;
        }
      }
      else {
        if ((int)puStack_154 < 1) goto LAB_00566a6c;
        iVar7 = (*(code *)PTR_BIO_write_006a6e14)(bp,"\n",1);
        if (0 < iVar7) {
          puVar11 = puStack_154;
          if (0x6aeddf < (int)puStack_154) {
            puVar11 = &_gp;
          }
          iVar7 = (*(code *)PTR_BIO_dump_indent_006a7334)(bp,pCStack_15c,puVar11,6);
          if (0 < iVar7) goto LAB_00566a8c;
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

