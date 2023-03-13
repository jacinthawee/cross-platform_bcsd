
/* WARNING: Type propagation algorithm not settling */

undefined4 pkcs7_main(int param_1,undefined4 *param_2)

{
  byte **ppbVar1;
  byte *pbVar2;
  PKCS7_SIGNED *pPVar3;
  _STACK *p_Var4;
  _STACK *p_Var5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  int iVar10;
  byte **ppbVar11;
  BIO_METHOD *pBVar12;
  BIO *bp;
  BIO *bp_00;
  long lVar13;
  PKCS7 *x;
  void *pvVar14;
  int iVar15;
  X509_CRL *pXVar16;
  X509 *pXVar17;
  byte *pbVar18;
  undefined4 uVar19;
  byte *pbVar20;
  bool bVar21;
  bool bVar22;
  byte bVar23;
  char *format;
  int local_48;
  int local_44;
  int local_40;
  byte *local_3c;
  byte *local_38;
  byte *local_2c;
  
  bVar23 = 0;
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    pBVar12 = BIO_s_file();
    bio_err = BIO_new(pBVar12);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  iVar10 = load_config(bio_err,0);
  if (iVar10 == 0) {
    return 1;
  }
  local_2c = (byte *)0x0;
  bVar6 = false;
  bVar8 = false;
  bVar9 = false;
  bVar7 = false;
  uVar19 = *param_2;
  local_38 = (byte *)0x0;
  local_3c = (byte *)0x0;
  local_40 = 3;
  local_44 = 3;
  local_48 = param_1 + -1;
  ppbVar11 = (byte **)(param_2 + 1);
  bVar21 = false;
  bVar22 = local_48 == 0;
  if (0 < local_48) {
LAB_0805c1fa:
    do {
      pbVar2 = *ppbVar11;
      iVar10 = 8;
      pbVar18 = pbVar2;
      pbVar20 = (byte *)"-inform";
      do {
        if (iVar10 == 0) break;
        iVar10 = iVar10 + -1;
        bVar21 = *pbVar18 < *pbVar20;
        bVar22 = *pbVar18 == *pbVar20;
        pbVar18 = pbVar18 + (uint)bVar23 * -2 + 1;
        pbVar20 = pbVar20 + (uint)bVar23 * -2 + 1;
      } while (bVar22);
      bVar21 = (!bVar21 && !bVar22) == bVar21;
      if (bVar21) {
        local_48 = local_48 + -1;
        if (local_48 == 0) goto LAB_0805c3b0;
        ppbVar1 = ppbVar11 + 1;
        ppbVar11 = ppbVar11 + 1;
        local_44 = str2fmt(*ppbVar1);
LAB_0805c1f0:
        bVar21 = local_48 == 0;
        local_48 = local_48 + -1;
        bVar22 = local_48 == 0;
        ppbVar11 = ppbVar11 + 1;
        if (bVar22) break;
        goto LAB_0805c1fa;
      }
      iVar10 = 9;
      pbVar18 = pbVar2;
      pbVar20 = (byte *)"-outform";
      do {
        if (iVar10 == 0) break;
        iVar10 = iVar10 + -1;
        bVar21 = *pbVar18 == *pbVar20;
        pbVar18 = pbVar18 + (uint)bVar23 * -2 + 1;
        pbVar20 = pbVar20 + (uint)bVar23 * -2 + 1;
      } while (bVar21);
      if (!bVar21) {
        bVar21 = *pbVar2 == 0x2d;
        if ((((bVar21) && (bVar21 = pbVar2[1] == 0x69, bVar21)) &&
            (bVar21 = pbVar2[2] == 0x6e, bVar21)) && (bVar21 = pbVar2[3] == 0, bVar21)) {
          local_48 = local_48 + -1;
          if (local_48 == 0) goto LAB_0805c3b0;
          local_3c = ppbVar11[1];
          ppbVar11 = ppbVar11 + 1;
        }
        else {
          iVar10 = 5;
          pbVar18 = pbVar2;
          pbVar20 = &DAT_081eab75;
          do {
            if (iVar10 == 0) break;
            iVar10 = iVar10 + -1;
            bVar21 = *pbVar18 == *pbVar20;
            pbVar18 = pbVar18 + (uint)bVar23 * -2 + 1;
            pbVar20 = pbVar20 + (uint)bVar23 * -2 + 1;
          } while (bVar21);
          if (bVar21) {
            local_48 = local_48 + -1;
            if (local_48 == 0) goto LAB_0805c3b0;
            local_38 = ppbVar11[1];
            ppbVar11 = ppbVar11 + 1;
          }
          else {
            iVar10 = 7;
            pbVar18 = pbVar2;
            pbVar20 = (byte *)"-noout";
            do {
              if (iVar10 == 0) break;
              iVar10 = iVar10 + -1;
              bVar21 = *pbVar18 == *pbVar20;
              pbVar18 = pbVar18 + (uint)bVar23 * -2 + 1;
              pbVar20 = pbVar20 + (uint)bVar23 * -2 + 1;
            } while (bVar21);
            if (bVar21) {
              bVar8 = true;
            }
            else {
              iVar10 = 6;
              pbVar18 = pbVar2;
              pbVar20 = (byte *)"-text";
              do {
                if (iVar10 == 0) break;
                iVar10 = iVar10 + -1;
                bVar21 = *pbVar18 == *pbVar20;
                pbVar18 = pbVar18 + (uint)bVar23 * -2 + 1;
                pbVar20 = pbVar20 + (uint)bVar23 * -2 + 1;
              } while (bVar21);
              if (bVar21) {
                bVar9 = true;
              }
              else {
                iVar10 = 7;
                pbVar18 = pbVar2;
                pbVar20 = (byte *)"-print";
                do {
                  if (iVar10 == 0) break;
                  iVar10 = iVar10 + -1;
                  bVar21 = *pbVar18 == *pbVar20;
                  pbVar18 = pbVar18 + (uint)bVar23 * -2 + 1;
                  pbVar20 = pbVar20 + (uint)bVar23 * -2 + 1;
                } while (bVar21);
                if (bVar21) {
                  bVar6 = true;
                }
                else {
                  iVar10 = 0xd;
                  pbVar18 = pbVar2;
                  pbVar20 = (byte *)"-print_certs";
                  do {
                    if (iVar10 == 0) break;
                    iVar10 = iVar10 + -1;
                    bVar21 = *pbVar18 == *pbVar20;
                    pbVar18 = pbVar18 + (uint)bVar23 * -2 + 1;
                    pbVar20 = pbVar20 + (uint)bVar23 * -2 + 1;
                  } while (bVar21);
                  if (bVar21) {
                    bVar7 = true;
                  }
                  else {
                    iVar10 = 8;
                    pbVar18 = pbVar2;
                    pbVar20 = (byte *)"-engine";
                    do {
                      if (iVar10 == 0) break;
                      iVar10 = iVar10 + -1;
                      bVar21 = *pbVar18 == *pbVar20;
                      pbVar18 = pbVar18 + (uint)bVar23 * -2 + 1;
                      pbVar20 = pbVar20 + (uint)bVar23 * -2 + 1;
                    } while (bVar21);
                    if (!bVar21) {
                      BIO_printf(bio_err,"unknown option %s\n",pbVar2);
LAB_0805c3b0:
                      BIO_printf(bio_err,"%s [options] <infile >outfile\n",uVar19);
                      BIO_printf(bio_err,"where options are\n");
                      BIO_printf(bio_err," -inform arg   input format - DER or PEM\n");
                      BIO_printf(bio_err," -outform arg  output format - DER or PEM\n");
                      BIO_printf(bio_err," -in arg       input file\n");
                      BIO_printf(bio_err," -out arg      output file\n");
                      BIO_printf(bio_err," -print_certs  print any certs or crl in the input\n");
                      BIO_printf(bio_err," -text         print full details of certificates\n");
                      BIO_printf(bio_err," -noout        don\'t output encoded data\n");
                      BIO_printf(bio_err,
                                 " -engine e     use engine e, possibly a hardware device.\n");
                      return 1;
                    }
                    local_48 = local_48 + -1;
                    if (local_48 == 0) goto LAB_0805c3b0;
                    local_2c = ppbVar11[1];
                    ppbVar11 = ppbVar11 + 1;
                  }
                }
              }
            }
          }
        }
        goto LAB_0805c1f0;
      }
      if (local_48 == 1) goto LAB_0805c3b0;
      local_40 = str2fmt(ppbVar11[1]);
      ppbVar11 = ppbVar11 + 2;
      bVar21 = local_48 == 1;
      local_48 = local_48 + -2;
      bVar22 = local_48 == 0;
    } while (!bVar22);
  }
  ERR_load_crypto_strings();
  setup_engine(bio_err,local_2c,0);
  pBVar12 = BIO_s_file();
  bp = BIO_new(pBVar12);
  pBVar12 = BIO_s_file();
  bp_00 = BIO_new(pBVar12);
  if ((bp == (BIO *)0x0) || (bp_00 == (BIO *)0x0)) {
    ERR_print_errors(bio_err);
LAB_0805c2ee:
    uVar19 = 1;
    if (bp == (BIO *)0x0) goto LAB_0805c30c;
    uVar19 = 1;
  }
  else {
    if (local_3c != (byte *)0x0) {
      lVar13 = BIO_ctrl(bp,0x6c,3,local_3c);
      if (0 < lVar13) goto LAB_0805c2c2;
      format = "unable to load input file\n";
LAB_0805c6cb:
      BIO_printf(bio_err,format);
      ERR_print_errors(bio_err);
      goto LAB_0805c2ee;
    }
    BIO_ctrl(bp,0x6a,0,stdin);
LAB_0805c2c2:
    if (local_44 == 1) {
      x = d2i_PKCS7_bio(bp,(PKCS7 **)0x0);
    }
    else {
      if (local_44 != 3) {
        BIO_printf(bio_err,"bad input format specified for pkcs7 object\n");
        goto LAB_0805c2ee;
      }
      x = PEM_read_bio_PKCS7(bp,(PKCS7 **)0x0,(undefined1 *)0x0,(void *)0x0);
    }
    if (x == (PKCS7 *)0x0) {
      format = "unable to load PKCS7 object\n";
      goto LAB_0805c6cb;
    }
    if (local_38 == (byte *)0x0) {
      BIO_ctrl(bp_00,0x6a,0,stdout);
LAB_0805c5ee:
      if (bVar6) {
        PKCS7_print_ctx(bp_00,x,0,(ASN1_PCTX *)0x0);
      }
      if (bVar7) {
        iVar10 = OBJ_obj2nid(x->type);
        if (((iVar10 == 0x16) || (iVar10 == 0x18)) &&
           (pPVar3 = (x->d).sign, pPVar3 != (PKCS7_SIGNED *)0x0)) {
          p_Var4 = (_STACK *)pPVar3->cert;
          p_Var5 = (_STACK *)pPVar3->crl;
          if (p_Var4 == (_STACK *)0x0) {
            if (p_Var5 != (_STACK *)0x0) {
              if (bVar8) goto LAB_0805c7a8;
              goto LAB_0805c664;
            }
          }
          else if (bVar8) {
            iVar10 = 0;
            if (bVar9) {
              for (; iVar15 = sk_num(p_Var4), iVar10 < iVar15; iVar10 = iVar10 + 1) {
                pXVar17 = (X509 *)sk_value(p_Var4,iVar10);
                X509_print(bp_00,pXVar17);
                BIO_puts(bp_00,"\n");
              }
            }
            else {
              for (; iVar15 = sk_num(p_Var4), iVar10 < iVar15; iVar10 = iVar10 + 1) {
                pvVar14 = sk_value(p_Var4,iVar10);
                dump_cert_text(bp_00,pvVar14);
                BIO_puts(bp_00,"\n");
              }
            }
            if (p_Var5 != (_STACK *)0x0) {
LAB_0805c7a8:
              for (iVar10 = 0; iVar15 = sk_num(p_Var5), iVar10 < iVar15; iVar10 = iVar10 + 1) {
                pXVar16 = (X509_CRL *)sk_value(p_Var5,iVar10);
                X509_CRL_print(bp_00,pXVar16);
                BIO_puts(bp_00,"\n");
              }
              uVar19 = 0;
              goto LAB_0805c643;
            }
          }
          else {
            iVar10 = 0;
            if (bVar9) {
              for (; iVar15 = sk_num(p_Var4), iVar10 < iVar15; iVar10 = iVar10 + 1) {
                pXVar17 = (X509 *)sk_value(p_Var4,iVar10);
                X509_print(bp_00,pXVar17);
                PEM_write_bio_X509(bp_00,pXVar17);
                BIO_puts(bp_00,"\n");
              }
            }
            else {
              for (; iVar15 = sk_num(p_Var4), iVar10 < iVar15; iVar10 = iVar10 + 1) {
                pXVar17 = (X509 *)sk_value(p_Var4,iVar10);
                dump_cert_text(bp_00,pXVar17);
                PEM_write_bio_X509(bp_00,pXVar17);
                BIO_puts(bp_00,"\n");
              }
            }
            if (p_Var5 == (_STACK *)0x0) {
              uVar19 = 0;
              goto LAB_0805c643;
            }
LAB_0805c664:
            for (iVar10 = 0; iVar15 = sk_num(p_Var5), iVar10 < iVar15; iVar10 = iVar10 + 1) {
              pXVar16 = (X509_CRL *)sk_value(p_Var5,iVar10);
              X509_CRL_print(bp_00,pXVar16);
              PEM_write_bio_X509_CRL(bp_00,pXVar16);
              BIO_puts(bp_00,"\n");
            }
          }
        }
      }
      else if (!bVar8) {
        if (local_40 == 1) {
          iVar10 = i2d_PKCS7_bio(bp_00,x);
        }
        else {
          if (local_40 != 3) {
            uVar19 = 1;
            BIO_printf(bio_err,"bad output format specified for outfile\n");
            goto LAB_0805c643;
          }
          iVar10 = PEM_write_bio_PKCS7(bp_00,x);
        }
        if (iVar10 == 0) {
          uVar19 = 1;
          BIO_printf(bio_err,"unable to write pkcs7 object\n");
          ERR_print_errors(bio_err);
          goto LAB_0805c643;
        }
      }
      uVar19 = 0;
    }
    else {
      lVar13 = BIO_ctrl(bp_00,0x6c,5,local_38);
      if (0 < lVar13) goto LAB_0805c5ee;
      uVar19 = 1;
      perror((char *)local_38);
    }
LAB_0805c643:
    PKCS7_free(x);
  }
  BIO_free(bp);
LAB_0805c30c:
  if (bp_00 != (BIO *)0x0) {
    BIO_free_all(bp_00);
    return uVar19;
  }
  return uVar19;
}

