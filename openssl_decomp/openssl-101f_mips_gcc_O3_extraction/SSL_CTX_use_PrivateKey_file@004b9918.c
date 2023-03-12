
int SSL_CTX_use_PrivateKey_file(SSL_CTX *ctx,char *file,int type)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  uVar1 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  iVar2 = (*(code *)PTR_BIO_new_006a7fa4)(uVar1);
  if (iVar2 == 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xb0,7,&DAT_00649ed0,0x282);
    return 0;
  }
  iVar3 = (*(code *)PTR_BIO_ctrl_006a7f18)(iVar2,0x6c,3,file);
  if (iVar3 < 1) {
    uVar4 = 2;
    uVar1 = 0x288;
LAB_004b99b0:
    iVar5 = 0;
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xb0,uVar4,&DAT_00649ed0,uVar1);
  }
  else {
    if (type == 1) {
      iVar3 = (*(code *)PTR_PEM_read_bio_PrivateKey_006a8c78)
                        (iVar2,0,ctx->default_passwd_callback,ctx->default_passwd_callback_userdata)
      ;
      uVar1 = 9;
    }
    else {
      if (type != 2) {
        uVar4 = 0x7c;
        uVar1 = 0x298;
        goto LAB_004b99b0;
      }
      iVar3 = (*(code *)PTR_d2i_PrivateKey_bio_006a8c74)(iVar2,0);
      uVar1 = 0xd;
    }
    if (iVar3 == 0) {
      iVar5 = 0;
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xb0,uVar1,&DAT_00649ed0,0x29d);
    }
    else {
      iVar5 = ssl_cert_inst(&ctx->cert);
      if (iVar5 == 0) {
        iVar5 = 0;
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xae,0x41,&DAT_00649ed0,0x272);
      }
      else {
        iVar5 = ssl_set_pkey(ctx->cert,iVar3);
      }
      (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar3);
    }
  }
  (*(code *)PTR_BIO_free_006a7f70)(iVar2);
  return iVar5;
}

