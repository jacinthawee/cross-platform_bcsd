
int SSL_CTX_use_certificate_file(SSL_CTX *ctx,char *file,int type)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  uVar1 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  iVar2 = (*(code *)PTR_BIO_new_006a6ea4)(uVar1);
  if (iVar2 == 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xad,7,&DAT_00649450,0x1c1);
    return 0;
  }
  iVar3 = (*(code *)PTR_BIO_ctrl_006a6e18)(iVar2,0x6c,3,file);
  if (iVar3 < 1) {
    uVar4 = 2;
    uVar1 = 0x1c6;
LAB_004b5c44:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xad,uVar4,&DAT_00649450,uVar1);
  }
  else {
    if (type == 2) {
      iVar3 = (*(code *)PTR_d2i_X509_bio_006a7b74)(iVar2,0);
      uVar1 = 0xd;
    }
    else {
      if (type != 1) {
        uVar4 = 0x7c;
        uVar1 = 0x1d1;
        goto LAB_004b5c44;
      }
      iVar3 = (*(code *)PTR_PEM_read_bio_X509_006a6fcc)
                        (iVar2,0,ctx->default_passwd_callback,ctx->default_passwd_callback_userdata)
      ;
      uVar1 = 9;
    }
    if (iVar3 != 0) {
      iVar5 = ssl_cert_inst(&ctx->cert);
      if (iVar5 == 0) {
        iVar5 = 0;
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xab,0x41,&DAT_00649450,0x174);
      }
      else {
        iVar5 = ssl_set_cert(ctx->cert,iVar3);
      }
      (*(code *)PTR_X509_free_006a6e90)(iVar3);
      goto LAB_004b5c5c;
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xad,uVar1,&DAT_00649450,0x1d6);
  }
  iVar5 = 0;
LAB_004b5c5c:
  (*(code *)PTR_BIO_free_006a6e70)(iVar2);
  return iVar5;
}

