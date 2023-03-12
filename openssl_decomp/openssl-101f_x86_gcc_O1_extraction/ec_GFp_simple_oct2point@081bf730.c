
int ec_GFp_simple_oct2point
              (EC_GROUP *param_1,EC_POINT *param_2,byte *param_3,int param_4,BN_CTX *param_5)

{
  BIGNUM *a;
  byte bVar1;
  byte bVar2;
  BIGNUM *pBVar3;
  uint uVar4;
  BN_CTX *ctx;
  int iVar5;
  int iVar6;
  BIGNUM *local_30;
  BIGNUM *local_20;
  
  if (param_4 == 0) {
    iVar6 = 0x151;
    iVar5 = 100;
    goto LAB_081bf7ab;
  }
  bVar1 = *param_3;
  bVar2 = bVar1 & 0xfe;
  if ((bVar1 & 0xf8) == 0) {
    if ((bVar1 & 0xfa) == 0) {
      if ((bVar1 & 1) == 0) {
        if ((bVar1 & 0xfe) != 0) goto LAB_081bf7e0;
        if (param_4 == 1) {
          iVar5 = EC_POINT_set_to_infinity(param_1,param_2);
          return iVar5;
        }
        iVar6 = 0x168;
      }
      else {
        iVar6 = 0x160;
      }
    }
    else {
LAB_081bf7e0:
      a = (BIGNUM *)(param_1 + 0x48);
      iVar6 = BN_num_bits(a);
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
          local_30 = BN_CTX_get(ctx);
          local_20 = BN_CTX_get(ctx);
          if ((local_20 == (BIGNUM *)0x0) ||
             (pBVar3 = BN_bin2bn(param_3 + 1,iVar5,local_30), param_5 = ctx, pBVar3 == (BIGNUM *)0x0
             )) {
            iVar5 = 0;
            BN_CTX_end(ctx);
            goto LAB_081bf8dd;
          }
        }
        else {
          BN_CTX_start(param_5);
          local_30 = BN_CTX_get(param_5);
          local_20 = BN_CTX_get(param_5);
          if ((local_20 == (BIGNUM *)0x0) ||
             (pBVar3 = BN_bin2bn(param_3 + 1,iVar5,local_30), pBVar3 == (BIGNUM *)0x0)) {
            BN_CTX_end(param_5);
            return 0;
          }
          ctx = (BN_CTX *)0x0;
        }
        iVar6 = BN_ucmp(local_30,a);
        if (-1 < iVar6) {
          iVar6 = 0x187;
          iVar5 = 0x66;
          goto LAB_081bf8bb;
        }
        if (bVar2 == 2) {
          iVar5 = EC_POINT_set_compressed_coordinates_GFp
                            (param_1,param_2,local_30,bVar1 & 1,param_5);
          if (iVar5 == 0) goto LAB_081bf8c7;
LAB_081bfa58:
          iVar5 = 1;
          iVar6 = EC_POINT_is_on_curve(param_1,param_2,param_5);
          if (iVar6 == 0) {
            iVar6 = 0x1a5;
            iVar5 = 0x6b;
LAB_081bf8bb:
            ERR_put_error(0x10,0x67,iVar5,"ecp_oct.c",iVar6);
            goto LAB_081bf8c7;
          }
        }
        else {
          pBVar3 = BN_bin2bn(param_3 + iVar5 + 1,iVar5,local_20);
          if (pBVar3 != (BIGNUM *)0x0) {
            iVar5 = BN_ucmp(local_20,a);
            if (-1 < iVar5) {
              iVar6 = 0x194;
              iVar5 = 0x66;
              goto LAB_081bf8bb;
            }
            if (bVar2 == 6) {
              uVar4 = 0;
              if (0 < local_20->top) {
                uVar4 = *local_20->d & 1;
              }
              if (uVar4 != (bVar1 & 1)) {
                iVar6 = 0x19b;
                iVar5 = 0x66;
                goto LAB_081bf8bb;
              }
            }
            iVar5 = EC_POINT_set_affine_coordinates_GFp(param_1,param_2,local_30,local_20,param_5);
            if (iVar5 != 0) goto LAB_081bfa58;
          }
LAB_081bf8c7:
          iVar5 = 0;
        }
        BN_CTX_end(param_5);
        if (ctx == (BN_CTX *)0x0) {
          return iVar5;
        }
LAB_081bf8dd:
        BN_CTX_free(ctx);
        return iVar5;
      }
      iVar6 = 0x174;
    }
  }
  else {
    iVar6 = 0x15b;
  }
  iVar5 = 0x66;
LAB_081bf7ab:
  ERR_put_error(0x10,0x67,iVar5,"ecp_oct.c",iVar6);
  return 0;
}

