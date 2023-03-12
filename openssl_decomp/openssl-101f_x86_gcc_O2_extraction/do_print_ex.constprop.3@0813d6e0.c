
int __regparm3 do_print_ex_constprop_3(FILE *param_1,uint param_2,_union_257 param_3)

{
  int iVar1;
  byte bVar2;
  bool bVar3;
  size_t sVar4;
  char *__s;
  size_t sVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  byte *pbVar9;
  byte bVar10;
  byte bVar11;
  int iVar12;
  byte bVar13;
  byte *pbVar14;
  byte *pbVar15;
  byte *pbVar16;
  byte *pbVar17;
  int in_GS_OFFSET;
  int local_74;
  uint local_64;
  int local_60;
  int local_5c;
  byte *local_40;
  ASN1_TYPE local_3c;
  byte local_31 [4];
  byte local_2d;
  byte local_2c;
  char local_2b;
  char local_2a;
  int local_20;
  
  iVar1 = (param_3.asn1_string)->type;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  bVar3 = false;
  local_5c = 0;
  bVar2 = (byte)param_2;
  if ((param_2 & 0x40) == 0) {
LAB_0813d71f:
    if ((param_2 & 0x80) == 0) {
      if ((param_2 & 0x20) == 0) {
        if (0x1d < iVar1 - 1U) {
LAB_0813d8c0:
          if ((param_2 & 0x100) != 0) goto LAB_0813d72b;
          goto LAB_0813d8d0;
        }
        local_64 = (uint)(char)tag2nbyte[iVar1];
        if (local_64 == 0xffffffff) goto LAB_0813d8c0;
        if ((param_2 & 0x10) != 0) {
          if (local_64 == 0) {
            local_64 = 1;
          }
          else {
            local_64 = (uint)(char)(tag2nbyte[iVar1] | 8);
          }
        }
      }
      else {
LAB_0813d8d0:
        local_64 = (-(uint)((param_2 & 0x10) == 0) & 0xfffffff8) + 9;
      }
      iVar1 = (param_3.asn1_string)->length;
      pbVar9 = (param_3.asn1_string)->data;
      pbVar16 = pbVar9 + iVar1;
      if (pbVar9 == pbVar16) {
        local_60 = 0;
      }
      else {
        uVar6 = local_64 & 7;
        local_60 = 0;
        pbVar15 = pbVar9;
        do {
          while( true ) {
            bVar13 = 0;
            if (pbVar9 == pbVar15) {
              bVar13 = -(bVar2 & 1) & 0x20;
            }
            if (uVar6 == 1) {
              local_3c.type = (int)*pbVar15;
              pbVar15 = pbVar15 + 1;
            }
            else if (uVar6 < 2) {
              if ((uVar6 != 0) || (iVar7 = UTF8_getc(pbVar15,iVar1,(ulong *)&local_3c), iVar7 < 0))
              goto LAB_0813d7d8;
              pbVar15 = pbVar15 + iVar7;
            }
            else if (uVar6 == 2) {
              local_3c.type = (int)CONCAT11(*pbVar15,pbVar15[1]);
              pbVar15 = pbVar15 + 2;
            }
            else {
              if (uVar6 != 4) goto LAB_0813d7d8;
              local_3c.type =
                   (uint)pbVar15[2] << 8 | (uint)pbVar15[1] << 0x10 | (uint)*pbVar15 << 0x18 |
                   (uint)pbVar15[3];
              pbVar15 = pbVar15 + 4;
            }
            if ((pbVar16 == pbVar15) && ((param_2 & 1) != 0)) {
              bVar13 = 0x40;
            }
            if ((local_64 & 8) == 0) break;
            iVar7 = UTF8_putc(local_31,6,local_3c.type);
            if (0 < iVar7) {
              bVar13 = bVar13 | bVar2 & 0xf;
              uVar8 = (uint)local_31[0];
              if ((param_2 & 0xf) == 0) {
                if ((char)local_31[0] < '\0') {
                  bVar10 = bVar2 & 4;
LAB_0813d9f2:
                  iVar12 = 1;
                  if ((bVar10 & 6) != 0) {
                    BIO_snprintf(&local_2b,0xb,"\\%02X",uVar8);
                    iVar12 = 3;
                  }
                }
                else {
                  bVar10 = bVar13 & char_type[uVar8];
                  if ((bVar10 & 0x61) == 0) goto LAB_0813d9f2;
                  if ((bVar10 & 8) == 0) {
                    iVar12 = 2;
                  }
                  else {
                    bVar3 = true;
                    iVar12 = 1;
                  }
                }
                local_60 = local_60 + iVar12;
                if (iVar7 != 1) {
                  if ((char)local_31[1] < '\0') {
                    bVar10 = bVar2 & 4;
LAB_0813e075:
                    iVar12 = 1;
                    if ((bVar10 & 6) != 0) {
                      BIO_snprintf(&local_2b,0xb,"\\%02X",(uint)local_31[1]);
                      iVar12 = 3;
                    }
                  }
                  else {
                    bVar10 = bVar13 & char_type[local_31[1]];
                    if ((bVar10 & 0x61) == 0) goto LAB_0813e075;
                    if ((bVar10 & 8) == 0) {
                      iVar12 = 2;
                    }
                    else {
                      bVar3 = true;
                      iVar12 = 1;
                    }
                  }
                  local_60 = local_60 + iVar12;
                  if (iVar7 != 2) {
                    if ((char)local_31[2] < '\0') {
                      bVar10 = bVar2 & 4;
LAB_0813e03d:
                      iVar12 = 1;
                      if ((bVar10 & 6) != 0) {
                        BIO_snprintf(&local_2b,0xb,"\\%02X",(uint)local_31[2]);
                        iVar12 = 3;
                      }
                    }
                    else {
                      bVar10 = bVar13 & char_type[local_31[2]];
                      if ((bVar10 & 0x61) == 0) goto LAB_0813e03d;
                      if ((bVar10 & 8) == 0) {
                        iVar12 = 2;
                      }
                      else {
                        bVar3 = true;
                        iVar12 = 1;
                      }
                    }
                    local_60 = local_60 + iVar12;
                    if (iVar7 != 3) {
                      if ((char)local_31[3] < '\0') {
                        bVar10 = bVar2 & 4;
LAB_0813e005:
                        iVar12 = 1;
                        if ((bVar10 & 6) != 0) {
                          BIO_snprintf(&local_2b,0xb,"\\%02X",(uint)local_31[3]);
                          iVar12 = 3;
                        }
                      }
                      else {
                        bVar10 = bVar13 & char_type[local_31[3]];
                        if ((bVar10 & 0x61) == 0) goto LAB_0813e005;
                        if ((bVar10 & 8) == 0) {
                          iVar12 = 2;
                        }
                        else {
                          bVar3 = true;
                          iVar12 = 1;
                        }
                      }
                      local_60 = local_60 + iVar12;
                      if (iVar7 != 4) {
                        if ((char)local_2d < '\0') {
                          bVar10 = bVar2 & 4;
LAB_0813dfcd:
                          iVar12 = 1;
                          if ((bVar10 & 6) != 0) {
                            BIO_snprintf(&local_2b,0xb,"\\%02X",(uint)local_2d);
                            iVar12 = 3;
                          }
                        }
                        else {
                          bVar10 = bVar13 & char_type[local_2d];
                          if ((bVar10 & 0x61) == 0) goto LAB_0813dfcd;
                          if ((bVar10 & 8) == 0) {
                            iVar12 = 2;
                          }
                          else {
                            bVar3 = true;
                            iVar12 = 1;
                          }
                        }
                        local_60 = local_60 + iVar12;
                        if (iVar7 != 5) {
                          if ((char)local_2c < '\0') {
                            bVar13 = bVar2 & 4;
LAB_0813df93:
                            if ((bVar13 & 6) != 0) {
                              BIO_snprintf(&local_2b,0xb,"\\%02X",(uint)local_2c);
                              local_60 = local_60 + 3;
                              goto LAB_0813db33;
                            }
                          }
                          else {
                            bVar13 = bVar13 & char_type[local_2c];
                            if ((bVar13 & 0x61) == 0) goto LAB_0813df93;
                            if ((bVar13 & 8) == 0) {
                              local_60 = local_60 + 2;
                              goto LAB_0813db33;
                            }
                            bVar3 = true;
                          }
                          local_60 = local_60 + 1;
                        }
                      }
                    }
                  }
                }
              }
              else {
                if ((char)local_31[0] < '\0') {
                  bVar10 = bVar2 & 4;
LAB_0813df6d:
                  if ((bVar10 & 6) == 0) {
                    iVar12 = (local_31[0] == 0x5c) + 1;
                  }
                  else {
                    BIO_snprintf(&local_2b,0xb,"\\%02X",uVar8);
                    iVar12 = 3;
                  }
                }
                else {
                  bVar10 = bVar13 & char_type[local_31[0]];
                  if ((bVar10 & 0x61) == 0) goto LAB_0813df6d;
                  if ((bVar10 & 8) == 0) {
                    iVar12 = 2;
                  }
                  else {
                    bVar3 = true;
                    iVar12 = 1;
                  }
                }
                local_60 = local_60 + iVar12;
                if (iVar7 == 1) goto LAB_0813db33;
                if ((char)local_31[1] < '\0') {
                  bVar10 = bVar2 & 4;
LAB_0813e2f0:
                  if ((bVar10 & 6) == 0) {
                    iVar12 = (local_31[1] == 0x5c) + 1;
                  }
                  else {
                    BIO_snprintf(&local_2b,0xb,"\\%02X",(uint)local_31[1]);
                    iVar12 = 3;
                  }
                }
                else {
                  bVar10 = bVar13 & char_type[local_31[1]];
                  if ((bVar10 & 0x61) == 0) goto LAB_0813e2f0;
                  if ((bVar10 & 8) == 0) {
                    iVar12 = 2;
                  }
                  else {
                    bVar3 = true;
                    iVar12 = 1;
                  }
                }
                local_60 = local_60 + iVar12;
                if (iVar7 == 2) goto LAB_0813db33;
                if ((char)local_31[2] < '\0') {
                  bVar10 = bVar2 & 4;
LAB_0813e2b4:
                  if ((bVar10 & 6) == 0) {
                    iVar12 = (local_31[2] == 0x5c) + 1;
                  }
                  else {
                    BIO_snprintf(&local_2b,0xb,"\\%02X",(uint)local_31[2]);
                    iVar12 = 3;
                  }
                }
                else {
                  bVar10 = bVar13 & char_type[local_31[2]];
                  if ((bVar10 & 0x61) == 0) goto LAB_0813e2b4;
                  if ((bVar10 & 8) == 0) {
                    iVar12 = 2;
                  }
                  else {
                    bVar3 = true;
                    iVar12 = 1;
                  }
                }
                local_60 = local_60 + iVar12;
                if (iVar7 == 3) goto LAB_0813db33;
                if ((char)local_31[3] < '\0') {
                  bVar10 = bVar2 & 4;
LAB_0813e2d2:
                  if ((bVar10 & 6) == 0) {
                    iVar12 = (local_31[3] == 0x5c) + 1;
                  }
                  else {
                    BIO_snprintf(&local_2b,0xb,"\\%02X",(uint)local_31[3]);
                    iVar12 = 3;
                  }
                }
                else {
                  bVar10 = bVar13 & char_type[local_31[3]];
                  if ((bVar10 & 0x61) == 0) goto LAB_0813e2d2;
                  if ((bVar10 & 8) == 0) {
                    iVar12 = 2;
                  }
                  else {
                    bVar3 = true;
                    iVar12 = 1;
                  }
                }
                local_60 = local_60 + iVar12;
                if (iVar7 == 4) goto LAB_0813db33;
                if ((char)local_2d < '\0') {
                  bVar10 = bVar2 & 4;
LAB_0813e296:
                  if ((bVar10 & 6) == 0) {
                    iVar12 = (local_2d == 0x5c) + 1;
                  }
                  else {
                    BIO_snprintf(&local_2b,0xb,"\\%02X",(uint)local_2d);
                    iVar12 = 3;
                  }
                }
                else {
                  bVar10 = bVar13 & char_type[local_2d];
                  if ((bVar10 & 0x61) == 0) goto LAB_0813e296;
                  if ((bVar10 & 8) == 0) {
                    iVar12 = 2;
                  }
                  else {
                    bVar3 = true;
                    iVar12 = 1;
                  }
                }
                local_60 = local_60 + iVar12;
                if (iVar7 != 5) {
                  if ((char)local_2c < '\0') {
                    bVar13 = bVar2 & 4;
                  }
                  else {
                    bVar13 = bVar13 & char_type[local_2c];
                    if ((bVar13 & 0x61) != 0) {
                      if ((bVar13 & 8) == 0) {
                        local_60 = local_60 + 2;
                      }
                      else {
                        bVar3 = true;
                        local_60 = local_60 + 1;
                      }
                      goto LAB_0813dd2a;
                    }
                  }
                  if ((bVar13 & 6) == 0) {
                    local_60 = local_60 + (local_2c == 0x5c) + 1;
                  }
                  else {
                    BIO_snprintf(&local_2b,0xb,"\\%02X",(uint)local_2c);
                    local_60 = local_60 + 3;
                  }
                  goto LAB_0813dd2a;
                }
              }
            }
LAB_0813db33:
            if (pbVar16 == pbVar15) goto LAB_0813db41;
          }
          iVar7 = do_esc_char_constprop_7(0);
          if (iVar7 < 0) goto LAB_0813d7d8;
          local_60 = local_60 + iVar7;
LAB_0813dd2a:
        } while (pbVar16 != pbVar15);
      }
LAB_0813db41:
      local_60 = local_60 + local_5c;
      if (bVar3) {
        local_60 = local_60 + 2;
        if (param_1 == (FILE *)0x0) goto LAB_0813d7dd;
        sVar4 = fwrite(&DAT_0823b5a9,1,1,param_1);
        if (sVar4 != 1) goto LAB_0813d7d8;
      }
      else if (param_1 == (FILE *)0x0) goto LAB_0813d7dd;
      iVar1 = (param_3.asn1_string)->length;
      pbVar9 = (param_3.asn1_string)->data;
      pbVar16 = pbVar9 + iVar1;
      if (pbVar9 != pbVar16) {
        uVar6 = local_64 & 7;
        pbVar15 = pbVar9;
        do {
          bVar13 = 0;
          if (pbVar9 == pbVar15) {
            bVar13 = -(bVar2 & 1) & 0x20;
          }
          if (uVar6 == 1) {
            local_3c.type = (int)*pbVar15;
            pbVar15 = pbVar15 + 1;
          }
          else if (uVar6 < 2) {
            if ((uVar6 != 0) || (iVar7 = UTF8_getc(pbVar15,iVar1,(ulong *)&local_3c), iVar7 < 0))
            goto LAB_0813d7d8;
            pbVar15 = pbVar15 + iVar7;
          }
          else if (uVar6 == 2) {
            local_3c.type = (int)CONCAT11(*pbVar15,pbVar15[1]);
            pbVar15 = pbVar15 + 2;
          }
          else {
            if (uVar6 != 4) goto LAB_0813d7d8;
            local_3c.type =
                 (uint)pbVar15[2] << 8 | (uint)pbVar15[1] << 0x10 | (uint)*pbVar15 << 0x18 |
                 (uint)pbVar15[3];
            pbVar15 = pbVar15 + 4;
          }
          if ((pbVar16 == pbVar15) && ((param_2 & 1) != 0)) {
            bVar13 = 0x40;
          }
          if ((local_64 & 8) == 0) {
            iVar7 = do_esc_char_constprop_7(param_1);
            if (iVar7 < 0) goto LAB_0813d7d8;
          }
          else {
            iVar7 = UTF8_putc(local_31,6,local_3c.type);
            if (0 < iVar7) {
              pbVar14 = local_31;
              pbVar17 = pbVar14 + iVar7;
              do {
                while( true ) {
                  bVar10 = *pbVar14;
                  bVar11 = bVar2 & 4;
                  local_40 = (byte *)((uint)local_40 & 0xffffff00 | (uint)bVar10);
                  if (((char)bVar10 < '\0') ||
                     (bVar11 = (bVar13 | bVar2 & 0xf) & char_type[bVar10], (bVar11 & 0x61) == 0))
                  break;
                  if (((bVar11 & 8) == 0) && (sVar4 = fwrite(&DAT_08226cb6,1,1,param_1), sVar4 != 1)
                     ) goto LAB_0813d7d8;
LAB_0813dcbb:
                  sVar4 = fwrite(&local_40,1,1,param_1);
                  if (sVar4 != 1) goto LAB_0813d7d8;
                  pbVar14 = pbVar14 + 1;
                  if (pbVar17 == pbVar14) goto LAB_0813dce4;
                }
                if ((bVar11 & 6) == 0) {
                  if ((bVar10 != 0x5c) || ((param_2 & 0xf) == 0)) goto LAB_0813dcbb;
                  sVar4 = fwrite(&DAT_08226cb5,1,2,param_1);
                  if (sVar4 != 2) goto LAB_0813d7d8;
                }
                else {
                  BIO_snprintf(&local_2b,0xb,"\\%02X",(uint)bVar10);
                  sVar4 = fwrite(&local_2b,1,3,param_1);
                  if (sVar4 != 3) goto LAB_0813d7d8;
                }
                pbVar14 = pbVar14 + 1;
              } while (pbVar17 != pbVar14);
            }
          }
LAB_0813dce4:
        } while (pbVar16 != pbVar15);
      }
      if ((!bVar3) || (sVar4 = fwrite(&DAT_0823b5a9,1,1,param_1), sVar4 == 1)) goto LAB_0813d7dd;
    }
    else {
LAB_0813d72b:
      if (param_1 == (FILE *)0x0) {
        if ((param_2 & 0x200) == 0) {
          local_74 = (param_3.asn1_string)->length;
        }
        else {
          local_3c.type = (param_3.asn1_string)->type;
          local_3c.value = param_3;
          local_74 = i2d_ASN1_TYPE(&local_3c,(uchar **)0x0);
          pbVar9 = (byte *)CRYPTO_malloc(local_74,"a_strex.c",0x119);
          if (pbVar9 == (byte *)0x0) goto LAB_0813d7d8;
          local_40 = pbVar9;
          i2d_ASN1_TYPE(&local_3c,&local_40);
LAB_0813e3a2:
          CRYPTO_free(pbVar9);
        }
      }
      else {
        sVar4 = fwrite(&DAT_08226cb8,1,1,param_1);
        local_60 = -1;
        if (sVar4 != 1) goto LAB_0813d7dd;
        if ((param_2 & 0x200) != 0) {
          local_3c.type = (param_3.asn1_string)->type;
          local_3c.value = param_3;
          local_74 = i2d_ASN1_TYPE(&local_3c,(uchar **)0x0);
          pbVar9 = (byte *)CRYPTO_malloc(local_74,"a_strex.c",0x119);
          if (pbVar9 != (byte *)0x0) {
            local_40 = pbVar9;
            i2d_ASN1_TYPE(&local_3c,&local_40);
            for (pbVar16 = pbVar9; pbVar9 + local_74 != pbVar16; pbVar16 = pbVar16 + 1) {
              local_2a = "0123456789ABCDEF"[*pbVar16 & 0xf];
              local_2b = "0123456789ABCDEF"[*pbVar16 >> 4];
              sVar4 = fwrite(&local_2b,1,2,param_1);
              if (sVar4 != 2) {
                CRYPTO_free(pbVar9);
                goto LAB_0813d7d8;
              }
            }
            goto LAB_0813e3a2;
          }
          goto LAB_0813d7d8;
        }
        pbVar16 = (param_3.asn1_string)->data;
        local_74 = (param_3.asn1_string)->length;
        pbVar9 = pbVar16 + local_74;
        for (; pbVar9 != pbVar16; pbVar16 = pbVar16 + 1) {
          local_2a = "0123456789ABCDEF"[*pbVar16 & 0xf];
          local_2b = "0123456789ABCDEF"[*pbVar16 >> 4];
          sVar4 = fwrite(&local_2b,1,2,param_1);
          if (sVar4 != 2) goto LAB_0813d7d8;
        }
      }
      if (-1 < local_74 * 2) {
        local_60 = local_74 * 2 + 1 + local_5c;
        goto LAB_0813d7dd;
      }
    }
  }
  else {
    __s = ASN1_tag2str(iVar1);
    sVar4 = strlen(__s);
    if ((param_1 == (FILE *)0x0) ||
       ((sVar5 = fwrite(__s,1,sVar4,param_1), sVar4 == sVar5 &&
        (sVar5 = fwrite(":",1,1,param_1), sVar5 == 1)))) {
      local_5c = sVar4 + 1;
      goto LAB_0813d71f;
    }
  }
LAB_0813d7d8:
  local_60 = -1;
LAB_0813d7dd:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return local_60;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

