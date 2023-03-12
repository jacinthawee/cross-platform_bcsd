
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void pkcs8_main(undefined4 param_1,int param_2)

{
  char cVar1;
  char cVar2;
  BIO *pBVar3;
  uint uVar4;
  int iVar5;
  BIO *bp;
  BIO *bp_00;
  size_t sVar6;
  BIO *p8;
  char *pcVar7;
  int iVar8;
  int pbe_nid;
  undefined4 uVar9;
  BIO *cipher;
  int iVar10;
  int local_94;
  int local_90;
  BIO *local_8c;
  BIO *local_88;
  BIO *local_84;
  BIO *local_80;
  BIO *local_7c;
  BIO *local_78;
  BIO *local_74;
  int local_70;
  BIO *local_6c;
  char *local_68;
  char *local_64;
  char acStack_60 [52];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  local_68 = (char *)0x0;
  local_64 = (char *)0x0;
  if (bio_err == (BIO *)0x0) {
    bio_err = BIO_new_fp(stderr,0);
  }
  pBVar3 = (BIO *)load_config(bio_err,0);
  if (pBVar3 == (BIO *)0x0) {
    uVar9 = 1;
    bp_00 = pBVar3;
    bp = pBVar3;
    p8 = pBVar3;
    local_74 = pBVar3;
    goto LAB_00039568;
  }
  ERR_load_crypto_strings();
  iVar10 = param_2 + 4;
  OPENSSL_add_all_algorithms_noconf();
  pBVar3 = *(BIO **)(param_2 + 4);
  local_80 = pBVar3;
  if ((pBVar3 == (BIO *)0x0) || (local_80 = (BIO *)0x0, *(char *)&pBVar3->method != '-')) {
    local_94 = 3;
    pbe_nid = -1;
    local_90 = 3;
    local_70 = 0x800;
    cipher = local_80;
    local_8c = local_80;
    local_88 = local_80;
    local_84 = local_80;
    local_7c = local_80;
    local_78 = local_80;
    local_74 = local_80;
    local_6c = local_80;
  }
  else {
    local_74 = (BIO *)0x0;
    cipher = (BIO *)0x0;
    local_6c = (BIO *)0x0;
    local_8c = (BIO *)0x0;
    local_84 = (BIO *)0x0;
    local_88 = (BIO *)0x0;
    local_78 = (BIO *)0x0;
    local_7c = (BIO *)0x0;
    local_80 = (BIO *)0x0;
    local_94 = 3;
    local_90 = 3;
    pbe_nid = -1;
    local_70 = 0x800;
    do {
      cVar2 = *(char *)((int)&pBVar3->method + 1);
      iVar8 = iVar10;
      if (cVar2 != 'v') {
LAB_00039640:
        uVar4 = strcmp((char *)pBVar3,"-inform");
        if (uVar4 == 0) {
          if (*(int *)(iVar10 + 4) == 0) goto LAB_00039664;
          local_90 = str2fmt();
          iVar8 = iVar10 + 4;
          goto LAB_0003961c;
        }
        uVar4 = strcmp((char *)pBVar3,"-outform");
        if (uVar4 == 0) {
          if (*(int *)(iVar10 + 4) == 0) goto LAB_00039664;
          local_94 = str2fmt();
          iVar8 = iVar10 + 4;
          goto LAB_0003961c;
        }
        uVar4 = strcmp((char *)pBVar3,"-topk8");
        if (uVar4 == 0) {
          local_8c = (BIO *)0x1;
          goto LAB_0003961c;
        }
        uVar4 = strcmp((char *)pBVar3,"-noiter");
        if (uVar4 == 0) {
          local_70 = 1;
          goto LAB_0003961c;
        }
        uVar4 = strcmp((char *)pBVar3,"-nocrypt");
        if (uVar4 == 0) {
          local_74 = (BIO *)0x1;
          goto LAB_0003961c;
        }
        uVar4 = strcmp((char *)pBVar3,"-nooct");
        if (uVar4 == 0) {
          local_6c = (BIO *)0x1;
          goto LAB_0003961c;
        }
        uVar4 = strcmp((char *)pBVar3,"-nsdb");
        if (uVar4 == 0) {
          local_6c = (BIO *)0x3;
          goto LAB_0003961c;
        }
        uVar4 = strcmp((char *)pBVar3,"-embed");
        if (uVar4 == 0) {
          local_6c = (BIO *)0x2;
          goto LAB_0003961c;
        }
        iVar5 = strcmp((char *)pBVar3,"-passin");
        if (iVar5 == 0) {
          local_88 = *(BIO **)(iVar10 + 4);
          pBVar3 = local_88;
        }
        else {
          iVar5 = strcmp((char *)pBVar3,"-passout");
          if (iVar5 == 0) {
            local_84 = *(BIO **)(iVar10 + 4);
            pBVar3 = local_84;
          }
          else {
            iVar5 = strcmp((char *)pBVar3,"-engine");
            if (iVar5 != 0) {
              if (((cVar2 == 'i') && (*(char *)((int)&pBVar3->method + 2) == 'n')) &&
                 (uVar4 = (uint)*(byte *)((int)&pBVar3->method + 3), uVar4 == 0)) {
                if (*(BIO **)(iVar10 + 4) == (BIO *)0x0) {
LAB_00039664:
                  uVar4 = 1;
                }
                else {
                  iVar8 = iVar10 + 4;
                  local_7c = *(BIO **)(iVar10 + 4);
                }
              }
              else {
                uVar4 = strcmp((char *)pBVar3,"-out");
                if ((uVar4 != 0) || (*(BIO **)(iVar10 + 4) == (BIO *)0x0)) goto LAB_00039664;
                iVar8 = iVar10 + 4;
                local_78 = *(BIO **)(iVar10 + 4);
              }
              goto LAB_0003961c;
            }
            local_80 = *(BIO **)(iVar10 + 4);
            pBVar3 = local_80;
          }
        }
        if (pBVar3 != (BIO *)0x0) {
          uVar4 = 0;
          iVar8 = iVar10 + 4;
          goto LAB_0003961c;
        }
LAB_00039870:
        BIO_printf(bio_err,"Usage pkcs8 [options]\n");
        BIO_printf(bio_err,"where options are\n");
        BIO_printf(bio_err,"-in file        input file\n");
        BIO_printf(bio_err,"-inform X       input format (DER or PEM)\n");
        BIO_printf(bio_err,"-passin arg     input file pass phrase source\n");
        BIO_printf(bio_err,"-outform X      output format (DER or PEM)\n");
        BIO_printf(bio_err,"-out file       output file\n");
        BIO_printf(bio_err,"-passout arg    output file pass phrase source\n");
        BIO_printf(bio_err,"-topk8          output PKCS8 file\n");
        BIO_printf(bio_err,"-nooct          use (nonstandard) no octet format\n");
        BIO_printf(bio_err,"-embed          use (nonstandard) embedded DSA parameters format\n");
        BIO_printf(bio_err,"-nsdb           use (nonstandard) DSA Netscape DB format\n");
        BIO_printf(bio_err,"-noiter         use 1 as iteration count\n");
        BIO_printf(bio_err,"-nocrypt        use or expect unencrypted private key\n");
        BIO_printf(bio_err,"-v2 alg         use PKCS#5 v2.0 and cipher \"alg\"\n");
        BIO_printf(bio_err,"-v1 obj         use PKCS#5 v1.5 and cipher \"alg\"\n");
        pBVar3 = (BIO *)0x0;
        pcVar7 = " -engine e       use engine e, possibly a hardware device.\n";
        goto LAB_00039980;
      }
      cVar1 = *(char *)((int)&pBVar3->method + 2);
      if (cVar1 != '2') {
        if ((cVar1 != '1') || (uVar4 = (uint)*(byte *)((int)&pBVar3->method + 3), uVar4 != 0))
        goto LAB_00039640;
        if (*(char **)(iVar10 + 4) != (char *)0x0) {
          pbe_nid = OBJ_txt2nid(*(char **)(iVar10 + 4));
          iVar8 = iVar10 + 4;
          if (pbe_nid == 0) {
            BIO_printf(bio_err,"Unknown PBE algorithm %s\n",*(undefined4 *)(iVar10 + 4));
            uVar4 = 1;
          }
          goto LAB_0003961c;
        }
        goto LAB_00039664;
      }
      uVar4 = (uint)*(byte *)((int)&pBVar3->method + 3);
      if (uVar4 != 0) goto LAB_00039640;
      if (*(char **)(iVar10 + 4) == (char *)0x0) goto LAB_00039664;
      cipher = (BIO *)EVP_get_cipherbyname(*(char **)(iVar10 + 4));
      iVar8 = iVar10 + 4;
      if (cipher == (BIO *)0x0) {
        BIO_printf(bio_err,"Unknown cipher %s\n",*(undefined4 *)(iVar10 + 4));
        uVar4 = 1;
      }
LAB_0003961c:
      iVar10 = iVar8 + 4;
      if (uVar4 != 0) goto LAB_00039870;
      pBVar3 = *(BIO **)(iVar8 + 4);
    } while ((pBVar3 != (BIO *)0x0) && (*(char *)&pBVar3->method == '-'));
  }
  uVar9 = setup_engine(bio_err,local_80,0);
  pBVar3 = (BIO *)app_passwd(bio_err,local_88,local_84,&local_68,&local_64);
  if (pBVar3 == (BIO *)0x0) {
    pcVar7 = "Error getting passwords\n";
LAB_00039980:
    BIO_printf(bio_err,pcVar7);
    uVar9 = 1;
    bp_00 = pBVar3;
    bp = pBVar3;
    p8 = pBVar3;
    local_74 = pBVar3;
    goto LAB_00039568;
  }
  if (cipher == (BIO *)0x0 && pbe_nid == -1) {
    pbe_nid = 10;
  }
  if (local_7c == (BIO *)0x0) {
    bp_00 = BIO_new_fp(stdin,0);
  }
  else {
    pBVar3 = BIO_new_file((char *)local_7c,"rb");
    bp_00 = pBVar3;
    if (pBVar3 == (BIO *)0x0) {
      BIO_printf(bio_err,"Can\'t open input file %s\n",local_7c);
      uVar9 = 1;
      bp = pBVar3;
      p8 = pBVar3;
      local_74 = pBVar3;
      goto LAB_00039568;
    }
  }
  if (local_78 == (BIO *)0x0) {
    bp = BIO_new_fp(stdout,0);
  }
  else {
    pBVar3 = BIO_new_file((char *)local_78,"wb");
    bp = pBVar3;
    if (pBVar3 == (BIO *)0x0) {
      BIO_printf(bio_err,"Can\'t open output file %s\n",local_78);
      uVar9 = 1;
      p8 = pBVar3;
      local_74 = pBVar3;
      goto LAB_00039568;
    }
  }
  if (local_8c != (BIO *)0x0) {
    pBVar3 = (BIO *)load_key(bio_err,local_7c,local_90,1,local_68,uVar9,"key");
    if (pBVar3 == (BIO *)0x0) {
      uVar9 = 1;
      p8 = pBVar3;
      local_74 = pBVar3;
    }
    else {
      p8 = (BIO *)EVP_PKEY2PKCS8_broken((EVP_PKEY *)pBVar3,(int)local_6c);
      if (p8 == (BIO *)0x0) {
        uVar9 = 1;
        BIO_printf(bio_err,"Error converting key\n");
        ERR_print_errors(bio_err);
        local_74 = p8;
      }
      else if (local_74 == (BIO *)0x0) {
        pcVar7 = local_64;
        if (local_64 == (char *)0x0) {
          iVar10 = EVP_read_pw_string(acStack_60,0x32,"Enter Encryption Password:",1);
          if (iVar10 != 0) {
            uVar9 = 1;
            goto LAB_00039568;
          }
          pcVar7 = acStack_60;
        }
        uVar9 = 0;
        app_RAND_load_file(0,bio_err,0);
        sVar6 = strlen(pcVar7);
        local_74 = (BIO *)PKCS8_encrypt(pbe_nid,(EVP_CIPHER *)cipher,pcVar7,sVar6,(uchar *)0x0,0,
                                        local_70,(PKCS8_PRIV_KEY_INFO *)p8);
        if (local_74 == (BIO *)0x0) {
          uVar9 = 1;
          BIO_printf(bio_err,"Error encrypting key\n");
          ERR_print_errors(bio_err);
        }
        else {
          app_RAND_write_file(0,bio_err);
          if (local_94 == 3) {
            uVar9 = 0;
            PEM_write_bio_PKCS8(bp,(X509_SIG *)local_74);
          }
          else if (local_94 == 1) {
            i2d_PKCS8_bio(bp,(X509_SIG *)local_74);
          }
          else {
            uVar9 = 1;
            BIO_printf(bio_err,"Bad format specified for key\n");
          }
        }
      }
      else if (local_94 == 3) {
        uVar9 = 0;
        PEM_write_bio_PKCS8_PRIV_KEY_INFO(bp,(PKCS8_PRIV_KEY_INFO *)p8);
        local_74 = (BIO *)0x0;
      }
      else if (local_94 == 1) {
        uVar9 = 0;
        i2d_PKCS8_PRIV_KEY_INFO_bio(bp,(PKCS8_PRIV_KEY_INFO *)p8);
        local_74 = (BIO *)0x0;
      }
      else {
        uVar9 = 1;
        BIO_printf(bio_err,"Bad format specified for key\n");
        local_74 = (BIO *)0x0;
      }
    }
    goto LAB_00039568;
  }
  if (local_74 == (BIO *)0x0) {
    if (local_90 == 3) {
      pBVar3 = (BIO *)PEM_read_bio_PKCS8(bp_00,(X509_SIG **)0x0,(undefined1 *)0x0,(void *)0x0);
    }
    else {
      if (local_90 != 1) goto LAB_00039840;
      pBVar3 = (BIO *)d2i_PKCS8_bio(bp_00,(X509_SIG **)0x0);
    }
    if (pBVar3 == (BIO *)0x0) {
      uVar9 = 1;
      BIO_printf(bio_err,"Error reading key\n");
      ERR_print_errors(bio_err);
      p8 = pBVar3;
      local_74 = pBVar3;
      goto LAB_00039568;
    }
    pcVar7 = local_68;
    if (local_68 == (char *)0x0) {
      pcVar7 = acStack_60;
      EVP_read_pw_string(acStack_60,0x32,"Enter Password:",0);
    }
    sVar6 = strlen(pcVar7);
    p8 = (BIO *)PKCS8_decrypt((X509_SIG *)pBVar3,pcVar7,sVar6);
    local_8c = pBVar3;
  }
  else if (local_90 == 3) {
    p8 = (BIO *)PEM_read_bio_PKCS8_PRIV_KEY_INFO
                          (bp_00,(PKCS8_PRIV_KEY_INFO **)0x0,(undefined1 *)0x0,(void *)0x0);
  }
  else {
    local_74 = local_8c;
    if (local_90 != 1) {
LAB_00039840:
      BIO_printf(bio_err,"Bad format specified for key\n");
      uVar9 = 1;
      pBVar3 = local_74;
      p8 = local_74;
      goto LAB_00039568;
    }
    p8 = (BIO *)d2i_PKCS8_PRIV_KEY_INFO_bio(bp_00,(PKCS8_PRIV_KEY_INFO **)0x0);
  }
  local_74 = local_8c;
  if (p8 == (BIO *)0x0) {
    uVar9 = 1;
    BIO_printf(bio_err,"Error decrypting key\n");
    ERR_print_errors(bio_err);
    pBVar3 = p8;
  }
  else {
    pBVar3 = (BIO *)EVP_PKCS82PKEY((PKCS8_PRIV_KEY_INFO *)p8);
    if (pBVar3 == (BIO *)0x0) {
      uVar9 = 1;
      BIO_printf(bio_err,"Error converting key\n");
      ERR_print_errors(bio_err);
    }
    else {
      if (p8->method != (BIO_METHOD *)0x0) {
        BIO_printf(bio_err,"Warning: broken key encoding: ");
        switch(p8->method) {
        case (BIO_METHOD *)0x1:
          BIO_printf(bio_err,"No Octet String in PrivateKey\n");
          break;
        case (BIO_METHOD *)0x2:
          BIO_printf(bio_err,"DSA parameters included in PrivateKey\n");
          break;
        case (BIO_METHOD *)0x3:
          BIO_printf(bio_err,"DSA public key include in PrivateKey\n");
          break;
        case (BIO_METHOD *)0x4:
          BIO_printf(bio_err,"DSA private key value is negative\n");
          break;
        default:
          BIO_printf(bio_err,"Unknown broken type\n");
        }
      }
      if (local_94 == 3) {
        uVar9 = 0;
        PEM_write_bio_PrivateKey
                  (bp,(EVP_PKEY *)pBVar3,(EVP_CIPHER *)0x0,(uchar *)0x0,0,(undefined1 *)0x0,local_64
                  );
      }
      else if (local_94 == 1) {
        i2d_PrivateKey_bio(bp,(EVP_PKEY *)pBVar3);
        uVar9 = 0;
      }
      else {
        uVar9 = 1;
        BIO_printf(bio_err,"Bad format specified for key\n");
      }
    }
  }
LAB_00039568:
  X509_SIG_free((X509_SIG *)local_74);
  PKCS8_PRIV_KEY_INFO_free((PKCS8_PRIV_KEY_INFO *)p8);
  EVP_PKEY_free((EVP_PKEY *)pBVar3);
  BIO_free_all(bp);
  BIO_free(bp_00);
  if (local_68 != (char *)0x0) {
    CRYPTO_free(local_68);
  }
  if (local_64 != (char *)0x0) {
    CRYPTO_free(local_64);
  }
  if (local_2c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar9);
}

