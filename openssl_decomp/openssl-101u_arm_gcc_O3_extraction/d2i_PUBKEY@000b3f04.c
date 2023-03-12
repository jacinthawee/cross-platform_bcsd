
EVP_PKEY * d2i_PUBKEY(EVP_PKEY **a,uchar **pp,long length)

{
  undefined4 *val;
  int iVar1;
  EVP_PKEY *pkey;
  uchar *local_1c;
  
  local_1c = *pp;
  val = (undefined4 *)
        ASN1_item_d2i((ASN1_VALUE **)0x0,&local_1c,length,(ASN1_ITEM *)&X509_PUBKEY_it);
  if (val == (undefined4 *)0x0) {
    return (EVP_PKEY *)0x0;
  }
  if (val[2] == 0) {
    if (val[1] != 0) {
      pkey = EVP_PKEY_new();
      if (pkey == (EVP_PKEY *)0x0) {
        ERR_put_error(0xb,0x77,0x41,"x_pubkey.c",0x8f);
      }
      else {
        iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)*val);
        iVar1 = EVP_PKEY_set_type(pkey,iVar1);
        if (iVar1 == 0) {
          ERR_put_error(0xb,0x77,0x6f,"x_pubkey.c",0x94);
        }
        else if (*(code **)(pkey->ameth + 0x14) == (code *)0x0) {
          ERR_put_error(0xb,0x77,0x7c,"x_pubkey.c",0x9e);
        }
        else {
          iVar1 = (**(code **)(pkey->ameth + 0x14))(pkey,val);
          if (iVar1 != 0) {
            CRYPTO_lock(9,10,"x_pubkey.c",0xa3);
            if (val[2] == 0) {
              val[2] = pkey;
              CRYPTO_lock(10,10,"x_pubkey.c",0xaa);
            }
            else {
              CRYPTO_lock(10,10,"x_pubkey.c",0xa5);
              EVP_PKEY_free(pkey);
              pkey = (EVP_PKEY *)val[2];
            }
            CRYPTO_add_lock(&pkey->references,1,10,"x_pubkey.c",0xac);
            goto LAB_000b3f4a;
          }
          ERR_put_error(0xb,0x77,0x7d,"x_pubkey.c",0x9a);
        }
        EVP_PKEY_free(pkey);
      }
    }
    ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)&X509_PUBKEY_it);
    return (EVP_PKEY *)0x0;
  }
  CRYPTO_add_lock((int *)(val[2] + 8),1,10,"x_pubkey.c",0x87);
  pkey = (EVP_PKEY *)val[2];
LAB_000b3f4a:
  ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)&X509_PUBKEY_it);
  if (pkey == (EVP_PKEY *)0x0) {
    return (EVP_PKEY *)0x0;
  }
  *pp = local_1c;
  if (a != (EVP_PKEY **)0x0) {
    EVP_PKEY_free(*a);
    *a = pkey;
    return pkey;
  }
  return pkey;
}
