
/* WARNING: Type propagation algorithm not settling */

undefined4 pkcs7_main(int param_1,undefined4 *param_2)

{
  byte **ppbVar1;
  byte *pbVar2;
  _STACK *p_Var3;
  _STACK *p_Var4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  int iVar9;
  byte **ppbVar10;
  BIO_METHOD *pBVar11;
  BIO *bp;
  BIO *bp_00;
  PKCS7 *x;
  long lVar12;
  void *pvVar13;
  int iVar14;
  X509_CRL *pXVar15;
  X509 *pXVar16;
  byte *pbVar17;
  undefined4 uVar18;
  byte *pbVar19;
  bool bVar20;
  bool bVar21;
  byte bVar22;
  int local_48;
  int local_44;
  int local_40;
  byte *local_3c;
  byte *local_38;
  byte *local_2c;
  
  bVar22 = 0;
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    pBVar11 = BIO_s_file();
    bio_err = BIO_new(pBVar11);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  iVar9 = load_config(bio_err,0);
  if (iVar9 == 0) {
    return 1;
  }
  local_2c = (byte *)0x0;
  bVar5 = false;
  bVar7 = false;
  bVar8 = false;
  bVar6 = false;
  uVar18 = *param_2;
  local_38 = (byte *)0x0;
  local_3c = (byte *)0x0;
  local_40 = 3;
  local_44 = 3;
  local_48 = param_1 + -1;
  ppbVar10 = (byte **)(param_2 + 1);
  bVar20 = false;
  bVar21 = local_48 == 0;
  if (0 < local_48) {
LAB_0805bf8a:
    do {
      pbVar2 = *ppbVar10;
      iVar9 = 8;
      pbVar17 = pbVar2;
      pbVar19 = (byte *)"-inform";
      do {
        if (iVar9 == 0) break;
        iVar9 = iVar9 + -1;
        bVar20 = *pbVar17 < *pbVar19;
        bVar21 = *pbVar17 == *pbVar19;
        pbVar17 = pbVar17 + (uint)bVar22 * -2 + 1;
        pbVar19 = pbVar19 + (uint)bVar22 * -2 + 1;
      } while (bVar21);
      bVar20 = (!bVar20 && !bVar21) == bVar20;
      if (bVar20) {
        local_48 = local_48 + -1;
        if (local_48 == 0) goto LAB_0805c130;
        ppbVar1 = ppbVar10 + 1;
        ppbVar10 = ppbVar10 + 1;
        local_44 = str2fmt(*ppbVar1);
LAB_0805bf80:
        bVar20 = local_48 == 0;
        local_48 = local_48 + -1;
        bVar21 = local_48 == 0;
        ppbVar10 = ppbVar10 + 1;
        if (bVar21) break;
        goto LAB_0805bf8a;
      }
      iVar9 = 9;
      pbVar17 = pbVar2;
      pbVar19 = (byte *)"-outform";
      do {
        if (iVar9 == 0) break;
        iVar9 = iVar9 + -1;
        bVar20 = *pbVar17 == *pbVar19;
        pbVar17 = pbVar17 + (uint)bVar22 * -2 + 1;
        pbVar19 = pbVar19 + (uint)bVar22 * -2 + 1;
      } while (bVar20);
      if (!bVar20) {
        bVar20 = *pbVar2 == 0x2d;
        if ((((bVar20) && (bVar20 = pbVar2[1] == 0x69, bVar20)) &&
            (bVar20 = pbVar2[2] == 0x6e, bVar20)) && (bVar20 = pbVar2[3] == 0, bVar20)) {
          local_48 = local_48 + -1;
          if (local_48 == 0) goto LAB_0805c130;
          local_3c = ppbVar10[1];
          ppbVar10 = ppbVar10 + 1;
        }
        else {
          iVar9 = 5;
          pbVar17 = pbVar2;
          pbVar19 = &DAT_081ea8e1;
          do {
            if (iVar9 == 0) break;
            iVar9 = iVar9 + -1;
            bVar20 = *pbVar17 == *pbVar19;
            pbVar17 = pbVar17 + (uint)bVar22 * -2 + 1;
            pbVar19 = pbVar19 + (uint)bVar22 * -2 + 1;
          } while (bVar20);
          if (bVar20) {
            local_48 = local_48 + -1;
            if (local_48 == 0) goto LAB_0805c130;
            local_38 = ppbVar10[1];
            ppbVar10 = ppbVar10 + 1;
          }
          else {
            iVar9 = 7;
            pbVar17 = pbVar2;
            pbVar19 = (byte *)"-noout";
            do {
              if (iVar9 == 0) break;
              iVar9 = iVar9 + -1;
              bVar20 = *pbVar17 == *pbVar19;
              pbVar17 = pbVar17 + (uint)bVar22 * -2 + 1;
              pbVar19 = pbVar19 + (uint)bVar22 * -2 + 1;
            } while (bVar20);
            if (bVar20) {
              bVar7 = true;
            }
            else {
              iVar9 = 6;
              pbVar17 = pbVar2;
              pbVar19 = (byte *)"-text";
              do {
                if (iVar9 == 0) break;
                iVar9 = iVar9 + -1;
                bVar20 = *pbVar17 == *pbVar19;
                pbVar17 = pbVar17 + (uint)bVar22 * -2 + 1;
                pbVar19 = pbVar19 + (uint)bVar22 * -2 + 1;
              } while (bVar20);
              if (bVar20) {
                bVar8 = true;
              }
              else {
                iVar9 = 7;
                pbVar17 = pbVar2;
                pbVar19 = (byte *)"-print";
                do {
                  if (iVar9 == 0) break;
                  iVar9 = iVar9 + -1;
                  bVar20 = *pbVar17 == *pbVar19;
                  pbVar17 = pbVar17 + (uint)bVar22 * -2 + 1;
                  pbVar19 = pbVar19 + (uint)bVar22 * -2 + 1;
                } while (bVar20);
                if (bVar20) {
                  bVar5 = true;
                }
                else {
                  iVar9 = 0xd;
                  pbVar17 = pbVar2;
                  pbVar19 = (byte *)"-print_certs";
                  do {
                    if (iVar9 == 0) break;
                    iVar9 = iVar9 + -1;
                    bVar20 = *pbVar17 == *pbVar19;
                    pbVar17 = pbVar17 + (uint)bVar22 * -2 + 1;
                    pbVar19 = pbVar19 + (uint)bVar22 * -2 + 1;
                  } while (bVar20);
                  if (bVar20) {
                    bVar6 = true;
                  }
                  else {
                    iVar9 = 8;
                    pbVar17 = pbVar2;
                    pbVar19 = (byte *)"-engine";
                    do {
                      if (iVar9 == 0) break;
                      iVar9 = iVar9 + -1;
                      bVar20 = *pbVar17 == *pbVar19;
                      pbVar17 = pbVar17 + (uint)bVar22 * -2 + 1;
                      pbVar19 = pbVar19 + (uint)bVar22 * -2 + 1;
                    } while (bVar20);
                    if (!bVar20) {
                      BIO_printf(bio_err,"unknown option %s\n",pbVar2);
LAB_0805c130:
                      BIO_printf(bio_err,"%s [options] <infile >outfile\n",uVar18);
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
                    if (local_48 == 0) goto LAB_0805c130;
                    local_2c = ppbVar10[1];
                    ppbVar10 = ppbVar10 + 1;
                  }
                }
              }
            }
          }
        }
        goto LAB_0805bf80;
      }
      if (local_48 == 1) goto LAB_0805c130;
      local_40 = str2fmt(ppbVar10[1]);
      ppbVar10 = ppbVar10 + 2;
      bVar20 = local_48 == 1;
      local_48 = local_48 + -2;
      bVar21 = local_48 == 0;
    } while (!bVar21);
  }
  ERR_load_crypto_strings();
  setup_engine(bio_err,local_2c,0);
  pBVar11 = BIO_s_file();
  bp = BIO_new(pBVar11);
  pBVar11 = BIO_s_file();
  bp_00 = BIO_new(pBVar11);
  if ((bp == (BIO *)0x0) || (bp_00 == (BIO *)0x0)) {
    ERR_print_errors(bio_err);
LAB_0805c076:
    uVar18 = 1;
    if (bp == (BIO *)0x0) goto LAB_0805c08c;
  }
  else {
    if (local_3c == (byte *)0x0) {
      BIO_ctrl(bp,0x6a,0,stdin);
    }
    else {
      BIO_ctrl(bp,0x6c,3,local_3c);
    }
    if (local_44 == 1) {
      x = d2i_PKCS7_bio(bp,(PKCS7 **)0x0);
    }
    else {
      if (local_44 != 3) {
        BIO_printf(bio_err,"bad input format specified for pkcs7 object\n");
        goto LAB_0805c076;
      }
      x = PEM_read_bio_PKCS7(bp,(PKCS7 **)0x0,(undefined1 *)0x0,(void *)0x0);
    }
    if (x == (PKCS7 *)0x0) {
      BIO_printf(bio_err,"unable to load PKCS7 object\n");
      ERR_print_errors(bio_err);
      goto LAB_0805c076;
    }
    if (local_38 == (byte *)0x0) {
      BIO_ctrl(bp_00,0x6a,0,stdout);
LAB_0805c36e:
      if (bVar5) {
        PKCS7_print_ctx(bp_00,x,0,(ASN1_PCTX *)0x0);
      }
      if (bVar6) {
        iVar9 = OBJ_obj2nid(x->type);
        if ((iVar9 == 0x16) || (iVar9 == 0x18)) {
          p_Var3 = (_STACK *)((x->d).sign)->cert;
          p_Var4 = (_STACK *)((x->d).sign)->crl;
          if (p_Var3 == (_STACK *)0x0) {
            if (p_Var4 != (_STACK *)0x0) {
              if (bVar7) goto LAB_0805c4f8;
              goto LAB_0805c3e4;
            }
          }
          else if (bVar7) {
            iVar9 = 0;
            if (bVar8) {
              for (; iVar14 = sk_num(p_Var3), iVar9 < iVar14; iVar9 = iVar9 + 1) {
                pXVar16 = (X509 *)sk_value(p_Var3,iVar9);
                X509_print(bp_00,pXVar16);
                BIO_puts(bp_00,"\n");
              }
            }
            else {
              for (; iVar14 = sk_num(p_Var3), iVar9 < iVar14; iVar9 = iVar9 + 1) {
                pvVar13 = sk_value(p_Var3,iVar9);
                dump_cert_text(bp_00,pvVar13);
                BIO_puts(bp_00,"\n");
              }
            }
            if (p_Var4 != (_STACK *)0x0) {
LAB_0805c4f8:
              for (iVar9 = 0; iVar14 = sk_num(p_Var4), iVar9 < iVar14; iVar9 = iVar9 + 1) {
                pXVar15 = (X509_CRL *)sk_value(p_Var4,iVar9);
                X509_CRL_print(bp_00,pXVar15);
                BIO_puts(bp_00,"\n");
              }
              uVar18 = 0;
              goto LAB_0805c3c3;
            }
          }
          else {
            iVar9 = 0;
            if (bVar8) {
              for (; iVar14 = sk_num(p_Var3), iVar9 < iVar14; iVar9 = iVar9 + 1) {
                pXVar16 = (X509 *)sk_value(p_Var3,iVar9);
                X509_print(bp_00,pXVar16);
                PEM_write_bio_X509(bp_00,pXVar16);
                BIO_puts(bp_00,"\n");
              }
            }
            else {
              for (; iVar14 = sk_num(p_Var3), iVar9 < iVar14; iVar9 = iVar9 + 1) {
                pXVar16 = (X509 *)sk_value(p_Var3,iVar9);
                dump_cert_text(bp_00,pXVar16);
                PEM_write_bio_X509(bp_00,pXVar16);
                BIO_puts(bp_00,"\n");
              }
            }
            if (p_Var4 == (_STACK *)0x0) {
              uVar18 = 0;
              goto LAB_0805c3c3;
            }
LAB_0805c3e4:
            for (iVar9 = 0; iVar14 = sk_num(p_Var4), iVar9 < iVar14; iVar9 = iVar9 + 1) {
              pXVar15 = (X509_CRL *)sk_value(p_Var4,iVar9);
              X509_CRL_print(bp_00,pXVar15);
              PEM_write_bio_X509_CRL(bp_00,pXVar15);
              BIO_puts(bp_00,"\n");
            }
          }
        }
      }
      else if (!bVar7) {
        if (local_40 == 1) {
          iVar9 = i2d_PKCS7_bio(bp_00,x);
        }
        else {
          if (local_40 != 3) {
            uVar18 = 1;
            BIO_printf(bio_err,"bad output format specified for outfile\n");
            goto LAB_0805c3c3;
          }
          iVar9 = PEM_write_bio_PKCS7(bp_00,x);
        }
        if (iVar9 == 0) {
          uVar18 = 1;
          BIO_printf(bio_err,"unable to write pkcs7 object\n");
          ERR_print_errors(bio_err);
          goto LAB_0805c3c3;
        }
      }
      uVar18 = 0;
    }
    else {
      lVar12 = BIO_ctrl(bp_00,0x6c,5,local_38);
      if (0 < lVar12) goto LAB_0805c36e;
      uVar18 = 1;
      perror((char *)local_38);
    }
LAB_0805c3c3:
    PKCS7_free(x);
  }
  BIO_free(bp);
LAB_0805c08c:
  if (bp_00 != (BIO *)0x0) {
    BIO_free_all(bp_00);
    return uVar18;
  }
  return uVar18;
}

