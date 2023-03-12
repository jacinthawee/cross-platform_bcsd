
BIO * load_pubkey(BIO *param_1,BIO *param_2,int param_3,int param_4,undefined4 param_5,BIO *param_6,
                 undefined4 param_7)

{
  BIO_METHOD *type;
  long lVar1;
  rsa_st *key;
  uint uVar2;
  BIO *pkey;
  undefined4 local_28;
  BIO *local_24;
  
  local_28 = param_5;
  local_24 = param_2;
  if (param_2 == (BIO *)0x0) {
    if (param_3 == 7 || param_4 == 0) {
      BIO_printf(param_1,"no keyfile specified\n");
      param_6 = param_2;
      goto LAB_000339b8;
    }
  }
  else if (param_3 == 7) {
    if (param_6 == (BIO *)0x0) {
      BIO_printf(bio_err,"no engine specified\n");
    }
    else {
      param_6 = (BIO *)ENGINE_load_public_key((ENGINE *)param_6,(char *)param_2,ui_method,&local_28)
      ;
      if (param_6 != (BIO *)0x0) {
        return param_6;
      }
    }
    goto LAB_000339b8;
  }
  type = BIO_s_file();
  param_6 = BIO_new(type);
  if (param_6 == (BIO *)0x0) {
    ERR_print_errors(param_1);
    goto LAB_000339b8;
  }
  uVar2 = count_leading_zeroes(param_2);
  pkey = (BIO *)(uVar2 >> 5);
  if (param_4 == 0) {
    pkey = (BIO *)0x0;
  }
  if (pkey == (BIO *)0x0) {
    lVar1 = BIO_ctrl(param_6,0x6c,3,param_2);
    if (0 < lVar1) goto LAB_00033984;
    BIO_printf(param_1,"Error opening %s %s\n",param_7,param_2);
    ERR_print_errors(param_1);
  }
  else {
    setvbuf(stdin,(char *)0x0,2,0);
    BIO_ctrl(param_6,0x6a,0,stdin);
LAB_00033984:
    if (param_3 == 1) {
      pkey = (BIO *)d2i_PUBKEY_bio(param_6,(EVP_PKEY **)0x0);
    }
    else if (param_3 == 10) {
      key = d2i_RSAPublicKey_bio(param_6,(RSA **)0x0);
      if (key == (rsa_st *)0x0) goto LAB_00033a4a;
LAB_00033a1c:
      pkey = (BIO *)EVP_PKEY_new();
      if (pkey != (BIO *)0x0) {
        EVP_PKEY_set1_RSA((EVP_PKEY *)pkey,key);
      }
      RSA_free(key);
    }
    else if (param_3 == 9) {
      key = PEM_read_bio_RSAPublicKey(param_6,(RSA **)0x0,password_callback + 1,&local_28);
      if (key != (rsa_st *)0x0) goto LAB_00033a1c;
LAB_00033a4a:
      pkey = (BIO *)0x0;
    }
    else if (param_3 == 3) {
      pkey = (BIO *)PEM_read_bio_PUBKEY(param_6,(EVP_PKEY **)0x0,password_callback + 1,&local_28);
    }
    else if (param_3 == 4 || param_3 == 8) {
      pkey = (BIO *)load_netscape_key(param_1,param_6,param_2,param_7,param_3);
    }
    else {
      pkey = (BIO *)0x0;
      if (param_3 == 0xb) {
        pkey = (BIO *)b2i_PublicKey_bio(param_6);
      }
      else {
        BIO_printf(param_1,"bad input format specified for key file\n");
      }
    }
  }
  BIO_free(param_6);
  param_6 = pkey;
  if (pkey != (BIO *)0x0) {
    return pkey;
  }
LAB_000339b8:
  BIO_printf(param_1,"unable to load %s\n",param_7);
  return param_6;
}

