
int PKCS12_setup_mac(PKCS12 *p12,int iter,uchar *salt,int saltlen,EVP_MD *md_type)

{
  PKCS12_MAC_DATA *pPVar1;
  ASN1_INTEGER *pAVar2;
  int iVar3;
  uchar *puVar4;
  undefined4 uVar5;
  ASN1_OBJECT *pAVar6;
  ASN1_TYPE *pAVar7;
  X509_ALGOR *pXVar8;
  ASN1_OCTET_STRING *pAVar9;
  
  pPVar1 = PKCS12_MAC_DATA_new();
  p12->mac = pPVar1;
  if (pPVar1 != (PKCS12_MAC_DATA *)0x0) {
    if (1 < iter) {
      pAVar2 = (ASN1_INTEGER *)(*(code *)PTR_ASN1_STRING_type_new_006a8680)(2);
      pPVar1->iter = pAVar2;
      if (pAVar2 == (ASN1_INTEGER *)0x0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x7a,0x41,"p12_mutl.c",0xa6);
        return 0;
      }
      iVar3 = (*(code *)PTR_ASN1_INTEGER_set_006a7164)(p12->mac->iter,iter);
      if (iVar3 == 0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x7a,0x41,"p12_mutl.c",0xaa);
        return 0;
      }
      pPVar1 = p12->mac;
    }
    pAVar9 = pPVar1->salt;
    if (saltlen == 0) {
      saltlen = 8;
    }
    puVar4 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a7008)(saltlen,"p12_mutl.c",0xb0);
    pAVar9->data = puVar4;
    if (puVar4 == (uchar *)0x0) {
      uVar5 = 0xb1;
    }
    else {
      pAVar9 = p12->mac->salt;
      pAVar9->length = saltlen;
      if (salt == (uchar *)0x0) {
        iVar3 = (*(code *)PTR_RAND_bytes_006a7574)(pAVar9->data,saltlen);
        if (iVar3 < 1) {
          return 0;
        }
      }
      else {
        (*(code *)PTR_memcpy_006a9aec)(pAVar9->data,salt,saltlen);
      }
      pXVar8 = p12->mac->dinfo->algor;
      uVar5 = (*(code *)PTR_EVP_MD_type_006a73cc)(md_type);
      pAVar6 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a7140)(uVar5);
      pPVar1 = p12->mac;
      pXVar8->algorithm = pAVar6;
      pXVar8 = pPVar1->dinfo->algor;
      pAVar7 = (ASN1_TYPE *)(*(code *)PTR_ASN1_TYPE_new_006a7ecc)();
      pXVar8->parameter = pAVar7;
      if (pAVar7 != (ASN1_TYPE *)0x0) {
        p12->mac->dinfo->algor->parameter->type = 5;
        return 1;
      }
      uVar5 = 0xbc;
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x7a,0x41,"p12_mutl.c",uVar5);
  }
  return 0;
}

