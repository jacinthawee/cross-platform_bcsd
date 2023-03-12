
EVP_PKEY * d2i_PUBKEY(EVP_PKEY **a,uchar **pp,long length)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 *val;
  EVP_PKEY *pkey;
  ASN1_VALUE *val_00;
  int iVar3;
  undefined4 uVar4;
  undefined1 *in;
  undefined4 uVar5;
  EVP_PKEY *pEVar6;
  code *pcVar7;
  uchar *local_28;
  int local_24;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_28 = *pp;
  in = (undefined1 *)&local_28;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  val = (undefined4 *)
        ASN1_item_d2i((ASN1_VALUE **)0x0,(uchar **)in,length,(ASN1_ITEM *)X509_PUBKEY_it);
  if (val != (undefined4 *)0x0) {
    pEVar6 = (EVP_PKEY *)val[2];
    if (pEVar6 == (EVP_PKEY *)0x0) {
      if (val[1] != 0) {
        pkey = EVP_PKEY_new();
        if (pkey != (EVP_PKEY *)0x0) {
          iVar3 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*(undefined4 *)*val);
          iVar3 = EVP_PKEY_set_type(pkey,iVar3);
          if (iVar3 == 0) {
            uVar5 = 0x6f;
            uVar4 = 0x94;
          }
          else if (*(code **)(pkey->ameth + 0x14) == (code *)0x0) {
            uVar5 = 0x7c;
            uVar4 = 0x9e;
          }
          else {
            iVar3 = (**(code **)(pkey->ameth + 0x14))(pkey,val);
            if (iVar3 != 0) {
              (*(code *)PTR_CRYPTO_lock_006a8144)(9,10,"x_pubkey.c",0xa3);
              puVar1 = PTR_CRYPTO_lock_006a8144;
              if (val[2] == 0) {
                val[2] = pkey;
                (*(code *)puVar1)(10,10,"x_pubkey.c",0xaa);
                pEVar6 = pkey;
              }
              else {
                (*(code *)PTR_CRYPTO_lock_006a8144)(10,10,"x_pubkey.c",0xa5);
                EVP_PKEY_free(pkey);
                pEVar6 = (EVP_PKEY *)val[2];
              }
              (*(code *)PTR_CRYPTO_add_lock_006a805c)(&pEVar6->references,1,10,"x_pubkey.c",0xac);
              goto LAB_00551130;
            }
            uVar5 = 0x7d;
            uVar4 = 0x9a;
          }
          (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x77,uVar5,"x_pubkey.c",uVar4);
          EVP_PKEY_free(pkey);
          in = X509_PUBKEY_it;
          ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)X509_PUBKEY_it);
          goto LAB_00551168;
        }
        (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x77,0x41,"x_pubkey.c",0x8f);
      }
      in = X509_PUBKEY_it;
      ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)X509_PUBKEY_it);
      goto LAB_00551168;
    }
    (*(code *)PTR_CRYPTO_add_lock_006a805c)(&pEVar6->references,1,10,"x_pubkey.c",0x87);
    pEVar6 = (EVP_PKEY *)val[2];
LAB_00551130:
    in = X509_PUBKEY_it;
    ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)X509_PUBKEY_it);
    if (pEVar6 != (EVP_PKEY *)0x0) {
      *pp = local_28;
      if (a != (EVP_PKEY **)0x0) {
        EVP_PKEY_free(*a);
        *a = pEVar6;
      }
      goto LAB_00551168;
    }
  }
  pEVar6 = (EVP_PKEY *)0x0;
LAB_00551168:
  if (local_24 == *(int *)puVar2) {
    return pEVar6;
  }
  iVar3 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (iVar3 != 0) {
    val_00 = ASN1_item_new((ASN1_ITEM *)X509_PUBKEY_it);
    if (val_00 != (ASN1_VALUE *)0x0) {
      if (*(int *)(iVar3 + 0xc) == 0) {
        uVar5 = 0x6f;
        uVar4 = 0x6f;
      }
      else {
        pcVar7 = *(code **)(*(int *)(iVar3 + 0xc) + 0x18);
        if (pcVar7 == (code *)0x0) {
          uVar5 = 0x7c;
          uVar4 = 0x6b;
        }
        else {
          iVar3 = (*pcVar7)(val_00,iVar3);
          if (iVar3 != 0) {
            pEVar6 = (EVP_PKEY *)ASN1_item_i2d(val_00,(uchar **)in,(ASN1_ITEM *)X509_PUBKEY_it);
            ASN1_item_free(val_00,(ASN1_ITEM *)X509_PUBKEY_it);
            return pEVar6;
          }
          uVar5 = 0x7e;
          uVar4 = 0x67;
        }
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x78,uVar5,"x_pubkey.c",uVar4);
      ASN1_item_free(val_00,(ASN1_ITEM *)X509_PUBKEY_it);
    }
    return (EVP_PKEY *)0x0;
  }
  return (EVP_PKEY *)0x0;
}

