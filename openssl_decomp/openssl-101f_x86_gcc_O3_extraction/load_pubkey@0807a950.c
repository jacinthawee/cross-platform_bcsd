
EVP_PKEY *
load_pubkey(BIO *param_1,UI_METHOD *param_2,int param_3,int param_4,undefined4 param_5,char *param_6
           ,undefined4 param_7)

{
  EVP_PKEY *pkey;
  BIO_METHOD *pBVar1;
  BIO *bp;
  long lVar2;
  rsa_st *key;
  int in_GS_OFFSET;
  undefined4 local_28;
  UI_METHOD *local_24;
  int local_20;
  
  local_24 = param_2;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_28 = param_5;
  if (param_2 == (UI_METHOD *)0x0) {
    if ((param_4 == 0) || (param_3 == 7)) {
      BIO_printf(param_1,"no keyfile specified\n");
    }
    else {
      pBVar1 = BIO_s_file();
      bp = BIO_new(pBVar1);
      if (bp == (BIO *)0x0) goto LAB_0807aae0;
      setvbuf(stdin,(char *)0x0,2,0);
      BIO_ctrl(bp,0x6a,0,stdin);
LAB_0807aa11:
      if (param_3 == 1) {
        pkey = d2i_PUBKEY_bio(bp,(EVP_PKEY **)0x0);
      }
      else if (param_3 == 10) {
        key = d2i_RSAPublicKey_bio(bp,(RSA **)0x0);
        if (key == (rsa_st *)0x0) goto LAB_0807ab83;
LAB_0807ab3c:
        pkey = EVP_PKEY_new();
        if (pkey != (EVP_PKEY *)0x0) {
          EVP_PKEY_set1_RSA(pkey,key);
        }
        RSA_free(key);
      }
      else if (param_3 == 9) {
        key = PEM_read_bio_RSAPublicKey(bp,(RSA **)0x0,password_callback,&local_28);
        if (key != (rsa_st *)0x0) goto LAB_0807ab3c;
LAB_0807ab83:
        pkey = (EVP_PKEY *)0x0;
      }
      else if (param_3 == 3) {
        pkey = PEM_read_bio_PUBKEY(bp,(EVP_PKEY **)0x0,password_callback,&local_28);
      }
      else if ((param_3 - 4U & 0xfffffffb) == 0) {
        pkey = (EVP_PKEY *)load_netscape_key(param_7,param_3);
      }
      else if (param_3 == 0xb) {
        pkey = b2i_PublicKey_bio(bp);
      }
      else {
        pkey = (EVP_PKEY *)0x0;
        BIO_printf(param_1,"bad input format specified for key file\n");
      }
LAB_0807aa54:
      BIO_free(bp);
LAB_0807a9b3:
      if (pkey != (EVP_PKEY *)0x0) goto LAB_0807a9bb;
    }
  }
  else if (param_3 == 7) {
    if (param_6 != (char *)0x0) {
      pkey = ENGINE_load_public_key((ENGINE *)&local_28,param_6,param_2,ui_method);
      goto LAB_0807a9b3;
    }
    BIO_printf(bio_err,"no engine specified\n");
  }
  else {
    pBVar1 = BIO_s_file();
    bp = BIO_new(pBVar1);
    if (bp != (BIO *)0x0) {
      lVar2 = BIO_ctrl(bp,0x6c,3,param_2);
      if (0 < lVar2) goto LAB_0807aa11;
      pkey = (EVP_PKEY *)0x0;
      BIO_printf(param_1,"Error opening %s %s\n",param_7,param_2);
      ERR_print_errors(param_1);
      goto LAB_0807aa54;
    }
LAB_0807aae0:
    ERR_print_errors(param_1);
  }
  pkey = (EVP_PKEY *)0x0;
  BIO_printf(param_1,"unable to load %s\n",param_7);
LAB_0807a9bb:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pkey;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

