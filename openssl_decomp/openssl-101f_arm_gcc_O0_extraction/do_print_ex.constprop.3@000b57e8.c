
/* WARNING: Could not reconcile some variable overlaps */

void do_print_ex_constprop_3(FILE *param_1,uint param_2,_union_257 param_3)

{
  size_t sVar1;
  size_t sVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte bVar6;
  byte bVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  byte *pbVar13;
  int iVar14;
  byte *pbVar15;
  char *pcVar16;
  uint uVar17;
  byte *pbVar18;
  uint local_70;
  char local_60 [8];
  char local_58;
  char local_57;
  byte *local_50 [2];
  undefined8 local_48;
  byte local_40 [4];
  byte local_3c;
  byte local_3b;
  char acStack_38 [12];
  int local_2c;
  
  uVar8 = param_2 & 0xf;
  local_2c = __TMC_END__;
  local_70 = param_2 & 0x40;
  iVar14 = (param_3.asn1_string)->type;
  local_60[0] = '\0';
  if (local_70 == 0) {
LAB_000b5820:
    if ((int)(param_2 << 0x18) < 0) {
LAB_000b5824:
      if ((param_1 == (FILE *)0x0) || (sVar1 = fwrite(&DAT_001621c0,1,1,param_1), sVar1 == 1)) {
        if ((int)(param_2 << 0x16) < 0) {
          local_48._0_4_ = (param_3.asn1_string)->type;
          local_48._4_4_ = param_3;
          iVar14 = i2d_ASN1_TYPE((ASN1_TYPE *)&local_48,(uchar **)0x0);
          pbVar4 = (byte *)CRYPTO_malloc(iVar14,"a_strex.c",0x119);
          if (pbVar4 != (byte *)0x0) {
            local_50[0] = pbVar4;
            i2d_ASN1_TYPE((ASN1_TYPE *)&local_48,local_50);
            if (param_1 == (FILE *)0x0) {
LAB_000b5d12:
              iVar14 = iVar14 * 2;
              CRYPTO_free(pbVar4);
              goto joined_r0x000b5d02;
            }
            pbVar18 = pbVar4;
            do {
              if (pbVar18 == pbVar4 + iVar14) goto LAB_000b5d12;
              local_57 = "0123456789ABCDEF"[*pbVar18 & 0xf];
              local_58 = "0123456789ABCDEF"[*pbVar18 >> 4];
              sVar1 = fwrite(&local_58,1,2,param_1);
              pbVar18 = pbVar18 + 1;
            } while (sVar1 == 2);
            CRYPTO_free(pbVar4);
          }
        }
        else {
          pbVar4 = (param_3.asn1_string)->data;
          pcVar16 = (param_3.object)->sn;
          if (param_1 == (FILE *)0x0) {
LAB_000b5cfe:
            iVar14 = (int)pcVar16 << 1;
joined_r0x000b5d02:
            if (-1 < iVar14) {
              local_70 = iVar14 + 1 + local_70;
              goto LAB_000b5848;
            }
          }
          else {
            pbVar18 = pbVar4;
            do {
              if (pbVar18 == pbVar4 + (int)pcVar16) goto LAB_000b5cfe;
              local_48._2_2_ = (undefined2)((ulong)local_48 >> 0x10);
              local_48._0_4_ =
                   CONCAT31(CONCAT21(local_48._2_2_,"0123456789ABCDEF"[*pbVar18 & 0xf]),
                            "0123456789ABCDEF"[*pbVar18 >> 4]);
              sVar1 = fwrite(&local_48,1,2,param_1);
              pbVar18 = pbVar18 + 1;
            } while (sVar1 == 2);
          }
        }
      }
    }
    else {
      if ((int)(param_2 << 0x1a) < 0) {
LAB_000b585e:
        if ((int)(param_2 << 0x1b) < 0) {
          bVar7 = 1;
LAB_000b5946:
          bVar7 = bVar7 | 8;
        }
        else {
LAB_000b5864:
          bVar7 = 1;
        }
      }
      else {
        if ((0x1d < iVar14 - 1U) || (bVar7 = tag2nbyte[iVar14], bVar7 == 0xff)) {
          if ((int)(param_2 << 0x17) < 0) goto LAB_000b5824;
          goto LAB_000b585e;
        }
        if ((int)(param_2 << 0x1b) < 0) {
          if (bVar7 != 0) goto LAB_000b5946;
          goto LAB_000b5864;
        }
      }
      iVar14 = (param_3.asn1_string)->length;
      pbVar4 = (param_3.asn1_string)->data;
      pbVar18 = pbVar4 + iVar14;
      if (pbVar4 == pbVar18) {
        iVar12 = 0;
      }
      else {
        iVar12 = 0;
        bVar6 = bVar7 & 8;
        pbVar13 = pbVar4;
        do {
          if (pbVar4 == pbVar13) {
            uVar17 = (param_2 & 1) << 5;
          }
          else {
            uVar17 = 0;
          }
          switch(bVar7 & 7) {
          case 0:
            iVar3 = UTF8_getc(pbVar13,iVar14,(ulong *)&local_48);
            if (iVar3 < 0) goto switchD_000b5b44_caseD_3;
            pbVar13 = pbVar13 + iVar3;
            break;
          case 1:
            local_48._0_4_ = (ulong)*pbVar13;
            pbVar13 = pbVar13 + 1;
            break;
          case 2:
            local_48._0_4_ = (ulong)CONCAT11(*pbVar13,pbVar13[1]);
            pbVar13 = pbVar13 + 2;
            break;
          default:
            goto switchD_000b5b44_caseD_3;
          case 4:
            local_48._0_4_ =
                 (uint)pbVar13[3] |
                 (uint)*pbVar13 << 0x18 | (uint)pbVar13[1] << 0x10 | (uint)pbVar13[2] << 8;
            pbVar13 = pbVar13 + 4;
          }
          if (pbVar18 == pbVar13) {
            if ((param_2 & 1) != 0) {
              uVar17 = 0x40;
            }
            if (bVar6 != 0) goto LAB_000b5980;
LAB_000b5b88:
            iVar3 = do_esc_char_constprop_7((ulong)local_48,uVar17 | uVar8,local_60,bVar6);
            if (iVar3 < 0) goto switchD_000b5b44_caseD_3;
            iVar12 = iVar12 + iVar3;
          }
          else {
            if (bVar6 == 0) goto LAB_000b5b88;
LAB_000b5980:
            iVar3 = UTF8_putc(local_40,6,(ulong)local_48);
            if (0 < iVar3) {
              uVar17 = uVar17 | uVar8;
              if (uVar8 == 0) {
                if ((int)((uint)local_40[0] << 0x18) < 0) {
                  uVar9 = param_2 & 4;
                }
                else {
                  uVar9 = uVar17 & (byte)(&char_type)[local_40[0]];
                }
                if ((uVar9 & 0x61) == 0) {
                  if ((uVar9 & 6) == 0) {
                    iVar10 = 1;
                  }
                  else {
                    BIO_snprintf(acStack_38,0xb,"\\%02X");
                    iVar10 = 3;
                  }
                }
                else if ((int)(uVar9 << 0x1c) < 0) {
                  iVar10 = 1;
                  local_60[0] = '\x01';
                }
                else {
                  iVar10 = 2;
                }
                iVar12 = iVar12 + iVar10;
                if (iVar3 != 1) {
                  if ((int)((uint)local_40[1] << 0x18) < 0) {
                    uVar9 = param_2 & 4;
                  }
                  else {
                    uVar9 = uVar17 & (byte)(&char_type)[local_40[1]];
                  }
                  if ((uVar9 & 0x61) == 0) {
                    if ((uVar9 & 6) == 0) {
                      iVar10 = 1;
                    }
                    else {
                      BIO_snprintf(acStack_38,0xb,"\\%02X");
                      iVar10 = 3;
                    }
                  }
                  else if ((int)(uVar9 << 0x1c) < 0) {
                    iVar10 = 1;
                    local_60[0] = '\x01';
                  }
                  else {
                    iVar10 = 2;
                  }
                  iVar12 = iVar12 + iVar10;
                  if (iVar3 != 2) {
                    if ((int)((uint)local_40[2] << 0x18) < 0) {
                      uVar9 = param_2 & 4;
                    }
                    else {
                      uVar9 = uVar17 & (byte)(&char_type)[local_40[2]];
                    }
                    if ((uVar9 & 0x61) == 0) {
                      if ((uVar9 & 6) == 0) {
                        iVar10 = 1;
                      }
                      else {
                        BIO_snprintf(acStack_38,0xb,"\\%02X");
                        iVar10 = 3;
                      }
                    }
                    else if ((int)(uVar9 << 0x1c) < 0) {
                      iVar10 = 1;
                      local_60[0] = '\x01';
                    }
                    else {
                      iVar10 = 2;
                    }
                    iVar12 = iVar12 + iVar10;
                    if (iVar3 != 3) {
                      if ((int)((uint)local_40[3] << 0x18) < 0) {
                        uVar9 = param_2 & 4;
                      }
                      else {
                        uVar9 = uVar17 & (byte)(&char_type)[local_40[3]];
                      }
                      if ((uVar9 & 0x61) == 0) {
                        if ((uVar9 & 6) == 0) {
                          iVar10 = 1;
                        }
                        else {
                          BIO_snprintf(acStack_38,0xb,"\\%02X");
                          iVar10 = 3;
                        }
                      }
                      else if ((int)(uVar9 << 0x1c) < 0) {
                        iVar10 = 1;
                        local_60[0] = '\x01';
                      }
                      else {
                        iVar10 = 2;
                      }
                      iVar12 = iVar12 + iVar10;
                      if (iVar3 != 4) {
                        if ((int)((uint)local_3c << 0x18) < 0) {
                          uVar9 = param_2 & 4;
                        }
                        else {
                          uVar9 = uVar17 & (byte)(&char_type)[local_3c];
                        }
                        if ((uVar9 & 0x61) == 0) {
                          if ((uVar9 & 6) == 0) {
                            iVar10 = 1;
                          }
                          else {
                            BIO_snprintf(acStack_38,0xb,"\\%02X");
                            iVar10 = 3;
                          }
                        }
                        else if ((int)(uVar9 << 0x1c) < 0) {
                          iVar10 = 1;
                          local_60[0] = '\x01';
                        }
                        else {
                          iVar10 = 2;
                        }
                        iVar12 = iVar12 + iVar10;
                        if (iVar3 != 5) {
                          if ((int)((uint)local_3b << 0x18) < 0) {
                            uVar17 = param_2 & 4;
                          }
                          else {
                            uVar17 = uVar17 & (byte)(&char_type)[local_3b];
                          }
                          if ((uVar17 & 0x61) == 0) {
                            if ((uVar17 & 6) == 0) {
                              iVar3 = 1;
                            }
                            else {
                              BIO_snprintf(acStack_38,0xb,"\\%02X");
                              iVar3 = 3;
                            }
                          }
                          else if ((uVar17 & 8) == 0) {
                            iVar3 = 2;
                          }
                          else {
                            iVar3 = 1;
                            local_60[0] = '\x01';
                          }
                          iVar12 = iVar12 + iVar3;
                        }
                      }
                    }
                  }
                }
              }
              else {
                pbVar15 = (byte *)((int)&local_48 + 7);
                pbVar5 = pbVar15 + iVar3;
                do {
                  while( true ) {
                    pbVar15 = pbVar15 + 1;
                    uVar11 = (uint)*pbVar15;
                    uVar9 = param_2 & 4;
                    if (-1 < (int)(uVar11 << 0x18)) {
                      uVar9 = uVar17 & (byte)(&char_type)[uVar11];
                    }
                    if ((uVar9 & 0x61) == 0) break;
                    if ((int)(uVar9 << 0x1c) < 0) {
                      iVar3 = 1;
                      local_60[0] = '\x01';
                    }
                    else {
                      iVar3 = 2;
                    }
LAB_000b5be4:
                    iVar12 = iVar12 + iVar3;
                    if (pbVar15 == pbVar5) goto LAB_000b5ad4;
                  }
                  if ((uVar9 & 6) != 0) {
                    BIO_snprintf(acStack_38,0xb,"\\%02X");
                    iVar3 = 3;
                    goto LAB_000b5be4;
                  }
                  if (uVar11 == 0x5c) {
                    iVar3 = 2;
                  }
                  else {
                    iVar3 = 1;
                  }
                  iVar12 = iVar12 + iVar3;
                } while (pbVar15 != pbVar5);
              }
            }
          }
LAB_000b5ad4:
        } while (pbVar18 != pbVar13);
      }
      local_70 = local_70 + iVar12;
      if (local_60[0] == '\0') {
        if (param_1 == (FILE *)0x0) goto LAB_000b5848;
      }
      else {
        local_70 = local_70 + 2;
        if (param_1 == (FILE *)0x0) goto LAB_000b5848;
        sVar1 = fwrite(&DAT_00176744,1,1,param_1);
        if (sVar1 != 1) goto switchD_000b5b44_caseD_3;
      }
      iVar14 = (param_3.asn1_string)->length;
      pbVar4 = (param_3.asn1_string)->data;
      pbVar18 = pbVar4 + iVar14;
      if (pbVar4 != pbVar18) {
        bVar6 = bVar7 & 8;
        pbVar13 = pbVar4;
        do {
          if (pbVar4 == pbVar13) {
            uVar17 = (param_2 & 1) << 5;
          }
          else {
            uVar17 = 0;
          }
          switch(bVar7 & 7) {
          case 0:
            iVar12 = UTF8_getc(pbVar13,iVar14,(ulong *)&local_48);
            if (iVar12 < 0) goto switchD_000b5b44_caseD_3;
            pbVar13 = pbVar13 + iVar12;
            break;
          case 1:
            local_48._0_4_ = (ulong)*pbVar13;
            pbVar13 = pbVar13 + 1;
            break;
          case 2:
            local_48._0_4_ = (ulong)CONCAT11(*pbVar13,pbVar13[1]);
            pbVar13 = pbVar13 + 2;
            break;
          default:
            goto switchD_000b5b44_caseD_3;
          case 4:
            local_48._0_4_ =
                 (uint)pbVar13[3] |
                 (uint)*pbVar13 << 0x18 | (uint)pbVar13[1] << 0x10 | (uint)pbVar13[2] << 8;
            pbVar13 = pbVar13 + 4;
          }
          if (pbVar18 == pbVar13) {
            if ((param_2 & 1) != 0) {
              uVar17 = 0x40;
            }
            if (bVar6 != 0) goto LAB_000b5e2a;
LAB_000b5ebe:
            iVar12 = do_esc_char_constprop_7((ulong)local_48,uVar8 | uVar17,bVar6);
            if (iVar12 < 0) goto switchD_000b5b44_caseD_3;
          }
          else {
            if (bVar6 == 0) goto LAB_000b5ebe;
LAB_000b5e2a:
            iVar12 = UTF8_putc(local_40,6,(ulong)local_48);
            if (0 < iVar12) {
              pbVar15 = (byte *)((int)&local_48 + 7);
              pbVar5 = pbVar15 + iVar12;
              do {
                pbVar15 = pbVar15 + 1;
                uVar11 = (uint)*pbVar15;
                local_50[0] = (byte *)((uint)local_50[0] & 0xffffff00 | (uint)*pbVar15);
                uVar9 = param_2 & 4;
                if (-1 < (int)(uVar11 << 0x18)) {
                  uVar9 = (uint)(byte)(&char_type)[uVar11] & (uVar17 | uVar8);
                }
                if ((uVar9 & 0x61) == 0) {
                  if ((uVar9 & 6) == 0) {
                    if ((uVar11 != 0x5c) || (uVar8 == 0)) goto LAB_000b5e6e;
                    sVar1 = fwrite(&DAT_001621bc,1,2,param_1);
                    if (sVar1 != 2) goto switchD_000b5b44_caseD_3;
                  }
                  else {
                    BIO_snprintf(acStack_38,0xb,"\\%02X");
                    sVar1 = fwrite(acStack_38,1,3,param_1);
                    if (sVar1 != 3) goto switchD_000b5b44_caseD_3;
                  }
                }
                else {
                  if ((int)(uVar9 << 0x1c) < 0) {
LAB_000b5e6e:
                    sVar1 = 1;
                  }
                  else {
                    sVar1 = fwrite(&DAT_001621b0,1,1,param_1);
                    if (sVar1 != 1) goto switchD_000b5b44_caseD_3;
                  }
                  sVar1 = fwrite(local_50,sVar1,sVar1,param_1);
                  if (sVar1 != 1) goto switchD_000b5b44_caseD_3;
                }
              } while (pbVar15 != pbVar5);
            }
          }
        } while (pbVar18 != pbVar13);
      }
      if ((local_60[0] == '\0') || (sVar1 = fwrite(&DAT_00176744,1,1,param_1), sVar1 == 1))
      goto LAB_000b5848;
    }
  }
  else {
    pcVar16 = ASN1_tag2str(iVar14);
    sVar1 = strlen(pcVar16);
    if ((param_1 == (FILE *)0x0) ||
       ((sVar2 = fwrite(pcVar16,1,sVar1,param_1), sVar1 == sVar2 &&
        (sVar2 = fwrite(":",1,1,param_1), sVar2 == 1)))) {
      local_70 = sVar1 + 1;
      goto LAB_000b5820;
    }
  }
switchD_000b5b44_caseD_3:
  local_70 = -1;
LAB_000b5848:
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_70);
  }
  return;
}

