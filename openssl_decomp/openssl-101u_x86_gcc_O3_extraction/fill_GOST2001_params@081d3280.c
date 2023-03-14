
undefined4 fill_GOST2001_params(EC_KEY *param_1,int param_2)

{
  BN_CTX *ctx;
  int iVar1;
  EC_GROUP *group;
  EC_POINT *p;
  undefined1 *puVar2;
  undefined4 uVar3;
  int in_GS_OFFSET;
  undefined4 uVar4;
  BIGNUM *local_38;
  BIGNUM *local_34;
  BIGNUM *local_30;
  BIGNUM *local_2c;
  BIGNUM *local_28;
  BIGNUM *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_38 = (BIGNUM *)0x0;
  local_34 = (BIGNUM *)0x0;
  local_30 = (BIGNUM *)0x0;
  local_2c = (BIGNUM *)0x0;
  local_28 = (BIGNUM *)0x0;
  local_24 = (BIGNUM *)0x0;
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    uVar3 = 0;
    ERR_GOST_error(0x65,0x41,"gost2001.c",0x2d);
  }
  else {
    BN_CTX_start(ctx);
    local_38 = BN_CTX_get(ctx);
    local_30 = BN_CTX_get(ctx);
    local_2c = BN_CTX_get(ctx);
    local_28 = BN_CTX_get(ctx);
    local_24 = BN_CTX_get(ctx);
    local_34 = BN_CTX_get(ctx);
    if ((((local_38 == (BIGNUM *)0x0) || (local_30 == (BIGNUM *)0x0)) || (local_2c == (BIGNUM *)0x0)
        ) || (((local_28 == (BIGNUM *)0x0 || (local_24 == (BIGNUM *)0x0)) ||
              (local_34 == (BIGNUM *)0x0)))) {
      uVar3 = 0x39;
LAB_081d33ea:
      ERR_GOST_error(0x65,0x41,"gost2001.c",uVar3);
    }
    else {
      if (R3410_2001_paramset._0_4_ != 0) {
        puVar2 = R3410_2001_paramset;
        iVar1 = R3410_2001_paramset._0_4_;
        do {
          if (param_2 == iVar1) {
            iVar1 = BN_hex2bn(&local_38,*(char **)((int)puVar2 + 0xc));
            if (((iVar1 == 0) ||
                (iVar1 = BN_hex2bn(&local_30,*(char **)((int)puVar2 + 4)), iVar1 == 0)) ||
               (iVar1 = BN_hex2bn(&local_2c,*(char **)((int)puVar2 + 8)), iVar1 == 0)) {
              ERR_GOST_error(0x65,0x44,"gost2001.c",0x47);
              goto LAB_081d33b0;
            }
            group = EC_GROUP_new_curve_GFp(local_38,local_30,local_2c,ctx);
            if (group == (EC_GROUP *)0x0) {
              uVar3 = 0x4d;
              goto LAB_081d33ea;
            }
            p = EC_POINT_new(group);
            if (p == (EC_POINT *)0x0) {
              uVar3 = 0;
              ERR_GOST_error(0x65,0x41,"gost2001.c",0x53);
            }
            else {
              iVar1 = BN_hex2bn(&local_28,*(char **)((int)puVar2 + 0x14));
              if ((((iVar1 == 0) ||
                   (iVar1 = BN_hex2bn(&local_24,*(char **)((int)puVar2 + 0x18)), iVar1 == 0)) ||
                  (iVar1 = EC_POINT_set_affine_coordinates_GFp(group,p,local_28,local_24,ctx),
                  iVar1 == 0)) ||
                 (iVar1 = BN_hex2bn(&local_34,*(char **)((int)puVar2 + 0x10)), iVar1 == 0)) {
                uVar4 = 0x5b;
LAB_081d34e8:
                uVar3 = 0;
                ERR_GOST_error(0x65,0x44,"gost2001.c",uVar4);
              }
              else {
                iVar1 = EC_GROUP_set_generator(group,p,local_34,(BIGNUM *)0x0);
                if (iVar1 == 0) {
                  uVar4 = 0x66;
                  goto LAB_081d34e8;
                }
                uVar3 = 1;
                EC_GROUP_set_curve_name(group,*(int *)puVar2);
                iVar1 = EC_KEY_set_group(param_1,group);
                if (iVar1 == 0) {
                  uVar4 = 0x6b;
                  goto LAB_081d34e8;
                }
              }
              EC_POINT_free(p);
            }
            EC_GROUP_free(group);
            goto LAB_081d33b2;
          }
          puVar2 = (undefined1 *)((int)puVar2 + 0x1c);
          iVar1 = *(int *)puVar2;
        } while (iVar1 != 0);
      }
      ERR_GOST_error(0x65,0x82,"gost2001.c",0x40);
    }
LAB_081d33b0:
    uVar3 = 0;
LAB_081d33b2:
    BN_CTX_end(ctx);
    BN_CTX_free(ctx);
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}
