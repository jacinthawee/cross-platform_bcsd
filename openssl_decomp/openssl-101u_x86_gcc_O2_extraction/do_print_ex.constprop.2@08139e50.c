
int __regparm3 do_print_ex_constprop_2(BIO *param_1,uint param_2,_union_257 param_3)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  char *__s;
  size_t len;
  size_t sVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  byte *pbVar8;
  byte bVar9;
  byte bVar10;
  int iVar11;
  byte bVar12;
  byte *pbVar13;
  byte *pbVar14;
  byte *pbVar15;
  byte *pbVar16;
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
  
  iVar3 = (param_3.asn1_string)->type;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  bVar2 = false;
  local_5c = 0;
  bVar1 = (byte)param_2;
  if ((param_2 & 0x40) == 0) {
LAB_08139e8f:
    if ((param_2 & 0x80) == 0) {
      if ((param_2 & 0x20) == 0) {
        if (0x1d < iVar3 - 1U) {
LAB_0813a030:
          if ((param_2 & 0x100) != 0) goto LAB_08139e9b;
          goto LAB_0813a040;
        }
        local_64 = (uint)(char)tag2nbyte[iVar3];
        if (local_64 == 0xffffffff) goto LAB_0813a030;
        if ((param_2 & 0x10) != 0) {
          if (local_64 == 0) {
            local_64 = 1;
          }
          else {
            local_64 = (uint)(char)(tag2nbyte[iVar3] | 8);
          }
        }
      }
      else {
LAB_0813a040:
        local_64 = (-(uint)((param_2 & 0x10) == 0) & 0xfffffff8) + 9;
      }
      iVar3 = (param_3.asn1_string)->length;
      pbVar8 = (param_3.asn1_string)->data;
      pbVar15 = pbVar8 + iVar3;
      if (pbVar8 == pbVar15) {
        local_60 = 0;
      }
      else {
        uVar5 = local_64 & 7;
        local_60 = 0;
        pbVar14 = pbVar8;
        do {
          while( true ) {
            bVar12 = 0;
            if (pbVar8 == pbVar14) {
              bVar12 = -(bVar1 & 1) & 0x20;
            }
            if (uVar5 == 1) {
              local_3c.type = (int)*pbVar14;
              pbVar14 = pbVar14 + 1;
            }
            else if (uVar5 < 2) {
              if ((uVar5 != 0) || (iVar6 = UTF8_getc(pbVar14,iVar3,(ulong *)&local_3c), iVar6 < 0))
              goto LAB_08139f48;
              pbVar14 = pbVar14 + iVar6;
            }
            else if (uVar5 == 2) {
              local_3c.type = (int)CONCAT11(*pbVar14,pbVar14[1]);
              pbVar14 = pbVar14 + 2;
            }
            else {
              if (uVar5 != 4) goto LAB_08139f48;
              local_3c.type =
                   (uint)pbVar14[2] << 8 | (uint)pbVar14[1] << 0x10 | (uint)*pbVar14 << 0x18 |
                   (uint)pbVar14[3];
              pbVar14 = pbVar14 + 4;
            }
            if ((pbVar15 == pbVar14) && ((param_2 & 1) != 0)) {
              bVar12 = 0x40;
            }
            if ((local_64 & 8) == 0) break;
            iVar6 = UTF8_putc(local_31,6,local_3c.type);
            if (0 < iVar6) {
              bVar12 = bVar12 | bVar1 & 0xf;
              uVar7 = (uint)local_31[0];
              if ((param_2 & 0xf) == 0) {
                if ((char)local_31[0] < '\0') {
                  bVar9 = bVar1 & 4;
LAB_0813a162:
                  iVar11 = 1;
                  if ((bVar9 & 6) != 0) {
                    BIO_snprintf(&local_2b,0xb,"\\%02X",uVar7);
                    iVar11 = 3;
                  }
                }
                else {
                  bVar9 = bVar12 & char_type[uVar7];
                  if ((bVar9 & 0x61) == 0) goto LAB_0813a162;
                  if ((bVar9 & 8) == 0) {
                    iVar11 = 2;
                  }
                  else {
                    bVar2 = true;
                    iVar11 = 1;
                  }
                }
                local_60 = local_60 + iVar11;
                if (iVar6 != 1) {
                  if ((char)local_31[1] < '\0') {
                    bVar9 = bVar1 & 4;
LAB_0813a7e5:
                    iVar11 = 1;
                    if ((bVar9 & 6) != 0) {
                      BIO_snprintf(&local_2b,0xb,"\\%02X",(uint)local_31[1]);
                      iVar11 = 3;
                    }
                  }
                  else {
                    bVar9 = bVar12 & char_type[local_31[1]];
                    if ((bVar9 & 0x61) == 0) goto LAB_0813a7e5;
                    if ((bVar9 & 8) == 0) {
                      iVar11 = 2;
                    }
                    else {
                      bVar2 = true;
                      iVar11 = 1;
                    }
                  }
                  local_60 = local_60 + iVar11;
                  if (iVar6 != 2) {
                    if ((char)local_31[2] < '\0') {
                      bVar9 = bVar1 & 4;
LAB_0813a7ad:
                      iVar11 = 1;
                      if ((bVar9 & 6) != 0) {
                        BIO_snprintf(&local_2b,0xb,"\\%02X",(uint)local_31[2]);
                        iVar11 = 3;
                      }
                    }
                    else {
                      bVar9 = bVar12 & char_type[local_31[2]];
                      if ((bVar9 & 0x61) == 0) goto LAB_0813a7ad;
                      if ((bVar9 & 8) == 0) {
                        iVar11 = 2;
                      }
                      else {
                        bVar2 = true;
                        iVar11 = 1;
                      }
                    }
                    local_60 = local_60 + iVar11;
                    if (iVar6 != 3) {
                      if ((char)local_31[3] < '\0') {
                        bVar9 = bVar1 & 4;
LAB_0813a775:
                        iVar11 = 1;
                        if ((bVar9 & 6) != 0) {
                          BIO_snprintf(&local_2b,0xb,"\\%02X",(uint)local_31[3]);
                          iVar11 = 3;
                        }
                      }
                      else {
                        bVar9 = bVar12 & char_type[local_31[3]];
                        if ((bVar9 & 0x61) == 0) goto LAB_0813a775;
                        if ((bVar9 & 8) == 0) {
                          iVar11 = 2;
                        }
                        else {
                          bVar2 = true;
                          iVar11 = 1;
                        }
                      }
                      local_60 = local_60 + iVar11;
                      if (iVar6 != 4) {
                        if ((char)local_2d < '\0') {
                          bVar9 = bVar1 & 4;
LAB_0813a73d:
                          iVar11 = 1;
                          if ((bVar9 & 6) != 0) {
                            BIO_snprintf(&local_2b,0xb,"\\%02X",(uint)local_2d);
                            iVar11 = 3;
                          }
                        }
                        else {
                          bVar9 = bVar12 & char_type[local_2d];
                          if ((bVar9 & 0x61) == 0) goto LAB_0813a73d;
                          if ((bVar9 & 8) == 0) {
                            iVar11 = 2;
                          }
                          else {
                            bVar2 = true;
                            iVar11 = 1;
                          }
                        }
                        local_60 = local_60 + iVar11;
                        if (iVar6 != 5) {
                          if ((char)local_2c < '\0') {
                            bVar12 = bVar1 & 4;
LAB_0813a703:
                            if ((bVar12 & 6) != 0) {
                              BIO_snprintf(&local_2b,0xb,"\\%02X",(uint)local_2c);
                              local_60 = local_60 + 3;
                              goto LAB_0813a2a3;
                            }
                          }
                          else {
                            bVar12 = bVar12 & char_type[local_2c];
                            if ((bVar12 & 0x61) == 0) goto LAB_0813a703;
                            if ((bVar12 & 8) == 0) {
                              local_60 = local_60 + 2;
                              goto LAB_0813a2a3;
                            }
                            bVar2 = true;
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
                  bVar9 = bVar1 & 4;
LAB_0813a6dd:
                  if ((bVar9 & 6) == 0) {
                    iVar11 = (local_31[0] == 0x5c) + 1;
                  }
                  else {
                    BIO_snprintf(&local_2b,0xb,"\\%02X",uVar7);
                    iVar11 = 3;
                  }
                }
                else {
                  bVar9 = bVar12 & char_type[local_31[0]];
                  if ((bVar9 & 0x61) == 0) goto LAB_0813a6dd;
                  if ((bVar9 & 8) == 0) {
                    iVar11 = 2;
                  }
                  else {
                    bVar2 = true;
                    iVar11 = 1;
                  }
                }
                local_60 = local_60 + iVar11;
                if (iVar6 == 1) goto LAB_0813a2a3;
                if ((char)local_31[1] < '\0') {
                  bVar9 = bVar1 & 4;
LAB_0813aa61:
                  if ((bVar9 & 6) == 0) {
                    iVar11 = (local_31[1] == 0x5c) + 1;
                  }
                  else {
                    BIO_snprintf(&local_2b,0xb,"\\%02X",(uint)local_31[1]);
                    iVar11 = 3;
                  }
                }
                else {
                  bVar9 = bVar12 & char_type[local_31[1]];
                  if ((bVar9 & 0x61) == 0) goto LAB_0813aa61;
                  if ((bVar9 & 8) == 0) {
                    iVar11 = 2;
                  }
                  else {
                    bVar2 = true;
                    iVar11 = 1;
                  }
                }
                local_60 = local_60 + iVar11;
                if (iVar6 == 2) goto LAB_0813a2a3;
                if ((char)local_31[2] < '\0') {
                  bVar9 = bVar1 & 4;
LAB_0813aa25:
                  if ((bVar9 & 6) == 0) {
                    iVar11 = (local_31[2] == 0x5c) + 1;
                  }
                  else {
                    BIO_snprintf(&local_2b,0xb,"\\%02X",(uint)local_31[2]);
                    iVar11 = 3;
                  }
                }
                else {
                  bVar9 = bVar12 & char_type[local_31[2]];
                  if ((bVar9 & 0x61) == 0) goto LAB_0813aa25;
                  if ((bVar9 & 8) == 0) {
                    iVar11 = 2;
                  }
                  else {
                    bVar2 = true;
                    iVar11 = 1;
                  }
                }
                local_60 = local_60 + iVar11;
                if (iVar6 == 3) goto LAB_0813a2a3;
                if ((char)local_31[3] < '\0') {
                  bVar9 = bVar1 & 4;
LAB_0813aa43:
                  if ((bVar9 & 6) == 0) {
                    iVar11 = (local_31[3] == 0x5c) + 1;
                  }
                  else {
                    BIO_snprintf(&local_2b,0xb,"\\%02X",(uint)local_31[3]);
                    iVar11 = 3;
                  }
                }
                else {
                  bVar9 = bVar12 & char_type[local_31[3]];
                  if ((bVar9 & 0x61) == 0) goto LAB_0813aa43;
                  if ((bVar9 & 8) == 0) {
                    iVar11 = 2;
                  }
                  else {
                    bVar2 = true;
                    iVar11 = 1;
                  }
                }
                local_60 = local_60 + iVar11;
                if (iVar6 == 4) goto LAB_0813a2a3;
                if ((char)local_2d < '\0') {
                  bVar9 = bVar1 & 4;
LAB_0813aa07:
                  if ((bVar9 & 6) == 0) {
                    iVar11 = (local_2d == 0x5c) + 1;
                  }
                  else {
                    BIO_snprintf(&local_2b,0xb,"\\%02X",(uint)local_2d);
                    iVar11 = 3;
                  }
                }
                else {
                  bVar9 = bVar12 & char_type[local_2d];
                  if ((bVar9 & 0x61) == 0) goto LAB_0813aa07;
                  if ((bVar9 & 8) == 0) {
                    iVar11 = 2;
                  }
                  else {
                    bVar2 = true;
                    iVar11 = 1;
                  }
                }
                local_60 = local_60 + iVar11;
                if (iVar6 != 5) {
                  if ((char)local_2c < '\0') {
                    bVar12 = bVar1 & 4;
                  }
                  else {
                    bVar12 = bVar12 & char_type[local_2c];
                    if ((bVar12 & 0x61) != 0) {
                      if ((bVar12 & 8) == 0) {
                        local_60 = local_60 + 2;
                      }
                      else {
                        bVar2 = true;
                        local_60 = local_60 + 1;
                      }
                      goto LAB_0813a49a;
                    }
                  }
                  if ((bVar12 & 6) == 0) {
                    local_60 = local_60 + (local_2c == 0x5c) + 1;
                  }
                  else {
                    BIO_snprintf(&local_2b,0xb,"\\%02X",(uint)local_2c);
                    local_60 = local_60 + 3;
                  }
                  goto LAB_0813a49a;
                }
              }
            }
LAB_0813a2a3:
            if (pbVar15 == pbVar14) goto LAB_0813a2b1;
          }
          iVar6 = do_esc_char_constprop_6(0);
          if (iVar6 < 0) goto LAB_08139f48;
          local_60 = local_60 + iVar6;
LAB_0813a49a:
        } while (pbVar15 != pbVar14);
      }
LAB_0813a2b1:
      local_60 = local_60 + local_5c;
      if (bVar2) {
        local_60 = local_60 + 2;
        if (param_1 == (BIO *)0x0) goto LAB_08139f4d;
        iVar3 = BIO_write(param_1,&DAT_0823baa9,1);
        if (iVar3 != 1) goto LAB_08139f48;
      }
      else if (param_1 == (BIO *)0x0) goto LAB_08139f4d;
      iVar3 = (param_3.asn1_string)->length;
      pbVar8 = (param_3.asn1_string)->data;
      pbVar15 = pbVar8 + iVar3;
      if (pbVar8 != pbVar15) {
        uVar5 = local_64 & 7;
        pbVar14 = pbVar8;
        do {
          bVar12 = 0;
          if (pbVar14 == pbVar8) {
            bVar12 = -(bVar1 & 1) & 0x20;
          }
          if (uVar5 == 1) {
            local_3c.type = (int)*pbVar14;
            pbVar14 = pbVar14 + 1;
          }
          else if (uVar5 < 2) {
            if ((uVar5 != 0) || (iVar6 = UTF8_getc(pbVar14,iVar3,(ulong *)&local_3c), iVar6 < 0))
            goto LAB_08139f48;
            pbVar14 = pbVar14 + iVar6;
          }
          else if (uVar5 == 2) {
            local_3c.type = (int)CONCAT11(*pbVar14,pbVar14[1]);
            pbVar14 = pbVar14 + 2;
          }
          else {
            if (uVar5 != 4) goto LAB_08139f48;
            local_3c.type =
                 (uint)pbVar14[2] << 8 | (uint)pbVar14[1] << 0x10 | (uint)*pbVar14 << 0x18 |
                 (uint)pbVar14[3];
            pbVar14 = pbVar14 + 4;
          }
          if ((pbVar15 == pbVar14) && ((param_2 & 1) != 0)) {
            bVar12 = 0x40;
          }
          if ((local_64 & 8) == 0) {
            iVar6 = do_esc_char_constprop_6(param_1);
            if (iVar6 < 0) goto LAB_08139f48;
          }
          else {
            iVar6 = UTF8_putc(local_31,6,local_3c.type);
            if (0 < iVar6) {
              pbVar13 = local_31;
              pbVar16 = pbVar13 + iVar6;
              do {
                while( true ) {
                  bVar9 = *pbVar13;
                  bVar10 = bVar1 & 4;
                  local_40 = (byte *)((uint)local_40 & 0xffffff00 | (uint)bVar9);
                  if (((char)bVar9 < '\0') ||
                     (bVar10 = (bVar12 | bVar1 & 0xf) & char_type[bVar9], (bVar10 & 0x61) == 0))
                  break;
                  if (((bVar10 & 8) == 0) &&
                     (iVar6 = BIO_write(param_1,&DAT_08226f16,1), iVar6 != 1)) goto LAB_08139f48;
LAB_0813a42b:
                  iVar6 = BIO_write(param_1,&local_40,1);
                  if (iVar6 != 1) goto LAB_08139f48;
                  pbVar13 = pbVar13 + 1;
                  if (pbVar16 == pbVar13) goto LAB_0813a454;
                }
                if ((bVar10 & 6) == 0) {
                  if ((bVar9 != 0x5c) || ((param_2 & 0xf) == 0)) goto LAB_0813a42b;
                  iVar6 = BIO_write(param_1,&DAT_08226f15,2);
                  if (iVar6 != 2) goto LAB_08139f48;
                }
                else {
                  BIO_snprintf(&local_2b,0xb,"\\%02X",(uint)bVar9);
                  iVar6 = BIO_write(param_1,&local_2b,3);
                  if (iVar6 != 3) goto LAB_08139f48;
                }
                pbVar13 = pbVar13 + 1;
              } while (pbVar16 != pbVar13);
            }
          }
LAB_0813a454:
        } while (pbVar15 != pbVar14);
      }
      if ((!bVar2) || (iVar3 = BIO_write(param_1,&DAT_0823baa9,1), iVar3 == 1)) goto LAB_08139f4d;
    }
    else {
LAB_08139e9b:
      if (param_1 == (BIO *)0x0) {
        if ((param_2 & 0x200) == 0) {
          local_74 = (param_3.asn1_string)->length;
        }
        else {
          local_3c.type = (param_3.asn1_string)->type;
          local_3c.value = param_3;
          local_74 = i2d_ASN1_TYPE(&local_3c,(uchar **)0x0);
          pbVar8 = (byte *)CRYPTO_malloc(local_74,"a_strex.c",0x13d);
          if (pbVar8 == (byte *)0x0) goto LAB_08139f48;
          local_40 = pbVar8;
          i2d_ASN1_TYPE(&local_3c,&local_40);
LAB_0813ab13:
          CRYPTO_free(pbVar8);
        }
      }
      else {
        iVar3 = BIO_write(param_1,&DAT_08226f18,1);
        local_60 = -1;
        if (iVar3 != 1) goto LAB_08139f4d;
        if ((param_2 & 0x200) != 0) {
          local_3c.type = (param_3.asn1_string)->type;
          local_3c.value = param_3;
          local_74 = i2d_ASN1_TYPE(&local_3c,(uchar **)0x0);
          pbVar8 = (byte *)CRYPTO_malloc(local_74,"a_strex.c",0x13d);
          if (pbVar8 != (byte *)0x0) {
            local_40 = pbVar8;
            i2d_ASN1_TYPE(&local_3c,&local_40);
            for (pbVar15 = pbVar8; pbVar8 + local_74 != pbVar15; pbVar15 = pbVar15 + 1) {
              local_2a = "0123456789ABCDEF"[*pbVar15 & 0xf];
              local_2b = "0123456789ABCDEF"[*pbVar15 >> 4];
              iVar3 = BIO_write(param_1,&local_2b,2);
              if (iVar3 != 2) {
                CRYPTO_free(pbVar8);
                goto LAB_08139f48;
              }
            }
            goto LAB_0813ab13;
          }
          goto LAB_08139f48;
        }
        pbVar15 = (param_3.asn1_string)->data;
        local_74 = (param_3.asn1_string)->length;
        pbVar8 = pbVar15 + local_74;
        for (; pbVar15 != pbVar8; pbVar15 = pbVar15 + 1) {
          local_2a = "0123456789ABCDEF"[*pbVar15 & 0xf];
          local_2b = "0123456789ABCDEF"[*pbVar15 >> 4];
          iVar3 = BIO_write(param_1,&local_2b,2);
          if (iVar3 != 2) goto LAB_08139f48;
        }
      }
      if (-1 < local_74 * 2) {
        local_60 = local_74 * 2 + 1 + local_5c;
        goto LAB_08139f4d;
      }
    }
  }
  else {
    __s = ASN1_tag2str(iVar3);
    len = strlen(__s);
    if ((param_1 == (BIO *)0x0) ||
       ((sVar4 = BIO_write(param_1,__s,len), len == sVar4 &&
        (iVar6 = BIO_write(param_1,":",1), iVar6 == 1)))) {
      local_5c = len + 1;
      goto LAB_08139e8f;
    }
  }
LAB_08139f48:
  local_60 = -1;
LAB_08139f4d:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return local_60;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

