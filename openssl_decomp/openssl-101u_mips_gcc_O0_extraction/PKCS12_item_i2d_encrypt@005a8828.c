
ASN1_OCTET_STRING *
PKCS12_item_i2d_encrypt(X509_ALGOR *algor,ASN1_ITEM *it,char *pass,int passlen,void *obj,int zbuf)

{
  undefined *puVar1;
  undefined *puVar2;
  ASN1_OCTET_STRING *pAVar3;
  int iVar4;
  int iVar5;
  uchar *puVar6;
  ASN1_OBJECT *pAVar7;
  undefined4 uVar8;
  char *pcVar9;
  int iVar10;
  undefined4 uVar11;
  PKCS7 *pPVar12;
  int local_c0;
  int local_bc;
  undefined auStack_b8 [140];
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_c0 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pAVar3 = (ASN1_OCTET_STRING *)(*(code *)PTR_ASN1_STRING_type_new_006a8680)(4);
  if (pAVar3 == (ASN1_OCTET_STRING *)0x0) {
    uVar11 = 0x41;
    uVar8 = 0xb2;
  }
  else {
    iVar4 = (*(code *)PTR_ASN1_item_i2d_006a8678)(obj,&local_c0,it);
    iVar10 = local_c0;
    if (local_c0 != 0) {
      (*(code *)PTR_EVP_CIPHER_CTX_init_006a7a64)(auStack_b8);
      iVar5 = (*(code *)PTR_EVP_PBE_CipherInit_006a9228)
                        (algor->algorithm,pass,passlen,algor->parameter,auStack_b8,1);
      if (iVar5 == 0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x77,0x73,"p12_decr.c",0x57);
      }
      else {
        iVar5 = (*(code *)PTR_EVP_CIPHER_CTX_block_size_006a922c)(auStack_b8);
        puVar6 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar4 + iVar5,"p12_decr.c",0x5b);
        if (puVar6 == (uchar *)0x0) {
          (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x77,0x41,"p12_decr.c",0x5c);
        }
        else {
          iVar5 = (*(code *)PTR_EVP_CipherUpdate_006a8b04)(auStack_b8,puVar6,&local_bc,iVar10,iVar4)
          ;
          iVar10 = local_bc;
          if (iVar5 == 0) {
            (*(code *)PTR_CRYPTO_free_006a6e88)(puVar6);
            (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x77,6,"p12_decr.c",99);
          }
          else {
            iVar5 = (*(code *)PTR_EVP_CipherFinal_ex_006a8b08)
                              (auStack_b8,puVar6 + local_bc,&local_bc);
            puVar1 = PTR_EVP_CIPHER_CTX_cleanup_006a7a74;
            if (iVar5 != 0) {
              pAVar3->data = puVar6;
              pAVar3->length = local_bc + iVar10;
              (*(code *)puVar1)(auStack_b8);
              if (zbuf != 0) {
                (*(code *)PTR_OPENSSL_cleanse_006a7074)(local_c0,iVar4);
              }
              (*(code *)PTR_CRYPTO_free_006a6e88)(local_c0);
              goto LAB_005a89b8;
            }
            (*(code *)PTR_CRYPTO_free_006a6e88)(puVar6);
            (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x77,0x74,"p12_decr.c",0x6c);
          }
        }
        (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a7a74)(auStack_b8);
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x6c,0x67,"p12_decr.c",0xbc);
      (*(code *)PTR_CRYPTO_free_006a6e88)(local_c0);
      pAVar3 = (ASN1_OCTET_STRING *)0x0;
      goto LAB_005a89b8;
    }
    uVar11 = 0x66;
    uVar8 = 0xb7;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x6c,uVar11,"p12_decr.c",uVar8);
  pAVar3 = (ASN1_OCTET_STRING *)0x0;
LAB_005a89b8:
  if (local_2c == *(int *)puVar2) {
    return pAVar3;
  }
  iVar10 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  pAVar3 = (ASN1_OCTET_STRING *)PKCS12_new();
  if (pAVar3 == (ASN1_OCTET_STRING *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x6d,0x41,"p12_init.c",0x46);
  }
  else {
    (*(code *)PTR_ASN1_INTEGER_set_006a7164)((ASN1_INTEGER *)pAVar3->length,3);
    pPVar12 = (PKCS7 *)pAVar3->data;
    pAVar7 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a7140)(iVar10);
    pPVar12->type = pAVar7;
    if (iVar10 == 0x15) {
      pPVar12 = (PKCS7 *)pAVar3->data;
      pcVar9 = (char *)(*(code *)PTR_ASN1_STRING_type_new_006a8680)(4);
      (pPVar12->d).ptr = pcVar9;
      if (pcVar9 != (char *)0x0) {
        return pAVar3;
      }
      uVar11 = 0x41;
      uVar8 = 0x4e;
    }
    else {
      uVar11 = 0x77;
      uVar8 = 0x53;
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x6d,uVar11,"p12_init.c",uVar8);
    PKCS12_free((PKCS12 *)pAVar3);
  }
  return (ASN1_OCTET_STRING *)0x0;
}
