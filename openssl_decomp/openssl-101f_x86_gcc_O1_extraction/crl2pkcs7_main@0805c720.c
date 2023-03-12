
undefined4 crl2pkcs7_main(int param_1,undefined4 *param_2)

{
  char **ppcVar1;
  pkcs7_st *ppVar2;
  bool bVar3;
  BIO_METHOD *pBVar4;
  BIO *bp;
  long lVar5;
  PKCS7_SIGNED *pPVar6;
  ASN1_OBJECT *pAVar7;
  _STACK *p_Var8;
  void *parg;
  BIO *bp_00;
  _STACK *st;
  X509_INFO *a;
  int iVar9;
  char **ppcVar10;
  undefined4 uVar11;
  PKCS7 *p7;
  char *pcVar12;
  X509_CRL *a_00;
  char *pcVar13;
  bool bVar14;
  byte bVar15;
  char *pcVar16;
  int local_38;
  int local_34;
  char *local_30;
  _STACK *local_2c;
  char *local_24;
  BIO *local_20;
  
  bVar15 = 0;
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    pBVar4 = BIO_s_file();
    bio_err = BIO_new(pBVar4);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  uVar11 = *param_2;
  ppcVar10 = (char **)(param_2 + 1);
  param_1 = param_1 + -1;
  bVar14 = param_1 == 0;
  if (param_1 < 1) {
    ERR_load_crypto_strings();
    pBVar4 = BIO_s_file();
    local_20 = BIO_new(pBVar4);
    pBVar4 = BIO_s_file();
    bp = BIO_new(pBVar4);
    if ((bp != (BIO *)0x0) && (local_20 != (BIO *)0x0)) {
      local_24 = (char *)0x0;
      local_2c = (_STACK *)0x0;
      local_38 = 3;
      local_34 = 3;
LAB_0805cd51:
      BIO_ctrl(local_20,0x6a,0,stdin);
LAB_0805c871:
      if (local_38 == 1) {
        a_00 = d2i_X509_CRL_bio(local_20,(X509_CRL **)0x0);
      }
      else {
        if (local_38 != 3) {
          uVar11 = 1;
          a_00 = (X509_CRL *)0x0;
          p7 = (PKCS7 *)0x0;
          BIO_printf(bio_err,"bad input format specified for input crl\n");
          goto LAB_0805c8a6;
        }
        a_00 = PEM_read_bio_X509_CRL(local_20,(X509_CRL **)0x0,(undefined1 *)0x0,(void *)0x0);
      }
      if (a_00 == (X509_CRL *)0x0) {
        uVar11 = 1;
        p7 = (PKCS7 *)0x0;
        BIO_printf(bio_err,"unable to load CRL\n");
        ERR_print_errors(bio_err);
      }
      else {
LAB_0805cad2:
        p7 = PKCS7_new();
        uVar11 = 1;
        if ((p7 != (PKCS7 *)0x0) && (pPVar6 = PKCS7_SIGNED_new(), pPVar6 != (PKCS7_SIGNED *)0x0)) {
          pAVar7 = OBJ_nid2obj(0x16);
          p7->type = pAVar7;
          (p7->d).sign = pPVar6;
          ppVar2 = pPVar6->contents;
          pAVar7 = OBJ_nid2obj(0x15);
          ppVar2->type = pAVar7;
          iVar9 = ASN1_INTEGER_set(pPVar6->version,1);
          if ((iVar9 != 0) && (p_Var8 = sk_new_null(), p_Var8 != (_STACK *)0x0)) {
            pPVar6->crl = (stack_st_X509_CRL *)p_Var8;
            if (a_00 != (X509_CRL *)0x0) {
              sk_push(p_Var8,a_00);
            }
            p_Var8 = sk_new_null();
            if (p_Var8 == (_STACK *)0x0) {
              uVar11 = 1;
              a_00 = (X509_CRL *)0x0;
            }
            else {
              pPVar6->cert = (stack_st_X509 *)p_Var8;
              if (local_2c != (_STACK *)0x0) {
                for (local_38 = 0; iVar9 = sk_num(local_2c), local_38 < iVar9;
                    local_38 = local_38 + 1) {
                  parg = sk_value(local_2c,local_38);
                  pBVar4 = BIO_s_file();
                  bp_00 = BIO_new(pBVar4);
                  if (bp_00 == (BIO *)0x0) {
                    BIO_printf(bio_err,"error opening the file, %s\n",parg);
LAB_0805cd95:
                    uVar11 = 1;
                    a_00 = (X509_CRL *)0x0;
                    BIO_printf(bio_err,"error loading certificates\n",parg);
                    ERR_print_errors(bio_err);
                    goto LAB_0805c8a6;
                  }
                  lVar5 = BIO_ctrl(bp_00,0x6c,3,parg);
                  if (lVar5 < 1) {
                    pcVar16 = "error opening the file, %s\n";
LAB_0805cd7f:
                    BIO_printf(bio_err,pcVar16,parg);
                    BIO_free(bp_00);
                    goto LAB_0805cd95;
                  }
                  st = (_STACK *)
                       PEM_X509_INFO_read_bio
                                 (bp_00,(stack_st_X509_INFO *)0x0,(undefined1 *)0x0,(void *)0x0);
                  if (st == (_STACK *)0x0) {
                    pcVar16 = "error reading the file, %s\n";
                    goto LAB_0805cd7f;
                  }
                  while (iVar9 = sk_num(st), iVar9 != 0) {
                    a = (X509_INFO *)sk_shift(st);
                    if (a->x509 != (X509 *)0x0) {
                      sk_push(p_Var8,a->x509);
                      a->x509 = (X509 *)0x0;
                    }
                    X509_INFO_free(a);
                  }
                  BIO_free(bp_00);
                  sk_free(st);
                }
              }
              sk_free(local_2c);
              if (local_24 == (char *)0x0) {
                BIO_ctrl(bp,0x6a,0,stdout);
              }
              else {
                lVar5 = BIO_ctrl(bp,0x6c,5,local_24);
                if (lVar5 < 1) {
                  uVar11 = 1;
                  a_00 = (X509_CRL *)0x0;
                  perror(local_24);
                  goto LAB_0805c8a6;
                }
              }
              if (local_34 == 1) {
                iVar9 = i2d_PKCS7_bio(bp,p7);
              }
              else {
                if (local_34 != 3) {
                  uVar11 = 1;
                  a_00 = (X509_CRL *)0x0;
                  BIO_printf(bio_err,"bad output format specified for outfile\n");
                  goto LAB_0805c8a6;
                }
                iVar9 = PEM_write_bio_PKCS7(bp,p7);
              }
              uVar11 = 0;
              a_00 = (X509_CRL *)0x0;
              if (iVar9 == 0) {
                uVar11 = 1;
                BIO_printf(bio_err,"unable to write pkcs7 object\n");
                ERR_print_errors(bio_err);
              }
            }
          }
        }
      }
LAB_0805c8a6:
      BIO_free(local_20);
      goto LAB_0805c8b5;
    }
  }
  else {
    bVar3 = false;
    local_2c = (_STACK *)0x0;
    local_24 = (char *)0x0;
    local_30 = (char *)0x0;
    local_34 = 3;
    local_38 = 3;
LAB_0805c7b6:
    do {
      pcVar16 = *ppcVar10;
      iVar9 = 8;
      pcVar12 = pcVar16;
      pcVar13 = "-inform";
      do {
        if (iVar9 == 0) break;
        iVar9 = iVar9 + -1;
        bVar14 = *pcVar12 == *pcVar13;
        pcVar12 = pcVar12 + (uint)bVar15 * -2 + 1;
        pcVar13 = pcVar13 + (uint)bVar15 * -2 + 1;
      } while (bVar14);
      if (bVar14) {
        param_1 = param_1 + -1;
        if (param_1 == 0) goto LAB_0805c990;
        ppcVar1 = ppcVar10 + 1;
        ppcVar10 = ppcVar10 + 1;
        local_38 = str2fmt(*ppcVar1);
      }
      else {
        iVar9 = 9;
        pcVar12 = pcVar16;
        pcVar13 = "-outform";
        do {
          if (iVar9 == 0) break;
          iVar9 = iVar9 + -1;
          bVar14 = *pcVar12 == *pcVar13;
          pcVar12 = pcVar12 + (uint)bVar15 * -2 + 1;
          pcVar13 = pcVar13 + (uint)bVar15 * -2 + 1;
        } while (bVar14);
        if (bVar14) {
          if (param_1 == 1) goto LAB_0805c990;
          local_34 = str2fmt(ppcVar10[1]);
          param_1 = param_1 + -2;
          bVar14 = param_1 == 0;
          ppcVar10 = ppcVar10 + 2;
          if (bVar14) break;
          goto LAB_0805c7b6;
        }
        bVar14 = *pcVar16 == '-';
        if ((((bVar14) && (bVar14 = pcVar16[1] == 'i', bVar14)) &&
            (bVar14 = pcVar16[2] == 'n', bVar14)) && (bVar14 = pcVar16[3] == '\0', bVar14)) {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_0805c990;
          local_30 = ppcVar10[1];
          ppcVar10 = ppcVar10 + 1;
        }
        else {
          iVar9 = 7;
          pcVar12 = pcVar16;
          pcVar13 = "-nocrl";
          do {
            if (iVar9 == 0) break;
            iVar9 = iVar9 + -1;
            bVar14 = *pcVar12 == *pcVar13;
            pcVar12 = pcVar12 + (uint)bVar15 * -2 + 1;
            pcVar13 = pcVar13 + (uint)bVar15 * -2 + 1;
          } while (bVar14);
          if (bVar14) {
            bVar3 = true;
          }
          else {
            iVar9 = 5;
            pcVar12 = pcVar16;
            pcVar13 = "-out";
            do {
              if (iVar9 == 0) break;
              iVar9 = iVar9 + -1;
              bVar14 = *pcVar12 == *pcVar13;
              pcVar12 = pcVar12 + (uint)bVar15 * -2 + 1;
              pcVar13 = pcVar13 + (uint)bVar15 * -2 + 1;
            } while (bVar14);
            if (bVar14) {
              param_1 = param_1 + -1;
              if (param_1 == 0) goto LAB_0805c990;
              local_24 = ppcVar10[1];
              ppcVar10 = ppcVar10 + 1;
            }
            else {
              iVar9 = 10;
              pcVar12 = pcVar16;
              pcVar13 = "-certfile";
              do {
                if (iVar9 == 0) break;
                iVar9 = iVar9 + -1;
                bVar14 = *pcVar12 == *pcVar13;
                pcVar12 = pcVar12 + (uint)bVar15 * -2 + 1;
                pcVar13 = pcVar13 + (uint)bVar15 * -2 + 1;
              } while (bVar14);
              if (!bVar14) {
                BIO_printf(bio_err,"unknown option %s\n",pcVar16);
LAB_0805c990:
                BIO_printf(bio_err,"%s [options] <infile >outfile\n",uVar11);
                BIO_printf(bio_err,"where options are\n");
                BIO_printf(bio_err," -inform arg    input format - DER or PEM\n");
                BIO_printf(bio_err," -outform arg   output format - DER or PEM\n");
                BIO_printf(bio_err," -in arg        input file\n");
                BIO_printf(bio_err," -out arg       output file\n");
                BIO_printf(bio_err," -certfile arg  certificates file of chain to a trusted CA\n");
                BIO_printf(bio_err,"                (can be used more than once)\n");
                BIO_printf(bio_err," -nocrl         no crl to load, just certs from \'-certfile\'\n"
                          );
                return 1;
              }
              param_1 = param_1 + -1;
              if (param_1 == 0) goto LAB_0805c990;
              if (local_2c == (_STACK *)0x0) {
                local_2c = sk_new_null();
              }
              ppcVar1 = ppcVar10 + 1;
              ppcVar10 = ppcVar10 + 1;
              sk_push(local_2c,*ppcVar1);
            }
          }
        }
      }
      param_1 = param_1 + -1;
      bVar14 = param_1 == 0;
      ppcVar10 = ppcVar10 + 1;
    } while (!bVar14);
    ERR_load_crypto_strings();
    pBVar4 = BIO_s_file();
    local_20 = BIO_new(pBVar4);
    pBVar4 = BIO_s_file();
    bp = BIO_new(pBVar4);
    if ((local_20 != (BIO *)0x0) && (bp != (BIO *)0x0)) {
      if (bVar3) {
        a_00 = (X509_CRL *)0x0;
        goto LAB_0805cad2;
      }
      if (local_30 == (char *)0x0) goto LAB_0805cd51;
      lVar5 = BIO_ctrl(local_20,0x6c,3,local_30);
      if (0 < lVar5) goto LAB_0805c871;
      uVar11 = 1;
      a_00 = (X509_CRL *)0x0;
      p7 = (PKCS7 *)0x0;
      perror(local_30);
      goto LAB_0805c8a6;
    }
  }
  ERR_print_errors(bio_err);
  if (local_20 != (BIO *)0x0) {
    BIO_free(local_20);
  }
  if (bp == (BIO *)0x0) {
    return 1;
  }
  p7 = (PKCS7 *)0x0;
  a_00 = (X509_CRL *)0x0;
  uVar11 = 1;
LAB_0805c8b5:
  BIO_free_all(bp);
  if (p7 != (PKCS7 *)0x0) {
    PKCS7_free(p7);
  }
  if (a_00 == (X509_CRL *)0x0) {
    return uVar11;
  }
  X509_CRL_free(a_00);
  return uVar11;
}

