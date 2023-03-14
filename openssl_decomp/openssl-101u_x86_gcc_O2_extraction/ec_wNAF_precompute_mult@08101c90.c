
bool ec_wNAF_precompute_mult(EC_GROUP *param_1,BN_CTX *param_2)

{
  EC_GROUP **ptr;
  EC_POINT *pEVar1;
  BIGNUM *order;
  int iVar2;
  uint uVar3;
  EC_GROUP *pEVar4;
  EC_GROUP *num;
  EC_POINT **points;
  EC_POINT *pEVar5;
  int iVar6;
  int iVar7;
  EC_GROUP *pEVar8;
  EC_POINT **ppEVar9;
  bool bVar10;
  BN_CTX *local_50;
  EC_POINT *local_4c;
  EC_POINT *local_48;
  EC_POINT **local_40;
  EC_GROUP *local_38;
  EC_GROUP *local_30;
  
  EC_EX_DATA_free_data(param_1 + 0x44,ec_pre_comp_dup,ec_pre_comp_free,ec_pre_comp_clear_free);
  if (param_1 == (EC_GROUP *)0x0) {
    return false;
  }
  ptr = (EC_GROUP **)CRYPTO_malloc(0x1c,"ec_mult.c",0x67);
  if (ptr == (EC_GROUP **)0x0) {
    ERR_put_error(0x10,0xc4,0x41,"ec_mult.c",0x69);
    return false;
  }
  *ptr = param_1;
  ptr[1] = (EC_GROUP *)&DAT_00000008;
  ptr[2] = (EC_GROUP *)0x0;
  ptr[3] = (EC_GROUP *)&DAT_00000004;
  ptr[4] = (EC_GROUP *)0x0;
  ptr[5] = (EC_GROUP *)0x0;
  ptr[6] = (EC_GROUP *)0x1;
  pEVar1 = EC_GROUP_get0_generator(param_1);
  if (pEVar1 == (EC_POINT *)0x0) {
    ERR_put_error(0x10,0xbc,0x71,"ec_mult.c",0x2f9);
    if (param_2 != (BN_CTX *)0x0) {
      BN_CTX_end(param_2);
    }
LAB_08102040:
    points = (EC_POINT **)0x0;
    bVar10 = false;
    local_4c = (EC_POINT *)0x0;
    local_48 = (EC_POINT *)0x0;
  }
  else {
    local_50 = (BN_CTX *)0x0;
    if ((param_2 == (BN_CTX *)0x0) &&
       (param_2 = BN_CTX_new(), local_50 = param_2, param_2 == (BN_CTX *)0x0)) goto LAB_08102040;
    BN_CTX_start(param_2);
    order = BN_CTX_get(param_2);
    if ((order == (BIGNUM *)0x0) || (iVar2 = EC_GROUP_get_order(param_1,order,param_2), iVar2 == 0))
    {
      bVar10 = false;
      points = (EC_POINT **)0x0;
      local_4c = (EC_POINT *)0x0;
      local_48 = (EC_POINT *)0x0;
    }
    else if (order->top == 0) {
      bVar10 = false;
      points = (EC_POINT **)0x0;
      ERR_put_error(0x10,0xbc,0x72,"ec_mult.c",0x30b);
      local_4c = (EC_POINT *)0x0;
      local_48 = (EC_POINT *)0x0;
    }
    else {
      uVar3 = BN_num_bits(order);
      if (uVar3 < 800) {
        local_38 = (EC_GROUP *)0x8;
        local_30 = (EC_GROUP *)&DAT_00000004;
      }
      else {
        local_38 = (EC_GROUP *)((-(uint)(uVar3 < 2000) & 0xfffffff0) + 0x20);
        local_30 = (EC_GROUP *)(6 - (uint)(uVar3 < 2000));
      }
      iVar2 = (int)local_38;
      pEVar4 = (EC_GROUP *)(uVar3 + 7 >> 3);
      num = (EC_GROUP *)((int)pEVar4 * (int)local_38);
      points = (EC_POINT **)CRYPTO_malloc((int)num * 4 + 4,"ec_mult.c",0x325);
      if (points == (EC_POINT **)0x0) {
        iVar2 = 0x327;
LAB_08101e32:
        bVar10 = false;
        ERR_put_error(0x10,0xbc,0x41,"ec_mult.c",iVar2);
        local_4c = (EC_POINT *)0x0;
        local_48 = (EC_POINT *)0x0;
      }
      else {
        points[(int)num] = (EC_POINT *)0x0;
        if (num != (EC_GROUP *)0x0) {
          pEVar8 = (EC_GROUP *)0x0;
          do {
            pEVar5 = EC_POINT_new(param_1);
            points[(int)pEVar8] = pEVar5;
            if (pEVar5 == (EC_POINT *)0x0) {
              iVar2 = 0x32f;
              goto LAB_08101e32;
            }
            pEVar8 = pEVar8 + 1;
          } while (num != pEVar8);
        }
        local_48 = EC_POINT_new(param_1);
        if ((local_48 == (EC_POINT *)0x0) ||
           (local_4c = EC_POINT_new(param_1), local_4c == (EC_POINT *)0x0)) {
          bVar10 = false;
          ERR_put_error(0x10,0xbc,0x41,"ec_mult.c",0x335);
          local_4c = (EC_POINT *)0x0;
        }
        else {
          bVar10 = false;
          iVar6 = EC_POINT_copy(local_4c,pEVar1);
          if (iVar6 != 0) {
            if (pEVar4 != (EC_GROUP *)0x0) {
              local_38 = (EC_GROUP *)0x0;
              local_40 = points;
              do {
                iVar6 = EC_POINT_dbl(param_1,local_48,local_4c,param_2);
                if (iVar6 == 0) {
LAB_08102148:
                  bVar10 = false;
                  goto LAB_08101e74;
                }
                ppEVar9 = local_40 + 1;
                iVar6 = EC_POINT_copy(*local_40,local_4c);
                if (iVar6 == 0) goto LAB_08102148;
                local_40 = local_40 + iVar2;
                do {
                  iVar6 = EC_POINT_add(param_1,*ppEVar9,local_48,ppEVar9[-1],param_2);
                  if (iVar6 == 0) goto LAB_08102148;
                  ppEVar9 = ppEVar9 + 1;
                } while (ppEVar9 != local_40);
                if (local_38 < pEVar4 + -1) {
                  iVar6 = EC_POINT_dbl(param_1,local_4c,local_48,param_2);
                  if (iVar6 == 0) goto LAB_08102148;
                  iVar6 = 6;
                  do {
                    iVar7 = EC_POINT_dbl(param_1,local_4c,local_4c,param_2);
                    if (iVar7 == 0) goto LAB_08102148;
                    iVar6 = iVar6 + -1;
                  } while (iVar6 != 0);
                }
                local_38 = local_38 + 1;
              } while (pEVar4 != local_38);
            }
            bVar10 = false;
            iVar2 = EC_POINTs_make_affine(param_1,(size_t)num,points,param_2);
            if (iVar2 != 0) {
              ptr[4] = (EC_GROUP *)points;
              *ptr = param_1;
              ptr[1] = (EC_GROUP *)&DAT_00000008;
              ptr[2] = pEVar4;
              ptr[3] = local_30;
              ptr[5] = num;
              iVar2 = EC_EX_DATA_set_data(param_1 + 0x44,ptr,ec_pre_comp_dup,ec_pre_comp_free,
                                          ec_pre_comp_clear_free);
              bVar10 = iVar2 != 0;
              points = (EC_POINT **)0x0;
              if (iVar2 != 0) {
                ptr = (EC_GROUP **)0x0;
              }
            }
          }
        }
      }
    }
LAB_08101e74:
    BN_CTX_end(param_2);
    if (local_50 != (BN_CTX *)0x0) {
      BN_CTX_free(local_50);
    }
    if (ptr == (EC_GROUP **)0x0) goto LAB_08101ec3;
  }
  iVar2 = CRYPTO_add_lock((int *)(ptr + 6),-1,0x24,"ec_mult.c",0x89);
  if (iVar2 < 1) {
    ppEVar9 = (EC_POINT **)ptr[4];
    if (ppEVar9 != (EC_POINT **)0x0) {
      pEVar1 = *ppEVar9;
      if (pEVar1 != (EC_POINT *)0x0) {
        do {
          ppEVar9 = ppEVar9 + 1;
          EC_POINT_free(pEVar1);
          pEVar1 = *ppEVar9;
        } while (pEVar1 != (EC_POINT *)0x0);
        ppEVar9 = (EC_POINT **)ptr[4];
      }
      CRYPTO_free(ppEVar9);
    }
    CRYPTO_free(ptr);
  }
LAB_08101ec3:
  if (points != (EC_POINT **)0x0) {
    pEVar1 = *points;
    ppEVar9 = points;
    while (pEVar1 != (EC_POINT *)0x0) {
      ppEVar9 = ppEVar9 + 1;
      EC_POINT_free(pEVar1);
      pEVar1 = *ppEVar9;
    }
    CRYPTO_free(points);
  }
  if (local_48 != (EC_POINT *)0x0) {
    EC_POINT_free(local_48);
  }
  if (local_4c != (EC_POINT *)0x0) {
    EC_POINT_free(local_4c);
    return bVar10;
  }
  return bVar10;
}
