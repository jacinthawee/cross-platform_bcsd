
EVP_PKEY_CTX *
set_keygen_ctx(BIO *param_1,byte *param_2,int *param_3,long *param_4,char **param_5,ENGINE *param_6)

{
  BIO *bp;
  X509 *x;
  int iVar1;
  EVP_PKEY_ASN1_METHOD *pEVar2;
  char *pcVar3;
  EVP_PKEY_CTX *ctx;
  int iVar4;
  EVP_PKEY *pkey;
  long p1;
  size_t len;
  ENGINE *local_30;
  ENGINE *local_2c [2];
  
  if (param_2 == (byte *)0x0) {
    p1 = *param_4;
    *param_3 = 6;
  }
  else if (*param_2 - 0x30 < 10) {
    *param_3 = 6;
    p1 = strtol((char *)param_2,(char **)0x0,10);
    *param_4 = p1;
  }
  else {
    iVar4 = strncmp((char *)param_2,"param:",6);
    if (iVar4 == 0) {
      param_2 = param_2 + 6;
LAB_00012026:
      p1 = -1;
      if (param_2 != (byte *)0x0) {
        bp = BIO_new_file((char *)param_2,"r");
        if (bp == (BIO *)0x0) {
          BIO_printf(param_1,"Can\'t open parameter file %s\n",param_2);
          return (EVP_PKEY_CTX *)0x0;
        }
        pkey = PEM_read_bio_Parameters(bp,(EVP_PKEY **)0x0);
        if (pkey == (EVP_PKEY *)0x0) {
          BIO_ctrl(bp,1,0,(void *)0x0);
          x = PEM_read_bio_X509(bp,(X509 **)0x0,(undefined1 *)0x0,(void *)0x0);
          if (x != (X509 *)0x0) {
            pkey = X509_get_pubkey(x);
            X509_free(x);
          }
        }
        BIO_free(bp);
        if (pkey == (EVP_PKEY *)0x0) {
          BIO_printf(param_1,"Error reading parameter file %s\n",param_2);
          return (EVP_PKEY_CTX *)0x0;
        }
        iVar4 = *param_3;
        if (iVar4 == -1) {
          iVar4 = EVP_PKEY_id(pkey);
          *param_3 = iVar4;
        }
        else {
          iVar1 = EVP_PKEY_base_id(pkey);
          if (iVar4 != iVar1) {
            BIO_printf(param_1,"Key Type does not match parameters\n");
            EVP_PKEY_free(pkey);
            return (EVP_PKEY_CTX *)0x0;
          }
        }
        goto LAB_000120d2;
      }
    }
    else {
      pcVar3 = strchr((char *)param_2,0x3a);
      if (pcVar3 == (char *)0x0) {
        len = strlen((char *)param_2);
      }
      else {
        len = (int)pcVar3 - (int)param_2;
      }
      pEVar2 = EVP_PKEY_asn1_find_str(local_2c,(char *)param_2,len);
      if (pEVar2 == (EVP_PKEY_ASN1_METHOD *)0x0) {
        BIO_printf(param_1,"Unknown algorithm %.*s\n",len,param_2);
        return (EVP_PKEY_CTX *)0x0;
      }
      EVP_PKEY_asn1_get0_info((int *)0x0,param_3,(int *)0x0,(char **)0x0,(char **)0x0,pEVar2);
      if (local_2c[0] != (ENGINE *)0x0) {
        ENGINE_finish(local_2c[0]);
      }
      if (*param_3 == 6) {
        if (pcVar3 == (char *)0x0) {
          p1 = *param_4;
        }
        else {
          p1 = strtol(pcVar3 + 1,(char **)0x0,10);
          *param_4 = p1;
        }
      }
      else {
        if (pcVar3 != (char *)0x0) {
          param_2 = (byte *)(pcVar3 + 1);
          goto LAB_00012026;
        }
        p1 = -1;
      }
    }
  }
  pkey = (EVP_PKEY *)0x0;
LAB_000120d2:
  if (param_5 != (char **)0x0) {
    pEVar2 = EVP_PKEY_asn1_find(&local_30,*param_3);
    if (pEVar2 == (EVP_PKEY_ASN1_METHOD *)0x0) {
      BIO_puts(param_1,"Internal error: can\'t find key algorithm\n");
      return (EVP_PKEY_CTX *)0x0;
    }
    EVP_PKEY_asn1_get0_info((int *)0x0,(int *)0x0,(int *)0x0,(char **)0x0,(char **)local_2c,pEVar2);
    pcVar3 = BUF_strdup((char *)local_2c[0]);
    *param_5 = pcVar3;
    if (local_30 != (ENGINE *)0x0) {
      ENGINE_finish(local_30);
    }
  }
  if (pkey == (EVP_PKEY *)0x0) {
    ctx = EVP_PKEY_CTX_new_id(*param_3,param_6);
  }
  else {
    ctx = EVP_PKEY_CTX_new(pkey,param_6);
    iVar4 = EVP_PKEY_bits(pkey);
    *param_4 = iVar4;
    EVP_PKEY_free(pkey);
  }
  if (ctx == (EVP_PKEY_CTX *)0x0) {
    BIO_puts(param_1,"Error allocating keygen context\n");
    ERR_print_errors(param_1);
  }
  else {
    iVar4 = EVP_PKEY_keygen_init(ctx);
    if (iVar4 < 1) {
      BIO_puts(param_1,"Error initializing keygen context\n");
      ERR_print_errors(param_1);
      ctx = (EVP_PKEY_CTX *)0x0;
    }
    else if (((*param_3 == 6) && (p1 != -1)) &&
            (iVar4 = EVP_PKEY_CTX_ctrl(ctx,6,4,0x1003,p1,(void *)0x0), iVar4 < 1)) {
      BIO_puts(param_1,"Error setting RSA keysize\n");
      ERR_print_errors(param_1);
      EVP_PKEY_CTX_free(ctx);
      ctx = (EVP_PKEY_CTX *)0x0;
    }
  }
  return ctx;
}

