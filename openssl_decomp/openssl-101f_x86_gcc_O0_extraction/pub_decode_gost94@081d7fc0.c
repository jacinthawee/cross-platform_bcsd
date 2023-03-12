
undefined4 pub_decode_gost94(EVP_PKEY *param_1,X509_PUBKEY *param_2)

{
  uchar *puVar1;
  int iVar2;
  undefined4 uVar3;
  ASN1_OCTET_STRING *a;
  uchar *s;
  void *pvVar4;
  BIGNUM *pBVar5;
  uchar *puVar6;
  int in_GS_OFFSET;
  X509_ALGOR *local_20;
  uchar *local_1c;
  ASN1_OBJECT *local_18;
  long local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_20 = (X509_ALGOR *)0x0;
  local_1c = (uchar *)0x0;
  local_18 = (ASN1_OBJECT *)0x0;
  iVar2 = X509_PUBKEY_get0_param(&local_18,&local_1c,&local_14,&local_20,param_2);
  if (iVar2 != 0) {
    iVar2 = OBJ_obj2nid(local_18);
    EVP_PKEY_assign(param_1,iVar2,(void *)0x0);
    iVar2 = decode_gost_algor_params();
    if (iVar2 != 0) {
      a = d2i_ASN1_OCTET_STRING((ASN1_OCTET_STRING **)0x0,&local_1c,local_14);
      if (a != (ASN1_OCTET_STRING *)0x0) {
        s = (uchar *)CRYPTO_malloc(a->length,"gost_ameth.c",0x272);
        puVar6 = s + a->length;
        iVar2 = 0;
        if (0 < a->length) {
          do {
            puVar6 = puVar6 + -1;
            puVar1 = a->data + iVar2;
            iVar2 = iVar2 + 1;
            *puVar6 = *puVar1;
          } while (a->length != iVar2 && iVar2 <= a->length);
        }
        pvVar4 = EVP_PKEY_get0(param_1);
        pBVar5 = BN_bin2bn(s,a->length,(BIGNUM *)0x0);
        *(BIGNUM **)((int)pvVar4 + 0x18) = pBVar5;
        ASN1_OCTET_STRING_free(a);
        CRYPTO_free(s);
        uVar3 = 1;
        goto LAB_081d8014;
      }
      ERR_GOST_error(0x86,0x41,"gost_ameth.c",0x26f);
    }
  }
  uVar3 = 0;
LAB_081d8014:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}

