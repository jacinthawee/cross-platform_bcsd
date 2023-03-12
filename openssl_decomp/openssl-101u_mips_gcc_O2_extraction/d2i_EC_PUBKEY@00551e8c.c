
EC_KEY * d2i_EC_PUBKEY(EC_KEY **a,uchar **pp,long length)

{
  undefined *puVar1;
  undefined *puVar2;
  uchar *puVar3;
  undefined4 *val;
  EC_KEY *pEVar4;
  ASN1_VALUE *val_00;
  int iVar5;
  undefined4 uVar6;
  ec_key_st *key;
  undefined1 *in;
  undefined4 uVar7;
  EVP_PKEY *pEVar8;
  code *pcVar9;
  uchar *local_28;
  ec_key_st *local_24;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_28 = *pp;
  in = (undefined1 *)&local_28;
  local_24 = *(ec_key_st **)PTR___stack_chk_guard_006a9ae8;
  val = (undefined4 *)
        ASN1_item_d2i((ASN1_VALUE **)0x0,(uchar **)in,length,(ASN1_ITEM *)X509_PUBKEY_it);
  if (val == (undefined4 *)0x0) {
LAB_00552084:
    pEVar4 = (EC_KEY *)0x0;
  }
  else {
    if (val[2] != 0) {
      (*(code *)PTR_CRYPTO_add_lock_006a805c)(val[2] + 8,1,10,"x_pubkey.c",0x87);
      pEVar8 = (EVP_PKEY *)val[2];
LAB_00551f34:
      in = X509_PUBKEY_it;
      ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)X509_PUBKEY_it);
      puVar3 = local_28;
      if (pEVar8 != (EVP_PKEY *)0x0) {
        pEVar4 = EVP_PKEY_get1_EC_KEY(pEVar8);
        EVP_PKEY_free(pEVar8);
        if (pEVar4 != (ec_key_st *)0x0) {
          *pp = puVar3;
          if (a != (EC_KEY **)0x0) {
            (*(code *)PTR_EC_KEY_free_006a71d4)(*a);
            *a = pEVar4;
          }
          goto LAB_00551f98;
        }
      }
      goto LAB_00552084;
    }
    if (val[1] != 0) {
      pEVar8 = EVP_PKEY_new();
      if (pEVar8 != (EVP_PKEY *)0x0) {
        iVar5 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*(undefined4 *)*val);
        iVar5 = EVP_PKEY_set_type(pEVar8,iVar5);
        if (iVar5 == 0) {
          uVar7 = 0x6f;
          uVar6 = 0x94;
        }
        else if (*(code **)(pEVar8->ameth + 0x14) == (code *)0x0) {
          uVar7 = 0x7c;
          uVar6 = 0x9e;
        }
        else {
          iVar5 = (**(code **)(pEVar8->ameth + 0x14))(pEVar8,val);
          if (iVar5 != 0) {
            (*(code *)PTR_CRYPTO_lock_006a8144)(9,10,"x_pubkey.c",0xa3);
            puVar1 = PTR_CRYPTO_lock_006a8144;
            if (val[2] == 0) {
              val[2] = pEVar8;
              (*(code *)puVar1)(10,10,"x_pubkey.c",0xaa);
            }
            else {
              (*(code *)PTR_CRYPTO_lock_006a8144)(10,10,"x_pubkey.c",0xa5);
              EVP_PKEY_free(pEVar8);
              pEVar8 = (EVP_PKEY *)val[2];
            }
            (*(code *)PTR_CRYPTO_add_lock_006a805c)(&pEVar8->references,1,10,"x_pubkey.c",0xac);
            goto LAB_00551f34;
          }
          uVar7 = 0x7d;
          uVar6 = 0x9a;
        }
        (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x77,uVar7,"x_pubkey.c",uVar6);
        EVP_PKEY_free(pEVar8);
        in = X509_PUBKEY_it;
        ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)X509_PUBKEY_it);
        goto LAB_00552084;
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x77,0x41,"x_pubkey.c",0x8f);
    }
    in = X509_PUBKEY_it;
    ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)X509_PUBKEY_it);
    pEVar4 = (EC_KEY *)0x0;
  }
LAB_00551f98:
  if (local_24 == *(ec_key_st **)puVar2) {
    return pEVar4;
  }
  key = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (key == (ec_key_st *)0x0) {
    return (EC_KEY *)0x0;
  }
  pEVar8 = EVP_PKEY_new();
  if (pEVar8 == (EVP_PKEY *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xb5,0x41,"x_pubkey.c",0x14d);
    return (EC_KEY *)0x0;
  }
  EVP_PKEY_set1_EC_KEY(pEVar8,key);
  val_00 = ASN1_item_new((ASN1_ITEM *)X509_PUBKEY_it);
  if (val_00 != (ASN1_VALUE *)0x0) {
    if (pEVar8->ameth == (EVP_PKEY_ASN1_METHOD *)0x0) {
      uVar7 = 0x6f;
      uVar6 = 0x6f;
    }
    else {
      pcVar9 = *(code **)(pEVar8->ameth + 0x18);
      if (pcVar9 == (code *)0x0) {
        uVar7 = 0x7c;
        uVar6 = 0x6b;
      }
      else {
        iVar5 = (*pcVar9)(val_00,pEVar8);
        if (iVar5 != 0) {
          pEVar4 = (EC_KEY *)ASN1_item_i2d(val_00,(uchar **)in,(ASN1_ITEM *)X509_PUBKEY_it);
          ASN1_item_free(val_00,(ASN1_ITEM *)X509_PUBKEY_it);
          goto LAB_00552280;
        }
        uVar7 = 0x7e;
        uVar6 = 0x67;
      }
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x78,uVar7,"x_pubkey.c",uVar6);
    ASN1_item_free(val_00,(ASN1_ITEM *)X509_PUBKEY_it);
  }
  pEVar4 = (EC_KEY *)0x0;
LAB_00552280:
  EVP_PKEY_free(pEVar8);
  return pEVar4;
}

