
int certify(undefined4 param_1,char *param_2,EVP_PKEY *param_3,undefined4 param_4,undefined4 param_5
           ,undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
           undefined4 param_10,undefined4 param_11,undefined4 param_12,undefined4 param_13,
           undefined4 param_14,undefined4 param_15,undefined4 param_16,undefined4 param_17,
           undefined4 param_18,undefined4 param_19,int param_20,undefined4 param_21,
           undefined4 param_22,undefined4 param_23,undefined4 param_24,int param_25)

{
  BIO_METHOD *type;
  BIO *bp;
  long lVar1;
  X509_REQ *req;
  int iVar2;
  EVP_PKEY *r;
  
  type = BIO_s_file();
  bp = BIO_new(type);
  lVar1 = BIO_ctrl(bp,0x6c,3,param_2);
  if (lVar1 < 1) {
    perror(param_2);
  }
  else {
    req = PEM_read_bio_X509_REQ(bp,(X509_REQ **)0x0,(undefined1 *)0x0,(void *)0x0);
    if (req != (X509_REQ *)0x0) {
      if (param_20 != 0) {
        X509_REQ_print(bio_err,req);
      }
      BIO_printf(bio_err,"Check that the request matches the signature\n");
      if ((param_25 == 0) || (iVar2 = X509_REQ_check_private_key(req,param_3), iVar2 != 0)) {
        r = X509_REQ_get_pubkey(req);
        if (r == (EVP_PKEY *)0x0) {
          iVar2 = -1;
          BIO_printf(bio_err,"error unpacking public key\n");
        }
        else {
          iVar2 = X509_REQ_verify(req,r);
          EVP_PKEY_free(r);
          if (iVar2 < 0) {
            iVar2 = 0;
            BIO_printf(bio_err,"Signature verification problems....\n");
          }
          else if (iVar2 == 0) {
            BIO_printf(bio_err,"Signature did not match the certificate request\n");
          }
          else {
            BIO_printf(bio_err,"Signature ok\n");
            iVar2 = do_body(param_1,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10
                            ,param_11,param_12,param_13,param_14,param_15,param_16,param_17,param_20
                            ,req,param_18,param_19,param_21,param_22,param_23,param_24,param_25);
          }
        }
      }
      else {
        BIO_printf(bio_err,"Certificate request and CA private key do not match\n");
      }
      X509_REQ_free(req);
      goto LAB_00012eba;
    }
    BIO_printf(bio_err,"Error reading certificate request in %s\n",param_2);
  }
  iVar2 = -1;
LAB_00012eba:
  if (bp != (BIO *)0x0) {
    BIO_free(bp);
  }
  return iVar2;
}

