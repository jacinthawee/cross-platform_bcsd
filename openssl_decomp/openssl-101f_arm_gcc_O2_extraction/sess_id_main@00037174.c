
undefined4 sess_id_main(int param_1,int param_2)

{
  char **ppcVar1;
  int iVar2;
  BIO_METHOD *pBVar3;
  BIO *pBVar4;
  long lVar5;
  SSL_SESSION *s;
  X509 *x;
  size_t sid_ctx_len;
  undefined *puVar6;
  undefined **ppuVar7;
  char *__s1;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  char **ppcVar13;
  char *local_3c;
  char *local_38;
  uint local_34;
  uchar *local_30;
  uint local_2c;
  
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    pBVar3 = BIO_s_file();
    bio_err = BIO_new(pBVar3);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  param_1 = param_1 + -1;
  ppcVar13 = (char **)(param_2 + 4);
  if (param_1 < 1) {
    ERR_load_crypto_strings();
    pBVar3 = BIO_s_file();
    pBVar4 = BIO_new(pBVar3);
    if (pBVar4 == (BIO *)0x0) goto LAB_00037528;
    iVar9 = 3;
    uVar11 = 0;
    iVar10 = 3;
    local_38 = (char *)0x0;
    local_30 = (uchar *)0x0;
    local_34 = 0;
    local_2c = 0;
LAB_00037464:
    BIO_ctrl(pBVar4,0x6a,0,stdin);
  }
  else {
    uVar11 = 0;
    iVar10 = 3;
    local_2c = 0;
    uVar12 = 0;
    local_34 = 0;
    iVar9 = 3;
    local_30 = (uchar *)0x0;
    local_38 = (char *)0x0;
    local_3c = (char *)0x0;
LAB_000371e2:
    do {
      __s1 = *ppcVar13;
      iVar2 = strcmp(__s1,"-inform");
      if (iVar2 == 0) {
        param_1 = param_1 + -1;
        if (param_1 == 0) goto LAB_00037344;
        ppcVar1 = ppcVar13 + 1;
        ppcVar13 = ppcVar13 + 1;
        iVar9 = str2fmt(*ppcVar1);
      }
      else {
        iVar2 = strcmp(__s1,"-outform");
        if (iVar2 == 0) {
          if (param_1 == 1) goto LAB_00037344;
          param_1 = param_1 + -2;
          iVar10 = str2fmt(ppcVar13[1]);
          ppcVar13 = ppcVar13 + 2;
          if (param_1 < 1) break;
          goto LAB_000371e2;
        }
        if ((((*__s1 == '-') && (__s1[1] == 'i')) && (__s1[2] == 'n')) && (__s1[3] == '\0')) {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_00037344;
          local_3c = ppcVar13[1];
          ppcVar13 = ppcVar13 + 1;
        }
        else {
          iVar2 = strcmp(__s1,"-out");
          if (iVar2 == 0) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_00037344;
            local_38 = ppcVar13[1];
            ppcVar13 = ppcVar13 + 1;
          }
          else {
            iVar2 = strcmp(__s1,"-text");
            if (iVar2 == 0) {
              uVar11 = uVar12 + 1;
              uVar12 = uVar11;
            }
            else {
              iVar2 = strcmp(__s1,"-cert");
              if (iVar2 == 0) {
                uVar12 = uVar12 + 1;
                local_34 = uVar12;
              }
              else {
                iVar2 = strcmp(__s1,"-noout");
                if (iVar2 == 0) {
                  uVar12 = uVar12 + 1;
                  local_2c = uVar12;
                }
                else {
                  iVar2 = strcmp(__s1,"-context");
                  if (iVar2 != 0) {
                    BIO_printf(bio_err,"unknown option %s\n",__s1);
LAB_00037344:
                    ppuVar7 = &sess_id_usage;
                    puVar6 = sess_id_usage;
                    while (puVar6 != (undefined *)0x0) {
                      BIO_printf(bio_err,"%s");
                      ppuVar7 = ppuVar7 + 1;
                      puVar6 = *ppuVar7;
                    }
                    return 1;
                  }
                  param_1 = param_1 + -1;
                  if (param_1 == 0) goto LAB_00037344;
                  local_30 = (uchar *)ppcVar13[1];
                  ppcVar13 = ppcVar13 + 1;
                }
              }
            }
          }
        }
      }
      param_1 = param_1 + -1;
      ppcVar13 = ppcVar13 + 1;
    } while (0 < param_1);
    ERR_load_crypto_strings();
    pBVar3 = BIO_s_file();
    pBVar4 = BIO_new(pBVar3);
    if (pBVar4 == (BIO *)0x0) {
LAB_00037528:
      ERR_print_errors(bio_err);
      return 1;
    }
    if (local_3c == (char *)0x0) goto LAB_00037464;
    lVar5 = BIO_ctrl(pBVar4,0x6c,3,local_3c);
    if (lVar5 < 1) {
      perror(local_3c);
      goto LAB_000374ee;
    }
  }
  if (iVar9 == 1) {
    s = (SSL_SESSION *)ASN1_d2i_bio(SSL_SESSION_new + 1,d2i_SSL_SESSION + 1,pBVar4,(void **)0x0);
  }
  else {
    if (iVar9 != 3) {
      BIO_printf(bio_err,"bad input format specified for input crl\n");
      goto LAB_000374ee;
    }
    s = PEM_read_bio_SSL_SESSION(pBVar4,(SSL_SESSION **)0x0,(undefined1 *)0x0,(void *)0x0);
  }
  if (s == (SSL_SESSION *)0x0) {
    BIO_printf(bio_err,"unable to load SSL_SESSION\n");
    ERR_print_errors(bio_err);
LAB_000374ee:
    BIO_free(pBVar4);
    return 1;
  }
  BIO_free(pBVar4);
  x = SSL_SESSION_get0_peer(s);
  if (local_30 != (uchar *)0x0) {
    sid_ctx_len = strlen((char *)local_30);
    if (sid_ctx_len < 0x21) {
      SSL_SESSION_set1_id_context(s,local_30,sid_ctx_len);
      goto LAB_000373be;
    }
    BIO_printf(bio_err,"Context too long\n");
LAB_000372a2:
    uVar8 = 1;
    goto LAB_000372a4;
  }
LAB_000373be:
  uVar12 = count_leading_zeroes(local_2c);
  if (uVar11 != 0) {
    uVar11 = 1;
  }
  pBVar4 = (BIO *)(uVar11 | uVar12 >> 5);
  if (pBVar4 == (BIO *)0x0) {
LAB_000373d6:
    if ((local_34 | local_2c) == 0) {
      if (iVar10 == 1) {
        iVar9 = ASN1_i2d_bio(i2d_SSL_SESSION + 1,pBVar4,(uchar *)s);
      }
      else {
        if (iVar10 != 3) {
LAB_000373fa:
          uVar8 = 1;
          BIO_printf(bio_err,"bad output format specified for outfile\n");
          goto LAB_0003740a;
        }
        iVar9 = PEM_write_bio_SSL_SESSION(pBVar4,s);
      }
      if (iVar9 != 0) goto LAB_00037436;
      uVar8 = 1;
      BIO_printf(bio_err,"unable to write SSL_SESSION\n");
    }
    else {
      if (x == (X509 *)0x0) {
        uVar11 = 0;
      }
      else {
        uVar11 = uVar12 >> 5 & 1;
      }
      if (uVar11 != 0) {
        if (iVar10 == 1) {
          iVar9 = i2d_X509_bio(pBVar4,x);
        }
        else {
          if (iVar10 != 3) goto LAB_000373fa;
          iVar9 = PEM_write_bio_X509(pBVar4,x);
        }
        if (iVar9 == 0) {
          uVar8 = 1;
          BIO_printf(bio_err,"unable to write X509\n");
          goto LAB_0003740a;
        }
      }
LAB_00037436:
      uVar8 = 0;
    }
LAB_0003740a:
    if (pBVar4 == (BIO *)0x0) goto LAB_000372a4;
  }
  else {
    pBVar3 = BIO_s_file();
    pBVar4 = BIO_new(pBVar3);
    if (pBVar4 == (BIO *)0x0) {
      ERR_print_errors(bio_err);
      goto LAB_000372a2;
    }
    if (local_38 == (char *)0x0) {
      BIO_ctrl(pBVar4,0x6a,0,stdout);
LAB_0003749e:
      if ((uVar11 != 0) && (SSL_SESSION_print(pBVar4,s), local_34 != 0)) {
        if (x == (X509 *)0x0) {
          BIO_puts(pBVar4,"No certificate present\n");
        }
        else {
          X509_print(pBVar4,x);
        }
      }
      goto LAB_000373d6;
    }
    lVar5 = BIO_ctrl(pBVar4,0x6c,5,local_38);
    if (0 < lVar5) goto LAB_0003749e;
    uVar8 = 1;
    perror(local_38);
  }
  BIO_free_all(pBVar4);
LAB_000372a4:
  SSL_SESSION_free(s);
  return uVar8;
}

