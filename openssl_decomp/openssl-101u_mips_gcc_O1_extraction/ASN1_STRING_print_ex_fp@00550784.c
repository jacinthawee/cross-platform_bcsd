
int ASN1_STRING_print_ex_fp(FILE *fp,ASN1_STRING *str,ulong flags)

{
  byte bVar1;
  uint uVar2;
  undefined *puVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  ushort *puVar13;
  ushort *puVar14;
  ASN1_STRING *pAVar15;
  ushort *puVar16;
  byte *pbVar17;
  _union_257 _Var18;
  uint uVar19;
  byte *pbVar20;
  char *pcStack_78;
  uint uStack_74;
  char cStack_4d;
  _union_257 _Stack_4c;
  ASN1_TYPE AStack_48;
  byte abStack_40 [4];
  byte bStack_3c;
  byte bStack_3b;
  char cStack_38;
  char cStack_37;
  char *pcStack_2c;
  
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  uVar2 = flags & 0xf;
  cStack_4d = '\0';
  pcStack_2c = *(char **)PTR___stack_chk_guard_006a9ae8;
  iVar11 = str->type;
  if ((flags & 0x40) == 0) {
    uStack_74 = 0;
  }
  else {
    pcVar4 = ASN1_tag2str(iVar11);
    iVar8 = (*(code *)PTR_strlen_006a9a24)(pcVar4);
    if ((fp != (FILE *)0x0) &&
       ((iVar5 = (*(code *)PTR_fwrite_006a9a74)(pcVar4,1,iVar8,fp), iVar8 != iVar5 ||
        (iVar5 = (*(code *)PTR_fwrite_006a9a74)(":",1,1,fp), iVar5 != 1)))) goto LAB_0054ea38;
    uStack_74 = iVar8 + 1;
  }
  if ((flags & 0x80) != 0) {
LAB_0054ea0c:
    if (fp == (FILE *)0x0) {
      fp = (FILE *)&AStack_48;
      if ((flags & 0x200) != 0) {
        AStack_48.type = str->type;
        AStack_48.value.asn1_string = str;
        iVar11 = i2d_ASN1_TYPE((ASN1_TYPE *)fp,(uchar **)0x0);
        str = (ASN1_STRING *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar11,"a_strex.c",0x13d);
        if (str != (ASN1_STRING *)0x0) {
          _Stack_4c.ptr = (char *)str;
          i2d_ASN1_TYPE((ASN1_TYPE *)fp,(uchar **)&_Stack_4c.ptr);
          goto LAB_0054f804;
        }
        goto LAB_0054ea38;
      }
      iVar11 = str->length;
    }
    else {
      iVar11 = (*(code *)PTR_fwrite_006a9a74)(&DAT_006695a8,1,1,fp);
      if (iVar11 != 1) goto LAB_0054ea38;
      if ((flags & 0x200) != 0) goto LAB_0054f954;
      pAVar15 = (ASN1_STRING *)str->data;
      iVar11 = str->length;
      str = (ASN1_STRING *)((int)&pAVar15->length + iVar11);
      if (str != pAVar15) {
        do {
          cStack_38 = "0123456789ABCDEF"[*(byte *)&pAVar15->length >> 4];
          cStack_37 = "0123456789ABCDEF"[*(byte *)&pAVar15->length & 0xf];
          iVar8 = (*(code *)PTR_fwrite_006a9a74)(&cStack_38,1,2,fp);
          if (iVar8 != 2) goto LAB_0054ea38;
          pAVar15 = (ASN1_STRING *)((int)&pAVar15->length + 1);
        } while (str != pAVar15);
      }
    }
    if (-1 < iVar11 * 2) {
      pcVar4 = (char *)(uStack_74 + iVar11 * 2 + 1);
      goto LAB_0054ea40;
    }
    goto LAB_0054ea38;
  }
  if ((flags & 0x20) == 0) {
    if ((0x1d < iVar11 - 1U) || (uVar12 = (uint)(char)tag2nbyte[iVar11], uVar12 == 0xffffffff)) {
      if ((flags & 0x100) != 0) goto LAB_0054ea0c;
      goto LAB_0054eb54;
    }
    if ((flags & 0x10) != 0) {
      if (uVar12 == 0) {
        uVar12 = 1;
      }
      else {
        uVar12 = uVar12 | 8;
      }
    }
  }
  else {
LAB_0054eb54:
    uVar12 = 1;
    if ((flags & 0x10) != 0) {
      uVar12 = 9;
    }
  }
  iVar11 = str->length;
  puVar13 = (ushort *)str->data;
  puVar16 = (ushort *)((int)puVar13 + iVar11);
  if (puVar13 == puVar16) {
    iVar8 = 0;
  }
  else {
    uVar19 = uVar12 & 7;
    iVar8 = 0;
    puVar14 = puVar13;
    do {
      if (puVar13 == puVar14) {
        uVar9 = 0x20;
        if ((flags & 1) == 0) {
          uVar9 = 0;
        }
      }
      else {
        uVar9 = 0;
      }
      if (uVar19 == 1) {
        AStack_48.type = (int)*(byte *)puVar14;
        puVar14 = (ushort *)((int)puVar14 + 1);
      }
      else if (uVar19 < 2) {
        if ((uVar19 != 0) ||
           (iVar5 = (*(code *)PTR_UTF8_getc_006a8ccc)(puVar14,iVar11,&AStack_48), iVar5 < 0))
        goto LAB_0054ea38;
        puVar14 = (ushort *)((int)puVar14 + iVar5);
      }
      else if (uVar19 == 2) {
        AStack_48.type = (int)*puVar14;
        puVar14 = puVar14 + 1;
      }
      else {
        pcVar4 = (char *)0xffffffff;
        if (uVar19 != 4) goto LAB_0054ea40;
        AStack_48.type =
             (uint)*(byte *)((int)puVar14 + 3) |
             (uint)*(byte *)(puVar14 + 1) << 8 |
             (uint)*(byte *)((int)puVar14 + 1) << 0x10 | (uint)*(byte *)puVar14 << 0x18;
        puVar14 = puVar14 + 2;
      }
      if ((puVar16 == puVar14) && ((flags & 1) != 0)) {
        uVar9 = 0x40;
      }
      if ((uVar12 & 8) == 0) {
        iVar5 = do_esc_char_constprop_7(AStack_48.type,uVar2 | uVar9,&cStack_4d,0);
        if (iVar5 < 0) goto LAB_0054ea38;
        iVar8 = iVar8 + iVar5;
      }
      else {
        iVar5 = (*(code *)PTR_UTF8_putc_006a8cc8)(abStack_40,6,AStack_48.type);
        if (0 < iVar5) {
          uVar9 = uVar2 | uVar9;
          uVar10 = (uint)abStack_40[0];
          if (uVar2 == 0) {
            uVar6 = flags & 4;
            if (((char)abStack_40[0] < '\0') ||
               (uVar6 = uVar9 & (byte)char_type[uVar10], (uVar6 & 0x61) == 0)) {
              if ((uVar6 & 6) == 0) {
                iVar7 = 1;
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a6f60)(&cStack_38,0xb,"\\%02X");
                iVar7 = 3;
              }
            }
            else if ((uVar6 & 8) == 0) {
              iVar7 = 2;
            }
            else {
              iVar7 = 1;
              cStack_4d = '\x01';
            }
            iVar8 = iVar8 + iVar7;
            if (iVar5 == 1) goto LAB_0054ee18;
            if ((char)abStack_40[1] < '\0') {
              uVar10 = flags & 4;
LAB_0054f4e4:
              if ((uVar10 & 6) == 0) {
                iVar7 = 1;
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a6f60)(&cStack_38,0xb,"\\%02X");
                iVar7 = 3;
              }
            }
            else {
              uVar10 = uVar9 & (byte)char_type[abStack_40[1]];
              if ((uVar10 & 0x61) == 0) goto LAB_0054f4e4;
              if ((uVar10 & 8) == 0) {
                iVar7 = 2;
              }
              else {
                cStack_4d = '\x01';
                iVar7 = 1;
              }
            }
            iVar8 = iVar8 + iVar7;
            if (iVar5 == 2) goto LAB_0054ee18;
            if ((char)abStack_40[2] < '\0') {
              uVar10 = flags & 4;
LAB_0054f4c8:
              if ((uVar10 & 6) == 0) {
                iVar7 = 1;
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a6f60)(&cStack_38,0xb,"\\%02X");
                iVar7 = 3;
              }
            }
            else {
              uVar10 = uVar9 & (byte)char_type[abStack_40[2]];
              if ((uVar10 & 0x61) == 0) goto LAB_0054f4c8;
              if ((uVar10 & 8) == 0) {
                iVar7 = 2;
              }
              else {
                iVar7 = 1;
                cStack_4d = '\x01';
              }
            }
            iVar8 = iVar8 + iVar7;
            if (iVar5 == 3) goto LAB_0054ee18;
            if ((char)abStack_40[3] < '\0') {
              uVar10 = flags & 4;
LAB_0054f500:
              if ((uVar10 & 6) == 0) {
                iVar7 = 1;
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a6f60)(&cStack_38,0xb,"\\%02X");
                iVar7 = 3;
              }
            }
            else {
              uVar10 = uVar9 & (byte)char_type[abStack_40[3]];
              if ((uVar10 & 0x61) == 0) goto LAB_0054f500;
              if ((uVar10 & 8) == 0) {
                iVar7 = 2;
              }
              else {
                iVar7 = 1;
                cStack_4d = '\x01';
              }
            }
            iVar8 = iVar8 + iVar7;
            if (iVar5 == 4) goto LAB_0054ee18;
            if ((char)bStack_3c < '\0') {
              uVar10 = flags & 4;
LAB_0054f4ac:
              if ((uVar10 & 6) == 0) {
                iVar7 = 1;
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a6f60)(&cStack_38,0xb,"\\%02X");
                iVar7 = 3;
              }
            }
            else {
              uVar10 = uVar9 & (byte)char_type[bStack_3c];
              if ((uVar10 & 0x61) == 0) goto LAB_0054f4ac;
              if ((uVar10 & 8) == 0) {
                iVar7 = 2;
              }
              else {
                iVar7 = 1;
                cStack_4d = '\x01';
              }
            }
            iVar8 = iVar8 + iVar7;
            if (iVar5 == 5) goto LAB_0054ee18;
            if ((char)bStack_3b < '\0') {
              uVar9 = flags & 4;
LAB_0054f490:
              if ((uVar9 & 6) == 0) {
                iVar8 = iVar8 + 1;
                goto LAB_0054ee18;
              }
LAB_0054f524:
              (*(code *)PTR_BIO_snprintf_006a6f60)(&cStack_38,0xb,"\\%02X");
              iVar8 = iVar8 + 3;
            }
            else {
              uVar9 = uVar9 & (byte)char_type[bStack_3b];
              if ((uVar9 & 0x61) == 0) goto LAB_0054f490;
LAB_0054ee00:
              if ((uVar9 & 8) == 0) {
                iVar8 = iVar8 + 2;
              }
              else {
                iVar8 = iVar8 + 1;
                cStack_4d = '\x01';
              }
            }
          }
          else {
            if ((char)abStack_40[0] < '\0') {
              uVar6 = flags & 4;
LAB_0054f46c:
              if ((uVar6 & 6) == 0) {
                iVar7 = 1;
                if (uVar10 == 0x5c) {
                  iVar7 = 2;
                }
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a6f60)(&cStack_38,0xb,"\\%02X");
                iVar7 = 3;
              }
            }
            else {
              uVar6 = uVar9 & (byte)char_type[uVar10];
              if ((uVar6 & 0x61) == 0) goto LAB_0054f46c;
              if ((uVar6 & 8) == 0) {
                iVar7 = 2;
              }
              else {
                iVar7 = 1;
                cStack_4d = '\x01';
              }
            }
            iVar8 = iVar8 + iVar7;
            if (iVar5 == 1) goto LAB_0054ee18;
            if ((char)abStack_40[1] < '\0') {
              uVar10 = flags & 4;
LAB_0054f670:
              if ((uVar10 & 6) == 0) {
                iVar7 = 2;
                if (abStack_40[1] != 0x5c) {
                  iVar7 = 1;
                }
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a6f60)(&cStack_38,0xb,"\\%02X");
                iVar7 = 3;
              }
            }
            else {
              uVar10 = uVar9 & (byte)char_type[abStack_40[1]];
              if ((uVar10 & 0x61) == 0) goto LAB_0054f670;
              if ((uVar10 & 8) == 0) {
                iVar7 = 2;
              }
              else {
                cStack_4d = '\x01';
                iVar7 = 1;
              }
            }
            iVar8 = iVar8 + iVar7;
            if (iVar5 == 2) goto LAB_0054ee18;
            if ((char)abStack_40[2] < '\0') {
              uVar10 = flags & 4;
LAB_0054f64c:
              if ((uVar10 & 6) == 0) {
                iVar7 = 2;
                if (abStack_40[2] != 0x5c) {
                  iVar7 = 1;
                }
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a6f60)(&cStack_38,0xb,"\\%02X");
                iVar7 = 3;
              }
            }
            else {
              uVar10 = uVar9 & (byte)char_type[abStack_40[2]];
              if ((uVar10 & 0x61) == 0) goto LAB_0054f64c;
              if ((uVar10 & 8) == 0) {
                iVar7 = 2;
              }
              else {
                iVar7 = 1;
                cStack_4d = '\x01';
              }
            }
            iVar8 = iVar8 + iVar7;
            if (iVar5 == 3) goto LAB_0054ee18;
            if ((char)abStack_40[3] < '\0') {
              uVar10 = flags & 4;
LAB_0054f628:
              if ((uVar10 & 6) == 0) {
                iVar7 = 2;
                if (abStack_40[3] != 0x5c) {
                  iVar7 = 1;
                }
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a6f60)(&cStack_38,0xb,"\\%02X");
                iVar7 = 3;
              }
            }
            else {
              uVar10 = uVar9 & (byte)char_type[abStack_40[3]];
              if ((uVar10 & 0x61) == 0) goto LAB_0054f628;
              if ((uVar10 & 8) == 0) {
                iVar7 = 2;
              }
              else {
                iVar7 = 1;
                cStack_4d = '\x01';
              }
            }
            iVar8 = iVar8 + iVar7;
            if (iVar5 == 4) goto LAB_0054ee18;
            if ((char)bStack_3c < '\0') {
              uVar10 = flags & 4;
LAB_0054f604:
              if ((uVar10 & 6) == 0) {
                iVar7 = 2;
                if (bStack_3c != 0x5c) {
                  iVar7 = 1;
                }
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a6f60)(&cStack_38,0xb,"\\%02X");
                iVar7 = 3;
              }
            }
            else {
              uVar10 = uVar9 & (byte)char_type[bStack_3c];
              if ((uVar10 & 0x61) == 0) goto LAB_0054f604;
              if ((uVar10 & 8) == 0) {
                iVar7 = 2;
              }
              else {
                iVar7 = 1;
                cStack_4d = '\x01';
              }
            }
            iVar8 = iVar8 + iVar7;
            if (iVar5 != 5) {
              if ((char)bStack_3b < '\0') {
                uVar9 = flags & 4;
              }
              else {
                uVar9 = uVar9 & (byte)char_type[bStack_3b];
                if ((uVar9 & 0x61) != 0) goto LAB_0054ee00;
              }
              iVar5 = 1;
              if ((uVar9 & 6) != 0) goto LAB_0054f524;
              if (bStack_3b == 0x5c) {
                iVar5 = 2;
              }
              iVar8 = iVar8 + iVar5;
            }
          }
        }
      }
LAB_0054ee18:
    } while (puVar16 != puVar14);
  }
  pcStack_78 = (char *)(uStack_74 + iVar8);
  if (cStack_4d == '\0') {
    pcVar4 = pcStack_78;
    if (fp == (FILE *)0x0) goto LAB_0054ea40;
  }
  else {
    pcStack_78 = pcStack_78 + 2;
    pcVar4 = pcStack_78;
    if (fp == (FILE *)0x0) goto LAB_0054ea40;
    iVar11 = (*(code *)PTR_fwrite_006a9a74)(&DAT_00679c10,1,1,fp);
    if (iVar11 != 1) goto LAB_0054ea38;
  }
  iVar11 = str->length;
  puVar16 = (ushort *)str->data;
  puVar13 = (ushort *)((int)puVar16 + iVar11);
  if (puVar16 != puVar13) {
    str = (ASN1_STRING *)(uVar12 & 7);
    uStack_74 = uVar12 & 8;
    puVar14 = puVar16;
    do {
      while( true ) {
        if (puVar16 == puVar14) {
          uVar12 = 0x20;
          if ((flags & 1) == 0) {
            uVar12 = 0;
          }
        }
        else {
          uVar12 = 0;
        }
        if (str == (ASN1_STRING *)0x1) {
          AStack_48.type = (int)*(byte *)puVar14;
          puVar14 = (ushort *)((int)puVar14 + 1);
        }
        else if (str < (ASN1_STRING *)0x2) {
          if ((str != (ASN1_STRING *)0x0) ||
             (iVar8 = (*(code *)PTR_UTF8_getc_006a8ccc)(puVar14,iVar11,&AStack_48), iVar8 < 0))
          goto LAB_0054ea38;
          puVar14 = (ushort *)((int)puVar14 + iVar8);
        }
        else if (str == (ASN1_STRING *)&SUB_00000002) {
          AStack_48.type = (int)*puVar14;
          puVar14 = puVar14 + 1;
        }
        else {
          pcVar4 = (char *)0xffffffff;
          if (str != (ASN1_STRING *)&SUB_00000004) goto LAB_0054ea40;
          AStack_48.type =
               (uint)*(byte *)((int)puVar14 + 3) |
               (uint)*(byte *)(puVar14 + 1) << 8 |
               (uint)*(byte *)((int)puVar14 + 1) << 0x10 | (uint)*(byte *)puVar14 << 0x18;
          puVar14 = puVar14 + 2;
        }
        if ((puVar13 == puVar14) && ((flags & 1) != 0)) {
          uVar12 = 0x40;
        }
        if (uStack_74 != 0) break;
        iVar8 = do_esc_char_constprop_7(AStack_48.type,uVar2 | uVar12,0,fp);
        if (iVar8 < 0) goto LAB_0054ea38;
        if (puVar13 == puVar14) goto LAB_0054f004;
      }
      pbVar20 = abStack_40;
      iVar8 = (*(code *)PTR_UTF8_putc_006a8cc8)(pbVar20,6,AStack_48.type);
      if (0 < iVar8) {
        pbVar17 = pbVar20 + iVar8;
        do {
          while( true ) {
            bVar1 = *pbVar20;
            _Stack_4c.boolean = _Stack_4c.boolean & 0xffffffU | (uint)bVar1 << 0x18;
            if ((char)bVar1 < '\0') break;
            uVar19 = (uVar2 | uVar12) & (uint)(byte)char_type[bVar1];
            if ((uVar19 & 0x61) == 0) goto LAB_0054f044;
            if ((uVar19 & 8) == 0) {
              iVar8 = (*(code *)PTR_fwrite_006a9a74)(&DAT_00669598,1,1,fp);
              if (iVar8 != 1) goto LAB_0054ea38;
              iVar8 = (*(code *)PTR_fwrite_006a9a74)(&_Stack_4c,1,1,fp);
            }
            else {
LAB_0054efcc:
              iVar8 = (*(code *)PTR_fwrite_006a9a74)(&_Stack_4c,1,1,fp);
            }
            if (iVar8 != 1) goto LAB_0054ea38;
joined_r0x0054f204:
            pbVar20 = pbVar20 + 1;
            if (pbVar17 == pbVar20) goto LAB_0054eff8;
          }
          uVar19 = flags & 4;
LAB_0054f044:
          if ((uVar19 & 6) == 0) {
            if ((bVar1 != 0x5c) || (uVar2 == 0)) goto LAB_0054efcc;
            iVar8 = (*(code *)PTR_fwrite_006a9a74)(&DAT_006695a4,1,2,fp);
            if (iVar8 == 2) goto joined_r0x0054f204;
            goto LAB_0054ea38;
          }
          (*(code *)PTR_BIO_snprintf_006a6f60)(&cStack_38,0xb,"\\%02X");
          iVar8 = (*(code *)PTR_fwrite_006a9a74)(&cStack_38,1,3,fp);
          if (iVar8 != 3) goto LAB_0054ea38;
          pbVar20 = pbVar20 + 1;
        } while (pbVar17 != pbVar20);
      }
LAB_0054eff8:
    } while (puVar13 != puVar14);
  }
LAB_0054f004:
  pcVar4 = pcStack_78;
  if (cStack_4d == '\0') goto LAB_0054ea40;
  iVar11 = (*(code *)PTR_fwrite_006a9a74)(&DAT_00679c10,1,1,fp);
  if (iVar11 == 1) goto LAB_0054ea40;
LAB_0054ea38:
  do {
    pcVar4 = (char *)0xffffffff;
LAB_0054ea40:
    while( true ) {
      if (pcStack_2c == *(char **)puVar3) {
        return (int)pcVar4;
      }
      (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_0054f954:
      AStack_48.type = str->type;
      AStack_48.value.asn1_string = str;
      iVar11 = i2d_ASN1_TYPE(&AStack_48,(uchar **)0x0);
      str = (ASN1_STRING *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar11,"a_strex.c",0x13d);
      if (str == (ASN1_STRING *)0x0) break;
      _Stack_4c.ptr = (char *)str;
      i2d_ASN1_TYPE(&AStack_48,(uchar **)&_Stack_4c.ptr);
      if ((ASN1_STRING *)((int)str + iVar11) != str) {
        _Var18.ptr = (char *)str;
        do {
          cStack_38 = "0123456789ABCDEF"[(byte)*_Var18.ptr >> 4];
          cStack_37 = "0123456789ABCDEF"[(byte)*_Var18.ptr & 0xf];
          iVar8 = (*(code *)PTR_fwrite_006a9a74)(&cStack_38,1,2,fp);
          if (iVar8 != 2) {
            (*(code *)PTR_CRYPTO_free_006a6e88)(str);
            goto LAB_0054ea38;
          }
          _Var18.ptr = (char *)((int)&(_Var18.asn1_string)->length + 1);
        } while ((ASN1_STRING *)((int)str + iVar11) != (ASN1_STRING *)_Var18.ptr);
      }
LAB_0054f804:
      fp = (FILE *)(iVar11 * 2);
      (*(code *)PTR_CRYPTO_free_006a6e88)(str);
      if ((int)fp < 0) break;
      pcVar4 = fp->_shortbuf + (uStack_74 - 0x46);
    }
  } while( true );
}

