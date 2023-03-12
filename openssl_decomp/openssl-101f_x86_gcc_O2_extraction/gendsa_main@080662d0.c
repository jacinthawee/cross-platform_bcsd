
undefined4 gendsa_main(int param_1,int param_2)

{
  int iVar1;
  BIO_METHOD *pBVar2;
  long lVar3;
  char **ppcVar4;
  DSA *a;
  undefined4 uVar5;
  char *pcVar6;
  BIO *pBVar7;
  char *pcVar8;
  int in_GS_OFFSET;
  bool bVar9;
  byte bVar10;
  char *pcVar11;
  char *local_48;
  char *local_44;
  char *local_40;
  char *local_3c;
  EVP_CIPHER *local_38;
  char *local_34;
  void *local_24;
  int local_20;
  
  bVar10 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_24 = (void *)0x0;
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    pBVar2 = BIO_s_file();
    bio_err = BIO_new(pBVar2);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  iVar1 = load_config(bio_err,0);
  if (iVar1 == 0) {
    pBVar7 = (BIO *)0x0;
    a = (DSA *)0x0;
    goto LAB_0806641c;
  }
  ppcVar4 = (char **)(param_2 + 4);
  param_1 = param_1 + -1;
  bVar9 = param_1 == 0;
  if (0 < param_1) {
    local_40 = (char *)0x0;
    local_38 = (EVP_CIPHER *)0x0;
    local_44 = (char *)0x0;
    local_34 = (char *)0x0;
    local_3c = (char *)0x0;
    local_48 = (char *)0x0;
LAB_08066383:
    pcVar11 = *ppcVar4;
    iVar1 = 5;
    pcVar6 = pcVar11;
    pcVar8 = "-out";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar9 = *pcVar6 == *pcVar8;
      pcVar6 = pcVar6 + (uint)bVar10 * -2 + 1;
      pcVar8 = pcVar8 + (uint)bVar10 * -2 + 1;
    } while (bVar9);
    if (bVar9) {
      param_1 = param_1 + -1;
      if (param_1 == 0) goto LAB_08066488;
      local_48 = ppcVar4[1];
      ppcVar4 = ppcVar4 + 1;
    }
    else {
      iVar1 = 9;
      pcVar6 = pcVar11;
      pcVar8 = "-passout";
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar9 = *pcVar6 == *pcVar8;
        pcVar6 = pcVar6 + (uint)bVar10 * -2 + 1;
        pcVar8 = pcVar8 + (uint)bVar10 * -2 + 1;
      } while (bVar9);
      if (bVar9) {
        if (param_1 == 1) goto LAB_08066488;
        local_44 = ppcVar4[1];
        param_1 = param_1 + -2;
        ppcVar4 = ppcVar4 + 2;
        goto joined_r0x080663c2;
      }
      iVar1 = 8;
      pcVar6 = pcVar11;
      pcVar8 = "-engine";
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar9 = *pcVar6 == *pcVar8;
        pcVar6 = pcVar6 + (uint)bVar10 * -2 + 1;
        pcVar8 = pcVar8 + (uint)bVar10 * -2 + 1;
      } while (bVar9);
      if (bVar9) {
        param_1 = param_1 + -1;
        if (param_1 == 0) goto LAB_08066488;
        local_40 = ppcVar4[1];
        ppcVar4 = ppcVar4 + 1;
      }
      else {
        iVar1 = 6;
        pcVar6 = pcVar11;
        pcVar8 = "-rand";
        do {
          if (iVar1 == 0) break;
          iVar1 = iVar1 + -1;
          bVar9 = *pcVar6 == *pcVar8;
          pcVar6 = pcVar6 + (uint)bVar10 * -2 + 1;
          pcVar8 = pcVar8 + (uint)bVar10 * -2 + 1;
        } while (bVar9);
        if (bVar9) {
          param_1 = param_1 + -1;
          if (param_1 != 0) {
            local_3c = ppcVar4[1];
            ppcVar4 = ppcVar4 + 1;
            goto LAB_0806637b;
          }
          goto LAB_08066488;
        }
        bVar9 = *pcVar11 == '-';
        if ((bVar9) && (bVar9 = pcVar11[1] == '\0', bVar9)) goto LAB_08066488;
        iVar1 = 5;
        pcVar6 = pcVar11;
        pcVar8 = "-des";
        do {
          if (iVar1 == 0) break;
          iVar1 = iVar1 + -1;
          bVar9 = *pcVar6 == *pcVar8;
          pcVar6 = pcVar6 + (uint)bVar10 * -2 + 1;
          pcVar8 = pcVar8 + (uint)bVar10 * -2 + 1;
        } while (bVar9);
        if (bVar9) {
          local_38 = EVP_des_cbc();
        }
        else {
          iVar1 = 6;
          pcVar6 = pcVar11;
          pcVar8 = "-des3";
          do {
            if (iVar1 == 0) break;
            iVar1 = iVar1 + -1;
            bVar9 = *pcVar6 == *pcVar8;
            pcVar6 = pcVar6 + (uint)bVar10 * -2 + 1;
            pcVar8 = pcVar8 + (uint)bVar10 * -2 + 1;
          } while (bVar9);
          if (bVar9) {
            local_38 = EVP_des_ede3_cbc();
          }
          else {
            iVar1 = 6;
            pcVar6 = pcVar11;
            pcVar8 = "-idea";
            do {
              if (iVar1 == 0) break;
              iVar1 = iVar1 + -1;
              bVar9 = *pcVar6 == *pcVar8;
              pcVar6 = pcVar6 + (uint)bVar10 * -2 + 1;
              pcVar8 = pcVar8 + (uint)bVar10 * -2 + 1;
            } while (bVar9);
            if (bVar9) {
              local_38 = EVP_idea_cbc();
            }
            else {
              iVar1 = 6;
              pcVar6 = pcVar11;
              pcVar8 = "-seed";
              do {
                if (iVar1 == 0) break;
                iVar1 = iVar1 + -1;
                bVar9 = *pcVar6 == *pcVar8;
                pcVar6 = pcVar6 + (uint)bVar10 * -2 + 1;
                pcVar8 = pcVar8 + (uint)bVar10 * -2 + 1;
              } while (bVar9);
              if (bVar9) {
                local_38 = EVP_seed_cbc();
              }
              else {
                iVar1 = 8;
                pcVar6 = pcVar11;
                pcVar8 = "-aes128";
                do {
                  if (iVar1 == 0) break;
                  iVar1 = iVar1 + -1;
                  bVar9 = *pcVar6 == *pcVar8;
                  pcVar6 = pcVar6 + (uint)bVar10 * -2 + 1;
                  pcVar8 = pcVar8 + (uint)bVar10 * -2 + 1;
                } while (bVar9);
                if (bVar9) {
                  local_38 = EVP_aes_128_cbc();
                }
                else {
                  iVar1 = 8;
                  pcVar6 = pcVar11;
                  pcVar8 = "-aes192";
                  do {
                    if (iVar1 == 0) break;
                    iVar1 = iVar1 + -1;
                    bVar9 = *pcVar6 == *pcVar8;
                    pcVar6 = pcVar6 + (uint)bVar10 * -2 + 1;
                    pcVar8 = pcVar8 + (uint)bVar10 * -2 + 1;
                  } while (bVar9);
                  if (bVar9) {
                    local_38 = EVP_aes_192_cbc();
                  }
                  else {
                    iVar1 = 8;
                    pcVar6 = pcVar11;
                    pcVar8 = "-aes256";
                    do {
                      if (iVar1 == 0) break;
                      iVar1 = iVar1 + -1;
                      bVar9 = *pcVar6 == *pcVar8;
                      pcVar6 = pcVar6 + (uint)bVar10 * -2 + 1;
                      pcVar8 = pcVar8 + (uint)bVar10 * -2 + 1;
                    } while (bVar9);
                    if (bVar9) {
                      local_38 = EVP_aes_256_cbc();
                    }
                    else {
                      iVar1 = 0xd;
                      pcVar6 = pcVar11;
                      pcVar8 = "-camellia128";
                      do {
                        if (iVar1 == 0) break;
                        iVar1 = iVar1 + -1;
                        bVar9 = *pcVar6 == *pcVar8;
                        pcVar6 = pcVar6 + (uint)bVar10 * -2 + 1;
                        pcVar8 = pcVar8 + (uint)bVar10 * -2 + 1;
                      } while (bVar9);
                      if (bVar9) {
                        local_38 = EVP_camellia_128_cbc();
                      }
                      else {
                        iVar1 = 0xd;
                        pcVar6 = pcVar11;
                        pcVar8 = "-camellia192";
                        do {
                          if (iVar1 == 0) break;
                          iVar1 = iVar1 + -1;
                          bVar9 = *pcVar6 == *pcVar8;
                          pcVar6 = pcVar6 + (uint)bVar10 * -2 + 1;
                          pcVar8 = pcVar8 + (uint)bVar10 * -2 + 1;
                        } while (bVar9);
                        if (bVar9) {
                          local_38 = EVP_camellia_192_cbc();
                        }
                        else {
                          iVar1 = 0xd;
                          pcVar6 = pcVar11;
                          pcVar8 = "-camellia256";
                          do {
                            if (iVar1 == 0) break;
                            iVar1 = iVar1 + -1;
                            bVar9 = *pcVar6 == *pcVar8;
                            pcVar6 = pcVar6 + (uint)bVar10 * -2 + 1;
                            pcVar8 = pcVar8 + (uint)bVar10 * -2 + 1;
                          } while (bVar9);
                          if (bVar9) {
                            local_38 = EVP_camellia_256_cbc();
                          }
                          else if ((local_34 != (char *)0x0) ||
                                  (local_34 = pcVar11, *pcVar11 == '-')) goto LAB_08066488;
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
LAB_0806637b:
    param_1 = param_1 + -1;
    ppcVar4 = ppcVar4 + 1;
joined_r0x080663c2:
    bVar9 = param_1 == 0;
    if (bVar9) goto LAB_080663c4;
    goto LAB_08066383;
  }
LAB_08066488:
  BIO_printf(bio_err,"usage: gendsa [args] dsaparam-file\n");
  BIO_printf(bio_err," -out file - output the key to \'file\'\n");
  BIO_printf(bio_err," -des      - encrypt the generated key with DES in cbc mode\n");
  BIO_printf(bio_err,
             " -des3     - encrypt the generated key with DES in ede cbc mode (168 bit key)\n");
  BIO_printf(bio_err," -idea     - encrypt the generated key with IDEA in cbc mode\n");
  BIO_printf(bio_err," -seed\n");
  BIO_printf(bio_err,"                 encrypt PEM output with cbc seed\n");
  BIO_printf(bio_err," -aes128, -aes192, -aes256\n");
  BIO_printf(bio_err,"                 encrypt PEM output with cbc aes\n");
  BIO_printf(bio_err," -camellia128, -camellia192, -camellia256\n");
  BIO_printf(bio_err,"                 encrypt PEM output with cbc camellia\n");
  BIO_printf(bio_err," -engine e - use engine e, possibly a hardware device.\n");
  BIO_printf(bio_err," -rand file%cfile%c...\n",0x3a,0x3a);
  BIO_printf(bio_err,"           - load the file (or the files in the directory) into\n");
  BIO_printf(bio_err,"             the random number generator\n");
  BIO_printf(bio_err," dsaparam-file\n");
  pcVar11 = "           - a DSA parameter file as generated by the dsaparam command\n";
LAB_080665b3:
  pBVar7 = (BIO *)0x0;
  a = (DSA *)0x0;
  BIO_printf(bio_err,pcVar11);
LAB_0806641c:
  uVar5 = 1;
  ERR_print_errors(bio_err);
  if (pBVar7 != (BIO *)0x0) goto LAB_08066436;
LAB_08066442:
  if (a != (DSA *)0x0) {
    DSA_free(a);
  }
LAB_08066452:
  if (local_24 != (void *)0x0) {
    CRYPTO_free(local_24);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
LAB_080663c4:
  if (local_34 == (char *)0x0) goto LAB_08066488;
  setup_engine(bio_err,local_40,0);
  iVar1 = app_passwd(bio_err,0,local_44,0,&local_24);
  if (iVar1 == 0) {
    pcVar11 = "Error getting password\n";
    goto LAB_080665b3;
  }
  pBVar2 = BIO_s_file();
  pBVar7 = BIO_new(pBVar2);
  lVar3 = BIO_ctrl(pBVar7,0x6c,3,local_34);
  if (lVar3 == 0) {
    perror(local_34);
LAB_0806690f:
    ERR_print_errors(bio_err);
    if (pBVar7 == (BIO *)0x0) {
      uVar5 = 1;
    }
    else {
      uVar5 = 1;
      BIO_free(pBVar7);
    }
    goto LAB_08066452;
  }
  a = PEM_read_bio_DSAparams(pBVar7,(DSA **)0x0,(undefined1 *)0x0,(void *)0x0);
  if (a == (DSA *)0x0) {
    BIO_printf(bio_err,"unable to load DSA parameter file\n");
    goto LAB_0806690f;
  }
  BIO_free(pBVar7);
  pBVar2 = BIO_s_file();
  pBVar7 = BIO_new(pBVar2);
  if (pBVar7 == (BIO *)0x0) goto LAB_0806641c;
  if (local_48 == (char *)0x0) {
    BIO_ctrl(pBVar7,0x6a,0,stdout);
  }
  else {
    lVar3 = BIO_ctrl(pBVar7,0x6c,5,local_48);
    if (lVar3 < 1) {
      perror(local_48);
      goto LAB_0806641c;
    }
  }
  iVar1 = app_RAND_load_file(0,bio_err,1);
  if (iVar1 == 0) {
    if (local_3c == (char *)0x0) {
      BIO_printf(bio_err,"warning, not much extra random data, consider using the -rand option\n");
    }
    else {
LAB_08066824:
      uVar5 = app_RAND_load_files(local_3c);
      BIO_printf(bio_err,"%ld semi-random bytes loaded\n",uVar5);
    }
  }
  else if (local_3c != (char *)0x0) goto LAB_08066824;
  iVar1 = BN_num_bits(a->p);
  BIO_printf(bio_err,"Generating DSA key, %d bits\n",iVar1);
  iVar1 = DSA_generate_key(a);
  if (iVar1 == 0) goto LAB_0806641c;
  uVar5 = 0;
  app_RAND_write_file(0,bio_err);
  iVar1 = PEM_write_bio_DSAPrivateKey(pBVar7,a,local_38,(uchar *)0x0,0,(undefined1 *)0x0,local_24);
  if (iVar1 == 0) goto LAB_0806641c;
LAB_08066436:
  BIO_free_all(pBVar7);
  goto LAB_08066442;
}

