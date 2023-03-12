
int asn1parse_main(int param_1,undefined4 *param_2)

{
  char **ppcVar1;
  undefined4 uVar2;
  bool bVar3;
  int iVar4;
  BIO_METHOD *pBVar5;
  BIO *bp;
  long lVar6;
  CONF *conf;
  void *pvVar7;
  int iVar8;
  char *pcVar9;
  ASN1_TYPE *pAVar10;
  BIO *b;
  BUF_MEM *str;
  char **ppcVar11;
  size_t len;
  ASN1_TYPE *pAVar12;
  ASN1_TYPE *a;
  BIO *pBVar13;
  char *pcVar14;
  int in_GS_OFFSET;
  bool bVar15;
  byte bVar16;
  char *pcVar17;
  uchar *local_64;
  _STACK *local_60;
  BIO *local_5c;
  char *local_58;
  BIO *local_54;
  int local_50;
  char *local_48;
  long local_44;
  int local_40;
  char *local_3c;
  char *local_38;
  long local_34;
  char *local_28;
  uchar *local_24;
  int local_20;
  
  bVar16 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    pBVar5 = BIO_s_file();
    bio_err = BIO_new(pBVar5);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  iVar4 = load_config(bio_err,0);
  local_60 = (_STACK *)0x0;
  if (iVar4 == 0) {
LAB_0804ce7a:
    pAVar12 = (ASN1_TYPE *)0x0;
    str = (BUF_MEM *)0x0;
    BIO_free((BIO *)0x0);
  }
  else {
    uVar2 = *param_2;
    ppcVar11 = (char **)(param_2 + 1);
    param_1 = param_1 + -1;
    local_60 = sk_new_null();
    if (local_60 == (_STACK *)0x0) {
      BIO_printf(bio_err,"Memory allocation failure\n");
      goto LAB_0804ce7a;
    }
    bVar15 = param_1 == 0;
    local_3c = (char *)0x0;
    local_38 = (char *)0x0;
    local_58 = (char *)0x0;
    local_48 = (char *)0x0;
    local_5c = (BIO *)0x0;
    local_34 = 0;
    bVar3 = false;
    local_50 = 0;
    local_64 = (uchar *)0x3;
    local_40 = 0;
    local_44 = 0;
    if (0 < param_1) {
LAB_0804cfa6:
      do {
        pcVar9 = *ppcVar11;
        iVar4 = 8;
        pcVar17 = pcVar9;
        pcVar14 = "-inform";
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          bVar15 = *pcVar17 == *pcVar14;
          pcVar17 = pcVar17 + (uint)bVar16 * -2 + 1;
          pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
        } while (bVar15);
        if (bVar15) {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_0804d2b8;
          ppcVar1 = ppcVar11 + 1;
          ppcVar11 = ppcVar11 + 1;
          local_64 = (uchar *)str2fmt(*ppcVar1);
LAB_0804cf9e:
          param_1 = param_1 + -1;
          bVar15 = param_1 == 0;
          ppcVar11 = ppcVar11 + 1;
          if (bVar15) break;
          goto LAB_0804cfa6;
        }
        bVar15 = *pcVar9 == '-';
        if (!bVar15) {
          iVar4 = 5;
          pcVar17 = pcVar9;
          pcVar14 = "-out";
          do {
            if (iVar4 == 0) break;
            iVar4 = iVar4 + -1;
            bVar15 = *pcVar17 == *pcVar14;
            pcVar17 = pcVar17 + (uint)bVar16 * -2 + 1;
            pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
          } while (bVar15);
          if (bVar15) {
LAB_0804d1f8:
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_0804d2b8;
            local_58 = ppcVar11[1];
            ppcVar11 = ppcVar11 + 1;
            goto LAB_0804cf9e;
          }
LAB_0804d240:
          iVar4 = 7;
          pcVar17 = pcVar9;
          pcVar14 = "-noout";
          do {
            if (iVar4 == 0) break;
            iVar4 = iVar4 + -1;
            bVar15 = *pcVar17 == *pcVar14;
            pcVar17 = pcVar17 + (uint)bVar16 * -2 + 1;
            pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
          } while (bVar15);
          if (bVar15) {
            bVar3 = true;
            goto LAB_0804cf9e;
          }
          iVar4 = 5;
          pcVar17 = pcVar9;
          pcVar14 = "-oid";
          do {
            if (iVar4 == 0) break;
            iVar4 = iVar4 + -1;
            bVar15 = *pcVar17 == *pcVar14;
            pcVar17 = pcVar17 + (uint)bVar16 * -2 + 1;
            pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
          } while (bVar15);
          if (bVar15) {
            param_1 = param_1 + -1;
            if (param_1 != 0) {
              local_48 = ppcVar11[1];
              ppcVar11 = ppcVar11 + 1;
              goto LAB_0804cf9e;
            }
          }
          else {
            iVar4 = 8;
            pcVar17 = pcVar9;
            pcVar14 = "-offset";
            do {
              if (iVar4 == 0) break;
              iVar4 = iVar4 + -1;
              bVar15 = *pcVar17 == *pcVar14;
              pcVar17 = pcVar17 + (uint)bVar16 * -2 + 1;
              pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
            } while (bVar15);
            if (bVar15) {
              param_1 = param_1 + -1;
              if (param_1 != 0) {
                local_44 = strtol(ppcVar11[1],(char **)0x0,10);
                ppcVar11 = ppcVar11 + 1;
                goto LAB_0804cf9e;
              }
            }
            else {
              iVar4 = 8;
              pcVar17 = pcVar9;
              pcVar14 = "-length";
              do {
                if (iVar4 == 0) break;
                iVar4 = iVar4 + -1;
                bVar15 = *pcVar17 == *pcVar14;
                pcVar17 = pcVar17 + (uint)bVar16 * -2 + 1;
                pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
              } while (bVar15);
              if (bVar15) {
                param_1 = param_1 + -1;
                if (param_1 != 0) {
                  local_40 = strtol(ppcVar11[1],(char **)0x0,10);
                  ppcVar11 = ppcVar11 + 1;
                  if (local_40 != 0) goto LAB_0804cf9e;
                }
              }
              else {
                iVar4 = 6;
                pcVar17 = pcVar9;
                pcVar14 = "-dump";
                do {
                  if (iVar4 == 0) break;
                  iVar4 = iVar4 + -1;
                  bVar15 = *pcVar17 == *pcVar14;
                  pcVar17 = pcVar17 + (uint)bVar16 * -2 + 1;
                  pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
                } while (bVar15);
                if (bVar15) {
                  local_34 = -1;
                  goto LAB_0804cf9e;
                }
                iVar4 = 8;
                pcVar17 = pcVar9;
                pcVar14 = "-dlimit";
                do {
                  if (iVar4 == 0) break;
                  iVar4 = iVar4 + -1;
                  bVar15 = *pcVar17 == *pcVar14;
                  pcVar17 = pcVar17 + (uint)bVar16 * -2 + 1;
                  pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
                } while (bVar15);
                if (bVar15) {
                  param_1 = param_1 + -1;
                  if (param_1 != 0) {
                    local_34 = strtol(ppcVar11[1],(char **)0x0,10);
                    ppcVar11 = ppcVar11 + 1;
                    if (0 < local_34) goto LAB_0804cf9e;
                  }
                }
                else {
                  iVar4 = 10;
                  pcVar17 = pcVar9;
                  pcVar14 = "-strparse";
                  do {
                    if (iVar4 == 0) break;
                    iVar4 = iVar4 + -1;
                    bVar15 = *pcVar17 == *pcVar14;
                    pcVar17 = pcVar17 + (uint)bVar16 * -2 + 1;
                    pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
                  } while (bVar15);
                  if (bVar15) {
                    param_1 = param_1 + -1;
                    if (param_1 != 0) {
                      sk_push(local_60,ppcVar11[1]);
                      ppcVar11 = ppcVar11 + 1;
                      goto LAB_0804cf9e;
                    }
                  }
                  else {
                    iVar4 = 8;
                    pcVar17 = pcVar9;
                    pcVar14 = "-genstr";
                    do {
                      if (iVar4 == 0) break;
                      iVar4 = iVar4 + -1;
                      bVar15 = *pcVar17 == *pcVar14;
                      pcVar17 = pcVar17 + (uint)bVar16 * -2 + 1;
                      pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
                    } while (bVar15);
                    if (bVar15) {
                      param_1 = param_1 + -1;
                      if (param_1 != 0) {
                        local_38 = ppcVar11[1];
                        ppcVar11 = ppcVar11 + 1;
                        goto LAB_0804cf9e;
                      }
                    }
                    else {
                      iVar4 = 9;
                      pcVar17 = pcVar9;
                      pcVar14 = "-genconf";
                      do {
                        if (iVar4 == 0) break;
                        iVar4 = iVar4 + -1;
                        bVar15 = *pcVar17 == *pcVar14;
                        pcVar17 = pcVar17 + (uint)bVar16 * -2 + 1;
                        pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
                      } while (bVar15);
                      if (bVar15) {
                        param_1 = param_1 + -1;
                        if (param_1 != 0) {
                          local_3c = ppcVar11[1];
                          ppcVar11 = ppcVar11 + 1;
                          goto LAB_0804cf9e;
                        }
                      }
                      else {
                        BIO_printf(bio_err,"unknown option %s\n",pcVar9,iVar4);
                      }
                    }
                  }
                }
              }
            }
          }
LAB_0804d2b8:
          BIO_printf(bio_err,"%s [options] <infile\n",uVar2);
          BIO_printf(bio_err,"where options are\n");
          BIO_printf(bio_err," -inform arg   input format - one of DER PEM\n");
          BIO_printf(bio_err," -in arg       input file\n");
          BIO_printf(bio_err," -out arg      output file (output format is always DER\n");
          BIO_printf(bio_err," -noout arg    don\'t produce any output\n");
          BIO_printf(bio_err," -offset arg   offset into file\n");
          BIO_printf(bio_err," -length arg   length of section in file\n");
          BIO_printf(bio_err," -i            indent entries\n");
          BIO_printf(bio_err," -dump         dump unknown data in hex form\n");
          BIO_printf(bio_err," -dlimit arg   dump the first arg bytes of unknown data in hex form\n"
                    );
          BIO_printf(bio_err," -oid file     file of extra oid definitions\n");
          BIO_printf(bio_err," -strparse offset\n");
          BIO_printf(bio_err,
                     "               a series of these can be used to \'dig\' into multiple\n");
          BIO_printf(bio_err,"               ASN1 blob wrappings\n");
          BIO_printf(bio_err," -genstr str   string to generate ASN1 structure from\n");
          BIO_printf(bio_err," -genconf file file to generate ASN1 structure from\n");
          goto LAB_0804ce7a;
        }
        bVar15 = pcVar9[1] == 'i';
        if (((!bVar15) || (bVar15 = pcVar9[2] == 'n', !bVar15)) ||
           (bVar15 = pcVar9[3] == '\0', !bVar15)) {
          iVar4 = 5;
          pcVar17 = pcVar9;
          pcVar14 = "-out";
          do {
            if (iVar4 == 0) break;
            iVar4 = iVar4 + -1;
            bVar15 = *pcVar17 == *pcVar14;
            pcVar17 = pcVar17 + (uint)bVar16 * -2 + 1;
            pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
          } while (bVar15);
          if (bVar15) goto LAB_0804d1f8;
          bVar15 = pcVar9[1] == 'i';
          if ((bVar15) && (bVar15 = pcVar9[2] == '\0', bVar15)) {
            local_50 = 1;
            goto LAB_0804cf9e;
          }
          goto LAB_0804d240;
        }
        if (param_1 == 1) goto LAB_0804d2b8;
        local_5c = (BIO *)ppcVar11[1];
        param_1 = param_1 + -2;
        bVar15 = param_1 == 0;
        ppcVar11 = ppcVar11 + 2;
      } while (!bVar15);
    }
    ERR_load_crypto_strings();
    pBVar5 = BIO_s_file();
    local_54 = BIO_new(pBVar5);
    pBVar5 = BIO_s_file();
    bp = BIO_new(pBVar5);
    if ((local_54 == (BIO *)0x0) || (bp == (BIO *)0x0)) {
      ERR_print_errors(bio_err);
      BIO_free((BIO *)0x0);
      if (local_54 == (BIO *)0x0) {
        if (bp != (BIO *)0x0) {
          pBVar13 = (BIO *)0x0;
          iVar4 = 1;
          str = (BUF_MEM *)0x0;
          pAVar12 = (ASN1_TYPE *)0x0;
          goto LAB_0804d1bc;
        }
        pAVar12 = (ASN1_TYPE *)0x0;
        str = (BUF_MEM *)0x0;
      }
      else {
        BIO_free(local_54);
        if (bp != (BIO *)0x0) {
          iVar4 = 1;
          str = (BUF_MEM *)0x0;
          pAVar12 = (ASN1_TYPE *)0x0;
          pBVar13 = (BIO *)0x0;
          goto LAB_0804d1bc;
        }
        str = (BUF_MEM *)0x0;
        pAVar12 = (ASN1_TYPE *)0x0;
      }
    }
    else {
      BIO_ctrl(bp,0x6a,0x10,stdout);
      if (local_48 == (char *)0x0) {
LAB_0804d08c:
        if (local_5c == (BIO *)0x0) {
          BIO_ctrl(local_54,0x6a,0,stdin);
        }
        else {
          lVar6 = BIO_ctrl(local_54,0x6c,3,local_5c);
          if (lVar6 < 1) {
            perror((char *)local_5c);
            goto LAB_0804d5f2;
          }
        }
        if (local_58 == (char *)0x0) {
          local_5c = (BIO *)0x0;
        }
        else {
          local_5c = BIO_new_file(local_58,"wb");
          if (local_5c == (BIO *)0x0) {
            pAVar12 = (ASN1_TYPE *)0x0;
            str = (BUF_MEM *)0x0;
            pBVar13 = (BIO *)0x0;
            iVar4 = 1;
            BIO_printf(bio_err,"problems opening %s\n",local_58);
            ERR_print_errors(bio_err);
            goto LAB_0804d19b;
          }
        }
        str = BUF_MEM_new();
        if ((str == (BUF_MEM *)0x0) ||
           (iVar4 = BUF_MEM_grow(str,0x10000), pBVar13 = bio_err, iVar4 == 0)) {
          pAVar12 = (ASN1_TYPE *)0x0;
          pBVar13 = (BIO *)0x0;
          iVar4 = 1;
        }
        else if ((local_38 == (char *)0x0) && (local_3c == (char *)0x0)) {
          pBVar13 = (BIO *)0x0;
          if (local_64 == (uchar *)0x3) {
            pBVar5 = BIO_f_base64();
            b = BIO_new(pBVar5);
            pBVar13 = b;
            if (b != (BIO *)0x0) {
              BIO_push(b,local_54);
              pBVar13 = local_54;
              local_54 = b;
              goto LAB_0804d146;
            }
          }
          else {
LAB_0804d146:
            len = 0;
            while (iVar4 = BUF_MEM_grow(str,len + 0x2000), iVar4 != 0) {
              iVar4 = BIO_read(local_54,str->data + len,0x2000);
              if (iVar4 < 1) goto LAB_0804d753;
              len = len + iVar4;
            }
          }
          pAVar12 = (ASN1_TYPE *)0x0;
          iVar4 = 1;
        }
        else {
          if (local_3c == (char *)0x0) {
            conf = (CONF *)0x0;
LAB_0804d6ce:
            pAVar12 = ASN1_generate_nconf(local_38,conf);
            NCONF_free(conf);
            if (pAVar12 != (ASN1_TYPE *)0x0) {
              len = i2d_ASN1_TYPE(pAVar12,(uchar **)0x0);
              if ((0 < (int)len) && (iVar4 = BUF_MEM_grow(str,len), iVar4 != 0)) {
                local_24 = (uchar *)str->data;
                i2d_ASN1_TYPE(pAVar12,&local_24);
                pBVar13 = (BIO *)0x0;
                ASN1_TYPE_free(pAVar12);
LAB_0804d753:
                local_64 = (uchar *)str->data;
                a = (ASN1_TYPE *)0x0;
                iVar4 = sk_num(local_60);
                pAVar12 = a;
                if (iVar4 != 0) {
                  for (iVar4 = 0; iVar8 = sk_num(local_60), pAVar12 = a, iVar4 < iVar8;
                      iVar4 = iVar4 + 1) {
                    pcVar9 = (char *)sk_value(local_60,iVar4);
                    lVar6 = strtol(pcVar9,(char **)0x0,10);
                    if (lVar6 == 0) {
                      pvVar7 = sk_value(local_60,iVar4);
                      BIO_printf(bio_err,"\'%s\' is an invalid number\n",pvVar7);
                    }
                    else {
                      local_24 = local_64 + lVar6;
                      pAVar12 = d2i_ASN1_TYPE((ASN1_TYPE **)0x0,&local_24,len - lVar6);
                      pAVar10 = pAVar12;
                      ASN1_TYPE_free(a);
                      if (pAVar12 == (ASN1_TYPE *)0x0) {
                        pAVar12 = (ASN1_TYPE *)0x0;
                        iVar4 = 1;
                        BIO_printf(bio_err,"Error parsing structure\n",pAVar10,pAVar10);
                        ERR_print_errors(bio_err);
                        goto LAB_0804d19b;
                      }
                      iVar8 = ASN1_TYPE_get(pAVar12);
                      if (iVar8 - 5U < 2) {
                        pcVar9 = "OBJECT";
                        if (iVar8 == 5) {
                          pcVar9 = "NULL";
                        }
                        iVar4 = 1;
                        BIO_printf(bio_err,"Can\'t parse %s type\n",pcVar9,a);
                        ERR_print_errors(bio_err);
                        goto LAB_0804d19b;
                      }
                      local_64 = ((pAVar12->value).asn1_string)->data;
                      len = ((pAVar12->value).asn1_string)->length;
                      a = pAVar12;
                    }
                  }
                }
                if (local_44 < (int)len) {
                  if ((local_40 == 0) || ((int)(len - local_44) < local_40)) {
                    local_40 = len - local_44;
                  }
                  if ((local_5c == (BIO *)0x0) ||
                     (iVar4 = BIO_write(local_5c,local_64 + local_44,local_40), local_40 == iVar4))
                  {
                    iVar4 = 0;
                    if ((bVar3) ||
                       (iVar8 = ASN1_parse_dump(bp,local_64 + local_44,local_40,local_50,local_34),
                       iVar8 != 0)) goto LAB_0804d19b;
                  }
                  else {
                    BIO_printf(bio_err,"Error writing output\n");
                  }
                  iVar4 = 1;
                  ERR_print_errors(bio_err);
                }
                else {
                  iVar4 = 1;
                  BIO_printf(bio_err,"Error: offset too large\n");
                }
                goto LAB_0804d19b;
              }
              conf = (CONF *)0x0;
              goto LAB_0804da15;
            }
          }
          else {
            conf = NCONF_new((CONF_METHOD *)0x0);
            iVar4 = NCONF_load(conf,local_3c,(long *)&local_28);
            pcVar9 = local_3c;
            if (iVar4 == 0) {
              if ((int)local_28 < 1) {
                pcVar17 = "Error loading config file \'%s\'\n";
                local_3c = local_28;
              }
              else {
                pcVar17 = "Error on line %ld of config file \'%s\'\n";
                pcVar9 = local_28;
              }
            }
            else {
              if ((local_38 != (char *)0x0) ||
                 (local_38 = NCONF_get_string(conf,"default","asn1"), local_38 != (char *)0x0))
              goto LAB_0804d6ce;
              pcVar17 = "Can\'t find \'asn1\' in \'%s\'\n";
              local_3c = local_38;
            }
            pAVar12 = (ASN1_TYPE *)0x0;
            BIO_printf(pBVar13,pcVar17,pcVar9,local_3c);
LAB_0804da15:
            NCONF_free(conf);
            ASN1_TYPE_free(pAVar12);
          }
          pAVar12 = (ASN1_TYPE *)0x0;
          pBVar13 = (BIO *)0x0;
          iVar4 = 1;
          ERR_print_errors(bio_err);
        }
      }
      else {
        lVar6 = BIO_ctrl(local_54,0x6c,3,local_48);
        if (0 < lVar6) {
          OBJ_create_objects(local_54);
          goto LAB_0804d08c;
        }
        BIO_printf(bio_err,"problems opening %s\n",local_48);
        ERR_print_errors(bio_err);
LAB_0804d5f2:
        pAVar12 = (ASN1_TYPE *)0x0;
        str = (BUF_MEM *)0x0;
        local_5c = (BIO *)0x0;
        pBVar13 = (BIO *)0x0;
        iVar4 = 1;
      }
LAB_0804d19b:
      BIO_free(local_5c);
      BIO_free(local_54);
LAB_0804d1bc:
      BIO_free_all(bp);
      if (pBVar13 != (BIO *)0x0) {
        BIO_free(pBVar13);
      }
      if (iVar4 == 0) goto LAB_0804cea1;
    }
  }
  iVar4 = 1;
  ERR_print_errors(bio_err);
LAB_0804cea1:
  if (str != (BUF_MEM *)0x0) {
    BUF_MEM_free(str);
  }
  if (pAVar12 != (ASN1_TYPE *)0x0) {
    ASN1_TYPE_free(pAVar12);
  }
  if (local_60 != (_STACK *)0x0) {
    sk_free(local_60);
  }
  OBJ_cleanup();
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}

