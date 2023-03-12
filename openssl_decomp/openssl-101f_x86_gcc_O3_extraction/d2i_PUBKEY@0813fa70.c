
EVP_PKEY * d2i_PUBKEY(EVP_PKEY **a,uchar **pp,long length)

{
  undefined4 *val;
  EVP_PKEY *pkey;
  int iVar1;
  
  val = (undefined4 *)ASN1_item_d2i((ASN1_VALUE **)0x0,pp,length,(ASN1_ITEM *)X509_PUBKEY_it);
  if (val != (undefined4 *)0x0) {
    if (val[2] == 0) {
      if (val[1] == 0) {
LAB_0813fbab:
        ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)X509_PUBKEY_it);
        return (EVP_PKEY *)0x0;
      }
      pkey = EVP_PKEY_new();
      if (pkey == (EVP_PKEY *)0x0) {
        ERR_put_error(0xb,0x77,0x41,"x_pubkey.c",0x95);
        goto LAB_0813fbab;
      }
      iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)*val);
      iVar1 = EVP_PKEY_set_type(pkey,iVar1);
      if (iVar1 == 0) {
        ERR_put_error(0xb,0x77,0x6f,"x_pubkey.c",0x9b);
LAB_0813fb6d:
        EVP_PKEY_free(pkey);
        ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)X509_PUBKEY_it);
        return (EVP_PKEY *)0x0;
      }
      if (*(code **)(pkey->ameth + 0x14) == (code *)0x0) {
        ERR_put_error(0xb,0x77,0x7c,"x_pubkey.c",0xaa);
        goto LAB_0813fb6d;
      }
      iVar1 = (**(code **)(pkey->ameth + 0x14))(pkey,val);
      if (iVar1 == 0) {
        ERR_put_error(0xb,0x77,0x7d,"x_pubkey.c",0xa4);
        goto LAB_0813fb6d;
      }
      CRYPTO_lock(iVar1,9,(char *)0xa,(int)"x_pubkey.c");
      if (val[2] == 0) {
        val[2] = pkey;
        CRYPTO_lock(iVar1,10,(char *)0xa,(int)"x_pubkey.c");
      }
      else {
        CRYPTO_lock(iVar1,10,(char *)0xa,(int)"x_pubkey.c");
        EVP_PKEY_free(pkey);
        pkey = (EVP_PKEY *)val[2];
      }
      CRYPTO_add_lock(&pkey->references,1,10,"x_pubkey.c",0xbb);
    }
    else {
      CRYPTO_add_lock((int *)(val[2] + 8),1,10,"x_pubkey.c",0x8d);
      pkey = (EVP_PKEY *)val[2];
    }
    ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)X509_PUBKEY_it);
    if (pkey != (EVP_PKEY *)0x0) {
      if (a == (EVP_PKEY **)0x0) {
        return pkey;
      }
      EVP_PKEY_free(*a);
      *a = pkey;
      return pkey;
    }
  }
  return (EVP_PKEY *)0x0;
}

