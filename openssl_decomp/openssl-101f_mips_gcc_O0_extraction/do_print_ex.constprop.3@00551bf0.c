
int do_print_ex_constprop_3(ASN1_TYPE *param_1,uint param_2,_union_257 param_3)

{
  byte bVar1;
  undefined *puVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  ushort *puVar11;
  ushort *puVar12;
  byte *pbVar13;
  ushort *puVar14;
  byte *pbVar15;
  uint uVar16;
  _union_257 _Var17;
  uint uVar18;
  int local_78;
  uint local_74;
  char local_4d;
  _union_257 local_4c;
  ASN1_TYPE local_48;
  byte local_40 [4];
  byte local_3c;
  byte local_3b;
  char local_38;
  char local_37;
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  uVar16 = param_2 & 0xf;
  local_4d = '\0';
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar9 = (param_3.asn1_string)->type;
  if ((param_2 & 0x40) == 0) {
    local_74 = 0;
  }
  else {
    pcVar4 = ASN1_tag2str(iVar9);
    iVar6 = (*(code *)PTR_strlen_006aab30)(pcVar4);
    if ((param_1 != (ASN1_TYPE *)0x0) &&
       ((iVar3 = (*(code *)PTR_fwrite_006aab7c)(pcVar4,1,iVar6,param_1), iVar6 != iVar3 ||
        (iVar3 = (*(code *)PTR_fwrite_006aab7c)(":",1,1,param_1), iVar3 != 1)))) goto LAB_00551ca8;
    local_74 = iVar6 + 1;
  }
  if ((param_2 & 0x80) != 0) {
LAB_00551c7c:
    if (param_1 == (ASN1_TYPE *)0x0) {
      param_1 = &local_48;
      if ((param_2 & 0x200) != 0) {
        local_48.type = (param_3.asn1_string)->type;
        local_48.value = param_3;
        iVar9 = i2d_ASN1_TYPE(param_1,(uchar **)0x0);
        param_3.ptr = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar9,"a_strex.c",0x119);
        if ((byte *)param_3.ptr != (byte *)0x0) {
          local_4c.ptr = param_3.ptr;
          i2d_ASN1_TYPE(param_1,(uchar **)&local_4c.ptr);
          goto LAB_00552a74;
        }
        goto LAB_00551ca8;
      }
      iVar9 = (param_3.asn1_string)->length;
    }
    else {
      iVar9 = (*(code *)PTR_fwrite_006aab7c)(&DAT_0066a058,1,1,param_1);
      if (iVar9 != 1) goto LAB_00551ca8;
      if ((param_2 & 0x200) != 0) goto LAB_00552bc4;
      pbVar13 = (param_3.asn1_string)->data;
      iVar9 = (param_3.asn1_string)->length;
      param_3.ptr = (char *)(pbVar13 + iVar9);
      if ((byte *)param_3.ptr != pbVar13) {
        do {
          local_38 = "0123456789ABCDEF"[*pbVar13 >> 4];
          local_37 = "0123456789ABCDEF"[*pbVar13 & 0xf];
          iVar6 = (*(code *)PTR_fwrite_006aab7c)(&local_38,1,2,param_1);
          if (iVar6 != 2) goto LAB_00551ca8;
          pbVar13 = pbVar13 + 1;
        } while ((byte *)param_3.ptr != pbVar13);
      }
    }
    if (-1 < iVar9 * 2) {
      iVar9 = local_74 + iVar9 * 2 + 1;
      goto LAB_00551cb0;
    }
    goto LAB_00551ca8;
  }
  if ((param_2 & 0x20) == 0) {
    if ((0x1d < iVar9 - 1U) || (uVar10 = (uint)(char)tag2nbyte[iVar9], uVar10 == 0xffffffff)) {
      if ((param_2 & 0x100) != 0) goto LAB_00551c7c;
      goto LAB_00551dc4;
    }
    if ((param_2 & 0x10) != 0) {
      if (uVar10 == 0) {
        uVar10 = 1;
      }
      else {
        uVar10 = uVar10 | 8;
      }
    }
  }
  else {
LAB_00551dc4:
    uVar10 = 1;
    if ((param_2 & 0x10) != 0) {
      uVar10 = 9;
    }
  }
  pcVar4 = (param_3.object)->sn;
  puVar11 = (ushort *)(param_3.asn1_string)->data;
  puVar14 = (ushort *)((int)puVar11 + (int)pcVar4);
  if (puVar11 == puVar14) {
    local_78 = 0;
  }
  else {
    uVar18 = uVar10 & 7;
    local_78 = 0;
    puVar12 = puVar11;
    do {
      if (puVar11 == puVar12) {
        uVar7 = 0x20;
        if ((param_2 & 1) == 0) {
          uVar7 = 0;
        }
      }
      else {
        uVar7 = 0;
      }
      if (uVar18 == 1) {
        local_48.type = (int)*(byte *)puVar12;
        puVar12 = (ushort *)((int)puVar12 + 1);
      }
      else if (uVar18 < 2) {
        if ((uVar18 != 0) ||
           (iVar9 = (*(code *)PTR_UTF8_getc_006a9df0)(puVar12,pcVar4,&local_48), iVar9 < 0))
        goto LAB_00551ca8;
        puVar12 = (ushort *)((int)puVar12 + iVar9);
      }
      else if (uVar18 == 2) {
        local_48.type = (int)*puVar12;
        puVar12 = puVar12 + 1;
      }
      else {
        iVar9 = -1;
        if (uVar18 != 4) goto LAB_00551cb0;
        local_48.type =
             (uint)*(byte *)((int)puVar12 + 3) |
             (uint)*(byte *)(puVar12 + 1) << 8 |
             (uint)*(byte *)((int)puVar12 + 1) << 0x10 | (uint)*(byte *)puVar12 << 0x18;
        puVar12 = puVar12 + 2;
      }
      if ((puVar14 == puVar12) && ((param_2 & 1) != 0)) {
        uVar7 = 0x40;
      }
      if ((uVar10 & 8) == 0) {
        iVar9 = do_esc_char_constprop_7(local_48.type,uVar16 | uVar7,&local_4d,0);
        if (iVar9 < 0) goto LAB_00551ca8;
        local_78 = local_78 + iVar9;
      }
      else {
        iVar9 = (*(code *)PTR_UTF8_putc_006a9dec)(local_40,6,local_48.type);
        if (0 < iVar9) {
          uVar7 = uVar16 | uVar7;
          uVar8 = (uint)local_40[0];
          if (uVar16 == 0) {
            uVar5 = param_2 & 4;
            if (((char)local_40[0] < '\0') ||
               (uVar5 = uVar7 & (byte)char_type[uVar8], (uVar5 & 0x61) == 0)) {
              if ((uVar5 & 6) == 0) {
                iVar6 = 1;
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a8060)(&local_38,0xb,"\\%02X");
                iVar6 = 3;
              }
            }
            else if ((uVar5 & 8) == 0) {
              iVar6 = 2;
            }
            else {
              iVar6 = 1;
              local_4d = '\x01';
            }
            local_78 = local_78 + iVar6;
            if (iVar9 == 1) goto LAB_00552088;
            if ((char)local_40[1] < '\0') {
              uVar8 = param_2 & 4;
LAB_00552754:
              if ((uVar8 & 6) == 0) {
                iVar6 = 1;
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a8060)(&local_38,0xb,"\\%02X");
                iVar6 = 3;
              }
            }
            else {
              uVar8 = uVar7 & (byte)char_type[local_40[1]];
              if ((uVar8 & 0x61) == 0) goto LAB_00552754;
              if ((uVar8 & 8) == 0) {
                iVar6 = 2;
              }
              else {
                local_4d = '\x01';
                iVar6 = 1;
              }
            }
            local_78 = local_78 + iVar6;
            if (iVar9 == 2) goto LAB_00552088;
            if ((char)local_40[2] < '\0') {
              uVar8 = param_2 & 4;
LAB_00552738:
              if ((uVar8 & 6) == 0) {
                iVar6 = 1;
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a8060)(&local_38,0xb,"\\%02X");
                iVar6 = 3;
              }
            }
            else {
              uVar8 = uVar7 & (byte)char_type[local_40[2]];
              if ((uVar8 & 0x61) == 0) goto LAB_00552738;
              if ((uVar8 & 8) == 0) {
                iVar6 = 2;
              }
              else {
                iVar6 = 1;
                local_4d = '\x01';
              }
            }
            local_78 = local_78 + iVar6;
            if (iVar9 == 3) goto LAB_00552088;
            if ((char)local_40[3] < '\0') {
              uVar8 = param_2 & 4;
LAB_00552770:
              if ((uVar8 & 6) == 0) {
                iVar6 = 1;
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a8060)(&local_38,0xb,"\\%02X");
                iVar6 = 3;
              }
            }
            else {
              uVar8 = uVar7 & (byte)char_type[local_40[3]];
              if ((uVar8 & 0x61) == 0) goto LAB_00552770;
              if ((uVar8 & 8) == 0) {
                iVar6 = 2;
              }
              else {
                iVar6 = 1;
                local_4d = '\x01';
              }
            }
            local_78 = local_78 + iVar6;
            if (iVar9 == 4) goto LAB_00552088;
            if ((char)local_3c < '\0') {
              uVar8 = param_2 & 4;
LAB_0055271c:
              if ((uVar8 & 6) == 0) {
                iVar6 = 1;
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a8060)(&local_38,0xb,"\\%02X");
                iVar6 = 3;
              }
            }
            else {
              uVar8 = uVar7 & (byte)char_type[local_3c];
              if ((uVar8 & 0x61) == 0) goto LAB_0055271c;
              if ((uVar8 & 8) == 0) {
                iVar6 = 2;
              }
              else {
                iVar6 = 1;
                local_4d = '\x01';
              }
            }
            local_78 = local_78 + iVar6;
            if (iVar9 == 5) goto LAB_00552088;
            if ((char)local_3b < '\0') {
              uVar7 = param_2 & 4;
LAB_00552700:
              if ((uVar7 & 6) == 0) {
                local_78 = local_78 + 1;
                goto LAB_00552088;
              }
LAB_00552794:
              (*(code *)PTR_BIO_snprintf_006a8060)(&local_38,0xb,"\\%02X");
              local_78 = local_78 + 3;
            }
            else {
              uVar7 = uVar7 & (byte)char_type[local_3b];
              if ((uVar7 & 0x61) == 0) goto LAB_00552700;
LAB_00552070:
              if ((uVar7 & 8) == 0) {
                local_78 = local_78 + 2;
              }
              else {
                local_78 = local_78 + 1;
                local_4d = '\x01';
              }
            }
          }
          else {
            if ((char)local_40[0] < '\0') {
              uVar5 = param_2 & 4;
LAB_005526dc:
              if ((uVar5 & 6) == 0) {
                iVar6 = 1;
                if (uVar8 == 0x5c) {
                  iVar6 = 2;
                }
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a8060)(&local_38,0xb,"\\%02X");
                iVar6 = 3;
              }
            }
            else {
              uVar5 = uVar7 & (byte)char_type[uVar8];
              if ((uVar5 & 0x61) == 0) goto LAB_005526dc;
              if ((uVar5 & 8) == 0) {
                iVar6 = 2;
              }
              else {
                iVar6 = 1;
                local_4d = '\x01';
              }
            }
            local_78 = local_78 + iVar6;
            if (iVar9 == 1) goto LAB_00552088;
            if ((char)local_40[1] < '\0') {
              uVar8 = param_2 & 4;
LAB_005528e0:
              if ((uVar8 & 6) == 0) {
                iVar6 = 2;
                if (local_40[1] != 0x5c) {
                  iVar6 = 1;
                }
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a8060)(&local_38,0xb,"\\%02X");
                iVar6 = 3;
              }
            }
            else {
              uVar8 = uVar7 & (byte)char_type[local_40[1]];
              if ((uVar8 & 0x61) == 0) goto LAB_005528e0;
              if ((uVar8 & 8) == 0) {
                iVar6 = 2;
              }
              else {
                local_4d = '\x01';
                iVar6 = 1;
              }
            }
            local_78 = local_78 + iVar6;
            if (iVar9 == 2) goto LAB_00552088;
            if ((char)local_40[2] < '\0') {
              uVar8 = param_2 & 4;
LAB_005528bc:
              if ((uVar8 & 6) == 0) {
                iVar6 = 2;
                if (local_40[2] != 0x5c) {
                  iVar6 = 1;
                }
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a8060)(&local_38,0xb,"\\%02X");
                iVar6 = 3;
              }
            }
            else {
              uVar8 = uVar7 & (byte)char_type[local_40[2]];
              if ((uVar8 & 0x61) == 0) goto LAB_005528bc;
              if ((uVar8 & 8) == 0) {
                iVar6 = 2;
              }
              else {
                iVar6 = 1;
                local_4d = '\x01';
              }
            }
            local_78 = local_78 + iVar6;
            if (iVar9 == 3) goto LAB_00552088;
            if ((char)local_40[3] < '\0') {
              uVar8 = param_2 & 4;
LAB_00552898:
              if ((uVar8 & 6) == 0) {
                iVar6 = 2;
                if (local_40[3] != 0x5c) {
                  iVar6 = 1;
                }
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a8060)(&local_38,0xb,"\\%02X");
                iVar6 = 3;
              }
            }
            else {
              uVar8 = uVar7 & (byte)char_type[local_40[3]];
              if ((uVar8 & 0x61) == 0) goto LAB_00552898;
              if ((uVar8 & 8) == 0) {
                iVar6 = 2;
              }
              else {
                iVar6 = 1;
                local_4d = '\x01';
              }
            }
            local_78 = local_78 + iVar6;
            if (iVar9 == 4) goto LAB_00552088;
            if ((char)local_3c < '\0') {
              uVar8 = param_2 & 4;
LAB_00552874:
              if ((uVar8 & 6) == 0) {
                iVar6 = 2;
                if (local_3c != 0x5c) {
                  iVar6 = 1;
                }
              }
              else {
                (*(code *)PTR_BIO_snprintf_006a8060)(&local_38,0xb,"\\%02X");
                iVar6 = 3;
              }
            }
            else {
              uVar8 = uVar7 & (byte)char_type[local_3c];
              if ((uVar8 & 0x61) == 0) goto LAB_00552874;
              if ((uVar8 & 8) == 0) {
                iVar6 = 2;
              }
              else {
                iVar6 = 1;
                local_4d = '\x01';
              }
            }
            local_78 = local_78 + iVar6;
            if (iVar9 != 5) {
              if ((char)local_3b < '\0') {
                uVar7 = param_2 & 4;
              }
              else {
                uVar7 = uVar7 & (byte)char_type[local_3b];
                if ((uVar7 & 0x61) != 0) goto LAB_00552070;
              }
              iVar9 = 1;
              if ((uVar7 & 6) != 0) goto LAB_00552794;
              if (local_3b == 0x5c) {
                iVar9 = 2;
              }
              local_78 = local_78 + iVar9;
            }
          }
        }
      }
LAB_00552088:
    } while (puVar14 != puVar12);
  }
  local_78 = local_74 + local_78;
  if (local_4d == '\0') {
    iVar9 = local_78;
    if (param_1 == (ASN1_TYPE *)0x0) goto LAB_00551cb0;
  }
  else {
    local_78 = local_78 + 2;
    iVar9 = local_78;
    if (param_1 == (ASN1_TYPE *)0x0) goto LAB_00551cb0;
    iVar9 = (*(code *)PTR_fwrite_006aab7c)(&DAT_0067a4c0,1,1,param_1);
    if (iVar9 != 1) goto LAB_00551ca8;
  }
  pcVar4 = (param_3.object)->sn;
  puVar14 = (ushort *)(param_3.asn1_string)->data;
  puVar11 = (ushort *)((int)puVar14 + (int)pcVar4);
  if (puVar14 != puVar11) {
    param_3.boolean = uVar10 & 7;
    local_74 = uVar10 & 8;
    puVar12 = puVar14;
    do {
      while( true ) {
        if (puVar14 == puVar12) {
          uVar10 = 0x20;
          if ((param_2 & 1) == 0) {
            uVar10 = 0;
          }
        }
        else {
          uVar10 = 0;
        }
        if ((byte *)param_3.ptr == (byte *)0x1) {
          local_48.type = (int)*(byte *)puVar12;
          puVar12 = (ushort *)((int)puVar12 + 1);
        }
        else if ((uint)param_3 < (byte *)0x2) {
          if (((byte *)param_3.ptr != (byte *)0x0) ||
             (iVar9 = (*(code *)PTR_UTF8_getc_006a9df0)(puVar12,pcVar4,&local_48), iVar9 < 0))
          goto LAB_00551ca8;
          puVar12 = (ushort *)((int)puVar12 + iVar9);
        }
        else if (param_3.ptr == &SUB_00000002) {
          local_48.type = (int)*puVar12;
          puVar12 = puVar12 + 1;
        }
        else {
          iVar9 = -1;
          if (param_3.ptr != &SUB_00000004) goto LAB_00551cb0;
          local_48.type =
               (uint)*(byte *)((int)puVar12 + 3) |
               (uint)*(byte *)(puVar12 + 1) << 8 |
               (uint)*(byte *)((int)puVar12 + 1) << 0x10 | (uint)*(byte *)puVar12 << 0x18;
          puVar12 = puVar12 + 2;
        }
        if ((puVar11 == puVar12) && ((param_2 & 1) != 0)) {
          uVar10 = 0x40;
        }
        if (local_74 != 0) break;
        iVar9 = do_esc_char_constprop_7(local_48.type,uVar16 | uVar10,0,param_1);
        if (iVar9 < 0) goto LAB_00551ca8;
        if (puVar11 == puVar12) goto LAB_00552274;
      }
      pbVar13 = local_40;
      iVar9 = (*(code *)PTR_UTF8_putc_006a9dec)(pbVar13,6,local_48.type);
      if (0 < iVar9) {
        pbVar15 = pbVar13 + iVar9;
        do {
          while( true ) {
            bVar1 = *pbVar13;
            local_4c.boolean = local_4c.boolean & 0xffffffU | (uint)bVar1 << 0x18;
            if ((char)bVar1 < '\0') break;
            uVar18 = (uVar16 | uVar10) & (uint)(byte)char_type[bVar1];
            if ((uVar18 & 0x61) == 0) goto LAB_005522b4;
            if ((uVar18 & 8) == 0) {
              iVar9 = (*(code *)PTR_fwrite_006aab7c)(&DAT_0066a048,1,1,param_1);
              if (iVar9 != 1) goto LAB_00551ca8;
              iVar9 = (*(code *)PTR_fwrite_006aab7c)(&local_4c,1,1,param_1);
            }
            else {
LAB_0055223c:
              iVar9 = (*(code *)PTR_fwrite_006aab7c)(&local_4c,1,1,param_1);
            }
            if (iVar9 != 1) goto LAB_00551ca8;
joined_r0x00552474:
            pbVar13 = pbVar13 + 1;
            if (pbVar15 == pbVar13) goto LAB_00552268;
          }
          uVar18 = param_2 & 4;
LAB_005522b4:
          if ((uVar18 & 6) == 0) {
            if ((bVar1 != 0x5c) || (uVar16 == 0)) goto LAB_0055223c;
            iVar9 = (*(code *)PTR_fwrite_006aab7c)(&DAT_0066a054,1,2,param_1);
            if (iVar9 == 2) goto joined_r0x00552474;
            goto LAB_00551ca8;
          }
          (*(code *)PTR_BIO_snprintf_006a8060)(&local_38,0xb,"\\%02X");
          iVar9 = (*(code *)PTR_fwrite_006aab7c)(&local_38,1,3,param_1);
          if (iVar9 != 3) goto LAB_00551ca8;
          pbVar13 = pbVar13 + 1;
        } while (pbVar15 != pbVar13);
      }
LAB_00552268:
    } while (puVar11 != puVar12);
  }
LAB_00552274:
  iVar9 = local_78;
  if (local_4d == '\0') goto LAB_00551cb0;
  iVar6 = (*(code *)PTR_fwrite_006aab7c)(&DAT_0067a4c0,1,1,param_1);
  if (iVar6 == 1) goto LAB_00551cb0;
LAB_00551ca8:
  do {
    iVar9 = -1;
LAB_00551cb0:
    while( true ) {
      if (local_2c == *(int *)puVar2) {
        return iVar9;
      }
      (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_00552bc4:
      local_48.type = (param_3.asn1_string)->type;
      local_48.value = param_3;
      iVar9 = i2d_ASN1_TYPE(&local_48,(uchar **)0x0);
      param_3.ptr = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar9,"a_strex.c",0x119);
      if ((byte *)param_3.ptr == (byte *)0x0) break;
      local_4c.ptr = param_3.ptr;
      i2d_ASN1_TYPE(&local_48,(uchar **)&local_4c.ptr);
      if (param_3.ptr + iVar9 != param_3.ptr) {
        _Var17.ptr = param_3.ptr;
        do {
          local_38 = "0123456789ABCDEF"[(byte)*_Var17.ptr >> 4];
          local_37 = "0123456789ABCDEF"[(byte)*_Var17.ptr & 0xf];
          iVar6 = (*(code *)PTR_fwrite_006aab7c)(&local_38,1,2,param_1);
          if (iVar6 != 2) {
            (*(code *)PTR_CRYPTO_free_006a7f88)(param_3.ptr);
            goto LAB_00551ca8;
          }
          _Var17.ptr = (char *)((int)&(_Var17.asn1_string)->length + 1);
        } while (param_3.ptr + iVar9 != _Var17.ptr);
      }
LAB_00552a74:
      param_1 = (ASN1_TYPE *)(iVar9 * 2);
      (*(code *)PTR_CRYPTO_free_006a7f88)(param_3.ptr);
      if ((int)param_1 < 0) break;
      iVar9 = (int)&param_1->type + local_74 + 1;
    }
  } while( true );
}

