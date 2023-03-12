
int pub_decode_gost01(EVP_PKEY *param_1,X509_PUBKEY *param_2)

{
  uchar *puVar1;
  int iVar2;
  EC_KEY *pEVar3;
  EC_GROUP *group;
  ASN1_OCTET_STRING *a;
  void *ptr;
  int iVar4;
  BIGNUM *y;
  BIGNUM *x;
  EC_POINT *p;
  uchar *puVar5;
  int in_GS_OFFSET;
  X509_ALGOR *local_30;
  uchar *local_2c;
  ASN1_OBJECT *local_28;
  long local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_30 = (X509_ALGOR *)0x0;
  local_2c = (uchar *)0x0;
  local_28 = (ASN1_OBJECT *)0x0;
  iVar2 = X509_PUBKEY_get0_param(&local_28,&local_2c,&local_24,&local_30,param_2);
  if (iVar2 != 0) {
    iVar2 = OBJ_obj2nid(local_28);
    EVP_PKEY_assign(param_1,iVar2,(void *)0x0);
    iVar2 = decode_gost_algor_params();
    if (iVar2 != 0) {
      pEVar3 = (EC_KEY *)EVP_PKEY_get0(param_1);
      group = EC_KEY_get0_group(pEVar3);
      a = d2i_ASN1_OCTET_STRING((ASN1_OCTET_STRING **)0x0,&local_2c,local_24);
      if (a != (ASN1_OCTET_STRING *)0x0) {
        ptr = CRYPTO_malloc(a->length,"gost_ameth.c",0x2b9);
        iVar2 = a->length;
        if (0 < iVar2) {
          puVar5 = (uchar *)((int)ptr + iVar2);
          iVar4 = 0;
          do {
            puVar5 = puVar5 + -1;
            puVar1 = a->data + iVar4;
            iVar4 = iVar4 + 1;
            *puVar5 = *puVar1;
            iVar2 = a->length;
          } while (iVar4 < iVar2);
        }
        ASN1_OCTET_STRING_free(a);
        iVar2 = iVar2 / 2;
        y = (BIGNUM *)getbnfrombuf(ptr,iVar2);
        x = (BIGNUM *)getbnfrombuf(iVar2 + (int)ptr,iVar2);
        CRYPTO_free(ptr);
        p = EC_POINT_new(group);
        iVar2 = EC_POINT_set_affine_coordinates_GFp(group,p,x,y,(BN_CTX *)0x0);
        if (iVar2 == 0) {
          ERR_GOST_error(0x85,0x10,"gost_ameth.c",0x2c9);
          EC_POINT_free(p);
          BN_free(x);
          BN_free(y);
        }
        else {
          BN_free(x);
          BN_free(y);
          pEVar3 = (EC_KEY *)EVP_PKEY_get0(param_1);
          iVar2 = EC_KEY_set_public_key(pEVar3,p);
          if (iVar2 == 0) {
            ERR_GOST_error(0x85,0x10,"gost_ameth.c",0x2d4);
            EC_POINT_free(p);
          }
          else {
            EC_POINT_free(p);
            iVar2 = 1;
          }
        }
        goto LAB_081d7ae5;
      }
      ERR_GOST_error(0x85,0x41,"gost_ameth.c",0x2b6);
    }
  }
  iVar2 = 0;
LAB_081d7ae5:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

