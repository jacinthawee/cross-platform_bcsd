
int pub_encode_gost94(X509_PUBKEY *param_1,EVP_PKEY *param_2)

{
  uchar *puVar1;
  void *pvVar2;
  int iVar3;
  ASN1_OBJECT *aobj;
  int iVar4;
  uchar *to;
  ASN1_OCTET_STRING *str;
  uchar *puVar5;
  uchar *puVar6;
  void *pval;
  int in_GS_OFFSET;
  int local_38;
  uchar *local_24;
  int local_20;
  
  pval = (void *)0x0;
  local_24 = (uchar *)0x0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  pvVar2 = EVP_PKEY_get0(param_2);
  iVar3 = EVP_PKEY_base_id(param_2);
  aobj = OBJ_nid2obj(iVar3);
  local_38 = -1;
  if (param_2->save_parameters != 0) {
    pval = (void *)encode_gost_algor_params();
    local_38 = 0x10;
  }
  iVar4 = BN_num_bits(*(BIGNUM **)((int)pvVar2 + 0x18));
  iVar3 = iVar4 + 0xe;
  if (-1 < iVar4 + 7) {
    iVar3 = iVar4 + 7;
  }
  iVar3 = iVar3 >> 3;
  to = (uchar *)CRYPTO_malloc(iVar3,"gost_ameth.c",0x291);
  BN_bn2bin(*(BIGNUM **)((int)pvVar2 + 0x18),to);
  str = ASN1_OCTET_STRING_new();
  ASN1_STRING_set(str,(void *)0x0,iVar3);
  puVar5 = ASN1_STRING_data(str);
  puVar6 = to + iVar3;
  if (0 < iVar3) {
    do {
      puVar1 = puVar6 + -1;
      puVar6 = puVar6 + -1;
      *puVar5 = *puVar1;
      puVar5 = puVar5 + 1;
    } while (puVar6 != to);
  }
  CRYPTO_free(to);
  iVar3 = i2d_ASN1_OCTET_STRING(str,&local_24);
  ASN1_BIT_STRING_free(str);
  iVar4 = 0;
  if (-1 < iVar3) {
    iVar4 = X509_PUBKEY_set0_param(param_1,aobj,local_38,pval,local_24,iVar3);
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}

