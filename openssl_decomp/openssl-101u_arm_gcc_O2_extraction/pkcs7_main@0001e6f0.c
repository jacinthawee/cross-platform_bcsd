
undefined4 pkcs7_main(int param_1,undefined4 *param_2)

{
  char **ppcVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  BIO_METHOD *pBVar5;
  BIO *bp;
  BIO *bp_00;
  long lVar6;
  int iVar7;
  PKCS7 *x;
  void *pvVar8;
  X509_CRL *pXVar9;
  X509 *pXVar10;
  undefined4 uVar11;
  PKCS7_SIGNED *pPVar12;
  char **ppcVar13;
  char *__s1;
  _STACK *p_Var14;
  int iVar15;
  _STACK *p_Var16;
  char *pcVar17;
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
LAB_0001e952:
    bp_00 = (BIO *)0x0;
LAB_0001e954:
    uVar11 = 1;
  }
  else {
    ppcVar13 = (char **)(param_2 + 1);
    uVar11 = *param_2;
    pcVar17 = (char *)0x0;
    iVar4 = 3;
    bVar2 = false;
    parg = (char *)0x0;
    iVar15 = 3;
    local_3c = 0;
    local_34 = 0;
    bVar3 = false;
    local_40 = (char *)0x0;
    for (param_1 = param_1 + -1; 0 < param_1; param_1 = param_1 + -1) {
      __s1 = *ppcVar13;
      iVar7 = strcmp(__s1,"-inform");
      if (iVar7 == 0) {
        param_1 = param_1 + -1;
        if (param_1 == 0) goto LAB_0001e8c4;
        ppcVar1 = ppcVar13 + 1;
        ppcVar13 = ppcVar13 + 1;
        iVar15 = str2fmt(*ppcVar1);
      }
      else {
        iVar7 = strcmp(__s1,"-outform");
        if (iVar7 == 0) {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_0001e8c4;
          iVar4 = str2fmt(ppcVar13[1]);
          ppcVar13 = ppcVar13 + 1;
        }
        else if ((((*__s1 == '-') && (__s1[1] == 'i')) && (__s1[2] == 'n')) && (__s1[3] == '\0')) {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_0001e8c4;
          parg = ppcVar13[1];
          ppcVar13 = ppcVar13 + 1;
        }
        else {
          iVar7 = strcmp(__s1,"-out");
          if (iVar7 == 0) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_0001e8c4;
            local_40 = ppcVar13[1];
            ppcVar13 = ppcVar13 + 1;
          }
          else {
            iVar7 = strcmp(__s1,"-noout");
            if (iVar7 == 0) {
              local_3c = 1;
            }
            else {
              iVar7 = strcmp(__s1,"-text");
              if (iVar7 == 0) {
                local_34 = 1;
              }
              else {
                iVar7 = strcmp(__s1,"-print");
                if (iVar7 == 0) {
                  bVar2 = true;
                }
                else {
                  iVar7 = strcmp(__s1,"-print_certs");
                  if (iVar7 != 0) {
                    iVar7 = strcmp(__s1,"-engine");
                    if (iVar7 == 0) {
                      param_1 = param_1 + -1;
                      if (param_1 != 0) {
                        pcVar17 = ppcVar13[1];
                        ppcVar13 = ppcVar13 + 1;
                        goto LAB_0001e7ce;
                      }
                    }
                    else {
                      BIO_printf(bio_err,"unknown option %s\n",__s1);
                    }
LAB_0001e8c4:
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
                    goto LAB_0001e952;
                  }
                  bVar3 = true;
                }
              }
            }
          }
        }
      }
LAB_0001e7ce:
      ppcVar13 = ppcVar13 + 1;
    }
    ERR_load_crypto_strings();
    setup_engine(bio_err,pcVar17,0);
    pBVar5 = BIO_s_file();
    bp = BIO_new(pBVar5);
    pBVar5 = BIO_s_file();
    bp_00 = BIO_new(pBVar5);
    if (bp == (BIO *)0x0 || bp_00 == (BIO *)0x0) {
LAB_0001e9ca:
      ERR_print_errors(bio_err);
LAB_0001e9d0:
      uVar11 = 1;
      if (bp == (BIO *)0x0) goto LAB_0001e954;
    }
    else {
      if (parg == (char *)0x0) {
        BIO_ctrl(bp,0x6a,0,stdin);
      }
      else {
        lVar6 = BIO_ctrl(bp,0x6c,3,parg);
        if (lVar6 < 1) {
          BIO_printf(bio_err,"unable to load input file\n");
          goto LAB_0001e9ca;
        }
      }
      if (iVar15 == 1) {
        x = d2i_PKCS7_bio(bp,(PKCS7 **)0x0);
      }
      else {
        if (iVar15 != 3) {
          BIO_printf(bio_err,"bad input format specified for pkcs7 object\n");
          goto LAB_0001e9d0;
        }
        x = PEM_read_bio_PKCS7(bp,(PKCS7 **)0x0,(undefined1 *)0x0,(void *)0x0);
      }
      if (x == (PKCS7 *)0x0) {
        BIO_printf(bio_err,"unable to load PKCS7 object\n");
        ERR_print_errors(bio_err);
        goto LAB_0001e9d0;
      }
      if (local_40 == (char *)0x0) {
        BIO_ctrl(bp_00,0x6a,0,stdout);
LAB_0001ea22:
        if (bVar2) {
          PKCS7_print_ctx(bp_00,x,0,(ASN1_PCTX *)0x0);
        }
        if (bVar3) {
          iVar4 = OBJ_obj2nid(x->type);
          if (((iVar4 == 0x16) || (iVar4 == 0x18)) &&
             (pPVar12 = (x->d).sign, pPVar12 != (PKCS7_SIGNED *)0x0)) {
            p_Var16 = (_STACK *)pPVar12->cert;
            p_Var14 = (_STACK *)pPVar12->crl;
            if (p_Var16 == (_STACK *)0x0) {
              if (p_Var14 != (_STACK *)0x0) {
                if (local_3c == 0) goto LAB_0001ea64;
LAB_0001eb0a:
                iVar4 = 0;
                while( true ) {
                  iVar15 = sk_num(p_Var14);
                  if (iVar15 <= iVar4) break;
                  pXVar9 = (X509_CRL *)sk_value(p_Var14,iVar4);
                  X509_CRL_print(bp_00,pXVar9);
                  BIO_puts(bp_00,"\n");
                  iVar4 = iVar4 + 1;
                }
              }
            }
            else if (local_3c == 0) {
              if (local_34 == 0) {
                while( true ) {
                  iVar4 = sk_num(p_Var16);
                  if (iVar4 <= local_34) break;
                  pXVar10 = (X509 *)sk_value(p_Var16,local_34);
                  dump_cert_text(bp_00,pXVar10);
                  PEM_write_bio_X509(bp_00,pXVar10);
                  BIO_puts(bp_00,"\n");
                  local_34 = local_34 + 1;
                }
              }
              else {
                while( true ) {
                  iVar4 = sk_num(p_Var16);
                  if (iVar4 <= local_3c) break;
                  pXVar10 = (X509 *)sk_value(p_Var16,local_3c);
                  X509_print(bp_00,pXVar10);
                  PEM_write_bio_X509(bp_00,pXVar10);
                  BIO_puts(bp_00,"\n");
                  local_3c = local_3c + 1;
                }
              }
              if (p_Var14 != (_STACK *)0x0) {
LAB_0001ea64:
                iVar4 = 0;
                while( true ) {
                  iVar15 = sk_num(p_Var14);
                  if (iVar15 <= iVar4) break;
                  pXVar9 = (X509_CRL *)sk_value(p_Var14,iVar4);
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
                  iVar4 = sk_num(p_Var16);
                  if (iVar4 <= local_34) break;
                  pvVar8 = sk_value(p_Var16,local_34);
                  dump_cert_text(bp_00,pvVar8);
                  BIO_puts(bp_00,"\n");
                  local_34 = local_34 + 1;
                }
              }
              else {
                iVar4 = 0;
                while( true ) {
                  iVar15 = sk_num(p_Var16);
                  if (iVar15 <= iVar4) break;
                  pXVar10 = (X509 *)sk_value(p_Var16,iVar4);
                  X509_print(bp_00,pXVar10);
                  BIO_puts(bp_00,"\n");
                  iVar4 = iVar4 + 1;
                }
              }
              if (p_Var14 != (_STACK *)0x0) goto LAB_0001eb0a;
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
              goto LAB_0001ea54;
            }
            iVar4 = PEM_write_bio_PKCS7(bp_00,x);
          }
          if (iVar4 == 0) {
            uVar11 = 1;
            BIO_printf(bio_err,"unable to write pkcs7 object\n");
            ERR_print_errors(bio_err);
            goto LAB_0001ea54;
          }
        }
        uVar11 = 0;
      }
      else {
        lVar6 = BIO_ctrl(bp_00,0x6c,5,local_40);
        if (0 < lVar6) goto LAB_0001ea22;
        uVar11 = 1;
        perror(local_40);
      }
LAB_0001ea54:
      PKCS7_free(x);
    }
    BIO_free(bp);
  }
  if (bp_00 != (BIO *)0x0) {
    BIO_free_all(bp_00);
  }
  return uVar11;
}

