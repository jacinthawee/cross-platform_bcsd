
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void pkcs12_main(undefined4 param_1,int param_2)

{
  X509 **ppXVar1;
  bool bVar2;
  BIO *pBVar3;
  X509 *pXVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uchar *name;
  X509 *md_type;
  ASN1_OBJECT *a;
  _STACK *p_Var8;
  void *pvVar9;
  char *pcVar10;
  int *piVar11;
  long lVar12;
  uint uVar13;
  X509 *bp;
  X509 *st;
  X509 *pXVar14;
  undefined4 uVar15;
  X509 *local_198;
  X509 *local_194;
  X509 *local_190;
  X509 *local_18c;
  X509 *local_188;
  int local_184;
  X509 *local_180;
  X509 *local_17c;
  X509 *local_178;
  X509 *local_174;
  X509 *local_170;
  X509 *local_16c;
  X509 *local_168;
  X509 *local_164;
  X509 *local_160;
  X509 *local_15c;
  X509 *local_158;
  X509 *local_154;
  X509 *local_150;
  X509 *local_14c;
  X509 *local_148;
  int local_144;
  int local_140;
  X509 *local_13c;
  X509 *local_138;
  int local_12c;
  int local_128;
  char *local_124;
  char *local_120;
  X509_STORE_CTX XStack_11c;
  char acStack_94 [52];
  char acStack_60 [52];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  local_128 = 0x92;
  local_124 = (char *)0x0;
  local_120 = (char *)0x0;
  signal(0xd,(__sighandler_t)0x1);
  enc = EVP_des_ede3_cbc();
  if (bio_err == (BIO *)0x0) {
    bio_err = BIO_new_fp(stderr,0);
  }
  pXVar4 = (X509 *)load_config(bio_err,0);
  bp = pXVar4;
  st = pXVar4;
  local_17c = pXVar4;
  if (pXVar4 != (X509 *)0x0) {
    pXVar4 = *(X509 **)(param_2 + 4);
    param_2 = param_2 + 4;
    local_12c = 0x95;
    if (pXVar4 != (X509 *)0x0) {
      pXVar14 = (X509 *)0x0;
      local_184 = 0x800;
      st = (X509 *)0x0;
      local_138 = (X509 *)0x0;
      bVar2 = false;
      local_13c = (X509 *)0x0;
      local_198 = (X509 *)0x0;
      local_158 = (X509 *)0x0;
      local_17c = (X509 *)0x0;
      local_18c = (X509 *)0x0;
      local_16c = (X509 *)0x0;
      local_178 = (X509 *)0x0;
      local_168 = (X509 *)0x0;
      local_180 = (X509 *)0x0;
      local_160 = (X509 *)0x0;
      local_164 = (X509 *)0x0;
      local_190 = (X509 *)0x0;
      local_14c = (X509 *)0x0;
      local_150 = (X509 *)0x0;
      local_148 = (X509 *)0x0;
      local_15c = (X509 *)0x0;
      local_154 = (X509 *)0x0;
      local_170 = (X509 *)0x0;
      local_174 = (X509 *)0x0;
      local_144 = 0x800;
      local_140 = 1;
      bp = pXVar4;
      do {
        iVar6 = local_140;
        if (*(char *)&bp->cert_info != '-') goto LAB_00038452;
        iVar5 = strcmp((char *)bp,"-nokeys");
        if (iVar5 == 0) {
          bp = *(X509 **)(param_2 + 4);
          local_198 = (X509 *)((uint)local_198 | 1);
        }
        else {
          iVar5 = strcmp((char *)bp,"-keyex");
          if (iVar5 == 0) {
            local_180 = (X509 *)&DAT_00000010;
          }
          else {
            iVar5 = strcmp((char *)bp,"-keysig");
            if (iVar5 == 0) {
              local_180 = (X509 *)0x80;
            }
            else {
              iVar5 = strcmp((char *)bp,"-nocerts");
              if (iVar5 == 0) {
                local_198 = (X509 *)((uint)local_198 | 2);
              }
              else {
                iVar5 = strcmp((char *)bp,"-clcerts");
                if (iVar5 == 0) {
                  local_198 = (X509 *)((uint)local_198 | 8);
                }
                else {
                  iVar5 = strcmp((char *)bp,"-cacerts");
                  if (iVar5 == 0) {
                    local_198 = (X509 *)((uint)local_198 | 0x10);
                  }
                  else {
                    iVar5 = strcmp((char *)bp,"-noout");
                    if (iVar5 == 0) {
                      local_198 = (X509 *)((uint)local_198 | 3);
                    }
                    else {
                      iVar5 = strcmp((char *)bp,"-info");
                      if (iVar5 == 0) {
                        local_198 = (X509 *)((uint)local_198 | 4);
                      }
                      else {
                        iVar5 = strcmp((char *)bp,"-chain");
                        if (iVar5 == 0) {
                          local_164 = (X509 *)0x1;
                        }
                        else {
                          iVar5 = strcmp((char *)bp,"-twopass");
                          if (iVar5 == 0) {
                            local_160 = (X509 *)0x1;
                          }
                          else {
                            iVar6 = strcmp((char *)bp,"-nomacver");
                            if (iVar6 != 0) {
                              iVar6 = strcmp((char *)bp,"-descert");
                              if (iVar6 == 0) {
                                local_12c = 0x92;
                                iVar6 = local_140;
                              }
                              else {
                                iVar6 = strcmp((char *)bp,"-export");
                                if (iVar6 == 0) {
                                  local_190 = (X509 *)0x1;
                                  iVar6 = local_140;
                                }
                                else {
                                  iVar6 = strcmp((char *)bp,"-des");
                                  if (iVar6 == 0) {
                                    enc = EVP_des_cbc();
                                    iVar6 = local_140;
                                  }
                                  else {
                                    iVar6 = strcmp((char *)bp,"-des3");
                                    if (iVar6 == 0) {
                                      enc = EVP_des_ede3_cbc();
                                      iVar6 = local_140;
                                    }
                                    else {
                                      iVar6 = strcmp((char *)bp,"-idea");
                                      if (iVar6 == 0) {
                                        enc = EVP_idea_cbc();
                                        iVar6 = local_140;
                                      }
                                      else {
                                        iVar6 = strcmp((char *)bp,"-seed");
                                        if (iVar6 == 0) {
                                          enc = EVP_seed_cbc();
                                          iVar6 = local_140;
                                        }
                                        else {
                                          iVar6 = strcmp((char *)bp,"-aes128");
                                          if (iVar6 == 0) {
                                            enc = EVP_aes_128_cbc();
                                            iVar6 = local_140;
                                          }
                                          else {
                                            iVar6 = strcmp((char *)bp,"-aes192");
                                            if (iVar6 == 0) {
                                              enc = EVP_aes_192_cbc();
                                              iVar6 = local_140;
                                            }
                                            else {
                                              iVar6 = strcmp((char *)bp,"-aes256");
                                              if (iVar6 == 0) {
                                                enc = EVP_aes_256_cbc();
                                                iVar6 = local_140;
                                              }
                                              else {
                                                iVar6 = strcmp((char *)bp,"-camellia128");
                                                if (iVar6 == 0) {
                                                  enc = EVP_camellia_128_cbc();
                                                  iVar6 = local_140;
                                                }
                                                else {
                                                  iVar6 = strcmp((char *)bp,"-camellia192");
                                                  if (iVar6 == 0) {
                                                    enc = EVP_camellia_192_cbc();
                                                    iVar6 = local_140;
                                                  }
                                                  else {
                                                    iVar6 = strcmp((char *)bp,"-camellia256");
                                                    if (iVar6 == 0) {
                                                      enc = EVP_camellia_256_cbc();
                                                      iVar6 = local_140;
                                                    }
                                                    else {
                                                      iVar6 = strcmp((char *)bp,"-noiter");
                                                      if (iVar6 == 0) {
                                                        local_144 = 1;
                                                        iVar6 = local_140;
                                                      }
                                                      else {
                                                        iVar6 = strcmp((char *)bp,"-maciter");
                                                        if (iVar6 == 0) {
                                                          local_184 = 0x800;
                                                          iVar6 = local_140;
                                                        }
                                                        else {
                                                          iVar6 = strcmp((char *)bp,"-nomaciter");
                                                          if (iVar6 == 0) {
                                                            local_184 = 1;
                                                            iVar6 = local_140;
                                                          }
                                                          else {
                                                            iVar6 = strcmp((char *)bp,"-nomac");
                                                            if (iVar6 == 0) {
                                                              local_184 = -1;
                                                              iVar6 = local_140;
                                                            }
                                                            else {
                                                              iVar6 = strcmp((char *)bp,"-macalg");
                                                              if (iVar6 == 0) {
                                                                ppXVar1 = (X509 **)(param_2 + 4);
                                                                if (*ppXVar1 == (X509 *)0x0)
                                                                goto LAB_00038452;
                                                                param_2 = param_2 + 4;
                                                                local_158 = *ppXVar1;
                                                                iVar6 = local_140;
                                                              }
                                                              else {
                                                                iVar6 = strcmp((char *)bp,"-nodes");
                                                                if (iVar6 == 0) {
                                                                  enc = (EVP_CIPHER *)0x0;
                                                                  iVar6 = local_140;
                                                                }
                                                                else {
                                                                  iVar6 = strcmp((char *)bp,
                                                                                 "-certpbe");
                                                                  if (iVar6 == 0) {
                                                                    piVar11 = &local_12c;
                                                                  }
                                                                  else {
                                                                    iVar6 = strcmp((char *)bp,
                                                                                   "-keypbe");
                                                                    if (iVar6 != 0) {
                                                                      iVar6 = strcmp((char *)bp,
                                                                                     "-rand");
                                                                      if (iVar6 == 0) {
                                                                        ppXVar1 = (X509 **)(param_2 
                                                  + 4);
                                                  if (*ppXVar1 == (X509 *)0x0) goto LAB_00038452;
                                                  param_2 = param_2 + 4;
                                                  local_17c = *ppXVar1;
                                                  iVar6 = local_140;
                                                  }
                                                  else {
                                                    iVar6 = strcmp((char *)bp,"-inkey");
                                                    if (iVar6 == 0) {
                                                      ppXVar1 = (X509 **)(param_2 + 4);
                                                      if (*ppXVar1 == (X509 *)0x0)
                                                      goto LAB_00038452;
                                                      param_2 = param_2 + 4;
                                                      local_154 = *ppXVar1;
                                                      iVar6 = local_140;
                                                    }
                                                    else {
                                                      iVar6 = strcmp((char *)bp,"-certfile");
                                                      if (iVar6 == 0) {
                                                        ppXVar1 = (X509 **)(param_2 + 4);
                                                        if (*ppXVar1 == (X509 *)0x0)
                                                        goto LAB_00038452;
                                                        param_2 = param_2 + 4;
                                                        local_15c = *ppXVar1;
                                                        iVar6 = local_140;
                                                      }
                                                      else {
                                                        iVar6 = strcmp((char *)bp,"-name");
                                                        if (iVar6 == 0) {
                                                          ppXVar1 = (X509 **)(param_2 + 4);
                                                          if (*ppXVar1 == (X509 *)0x0)
                                                          goto LAB_00038452;
                                                          param_2 = param_2 + 4;
                                                          local_148 = *ppXVar1;
                                                          iVar6 = local_140;
                                                        }
                                                        else {
                                                          iVar6 = strcmp((char *)bp,"-LMK");
                                                          if (iVar6 == 0) {
                                                            local_14c = (X509 *)0x1;
                                                            iVar6 = local_140;
                                                          }
                                                          else {
                                                            iVar6 = strcmp((char *)bp,"-CSP");
                                                            if (iVar6 == 0) {
                                                              ppXVar1 = (X509 **)(param_2 + 4);
                                                              if (*ppXVar1 == (X509 *)0x0)
                                                              goto LAB_00038452;
                                                              param_2 = param_2 + 4;
                                                              local_150 = *ppXVar1;
                                                              iVar6 = local_140;
                                                            }
                                                            else {
                                                              iVar6 = strcmp((char *)bp,"-caname");
                                                              if (iVar6 == 0) {
                                                                if (*(int *)(param_2 + 4) == 0)
                                                                goto LAB_00038452;
                                                                if (st == (X509 *)0x0) {
                                                                  st = (X509 *)sk_new_null();
                                                                }
                                                                sk_push((_STACK *)st,
                                                                        *(void **)(param_2 + 4));
                                                                param_2 = param_2 + 4;
                                                                iVar6 = local_140;
                                                              }
                                                              else if (((*(char *)((int)&bp->
                                                  cert_info + 1) == 'i') &&
                                                  (*(char *)((int)&bp->cert_info + 2) == 'n')) &&
                                                  (*(char *)((int)&bp->cert_info + 3) == '\0')) {
                                                    ppXVar1 = (X509 **)(param_2 + 4);
                                                    if (*ppXVar1 == (X509 *)0x0) goto LAB_00038452;
                                                    param_2 = param_2 + 4;
                                                    local_174 = *ppXVar1;
                                                    iVar6 = local_140;
                                                  }
                                                  else {
                                                    iVar6 = strcmp((char *)bp,"-out");
                                                    if (iVar6 == 0) {
                                                      ppXVar1 = (X509 **)(param_2 + 4);
                                                      if (*ppXVar1 == (X509 *)0x0)
                                                      goto LAB_00038452;
                                                      param_2 = param_2 + 4;
                                                      local_170 = *ppXVar1;
                                                      iVar6 = local_140;
                                                    }
                                                    else {
                                                      iVar6 = strcmp((char *)bp,"-passin");
                                                      if (iVar6 == 0) {
                                                        ppXVar1 = (X509 **)(param_2 + 4);
                                                        if (*ppXVar1 == (X509 *)0x0)
                                                        goto LAB_00038452;
                                                        param_2 = param_2 + 4;
                                                        local_178 = *ppXVar1;
                                                        iVar6 = local_140;
                                                      }
                                                      else {
                                                        iVar6 = strcmp((char *)bp,"-passout");
                                                        if (iVar6 == 0) {
                                                          ppXVar1 = (X509 **)(param_2 + 4);
                                                          if (*ppXVar1 == (X509 *)0x0)
                                                          goto LAB_00038452;
                                                          param_2 = param_2 + 4;
                                                          local_16c = *ppXVar1;
                                                          iVar6 = local_140;
                                                        }
                                                        else {
                                                          iVar6 = strcmp((char *)bp,"-password");
                                                          if (iVar6 == 0) {
                                                            ppXVar1 = (X509 **)(param_2 + 4);
                                                            if (*ppXVar1 == (X509 *)0x0)
                                                            goto LAB_00038452;
                                                            param_2 = param_2 + 4;
                                                            local_168 = (X509 *)0x1;
                                                            local_18c = *ppXVar1;
                                                            iVar6 = local_140;
                                                          }
                                                          else {
                                                            iVar6 = strcmp((char *)bp,"-CApath");
                                                            if (iVar6 == 0) {
                                                              ppXVar1 = (X509 **)(param_2 + 4);
                                                              if (*ppXVar1 == (X509 *)0x0)
                                                              goto LAB_00038452;
                                                              param_2 = param_2 + 4;
                                                              iVar6 = local_140;
                                                              local_13c = *ppXVar1;
                                                            }
                                                            else {
                                                              iVar6 = strcmp((char *)bp,"-CAfile");
                                                              if (iVar6 == 0) {
                                                                ppXVar1 = (X509 **)(param_2 + 4);
                                                                if (*ppXVar1 == (X509 *)0x0) {
LAB_00038452:
                                                                  bVar2 = true;
                                                                  iVar6 = local_140;
                                                                }
                                                                else {
                                                                  param_2 = param_2 + 4;
                                                                  iVar6 = local_140;
                                                                  local_138 = *ppXVar1;
                                                                }
                                                              }
                                                              else {
                                                                iVar6 = strcmp((char *)bp,"-engine")
                                                                ;
                                                                if ((iVar6 != 0) ||
                                                                   (ppXVar1 = (X509 **)(param_2 + 4)
                                                                   , *ppXVar1 == (X509 *)0x0))
                                                                goto LAB_00038452;
                                                                param_2 = param_2 + 4;
                                                                pXVar14 = *ppXVar1;
                                                                iVar6 = local_140;
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
                                                  goto LAB_00038456;
                                                  }
                                                  piVar11 = &local_128;
                                                  }
                                                  iVar5 = set_pbe_isra_0(piVar11,*(undefined4 *)
                                                                                  (param_2 + 4));
                                                  param_2 = param_2 + 4;
                                                  iVar6 = local_140;
                                                  if (iVar5 == 0) {
                                                    bVar2 = true;
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
          }
LAB_00038456:
          local_140 = iVar6;
          bp = *(X509 **)(param_2 + 4);
        }
        if (bp == (X509 *)0x0) goto LAB_00038484;
        param_2 = param_2 + 4;
      } while( true );
    }
    local_184 = 0x800;
    local_144 = 0x800;
    local_140 = 1;
    st = pXVar4;
    pXVar14 = pXVar4;
    local_198 = pXVar4;
    local_194 = pXVar4;
    local_190 = pXVar4;
    local_18c = pXVar4;
    local_188 = pXVar4;
    local_180 = pXVar4;
    local_17c = pXVar4;
    local_178 = pXVar4;
    local_174 = pXVar4;
    local_170 = pXVar4;
    local_16c = pXVar4;
    local_168 = pXVar4;
    local_164 = pXVar4;
    local_160 = pXVar4;
    local_15c = pXVar4;
    local_158 = pXVar4;
    local_154 = pXVar4;
    local_150 = pXVar4;
    local_14c = pXVar4;
    local_148 = pXVar4;
    local_13c = pXVar4;
    local_138 = pXVar4;
    goto LAB_0003882e;
  }
  goto LAB_0003879a;
LAB_00038484:
  local_194 = local_190;
  if (local_190 != (X509 *)0x0) {
    local_194 = (X509 *)0x1;
  }
  local_188 = local_17c;
  if (local_17c != (X509 *)0x0) {
    local_188 = (X509 *)0x1;
  }
  pXVar4 = (X509 *)((uint)local_194 | (uint)local_188);
  if (bVar2) {
    BIO_printf(bio_err,"Usage: pkcs12 [options]\n");
    BIO_printf(bio_err,"where options are\n");
    BIO_printf(bio_err,"-export       output PKCS12 file\n");
    BIO_printf(bio_err,"-chain        add certificate chain\n");
    BIO_printf(bio_err,"-inkey file   private key if not infile\n");
    BIO_printf(bio_err,"-certfile f   add all certs in f\n");
    BIO_printf(bio_err,"-CApath arg   - PEM format directory of CA\'s\n");
    BIO_printf(bio_err,"-CAfile arg   - PEM format file of CA\'s\n");
    BIO_printf(bio_err,"-name \"name\"  use name as friendly name\n");
    BIO_printf(bio_err,"-caname \"nm\"  use nm as CA friendly name (can be used more than once).\n")
    ;
    BIO_printf(bio_err,"-in  infile   input filename\n");
    BIO_printf(bio_err,"-out outfile  output filename\n");
    BIO_printf(bio_err,"-noout        don\'t output anything, just verify.\n");
    BIO_printf(bio_err,"-nomacver     don\'t verify MAC.\n");
    BIO_printf(bio_err,"-nocerts      don\'t output certificates.\n");
    BIO_printf(bio_err,"-clcerts      only output client certificates.\n");
    BIO_printf(bio_err,"-cacerts      only output CA certificates.\n");
    BIO_printf(bio_err,"-nokeys       don\'t output private keys.\n");
    BIO_printf(bio_err,"-info         give info about PKCS#12 structure.\n");
    BIO_printf(bio_err,"-des          encrypt private keys with DES\n");
    BIO_printf(bio_err,"-des3         encrypt private keys with triple DES (default)\n");
    BIO_printf(bio_err,"-idea         encrypt private keys with idea\n");
    BIO_printf(bio_err,"-seed         encrypt private keys with seed\n");
    BIO_printf(bio_err,"-aes128, -aes192, -aes256\n");
    BIO_printf(bio_err,"              encrypt PEM output with cbc aes\n");
    BIO_printf(bio_err,"-camellia128, -camellia192, -camellia256\n");
    BIO_printf(bio_err,"              encrypt PEM output with cbc camellia\n");
    BIO_printf(bio_err,"-nodes        don\'t encrypt private keys\n");
    BIO_printf(bio_err,"-noiter       don\'t use encryption iteration\n");
    BIO_printf(bio_err,"-nomaciter    don\'t use MAC iteration\n");
    BIO_printf(bio_err,"-maciter      use MAC iteration\n");
    BIO_printf(bio_err,"-nomac        don\'t generate MAC\n");
    BIO_printf(bio_err,"-twopass      separate MAC, encryption passwords\n");
    BIO_printf(bio_err,
               "-descert      encrypt PKCS#12 certificates with triple DES (default RC2-40)\n");
    BIO_printf(bio_err,"-certpbe alg  specify certificate PBE algorithm (default RC2-40)\n");
    BIO_printf(bio_err,"-keypbe alg   specify private key PBE algorithm (default 3DES)\n");
    BIO_printf(bio_err,"-macalg alg   digest algorithm used in MAC (default SHA1)\n");
    BIO_printf(bio_err,"-keyex        set MS key exchange type\n");
    BIO_printf(bio_err,"-keysig       set MS key signature type\n");
    BIO_printf(bio_err,"-password p   set import/export password source\n");
    BIO_printf(bio_err,"-passin p     input file pass phrase source\n");
    BIO_printf(bio_err,"-passout p    output file pass phrase source\n");
    BIO_printf(bio_err,"-engine e     use engine e, possibly a hardware device.\n");
    BIO_printf(bio_err,"-rand file%cfile%c...\n",0x3a,0x3a);
    BIO_printf(bio_err,"              load the file (or the files in the directory) into\n");
    BIO_printf(bio_err,"              the random number generator\n");
    BIO_printf(bio_err,"-CSP name     Microsoft CSP name\n");
    BIO_printf(bio_err,"-LMK          Add local machine keyset attribute to private key\n");
    uVar15 = 1;
    local_17c = bp;
    local_188 = pXVar4;
joined_r0x00038756:
    if (local_188 == (X509 *)0x0) goto LAB_00038758;
  }
  else {
LAB_0003882e:
    uVar15 = setup_engine(bio_err,pXVar14,0);
    if (local_18c != (X509 *)0x0) {
      if (local_190 == (X509 *)0x0) {
        iVar6 = app_passwd(bio_err,local_18c,local_16c,&local_124,&local_120);
        local_18c = (X509 *)local_124;
        if (iVar6 != 0) goto LAB_00038894;
      }
      else {
        iVar6 = app_passwd(bio_err,local_178,local_18c,&local_124,&local_120);
        if (iVar6 != 0) goto LAB_00038890;
      }
LAB_0003885e:
      local_17c = (X509 *)0x0;
      BIO_printf(bio_err,"Error getting passwords\n");
      bp = local_17c;
LAB_0003879a:
      uVar15 = 1;
      local_188 = pXVar4;
      goto joined_r0x00038756;
    }
    iVar6 = app_passwd(bio_err,local_178,local_16c,&local_124,&local_120);
    if (iVar6 == 0) goto LAB_0003885e;
    local_18c = (X509 *)local_124;
    if (local_190 != (X509 *)0x0) {
LAB_00038890:
      local_18c = (X509 *)local_120;
    }
LAB_00038894:
    if (local_18c == (X509 *)0x0) {
      local_178 = (X509 *)acStack_60;
      local_18c = (X509 *)acStack_94;
    }
    else {
      local_168 = (X509 *)0x1;
      local_178 = local_18c;
    }
    if ((pXVar4 != (X509 *)0x0) &&
       (app_RAND_load_file(0,bio_err,local_188), pBVar3 = bio_err, local_188 != (X509 *)0x0)) {
      uVar7 = app_RAND_load_files(local_17c);
      BIO_printf(pBVar3,"%ld semi-random bytes loaded\n",uVar7);
    }
    ERR_load_crypto_strings();
    if (local_174 == (X509 *)0x0) {
      bp = (X509 *)BIO_new_fp(stdin,0);
    }
    else {
      bp = (X509 *)BIO_new_file((char *)local_174,"rb");
    }
    if (bp == (X509 *)0x0) {
      pXVar14 = (X509 *)&UNK_001336b0;
      if (local_174 != (X509 *)0x0) {
        pXVar14 = local_174;
      }
      BIO_printf(bio_err,"Error opening input file %s\n",pXVar14);
      perror((char *)local_174);
      local_17c = bp;
      goto LAB_0003879a;
    }
    if (local_170 == (X509 *)0x0) {
      local_17c = (X509 *)BIO_new_fp(stdout,0);
    }
    else {
      local_17c = (X509 *)BIO_new_file((char *)local_170,"wb");
    }
    if (local_17c == (X509 *)0x0) {
      pXVar14 = (X509 *)"<stdout>";
      if (local_170 != (X509 *)0x0) {
        pXVar14 = local_170;
      }
      BIO_printf(bio_err,"Error opening output file %s\n",pXVar14);
      perror((char *)local_170);
      goto LAB_0003879a;
    }
    if ((local_160 != (X509 *)0x0) &&
       (iVar6 = EVP_read_pw_string(acStack_60,0x32,"Enter MAC Password:",(int)local_190), iVar6 != 0
       )) {
      BIO_printf(bio_err,"Can\'t read Password\n");
      goto LAB_0003879a;
    }
    if (local_194 == (X509 *)0x0) {
      pXVar14 = (X509 *)d2i_PKCS12_bio((BIO *)bp,(PKCS12 **)0x0);
      if (pXVar14 == (X509 *)0x0) {
        ERR_print_errors(bio_err);
        pXVar4 = local_188;
        goto LAB_0003879a;
      }
      if ((local_168 == (X509 *)0x0) &&
         (iVar6 = EVP_read_pw_string(acStack_94,0x32,"Enter Import Password:",0), iVar6 != 0)) {
        uVar15 = 1;
        BIO_printf(bio_err,"Can\'t read Password\n");
      }
      else {
        if (local_160 == (X509 *)0x0) {
          BUF_strlcpy(acStack_60,acStack_94,0x32);
        }
        pBVar3 = bio_err;
        if (((int)local_198 << 0x1d < 0) && (pXVar14->sig_alg != (X509_ALGOR *)0x0)) {
          a = pXVar14->sig_alg[1].algorithm;
          lVar12 = 1;
          if (a != (ASN1_OBJECT *)0x0) {
            lVar12 = ASN1_INTEGER_get((ASN1_INTEGER *)a);
          }
          BIO_printf(pBVar3,"MAC Iteration %ld\n",lVar12);
        }
        if (local_140 == 0) {
LAB_00038c52:
          uVar15 = 0;
          iVar6 = dump_certs_keys_p12(local_17c,pXVar14,local_18c,0xffffffff,local_198,local_120);
          if (iVar6 != 0) goto LAB_00038b84;
          pcVar10 = "Error outputting keys and certificates\n";
        }
        else {
          if ((*(char *)local_178 == '\0') &&
             (iVar6 = PKCS12_verify_mac((PKCS12 *)pXVar14,(char *)0x0,0), iVar6 != 0)) {
            if (local_160 == (X509 *)0x0) {
              local_18c = (X509 *)0x0;
            }
LAB_00038c3c:
            BIO_printf(bio_err,"MAC verified OK\n");
            goto LAB_00038c52;
          }
          iVar6 = PKCS12_verify_mac((PKCS12 *)pXVar14,(char *)local_178,-1);
          if (iVar6 != 0) goto LAB_00038c3c;
          pcVar10 = "Mac verify error: invalid password?\n";
        }
        BIO_printf(bio_err,pcVar10);
        ERR_print_errors(bio_err);
        uVar15 = 1;
      }
LAB_00038b84:
      PKCS12_free((PKCS12 *)pXVar14);
      goto joined_r0x00038756;
    }
    if (((uint)local_198 & 3) == 3) {
      BIO_printf(bio_err,"Nothing to do!\n");
LAB_0003893e:
      uVar15 = 1;
    }
    else {
      pXVar14 = (X509 *)((uint)local_198 & 2);
      if (pXVar14 != (X509 *)0x0) {
        local_164 = (X509 *)0x0;
      }
      if ((int)local_198 << 0x1f < 0) {
        local_198 = (X509 *)0x0;
      }
      else {
        if (local_154 == (X509 *)0x0) {
          local_154 = local_174;
        }
        local_198 = (X509 *)load_key(bio_err,local_154,3,1,local_124,uVar15,"private key");
        if (local_198 == (X509 *)0x0) goto LAB_0003893e;
      }
      if (pXVar14 == (X509 *)0x0) {
        local_190 = (X509 *)load_certs(bio_err,local_174,3,0,uVar15,"certificates");
        if (local_190 == (X509 *)0x0) {
          uVar15 = 1;
          local_194 = pXVar14;
          goto LAB_00038b40;
        }
        local_194 = local_198;
        if (local_198 == (X509 *)0x0) goto LAB_000389f0;
        for (; iVar6 = sk_num((_STACK *)local_190), (int)pXVar14 < iVar6;
            pXVar14 = (X509 *)((int)&pXVar14->cert_info + 1)) {
          local_194 = (X509 *)sk_value((_STACK *)local_190,(int)pXVar14);
          iVar6 = X509_check_private_key(local_194,(EVP_PKEY *)local_198);
          if (iVar6 != 0) {
            X509_keyid_set1(local_194,(uchar *)0x0,0);
            X509_alias_set1(local_194,(uchar *)0x0,0);
            sk_delete((_STACK *)local_190,(int)pXVar14);
            if (local_194 != (X509 *)0x0) goto LAB_000389f0;
            break;
          }
        }
        uVar15 = 1;
        local_194 = (X509 *)0x0;
        BIO_printf(bio_err,"No certificate matches private key\n");
        pXVar14 = local_194;
LAB_00038b44:
        EVP_PKEY_free((EVP_PKEY *)local_198);
      }
      else {
        local_190 = (X509 *)0x0;
        local_194 = (X509 *)0x0;
LAB_000389f0:
        if (local_15c != (X509 *)0x0) {
          pXVar14 = (X509 *)load_certs(bio_err,local_15c,3,0,uVar15,"certificates from certfile");
          if (pXVar14 == (X509 *)0x0) {
            uVar15 = 1;
            goto LAB_00038b40;
          }
          while (iVar6 = sk_num((_STACK *)pXVar14), 0 < iVar6) {
            pvVar9 = sk_shift((_STACK *)pXVar14);
            sk_push((_STACK *)local_190,pvVar9);
          }
          sk_free((_STACK *)pXVar14);
        }
        if (local_164 == (X509 *)0x0) {
LAB_00038a46:
          for (iVar6 = 0; iVar5 = sk_num((_STACK *)st), iVar6 < iVar5; iVar6 = iVar6 + 1) {
            name = (uchar *)sk_value((_STACK *)st,iVar6);
            pXVar14 = (X509 *)sk_value((_STACK *)local_190,iVar6);
            X509_alias_set1(pXVar14,name,-1);
          }
          pXVar14 = local_198;
          if (local_198 != (X509 *)0x0) {
            pXVar14 = (X509 *)0x1;
          }
          if (local_150 != (X509 *)0x0 && local_198 != (X509 *)0x0) {
            EVP_PKEY_add1_attr_by_NID((EVP_PKEY *)local_198,0x1a1,0x1001,(uchar *)local_150,-1);
          }
          if (local_14c == (X509 *)0x0) {
            uVar13 = 0;
          }
          else {
            uVar13 = (uint)pXVar14 & 1;
          }
          if (uVar13 != 0) {
            EVP_PKEY_add1_attr_by_NID((EVP_PKEY *)local_198,0x358,0,(uchar *)0x0,-1);
          }
          if ((local_168 == (X509 *)0x0) &&
             (iVar6 = EVP_read_pw_string(acStack_94,0x32,"Enter Export Password:",1), iVar6 != 0)) {
            uVar15 = 1;
            BIO_printf(bio_err,"Can\'t read Password\n");
            pXVar14 = local_168;
          }
          else {
            if (local_160 == (X509 *)0x0) {
              BUF_strlcpy(acStack_60,acStack_94,0x32);
            }
            pXVar14 = (X509 *)PKCS12_create((char *)local_18c,(char *)local_148,
                                            (EVP_PKEY *)local_198,local_194,
                                            (stack_st_X509 *)local_190,local_128,local_12c,local_144
                                            ,-1,(int)local_180);
            if (pXVar14 == (X509 *)0x0) {
              uVar15 = 1;
              ERR_print_errors(bio_err);
            }
            else {
              md_type = local_158;
              if ((local_158 != (X509 *)0x0) &&
                 (md_type = (X509 *)EVP_get_digestbyname((char *)local_158), md_type == (X509 *)0x0)
                 ) {
                BIO_printf(bio_err,"Unknown digest algorithm %s\n",local_158);
              }
              if (local_184 != -1) {
                PKCS12_set_mac((PKCS12 *)pXVar14,(char *)local_178,-1,(uchar *)0x0,0,local_184,
                               (EVP_MD *)md_type);
              }
              i2d_PKCS12_bio((BIO *)local_17c,(PKCS12 *)pXVar14);
              uVar15 = 0;
            }
          }
        }
        else {
          pXVar14 = (X509 *)X509_STORE_new();
          if (pXVar14 == (X509 *)0x0) {
            uVar15 = 1;
            BIO_printf(bio_err,"Memory allocation error\n");
          }
          else {
            iVar6 = X509_STORE_load_locations
                              ((X509_STORE *)pXVar14,(char *)local_138,(char *)local_13c);
            if (iVar6 == 0) {
              X509_STORE_set_default_paths((X509_STORE *)pXVar14);
            }
            iVar6 = X509_STORE_CTX_init(&XStack_11c,(X509_STORE *)pXVar14,local_194,
                                        (stack_st_X509 *)0x0);
            if (iVar6 == 0) {
LAB_00038dc6:
              X509_STORE_free((X509_STORE *)pXVar14);
            }
            else {
              iVar6 = X509_verify_cert(&XStack_11c);
              if (0 < iVar6) {
                p_Var8 = (_STACK *)X509_STORE_CTX_get1_chain(&XStack_11c);
                X509_STORE_CTX_cleanup(&XStack_11c);
                X509_STORE_free((X509_STORE *)pXVar14);
                for (iVar6 = 1; iVar5 = sk_num(p_Var8), iVar6 < iVar5; iVar6 = iVar6 + 1) {
                  pvVar9 = sk_value(p_Var8,iVar6);
                  sk_push((_STACK *)local_190,pvVar9);
                }
                pXVar14 = (X509 *)sk_value(p_Var8,0);
                X509_free(pXVar14);
                sk_free(p_Var8);
                goto LAB_00038a46;
              }
              iVar6 = X509_STORE_CTX_get_error(&XStack_11c);
              if (iVar6 == 0) {
                X509_STORE_CTX_cleanup(&XStack_11c);
                goto LAB_00038dc6;
              }
              X509_STORE_CTX_cleanup(&XStack_11c);
              X509_STORE_free((X509_STORE *)pXVar14);
              pBVar3 = bio_err;
              if (iVar6 != 1) {
                pcVar10 = X509_verify_cert_error_string(iVar6);
                BIO_printf(pBVar3,"Error %s getting chain.\n",pcVar10);
                uVar15 = 1;
                pXVar14 = (X509 *)0x0;
                goto LAB_00038b40;
              }
            }
            uVar15 = 1;
            ERR_print_errors(bio_err);
            pXVar14 = (X509 *)0x0;
          }
        }
LAB_00038b40:
        if (local_198 != (X509 *)0x0) goto LAB_00038b44;
      }
      if (local_190 != (X509 *)0x0) {
        sk_pop_free((_STACK *)local_190,X509_free);
      }
      if (local_194 != (X509 *)0x0) {
        X509_free(local_194);
      }
      local_188 = pXVar4;
      if (pXVar14 != (X509 *)0x0) goto LAB_00038b84;
    }
  }
  app_RAND_write_file(0,bio_err);
LAB_00038758:
  BIO_free((BIO *)bp);
  BIO_free_all((BIO *)local_17c);
  if (st != (X509 *)0x0) {
    sk_free((_STACK *)st);
  }
  if (local_124 != (char *)0x0) {
    CRYPTO_free(local_124);
  }
  if (local_120 != (char *)0x0) {
    CRYPTO_free(local_120);
  }
  if (local_2c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar15);
}

