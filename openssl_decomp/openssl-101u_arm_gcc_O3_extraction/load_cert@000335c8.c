
X509 * load_cert(BIO *param_1,void *param_2,int param_3,undefined4 param_4,undefined4 param_5,
                undefined4 param_6)

{
  BIO_METHOD *type;
  BIO *bp;
  long lVar1;
  NETSCAPE_X509 *a;
  int iVar2;
  X509 *local_1c;
  
  local_1c = (X509 *)0x0;
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
LAB_00033670:
    ERR_print_errors(param_1);
  }
  else {
    if (param_2 == (void *)0x0) {
      setvbuf(stdin,(char *)0x0,2,0);
      BIO_ctrl(bp,0x6a,0,stdin);
    }
    else {
      lVar1 = BIO_ctrl(bp,0x6c,3,param_2);
      if (lVar1 < 1) {
        BIO_printf(param_1,"Error opening %s %s\n",param_6,param_2);
        goto LAB_00033670;
      }
    }
    if (param_3 == 1) {
      local_1c = d2i_X509_bio(bp,(X509 **)0x0);
    }
    else if (param_3 == 4) {
      a = (NETSCAPE_X509 *)ASN1_item_d2i_bio((ASN1_ITEM *)&NETSCAPE_X509_it,bp,(void *)0x0);
      if (a != (NETSCAPE_X509 *)0x0) {
        iVar2 = strncmp("certificate",(char *)a->header->data,a->header->length);
        if (iVar2 == 0) {
          local_1c = a->cert;
          a->cert = (X509 *)0x0;
          NETSCAPE_X509_free(a);
        }
        else {
          NETSCAPE_X509_free(a);
          BIO_printf(param_1,"Error reading header on certificate\n");
        }
      }
    }
    else if (param_3 == 3) {
      local_1c = PEM_read_bio_X509_AUX(bp,(X509 **)0x0,password_callback + 1,(void *)0x0);
    }
    else if (param_3 == 5) {
      load_pkcs12_constprop_3(param_1,bp,param_6,0,0,0,&local_1c);
    }
    else {
      BIO_printf(param_1,"bad input format specified for %s\n",param_6);
    }
  }
  if (local_1c == (X509 *)0x0) {
    BIO_printf(param_1,"unable to load certificate\n");
    ERR_print_errors(param_1);
  }
  if (bp != (BIO *)0x0) {
    BIO_free(bp);
  }
  return local_1c;
}

