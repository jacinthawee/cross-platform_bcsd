
int pub_encode_gost01(X509_PUBKEY *param_1,EVP_PKEY *param_2)

{
  uchar *puVar1;
  size_t __n;
  EC_KEY *key;
  int iVar2;
  ASN1_OBJECT *aobj;
  BIGNUM *order;
  EC_GROUP *pEVar3;
  EC_POINT *p;
  BIGNUM *a;
  BIGNUM *a_00;
  int iVar4;
  void *__s;
  ASN1_OCTET_STRING *str;
  uchar *puVar5;
  void *pvVar6;
  int in_GS_OFFSET;
  void *local_40;
  int local_3c;
  uchar *local_24;
  int local_20;
  
  local_24 = (uchar *)0x0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  key = (EC_KEY *)EVP_PKEY_get0(param_2);
  iVar2 = EVP_PKEY_base_id(param_2);
  aobj = OBJ_nid2obj(iVar2);
  local_3c = -1;
  local_40 = (void *)0x0;
  if (param_2->save_parameters != 0) {
    local_40 = (void *)encode_gost_algor_params();
    local_3c = 0x10;
  }
  order = BN_new();
  pEVar3 = EC_KEY_get0_group(key);
  EC_GROUP_get_order(pEVar3,order,(BN_CTX *)0x0);
  p = EC_KEY_get0_public_key(key);
  if (p == (EC_POINT *)0x0) {
    ERR_GOST_error(0x87,0x7a,"gost_ameth.c",0x2e4);
    iVar2 = 0;
  }
  else {
    a = BN_new();
    a_00 = BN_new();
    if ((a == (BIGNUM *)0x0) || (a_00 == (BIGNUM *)0x0)) {
      ERR_GOST_error(0x87,0x41,"gost_ameth.c",0x2ea);
      if (a != (BIGNUM *)0x0) {
        BN_free(a);
      }
      if (a_00 != (BIGNUM *)0x0) {
        BN_free(a_00);
      }
      BN_free(order);
      iVar2 = 0;
    }
    else {
      pEVar3 = EC_KEY_get0_group(key);
      iVar2 = EC_POINT_get_affine_coordinates_GFp(pEVar3,p,a,a_00,(BN_CTX *)0x0);
      if (iVar2 == 0) {
        ERR_GOST_error(0x87,0x44,"gost_ameth.c",0x2f2);
        BN_free(a);
        BN_free(a_00);
        BN_free(order);
      }
      else {
        iVar4 = BN_num_bits(order);
        iVar2 = iVar4 + 0xe;
        if (-1 < iVar4 + 7) {
          iVar2 = iVar4 + 7;
        }
        iVar2 = iVar2 >> 3;
        __n = iVar2 * 2;
        BN_free(order);
        __s = CRYPTO_malloc(__n,"gost_ameth.c",0x2fa);
        memset(__s,0,__n);
        store_bignum(a,(int)__s + iVar2,iVar2);
        store_bignum(a_00,__s,iVar2);
        BN_free(a);
        BN_free(a_00);
        str = ASN1_OCTET_STRING_new();
        ASN1_STRING_set(str,(void *)0x0,__n);
        puVar5 = ASN1_STRING_data(str);
        pvVar6 = (void *)(iVar2 + (int)__s + iVar2);
        if (0 < (int)__n) {
          do {
            puVar1 = (uchar *)((int)pvVar6 + -1);
            pvVar6 = (void *)((int)pvVar6 + -1);
            *puVar5 = *puVar1;
            puVar5 = puVar5 + 1;
          } while (pvVar6 != __s);
        }
        CRYPTO_free(__s);
        iVar4 = i2d_ASN1_OCTET_STRING(str,&local_24);
        ASN1_BIT_STRING_free(str);
        iVar2 = 0;
        if (-1 < iVar4) {
          iVar2 = X509_PUBKEY_set0_param(param_1,aobj,local_3c,local_40,local_24,iVar4);
        }
      }
    }
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}

