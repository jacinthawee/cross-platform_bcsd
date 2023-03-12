
int PKCS7_add_signer(PKCS7 *p7,PKCS7_SIGNER_INFO *p7i)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  stack_st_X509_ALGOR *psVar8;
  stack_st_PKCS7_SIGNER_INFO *psVar9;
  
  iVar2 = (*(code *)PTR_OBJ_obj2nid_006a712c)(p7->type);
  if ((iVar2 != 0x16) && (iVar2 != 0x18)) {
    uVar7 = 0x71;
    uVar6 = 0xff;
LAB_005a00c8:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x67,uVar7,"pk7_lib.c",uVar6);
    return 0;
  }
  psVar9 = ((p7->d).sign)->signer_info;
  psVar8 = ((p7->d).sign)->md_algs;
  iVar3 = (*(code *)PTR_OBJ_obj2nid_006a712c)(p7i->digest_alg->algorithm);
  iVar2 = 0;
  do {
    iVar4 = (*(code *)PTR_sk_num_006a6e2c)(psVar8);
    if (iVar4 <= iVar2) {
      puVar5 = (undefined4 *)(*(code *)PTR_X509_ALGOR_new_006a7ec8)();
      if (puVar5 != (undefined4 *)0x0) {
        iVar2 = (*(code *)PTR_ASN1_TYPE_new_006a7ecc)();
        puVar5[1] = iVar2;
        if (iVar2 != 0) {
          uVar6 = (*(code *)PTR_OBJ_nid2obj_006a7140)(iVar3);
          *puVar5 = uVar6;
          puVar1 = PTR_sk_push_006a6fa8;
          *(undefined4 *)puVar5[1] = 5;
          iVar2 = (*(code *)puVar1)(psVar8,puVar5);
          if (iVar2 == 0) {
            (*(code *)PTR_X509_ALGOR_free_006a7ea4)(puVar5);
            return 0;
          }
          break;
        }
      }
      (*(code *)PTR_X509_ALGOR_free_006a7ea4)(puVar5);
      uVar7 = 0x41;
      uVar6 = 0x112;
      goto LAB_005a00c8;
    }
    puVar5 = (undefined4 *)(*(code *)PTR_sk_value_006a6e24)(psVar8,iVar2);
    iVar4 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*puVar5);
    iVar2 = iVar2 + 1;
  } while (iVar3 != iVar4);
  iVar2 = (*(code *)PTR_sk_push_006a6fa8)(psVar9,p7i);
  return (uint)(iVar2 != 0);
}

