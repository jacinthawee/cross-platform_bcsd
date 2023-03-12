
EVP_PKEY * EVP_PKCS82PKEY(PKCS8_PRIV_KEY_INFO *p8)

{
  EVP_PKEY *pkey;
  int iVar1;
  ASN1_OBJECT *local_68;
  char acStack_64 [80];
  int local_14;
  
  local_14 = __TMC_END__;
  pkey = (EVP_PKEY *)PKCS8_pkey_get0(&local_68,(uchar **)0x0,(int *)0x0,(X509_ALGOR **)0x0,p8);
  if (pkey != (EVP_PKEY *)0x0) {
    pkey = EVP_PKEY_new();
    if (pkey == (EVP_PKEY *)0x0) {
      ERR_put_error(6,0x6f,0x41,"evp_pkey.c",0x4e);
    }
    else {
      iVar1 = OBJ_obj2nid(local_68);
      iVar1 = EVP_PKEY_set_type(pkey,iVar1);
      if (iVar1 == 0) {
        ERR_put_error(6,0x6f,0x76,"evp_pkey.c",0x54);
        i2t_ASN1_OBJECT(acStack_64,0x50,local_68);
        ERR_add_error_data(2,"TYPE=",acStack_64);
      }
      else if (*(code **)(pkey->ameth + 0x24) == (code *)0x0) {
        ERR_put_error(6,0x6f,0x90,"evp_pkey.c",0x65);
      }
      else {
        iVar1 = (**(code **)(pkey->ameth + 0x24))(pkey,p8);
        if (iVar1 != 0) goto LAB_000aff76;
        ERR_put_error(6,0x6f,0x91,"evp_pkey.c",0x5f);
      }
      EVP_PKEY_free(pkey);
      pkey = (EVP_PKEY *)0x0;
    }
  }
LAB_000aff76:
  if (local_14 != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pkey;
}

