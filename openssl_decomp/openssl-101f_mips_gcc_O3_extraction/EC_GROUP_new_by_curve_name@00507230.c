
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
        (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xaf,0x41,"ec_curve.c",0x79d);
        a = (BIGNUM *)0x0;
        group = (int *)0x0;
        local_3c = (BIGNUM *)0x0;
LAB_00507400:
        y = (BIGNUM *)0x0;
        order = (BIGNUM *)0x0;
        EC_GROUP_free((EC_GROUP *)group);
        x = (BIGNUM *)0x0;
        group = (int *)0x0;
        if (ctx != (BN_CTX *)0x0) goto LAB_0050753c;
      }
      else {
        sVar2 = piVar8[1];
        iVar1 = piVar8[2];
        s = (uchar *)((int)piVar8 + sVar2 + 0x10);
        a = BN_bin2bn(s,iVar1,(BIGNUM *)0x0);
        if (a == (BIGNUM *)0x0) {
LAB_005073cc:
          a_00 = (BIGNUM *)0x0;
LAB_005073d0:
          group = (int *)0x0;
          (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xaf,3,"ec_curve.c",0x7ab);
          local_3c = (BIGNUM *)0x0;
          goto LAB_00507400;
        }
        puVar9 = s + iVar1;
        a_00 = BN_bin2bn(puVar9,iVar1,(BIGNUM *)0x0);
        if (a_00 == (BIGNUM *)0x0) goto LAB_005073cc;
        puVar9 = puVar9 + iVar1;
        local_3c = BN_bin2bn(puVar9,iVar1,(BIGNUM *)0x0);
        if (local_3c == (BIGNUM *)0x0) goto LAB_005073d0;
        if (pcVar7 != (code *)0x0) {
          meth = (EC_METHOD *)(*pcVar7)();
          group = (int *)EC_GROUP_new(meth);
          if ((group != (int *)0x0) &&
             (iVar4 = (**(code **)(*group + 0x18))(group,a,a_00,local_3c,ctx), iVar4 != 0))
          goto LAB_005075d8;
          uVar3 = 0x7b5;
LAB_005073b4:
          (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xaf,0x10,"ec_curve.c",uVar3);
          goto LAB_00507400;
        }
        if (*piVar8 == 0x196) {
          group = (int *)(*(code *)PTR_EC_GROUP_new_curve_GFp_006a975c)(a,a_00,local_3c,ctx);
          if (group != (int *)0x0) goto LAB_005075d8;
          uVar3 = 0x7bd;
          goto LAB_005073b4;
        }
        group = (int *)(*(code *)PTR_EC_GROUP_new_curve_GF2m_006a9754)(a,a_00,local_3c,ctx);
        if (group == (int *)0x0) {
          uVar3 = 0x7c6;
          goto LAB_005073b4;
        }
LAB_005075d8:
        p = EC_POINT_new((EC_GROUP *)group);
        if (p == (EC_POINT *)0x0) {
          uVar3 = 0x7ce;
          goto LAB_005073b4;
        }
        puVar9 = puVar9 + iVar1;
        x = BN_bin2bn(puVar9,iVar1,(BIGNUM *)0x0);
        if (x == (BIGNUM *)0x0) {
LAB_005074e8:
          order = (BIGNUM *)0x0;
          (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xaf,3,"ec_curve.c",0x7d5);
          y = (BIGNUM *)0x0;
LAB_00507518:
          EC_GROUP_free((EC_GROUP *)group);
          group = (int *)0x0;
        }
        else {
          y = BN_bin2bn(puVar9 + iVar1,iVar1,(BIGNUM *)0x0);
          if (y == (BIGNUM *)0x0) goto LAB_005074e8;
          iVar4 = EC_POINT_set_affine_coordinates_GFp((EC_GROUP *)group,p,x,y,ctx);
          if (iVar4 == 0) {
            order = (BIGNUM *)0x0;
            (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xaf,0x10,"ec_curve.c",0x7da);
            goto LAB_00507518;
          }
          order = BN_bin2bn(puVar9 + iVar1 + iVar1,iVar1,(BIGNUM *)0x0);
          if ((order == (BIGNUM *)0x0) || (iVar1 = BN_set_word(x,piVar8[3]), iVar1 == 0)) {
            uVar6 = 3;
            uVar3 = 0x7e0;
LAB_005076b0:
            (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xaf,uVar6,"ec_curve.c",uVar3);
            goto LAB_00507518;
          }
          iVar1 = EC_GROUP_set_generator((EC_GROUP *)group,p,order,x);
          if (iVar1 == 0) {
            uVar6 = 0x10;
            uVar3 = 0x7e5;
            goto LAB_005076b0;
          }
          if ((sVar2 != 0) &&
             (sVar2 = EC_GROUP_set_seed((EC_GROUP *)group,s + -sVar2,sVar2), sVar2 == 0)) {
            uVar6 = 0x10;
            uVar3 = 0x7ec;
            goto LAB_005076b0;
          }
        }
        EC_POINT_free(p);
LAB_0050753c:
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
  (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xae,0x81,"ec_curve.c",0x81b);
  return (EC_GROUP *)0x0;
}

