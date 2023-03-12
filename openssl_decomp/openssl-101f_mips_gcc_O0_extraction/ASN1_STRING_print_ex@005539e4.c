
int ASN1_STRING_print_ex(BIO *out,ASN1_STRING *str,ulong flags)

{
  byte bVar1;
  uint uVar2;
  undefined *puVar3;
  char *pcVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  ushort *puVar12;
  ushort *puVar13;
  ASN1_STRING *pAVar14;
  ushort *puVar15;
  byte *pbVar16;
  _union_257 _Var17;
  uint uVar18;
  byte *pbVar19;
  int iStack_78;
  uint uStack_74;
  char cStack_4d;
  _union_257 _Stack_4c;
  ASN1_TYPE AStack_48;
  byte abStack_40 [4];
  byte bStack_3c;
  byte bStack_3b;
  char cStack_38;
  char cStack_37;
  int iStack_2c;
  
  puVar3 = PTR___stack_chk_guard_006aabf0;
  uVar2 = flags & 0xf;
  cStack_4d = '\0';
  iStack_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar10 = str->type;
  if ((flags & 0x40) == 0) {
    uStack_74 = 0;
  }
  else {
    pcVar4 = ASN1_tag2str(iVar10);
    iVar7 = (*(code *)PTR_strlen_006aab30)(pcVar4);
    if ((out != (BIO *)0x0) &&
       ((iVar6 = (*(code *)PTR_BIO_write_006a7f14)(out,pcVar4,iVar7), iVar7 != iVar6 ||
        (iVar6 = (*(code *)PTR_BIO_write_006a7f14)(out,":",1), iVar6 != 1)))) goto LAB_00550980;
    uStack_74 = iVar7 + 1;
  }
  if ((flags & 0x80) != 0) {
LAB_00550958:
    if (out == (BIO *)0x0) {
      out = (BIO *)&AStack_48;
      if ((flags & 0x200) != 0) {
        AStack_48.type = str->type;
        AStack_48.value.asn1_string = str;
        iVar10 = i2d_ASN1_TYPE((ASN1_TYPE *)out,(uchar **)0x0);
        str = (ASN1_STRING *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar10,"a_strex.c",0x119);
        if (str != (ASN1_STRING *)0x0) {
          _Stack_4c.ptr = (char *)str;
          i2d_ASN1_TYPE((ASN1_TYPE *)out,(uchar **)&_Stack_4c.ptr);
          goto LAB_00551724;
        }
        goto LAB_00550980;
      }
      iVar10 = str->length;
    }
    else {
      iVar10 = (*(code *)PTR_BIO_write_006a7f14)(out,&DAT_0066a058,1);
      if (iVar10 != 1) goto LAB_00550980;
      if ((flags & 0x200) != 0) goto LAB_00551874;
      pAVar14 = (ASN1_STRING *)str->data;
      iVar10 = str->length;
      str = (ASN1_STRING *)((int)&pAVar14->length + iVar10);
      if (str != pAVar14) {
        do {
          cStack_38 = "0123456789ABCDEF"[*(byte *)&pAVar14->length >> 4];
          cStack_37 = "0123456789ABCDEF"[*(byte *)&pAVar14->length & 0xf];
          iVar7 = (*(code *)PTR_BIO_write_006a7f14)(out,&cStack_38,2);
          if (iVar7 != 2) goto LAB_00550980;
          pAVar14 = (ASN1_STRING *)((int)&pAVar14->length + 1);
        } while (str != pAVar14);
      }
    }
    if (-1 < iVar10 * 2) {
      iVar10 = uStack_74 + iVar10 * 2 + 1;
      goto LAB_00550988;
    }
    goto LAB_00550980;
  }
  if ((flags & 0x20) == 0) {
    if ((0x1d < iVar10 - 1U) || (uVar11 = (uint)(char)tag2nbyte[iVar10], uVar11 == 0xffffffff)) {
      if ((flags & 0x100) != 0) goto LAB_00550958;
      goto LAB_00550a94;
    }
    if ((flags & 0x10) != 0) {
      if (uVar11 == 0) {
        uVar11 = 1;
      }
      else {
        uVar11 = uVar11 | 8;
      }
    }
  }
  else {
LAB_00550a94:
    uVar11 = 1;
    if ((flags & 0x10) != 0) {
      uVar11 = 9;
    }
  }
  iVar7 = str->length;
  puVar12 = (ushort *)str->data;
  puVar15 = (ushort *)((int)puVar12 + iVar7);
  if (puVar12 == puVar15) {
    iStack_78 = 0;
  }
  else {
    uVar18 = uVar11 & 7;
    iStack_78 = 0;
    puVar13 = puVar12;
    do {
      if (puVar12 == puVar13) {
        uVar8 = 0x20;
        if ((flags & 1) == 0) {
          uVar8 = 0;
        }
      }
      else {
        uVar8 = 0;
      }
      if (uVar18 == 1) {
        AStack_48.type = (int)*(byte *)puVar13;
        puVar13 = (ushort *)((int)puVar13 + 1);
      }
      else if (uVar18 < 2) {
        if ((uVar18 != 0) ||
           (iVar10 = (*(code *)PTR_UTF8_getc_006a9df0)(puVar13,iVar7,&AStack_48), iVar10 < 0))
        goto LAB_00550980;
        puVar13 = (ushort *)((int)puVar13 + iVar10);
      }
      else if (uVar18 == 2) {
        AStack_48.type = (int)*puVar13;
        puVar13 = puVar13 + 1;
      }
      else {
        iVar10 = -1;
        if (uVar18 != 4) goto LAB_00550988;
        AStack_48.type =
             (uint)*(byte *)((int)puVar13 + 3) |
             (uint)*(byte *)(puVar13 + 1) << 8 |
             (uint)*(byte *)((int)puVar13 + 1) << 0x10 | (uint)*(byte *)puVar13 << 0x18;
        puVar13 = puVar13 + 2;
      }
      if ((puVar15 == puVar13) && ((flags & 1) != 0)) {
        uVar8 = 0x40;
      }
      if ((uVar11 & 8) == 0) {
        iVar10 = do_esc_char_constprop_6(AStack_48.type,uVar2 | uVar8,&cStack_4d,0);
        if (iVar10 < 0) goto LAB_00550980;
        iStack_78 = iStack_78 + iVar10;
      }
      else {
        iVar10 = (*(code *)PTR_UTF8_putc_006a9dec)(abStack_40,6,AStack_48.type);
        if (0 < iVar10) {
          uVar8 = uVar2 | uVar8;
          uVar9 = (uint)abStack_40[0];
          if (uVar2 == 0) {
            uVar5 = flags & 4;
            if (((char)abStack_40[0] < '\0') ||
               (uVar5 = uVar8 & (byte)char_type[uVar9], (uVar5 & 0x61) == 0)) {
              if ((uVar5 & 6) == 0) {
                iVar6 = 1;
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a8060)(&cStack_38,0xb,"\\%02X");
                iVar6 = 3;
              }
            }
            else if ((uVar5 & 8) == 0) {
              iVar6 = 2;
            }
            else {
              iVar6 = 1;
              cStack_4d = '\x01';
            }
            iStack_78 = iStack_78 + iVar6;
            if (iVar10 == 1) goto LAB_00550d58;
            if ((char)abStack_40[1] < '\0') {
              uVar9 = flags & 4;
LAB_00551408:
              if ((uVar9 & 6) == 0) {
                iVar6 = 1;
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a8060)(&cStack_38,0xb,"\\%02X");
                iVar6 = 3;
              }
            }
            else {
              uVar9 = uVar8 & (byte)char_type[abStack_40[1]];
              if ((uVar9 & 0x61) == 0) goto LAB_00551408;
              if ((uVar9 & 8) == 0) {
                iVar6 = 2;
              }
              else {
                cStack_4d = '\x01';
                iVar6 = 1;
              }
            }
            iStack_78 = iStack_78 + iVar6;
            if (iVar10 == 2) goto LAB_00550d58;
            if ((char)abStack_40[2] < '\0') {
              uVar9 = flags & 4;
LAB_005513ec:
              if ((uVar9 & 6) == 0) {
                iVar6 = 1;
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a8060)(&cStack_38,0xb,"\\%02X");
                iVar6 = 3;
              }
            }
            else {
              uVar9 = uVar8 & (byte)char_type[abStack_40[2]];
              if ((uVar9 & 0x61) == 0) goto LAB_005513ec;
              if ((uVar9 & 8) == 0) {
                iVar6 = 2;
              }
              else {
                iVar6 = 1;
                cStack_4d = '\x01';
              }
            }
            iStack_78 = iStack_78 + iVar6;
            if (iVar10 == 3) goto LAB_00550d58;
            if ((char)abStack_40[3] < '\0') {
              uVar9 = flags & 4;
LAB_00551424:
              if ((uVar9 & 6) == 0) {
                iVar6 = 1;
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a8060)(&cStack_38,0xb,"\\%02X");
                iVar6 = 3;
              }
            }
            else {
              uVar9 = uVar8 & (byte)char_type[abStack_40[3]];
              if ((uVar9 & 0x61) == 0) goto LAB_00551424;
              if ((uVar9 & 8) == 0) {
                iVar6 = 2;
              }
              else {
                iVar6 = 1;
                cStack_4d = '\x01';
              }
            }
            iStack_78 = iStack_78 + iVar6;
            if (iVar10 == 4) goto LAB_00550d58;
            if ((char)bStack_3c < '\0') {
              uVar9 = flags & 4;
LAB_005513d0:
              if ((uVar9 & 6) == 0) {
                iVar6 = 1;
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a8060)(&cStack_38,0xb,"\\%02X");
                iVar6 = 3;
              }
            }
            else {
              uVar9 = uVar8 & (byte)char_type[bStack_3c];
              if ((uVar9 & 0x61) == 0) goto LAB_005513d0;
              if ((uVar9 & 8) == 0) {
                iVar6 = 2;
              }
              else {
                iVar6 = 1;
                cStack_4d = '\x01';
              }
            }
            iStack_78 = iStack_78 + iVar6;
            if (iVar10 == 5) goto LAB_00550d58;
            if ((char)bStack_3b < '\0') {
              uVar8 = flags & 4;
LAB_005513b4:
              if ((uVar8 & 6) == 0) {
                iStack_78 = iStack_78 + 1;
                goto LAB_00550d58;
              }
LAB_00551448:
              (*(code *)PTR_BIO_snprintf_006a8060)(&cStack_38,0xb,"\\%02X");
              iStack_78 = iStack_78 + 3;
            }
            else {
              uVar8 = uVar8 & (byte)char_type[bStack_3b];
              if ((uVar8 & 0x61) == 0) goto LAB_005513b4;
LAB_00550d40:
              if ((uVar8 & 8) == 0) {
                iStack_78 = iStack_78 + 2;
              }
              else {
                iStack_78 = iStack_78 + 1;
                cStack_4d = '\x01';
              }
            }
          }
          else {
            if ((char)abStack_40[0] < '\0') {
              uVar5 = flags & 4;
LAB_00551390:
              if ((uVar5 & 6) == 0) {
                iVar6 = 1;
                if (uVar9 == 0x5c) {
                  iVar6 = 2;
                }
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a8060)(&cStack_38,0xb,"\\%02X");
                iVar6 = 3;
              }
            }
            else {
              uVar5 = uVar8 & (byte)char_type[uVar9];
              if ((uVar5 & 0x61) == 0) goto LAB_00551390;
              if ((uVar5 & 8) == 0) {
                iVar6 = 2;
              }
              else {
                iVar6 = 1;
                cStack_4d = '\x01';
              }
            }
            iStack_78 = iStack_78 + iVar6;
            if (iVar10 == 1) goto LAB_00550d58;
            if ((char)abStack_40[1] < '\0') {
              uVar9 = flags & 4;
LAB_00551590:
              if ((uVar9 & 6) == 0) {
                iVar6 = 2;
                if (abStack_40[1] != 0x5c) {
                  iVar6 = 1;
                }
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a8060)(&cStack_38,0xb,"\\%02X");
                iVar6 = 3;
              }
            }
            else {
              uVar9 = uVar8 & (byte)char_type[abStack_40[1]];
              if ((uVar9 & 0x61) == 0) goto LAB_00551590;
              if ((uVar9 & 8) == 0) {
                iVar6 = 2;
              }
              else {
                cStack_4d = '\x01';
                iVar6 = 1;
              }
            }
            iStack_78 = iStack_78 + iVar6;
            if (iVar10 == 2) goto LAB_00550d58;
            if ((char)abStack_40[2] < '\0') {
              uVar9 = flags & 4;
LAB_0055156c:
              if ((uVar9 & 6) == 0) {
                iVar6 = 2;
                if (abStack_40[2] != 0x5c) {
                  iVar6 = 1;
                }
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a8060)(&cStack_38,0xb,"\\%02X");
                iVar6 = 3;
              }
            }
            else {
              uVar9 = uVar8 & (byte)char_type[abStack_40[2]];
              if ((uVar9 & 0x61) == 0) goto LAB_0055156c;
              if ((uVar9 & 8) == 0) {
                iVar6 = 2;
              }
              else {
                iVar6 = 1;
                cStack_4d = '\x01';
              }
            }
            iStack_78 = iStack_78 + iVar6;
            if (iVar10 == 3) goto LAB_00550d58;
            if ((char)abStack_40[3] < '\0') {
              uVar9 = flags & 4;
LAB_00551548:
              if ((uVar9 & 6) == 0) {
                iVar6 = 2;
                if (abStack_40[3] != 0x5c) {
                  iVar6 = 1;
                }
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a8060)(&cStack_38,0xb,"\\%02X");
                iVar6 = 3;
              }
            }
            else {
              uVar9 = uVar8 & (byte)char_type[abStack_40[3]];
              if ((uVar9 & 0x61) == 0) goto LAB_00551548;
              if ((uVar9 & 8) == 0) {
                iVar6 = 2;
              }
              else {
                iVar6 = 1;
                cStack_4d = '\x01';
              }
            }
            iStack_78 = iStack_78 + iVar6;
            if (iVar10 == 4) goto LAB_00550d58;
            if ((char)bStack_3c < '\0') {
              uVar9 = flags & 4;
LAB_00551524:
              if ((uVar9 & 6) == 0) {
                iVar6 = 2;
                if (bStack_3c != 0x5c) {
                  iVar6 = 1;
                }
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a8060)(&cStack_38,0xb,"\\%02X");
                iVar6 = 3;
              }
            }
            else {
              uVar9 = uVar8 & (byte)char_type[bStack_3c];
              if ((uVar9 & 0x61) == 0) goto LAB_00551524;
              if ((uVar9 & 8) == 0) {
                iVar6 = 2;
              }
              else {
                iVar6 = 1;
                cStack_4d = '\x01';
              }
            }
            iStack_78 = iStack_78 + iVar6;
            if (iVar10 != 5) {
              if ((char)bStack_3b < '\0') {
                uVar8 = flags & 4;
              }
              else {
                uVar8 = uVar8 & (byte)char_type[bStack_3b];
                if ((uVar8 & 0x61) != 0) goto LAB_00550d40;
              }
              iVar10 = 1;
              if ((uVar8 & 6) != 0) goto LAB_00551448;
              if (bStack_3b == 0x5c) {
                iVar10 = 2;
              }
              iStack_78 = iStack_78 + iVar10;
            }
          }
        }
      }
LAB_00550d58:
    } while (puVar15 != puVar13);
  }
  iStack_78 = uStack_74 + iStack_78;
  if (cStack_4d == '\0') {
    iVar10 = iStack_78;
    if (out == (BIO *)0x0) goto LAB_00550988;
  }
  else {
    iStack_78 = iStack_78 + 2;
    iVar10 = iStack_78;
    if (out == (BIO *)0x0) goto LAB_00550988;
    iVar10 = (*(code *)PTR_BIO_write_006a7f14)(out,&DAT_0067a4c0,1);
    if (iVar10 != 1) goto LAB_00550980;
  }
  iVar7 = str->length;
  puVar15 = (ushort *)str->data;
  puVar12 = (ushort *)((int)puVar15 + iVar7);
  if (puVar15 != puVar12) {
    str = (ASN1_STRING *)(uVar11 & 7);
    uStack_74 = uVar11 & 8;
    puVar13 = puVar15;
    do {
      while( true ) {
        if (puVar13 == puVar15) {
          uVar11 = 0x20;
          if ((flags & 1) == 0) {
            uVar11 = 0;
          }
        }
        else {
          uVar11 = 0;
        }
        if (str == (ASN1_STRING *)0x1) {
          AStack_48.type = (int)*(byte *)puVar13;
          puVar13 = (ushort *)((int)puVar13 + 1);
        }
        else if (str < (ASN1_STRING *)0x2) {
          if ((str != (ASN1_STRING *)0x0) ||
             (iVar10 = (*(code *)PTR_UTF8_getc_006a9df0)(puVar13,iVar7,&AStack_48), iVar10 < 0))
          goto LAB_00550980;
          puVar13 = (ushort *)((int)puVar13 + iVar10);
        }
        else if (str == (ASN1_STRING *)&SUB_00000002) {
          AStack_48.type = (int)*puVar13;
          puVar13 = puVar13 + 1;
        }
        else {
          iVar10 = -1;
          if (str != (ASN1_STRING *)&SUB_00000004) goto LAB_00550988;
          AStack_48.type =
               (uint)*(byte *)((int)puVar13 + 3) |
               (uint)*(byte *)(puVar13 + 1) << 8 |
               (uint)*(byte *)((int)puVar13 + 1) << 0x10 | (uint)*(byte *)puVar13 << 0x18;
          puVar13 = puVar13 + 2;
        }
        if ((puVar12 == puVar13) && ((flags & 1) != 0)) {
          uVar11 = 0x40;
        }
        if (uStack_74 != 0) break;
        iVar10 = do_esc_char_constprop_6(AStack_48.type,uVar2 | uVar11,0,out);
        if (iVar10 < 0) goto LAB_00550980;
        if (puVar12 == puVar13) goto LAB_00550f3c;
      }
      pbVar19 = abStack_40;
      iVar10 = (*(code *)PTR_UTF8_putc_006a9dec)(pbVar19,6,AStack_48.type);
      if (0 < iVar10) {
        pbVar16 = pbVar19 + iVar10;
        do {
          while( true ) {
            bVar1 = *pbVar19;
            _Stack_4c.boolean = _Stack_4c.boolean & 0xffffffU | (uint)bVar1 << 0x18;
            if ((char)bVar1 < '\0') break;
            uVar18 = (uVar2 | uVar11) & (uint)(byte)char_type[bVar1];
            if ((uVar18 & 0x61) == 0) goto LAB_00550f78;
            if ((uVar18 & 8) == 0) {
              iVar10 = (*(code *)PTR_BIO_write_006a7f14)(out,&DAT_0066a048,1);
              if (iVar10 != 1) goto LAB_00550980;
              iVar10 = (*(code *)PTR_BIO_write_006a7f14)(out,&_Stack_4c,1);
            }
            else {
LAB_00550f08:
              iVar10 = (*(code *)PTR_BIO_write_006a7f14)(out,&_Stack_4c,1);
            }
            if (iVar10 != 1) goto LAB_00550980;
joined_r0x00551128:
            pbVar19 = pbVar19 + 1;
            if (pbVar16 == pbVar19) goto LAB_00550f30;
          }
          uVar18 = flags & 4;
LAB_00550f78:
          if ((uVar18 & 6) == 0) {
            if ((bVar1 != 0x5c) || (uVar2 == 0)) goto LAB_00550f08;
            iVar10 = (*(code *)PTR_BIO_write_006a7f14)(out,&DAT_0066a054,2);
            if (iVar10 == 2) goto joined_r0x00551128;
            goto LAB_00550980;
          }
          (*(code *)PTR_BIO_snprintf_006a8060)(&cStack_38,0xb,"\\%02X");
          iVar10 = (*(code *)PTR_BIO_write_006a7f14)(out,&cStack_38,3);
          if (iVar10 != 3) goto LAB_00550980;
          pbVar19 = pbVar19 + 1;
        } while (pbVar16 != pbVar19);
      }
LAB_00550f30:
    } while (puVar12 != puVar13);
  }
LAB_00550f3c:
  iVar10 = iStack_78;
  if (cStack_4d == '\0') goto LAB_00550988;
  iVar7 = (*(code *)PTR_BIO_write_006a7f14)(out,&DAT_0067a4c0,1);
  if (iVar7 == 1) goto LAB_00550988;
LAB_00550980:
  do {
    iVar10 = -1;
LAB_00550988:
    while( true ) {
      if (iStack_2c == *(int *)puVar3) {
        return iVar10;
      }
      (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_00551874:
      AStack_48.type = str->type;
      AStack_48.value.asn1_string = str;
      iVar10 = i2d_ASN1_TYPE(&AStack_48,(uchar **)0x0);
      str = (ASN1_STRING *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar10,"a_strex.c",0x119);
      if (str == (ASN1_STRING *)0x0) break;
      _Stack_4c.ptr = (char *)str;
      i2d_ASN1_TYPE(&AStack_48,(uchar **)&_Stack_4c.ptr);
      if ((ASN1_STRING *)((int)str + iVar10) != str) {
        _Var17.ptr = (char *)str;
        do {
          cStack_38 = "0123456789ABCDEF"[(byte)*_Var17.ptr >> 4];
          cStack_37 = "0123456789ABCDEF"[(byte)*_Var17.ptr & 0xf];
          iVar7 = (*(code *)PTR_BIO_write_006a7f14)(out,&cStack_38,2);
          if (iVar7 != 2) {
            (*(code *)PTR_CRYPTO_free_006a7f88)(str);
            goto LAB_00550980;
          }
          _Var17.ptr = (char *)((int)&(_Var17.asn1_string)->length + 1);
        } while ((ASN1_STRING *)((int)str + iVar10) != (ASN1_STRING *)_Var17.ptr);
      }
LAB_00551724:
      out = (BIO *)(iVar10 * 2);
      (*(code *)PTR_CRYPTO_free_006a7f88)(str);
      if ((int)out < 0) break;
      iVar10 = (int)&out->method + uStack_74 + 1;
    }
  } while( true );
}

