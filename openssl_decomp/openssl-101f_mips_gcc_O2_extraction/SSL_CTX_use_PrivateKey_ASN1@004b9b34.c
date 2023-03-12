
int SSL_CTX_use_PrivateKey_ASN1(int pk,SSL_CTX *ctx,uchar *d,long len)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  void *parg;
  uint uVar8;
  SSL_CTX *ctx_00;
  undefined4 uVar9;
  uchar *local_20;
  SSL_CTX *local_1c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(SSL_CTX **)PTR___stack_chk_guard_006aabf0;
  local_20 = d;
  iVar2 = (*(code *)PTR_d2i_PrivateKey_006a94f0)(pk,0,&local_20);
  if (iVar2 == 0) {
    iVar5 = 0xaf;
    iVar3 = 0;
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xaf,0xd,&DAT_00649ed0,0x2b2);
  }
  else {
    iVar3 = ssl_cert_inst(&ctx->cert);
    if (iVar3 == 0) {
      iVar5 = 0xae;
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xae,0x41,&DAT_00649ed0,0x272);
    }
    else {
      iVar5 = iVar2;
      iVar3 = ssl_set_pkey(ctx->cert,iVar2);
    }
    (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar2);
  }
  if (local_1c == *(SSL_CTX **)puVar1) {
    return iVar3;
  }
  ctx_00 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  (*(code *)PTR_ERR_clear_error_006a7fe0)();
  uVar4 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  iVar2 = (*(code *)PTR_BIO_new_006a7fa4)(uVar4);
  if (iVar2 == 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xdc,7,&DAT_00649ed0,0x2cc);
    return 0;
  }
  iVar5 = (*(code *)PTR_BIO_ctrl_006a7f18)(iVar2,0x6c,3,iVar5);
  if (iVar5 < 1) {
    uVar9 = 2;
    uVar4 = 0x2d2;
  }
  else {
    iVar5 = (*(code *)PTR_PEM_read_bio_X509_AUX_006a8c6c)
                      (iVar2,0,ctx_00->default_passwd_callback,
                       ctx_00->default_passwd_callback_userdata);
    if (iVar5 != 0) {
      iVar3 = ssl_cert_inst(&ctx_00->cert);
      if (iVar3 == 0) {
        iVar3 = 0;
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xab,0x41,&DAT_00649ed0,0x184);
        (*(code *)PTR_ERR_peek_error_006a8054)();
      }
      else {
        iVar3 = ssl_set_cert(ctx_00->cert,iVar5);
        iVar6 = (*(code *)PTR_ERR_peek_error_006a8054)();
        if ((iVar6 == 0) && (iVar3 != 0)) {
          if (ctx_00->extra_certs != (stack_st_X509 *)0x0) {
            (*(code *)PTR_sk_pop_free_006a8158)(ctx_00->extra_certs,PTR_X509_free_006a7f90);
            ctx_00->extra_certs = (stack_st_X509 *)0x0;
          }
          do {
            parg = (void *)(*(code *)PTR_PEM_read_bio_X509_006a80cc)
                                     (iVar2,0,ctx_00->default_passwd_callback,
                                      ctx_00->default_passwd_callback_userdata);
            if (parg == (void *)0x0) {
              uVar8 = (*(code *)PTR_ERR_peek_last_error_006a8508)();
              if ((uVar8 >> 0x18 != 9) || ((uVar8 & 0xfff) != 0x6c)) goto LAB_004b9dcc;
              (*(code *)PTR_ERR_clear_error_006a7fe0)();
              goto LAB_004b9dd0;
            }
            lVar7 = SSL_CTX_ctrl(ctx_00,0xe,0,parg);
          } while (lVar7 != 0);
          iVar3 = 0;
          (*(code *)PTR_X509_free_006a7f90)(parg);
        }
        else {
LAB_004b9dcc:
          iVar3 = 0;
        }
      }
LAB_004b9dd0:
      (*(code *)PTR_X509_free_006a7f90)(iVar5);
      goto LAB_004b9e10;
    }
    uVar9 = 9;
    uVar4 = 0x2da;
  }
  iVar3 = 0;
  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xdc,uVar9,&DAT_00649ed0,uVar4);
LAB_004b9e10:
  (*(code *)PTR_BIO_free_006a7f70)(iVar2);
  return iVar3;
}

