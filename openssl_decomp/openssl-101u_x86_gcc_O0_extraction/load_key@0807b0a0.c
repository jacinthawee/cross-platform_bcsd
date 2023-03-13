
EVP_PKEY *
load_key(BIO *param_1,UI_METHOD *param_2,int param_3,int param_4,undefined4 param_5,char *param_6,
        undefined4 param_7)

{
  BIO_METHOD *pBVar1;
  BIO *bp;
  long lVar2;
  int in_GS_OFFSET;
  undefined4 *e;
  EVP_PKEY *local_2c;
  undefined4 local_28;
  UI_METHOD *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_2c = (EVP_PKEY *)0x0;
  local_24 = param_2;
  local_28 = param_5;
  if (param_2 == (UI_METHOD *)0x0) {
    if ((param_4 == 0) || (param_3 == 7)) {
      BIO_printf(param_1,"no keyfile specified\n");
    }
    else {
      pBVar1 = BIO_s_file();
      bp = BIO_new(pBVar1);
      if (bp == (BIO *)0x0) goto LAB_0807b1f8;
      setvbuf(stdin,(char *)0x0,2,0);
      BIO_ctrl(bp,0x6a,0,stdin);
LAB_0807b161:
      if (param_3 == 1) {
        local_2c = d2i_PrivateKey_bio(bp,(EVP_PKEY **)0x0);
      }
      else if (param_3 == 3) {
        local_2c = PEM_read_bio_PrivateKey(bp,(EVP_PKEY **)0x0,password_callback,&local_28);
      }
      else if ((param_3 - 4U & 0xfffffffb) == 0) {
        local_2c = (EVP_PKEY *)load_netscape_key(param_7,param_3);
      }
      else if (param_3 == 5) {
        load_pkcs12_constprop_4(password_callback,&local_28,&local_2c,0);
      }
      else if (param_3 == 0xb) {
        local_2c = b2i_PrivateKey_bio(bp);
      }
      else if (param_3 == 0xc) {
        local_2c = b2i_PVK_bio(bp,password_callback,&local_28);
      }
      else {
        BIO_printf(param_1,"bad input format specified for key file\n");
      }
LAB_0807b1b9:
      BIO_free(bp);
    }
  }
  else if (param_3 == 7) {
    if (param_6 == (char *)0x0) {
      BIO_printf(param_1,"no engine specified\n");
    }
    else {
      e = &local_28;
      local_2c = ENGINE_load_private_key((ENGINE *)e,param_6,param_2,ui_method);
      if (local_2c != (EVP_PKEY *)0x0) goto LAB_0807b10e;
      BIO_printf(param_1,"cannot load %s from engine\n",param_7,e);
      ERR_print_errors(param_1);
    }
  }
  else {
    pBVar1 = BIO_s_file();
    bp = BIO_new(pBVar1);
    if (bp != (BIO *)0x0) {
      lVar2 = BIO_ctrl(bp,0x6c,3,param_2);
      if (0 < lVar2) goto LAB_0807b161;
      BIO_printf(param_1,"Error opening %s %s\n",param_7,param_2);
      ERR_print_errors(param_1);
      goto LAB_0807b1b9;
    }
LAB_0807b1f8:
    ERR_print_errors(param_1);
  }
  if (local_2c == (EVP_PKEY *)0x0) {
    BIO_printf(param_1,"unable to load %s\n",param_7);
    ERR_print_errors(param_1);
  }
LAB_0807b10e:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return local_2c;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

