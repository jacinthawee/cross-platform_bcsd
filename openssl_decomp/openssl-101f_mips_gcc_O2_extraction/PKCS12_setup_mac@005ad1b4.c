
int PKCS12_setup_mac(PKCS12 *p12,int iter,uchar *salt,int saltlen,EVP_MD *md_type)

{
  undefined *puVar1;
  PKCS12_MAC_DATA *pPVar2;
  ASN1_INTEGER *pAVar3;
  int iVar4;
  uchar *puVar5;
  undefined4 uVar6;
  ASN1_OBJECT *pAVar7;
  ASN1_TYPE *pAVar8;
  X509_ALGOR *pXVar9;
  ASN1_OCTET_STRING *pAVar10;
  
  pPVar2 = PKCS12_MAC_DATA_new();
  p12->mac = pPVar2;
  if (pPVar2 != (PKCS12_MAC_DATA *)0x0) {
    if (1 < iter) {
      pAVar3 = (ASN1_INTEGER *)(*(code *)PTR_ASN1_STRING_type_new_006a97a4)(2);
      pPVar2->iter = pAVar3;
      if (pAVar3 == (ASN1_INTEGER *)0x0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x7a,0x41,"p12_mutl.c",0xa2);
        return 0;
      }
      iVar4 = (*(code *)PTR_ASN1_INTEGER_set_006a8264)(p12->mac->iter,iter);
      if (iVar4 == 0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x7a,0x41,"p12_mutl.c",0xa6);
        return 0;
      }
      pPVar2 = p12->mac;
    }
    puVar1 = PTR_CRYPTO_malloc_006a8108;
    pAVar10 = pPVar2->salt;
    if (saltlen == 0) {
      saltlen = 8;
    }
    pAVar10->length = saltlen;
    puVar5 = (uchar *)(*(code *)puVar1)(saltlen,"p12_mutl.c",0xac);
    pAVar10->data = puVar5;
    if (puVar5 == (uchar *)0x0) {
      uVar6 = 0xad;
    }
    else {
      if (salt == (uchar *)0x0) {
        iVar4 = (*(code *)PTR_RAND_pseudo_bytes_006a8664)(p12->mac->salt->data,saltlen);
        if (iVar4 < 0) {
          return 0;
        }
      }
      else {
        (*(code *)PTR_memcpy_006aabf4)(p12->mac->salt->data,salt,saltlen);
      }
      pXVar9 = p12->mac->dinfo->algor;
      uVar6 = (*(code *)PTR_EVP_MD_type_006a84cc)(md_type);
      pAVar7 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a8240)(uVar6);
      pPVar2 = p12->mac;
      pXVar9->algorithm = pAVar7;
      pXVar9 = pPVar2->dinfo->algor;
      pAVar8 = (ASN1_TYPE *)(*(code *)PTR_ASN1_TYPE_new_006a8fbc)();
      pXVar9->parameter = pAVar8;
      if (pAVar8 != (ASN1_TYPE *)0x0) {
        p12->mac->dinfo->algor->parameter->type = 5;
        return 1;
      }
      uVar6 = 0xb7;
    }
    (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x7a,0x41,"p12_mutl.c",uVar6);
  }
  return 0;
}

