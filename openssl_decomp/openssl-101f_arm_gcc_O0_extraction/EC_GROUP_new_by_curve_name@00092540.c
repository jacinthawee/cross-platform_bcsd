
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
      piVar5 = (int *)(&PTR__EC_SECG_PRIME_112R1_0015a20c)[iVar4 * 4];
      pcVar3 = (code *)(&DAT_0015a210)[iVar4 * 4];
      ctx = (BIGNUM *)BN_CTX_new();
      if (ctx == (BIGNUM *)0x0) {
        ERR_put_error(0x10,0xaf,0x41,"ec_curve.c",0x79d);
        group = ctx;
        a = ctx;
        b = ctx;
        local_40 = ctx;
        goto LAB_00092628;
      }
      sVar1 = piVar5[1];
      iVar4 = piVar5[2];
      s = (uchar *)((int)piVar5 + sVar1 + 0x10);
      local_40 = BN_bin2bn(s,iVar4,(BIGNUM *)0x0);
      if (local_40 == (BIGNUM *)0x0) {
LAB_00092608:
        a = (BIGNUM *)0x0;
LAB_0009260a:
        ERR_put_error(0x10,0xaf,3,"ec_curve.c",0x7ab);
        group = (BIGNUM *)0x0;
        b = (BIGNUM *)0x0;
LAB_00092628:
        EC_GROUP_free((EC_GROUP *)group);
        order = ctx;
        x = ctx;
        local_3c = ctx;
        if (ctx != (BIGNUM *)0x0) {
          group = (BIGNUM *)0x0;
          local_3c = (BIGNUM *)0x0;
          order = group;
          x = group;
          goto LAB_0009279a;
        }
      }
      else {
        puVar6 = s + iVar4;
        a = BN_bin2bn(puVar6,iVar4,(BIGNUM *)0x0);
        if (a == (BIGNUM *)0x0) goto LAB_00092608;
        puVar6 = puVar6 + iVar4;
        b = BN_bin2bn(puVar6,iVar4,(BIGNUM *)0x0);
        if (b == (BIGNUM *)0x0) goto LAB_0009260a;
        if (pcVar3 != (code *)0x0) {
          meth = (EC_METHOD *)(*pcVar3)();
          group = (BIGNUM *)EC_GROUP_new(meth);
          if ((group != (BIGNUM *)0x0) &&
             (iVar2 = (*(code *)group->d[6])(group,local_40,a,b,ctx), iVar2 != 0))
          goto LAB_000926c8;
          ERR_put_error(0x10,0xaf,0x10,"ec_curve.c",0x7b5);
          goto LAB_00092628;
        }
        if (*piVar5 == 0x196) {
          group = (BIGNUM *)EC_GROUP_new_curve_GFp(local_40,a,b,(BN_CTX *)ctx);
          if (group != (BIGNUM *)0x0) goto LAB_000926c8;
          ERR_put_error(0x10,0xaf,0x10,"ec_curve.c",0x7bd);
          goto LAB_00092628;
        }
        group = (BIGNUM *)EC_GROUP_new_curve_GF2m();
        if (group == (BIGNUM *)0x0) {
          ERR_put_error(0x10,0xaf,0x10,"ec_curve.c",0x7c6);
          goto LAB_00092628;
        }
LAB_000926c8:
        p = EC_POINT_new((EC_GROUP *)group);
        if (p == (EC_POINT *)0x0) {
          ERR_put_error(0x10,0xaf,0x10,"ec_curve.c",0x7ce);
          goto LAB_00092628;
        }
        puVar6 = puVar6 + iVar4;
        x = BN_bin2bn(puVar6,iVar4,(BIGNUM *)0x0);
        if (x == (BIGNUM *)0x0) {
LAB_00092770:
          order = (BIGNUM *)0x0;
          ERR_put_error(0x10,0xaf,3,"ec_curve.c",0x7d5);
          local_3c = (BIGNUM *)0x0;
LAB_0009278c:
          EC_GROUP_free((EC_GROUP *)group);
          group = (BIGNUM *)0x0;
        }
        else {
          local_3c = BN_bin2bn(puVar6 + iVar4,iVar4,(BIGNUM *)0x0);
          if (local_3c == (BIGNUM *)0x0) goto LAB_00092770;
          order = (BIGNUM *)
                  EC_POINT_set_affine_coordinates_GFp((EC_GROUP *)group,p,x,local_3c,(BN_CTX *)ctx);
          if (order == (BIGNUM *)0x0) {
            ERR_put_error(0x10,0xaf,0x10,"ec_curve.c",0x7da);
            goto LAB_0009278c;
          }
          order = BN_bin2bn(puVar6 + iVar4 + iVar4,iVar4,(BIGNUM *)0x0);
          if ((order == (BIGNUM *)0x0) || (iVar4 = BN_set_word(x,piVar5[3]), iVar4 == 0)) {
            ERR_put_error(0x10,0xaf,3,"ec_curve.c",0x7e0);
            goto LAB_0009278c;
          }
          iVar4 = EC_GROUP_set_generator((EC_GROUP *)group,p,order,x);
          if (iVar4 == 0) {
            ERR_put_error(0x10,0xaf,0x10,"ec_curve.c",0x7e5);
            goto LAB_0009278c;
          }
          if ((sVar1 != 0) &&
             (sVar1 = EC_GROUP_set_seed((EC_GROUP *)group,s + -sVar1,sVar1), sVar1 == 0)) {
            ERR_put_error(0x10,0xaf,0x10,"ec_curve.c",0x7ec);
            goto LAB_0009278c;
          }
        }
        EC_POINT_free(p);
LAB_0009279a:
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
  ERR_put_error(0x10,0xae,0x81,"ec_curve.c",0x81b);
  return (EC_GROUP *)0x0;
}

