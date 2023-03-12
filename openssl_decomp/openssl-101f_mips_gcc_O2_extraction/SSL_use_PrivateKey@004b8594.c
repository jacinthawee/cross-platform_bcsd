
int SSL_use_PrivateKey(SSL *ssl,EVP_PKEY *pkey)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  
  if (pkey == (EVP_PKEY *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xc9,0x43,&DAT_00649ed0,0x12d);
    return 0;
  }
  iVar1 = ssl_cert_inst(&ssl->cert);
  if (iVar1 != 0) {
    piVar5 = (int *)ssl->cert;
    iVar1 = (*(code *)PTR_ssl_cert_type_006a91a8)(0,pkey);
    if (iVar1 < 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xc1,0xf7,&DAT_00649ed0,0xbd);
      iVar3 = 0;
    }
    else {
      if (piVar5[iVar1 * 3 + 0xc] != 0) {
        uVar2 = (*(code *)PTR_X509_get_pubkey_006a8008)();
        (*(code *)PTR_EVP_PKEY_copy_parameters_006a8274)(uVar2,pkey);
        (*(code *)PTR_EVP_PKEY_free_006a7f78)(uVar2);
        (*(code *)PTR_ERR_clear_error_006a7fe0)();
        if (((pkey->type != 6) ||
            (uVar4 = (*(code *)PTR_RSA_flags_006a94e0)((pkey->pkey).ptr), (uVar4 & 1) == 0)) &&
           (iVar3 = (*(code *)PTR_X509_check_private_key_006a817c)(piVar5[iVar1 * 3 + 0xc],pkey),
           iVar3 == 0)) {
          (*(code *)PTR_X509_free_006a7f90)(piVar5[iVar1 * 3 + 0xc]);
          piVar5[iVar1 * 3 + 0xc] = 0;
          return 0;
        }
      }
      if (piVar5[iVar1 * 3 + 0xd] != 0) {
        (*(code *)PTR_EVP_PKEY_free_006a7f78)();
      }
      CRYPTO_add_lock(&pkey->references,1,10,"ssl_rsa.c",0xdb);
      iVar3 = 1;
      piVar5[iVar1 * 3 + 0xd] = (int)pkey;
      piVar5[1] = 0;
      *piVar5 = (int)(piVar5 + iVar1 * 3 + 0xc);
    }
    return iVar3;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xc9,0x41,&DAT_00649ed0,0x132);
  return 0;
}

