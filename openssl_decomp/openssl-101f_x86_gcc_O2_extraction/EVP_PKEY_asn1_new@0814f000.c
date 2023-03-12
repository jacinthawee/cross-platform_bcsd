
EVP_PKEY_ASN1_METHOD * EVP_PKEY_asn1_new(int id,int flags,char *pem_str,char *info)

{
  int *ptr;
  char *pcVar1;
  uint uVar2;
  undefined4 *puVar3;
  byte bVar4;
  
  bVar4 = 0;
  ptr = (int *)CRYPTO_malloc(0x6c,"ameth_lib.c",0x124);
  if (ptr == (int *)0x0) {
    return (EVP_PKEY_ASN1_METHOD *)0x0;
  }
  ptr[0x1a] = 0;
  puVar3 = (undefined4 *)((uint)(ptr + 1) & 0xfffffffc);
  for (uVar2 = (uint)((int)ptr + (0x6c - (int)(undefined4 *)((uint)(ptr + 1) & 0xfffffffc))) >> 2;
      uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar3 = 0;
    puVar3 = puVar3 + (uint)bVar4 * -2 + 1;
  }
  *ptr = id;
  ptr[1] = id;
  ptr[2] = flags | 2;
  if (info == (char *)0x0) {
    ptr[4] = 0;
joined_r0x0814f14d:
    if (pem_str == (char *)0x0) {
      ptr[3] = 0;
LAB_0814f09c:
      ptr[5] = 0;
      ptr[6] = 0;
      ptr[7] = 0;
      ptr[8] = 0;
      ptr[9] = 0;
      ptr[10] = 0;
      ptr[0xb] = 0;
      ptr[0x18] = 0;
      ptr[0x17] = 0;
      ptr[0x19] = 0;
      ptr[0x1a] = 0;
      ptr[0xc] = 0;
      ptr[0xd] = 0;
      ptr[0xe] = 0;
      ptr[0xf] = 0;
      ptr[0x10] = 0;
      ptr[0x11] = 0;
      ptr[0x12] = 0;
      ptr[0x13] = 0;
      ptr[0x15] = 0;
      ptr[0x16] = 0;
      return (EVP_PKEY_ASN1_METHOD *)ptr;
    }
    pcVar1 = BUF_strdup(pem_str);
    ptr[3] = (int)pcVar1;
    if (pcVar1 != (char *)0x0) goto LAB_0814f09c;
    if (((byte)*(EVP_PKEY_ASN1_METHOD *)(ptr + 2) & 2) == 0) {
      return (EVP_PKEY_ASN1_METHOD *)0x0;
    }
  }
  else {
    pcVar1 = BUF_strdup(info);
    ptr[4] = (int)pcVar1;
    if (pcVar1 != (char *)0x0) goto joined_r0x0814f14d;
    if (((byte)*(EVP_PKEY_ASN1_METHOD *)(ptr + 2) & 2) == 0) {
      return (EVP_PKEY_ASN1_METHOD *)0x0;
    }
    if ((void *)ptr[3] == (void *)0x0) goto LAB_0814f18c;
    CRYPTO_free((void *)ptr[3]);
  }
  if ((void *)ptr[4] != (void *)0x0) {
    CRYPTO_free((void *)ptr[4]);
  }
LAB_0814f18c:
  CRYPTO_free(ptr);
  return (EVP_PKEY_ASN1_METHOD *)0x0;
}

