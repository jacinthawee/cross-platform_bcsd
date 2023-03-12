
int SSL_CTX_use_RSAPrivateKey_file(SSL_CTX *ctx,char *file,int type)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  uVar1 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  iVar2 = (*(code *)PTR_BIO_new_006a7fa4)(uVar1);
  if (iVar2 == 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xb3,7,&DAT_00649ed0,0x230);
    return 0;
  }
  iVar3 = (*(code *)PTR_BIO_ctrl_006a7f18)(iVar2,0x6c,3,file);
  if (iVar3 < 1) {
    uVar5 = 2;
    uVar1 = 0x236;
LAB_004b9320:
    iVar6 = 0;
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xb3,uVar5,&DAT_00649ed0,uVar1);
  }
  else {
    if (type == 2) {
      iVar3 = (*(code *)PTR_d2i_RSAPrivateKey_bio_006a94ec)(iVar2,0);
      uVar1 = 0xd;
    }
    else {
      if (type != 1) {
        uVar5 = 0x7c;
        uVar1 = 0x246;
        goto LAB_004b9320;
      }
      iVar3 = (*(code *)PTR_PEM_read_bio_RSAPrivateKey_006a94e8)
                        (iVar2,0,ctx->default_passwd_callback,ctx->default_passwd_callback_userdata)
      ;
      uVar1 = 9;
    }
    if (iVar3 == 0) {
      iVar6 = 0;
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xb3,uVar1,&DAT_00649ed0,0x24b);
    }
    else {
      iVar6 = ssl_cert_inst(&ctx->cert);
      if (iVar6 == 0) {
        iVar6 = 0;
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xb1,0x41,&DAT_00649ed0,0x215);
      }
      else {
        iVar6 = (*(code *)PTR_EVP_PKEY_new_006a8710)();
        if (iVar6 == 0) {
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xb1,6,&DAT_00649ed0,0x21a);
        }
        else {
          (*(code *)PTR_RSA_up_ref_006a9120)(iVar3);
          (*(code *)PTR_EVP_PKEY_assign_006a94e4)(iVar6,6,iVar3);
          iVar4 = ssl_set_pkey(ctx->cert,iVar6);
          (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar6);
          iVar6 = iVar4;
        }
      }
      (*(code *)PTR_RSA_free_006a86f0)(iVar3);
    }
  }
  (*(code *)PTR_BIO_free_006a7f70)(iVar2);
  return iVar6;
}

