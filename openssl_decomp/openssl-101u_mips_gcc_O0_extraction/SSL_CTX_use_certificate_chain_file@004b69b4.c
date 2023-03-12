
int SSL_CTX_use_certificate_chain_file(SSL_CTX *ctx,char *file)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  void *parg;
  uint uVar7;
  undefined4 uVar8;
  
  (*(code *)PTR_ERR_clear_error_006a6ee0)();
  uVar1 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  iVar2 = (*(code *)PTR_BIO_new_006a6ea4)(uVar1);
  if (iVar2 == 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xdc,7,&DAT_00649450,0x2aa);
    return 0;
  }
  iVar3 = (*(code *)PTR_BIO_ctrl_006a6e18)(iVar2,0x6c,3,file);
  if (iVar3 < 1) {
    uVar8 = 2;
    uVar1 = 0x2af;
  }
  else {
    iVar3 = (*(code *)PTR_PEM_read_bio_X509_AUX_006a7b80)
                      (iVar2,0,ctx->default_passwd_callback,ctx->default_passwd_callback_userdata);
    if (iVar3 != 0) {
      iVar4 = ssl_cert_inst(&ctx->cert);
      if (iVar4 == 0) {
        iVar4 = 0;
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xab,0x41,&DAT_00649450,0x174);
        (*(code *)PTR_ERR_peek_error_006a6f54)();
      }
      else {
        iVar4 = ssl_set_cert(ctx->cert,iVar3);
        iVar5 = (*(code *)PTR_ERR_peek_error_006a6f54)();
        if ((iVar5 == 0) && (iVar4 != 0)) {
          if (ctx->extra_certs != (stack_st_X509 *)0x0) {
            (*(code *)PTR_sk_pop_free_006a7058)(ctx->extra_certs,PTR_X509_free_006a6e90);
            ctx->extra_certs = (stack_st_X509 *)0x0;
          }
          do {
            parg = (void *)(*(code *)PTR_PEM_read_bio_X509_006a6fcc)
                                     (iVar2,0,ctx->default_passwd_callback,
                                      ctx->default_passwd_callback_userdata);
            if (parg == (void *)0x0) {
              uVar7 = (*(code *)PTR_ERR_peek_last_error_006a7408)();
              if ((uVar7 >> 0x18 != 9) || ((uVar7 & 0xfff) != 0x6c)) goto LAB_004b6b24;
              (*(code *)PTR_ERR_clear_error_006a6ee0)();
              goto LAB_004b6b28;
            }
            lVar6 = SSL_CTX_ctrl(ctx,0xe,0,parg);
          } while (lVar6 != 0);
          iVar4 = 0;
          (*(code *)PTR_X509_free_006a6e90)(parg);
        }
        else {
LAB_004b6b24:
          iVar4 = 0;
        }
      }
LAB_004b6b28:
      (*(code *)PTR_X509_free_006a6e90)(iVar3);
      goto LAB_004b6b68;
    }
    uVar8 = 9;
    uVar1 = 0x2b6;
  }
  iVar4 = 0;
  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xdc,uVar8,&DAT_00649450,uVar1);
LAB_004b6b68:
  (*(code *)PTR_BIO_free_006a6e70)(iVar2);
  return iVar4;
}

