
EVP_PKEY * EVP_PKCS82PKEY(PKCS8_PRIV_KEY_INFO *p8)

{
  int iVar1;
  EVP_PKEY *pkey;
  EVP_PKEY *pEVar2;
  int in_GS_OFFSET;
  ASN1_OBJECT *local_64;
  char local_60 [80];
  int local_10;
  
  pEVar2 = (EVP_PKEY *)0x0;
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = PKCS8_pkey_get0(&local_64,(uchar **)0x0,(int *)0x0,(X509_ALGOR **)0x0,p8);
  if (iVar1 != 0) {
    pkey = EVP_PKEY_new();
    if (pkey == (EVP_PKEY *)0x0) {
      ERR_put_error(6,0x6f,0x41,"evp_pkey.c",0x4e);
    }
    else {
      iVar1 = OBJ_obj2nid(local_64);
      iVar1 = EVP_PKEY_set_type(pkey,iVar1);
      if (iVar1 == 0) {
        ERR_put_error(6,0x6f,0x76,"evp_pkey.c",0x54);
        i2t_ASN1_OBJECT(local_60,0x50,local_64);
        ERR_add_error_data(2,"TYPE=",local_60);
      }
      else if (*(code **)(pkey->ameth + 0x24) == (code *)0x0) {
        ERR_put_error(6,0x6f,0x90,"evp_pkey.c",0x65);
      }
      else {
        iVar1 = (**(code **)(pkey->ameth + 0x24))(pkey,p8);
        pEVar2 = pkey;
        if (iVar1 != 0) goto LAB_081340f9;
        ERR_put_error(6,0x6f,0x91,"evp_pkey.c",0x5f);
      }
      pEVar2 = (EVP_PKEY *)0x0;
      EVP_PKEY_free(pkey);
    }
  }
LAB_081340f9:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pEVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

