
stack_st_X509 * PKCS7_get0_signers(PKCS7 *p7,stack_st_X509 *certs,int flags)

{
  int iVar1;
  stack_st_PKCS7_SIGNER_INFO *psVar2;
  stack_st_X509 *psVar3;
  int iVar4;
  undefined4 uVar5;
  uchar *puVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined4 *puVar9;
  
  if (p7 == (PKCS7 *)0x0) {
    uVar7 = 0x8f;
    uVar5 = 0x1b8;
  }
  else {
    iVar1 = (*(code *)PTR_OBJ_obj2nid_006a822c)(p7->type);
    if (iVar1 == 0x16) {
      psVar2 = PKCS7_get_signer_info(p7);
      iVar1 = (*(code *)PTR_sk_num_006a7f2c)(psVar2);
      if (iVar1 < 1) {
        uVar7 = 0x8e;
        uVar5 = 0x1c6;
      }
      else {
        psVar3 = (stack_st_X509 *)(*(code *)PTR_sk_new_null_006a80a4)();
        if (psVar3 != (stack_st_X509 *)0x0) {
          uVar8 = flags & 0x10;
          if (certs == (stack_st_X509 *)0x0) {
            if (uVar8 != 0) {
              iVar1 = (*(code *)PTR_sk_num_006a7f2c)(psVar2);
              if (iVar1 < 1) {
                return psVar3;
              }
              (*(code *)PTR_sk_value_006a7f24)(psVar2,0);
LAB_005a7ba0:
              (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x7c,0x80,"pk7_smime.c",0x1dc);
              (*(code *)PTR_sk_free_006a7f80)(psVar3);
              return (stack_st_X509 *)0x0;
            }
            do {
              iVar1 = (*(code *)PTR_sk_num_006a7f2c)(psVar2);
              if (iVar1 <= (int)uVar8) {
                return psVar3;
              }
              iVar1 = (*(code *)PTR_sk_value_006a7f24)(psVar2,uVar8);
              puVar6 = ((p7->d).data)->data;
              if ((puVar6 == (uchar *)0x0) ||
                 (iVar1 = (*(code *)PTR_X509_find_by_issuer_and_serial_006aa254)
                                    (puVar6,**(undefined4 **)(iVar1 + 4),
                                     (*(undefined4 **)(iVar1 + 4))[1]), iVar1 == 0))
              goto LAB_005a7ba0;
              iVar1 = (*(code *)PTR_sk_push_006a80a8)(psVar3,iVar1);
              uVar8 = uVar8 + 1;
            } while (iVar1 != 0);
          }
          else if (uVar8 == 0) {
            do {
              iVar1 = (*(code *)PTR_sk_num_006a7f2c)(psVar2);
              if (iVar1 <= (int)uVar8) {
                return psVar3;
              }
              iVar1 = (*(code *)PTR_sk_value_006a7f24)(psVar2,uVar8);
              puVar9 = *(undefined4 **)(iVar1 + 4);
              iVar1 = (*(code *)PTR_X509_find_by_issuer_and_serial_006aa254)
                                (certs,*puVar9,puVar9[1]);
              if ((iVar1 == 0) &&
                 ((puVar6 = ((p7->d).data)->data, puVar6 == (uchar *)0x0 ||
                  (iVar1 = (*(code *)PTR_X509_find_by_issuer_and_serial_006aa254)
                                     (puVar6,*puVar9,puVar9[1]), iVar1 == 0)))) goto LAB_005a7ba0;
              iVar1 = (*(code *)PTR_sk_push_006a80a8)(psVar3,iVar1);
              uVar8 = uVar8 + 1;
            } while (iVar1 != 0);
          }
          else {
            iVar1 = 0;
            do {
              iVar4 = (*(code *)PTR_sk_num_006a7f2c)(psVar2);
              if (iVar4 <= iVar1) {
                return psVar3;
              }
              iVar4 = (*(code *)PTR_sk_value_006a7f24)(psVar2,iVar1);
              iVar4 = (*(code *)PTR_X509_find_by_issuer_and_serial_006aa254)
                                (certs,**(undefined4 **)(iVar4 + 4),(*(undefined4 **)(iVar4 + 4))[1]
                                );
              if (iVar4 == 0) goto LAB_005a7ba0;
              iVar4 = (*(code *)PTR_sk_push_006a80a8)(psVar3,iVar4);
              iVar1 = iVar1 + 1;
            } while (iVar4 != 0);
          }
          (*(code *)PTR_sk_free_006a7f80)(psVar3);
          return (stack_st_X509 *)0x0;
        }
        uVar7 = 0x41;
        uVar5 = 0x1cb;
      }
    }
    else {
      uVar7 = 0x71;
      uVar5 = 0x1bd;
    }
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x7c,uVar7,"pk7_smime.c",uVar5);
  return (stack_st_X509 *)0x0;
}

