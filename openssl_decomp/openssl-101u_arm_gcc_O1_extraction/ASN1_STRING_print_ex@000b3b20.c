
/* WARNING: Could not reconcile some variable overlaps */

int ASN1_STRING_print_ex(BIO *out,ASN1_STRING *str,ulong flags)

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
  uint uStack_70;
  char acStack_60 [8];
  char cStack_58;
  char cStack_57;
  byte *apbStack_50 [2];
  undefined8 uStack_48;
  byte abStack_40 [4];
  byte bStack_3c;
  byte bStack_3b;
  char acStack_38 [12];
  int iStack_2c;
  
  uVar8 = flags & 0xf;
  iStack_2c = __stack_chk_guard;
  uStack_70 = flags & 0x40;
  iVar13 = str->type;
  acStack_60[0] = '\0';
  if (uStack_70 == 0) {
LAB_000b23c8:
    if ((int)(flags << 0x18) < 0) {
LAB_000b23cc:
      if ((out == (BIO *)0x0) || (iVar13 = BIO_write(out,&DAT_00160d9c,1), iVar13 == 1)) {
        if ((int)(flags << 0x16) < 0) {
          uStack_48._0_4_ = str->type;
          uStack_48._4_4_ = str;
          iVar13 = i2d_ASN1_TYPE((ASN1_TYPE *)&uStack_48,(uchar **)0x0);
          pbVar3 = (byte *)CRYPTO_malloc(iVar13,"a_strex.c",0x13d);
          if (pbVar3 != (byte *)0x0) {
            apbStack_50[0] = pbVar3;
            i2d_ASN1_TYPE((ASN1_TYPE *)&uStack_48,apbStack_50);
            if (out == (BIO *)0x0) {
LAB_000b28aa:
              CRYPTO_free(pbVar3);
              goto joined_r0x000b289a;
            }
            pbVar16 = pbVar3;
            do {
              if (pbVar16 == pbVar3 + iVar13) goto LAB_000b28aa;
              cStack_57 = "0123456789ABCDEF"[*pbVar16 & 0xf];
              cStack_58 = "0123456789ABCDEF"[*pbVar16 >> 4];
              iVar4 = BIO_write(out,&cStack_58,2);
              pbVar16 = pbVar16 + 1;
            } while (iVar4 == 2);
            CRYPTO_free(pbVar3);
          }
        }
        else {
          pbVar3 = str->data;
          iVar13 = str->length;
          if (out == (BIO *)0x0) {
joined_r0x000b289a:
            if (-1 < iVar13 * 2) {
              uStack_70 = iVar13 * 2 + 1 + uStack_70;
              goto LAB_000b23ee;
            }
          }
          else {
            pbVar16 = pbVar3;
            do {
              if (pbVar16 == pbVar3 + iVar13) goto joined_r0x000b289a;
              uStack_48._2_2_ = (undefined2)((ulong)uStack_48 >> 0x10);
              uStack_48._0_4_ =
                   CONCAT31(CONCAT21(uStack_48._2_2_,"0123456789ABCDEF"[*pbVar16 & 0xf]),
                            "0123456789ABCDEF"[*pbVar16 >> 4]);
              iVar4 = BIO_write(out,&uStack_48,2);
              pbVar16 = pbVar16 + 1;
            } while (iVar4 == 2);
          }
        }
      }
    }
    else {
      if ((int)(flags << 0x1a) < 0) {
LAB_000b2404:
        if ((int)(flags << 0x1b) < 0) {
          bVar7 = 1;
LAB_000b24e6:
          bVar7 = bVar7 | 8;
        }
        else {
LAB_000b240a:
          bVar7 = 1;
        }
      }
      else {
        if ((0x1d < iVar13 - 1U) || (bVar7 = tag2nbyte[iVar13], bVar7 == 0xff)) {
          if ((int)(flags << 0x17) < 0) goto LAB_000b23cc;
          goto LAB_000b2404;
        }
        if ((int)(flags << 0x1b) < 0) {
          if (bVar7 != 0) goto LAB_000b24e6;
          goto LAB_000b240a;
        }
      }
      iVar13 = str->length;
      pbVar3 = str->data;
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
            uVar15 = (flags & 1) << 5;
          }
          else {
            uVar15 = 0;
          }
          switch(bVar7 & 7) {
          case 0:
            iVar2 = UTF8_getc(pbVar12,iVar13,(ulong *)&uStack_48);
            if (iVar2 < 0) goto switchD_000b26e4_caseD_3;
            pbVar12 = pbVar12 + iVar2;
            break;
          case 1:
            uStack_48._0_4_ = (ulong)*pbVar12;
            pbVar12 = pbVar12 + 1;
            break;
          case 2:
            uStack_48._0_4_ = (ulong)CONCAT11(*pbVar12,pbVar12[1]);
            pbVar12 = pbVar12 + 2;
            break;
          default:
            goto switchD_000b26e4_caseD_3;
          case 4:
            uStack_48._0_4_ =
                 (uint)pbVar12[3] |
                 (uint)*pbVar12 << 0x18 | (uint)pbVar12[1] << 0x10 | (uint)pbVar12[2] << 8;
            pbVar12 = pbVar12 + 4;
          }
          if (pbVar16 == pbVar12) {
            if ((flags & 1) != 0) {
              uVar15 = 0x40;
            }
            if (bVar6 != 0) goto LAB_000b2520;
LAB_000b2728:
            iVar2 = do_esc_char_constprop_6((ulong)uStack_48,uVar15 | uVar8,acStack_60,bVar6);
            if (iVar2 < 0) goto switchD_000b26e4_caseD_3;
            iVar4 = iVar4 + iVar2;
          }
          else {
            if (bVar6 == 0) goto LAB_000b2728;
LAB_000b2520:
            iVar2 = UTF8_putc(abStack_40,6,(ulong)uStack_48);
            if (0 < iVar2) {
              uVar15 = uVar15 | uVar8;
              if (uVar8 == 0) {
                if ((int)((uint)abStack_40[0] << 0x18) < 0) {
                  uVar9 = flags & 4;
                }
                else {
                  uVar9 = uVar15 & (byte)(&char_type)[abStack_40[0]];
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
                  acStack_60[0] = '\x01';
                }
                else {
                  iVar10 = 2;
                }
                iVar4 = iVar4 + iVar10;
                if (iVar2 != 1) {
                  if ((int)((uint)abStack_40[1] << 0x18) < 0) {
                    uVar9 = flags & 4;
                  }
                  else {
                    uVar9 = uVar15 & (byte)(&char_type)[abStack_40[1]];
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
                    acStack_60[0] = '\x01';
                  }
                  else {
                    iVar10 = 2;
                  }
                  iVar4 = iVar4 + iVar10;
                  if (iVar2 != 2) {
                    if ((int)((uint)abStack_40[2] << 0x18) < 0) {
                      uVar9 = flags & 4;
                    }
                    else {
                      uVar9 = uVar15 & (byte)(&char_type)[abStack_40[2]];
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
                      acStack_60[0] = '\x01';
                    }
                    else {
                      iVar10 = 2;
                    }
                    iVar4 = iVar4 + iVar10;
                    if (iVar2 != 3) {
                      if ((int)((uint)abStack_40[3] << 0x18) < 0) {
                        uVar9 = flags & 4;
                      }
                      else {
                        uVar9 = uVar15 & (byte)(&char_type)[abStack_40[3]];
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
                        acStack_60[0] = '\x01';
                      }
                      else {
                        iVar10 = 2;
                      }
                      iVar4 = iVar4 + iVar10;
                      if (iVar2 != 4) {
                        if ((int)((uint)bStack_3c << 0x18) < 0) {
                          uVar9 = flags & 4;
                        }
                        else {
                          uVar9 = uVar15 & (byte)(&char_type)[bStack_3c];
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
                          acStack_60[0] = '\x01';
                        }
                        else {
                          iVar10 = 2;
                        }
                        iVar4 = iVar4 + iVar10;
                        if (iVar2 != 5) {
                          if ((int)((uint)bStack_3b << 0x18) < 0) {
                            uVar15 = flags & 4;
                          }
                          else {
                            uVar15 = uVar15 & (byte)(&char_type)[bStack_3b];
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
                            acStack_60[0] = '\x01';
                          }
                          iVar4 = iVar4 + iVar2;
                        }
                      }
                    }
                  }
                }
              }
              else {
                pbVar14 = (byte *)((int)&uStack_48 + 7);
                pbVar5 = pbVar14 + iVar2;
                do {
                  while( true ) {
                    pbVar14 = pbVar14 + 1;
                    uVar11 = (uint)*pbVar14;
                    uVar9 = flags & 4;
                    if (-1 < (int)(uVar11 << 0x18)) {
                      uVar9 = uVar15 & (byte)(&char_type)[uVar11];
                    }
                    if ((uVar9 & 0x61) == 0) break;
                    if ((int)(uVar9 << 0x1c) < 0) {
                      iVar2 = 1;
                      acStack_60[0] = '\x01';
                    }
                    else {
                      iVar2 = 2;
                    }
LAB_000b2784:
                    iVar4 = iVar4 + iVar2;
                    if (pbVar14 == pbVar5) goto LAB_000b2674;
                  }
                  if ((uVar9 & 6) != 0) {
                    BIO_snprintf(acStack_38,0xb,"\\%02X");
                    iVar2 = 3;
                    goto LAB_000b2784;
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
LAB_000b2674:
        } while (pbVar16 != pbVar12);
      }
      uStack_70 = uStack_70 + iVar4;
      if (acStack_60[0] == '\0') {
        if (out == (BIO *)0x0) goto LAB_000b23ee;
      }
      else {
        uStack_70 = uStack_70 + 2;
        if (out == (BIO *)0x0) goto LAB_000b23ee;
        iVar13 = BIO_write(out,&DAT_00175478,1);
        if (iVar13 != 1) goto switchD_000b26e4_caseD_3;
      }
      iVar13 = str->length;
      pbVar3 = str->data;
      pbVar16 = pbVar3 + iVar13;
      if (pbVar3 != pbVar16) {
        bVar6 = bVar7 & 8;
        pbVar12 = pbVar3;
        do {
          if (pbVar3 == pbVar12) {
            uVar15 = (flags & 1) << 5;
          }
          else {
            uVar15 = 0;
          }
          switch(bVar7 & 7) {
          case 0:
            iVar4 = UTF8_getc(pbVar12,iVar13,(ulong *)&uStack_48);
            if (iVar4 < 0) goto switchD_000b26e4_caseD_3;
            pbVar12 = pbVar12 + iVar4;
            break;
          case 1:
            uStack_48._0_4_ = (ulong)*pbVar12;
            pbVar12 = pbVar12 + 1;
            break;
          case 2:
            uStack_48._0_4_ = (ulong)CONCAT11(*pbVar12,pbVar12[1]);
            pbVar12 = pbVar12 + 2;
            break;
          default:
            goto switchD_000b26e4_caseD_3;
          case 4:
            uStack_48._0_4_ =
                 (uint)pbVar12[3] |
                 (uint)*pbVar12 << 0x18 | (uint)pbVar12[1] << 0x10 | (uint)pbVar12[2] << 8;
            pbVar12 = pbVar12 + 4;
          }
          if (pbVar16 == pbVar12) {
            if ((flags & 1) != 0) {
              uVar15 = 0x40;
            }
            if (bVar6 != 0) goto LAB_000b29c2;
LAB_000b2a54:
            iVar4 = do_esc_char_constprop_6((ulong)uStack_48,uVar8 | uVar15,bVar6);
            if (iVar4 < 0) goto switchD_000b26e4_caseD_3;
          }
          else {
            if (bVar6 == 0) goto LAB_000b2a54;
LAB_000b29c2:
            iVar4 = UTF8_putc(abStack_40,6,(ulong)uStack_48);
            if (0 < iVar4) {
              pbVar14 = (byte *)((int)&uStack_48 + 7);
              pbVar5 = pbVar14 + iVar4;
              do {
                pbVar14 = pbVar14 + 1;
                uVar11 = (uint)*pbVar14;
                apbStack_50[0] = (byte *)((uint)apbStack_50[0] & 0xffffff00 | (uint)*pbVar14);
                uVar9 = flags & 4;
                if (-1 < (int)(uVar11 << 0x18)) {
                  uVar9 = (uint)(byte)(&char_type)[uVar11] & (uVar15 | uVar8);
                }
                if ((uVar9 & 0x61) == 0) {
                  if ((uVar9 & 6) == 0) {
                    if ((uVar11 != 0x5c) || (uVar8 == 0)) goto LAB_000b2a06;
                    iVar4 = BIO_write(out,&DAT_00160d98,2);
                    if (iVar4 != 2) goto switchD_000b26e4_caseD_3;
                  }
                  else {
                    BIO_snprintf(acStack_38,0xb,"\\%02X");
                    iVar4 = BIO_write(out,acStack_38,3);
                    if (iVar4 != 3) goto switchD_000b26e4_caseD_3;
                  }
                }
                else {
                  if ((int)(uVar9 << 0x1c) < 0) {
LAB_000b2a06:
                    iVar4 = BIO_write(out,apbStack_50,1);
                  }
                  else {
                    iVar4 = BIO_write(out,&DAT_00160d8c,1);
                    if (iVar4 != 1) goto switchD_000b26e4_caseD_3;
                    iVar4 = BIO_write(out,apbStack_50,1);
                  }
                  if (iVar4 != 1) goto switchD_000b26e4_caseD_3;
                }
              } while (pbVar14 != pbVar5);
            }
          }
        } while (pbVar16 != pbVar12);
      }
      if ((acStack_60[0] == '\0') || (iVar13 = BIO_write(out,&DAT_00175478,1), iVar13 == 1))
      goto LAB_000b23ee;
    }
  }
  else {
    __s = ASN1_tag2str(iVar13);
    len = strlen(__s);
    if ((out == (BIO *)0x0) ||
       ((sVar1 = BIO_write(out,__s,len), len == sVar1 && (iVar4 = BIO_write(out,":",1), iVar4 == 1))
       )) {
      uStack_70 = len + 1;
      goto LAB_000b23c8;
    }
  }
switchD_000b26e4_caseD_3:
  uStack_70 = -1;
LAB_000b23ee:
  if (iStack_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uStack_70;
}

