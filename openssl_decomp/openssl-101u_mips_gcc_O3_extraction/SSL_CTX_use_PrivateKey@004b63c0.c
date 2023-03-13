
int SSL_CTX_use_PrivateKey(SSL_CTX *ctx,EVP_PKEY *pkey)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  cert_st **ppcVar4;
  
  if (pkey == (EVP_PKEY *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xae,0x43,&DAT_00649450,0x253);
    return 0;
  }
  iVar1 = ssl_cert_inst(&ctx->cert);
  if (iVar1 == 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xae,0x41,&DAT_00649450,599);
    return 0;
  }
  ppcVar4 = (cert_st **)ctx->cert;
  iVar1 = (*(code *)PTR_ssl_cert_type_006a8058)(0,pkey);
  if (iVar1 < 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xc1,0xf7,&DAT_00649450,0xb4);
    iVar2 = 0;
  }
  else {
    if (ppcVar4[iVar1 * 3 + 0xc] != (cert_st *)0x0) {
      iVar2 = (*(code *)PTR_X509_get_pubkey_006a6f08)();
      if (iVar2 == 0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xc1,0x41,&DAT_00649450,0xbc);
        (*(code *)PTR_EVP_PKEY_free_006a6e78)(0);
        return 0;
      }
      (*(code *)PTR_EVP_PKEY_copy_parameters_006a7174)(iVar2,pkey);
      (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar2);
      (*(code *)PTR_ERR_clear_error_006a6ee0)();
      if (((pkey->type != 6) ||
          (uVar3 = (*(code *)PTR_RSA_flags_006a83c8)((pkey->pkey).ptr), (uVar3 & 1) == 0)) &&
         (iVar2 = (*(code *)PTR_X509_check_private_key_006a707c)(ppcVar4[iVar1 * 3 + 0xc],pkey),
         iVar2 == 0)) {
        (*(code *)PTR_X509_free_006a6e90)(ppcVar4[iVar1 * 3 + 0xc]);
        ppcVar4[iVar1 * 3 + 0xc] = (cert_st *)0x0;
        return 0;
      }
    }
    if (ppcVar4[iVar1 * 3 + 0xd] != (cert_st *)0x0) {
      (*(code *)PTR_EVP_PKEY_free_006a6e78)();
    }
    CRYPTO_add_lock(&pkey->references,1,10,"ssl_rsa.c",0xda);
    iVar2 = 1;
    ppcVar4[iVar1 * 3 + 0xd] = (cert_st *)pkey;
    ppcVar4[1] = (cert_st *)0x0;
    *ppcVar4 = (cert_st *)(ppcVar4 + iVar1 * 3 + 0xc);
  }
  return iVar2;
}

