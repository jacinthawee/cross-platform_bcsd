
/* WARNING: Removing unreachable block (ram,0x08084f54) */

undefined4 pkey_main(undefined4 param_1,int param_2)

{
  char **ppcVar1;
  char cVar2;
  char *pcVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  int iVar9;
  BIO *bp;
  EVP_PKEY *x;
  int *piVar10;
  undefined4 uVar11;
  int *piVar12;
  char *pcVar13;
  char *pcVar14;
  int in_GS_OFFSET;
  bool bVar15;
  byte bVar16;
  undefined4 local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  char *local_48;
  EVP_CIPHER *local_30;
  void *local_28;
  void *local_24;
  int local_20;
  
  bVar16 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_28 = (void *)0x0;
  local_24 = (void *)0x0;
  if (bio_err == (BIO *)0x0) {
    bio_err = BIO_new_fp(stderr,0);
  }
  iVar9 = load_config(bio_err,0);
  if (iVar9 == 0) {
    uVar11 = 1;
    x = (EVP_PKEY *)0x0;
    bp = (BIO *)0x0;
  }
  else {
    ERR_load_crypto_strings();
    OPENSSL_add_all_algorithms_noconf();
    pcVar3 = *(char **)(param_2 + 4);
    if (pcVar3 == (char *)0x0) {
      local_50 = 0;
      bVar5 = false;
      bVar7 = false;
      bVar8 = false;
      bVar6 = false;
      bVar4 = false;
      local_5c = 3;
      local_60 = 3;
      local_30 = (EVP_CIPHER *)0x0;
      local_54 = 0;
      local_58 = 0;
      local_48 = (char *)0x0;
      local_4c = 0;
    }
    else {
      cVar2 = *pcVar3;
      local_50 = 0;
      bVar5 = false;
      bVar7 = false;
      bVar8 = false;
      bVar6 = false;
      bVar4 = false;
      local_5c = 3;
      local_60 = 3;
      local_30 = (EVP_CIPHER *)0x0;
      local_54 = 0;
      local_58 = 0;
      local_48 = (char *)0x0;
      local_4c = 0;
      piVar12 = (int *)(param_2 + 4);
      while (bVar15 = cVar2 == '-', bVar15) {
        iVar9 = 8;
        pcVar13 = pcVar3;
        pcVar14 = "-inform";
        do {
          if (iVar9 == 0) break;
          iVar9 = iVar9 + -1;
          bVar15 = *pcVar13 == *pcVar14;
          pcVar13 = pcVar13 + (uint)bVar16 * -2 + 1;
          pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
        } while (bVar15);
        if (bVar15) {
          piVar10 = piVar12 + 1;
          if (*piVar10 != 0) {
            piVar12 = piVar12 + 1;
            local_60 = str2fmt(*piVar10);
            bVar15 = false;
            goto LAB_08084ef0;
          }
LAB_080850a8:
          bVar15 = true;
LAB_08084ef0:
          piVar10 = piVar12 + 1;
          if (bVar15) {
LAB_08084f58:
            BIO_printf(bio_err,"Usage pkey [options]\n");
            BIO_printf(bio_err,"where options are\n");
            BIO_printf(bio_err,"-in file        input file\n");
            BIO_printf(bio_err,"-inform X       input format (DER or PEM)\n");
            BIO_printf(bio_err,"-passin arg     input file pass phrase source\n");
            BIO_printf(bio_err,"-outform X      output format (DER or PEM)\n");
            uVar11 = 1;
            BIO_printf(bio_err,"-out file       output file\n");
            BIO_printf(bio_err,"-passout arg    output file pass phrase source\n");
            BIO_printf(bio_err,"-engine e       use engine e, possibly a hardware device.\n");
            goto LAB_08085059;
          }
        }
        else {
          iVar9 = 9;
          pcVar13 = pcVar3;
          pcVar14 = "-outform";
          do {
            if (iVar9 == 0) break;
            iVar9 = iVar9 + -1;
            bVar15 = *pcVar13 == *pcVar14;
            pcVar13 = pcVar13 + (uint)bVar16 * -2 + 1;
            pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
          } while (bVar15);
          if (!bVar15) {
            iVar9 = 8;
            pcVar13 = pcVar3;
            pcVar14 = "-passin";
            do {
              if (iVar9 == 0) break;
              iVar9 = iVar9 + -1;
              bVar15 = *pcVar13 == *pcVar14;
              pcVar13 = pcVar13 + (uint)bVar16 * -2 + 1;
              pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
            } while (bVar15);
            if (bVar15) {
              local_58 = piVar12[1];
              iVar9 = local_58;
            }
            else {
              iVar9 = 9;
              pcVar13 = pcVar3;
              pcVar14 = "-passout";
              do {
                if (iVar9 == 0) break;
                iVar9 = iVar9 + -1;
                bVar15 = *pcVar13 == *pcVar14;
                pcVar13 = pcVar13 + (uint)bVar16 * -2 + 1;
                pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
              } while (bVar15);
              if (bVar15) {
                local_54 = piVar12[1];
                iVar9 = local_54;
              }
              else {
                iVar9 = 8;
                pcVar13 = pcVar3;
                pcVar14 = "-engine";
                do {
                  if (iVar9 == 0) break;
                  iVar9 = iVar9 + -1;
                  bVar15 = *pcVar13 == *pcVar14;
                  pcVar13 = pcVar13 + (uint)bVar16 * -2 + 1;
                  pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
                } while (bVar15);
                if (!bVar15) {
                  bVar15 = pcVar3[1] == 'i';
                  if (((bVar15) && (bVar15 = pcVar3[2] == 'n', bVar15)) &&
                     (bVar15 = pcVar3[3] == '\0', bVar15)) {
                    piVar10 = piVar12 + 1;
                    if (*piVar10 == 0) goto LAB_080850a8;
                    piVar12 = piVar12 + 1;
                    bVar15 = false;
                    local_4c = *piVar10;
                  }
                  else {
                    iVar9 = 5;
                    pcVar13 = pcVar3;
                    pcVar14 = "-out";
                    do {
                      if (iVar9 == 0) break;
                      iVar9 = iVar9 + -1;
                      bVar15 = *pcVar13 == *pcVar14;
                      pcVar13 = pcVar13 + (uint)bVar16 * -2 + 1;
                      pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
                    } while (bVar15);
                    if (bVar15) {
                      ppcVar1 = (char **)(piVar12 + 1);
                      if (*ppcVar1 == (char *)0x0) goto LAB_080850a8;
                      piVar12 = piVar12 + 1;
                      bVar15 = false;
                      local_48 = *ppcVar1;
                    }
                    else {
                      iVar9 = 7;
                      pcVar13 = pcVar3;
                      pcVar14 = "-pubin";
                      do {
                        if (iVar9 == 0) break;
                        iVar9 = iVar9 + -1;
                        bVar15 = *pcVar13 == *pcVar14;
                        pcVar13 = pcVar13 + (uint)bVar16 * -2 + 1;
                        pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
                      } while (bVar15);
                      if (bVar15) {
                        bVar15 = false;
                        bVar8 = true;
                        bVar6 = true;
                        bVar4 = true;
                      }
                      else {
                        iVar9 = 8;
                        pcVar13 = pcVar3;
                        pcVar14 = "-pubout";
                        do {
                          if (iVar9 == 0) break;
                          iVar9 = iVar9 + -1;
                          bVar15 = *pcVar13 == *pcVar14;
                          pcVar13 = pcVar13 + (uint)bVar16 * -2 + 1;
                          pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
                        } while (bVar15);
                        if (bVar15) {
                          bVar15 = false;
                          bVar6 = true;
                        }
                        else {
                          iVar9 = 10;
                          pcVar13 = pcVar3;
                          pcVar14 = "-text_pub";
                          do {
                            if (iVar9 == 0) break;
                            iVar9 = iVar9 + -1;
                            bVar15 = *pcVar13 == *pcVar14;
                            pcVar13 = pcVar13 + (uint)bVar16 * -2 + 1;
                            pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
                          } while (bVar15);
                          if (bVar15) {
                            bVar15 = false;
                            bVar7 = true;
                            bVar8 = true;
                          }
                          else {
                            iVar9 = 6;
                            pcVar13 = pcVar3;
                            pcVar14 = "-text";
                            do {
                              if (iVar9 == 0) break;
                              iVar9 = iVar9 + -1;
                              bVar15 = *pcVar13 == *pcVar14;
                              pcVar13 = pcVar13 + (uint)bVar16 * -2 + 1;
                              pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
                            } while (bVar15);
                            if (bVar15) {
                              bVar15 = false;
                              bVar7 = true;
                            }
                            else {
                              iVar9 = 7;
                              pcVar13 = pcVar3;
                              pcVar14 = "-noout";
                              do {
                                if (iVar9 == 0) break;
                                iVar9 = iVar9 + -1;
                                bVar15 = *pcVar13 == *pcVar14;
                                pcVar13 = pcVar13 + (uint)bVar16 * -2 + 1;
                                pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
                              } while (bVar15);
                              if (bVar15) {
                                bVar15 = false;
                                bVar5 = true;
                              }
                              else {
                                local_30 = EVP_get_cipherbyname(pcVar3 + 1);
                                bVar15 = false;
                                if (local_30 == (EVP_CIPHER *)0x0) {
                                  BIO_printf(bio_err,"Unknown cipher %s\n",*piVar12 + 1,0);
                                  bVar15 = true;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                  goto LAB_08084ef0;
                }
                local_50 = piVar12[1];
                iVar9 = local_50;
              }
            }
            if (iVar9 != 0) {
              piVar12 = piVar12 + 1;
              bVar15 = false;
              goto LAB_08084ef0;
            }
            goto LAB_08084f58;
          }
          if (piVar12[1] == 0) goto LAB_080850a8;
          piVar10 = piVar12 + 2;
          local_5c = str2fmt(piVar12[1]);
          piVar12 = piVar12 + 1;
        }
        pcVar3 = (char *)piVar12[1];
        if (pcVar3 == (char *)0x0) break;
        piVar12 = piVar10;
        cVar2 = *pcVar3;
      }
    }
    uVar11 = setup_engine(bio_err,local_50,0);
    iVar9 = app_passwd(bio_err,local_58,local_54,&local_28,&local_24);
    if (iVar9 == 0) {
      uVar11 = 1;
      x = (EVP_PKEY *)0x0;
      bp = (BIO *)0x0;
      BIO_printf(bio_err,"Error getting passwords\n");
    }
    else {
      if (local_48 == (char *)0x0) {
        bp = BIO_new_fp(stdout,0);
      }
      else {
        bp = BIO_new_file(local_48,"wb");
        if (bp == (BIO *)0x0) {
          uVar11 = 1;
          x = (EVP_PKEY *)0x0;
          BIO_printf(bio_err,"Can\'t open output file %s\n",local_48);
          goto LAB_08085011;
        }
      }
      if (bVar4) {
        x = (EVP_PKEY *)load_pubkey(bio_err,local_4c,local_60,1,local_28,uVar11,"Public Key");
      }
      else {
        x = (EVP_PKEY *)load_key(bio_err,local_4c,local_60,1,local_28,uVar11,"key");
      }
      if (x == (EVP_PKEY *)0x0) {
        uVar11 = 1;
      }
      else {
        if (!bVar5) {
          if (local_5c == 3) {
            if (bVar6) {
              PEM_write_bio_PUBKEY(bp,x);
            }
            else {
              PEM_write_bio_PrivateKey(bp,x,local_30,(uchar *)0x0,0,(undefined1 *)0x0,local_24);
            }
          }
          else {
            if (local_5c != 1) {
              uVar11 = 1;
              BIO_printf(bio_err,"Bad format specified for key\n");
              goto LAB_08085011;
            }
            if (bVar6) {
              i2d_PUBKEY_bio(bp,x);
            }
            else {
              i2d_PrivateKey_bio(bp,x);
            }
          }
        }
        uVar11 = 0;
        if (bVar7) {
          if (bVar8) {
            EVP_PKEY_print_public(bp,x,0,(ASN1_PCTX *)0x0);
          }
          else {
            EVP_PKEY_print_private(bp,x,0,(ASN1_PCTX *)0x0);
          }
        }
      }
    }
  }
LAB_08085011:
  EVP_PKEY_free(x);
  BIO_free_all(bp);
  BIO_free((BIO *)0x0);
  if (local_28 != (void *)0x0) {
    CRYPTO_free(local_28);
  }
  if (local_24 != (void *)0x0) {
    CRYPTO_free(local_24);
  }
LAB_08085059:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar11;
}

