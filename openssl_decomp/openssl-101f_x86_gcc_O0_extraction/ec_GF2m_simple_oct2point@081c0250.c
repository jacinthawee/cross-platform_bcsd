
int ec_GF2m_simple_oct2point
              (int *param_1,EC_POINT *param_2,byte *param_3,int param_4,BN_CTX *param_5)

{
  byte bVar1;
  byte bVar2;
  BIGNUM *pBVar3;
  uint uVar4;
  BN_CTX *ctx;
  int iVar5;
  int iVar6;
  BIGNUM *local_34;
  BIGNUM *local_28;
  BIGNUM *local_24;
  
  if (param_4 == 0) {
    iVar6 = 0x135;
    iVar5 = 100;
    goto LAB_081c02ca;
  }
  bVar1 = *param_3;
  bVar2 = bVar1 & 0xfe;
  if ((bVar1 & 0xf8) == 0) {
    if ((bVar1 & 0xfa) == 0) {
      if ((bVar1 & 1) == 0) {
        if ((bVar1 & 0xfe) != 0) goto LAB_081c0300;
        if (param_4 == 1) {
          iVar5 = EC_POINT_set_to_infinity((EC_GROUP *)param_1,param_2);
          return iVar5;
        }
        iVar6 = 0x14c;
      }
      else {
        iVar6 = 0x144;
      }
    }
    else {
LAB_081c0300:
      iVar6 = EC_GROUP_get_degree((EC_GROUP *)param_1);
      iVar5 = iVar6 + 7;
      if (iVar6 + 7 < 0) {
        iVar5 = iVar6 + 0xe;
      }
      iVar5 = iVar5 >> 3;
      iVar6 = iVar5 * 2;
      if (bVar2 == 2) {
        iVar6 = iVar5;
      }
      if (iVar6 + 1 == param_4) {
        if (param_5 == (BN_CTX *)0x0) {
          ctx = BN_CTX_new();
          if (ctx == (BN_CTX *)0x0) {
            return 0;
          }
          BN_CTX_start(ctx);
          local_34 = BN_CTX_get(ctx);
          local_28 = BN_CTX_get(ctx);
          local_24 = BN_CTX_get(ctx);
          if ((local_24 == (BIGNUM *)0x0) ||
             (pBVar3 = BN_bin2bn(param_3 + 1,iVar5,local_34), param_5 = ctx, pBVar3 == (BIGNUM *)0x0
             )) {
            iVar5 = 0;
            BN_CTX_end(ctx);
            goto LAB_081c0408;
          }
        }
        else {
          BN_CTX_start(param_5);
          local_34 = BN_CTX_get(param_5);
          local_28 = BN_CTX_get(param_5);
          local_24 = BN_CTX_get(param_5);
          if ((local_24 == (BIGNUM *)0x0) ||
             (pBVar3 = BN_bin2bn(param_3 + 1,iVar5,local_34), pBVar3 == (BIGNUM *)0x0)) {
            BN_CTX_end(param_5);
            return 0;
          }
          ctx = (BN_CTX *)0x0;
        }
        iVar6 = BN_ucmp(local_34,(BIGNUM *)(param_1 + 0x12));
        if (iVar6 < 0) {
          if (bVar2 != 2) {
            pBVar3 = BN_bin2bn(param_3 + iVar5 + 1,iVar5,local_28);
            if (pBVar3 != (BIGNUM *)0x0) {
              iVar5 = BN_ucmp(local_28,(BIGNUM *)(param_1 + 0x12));
              if (-1 < iVar5) {
                iVar6 = 0x179;
                iVar5 = 0x66;
                goto LAB_081c03e3;
              }
              if (bVar2 == 6) {
                iVar5 = (**(code **)(*param_1 + 0x8c))(param_1,local_24,local_28,local_34,param_5);
                if (iVar5 == 0) goto LAB_081c03f2;
                if (local_24->top < 1) {
                  uVar4 = 0;
                }
                else {
                  uVar4 = *local_24->d & 1;
                }
                if (uVar4 != (bVar1 & 1)) {
                  iVar6 = 0x181;
                  iVar5 = 0x66;
                  goto LAB_081c03e3;
                }
              }
              iVar5 = EC_POINT_set_affine_coordinates_GF2m
                                (param_1,param_2,local_34,local_28,param_5);
              if (iVar5 != 0) goto LAB_081c04de;
            }
            goto LAB_081c03f2;
          }
          iVar5 = EC_POINT_set_compressed_coordinates_GF2m
                            (param_1,param_2,local_34,bVar1 & 1,param_5);
          if (iVar5 == 0) goto LAB_081c03f2;
LAB_081c04de:
          iVar5 = 1;
          iVar6 = EC_POINT_is_on_curve((EC_GROUP *)param_1,param_2,param_5);
          if (iVar6 == 0) {
            iVar6 = 0x18b;
            iVar5 = 0x6b;
            goto LAB_081c03e3;
          }
        }
        else {
          iVar6 = 0x16c;
          iVar5 = 0x66;
LAB_081c03e3:
          ERR_put_error(0x10,0xa0,iVar5,"ec2_oct.c",iVar6);
LAB_081c03f2:
          iVar5 = 0;
        }
        BN_CTX_end(param_5);
        if (ctx == (BN_CTX *)0x0) {
          return iVar5;
        }
LAB_081c0408:
        BN_CTX_free(ctx);
        return iVar5;
      }
      iVar6 = 0x158;
    }
  }
  else {
    iVar6 = 0x13f;
  }
  iVar5 = 0x66;
LAB_081c02ca:
  ERR_put_error(0x10,0xa0,iVar5,"ec2_oct.c",iVar6);
  return 0;
}

