
size_t ecdh_compute_key(void *param_1,uint param_2,EC_POINT *param_3,EC_KEY *param_4,code *param_5)

{
  EC_KEY *key;
  BN_CTX *ctx;
  BIGNUM *x;
  BIGNUM *y;
  BIGNUM *m;
  EC_GROUP *group;
  EC_POINT *r;
  int iVar1;
  EC_METHOD *meth;
  uint uVar2;
  uint uVar3;
  void *__s;
  size_t sVar4;
  uint num;
  int iVar5;
  
  key = param_4;
  if ((int)param_2 < 0) {
    ERR_put_error(0x2b,100,0x41,"ech_ossl.c",0x7b);
    return 0xffffffff;
  }
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    return 0xffffffff;
  }
  BN_CTX_start(ctx);
  x = BN_CTX_get(ctx);
  y = BN_CTX_get(ctx);
  m = EC_KEY_get0_private_key(key);
  if (m == (BIGNUM *)0x0) {
    ERR_put_error(0x2b,100,100,"ech_ossl.c",0x88);
LAB_081c588b:
    BN_CTX_end(ctx);
    BN_CTX_free(ctx);
    return 0xffffffff;
  }
  group = EC_KEY_get0_group(key);
  r = EC_POINT_new(group);
  if (r == (EC_POINT *)0x0) {
    ERR_put_error(0x2b,100,0x41,"ech_ossl.c",0x8e);
    goto LAB_081c588b;
  }
  iVar1 = EC_POINT_mul(group,r,(BIGNUM *)0x0,param_3,m,ctx);
  if (iVar1 == 0) {
    iVar5 = 0x93;
    iVar1 = 0x65;
  }
  else {
    meth = EC_GROUP_method_of(group);
    iVar1 = EC_METHOD_get_field_type(meth);
    if (iVar1 == 0x196) {
      iVar1 = EC_POINT_get_affine_coordinates_GFp(group,r,x,y,ctx);
      if (iVar1 != 0) goto LAB_081c581d;
      iVar5 = 0x9a;
      iVar1 = 0x65;
    }
    else {
      iVar1 = EC_POINT_get_affine_coordinates_GF2m(group,r,x,y,ctx);
      if (iVar1 == 0) {
        iVar5 = 0xa1;
        iVar1 = 0x65;
      }
      else {
LAB_081c581d:
        iVar5 = EC_GROUP_get_degree(group);
        iVar1 = iVar5 + 0xe;
        if (-1 < iVar5 + 7) {
          iVar1 = iVar5 + 7;
        }
        iVar5 = BN_num_bits(x);
        num = iVar1 >> 3;
        iVar1 = iVar5 + 0xe;
        if (-1 < iVar5 + 7) {
          iVar1 = iVar5 + 7;
        }
        uVar3 = iVar1 >> 3;
        if (uVar3 <= num) {
          __s = CRYPTO_malloc(num,"ech_ossl.c",0xad);
          if (__s == (void *)0x0) {
            iVar5 = 0xae;
            iVar1 = 0x41;
          }
          else {
            memset(__s,0,num - uVar3);
            uVar2 = BN_bn2bin(x,(uchar *)((num - uVar3) + (int)__s));
            if (uVar3 == uVar2) {
              if (param_5 == (code *)0x0) {
                if (num < param_2) {
                  param_2 = num;
                }
                sVar4 = param_2;
                memcpy(param_1,__s,param_2);
                goto LAB_081c579c;
              }
              iVar1 = (*param_5)(__s,num,param_1,&param_2);
              sVar4 = param_2;
              if (iVar1 != 0) goto LAB_081c579c;
              iVar5 = 0xba;
              iVar1 = 0x66;
            }
            else {
              iVar5 = 0xb4;
              iVar1 = 3;
            }
          }
          ERR_put_error(0x2b,100,iVar1,"ech_ossl.c",iVar5);
          sVar4 = 0xffffffff;
          goto LAB_081c579c;
        }
        iVar5 = 0xaa;
        iVar1 = 0x44;
      }
    }
  }
  __s = (void *)0x0;
  ERR_put_error(0x2b,100,iVar1,"ech_ossl.c",iVar5);
  sVar4 = 0xffffffff;
LAB_081c579c:
  EC_POINT_free(r);
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
  if (__s != (void *)0x0) {
    CRYPTO_free(__s);
  }
  return sVar4;
}

