
uint ecdh_compute_key(void *param_1,uint param_2,EC_POINT *param_3,EC_KEY *param_4,code *param_5)

{
  uint uVar1;
  BN_CTX *ctx;
  BIGNUM *x;
  BIGNUM *y;
  BIGNUM *m;
  EC_GROUP *group;
  EC_POINT *r;
  void *__s;
  EC_METHOD *meth;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint local_2c [2];
  
  local_2c[0] = param_2;
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
  m = EC_KEY_get0_private_key(param_4);
  if (m == (BIGNUM *)0x0) {
    ERR_put_error(0x2b,100,100,"ech_ossl.c",0x87);
  }
  else {
    group = EC_KEY_get0_group(param_4);
    r = EC_POINT_new(group);
    if (r != (EC_POINT *)0x0) {
      __s = (void *)EC_POINT_mul(group,r,(BIGNUM *)0x0,param_3,m,ctx);
      iVar4 = 0x94;
      if (__s == (void *)0x0) {
LAB_0010b03c:
        uVar5 = 0xffffffff;
        ERR_put_error(0x2b,100,0x65,"ech_ossl.c",iVar4);
      }
      else {
        meth = EC_GROUP_method_of(group);
        iVar4 = EC_METHOD_get_field_type(meth);
        if (iVar4 == 0x196) {
          __s = (void *)EC_POINT_get_affine_coordinates_GFp(group,r,x,y,ctx);
          iVar4 = 0x9c;
          if (__s == (void *)0x0) goto LAB_0010b03c;
        }
        else {
          __s = (void *)EC_POINT_get_affine_coordinates_GF2m();
          if (__s == (void *)0x0) {
            iVar4 = 0xa5;
            goto LAB_0010b03c;
          }
        }
        iVar2 = EC_GROUP_get_degree(group);
        iVar4 = iVar2 + 0xe;
        if (-1 < iVar2 + 7) {
          iVar4 = iVar2 + 7;
        }
        iVar2 = BN_num_bits(x);
        uVar5 = iVar4 >> 3;
        iVar4 = iVar2 + 0xe;
        if (-1 < iVar2 + 7) {
          iVar4 = iVar2 + 7;
        }
        uVar1 = iVar4 >> 3;
        if (uVar5 < uVar1) {
          __s = (void *)0x0;
          ERR_put_error(0x2b,100,0x44,"ech_ossl.c",0xaf);
          uVar5 = 0xffffffff;
        }
        else {
          __s = CRYPTO_malloc(uVar5,"ech_ossl.c",0xb2);
          if (__s == (void *)0x0) {
            uVar5 = 0xffffffff;
            ERR_put_error(0x2b,100,0x41,"ech_ossl.c",0xb4);
          }
          else {
            memset(__s,0,uVar5 - uVar1);
            uVar3 = BN_bn2bin(x,(uchar *)((int)__s + (uVar5 - uVar1)));
            if (uVar3 == uVar1) {
              if (param_5 == (code *)0x0) {
                if (local_2c[0] <= uVar5) {
                  uVar5 = local_2c[0];
                }
                local_2c[0] = uVar5;
                uVar5 = local_2c[0];
                memcpy(param_1,__s,local_2c[0]);
              }
              else {
                iVar4 = (*param_5)(__s,uVar5,param_1,local_2c);
                uVar5 = local_2c[0];
                if (iVar4 == 0) {
                  uVar5 = 0xffffffff;
                  ERR_put_error(0x2b,100,0x66,"ech_ossl.c",0xc3);
                }
              }
            }
            else {
              ERR_put_error(0x2b,100,3,"ech_ossl.c",0xbb);
              uVar5 = 0xffffffff;
            }
          }
        }
      }
      EC_POINT_free(r);
      goto LAB_0010b056;
    }
    ERR_put_error(0x2b,100,0x41,"ech_ossl.c",0x8e);
  }
  uVar5 = 0xffffffff;
  __s = (void *)0x0;
LAB_0010b056:
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
  if (__s != (void *)0x0) {
    CRYPTO_free(__s);
  }
  return uVar5;
}

