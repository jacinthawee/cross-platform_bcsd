
int PKCS7_decrypt(PKCS7 *p7,EVP_PKEY *pkey,X509 *cert,BIO *data,int flags)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  BIO *pBVar4;
  int iVar5;
  undefined4 *data_00;
  undefined4 uVar6;
  PKCS7_SIGNER_INFO *p7si;
  BIO *pBVar7;
  undefined4 uVar8;
  BIO aBStack_101c [64];
  PKCS7_SIGNER_INFO *local_1c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(PKCS7_SIGNER_INFO **)PTR___stack_chk_guard_006aabf0;
  if (p7 == (PKCS7 *)0x0) {
    uVar8 = 0x8f;
    uVar6 = 0x21d;
  }
  else {
    iVar2 = (*(code *)PTR_OBJ_obj2nid_006a822c)(p7->type);
    if (iVar2 == 0x17) {
      if ((cert != (X509 *)0x0) &&
         (uVar3 = (*(code *)PTR_X509_check_private_key_006a817c)(cert,pkey), uVar3 == 0)) {
        data = (BIO *)0x72;
        (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x72,0x7f,"pk7_smime.c",0x228);
        goto LAB_005a89d8;
      }
      pBVar4 = PKCS7_dataDecode(p7,pkey,(BIO *)0x0,cert);
      if (pBVar4 != (BIO *)0x0) {
        if ((flags & 1U) == 0) {
          do {
            pBVar7 = aBStack_101c;
            iVar2 = (*(code *)PTR_BIO_read_006a85bc)(pBVar4,aBStack_101c,0x1000);
            if (iVar2 < 1) {
              iVar2 = (*(code *)PTR_BIO_method_type_006a9444)(pBVar4);
              if (iVar2 == 0x20a) {
                data = (BIO *)0x71;
                iVar2 = (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar4,0x71,0,0);
                uVar3 = (uint)(iVar2 != 0);
              }
              else {
                uVar3 = 1;
                data = pBVar7;
              }
              goto LAB_005a8994;
            }
            pBVar7 = aBStack_101c;
            iVar5 = (*(code *)PTR_BIO_write_006a7f14)(data,aBStack_101c,iVar2);
          } while (iVar2 == iVar5);
          uVar3 = 0;
          data = pBVar7;
LAB_005a8994:
          (*(code *)PTR_BIO_free_all_006a7f74)(pBVar4);
        }
        else {
          uVar6 = (*(code *)PTR_BIO_f_buffer_006a8940)();
          iVar2 = (*(code *)PTR_BIO_new_006a7fa4)(uVar6);
          if (iVar2 == 0) {
            data = (BIO *)0x72;
            (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x72,0x41,"pk7_smime.c",0x235);
          }
          else {
            iVar5 = (*(code *)PTR_BIO_push_006a85c0)(iVar2,pBVar4);
            if (iVar5 != 0) {
              uVar3 = (*(code *)PTR_SMIME_text_006aa2b4)(iVar5,data);
              if ((0 < (int)uVar3) &&
                 (iVar2 = (*(code *)PTR_BIO_method_type_006a9444)(pBVar4), iVar2 == 0x20a)) {
                data = (BIO *)0x71;
                iVar2 = (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar4,0x71,0,0);
                if (iVar2 == 0) {
                  uVar3 = 0;
                }
              }
              (*(code *)PTR_BIO_free_all_006a7f74)(iVar5);
              goto LAB_005a89d8;
            }
            data = (BIO *)0x72;
            (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x72,0x41,"pk7_smime.c",0x23a);
            (*(code *)PTR_BIO_free_all_006a7f74)(iVar2);
          }
          (*(code *)PTR_BIO_free_all_006a7f74)(pBVar4);
          uVar3 = 0;
        }
        goto LAB_005a89d8;
      }
      uVar8 = 0x77;
      uVar6 = 0x22d;
    }
    else {
      uVar8 = 0x71;
      uVar6 = 0x222;
    }
  }
  data = (BIO *)0x72;
  (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x72,uVar8,"pk7_smime.c",uVar6);
  uVar3 = 0;
LAB_005a89d8:
  if (local_1c == *(PKCS7_SIGNER_INFO **)puVar1) {
    return uVar3;
  }
  p7si = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  data_00 = (undefined4 *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
  if (data_00 == (undefined4 *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x76,0x41,"pk7_attr.c",0x49);
    return 0;
  }
  uVar6 = (*(code *)PTR_ASN1_item_i2d_006a979c)(data,data_00 + 2,PTR_X509_ALGORS_it_006aa2c8);
  *data_00 = uVar6;
  iVar2 = PKCS7_add_signed_attribute(p7si,0xa7,0x10,data_00);
  return iVar2;
}
