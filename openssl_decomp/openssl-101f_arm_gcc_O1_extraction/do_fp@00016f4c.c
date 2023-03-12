
undefined4
do_fp(BIO *param_1,uchar *param_2,BIO *param_3,int param_4,int param_5,int param_6,uchar *param_7,
     size_t param_8,int param_9,int param_10,undefined4 param_11)

{
  int iVar1;
  undefined4 uVar2;
  char *format;
  size_t local_20;
  EVP_MD_CTX *local_1c;
  
  do {
    iVar1 = BIO_read(param_3,param_2,0x2000);
    if (iVar1 < 0) {
      BIO_printf(bio_err,"Read Error in %s\n",param_11);
      ERR_print_errors(bio_err);
      return 1;
    }
  } while (iVar1 != 0);
  if (param_7 == (uchar *)0x0) {
    if (param_6 == 0) {
      local_20 = BIO_gets(param_3,(char *)param_2,0x2000);
      if ((int)local_20 < 0) {
        ERR_print_errors(bio_err);
        return 1;
      }
    }
    else {
      BIO_ctrl(param_3,0x78,0,&local_1c);
      local_20 = 0x2000;
      iVar1 = EVP_DigestSignFinal(local_1c,param_2,&local_20);
      if (iVar1 == 0) {
        format = "Error Signing Data\n";
        goto LAB_00017078;
      }
    }
    if (param_5 == 0) {
      if (param_4 == 2) {
        if (0 < (int)local_20) {
          do {
            BIO_printf(param_1,"%02x",(uint)param_2[param_5]);
            param_5 = param_5 + 1;
          } while (param_5 < (int)local_20);
        }
        BIO_printf(param_1," *%s\n",param_11);
        uVar2 = 0;
      }
      else {
        if (param_9 == 0) {
          if (param_10 == 0) {
            BIO_printf(param_1,"(%s)= ",param_11);
          }
          else {
            BIO_printf(param_1,"%s(%s)= ",param_10,param_11);
          }
        }
        else {
          BIO_printf(param_1,"%s-%s(%s)= ",param_9,param_10,param_11);
        }
        if (0 < (int)local_20) {
          iVar1 = 0;
          while( true ) {
            BIO_printf(param_1,"%02x",(uint)param_2[iVar1]);
            iVar1 = iVar1 + 1;
            if ((int)local_20 <= iVar1) break;
            if (iVar1 != 0 && param_4 != 0) {
              BIO_printf(param_1,":");
            }
          }
        }
        BIO_printf(param_1,"\n");
        uVar2 = 0;
      }
    }
    else {
      BIO_write(param_1,param_2,local_20);
      uVar2 = 0;
    }
  }
  else {
    BIO_ctrl(param_3,0x78,0,&local_1c);
    iVar1 = EVP_DigestVerifyFinal(local_1c,param_7,param_8);
    if (0 < iVar1) {
      BIO_printf(param_1,"Verified OK\n");
      return 0;
    }
    if (iVar1 != 0) {
      format = "Error Verifying Data\n";
LAB_00017078:
      BIO_printf(bio_err,format);
      ERR_print_errors(bio_err);
      return 1;
    }
    BIO_printf(param_1,"Verification Failure\n");
    uVar2 = 1;
  }
  return uVar2;
}

