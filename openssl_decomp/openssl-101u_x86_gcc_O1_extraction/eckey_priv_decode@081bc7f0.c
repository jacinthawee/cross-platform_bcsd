
undefined4 eckey_priv_decode(EVP_PKEY *param_1,PKCS8_PRIV_KEY_INFO *param_2)

{
  int iVar1;
  undefined4 uVar2;
  EC_KEY *pEVar3;
  EC_POINT *pEVar4;
  EC_GROUP *group;
  EC_POINT *src;
  BIGNUM *n;
  int in_GS_OFFSET;
  uchar *local_28;
  void *local_24;
  int local_20;
  long local_1c;
  EC_KEY *local_18;
  X509_ALGOR *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_28 = (uchar *)0x0;
  local_18 = (EC_KEY *)0x0;
  iVar1 = PKCS8_pkey_get0((ASN1_OBJECT **)0x0,&local_28,&local_1c,&local_14,param_2);
  if (iVar1 != 0) {
    X509_ALGOR_get0((ASN1_OBJECT **)0x0,&local_20,&local_24,local_14);
    local_18 = (EC_KEY *)eckey_type2param();
    if (local_18 == (EC_KEY *)0x0) {
LAB_081bc96d:
      ERR_put_error(0x10,0xd5,0x10,"ec_ameth.c",0x121);
    }
    else {
      pEVar3 = d2i_ECPrivateKey(&local_18,&local_28,local_1c);
      if (pEVar3 != (EC_KEY *)0x0) {
        pEVar4 = EC_KEY_get0_public_key(local_18);
        if (pEVar4 != (EC_POINT *)0x0) {
LAB_081bc8b9:
          EVP_PKEY_assign(param_1,0x198,local_18);
          uVar2 = 1;
          goto LAB_081bc839;
        }
        group = EC_KEY_get0_group(local_18);
        pEVar4 = EC_POINT_new(group);
        if (pEVar4 == (EC_POINT *)0x0) {
          iVar1 = 0x107;
        }
        else {
          src = EC_GROUP_get0_generator(group);
          iVar1 = EC_POINT_copy(pEVar4,src);
          if (iVar1 == 0) {
            EC_POINT_free(pEVar4);
            iVar1 = 0x10c;
          }
          else {
            n = EC_KEY_get0_private_key(local_18);
            iVar1 = EC_POINT_mul(group,pEVar4,n,(EC_POINT *)0x0,(BIGNUM *)0x0,(BN_CTX *)0x0);
            if (iVar1 == 0) {
              EC_POINT_free(pEVar4);
              iVar1 = 0x112;
            }
            else {
              iVar1 = EC_KEY_set_public_key(local_18,pEVar4);
              if (iVar1 != 0) {
                EC_POINT_free(pEVar4);
                goto LAB_081bc8b9;
              }
              EC_POINT_free(pEVar4);
              iVar1 = 0x117;
            }
          }
        }
        ERR_put_error(0x10,0xd5,0x10,"ec_ameth.c",iVar1);
        goto LAB_081bc96d;
      }
      ERR_put_error(0x10,0xd5,0x8e,"ec_ameth.c",0xf7);
    }
    if (local_18 != (EC_KEY *)0x0) {
      EC_KEY_free(local_18);
    }
  }
  uVar2 = 0;
LAB_081bc839:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

