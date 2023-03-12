
int X509_NAME_print_ex_fp(FILE *fp,X509_NAME *nm,int indent,ulong flags)

{
  byte bVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined *puVar8;
  uint uVar9;
  _union_257 _Var10;
  undefined *puVar11;
  uint uVar12;
  uint uVar13;
  ASN1_TYPE *a;
  int iVar14;
  uint uVar15;
  stack_st_X509_NAME_ENTRY *psVar16;
  X509_NAME *unaff_s2;
  BUF_MEM *pBVar17;
  BUF_MEM *pBVar18;
  X509_NAME *pXVar19;
  undefined4 *unaff_s3;
  byte *pbVar20;
  undefined *unaff_s4;
  BUF_MEM *pBVar21;
  undefined *unaff_s5;
  _union_257 _Var22;
  int unaff_s6;
  uint uVar23;
  int unaff_s7;
  code *pcVar24;
  byte *pbVar25;
  undefined *unaff_s8;
  int iStack_168;
  uint uStack_164;
  char cStack_13d;
  _union_257 _Stack_13c;
  ASN1_TYPE AStack_138;
  byte abStack_130 [4];
  byte bStack_12c;
  byte bStack_12b;
  char cStack_128;
  char cStack_127;
  int iStack_11c;
  undefined *puStack_118;
  FILE *pFStack_114;
  X509_NAME *pXStack_110;
  undefined4 *puStack_10c;
  undefined *puStack_108;
  undefined *puStack_104;
  int iStack_100;
  int iStack_fc;
  undefined *puStack_f8;
  code *pcStack_f4;
  undefined *local_e0;
  int local_d4;
  undefined *local_d0;
  uint local_cc;
  X509_NAME *local_c8;
  undefined *local_c4;
  uint local_c0;
  uint local_bc;
  undefined *local_b8;
  int local_b4;
  undefined *local_b0;
  undefined *local_ac;
  char *local_a8;
  undefined *local_a4;
  ASN1_TYPE **local_a0;
  undefined *local_9c;
  int local_98;
  int local_94;
  undefined *local_90;
  undefined *local_8c;
  uint local_88;
  char *local_84;
  undefined auStack_7c [80];
  ASN1_TYPE *local_2c;
  
  local_a0 = (ASN1_TYPE **)PTR___stack_chk_guard_006aabf0;
  local_e0 = &_gp;
  local_2c = *(ASN1_TYPE **)PTR___stack_chk_guard_006aabf0;
  _Var10 = (_union_257)nm;
  puVar11 = (undefined *)indent;
  iStack_fc = unaff_s7;
  local_c8 = nm;
  if (flags == 0) {
    _Var10.ptr = (char *)0x0;
    fp = (FILE *)(*(code *)PTR_BIO_new_fp_006a835c)();
    unaff_s2 = nm;
    if (fp == (FILE *)0x0) goto LAB_00553580;
    _Var10 = (_union_257)nm;
    puVar6 = (undefined *)X509_NAME_print((BIO *)fp,nm,indent);
    (**(code **)(local_e0 + -0x7f70))(fp);
    puVar11 = (undefined *)indent;
    puStack_118 = puVar6;
  }
  else {
    if (indent < 0) {
      puVar6 = (undefined *)0x0;
    }
    else {
      puVar6 = (undefined *)indent;
      if ((indent != 0) && (unaff_s3 = (undefined4 *)0x640000, fp != (FILE *)0x0)) {
        unaff_s2 = (X509_NAME *)0x0;
        unaff_s3 = &DAT_0063f0b8;
        do {
          puVar11 = (undefined *)0x1;
          _Var10.boolean = 1;
          iVar14 = (**(code **)(local_e0 + -0x5364))(&DAT_0063f0b8,1,1,fp);
          if (iVar14 != 1) goto LAB_00553580;
          unaff_s2 = (X509_NAME *)((int)&unaff_s2->entries + 1);
        } while ((X509_NAME *)indent != unaff_s2);
      }
    }
    uVar9 = flags & 0xf0000;
    unaff_s4 = (undefined *)0x0;
    if (uVar9 == 0x20000) {
      local_a4 = &SUB_00000002;
      local_90 = (undefined *)0x3;
      local_94 = 3;
      local_98 = 2;
      local_8c = &DAT_0066a068;
      local_a8 = ", ";
    }
    else {
      indent = (int)puVar6;
      if (uVar9 < 0x20001) {
        if (uVar9 != 0x10000) {
LAB_00553580:
          puVar6 = (undefined *)0xffffffff;
          puStack_118 = (undefined *)indent;
          iStack_fc = unaff_s7;
          goto LAB_00553584;
        }
        unaff_s4 = (undefined *)0x0;
        local_a4 = (undefined *)0x1;
        local_90 = (undefined *)0x1;
        local_94 = 1;
        local_98 = 1;
        local_8c = &DAT_0066a06c;
        local_a8 = ",";
      }
      else if (uVar9 == 0x30000) {
        unaff_s4 = (undefined *)0x0;
        local_a4 = &SUB_00000002;
        local_90 = (undefined *)0x3;
        local_94 = 3;
        local_98 = 2;
        local_8c = &DAT_0066a068;
        local_a8 = "; ";
      }
      else {
        if (uVar9 != 0x40000) goto LAB_00553580;
        local_a4 = (undefined *)0x1;
        local_90 = (undefined *)0x3;
        local_94 = 3;
        local_98 = 1;
        local_8c = &DAT_0066a068;
        local_a8 = "\n";
        unaff_s4 = puVar6;
      }
    }
    if ((int)(flags << 8) < 0) {
      local_b0 = (undefined *)0x3;
      local_b4 = 3;
      local_ac = &DAT_0066a074;
    }
    else {
      local_b0 = (undefined *)0x1;
      local_b4 = 1;
      local_ac = &DAT_00669e18;
    }
    local_cc = flags & 0x600000;
    iVar14 = (**(code **)(local_e0 + -0x7e6c))(local_c8);
    puStack_118 = puVar6;
    if (0 < iVar14) {
      unaff_s6 = iVar14 + -1;
      local_d4 = 0;
      local_bc = 0x80;
      if (-1 < (int)(flags << 7)) {
        local_bc = 0;
      }
      unaff_s8 = auStack_7c;
      local_84 = "";
      unaff_s2 = (X509_NAME *)&DAT_0063f0b8;
      local_c0 = flags & 0x100000;
      local_88 = flags & 0x2000000;
      unaff_s7 = -1;
      local_9c = unaff_s8;
      do {
        if (local_c0 == 0) {
          unaff_s3 = (undefined4 *)(**(code **)(local_e0 + -0x7cc0))(local_c8,local_d4);
          if (unaff_s7 == -1) goto LAB_0055366c;
LAB_00553504:
          unaff_s5 = local_90;
          puVar8 = local_a4;
          iStack_fc = unaff_s3[2];
          indent = (int)puVar6;
          if (iStack_fc == unaff_s7) {
            _Var10.boolean = 1;
            if (fp != (FILE *)0x0) {
              puVar11 = local_90;
              puVar8 = (undefined *)(**(code **)(local_e0 + -0x5364))(local_8c,1,local_90,fp);
              if (unaff_s5 != puVar8) goto LAB_00553580;
              iStack_fc = unaff_s3[2];
            }
            puVar6 = puVar6 + local_94;
          }
          else {
            _Var10.boolean = 1;
            if (fp == (FILE *)0x0) {
              puVar6 = unaff_s4 + (int)(puVar6 + local_98);
            }
            else {
              puVar11 = local_a4;
              puVar7 = (undefined *)(**(code **)(local_e0 + -0x5364))(local_a8,1,local_a4,fp);
              unaff_s5 = puVar8;
              if (puVar7 != puVar8) goto LAB_00553580;
              unaff_s5 = (undefined *)0x0;
              indent = (int)(puVar6 + local_98);
              if (unaff_s4 == (undefined *)0x0) {
                iStack_fc = unaff_s3[2];
              }
              else {
                do {
                  puVar11 = (undefined *)0x1;
                  _Var10.boolean = 1;
                  iVar14 = (**(code **)(local_e0 + -0x5364))(&DAT_0063f0b8,1,1,fp);
                  if (iVar14 != 1) goto LAB_00553580;
                  unaff_s5 = unaff_s5 + 1;
                } while (unaff_s4 != unaff_s5);
                iStack_fc = unaff_s3[2];
              }
              puVar6 = unaff_s4 + indent;
            }
          }
        }
        else {
          unaff_s3 = (undefined4 *)(**(code **)(local_e0 + -0x7cc0))(local_c8,unaff_s6);
          if (unaff_s7 != -1) goto LAB_00553504;
LAB_0055366c:
          iStack_fc = unaff_s3[2];
        }
        unaff_s5 = (undefined *)(**(code **)(local_e0 + -0x7cb8))(unaff_s3);
        local_d0 = (undefined *)(**(code **)(local_e0 + -0x7cbc))(unaff_s3);
        unaff_s3 = (undefined4 *)(**(code **)(local_e0 + -0x7cb4))(unaff_s5);
        puVar11 = local_9c;
        unaff_s7 = iStack_fc;
        if (local_cc != 0x600000) {
          indent = (int)puVar6;
          unaff_s8 = puVar11;
          if ((local_cc == 0x400000) || (unaff_s3 == (undefined4 *)0x0)) {
            (**(code **)(local_e0 + -0x6124))(local_9c,0x50,unaff_s5,1);
            unaff_s5 = (undefined *)0x0;
            local_c4 = (undefined *)(**(code **)(local_e0 + -0x53b0))(puVar11);
LAB_005537f8:
            if (fp == (FILE *)0x0) {
              if ((int)local_c4 < (int)unaff_s5) {
                unaff_s5 = unaff_s5 + -(int)local_c4;
                if (local_88 != 0) goto LAB_00553838;
                unaff_s5 = unaff_s5 + (int)local_c4;
              }
            }
            else {
              _Var10.boolean = 1;
              puVar11 = local_c4;
              local_b8 = local_c4;
              puVar8 = (undefined *)(**(code **)(local_e0 + -0x5364))(unaff_s8,1,local_c4,fp);
              if (puVar8 != local_b8) goto LAB_00553580;
              if (((int)local_b8 < (int)unaff_s5) &&
                 (unaff_s5 = unaff_s5 + -(int)local_b8, local_88 != 0)) {
LAB_00553838:
                if ((0 < (int)unaff_s5) && (unaff_s8 = (undefined *)0x0, fp != (FILE *)0x0)) {
                  pcVar24 = *(code **)(local_e0 + -0x5364);
                  do {
                    puVar11 = (undefined *)0x1;
                    _Var10.boolean = 1;
                    iVar14 = (*pcVar24)(&DAT_0063f0b8,1,1,fp);
                    if (iVar14 != 1) goto LAB_00553580;
                    unaff_s8 = unaff_s8 + 1;
                    pcVar24 = *(code **)(local_e0 + -0x5364);
                  } while (unaff_s5 != unaff_s8);
                }
                puVar6 = puVar6 + (int)unaff_s5;
                if (fp == (FILE *)0x0) goto LAB_00553768;
              }
LAB_00553740:
              unaff_s5 = local_b0;
              _Var10.boolean = 1;
              puVar11 = local_b0;
              puVar8 = (undefined *)(**(code **)(local_e0 + -0x5364))(local_ac,1,local_b0,fp);
              indent = (int)puVar6;
              if (unaff_s5 != puVar8) goto LAB_00553580;
            }
          }
          else {
            if (local_cc == 0) {
              unaff_s5 = &DAT_0000000a;
              unaff_s8 = (undefined *)(**(code **)(local_e0 + -0x7d44))(unaff_s3);
              local_c4 = (undefined *)(**(code **)(local_e0 + -0x53b0))(unaff_s8);
              goto LAB_005537f8;
            }
            if (local_cc == 0x200000) {
              unaff_s5 = &DAT_00000019;
              unaff_s8 = (undefined *)(**(code **)(local_e0 + -0x7cc4))(unaff_s3);
              local_c4 = (undefined *)(**(code **)(local_e0 + -0x53b0))(unaff_s8);
              goto LAB_005537f8;
            }
            if (fp != (FILE *)0x0) {
              puVar11 = (undefined *)0x0;
              _Var10.boolean = 1;
              iVar14 = (**(code **)(local_e0 + -0x5364))(local_84,1,0,fp);
              if (iVar14 == 0) {
                local_c4 = (undefined *)0x0;
                goto LAB_00553740;
              }
              goto LAB_00553580;
            }
            local_c4 = (undefined *)0x0;
            unaff_s8 = local_9c;
          }
LAB_00553768:
          puVar6 = puVar6 + (int)(local_c4 + local_b4);
        }
        uVar9 = local_bc;
        if (unaff_s3 != (undefined4 *)0x0) {
          uVar9 = 0;
        }
        _Var10.boolean = flags | uVar9;
        puVar11 = local_d0;
        iVar14 = do_print_ex_constprop_3(fp);
        indent = (int)puVar6;
        if (iVar14 < 0) goto LAB_00553580;
        puVar6 = puVar6 + iVar14;
        unaff_s6 = unaff_s6 + -1;
        local_d4 = local_d4 + 1;
        puStack_118 = puVar6;
      } while (unaff_s6 != -1);
    }
  }
LAB_00553584:
  if (local_2c == *local_a0) {
    return (int)puVar6;
  }
  pcStack_f4 = ASN1_STRING_print_ex;
  a = local_2c;
  (**(code **)(local_e0 + -0x5328))();
  puVar6 = PTR___stack_chk_guard_006aabf0;
  uVar9 = (uint)puVar11 & 0xf;
  cStack_13d = '\0';
  iStack_11c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar14 = (_Var10.asn1_string)->type;
  pFStack_114 = fp;
  pXStack_110 = unaff_s2;
  puStack_10c = unaff_s3;
  puStack_108 = unaff_s4;
  puStack_104 = unaff_s5;
  iStack_100 = unaff_s6;
  puStack_f8 = unaff_s8;
  if (((uint)puVar11 & 0x40) == 0) {
    uStack_164 = 0;
  }
  else {
    pcVar2 = ASN1_tag2str(iVar14);
    iVar5 = (*(code *)PTR_strlen_006aab30)(pcVar2);
    if ((a != (ASN1_TYPE *)0x0) &&
       ((iVar3 = (*(code *)PTR_BIO_write_006a7f14)(a,pcVar2,iVar5), iVar5 != iVar3 ||
        (iVar3 = (*(code *)PTR_BIO_write_006a7f14)(a,":",1), iVar3 != 1)))) goto LAB_00550980;
    uStack_164 = iVar5 + 1;
  }
  if (((uint)puVar11 & 0x80) != 0) {
LAB_00550958:
    if (a == (ASN1_TYPE *)0x0) {
      a = &AStack_138;
      if (((uint)puVar11 & 0x200) != 0) {
        AStack_138.type = (_Var10.asn1_string)->type;
        AStack_138.value = _Var10;
        iVar14 = i2d_ASN1_TYPE(a,(uchar **)0x0);
        _Var10.ptr = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar14,"a_strex.c",0x119);
        if ((X509_NAME *)_Var10.ptr != (X509_NAME *)0x0) {
          _Stack_13c.ptr = _Var10.ptr;
          i2d_ASN1_TYPE(a,(uchar **)&_Stack_13c.ptr);
          goto LAB_00551724;
        }
        goto LAB_00550980;
      }
      psVar16 = (stack_st_X509_NAME_ENTRY *)(_Var10.asn1_string)->length;
    }
    else {
      iVar14 = (*(code *)PTR_BIO_write_006a7f14)(a,&DAT_0066a058,1);
      if (iVar14 != 1) goto LAB_00550980;
      if (((uint)puVar11 & 0x200) != 0) goto LAB_00551874;
      pXVar19 = (X509_NAME *)(_Var10.asn1_string)->data;
      psVar16 = (stack_st_X509_NAME_ENTRY *)(_Var10.asn1_string)->length;
      _Var10.ptr = (char *)((int)&pXVar19->entries + (int)psVar16);
      if ((X509_NAME *)_Var10.ptr != pXVar19) {
        do {
          cStack_128 = "0123456789ABCDEF"[*(byte *)&pXVar19->entries >> 4];
          cStack_127 = "0123456789ABCDEF"[*(byte *)&pXVar19->entries & 0xf];
          iVar14 = (*(code *)PTR_BIO_write_006a7f14)(a,&cStack_128,2);
          if (iVar14 != 2) goto LAB_00550980;
          pXVar19 = (X509_NAME *)((int)&pXVar19->entries + 1);
        } while ((X509_NAME *)_Var10.ptr != pXVar19);
      }
    }
    if (-1 < (int)psVar16 * 2) {
      iVar14 = uStack_164 + (int)psVar16 * 2 + 1;
      goto LAB_00550988;
    }
    goto LAB_00550980;
  }
  if (((uint)puVar11 & 0x20) == 0) {
    if ((0x1d < iVar14 - 1U) || (uVar15 = (uint)(char)tag2nbyte[iVar14], uVar15 == 0xffffffff)) {
      if (((uint)puVar11 & 0x100) != 0) goto LAB_00550958;
      goto LAB_00550a94;
    }
    if (((uint)puVar11 & 0x10) != 0) {
      if (uVar15 == 0) {
        uVar15 = 1;
      }
      else {
        uVar15 = uVar15 | 8;
      }
    }
  }
  else {
LAB_00550a94:
    uVar15 = 1;
    if (((uint)puVar11 & 0x10) != 0) {
      uVar15 = 9;
    }
  }
  psVar16 = (stack_st_X509_NAME_ENTRY *)(_Var10.object)->sn;
  pBVar17 = (BUF_MEM *)(_Var10.asn1_string)->data;
  pBVar21 = (BUF_MEM *)((int)&pBVar17->length + (int)psVar16);
  if (pBVar17 == pBVar21) {
    iStack_168 = 0;
  }
  else {
    uVar23 = uVar15 & 7;
    iStack_168 = 0;
    pBVar18 = pBVar17;
    do {
      if (pBVar17 == pBVar18) {
        uVar12 = 0x20;
        if (((uint)puVar11 & 1) == 0) {
          uVar12 = 0;
        }
      }
      else {
        uVar12 = 0;
      }
      if (uVar23 == 1) {
        AStack_138.type = (int)*(byte *)&pBVar18->length;
        pBVar18 = (BUF_MEM *)((int)&pBVar18->length + 1);
      }
      else if (uVar23 < 2) {
        if ((uVar23 != 0) ||
           (iVar14 = (*(code *)PTR_UTF8_getc_006a9df0)(pBVar18,psVar16,&AStack_138), iVar14 < 0))
        goto LAB_00550980;
        pBVar18 = (BUF_MEM *)((int)&pBVar18->length + iVar14);
      }
      else if (uVar23 == 2) {
        AStack_138.type = (int)*(ushort *)&pBVar18->length;
        pBVar18 = (BUF_MEM *)((int)&pBVar18->length + 2);
      }
      else {
        iVar14 = -1;
        if (uVar23 != 4) goto LAB_00550988;
        AStack_138.type =
             (uint)*(byte *)((int)&pBVar18->length + 3) |
             (uint)*(byte *)((int)&pBVar18->length + 2) << 8 |
             (uint)*(byte *)((int)&pBVar18->length + 1) << 0x10 |
             (uint)*(byte *)&pBVar18->length << 0x18;
        pBVar18 = (BUF_MEM *)&pBVar18->data;
      }
      if ((pBVar21 == pBVar18) && (((uint)puVar11 & 1) != 0)) {
        uVar12 = 0x40;
      }
      if ((uVar15 & 8) == 0) {
        iVar14 = do_esc_char_constprop_6(AStack_138.type,uVar9 | uVar12,&cStack_13d,0);
        if (iVar14 < 0) goto LAB_00550980;
        iStack_168 = iStack_168 + iVar14;
      }
      else {
        iVar14 = (*(code *)PTR_UTF8_putc_006a9dec)(abStack_130,6,AStack_138.type);
        if (0 < iVar14) {
          uVar12 = uVar9 | uVar12;
          uVar13 = (uint)abStack_130[0];
          if (uVar9 == 0) {
            uVar4 = (uint)puVar11 & 4;
            if (((char)abStack_130[0] < '\0') ||
               (uVar4 = uVar12 & (byte)char_type[uVar13], (uVar4 & 0x61) == 0)) {
              if ((uVar4 & 6) == 0) {
                iVar5 = 1;
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a8060)(&cStack_128,0xb,"\\%02X");
                iVar5 = 3;
              }
            }
            else if ((uVar4 & 8) == 0) {
              iVar5 = 2;
            }
            else {
              iVar5 = 1;
              cStack_13d = '\x01';
            }
            iStack_168 = iStack_168 + iVar5;
            if (iVar14 == 1) goto LAB_00550d58;
            if ((char)abStack_130[1] < '\0') {
              uVar13 = (uint)puVar11 & 4;
LAB_00551408:
              if ((uVar13 & 6) == 0) {
                iVar5 = 1;
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a8060)(&cStack_128,0xb,"\\%02X");
                iVar5 = 3;
              }
            }
            else {
              uVar13 = uVar12 & (byte)char_type[abStack_130[1]];
              if ((uVar13 & 0x61) == 0) goto LAB_00551408;
              if ((uVar13 & 8) == 0) {
                iVar5 = 2;
              }
              else {
                cStack_13d = '\x01';
                iVar5 = 1;
              }
            }
            iStack_168 = iStack_168 + iVar5;
            if (iVar14 == 2) goto LAB_00550d58;
            if ((char)abStack_130[2] < '\0') {
              uVar13 = (uint)puVar11 & 4;
LAB_005513ec:
              if ((uVar13 & 6) == 0) {
                iVar5 = 1;
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a8060)(&cStack_128,0xb,"\\%02X");
                iVar5 = 3;
              }
            }
            else {
              uVar13 = uVar12 & (byte)char_type[abStack_130[2]];
              if ((uVar13 & 0x61) == 0) goto LAB_005513ec;
              if ((uVar13 & 8) == 0) {
                iVar5 = 2;
              }
              else {
                iVar5 = 1;
                cStack_13d = '\x01';
              }
            }
            iStack_168 = iStack_168 + iVar5;
            if (iVar14 == 3) goto LAB_00550d58;
            if ((char)abStack_130[3] < '\0') {
              uVar13 = (uint)puVar11 & 4;
LAB_00551424:
              if ((uVar13 & 6) == 0) {
                iVar5 = 1;
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a8060)(&cStack_128,0xb,"\\%02X");
                iVar5 = 3;
              }
            }
            else {
              uVar13 = uVar12 & (byte)char_type[abStack_130[3]];
              if ((uVar13 & 0x61) == 0) goto LAB_00551424;
              if ((uVar13 & 8) == 0) {
                iVar5 = 2;
              }
              else {
                iVar5 = 1;
                cStack_13d = '\x01';
              }
            }
            iStack_168 = iStack_168 + iVar5;
            if (iVar14 == 4) goto LAB_00550d58;
            if ((char)bStack_12c < '\0') {
              uVar13 = (uint)puVar11 & 4;
LAB_005513d0:
              if ((uVar13 & 6) == 0) {
                iVar5 = 1;
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a8060)(&cStack_128,0xb,"\\%02X");
                iVar5 = 3;
              }
            }
            else {
              uVar13 = uVar12 & (byte)char_type[bStack_12c];
              if ((uVar13 & 0x61) == 0) goto LAB_005513d0;
              if ((uVar13 & 8) == 0) {
                iVar5 = 2;
              }
              else {
                iVar5 = 1;
                cStack_13d = '\x01';
              }
            }
            iStack_168 = iStack_168 + iVar5;
            if (iVar14 == 5) goto LAB_00550d58;
            if ((char)bStack_12b < '\0') {
              uVar12 = (uint)puVar11 & 4;
LAB_005513b4:
              if ((uVar12 & 6) == 0) {
                iStack_168 = iStack_168 + 1;
                goto LAB_00550d58;
              }
LAB_00551448:
              (*(code *)PTR_BIO_snprintf_006a8060)(&cStack_128,0xb,"\\%02X");
              iStack_168 = iStack_168 + 3;
            }
            else {
              uVar12 = uVar12 & (byte)char_type[bStack_12b];
              if ((uVar12 & 0x61) == 0) goto LAB_005513b4;
LAB_00550d40:
              if ((uVar12 & 8) == 0) {
                iStack_168 = iStack_168 + 2;
              }
              else {
                iStack_168 = iStack_168 + 1;
                cStack_13d = '\x01';
              }
            }
          }
          else {
            if ((char)abStack_130[0] < '\0') {
              uVar4 = (uint)puVar11 & 4;
LAB_00551390:
              if ((uVar4 & 6) == 0) {
                iVar5 = 1;
                if (uVar13 == 0x5c) {
                  iVar5 = 2;
                }
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a8060)(&cStack_128,0xb,"\\%02X");
                iVar5 = 3;
              }
            }
            else {
              uVar4 = uVar12 & (byte)char_type[uVar13];
              if ((uVar4 & 0x61) == 0) goto LAB_00551390;
              if ((uVar4 & 8) == 0) {
                iVar5 = 2;
              }
              else {
                iVar5 = 1;
                cStack_13d = '\x01';
              }
            }
            iStack_168 = iStack_168 + iVar5;
            if (iVar14 == 1) goto LAB_00550d58;
            if ((char)abStack_130[1] < '\0') {
              uVar13 = (uint)puVar11 & 4;
LAB_00551590:
              if ((uVar13 & 6) == 0) {
                iVar5 = 2;
                if (abStack_130[1] != 0x5c) {
                  iVar5 = 1;
                }
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a8060)(&cStack_128,0xb,"\\%02X");
                iVar5 = 3;
              }
            }
            else {
              uVar13 = uVar12 & (byte)char_type[abStack_130[1]];
              if ((uVar13 & 0x61) == 0) goto LAB_00551590;
              if ((uVar13 & 8) == 0) {
                iVar5 = 2;
              }
              else {
                cStack_13d = '\x01';
                iVar5 = 1;
              }
            }
            iStack_168 = iStack_168 + iVar5;
            if (iVar14 == 2) goto LAB_00550d58;
            if ((char)abStack_130[2] < '\0') {
              uVar13 = (uint)puVar11 & 4;
LAB_0055156c:
              if ((uVar13 & 6) == 0) {
                iVar5 = 2;
                if (abStack_130[2] != 0x5c) {
                  iVar5 = 1;
                }
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a8060)(&cStack_128,0xb,"\\%02X");
                iVar5 = 3;
              }
            }
            else {
              uVar13 = uVar12 & (byte)char_type[abStack_130[2]];
              if ((uVar13 & 0x61) == 0) goto LAB_0055156c;
              if ((uVar13 & 8) == 0) {
                iVar5 = 2;
              }
              else {
                iVar5 = 1;
                cStack_13d = '\x01';
              }
            }
            iStack_168 = iStack_168 + iVar5;
            if (iVar14 == 3) goto LAB_00550d58;
            if ((char)abStack_130[3] < '\0') {
              uVar13 = (uint)puVar11 & 4;
LAB_00551548:
              if ((uVar13 & 6) == 0) {
                iVar5 = 2;
                if (abStack_130[3] != 0x5c) {
                  iVar5 = 1;
                }
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a8060)(&cStack_128,0xb,"\\%02X");
                iVar5 = 3;
              }
            }
            else {
              uVar13 = uVar12 & (byte)char_type[abStack_130[3]];
              if ((uVar13 & 0x61) == 0) goto LAB_00551548;
              if ((uVar13 & 8) == 0) {
                iVar5 = 2;
              }
              else {
                iVar5 = 1;
                cStack_13d = '\x01';
              }
            }
            iStack_168 = iStack_168 + iVar5;
            if (iVar14 == 4) goto LAB_00550d58;
            if ((char)bStack_12c < '\0') {
              uVar13 = (uint)puVar11 & 4;
LAB_00551524:
              if ((uVar13 & 6) == 0) {
                iVar5 = 2;
                if (bStack_12c != 0x5c) {
                  iVar5 = 1;
                }
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a8060)(&cStack_128,0xb,"\\%02X");
                iVar5 = 3;
              }
            }
            else {
              uVar13 = uVar12 & (byte)char_type[bStack_12c];
              if ((uVar13 & 0x61) == 0) goto LAB_00551524;
              if ((uVar13 & 8) == 0) {
                iVar5 = 2;
              }
              else {
                iVar5 = 1;
                cStack_13d = '\x01';
              }
            }
            iStack_168 = iStack_168 + iVar5;
            if (iVar14 != 5) {
              if ((char)bStack_12b < '\0') {
                uVar12 = (uint)puVar11 & 4;
              }
              else {
                uVar12 = uVar12 & (byte)char_type[bStack_12b];
                if ((uVar12 & 0x61) != 0) goto LAB_00550d40;
              }
              iVar14 = 1;
              if ((uVar12 & 6) != 0) goto LAB_00551448;
              if (bStack_12b == 0x5c) {
                iVar14 = 2;
              }
              iStack_168 = iStack_168 + iVar14;
            }
          }
        }
      }
LAB_00550d58:
    } while (pBVar21 != pBVar18);
  }
  iStack_168 = uStack_164 + iStack_168;
  if (cStack_13d == '\0') {
    iVar14 = iStack_168;
    if (a == (ASN1_TYPE *)0x0) goto LAB_00550988;
  }
  else {
    iStack_168 = iStack_168 + 2;
    iVar14 = iStack_168;
    if (a == (ASN1_TYPE *)0x0) goto LAB_00550988;
    iVar14 = (*(code *)PTR_BIO_write_006a7f14)(a,&DAT_0067a4c0,1);
    if (iVar14 != 1) goto LAB_00550980;
  }
  psVar16 = (stack_st_X509_NAME_ENTRY *)(_Var10.object)->sn;
  pBVar21 = (BUF_MEM *)(_Var10.asn1_string)->data;
  pBVar17 = (BUF_MEM *)((int)&pBVar21->length + (int)psVar16);
  if (pBVar21 != pBVar17) {
    _Var10.boolean = uVar15 & 7;
    uStack_164 = uVar15 & 8;
    pBVar18 = pBVar21;
    do {
      while( true ) {
        if (pBVar18 == pBVar21) {
          uVar15 = 0x20;
          if (((uint)puVar11 & 1) == 0) {
            uVar15 = 0;
          }
        }
        else {
          uVar15 = 0;
        }
        if ((X509_NAME *)_Var10.ptr == (X509_NAME *)0x1) {
          AStack_138.type = (int)*(byte *)&pBVar18->length;
          pBVar18 = (BUF_MEM *)((int)&pBVar18->length + 1);
        }
        else if ((uint)_Var10 < (X509_NAME *)0x2) {
          if (((X509_NAME *)_Var10.ptr != (X509_NAME *)0x0) ||
             (iVar14 = (*(code *)PTR_UTF8_getc_006a9df0)(pBVar18,psVar16,&AStack_138), iVar14 < 0))
          goto LAB_00550980;
          pBVar18 = (BUF_MEM *)((int)&pBVar18->length + iVar14);
        }
        else if ((X509_NAME *)_Var10.ptr == (X509_NAME *)&SUB_00000002) {
          AStack_138.type = (int)*(ushort *)&pBVar18->length;
          pBVar18 = (BUF_MEM *)((int)&pBVar18->length + 2);
        }
        else {
          iVar14 = -1;
          if ((X509_NAME *)_Var10.ptr != (X509_NAME *)&SUB_00000004) goto LAB_00550988;
          AStack_138.type =
               (uint)*(byte *)((int)&pBVar18->length + 3) |
               (uint)*(byte *)((int)&pBVar18->length + 2) << 8 |
               (uint)*(byte *)((int)&pBVar18->length + 1) << 0x10 |
               (uint)*(byte *)&pBVar18->length << 0x18;
          pBVar18 = (BUF_MEM *)&pBVar18->data;
        }
        if ((pBVar17 == pBVar18) && (((uint)puVar11 & 1) != 0)) {
          uVar15 = 0x40;
        }
        if (uStack_164 != 0) break;
        iVar14 = do_esc_char_constprop_6(AStack_138.type,uVar9 | uVar15,0,a);
        if (iVar14 < 0) goto LAB_00550980;
        if (pBVar17 == pBVar18) goto LAB_00550f3c;
      }
      pbVar25 = abStack_130;
      iVar14 = (*(code *)PTR_UTF8_putc_006a9dec)(pbVar25,6,AStack_138.type);
      if (0 < iVar14) {
        pbVar20 = pbVar25 + iVar14;
        do {
          while( true ) {
            bVar1 = *pbVar25;
            _Stack_13c.boolean = _Stack_13c.boolean & 0xffffffU | (uint)bVar1 << 0x18;
            if ((char)bVar1 < '\0') break;
            uVar23 = (uVar9 | uVar15) & (uint)(byte)char_type[bVar1];
            if ((uVar23 & 0x61) == 0) goto LAB_00550f78;
            if ((uVar23 & 8) == 0) {
              iVar14 = (*(code *)PTR_BIO_write_006a7f14)(a,&DAT_0066a048,1);
              if (iVar14 != 1) goto LAB_00550980;
              iVar14 = (*(code *)PTR_BIO_write_006a7f14)(a,&_Stack_13c,1);
            }
            else {
LAB_00550f08:
              iVar14 = (*(code *)PTR_BIO_write_006a7f14)(a,&_Stack_13c,1);
            }
            if (iVar14 != 1) goto LAB_00550980;
joined_r0x00551128:
            pbVar25 = pbVar25 + 1;
            if (pbVar20 == pbVar25) goto LAB_00550f30;
          }
          uVar23 = (uint)puVar11 & 4;
LAB_00550f78:
          if ((uVar23 & 6) == 0) {
            if ((bVar1 != 0x5c) || (uVar9 == 0)) goto LAB_00550f08;
            iVar14 = (*(code *)PTR_BIO_write_006a7f14)(a,&DAT_0066a054,2);
            if (iVar14 == 2) goto joined_r0x00551128;
            goto LAB_00550980;
          }
          (*(code *)PTR_BIO_snprintf_006a8060)(&cStack_128,0xb,"\\%02X");
          iVar14 = (*(code *)PTR_BIO_write_006a7f14)(a,&cStack_128,3);
          if (iVar14 != 3) goto LAB_00550980;
          pbVar25 = pbVar25 + 1;
        } while (pbVar20 != pbVar25);
      }
LAB_00550f30:
    } while (pBVar17 != pBVar18);
  }
LAB_00550f3c:
  iVar14 = iStack_168;
  if (cStack_13d == '\0') goto LAB_00550988;
  iVar5 = (*(code *)PTR_BIO_write_006a7f14)(a,&DAT_0067a4c0,1);
  if (iVar5 == 1) goto LAB_00550988;
LAB_00550980:
  do {
    iVar14 = -1;
LAB_00550988:
    while( true ) {
      if (iStack_11c == *(int *)puVar6) {
        return iVar14;
      }
      (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_00551874:
      AStack_138.type = (_Var10.asn1_string)->type;
      AStack_138.value = _Var10;
      iVar14 = i2d_ASN1_TYPE(&AStack_138,(uchar **)0x0);
      _Var10.ptr = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar14,"a_strex.c",0x119);
      if ((X509_NAME *)_Var10.ptr == (X509_NAME *)0x0) break;
      _Stack_13c.ptr = _Var10.ptr;
      i2d_ASN1_TYPE(&AStack_138,(uchar **)&_Stack_13c.ptr);
      if ((X509_NAME *)(_Var10.ptr + iVar14) != (X509_NAME *)_Var10.ptr) {
        _Var22.ptr = _Var10.ptr;
        do {
          cStack_128 = "0123456789ABCDEF"[(byte)*_Var22.ptr >> 4];
          cStack_127 = "0123456789ABCDEF"[(byte)*_Var22.ptr & 0xf];
          iVar5 = (*(code *)PTR_BIO_write_006a7f14)(a,&cStack_128,2);
          if (iVar5 != 2) {
            (*(code *)PTR_CRYPTO_free_006a7f88)(_Var10.ptr);
            goto LAB_00550980;
          }
          _Var22.ptr = (char *)((int)&(_Var22.asn1_string)->length + 1);
        } while ((X509_NAME *)(_Var10.ptr + iVar14) != (X509_NAME *)_Var22.ptr);
      }
LAB_00551724:
      a = (ASN1_TYPE *)(iVar14 * 2);
      (*(code *)PTR_CRYPTO_free_006a7f88)(_Var10.ptr);
      if ((int)a < 0) break;
      iVar14 = (int)&a->type + uStack_164 + 1;
    }
  } while( true );
}

