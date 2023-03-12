
/* WARNING: Restarted to delay deadcode elimination for space: ram */

EVP_CIPHER * pkey_main(undefined4 param_1,int param_2)

{
  EVP_CIPHER **ppEVar1;
  char cVar2;
  BIO *x;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  BIO *bp;
  EVP_CIPHER *pEVar6;
  EVP_CIPHER *pEVar7;
  int *piVar8;
  EVP_CIPHER *pEVar9;
  int iVar10;
  EVP_CIPHER *pEVar11;
  undefined4 uVar12;
  EVP_CIPHER *local_50;
  EVP_CIPHER *local_4c;
  EVP_CIPHER *local_48;
  EVP_CIPHER *local_44;
  EVP_CIPHER *local_40;
  EVP_CIPHER *local_3c;
  EVP_CIPHER *local_38;
  EVP_CIPHER *local_34;
  void *local_30;
  void *local_2c [2];
  
  local_30 = (void *)0x0;
  local_2c[0] = (void *)0x0;
  if (bio_err == (BIO *)0x0) {
    bio_err = BIO_new_fp(stderr,0);
  }
  x = (BIO *)load_config(bio_err,0);
  if (x == (BIO *)0x0) {
    local_40 = (EVP_CIPHER *)0x1;
    bp = x;
  }
  else {
    ERR_load_crypto_strings();
    OPENSSL_add_all_algorithms_noconf();
    pEVar7 = *(EVP_CIPHER **)(param_2 + 4);
    if (pEVar7 == (EVP_CIPHER *)0x0) {
      iVar10 = 3;
      uVar12 = 3;
      pEVar6 = pEVar7;
      pEVar11 = pEVar7;
      local_50 = pEVar7;
      local_4c = pEVar7;
      local_48 = pEVar7;
      local_44 = pEVar7;
      local_40 = pEVar7;
      local_3c = pEVar7;
      local_38 = pEVar7;
      local_34 = pEVar7;
    }
    else {
      cVar2 = *(char *)&pEVar7->nid;
      pEVar6 = (EVP_CIPHER *)0x0;
      iVar10 = 3;
      local_3c = (EVP_CIPHER *)0x0;
      local_40 = (EVP_CIPHER *)0x0;
      local_48 = (EVP_CIPHER *)0x0;
      pEVar11 = (EVP_CIPHER *)0x0;
      local_38 = (EVP_CIPHER *)0x0;
      local_44 = (EVP_CIPHER *)0x0;
      uVar12 = 3;
      local_34 = (EVP_CIPHER *)0x0;
      local_50 = (EVP_CIPHER *)0x0;
      local_4c = (EVP_CIPHER *)0x0;
      piVar8 = (int *)(param_2 + 4);
      pEVar9 = pEVar7;
      pEVar7 = pEVar6;
      while (cVar2 == '-') {
        uVar3 = strcmp((char *)pEVar9,"-inform");
        if (uVar3 == 0) {
          if (piVar8[1] != 0) {
            uVar12 = str2fmt();
            piVar8 = piVar8 + 1;
            goto LAB_0003a268;
          }
LAB_0003a396:
          uVar3 = 1;
LAB_0003a268:
          if (uVar3 != 0) {
LAB_0003a2ba:
            BIO_printf(bio_err,"Usage pkey [options]\n");
            BIO_printf(bio_err,"where options are\n");
            BIO_printf(bio_err,"-in file        input file\n");
            BIO_printf(bio_err,"-inform X       input format (DER or PEM)\n");
            BIO_printf(bio_err,"-passin arg     input file pass phrase source\n");
            BIO_printf(bio_err,"-outform X      output format (DER or PEM)\n");
            BIO_printf(bio_err,"-out file       output file\n");
            BIO_printf(bio_err,"-passout arg    output file pass phrase source\n");
            BIO_printf(bio_err,"-engine e       use engine e, possibly a hardware device.\n");
            return (EVP_CIPHER *)0x1;
          }
        }
        else {
          iVar4 = strcmp((char *)pEVar9,"-outform");
          if (iVar4 != 0) {
            uVar3 = strcmp((char *)pEVar9,"-passin");
            if (uVar3 == 0) {
              pEVar6 = (EVP_CIPHER *)piVar8[1];
              pEVar9 = pEVar6;
            }
            else {
              uVar3 = strcmp((char *)pEVar9,"-passout");
              if (uVar3 == 0) {
                pEVar11 = (EVP_CIPHER *)piVar8[1];
                pEVar9 = pEVar11;
              }
              else {
                uVar3 = strcmp((char *)pEVar9,"-engine");
                if (uVar3 != 0) {
                  if (((*(char *)((int)&pEVar9->nid + 1) == 'i') &&
                      (*(char *)((int)&pEVar9->nid + 2) == 'n')) &&
                     (uVar3 = (uint)*(byte *)((int)&pEVar9->nid + 3), uVar3 == 0)) {
                    ppEVar1 = (EVP_CIPHER **)(piVar8 + 1);
                    if (*ppEVar1 == (EVP_CIPHER *)0x0) goto LAB_0003a396;
                    piVar8 = piVar8 + 1;
                    local_4c = *ppEVar1;
                  }
                  else {
                    uVar3 = strcmp((char *)pEVar9,"-out");
                    if (uVar3 == 0) {
                      ppEVar1 = (EVP_CIPHER **)(piVar8 + 1);
                      if (*ppEVar1 == (EVP_CIPHER *)0x0) goto LAB_0003a396;
                      piVar8 = piVar8 + 1;
                      local_50 = *ppEVar1;
                    }
                    else {
                      uVar3 = strcmp((char *)pEVar9,"-pubin");
                      if (uVar3 == 0) {
                        local_48 = (EVP_CIPHER *)0x1;
                        local_38 = (EVP_CIPHER *)0x1;
                        local_44 = (EVP_CIPHER *)0x1;
                      }
                      else {
                        uVar3 = strcmp((char *)pEVar9,"-pubout");
                        if (uVar3 == 0) {
                          local_38 = (EVP_CIPHER *)0x1;
                        }
                        else {
                          uVar3 = strcmp((char *)pEVar9,"-text_pub");
                          if (uVar3 == 0) {
                            local_40 = (EVP_CIPHER *)0x1;
                            local_48 = (EVP_CIPHER *)0x1;
                          }
                          else {
                            uVar3 = strcmp((char *)pEVar9,"-text");
                            if (uVar3 == 0) {
                              local_40 = (EVP_CIPHER *)0x1;
                            }
                            else {
                              uVar3 = strcmp((char *)pEVar9,"-noout");
                              if (uVar3 == 0) {
                                local_3c = (EVP_CIPHER *)0x1;
                              }
                              else {
                                local_34 = EVP_get_cipherbyname((char *)((int)&pEVar9->nid + 1));
                                uVar3 = 0;
                                if (local_34 == (EVP_CIPHER *)0x0) {
                                  BIO_printf(bio_err,"Unknown cipher %s\n",*piVar8 + 1);
                                  uVar3 = 1;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                  goto LAB_0003a268;
                }
                pEVar7 = (EVP_CIPHER *)piVar8[1];
                pEVar9 = pEVar7;
              }
            }
            if (pEVar9 == (EVP_CIPHER *)0x0) goto LAB_0003a2ba;
            piVar8 = piVar8 + 1;
            goto LAB_0003a268;
          }
          if (piVar8[1] == 0) goto LAB_0003a396;
          iVar10 = str2fmt();
          piVar8 = piVar8 + 1;
        }
        pEVar9 = (EVP_CIPHER *)piVar8[1];
        if (pEVar9 == (EVP_CIPHER *)0x0) break;
        piVar8 = piVar8 + 1;
        cVar2 = *(char *)&pEVar9->nid;
      }
    }
    uVar5 = setup_engine(bio_err,pEVar7,0);
    x = (BIO *)app_passwd(bio_err,pEVar6,pEVar11,&local_30,local_2c);
    if (x == (BIO *)0x0) {
      BIO_printf(bio_err,"Error getting passwords\n");
      local_40 = (EVP_CIPHER *)0x1;
      bp = x;
    }
    else {
      if (local_50 == (EVP_CIPHER *)0x0) {
        bp = BIO_new_fp(stdout,0);
      }
      else {
        x = BIO_new_file((char *)local_50,"wb");
        bp = x;
        if (x == (BIO *)0x0) {
          BIO_printf(bio_err,"Can\'t open output file %s\n",local_50);
          local_40 = (EVP_CIPHER *)0x1;
          goto LAB_0003a348;
        }
      }
      if (local_44 == (EVP_CIPHER *)0x0) {
        x = (BIO *)load_key(bio_err,local_4c,uVar12,1,local_30,uVar5,"key");
      }
      else {
        x = (BIO *)load_pubkey(bio_err,local_4c,uVar12,1,local_30,uVar5,"Public Key");
      }
      if (x == (BIO *)0x0) {
        local_40 = (EVP_CIPHER *)0x1;
      }
      else {
        if (local_3c == (EVP_CIPHER *)0x0) {
          if (iVar10 == 3) {
            if (local_38 == (EVP_CIPHER *)0x0) {
              PEM_write_bio_PrivateKey
                        (bp,(EVP_PKEY *)x,local_34,(uchar *)0x0,0,(undefined1 *)0x0,local_2c[0]);
            }
            else {
              PEM_write_bio_PUBKEY(bp,(EVP_PKEY *)x);
            }
          }
          else {
            if (iVar10 != 1) {
              local_40 = (EVP_CIPHER *)0x1;
              BIO_printf(bio_err,"Bad format specified for key\n");
              goto LAB_0003a348;
            }
            if (local_38 == (EVP_CIPHER *)0x0) {
              i2d_PrivateKey_bio(bp,(EVP_PKEY *)x);
            }
            else {
              i2d_PUBKEY_bio(bp,(EVP_PKEY *)x);
            }
          }
        }
        if (local_40 != (EVP_CIPHER *)0x0) {
          if (local_48 == (EVP_CIPHER *)0x0) {
            EVP_PKEY_print_private(bp,(EVP_PKEY *)x,0,(ASN1_PCTX *)0x0);
            local_40 = local_48;
          }
          else {
            EVP_PKEY_print_public(bp,(EVP_PKEY *)x,0,(ASN1_PCTX *)0x0);
            local_40 = (EVP_CIPHER *)0x0;
          }
        }
      }
    }
  }
LAB_0003a348:
  EVP_PKEY_free((EVP_PKEY *)x);
  BIO_free_all(bp);
  BIO_free((BIO *)0x0);
  if (local_30 != (void *)0x0) {
    CRYPTO_free(local_30);
  }
  if (local_2c[0] == (void *)0x0) {
    return local_40;
  }
  CRYPTO_free(local_2c[0]);
  return local_40;
}

