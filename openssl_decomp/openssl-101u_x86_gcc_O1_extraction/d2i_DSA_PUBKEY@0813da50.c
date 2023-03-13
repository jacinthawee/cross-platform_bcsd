
DSA * d2i_DSA_PUBKEY(DSA **a,uchar **pp,long length)

{
  uchar *puVar1;
  undefined4 *val;
  dsa_st *pdVar2;
  EVP_PKEY *pkey;
  int iVar3;
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
          iVar3 = OBJ_obj2nid(*(ASN1_OBJECT **)*val);
          iVar3 = EVP_PKEY_set_type(pkey,iVar3);
          if (iVar3 == 0) {
            ERR_put_error(0xb,0x77,0x6f,"x_pubkey.c",0x94);
          }
          else if (*(code **)(pkey->ameth + 0x14) == (code *)0x0) {
            ERR_put_error(0xb,0x77,0x7c,"x_pubkey.c",0x9e);
          }
          else {
            iVar3 = (**(code **)(pkey->ameth + 0x14))(pkey,val);
            if (iVar3 != 0) {
              CRYPTO_lock(iVar3,9,(char *)0xa,(int)"x_pubkey.c");
              if (val[2] == 0) {
                val[2] = pkey;
                CRYPTO_lock(iVar3,10,(char *)0xa,(int)"x_pubkey.c");
              }
              else {
                CRYPTO_lock(iVar3,10,(char *)0xa,(int)"x_pubkey.c");
                EVP_PKEY_free(pkey);
                pkey = (EVP_PKEY *)val[2];
              }
              CRYPTO_add_lock(&pkey->references,1,10,"x_pubkey.c",0xac);
              goto LAB_0813dabe;
            }
            ERR_put_error(0xb,0x77,0x7d,"x_pubkey.c",0x9a);
          }
          EVP_PKEY_free(pkey);
          ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)X509_PUBKEY_it);
          goto LAB_0813dbbe;
        }
        ERR_put_error(0xb,0x77,0x41,"x_pubkey.c",0x8f);
      }
      pdVar2 = (dsa_st *)0x0;
      ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)X509_PUBKEY_it);
      goto LAB_0813db16;
    }
    CRYPTO_add_lock((int *)(val[2] + 8),1,10,"x_pubkey.c",0x87);
    pkey = (EVP_PKEY *)val[2];
LAB_0813dabe:
    ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)X509_PUBKEY_it);
    puVar1 = local_24;
    if (pkey != (EVP_PKEY *)0x0) {
      pdVar2 = EVP_PKEY_get1_DSA(pkey);
      EVP_PKEY_free(pkey);
      if (pdVar2 != (dsa_st *)0x0) {
        *pp = puVar1;
        if (a != (DSA **)0x0) {
          DSA_free(*a);
          *a = pdVar2;
        }
        goto LAB_0813db16;
      }
    }
  }
LAB_0813dbbe:
  pdVar2 = (dsa_st *)0x0;
LAB_0813db16:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pdVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

