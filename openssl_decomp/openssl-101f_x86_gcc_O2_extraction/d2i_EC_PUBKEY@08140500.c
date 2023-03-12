
EC_KEY * d2i_EC_PUBKEY(EC_KEY **a,uchar **pp,long length)

{
  undefined4 *val;
  ec_key_st *peVar1;
  EVP_PKEY *pkey;
  int iVar2;
  int in_GS_OFFSET;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_24 = *pp;
  val = (undefined4 *)ASN1_item_d2i((ASN1_VALUE **)0x0,&local_24,length,(ASN1_ITEM *)X509_PUBKEY_it)
  ;
  if (val != (undefined4 *)0x0) {
    if (val[2] == 0) {
      if (val[1] != 0) {
        pkey = EVP_PKEY_new();
        if (pkey != (EVP_PKEY *)0x0) {
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
              CRYPTO_lock(iVar2,9,(char *)0xa,(int)"x_pubkey.c");
              if (val[2] == 0) {
                val[2] = pkey;
                CRYPTO_lock(iVar2,10,(char *)0xa,(int)"x_pubkey.c");
              }
              else {
                CRYPTO_lock(iVar2,10,(char *)0xa,(int)"x_pubkey.c");
                EVP_PKEY_free(pkey);
                pkey = (EVP_PKEY *)val[2];
              }
              CRYPTO_add_lock(&pkey->references,1,10,"x_pubkey.c",0xbb);
              goto LAB_0814056e;
            }
            ERR_put_error(0xb,0x77,0x7d,"x_pubkey.c",0xa4);
          }
          EVP_PKEY_free(pkey);
          ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)X509_PUBKEY_it);
          goto LAB_08140666;
        }
        ERR_put_error(0xb,0x77,0x41,"x_pubkey.c",0x95);
      }
      peVar1 = (ec_key_st *)0x0;
      ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)X509_PUBKEY_it);
      goto LAB_081405be;
    }
    CRYPTO_add_lock((int *)(val[2] + 8),1,10,"x_pubkey.c",0x8d);
    pkey = (EVP_PKEY *)val[2];
LAB_0814056e:
    ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)X509_PUBKEY_it);
    if (pkey != (EVP_PKEY *)0x0) {
      peVar1 = EVP_PKEY_get1_EC_KEY(pkey);
      EVP_PKEY_free(pkey);
      if (peVar1 != (ec_key_st *)0x0) {
        *pp = local_24;
        if (a != (EC_KEY **)0x0) {
          EC_KEY_free(*a);
          *a = peVar1;
        }
        goto LAB_081405be;
      }
    }
  }
LAB_08140666:
  peVar1 = (ec_key_st *)0x0;
LAB_081405be:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return peVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

