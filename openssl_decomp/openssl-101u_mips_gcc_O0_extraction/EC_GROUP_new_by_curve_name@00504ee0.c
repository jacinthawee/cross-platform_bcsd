
EC_GROUP * EC_GROUP_new_by_curve_name(int nid)

{
  int iVar1;
  BN_CTX *ctx;
  size_t sVar2;
  uchar *s;
  BIGNUM *a;
  BIGNUM *a_00;
  EC_METHOD *meth;
  int *group;
  undefined4 uVar3;
  EC_POINT *p;
  int iVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  code *pcVar7;
  BIGNUM *order;
  int *piVar8;
  uchar *puVar9;
  BIGNUM *x;
  BIGNUM *y;
  BIGNUM *local_3c;
  
  if (nid < 1) {
    return (EC_GROUP *)0x0;
  }
  puVar5 = curve_list;
  iVar1 = 0;
  do {
    iVar4 = *(int *)puVar5;
    puVar5 = (undefined1 *)((int)puVar5 + 0x10);
    if (nid == iVar4) {
      piVar8 = *(int **)(curve_list + iVar1 * 0x10 + 4);
      pcVar7 = *(code **)(curve_list + iVar1 * 0x10 + 8);
      ctx = BN_CTX_new();
      if (ctx == (BN_CTX *)0x0) {
        a_00 = (BIGNUM *)0x0;
        (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xaf,0x41,"ec_curve.c",0x9b1);
        a = (BIGNUM *)0x0;
        group = (int *)0x0;
        local_3c = (BIGNUM *)0x0;
LAB_005050b0:
        y = (BIGNUM *)0x0;
        order = (BIGNUM *)0x0;
        EC_GROUP_free((EC_GROUP *)group);
        x = (BIGNUM *)0x0;
        group = (int *)0x0;
        if (ctx != (BN_CTX *)0x0) goto LAB_005051ec;
      }
      else {
        sVar2 = piVar8[1];
        iVar1 = piVar8[2];
        s = (uchar *)((int)piVar8 + sVar2 + 0x10);
        a = BN_bin2bn(s,iVar1,(BIGNUM *)0x0);
        if (a == (BIGNUM *)0x0) {
LAB_0050507c:
          a_00 = (BIGNUM *)0x0;
LAB_00505080:
          group = (int *)0x0;
          (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xaf,3,"ec_curve.c",0x9be);
          local_3c = (BIGNUM *)0x0;
          goto LAB_005050b0;
        }
        puVar9 = s + iVar1;
        a_00 = BN_bin2bn(puVar9,iVar1,(BIGNUM *)0x0);
        if (a_00 == (BIGNUM *)0x0) goto LAB_0050507c;
        puVar9 = puVar9 + iVar1;
        local_3c = BN_bin2bn(puVar9,iVar1,(BIGNUM *)0x0);
        if (local_3c == (BIGNUM *)0x0) goto LAB_00505080;
        if (pcVar7 != (code *)0x0) {
          meth = (EC_METHOD *)(*pcVar7)();
          group = (int *)EC_GROUP_new(meth);
          if ((group != (int *)0x0) &&
             (iVar4 = (**(code **)(*group + 0x18))(group,a,a_00,local_3c,ctx), iVar4 != 0))
          goto LAB_00505288;
          uVar3 = 0x9c6;
LAB_00505064:
          (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xaf,0x10,"ec_curve.c",uVar3);
          goto LAB_005050b0;
        }
        if (*piVar8 == 0x196) {
          group = (int *)(*(code *)PTR_EC_GROUP_new_curve_GFp_006a8638)(a,a_00,local_3c,ctx);
          if (group != (int *)0x0) goto LAB_00505288;
          uVar3 = 0x9cb;
          goto LAB_00505064;
        }
        group = (int *)(*(code *)PTR_EC_GROUP_new_curve_GF2m_006a8630)(a,a_00,local_3c,ctx);
        if (group == (int *)0x0) {
          uVar3 = 0x9d4;
          goto LAB_00505064;
        }
LAB_00505288:
        p = EC_POINT_new((EC_GROUP *)group);
        if (p == (EC_POINT *)0x0) {
          uVar3 = 0x9db;
          goto LAB_00505064;
        }
        puVar9 = puVar9 + iVar1;
        x = BN_bin2bn(puVar9,iVar1,(BIGNUM *)0x0);
        if (x == (BIGNUM *)0x0) {
LAB_00505198:
          order = (BIGNUM *)0x0;
          (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xaf,3,"ec_curve.c",0x9e1);
          y = (BIGNUM *)0x0;
LAB_005051c8:
          EC_GROUP_free((EC_GROUP *)group);
          group = (int *)0x0;
        }
        else {
          y = BN_bin2bn(puVar9 + iVar1,iVar1,(BIGNUM *)0x0);
          if (y == (BIGNUM *)0x0) goto LAB_00505198;
          iVar4 = EC_POINT_set_affine_coordinates_GFp((EC_GROUP *)group,p,x,y,ctx);
          if (iVar4 == 0) {
            order = (BIGNUM *)0x0;
            (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xaf,0x10,"ec_curve.c",0x9e5);
            goto LAB_005051c8;
          }
          order = BN_bin2bn(puVar9 + iVar1 + iVar1,iVar1,(BIGNUM *)0x0);
          if ((order == (BIGNUM *)0x0) || (iVar1 = BN_set_word(x,piVar8[3]), iVar1 == 0)) {
            uVar6 = 3;
            uVar3 = 0x9ea;
LAB_00505360:
            (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xaf,uVar6,"ec_curve.c",uVar3);
            goto LAB_005051c8;
          }
          iVar1 = EC_GROUP_set_generator((EC_GROUP *)group,p,order,x);
          if (iVar1 == 0) {
            uVar6 = 0x10;
            uVar3 = 0x9ee;
            goto LAB_00505360;
          }
          if ((sVar2 != 0) &&
             (sVar2 = EC_GROUP_set_seed((EC_GROUP *)group,s + -sVar2,sVar2), sVar2 == 0)) {
            uVar6 = 0x10;
            uVar3 = 0x9f3;
            goto LAB_00505360;
          }
        }
        EC_POINT_free(p);
LAB_005051ec:
        BN_CTX_free(ctx);
      }
      if (a != (BIGNUM *)0x0) {
        BN_free(a);
      }
      if (a_00 != (BIGNUM *)0x0) {
        BN_free(a_00);
      }
      if (local_3c != (BIGNUM *)0x0) {
        BN_free(local_3c);
      }
      if (order != (BIGNUM *)0x0) {
        BN_free(order);
      }
      if (x != (BIGNUM *)0x0) {
        BN_free(x);
      }
      if (y != (BIGNUM *)0x0) {
        BN_free(y);
      }
      if (group != (int *)0x0) {
        EC_GROUP_set_curve_name((EC_GROUP *)group,nid);
        return (EC_GROUP *)group;
      }
      break;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 != 0x43);
  (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xae,0x81,"ec_curve.c",0xa1f);
  return (EC_GROUP *)0x0;
}

