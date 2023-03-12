
/* WARNING: Could not reconcile some variable overlaps */

void do_print_ex_constprop_2(BIO *param_1,uint param_2,_union_257 param_3)

{
  char *__s;
  size_t len;
  size_t sVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  byte bVar6;
  byte bVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  byte *pbVar12;
  int iVar13;
  byte *pbVar14;
  uint uVar15;
  byte *pbVar16;
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
  iVar13 = (param_3.asn1_string)->type;
  local_60[0] = '\0';
  if (local_70 == 0) {
LAB_000b4f24:
    if ((int)(param_2 << 0x18) < 0) {
LAB_000b4f28:
      if ((param_1 == (BIO *)0x0) || (iVar13 = BIO_write(param_1,&DAT_001621b8,1), iVar13 == 1)) {
        if ((int)(param_2 << 0x16) < 0) {
          local_48._0_4_ = (param_3.asn1_string)->type;
          local_48._4_4_ = param_3;
          iVar13 = i2d_ASN1_TYPE((ASN1_TYPE *)&local_48,(uchar **)0x0);
          pbVar3 = (byte *)CRYPTO_malloc(iVar13,"a_strex.c",0x119);
          if (pbVar3 != (byte *)0x0) {
            local_50[0] = pbVar3;
            i2d_ASN1_TYPE((ASN1_TYPE *)&local_48,local_50);
            if (param_1 == (BIO *)0x0) {
LAB_000b5406:
              CRYPTO_free(pbVar3);
              goto joined_r0x000b53f6;
            }
            pbVar16 = pbVar3;
            do {
              if (pbVar16 == pbVar3 + iVar13) goto LAB_000b5406;
              local_57 = "0123456789ABCDEF"[*pbVar16 & 0xf];
              local_58 = "0123456789ABCDEF"[*pbVar16 >> 4];
              iVar4 = BIO_write(param_1,&local_58,2);
              pbVar16 = pbVar16 + 1;
            } while (iVar4 == 2);
            CRYPTO_free(pbVar3);
          }
        }
        else {
          pbVar3 = (param_3.asn1_string)->data;
          iVar13 = (param_3.asn1_string)->length;
          if (param_1 == (BIO *)0x0) {
joined_r0x000b53f6:
            if (-1 < iVar13 * 2) {
              local_70 = iVar13 * 2 + 1 + local_70;
              goto LAB_000b4f4a;
            }
          }
          else {
            pbVar16 = pbVar3;
            do {
              if (pbVar16 == pbVar3 + iVar13) goto joined_r0x000b53f6;
              local_48._2_2_ = (undefined2)((ulong)local_48 >> 0x10);
              local_48._0_4_ =
                   CONCAT31(CONCAT21(local_48._2_2_,"0123456789ABCDEF"[*pbVar16 & 0xf]),
                            "0123456789ABCDEF"[*pbVar16 >> 4]);
              iVar4 = BIO_write(param_1,&local_48,2);
              pbVar16 = pbVar16 + 1;
            } while (iVar4 == 2);
          }
        }
      }
    }
    else {
      if ((int)(param_2 << 0x1a) < 0) {
LAB_000b4f60:
        if ((int)(param_2 << 0x1b) < 0) {
          bVar7 = 1;
LAB_000b5042:
          bVar7 = bVar7 | 8;
        }
        else {
LAB_000b4f66:
          bVar7 = 1;
        }
      }
      else {
        if ((0x1d < iVar13 - 1U) || (bVar7 = tag2nbyte[iVar13], bVar7 == 0xff)) {
          if ((int)(param_2 << 0x17) < 0) goto LAB_000b4f28;
          goto LAB_000b4f60;
        }
        if ((int)(param_2 << 0x1b) < 0) {
          if (bVar7 != 0) goto LAB_000b5042;
          goto LAB_000b4f66;
        }
      }
      iVar13 = (param_3.asn1_string)->length;
      pbVar3 = (param_3.asn1_string)->data;
      pbVar16 = pbVar3 + iVar13;
      if (pbVar3 == pbVar16) {
        iVar4 = 0;
      }
      else {
        iVar4 = 0;
        bVar6 = bVar7 & 8;
        pbVar12 = pbVar3;
        do {
          if (pbVar3 == pbVar12) {
            uVar15 = (param_2 & 1) << 5;
          }
          else {
            uVar15 = 0;
          }
          switch(bVar7 & 7) {
          case 0:
            iVar2 = UTF8_getc(pbVar12,iVar13,(ulong *)&local_48);
            if (iVar2 < 0) goto switchD_000b5240_caseD_3;
            pbVar12 = pbVar12 + iVar2;
            break;
          case 1:
            local_48._0_4_ = (ulong)*pbVar12;
            pbVar12 = pbVar12 + 1;
            break;
          case 2:
            local_48._0_4_ = (ulong)CONCAT11(*pbVar12,pbVar12[1]);
            pbVar12 = pbVar12 + 2;
            break;
          default:
            goto switchD_000b5240_caseD_3;
          case 4:
            local_48._0_4_ =
                 (uint)pbVar12[3] |
                 (uint)*pbVar12 << 0x18 | (uint)pbVar12[1] << 0x10 | (uint)pbVar12[2] << 8;
            pbVar12 = pbVar12 + 4;
          }
          if (pbVar16 == pbVar12) {
            if ((param_2 & 1) != 0) {
              uVar15 = 0x40;
            }
            if (bVar6 != 0) goto LAB_000b507c;
LAB_000b5284:
            iVar2 = do_esc_char_constprop_6((ulong)local_48,uVar15 | uVar8,local_60,bVar6);
            if (iVar2 < 0) goto switchD_000b5240_caseD_3;
            iVar4 = iVar4 + iVar2;
          }
          else {
            if (bVar6 == 0) goto LAB_000b5284;
LAB_000b507c:
            iVar2 = UTF8_putc(local_40,6,(ulong)local_48);
            if (0 < iVar2) {
              uVar15 = uVar15 | uVar8;
              if (uVar8 == 0) {
                if ((int)((uint)local_40[0] << 0x18) < 0) {
                  uVar9 = param_2 & 4;
                }
                else {
                  uVar9 = uVar15 & (byte)(&char_type)[local_40[0]];
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
                iVar4 = iVar4 + iVar10;
                if (iVar2 != 1) {
                  if ((int)((uint)local_40[1] << 0x18) < 0) {
                    uVar9 = param_2 & 4;
                  }
                  else {
                    uVar9 = uVar15 & (byte)(&char_type)[local_40[1]];
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
                  iVar4 = iVar4 + iVar10;
                  if (iVar2 != 2) {
                    if ((int)((uint)local_40[2] << 0x18) < 0) {
                      uVar9 = param_2 & 4;
                    }
                    else {
                      uVar9 = uVar15 & (byte)(&char_type)[local_40[2]];
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
                    iVar4 = iVar4 + iVar10;
                    if (iVar2 != 3) {
                      if ((int)((uint)local_40[3] << 0x18) < 0) {
                        uVar9 = param_2 & 4;
                      }
                      else {
                        uVar9 = uVar15 & (byte)(&char_type)[local_40[3]];
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
                      iVar4 = iVar4 + iVar10;
                      if (iVar2 != 4) {
                        if ((int)((uint)local_3c << 0x18) < 0) {
                          uVar9 = param_2 & 4;
                        }
                        else {
                          uVar9 = uVar15 & (byte)(&char_type)[local_3c];
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
                        iVar4 = iVar4 + iVar10;
                        if (iVar2 != 5) {
                          if ((int)((uint)local_3b << 0x18) < 0) {
                            uVar15 = param_2 & 4;
                          }
                          else {
                            uVar15 = uVar15 & (byte)(&char_type)[local_3b];
                          }
                          if ((uVar15 & 0x61) == 0) {
                            if ((uVar15 & 6) == 0) {
                              iVar2 = 1;
                            }
                            else {
                              BIO_snprintf(acStack_38,0xb,"\\%02X");
                              iVar2 = 3;
                            }
                          }
                          else if ((uVar15 & 8) == 0) {
                            iVar2 = 2;
                          }
                          else {
                            iVar2 = 1;
                            local_60[0] = '\x01';
                          }
                          iVar4 = iVar4 + iVar2;
                        }
                      }
                    }
                  }
                }
              }
              else {
                pbVar14 = (byte *)((int)&local_48 + 7);
                pbVar5 = pbVar14 + iVar2;
                do {
                  while( true ) {
                    pbVar14 = pbVar14 + 1;
                    uVar11 = (uint)*pbVar14;
                    uVar9 = param_2 & 4;
                    if (-1 < (int)(uVar11 << 0x18)) {
                      uVar9 = uVar15 & (byte)(&char_type)[uVar11];
                    }
                    if ((uVar9 & 0x61) == 0) break;
                    if ((int)(uVar9 << 0x1c) < 0) {
                      iVar2 = 1;
                      local_60[0] = '\x01';
                    }
                    else {
                      iVar2 = 2;
                    }
LAB_000b52e0:
                    iVar4 = iVar4 + iVar2;
                    if (pbVar14 == pbVar5) goto LAB_000b51d0;
                  }
                  if ((uVar9 & 6) != 0) {
                    BIO_snprintf(acStack_38,0xb,"\\%02X");
                    iVar2 = 3;
                    goto LAB_000b52e0;
                  }
                  if (uVar11 == 0x5c) {
                    iVar2 = 2;
                  }
                  else {
                    iVar2 = 1;
                  }
                  iVar4 = iVar4 + iVar2;
                } while (pbVar14 != pbVar5);
              }
            }
          }
LAB_000b51d0:
        } while (pbVar16 != pbVar12);
      }
      local_70 = local_70 + iVar4;
      if (local_60[0] == '\0') {
        if (param_1 == (BIO *)0x0) goto LAB_000b4f4a;
      }
      else {
        local_70 = local_70 + 2;
        if (param_1 == (BIO *)0x0) goto LAB_000b4f4a;
        iVar13 = BIO_write(param_1,&DAT_00176720,1);
        if (iVar13 != 1) goto switchD_000b5240_caseD_3;
      }
      iVar13 = (param_3.asn1_string)->length;
      pbVar3 = (param_3.asn1_string)->data;
      pbVar16 = pbVar3 + iVar13;
      if (pbVar3 != pbVar16) {
        bVar6 = bVar7 & 8;
        pbVar12 = pbVar3;
        do {
          if (pbVar3 == pbVar12) {
            uVar15 = (param_2 & 1) << 5;
          }
          else {
            uVar15 = 0;
          }
          switch(bVar7 & 7) {
          case 0:
            iVar4 = UTF8_getc(pbVar12,iVar13,(ulong *)&local_48);
            if (iVar4 < 0) goto switchD_000b5240_caseD_3;
            pbVar12 = pbVar12 + iVar4;
            break;
          case 1:
            local_48._0_4_ = (ulong)*pbVar12;
            pbVar12 = pbVar12 + 1;
            break;
          case 2:
            local_48._0_4_ = (ulong)CONCAT11(*pbVar12,pbVar12[1]);
            pbVar12 = pbVar12 + 2;
            break;
          default:
            goto switchD_000b5240_caseD_3;
          case 4:
            local_48._0_4_ =
                 (uint)pbVar12[3] |
                 (uint)*pbVar12 << 0x18 | (uint)pbVar12[1] << 0x10 | (uint)pbVar12[2] << 8;
            pbVar12 = pbVar12 + 4;
          }
          if (pbVar16 == pbVar12) {
            if ((param_2 & 1) != 0) {
              uVar15 = 0x40;
            }
            if (bVar6 != 0) goto LAB_000b551e;
LAB_000b55b0:
            iVar4 = do_esc_char_constprop_6((ulong)local_48,uVar8 | uVar15,bVar6);
            if (iVar4 < 0) goto switchD_000b5240_caseD_3;
          }
          else {
            if (bVar6 == 0) goto LAB_000b55b0;
LAB_000b551e:
            iVar4 = UTF8_putc(local_40,6,(ulong)local_48);
            if (0 < iVar4) {
              pbVar14 = (byte *)((int)&local_48 + 7);
              pbVar5 = pbVar14 + iVar4;
              do {
                pbVar14 = pbVar14 + 1;
                uVar11 = (uint)*pbVar14;
                local_50[0] = (byte *)((uint)local_50[0] & 0xffffff00 | (uint)*pbVar14);
                uVar9 = param_2 & 4;
                if (-1 < (int)(uVar11 << 0x18)) {
                  uVar9 = (uint)(byte)(&char_type)[uVar11] & (uVar15 | uVar8);
                }
                if ((uVar9 & 0x61) == 0) {
                  if ((uVar9 & 6) == 0) {
                    if ((uVar11 != 0x5c) || (uVar8 == 0)) goto LAB_000b5562;
                    iVar4 = BIO_write(param_1,&DAT_001621b4,2);
                    if (iVar4 != 2) goto switchD_000b5240_caseD_3;
                  }
                  else {
                    BIO_snprintf(acStack_38,0xb,"\\%02X");
                    iVar4 = BIO_write(param_1,acStack_38,3);
                    if (iVar4 != 3) goto switchD_000b5240_caseD_3;
                  }
                }
                else {
                  if ((int)(uVar9 << 0x1c) < 0) {
LAB_000b5562:
                    iVar4 = BIO_write(param_1,local_50,1);
                  }
                  else {
                    iVar4 = BIO_write(param_1,&DAT_001621a8,1);
                    if (iVar4 != 1) goto switchD_000b5240_caseD_3;
                    iVar4 = BIO_write(param_1,local_50,1);
                  }
                  if (iVar4 != 1) goto switchD_000b5240_caseD_3;
                }
              } while (pbVar14 != pbVar5);
            }
          }
        } while (pbVar16 != pbVar12);
      }
      if ((local_60[0] == '\0') || (iVar13 = BIO_write(param_1,&DAT_00176720,1), iVar13 == 1))
      goto LAB_000b4f4a;
    }
  }
  else {
    __s = ASN1_tag2str(iVar13);
    len = strlen(__s);
    if ((param_1 == (BIO *)0x0) ||
       ((sVar1 = BIO_write(param_1,__s,len), len == sVar1 &&
        (iVar4 = BIO_write(param_1,":",1), iVar4 == 1)))) {
      local_70 = len + 1;
      goto LAB_000b4f24;
    }
  }
switchD_000b5240_caseD_3:
  local_70 = -1;
LAB_000b4f4a:
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_70);
  }
  return;
}

