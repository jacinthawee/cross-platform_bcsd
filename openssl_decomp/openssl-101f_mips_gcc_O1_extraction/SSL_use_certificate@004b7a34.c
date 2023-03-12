
int SSL_use_certificate(SSL *ssl,X509 *x)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  
  if (x == (X509 *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xc6,0x43,&DAT_00649ed0,0x49);
    return 0;
  }
  iVar2 = ssl_cert_inst(&ssl->cert);
  if (iVar2 == 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xc6,0x41,&DAT_00649ed0,0x4e);
    return 0;
  }
  piVar7 = (int *)ssl->cert;
  iVar2 = (*(code *)PTR_X509_get_pubkey_006a8008)(x);
  if (iVar2 == 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xbf,0x10c,&DAT_00649ed0,0x192);
    return 0;
  }
  iVar3 = (*(code *)PTR_ssl_cert_type_006a91a8)(x,iVar2);
  if (iVar3 < 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xbf,0xf7,&DAT_00649ed0,0x199);
    (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar2);
    return 0;
  }
  if (piVar7[iVar3 * 3 + 0xd] != 0) {
    (*(code *)PTR_EVP_PKEY_copy_parameters_006a8274)(iVar2);
    (*(code *)PTR_ERR_clear_error_006a7fe0)();
    piVar6 = (int *)piVar7[iVar3 * 3 + 0xd];
    if (*piVar6 == 6) {
      uVar5 = (*(code *)PTR_RSA_flags_006a94e0)(piVar6[5]);
      if ((uVar5 & 1) != 0) goto LAB_004b7b10;
      piVar6 = (int *)piVar7[iVar3 * 3 + 0xd];
    }
    iVar4 = (*(code *)PTR_X509_check_private_key_006a817c)(x,piVar6);
    if (iVar4 == 0) {
      (*(code *)PTR_EVP_PKEY_free_006a7f78)(piVar7[iVar3 * 3 + 0xd]);
      puVar1 = PTR_ERR_clear_error_006a7fe0;
      piVar7[iVar3 * 3 + 0xd] = 0;
      (*(code *)puVar1)();
    }
  }
LAB_004b7b10:
  (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar2);
  if (piVar7[iVar3 * 3 + 0xc] != 0) {
    (*(code *)PTR_X509_free_006a7f90)();
  }
  CRYPTO_add_lock(&x->references,1,3,"ssl_rsa.c",0x1bd);
  piVar7[iVar3 * 3 + 0xc] = (int)x;
  piVar7[1] = 0;
  *piVar7 = (int)(piVar7 + iVar3 * 3 + 0xc);
  return 1;
}

