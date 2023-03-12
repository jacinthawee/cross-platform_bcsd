
EVP_PKEY *
load_key(BIO *param_1,char *param_2,int param_3,int param_4,undefined4 param_5,ENGINE *param_6,
        undefined4 param_7)

{
  BIO_METHOD *type;
  BIO *bp;
  long lVar1;
  uint uVar2;
  EVP_PKEY *local_24;
  undefined4 local_20;
  char *local_1c;
  
  local_20 = param_5;
  local_24 = (EVP_PKEY *)0x0;
  local_1c = param_2;
  if (param_2 == (char *)0x0) {
    if (param_3 == 7 || param_4 == 0) {
      BIO_printf(param_1,"no keyfile specified\n");
      goto joined_r0x00033bea;
    }
  }
  else if (param_3 == 7) {
    if (param_6 == (ENGINE *)0x0) {
      BIO_printf(param_1,"no engine specified\n");
    }
    else {
      local_24 = ENGINE_load_private_key(param_6,param_2,ui_method,&local_20);
      if (local_24 == (EVP_PKEY *)0x0) {
        BIO_printf(param_1,"cannot load %s from engine\n",param_7);
        ERR_print_errors(param_1);
      }
    }
    goto joined_r0x00033bea;
  }
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    ERR_print_errors(param_1);
    goto joined_r0x00033bea;
  }
  uVar2 = count_leading_zeroes(param_2);
  uVar2 = uVar2 >> 5;
  if (param_4 == 0) {
    uVar2 = 0;
  }
  if (uVar2 == 0) {
    lVar1 = BIO_ctrl(bp,0x6c,3,param_2);
    if (0 < lVar1) goto LAB_00033bae;
    BIO_printf(param_1,"Error opening %s %s\n",param_7,param_2);
    ERR_print_errors(param_1);
  }
  else {
    setvbuf(stdin,(char *)0x0,2,0);
    BIO_ctrl(bp,0x6a,0,stdin);
LAB_00033bae:
    if (param_3 == 1) {
      local_24 = d2i_PrivateKey_bio(bp,(EVP_PKEY **)0x0);
    }
    else if (param_3 == 3) {
      local_24 = PEM_read_bio_PrivateKey(bp,(EVP_PKEY **)0x0,password_callback + 1,&local_20);
    }
    else if (param_3 == 4 || param_3 == 8) {
      local_24 = (EVP_PKEY *)load_netscape_key(param_1,bp,param_2,param_7,param_3);
    }
    else if (param_3 == 5) {
      load_pkcs12_constprop_3(param_1,bp,param_7,0x32f95,&local_20,&local_24,0);
    }
    else if (param_3 == 0xb) {
      local_24 = b2i_PrivateKey_bio(bp);
    }
    else if (param_3 == 0xc) {
      local_24 = b2i_PVK_bio(bp,password_callback + 1,&local_20);
    }
    else {
      BIO_printf(param_1,"bad input format specified for key file\n");
    }
  }
  BIO_free(bp);
joined_r0x00033bea:
  if (local_24 != (EVP_PKEY *)0x0) {
    return local_24;
  }
  BIO_printf(param_1,"unable to load %s\n",param_7);
  ERR_print_errors(param_1);
  return local_24;
}

