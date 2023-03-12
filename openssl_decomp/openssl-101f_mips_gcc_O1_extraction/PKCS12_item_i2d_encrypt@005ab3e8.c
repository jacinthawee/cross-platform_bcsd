
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
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_c0 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  pAVar3 = (ASN1_OCTET_STRING *)(*(code *)PTR_ASN1_STRING_type_new_006a97a4)(4);
  if (pAVar3 == (ASN1_OCTET_STRING *)0x0) {
    uVar11 = 0x41;
    uVar8 = 0xa5;
  }
  else {
    iVar4 = (*(code *)PTR_ASN1_item_i2d_006a979c)(obj,&local_c0,it);
    iVar10 = local_c0;
    if (local_c0 != 0) {
      (*(code *)PTR_EVP_CIPHER_CTX_init_006a8b50)(auStack_b8);
      iVar5 = (*(code *)PTR_EVP_PBE_CipherInit_006aa340)
                        (algor->algorithm,pass,passlen,algor->parameter,auStack_b8,1);
      if (iVar5 == 0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x77,0x73,"p12_decr.c",0x53);
      }
      else {
        iVar5 = (*(code *)PTR_EVP_CIPHER_CTX_block_size_006a90c4)(auStack_b8);
        puVar6 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar4 + iVar5,"p12_decr.c",0x57);
        if (puVar6 == (uchar *)0x0) {
          (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x77,0x41,"p12_decr.c",0x58);
        }
        else {
          iVar5 = (*(code *)PTR_EVP_CipherUpdate_006a9c20)(auStack_b8,puVar6,&local_bc,iVar10,iVar4)
          ;
          iVar10 = local_bc;
          if (iVar5 == 0) {
            (*(code *)PTR_CRYPTO_free_006a7f88)(puVar6);
            (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x77,6,"p12_decr.c",0x60);
          }
          else {
            iVar5 = (*(code *)PTR_EVP_CipherFinal_ex_006a9c24)
                              (auStack_b8,puVar6 + local_bc,&local_bc);
            puVar1 = PTR_EVP_CIPHER_CTX_cleanup_006a8b60;
            if (iVar5 != 0) {
              pAVar3->data = puVar6;
              pAVar3->length = local_bc + iVar10;
              (*(code *)puVar1)(auStack_b8);
              if (zbuf != 0) {
                (*(code *)PTR_OPENSSL_cleanse_006a8174)(local_c0,iVar4);
              }
              (*(code *)PTR_CRYPTO_free_006a7f88)(local_c0);
              goto LAB_005ab578;
            }
            (*(code *)PTR_CRYPTO_free_006a7f88)(puVar6);
            (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x77,0x74,"p12_decr.c",0x68);
          }
        }
        (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a8b60)(auStack_b8);
      }
      (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x6c,0x67,"p12_decr.c",0xaf);
      (*(code *)PTR_CRYPTO_free_006a7f88)(local_c0);
      pAVar3 = (ASN1_OCTET_STRING *)0x0;
      goto LAB_005ab578;
    }
    uVar11 = 0x66;
    uVar8 = 0xaa;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x6c,uVar11,"p12_decr.c",uVar8);
  pAVar3 = (ASN1_OCTET_STRING *)0x0;
LAB_005ab578:
  if (local_2c == *(int *)puVar2) {
    return pAVar3;
  }
  iVar10 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  pAVar3 = (ASN1_OCTET_STRING *)PKCS12_new();
  if (pAVar3 == (ASN1_OCTET_STRING *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x6d,0x41,"p12_init.c",0x45);
  }
  else {
    (*(code *)PTR_ASN1_INTEGER_set_006a8264)((ASN1_INTEGER *)pAVar3->length,3);
    pPVar12 = (PKCS7 *)pAVar3->data;
    pAVar7 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a8240)(iVar10);
    pPVar12->type = pAVar7;
    if (iVar10 == 0x15) {
      pPVar12 = (PKCS7 *)pAVar3->data;
      pcVar9 = (char *)(*(code *)PTR_ASN1_STRING_type_new_006a97a4)(4);
      (pPVar12->d).ptr = pcVar9;
      if (pcVar9 != (char *)0x0) {
        return pAVar3;
      }
      uVar11 = 0x41;
      uVar8 = 0x4e;
    }
    else {
      uVar11 = 0x77;
      uVar8 = 0x54;
    }
    (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x6d,uVar11,"p12_init.c",uVar8);
    PKCS12_free((PKCS12 *)pAVar3);
  }
  return (ASN1_OCTET_STRING *)0x0;
}

