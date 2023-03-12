
X509 * sess_id_main(int param_1,int param_2)

{
  byte **ppbVar1;
  byte *pbVar2;
  byte **ppbVar3;
  BIO_METHOD *pBVar4;
  BIO *pBVar5;
  long lVar6;
  SSL_SESSION *s;
  X509 *x;
  size_t sid_ctx_len;
  int iVar7;
  undefined1 *puVar8;
  byte *pbVar9;
  byte *pbVar10;
  bool bVar11;
  bool bVar12;
  byte bVar13;
  int local_44;
  int local_40;
  int local_3c;
  uint local_38;
  byte *local_34;
  byte *local_30;
  uint local_2c;
  uint local_28;
  byte *local_24;
  uint local_20;
  
  bVar13 = 0;
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    pBVar4 = BIO_s_file();
    bio_err = BIO_new(pBVar4);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  local_44 = param_1 + -1;
  ppbVar3 = (byte **)(param_2 + 4);
  bVar11 = false;
  bVar12 = local_44 == 0;
  if (local_44 < 1) {
    ERR_load_crypto_strings();
    pBVar4 = BIO_s_file();
    pBVar5 = BIO_new(pBVar4);
    if (pBVar5 == (BIO *)0x0) goto LAB_0807fce6;
    local_30 = (byte *)0x0;
    local_24 = (byte *)0x0;
    local_2c = 0;
    local_20 = 0;
    local_28 = 0;
    local_3c = 3;
    local_40 = 3;
LAB_0807fc60:
    BIO_ctrl(pBVar5,0x6a,0,stdin);
  }
  else {
    local_2c = 0;
    local_20 = 0;
    local_28 = 0;
    local_24 = (byte *)0x0;
    local_30 = (byte *)0x0;
    local_34 = (byte *)0x0;
    local_3c = 3;
    local_40 = 3;
    local_38 = 0;
LAB_0807f7aa:
    do {
      pbVar2 = *ppbVar3;
      iVar7 = 8;
      pbVar9 = pbVar2;
      pbVar10 = (byte *)"-inform";
      do {
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        bVar11 = *pbVar9 < *pbVar10;
        bVar12 = *pbVar9 == *pbVar10;
        pbVar9 = pbVar9 + (uint)bVar13 * -2 + 1;
        pbVar10 = pbVar10 + (uint)bVar13 * -2 + 1;
      } while (bVar12);
      bVar11 = (!bVar11 && !bVar12) == bVar11;
      if (bVar11) {
        local_44 = local_44 + -1;
        if (local_44 == 0) goto LAB_0807f9a8;
        ppbVar1 = ppbVar3 + 1;
        ppbVar3 = ppbVar3 + 1;
        local_40 = str2fmt(*ppbVar1);
LAB_0807f7a0:
        bVar11 = local_44 == 0;
        local_44 = local_44 + -1;
        bVar12 = local_44 == 0;
        ppbVar3 = ppbVar3 + 1;
        if (bVar12) break;
        goto LAB_0807f7aa;
      }
      iVar7 = 9;
      pbVar9 = pbVar2;
      pbVar10 = (byte *)"-outform";
      do {
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        bVar11 = *pbVar9 == *pbVar10;
        pbVar9 = pbVar9 + (uint)bVar13 * -2 + 1;
        pbVar10 = pbVar10 + (uint)bVar13 * -2 + 1;
      } while (bVar11);
      if (!bVar11) {
        bVar11 = *pbVar2 == 0x2d;
        if ((((bVar11) && (bVar11 = pbVar2[1] == 0x69, bVar11)) &&
            (bVar11 = pbVar2[2] == 0x6e, bVar11)) && (bVar11 = pbVar2[3] == 0, bVar11)) {
          local_44 = local_44 + -1;
          if (local_44 == 0) goto LAB_0807f9a8;
          local_34 = ppbVar3[1];
          ppbVar3 = ppbVar3 + 1;
        }
        else {
          iVar7 = 5;
          pbVar9 = pbVar2;
          pbVar10 = &DAT_081ea8e1;
          do {
            if (iVar7 == 0) break;
            iVar7 = iVar7 + -1;
            bVar11 = *pbVar9 == *pbVar10;
            pbVar9 = pbVar9 + (uint)bVar13 * -2 + 1;
            pbVar10 = pbVar10 + (uint)bVar13 * -2 + 1;
          } while (bVar11);
          if (bVar11) {
            local_44 = local_44 + -1;
            if (local_44 == 0) goto LAB_0807f9a8;
            local_30 = ppbVar3[1];
            ppbVar3 = ppbVar3 + 1;
          }
          else {
            iVar7 = 6;
            pbVar9 = pbVar2;
            pbVar10 = (byte *)"-text";
            do {
              if (iVar7 == 0) break;
              iVar7 = iVar7 + -1;
              bVar11 = *pbVar9 == *pbVar10;
              pbVar9 = pbVar9 + (uint)bVar13 * -2 + 1;
              pbVar10 = pbVar10 + (uint)bVar13 * -2 + 1;
            } while (bVar11);
            if (bVar11) {
              local_38 = local_38 + 1;
              local_2c = local_38;
            }
            else {
              iVar7 = 6;
              pbVar9 = pbVar2;
              pbVar10 = (byte *)0x8206f09;
              do {
                if (iVar7 == 0) break;
                iVar7 = iVar7 + -1;
                bVar11 = *pbVar9 == *pbVar10;
                pbVar9 = pbVar9 + (uint)bVar13 * -2 + 1;
                pbVar10 = pbVar10 + (uint)bVar13 * -2 + 1;
              } while (bVar11);
              if (bVar11) {
                local_38 = local_38 + 1;
                local_28 = local_38;
              }
              else {
                iVar7 = 7;
                pbVar9 = pbVar2;
                pbVar10 = (byte *)"-noout";
                do {
                  if (iVar7 == 0) break;
                  iVar7 = iVar7 + -1;
                  bVar11 = *pbVar9 == *pbVar10;
                  pbVar9 = pbVar9 + (uint)bVar13 * -2 + 1;
                  pbVar10 = pbVar10 + (uint)bVar13 * -2 + 1;
                } while (bVar11);
                if (bVar11) {
                  local_38 = local_38 + 1;
                  local_20 = local_38;
                }
                else {
                  iVar7 = 9;
                  pbVar9 = pbVar2;
                  pbVar10 = (byte *)"-context";
                  do {
                    if (iVar7 == 0) break;
                    iVar7 = iVar7 + -1;
                    bVar11 = *pbVar9 == *pbVar10;
                    pbVar9 = pbVar9 + (uint)bVar13 * -2 + 1;
                    pbVar10 = pbVar10 + (uint)bVar13 * -2 + 1;
                  } while (bVar11);
                  if (!bVar11) {
                    BIO_printf(bio_err,"unknown option %s\n",pbVar2);
LAB_0807f9a8:
                    puVar8 = sess_id_usage;
                    iVar7 = sess_id_usage._0_4_;
                    while (iVar7 != 0) {
                      puVar8 = (undefined1 *)((int)puVar8 + 4);
                      BIO_printf(bio_err,"%s",iVar7);
                      iVar7 = *(int *)puVar8;
                    }
                    return (X509 *)0x1;
                  }
                  local_44 = local_44 + -1;
                  if (local_44 == 0) goto LAB_0807f9a8;
                  local_24 = ppbVar3[1];
                  ppbVar3 = ppbVar3 + 1;
                }
              }
            }
          }
        }
        goto LAB_0807f7a0;
      }
      if (local_44 == 1) goto LAB_0807f9a8;
      local_3c = str2fmt(ppbVar3[1]);
      ppbVar3 = ppbVar3 + 2;
      bVar11 = local_44 == 1;
      local_44 = local_44 + -2;
      bVar12 = local_44 == 0;
    } while (!bVar12);
    ERR_load_crypto_strings();
    pBVar4 = BIO_s_file();
    pBVar5 = BIO_new(pBVar4);
    if (pBVar5 == (BIO *)0x0) {
LAB_0807fce6:
      ERR_print_errors(bio_err);
      return (X509 *)0x1;
    }
    if (local_34 == (byte *)0x0) goto LAB_0807fc60;
    lVar6 = BIO_ctrl(pBVar5,0x6c,3,local_34);
    if (lVar6 < 1) {
      perror((char *)local_34);
      goto LAB_0807fc8e;
    }
  }
  if (local_40 == 1) {
    s = (SSL_SESSION *)ASN1_d2i_bio(SSL_SESSION_new,d2i_SSL_SESSION,pBVar5,(void **)0x0);
  }
  else {
    if (local_40 != 3) {
      BIO_printf(bio_err,"bad input format specified for input crl\n");
      goto LAB_0807fc8e;
    }
    s = PEM_read_bio_SSL_SESSION(pBVar5,(SSL_SESSION **)0x0,(undefined1 *)0x0,(void *)0x0);
  }
  if (s == (SSL_SESSION *)0x0) {
    BIO_printf(bio_err,"unable to load SSL_SESSION\n");
    ERR_print_errors(bio_err);
LAB_0807fc8e:
    BIO_free(pBVar5);
    return (X509 *)0x1;
  }
  BIO_free(pBVar5);
  x = SSL_SESSION_get0_peer(s);
  if (local_24 != (byte *)0x0) {
    sid_ctx_len = strlen((char *)local_24);
    if (sid_ctx_len < 0x21) {
      SSL_SESSION_set1_id_context(s,local_24,sid_ctx_len);
      goto LAB_0807faa5;
    }
    BIO_printf(bio_err,"Context too long\n");
LAB_0807f8c7:
    x = (X509 *)0x1;
    goto LAB_0807f8cc;
  }
LAB_0807faa5:
  if ((local_2c == 0) && (pBVar5 = (BIO *)0x0, local_20 != 0)) goto LAB_0807fac6;
  pBVar4 = BIO_s_file();
  pBVar5 = BIO_new(pBVar4);
  if (pBVar5 == (BIO *)0x0) {
    ERR_print_errors(bio_err);
    goto LAB_0807f8c7;
  }
  if (local_30 == (byte *)0x0) {
    BIO_ctrl(pBVar5,0x6a,0,stdout);
LAB_0807fbc9:
    if ((local_2c == 0) || (SSL_SESSION_print(pBVar5,s), local_28 == 0)) {
LAB_0807fac6:
      if ((local_28 | local_20) == 0) goto LAB_0807fb47;
      if ((x != (X509 *)0x0) && (local_20 == 0)) {
        if (local_3c == 1) {
          iVar7 = i2d_X509_bio(pBVar5,x);
LAB_0807fd25:
          x = (X509 *)0x0;
          if (iVar7 == 0) {
            x = (X509 *)0x1;
            BIO_printf(bio_err,"unable to write X509\n");
          }
          goto LAB_0807fb13;
        }
        if (local_3c == 3) {
          iVar7 = PEM_write_bio_X509(pBVar5,x);
          goto LAB_0807fd25;
        }
        goto LAB_0807faf8;
      }
      x = (X509 *)0x0;
    }
    else {
      if (x != (X509 *)0x0) {
        X509_print(pBVar5,x);
        goto LAB_0807fac6;
      }
      BIO_puts(pBVar5,"No certificate present\n");
      if ((local_28 | local_20) != 0) goto LAB_0807fb1b;
LAB_0807fb47:
      if (local_3c == 1) {
        iVar7 = ASN1_i2d_bio(i2d_SSL_SESSION,pBVar5,(uchar *)s);
      }
      else {
        if (local_3c != 3) {
LAB_0807faf8:
          x = (X509 *)0x1;
          BIO_printf(bio_err,"bad output format specified for outfile\n");
          goto LAB_0807fb13;
        }
        iVar7 = PEM_write_bio_SSL_SESSION(pBVar5,s);
      }
      x = (X509 *)0x0;
      if (iVar7 == 0) {
        x = (X509 *)0x1;
        BIO_printf(bio_err,"unable to write SSL_SESSION\n");
      }
    }
LAB_0807fb13:
    if (pBVar5 == (BIO *)0x0) goto LAB_0807f8cc;
  }
  else {
    lVar6 = BIO_ctrl(pBVar5,0x6c,5,local_30);
    if (0 < lVar6) goto LAB_0807fbc9;
    x = (X509 *)0x1;
    perror((char *)local_30);
  }
LAB_0807fb1b:
  BIO_free_all(pBVar5);
LAB_0807f8cc:
  SSL_SESSION_free(s);
  return x;
}

