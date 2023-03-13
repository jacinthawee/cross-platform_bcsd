
EVP_PKEY * d2i_PUBKEY(EVP_PKEY **a,uchar **pp,long length)

{
  undefined4 *val;
  EVP_PKEY *pkey;
  int iVar1;
  int in_GS_OFFSET;
  EVP_PKEY *local_30;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_24 = *pp;
  val = (undefined4 *)ASN1_item_d2i((ASN1_VALUE **)0x0,&local_24,length,(ASN1_ITEM *)X509_PUBKEY_it)
  ;
  if (val != (undefined4 *)0x0) {
    local_30 = (EVP_PKEY *)val[2];
    if (local_30 == (EVP_PKEY *)0x0) {
      if (val[1] != 0) {
        pkey = EVP_PKEY_new();
        if (pkey != (EVP_PKEY *)0x0) {
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
              CRYPTO_lock(iVar1,9,(char *)0xa,(int)"x_pubkey.c");
              if (val[2] == 0) {
                val[2] = pkey;
                CRYPTO_lock((int)pkey,10,(char *)0xa,(int)"x_pubkey.c");
                local_30 = pkey;
              }
              else {
                CRYPTO_lock(iVar1,10,(char *)0xa,(int)"x_pubkey.c");
                EVP_PKEY_free(pkey);
                local_30 = (EVP_PKEY *)val[2];
              }
              CRYPTO_add_lock(&local_30->references,1,10,"x_pubkey.c",0xac);
              goto LAB_0813d37a;
            }
            ERR_put_error(0xb,0x77,0x7d,"x_pubkey.c",0x9a);
          }
          EVP_PKEY_free(pkey);
          ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)X509_PUBKEY_it);
          goto LAB_0813d3ac;
        }
        ERR_put_error(0xb,0x77,0x41,"x_pubkey.c",0x8f);
      }
      ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)X509_PUBKEY_it);
      goto LAB_0813d3ac;
    }
    CRYPTO_add_lock(&local_30->references,1,10,"x_pubkey.c",0x87);
    local_30 = (EVP_PKEY *)val[2];
LAB_0813d37a:
    ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)X509_PUBKEY_it);
    if (local_30 != (EVP_PKEY *)0x0) {
      *pp = local_24;
      if (a != (EVP_PKEY **)0x0) {
        EVP_PKEY_free(*a);
        *a = local_30;
      }
      goto LAB_0813d3ac;
    }
  }
  local_30 = (EVP_PKEY *)0x0;
LAB_0813d3ac:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return local_30;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

