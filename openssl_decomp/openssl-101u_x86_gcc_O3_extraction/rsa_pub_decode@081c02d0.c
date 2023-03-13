
int rsa_pub_decode(EVP_PKEY *param_1,X509_PUBKEY *param_2)

{
  int iVar1;
  RSA *key;
  int in_GS_OFFSET;
  uchar *local_18;
  long local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = X509_PUBKEY_get0_param((ASN1_OBJECT **)0x0,&local_18,&local_14,(X509_ALGOR **)0x0,param_2)
  ;
  if (iVar1 != 0) {
    key = d2i_RSAPublicKey((RSA **)0x0,&local_18,local_14);
    if (key == (RSA *)0x0) {
      ERR_put_error(4,0x8b,4,"rsa_ameth.c",0x5e);
      iVar1 = 0;
    }
    else {
      EVP_PKEY_assign(param_1,6,key);
      iVar1 = 1;
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

