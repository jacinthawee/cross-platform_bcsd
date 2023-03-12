
EC_POINT *
ec_GF2m_simple_mul(int *param_1,EC_POINT *param_2,int param_3,uint param_4,int param_5,int param_6,
                  BN_CTX *param_7)

{
  int *piVar1;
  EC_POINT *point;
  int iVar2;
  EC_POINT *point_00;
  EC_POINT *pEVar3;
  int iVar4;
  BN_CTX *c;
  
  c = (BN_CTX *)0x0;
  if ((param_7 != (BN_CTX *)0x0) ||
     (point = (EC_POINT *)BN_CTX_new(), param_7 = (BN_CTX *)point, c = (BN_CTX *)point,
     point != (EC_POINT *)0x0)) {
    iVar4 = param_3;
    if (param_3 != 0) {
      iVar4 = 1;
    }
    if ((((param_3 == 0 || param_4 != 0) && (param_3 != 0 && param_4 != 1)) || (2 < param_4)) ||
       ((param_4 == 0 && (iVar2 = EC_GROUP_have_precompute_mult((EC_GROUP *)param_1), iVar2 != 0))))
    {
      point = (EC_POINT *)ec_wNAF_mul(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    }
    else {
      point = EC_POINT_new((EC_GROUP *)param_1);
      if (point != (EC_POINT *)0x0) {
        point_00 = EC_POINT_new((EC_GROUP *)param_1);
        if (point_00 == (EC_POINT *)0x0) {
          EC_POINT_free(point);
          point = point_00;
        }
        else {
          pEVar3 = (EC_POINT *)EC_POINT_set_to_infinity((EC_GROUP *)param_1,point_00);
          if ((pEVar3 != (EC_POINT *)0x0) &&
             ((iVar4 == 0 ||
              ((pEVar3 = (EC_POINT *)
                         ec_GF2m_montgomery_point_multiply(param_1,point,param_3,param_1[1],param_7)
               , pEVar3 != (EC_POINT *)0x0 &&
               (((*(int *)(param_3 + 0xc) == 0 ||
                 (pEVar3 = (EC_POINT *)(**(code **)(*param_1 + 0x60))(param_1,point,param_7),
                 pEVar3 != (EC_POINT *)0x0)) &&
                (pEVar3 = (EC_POINT *)
                          (**(code **)(*param_1 + 0x58))(param_1,point_00,point_00,point,param_7),
                pEVar3 != (EC_POINT *)0x0)))))))) {
            if (param_4 != 0) {
              iVar4 = 0;
              do {
                pEVar3 = (EC_POINT *)
                         ec_GF2m_montgomery_point_multiply
                                   (param_1,point,*(undefined4 *)(param_6 + iVar4),
                                    *(undefined4 *)(param_5 + iVar4),param_7);
                if (((pEVar3 == (EC_POINT *)0x0) ||
                    ((piVar1 = (int *)(param_6 + iVar4), iVar4 = iVar4 + 4,
                     *(int *)(*piVar1 + 0xc) != 0 &&
                     (pEVar3 = (EC_POINT *)(**(code **)(*param_1 + 0x60))(param_1,point,param_7),
                     pEVar3 == (EC_POINT *)0x0)))) ||
                   (pEVar3 = (EC_POINT *)
                             (**(code **)(*param_1 + 0x58))(param_1,point_00,point_00,point,param_7)
                   , pEVar3 == (EC_POINT *)0x0)) goto LAB_00103af4;
              } while (iVar4 != param_4 * 4);
            }
            pEVar3 = (EC_POINT *)EC_POINT_copy(param_2,point_00);
            if (pEVar3 != (EC_POINT *)0x0) {
              pEVar3 = (EC_POINT *)0x1;
            }
          }
LAB_00103af4:
          EC_POINT_free(point);
          EC_POINT_free(point_00);
          point = pEVar3;
        }
      }
    }
    if (c != (BN_CTX *)0x0) {
      BN_CTX_free(c);
      return point;
    }
  }
  return point;
}

