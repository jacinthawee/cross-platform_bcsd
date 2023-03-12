
RSA * rsa_priv_decode(EVP_PKEY *param_1,PKCS8_PRIV_KEY_INFO *param_2)

{
  RSA *key;
  uchar *puStack_18;
  long local_14 [2];
  
  key = (RSA *)PKCS8_pkey_get0((ASN1_OBJECT **)0x0,&puStack_18,local_14,(X509_ALGOR **)0x0,param_2);
  if (key != (RSA *)0x0) {
    key = d2i_RSAPrivateKey((RSA **)0x0,&puStack_18,local_14[0]);
    if (key != (RSA *)0x0) {
      EVP_PKEY_assign(param_1,6,key);
      return (RSA *)0x1;
    }
    ERR_put_error(4,0x93,4,"rsa_ameth.c",0x72);
  }
  return key;
}

