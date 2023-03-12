
EC_GROUP * EC_GROUP_new_by_curve_name(int nid)

{
  uchar *s;
  code *pcVar1;
  int iVar2;
  BN_CTX *ctx;
  EC_METHOD *meth;
  int *group;
  EC_POINT *p;
  size_t sVar3;
  int iVar4;
  uchar *puVar5;
  BIGNUM *x;
  int *piVar6;
  BIGNUM *order;
  BIGNUM *local_40;
  BIGNUM *local_3c;
  BIGNUM *local_38;
  BIGNUM *local_34;
  
  iVar2 = 0;
  if (nid < 1) {
    return (EC_GROUP *)0x0;
  }
  do {
    iVar4 = iVar2 * 0x10;
    if (nid == *(int *)(curve_list + iVar4)) {
      piVar6 = *(int **)(curve_list + iVar4 + 4);
      pcVar1 = *(code **)(curve_list + iVar4 + 8);
      ctx = BN_CTX_new();
      if (ctx == (BN_CTX *)0x0) {
        piVar6 = (int *)0x0;
        ERR_put_error(0x10,0xaf,0x41,"ec_curve.c",0x79d);
        local_3c = (BIGNUM *)0x0;
        local_40 = (BIGNUM *)0x0;
        local_38 = (BIGNUM *)0x0;
LAB_08103f58:
        order = (BIGNUM *)0x0;
        x = (BIGNUM *)0x0;
        group = (int *)0x0;
        EC_GROUP_free((EC_GROUP *)piVar6);
        local_34 = (BIGNUM *)0x0;
        if (ctx != (BN_CTX *)0x0) goto LAB_08104057;
      }
      else {
        sVar3 = piVar6[1];
        iVar2 = piVar6[2];
        s = (uchar *)((int)piVar6 + sVar3 + 0x10);
        local_38 = BN_bin2bn(s,iVar2,(BIGNUM *)0x0);
        if (local_38 == (BIGNUM *)0x0) {
LAB_08103f28:
          local_40 = (BIGNUM *)0x0;
LAB_08103f30:
          piVar6 = (int *)0x0;
          ERR_put_error(0x10,0xaf,3,"ec_curve.c",0x7ab);
          local_3c = (BIGNUM *)0x0;
          goto LAB_08103f58;
        }
        puVar5 = s + iVar2;
        local_40 = BN_bin2bn(puVar5,iVar2,(BIGNUM *)0x0);
        if (local_40 == (BIGNUM *)0x0) goto LAB_08103f28;
        puVar5 = puVar5 + iVar2;
        local_3c = BN_bin2bn(puVar5,iVar2,(BIGNUM *)0x0);
        if (local_3c == (BIGNUM *)0x0) goto LAB_08103f30;
        if (pcVar1 != (code *)0x0) {
          meth = (EC_METHOD *)(*pcVar1)();
          group = (int *)EC_GROUP_new(meth);
          if ((group != (int *)0x0) &&
             (iVar4 = (**(code **)(*group + 0x18))(group,local_38,local_40,local_3c,ctx), iVar4 != 0
             )) goto LAB_081040cd;
          iVar2 = 0x7b5;
LAB_08103f0a:
          ERR_put_error(0x10,0xaf,0x10,"ec_curve.c",iVar2);
          piVar6 = group;
          goto LAB_08103f58;
        }
        if (*piVar6 == 0x196) {
          group = (int *)EC_GROUP_new_curve_GFp(local_38,local_40,local_3c,ctx);
          if (group != (int *)0x0) goto LAB_081040cd;
          iVar2 = 0x7bd;
          goto LAB_08103f0a;
        }
        group = (int *)EC_GROUP_new_curve_GF2m(local_38,local_40,local_3c,ctx);
        if (group == (int *)0x0) {
          iVar2 = 0x7c6;
          goto LAB_08103f0a;
        }
LAB_081040cd:
        p = EC_POINT_new((EC_GROUP *)group);
        if (p == (EC_POINT *)0x0) {
          iVar2 = 0x7ce;
          goto LAB_08103f0a;
        }
        puVar5 = puVar5 + iVar2;
        x = BN_bin2bn(puVar5,iVar2,(BIGNUM *)0x0);
        if (x == (BIGNUM *)0x0) {
LAB_08104012:
          order = (BIGNUM *)0x0;
          ERR_put_error(0x10,0xaf,3,"ec_curve.c",0x7d5);
          local_34 = (BIGNUM *)0x0;
LAB_0810403a:
          EC_GROUP_free((EC_GROUP *)group);
          group = (int *)0x0;
        }
        else {
          local_34 = BN_bin2bn(puVar5 + iVar2,iVar2,(BIGNUM *)0x0);
          if (local_34 == (BIGNUM *)0x0) goto LAB_08104012;
          iVar4 = EC_POINT_set_affine_coordinates_GFp((EC_GROUP *)group,p,x,local_34,ctx);
          if (iVar4 == 0) {
            order = (BIGNUM *)0x0;
            ERR_put_error(0x10,0xaf,0x10,"ec_curve.c",0x7da);
            goto LAB_0810403a;
          }
          order = BN_bin2bn(puVar5 + iVar2 + iVar2,iVar2,(BIGNUM *)0x0);
          if ((order == (BIGNUM *)0x0) || (iVar2 = BN_set_word(x,piVar6[3]), iVar2 == 0)) {
            ERR_put_error(0x10,0xaf,3,"ec_curve.c",0x7e0);
            goto LAB_0810403a;
          }
          iVar2 = EC_GROUP_set_generator((EC_GROUP *)group,p,order,x);
          if (iVar2 == 0) {
            iVar2 = 0x7e5;
LAB_08104294:
            ERR_put_error(0x10,0xaf,0x10,"ec_curve.c",iVar2);
            goto LAB_0810403a;
          }
          if ((sVar3 != 0) &&
             (sVar3 = EC_GROUP_set_seed((EC_GROUP *)group,s + -sVar3,sVar3), sVar3 == 0)) {
            iVar2 = 0x7ec;
            goto LAB_08104294;
          }
        }
        EC_POINT_free(p);
LAB_08104057:
        BN_CTX_free(ctx);
      }
      if (local_38 != (BIGNUM *)0x0) {
        BN_free(local_38);
      }
      if (local_40 != (BIGNUM *)0x0) {
        BN_free(local_40);
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
      if (local_34 != (BIGNUM *)0x0) {
        BN_free(local_34);
      }
      if (group != (int *)0x0) {
        EC_GROUP_set_curve_name((EC_GROUP *)group,nid);
        return (EC_GROUP *)group;
      }
      break;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 0x43);
  ERR_put_error(0x10,0xae,0x81,"ec_curve.c",0x81b);
  return (EC_GROUP *)0x0;
}

