
undefined4 pkcs8_main(undefined4 param_1,int param_2)

{
  byte bVar1;
  byte *__s1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  undefined4 uVar5;
  size_t passlen;
  int iVar6;
  undefined4 extraout_ECX;
  X509_SIG *extraout_ECX_00;
  undefined4 extraout_ECX_01;
  BIO *bp;
  X509_SIG *pXVar7;
  EVP_CIPHER *cipher;
  PKCS8_PRIV_KEY_INFO *p8;
  byte *pbVar8;
  BIO *bp_00;
  byte *pbVar9;
  int in_GS_OFFSET;
  bool bVar10;
  bool bVar11;
  byte bVar12;
  char *pcVar13;
  undefined4 local_90;
  EVP_PKEY *local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_74;
  char *local_70;
  X509_SIG *local_68;
  X509_SIG *local_64;
  int local_60;
  char *local_5c;
  char *local_58;
  char local_52 [50];
  int local_20;
  
  bVar12 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_5c = (char *)0x0;
  local_58 = (char *)0x0;
  if (bio_err == (BIO *)0x0) {
    bio_err = BIO_new_fp(stderr,0);
  }
  iVar4 = load_config(bio_err,0);
  if (iVar4 != 0) {
    ERR_load_crypto_strings();
    OPENSSL_add_all_algorithms_noconf();
    __s1 = *(byte **)(param_2 + 4);
    if (__s1 == (byte *)0x0) {
      local_74 = 0;
      bVar3 = false;
      cipher = (EVP_CIPHER *)0x0;
      local_60 = 0;
      local_84 = 3;
      local_8c = (EVP_PKEY *)0x3;
      local_68 = (X509_SIG *)0x800;
      local_88 = -1;
      bVar2 = false;
      local_7c = 0;
      local_80 = 0;
      local_64 = (X509_SIG *)0x0;
      local_70 = (char *)0x0;
    }
    else {
      bVar1 = *__s1;
      local_74 = 0;
      cipher = (EVP_CIPHER *)0x0;
      bVar3 = false;
      local_60 = 0;
      local_84 = 3;
      local_8c = (EVP_PKEY *)0x3;
      local_68 = (X509_SIG *)0x800;
      local_88 = -1;
      bVar2 = false;
      local_7c = 0;
      local_80 = 0;
      local_64 = (X509_SIG *)0x0;
      local_70 = (char *)0x0;
      while (bVar1 == 0x2d) {
        iVar4 = param_2 + 4;
        bVar1 = __s1[1];
        bVar10 = bVar1 < 0x76;
        bVar11 = bVar1 == 0x76;
        if (!bVar11) {
LAB_080842f2:
          iVar6 = 8;
          pbVar8 = __s1;
          pbVar9 = (byte *)"-inform";
          do {
            if (iVar6 == 0) break;
            iVar6 = iVar6 + -1;
            bVar10 = *pbVar8 < *pbVar9;
            bVar11 = *pbVar8 == *pbVar9;
            pbVar8 = pbVar8 + (uint)bVar12 * -2 + 1;
            pbVar9 = pbVar9 + (uint)bVar12 * -2 + 1;
          } while (bVar11);
          bVar10 = (!bVar10 && !bVar11) == bVar10;
          if (bVar10) {
            if (*(int *)(param_2 + 8) == 0) goto LAB_08084330;
            iVar4 = param_2 + 8;
            local_8c = (EVP_PKEY *)str2fmt(*(int *)(param_2 + 8));
            bVar10 = false;
            goto LAB_080842c6;
          }
          iVar6 = 9;
          pbVar8 = __s1;
          pbVar9 = (byte *)"-outform";
          do {
            if (iVar6 == 0) break;
            iVar6 = iVar6 + -1;
            bVar10 = *pbVar8 == *pbVar9;
            pbVar8 = pbVar8 + (uint)bVar12 * -2 + 1;
            pbVar9 = pbVar9 + (uint)bVar12 * -2 + 1;
          } while (bVar10);
          if (bVar10) {
            if (*(int *)(param_2 + 8) == 0) goto LAB_08084330;
            iVar4 = param_2 + 8;
            local_84 = str2fmt(*(int *)(param_2 + 8));
            bVar10 = false;
            goto LAB_080842c6;
          }
          iVar6 = 7;
          pbVar8 = __s1;
          pbVar9 = (byte *)"-topk8";
          do {
            if (iVar6 == 0) break;
            iVar6 = iVar6 + -1;
            bVar10 = *pbVar8 == *pbVar9;
            pbVar8 = pbVar8 + (uint)bVar12 * -2 + 1;
            pbVar9 = pbVar9 + (uint)bVar12 * -2 + 1;
          } while (bVar10);
          if (bVar10) {
            bVar10 = false;
            bVar2 = true;
            goto LAB_080842c6;
          }
          iVar6 = 8;
          pbVar8 = __s1;
          pbVar9 = (byte *)"-noiter";
          do {
            if (iVar6 == 0) break;
            iVar6 = iVar6 + -1;
            bVar10 = *pbVar8 == *pbVar9;
            pbVar8 = pbVar8 + (uint)bVar12 * -2 + 1;
            pbVar9 = pbVar9 + (uint)bVar12 * -2 + 1;
          } while (bVar10);
          if (bVar10) {
            bVar10 = false;
            local_68 = (X509_SIG *)0x1;
            goto LAB_080842c6;
          }
          iVar6 = 9;
          pbVar8 = __s1;
          pbVar9 = (byte *)"-nocrypt";
          do {
            if (iVar6 == 0) break;
            iVar6 = iVar6 + -1;
            bVar10 = *pbVar8 == *pbVar9;
            pbVar8 = pbVar8 + (uint)bVar12 * -2 + 1;
            pbVar9 = pbVar9 + (uint)bVar12 * -2 + 1;
          } while (bVar10);
          if (bVar10) {
            bVar10 = false;
            bVar3 = true;
            goto LAB_080842c6;
          }
          iVar6 = 7;
          pbVar8 = __s1;
          pbVar9 = (byte *)"-nooct";
          do {
            if (iVar6 == 0) break;
            iVar6 = iVar6 + -1;
            bVar10 = *pbVar8 == *pbVar9;
            pbVar8 = pbVar8 + (uint)bVar12 * -2 + 1;
            pbVar9 = pbVar9 + (uint)bVar12 * -2 + 1;
          } while (bVar10);
          if (bVar10) {
            bVar10 = false;
            local_60 = 1;
            goto LAB_080842c6;
          }
          iVar6 = 6;
          pbVar8 = __s1;
          pbVar9 = (byte *)"-nsdb";
          do {
            if (iVar6 == 0) break;
            iVar6 = iVar6 + -1;
            bVar10 = *pbVar8 == *pbVar9;
            pbVar8 = pbVar8 + (uint)bVar12 * -2 + 1;
            pbVar9 = pbVar9 + (uint)bVar12 * -2 + 1;
          } while (bVar10);
          if (bVar10) {
            bVar10 = false;
            local_60 = 3;
            goto LAB_080842c6;
          }
          iVar6 = 7;
          pbVar8 = __s1;
          pbVar9 = (byte *)"-embed";
          do {
            if (iVar6 == 0) break;
            iVar6 = iVar6 + -1;
            bVar10 = *pbVar8 == *pbVar9;
            pbVar8 = pbVar8 + (uint)bVar12 * -2 + 1;
            pbVar9 = pbVar9 + (uint)bVar12 * -2 + 1;
          } while (bVar10);
          if (bVar10) {
            bVar10 = false;
            local_60 = 2;
            goto LAB_080842c6;
          }
          iVar6 = 8;
          pbVar8 = __s1;
          pbVar9 = (byte *)"-passin";
          do {
            if (iVar6 == 0) break;
            iVar6 = iVar6 + -1;
            bVar10 = *pbVar8 == *pbVar9;
            pbVar8 = pbVar8 + (uint)bVar12 * -2 + 1;
            pbVar9 = pbVar9 + (uint)bVar12 * -2 + 1;
          } while (bVar10);
          if (bVar10) {
            local_80 = *(int *)(param_2 + 8);
            iVar4 = local_80;
          }
          else {
            iVar6 = 9;
            pbVar8 = __s1;
            pbVar9 = (byte *)"-passout";
            do {
              if (iVar6 == 0) break;
              iVar6 = iVar6 + -1;
              bVar10 = *pbVar8 == *pbVar9;
              pbVar8 = pbVar8 + (uint)bVar12 * -2 + 1;
              pbVar9 = pbVar9 + (uint)bVar12 * -2 + 1;
            } while (bVar10);
            if (bVar10) {
              local_7c = *(int *)(param_2 + 8);
              iVar4 = local_7c;
            }
            else {
              iVar6 = 8;
              pbVar8 = __s1;
              pbVar9 = (byte *)"-engine";
              do {
                if (iVar6 == 0) break;
                iVar6 = iVar6 + -1;
                bVar10 = *pbVar8 == *pbVar9;
                pbVar8 = pbVar8 + (uint)bVar12 * -2 + 1;
                pbVar9 = pbVar9 + (uint)bVar12 * -2 + 1;
              } while (bVar10);
              if (!bVar10) {
                if (((bVar1 == 0x69) && (__s1[2] == 0x6e)) && (__s1[3] == 0)) {
                  if (*(char **)(param_2 + 8) == (char *)0x0) {
LAB_08084330:
                    bVar10 = true;
                  }
                  else {
                    iVar4 = param_2 + 8;
                    bVar10 = false;
                    local_70 = *(char **)(param_2 + 8);
                  }
                }
                else {
                  iVar6 = strcmp((char *)__s1,"-out");
                  if ((iVar6 != 0) || (*(X509_SIG **)(param_2 + 8) == (X509_SIG *)0x0))
                  goto LAB_08084330;
                  iVar4 = param_2 + 8;
                  bVar10 = false;
                  local_64 = *(X509_SIG **)(param_2 + 8);
                }
                goto LAB_080842c6;
              }
              local_74 = *(int *)(param_2 + 8);
              iVar4 = local_74;
            }
          }
          if (iVar4 != 0) {
            iVar4 = param_2 + 8;
            bVar10 = false;
            goto LAB_080842c6;
          }
LAB_08084490:
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
          BIO_printf(bio_err," -engine e       use engine e, possibly a hardware device.\n");
          goto LAB_08084170;
        }
        if (__s1[2] != 0x32) {
          bVar10 = __s1[2] < 0x31;
          bVar11 = __s1[2] == 0x31;
          if (bVar11) {
            bVar10 = false;
            bVar11 = __s1[3] == 0;
            if (bVar11) {
              if (*(char **)(param_2 + 8) == (char *)0x0) goto LAB_08084330;
              iVar4 = param_2 + 8;
              local_88 = OBJ_txt2nid(*(char **)(param_2 + 8));
              bVar10 = false;
              if (local_88 == 0) {
                BIO_printf(bio_err,"Unknown PBE algorithm %s\n",*(undefined4 *)(param_2 + 8));
                bVar10 = true;
              }
              goto LAB_080842c6;
            }
          }
          goto LAB_080842f2;
        }
        bVar10 = false;
        bVar11 = __s1[3] == 0;
        if (!bVar11) goto LAB_080842f2;
        if (*(char **)(param_2 + 8) == (char *)0x0) goto LAB_08084330;
        iVar4 = param_2 + 8;
        cipher = EVP_get_cipherbyname(*(char **)(param_2 + 8));
        bVar10 = false;
        if (cipher == (EVP_CIPHER *)0x0) {
          BIO_printf(bio_err,"Unknown cipher %s\n",*(undefined4 *)(param_2 + 8));
          bVar10 = true;
        }
LAB_080842c6:
        if (bVar10) goto LAB_08084490;
        __s1 = *(byte **)(iVar4 + 4);
        if (__s1 == (byte *)0x0) break;
        param_2 = iVar4;
        bVar1 = *__s1;
      }
    }
    pXVar7 = (X509_SIG *)0x0;
    uVar5 = setup_engine(bio_err,local_74,0);
    iVar4 = app_passwd(bio_err,local_80,local_7c,&local_5c,&local_58);
    if (iVar4 != 0) {
      iVar4 = local_88;
      if ((local_88 == -1) && (iVar4 = 10, cipher != (EVP_CIPHER *)0x0)) {
        iVar4 = local_88;
      }
      local_88 = iVar4;
      if (local_70 == (char *)0x0) {
        bp_00 = BIO_new_fp(stdin,0);
      }
      else {
        bp_00 = BIO_new_file(local_70,"rb");
        if (bp_00 == (BIO *)0x0) {
          p8 = (PKCS8_PRIV_KEY_INFO *)0x0;
          pXVar7 = (X509_SIG *)0x0;
          bp = (BIO *)0x0;
          BIO_printf(bio_err,"Can\'t open input file %s\n",local_70);
          local_90 = 1;
          local_8c = (EVP_PKEY *)0x0;
          goto LAB_08084188;
        }
      }
      if (local_64 != (X509_SIG *)0x0) {
        bp = BIO_new_file((char *)local_64,"wb");
        if (bp != (BIO *)0x0) goto LAB_080846ec;
        pcVar13 = "Can\'t open output file %s\n";
LAB_08084722:
        p8 = (PKCS8_PRIV_KEY_INFO *)0x0;
        pXVar7 = (X509_SIG *)0x0;
        BIO_printf(bio_err,pcVar13,local_64);
        local_90 = 1;
        local_8c = (EVP_PKEY *)0x0;
        goto LAB_08084188;
      }
      bp = BIO_new_fp(stdout,0);
LAB_080846ec:
      local_64 = pXVar7;
      if (bVar2) {
        local_8c = (EVP_PKEY *)load_key(bio_err,local_70,local_8c,1,local_5c,uVar5,"key");
        if (local_8c == (EVP_PKEY *)0x0) {
          local_90 = 1;
          p8 = (PKCS8_PRIV_KEY_INFO *)0x0;
          pXVar7 = (X509_SIG *)0x0;
          goto LAB_08084188;
        }
        p8 = EVP_PKEY2PKCS8_broken(local_8c,local_60);
        if (p8 == (PKCS8_PRIV_KEY_INFO *)0x0) {
          pXVar7 = (X509_SIG *)0x0;
          BIO_printf(bio_err,"Error converting key\n",0,0);
          ERR_print_errors(bio_err);
          local_90 = 1;
          goto LAB_08084188;
        }
        if (bVar3) {
          if (local_84 == 3) {
            pXVar7 = (X509_SIG *)0x0;
            PEM_write_bio_PKCS8_PRIV_KEY_INFO(bp,p8);
            local_90 = 0;
          }
          else if (local_84 == 1) {
            pXVar7 = (X509_SIG *)0x0;
            i2d_PKCS8_PRIV_KEY_INFO_bio(bp,p8);
            local_90 = 0;
          }
          else {
            pXVar7 = (X509_SIG *)0x0;
            BIO_printf(bio_err,"Bad format specified for key\n");
            local_90 = 1;
          }
          goto LAB_08084188;
        }
        pcVar13 = local_58;
        if (local_58 == (char *)0x0) {
          pcVar13 = local_52;
          iVar4 = EVP_read_pw_string(pcVar13,0x32,"Enter Encryption Password:",1);
          if (iVar4 != 0) {
            local_90 = 1;
            pXVar7 = (X509_SIG *)0x0;
            goto LAB_08084188;
          }
        }
        app_RAND_load_file(0,bio_err,0);
        passlen = strlen(pcVar13);
        pXVar7 = PKCS8_encrypt(local_88,cipher,pcVar13,passlen,(uchar *)0x0,0,(int)local_68,p8);
        if (pXVar7 == (X509_SIG *)0x0) {
          pcVar13 = "Error encrypting key\n";
          local_68 = pXVar7;
          goto LAB_08084c0d;
        }
        app_RAND_write_file(0,bio_err);
        if (local_84 == 3) {
          PEM_write_bio_PKCS8(bp,pXVar7);
          local_90 = 0;
          goto LAB_08084188;
        }
        if (local_84 == 1) {
          i2d_PKCS8_bio(bp,pXVar7);
          local_90 = 0;
          goto LAB_08084188;
        }
      }
      else {
        if (bVar3) {
          if (local_8c == (EVP_PKEY *)0x3) {
            local_68 = (X509_SIG *)0x0;
            pXVar7 = (X509_SIG *)0x0;
            p8 = PEM_read_bio_PKCS8_PRIV_KEY_INFO
                           (bp_00,(PKCS8_PRIV_KEY_INFO **)0x0,(undefined1 *)0x0,(void *)0x0);
          }
          else {
            if (local_8c != (EVP_PKEY *)0x1) {
LAB_0808471a:
              pcVar13 = "Bad format specified for key\n";
              goto LAB_08084722;
            }
            pXVar7 = (X509_SIG *)0x0;
            p8 = d2i_PKCS8_PRIV_KEY_INFO_bio(bp_00,(PKCS8_PRIV_KEY_INFO **)0x0);
            local_68 = local_64;
          }
        }
        else {
          if (local_8c == (EVP_PKEY *)0x3) {
            pXVar7 = PEM_read_bio_PKCS8(bp_00,(X509_SIG **)0x0,(undefined1 *)0x0,(void *)0x0);
            uVar5 = extraout_ECX_01;
          }
          else {
            if (local_8c != (EVP_PKEY *)0x1) goto LAB_0808471a;
            pXVar7 = d2i_PKCS8_bio(bp_00,(X509_SIG **)0x0);
            uVar5 = extraout_ECX;
          }
          if (pXVar7 == (X509_SIG *)0x0) {
            BIO_printf(bio_err,"Error reading key\n",uVar5,uVar5);
            p8 = (PKCS8_PRIV_KEY_INFO *)0x0;
            ERR_print_errors(bio_err);
            local_90 = 1;
            local_8c = (EVP_PKEY *)0x0;
            goto LAB_08084188;
          }
          pcVar13 = local_5c;
          if (local_5c == (char *)0x0) {
            pcVar13 = local_52;
            EVP_read_pw_string(pcVar13,0x32,"Enter Password:",0);
          }
          local_68 = (X509_SIG *)strlen(pcVar13);
          p8 = PKCS8_decrypt(pXVar7,pcVar13,(int)local_68);
        }
        if (p8 == (PKCS8_PRIV_KEY_INFO *)0x0) {
          BIO_printf(bio_err,"Error decrypting key\n");
          ERR_print_errors(bio_err);
          local_90 = 1;
          local_8c = (EVP_PKEY *)0x0;
          goto LAB_08084188;
        }
        local_8c = EVP_PKCS82PKEY(p8);
        if (local_8c == (EVP_PKEY *)0x0) {
          pcVar13 = "Error converting key\n";
LAB_08084c0d:
          BIO_printf(bio_err,pcVar13,local_68);
          ERR_print_errors(bio_err);
          local_90 = 1;
          goto LAB_08084188;
        }
        if (p8->broken != 0) {
          BIO_printf(bio_err,"Warning: broken key encoding: ");
          local_68 = (X509_SIG *)p8->broken;
          if (local_68 == (X509_SIG *)0x2) {
            BIO_printf(bio_err,"DSA parameters included in PrivateKey\n",2,2);
          }
          else if ((int)local_68 < 3) {
            if (local_68 == (X509_SIG *)0x1) {
              BIO_printf(bio_err,"No Octet String in PrivateKey\n",1,1);
            }
            else {
LAB_08084d63:
              local_68 = extraout_ECX_00;
              BIO_printf(bio_err,"Unknown broken type\n",extraout_ECX_00,extraout_ECX_00);
            }
          }
          else if (local_68 == (X509_SIG *)0x3) {
            BIO_printf(bio_err,"DSA public key include in PrivateKey\n",3,3);
          }
          else {
            if (local_68 != (X509_SIG *)&DAT_00000004) goto LAB_08084d63;
            BIO_printf(bio_err,"DSA private key value is negative\n",4,4);
          }
        }
        if (local_84 == 3) {
          PEM_write_bio_PrivateKey
                    (bp,local_8c,(EVP_CIPHER *)0x0,(uchar *)0x0,0,(undefined1 *)0x0,local_58);
          local_90 = 0;
          goto LAB_08084188;
        }
        if (local_84 == 1) {
          i2d_PrivateKey_bio(bp,local_8c);
          local_90 = 0;
          goto LAB_08084188;
        }
      }
      BIO_printf(bio_err,"Bad format specified for key\n",local_68);
      local_90 = 1;
      goto LAB_08084188;
    }
    BIO_printf(bio_err,"Error getting passwords\n");
  }
LAB_08084170:
  local_90 = 1;
  local_8c = (EVP_PKEY *)0x0;
  p8 = (PKCS8_PRIV_KEY_INFO *)0x0;
  pXVar7 = (X509_SIG *)0x0;
  bp = (BIO *)0x0;
  bp_00 = (BIO *)0x0;
LAB_08084188:
  X509_SIG_free(pXVar7);
  PKCS8_PRIV_KEY_INFO_free(p8);
  EVP_PKEY_free(local_8c);
  BIO_free_all(bp);
  BIO_free(bp_00);
  if (local_5c != (char *)0x0) {
    CRYPTO_free(local_5c);
  }
  if (local_58 != (char *)0x0) {
    CRYPTO_free(local_58);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return local_90;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

