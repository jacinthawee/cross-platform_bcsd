
int asn1parse_main(int param_1,undefined4 *param_2)

{
  char cVar1;
  _STACK *__s;
  _STACK *p_Var2;
  BIO_METHOD *pBVar3;
  BIO *bp;
  long lVar4;
  ASN1_TYPE *a;
  void *pvVar5;
  int iVar6;
  char *pcVar7;
  undefined4 uVar8;
  uint uVar9;
  _STACK *p_Var10;
  _STACK *p_Var11;
  BIO *pBVar12;
  int iVar13;
  BIO *pBVar14;
  char **ppcVar15;
  BIO *pBVar16;
  BIO *pBVar17;
  BIO *str;
  _STACK *st;
  char **ppcVar18;
  size_t len;
  _STACK *unaff_r11;
  BIO *local_54;
  BIO *local_50;
  int local_4c;
  int local_48;
  char *local_44;
  int local_40;
  int local_3c;
  ASN1_TYPE *local_38;
  int local_34;
  int local_30;
  _func_603 *local_2c [2];
  
  p_Var10 = (_STACK *)&bio_err;
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    pBVar3 = BIO_s_file();
    bio_err = BIO_new(pBVar3);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  p_Var2 = (_STACK *)load_config(bio_err,0);
  if (p_Var2 != (_STACK *)0x0) {
    param_1 = param_1 + -1;
    ppcVar18 = (char **)(param_2 + 1);
    uVar8 = *param_2;
    p_Var2 = sk_new_null();
    if (p_Var2 != (_STACK *)0x0) {
      pBVar16 = (BIO *)0x0;
      iVar13 = 3;
      if (0 < param_1) {
        unaff_r11 = p_Var10;
      }
      local_38 = (ASN1_TYPE *)0x0;
      local_54 = (BIO *)0x0;
      if (0 < param_1) {
        p_Var10 = (_STACK *)0x0;
      }
      local_44 = (char *)0x0;
      st = (_STACK *)0x0;
      if (0 < param_1) {
        st = p_Var2;
      }
      local_34 = 0;
      local_4c = 0;
      local_48 = 0;
      local_40 = 0;
      local_3c = 0;
      p_Var11 = p_Var10;
      __s = st;
joined_r0x000143c8:
      do {
        if (param_1 < 1) goto LAB_00014438;
        pcVar7 = *ppcVar18;
        iVar6 = strcmp(pcVar7,"-inform");
        p_Var10 = unaff_r11;
        p_Var2 = st;
        if (iVar6 == 0) {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_000145d2;
          ppcVar15 = ppcVar18 + 1;
          iVar13 = str2fmt(ppcVar18[1]);
        }
        else {
          ppcVar15 = ppcVar18;
          if (*pcVar7 != '-') {
            iVar6 = strcmp(pcVar7,"-out");
            if (iVar6 == 0) {
LAB_00014418:
              if (param_1 != 1) {
                local_54 = (BIO *)ppcVar18[1];
                param_1 = param_1 + -2;
                ppcVar18 = ppcVar18 + 2;
                __s = p_Var11;
                goto joined_r0x000143c8;
              }
            }
            else {
LAB_000144ee:
              iVar6 = strcmp(pcVar7,"-noout");
              if (iVar6 == 0) {
                local_4c = 1;
                goto LAB_000143e0;
              }
              iVar6 = strcmp(pcVar7,"-oid");
              if (iVar6 == 0) {
                param_1 = param_1 + -1;
                if (param_1 != 0) {
                  local_44 = ppcVar18[1];
                  ppcVar15 = ppcVar18 + 1;
                  goto LAB_000143e0;
                }
              }
              else {
                iVar6 = strcmp(pcVar7,"-offset");
                if (iVar6 == 0) {
                  param_1 = param_1 + -1;
                  if (param_1 != 0) {
                    local_3c = strtol(ppcVar18[1],(char **)0x0,10);
                    ppcVar15 = ppcVar18 + 1;
                    goto LAB_000143e0;
                  }
                }
                else {
                  iVar6 = strcmp(pcVar7,"-length");
                  if (iVar6 == 0) {
                    param_1 = param_1 + -1;
                    if (param_1 != 0) {
                      local_40 = strtol(ppcVar18[1],(char **)0x0,10);
                      ppcVar15 = ppcVar18 + 1;
                      if (local_40 != 0) goto LAB_000143e0;
                    }
                  }
                  else {
                    iVar6 = strcmp(pcVar7,"-dump");
                    if (iVar6 == 0) {
                      local_34 = -1;
                      goto LAB_000143e0;
                    }
                    iVar6 = strcmp(pcVar7,"-dlimit");
                    if (iVar6 == 0) {
                      param_1 = param_1 + -1;
                      if (param_1 != 0) {
                        local_34 = strtol(ppcVar18[1],(char **)0x0,10);
                        ppcVar15 = ppcVar18 + 1;
                        if (0 < local_34) goto LAB_000143e0;
                      }
                    }
                    else {
                      iVar6 = strcmp(pcVar7,"-strparse");
                      if (iVar6 == 0) {
                        param_1 = param_1 + -1;
                        if (param_1 != 0) {
                          sk_push(st,ppcVar18[1]);
                          ppcVar15 = ppcVar18 + 1;
                          goto LAB_000143e0;
                        }
                      }
                      else {
                        iVar6 = strcmp(pcVar7,"-genstr");
                        if (iVar6 == 0) {
                          param_1 = param_1 + -1;
                          if (param_1 != 0) {
                            local_38 = (ASN1_TYPE *)ppcVar18[1];
                            ppcVar15 = ppcVar18 + 1;
                            goto LAB_000143e0;
                          }
                        }
                        else {
                          iVar6 = strcmp(pcVar7,"-genconf");
                          if (iVar6 == 0) {
                            param_1 = param_1 + -1;
                            if (param_1 != 0) {
                              pBVar16 = (BIO *)ppcVar18[1];
                              ppcVar15 = ppcVar18 + 1;
                              goto LAB_000143e0;
                            }
                          }
                          else {
                            BIO_printf((BIO *)unaff_r11->num,"unknown option %s\n",pcVar7);
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
LAB_000145d2:
            BIO_printf((BIO *)unaff_r11->num,"%s [options] <infile\n",uVar8);
            BIO_printf((BIO *)unaff_r11->num,"where options are\n");
            BIO_printf((BIO *)unaff_r11->num," -inform arg   input format - one of DER PEM\n");
            BIO_printf((BIO *)unaff_r11->num," -in arg       input file\n");
            BIO_printf((BIO *)unaff_r11->num,
                       " -out arg      output file (output format is always DER\n");
            BIO_printf((BIO *)unaff_r11->num," -noout arg    don\'t produce any output\n");
            BIO_printf((BIO *)unaff_r11->num," -offset arg   offset into file\n");
            BIO_printf((BIO *)unaff_r11->num," -length arg   length of section in file\n");
            BIO_printf((BIO *)unaff_r11->num," -i            indent entries\n");
            BIO_printf((BIO *)unaff_r11->num," -dump         dump unknown data in hex form\n");
            BIO_printf((BIO *)unaff_r11->num,
                       " -dlimit arg   dump the first arg bytes of unknown data in hex form\n");
            BIO_printf((BIO *)unaff_r11->num," -oid file     file of extra oid definitions\n");
            BIO_printf((BIO *)unaff_r11->num," -strparse offset\n");
            BIO_printf((BIO *)unaff_r11->num,
                       "               a series of these can be used to \'dig\' into multiple\n");
            BIO_printf((BIO *)unaff_r11->num,"               ASN1 blob wrappings\n");
            BIO_printf((BIO *)unaff_r11->num,
                       " -genstr str   string to generate ASN1 structure from\n");
            BIO_printf((BIO *)unaff_r11->num," -genconf file file to generate ASN1 structure from\n"
                      );
            goto LAB_0001433e;
          }
          cVar1 = pcVar7[1];
          if (((cVar1 == 'i') && (pcVar7[2] == 'n')) && (pcVar7[3] == '\0')) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_000145d2;
            ppcVar15 = ppcVar18 + 1;
            p_Var11 = (_STACK *)ppcVar18[1];
          }
          else {
            iVar6 = strcmp(pcVar7,"-out");
            if (iVar6 == 0) goto LAB_00014418;
            if ((cVar1 != 'i') || (pcVar7[2] != '\0')) goto LAB_000144ee;
            local_48 = 1;
          }
        }
LAB_000143e0:
        param_1 = param_1 + -1;
        ppcVar18 = ppcVar15 + 1;
        __s = p_Var11;
      } while( true );
    }
    BIO_printf(bio_err,"Memory allocation failure\n");
  }
LAB_0001433e:
  local_4c = 1;
  str = (BIO *)0x0;
  BIO_free((BIO *)0x0);
  pBVar12 = (BIO *)0x0;
LAB_0001434c:
  ERR_print_errors(p_Var10->num);
LAB_00014352:
  if (str != (BIO *)0x0) {
    BUF_MEM_free((BUF_MEM *)str);
  }
  if (pBVar12 != (BIO *)0x0) {
    ASN1_TYPE_free((ASN1_TYPE *)pBVar12);
  }
  if (p_Var2 != (_STACK *)0x0) {
    sk_free(p_Var2);
  }
  OBJ_cleanup();
  return local_4c;
LAB_00014438:
  ERR_load_crypto_strings();
  pBVar3 = BIO_s_file();
  pBVar12 = BIO_new(pBVar3);
  pBVar3 = BIO_s_file();
  bp = BIO_new(pBVar3);
  local_50 = (BIO *)(uint)(pBVar12 == (BIO *)0x0 || bp == (BIO *)0x0);
  if (pBVar12 != (BIO *)0x0 && bp != (BIO *)0x0) {
    BIO_ctrl(bp,0x6a,0x10,stdout);
    if (local_44 == (char *)0x0) {
LAB_00014718:
      if (__s == (_STACK *)0x0) {
        BIO_ctrl(pBVar12,0x6a,0,stdin);
      }
      else {
        lVar4 = BIO_ctrl(pBVar12,0x6c,3,__s);
        if (lVar4 < 1) {
          perror((char *)__s);
          local_4c = 1;
          local_50 = (BIO *)0x0;
          pBVar14 = (BIO *)0x0;
          pBVar17 = (BIO *)0x0;
          str = (BIO *)0x0;
          goto LAB_000147bc;
        }
      }
      local_50 = local_54;
      if ((local_54 == (BIO *)0x0) ||
         (local_50 = BIO_new_file((char *)local_54,"wb"), local_50 != (BIO *)0x0)) {
        str = (BIO *)BUF_MEM_new();
        if (str == (BIO *)0x0) {
          local_4c = 1;
          pBVar14 = str;
          pBVar17 = str;
        }
        else {
          pBVar14 = (BIO *)BUF_MEM_grow((BUF_MEM *)str,0x10000);
          if (pBVar14 == (BIO *)0x0) {
            local_4c = 1;
            pBVar17 = pBVar14;
          }
          else {
            pBVar14 = pBVar16;
            if (pBVar16 != (BIO *)0x0) {
              pBVar14 = (BIO *)0x1;
            }
            pBVar17 = pBVar14;
            if (local_38 != (ASN1_TYPE *)0x0) {
              pBVar17 = (BIO *)((uint)pBVar14 | 1);
            }
            if (pBVar17 == (BIO *)0x0) {
              pBVar14 = pBVar12;
              if (iVar13 == 3) {
                pBVar3 = BIO_f_base64();
                pBVar14 = BIO_new(pBVar3);
                if (pBVar14 == (BIO *)0x0) {
                  local_4c = 1;
                  pBVar17 = pBVar14;
                  goto LAB_000147bc;
                }
                BIO_push(pBVar14,pBVar12);
                pBVar17 = pBVar12;
              }
              len = 0;
              while (pBVar16 = (BIO *)BUF_MEM_grow((BUF_MEM *)str,len + 0x2000), pBVar12 = pBVar14,
                    pBVar16 != (BIO *)0x0) {
                iVar13 = BIO_read(pBVar14,str->callback + len,0x2000);
                if (iVar13 < 1) goto LAB_000148f2;
                len = len + iVar13;
              }
              local_4c = 1;
              pBVar14 = pBVar16;
            }
            else {
              pBVar17 = (BIO *)p_Var10->num;
              if (pBVar14 == (BIO *)0x0) {
LAB_000148a4:
                a = ASN1_generate_nconf((char *)local_38,(CONF *)pBVar14);
                NCONF_free((CONF *)pBVar14);
                if (a != (ASN1_TYPE *)0x0) {
                  len = i2d_ASN1_TYPE(a,(uchar **)0x0);
                  if ((int)len < 1) {
                    pBVar14 = (BIO *)0x0;
                  }
                  else {
                    pBVar14 = (BIO *)BUF_MEM_grow((BUF_MEM *)str,len);
                    if (pBVar14 != (BIO *)0x0) {
                      local_2c[0] = str->callback;
                      pBVar17 = (BIO *)0x0;
                      i2d_ASN1_TYPE(a,(uchar **)local_2c);
                      ASN1_TYPE_free(a);
LAB_000148f2:
                      local_54 = (BIO *)str->callback;
                      pBVar14 = (BIO *)sk_num(p_Var2);
                      if (pBVar14 != (BIO *)0x0) {
                        pBVar14 = (BIO *)0x0;
                        for (iVar13 = 0; iVar6 = sk_num(p_Var2), iVar13 < iVar6; iVar13 = iVar13 + 1
                            ) {
                          pcVar7 = (char *)sk_value(p_Var2,iVar13);
                          lVar4 = strtol(pcVar7,(char **)0x0,10);
                          if (lVar4 == 0) {
                            pBVar16 = (BIO *)p_Var10->num;
                            pvVar5 = sk_value(p_Var2,iVar13);
                            BIO_printf(pBVar16,"\'%s\' is an invalid number\n",pvVar5);
                          }
                          else {
                            local_2c[0] = (_func_603 *)((int)local_54 + lVar4);
                            pBVar16 = (BIO *)d2i_ASN1_TYPE((ASN1_TYPE **)0x0,(uchar **)local_2c,
                                                           len - lVar4);
                            ASN1_TYPE_free((ASN1_TYPE *)pBVar14);
                            pBVar14 = pBVar16;
                            if (pBVar16 == (BIO *)0x0) {
                              BIO_printf((BIO *)p_Var10->num,"Error parsing structure\n");
                              ERR_print_errors(p_Var10->num);
                              local_4c = 1;
                              goto LAB_000147bc;
                            }
                            iVar6 = ASN1_TYPE_get((ASN1_TYPE *)pBVar16);
                            if (iVar6 - 5U < 2) {
                              pcVar7 = "OBJECT";
                              if (iVar6 == 5) {
                                pcVar7 = "NULL";
                              }
                              BIO_printf((BIO *)p_Var10->num,"Can\'t parse %s type\n",pcVar7);
                              ERR_print_errors(p_Var10->num);
                              local_4c = 1;
                              goto LAB_000147bc;
                            }
                            local_54 = *(BIO **)((int)pBVar16->callback + 8);
                            len = *(size_t *)pBVar16->callback;
                          }
                        }
                      }
                      if (local_3c < (int)len) {
                        uVar9 = count_leading_zeroes(local_40);
                        uVar9 = uVar9 >> 5;
                        if ((int)(len - local_3c) < local_40) {
                          uVar9 = uVar9 | 1;
                        }
                        if (uVar9 != 0) {
                          local_40 = len - local_3c;
                        }
                        if ((local_50 == (BIO *)0x0) ||
                           (iVar13 = BIO_write(local_50,(_func_603 *)((int)local_54 + local_3c),
                                               local_40), local_40 == iVar13)) {
                          if (local_4c == 0) {
                            iVar13 = ASN1_parse_dump(bp,(uchar *)((int)local_54 + local_3c),local_40
                                                     ,local_48,local_34);
                            if (iVar13 == 0) {
                              local_4c = 1;
                              ERR_print_errors(p_Var10->num);
                            }
                          }
                          else {
                            local_4c = 0;
                          }
                        }
                        else {
                          local_4c = 1;
                          BIO_printf((BIO *)p_Var10->num,"Error writing output\n");
                          ERR_print_errors(p_Var10->num);
                        }
                      }
                      else {
                        local_4c = 1;
                        BIO_printf((BIO *)p_Var10->num,"Error: offset too large\n");
                      }
                      goto LAB_000147bc;
                    }
                  }
                  goto LAB_00014b42;
                }
              }
              else {
                pBVar14 = (BIO *)NCONF_new((CONF_METHOD *)0x0);
                a = (ASN1_TYPE *)NCONF_load((CONF *)pBVar14,(char *)pBVar16,&local_30);
                if (a == (ASN1_TYPE *)0x0) {
                  if (local_30 < 1) {
                    BIO_printf(pBVar17,"Error loading config file \'%s\'\n",pBVar16);
                  }
                  else {
                    BIO_printf(pBVar17,"Error on line %ld of config file \'%s\'\n",local_30,pBVar16)
                    ;
                  }
                }
                else {
                  if ((local_38 != (ASN1_TYPE *)0x0) ||
                     (a = (ASN1_TYPE *)NCONF_get_string((CONF *)pBVar14,"default","asn1"),
                     local_38 = a, a != (ASN1_TYPE *)0x0)) goto LAB_000148a4;
                  BIO_printf(pBVar17,"Can\'t find \'asn1\' in \'%s\'\n",pBVar16);
                }
LAB_00014b42:
                NCONF_free((CONF *)pBVar14);
                ASN1_TYPE_free(a);
              }
              ERR_print_errors(p_Var10->num);
              local_4c = 1;
              pBVar14 = (BIO *)0x0;
              pBVar17 = (BIO *)0x0;
            }
          }
        }
      }
      else {
        BIO_printf((BIO *)p_Var10->num,"problems opening %s\n",local_54);
        ERR_print_errors(p_Var10->num);
        local_4c = 1;
        pBVar14 = local_50;
        pBVar17 = local_50;
        str = local_50;
      }
    }
    else {
      lVar4 = BIO_ctrl(pBVar12,0x6c,3,local_44);
      if (0 < lVar4) {
        OBJ_create_objects(pBVar12);
        goto LAB_00014718;
      }
      BIO_printf((BIO *)p_Var10->num,"problems opening %s\n",local_44);
      ERR_print_errors(p_Var10->num);
      local_4c = 1;
      pBVar14 = local_50;
      pBVar17 = local_50;
      str = local_50;
    }
LAB_000147bc:
    BIO_free(local_50);
LAB_00014480:
    BIO_free(pBVar12);
    pBVar12 = pBVar14;
  }
  else {
    pBVar14 = (BIO *)0x0;
    ERR_print_errors(p_Var10->num);
    BIO_free((BIO *)0x0);
    local_4c = 1;
    str = (BIO *)0x0;
    pBVar17 = (BIO *)0x0;
    if (pBVar12 != (BIO *)0x0) goto LAB_00014480;
    local_4c = 1;
    pBVar17 = pBVar12;
    str = pBVar12;
  }
  if (bp != (BIO *)0x0) {
    BIO_free_all(bp);
  }
  if (pBVar17 != (BIO *)0x0) {
    BIO_free(pBVar17);
  }
  if (local_4c == 0) goto LAB_00014352;
  goto LAB_0001434c;
}

