
undefined4 crl_main(int param_1,char **param_2)

{
  ASN1_TIME *a;
  uint uVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  BIO_METHOD *pBVar5;
  BIO *pBVar6;
  long lVar7;
  X509_LOOKUP_METHOD *pXVar8;
  X509_LOOKUP *pXVar9;
  ASN1_INTEGER *a_00;
  int iVar10;
  undefined4 uVar11;
  undefined1 *puVar12;
  X509_STORE *v;
  char **ppcVar13;
  char *pcVar14;
  char *pcVar15;
  int in_GS_OFFSET;
  bool bVar16;
  byte bVar17;
  char *pcVar18;
  X509_NAME *name;
  X509_CRL *local_140;
  int local_13c;
  char *local_138;
  char *local_134;
  int local_130;
  int local_12c;
  EVP_MD *local_124;
  char *local_120;
  int local_11c;
  char *local_118;
  int local_110;
  int local_10c;
  int local_108;
  int local_104;
  int local_100;
  undefined4 local_f8;
  uint local_f4;
  X509_OBJECT local_f0;
  X509_STORE_CTX local_e8;
  byte local_60 [64];
  int local_20;
  
  bVar17 = 0;
  local_f8 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_124 = EVP_sha1();
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    pBVar5 = BIO_s_file();
    bio_err = BIO_new(pBVar5);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  iVar4 = load_config(bio_err,0);
  if (iVar4 != 0) {
    if (bio_out == (BIO *)0x0) {
      pBVar5 = BIO_s_file();
      bio_out = BIO_new(pBVar5);
      if (bio_out != (BIO *)0x0) {
        BIO_ctrl(bio_out,0x6a,0,stdout);
      }
    }
    bVar2 = false;
    local_100 = 0;
    local_104 = 0;
    bVar3 = false;
    local_110 = 0;
    param_1 = param_1 + -1;
    local_108 = 0;
    local_10c = 0;
    local_12c = 0;
    local_130 = 0;
    bVar16 = param_1 == 0;
    local_134 = (char *)0x0;
    local_138 = (char *)0x0;
    local_13c = 3;
    local_140 = (X509_CRL *)0x3;
    local_11c = 0;
    local_120 = (char *)0x0;
    local_118 = (char *)0x0;
    if (0 < param_1) {
      do {
        ppcVar13 = param_2 + 1;
        pcVar18 = *ppcVar13;
        iVar4 = 8;
        pcVar14 = pcVar18;
        pcVar15 = "-inform";
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          bVar16 = *pcVar14 == *pcVar15;
          pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
          pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
        } while (bVar16);
        if (!bVar16) {
          iVar4 = 9;
          pcVar14 = pcVar18;
          pcVar15 = "-outform";
          do {
            if (iVar4 == 0) break;
            iVar4 = iVar4 + -1;
            bVar16 = *pcVar14 == *pcVar15;
            pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
            pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
          } while (bVar16);
          if (bVar16) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_0805d440;
            ppcVar13 = param_2 + 2;
            local_13c = str2fmt(param_2[2]);
            goto LAB_0805d24e;
          }
          bVar16 = *pcVar18 == '-';
          if ((((bVar16) && (bVar16 = pcVar18[1] == 'i', bVar16)) &&
              (bVar16 = pcVar18[2] == 'n', bVar16)) && (bVar16 = pcVar18[3] == '\0', bVar16)) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_0805d440;
            local_138 = param_2[2];
            ppcVar13 = param_2 + 2;
            goto LAB_0805d24e;
          }
          iVar4 = 5;
          pcVar14 = pcVar18;
          pcVar15 = "-out";
          do {
            if (iVar4 == 0) break;
            iVar4 = iVar4 + -1;
            bVar16 = *pcVar14 == *pcVar15;
            pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
            pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
          } while (bVar16);
          if (bVar16) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_0805d440;
            local_134 = param_2[2];
            ppcVar13 = param_2 + 2;
            goto LAB_0805d24e;
          }
          iVar4 = 8;
          pcVar14 = pcVar18;
          pcVar15 = "-CApath";
          do {
            if (iVar4 == 0) break;
            iVar4 = iVar4 + -1;
            bVar16 = *pcVar14 == *pcVar15;
            pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
            pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
          } while (bVar16);
          if (bVar16) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_0805d440;
            local_120 = param_2[2];
            ppcVar13 = param_2 + 2;
            bVar2 = true;
            goto LAB_0805d24e;
          }
          iVar4 = 8;
          pcVar14 = pcVar18;
          pcVar15 = "-CAfile";
          do {
            if (iVar4 == 0) break;
            iVar4 = iVar4 + -1;
            bVar16 = *pcVar14 == *pcVar15;
            pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
            pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
          } while (bVar16);
          if (bVar16) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_0805d440;
            local_118 = param_2[2];
            ppcVar13 = param_2 + 2;
            bVar2 = true;
            goto LAB_0805d24e;
          }
          iVar4 = 8;
          pcVar14 = pcVar18;
          pcVar15 = "-verify";
          do {
            if (iVar4 == 0) break;
            iVar4 = iVar4 + -1;
            bVar16 = *pcVar14 == *pcVar15;
            pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
            pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
          } while (bVar16);
          if (bVar16) {
            bVar2 = true;
            goto LAB_0805d24e;
          }
          iVar4 = 6;
          pcVar14 = pcVar18;
          pcVar15 = "-text";
          do {
            if (iVar4 == 0) break;
            iVar4 = iVar4 + -1;
            bVar16 = *pcVar14 == *pcVar15;
            pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
            pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
          } while (bVar16);
          if (bVar16) {
            bVar3 = true;
            goto LAB_0805d24e;
          }
          iVar4 = 6;
          pcVar14 = pcVar18;
          pcVar15 = "-hash";
          do {
            if (iVar4 == 0) break;
            iVar4 = iVar4 + -1;
            bVar16 = *pcVar14 == *pcVar15;
            pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
            pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
          } while (bVar16);
          if (bVar16) {
            local_130 = local_11c + 1;
            local_11c = local_130;
            goto LAB_0805d24e;
          }
          iVar4 = 9;
          pcVar14 = pcVar18;
          pcVar15 = "-nameopt";
          do {
            if (iVar4 == 0) break;
            iVar4 = iVar4 + -1;
            bVar16 = *pcVar14 == *pcVar15;
            pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
            pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
          } while (bVar16);
          if (!bVar16) {
            iVar4 = 8;
            pcVar14 = pcVar18;
            pcVar15 = "-issuer";
            do {
              if (iVar4 == 0) break;
              iVar4 = iVar4 + -1;
              bVar16 = *pcVar14 == *pcVar15;
              pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
              pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
            } while (bVar16);
            if (bVar16) {
              local_12c = local_11c + 1;
              local_11c = local_12c;
            }
            else {
              iVar4 = 0xc;
              pcVar14 = pcVar18;
              pcVar15 = "-lastupdate";
              do {
                if (iVar4 == 0) break;
                iVar4 = iVar4 + -1;
                bVar16 = *pcVar14 == *pcVar15;
                pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
                pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
              } while (bVar16);
              if (bVar16) {
                local_11c = local_11c + 1;
                local_10c = local_11c;
              }
              else {
                iVar4 = 0xc;
                pcVar14 = pcVar18;
                pcVar15 = "-nextupdate";
                do {
                  if (iVar4 == 0) break;
                  iVar4 = iVar4 + -1;
                  bVar16 = *pcVar14 == *pcVar15;
                  pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
                  pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
                } while (bVar16);
                if (bVar16) {
                  local_11c = local_11c + 1;
                  local_108 = local_11c;
                }
                else {
                  iVar4 = 7;
                  pcVar14 = pcVar18;
                  pcVar15 = "-noout";
                  do {
                    if (iVar4 == 0) break;
                    iVar4 = iVar4 + -1;
                    bVar16 = *pcVar14 == *pcVar15;
                    pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
                    pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
                  } while (bVar16);
                  if (bVar16) {
                    local_11c = local_11c + 1;
                    local_110 = local_11c;
                  }
                  else {
                    iVar4 = 0xd;
                    pcVar14 = pcVar18;
                    pcVar15 = "-fingerprint";
                    do {
                      if (iVar4 == 0) break;
                      iVar4 = iVar4 + -1;
                      bVar16 = *pcVar14 == *pcVar15;
                      pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
                      pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
                    } while (bVar16);
                    if (bVar16) {
                      local_11c = local_11c + 1;
                      local_104 = local_11c;
                    }
                    else {
                      iVar4 = 0xb;
                      pcVar14 = pcVar18;
                      pcVar15 = "-crlnumber";
                      do {
                        if (iVar4 == 0) break;
                        iVar4 = iVar4 + -1;
                        bVar16 = *pcVar14 == *pcVar15;
                        pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
                        pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
                      } while (bVar16);
                      if (bVar16) {
                        local_11c = local_11c + 1;
                        local_100 = local_11c;
                      }
                      else {
                        local_124 = EVP_get_digestbyname(pcVar18 + 1);
                        if (local_124 == (EVP_MD *)0x0) {
                          BIO_printf(bio_err,"unknown option %s\n",*ppcVar13);
                          goto LAB_0805d440;
                        }
                      }
                    }
                  }
                }
              }
            }
            goto LAB_0805d24e;
          }
          param_1 = param_1 + -1;
          if (param_1 != 0) {
            ppcVar13 = param_2 + 2;
            iVar4 = set_name_ex(&local_f8,param_2[2]);
            if (iVar4 != 0) goto LAB_0805d24e;
          }
LAB_0805d440:
          puVar12 = crl_usage;
          iVar4 = crl_usage._0_4_;
          while (iVar4 != 0) {
            puVar12 = (undefined1 *)((int)puVar12 + 4);
            BIO_printf(bio_err,"%s",iVar4);
            iVar4 = *(int *)puVar12;
          }
          goto LAB_0805d320;
        }
        param_1 = param_1 + -1;
        if (param_1 == 0) goto LAB_0805d440;
        ppcVar13 = param_2 + 2;
        local_140 = (X509_CRL *)str2fmt(param_2[2]);
LAB_0805d24e:
        param_1 = param_1 + -1;
        bVar16 = param_1 == 0;
        param_2 = ppcVar13;
      } while (!bVar16);
    }
    ERR_load_crypto_strings();
    pBVar5 = BIO_s_file();
    pBVar6 = BIO_new(pBVar5);
    if (pBVar6 == (BIO *)0x0) {
      ERR_print_errors(bio_err);
    }
    else {
      if (local_138 == (char *)0x0) {
        name = (X509_NAME *)0x0;
        BIO_ctrl(pBVar6,0x6a,0,stdin);
      }
      else {
        name = (X509_NAME *)0x3;
        lVar7 = BIO_ctrl(pBVar6,0x6c,3,local_138);
        if (lVar7 < 1) {
          perror(local_138);
          goto LAB_0805d312;
        }
      }
      if (local_140 == (X509_CRL *)0x1) {
        local_140 = d2i_X509_CRL_bio(pBVar6,(X509_CRL **)0x0);
      }
      else {
        if (local_140 != (X509_CRL *)0x3) {
          BIO_printf(bio_err,"bad input format specified for input crl\n");
          goto LAB_0805d312;
        }
        name = (X509_NAME *)0x0;
        local_140 = PEM_read_bio_X509_CRL(pBVar6,(X509_CRL **)0x0,(undefined1 *)0x0,(void *)0x0);
      }
      if (local_140 != (X509_CRL *)0x0) {
        v = (X509_STORE *)0x0;
        BIO_free(pBVar6);
        if (bVar2) {
          v = X509_STORE_new();
          pXVar8 = X509_LOOKUP_file();
          pXVar9 = X509_STORE_add_lookup(v,pXVar8);
          if (pXVar9 != (X509_LOOKUP *)0x0) {
            iVar4 = X509_LOOKUP_ctrl(pXVar9,1,local_118,1,(char **)0x0);
            if (iVar4 == 0) {
              X509_LOOKUP_ctrl(pXVar9,1,(char *)0x0,3,(char **)0x0);
            }
            pXVar8 = X509_LOOKUP_hash_dir();
            pXVar9 = X509_STORE_add_lookup(v,pXVar8);
            if (pXVar9 != (X509_LOOKUP *)0x0) {
              iVar4 = X509_LOOKUP_ctrl(pXVar9,2,local_120,1,(char **)0x0);
              if (iVar4 == 0) {
                X509_LOOKUP_ctrl(pXVar9,2,(char *)0x0,3,(char **)0x0);
              }
              ERR_clear_error();
              iVar4 = X509_STORE_CTX_init(&local_e8,v,(X509 *)0x0,(stack_st_X509 *)0x0);
              if (iVar4 == 0) {
                pcVar18 = "Error initialising X509 store\n";
              }
              else {
                name = local_140->crl->issuer;
                iVar4 = X509_STORE_get_by_subject(&local_e8,1,name,&local_f0);
                if (0 < iVar4) {
                  pBVar6 = (BIO *)X509_get_pubkey(local_f0.data.x509);
                  X509_OBJECT_free_contents(&local_f0);
                  if (pBVar6 == (BIO *)0x0) {
                    uVar11 = 1;
                    BIO_printf(bio_err,"Error getting CRL issuer public key\n");
                    goto LAB_0805d1de;
                  }
                  iVar4 = X509_CRL_verify(local_140,(EVP_PKEY *)pBVar6);
                  EVP_PKEY_free((EVP_PKEY *)pBVar6);
                  if (-1 < iVar4) {
                    if (iVar4 == 0) {
                      BIO_printf(bio_err,"verify failure\n");
                    }
                    else {
                      BIO_printf(bio_err,"verify OK\n");
                    }
                    goto LAB_0805d0ec;
                  }
                  goto LAB_0805d667;
                }
                pcVar18 = "Error getting CRL issuer certificate\n";
              }
LAB_0805d5e1:
              pBVar6 = (BIO *)0x0;
              uVar11 = 1;
              BIO_printf(bio_err,pcVar18);
              goto LAB_0805d1de;
            }
          }
LAB_0805d667:
          pBVar6 = (BIO *)0x0;
          uVar11 = 1;
        }
        else {
LAB_0805d0ec:
          iVar4 = 1;
          if (local_11c != 0) {
            do {
              if (local_12c == iVar4) {
                name = local_140->crl->issuer;
                print_name(bio_out,"issuer=",name,local_f8);
              }
              if (iVar4 == local_100) {
                name = (X509_NAME *)0x0;
                a_00 = (ASN1_INTEGER *)X509_CRL_get_ext_d2i(local_140,0x58,(int *)0x0,(int *)0x0);
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
              if (local_130 == iVar4) {
                name = (X509_NAME *)X509_NAME_hash(local_140->crl->issuer);
                BIO_printf(bio_out,"%08lx\n",name);
              }
              if (local_10c == iVar4) {
                BIO_printf(bio_out,"lastUpdate=",name);
                ASN1_TIME_print(bio_out,local_140->crl->lastUpdate);
                BIO_printf(bio_out,"\n");
              }
              if (iVar4 == local_108) {
                BIO_printf(bio_out,"nextUpdate=",name);
                a = local_140->crl->nextUpdate;
                if (a == (ASN1_TIME *)0x0) {
                  BIO_printf(bio_out,"NONE",name);
                }
                else {
                  ASN1_TIME_print(bio_out,a);
                }
                BIO_printf(bio_out,"\n");
              }
              if (iVar4 == local_104) {
                iVar10 = X509_CRL_digest(local_140,local_124,local_60,&local_f4);
                if (iVar10 == 0) {
                  pcVar18 = "out of memory\n";
                  goto LAB_0805d5e1;
                }
                iVar10 = EVP_MD_type(local_124);
                name = (X509_NAME *)OBJ_nid2sn(iVar10);
                BIO_printf(bio_out,"%s Fingerprint=",name);
                if (0 < (int)local_f4) {
                  local_138 = (char *)0x0;
                  do {
                    uVar1 = (int)local_138 + 1;
                    uVar11 = 10;
                    if (uVar1 != local_f4) {
                      uVar11 = 0x3a;
                    }
                    name = (X509_NAME *)(uint)local_60[(int)local_138];
                    BIO_printf(bio_out,"%02X%c",name,uVar11);
                    local_138 = (char *)uVar1;
                  } while ((int)uVar1 < (int)local_f4);
                }
              }
              iVar4 = iVar4 + 1;
            } while (iVar4 <= local_11c);
          }
          pBVar5 = BIO_s_file();
          pBVar6 = BIO_new(pBVar5);
          if (pBVar6 == (BIO *)0x0) {
            uVar11 = 1;
            ERR_print_errors(bio_err);
          }
          else {
            if (local_134 == (char *)0x0) {
              BIO_ctrl(pBVar6,0x6a,0,stdout);
            }
            else {
              lVar7 = BIO_ctrl(pBVar6,0x6c,5,local_134);
              if (lVar7 < 1) {
                uVar11 = 1;
                perror(local_134);
                goto LAB_0805d1de;
              }
            }
            if (bVar3) {
              X509_CRL_print(pBVar6,local_140);
            }
            uVar11 = 0;
            if (local_110 == 0) {
              if (local_13c == 1) {
                iVar4 = i2d_X509_CRL_bio(pBVar6,local_140);
              }
              else {
                if (local_13c != 3) {
                  uVar11 = 1;
                  BIO_printf(bio_err,"bad output format specified for outfile\n");
                  goto LAB_0805d1de;
                }
                iVar4 = PEM_write_bio_X509_CRL(pBVar6,local_140);
              }
              uVar11 = 0;
              if (iVar4 == 0) {
                uVar11 = 1;
                BIO_printf(bio_err,"unable to write CRL\n");
              }
            }
          }
        }
LAB_0805d1de:
        BIO_free_all(pBVar6);
        BIO_free_all(bio_out);
        bio_out = (BIO *)0x0;
        X509_CRL_free(local_140);
        if (v != (X509_STORE *)0x0) {
          X509_STORE_CTX_cleanup(&local_e8);
          X509_STORE_free(v);
        }
        goto LAB_0805d354;
      }
      BIO_printf(bio_err,"unable to load CRL\n");
      ERR_print_errors(bio_err);
    }
LAB_0805d312:
    BIO_free(pBVar6);
  }
LAB_0805d320:
  uVar11 = 1;
  BIO_free_all((BIO *)0x0);
  BIO_free_all(bio_out);
  bio_out = (BIO *)0x0;
  X509_CRL_free((X509_CRL *)0x0);
LAB_0805d354:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar11;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

