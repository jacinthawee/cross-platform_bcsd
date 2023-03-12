
undefined * do_esc_char_constprop_7(uint param_1,uint param_2,char *param_3,int param_4)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined *puVar4;
  undefined *puVar5;
  char *pcVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  char cVar10;
  uint uVar11;
  uint uVar12;
  ASN1_TYPE *a;
  uint uVar13;
  undefined *unaff_s2;
  ushort *puVar14;
  ushort *puVar15;
  byte *pbVar16;
  ushort *puVar17;
  byte *pbVar18;
  _union_257 _Var19;
  uint uVar20;
  undefined *puStack_b8;
  uint uStack_b4;
  char cStack_8d;
  _union_257 _Stack_8c;
  ASN1_TYPE AStack_88;
  byte abStack_80 [4];
  byte bStack_7c;
  byte bStack_7b;
  char cStack_78;
  char cStack_77;
  int iStack_6c;
  undefined *puStack_68;
  int iStack_64;
  undefined *puStack_60;
  char local_21;
  undefined auStack_20 [12];
  ASN1_TYPE *local_14;
  
  puStack_68 = PTR___stack_chk_guard_006a9ae8;
  local_14 = *(ASN1_TYPE **)PTR___stack_chk_guard_006a9ae8;
  if (param_1 < 0x10000) {
    cVar10 = (char)param_1;
    if (param_1 < 0x100) {
      local_21 = cVar10;
      if (cVar10 < '\0') {
        uVar2 = param_2 & 4;
LAB_0054e7c8:
        if ((uVar2 & 6) == 0) {
          if ((param_1 != 0x5c) || (param_2 = param_2 & 0xf, param_2 == 0)) goto LAB_0054e770;
          if (param_4 != 0) {
            param_3 = &SUB_00000002;
            param_2 = 1;
            iVar3 = (*(code *)PTR_fwrite_006a9a74)(&DAT_006695a4,1,2,param_4);
            if (iVar3 != 2) goto LAB_0054e798;
          }
LAB_0054e814:
          puVar4 = &SUB_00000002;
        }
        else {
          unaff_s2 = auStack_20;
          param_3 = "\\%02X";
          param_2 = 0xb;
          (*(code *)PTR_BIO_snprintf_006a6f60)(unaff_s2,0xb,"\\%02X",param_1);
          if (param_4 != 0) {
            param_3 = (char *)0x3;
            param_2 = 1;
            iVar3 = (*(code *)PTR_fwrite_006a9a74)(unaff_s2,1,3,param_4);
            if (iVar3 != 3) goto LAB_0054e798;
          }
          puVar4 = (undefined *)0x3;
        }
      }
      else {
        uVar2 = param_2 & (byte)char_type[param_1];
        if ((uVar2 & 0x61) == 0) goto LAB_0054e7c8;
        if ((uVar2 & 8) == 0) {
          if (param_4 == 0) goto LAB_0054e814;
          param_3 = (char *)0x1;
          param_2 = 1;
          unaff_s2 = (undefined *)(*(code *)PTR_fwrite_006a9a74)(&DAT_00669598);
          if (unaff_s2 == (undefined *)0x1) {
            param_3 = (char *)0x1;
            param_2 = 1;
            iVar3 = (*(code *)PTR_fwrite_006a9a74)(&local_21,1,1,param_4);
            if (iVar3 == 1) {
              puVar4 = &SUB_00000002;
              goto LAB_0054e79c;
            }
          }
LAB_0054e798:
          puVar4 = (undefined *)0xffffffff;
        }
        else {
          if ((byte *)param_3 != (byte *)0x0) {
            *param_3 = 1;
          }
LAB_0054e770:
          if (param_4 != 0) {
            param_3 = (char *)0x1;
            param_2 = 1;
            iVar3 = (*(code *)PTR_fwrite_006a9a74)(&local_21,1,1,param_4);
            if (iVar3 != 1) goto LAB_0054e798;
          }
          puVar4 = (undefined *)0x1;
        }
      }
    }
    else {
      unaff_s2 = auStack_20;
      param_3 = "\\U%04lX";
      param_2 = 0xb;
      (*(code *)PTR_BIO_snprintf_006a6f60)(unaff_s2,0xb,"\\U%04lX",param_1);
      if (param_4 != 0) {
        param_3 = &DAT_00000006;
        param_2 = 1;
        iVar3 = (*(code *)PTR_fwrite_006a9a74)(unaff_s2,1,6,param_4);
        if (iVar3 != 6) goto LAB_0054e798;
      }
      puVar4 = &DAT_00000006;
    }
  }
  else {
    unaff_s2 = auStack_20;
    param_3 = "\\W%08lX";
    param_2 = 0xb;
    (*(code *)PTR_BIO_snprintf_006a6f60)(unaff_s2,0xb,"\\W%08lX",param_1);
    if (param_4 != 0) {
      param_3 = &DAT_0000000a;
      param_2 = 1;
      iVar3 = (*(code *)PTR_fwrite_006a9a74)(unaff_s2,1,10,param_4);
      if (iVar3 != 10) goto LAB_0054e798;
    }
    puVar4 = &DAT_0000000a;
  }
LAB_0054e79c:
  if (local_14 == *(ASN1_TYPE **)puStack_68) {
    return puVar4;
  }
  a = local_14;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar4 = PTR___stack_chk_guard_006a9ae8;
  uVar2 = param_2 & 0xf;
  cStack_8d = '\0';
  iStack_6c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar3 = *(int *)((int)param_3 + 4);
  iStack_64 = param_4;
  puStack_60 = unaff_s2;
  if ((param_2 & 0x40) == 0) {
    uStack_b4 = 0;
  }
  else {
    pcVar6 = ASN1_tag2str(iVar3);
    iVar9 = (*(code *)PTR_strlen_006a9a24)(pcVar6);
    if ((a != (ASN1_TYPE *)0x0) &&
       ((iVar8 = (*(code *)PTR_fwrite_006a9a74)(pcVar6,1,iVar9,a), iVar9 != iVar8 ||
        (iVar8 = (*(code *)PTR_fwrite_006a9a74)(":",1,1,a), iVar8 != 1)))) goto LAB_0054ea38;
    uStack_b4 = iVar9 + 1;
  }
  if ((param_2 & 0x80) != 0) {
LAB_0054ea0c:
    if (a == (ASN1_TYPE *)0x0) {
      a = &AStack_88;
      if ((param_2 & 0x200) != 0) {
        AStack_88.type = *(int *)((int)param_3 + 4);
        AStack_88.value.ptr = param_3;
        iVar3 = i2d_ASN1_TYPE(a,(uchar **)0x0);
        param_3 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar3,"a_strex.c",0x13d);
        if ((byte *)param_3 != (byte *)0x0) {
          _Stack_8c.ptr = param_3;
          i2d_ASN1_TYPE(a,(uchar **)&_Stack_8c.ptr);
          goto LAB_0054f804;
        }
        goto LAB_0054ea38;
      }
      iVar3 = *(int *)param_3;
    }
    else {
      iVar3 = (*(code *)PTR_fwrite_006a9a74)(&DAT_006695a8,1,1,a);
      if (iVar3 != 1) goto LAB_0054ea38;
      if ((param_2 & 0x200) != 0) goto LAB_0054f954;
      pbVar16 = *(uchar **)((int)param_3 + 8);
      iVar3 = *(int *)param_3;
      param_3 = (char *)(pbVar16 + iVar3);
      if ((byte *)param_3 != pbVar16) {
        do {
          cStack_78 = "0123456789ABCDEF"[*pbVar16 >> 4];
          cStack_77 = "0123456789ABCDEF"[*pbVar16 & 0xf];
          iVar9 = (*(code *)PTR_fwrite_006a9a74)(&cStack_78,1,2,a);
          if (iVar9 != 2) goto LAB_0054ea38;
          pbVar16 = pbVar16 + 1;
        } while ((byte *)param_3 != pbVar16);
      }
    }
    if (-1 < iVar3 * 2) {
      puVar5 = (undefined *)(uStack_b4 + iVar3 * 2 + 1);
      goto LAB_0054ea40;
    }
    goto LAB_0054ea38;
  }
  if ((param_2 & 0x20) == 0) {
    if ((0x1d < iVar3 - 1U) || (uVar13 = (uint)(char)tag2nbyte[iVar3], uVar13 == 0xffffffff)) {
      if ((param_2 & 0x100) != 0) goto LAB_0054ea0c;
      goto LAB_0054eb54;
    }
    if ((param_2 & 0x10) != 0) {
      if (uVar13 == 0) {
        uVar13 = 1;
      }
      else {
        uVar13 = uVar13 | 8;
      }
    }
  }
  else {
LAB_0054eb54:
    uVar13 = 1;
    if ((param_2 & 0x10) != 0) {
      uVar13 = 9;
    }
  }
  pcVar6 = *(char **)param_3;
  puVar14 = *(ushort **)((int)param_3 + 8);
  puVar17 = (ushort *)((int)puVar14 + (int)pcVar6);
  if (puVar14 == puVar17) {
    iVar3 = 0;
  }
  else {
    uVar20 = uVar13 & 7;
    iVar3 = 0;
    puVar15 = puVar14;
    do {
      if (puVar14 == puVar15) {
        uVar11 = 0x20;
        if ((param_2 & 1) == 0) {
          uVar11 = 0;
        }
      }
      else {
        uVar11 = 0;
      }
      if (uVar20 == 1) {
        AStack_88.type = (int)*(byte *)puVar15;
        puVar15 = (ushort *)((int)puVar15 + 1);
      }
      else if (uVar20 < 2) {
        if ((uVar20 != 0) ||
           (iVar9 = (*(code *)PTR_UTF8_getc_006a8ccc)(puVar15,pcVar6,&AStack_88), iVar9 < 0))
        goto LAB_0054ea38;
        puVar15 = (ushort *)((int)puVar15 + iVar9);
      }
      else if (uVar20 == 2) {
        AStack_88.type = (int)*puVar15;
        puVar15 = puVar15 + 1;
      }
      else {
        puVar5 = (undefined *)0xffffffff;
        if (uVar20 != 4) goto LAB_0054ea40;
        AStack_88.type =
             (uint)*(byte *)((int)puVar15 + 3) |
             (uint)*(byte *)(puVar15 + 1) << 8 |
             (uint)*(byte *)((int)puVar15 + 1) << 0x10 | (uint)*(byte *)puVar15 << 0x18;
        puVar15 = puVar15 + 2;
      }
      if ((puVar17 == puVar15) && ((param_2 & 1) != 0)) {
        uVar11 = 0x40;
      }
      if ((uVar13 & 8) == 0) {
        iVar9 = do_esc_char_constprop_7(AStack_88.type,uVar2 | uVar11,&cStack_8d,0);
        if (iVar9 < 0) goto LAB_0054ea38;
        iVar3 = iVar3 + iVar9;
      }
      else {
        iVar9 = (*(code *)PTR_UTF8_putc_006a8cc8)(abStack_80,6,AStack_88.type);
        if (0 < iVar9) {
          uVar11 = uVar2 | uVar11;
          uVar12 = (uint)abStack_80[0];
          if (uVar2 == 0) {
            uVar7 = param_2 & 4;
            if (((char)abStack_80[0] < '\0') ||
               (uVar7 = uVar11 & (byte)char_type[uVar12], (uVar7 & 0x61) == 0)) {
              if ((uVar7 & 6) == 0) {
                iVar8 = 1;
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a6f60)(&cStack_78,0xb,"\\%02X");
                iVar8 = 3;
              }
            }
            else if ((uVar7 & 8) == 0) {
              iVar8 = 2;
            }
            else {
              iVar8 = 1;
              cStack_8d = '\x01';
            }
            iVar3 = iVar3 + iVar8;
            if (iVar9 == 1) goto LAB_0054ee18;
            if ((char)abStack_80[1] < '\0') {
              uVar12 = param_2 & 4;
LAB_0054f4e4:
              if ((uVar12 & 6) == 0) {
                iVar8 = 1;
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a6f60)(&cStack_78,0xb,"\\%02X");
                iVar8 = 3;
              }
            }
            else {
              uVar12 = uVar11 & (byte)char_type[abStack_80[1]];
              if ((uVar12 & 0x61) == 0) goto LAB_0054f4e4;
              if ((uVar12 & 8) == 0) {
                iVar8 = 2;
              }
              else {
                cStack_8d = '\x01';
                iVar8 = 1;
              }
            }
            iVar3 = iVar3 + iVar8;
            if (iVar9 == 2) goto LAB_0054ee18;
            if ((char)abStack_80[2] < '\0') {
              uVar12 = param_2 & 4;
LAB_0054f4c8:
              if ((uVar12 & 6) == 0) {
                iVar8 = 1;
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a6f60)(&cStack_78,0xb,"\\%02X");
                iVar8 = 3;
              }
            }
            else {
              uVar12 = uVar11 & (byte)char_type[abStack_80[2]];
              if ((uVar12 & 0x61) == 0) goto LAB_0054f4c8;
              if ((uVar12 & 8) == 0) {
                iVar8 = 2;
              }
              else {
                iVar8 = 1;
                cStack_8d = '\x01';
              }
            }
            iVar3 = iVar3 + iVar8;
            if (iVar9 == 3) goto LAB_0054ee18;
            if ((char)abStack_80[3] < '\0') {
              uVar12 = param_2 & 4;
LAB_0054f500:
              if ((uVar12 & 6) == 0) {
                iVar8 = 1;
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a6f60)(&cStack_78,0xb,"\\%02X");
                iVar8 = 3;
              }
            }
            else {
              uVar12 = uVar11 & (byte)char_type[abStack_80[3]];
              if ((uVar12 & 0x61) == 0) goto LAB_0054f500;
              if ((uVar12 & 8) == 0) {
                iVar8 = 2;
              }
              else {
                iVar8 = 1;
                cStack_8d = '\x01';
              }
            }
            iVar3 = iVar3 + iVar8;
            if (iVar9 == 4) goto LAB_0054ee18;
            if ((char)bStack_7c < '\0') {
              uVar12 = param_2 & 4;
LAB_0054f4ac:
              if ((uVar12 & 6) == 0) {
                iVar8 = 1;
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a6f60)(&cStack_78,0xb,"\\%02X");
                iVar8 = 3;
              }
            }
            else {
              uVar12 = uVar11 & (byte)char_type[bStack_7c];
              if ((uVar12 & 0x61) == 0) goto LAB_0054f4ac;
              if ((uVar12 & 8) == 0) {
                iVar8 = 2;
              }
              else {
                iVar8 = 1;
                cStack_8d = '\x01';
              }
            }
            iVar3 = iVar3 + iVar8;
            if (iVar9 == 5) goto LAB_0054ee18;
            if ((char)bStack_7b < '\0') {
              uVar11 = param_2 & 4;
LAB_0054f490:
              if ((uVar11 & 6) == 0) {
                iVar3 = iVar3 + 1;
                goto LAB_0054ee18;
              }
LAB_0054f524:
              (*(code *)PTR_BIO_snprintf_006a6f60)(&cStack_78,0xb,"\\%02X");
              iVar3 = iVar3 + 3;
            }
            else {
              uVar11 = uVar11 & (byte)char_type[bStack_7b];
              if ((uVar11 & 0x61) == 0) goto LAB_0054f490;
LAB_0054ee00:
              if ((uVar11 & 8) == 0) {
                iVar3 = iVar3 + 2;
              }
              else {
                iVar3 = iVar3 + 1;
                cStack_8d = '\x01';
              }
            }
          }
          else {
            if ((char)abStack_80[0] < '\0') {
              uVar7 = param_2 & 4;
LAB_0054f46c:
              if ((uVar7 & 6) == 0) {
                iVar8 = 1;
                if (uVar12 == 0x5c) {
                  iVar8 = 2;
                }
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a6f60)(&cStack_78,0xb,"\\%02X");
                iVar8 = 3;
              }
            }
            else {
              uVar7 = uVar11 & (byte)char_type[uVar12];
              if ((uVar7 & 0x61) == 0) goto LAB_0054f46c;
              if ((uVar7 & 8) == 0) {
                iVar8 = 2;
              }
              else {
                iVar8 = 1;
                cStack_8d = '\x01';
              }
            }
            iVar3 = iVar3 + iVar8;
            if (iVar9 == 1) goto LAB_0054ee18;
            if ((char)abStack_80[1] < '\0') {
              uVar12 = param_2 & 4;
LAB_0054f670:
              if ((uVar12 & 6) == 0) {
                iVar8 = 2;
                if (abStack_80[1] != 0x5c) {
                  iVar8 = 1;
                }
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a6f60)(&cStack_78,0xb,"\\%02X");
                iVar8 = 3;
              }
            }
            else {
              uVar12 = uVar11 & (byte)char_type[abStack_80[1]];
              if ((uVar12 & 0x61) == 0) goto LAB_0054f670;
              if ((uVar12 & 8) == 0) {
                iVar8 = 2;
              }
              else {
                cStack_8d = '\x01';
                iVar8 = 1;
              }
            }
            iVar3 = iVar3 + iVar8;
            if (iVar9 == 2) goto LAB_0054ee18;
            if ((char)abStack_80[2] < '\0') {
              uVar12 = param_2 & 4;
LAB_0054f64c:
              if ((uVar12 & 6) == 0) {
                iVar8 = 2;
                if (abStack_80[2] != 0x5c) {
                  iVar8 = 1;
                }
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a6f60)(&cStack_78,0xb,"\\%02X");
                iVar8 = 3;
              }
            }
            else {
              uVar12 = uVar11 & (byte)char_type[abStack_80[2]];
              if ((uVar12 & 0x61) == 0) goto LAB_0054f64c;
              if ((uVar12 & 8) == 0) {
                iVar8 = 2;
              }
              else {
                iVar8 = 1;
                cStack_8d = '\x01';
              }
            }
            iVar3 = iVar3 + iVar8;
            if (iVar9 == 3) goto LAB_0054ee18;
            if ((char)abStack_80[3] < '\0') {
              uVar12 = param_2 & 4;
LAB_0054f628:
              if ((uVar12 & 6) == 0) {
                iVar8 = 2;
                if (abStack_80[3] != 0x5c) {
                  iVar8 = 1;
                }
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a6f60)(&cStack_78,0xb,"\\%02X");
                iVar8 = 3;
              }
            }
            else {
              uVar12 = uVar11 & (byte)char_type[abStack_80[3]];
              if ((uVar12 & 0x61) == 0) goto LAB_0054f628;
              if ((uVar12 & 8) == 0) {
                iVar8 = 2;
              }
              else {
                iVar8 = 1;
                cStack_8d = '\x01';
              }
            }
            iVar3 = iVar3 + iVar8;
            if (iVar9 == 4) goto LAB_0054ee18;
            if ((char)bStack_7c < '\0') {
              uVar12 = param_2 & 4;
LAB_0054f604:
              if ((uVar12 & 6) == 0) {
                iVar8 = 2;
                if (bStack_7c != 0x5c) {
                  iVar8 = 1;
                }
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a6f60)(&cStack_78,0xb,"\\%02X");
                iVar8 = 3;
              }
            }
            else {
              uVar12 = uVar11 & (byte)char_type[bStack_7c];
              if ((uVar12 & 0x61) == 0) goto LAB_0054f604;
              if ((uVar12 & 8) == 0) {
                iVar8 = 2;
              }
              else {
                iVar8 = 1;
                cStack_8d = '\x01';
              }
            }
            iVar3 = iVar3 + iVar8;
            if (iVar9 != 5) {
              if ((char)bStack_7b < '\0') {
                uVar11 = param_2 & 4;
              }
              else {
                uVar11 = uVar11 & (byte)char_type[bStack_7b];
                if ((uVar11 & 0x61) != 0) goto LAB_0054ee00;
              }
              iVar9 = 1;
              if ((uVar11 & 6) != 0) goto LAB_0054f524;
              if (bStack_7b == 0x5c) {
                iVar9 = 2;
              }
              iVar3 = iVar3 + iVar9;
            }
          }
        }
      }
LAB_0054ee18:
    } while (puVar17 != puVar15);
  }
  puStack_b8 = (undefined *)(uStack_b4 + iVar3);
  if (cStack_8d == '\0') {
    puVar5 = puStack_b8;
    if (a == (ASN1_TYPE *)0x0) goto LAB_0054ea40;
  }
  else {
    puStack_b8 = puStack_b8 + 2;
    puVar5 = puStack_b8;
    if (a == (ASN1_TYPE *)0x0) goto LAB_0054ea40;
    iVar3 = (*(code *)PTR_fwrite_006a9a74)(&DAT_00679c10,1,1,a);
    if (iVar3 != 1) goto LAB_0054ea38;
  }
  pcVar6 = *(char **)param_3;
  puVar17 = *(ushort **)((int)param_3 + 8);
  puVar14 = (ushort *)((int)puVar17 + (int)pcVar6);
  if (puVar17 != puVar14) {
    param_3 = (char *)(uVar13 & 7);
    uStack_b4 = uVar13 & 8;
    puVar15 = puVar17;
    do {
      while( true ) {
        if (puVar17 == puVar15) {
          uVar13 = 0x20;
          if ((param_2 & 1) == 0) {
            uVar13 = 0;
          }
        }
        else {
          uVar13 = 0;
        }
        if ((byte *)param_3 == (byte *)0x1) {
          AStack_88.type = (int)*(byte *)puVar15;
          puVar15 = (ushort *)((int)puVar15 + 1);
        }
        else if (param_3 < (byte *)0x2) {
          if (((byte *)param_3 != (byte *)0x0) ||
             (iVar3 = (*(code *)PTR_UTF8_getc_006a8ccc)(puVar15,pcVar6,&AStack_88), iVar3 < 0))
          goto LAB_0054ea38;
          puVar15 = (ushort *)((int)puVar15 + iVar3);
        }
        else if (param_3 == &SUB_00000002) {
          AStack_88.type = (int)*puVar15;
          puVar15 = puVar15 + 1;
        }
        else {
          puVar5 = (undefined *)0xffffffff;
          if (param_3 != &SUB_00000004) goto LAB_0054ea40;
          AStack_88.type =
               (uint)*(byte *)((int)puVar15 + 3) |
               (uint)*(byte *)(puVar15 + 1) << 8 |
               (uint)*(byte *)((int)puVar15 + 1) << 0x10 | (uint)*(byte *)puVar15 << 0x18;
          puVar15 = puVar15 + 2;
        }
        if ((puVar14 == puVar15) && ((param_2 & 1) != 0)) {
          uVar13 = 0x40;
        }
        if (uStack_b4 != 0) break;
        iVar3 = do_esc_char_constprop_7(AStack_88.type,uVar2 | uVar13,0,a);
        if (iVar3 < 0) goto LAB_0054ea38;
        if (puVar14 == puVar15) goto LAB_0054f004;
      }
      pbVar16 = abStack_80;
      iVar3 = (*(code *)PTR_UTF8_putc_006a8cc8)(pbVar16,6,AStack_88.type);
      if (0 < iVar3) {
        pbVar18 = pbVar16 + iVar3;
        do {
          while( true ) {
            bVar1 = *pbVar16;
            _Stack_8c.boolean = _Stack_8c.boolean & 0xffffffU | (uint)bVar1 << 0x18;
            if ((char)bVar1 < '\0') break;
            uVar20 = (uVar2 | uVar13) & (uint)(byte)char_type[bVar1];
            if ((uVar20 & 0x61) == 0) goto LAB_0054f044;
            if ((uVar20 & 8) == 0) {
              iVar3 = (*(code *)PTR_fwrite_006a9a74)(&DAT_00669598,1,1,a);
              if (iVar3 != 1) goto LAB_0054ea38;
              iVar3 = (*(code *)PTR_fwrite_006a9a74)(&_Stack_8c,1,1,a);
            }
            else {
LAB_0054efcc:
              iVar3 = (*(code *)PTR_fwrite_006a9a74)(&_Stack_8c,1,1,a);
            }
            if (iVar3 != 1) goto LAB_0054ea38;
joined_r0x0054f204:
            pbVar16 = pbVar16 + 1;
            if (pbVar18 == pbVar16) goto LAB_0054eff8;
          }
          uVar20 = param_2 & 4;
LAB_0054f044:
          if ((uVar20 & 6) == 0) {
            if ((bVar1 != 0x5c) || (uVar2 == 0)) goto LAB_0054efcc;
            iVar3 = (*(code *)PTR_fwrite_006a9a74)(&DAT_006695a4,1,2,a);
            if (iVar3 == 2) goto joined_r0x0054f204;
            goto LAB_0054ea38;
          }
          (*(code *)PTR_BIO_snprintf_006a6f60)(&cStack_78,0xb,"\\%02X");
          iVar3 = (*(code *)PTR_fwrite_006a9a74)(&cStack_78,1,3,a);
          if (iVar3 != 3) goto LAB_0054ea38;
          pbVar16 = pbVar16 + 1;
        } while (pbVar18 != pbVar16);
      }
LAB_0054eff8:
    } while (puVar14 != puVar15);
  }
LAB_0054f004:
  puVar5 = puStack_b8;
  if (cStack_8d == '\0') goto LAB_0054ea40;
  iVar3 = (*(code *)PTR_fwrite_006a9a74)(&DAT_00679c10,1,1,a);
  if (iVar3 == 1) goto LAB_0054ea40;
LAB_0054ea38:
  do {
    puVar5 = (undefined *)0xffffffff;
LAB_0054ea40:
    while( true ) {
      if (iStack_6c == *(int *)puVar4) {
        return puVar5;
      }
      (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_0054f954:
      AStack_88.type = *(int *)((int)param_3 + 4);
      AStack_88.value.ptr = param_3;
      iVar3 = i2d_ASN1_TYPE(&AStack_88,(uchar **)0x0);
      param_3 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar3,"a_strex.c",0x13d);
      if ((byte *)param_3 == (byte *)0x0) break;
      _Stack_8c.ptr = param_3;
      i2d_ASN1_TYPE(&AStack_88,(uchar **)&_Stack_8c.ptr);
      if (param_3 + iVar3 != param_3) {
        _Var19.ptr = param_3;
        do {
          cStack_78 = "0123456789ABCDEF"[(byte)*_Var19.ptr >> 4];
          cStack_77 = "0123456789ABCDEF"[(byte)*_Var19.ptr & 0xf];
          iVar9 = (*(code *)PTR_fwrite_006a9a74)(&cStack_78,1,2,a);
          if (iVar9 != 2) {
            (*(code *)PTR_CRYPTO_free_006a6e88)(param_3);
            goto LAB_0054ea38;
          }
          _Var19.ptr = (char *)((int)&(_Var19.asn1_string)->length + 1);
        } while (param_3 + iVar3 != _Var19.ptr);
      }
LAB_0054f804:
      a = (ASN1_TYPE *)(iVar3 * 2);
      (*(code *)PTR_CRYPTO_free_006a6e88)(param_3);
      if ((int)a < 0) break;
      puVar5 = (undefined *)((int)&a->type + uStack_b4 + 1);
    }
  } while( true );
}

