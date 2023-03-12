
EVP_PKEY_ASN1_METHOD *
init_gen_str(BIO *param_1,EVP_PKEY_CTX **param_2,char *param_3,ENGINE *param_4,int param_5)

{
  EVP_PKEY_ASN1_METHOD *ameth;
  int iVar1;
  uint uVar2;
  ENGINE *local_28;
  int local_24 [2];
  
  local_28 = (ENGINE *)0x0;
  if (*param_2 == (EVP_PKEY_CTX *)0x0) {
    ameth = EVP_PKEY_asn1_find_str(&local_28,param_3,-1);
    uVar2 = count_leading_zeroes(ameth);
    uVar2 = uVar2 >> 5;
    if (param_4 == (ENGINE *)0x0) {
      uVar2 = 0;
    }
    if (uVar2 != 0) {
      ameth = ENGINE_get_pkey_asn1_meth_str(param_4,param_3,-1);
    }
    if (ameth == (EVP_PKEY_ASN1_METHOD *)0x0) {
      BIO_printf(bio_err,"Algorithm %s not found\n",param_3);
    }
    else {
      ERR_clear_error();
      EVP_PKEY_asn1_get0_info(local_24,(int *)0x0,(int *)0x0,(char **)0x0,(char **)0x0,ameth);
      if (local_28 != (ENGINE *)0x0) {
        ENGINE_finish(local_28);
      }
      ameth = (EVP_PKEY_ASN1_METHOD *)EVP_PKEY_CTX_new_id(local_24[0],param_4);
      if (ameth == (EVP_PKEY_ASN1_METHOD *)0x0) {
        BIO_printf(param_1,"Error initializing %s context\n",param_3);
        ERR_print_errors(param_1);
      }
      else {
        if (param_5 == 0) {
          iVar1 = EVP_PKEY_keygen_init((EVP_PKEY_CTX *)ameth);
        }
        else {
          iVar1 = EVP_PKEY_paramgen_init((EVP_PKEY_CTX *)ameth);
        }
        if (0 < iVar1) {
          *param_2 = (EVP_PKEY_CTX *)ameth;
          return (EVP_PKEY_ASN1_METHOD *)0x1;
        }
        BIO_printf(param_1,"Error initializing %s context\n",param_3);
        ERR_print_errors(param_1);
        EVP_PKEY_CTX_free((EVP_PKEY_CTX *)ameth);
        ameth = (EVP_PKEY_ASN1_METHOD *)0x0;
      }
    }
  }
  else {
    BIO_puts(param_1,"Algorithm already set!\n");
    ameth = (EVP_PKEY_ASN1_METHOD *)0x0;
  }
  return ameth;
}

