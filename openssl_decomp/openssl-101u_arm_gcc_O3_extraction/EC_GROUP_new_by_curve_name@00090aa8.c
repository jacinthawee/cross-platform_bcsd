
EC_GROUP * EC_GROUP_new_by_curve_name(int nid)

{
  BIGNUM *ctx;
  BIGNUM *a;
  BIGNUM *b;
  EC_METHOD *meth;
  BIGNUM *group;
  EC_POINT *p;
  BIGNUM *x;
  BIGNUM *order;
  size_t sVar1;
  uchar *s;
  int iVar2;
  code *pcVar3;
  int iVar4;
  int *piVar5;
  uchar *puVar6;
  BIGNUM *local_40;
  BIGNUM *local_3c;
  
  if (nid < 1) {
    return (EC_GROUP *)0x0;
  }
  iVar4 = 0;
  do {
    iVar2 = iVar4 + 1;
    if ((&curve_list)[iVar4 * 4] == nid) {
      piVar5 = (int *)(&PTR__EC_SECG_PRIME_112R1_00158dd0)[iVar4 * 4];
      pcVar3 = (code *)(&DAT_00158dd4)[iVar4 * 4];
      ctx = (BIGNUM *)BN_CTX_new();
      if (ctx == (BIGNUM *)0x0) {
        ERR_put_error(0x10,0xaf,0x41,"ec_curve.c",0x9b1);
        group = ctx;
        a = ctx;
        b = ctx;
        local_40 = ctx;
        goto LAB_00090b90;
      }
      sVar1 = piVar5[1];
      iVar4 = piVar5[2];
      s = (uchar *)((int)piVar5 + sVar1 + 0x10);
      local_40 = BN_bin2bn(s,iVar4,(BIGNUM *)0x0);
      if (local_40 == (BIGNUM *)0x0) {
LAB_00090b70:
        a = (BIGNUM *)0x0;
LAB_00090b72:
        ERR_put_error(0x10,0xaf,3,"ec_curve.c",0x9be);
        group = (BIGNUM *)0x0;
        b = (BIGNUM *)0x0;
LAB_00090b90:
        EC_GROUP_free((EC_GROUP *)group);
        order = ctx;
        x = ctx;
        local_3c = ctx;
        if (ctx != (BIGNUM *)0x0) {
          group = (BIGNUM *)0x0;
          local_3c = (BIGNUM *)0x0;
          order = group;
          x = group;
          goto LAB_00090d02;
        }
      }
      else {
        puVar6 = s + iVar4;
        a = BN_bin2bn(puVar6,iVar4,(BIGNUM *)0x0);
        if (a == (BIGNUM *)0x0) goto LAB_00090b70;
        puVar6 = puVar6 + iVar4;
        b = BN_bin2bn(puVar6,iVar4,(BIGNUM *)0x0);
        if (b == (BIGNUM *)0x0) goto LAB_00090b72;
        if (pcVar3 != (code *)0x0) {
          meth = (EC_METHOD *)(*pcVar3)();
          group = (BIGNUM *)EC_GROUP_new(meth);
          if ((group != (BIGNUM *)0x0) &&
             (iVar2 = (*(code *)group->d[6])(group,local_40,a,b,ctx), iVar2 != 0))
          goto LAB_00090c30;
          ERR_put_error(0x10,0xaf,0x10,"ec_curve.c",0x9c6);
          goto LAB_00090b90;
        }
        if (*piVar5 == 0x196) {
          group = (BIGNUM *)EC_GROUP_new_curve_GFp(local_40,a,b,(BN_CTX *)ctx);
          if (group != (BIGNUM *)0x0) goto LAB_00090c30;
          ERR_put_error(0x10,0xaf,0x10,"ec_curve.c",0x9cb);
          goto LAB_00090b90;
        }
        group = (BIGNUM *)EC_GROUP_new_curve_GF2m();
        if (group == (BIGNUM *)0x0) {
          ERR_put_error(0x10,0xaf,0x10,"ec_curve.c",0x9d4);
          goto LAB_00090b90;
        }
LAB_00090c30:
        p = EC_POINT_new((EC_GROUP *)group);
        if (p == (EC_POINT *)0x0) {
          ERR_put_error(0x10,0xaf,0x10,"ec_curve.c",0x9db);
          goto LAB_00090b90;
        }
        puVar6 = puVar6 + iVar4;
        x = BN_bin2bn(puVar6,iVar4,(BIGNUM *)0x0);
        if (x == (BIGNUM *)0x0) {
LAB_00090cd8:
          order = (BIGNUM *)0x0;
          ERR_put_error(0x10,0xaf,3,"ec_curve.c",0x9e1);
          local_3c = (BIGNUM *)0x0;
LAB_00090cf4:
          EC_GROUP_free((EC_GROUP *)group);
          group = (BIGNUM *)0x0;
        }
        else {
          local_3c = BN_bin2bn(puVar6 + iVar4,iVar4,(BIGNUM *)0x0);
          if (local_3c == (BIGNUM *)0x0) goto LAB_00090cd8;
          order = (BIGNUM *)
                  EC_POINT_set_affine_coordinates_GFp((EC_GROUP *)group,p,x,local_3c,(BN_CTX *)ctx);
          if (order == (BIGNUM *)0x0) {
            ERR_put_error(0x10,0xaf,0x10,"ec_curve.c",0x9e5);
            goto LAB_00090cf4;
          }
          order = BN_bin2bn(puVar6 + iVar4 + iVar4,iVar4,(BIGNUM *)0x0);
          if ((order == (BIGNUM *)0x0) || (iVar4 = BN_set_word(x,piVar5[3]), iVar4 == 0)) {
            ERR_put_error(0x10,0xaf,3,"ec_curve.c",0x9ea);
            goto LAB_00090cf4;
          }
          iVar4 = EC_GROUP_set_generator((EC_GROUP *)group,p,order,x);
          if (iVar4 == 0) {
            ERR_put_error(0x10,0xaf,0x10,"ec_curve.c",0x9ee);
            goto LAB_00090cf4;
          }
          if ((sVar1 != 0) &&
             (sVar1 = EC_GROUP_set_seed((EC_GROUP *)group,s + -sVar1,sVar1), sVar1 == 0)) {
            ERR_put_error(0x10,0xaf,0x10,"ec_curve.c",0x9f3);
            goto LAB_00090cf4;
          }
        }
        EC_POINT_free(p);
LAB_00090d02:
        BN_CTX_free((BN_CTX *)ctx);
        ctx = group;
      }
      if (local_40 != (BIGNUM *)0x0) {
        BN_free(local_40);
      }
      if (a != (BIGNUM *)0x0) {
        BN_free(a);
      }
      if (b != (BIGNUM *)0x0) {
        BN_free(b);
      }
      if (order != (BIGNUM *)0x0) {
        BN_free(order);
      }
      if (x != (BIGNUM *)0x0) {
        BN_free(x);
      }
      if (local_3c != (BIGNUM *)0x0) {
        BN_free(local_3c);
      }
      if (ctx != (BIGNUM *)0x0) {
        EC_GROUP_set_curve_name((EC_GROUP *)ctx,nid);
        return (EC_GROUP *)ctx;
      }
      break;
    }
    iVar4 = iVar2;
  } while (iVar2 != 0x43);
  ERR_put_error(0x10,0xae,0x81,"ec_curve.c",0xa1f);
  return (EC_GROUP *)0x0;
}

