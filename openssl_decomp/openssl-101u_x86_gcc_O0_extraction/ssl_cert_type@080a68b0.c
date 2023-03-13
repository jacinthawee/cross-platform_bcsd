
undefined4 ssl_cert_type(X509 *param_1,EVP_PKEY *param_2)

{
  undefined4 uVar1;
  EVP_PKEY *pkey;
  int iVar2;
  
  if (param_2 == (EVP_PKEY *)0x0) {
    pkey = X509_get_pubkey(param_1);
    if (pkey == (EVP_PKEY *)0x0) {
      uVar1 = 0xffffffff;
      goto LAB_080a693e;
    }
    iVar2 = pkey->type;
    if (iVar2 == 6) {
      uVar1 = 0;
      goto LAB_080a693e;
    }
    if (iVar2 == 0x74) {
      uVar1 = 2;
      goto LAB_080a693e;
    }
  }
  else {
    iVar2 = param_2->type;
    if (iVar2 == 6) {
      return 0;
    }
    pkey = param_2;
    if (iVar2 == 0x74) {
      return 2;
    }
  }
  uVar1 = 5;
  if (iVar2 != 0x198) {
    if ((iVar2 == 0x32c) || (iVar2 == 0x352)) {
      uVar1 = 6;
    }
    else if ((iVar2 == 0x32b) || (iVar2 == 0x353)) {
      uVar1 = 7;
    }
    else {
      uVar1 = 0xffffffff;
    }
  }
  if (param_2 != (EVP_PKEY *)0x0) {
    return uVar1;
  }
LAB_080a693e:
  EVP_PKEY_free(pkey);
  return uVar1;
}

