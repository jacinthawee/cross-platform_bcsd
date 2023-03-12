
undefined4 pkcs7_main(int param_1,undefined4 *param_2)

{
  char **ppcVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  BIO_METHOD *pBVar5;
  BIO *bp;
  BIO *bp_00;
  int iVar6;
  PKCS7 *x;
  long lVar7;
  void *pvVar8;
  X509_CRL *pXVar9;
  X509 *pXVar10;
  undefined4 uVar11;
  char **ppcVar12;
  char *__s1;
  _STACK *p_Var13;
  int iVar14;
  _STACK *p_Var15;
  char *pcVar16;
  char *parg;
  char *local_40;
  int local_3c;
  int local_34;
  
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    pBVar5 = BIO_s_file();
    bio_err = BIO_new(pBVar5);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  iVar4 = load_config(bio_err,0);
  if (iVar4 == 0) {
LAB_0001e7d0:
    bp_00 = (BIO *)0x0;
LAB_0001e7d2:
    uVar11 = 1;
  }
  else {
    ppcVar12 = (char **)(param_2 + 1);
    uVar11 = *param_2;
    pcVar16 = (char *)0x0;
    iVar4 = 3;
    bVar2 = false;
    parg = (char *)0x0;
    iVar14 = 3;
    local_3c = 0;
    local_34 = 0;
    bVar3 = false;
    local_40 = (char *)0x0;
    for (param_1 = param_1 + -1; 0 < param_1; param_1 = param_1 + -1) {
      __s1 = *ppcVar12;
      iVar6 = strcmp(__s1,"-inform");
      if (iVar6 == 0) {
        param_1 = param_1 + -1;
        if (param_1 == 0) goto LAB_0001e742;
        ppcVar1 = ppcVar12 + 1;
        ppcVar12 = ppcVar12 + 1;
        iVar14 = str2fmt(*ppcVar1);
      }
      else {
        iVar6 = strcmp(__s1,"-outform");
        if (iVar6 == 0) {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_0001e742;
          iVar4 = str2fmt(ppcVar12[1]);
          ppcVar12 = ppcVar12 + 1;
        }
        else if ((((*__s1 == '-') && (__s1[1] == 'i')) && (__s1[2] == 'n')) && (__s1[3] == '\0')) {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_0001e742;
          parg = ppcVar12[1];
          ppcVar12 = ppcVar12 + 1;
        }
        else {
          iVar6 = strcmp(__s1,"-out");
          if (iVar6 == 0) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_0001e742;
            local_40 = ppcVar12[1];
            ppcVar12 = ppcVar12 + 1;
          }
          else {
            iVar6 = strcmp(__s1,"-noout");
            if (iVar6 == 0) {
              local_3c = 1;
            }
            else {
              iVar6 = strcmp(__s1,"-text");
              if (iVar6 == 0) {
                local_34 = 1;
              }
              else {
                iVar6 = strcmp(__s1,"-print");
                if (iVar6 == 0) {
                  bVar2 = true;
                }
                else {
                  iVar6 = strcmp(__s1,"-print_certs");
                  if (iVar6 != 0) {
                    iVar6 = strcmp(__s1,"-engine");
                    if (iVar6 == 0) {
                      param_1 = param_1 + -1;
                      if (param_1 != 0) {
                        pcVar16 = ppcVar12[1];
                        ppcVar12 = ppcVar12 + 1;
                        goto LAB_0001e64c;
                      }
                    }
                    else {
                      BIO_printf(bio_err,"unknown option %s\n",__s1);
                    }
LAB_0001e742:
                    BIO_printf(bio_err,"%s [options] <infile >outfile\n",uVar11);
                    BIO_printf(bio_err,"where options are\n");
                    BIO_printf(bio_err," -inform arg   input format - DER or PEM\n");
                    BIO_printf(bio_err," -outform arg  output format - DER or PEM\n");
                    BIO_printf(bio_err," -in arg       input file\n");
                    BIO_printf(bio_err," -out arg      output file\n");
                    BIO_printf(bio_err," -print_certs  print any certs or crl in the input\n");
                    BIO_printf(bio_err," -text         print full details of certificates\n");
                    BIO_printf(bio_err," -noout        don\'t output encoded data\n");
                    BIO_printf(bio_err," -engine e     use engine e, possibly a hardware device.\n")
                    ;
                    goto LAB_0001e7d0;
                  }
                  bVar3 = true;
                }
              }
            }
          }
        }
      }
LAB_0001e64c:
      ppcVar12 = ppcVar12 + 1;
    }
    ERR_load_crypto_strings();
    setup_engine(bio_err,pcVar16,0);
    pBVar5 = BIO_s_file();
    bp = BIO_new(pBVar5);
    pBVar5 = BIO_s_file();
    bp_00 = BIO_new(pBVar5);
    if (bp == (BIO *)0x0 || bp_00 == (BIO *)0x0) {
      ERR_print_errors(bio_err);
LAB_0001e840:
      uVar11 = 1;
      if (bp == (BIO *)0x0) goto LAB_0001e7d2;
    }
    else {
      if (parg == (char *)0x0) {
        BIO_ctrl(bp,0x6a,0,stdin);
      }
      else {
        BIO_ctrl(bp,0x6c,3,parg);
      }
      if (iVar14 == 1) {
        x = d2i_PKCS7_bio(bp,(PKCS7 **)0x0);
      }
      else {
        if (iVar14 != 3) {
          BIO_printf(bio_err,"bad input format specified for pkcs7 object\n");
          goto LAB_0001e840;
        }
        x = PEM_read_bio_PKCS7(bp,(PKCS7 **)0x0,(undefined1 *)0x0,(void *)0x0);
      }
      if (x == (PKCS7 *)0x0) {
        BIO_printf(bio_err,"unable to load PKCS7 object\n");
        ERR_print_errors(bio_err);
        goto LAB_0001e840;
      }
      if (local_40 == (char *)0x0) {
        BIO_ctrl(bp_00,0x6a,0,stdout);
LAB_0001e892:
        if (bVar2) {
          PKCS7_print_ctx(bp_00,x,0,(ASN1_PCTX *)0x0);
        }
        if (bVar3) {
          iVar4 = OBJ_obj2nid(x->type);
          if ((iVar4 == 0x16) || (iVar4 == 0x18)) {
            p_Var15 = (_STACK *)((x->d).sign)->cert;
            p_Var13 = (_STACK *)((x->d).sign)->crl;
            if (p_Var15 == (_STACK *)0x0) {
              if (p_Var13 != (_STACK *)0x0) {
                if (local_3c == 0) goto LAB_0001e8d4;
LAB_0001e978:
                iVar4 = 0;
                while( true ) {
                  iVar14 = sk_num(p_Var13);
                  if (iVar14 <= iVar4) break;
                  pXVar9 = (X509_CRL *)sk_value(p_Var13,iVar4);
                  X509_CRL_print(bp_00,pXVar9);
                  BIO_puts(bp_00,"\n");
                  iVar4 = iVar4 + 1;
                }
              }
            }
            else if (local_3c == 0) {
              if (local_34 == 0) {
                while( true ) {
                  iVar4 = sk_num(p_Var15);
                  if (iVar4 <= local_34) break;
                  pXVar10 = (X509 *)sk_value(p_Var15,local_34);
                  dump_cert_text(bp_00,pXVar10);
                  PEM_write_bio_X509(bp_00,pXVar10);
                  BIO_puts(bp_00,"\n");
                  local_34 = local_34 + 1;
                }
              }
              else {
                while( true ) {
                  iVar4 = sk_num(p_Var15);
                  if (iVar4 <= local_3c) break;
                  pXVar10 = (X509 *)sk_value(p_Var15,local_3c);
                  X509_print(bp_00,pXVar10);
                  PEM_write_bio_X509(bp_00,pXVar10);
                  BIO_puts(bp_00,"\n");
                  local_3c = local_3c + 1;
                }
              }
              if (p_Var13 != (_STACK *)0x0) {
LAB_0001e8d4:
                iVar4 = 0;
                while( true ) {
                  iVar14 = sk_num(p_Var13);
                  if (iVar14 <= iVar4) break;
                  pXVar9 = (X509_CRL *)sk_value(p_Var13,iVar4);
                  X509_CRL_print(bp_00,pXVar9);
                  PEM_write_bio_X509_CRL(bp_00,pXVar9);
                  BIO_puts(bp_00,"\n");
                  iVar4 = iVar4 + 1;
                }
              }
            }
            else {
              if (local_34 == 0) {
                while( true ) {
                  iVar4 = sk_num(p_Var15);
                  if (iVar4 <= local_34) break;
                  pvVar8 = sk_value(p_Var15,local_34);
                  dump_cert_text(bp_00,pvVar8);
                  BIO_puts(bp_00,"\n");
                  local_34 = local_34 + 1;
                }
              }
              else {
                iVar4 = 0;
                while( true ) {
                  iVar14 = sk_num(p_Var15);
                  if (iVar14 <= iVar4) break;
                  pXVar10 = (X509 *)sk_value(p_Var15,iVar4);
                  X509_print(bp_00,pXVar10);
                  BIO_puts(bp_00,"\n");
                  iVar4 = iVar4 + 1;
                }
              }
              if (p_Var13 != (_STACK *)0x0) goto LAB_0001e978;
            }
          }
        }
        else if (local_3c == 0) {
          if (iVar4 == 1) {
            iVar4 = i2d_PKCS7_bio(bp_00,x);
          }
          else {
            if (iVar4 != 3) {
              uVar11 = 1;
              BIO_printf(bio_err,"bad output format specified for outfile\n");
              goto LAB_0001e8c4;
            }
            iVar4 = PEM_write_bio_PKCS7(bp_00,x);
          }
          if (iVar4 == 0) {
            uVar11 = 1;
            BIO_printf(bio_err,"unable to write pkcs7 object\n");
            ERR_print_errors(bio_err);
            goto LAB_0001e8c4;
          }
        }
        uVar11 = 0;
      }
      else {
        lVar7 = BIO_ctrl(bp_00,0x6c,5,local_40);
        if (0 < lVar7) goto LAB_0001e892;
        uVar11 = 1;
        perror(local_40);
      }
LAB_0001e8c4:
      PKCS7_free(x);
    }
    BIO_free(bp);
  }
  if (bp_00 != (BIO *)0x0) {
    BIO_free_all(bp_00);
  }
  return uVar11;
}

