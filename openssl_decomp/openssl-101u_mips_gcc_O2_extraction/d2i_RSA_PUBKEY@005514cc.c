
RSA * d2i_RSA_PUBKEY(RSA **a,uchar **pp,long length)

{
  undefined *puVar1;
  undefined *puVar2;
  uchar *puVar3;
  undefined4 *val;
  RSA *pRVar4;
  ASN1_VALUE *val_00;
  int iVar5;
  undefined4 uVar6;
  rsa_st *key;
  undefined1 *in;
  undefined4 uVar7;
  EVP_PKEY *pEVar8;
  code *pcVar9;
  uchar *local_28;
  rsa_st *local_24;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_28 = *pp;
  in = (undefined1 *)&local_28;
  local_24 = *(rsa_st **)PTR___stack_chk_guard_006a9ae8;
  val = (undefined4 *)
        ASN1_item_d2i((ASN1_VALUE **)0x0,(uchar **)in,length,(ASN1_ITEM *)X509_PUBKEY_it);
  if (val == (undefined4 *)0x0) {
LAB_005516c4:
    pRVar4 = (RSA *)0x0;
  }
  else {
    if (val[2] != 0) {
      (*(code *)PTR_CRYPTO_add_lock_006a805c)(val[2] + 8,1,10,"x_pubkey.c",0x87);
      pEVar8 = (EVP_PKEY *)val[2];
LAB_00551574:
      in = X509_PUBKEY_it;
      ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)X509_PUBKEY_it);
      puVar3 = local_28;
      if (pEVar8 != (EVP_PKEY *)0x0) {
        pRVar4 = EVP_PKEY_get1_RSA(pEVar8);
        EVP_PKEY_free(pEVar8);
        if (pRVar4 != (rsa_st *)0x0) {
          *pp = puVar3;
          if (a != (RSA **)0x0) {
            (*(code *)PTR_RSA_free_006a7600)(*a);
            *a = pRVar4;
          }
          goto LAB_005515d8;
        }
      }
      goto LAB_005516c4;
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
            goto LAB_00551574;
          }
          uVar7 = 0x7d;
          uVar6 = 0x9a;
        }
        (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x77,uVar7,"x_pubkey.c",uVar6);
        EVP_PKEY_free(pEVar8);
        in = X509_PUBKEY_it;
        ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)X509_PUBKEY_it);
        goto LAB_005516c4;
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x77,0x41,"x_pubkey.c",0x8f);
    }
    in = X509_PUBKEY_it;
    ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)X509_PUBKEY_it);
    pRVar4 = (RSA *)0x0;
  }
LAB_005515d8:
  if (local_24 == *(rsa_st **)puVar2) {
    return pRVar4;
  }
  key = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (key == (rsa_st *)0x0) {
    return (RSA *)0x0;
  }
  pEVar8 = EVP_PKEY_new();
  if (pEVar8 == (EVP_PKEY *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xa5,0x41,"x_pubkey.c",0xfe);
    return (RSA *)0x0;
  }
  EVP_PKEY_set1_RSA(pEVar8,key);
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
          pRVar4 = (RSA *)ASN1_item_i2d(val_00,(uchar **)in,(ASN1_ITEM *)X509_PUBKEY_it);
          ASN1_item_free(val_00,(ASN1_ITEM *)X509_PUBKEY_it);
          goto LAB_005518c0;
        }
        uVar7 = 0x7e;
        uVar6 = 0x67;
      }
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x78,uVar7,"x_pubkey.c",uVar6);
    ASN1_item_free(val_00,(ASN1_ITEM *)X509_PUBKEY_it);
  }
  pRVar4 = (RSA *)0x0;
LAB_005518c0:
  EVP_PKEY_free(pEVar8);
  return pRVar4;
}
