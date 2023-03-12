
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void crl_main(int param_1,int param_2)

{
  char **ppcVar1;
  byte *pbVar2;
  bool bVar3;
  BIO *bio;
  int iVar4;
  int iVar5;
  BIO_METHOD *pBVar6;
  BIO *pBVar7;
  long lVar8;
  X509_CRL *a;
  X509_LOOKUP_METHOD *pXVar9;
  ulong uVar10;
  ASN1_INTEGER *a_00;
  ASN1_TIME *a_01;
  undefined *puVar11;
  char *pcVar12;
  undefined **ppuVar13;
  uint uVar14;
  undefined4 uVar15;
  X509_STORE *v;
  char **ppcVar16;
  char *local_148;
  int local_144;
  char *local_140;
  EVP_MD *local_138;
  char *local_134;
  int local_130;
  char *local_12c;
  int local_128;
  int local_120;
  int local_11c;
  int local_118;
  int local_114;
  int local_110;
  int local_10c;
  undefined4 local_104;
  uint local_100;
  X509_OBJECT XStack_fc;
  X509_STORE_CTX XStack_f4;
  byte local_6c [64];
  int local_2c;
  
  local_104 = 0;
  local_2c = __TMC_END__;
  local_138 = EVP_sha1();
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    pBVar6 = BIO_s_file();
    bio_err = BIO_new(pBVar6);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  iVar4 = load_config(bio_err,0);
  if (iVar4 != 0) {
    if (bio_out == (BIO *)0x0) {
      pBVar6 = BIO_s_file();
      bio_out = BIO_new(pBVar6);
      if (bio_out != (BIO *)0x0) {
        BIO_ctrl(bio_out,0x6a,0,stdout);
      }
    }
    param_1 = param_1 + -1;
    ppcVar16 = (char **)(param_2 + 4);
    v = (X509_STORE *)0x0;
    if (param_1 < 1) {
      iVar4 = 3;
      local_10c = 0;
      local_144 = 3;
      local_110 = 0;
      bVar3 = false;
      local_11c = 0;
      local_114 = 0;
      local_118 = 0;
      local_120 = 0;
      local_128 = 0;
      local_140 = (char *)0x0;
      local_148 = (char *)0x0;
      local_130 = 0;
      local_134 = (char *)0x0;
      local_12c = (char *)0x0;
    }
    else {
      local_10c = 0;
      iVar4 = 3;
      local_110 = 0;
      local_144 = 3;
      bVar3 = false;
      local_11c = 0;
      local_114 = 0;
      local_118 = 0;
      local_120 = 0;
      local_128 = 0;
      local_140 = (char *)0x0;
      local_148 = (char *)0x0;
      local_130 = 0;
      local_134 = (char *)0x0;
      local_12c = (char *)0x0;
LAB_0001f0e8:
      do {
        pcVar12 = *ppcVar16;
        iVar5 = strcmp(pcVar12,"-inform");
        if (iVar5 == 0) {
          param_1 = param_1 + -1;
          if (param_1 != 0) {
            ppcVar1 = ppcVar16 + 1;
            ppcVar16 = ppcVar16 + 1;
            iVar4 = str2fmt(*ppcVar1);
            goto LAB_0001f0dc;
          }
LAB_0001f39c:
          ppuVar13 = &crl_usage;
          puVar11 = crl_usage;
          while (puVar11 != (undefined *)0x0) {
            BIO_printf(bio_err,"%s");
            ppuVar13 = ppuVar13 + 1;
            puVar11 = *ppuVar13;
          }
          goto LAB_0001f296;
        }
        iVar5 = strcmp(pcVar12,"-outform");
        if (iVar5 != 0) {
          if ((((*pcVar12 == '-') && (pcVar12[1] == 'i')) && (pcVar12[2] == 'n')) &&
             (pcVar12[3] == '\0')) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_0001f39c;
            local_148 = ppcVar16[1];
            ppcVar16 = ppcVar16 + 1;
          }
          else {
            iVar5 = strcmp(pcVar12,"-out");
            if (iVar5 == 0) {
              param_1 = param_1 + -1;
              if (param_1 == 0) goto LAB_0001f39c;
              local_140 = ppcVar16[1];
              ppcVar16 = ppcVar16 + 1;
            }
            else {
              iVar5 = strcmp(pcVar12,"-CApath");
              if (iVar5 == 0) {
                param_1 = param_1 + -1;
                if (param_1 == 0) goto LAB_0001f39c;
                local_134 = ppcVar16[1];
                v = (X509_STORE *)0x1;
                ppcVar16 = ppcVar16 + 1;
              }
              else {
                iVar5 = strcmp(pcVar12,"-CAfile");
                if (iVar5 == 0) {
                  param_1 = param_1 + -1;
                  if (param_1 == 0) goto LAB_0001f39c;
                  local_12c = ppcVar16[1];
                  v = (X509_STORE *)0x1;
                  ppcVar16 = ppcVar16 + 1;
                }
                else {
                  iVar5 = strcmp(pcVar12,"-verify");
                  if (iVar5 == 0) {
                    v = (X509_STORE *)0x1;
                  }
                  else {
                    iVar5 = strcmp(pcVar12,"-text");
                    if (iVar5 == 0) {
                      bVar3 = true;
                    }
                    else {
                      iVar5 = strcmp(pcVar12,"-hash");
                      if (iVar5 == 0) {
                        local_130 = local_130 + 1;
                        local_128 = local_130;
                      }
                      else {
                        iVar5 = strcmp(pcVar12,"-nameopt");
                        if (iVar5 == 0) {
                          param_1 = param_1 + -1;
                          if (param_1 != 0) {
                            iVar5 = set_name_ex(&local_104,ppcVar16[1]);
                            ppcVar16 = ppcVar16 + 1;
                            if (iVar5 != 0) goto LAB_0001f0dc;
                          }
                          goto LAB_0001f39c;
                        }
                        iVar5 = strcmp(pcVar12,"-issuer");
                        if (iVar5 == 0) {
                          local_130 = local_130 + 1;
                          local_120 = local_130;
                        }
                        else {
                          iVar5 = strcmp(pcVar12,"-lastupdate");
                          if (iVar5 == 0) {
                            local_130 = local_130 + 1;
                            local_118 = local_130;
                          }
                          else {
                            iVar5 = strcmp(pcVar12,"-nextupdate");
                            if (iVar5 == 0) {
                              local_130 = local_130 + 1;
                              local_114 = local_130;
                            }
                            else {
                              iVar5 = strcmp(pcVar12,"-noout");
                              if (iVar5 == 0) {
                                local_130 = local_130 + 1;
                                local_11c = local_130;
                              }
                              else {
                                iVar5 = strcmp(pcVar12,"-fingerprint");
                                if (iVar5 == 0) {
                                  local_130 = local_130 + 1;
                                  local_110 = local_130;
                                }
                                else {
                                  iVar5 = strcmp(pcVar12,"-crlnumber");
                                  if (iVar5 == 0) {
                                    local_130 = local_130 + 1;
                                    local_10c = local_130;
                                  }
                                  else {
                                    local_138 = EVP_get_digestbyname(pcVar12 + 1);
                                    if (local_138 == (EVP_MD *)0x0) {
                                      BIO_printf(bio_err,"unknown option %s\n",*ppcVar16);
                                      goto LAB_0001f39c;
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
LAB_0001f0dc:
          param_1 = param_1 + -1;
          ppcVar16 = ppcVar16 + 1;
          if (param_1 < 1) break;
          goto LAB_0001f0e8;
        }
        if (param_1 == 1) goto LAB_0001f39c;
        param_1 = param_1 + -2;
        local_144 = str2fmt(ppcVar16[1]);
        ppcVar16 = ppcVar16 + 2;
      } while (0 < param_1);
    }
    ERR_load_crypto_strings();
    pBVar6 = BIO_s_file();
    pBVar7 = BIO_new(pBVar6);
    if (pBVar7 == (BIO *)0x0) {
LAB_0001f53c:
      ERR_print_errors(bio_err);
    }
    else {
      if (local_148 == (char *)0x0) {
        BIO_ctrl(pBVar7,0x6a,0,stdin);
LAB_0001f164:
        if (iVar4 == 1) {
          a = d2i_X509_CRL_bio(pBVar7,(X509_CRL **)0x0);
        }
        else {
          if (iVar4 != 3) {
            BIO_printf(bio_err,"bad input format specified for input crl\n");
            goto LAB_0001f290;
          }
          a = PEM_read_bio_X509_CRL(pBVar7,(X509_CRL **)0x0,(undefined1 *)0x0,(void *)0x0);
        }
        if (a != (X509_CRL *)0x0) {
          BIO_free(pBVar7);
          if (v == (X509_STORE *)0x0) {
LAB_0001f192:
            if (local_130 != 0) {
              iVar4 = 1;
              do {
                if (local_120 == iVar4) {
                  print_name(bio_out,"issuer=",a->crl->issuer,local_104);
                }
                if (local_10c == iVar4) {
                  a_00 = (ASN1_INTEGER *)X509_CRL_get_ext_d2i(a,0x58,(int *)0x0,(int *)0x0);
                  BIO_printf(bio_out,"crlNumber=");
                  if (a_00 == (ASN1_INTEGER *)0x0) {
                    BIO_puts(bio_out,"<NONE>");
                  }
                  else {
                    i2a_ASN1_INTEGER(bio_out,a_00);
                    ASN1_INTEGER_free(a_00);
                  }
                  BIO_printf(bio_out,"\n");
                }
                pBVar7 = bio_out;
                if (local_128 == iVar4) {
                  uVar10 = X509_NAME_hash(a->crl->issuer);
                  BIO_printf(pBVar7,"%08lx\n",uVar10);
                }
                if (local_118 == iVar4) {
                  BIO_printf(bio_out,"lastUpdate=");
                  ASN1_TIME_print(bio_out,a->crl->lastUpdate);
                  BIO_printf(bio_out,"\n");
                }
                if (local_114 == iVar4) {
                  BIO_printf(bio_out,"nextUpdate=");
                  a_01 = a->crl->nextUpdate;
                  if (a_01 == (ASN1_TIME *)0x0) {
                    BIO_printf(bio_out,"NONE");
                  }
                  else {
                    ASN1_TIME_print(bio_out,a_01);
                  }
                  BIO_printf(bio_out,"\n");
                }
                if (local_110 == iVar4) {
                  pBVar7 = (BIO *)X509_CRL_digest(a,local_138,local_6c,&local_100);
                  bio = bio_out;
                  if (pBVar7 == (BIO *)0x0) {
                    uVar15 = 1;
                    BIO_printf(bio_err,"out of memory\n");
                    goto LAB_0001f258;
                  }
                  iVar5 = EVP_MD_type(local_138);
                  pcVar12 = OBJ_nid2sn(iVar5);
                  BIO_printf(bio,"%s Fingerprint=",pcVar12);
                  if (0 < (int)local_100) {
                    uVar14 = 0;
                    do {
                      pbVar2 = local_6c + uVar14;
                      uVar14 = uVar14 + 1;
                      if (local_100 == uVar14) {
                        uVar15 = 10;
                      }
                      else {
                        uVar15 = 0x3a;
                      }
                      BIO_printf(bio_out,"%02X%c",(uint)*pbVar2,uVar15);
                    } while ((int)uVar14 < (int)local_100);
                  }
                }
                iVar4 = iVar4 + 1;
              } while (iVar4 <= local_130);
            }
            pBVar6 = BIO_s_file();
            pBVar7 = BIO_new(pBVar6);
            if (pBVar7 == (BIO *)0x0) {
              uVar15 = 1;
              ERR_print_errors(bio_err);
            }
            else {
              if (local_140 == (char *)0x0) {
                BIO_ctrl(pBVar7,0x6a,0,stdout);
              }
              else {
                lVar8 = BIO_ctrl(pBVar7,0x6c,5,local_140);
                if (lVar8 < 1) {
                  uVar15 = 1;
                  perror(local_140);
                  goto LAB_0001f258;
                }
              }
              if (bVar3) {
                X509_CRL_print(pBVar7,a);
              }
              if (local_11c == 0) {
                if (local_144 == 1) {
                  iVar4 = i2d_X509_CRL_bio(pBVar7,a);
                }
                else {
                  if (local_144 != 3) {
                    uVar15 = 1;
                    BIO_printf(bio_err,"bad output format specified for outfile\n");
                    goto LAB_0001f258;
                  }
                  iVar4 = PEM_write_bio_X509_CRL(pBVar7,a);
                }
                if (iVar4 == 0) {
                  uVar15 = 1;
                  BIO_printf(bio_err,"unable to write CRL\n");
                  goto LAB_0001f258;
                }
              }
              uVar15 = 0;
            }
          }
          else {
            v = X509_STORE_new();
            pXVar9 = X509_LOOKUP_file();
            pBVar7 = (BIO *)X509_STORE_add_lookup(v,pXVar9);
            if (pBVar7 != (BIO *)0x0) {
              iVar4 = X509_LOOKUP_ctrl((X509_LOOKUP *)pBVar7,1,local_12c,1,(char **)0x0);
              if (iVar4 == 0) {
                X509_LOOKUP_ctrl((X509_LOOKUP *)pBVar7,1,(char *)0x0,3,(char **)0x0);
              }
              pXVar9 = X509_LOOKUP_hash_dir();
              pBVar7 = (BIO *)X509_STORE_add_lookup(v,pXVar9);
              if (pBVar7 != (BIO *)0x0) {
                iVar4 = X509_LOOKUP_ctrl((X509_LOOKUP *)pBVar7,2,local_134,1,(char **)0x0);
                if (iVar4 == 0) {
                  X509_LOOKUP_ctrl((X509_LOOKUP *)pBVar7,2,(char *)0x0,3,(char **)0x0);
                }
                ERR_clear_error();
                pBVar7 = (BIO *)X509_STORE_CTX_init(&XStack_f4,v,(X509 *)0x0,(stack_st_X509 *)0x0);
                if (pBVar7 == (BIO *)0x0) {
                  uVar15 = 1;
                  BIO_printf(bio_err,"Error initialising X509 store\n");
                }
                else {
                  iVar4 = X509_STORE_get_by_subject(&XStack_f4,1,a->crl->issuer,&XStack_fc);
                  if (iVar4 < 1) {
                    pBVar7 = (BIO *)0x0;
                    BIO_printf(bio_err,"Error getting CRL issuer certificate\n");
                    uVar15 = 1;
                  }
                  else {
                    pBVar7 = (BIO *)X509_get_pubkey(XStack_fc.data.x509);
                    X509_OBJECT_free_contents(&XStack_fc);
                    if (pBVar7 != (BIO *)0x0) {
                      iVar4 = X509_CRL_verify(a,(EVP_PKEY *)pBVar7);
                      EVP_PKEY_free((EVP_PKEY *)pBVar7);
                      if (-1 < iVar4) {
                        if (iVar4 == 0) {
                          pcVar12 = "verify failure\n";
                        }
                        else {
                          pcVar12 = "verify OK\n";
                        }
                        BIO_printf(bio_err,pcVar12);
                        goto LAB_0001f192;
                      }
                      pBVar7 = (BIO *)0x0;
                      goto LAB_0001f52a;
                    }
                    uVar15 = 1;
                    BIO_printf(bio_err,"Error getting CRL issuer public key\n");
                  }
                }
                goto LAB_0001f258;
              }
            }
LAB_0001f52a:
            uVar15 = 1;
          }
LAB_0001f258:
          BIO_free_all(pBVar7);
          BIO_free_all(bio_out);
          bio_out = (BIO *)0x0;
          X509_CRL_free(a);
          if (v != (X509_STORE *)0x0) {
            X509_STORE_CTX_cleanup(&XStack_f4);
            X509_STORE_free(v);
          }
          goto LAB_0001f2b2;
        }
        BIO_printf(bio_err,"unable to load CRL\n");
        goto LAB_0001f53c;
      }
      lVar8 = BIO_ctrl(pBVar7,0x6c,3,local_148);
      if (0 < lVar8) goto LAB_0001f164;
      perror(local_148);
    }
LAB_0001f290:
    BIO_free(pBVar7);
  }
LAB_0001f296:
  uVar15 = 1;
  BIO_free_all((BIO *)0x0);
  BIO_free_all(bio_out);
  bio_out = (BIO *)0x0;
  X509_CRL_free((X509_CRL *)0x0);
LAB_0001f2b2:
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar15);
  }
  return;
}

