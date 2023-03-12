
RSA * d2i_RSA_PUBKEY(RSA **a,uchar **pp,long length)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 *val;
  RSA *pRVar3;
  ASN1_VALUE *val_00;
  int iVar4;
  undefined4 uVar5;
  rsa_st *key;
  undefined1 *in;
  undefined4 uVar6;
  EVP_PKEY *pEVar7;
  code *pcVar8;
  uchar *local_28;
  rsa_st *local_24;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_28 = *pp;
  in = (undefined1 *)&local_28;
  local_24 = *(rsa_st **)PTR___stack_chk_guard_006aabf0;
  val = (undefined4 *)
        ASN1_item_d2i((ASN1_VALUE **)0x0,(uchar **)in,length,(ASN1_ITEM *)X509_PUBKEY_it);
  if (val == (undefined4 *)0x0) {
LAB_00554898:
    pRVar3 = (RSA *)0x0;
  }
  else {
    if (val[2] != 0) {
      (*(code *)PTR_CRYPTO_add_lock_006a9080)(val[2] + 8,1,10,"x_pubkey.c",0x8d);
      pEVar7 = (EVP_PKEY *)val[2];
LAB_00554748:
      in = X509_PUBKEY_it;
      ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)X509_PUBKEY_it);
      if (pEVar7 != (EVP_PKEY *)0x0) {
        pRVar3 = EVP_PKEY_get1_RSA(pEVar7);
        EVP_PKEY_free(pEVar7);
        if (pRVar3 != (rsa_st *)0x0) {
          *pp = local_28;
          if (a != (RSA **)0x0) {
            (*(code *)PTR_RSA_free_006a86f0)(*a);
            *a = pRVar3;
          }
          goto LAB_005547ac;
        }
      }
      goto LAB_00554898;
    }
    if (val[1] != 0) {
      pEVar7 = EVP_PKEY_new();
      if (pEVar7 != (EVP_PKEY *)0x0) {
        iVar4 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*(undefined4 *)*val);
        iVar4 = EVP_PKEY_set_type(pEVar7,iVar4);
        if (iVar4 == 0) {
          uVar6 = 0x6f;
          uVar5 = 0x9b;
        }
        else if (*(code **)(pEVar7->ameth + 0x14) == (code *)0x0) {
          uVar6 = 0x7c;
          uVar5 = 0xaa;
        }
        else {
          iVar4 = (**(code **)(pEVar7->ameth + 0x14))(pEVar7,val);
          if (iVar4 != 0) {
            (*(code *)PTR_CRYPTO_lock_006a926c)(9,10,"x_pubkey.c",0xaf);
            puVar1 = PTR_CRYPTO_lock_006a926c;
            if (val[2] == 0) {
              val[2] = pEVar7;
              (*(code *)puVar1)(10,10,"x_pubkey.c",0xb9);
            }
            else {
              (*(code *)PTR_CRYPTO_lock_006a926c)(10,10,"x_pubkey.c",0xb2);
              EVP_PKEY_free(pEVar7);
              pEVar7 = (EVP_PKEY *)val[2];
            }
            (*(code *)PTR_CRYPTO_add_lock_006a9080)(&pEVar7->references,1,10,"x_pubkey.c",0xbb);
            goto LAB_00554748;
          }
          uVar6 = 0x7d;
          uVar5 = 0xa4;
        }
        (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x77,uVar6,"x_pubkey.c",uVar5);
        EVP_PKEY_free(pEVar7);
        in = X509_PUBKEY_it;
        ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)X509_PUBKEY_it);
        goto LAB_00554898;
      }
      (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x77,0x41,"x_pubkey.c",0x95);
    }
    in = X509_PUBKEY_it;
    ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)X509_PUBKEY_it);
    pRVar3 = (RSA *)0x0;
  }
LAB_005547ac:
  if (local_24 == *(rsa_st **)puVar2) {
    return pRVar3;
  }
  key = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (key == (rsa_st *)0x0) {
    return (RSA *)0x0;
  }
  pEVar7 = EVP_PKEY_new();
  if (pEVar7 == (EVP_PKEY *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xa5,0x41,"x_pubkey.c",0x107);
    return (RSA *)0x0;
  }
  EVP_PKEY_set1_RSA(pEVar7,key);
  val_00 = ASN1_item_new((ASN1_ITEM *)X509_PUBKEY_it);
  if (val_00 != (ASN1_VALUE *)0x0) {
    if (pEVar7->ameth == (EVP_PKEY_ASN1_METHOD *)0x0) {
      uVar6 = 0x6f;
      uVar5 = 0x76;
    }
    else {
      pcVar8 = *(code **)(pEVar7->ameth + 0x18);
      if (pcVar8 == (code *)0x0) {
        uVar6 = 0x7c;
        uVar5 = 0x70;
      }
      else {
        iVar4 = (*pcVar8)(val_00,pEVar7);
        if (iVar4 != 0) {
          pRVar3 = (RSA *)ASN1_item_i2d(val_00,(uchar **)in,(ASN1_ITEM *)X509_PUBKEY_it);
          ASN1_item_free(val_00,(ASN1_ITEM *)X509_PUBKEY_it);
          goto LAB_00554a94;
        }
        uVar6 = 0x7e;
        uVar5 = 0x69;
      }
    }
    (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x78,uVar6,"x_pubkey.c",uVar5);
    ASN1_item_free(val_00,(ASN1_ITEM *)X509_PUBKEY_it);
  }
  pRVar3 = (RSA *)0x0;
LAB_00554a94:
  EVP_PKEY_free(pEVar7);
  return pRVar3;
}
