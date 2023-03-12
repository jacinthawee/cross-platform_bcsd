
X509_CRL * crl2pkcs7_main(int param_1,undefined4 *param_2)

{
  char **ppcVar1;
  int iVar2;
  BIO_METHOD *pBVar3;
  X509_CRL *a;
  BIO *bp;
  long lVar4;
  X509_CRL *p7;
  PKCS7_SIGNED *pPVar5;
  ASN1_OBJECT *pAVar6;
  _STACK *p_Var7;
  void *parg;
  BIO *bp_00;
  X509_INFO *a_00;
  int iVar8;
  undefined4 uVar9;
  X509_CRL *pXVar10;
  char **ppcVar11;
  char *__s1;
  int iVar12;
  int iVar13;
  X509_CRL *st;
  char *__s;
  pkcs7_st *ppVar14;
  _STACK *local_3c;
  char *local_34;
  
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    pBVar3 = BIO_s_file();
    bio_err = BIO_new(pBVar3);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  param_1 = param_1 + -1;
  ppcVar11 = (char **)(param_2 + 1);
  uVar9 = *param_2;
  if (param_1 < 1) {
    ERR_load_crypto_strings();
    pBVar3 = BIO_s_file();
    a = (X509_CRL *)BIO_new(pBVar3);
    pBVar3 = BIO_s_file();
    bp = BIO_new(pBVar3);
    if (bp == (BIO *)0x0 || a == (X509_CRL *)0x0) goto LAB_0001eee0;
    iVar13 = 3;
    local_3c = (_STACK *)0x0;
    iVar12 = 3;
    local_34 = (char *)0x0;
LAB_0001efa6:
    BIO_ctrl((BIO *)a,0x6a,0,stdin);
LAB_0001ed5c:
    if (iVar12 == 1) {
      st = d2i_X509_CRL_bio((BIO *)a,(X509_CRL **)0x0);
    }
    else {
      if (iVar12 != 3) {
        st = (X509_CRL *)0x0;
        BIO_printf(bio_err,"bad input format specified for input crl\n");
        pXVar10 = (X509_CRL *)0x1;
        p7 = (X509_CRL *)0x0;
        goto LAB_0001eef4;
      }
      st = PEM_read_bio_X509_CRL((BIO *)a,(X509_CRL **)0x0,(undefined1 *)0x0,(void *)0x0);
    }
    pXVar10 = st;
    if (st == (X509_CRL *)0x0) {
      pXVar10 = (X509_CRL *)0x1;
      BIO_printf(bio_err,"unable to load CRL\n");
      ERR_print_errors(bio_err);
      p7 = st;
    }
    else {
LAB_0001ef34:
      p7 = (X509_CRL *)PKCS7_new();
      st = pXVar10;
      if ((p7 != (X509_CRL *)0x0) && (pPVar5 = PKCS7_SIGNED_new(), pPVar5 != (PKCS7_SIGNED *)0x0)) {
        pAVar6 = OBJ_nid2obj(0x16);
        p7->akid = (AUTHORITY_KEYID *)pPVar5;
        ppVar14 = pPVar5->contents;
        p7->flags = (int)pAVar6;
        pAVar6 = OBJ_nid2obj(0x15);
        ppVar14->type = pAVar6;
        iVar12 = ASN1_INTEGER_set(pPVar5->version,1);
        if ((iVar12 != 0) && (p_Var7 = sk_new_null(), p_Var7 != (_STACK *)0x0)) {
          pPVar5->crl = (stack_st_X509_CRL *)p_Var7;
          if (pXVar10 != (X509_CRL *)0x0) {
            sk_push(p_Var7,pXVar10);
          }
          st = (X509_CRL *)sk_new_null();
          if (st != (X509_CRL *)0x0) {
            pPVar5->cert = (stack_st_X509 *)st;
            if (local_3c != (_STACK *)0x0) {
              for (iVar12 = 0; iVar2 = sk_num(local_3c), iVar12 < iVar2; iVar12 = iVar12 + 1) {
                parg = sk_value(local_3c,iVar12);
                pBVar3 = BIO_s_file();
                bp_00 = BIO_new(pBVar3);
                if (bp_00 == (BIO *)0x0) {
                  BIO_printf(bio_err,"error opening the file, %s\n",parg);
LAB_0001f0c0:
                  BIO_printf(bio_err,"error loading certificates\n");
                  ERR_print_errors(bio_err);
                  st = (X509_CRL *)0x0;
                  pXVar10 = (X509_CRL *)0x1;
                  goto LAB_0001eef4;
                }
                lVar4 = BIO_ctrl(bp_00,0x6c,3,parg);
                if (lVar4 < 1) {
                  BIO_printf(bio_err,"error opening the file, %s\n",parg);
                  BIO_free(bp_00);
                  goto LAB_0001f0c0;
                }
                p_Var7 = (_STACK *)
                         PEM_X509_INFO_read_bio
                                   (bp_00,(stack_st_X509_INFO *)0x0,(undefined1 *)0x0,(void *)0x0);
                if (p_Var7 == (_STACK *)0x0) {
                  BIO_printf(bio_err,"error reading the file, %s\n",parg);
                  iVar2 = -1;
                }
                else {
                  iVar2 = 0;
                  while (iVar8 = sk_num(p_Var7), iVar8 != 0) {
                    a_00 = (X509_INFO *)sk_shift(p_Var7);
                    if (a_00->x509 != (X509 *)0x0) {
                      iVar2 = iVar2 + 1;
                      sk_push((_STACK *)st,a_00->x509);
                      a_00->x509 = (X509 *)0x0;
                    }
                    X509_INFO_free(a_00);
                  }
                }
                BIO_free(bp_00);
                if (p_Var7 != (_STACK *)0x0) {
                  sk_free(p_Var7);
                }
                if (iVar2 == -1) goto LAB_0001f0c0;
              }
            }
            sk_free(local_3c);
            if (local_34 == (char *)0x0) {
              BIO_ctrl(bp,0x6a,0,stdout);
            }
            else {
              lVar4 = BIO_ctrl(bp,0x6c,5,local_34);
              if (lVar4 < 1) {
                pXVar10 = (X509_CRL *)0x1;
                perror(local_34);
                st = (X509_CRL *)0x0;
                goto LAB_0001eef4;
              }
            }
            if (iVar13 == 1) {
              st = (X509_CRL *)i2d_PKCS7_bio(bp,(PKCS7 *)p7);
            }
            else {
              if (iVar13 != 3) {
                BIO_printf(bio_err,"bad output format specified for outfile\n");
                st = (X509_CRL *)0x0;
                pXVar10 = (X509_CRL *)0x1;
                goto LAB_0001eef4;
              }
              st = (X509_CRL *)PEM_write_bio_PKCS7(bp,(PKCS7 *)p7);
            }
            if (st == (X509_CRL *)0x0) {
              pXVar10 = (X509_CRL *)0x1;
              BIO_printf(bio_err,"unable to write pkcs7 object\n");
              ERR_print_errors(bio_err);
            }
            else {
              st = (X509_CRL *)0x0;
              pXVar10 = st;
            }
            goto LAB_0001eef4;
          }
        }
      }
      pXVar10 = (X509_CRL *)0x1;
    }
  }
  else {
    st = (X509_CRL *)0x0;
    iVar13 = 3;
    local_3c = (_STACK *)0x0;
    __s = (char *)0x0;
    local_34 = (char *)0x0;
    iVar12 = 3;
LAB_0001ecce:
    do {
      __s1 = *ppcVar11;
      iVar2 = strcmp(__s1,"-inform");
      if (iVar2 == 0) {
        param_1 = param_1 + -1;
        if (param_1 == 0) goto LAB_0001edee;
        ppcVar1 = ppcVar11 + 1;
        ppcVar11 = ppcVar11 + 1;
        iVar12 = str2fmt(*ppcVar1);
      }
      else {
        iVar2 = strcmp(__s1,"-outform");
        if (iVar2 == 0) {
          if (param_1 == 1) goto LAB_0001edee;
          param_1 = param_1 + -2;
          iVar13 = str2fmt(ppcVar11[1]);
          ppcVar11 = ppcVar11 + 2;
          if (param_1 < 1) break;
          goto LAB_0001ecce;
        }
        if ((((*__s1 == '-') && (__s1[1] == 'i')) && (__s1[2] == 'n')) && (__s1[3] == '\0')) {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_0001edee;
          __s = ppcVar11[1];
          ppcVar11 = ppcVar11 + 1;
        }
        else {
          iVar2 = strcmp(__s1,"-nocrl");
          if (iVar2 == 0) {
            st = (X509_CRL *)0x1;
          }
          else {
            iVar2 = strcmp(__s1,"-out");
            if (iVar2 == 0) {
              param_1 = param_1 + -1;
              if (param_1 == 0) goto LAB_0001edee;
              local_34 = ppcVar11[1];
              ppcVar11 = ppcVar11 + 1;
            }
            else {
              iVar2 = strcmp(__s1,"-certfile");
              if (iVar2 != 0) {
                BIO_printf(bio_err,"unknown option %s\n",__s1);
LAB_0001edee:
                BIO_printf(bio_err,"%s [options] <infile >outfile\n",uVar9);
                BIO_printf(bio_err,"where options are\n");
                BIO_printf(bio_err," -inform arg    input format - DER or PEM\n");
                BIO_printf(bio_err," -outform arg   output format - DER or PEM\n");
                BIO_printf(bio_err," -in arg        input file\n");
                BIO_printf(bio_err," -out arg       output file\n");
                BIO_printf(bio_err," -certfile arg  certificates file of chain to a trusted CA\n");
                BIO_printf(bio_err,"                (can be used more than once)\n");
                BIO_printf(bio_err," -nocrl         no crl to load, just certs from \'-certfile\'\n"
                          );
                return (X509_CRL *)0x1;
              }
              param_1 = param_1 + -1;
              if (param_1 == 0) goto LAB_0001edee;
              if ((local_3c == (_STACK *)0x0) &&
                 (local_3c = sk_new_null(), local_3c == (_STACK *)0x0)) {
                return (X509_CRL *)0x1;
              }
              iVar2 = sk_push(local_3c,ppcVar11[1]);
              ppcVar11 = ppcVar11 + 1;
              if (iVar2 == 0) {
                sk_free(local_3c);
                return (X509_CRL *)0x1;
              }
            }
          }
        }
      }
      param_1 = param_1 + -1;
      ppcVar11 = ppcVar11 + 1;
    } while (0 < param_1);
    ERR_load_crypto_strings();
    pBVar3 = BIO_s_file();
    a = (X509_CRL *)BIO_new(pBVar3);
    pBVar3 = BIO_s_file();
    bp = BIO_new(pBVar3);
    if (a == (X509_CRL *)0x0 || bp == (BIO *)0x0) {
LAB_0001eee0:
      st = (X509_CRL *)0x0;
      ERR_print_errors(bio_err);
      pXVar10 = (X509_CRL *)0x1;
      p7 = (X509_CRL *)0x0;
      if (a == (X509_CRL *)0x0) {
        pXVar10 = (X509_CRL *)0x1;
        p7 = a;
        goto LAB_0001eefa;
      }
    }
    else {
      pXVar10 = (X509_CRL *)0x0;
      if (st != (X509_CRL *)0x0) goto LAB_0001ef34;
      if (__s == (char *)0x0) goto LAB_0001efa6;
      lVar4 = BIO_ctrl((BIO *)a,0x6c,3,__s);
      if (0 < lVar4) goto LAB_0001ed5c;
      perror(__s);
      pXVar10 = (X509_CRL *)0x1;
      p7 = st;
    }
  }
LAB_0001eef4:
  BIO_free((BIO *)a);
  a = st;
LAB_0001eefa:
  if (bp != (BIO *)0x0) {
    BIO_free_all(bp);
  }
  if (p7 != (X509_CRL *)0x0) {
    PKCS7_free((PKCS7 *)p7);
  }
  if (a != (X509_CRL *)0x0) {
    X509_CRL_free(a);
    return pXVar10;
  }
  return pXVar10;
}

