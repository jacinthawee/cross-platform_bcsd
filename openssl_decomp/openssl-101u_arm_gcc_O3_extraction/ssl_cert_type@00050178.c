
undefined4 ssl_cert_type(X509 *param_1,EVP_PKEY *param_2)

{
  EVP_PKEY *pkey;
  int iVar1;
  undefined4 uVar2;
  
  pkey = param_2;
  if ((param_2 == (EVP_PKEY *)0x0) && (pkey = X509_get_pubkey(param_1), pkey == (EVP_PKEY *)0x0)) {
    uVar2 = 0xffffffff;
  }
  else {
    iVar1 = pkey->type;
    if (iVar1 == 6) {
      uVar2 = 0;
    }
    else if (iVar1 == 0x74) {
      uVar2 = 2;
    }
    else if (iVar1 == 0x198) {
      uVar2 = 5;
    }
    else if (iVar1 == 0x32c || iVar1 == 0x352) {
      uVar2 = 6;
    }
    else if (iVar1 == 0x32b || iVar1 == 0x353) {
      uVar2 = 7;
    }
    else {
      uVar2 = 0xffffffff;
    }
    if (param_2 != (EVP_PKEY *)0x0) {
      return uVar2;
    }
  }
  EVP_PKEY_free(pkey);
  return uVar2;
}

