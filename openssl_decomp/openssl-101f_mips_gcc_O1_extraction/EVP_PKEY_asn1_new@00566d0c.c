
EVP_PKEY_ASN1_METHOD * EVP_PKEY_asn1_new(int id,int flags,char *pem_str,char *info)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x6c,"ameth_lib.c",0x124);
  if (piVar1 == (int *)0x0) {
    return (EVP_PKEY_ASN1_METHOD *)0x0;
  }
  (*(code *)PTR_memset_006aab00)(piVar1,0,0x6c);
  *piVar1 = id;
  piVar1[1] = id;
  piVar1[2] = flags | 2;
  if (info == (char *)0x0) {
    piVar1[4] = 0;
joined_r0x00566e44:
    if (pem_str == (char *)0x0) {
      piVar1[3] = 0;
LAB_00566dcc:
      piVar1[5] = 0;
      piVar1[6] = 0;
      piVar1[7] = 0;
      piVar1[8] = 0;
      piVar1[9] = 0;
      piVar1[10] = 0;
      piVar1[0xb] = 0;
      piVar1[0x18] = 0;
      piVar1[0x17] = 0;
      piVar1[0x19] = 0;
      piVar1[0x1a] = 0;
      piVar1[0xc] = 0;
      piVar1[0xd] = 0;
      piVar1[0xe] = 0;
      piVar1[0xf] = 0;
      piVar1[0x10] = 0;
      piVar1[0x11] = 0;
      piVar1[0x12] = 0;
      piVar1[0x13] = 0;
      piVar1[0x15] = 0;
      piVar1[0x16] = 0;
      return (EVP_PKEY_ASN1_METHOD *)piVar1;
    }
    iVar2 = (*(code *)PTR_BUF_strdup_006a80dc)(pem_str);
    piVar1[3] = iVar2;
    if (iVar2 != 0) goto LAB_00566dcc;
    if ((piVar1[2] & 2U) == 0) {
      return (EVP_PKEY_ASN1_METHOD *)0x0;
    }
  }
  else {
    iVar2 = (*(code *)PTR_BUF_strdup_006a80dc)(info);
    piVar1[4] = iVar2;
    if (iVar2 != 0) goto joined_r0x00566e44;
    if ((piVar1[2] & 2U) == 0) {
      return (EVP_PKEY_ASN1_METHOD *)0x0;
    }
    if (piVar1[3] == 0) goto LAB_00566e94;
    (*(code *)PTR_CRYPTO_free_006a7f88)();
  }
  if (piVar1[4] != 0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
  }
LAB_00566e94:
  (*(code *)PTR_CRYPTO_free_006a7f88)(piVar1);
  return (EVP_PKEY_ASN1_METHOD *)0x0;
}

