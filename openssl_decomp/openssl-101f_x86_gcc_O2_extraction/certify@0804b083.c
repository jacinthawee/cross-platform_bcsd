
undefined4 __regparm3
certify(undefined4 param_1_00,char *param_2_00,EVP_PKEY *param_3_00,undefined4 param_1,
       undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
       undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
       undefined4 param_10,undefined4 param_11,undefined4 param_12,undefined4 param_13,
       undefined4 param_14,undefined4 param_15,undefined4 param_16,int param_17,undefined4 param_18,
       undefined4 param_19,undefined4 param_20,undefined4 param_21,int param_22)

{
  BIO_METHOD *type;
  BIO *bp;
  long lVar1;
  X509_REQ *req;
  X509_REQ *pXVar2;
  int iVar3;
  EVP_PKEY *r;
  undefined4 extraout_EDX;
  undefined4 uVar4;
  
  type = BIO_s_file();
  bp = BIO_new(type);
  lVar1 = BIO_ctrl(bp,0x6c,3,param_2_00);
  if (lVar1 < 1) {
    perror(param_2_00);
  }
  else {
    req = PEM_read_bio_X509_REQ(bp,(X509_REQ **)0x0,(undefined1 *)0x0,(void *)0x0);
    if (req != (X509_REQ *)0x0) {
      pXVar2 = req;
      if (param_17 != 0) {
        pXVar2 = (X509_REQ *)X509_REQ_print(bio_err,req);
      }
      BIO_printf(bio_err,"Check that the request matches the signature\n",pXVar2,pXVar2);
      if (param_22 == 0) {
LAB_0804b157:
        r = X509_REQ_get_pubkey(req);
        if (r == (EVP_PKEY *)0x0) {
          uVar4 = 0xffffffff;
          BIO_printf(bio_err,"error unpacking public key\n",0,0);
        }
        else {
          iVar3 = X509_REQ_verify(req,r);
          EVP_PKEY_free(r);
          if (iVar3 < 0) {
            uVar4 = 0;
            BIO_printf(bio_err,"Signature verification problems....\n",param_3_00,param_3_00);
          }
          else if (iVar3 == 0) {
            uVar4 = 0;
            BIO_printf(bio_err,"Signature did not match the certificate request\n",r,r);
          }
          else {
            BIO_printf(bio_err,"Signature ok\n",iVar3,iVar3);
            uVar4 = do_body(param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10
                            ,param_11,param_12,param_13,param_14,param_17,req,param_15,param_16,
                            param_18,param_19,param_20,param_21,param_22);
          }
        }
      }
      else {
        iVar3 = X509_REQ_check_private_key(req,param_3_00);
        if (iVar3 != 0) goto LAB_0804b157;
        uVar4 = 0;
        BIO_printf(bio_err,"Certificate request and CA private key do not match\n",0,0);
      }
      X509_REQ_free(req);
      goto LAB_0804b2ab;
    }
    BIO_printf(bio_err,"Error reading certificate request in %s\n",param_2_00,extraout_EDX);
  }
  uVar4 = 0xffffffff;
LAB_0804b2ab:
  if (bp != (BIO *)0x0) {
    BIO_free(bp);
  }
  return uVar4;
}

