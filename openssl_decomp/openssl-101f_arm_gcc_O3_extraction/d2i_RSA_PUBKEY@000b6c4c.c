
RSA * d2i_RSA_PUBKEY(RSA **a,uchar **pp,long length)

{
  undefined4 *val;
  rsa_st *prVar1;
  int iVar2;
  EVP_PKEY *pkey;
  uchar *local_1c [2];
  
  local_1c[0] = *pp;
  val = (undefined4 *)ASN1_item_d2i((ASN1_VALUE **)0x0,local_1c,length,(ASN1_ITEM *)&X509_PUBKEY_it)
  ;
  if (val == (undefined4 *)0x0) {
    return (RSA *)0x0;
  }
  if (val[2] == 0) {
    if (val[1] != 0) {
      pkey = EVP_PKEY_new();
      if (pkey == (EVP_PKEY *)0x0) {
        ERR_put_error(0xb,0x77,0x41,"x_pubkey.c",0x95);
      }
      else {
        iVar2 = OBJ_obj2nid(*(ASN1_OBJECT **)*val);
        iVar2 = EVP_PKEY_set_type(pkey,iVar2);
        if (iVar2 == 0) {
          ERR_put_error(0xb,0x77,0x6f,"x_pubkey.c",0x9b);
        }
        else if (*(code **)(pkey->ameth + 0x14) == (code *)0x0) {
          ERR_put_error(0xb,0x77,0x7c,"x_pubkey.c",0xaa);
        }
        else {
          iVar2 = (**(code **)(pkey->ameth + 0x14))(pkey,val);
          if (iVar2 != 0) {
            CRYPTO_lock(9,10,"x_pubkey.c",0xaf);
            if (val[2] == 0) {
              val[2] = pkey;
              CRYPTO_lock(10,10,"x_pubkey.c",0xb9);
            }
            else {
              CRYPTO_lock(10,10,"x_pubkey.c",0xb2);
              EVP_PKEY_free(pkey);
              pkey = (EVP_PKEY *)val[2];
            }
            CRYPTO_add_lock(&pkey->references,1,10,"x_pubkey.c",0xbb);
            goto LAB_000b6c8c;
          }
          ERR_put_error(0xb,0x77,0x7d,"x_pubkey.c",0xa4);
        }
        EVP_PKEY_free(pkey);
      }
    }
    ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)&X509_PUBKEY_it);
  }
  else {
    CRYPTO_add_lock((int *)(val[2] + 8),1,10,"x_pubkey.c",0x8d);
    pkey = (EVP_PKEY *)val[2];
LAB_000b6c8c:
    ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)&X509_PUBKEY_it);
    if (pkey != (EVP_PKEY *)0x0) {
      prVar1 = EVP_PKEY_get1_RSA(pkey);
      EVP_PKEY_free(pkey);
      if ((prVar1 != (rsa_st *)0x0) && (*pp = local_1c[0], a != (RSA **)0x0)) {
        RSA_free(*a);
        *a = prVar1;
        return prVar1;
      }
      return prVar1;
    }
  }
  return (RSA *)0x0;
}

