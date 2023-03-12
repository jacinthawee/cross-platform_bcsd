
EVP_PKEY * d2i_PUBKEY(EVP_PKEY **a,uchar **pp,long length)

{
  undefined *puVar1;
  undefined4 *val;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  EVP_PKEY *pkey;
  
  val = (undefined4 *)ASN1_item_d2i((ASN1_VALUE **)0x0,pp,length,(ASN1_ITEM *)X509_PUBKEY_it);
  if (val != (undefined4 *)0x0) {
    if (val[2] == 0) {
      if (val[1] == 0) {
LAB_00554448:
        ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)X509_PUBKEY_it);
        return (EVP_PKEY *)0x0;
      }
      pkey = EVP_PKEY_new();
      if (pkey == (EVP_PKEY *)0x0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x77,0x41,"x_pubkey.c",0x95);
        goto LAB_00554448;
      }
      iVar2 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*(undefined4 *)*val);
      iVar2 = EVP_PKEY_set_type(pkey,iVar2);
      if (iVar2 == 0) {
        uVar4 = 0x6f;
        uVar3 = 0x9b;
LAB_005543c8:
        (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x77,uVar4,"x_pubkey.c",uVar3);
        EVP_PKEY_free(pkey);
        ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)X509_PUBKEY_it);
        return (EVP_PKEY *)0x0;
      }
      if (*(code **)(pkey->ameth + 0x14) == (code *)0x0) {
        uVar4 = 0x7c;
        uVar3 = 0xaa;
        goto LAB_005543c8;
      }
      iVar2 = (**(code **)(pkey->ameth + 0x14))(pkey,val);
      if (iVar2 == 0) {
        uVar4 = 0x7d;
        uVar3 = 0xa4;
        goto LAB_005543c8;
      }
      (*(code *)PTR_CRYPTO_lock_006a926c)(9,10,"x_pubkey.c",0xaf);
      puVar1 = PTR_CRYPTO_lock_006a926c;
      if (val[2] == 0) {
        val[2] = pkey;
        (*(code *)puVar1)(10,10,"x_pubkey.c",0xb9);
      }
      else {
        (*(code *)PTR_CRYPTO_lock_006a926c)(10,10,"x_pubkey.c",0xb2);
        EVP_PKEY_free(pkey);
        pkey = (EVP_PKEY *)val[2];
      }
      (*(code *)PTR_CRYPTO_add_lock_006a9080)(&pkey->references,1,10,"x_pubkey.c",0xbb);
    }
    else {
      (*(code *)PTR_CRYPTO_add_lock_006a9080)(val[2] + 8,1,10,"x_pubkey.c",0x8d);
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

